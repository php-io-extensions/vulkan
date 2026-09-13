---
type: Component
title: The struct tier — flat pack and unpack
description: >-
  One class per registry struct or union, four methods, members marshalled by
  a table with no judgement in it. Complete, member-audited, layout-asserted
  on both platforms, and round-tripped by scripts/tests/struct-guard.php.
resource: src/vk-struct-10.c
tags: [struct, pack, unpack, memory, layout, vulkan]
status: stable
generated:
  by: claude-fable-5.1
  at: 2026-09-13T00:00:00Z
---

# The struct tier

Vulkan is a struct-shaped API: almost every command takes a pointer to one.
PHP cannot lay out a C struct, and a binding that marshalled struct members
as PHP objects would be holding an opinion about every one of the 368 of
them. So the tier is generated, and it is **flat**.

**368 classes, 2296 members, 1472 methods.** Measured from
`scripts/khronos/vk.xml` (`VK_HEADER_VERSION` 357) by
`scripts/lib/registry.php`, which is the same walk the generator uses. Two of
the 368 are unions: `VkClearColorValue` and `VkClearValue`.

## Four methods, per struct or union

```php
Vulkan\Struct\VkInstanceCreateInfo\VkInstanceCreateInfo::pack(array $members): int
Vulkan\Struct\VkInstanceCreateInfo\VkInstanceCreateInfo::packInto(int $ptr, array $members): void
Vulkan\Struct\VkInstanceCreateInfo\VkInstanceCreateInfo::unpack(int $ptr): array
Vulkan\Struct\VkInstanceCreateInfo\VkInstanceCreateInfo::size(): int
```

| method | does | who frees |
|---|---|---|
| `pack` | `malloc(sizeof(T))`, zero, fill, track. Returns pointer bits, `0` on refusal. | you, with `Bridge::free`; the module teardown sweeps what you miss |
| `packInto` | fill memory you already own. Returns nothing. | you |
| `unpack` | read one back into a PHP array. `null` and a warning for a NULL pointer. | — |
| `size` | `sizeof(T)`, from the ABI | — |

`packInto` is how an array of structs is built:

```php
$n = 2;
$block = Bridge::alloc($n * VkViewport::size());
for ($i = 0; $i < $n; $i++) {
    VkViewport::packInto($block + $i * VkViewport::size(), $viewports[$i]);
}
```

That only works because `packInto` writes exactly the bytes `pack` would have
written into its own block. It is not an assumption:
`scripts/tests/struct-guard.php` packs every one of the 368, then `packInto`s
the same member array into a `Bridge::alloc(size())` block and compares the
two blocks byte for byte.

## Ownership

- **`pack` owns its block until you free it.** Every block it returns is
  *tracked*: `Bridge::free` accepts it, `Bridge::write`/`read` bounds-check it
  because its extent is known, and module teardown frees whatever a script
  leaked. A pointer this extension never allocated is none of those things —
  see [bridge.md](/bridge.md).
- **`packInto` owns nothing.** It fills a staging copy on its own stack and
  `memcpy`s `sizeof(T)` bytes over your memory only once every member was
  accepted, so a refused fill leaves what you had **byte for byte** — that is
  spec §7's "no write", and `scripts/tests/struct-guard.php` compares the block
  before and after a refused call. A successful fill starts from a `memset`, so
  a member you omitted is zero, not whatever was there. Pointing it at a block
  shorter than `size()` is still your bug; the extension does not know how big
  foreign memory is and never pretends to.
- **`unpack` copies.** The array it returns shares nothing with the memory it
  read.

## Flat means flat

**No pointer is ever followed, and none is ever produced.** `pNext`,
`pApplicationInfo`, `ppEnabledExtensionNames`, every `PFN_*` member and every
platform handle cross as pointer bits in an `int`. A nested *by-value* struct
is a nested PHP array, because that is inline memory; a nested *pointed-to*
struct is a number you got from another `pack`.

That is the whole reason the tier can be generated without judgement, and the
reason the caller stays in control of lifetimes.

## Members

