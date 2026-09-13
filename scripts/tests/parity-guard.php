#!/usr/bin/env php
<?php
/*
 * Negative controls for check-parity.php — one per thing it claims to catch.
 *
 *   good              a sound package must pass (a guard that always fails
 *                     proves nothing either)
 *   composite         a body that calls through its resolved pointer twice
 *   linktime          a body that calls vkDestroyInstance by name instead of
 *                     through fn
 *   extra-sources     a src/*.c that config.json does not list
 *   support-linktime  a direct Vulkan call in a file with NO annotations at
 *                     all, which the per-body composite check cannot see
 *   struct-native-call a Struct\<Name> method that names a Vulkan symbol, and
 *                     another that resolves an entry point and calls through
 *                     it — a struct method is flat memory work and must do
 *                     neither
 *
 * Each fixture is generated first (gen-zep), because parity compares the
 * .zep tree and the optimizers against the annotations.
 *
 * Prints PARITY_GUARD_OK.
 */

declare(strict_types=1);

require __DIR__ . '/lib/harness.php';

$scripts = dirname(__DIR__);
$expect = new Expect('parity-guard');

function preparedFixture(string $name, Expect $expect, string $scripts): string
{
    $dir = stageFixture(__DIR__ . '/fixtures/' . $name);
    [$code, $text] = runScript($scripts . '/gen-zep.php', [$dir]);
    $expect->that($code === 0, "gen-zep could not prepare the '{$name}' fixture:\n{$text}");

    return $dir;
}

// ---- positive control
$dir = preparedFixture('good', $expect, $scripts);
[$code, $text] = runScript($scripts . '/check-parity.php', [$dir]);
$expect->that(
    $code === 0 && str_contains($text, 'PARITY_OK'),
    "check-parity rejected a sound package:\n{$text}"
);

// ---- composite: two calls through one entry point
$dir = preparedFixture('composite', $expect, $scripts);
[$code, $text] = runScript($scripts . '/check-parity.php', [$dir]);
$expect->that($code !== 0, 'check-parity accepted two native calls in one binding');
$expect->that(
    str_contains($text, 'one PHP static method = one native call'),
    "check-parity failed without the composite diagnostic:\n{$text}"
);

// ---- link-time: a call by name instead of through the loader
$dir = preparedFixture('linktime', $expect, $scripts);
[$code, $text] = runScript($scripts . '/check-parity.php', [$dir]);
$expect->that($code !== 0, 'check-parity accepted a link-time Vulkan call');
$expect->that(
    str_contains($text, 'resolved at runtime') && str_contains($text, 'vkDestroyInstance'),
    "check-parity failed without naming the link-time call:\n{$text}"
);

// ---- extra-sources: a source the build would never compile
$dir = preparedFixture('extra-sources', $expect, $scripts);
[$code, $text] = runScript($scripts . '/check-parity.php', [$dir]);
$expect->that($code !== 0, 'check-parity accepted an unlisted src/*.c');
$expect->that(
    str_contains($text, 'not in config.json extra-sources'),
    "check-parity failed without the extra-sources diagnostic:\n{$text}"
);

// ---- a link-time call in a file the composite guard never inspects
$dir = preparedFixture('support-linktime', $expect, $scripts);
[$code, $text] = runScript($scripts . '/check-parity.php', [$dir]);
$expect->that($code !== 0, 'check-parity accepted a link-time Vulkan call in an unannotated file');
$expect->that(
    str_contains($text, 'phpvk-support.c') && str_contains($text, 'vkDeviceWaitIdle'),
    "check-parity did not name the offending file and call:\n{$text}"
);

// ---- the struct tier makes no Vulkan call, by name or through the loader
$dir = preparedFixture('struct-native-call', $expect, $scripts);
[$code, $text] = runScript($scripts . '/check-parity.php', [$dir]);
$expect->that($code !== 0, 'check-parity accepted a struct method that calls Vulkan');
$expect->that(
    str_contains($text, 'vkGetInstanceProcAddr'),
    "check-parity did not name the symbol the struct method called:\n{$text}"
);
$expect->that(
    str_contains($text, 'a struct method is flat memory work'),
    "check-parity failed without the struct-tier composite diagnostic:\n{$text}"
);

$expect->finish('PARITY_GUARD_OK');
