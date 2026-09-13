#!/usr/bin/env php
<?php
/**
 * check-parity.php — mechanical 1:1 binding guard.
 *
 * Proves, and exits non-zero on any drift:
 *
 *   1. Every @zep / @zep-construct annotation has a following C prototype,
 *      and every binding phpvk_* prototype (everything in src/*.h except the
 *      support, registry, platform and struct-internal headers) has one of
 *      those annotations.
 *   2. Every .zep bare call has an optimizer and vice versa.
 *   3. Emitted arity agrees across .zep signature, optimizer check, and C
 *      prototype (return_value does not count).
 *   4. Every src/*.c is listed in config.json extra-sources, and every
 *      extra-sources entry names a file that exists.
 *   5. Composite guard — the "one PHP static method = one native call" rule,
 *      enforced structurally. Every entry point in this extension is
 *      resolved at runtime, so a binding body's native call is the call
 *      through its resolved function pointer. A binding body must therefore
 *      contain:
 *        - exactly one phpvk_entry(...) resolution, and
 *        - exactly one fn(...) call through it,
 *      and it must contain NO direct Vulkan identifier call (a vkFoo name
 *      followed by an open paren), which would be a link-time call and would
 *      break the one-.so-for-both-boxes contract. A Struct\<Name> binding is
 *      held to the opposite rule: zero resolutions, zero calls.
 *      phpvk-bridge.c is glue and is exempt on all three counts — it is the
 *      one place allowed to name vkGetInstanceProcAddr, this extension's
 *      only linked Vulkan symbol.
 *
 *      The no-link-time-call half is also applied to every non-glue
 *      src/*.c end to end, not just to annotated bodies, so a direct call
 *      in a file with no bindings in it (src/phpvk-support.c) cannot hide.
 *   6. The registry audit (scripts/audit-registry.php) passes, when the
 *      vendored registry is present at <root>/scripts/khronos (fixture roots
 *      without it skip the audit).
 *
 * Prints per-class bound/reserved counts, then PARITY_OK with the three-way
 * zep/optimizer/prototype totals, then the audit output ending in AUDIT_OK.
 *
 * Optional argv[1]: package root (defaults to the package root). Used by
 * the self-test fixtures.
 */

declare(strict_types=1);

/** Headers that carry no binding annotations and are skipped by check 1. */
const NON_BINDING_HEADERS = [
    'phpvk-support.h',
    'phpvk-registry.h',
    'phpvk-platform.h',
    'vk-struct-internal.h',
];
const GLUE_SOURCE = 'phpvk-bridge.c';

/**
 * Struct-tier class paths make no native call at all: pack/packInto/unpack/
 * size are flat memory work over a generated layout. They get the opposite
 * composite rule — zero resolutions and zero calls — which is a real check,
 * not an exemption: a struct method that resolved an entry point would be
 * doing something this tier is not allowed to do.
 */
const STRUCT_CLASS_PREFIX = 'Struct\\';
const PARAM_TYPES = ['int', 'double', 'bool', 'string', 'var', 'array'];
const RETURN_TYPES = ['int', 'double', 'bool', 'string', 'var', 'array', 'void'];

$errors = [];

function error(string $msg): void
{
    global $errors;
    $errors[] = $msg;
}

/**
 * Replace comments and string/char-literal contents with spaces (newlines
 * kept) so later scans can ignore them without a second state machine.
 */
function blankCommentsAndStrings(string $src): string
{
    $len = strlen($src);
    $out = $src;
    $i = 0;
    while ($i < $len) {
        $c = $src[$i];
        $n = $i + 1 < $len ? $src[$i + 1] : '';
        if ($c === '/' && $n === '/') {
            $i += 2;
            while ($i < $len && $src[$i] !== "\n") {
                $out[$i] = ' ';
                $i++;
            }
            continue;
        }
        if ($c === '/' && $n === '*') {
            $out[$i] = ' ';
            $out[$i + 1] = ' ';
            $i += 2;
            while ($i < $len && !($src[$i] === '*' && $i + 1 < $len && $src[$i + 1] === '/')) {
                if ($src[$i] !== "\n") {
                    $out[$i] = ' ';
                }
                $i++;
            }
            if ($i < $len) {
                $out[$i] = ' ';
                if ($i + 1 < $len) {
                    $out[$i + 1] = ' ';
                }
                $i += 2;
            }
            continue;
        }
        if ($c === '"' || $c === "'") {
            $quote = $c;
            $out[$i] = ' ';
            $i++;
            while ($i < $len && $src[$i] !== $quote) {
                if ($src[$i] === '\\' && $i + 1 < $len) {
                    $out[$i] = ' ';
                    $out[$i + 1] = ' ';
                    $i += 2;
                    continue;
                }
                if ($src[$i] !== "\n") {
                    $out[$i] = ' ';
                }
                $i++;
            }
            if ($i < $len) {
                $out[$i] = ' ';
                $i++;
            }
            continue;
        }
        $i++;
    }

    return $out;
}

