#!/usr/bin/env php
<?php
/*
 * Whole-package structure check: the things that are true of this repo and
 * would be quietly wrong if a wave forgot one of them.
 *
 *   - config.json and composer.json agree on the version, and both say 0.8.0
 *   - composer.json declares both os-families and excludes Windows
 *   - every class named by an annotation has a .zep, and its method count
 *     matches its annotation count
 *   - every src/*.c is in extra-sources and every extra-sources entry exists
 *   - the vendored registry is present with a provenance README
 *   - no generated file was hand-edited out of its GENERATED banner
 *   - the per-class counts are the ones the design fixed (spec §6)
 *   - the struct tier is four methods per class, no more and no fewer
 *   - src/vk-struct-asserts.c carries a measured layout for every struct
 *   - run-all.php actually runs the guards this repo ships
 *   - every wave's proof exists and carries its success and failure tokens
 *   - the vendored SPIR-V is present, word-aligned and carries the magic word,
 *     and its README records the command that produced it
 *   - scripts/pi-verify.sh runs the current wave's proof, not a retired one
 *
 * Prints STRUCTURE_OK.
 */

declare(strict_types=1);

require __DIR__ . '/lib/harness.php';

$root = dirname(__DIR__, 2);
$expect = new Expect('structure-check');

/**
 * The command surface spec §6 fixed, per class. Changing a number here is a
 * design change, not a refactor. Measured by scripts/gen-vk-src.php against
 * scripts/khronos/vk.xml (VK_HEADER_VERSION 357).
 */
const EXPECTED = [
    'VK\\VK10' => 137,
    'VK\\VK11' => 28,
    'VK\\VK12' => 13,
    'VK\\VK13' => 37,
    'VK\\VK14' => 19,
    'Ext\\KHRSurface' => 5,
    'Ext\\KHRSwapchain' => 9,
    'Ext\\KHRWaylandSurface' => 2,
    'Ext\\KHRXcbSurface' => 2,
    'Ext\\KHRXlibSurface' => 2,
    'Ext\\EXTMetalSurface' => 1,
    'Ext\\EXTMetalObjects' => 1,
    'Ext\\EXTDebugUtils' => 11,
    'Bridge\\Bridge' => 12,
];

/** The struct tier, as a whole. */
const EXPECTED_STRUCTS = 368;
const STRUCT_METHODS = ['pack', 'packInto', 'unpack', 'size'];

// ---- versions
$config = json_decode((string) file_get_contents($root . '/config.json'), true);
$composer = json_decode((string) file_get_contents($root . '/composer.json'), true);
$expect->that(is_array($config), 'config.json is not valid JSON');
$expect->that(is_array($composer), 'composer.json is not valid JSON');
$expect->that(($config['version'] ?? null) === '0.8.0', 'config.json version is not 0.8.0');
$expect->that(($composer['version'] ?? null) === '0.8.0', 'composer.json version is not 0.8.0');
$expect->that(($config['extension-name'] ?? null) === 'vulkan', 'config.json extension-name is not "vulkan"');
$expect->that(($composer['name'] ?? null) === 'php-io-extensions/vulkan', 'composer.json name is wrong');

$families = $composer['php-ext']['os-families'] ?? [];
sort($families);
$expect->that($families === ['darwin', 'linux'], 'composer.json os-families is not [darwin, linux]');
$expect->that(
    !in_array('windows', $families, true),
    'composer.json lists windows; this extension has no Windows half'
);

// ---- vendored registry
foreach (['vk.xml', 'README.md'] as $f) {
    $expect->that(is_file("{$root}/scripts/khronos/{$f}"), "scripts/khronos/{$f} is missing");
}
$khronosReadme = (string) @file_get_contents("{$root}/scripts/khronos/README.md");
$expect->that(
    str_contains($khronosReadme, md5_file("{$root}/scripts/khronos/vk.xml") ?: 'no-md5'),
    "scripts/khronos/README.md does not record the md5 of the vk.xml beside it"
);