The member table is in
[binding-rules.md](/binding-rules.md#table-2--struct-and-union-members).
Restated here with what each shape actually costs:

| registry member | PHP | round trip |
|---|---|---|
| integer scalars, enums, `VkFlags*` | `int` | exact at the member's own C width; a wider value truncates the way C truncates |
| `VkDeviceSize`, `VkDeviceAddress`, `VkFlags64`, `size_t`, `uint64_t` | `int` | exact, reinterpreted (see the 64-bit wrap) |
| dispatchable and non-dispatchable handles | `int` | exact, pointer bits through `uintptr_t` |
| `VkBool32` | `bool` | any truthy value packs as `VK_TRUE`; unpack gives `true`/`false` |
| `float`, `double` | `float` | a `float` member round-trips through 32 bits, so `0.1` comes back as `0.10000000149…` |
| `char[N]` | `string` | NUL-padded on pack, cut at the first NUL on unpack; **longer than `N-1` is refused by name**, never truncated |
| `T[N]` of scalars | `array` of N | positional, in the caller's array order; short zero-fills, long refuses |
| struct or union by value, including `T[N]` of them | nested `array` | recursion over *inline memory only* |
| any pointer, `pNext`, `PFN_*`, `id<MTL*>`, platform handles | `int` bits | exact; never followed, never produced |

The rules that surprise people:

- **A missing key packs as zero.** `memset` runs first, so an omitted member
  is `0` / `NULL` / `VK_FALSE` — never a default this extension invented.
- **An unknown key is an error.** It raises `E_WARNING` naming the struct and
  the key, and `pack` returns `0`, freeing the block it was filling so nothing
  is tracked and nothing leaks. A typo in `sType` must not silently become a
  zeroed struct that Vulkan then rejects for a reason that points somewhere
  else.
- **`sType` is a plain member.** The caller supplies it. jovian/vulkan's typed
  layer may default it; this extension does not.
- **A long scalar array refuses**, and so does a long string. `E_WARNING`
  names the struct, the member and both lengths, and the fill stops. `pack`
  returns `0` and `packInto` writes nothing, so there is no partial write to
  find either way.
- **Nothing is skipped.** Every member the registry declares is written by the
  generated fill body and read back by the generated read body, and
  `scripts/audit-registry.php` re-measures that member by member against
  `vk.xml` (`structs=368 members=2296`). A member the table cannot express
  stops the generator by name; there is no `@audit partial` for a member.

## Unions

There are two, and they follow the bytes rather than a convention:

- **`pack` writes the members present**, last wins in registry order. Writing
  two members of a union is not an error — it is what the caller asked for.
- **`unpack` returns every member**, because which one is live is not
  knowable from the bytes. Only the member you wrote has a meaning; the rest
  is the same memory read a different way.

`struct-guard.php` therefore packs a union one member at a time and compares
only that member — the others are deliberately compared against nothing.

## The 64-bit wrap

PHP's int is signed 64-bit and Vulkan's `VkDeviceSize`, `VkDeviceAddress` and
`VkFlags64` are unsigned. A value above `PHP_INT_MAX` cannot be written
directly and wraps. The consequence that matters in practice:

```php
'size' => -1,   // VK_WHOLE_SIZE (UINT64_MAX)
```

This is reinterpretation, not conversion — `phpvk_arg_u64` is
`(uint64_t) phpvk_arg_long` — so it is exact, and it is the only spelling
available.

## The layout-assert contract

The generated fill and read bodies are written in terms of `s->member` and
`sizeof(s->m) / sizeof(s->m[0])`. That makes them correct by construction on
whatever box compiles them — and it is exactly why nothing in them would
notice if two build boxes disagreed about a layout. `size()` would quietly
return a different number on each, and an array of structs built with
`packInto` would stride wrong.

So `scripts/gen-vk-src.php` measures the layout instead of assuming it. On
the generating box it writes a small C probe, compiles it against the real
Khronos headers through `src/phpvk-platform.h`, runs it, and emits
`src/vk-struct-asserts.c`:

```c
_Static_assert(sizeof(VkApplicationInfo) == 48, "VkApplicationInfo");
_Static_assert(offsetof(VkApplicationInfo, pNext) == 8, "VkApplicationInfo.pNext");
```

**2664 assertions: one `sizeof` per struct or union, one `offsetof` per
member.** The file is in `extra-sources`, so every build compiles it and a
build box that disagrees fails at compile time naming the struct. There are
no bit-fields in scope, so every member has an offset to assert.

The contract this creates:

- `cc` is a **generation-box** requirement, like `php`. A box that only
  *builds* needs nothing new.
- The numbers are measured, never hand-written. `gen-vk-src.php --check` is
  the idempotence guard, and it re-runs the probe.
- A failure here is never "fix the Pi". The generator measured on the Mac, so
  a mismatch means the Mac's probe or `src/phpvk-platform.h` is wrong — fix
  there, re-push, rebuild.

Measured 2026-09-13: clean on Darwin arm64 (Apple clang 17, Khronos headers
1.4.357) and on Linux arm64 (Raspberry Pi 5, Khronos headers 1.4.309). Forty-
eight patch versions apart, and every one of the 2664 numbers agrees — which
is what an ABI-stable registry is supposed to mean, now checked instead of
assumed.

## What watches this tier

| check | what it would catch |
|---|---|
| `scripts/audit-registry.php` | a struct with no class, a class outside scope, a member the emitted bodies never touch, a key list that accepts something the registry does not declare |
| `src/vk-struct-asserts.c` | two platforms disagreeing about a size or an offset |
| `scripts/check-parity.php` | a struct method that resolved an entry point or made a Vulkan call — this tier is flat memory work and makes neither |
| `scripts/tests/struct-guard.php` | a member that does not survive `pack` → `unpack`, a `packInto` that writes different bytes than `pack`, an unknown key or an over-long array that does not refuse, `unpack(0)` that does not warn |
| `scripts/tests/structure-check.php` | four methods per class, 368 classes, the asserts file present and in `extra-sources` |

`struct-guard.php` builds its member values from the registry walk with a
seed plus each member's position, masked to that member's own C width. Two
members cannot accidentally agree, so a member written at the wrong offset or
the wrong width shows up as a mismatch rather than as a plausible-looking
zero.