function matchingClose(string $s, int $open, string $openCh = '(', string $closeCh = ')'): int
{
    $len = strlen($s);
    $depth = 0;
    for ($i = $open; $i < $len; $i++) {
        if ($s[$i] === $openCh) {
            $depth++;
        } elseif ($s[$i] === $closeCh) {
            $depth--;
            if ($depth === 0) {
                return $i;
            }
        }
    }

    return $len - 1;
}

function listFiles(string $dir, string $suffix): array
{
    if (!is_dir($dir)) {
        return [];
    }
    $out = [];
    $it = new RecursiveIteratorIterator(
        new RecursiveDirectoryIterator($dir, FilesystemIterator::SKIP_DOTS)
    );
    foreach ($it as $file) {
        if ($file->isFile() && str_ends_with($file->getFilename(), $suffix)) {
            $out[] = $file->getPathname();
        }
    }
    sort($out);

    return $out;
}

function relativeTo(string $path, string $root): string
{
    $root = rtrim($root, '/') . '/';
    if (str_starts_with($path, $root)) {
        return substr($path, strlen($root));
    }

    return $path;
}

function studly(string $snake): string
{
    return str_replace(' ', '', ucwords(str_replace('_', ' ', $snake)));
}

/**
 * Count what a binding body does, for the composite guard.
 *
 * @return array{entries: int, calls: int, direct: list<string>}
 *   entries — phpvk_entry(...) resolutions
 *   calls   — fn(...) calls through the resolved pointer
 *   direct  — Vulkan identifiers called by name, i.e. link-time calls
 */
function measureBody(string $body): array
{
    $blank = blankCommentsAndStrings($body);

    $entries = preg_match_all('/\bphpvk_entry\s*\(/', $blank);
    $calls = preg_match_all('/\bfn\s*\(/', $blank);

    $direct = [];
    if (preg_match_all('/\bvk[A-Z][A-Za-z0-9]*\s*\(/', $blank, $m)) {
        $direct = array_map(static fn (string $t): string => rtrim(rtrim($t), '('), $m[0]);
    }

    return [
        'entries' => (int) $entries,
        'calls' => (int) $calls,
        'direct' => $direct,
    ];
}

/**
 * @return array<string, string> symbol → function body (including braces)
 */
function findFunctionBodies(string $src): array
{
    $blank = blankCommentsAndStrings($src);
    $len = strlen($blank);
    $out = [];
    $offset = 0;
    while (($pos = strpos($blank, 'phpvk_', $offset)) !== false) {
        // Must be the start of an identifier.
        if ($pos > 0 && (ctype_alnum($blank[$pos - 1]) || $blank[$pos - 1] === '_')) {
            $offset = $pos + 7;
            continue;
        }
        $before = $pos;
        while ($before > 0 && ctype_space($blank[$before - 1])) {
            $before--;
        }
        $typeEnd = $before;
        $typeStart = $typeEnd;
        while ($typeStart > 0 && (ctype_alnum($blank[$typeStart - 1]) || $blank[$typeStart - 1] === '_')) {
            $typeStart--;
        }
        $returnType = substr($blank, $typeStart, $typeEnd - $typeStart);
        if (!in_array($returnType, ['zend_long', 'double', 'void'], true)) {
            $offset = $pos + 7;
            continue;
        }

        $i = $pos;
        while ($i < $len && (ctype_alnum($blank[$i]) || $blank[$i] === '_')) {
            $i++;
        }
        $symbol = substr($blank, $pos, $i - $pos);
        while ($i < $len && ctype_space($blank[$i])) {
            $i++;
        }
        if ($i >= $len || $blank[$i] !== '(') {
            $offset = $pos + 7;
            continue;
        }
        $i = matchingClose($blank, $i, '(', ')') + 1;
        while ($i < $len && ctype_space($blank[$i])) {
            $i++;
        }
        if ($i >= $len || $blank[$i] !== '{') {
            $offset = $pos + 7;
            continue;
        }
        $close = matchingClose($blank, $i, '{', '}');
        $out[$symbol] = substr($src, $i, $close - $i + 1);
        $offset = $close + 1;
    }

    return $out;
}

