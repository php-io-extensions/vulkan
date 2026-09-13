#!/usr/bin/env php
<?php
/*
 * The struct tier, exercised against the built .so.
 *
 * Everything else that watches this tier is static: the audit counts
 * annotations and members, the layout asserts are a compile-time contract,
 * check-parity proves a struct method makes no Vulkan call. None of them ever
 * writes a byte. This one does: for every one of the Vulkan\Struct\* classes
 * it builds a deterministic member array straight from the registry walk,
 * packs it into real memory, reads it back and compares.
 *
 *   pack -> unpack          every member survives the round trip, at the
 *                           width the registry declares for it
 *   packInto == pack        filling caller-owned memory produces the same
 *                           bytes as filling a malloc'd block (this is what
 *                           makes an array of structs work)
 *   negative controls       an unknown key warns by name and refuses; a
 *                           scalar array one element too long warns by name
 *                           and refuses; a char[N] string one byte too long
 *                           warns by name and refuses; a refused packInto
 *                           leaves the caller's memory byte-identical;
 *                           unpack(0) warns and returns null
 *
 * The deterministic pattern is the point. Values are derived from a seed
 * plus the member's position in a single walk, then masked to the member's
 * own C width, so two members cannot accidentally agree and a member written
 * at the wrong offset or the wrong width shows up as a mismatch rather than
 * as a zero that looked plausible.
 *
 * Unions are packed one member at a time: `pack` writes the members present
 * and `unpack` returns all of them, so only the member that was written has
 * a knowable value. The others are compared against nothing on purpose.
 *
 * Prints STRUCT_GUARD_OK structs=<n>.
 */

declare(strict_types=1);

use Vulkan\Bridge\Bridge;

require __DIR__ . '/lib/harness.php';
require dirname(__DIR__) . '/lib/registry.php';

$root = dirname(__DIR__, 2);
$expect = new Expect('struct-guard');

/** The seed the plan fixes; high bytes on purpose, so truncation shows. */
const GUARD_SEED = 0x0102030405;

/**
 * The window-system and Metal spellings the registry names and
 * src/phpvk-platform.h defines, with the width each shim typedef gives them.
 * Kept here rather than shared with the generator because the generator
 * never needs a WIDTH — it casts — and this guard needs nothing else from
 * its table. The key set is cross-checked against the generator's
 * PLATFORM_TYPES below, so the two cannot drift apart quietly.
 */
const GUARD_PLATFORM_TYPES = [
    'xcb_visualid_t' => ['int', 32, false],
    'xcb_window_t' => ['int', 32, false],
    'Window' => ['int', 64, false],
    'VisualID' => ['int', 64, false],
    'MTLDevice_id' => ['ptr', 64, false],
    'MTLCommandQueue_id' => ['ptr', 64, false],
    'MTLBuffer_id' => ['ptr', 64, false],
    'MTLTexture_id' => ['ptr', 64, false],
    'MTLSharedEvent_id' => ['ptr', 64, false],
    'IOSurfaceRef' => ['ptr', 64, false],
];

/** Marks a value nothing can predict — an overlapped union member. */
final class Unknowable
{
    private static ?self $it = null;

    public static function it(): self
    {
        return self::$it ??= new self();
    }
}

function guardFail(string $msg): never
{
    fwrite(STDERR, "struct-guard: {$msg}\n");
    exit(1);
}

/**
 * What one non-pointer member type is, in PHP terms and in C widths.
 *
 * Unlike the generator's table this resolves all the way down to a primitive
 * spelling, because a guard that wrote 0x0102030405 into a uint8_t and then
 * expected it back would be testing nothing. A type it cannot resolve is a
 * hard failure naming the type, exactly as in the generator.
 *
 * @return array{0: string, 1: int, 2: bool}  kind, bits, signed
 */
