---
type: Runbook
title: Registry to .so — the pipeline and its guards
description: >-
  How vk.xml becomes a loadable extension, which guard catches which mistake,
  and why the Mac generates while the Pi only builds.
tags: [toolchain, zephir, generator, guards, pi, vulkan]
status: stable
generated:
  by: claude-fable-5.1
  at: 2026-09-13T00:00:00Z
---

# Registry to `.so`

```
scripts/khronos/vk.xml
   │  scripts/lib/registry.php          one walk, shared by both readers
   ▼
scripts/gen-vk-src.php  ──▶  src/vk-*.{h,c}, src/phpvk-registry.{h,c},
   │                         config.json extra-sources
   │  (the @zep / @reserved / @audit annotations it writes)
   ▼
scripts/gen-zep.php     ──▶  vulkan/**/*.zep, optimizers/*Optimizer.php
   ▼
zephir generate         ──▶  ext/*.zep.c, ext/config.m4, ext/vulkan.c
   │  scripts/patch-config-m4.php    per-platform link flags
   │  scripts/patch-mshutdown.php    a module teardown Zephir compiles out
   ▼
phpize / configure / make  ──▶  vulkan.so
```

`scripts/prepare-ext.sh` runs everything above the `phpize` line, strips
phpize leftovers, and writes `ext/.gen-stamp` — a SHA-256 over `src/`,
`vulkan/`, `optimizers/` and `config.json`. `build-linux.sh` refuses a
committed `ext/` whose stamp no longer matches its sources, so a stale tree
can never be silently compiled.

## Run it

```bash
export HERD_PHP_84_INI_SCAN_DIR="$(zsh -ic 'echo $HERD_PHP_84_INI_SCAN_DIR')"   # Mac

php scripts/gen-vk-src.php        # GEN_SRC_OK   (--check → GEN_SRC_CLEAN)
php scripts/gen-zep.php           # GEN_OK
php scripts/check-parity.php      # PARITY_OK, then chains audit-registry → AUDIT_OK
php scripts/tests/run-all.php     # TESTS_OK
bash install-macos.sh             # php --ri vulkan reports config.json's version
php scripts/verify-reflection.php # REFLECTION_OK
php examples/proof_enumerate.php  # PROOF_ENUMERATE_OK
bash scripts/pi-verify.sh         # PI_VERIFY_OK
```

## The guards, and what each one catches

| guard | catches |
|---|---|
| `gen-src-guard.php` | a generator that is not idempotent, and a hand-edit to a generated file (`--check` must name it) |
| `drift-guard.php` | an annotation whose arity or return shape drifted from its C prototype; the generator must write **nothing** |
| `parity-guard.php` | a binding that makes two native calls, one that names a Vulkan symbol, a `src/*.c` config.json does not list, a Vulkan call in a file with no annotations, and a struct method that calls Vulkan at all |
| `audit-guard.php` | an `@audit` marker the registry contradicts, and an unsanctioned shortfall — with `@audit partial` proved to pass |
| `reserved-guard.php` | a callback parameter silently dropped instead of reserved, **and** an unknown type reserved instead of stopping the generator |
| `loader-guard.php` | a generation counter that is not wired, an allocation path that can `exit`, a second Vulkan symbol named at link time, and live: both gate refusals, the C-string round trip, the OOM path |
| `structure-check.php` | version drift between `config.json` and `composer.json`, a class count that moved, a missing `.zep`, a lost GENERATED banner, a hand-written file claiming to be generated |

Every one of them runs against a fixture that breaks exactly what it catches.
**A guard nobody has watched fail is a guard nobody should trust.**

`scripts/tests/fixtures/audit-*` each carry a miniature `vk.xml`, so the audit
guard is measuring a registry rather than a number someone typed.

## The Mac generates, the Pi builds

`scripts/khronos/vk.xml` is the audit truth and it lives in this repo. The Pi
has its own `/usr/share/vulkan/registry/vk.xml` (1.4.309 against the Mac's
1.4.357) and **nothing on the Pi ever reads it**: `pi-verify.sh` regenerates
and stamps on the Mac, tars the tree across, and the Pi runs
`phpize`/`configure`/`make` against the committed `ext/`.

**Never edit on the Pi.** Fix on the Mac, re-push, rebuild. The Pi's Vulkan
headers are older than the registry the surface was generated from; if that
ever stops compiling, that is the signal to reconsider the vendored version,
not to patch the Pi.

`build-linux.sh` enables the extension for **one interpreter only** — the one
`$PHP_BIN` names, plus an `fpm` sibling under the same prefix — and asserts
that exactly one ini in that scan dir names `vulkan.so`. The Pi carried a
0.7.x `30-vulkan.ini` pointing at an older build; two `extension=` lines for
one extension is how a stale `.so` silently wins a green build.

## Hygiene

After every build:

```bash
git clean -X -d -f ext && rm -rf .zephir build.log
git status --short --ignored | grep '^!!'      # must print nothing
```

`ext/` ships **generated C only**. phpize and libtool output is never
committed.
