#!/usr/bin/env php
<?php
/*
 * The loader's cache-invalidation contract, and the gate's two refusals.
 *
 * Every load*() must invalidate everything cached off the dispatch situation,
 * not just record a handle:
 *
 *   - every entry-point slot (a slot that resolved to "missing" once must be
 *     retried after a later load*(), not latched for the life of the process)
 *   - the same on module teardown
 *
 * Honest note on coverage. The slot half is checked STRUCTURALLY, because
 * making it observable from PHP needs a command that is absent and then
 * present in one process. The generation counter, its comparison in
 * phpvk_entry(), its bump in all three load*() calls and in teardown, and the
 * malloc-not-pemalloc rule are asserted in the source. The two gate refusals
 * ARE observable and are exercised live below.
 *
 * Prints LOADER_GUARD_OK.
 */

declare(strict_types=1);

require __DIR__ . '/lib/harness.php';

$root = dirname(__DIR__, 2);
$expect = new Expect('loader-guard');

// ---- structural: the generation mechanism is actually wired ---------------
$h = (string) file_get_contents($root . '/src/phpvk-bridge.h');
$c = (string) file_get_contents($root . '/src/phpvk-bridge.c');

$expect->that(
    (bool) preg_match('/typedef struct \{[^}]*unsigned int generation;[^}]*\} phpvk_slot;/s', $h),
    'phpvk_slot has no generation field'
);
$expect->that(
    str_contains($h, '#define PHPVK_SLOT_INIT {NULL, 0, 0}'),
    'PHPVK_SLOT_INIT does not initialise the generation to 0 (a fresh slot must look stale)'
);
$expect->that(
    (bool) preg_match('/slot->state == 0 \|\| slot->generation != phpvk_generation/', $c),
    'phpvk_entry does not re-resolve a slot from an older generation'
);
$expect->that(
    (bool) preg_match('/slot->generation = phpvk_generation;/', $c),
    'phpvk_entry does not stamp the slot with the current generation'
);
$expect->that(
    (bool) preg_match('/phpvk_bump_generation\(void\)\s*\{\s*phpvk_generation\+\+;/', $c),
    'phpvk_bump_generation does not increment the generation'
);
$expect->that(
    (bool) preg_match('/phpvk_generation == 0\) \{\s*phpvk_generation = 1;/', $c),
    'the generation can wrap to 0, which is the "never resolved" sentinel'
);
foreach ([
    'phpvk_bridge_load' => 'Bridge::load()',
    'phpvk_bridge_load_instance' => 'Bridge::loadInstance()',
    'phpvk_bridge_load_device' => 'Bridge::loadDevice()',
    'phpvk_bridge_shutdown' => 'the module teardown',
] as $fn => $what) {
    $expect->that(
        (bool) preg_match('/zend_long ' . $fn . '\(|void ' . $fn . '\(/', $c)
            && (bool) preg_match('/' . $fn . '\([^)]*\)\s*\{.*?phpvk_bump_generation\(\);/s', $c),
        "{$what} does not bump the generation"
    );
}

// ---- structural: the two distinct refusals --------------------------------
$expect->that(
    str_contains($c, '"%s: call Bridge::load() first"'),
    'phpvk_entry has no "call Bridge::load() first" refusal'
);
$expect->that(
    str_contains($c, '"%s: call Bridge::loadInstance() first"'),
    'phpvk_entry has no "call Bridge::loadInstance() first" refusal'
);
$expect->that(
    str_contains($c, '"%s is not available on this %s"'),
    'phpvk_entry has no "not available" refusal'
);

// ---- structural: no allocation path can take the process down ------------
$expect->that(
    !preg_match('/\bpemalloc\s*\(\s*\(size_t\)/', $c),
    'a caller-sized allocation still goes through pemalloc, whose failure path exits'
);
$expect->that(
    (bool) preg_match('/block = malloc\(\(size_t\) want\);\s*if \(!block\) \{/', $c),
    'Bridge::alloc does not check malloc for NULL'
);
$expect->that(
    (bool) preg_match('/block = \(char \*\) malloc\(len \+ 1\);\s*if \(!block\) \{/', $c),
    'Bridge::cstring does not check malloc for NULL'
);

/*
 * ---- structural: the extension names exactly one Vulkan symbol -----------
 *
 * check-parity.php catches a Vulkan name that is CALLED; this catches a
 * Vulkan name that is merely mentioned in code, which is the same link-time
 * dependency (the Bridge's fallback takes vkGetInstanceProcAddr's address
 * rather than calling it). Comments and string literals are blanked first,
 * since "vkCreateInstance" as a resolution argument is data, not a symbol.
 */
$named = [];
foreach (glob($root . '/src/*.c') ?: [] as $file) {
    $src = (string) file_get_contents($file);
    $src = preg_replace('~/\*.*?\*/~s', ' ', $src);
    $src = preg_replace('~//[^\n]*~', ' ', $src);
    $src = preg_replace('/"(?:[^"\\\\]|\\\\.)*"/', '""', $src);
    if (preg_match_all('/\bvk[A-Z][A-Za-z0-9]*\b/', (string) $src, $m)) {
        foreach ($m[0] as $t) {
            $named[$t] = true;
        }
    }
}
ksort($named);
$expect->that(
    array_keys($named) === ['vkGetInstanceProcAddr'],
    'the extension names [' . implode(', ', array_keys($named))
    . '] at link time; exactly one, vkGetInstanceProcAddr, is allowed'
);