function guardScalar(string $type, array $types, string $ctx, array $seen = []): array
{
    if (isset($seen[$type])) {
        guardFail("{$ctx}: type '{$type}' resolves in a circle");
    }
    $seen[$type] = true;

    if (isset(GUARD_PLATFORM_TYPES[$type])) {
        return GUARD_PLATFORM_TYPES[$type];
    }

    $t = $types[$type] ?? null;
    if ($t !== null) {
        if ($t['alias'] !== null) {
            return guardScalar($t['alias'], $types, $ctx, $seen);
        }
        switch ($t['category']) {
            case 'handle':
                // Dispatchable: a real pointer. Non-dispatchable: 64 bits
                // through uintptr_t either way.
                return $t['dispatchable'] ? ['ptr', 64, false] : ['int', 64, false];
            case 'enum':
                // Every Vulkan enum carries a _MAX_ENUM = 0x7FFFFFFF member,
                // so its underlying type is a 32-bit signed int.
                return ['int', 32, true];
            case 'funcpointer':
                return ['ptr', 64, false];
            case 'struct':
                return ['struct', 0, false];
            case 'union':
                return ['union', 0, false];
            case 'bitmask':
            case 'basetype':
                if ($type === 'VkBool32') {
                    return ['bool', 32, false];
                }
                if (($t['underlyingPtr'] ?? 0) > 0) {
                    return ['ptr', 64, false];
                }
                if ($t['underlying'] === null || $t['underlying'] === $type) {
                    guardFail("{$ctx}: '{$type}' has no underlying type this guard can size");
                }

                return guardScalar($t['underlying'], $types, $ctx, $seen);
        }
    }

    return match ($type) {
        'uint8_t' => ['int', 8, false],
        'int8_t' => ['int', 8, true],
        'uint16_t' => ['int', 16, false],
        'int16_t' => ['int', 16, true],
        'uint32_t' => ['int', 32, false],
        'int32_t', 'int' => ['int', 32, true],
        'uint64_t', 'size_t' => ['int', 64, false],
        'int64_t' => ['int', 64, true],
        // Plain `char` is signed on x86 and unsigned on arm; a 7-bit value
        // round-trips under either, so the guard never has to know which.
        'char' => ['int', 7, false],
        'float', 'double' => ['float', 0, false],
        default => guardFail("{$ctx}: unsupported member type '{$type}'"),
    };
}

/** The value a member of this width holds, derived from its position. */
function guardInt(int $bits, bool $signed, int $seq): int
{
    $v = GUARD_SEED + $seq;
    if ($bits >= 64) {
        return $v;
    }
    $v &= (1 << $bits) - 1;
    if ($signed && ($v & (1 << ($bits - 1))) !== 0) {
        $v -= 1 << $bits;
    }

    return $v;
}

/**
 * Build the input array for one struct or union, and what unpack must give
 * back for it.
 *
 * @param list<string>|null $only for a union: the single member to write
 *
 * @return array{0: array<string, mixed>, 1: array<string, mixed>}
 */
function guardBuild(string $name, array $types, array $reg, int &$seq, ?string $only = null, array $stack = []): array
{
    if (isset($stack[$name])) {
        guardFail("{$name}: by-value nesting is cyclic, which cannot happen in C");
    }
    $stack[$name] = true;

    $t = $types[$name] ?? guardFail("{$name}: the registry has no such type");
    $isUnion = $t['category'] === 'union';
    if ($isUnion && $only === null) {
        $only = $t['members'][0]['name'];
    }

    $input = [];
    $want = [];

    foreach ($t['members'] as $m) {
        $key = $m['name'];
        $ctx = "{$name}.{$key}";
        $seq++;
        $mine = !$isUnion || $key === $only;

        // ---- any pointer, pNext included: bits, never followed
        if ($m['ptr'] > 0) {
            $value = 0x1000 + $seq;
            if ($mine) {
                $input[$key] = $value;
            }
            $want[$key] = $mine ? $value : Unknowable::it();
            continue;
        }

        [$kind, $bits, $signed] = guardScalar($m['type'], $types, $ctx);

        // ---- char[N]: a string, NUL-padded in and cut at the NUL out
        if ($m['dims'] !== [] && $m['type'] === 'char') {
            $n = vkArrayLength($m['dims'][0], $reg, $ctx);
            $text = substr("m{$seq}", 0, max(0, $n - 1));
            if ($mine) {
                $input[$key] = $text;
            }
            $want[$key] = $mine ? $text : Unknowable::it();
            continue;
        }

        // ---- T[N]
        if ($m['dims'] !== []) {
            $n = vkArrayLength($m['dims'][0], $reg, $ctx);
            $in = [];
            $out = [];
            for ($i = 0; $i < $n; $i++) {
                if ($kind === 'struct' || $kind === 'union') {
                    [$si, $so] = guardBuild($m['type'], $types, $reg, $seq, null, $stack);
                    $in[] = $si;
                    $out[] = $so;
                    continue;
                }
                $seq++;
                $in[] = guardElement($kind, $bits, $signed, $seq);
                $out[] = $in[$i];
            }
            if ($mine) {
                $input[$key] = $in;
            }
            $want[$key] = $mine ? $out : Unknowable::it();
            continue;
        }

        // ---- nested struct or union, by value
        if ($kind === 'struct' || $kind === 'union') {
            [$si, $so] = guardBuild($m['type'], $types, $reg, $seq, null, $stack);
            if ($mine) {
                $input[$key] = $si;
            }
            $want[$key] = $mine ? $so : Unknowable::it();
            continue;
        }

        // ---- scalars
        $value = guardElement($kind, $bits, $signed, $seq);
        if ($mine) {
            $input[$key] = $value;
        }
        $want[$key] = $mine ? $value : Unknowable::it();
    }

    return [$input, $want];
}

