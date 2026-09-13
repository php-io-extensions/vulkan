#!/usr/bin/env php
<?php
/**
 * audit-registry.php — nothing silently omitted.
 *
 * ext-opengl audits against prototype counts in vendored C headers; the
 * audit truth here is the vendored Khronos registry, `scripts/khronos/vk.xml`,
 * walked by the same `scripts/lib/registry.php` the generator walks. Sharing
 * the walk is deliberate: an audit that re-implements the generator's reading
 * of the registry audits the re-implementation, not the registry. What is
 * independent here is the *source* of the counts — the markers in `src/*.h`
 * were written by a past run of the generator, and this re-measures them
 * against the file on disk today.
 *
 * Per bound class the rule is the house rule:
 *
 *     bound + reserved  ==  the class's @audit marker  ==  the registry's count
 *
 * Markers, all one line, all in src/*.h:
 *
 *   /*@audit feature VK\VK10 VK_VERSION_1_0 137 * /
 *       class VK\VK10 covers VK_VERSION_1_0, which has 137 commands.
 *   /*@audit extension Ext\KHRSurface VK_KHR_surface 5 * /
 *       same, for an extension.
 *   /*@audit partial VK\VK14 <reason> * /
 *       sanctions bound+reserved falling SHORT of the registry count (never
 *       an excess) while a class is deliberately incomplete.
 *
 * The struct tier is audited as a whole rather than per file, because a
 * struct's file is an artefact of which block first required it and carries
 * no meaning: every scoped struct or union must have exactly four
 * annotations (pack, packInto, unpack, size) under `Struct\<Name>`, and
 * there must be no Struct\ class the registry does not put in scope.
 *
 * Class-level coverage is not enough for that tier, though. A class with its
 * four methods can still be missing a MEMBER, and nothing above would see
 * it: the struct would pack short, the bytes Vulkan reads would be zero, and
 * the failure would surface somewhere else entirely. So the audit also goes
 * member by member (Wave 1): for every member the registry declares for a
 * scoped struct, the emitted `phpvk_fill_<T>` body must mention `s-><member>`
 * and the emitted `phpvk_read_<T>` body must too, and the member must appear
 * in that struct's `phpvk_names_<T>` key list — which is what makes an
 * unknown key a refusal rather than a silent drop.
 *
 * A member the type table cannot express is NOT what this catches: the
 * generator fails by name on one of those (`renderMember`), so it never
 * reaches a body. What this catches is a member that went missing — an
 * emitter branch that fell through, a hand-edit, or a re-vendored registry
 * that grew a member an old generated tree does not have.
 *
 * Prints `structs=<n> members=<m>` — the member-level coverage total — before
 * AUDIT_OK.
 *
 * Usage: php scripts/audit-registry.php [root]
 */

declare(strict_types=1);

require __DIR__ . '/lib/registry.php';

const STRUCT_METHODS = ['pack', 'packInto', 'unpack', 'size'];

$failures = [];

function problem(string $msg): void
{
    global $failures;
    $failures[] = $msg;
}

/**
 * The struct tier's emitted bodies, read back out of src/*.c.
 *
 * A generated body is `int phpvk_fill_<T>(<T> *s, …)\n{\n…\n}` at column 0,
 * so the shape is enough to find it without a C parser. The key list is the
 * `phpvk_names_<T>[]` initialiser beside it.
 *
 * @return array{
 *   fill: array<string, string>,
 *   read: array<string, string>,
 *   names: array<string, list<string>>,
 * }
 */
function structBodies(string $root): array
{
    $fill = [];
    $read = [];
    $names = [];

    foreach (glob("{$root}/src/*.c") ?: [] as $path) {
        $src = (string) file_get_contents($path);

        if (preg_match_all('/^int phpvk_fill_(\w+)\(\w+ \*s, zval \*members, const char \*ctx\)\n\{\n(.*?)\n\}$/ms', $src, $m, PREG_SET_ORDER)) {
            foreach ($m as $hit) {
                $fill[$hit[1]] = $hit[2];
            }
        }
        if (preg_match_all('/^void phpvk_read_(\w+)\(zval \*out, const \w+ \*s\)\n\{\n(.*?)\n\}$/ms', $src, $m, PREG_SET_ORDER)) {
            foreach ($m as $hit) {
                $read[$hit[1]] = $hit[2];
            }
        }
        if (preg_match_all('/^static const char \*const phpvk_names_(\w+)\[\] = \{(.*?)\};$/m', $src, $m, PREG_SET_ORDER)) {
            foreach ($m as $hit) {
                preg_match_all('/"([^"]*)"/', $hit[2], $keys);
                $names[$hit[1]] = $keys[1];
            }
        }
    }

    return ['fill' => $fill, 'read' => $read, 'names' => $names];
}

