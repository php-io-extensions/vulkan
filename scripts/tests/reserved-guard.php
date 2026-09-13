#!/usr/bin/env php
<?php
/*
 * The "nothing silently omitted" path, proved rather than asserted.
 *
 * One kind of command cannot be bound, and it must appear as a visible
 * @reserved line rather than stopping the generator or vanishing:
 *
 *   callback   a function-pointer PARAMETER. PHP cannot be a C function
 *              pointer and this extension has no callback glue. There is
 *              none in the bound surface today — VK_EXT_debug_utils hides
 *              its PFN behind a struct member, which is bits — so this test
 *              builds a SCRATCH copy of the vendored registry with one
 *              injected into VK_VERSION_1_0 and checks the emitted line.
 *              The committed tree is never touched.
 *
 * Also checks the other half of the rule: a type the table does not cover is
 * still a HARD FAILURE that names the type, so a new spelling in a
 * re-vendored registry cannot quietly shrink the surface.
 *
 * Prints RESERVED_GUARD_OK.
 */

declare(strict_types=1);

require __DIR__ . '/lib/harness.php';

$scripts = dirname(__DIR__);
$root = dirname($scripts);
$expect = new Expect('reserved-guard');

/**
 * Stage a package whose vendored registry has one extra command in
 * VK_VERSION_1_0, with the parameters given as registry XML.
 */
function scratchRegistry(string $root, string $scripts, string $command, string $params): string
{
    $pkg = sys_get_temp_dir() . '/phpvk-reserved-' . bin2hex(random_bytes(6));
    mkdir($pkg . '/scripts/lib', 0755, true);
    mkdir($pkg . '/scripts/khronos', 0755, true);
    mkdir($pkg . '/src', 0755, true);
    register_shutdown_function(static function () use ($pkg): void {
        removeTree($pkg);
    });

    copy($scripts . '/gen-vk-src.php', $pkg . '/scripts/gen-vk-src.php');
    copy($scripts . '/lib/registry.php', $pkg . '/scripts/lib/registry.php');
    // The generator's layout probe includes the platform shim, so a scratch
    // package needs it before gen-vk-src.php will run at all.
    copy($root . '/src/phpvk-platform.h', $pkg . '/src/phpvk-platform.h');
    copy($root . '/config.json', $pkg . '/config.json');

    $xml = (string) file_get_contents($root . '/scripts/khronos/vk.xml');

    $injected = "\n         <command>\n"
        . "             <proto><type>void</type> <name>{$command}</name></proto>\n"
        . "             <param><type>VkInstance</type> <name>instance</name></param>\n"
        . $params
        . "         </command>\n";
    $at = strpos($xml, '<commands');
    if ($at === false) {
        fwrite(STDERR, "reserved-guard: the vendored registry has no <commands> element\n");
        exit(1);
    }
    $at = strpos($xml, '>', $at) + 1;
    $xml = substr($xml, 0, $at) . $injected . substr($xml, $at);

    if (!preg_match('/<feature[^>]*name="VK_VERSION_1_0"[^>]*>/', $xml, $m, PREG_OFFSET_CAPTURE)) {
        fwrite(STDERR, "reserved-guard: the vendored registry has no VK_VERSION_1_0 feature\n");
        exit(1);
    }
    $at = $m[0][1] + strlen($m[0][0]);
    $xml = substr($xml, 0, $at)
        . "\n        <require><command name=\"{$command}\" /></require>\n"
        . substr($xml, $at);

    file_put_contents($pkg . '/scripts/khronos/vk.xml', $xml);

    return $pkg;
}

// ---- 1. a callback parameter is reserved, not fatal ------------------------
$pkg = scratchRegistry(
    $root,
    $scripts,
    'vkFixtureCallbackCommand',
    "             <param><type>PFN_vkVoidFunction</type> <name>pfnCallback</name></param>\n"
);
[$code, $text] = runScript($pkg . '/scripts/gen-vk-src.php');

$expect->that(
    $code === 0 && str_contains($text, 'GEN_SRC_OK'),
    "the generator died on a registry containing a PFN parameter instead of reserving it:\n{$text}"
);
$expect->that(
    (bool) preg_match('/reserved=([1-9]\d*)/', $text),
    "the generator reported no reservations at all:\n{$text}"
);

$vk10 = $pkg . '/src/vk-10.h';
$expect->that(is_file($vk10), 'the scratch generator produced no src/vk-10.h');
if (is_file($vk10)) {
    $h = (string) file_get_contents($vk10);

    $line = null;
    foreach (explode("\n", $h) as $l) {
        if (str_contains($l, '@reserved') && str_contains($l, 'vkFixtureCallbackCommand')) {
            $line = trim($l);
            break;
        }
    }
    $expect->that($line !== null, 'the injected command has no @reserved line in the scratch src/vk-10.h');
    if ($line !== null) {
        echo "reserved-guard: emitted line is\n  {$line}\n";
        $expect->that(str_contains($line, 'VK\\VK10'), 'the @reserved line names the wrong class');
        $expect->that(str_contains($line, 'PFN_vkVoidFunction'), 'the @reserved line does not name the function pointer');
        $expect->that(str_contains($line, 'callback'), 'the @reserved line does not give the callback reason');
        $expect->that(
            (bool) preg_match('#^/\*@reserved\s+[A-Za-z0-9_\\\\]+\s+.*\*/$#', $line),
            'the @reserved line does not match the grammar gen-zep.php parses'
        );
    }

    $expect->that(
        !preg_match('/@zep\s+\S+\s+vkFixtureCallbackCommand\s*\(/', $h),
        'the injected command was bound as well as reserved'
    );

    // bound + reserved must still equal the block's registry count.
    preg_match('/@audit feature \S+ VK_VERSION_1_0 (\d+)/', $h, $bm);
    $registry = isset($bm[1]) ? (int) $bm[1] : -1;
    $bound = preg_match_all('/@zep\s+VK\\\\VK10\s+/', $h);
    $reserved = preg_match_all('/@reserved\s+VK\\\\VK10\s+/', $h);
    $expect->that(
        $registry > 0 && $bound + $reserved === $registry,
        "vk-10.h accounts for {$bound}+{$reserved} of {$registry} commands — the audit sum must be exact"
    );
    echo "reserved-guard: scratch VK_VERSION_1_0 registry={$registry} bound={$bound} reserved={$reserved}\n";
}

// ---- 2. an unclassified type is still a hard failure -----------------------
$pkg2 = scratchRegistry(
    $root,
    $scripts,
    'vkFixtureUnknownTypeCommand',
    "             <param><type>FooBar</type> <name>thing</name></param>\n"
);
[$code, $text] = runScript($pkg2 . '/scripts/gen-vk-src.php');
$expect->that($code !== 0, 'the generator reserved an unclassified type instead of failing');
$expect->that(
    str_contains($text, 'unsupported parameter type') && str_contains($text, 'FooBar'),
    "the generator failed without naming the unclassified type:\n{$text}"
);

// ---- 3. the committed tree reserves nothing, and says so -------------------
$reservedInTree = 0;
foreach (glob($root . '/src/*.h') ?: [] as $header) {
    $reservedInTree += preg_match_all('/@reserved\s+/', (string) file_get_contents($header));
}
$expect->that(
    $reservedInTree === 0,
    "the committed tree has {$reservedInTree} @reserved line(s); the type table covers"
    . ' every command in scope today, so any reservation is news that belongs in .okf/log.md'
);

$expect->finish('RESERVED_GUARD_OK');
