#!/usr/bin/env php
<?php
/*
 * Idempotence controls for the two generators.
 *
 * src/ is generated from the vendored registry and the .zep tree is
 * generated from src/'s annotations, so "re-run it and nothing changes" is
 * the whole contract. Two ways it can break: a generator that is not deterministic,
 * and a tree someone hand-edited.
 *
 *   1. gen-vk-src.php --check must print GEN_SRC_CLEAN against the committed
 *      tree.
 *   2. A hand-edit to a generated file must make --check fail and name the
 *      file (run in a staged copy; the committed tree is never touched).
 *   3. gen-zep.php re-run must write nothing (written=0) and prune nothing.
 *
 * Prints GEN_SRC_GUARD_OK.
 */

declare(strict_types=1);

require __DIR__ . '/lib/harness.php';

$scripts = dirname(__DIR__);
$root = dirname($scripts);
$expect = new Expect('gen-src-guard');

// ---- 1. the committed src/ is exactly what the headers produce
[$code, $text] = runScript($scripts . '/gen-vk-src.php', ['--check']);
$expect->that(
    $code === 0 && str_contains($text, 'GEN_SRC_CLEAN'),
    "src/ is not what the vendored registry produces:\n{$text}"
);

// ---- 2. a hand-edit must be caught
$staged = stageFixture($root . '/scripts/khronos');
// Stage a minimal package: the generator needs scripts/khronos, the shared
// registry walk, a config.json whose extra-sources it rewrites, and
// src/phpvk-platform.h — the layout probe it compiles includes that shim
// rather than <vulkan/vulkan.h>, so the probe sees exactly the types the
// build does.
$pkg = dirname($staged) . '/phpvk-gen-' . bin2hex(random_bytes(4));
mkdir($pkg . '/scripts/lib', 0755, true);
mkdir($pkg . '/src', 0755, true);
rename($staged, $pkg . '/scripts/khronos');
register_shutdown_function(static function () use ($pkg): void {
    removeTree($pkg);
});
copy($scripts . '/gen-vk-src.php', $pkg . '/scripts/gen-vk-src.php');
copy($scripts . '/lib/registry.php', $pkg . '/scripts/lib/registry.php');
copy($root . '/src/phpvk-platform.h', $pkg . '/src/phpvk-platform.h');
copy($root . '/config.json', $pkg . '/config.json');

[$code, $text] = runScript($pkg . '/scripts/gen-vk-src.php');
$expect->that($code === 0 && str_contains($text, 'GEN_SRC_OK'), "the generator failed on a staged copy:\n{$text}");

// The layout probe really compiled and ran here, not just in the committed
// tree: a staged package with nothing but the registry and the platform shim
// still produces measured asserts.
$staged_asserts = (string) @file_get_contents($pkg . '/src/vk-struct-asserts.c');
$expect->that(
    str_contains($staged_asserts, '_Static_assert(sizeof(VkApplicationInfo)'),
    'the staged generator produced no measured layout asserts'
);

$victim = $pkg . '/src/vk-10.c';
$expect->that(is_file($victim), 'the staged generator produced no src/vk-10.c');
if (is_file($victim)) {
    file_put_contents($victim, "/* hand-edited */\n" . file_get_contents($victim));
    [$code, $text] = runScript($pkg . '/scripts/gen-vk-src.php', ['--check']);
    $expect->that($code !== 0, 'the generator accepted a hand-edited generated file');
    $expect->that(
        str_contains($text, 'src/vk-10.c') && str_contains($text, 'GEN_SRC_DRIFT'),
        "the drift report did not name the edited file:\n{$text}"
    );
}

// ---- 3. gen-zep is idempotent against the committed tree
[$code, $text] = runScript($scripts . '/gen-zep.php');
$expect->that($code === 0 && str_contains($text, 'GEN_OK'), "gen-zep failed on the real package:\n{$text}");
$expect->that(
    (bool) preg_match('/written=0 pruned=0/', $text),
    "re-running gen-zep changed the tree (it must not):\n{$text}"
);

$expect->finish('GEN_SRC_GUARD_OK');