// ------------------------------------------------------------------- parse

$root = isset($argv[1]) ? rtrim($argv[1], '/') : dirname(__DIR__);

$bound = [];        // classPath => count of @zep
$reserved = [];     // classPath => count of @reserved
$markers = [];      // classPath => ['kind' => feature|extension, 'block' => ..., 'count' => ...]
$partials = [];     // classPath => reason
$structMethods = [];// struct name => [method => true]

foreach (glob("{$root}/src/*.h") ?: [] as $path) {
    $rel = 'src/' . basename($path);
    foreach (file($path, FILE_IGNORE_NEW_LINES) ?: [] as $no => $line) {
        if (preg_match('#/\*\s*@audit\s+(feature|extension)\s+([A-Za-z0-9_\\\\]+)\s+(\S+)\s+(\d+)\s*\*/#', $line, $m)) {
            if (isset($markers[$m[2]])) {
                problem("{$rel}:" . ($no + 1) . " duplicate @audit marker for {$m[2]}");
            }
            $markers[$m[2]] = ['kind' => $m[1], 'block' => $m[3], 'count' => (int) $m[4]];
            continue;
        }
        if (preg_match('#/\*\s*@audit\s+partial\s+([A-Za-z0-9_\\\\]+)\s+(.*?)\s*\*/#', $line, $m)) {
            $partials[$m[1]] = $m[2];
            continue;
        }
        if (preg_match('#/\*\s*@reserved\s+([A-Za-z0-9_\\\\]+)\s+#', $line, $m)) {
            $reserved[$m[1]] = ($reserved[$m[1]] ?? 0) + 1;
            continue;
        }
        if (preg_match('#/\*\s*@zep(?:-construct)?\s+([A-Za-z0-9_\\\\]+)\s+(\w+)\s*\(#', $line, $m)) {
            $bound[$m[1]] = ($bound[$m[1]] ?? 0) + 1;
            if (str_starts_with($m[1], 'Struct\\')) {
                $structMethods[substr($m[1], 7)][$m[2]] = true;
            }
        }
    }
}

if ($bound === []) {
    fwrite(STDERR, "audit: no annotations found under {$root}/src\n");
    exit(1);
}

// ------------------------------------------------------ measure the registry

$reg = vkRegistryLoad("{$root}/scripts/khronos/vk.xml");
$scope = vkRegistryScope($reg);

$measured = [];      // classPath => command count
$measuredBlock = []; // classPath => registry block name
foreach (VK_FEATURES as $feature => $class) {
    $measured["VK\\{$class}"] = count($scope['commands'][$class]['names']);
    $measuredBlock["VK\\{$class}"] = $feature;
}
foreach (VK_EXTENSIONS as $extension => $class) {
    if ($class === null) {
        continue;
    }
    $measured["Ext\\{$class}"] = count($scope['commands'][$class]['names']);
    $measuredBlock["Ext\\{$class}"] = $extension;
}

$measuredStructs = [];
foreach ($scope['structs'] as $bucket) {
    foreach ($bucket['names'] as $n) {
        $measuredStructs[$n] = true;
    }
}

// -------------------------------------------- re-measure every @audit marker

foreach ($markers as $classPath => $marker) {
    if (!isset($measured[$classPath])) {
        problem("{$classPath}: an @audit marker names a class the registry scope does not have");
        continue;
    }
    if ($marker['block'] !== $measuredBlock[$classPath]) {
        problem("{$classPath}: @audit names block '{$marker['block']}', the scope says '"
            . $measuredBlock[$classPath] . "'");
    }
    if ($marker['count'] !== $measured[$classPath]) {
        problem("{$classPath}: @audit {$marker['block']} claims {$marker['count']}, the registry has "
            . $measured[$classPath] . ' — re-run scripts/gen-vk-src.php');
    }
}

// --------------------------------------------------- every class has a marker

foreach ($measured as $classPath => $n) {
    if (!isset($markers[$classPath])) {
        problem("{$measuredBlock[$classPath]} has {$n} command(s) and no class claims it");
    }
}

// -------------------------------------------------------------- the verdict

$classes = array_values(array_unique(array_merge(
    array_keys($markers),
    array_keys($measured),
    array_filter(array_keys($bound), static fn (string $c): bool => !str_starts_with($c, 'Struct\\'))
)));
sort($classes);

$audited = 0;
$skipped = 0;