/**
 * Parse src/*.h @zep/@reserved annotations and C prototypes.
 *
 * @return array{
 *   methods: list<array{classPath: string, method: string, params: int, returnType: string, symbol: string, bareCall: string, header: string, line: int, cArity: int}>,
 *   reserved: array<string, int>,
 * }
 */
function parseHeaders(string $root): array
{
    $methods = [];
    $reserved = [];
    foreach (glob("{$root}/src/*.h") ?: [] as $path) {
        $base = basename($path);
        $lines = file($path, FILE_IGNORE_NEW_LINES);
        if ($lines === false) {
            error("cannot read {$path}");
            continue;
        }
        $total = count($lines);
        $skipMarshalling = in_array($base, NON_BINDING_HEADERS, true);

        for ($i = 0; $i < $total; $i++) {
            $line = $lines[$i];
            $lineNo = $i + 1;
            $rel = 'src/' . $base;

            if (preg_match('#/\*\s*@reserved\s+([A-Za-z0-9_\\\\]+)\s+(.*?)\s*\*/#', $line, $m)) {
                $reserved[$m[1]] = ($reserved[$m[1]] ?? 0) + 1;
                continue;
            }

            if (preg_match('#/\*\s*@zep(?:-construct)?\s+([A-Za-z0-9_\\\\]+)\s+(\w+)\s*\(([^)]*)\)\s*->\s*(\w+)\s*\*/#', $line, $m)) {
                [, $classPath, $method, $paramSrc, $returnType] = $m;
                if (!in_array($returnType, RETURN_TYPES, true)) {
                    error("{$rel}:{$lineNo} unknown return type '{$returnType}'");
                }
                $paramCount = 0;
                if (trim($paramSrc) !== '') {
                    foreach (explode(',', $paramSrc) as $p) {
                        $parts = preg_split('/\s+/', trim($p));
                        if (count($parts) !== 2 || !in_array($parts[0], PARAM_TYPES, true)) {
                            error("{$rel}:{$lineNo} bad parameter '" . trim($p) . "'");
                            continue;
                        }
                        $paramCount++;
                    }
                }

                $proto = null;
                for ($j = $i + 1; $j < $total; $j++) {
                    if (trim($lines[$j]) !== '') {
                        $proto = $lines[$j];
                        $i = $j;
                        break;
                    }
                }
                if (is_null($proto) || !preg_match('/^\s*(zend_long|double|void)\s+(phpvk_[a-z0-9_]+)\s*\(([^)]*)\)\s*;/', $proto, $pm)) {
                    error("{$rel}:{$lineNo} @zep for '{$method}' is not followed by a parseable C prototype");
                    continue;
                }
                [, $cReturn, $symbol, $cParamSrc] = $pm;
                $cParams = trim($cParamSrc) === '' || trim($cParamSrc) === 'void'
                    ? []
                    : array_map('trim', explode(',', $cParamSrc));
                $hasReturnValueArg = $cParams !== [] && str_contains($cParams[0], 'return_value');
                $cArity = count($cParams) - ($hasReturnValueArg ? 1 : 0);
                $expectedCReturn = match ($returnType) {
                    'int', 'bool' => 'zend_long',
                    'double' => 'double',
                    default => 'void',
                };
                if ($cReturn !== $expectedCReturn) {
                    error("{$symbol}: @zep return '{$returnType}' expects C '{$expectedCReturn}', found '{$cReturn}'");
                }
                $needsSymbolWrite = in_array($returnType, ['string', 'array', 'var'], true);
                if ($needsSymbolWrite !== $hasReturnValueArg) {
                    error("{$symbol}: @zep return '{$returnType}' "
                        . ($needsSymbolWrite
                            ? 'requires a leading zval *return_value parameter'
                            : 'must not take a return_value parameter'));
                }
                if ($cArity !== $paramCount) {
                    error("{$symbol}: @zep declares {$paramCount} parameter(s), C prototype has {$cArity}");
                }

                $methods[] = [
                    'classPath' => $classPath,
                    'method' => $method,
                    'params' => $paramCount,
                    'returnType' => $returnType,
                    'symbol' => $symbol,
                    'bareCall' => preg_replace('/^phpvk_/', '', $symbol),
                    'header' => $rel,
                    'line' => $lineNo,
                    'cArity' => $cArity,
                ];
                continue;
            }

            if (str_contains($line, '@zep')) {
                error("{$rel}:{$lineNo} malformed @zep annotation: {$line}");
                continue;
            }

            if ($skipMarshalling) {
                continue;
            }

            if (preg_match('/^\s*(zend_long|double|void)\s+(phpvk_[a-z0-9_]+)\s*\(([^)]*)\)\s*;/', $line, $pm)) {
                // The registry surface is shared plumbing declared without @zep.
                // The loader surface is shared plumbing declared without @zep.
                if (in_array($pm[2], ['phpvk_bridge_shutdown'], true)) {
                    continue;
                }
                $prev = null;
                for ($j = $i - 1; $j >= 0; $j--) {
                    if (trim($lines[$j]) !== '') {
                        $prev = $lines[$j];
                        break;
                    }
                }
                if (is_null($prev) || !preg_match('#/\*\s*@zep(?:-construct)?\s+#', $prev)) {
                    error("{$rel}:{$lineNo} prototype '{$pm[2]}' has no preceding @zep");
                }
            }
        }
    }

    return ['methods' => $methods, 'reserved' => $reserved];
}