// ---- annotations -> classes
$bound = [];
$reserved = [];
$structMethods = [];
foreach (glob("{$root}/src/*.h") ?: [] as $header) {
    foreach (file($header, FILE_IGNORE_NEW_LINES) ?: [] as $line) {
        if (preg_match('#/\*\s*@reserved\s+([A-Za-z0-9_\\\\]+)\s+#', $line, $m)) {
            $reserved[$m[1]] = ($reserved[$m[1]] ?? 0) + 1;
            continue;
        }
        if (preg_match('#/\*\s*@zep(?:-construct)?\s+([A-Za-z0-9_\\\\]+)\s+(\w+)\s*\(#', $line, $m)) {
            $bound[$m[1]] = ($bound[$m[1]] ?? 0) + 1;
            if (str_starts_with($m[1], 'Struct\\')) {
                $structMethods[substr($m[1], 7)][] = $m[2];
            }
        }
    }
}
$expect->that($bound !== [], 'no annotations found under src/');

foreach (EXPECTED as $classPath => $count) {
    $expect->that(
        ($bound[$classPath] ?? 0) === $count,
        "{$classPath} binds " . ($bound[$classPath] ?? 0) . " method(s), the design fixed {$count}"
    );
}

// ---- the struct tier
$expect->that(
    count($structMethods) === EXPECTED_STRUCTS,
    'the struct tier has ' . count($structMethods) . ' class(es), the design fixed ' . EXPECTED_STRUCTS
);
foreach ($structMethods as $name => $methods) {
    sort($methods);
    $wanted = STRUCT_METHODS;
    sort($wanted);
    if ($methods !== $wanted) {
        $expect->that(false, "Struct\\{$name} has [" . implode(', ', $methods)
            . '], expected [' . implode(', ', $wanted) . ']');
    }
}

// ---- the layout asserts: one sizeof per struct, one offsetof per member
$asserts = (string) @file_get_contents($root . '/src/vk-struct-asserts.c');
$expect->that($asserts !== '', 'src/vk-struct-asserts.c is missing');
$sizeofs = preg_match_all('/^_Static_assert\(sizeof\(/m', $asserts);
$offsets = preg_match_all('/^_Static_assert\(offsetof\(/m', $asserts);
$expect->that(
    $sizeofs === EXPECTED_STRUCTS,
    "src/vk-struct-asserts.c has {$sizeofs} sizeof assertion(s), the struct tier has " . EXPECTED_STRUCTS
);
$expect->that(
    $offsets > $sizeofs,
    'src/vk-struct-asserts.c asserts no member offsets; a size that matches is not a layout that matches'
);
$expect->that(
    in_array('src/vk-struct-asserts.c', $config['extra-sources'] ?? [], true),
    'src/vk-struct-asserts.c is not in extra-sources, so no build ever checks it'
);

// ---- the wave's guards are actually in the runner
$runAll = (string) @file_get_contents(__DIR__ . '/run-all.php');
foreach (['loader-guard.php', 'struct-guard.php'] as $guard) {
    $expect->that(is_file(__DIR__ . '/' . $guard), "scripts/tests/{$guard} is missing");
    $expect->that(
        str_contains($runAll, "'{$guard}'"),
        "scripts/tests/{$guard} exists but run-all.php never runs it"
    );
}

// ---- every class has a .zep with the right method count
foreach ($bound as $classPath => $count) {
    $segments = explode('\\', $classPath);
    $class = end($segments);
    if (count($segments) >= 2 && $segments[count($segments) - 1] === $segments[count($segments) - 2]) {
        array_pop($segments);
    }
    $zep = $root . '/vulkan/' . implode('/', array_map('strtolower', $segments))
        . '/' . strtolower($class) . '.zep';
    if (!is_file($zep)) {
        $expect->that(false, "{$classPath} has no generated .zep at " . substr($zep, strlen($root) + 1));
        continue;
    }
    $src = (string) file_get_contents($zep);
    $methods = preg_match_all('/public static function /', $src);
    $expect->that(
        $methods === $count,
        "{$classPath}: {$count} annotation(s) but {$methods} method(s) in the .zep"
    );
    $expect->that(
        str_contains($src, 'GENERATED by scripts/gen-zep.php'),
        "{$classPath}: the .zep lost its GENERATED banner"
    );
}

