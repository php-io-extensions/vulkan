#!/usr/bin/env php
<?php
/*
 * Every Mac-side check, in the order they matter.
 *
 * The first five are negative controls: each one proves a guard is able to
 * fail, by running it against a fixture that breaks exactly the thing that
 * guard exists to catch. A guard nobody has watched fail is a guard nobody
 * should trust.
 *
 * Prints TESTS_OK only when every child prints its own token.
 */

declare(strict_types=1);

$tests = __DIR__;
$failures = [];

$checks = [
    ['gen-src-guard.php', 'GEN_SRC_GUARD_OK', 'generators are idempotent and catch hand-edits'],
    ['drift-guard.php', 'DRIFT_GUARD_OK', 'gen-zep refuses an annotation that drifted from its prototype'],
    ['parity-guard.php', 'PARITY_GUARD_OK', 'check-parity catches composites, link-time calls, struct calls'],
    ['audit-guard.php', 'AUDIT_GUARD_OK', 'audit-registry catches marker drift and unsanctioned shortfalls'],
    ['reserved-guard.php', 'RESERVED_GUARD_OK', 'unbindable commands are reserved visibly, not skipped or fatal'],
    ['loader-guard.php', 'LOADER_GUARD_OK', 'load*() invalidates cached slots; the gate refuses by name'],
    ['struct-guard.php', 'STRUCT_GUARD_OK', 'every struct packs, unpacks and refuses bad members by name'],
    ['structure-check.php', 'STRUCTURE_OK', 'versions, class counts, extra-sources, generated banners'],
];

foreach ($checks as [$file, $token, $what]) {
    $cmd = escapeshellarg(PHP_BINARY) . ' ' . escapeshellarg("{$tests}/{$file}") . ' 2>&1';
    $output = [];
    $code = 0;
    exec($cmd, $output, $code);
    $text = implode("\n", $output);

    if ($code !== 0 || !str_contains($text, $token)) {
        $failures[] = $file;
        fwrite(STDERR, "FAIL {$file} (exit {$code})\n{$text}\n\n");
        continue;
    }
    printf("PASS %-22s %s\n", $file, $what);
}

printf("\nchecks=%d failures=%d\n", count($checks), count($failures));

if ($failures !== []) {
    fwrite(STDERR, 'TESTS_FAILED (' . implode(', ', $failures) . ")\n");
    exit(1);
}

echo "TESTS_OK\n";