/**
 * @return array<string, array{arity: int, file: string}> bareCall → info
 */
function parseZepCalls(string $root): array
{
    $calls = [];
    foreach (listFiles("{$root}/vulkan", '.zep') as $path) {
        $src = (string) file_get_contents($path);
        $rel = relativeTo($path, $root);
        if (!preg_match_all(
            '/public static function \w+\(([^)]*)\)\s*->\s*\w+\s*\{(.*?)\}/s',
            $src,
            $blocks,
            PREG_SET_ORDER
        )) {
            continue;
        }
        foreach ($blocks as $block) {
            $paramSrc = trim($block[1]);
            $arity = $paramSrc === '' ? 0 : count(array_map('trim', explode(',', $paramSrc)));
            $body = $block[2];
            if (!preg_match('/\b([a-z][a-z0-9_]*)\s*\(/', $body, $cm)) {
                error("{$rel}: static method has no bare call");
                continue;
            }
            $bare = $cm[1];
            if (isset($calls[$bare])) {
                error("duplicate zep bare call '{$bare}' ({$calls[$bare]['file']} and {$rel})");
            }
            $calls[$bare] = ['arity' => $arity, 'file' => $rel];
        }
    }

    return $calls;
}

/**
 * @return array<string, array{arity: int, file: string, symbol: string}> bareCall → info
 */
function parseOptimizers(string $root): array
{
    $opts = [];
    foreach (glob("{$root}/optimizers/*Optimizer.php") ?: [] as $path) {
        $src = (string) file_get_contents($path);
        $rel = relativeTo($path, $root);
        if (!preg_match('/\b(phpvk_[a-z0-9_]+)\s*\(/', $src, $sm)) {
            error("{$rel}: optimizer does not call a phpvk_* symbol");
            continue;
        }
        $symbol = $sm[1];
        $bare = preg_replace('/^phpvk_/', '', $symbol);
        if (!preg_match('/count\(\$expression\[\'parameters\'\]\)\s*!==\s*(\d+)/', $src, $am)) {
            error("{$rel}: optimizer has no arity check against \$expression['parameters']");
            continue;
        }
        $arity = (int) $am[1];
        $expectedClass = studly($bare) . 'Optimizer';
        $base = basename($path, '.php');
        if ($base !== $expectedClass) {
            error("{$rel}: file class/name '{$base}' does not match symbol '{$symbol}' (expected {$expectedClass})");
        }
        if (isset($opts[$bare])) {
            error("duplicate optimizer for '{$bare}' ({$opts[$bare]['file']} and {$rel})");
        }
        $opts[$bare] = ['arity' => $arity, 'file' => $rel, 'symbol' => $symbol];
    }

    return $opts;
}