/** One scalar element's value, by kind. */
function guardElement(string $kind, int $bits, bool $signed, int $seq): int|float|bool
{
    return match ($kind) {
        'bool' => $seq % 2 === 0,
        // 1.5 + n is exact in a 32-bit float for every n this guard reaches,
        // so `===` is the right comparison and no epsilon is needed.
        'float' => 1.5 + $seq,
        'ptr' => 0x1000 + $seq,
        default => guardInt($bits, $signed, $seq),
    };
}

/** Compare what unpack gave back against what the walk predicted. */
function guardCompare(mixed $want, mixed $got, string $path, array &$problems): void
{
    if ($want instanceof Unknowable) {
        return;
    }
    if (is_array($want)) {
        if (!is_array($got)) {
            $problems[] = "{$path}: expected an array, unpack gave " . gettype($got);

            return;
        }
        if (array_keys($want) !== array_keys($got)) {
            $problems[] = "{$path}: unpack returned keys [" . implode(', ', array_keys($got))
                . '], the registry declares [' . implode(', ', array_keys($want)) . ']';

            return;
        }
        foreach ($want as $k => $v) {
            guardCompare($v, $got[$k], "{$path}.{$k}", $problems);
        }

        return;
    }
    if ($want !== $got) {
        $problems[] = "{$path}: packed " . var_export($want, true)
            . ', unpack gave ' . var_export($got, true);
    }
}

// ------------------------------------------------------------- the registry

$reg = vkRegistryLoad("{$root}/scripts/khronos/vk.xml");
$scope = vkRegistryScope($reg);
$types = $reg['types'];

/* Emission order: the core buckets, then the extension ones. */
$order = [];
foreach (VK_FEATURES as $class) {
    foreach ($scope['structs'][$class]['names'] as $n) {
        $order[] = $n;
    }
}
foreach (VK_EXTENSIONS as $extension => $class) {
    foreach ($scope['structs'][$class ?? 'EXT:' . $extension]['names'] as $n) {
        $order[] = $n;
    }
}

/*
 * The guard's platform table and the generator's must name the same
 * spellings. Neither can grow one without the other noticing.
 */
$genSrc = (string) file_get_contents("{$root}/scripts/gen-vk-src.php");
preg_match('/const PLATFORM_TYPES = \[(.*?)\n\];/s', $genSrc, $pm);
preg_match_all("/'([A-Za-z_][A-Za-z0-9_]*)' =>/", $pm[1] ?? '', $pk);
$generatorPlatform = $pk[1] ?? [];
sort($generatorPlatform);
$guardPlatform = array_keys(GUARD_PLATFORM_TYPES);
sort($guardPlatform);
$expect->that(
    $generatorPlatform !== [] && $generatorPlatform === $guardPlatform,
    'the generator knows platform types [' . implode(', ', $generatorPlatform)
    . '] and this guard knows [' . implode(', ', $guardPlatform) . ']'
);

if (!extension_loaded('vulkan')) {
    echo "struct-guard: the vulkan extension is not loaded; live checks skipped\n";
    $expect->finish('STRUCT_GUARD_OK structs=0');
}

// ------------------------------------------------------ the classes exist

$declared = [];
foreach (get_declared_classes() as $class) {
    if (str_starts_with($class, 'Vulkan\\Struct\\')) {
        $segments = explode('\\', $class);
        $declared[end($segments)] = $class;
    }
}
$missing = array_values(array_diff($order, array_keys($declared)));
$extra = array_values(array_diff(array_keys($declared), $order));
$expect->that($missing === [], 'the registry scopes structs with no loaded class: ' . implode(', ', $missing));
$expect->that($extra === [], 'the extension declares Struct\\ classes the registry does not scope: ' . implode(', ', $extra));