// ---- extra-sources
$listed = $config['extra-sources'] ?? [];
$onDisk = array_map(
    static fn (string $p): string => 'src/' . basename($p),
    glob("{$root}/src/*.c") ?: []
);
sort($listed);
sort($onDisk);
$expect->that($listed === $onDisk, 'config.json extra-sources does not match src/*.c on disk');

// ---- generated banners, and the hand-written files that must NOT carry one
foreach (glob("{$root}/src/vk-*.[ch]") ?: [] as $f) {
    $head = (string) file_get_contents($f, false, null, 0, 400);
    $expect->that(
        str_contains($head, 'GENERATED by scripts/gen-vk-src.php'),
        basename($f) . ' lost its GENERATED banner'
    );
}
foreach (['phpvk-registry.h', 'phpvk-registry.c'] as $f) {
    $head = (string) @file_get_contents("{$root}/src/{$f}", false, null, 0, 400);
    $expect->that(
        str_contains($head, 'GENERATED by scripts/gen-vk-src.php'),
        "{$f} lost its GENERATED banner"
    );
}
foreach (['phpvk-support.h', 'phpvk-support.c', 'phpvk-bridge.h', 'phpvk-bridge.c', 'phpvk-platform.h'] as $f) {
    $expect->that(is_file("{$root}/src/{$f}"), "src/{$f} is missing");
    $head = (string) @file_get_contents("{$root}/src/{$f}", false, null, 0, 800);
    $expect->that(
        !str_contains($head, 'GENERATED by scripts/gen-vk-src.php'),
        "src/{$f} is hand-written and must not claim to be generated"
    );
}

// ---- every wave's proof
foreach (['proof_enumerate' => 'PROOF_ENUMERATE_OK', 'proof_headless' => 'PROOF_HEADLESS_OK'] as $name => $token) {
    $proof = (string) @file_get_contents("{$root}/examples/{$name}.php");
    $expect->that($proof !== '', "examples/{$name}.php is missing");
    $expect->that(
        str_contains($proof, $token),
        "{$name}.php has no success token"
    );
    $expect->that(
        str_contains($proof, str_replace('_OK', '_FAILED', $token) . ': '),
        "{$name}.php has no named failure token"
    );
    $expect->that(
        preg_match_all('/PHP_OS_FAMILY\s*===/', $proof) === 1,
        "{$name}.php branches on PHP_OS_FAMILY in more than one place;"
        . ' portability enumeration is one decision, made once'
    );
}

// ---- the vendored SPIR-V the headless proof draws with
foreach (['triangle.vert', 'triangle.frag'] as $stage) {
    $glsl = "{$root}/examples/shaders/{$stage}";
    $spv = "{$glsl}.spv";
    $expect->that(is_file($glsl), "examples/shaders/{$stage} is missing");
    $expect->that(is_file($spv), "examples/shaders/{$stage}.spv is missing (vendored, not built)");
    $bytes = (string) @file_get_contents($spv);
    $expect->that(
        strlen($bytes) >= 20 && strlen($bytes) % 4 === 0,
        "examples/shaders/{$stage}.spv is not a whole number of SPIR-V words"
    );
    $expect->that(
        strlen($bytes) >= 4 && unpack('V', substr($bytes, 0, 4))[1] === 0x07230203,
        "examples/shaders/{$stage}.spv does not begin with the SPIR-V magic word"
    );
}
$shaderReadme = (string) @file_get_contents($root . '/examples/shaders/README.md');
$expect->that(
    str_contains($shaderReadme, 'glslangValidator -V'),
    'examples/shaders/README.md does not record the command that produced the .spv files'
);

// ---- pi-verify runs the current wave's proof, not a retired one
$piVerify = (string) @file_get_contents($root . '/scripts/pi-verify.sh');
$expect->that(
    str_contains($piVerify, 'examples/proof_headless.php')
    && str_contains($piVerify, 'PROOF_HEADLESS_OK'),
    'scripts/pi-verify.sh does not run the headless proof'
);

$expect->finish('STRUCTURE_OK');