function checkExtraSources(string $root): int
{
    $configPath = "{$root}/config.json";
    if (!is_file($configPath)) {
        error('config.json is missing');

        return 0;
    }
    $config = json_decode((string) file_get_contents($configPath), true);
    if (!is_array($config)) {
        error('config.json is not valid JSON');

        return 0;
    }
    $listed = $config['extra-sources'] ?? null;
    if (!is_array($listed)) {
        error("config.json has no extra-sources array");
        $listed = [];
    }
    $listed = array_values(array_map('strval', $listed));

    $onDisk = [];
    foreach (glob("{$root}/src/*.c") ?: [] as $path) {
        $onDisk[] = relativeTo($path, $root);
    }
    sort($onDisk);

    foreach ($onDisk as $rel) {
        if (!in_array($rel, $listed, true)) {
            error("{$rel} exists but is not in config.json extra-sources");
        }
    }
    foreach ($listed as $rel) {
        if (!is_file("{$root}/{$rel}")) {
            error("config.json extra-sources lists '{$rel}' but the file does not exist");
        }
    }

    return count($onDisk);
}

/**
 * Whole-file scan for link-time calls.
 *
 * checkComposite only sees functions that carry a binding annotation, so a
 * direct Vulkan call in a file with no bindings at all — src/phpvk-support.c
 * is exactly that shape — would be invisible to it. Every non-glue src/*.c is
 * therefore also read end to end: nothing outside phpvk-bridge.c may name a
 * Vulkan command at all.
 */
function checkNoLinkTimeCalls(string $root): void
{
    foreach (glob("{$root}/src/*.c") ?: [] as $path) {
        $rel = relativeTo($path, $root);
        if (basename($path) === GLUE_SOURCE) {
            continue;
        }
        $blank = blankCommentsAndStrings((string) file_get_contents($path));
        if (!preg_match_all('/\bvk[A-Z][A-Za-z0-9]*\s*\(/', $blank, $m)) {
            continue;
        }
        $names = array_map(static fn (string $t): string => rtrim(rtrim($t), '('), $m[0]);
        error("{$rel}: calls [" . implode(', ', array_unique($names))
            . '] by name — every entry point is resolved at runtime through'
            . ' phpvk_entry(), never at link time');
    }
}

function checkComposite(string $root, array $methods): void
{
    $bodies = [];
    $homes = [];
    foreach (glob("{$root}/src/*.c") ?: [] as $path) {
        $rel = relativeTo($path, $root);
        $src = (string) file_get_contents($path);
        foreach (findFunctionBodies($src) as $symbol => $body) {
            if (isset($bodies[$symbol])) {
                error("duplicate definition of {$symbol} in {$rel} (already in {$homes[$symbol]})");
            }
            $bodies[$symbol] = $body;
            $homes[$symbol] = $rel;
        }
    }

    foreach ($methods as $m) {
        $symbol = $m['symbol'];
        if (!isset($bodies[$symbol])) {
            error("{$symbol}: @zep has no function definition in src/*.c");
            continue;
        }
        $home = $homes[$symbol];
        if (basename($home) === GLUE_SOURCE) {
            continue;
        }
        $seen = measureBody($bodies[$symbol]);
        if ($seen['direct'] !== []) {
            error("{$home}: {$symbol} calls [" . implode(', ', array_unique($seen['direct']))
                . '] by name — every entry point is resolved at runtime through'
                . ' phpvk_entry(), never at link time');
        }
        if (str_starts_with($m['classPath'], STRUCT_CLASS_PREFIX)) {
            if ($seen['entries'] !== 0 || $seen['calls'] !== 0) {
                error("{$home}: {$symbol} resolves {$seen['entries']} entry point(s) and makes"
                    . " {$seen['calls']} call(s) — a struct method is flat memory work"
                    . ' and makes no Vulkan call at all');
            }
            continue;
        }
        if ($seen['entries'] !== 1) {
            error("{$home}: {$symbol} makes {$seen['entries']} phpvk_entry() resolution(s)"
                . ' — a binding resolves exactly one entry point');
        }
        if ($seen['calls'] !== 1) {
            error("{$home}: {$symbol} makes {$seen['calls']} call(s) through the resolved"
                . ' pointer — one PHP static method = one native call');
        }
    }
}

// ---- main ----

$root = isset($argv[1]) ? rtrim($argv[1], '/') : dirname(__DIR__);
if (!is_dir($root)) {
    fwrite(STDERR, "check-parity: root '{$root}' is not a directory\n");
    exit(1);
}