printf("%-26s %10s %7s %9s  %s\n", 'class', 'registry', 'bound', 'reserved', 'verdict');
foreach ($classes as $classPath) {
    $b = $bound[$classPath] ?? 0;
    $r = $reserved[$classPath] ?? 0;

    if (!isset($markers[$classPath])) {
        // Bridge is glue: it has no registry counterpart to audit against.
        printf("%-26s %10s %7d %9d  %s\n", $classPath, '—', $b, $r, 'SKIP (glue)');
        $skipped++;
        continue;
    }

    $registry = $markers[$classPath]['count'];
    $verdict = 'OK';
    if ($b + $r > $registry) {
        $verdict = 'EXCESS';
        problem("{$classPath}: bound+reserved=" . ($b + $r) . " exceeds the registry's {$registry}");
    } elseif ($b + $r < $registry) {
        if (isset($partials[$classPath])) {
            $verdict = 'PARTIAL';
        } else {
            $verdict = 'SHORT';
            problem("{$classPath}: bound+reserved=" . ($b + $r) . " is short of the registry's {$registry}"
                . ' — bind it, reserve it, or mark the class @audit partial');
        }
    }

    printf("%-26s %10d %7d %9d  %s\n", $classPath, $registry, $b, $r, $verdict);
    $audited++;
}

// ------------------------------------------------------------- struct tier

$structClasses = 0;
$structMethodCount = 0;
foreach ($structMethods as $name => $methods) {
    $structClasses++;
    $structMethodCount += count($methods);
    if (!isset($measuredStructs[$name])) {
        problem("Struct\\{$name}: bound, but the registry scope does not contain it");
        continue;
    }
    foreach (STRUCT_METHODS as $method) {
        if (!isset($methods[$method])) {
            problem("Struct\\{$name}: no {$method}() annotation");
        }
    }
    if (count($methods) !== count(STRUCT_METHODS)) {
        problem("Struct\\{$name}: " . count($methods) . ' annotation(s), expected ' . count(STRUCT_METHODS));
    }
}
foreach (array_keys($measuredStructs) as $name) {
    if (!isset($structMethods[$name])) {
        problem("{$name} is in the registry scope and has no Struct\\{$name} class");
    }
}

printf(
    "\nstructs=%d/%d methods=%d\n",
    $structClasses,
    count($measuredStructs),
    $structMethodCount
);

// ------------------------------------------------------ struct tier, members

/*
 * Every member the registry declares must be visible in the emitted bodies.
 * Missing one is not a shortfall that can be sanctioned — there is no
 * @audit partial for a member — because a member the table cannot express
 * stops the generator by name and so never reaches a body at all.
 */
$bodies = structBodies($root);
$memberCount = 0;
$memberStructs = 0;

foreach (array_keys($measuredStructs) as $name) {
    $members = $reg['types'][$name]['members'] ?? [];
    if ($members === []) {
        problem("{$name}: the registry scopes it and it declares no member");
        continue;
    }
    $memberStructs++;

    $fillBody = $bodies['fill'][$name] ?? null;
    $readBody = $bodies['read'][$name] ?? null;
    $keys = $bodies['names'][$name] ?? null;

    if ($fillBody === null) {
        problem("{$name}: no phpvk_fill_{$name}() body in src/*.c");
    }
    if ($readBody === null) {
        problem("{$name}: no phpvk_read_{$name}() body in src/*.c");
    }
    if ($keys === null) {
        problem("{$name}: no phpvk_names_{$name}[] key list in src/*.c");
    }

    foreach ($members as $member) {
        $memberCount++;
        $key = $member['name'];
        $ref = '/\bs->' . preg_quote($key, '/') . '\b/';

        if ($fillBody !== null && !preg_match($ref, $fillBody)) {
            problem("{$name}.{$key}: the registry declares it and phpvk_fill_{$name}() never writes it"
                . ' — a member is bound or the generator stops by name, never skipped');
        }
        if ($readBody !== null && !preg_match($ref, $readBody)) {
            problem("{$name}.{$key}: the registry declares it and phpvk_read_{$name}() never reads it back");
        }
        if ($keys !== null && !in_array($key, $keys, true)) {
            problem("{$name}.{$key}: missing from phpvk_names_{$name}[], so passing it would warn as unknown");
        }
    }

    if ($keys !== null) {
        $declared = array_map(static fn (array $m): string => $m['name'], $members);
        foreach ($keys as $key) {
            if (!in_array($key, $declared, true)) {
                problem("{$name}.{$key}: phpvk_names_{$name}[] accepts a key the registry does not declare");
            }
        }
    }
}

printf("structs=%d members=%d\n", $memberStructs, $memberCount);

printf("audited=%d skipped=%d failures=%d\n", $audited, $skipped, count($failures));

if ($failures !== []) {
    foreach ($failures as $f) {
        fwrite(STDERR, "audit: {$f}\n");
    }
    fwrite(STDERR, 'AUDIT_FAILED (' . count($failures) . ")\n");
    exit(1);
}

echo "AUDIT_OK\n";