// ------------------------------------------------------------- round trips
$warnings = [];
set_error_handler(static function (int $no, string $msg) use (&$warnings): bool {
    $warnings[] = $msg;

    return true;
});

$problems = [];
$checked = 0;
$seq = 0;

foreach ($order as $name) {
    $class = $declared[$name] ?? null;
    if ($class === null) {
        continue;
    }
    $isUnion = ($types[$name]['category'] ?? '') === 'union';

    /*
     * A union is packed one member at a time; a struct once, with every
     * member present.
     */
    $cases = $isUnion
        ? array_map(static fn (array $m): ?string => $m['name'], $types[$name]['members'])
        : [null];

    $first = true;
    foreach ($cases as $only) {
        [$input, $want] = guardBuild($name, $types, $reg, $seq, $only);
        $label = $only === null ? $name : "{$name}({$only})";

        $warnings = [];
        $ptr = $class::pack($input);
        if ($warnings !== []) {
            $problems[] = "{$label}: pack warned on a valid member array: " . implode(' | ', $warnings);
        }
        if ($ptr === 0) {
            $problems[] = "{$label}: pack refused a valid member array";
            continue;
        }

        $warnings = [];
        $got = $class::unpack($ptr);
        if ($warnings !== []) {
            $problems[] = "{$label}: unpack warned: " . implode(' | ', $warnings);
        }
        if (!is_array($got)) {
            $problems[] = "{$label}: unpack returned " . gettype($got);
        } else {
            guardCompare($want, $got, $label, $problems);
        }

        /*
         * packInto must write caller-owned memory byte for byte the way pack
         * writes its own block — that identity is what makes
         * `alloc(n * size())` plus n packInto calls a legal array of structs.
         */
        if ($first) {
            $size = $class::size();
            if ($size <= 0) {
                $problems[] = "{$label}: size() returned {$size}";
            } else {
                $block = Bridge::alloc($size);
                if ($block === 0) {
                    $problems[] = "{$label}: Bridge::alloc({$size}) returned 0";
                } else {
                    $warnings = [];
                    $class::packInto($block, $input);
                    if ($warnings !== []) {
                        $problems[] = "{$label}: packInto warned: " . implode(' | ', $warnings);
                    }
                    $a = Bridge::read($ptr, 0, $size);
                    $b = Bridge::read($block, 0, $size);
                    if (!is_string($a) || !is_string($b)) {
                        $problems[] = "{$label}: Bridge::read did not return bytes";
                    } elseif ($a !== $b) {
                        $problems[] = "{$label}: packInto wrote different bytes than pack"
                            . ' (' . bin2hex($a) . ' vs ' . bin2hex($b) . ')';
                    }
                    Bridge::free($block);
                }
            }
            $first = false;
        }

        Bridge::free($ptr);
    }

    $checked++;
}

// ------------------------------------------------------- negative controls

/* 1. An unknown key names the struct and the key, and refuses. */
$probe = $declared['VkApplicationInfo'];
$warnings = [];
$r = $probe::pack(['nope' => 1]);
if ($r !== 0) {
    $problems[] = 'pack accepted an unknown member and returned ' . $r;
}
if (count($warnings) !== 1
    || !str_contains($warnings[0], 'VkApplicationInfo')
    || !str_contains($warnings[0], 'nope')) {
    $problems[] = 'an unknown member did not warn naming struct and key: ' . json_encode($warnings);
}