$parsed = parseHeaders($root);
$methods = $parsed['methods'];
$reserved = $parsed['reserved'];

if ($methods === []) {
    error('no @zep annotations found in any header');
}

$seenSymbols = [];
$seenMethods = [];
foreach ($methods as $m) {
    if (isset($seenSymbols[$m['symbol']])) {
        error("duplicate C symbol '{$m['symbol']}'");
    }
    $seenSymbols[$m['symbol']] = true;
    $methodKey = $m['classPath'] . '::' . $m['method'];
    if (isset($seenMethods[$methodKey])) {
        error("duplicate method '{$methodKey}'");
    }
    $seenMethods[$methodKey] = true;
}

$zepCalls = parseZepCalls($root);
$optimizers = parseOptimizers($root);
$cCount = checkExtraSources($root);
checkComposite($root, $methods);
checkNoLinkTimeCalls($root);

$protoBare = [];
foreach ($methods as $m) {
    $protoBare[$m['bareCall']] = $m;
}

$zepNames = array_keys($zepCalls);
$optNames = array_keys($optimizers);
$protoNames = array_keys($protoBare);
sort($zepNames);
sort($optNames);
sort($protoNames);

foreach (array_diff($zepNames, $optNames) as $bare) {
    error("zep call '{$bare}' has no optimizer");
}
foreach (array_diff($optNames, $zepNames) as $bare) {
    error("optimizer for '{$bare}' has no zep call");
}
foreach (array_diff($protoNames, $zepNames) as $bare) {
    error("C prototype 'phpvk_{$bare}' has no zep call");
}
foreach (array_diff($zepNames, $protoNames) as $bare) {
    error("zep call '{$bare}' has no C prototype");
}
foreach (array_diff($protoNames, $optNames) as $bare) {
    error("C prototype 'phpvk_{$bare}' has no optimizer");
}
foreach (array_diff($optNames, $protoNames) as $bare) {
    error("optimizer for '{$bare}' has no C prototype");
}

foreach ($protoBare as $bare => $m) {
    $cArity = $m['cArity'];
    if (isset($zepCalls[$bare]) && $zepCalls[$bare]['arity'] !== $cArity) {
        error("{$m['symbol']}: zep arity {$zepCalls[$bare]['arity']} != C arity {$cArity}");
    }
    if (isset($optimizers[$bare]) && $optimizers[$bare]['arity'] !== $cArity) {
        error("{$m['symbol']}: optimizer arity {$optimizers[$bare]['arity']} != C arity {$cArity}");
    }
}

$byClass = [];
foreach ($methods as $m) {
    $byClass[$m['classPath']]['bound'] = ($byClass[$m['classPath']]['bound'] ?? 0) + 1;
}
foreach ($reserved as $classPath => $count) {
    $byClass[$classPath]['reserved'] = $count;
}
ksort($byClass);
foreach ($byClass as $classPath => $info) {
    $bound = $info['bound'] ?? 0;
    $res = $info['reserved'] ?? 0;
    echo sprintf("%-40s bound=%-4d reserved=%-4d\n", $classPath, $bound, $res);
}

$zepCount = count($zepCalls);
$optCount = count($optimizers);
$protoCount = count($protoBare);
echo "zep_calls={$zepCount} optimizers={$optCount} prototypes={$protoCount} extra_sources={$cCount}\n";

if ($errors !== []) {
    foreach ($errors as $e) {
        fwrite(STDERR, "parity: {$e}\n");
    }
    fwrite(STDERR, 'parity: ' . count($errors) . " drift(s)\n");
    exit(1);
}

if ($zepCount !== $optCount || $optCount !== $protoCount) {
    fwrite(STDERR, "parity: count mismatch zep={$zepCount} optimizers={$optCount} prototypes={$protoCount}\n");
    exit(1);
}

echo "PARITY_OK\n";

// ---- registry audit (skipped for fixture roots with no vendored vk.xml) ----
if (is_dir("{$root}/scripts/khronos")) {
    $audit = __DIR__ . '/audit-registry.php';
    if (!is_file($audit)) {
        fwrite(STDERR, "parity: scripts/audit-registry.php is missing\n");
        exit(1);
    }
    passthru(escapeshellarg(PHP_BINARY) . ' ' . escapeshellarg($audit) . ' ' . escapeshellarg($root), $status);
    if ($status !== 0) {
        exit(1);
    }
}
