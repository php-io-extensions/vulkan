#!/usr/bin/env php
<?php
/**
 * patch-mshutdown.php — give the extension a module teardown.
 *
 * Zephir emits a PHP_MSHUTDOWN_FUNCTION but wraps both the function and its
 * module-entry slot in `#ifndef ZEPHIR_RELEASE`, and the generated
 * php_vulkan.h defines ZEPHIR_RELEASE — so a built extension has no module
 * shutdown at all. Nothing in this repo could hook one without saying so.
 *
 * This extension needs one. Its byte buffers are plain malloc'd and tracked
 * in a process-global registry, and the loader holds dlopen handles; both
 * outlive every request and nothing else will ever reclaim them.
 *
 * Three targeted edits to the generated ext/<name>.c, each verified after
 * writing, so a Zephir template change fails the build instead of silently
 * dropping the teardown:
 *
 *   1. include the Bridge header
 *   2. unwrap the MSHUTDOWN function from #ifndef ZEPHIR_RELEASE and call
 *      phpvk_bridge_shutdown() first thing in its body
 *   3. point the module entry at it unconditionally
 *
 * Idempotent: a marker comment is checked first.
 *
 * Usage: php scripts/patch-mshutdown.php <path-to-ext/vulkan.c>
 */

declare(strict_types=1);

const MARKER = 'PHPVK module teardown';

$path = $argv[1] ?? '';
if ($path === '' || !is_file($path)) {
    fwrite(STDERR, "patch-mshutdown: usage: patch-mshutdown.php <ext/vulkan.c>\n");
    exit(1);
}

$src = (string) file_get_contents($path);

if (str_contains($src, MARKER)) {
    echo "patch-mshutdown: already patched\n";
    exit(0);
}

$problems = [];

// ---- 1. include the Bridge header -----------------------------------------
if (!str_contains($src, '#include "src/phpvk-bridge.h"')) {
    $anchor = '#include "php_ext.h"';
    if (!str_contains($src, $anchor)) {
        $problems[] = "could not find {$anchor} to anchor the include";
    } else {
        $src = str_replace(
            $anchor,
            $anchor . "\n\n/* " . MARKER . " */\n#include \"src/phpvk-bridge.h\"",
            $src
        );
    }
}

// ---- 2. the MSHUTDOWN function --------------------------------------------
$fn = "#ifndef ZEPHIR_RELEASE\nstatic PHP_MSHUTDOWN_FUNCTION(vulkan)\n{\n";
if (!str_contains($src, $fn)) {
    $problems[] = 'could not find the #ifndef ZEPHIR_RELEASE MSHUTDOWN function';
} else {
    $src = str_replace(
        $fn,
        "static PHP_MSHUTDOWN_FUNCTION(vulkan)\n{\n"
        . "\t/* " . MARKER . ": free the byte buffers the caller did not,\n"
        . "\t * destroy the registry, and close the loader's dlopen handles. */\n"
        . "\tphpvk_bridge_shutdown();\n",
        $src
    );
    // The #endif that closed that block now closes nothing; it sits right
    // after the function's own closing brace.
    $tail = "\tUNREGISTER_INI_ENTRIES();\n\treturn SUCCESS;\n}\n#endif\n";
    if (!str_contains($src, $tail)) {
        $problems[] = 'could not find the MSHUTDOWN function tail to unwrap';
    } else {
        $src = str_replace(
            $tail,
            "\tUNREGISTER_INI_ENTRIES();\n\treturn SUCCESS;\n}\n",
            $src
        );
    }
}

// ---- 3. the module entry --------------------------------------------------
$entry = "#ifndef ZEPHIR_RELEASE\n\tPHP_MSHUTDOWN(vulkan),\n#else\n\tNULL,\n#endif\n";
if (!str_contains($src, $entry)) {
    $problems[] = 'could not find the conditional PHP_MSHUTDOWN module-entry slot';
} else {
    $src = str_replace($entry, "\tPHP_MSHUTDOWN(vulkan),\n", $src);
}

if ($problems !== []) {
    foreach ($problems as $p) {
        fwrite(STDERR, "patch-mshutdown: {$p}\n");
    }
    fwrite(STDERR, "patch-mshutdown: refusing to write a half-patched {$path}\n");
    exit(1);
}

if (file_put_contents($path, $src) === false) {
    fwrite(STDERR, "patch-mshutdown: cannot write {$path}\n");
    exit(1);
}

// ---- verify ---------------------------------------------------------------
$check = (string) file_get_contents($path);
$required = [
    MARKER => 'the marker comment',
    '#include "src/phpvk-bridge.h"' => 'the Bridge include',
    'phpvk_bridge_shutdown();' => 'the teardown call',
    "\tPHP_MSHUTDOWN(vulkan),\n" => 'the unconditional module-entry slot',
];
foreach ($required as $needle => $what) {
    if (!str_contains($check, $needle)) {
        fwrite(STDERR, "patch-mshutdown: {$what} is not present after writing\n");
        exit(1);
    }
}
if (preg_match('/#ifndef ZEPHIR_RELEASE\s*\n\s*PHP_MSHUTDOWN/', $check)) {
    fwrite(STDERR, "patch-mshutdown: the module entry is still conditional\n");
    exit(1);
}

echo "patch-mshutdown: PATCH_OK\n";
