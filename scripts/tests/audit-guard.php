#!/usr/bin/env php
<?php
/*
 * Negative controls for audit-registry.php — the "nothing silently omitted"
 * guard.
 *
 *   audit-drift    an @audit marker that claims more commands than the
 *                  registry block it names actually has (this is what catches
 *                  a re-vendored vk.xml that changed the surface)
 *   audit-short    a block whose commands are not all bound or reserved, with
 *                  nothing sanctioning the shortfall
 *   audit-partial  the same shortfall with @audit partial — must PASS and
 *                  print PARTIAL, because a sanctioned gap is not drift
 *   struct-member-gap
 *                  a struct whose class-level coverage is perfect and whose
 *                  fill body drops one member. Nothing above the member level
 *                  can see it, and there is no @audit partial for a member:
 *                  the audit must fail naming struct.member.
 *
 * Each fixture carries its own miniature vk.xml, so the audit is measuring a
 * registry rather than a hard-coded number.
 *
 * Also asserts the real package audits clean, with every class OK and the
 * struct tier fully covered.
 *
 * Prints AUDIT_GUARD_OK.
 */

declare(strict_types=1);

require __DIR__ . '/lib/harness.php';

$scripts = dirname(__DIR__);
$root = dirname($scripts);
$audit = $scripts . '/audit-registry.php';
$expect = new Expect('audit-guard');

// ---- a marker that no longer matches the registry
$dir = stageFixture(__DIR__ . '/fixtures/audit-drift');
[$code, $text] = runScript($audit, [$dir]);
$expect->that($code !== 0, 'the audit accepted a marker the registry contradicts');
$expect->that(
    str_contains($text, 'the registry has 2'),
    "the audit failed without naming the real registry count:\n{$text}"
);

// ---- an unsanctioned shortfall
$dir = stageFixture(__DIR__ . '/fixtures/audit-short');
[$code, $text] = runScript($audit, [$dir]);
$expect->that($code !== 0, 'the audit accepted an unsanctioned shortfall');
$expect->that(
    str_contains($text, "is short of the registry"),
    "the audit failed without the shortfall diagnostic:\n{$text}"
);

// ---- the same shortfall, sanctioned
$dir = stageFixture(__DIR__ . '/fixtures/audit-partial');
[$code, $text] = runScript($audit, [$dir]);
$expect->that($code === 0, "the audit rejected an @audit partial class:\n{$text}");
$expect->that(str_contains($text, 'PARTIAL'), "an @audit partial class did not print PARTIAL:\n{$text}");
$expect->that(str_contains($text, 'AUDIT_OK'), 'the sanctioned fixture did not print AUDIT_OK');

// ---- a member the emitted fill body never writes
$dir = stageFixture(__DIR__ . '/fixtures/struct-member-gap');
[$code, $text] = runScript($audit, [$dir]);
$expect->that($code !== 0, 'the audit accepted a struct whose fill body drops a member');
$expect->that(
    str_contains($text, 'VkFakeInfo.flags') && str_contains($text, 'phpvk_fill_VkFakeInfo'),
    "the audit failed without naming the missing struct.member:\n{$text}"
);
$expect->that(
    str_contains($text, 'structs=1 members=2'),
    "the audit did not report member-level coverage totals:\n{$text}"
);

// ---- the real package
[$code, $text] = runScript($audit, [$root]);
$expect->that($code === 0 && str_contains($text, 'AUDIT_OK'), "the real package does not audit clean:\n{$text}");
$expect->that(str_contains($text, 'failures=0'), 'the real audit reported failures');
$expect->that(
    !str_contains($text, 'SHORT') && !str_contains($text, 'EXCESS') && !str_contains($text, 'PARTIAL'),
    "the real audit reported a short, excess or partial class:\n{$text}"
);
$expect->that(
    (bool) preg_match('/structs=(\d+)\/\1 /', $text),
    "the real audit did not cover every struct the registry scopes:\n{$text}"
);
$expect->that(
    (bool) preg_match('/^structs=(\d+) members=(\d+)$/m', $text, $m) && (int) $m[2] > (int) $m[1],
    "the real audit did not report member-level coverage:\n{$text}"
);

$expect->finish('AUDIT_GUARD_OK');
