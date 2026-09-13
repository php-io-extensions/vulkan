---
type: Component
title: Vulkan\Bridge\Bridge — the only glue
description: >-
  The three loader levels and the gate they form, the byte buffers the
  pointer rule makes necessary, and the C strings nothing else can produce.
  Nothing here decides how Vulkan is used.
resource: src/phpvk-bridge.c
tags: [bridge, glue, loader, buffers, cstring, vulkan]
status: stable
generated:
  by: claude-fable-5.1
  at: 2026-09-13T00:00:00Z
---

# Vulkan\Bridge\Bridge

Everything in `src/phpvk-bridge.{h,c}` exists because PHP cannot open a shared
library, cannot hold a byte buffer a driver can write into, cannot make a
NUL-terminated C string, and cannot know whether a given instance or device can
make a given call. Nothing here decides anything about how Vulkan is used.

## Surface

| call | does |
|---|---|
| `load(): bool` | `dlopen` the platform's loader (`libvulkan.1.dylib` / `libvulkan.so.1`), take `vkGetInstanceProcAddr` from it, and bump the generation. Falls back to the linked symbol when `dlopen` by soname fails. Idempotent for the handle, **deliberately not** for the cached slots. |
| `loadInstance(int instance): bool` | record the instance, resolve `vkGetDeviceProcAddr` through it, clear any device, bump the generation. |
| `loadDevice(int device): bool` | record the device for direct dispatch, bump the generation. Refuses with a warning if no instance is loaded. |
| `isAvailable(string name): bool` | resolve `name` at the level `src/phpvk-registry.c` says it lives at, and report whether the loader answered. **This is the same question `phpvk_entry()` answers** — see "resolution is availability" below. |
| `procAddress(string name): int` | the same resolution, returned as pointer bits. Diagnostics. |
| `version(): int` | the loader's `vkEnumerateInstanceVersion` answer, packed; `0` on a 1.0 loader or on failure. |
| `alloc(int size): int` | `malloc` + zero + track. `0` and an `E_WARNING` on failure — never `exit`. |
| `free(int ptr): void` | free a tracked block: a buffer, a C string, or a `Struct::pack` block. Warns on a pointer this extension did not allocate. |
| `write(int ptr, int offset, string bytes): bool` | copy bytes in. Bounds-checked against a **tracked** block; a foreign pointer is written as given. |
| `read(int ptr, int offset, int length): string\|null` | copy bytes out, same rule. Returns `null` (and warns) for a NULL pointer, a negative offset or length, or a read past the end of a *tracked* block. |
| `cstring(string text): int` | `malloc` a NUL-terminated copy and track it. |
| `readCString(int ptr): string` | read one back; `""` for `0`. |

## Resolution is availability

ext-opengl needs a version gate because symbol resolution and availability are
different questions there — Mesa resolves GL 4.6 names on a 3.1 context. Vulkan
has no such gap: `vkGetInstanceProcAddr` returns NULL for a command above the
instance's API version and for an extension that was not enabled, and
`vkGetDeviceProcAddr` does the same per device. So this extension has **no
version table and no version comparison**. `src/phpvk-registry.c` carries only
the level each command resolves at, which is a fact about *which* dispatch
table to ask, not about whether the answer will be yes.

That is also why `isAvailable()` is trustworthy here in a way its GL namesake
is not: it is literally the resolution the binding would do.

## Two refusals, and they mean different things

```
<name>: call Bridge::load() first
<name>: call Bridge::loadInstance() first
<name> is not available on this loader|instance|device
```

The first two are a missing step in your own code. The third is the driver
saying no. Both return `0` (or nothing, for a `void` binding) and raise
`E_WARNING`; there is no third channel.

## The generation counter

Every `load*()` and the module teardown bump a process-global generation. A
cached slot carries the generation it resolved under, and `phpvk_entry()`
re-resolves whenever they differ. Without it, a command that resolved to
"missing" before `loadDevice()` would stay missing for the life of the
process — the exact bug ext-opengl shipped and then fixed. `PHPVK_SLOT_INIT`
sets the generation to `0`, which the counter never takes, so a fresh slot is
always stale. `scripts/tests/loader-guard.php` asserts all of this in the
source and exercises the observable half live.

## Tracked blocks

`alloc`, `cstring` and every `Struct::pack` return a block registered in a
process-global table keyed by pointer bits. `free` reclaims one; the module
teardown (wired by `scripts/patch-mshutdown.php`, because Zephir compiles its
own `MSHUTDOWN` out of a release build) sweeps whatever the caller missed.

Allocation is plain `malloc`, never `pemalloc`: `pemalloc` routes a failed
allocation through `zend_out_of_memory()`, which prints and calls `exit(1)`, so
`Bridge::alloc(PHP_INT_MAX)` would take the interpreter down instead of
returning an error a caller can see. It is also the right lifetime — the table
is a process global and a request-scoped block would dangle in it after
request shutdown.

## Foreign memory is the caller's problem

`write`/`read` bounds-check a **tracked** block, because its extent is known.
A pointer this extension never allocated — `vkMapMemory`'s result is the case
that matters — has no extent to check against and is used as given. That is
the price of the pointer rule, and it is the same price a C caller pays. See
[traps/pointer-bits-only.md](/traps/pointer-bits-only.md).

## One linked symbol

The module links `libvulkan` for `vkGetInstanceProcAddr` and nothing else.
`nm -u` on the built `.so` lists exactly one symbol beginning `vk`, and
`scripts/tests/loader-guard.php` re-derives that from the sources on every run.
See [traps/runtime-resolution-not-linking.md](/traps/runtime-resolution-not-linking.md).