// ---- live: the gate, the loader and the allocator ------------------------
if (extension_loaded('vulkan')) {
    $php = escapeshellarg(PHP_BINARY);

    // A command before Bridge::load() names the load call that is missing.
    $script = <<<'PHP'
use Vulkan\VK\VK10\VK10;
$w = [];
set_error_handler(function ($n, $s) use (&$w) { $w[] = $s; return true; });
VK10::vkEnumeratePhysicalDevices(0, 0, 0);
restore_error_handler();
echo json_encode(['warnings' => $w]), "\n";
PHP;
    $out = [];
    exec($php . ' -r ' . escapeshellarg($script) . ' 2>&1', $out, $code);
    $json = json_decode(trim((string) end($out)), true);
    $expect->that($code === 0, 'a command before Bridge::load() did not leave the process alive');
    $expect->that(
        is_array($json) && count($json['warnings'] ?? []) === 1
            && str_contains($json['warnings'][0], 'call Bridge::load() first'),
        'a command before Bridge::load() did not name the missing load call: '
        . json_encode($json)
    );

    // After load(), an instance-level command still refuses until loadInstance().
    $script = <<<'PHP'
use Vulkan\Bridge\Bridge;
use Vulkan\VK\VK10\VK10;
$loaded = Bridge::load();
$version = Bridge::version();
$w = [];
set_error_handler(function ($n, $s) use (&$w) { $w[] = $s; return true; });
$r = VK10::vkEnumeratePhysicalDevices(0, 0, 0);
restore_error_handler();
echo json_encode(['loaded' => $loaded, 'version' => $version, 'result' => $r, 'warnings' => $w]), "\n";
PHP;
    $out = [];
    exec($php . ' -r ' . escapeshellarg($script) . ' 2>&1', $out, $code);
    $json = json_decode(trim((string) end($out)), true);
    $expect->that($code === 0, 'the load()/gate sequence did not exit cleanly');
    $expect->that(is_array($json), 'the load()/gate sequence produced no readable result');
    if (is_array($json)) {
        $expect->that($json['loaded'] === true, 'Bridge::load() could not open the Vulkan loader');
        $expect->that($json['version'] > 0, 'Bridge::version() returned 0 after a successful load()');
        $expect->that($json['result'] === 0, 'a refused command did not return 0');
        $expect->that(
            count($json['warnings']) === 1
                && str_contains($json['warnings'][0], 'call Bridge::loadInstance() first'),
            'an instance-level command before loadInstance() did not name that call: '
            . json_encode($json['warnings'])
        );
    }

    // A global-level command resolves with no instance at all, every time.
    $script = <<<'PHP'
use Vulkan\Bridge\Bridge;
Bridge::load();
$a = Bridge::version();
Bridge::load();
$b = Bridge::version();
echo json_encode([
    'first' => $a,
    'second' => $b,
    'known' => Bridge::isAvailable('vkCreateInstance'),
    'bogus' => Bridge::isAvailable('vkNotACommand'),
    'address' => Bridge::procAddress('vkCreateInstance') !== 0,
]), "\n";
PHP;
    $out = [];
    exec($php . ' -r ' . escapeshellarg($script) . ' 2>&1', $out, $code);
    $json = json_decode(trim((string) end($out)), true);
    $expect->that($code === 0, 'two load()s in one process did not exit cleanly');
    if (is_array($json)) {
        $expect->that(
            $json['first'] === $json['second'] && $json['first'] > 0,
            'two load()s with nothing in between disagreed about the loader version'
        );
        $expect->that($json['known'] === true, 'isAvailable said vkCreateInstance is not resolvable');
        $expect->that($json['bogus'] === false, 'isAvailable resolved a name that does not exist');
        $expect->that($json['address'] === true, 'procAddress returned 0 for vkCreateInstance');
    }

    // The OOM path: a size that cannot be allocated must warn and return 0,
    // not exit(1).
    $script = <<<'PHP'
use Vulkan\Bridge\Bridge;
$r = [];
set_error_handler(function () { return true; });
foreach ([PHP_INT_MAX, 1 << 62, 1 << 50, 0, -1] as $n) { $r[] = Bridge::alloc($n); }
restore_error_handler();
echo json_encode(['results' => $r]), "\n";
PHP;
    $out = [];
    exec($php . ' -r ' . escapeshellarg($script) . ' 2>&1', $out, $code);
    $json = json_decode(trim((string) end($out)), true);
    $expect->that($code === 0, 'an impossible Bridge::alloc took the process down');
    $expect->that(
        is_array($json) && $json['results'] === [0, 0, 0, 0, 0],
        'an impossible or non-positive Bridge::alloc did not return 0: ' . json_encode($json)
    );

    // C strings round-trip, because nothing else in the type table makes one.
    $script = <<<'PHP'
use Vulkan\Bridge\Bridge;
$p = Bridge::cstring('VK_KHR_portability_enumeration');
$back = Bridge::readCString($p);
Bridge::free($p);
echo json_encode(['ptr' => $p !== 0, 'text' => $back, 'empty' => Bridge::readCString(0)]), "\n";
PHP;
    $out = [];
    exec($php . ' -r ' . escapeshellarg($script) . ' 2>&1', $out, $code);
    $json = json_decode(trim((string) end($out)), true);
    $expect->that($code === 0, 'the C-string round trip did not exit cleanly');
    $expect->that(
        is_array($json) && $json['ptr'] === true
            && $json['text'] === 'VK_KHR_portability_enumeration'
            && $json['empty'] === '',
        'Bridge::cstring/readCString did not round-trip: ' . json_encode($json)
    );
} else {
    echo "loader-guard: the vulkan extension is not loaded; live checks skipped\n";
}

$expect->finish('LOADER_GUARD_OK');