/* 2. A scalar array one element too long names the member, and refuses. */
$victim = null;
foreach ($order as $name) {
    if (($types[$name]['category'] ?? '') === 'union') {
        continue;
    }
    foreach ($types[$name]['members'] as $m) {
        if ($m['dims'] === [] || $m['ptr'] > 0 || $m['type'] === 'char') {
            continue;
        }
        [$kind] = guardScalar($m['type'], $types, "{$name}.{$m['name']}");
        if ($kind === 'struct' || $kind === 'union') {
            continue;
        }
        $victim = [$name, $m, vkArrayLength($m['dims'][0], $reg, "{$name}.{$m['name']}")];
        break 2;
    }
}
if ($victim === null) {
    $problems[] = 'no scoped struct has a scalar array member to over-fill';
} else {
    [$vName, $vMember, $vLen] = $victim;
    $seq2 = 0;
    [$vInput] = guardBuild($vName, $types, $reg, $seq2);
    $vInput[$vMember['name']] = array_fill(0, $vLen + 1, 1);
    $warnings = [];
    $r = $declared[$vName]::pack($vInput);
    if ($r !== 0) {
        $problems[] = "{$vName}.{$vMember['name']}: pack accepted an over-long array and returned {$r}";
    }
    $said = implode(' | ', $warnings);
    if (!str_contains($said, $vName)
        || !str_contains($said, $vMember['name'])
        || !str_contains($said, (string) ($vLen + 1))
        || !str_contains($said, (string) $vLen)) {
        $problems[] = "an over-long array member did not warn naming {$vName}.{$vMember['name']}"
            . " and both lengths: {$said}";
    }
}

/* 3. A char[N] string one byte too long names the member, and refuses. */
$charVictim = null;
foreach ($order as $name) {
    if (($types[$name]['category'] ?? '') === 'union') {
        continue;
    }
    foreach ($types[$name]['members'] as $m) {
        if ($m['dims'] === [] || $m['ptr'] > 0 || $m['type'] !== 'char') {
            continue;
        }
        $charVictim = [$name, $m, vkArrayLength($m['dims'][0], $reg, "{$name}.{$m['name']}")];
        break 2;
    }
}
if ($charVictim === null) {
    $problems[] = 'no scoped struct has a char[N] member to over-fill';
} else {
    [$cName, $cMember, $cLen] = $charVictim;
    $seq3 = 0;
    [$cInput] = guardBuild($cName, $types, $reg, $seq3);
    // N-1 bytes fit beside the NUL; N do not.
    $cInput[$cMember['name']] = str_repeat('x', $cLen);
    $warnings = [];
    $r = $declared[$cName]::pack($cInput);
    if ($r !== 0) {
        $problems[] = "{$cName}.{$cMember['name']}: pack accepted an over-long string and returned {$r}";
        Bridge::free($r);
    }
    $said = implode(' | ', $warnings);
    if (!str_contains($said, $cName)
        || !str_contains($said, $cMember['name'])
        || !str_contains($said, (string) $cLen)) {
        $problems[] = "an over-long char[N] member did not warn naming {$cName}.{$cMember['name']}"
            . " and the length: {$said}";
    }

    // And the string that does fit still round-trips, so the check is not off by one.
    $cInput[$cMember['name']] = str_repeat('x', $cLen - 1);
    $warnings = [];
    $fits = $declared[$cName]::pack($cInput);
    if ($fits === 0 || $warnings !== []) {
        $problems[] = "{$cName}.{$cMember['name']}: a string of exactly N-1 bytes was refused: "
            . implode(' | ', $warnings);
    } else {
        $back = $declared[$cName]::unpack($fits);
        if (($back[$cMember['name']] ?? null) !== $cInput[$cMember['name']]) {
            $problems[] = "{$cName}.{$cMember['name']}: an N-1 byte string did not round-trip";
        }
        Bridge::free($fits);
    }
}

/* 4. A refused packInto leaves the caller's memory untouched (spec §7). */
$target = Bridge::alloc($probe::size());
$seq4 = 0;
[$goodInput] = guardBuild('VkApplicationInfo', $types, $reg, $seq4);
$probe::packInto($target, $goodInput);
$before = Bridge::read($target, 0, $probe::size());
$warnings = [];
$probe::packInto($target, ['nope' => 1]);
$after = Bridge::read($target, 0, $probe::size());
if ($after !== $before) {
    $problems[] = 'a refused packInto rewrote the caller\'s memory instead of leaving it alone';
}
if ($warnings === []) {
    $problems[] = 'a refused packInto did not warn';
}
Bridge::free($target);

/* 5. unpack(0) warns and returns null. */
$warnings = [];
$r = $probe::unpack(0);
if ($r !== null) {
    $problems[] = 'unpack(0) returned ' . var_export($r, true) . ', not null';
}
if (count($warnings) !== 1 || !str_contains($warnings[0], 'VkApplicationInfo')) {
    $problems[] = 'unpack(0) did not warn naming the struct: ' . json_encode($warnings);
}

restore_error_handler();

foreach ($problems as $p) {
    $expect->that(false, $p);
}

$expect->finish("STRUCT_GUARD_OK structs={$checked}");
