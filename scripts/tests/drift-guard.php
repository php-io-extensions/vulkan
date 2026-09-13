#!/usr/bin/env php
<?php
/*
 * Negative control for gen-zep.php.
 *
 * The fixture's annotation promises two parameters and its C prototype has
 * one. The generator must exit non-zero, say so, and write nothing — a
 * half-generated tree is worse than no tree.
 *
 * Prints DRIFT_GUARD_OK.
 */

declare(strict_types=1);

require __DIR__ . '/lib/harness.php';

$scripts = dirname(__DIR__);
$expect = new Expect('drift-guard');

$bad = stageFixture(__DIR__ . '/fixtures/drift');
[$code, $text] = runScript($scripts . '/gen-zep.php', [$bad]);

$expect->that($code !== 0, "gen-zep accepted a drifted header (exit {$code})\n{$text}");
$expect->that(str_contains($text, 'parameter'), "gen-zep failed without a drift diagnostic:\n{$text}");
$expect->that(!str_contains($text, 'GEN_OK'), 'gen-zep printed GEN_OK despite failing');
$expect->that(
    (glob("{$bad}/vulkan/*") ?: []) === [] && (glob("{$bad}/optimizers/*") ?: []) === [],
    'gen-zep wrote output despite the drift'
);

// Positive control: the same generator on a sound fixture must succeed.
$good = stageFixture(__DIR__ . '/fixtures/good');
[$code, $text] = runScript($scripts . '/gen-zep.php', [$good]);
$expect->that($code === 0 && str_contains($text, 'GEN_OK'), "gen-zep rejected a sound fixture:\n{$text}");
$expect->that(is_file("{$good}/vulkan/vk/vk10/vk10.zep"), 'gen-zep produced no .zep for the sound fixture');

$expect->finish('DRIFT_GUARD_OK');
