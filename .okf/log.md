# Change log

## 2026-09-13 — Wave 0: commands, Bridge, guards, PROOF_ENUMERATE_OK on both boxes

The first slice of ext-vulkan 0.8.0, which supersedes the 0.7.1 helper library
entirely. Nothing carried forward except the two Darwin facts recorded in
[traps/moltenvk-portability.md](/traps/moltenvk-portability.md).

### What was built

Everything measured by `scripts/gen-vk-src.php` from
`scripts/khronos/vk.xml` (`VK_HEADER_VERSION` 357, md5
`f750004aa051f3a36e34966236662acf`, copied from
`/opt/homebrew/share/vulkan/registry/vk.xml`):

| class | commands | structs first required here |
|---|---:|---:|
| `VK\VK10` | 137 | 110 |
| `VK\VK11` | 28 | 68 |
| `VK\VK12` | 13 | 51 |
| `VK\VK13` | 37 | 53 |
| `VK\VK14` | 19 | 51 |
| `Ext\KHRSurface` | 5 | 2 |
| `Ext\KHRSwapchain` | 9 | 8 |
| `Ext\KHRWaylandSurface` | 2 | 1 |
| `Ext\KHRXcbSurface` | 2 | 1 |
| `Ext\KHRXlibSurface` | 2 | 1 |
| `Ext\EXTMetalSurface` | 1 | 1 |
| `Ext\EXTMetalObjects` | 1 | 12 |
| `Ext\EXTDebugUtils` | 11 | 5 |
| `VK_KHR_portability_enumeration` (structs only) | 0 | 0 |
| `VK_KHR_portability_subset` (structs only) | 0 | 2 |
| `VK_EXT_layer_settings` (structs only) | 0 | 2 |
| **total** | **267** | **368** |

Every command count is exactly what spec §2 predicted. Core structs total 333,
also as predicted; the 35 extension structs bring it to 368 (spec §6 said
"~375", which was an estimate).

Plus `Bridge\Bridge` (12 methods) and 368 `Struct\<Name>` classes at four
methods each. **382 classes, 1751 static methods, 0 reserved.**

### What is hand-written

`src/phpvk-platform.h`, `src/phpvk-support.{h,c}`, `src/phpvk-bridge.{h,c}`.
Nothing else under `src/`, nothing at all under `vulkan/` or `optimizers/`.

### Measured on both boxes

```
Mac (M1 Pro, MoltenVK 1.4.2, loader 1.4.357)
  loader: 1.4.357
  device 0: Apple M1 Pro api 1.3.357
  PROOF_ENUMERATE_OK

Pi 5 (trixie, Mesa 26.2, loader 1.4.309, PHP 8.4 ZTS)
  loader: 1.4.309
  device 0: V3D 7.1.7.0 api 1.3.354
  device 1: llvmpipe (LLVM 19.1.7, 128 bits) api 1.4.354
  PROOF_ENUMERATE_OK
```

`REFLECTION_OK` on both (382 classes, 0 failures); `php --ri vulkan` reports
`0.8.0` on both; `PI_VERIFY_OK`.

### Decisions taken, and why

**Zero reservations, and the mechanism proved anyway.** The type table covers
every command in scope. `VK_EXT_debug_utils` was the candidate — it is the one
extension here with a callback — but its `PFN_vkDebugUtilsMessengerCallbackEXT`
is a *struct member*, and a member is pointer bits. So
`scripts/tests/reserved-guard.php` injects a `PFN_vkVoidFunction` **parameter**
into a scratch copy of the registry and checks the emitted `@reserved` line and
the audit sum (137 + 1 = 138), then separately injects an unknown type and
checks the generator dies naming it. Both halves of rule 4 are watched failing.

**Non-dispatchable handles are spelled through `uintptr_t`.** The plan's table
said `(T) phpvk_arg_u64(x)` in and `(zend_long)` out. With
`VK_USE_64_BIT_PTR_DEFINES` — the default on every box this builds on — a
non-dispatchable handle is a real pointer type, so those spellings do not
compile cleanly. The *value* still travels through `phpvk_arg_u64` /
`phpvk_member_u64`, so the `-1 = UINT64_MAX` contract is unchanged; only the
cast is `(T) (uintptr_t) …` and `(zend_long) (uintptr_t) …`. Same for `PFN_*`
struct members.

**Array parameters are pointers.** `vkCmdSetBlendConstants(…, const float
blendConstants[4])` is `const float *` in C. The generator decays an array
parameter to a pointer and then applies the pointer rule; the registry spells
the length for validators, and the ABI does not care.

**Platform-conditional classes are compiled on both platforms.** Spec §6
described `#ifdef`-guarded WSI and Metal classes. They are not guarded: the
Khronos WSI headers are pure C behind the shims in `src/phpvk-platform.h`, so
all eight extension classes exist everywhere and the wrong-platform ones simply
fail to resolve and warn — the same behaviour ext-opengl's `EGL` class has on
Darwin. **No `#ifdef` appears in any generated binding body.** Recorded in
[binding-rules.md](/binding-rules.md).

**Foreign memory is not bounds-checked.** Spec §7 said so; the implementation
reads that as: a *tracked* block (from `alloc`, `cstring` or `pack`) has a known
extent and is checked; a pointer this extension never allocated has none and is
used as given. That is what makes Wave 2's `vkMapMemory` write possible at all.
Negative offsets and lengths are always refused.

**No version table.** ext-opengl needs one because symbol resolution and
availability differ there. They do not in Vulkan: the loader returns NULL for a
command above the instance's or device's version and for an unenabled
extension. `src/phpvk-registry.c` therefore carries only each command's
dispatch *level*, and `Bridge::isAvailable()` is literally the resolution the
binding would do.

### Facts learned, now in traps/

- [loader-clamps-device-version.md](/traps/loader-clamps-device-version.md) —
  new. `VkPhysicalDeviceProperties::apiVersion` came back `1.3.357` on the Mac
  while `vulkaninfo` said `1.4.357` for the same device. Re-running the proof
  with `apiVersion` set to 1.4 produced `1.4.357`: the loader clamps what it
  reports to what the instance asked for. The Pi's llvmpipe, asked the same
  1.3 question, reported 1.4 — so the clamping is a loader/ICD property, not a
  rule. Do not read that field as a device ceiling.
- [no-platform-dev-packages.md](/traps/no-platform-dev-packages.md) — the whole
  WSI surface builds with no wayland, xcb or X11 headers installed, and the
  generator's `PLATFORM_TYPES` table must stay in lockstep with
  `src/phpvk-platform.h`. A registry that introduces a new platform spelling
  stops the generator by name.
- [runtime-resolution-not-linking.md](/traps/runtime-resolution-not-linking.md)
  — adapted from ext-opengl's. Here the loader *is* linked, for exactly one
  symbol. `nm -u` on the Mac build lists `_vkGetInstanceProcAddr` and nothing
  else beginning `vk`; `loader-guard.php` re-derives that from the sources.
- [moltenvk-portability.md](/traps/moltenvk-portability.md),
  [pointer-bits-only.md](/traps/pointer-bits-only.md),
  [no-window-in-ext.md](/traps/no-window-in-ext.md) — spec §9, §4 and §2 as
  traps.

### Left for later waves, deliberately

- **Wave 1** owns the struct tier's guards: the per-struct pack/unpack
  roundtrip, the `_Static_assert` layout proof, and the member-level coverage
  audit. Wave 0 generates and builds the tier and the enumerate proof exercises
  three of its classes, but no guard yet says every one of the 368 is correct.
  [struct-tier.md](/struct-tier.md) is `status: draft` for that reason.
- **Wave 2** owns `examples/proof_headless.php`, the vendored SPIR-V, and the
  README's measured-results table.

---

## 2026-09-13 — Wave 1: struct tier audited, layout-asserted and guarded

Wave 0 generated, built and ran the struct tier; nothing said it was
*correct*. Wave 1 says it, three ways, and all three are watched failing.
No new binding, no new class, no change to any generated body: the surface is
still **382 classes, 1751 static methods, 0 reserved**.
[struct-tier.md](/struct-tier.md) moves from `draft` to `stable`.

### What was built

**Member-level coverage in `scripts/audit-registry.php`.** The audit already
checked that every scoped struct has its four annotations and that no
`Struct\` class exists outside scope. It now also re-reads the emitted
`phpvk_fill_<T>` and `phpvk_read_<T>` bodies out of `src/*.c` and requires
every member the registry declares to appear as `s-><member>` in both, and in
the `phpvk_names_<T>[]` key list — and requires that key list to accept
nothing the registry does not declare. It prints
`structs=368 members=2296` before `AUDIT_OK`.

There is **no `@audit partial` for a member**, deliberately. A member the type
table cannot express stops the generator by name (`renderMember`), so it never
reaches a body; a member missing from a body can only be an emitter branch
that fell through, a hand-edit, or a re-vendored registry that grew one.

**No generator gap was found.** All 2296 members were already covered on the
first run — the audit was added to *prove* that, not to fix it.

**`src/vk-struct-asserts.c`, generated.** `gen-vk-src.php` now writes a C
probe to a scratch directory, compiles it against the real Khronos headers
through `src/phpvk-platform.h`, runs it, and emits **2664 assertions** — one
`_Static_assert(sizeof(T) == N, "T")` per struct or union and one
`_Static_assert(offsetof(T, m) == off, "T.m")` per member. It is in
`extra-sources`, so every build compiles it. `cc` became a generation-box
requirement; a box that only builds needs nothing new.

**`scripts/tests/struct-guard.php`.** With the extension loaded, for every
`Vulkan\Struct\*` class: build a deterministic member array from the registry
walk, `pack`, `unpack`, compare; `packInto` the same array into a
`Bridge::alloc(size())` block and compare it byte for byte with `pack`'s.
Then three negative controls — an unknown key, a scalar array one element too
long, `unpack(0)` — each of which must warn naming the struct (and the member,
and both lengths) and refuse. Prints `STRUCT_GUARD_OK structs=368`. Added to
`run-all.php` after `loader-guard.php`.

### Measured on both boxes

```
php scripts/gen-vk-src.php --check   files=43 … structs=368   GEN_SRC_CLEAN
php scripts/check-parity.php         structs=368/368 methods=1472
                                     structs=368 members=2296   AUDIT_OK
php scripts/tests/run-all.php        checks=8 failures=0        TESTS_OK
php scripts/tests/struct-guard.php   STRUCT_GUARD_OK structs=368
bash install-macos.sh                Version => 0.8.0
php scripts/verify-reflection.php    classes=382 failures=0     REFLECTION_OK
bash scripts/pi-verify.sh            REFLECTION_OK, PROOF_ENUMERATE_OK,
                                     PI_VERIFY_OK
```

The Pi line is the one that matters here: `ext/src/.libs/vk-struct-asserts.o`
exists on the Pi, so all 2664 assertions compiled clean under gcc on arm64
Linux against Khronos headers **1.4.309**, while the numbers were measured on
the Mac by Apple clang 17 against **1.4.357**. Forty-eight patch versions
apart and every size and offset agrees.

### Decisions taken, and why

**The asserts are generated, not written.** The plan allowed a hand-written
table of sizes; a hand-written number is a number nobody re-measures. The
probe runs on every `gen-vk-src.php` run, `--check` included, which is what
keeps `GEN_SRC_CLEAN` meaningful.

**The guard resolves member widths itself.** The generator's type table
collapses every integer to one `long` kind because it casts; a guard that
wrote `0x0102030405` into a `uint8_t` and expected it back would be testing
nothing. So `struct-guard.php` walks the registry's own alias / bitmask /
basetype chain down to a primitive spelling and masks each value to that
member's real width. The one table it cannot re-derive is the platform
spellings, so it cross-checks its key set against the generator's
`PLATFORM_TYPES` and fails if either grows a name the other lacks.

**Plain `char` gets a 7-bit value.** `char` is signed on x86 and unsigned on
arm, and a guard has no business knowing which. Every `char` in scope is part
of a `char[N]` string member anyway.

**Unions are packed one member at a time.** `pack` writes the members present
and `unpack` returns all of them, so only the member written has a knowable
value; the guard compares that one and deliberately compares the others
against nothing.

**API constants joined the shared registry walk.** `scripts/lib/registry.php`
now also reads the `API Constants` enum block, and `vkArrayLength()` resolves
a `T[VK_SOMETHING]` dimension to a count. The generated C never needs it (it
writes `sizeof(s->m) / sizeof(s->m[0])`); the guard does, and the raw C text
is kept rather than a parsed number so that `(~0U)` cannot be mistaken for a
length.

### Guards watched failing

- `scripts/tests/fixtures/struct-member-gap/` — new. A struct whose
  class-level coverage is perfect and whose fill body drops one of two
  members. The audit fails naming `VkFakeInfo.flags` and
  `phpvk_fill_VkFakeInfo`. Wired into `audit-guard.php`.
- The three existing audit fixtures gained a `src/fake.c` with the emitted
  fill/read/key-list shape, because member-level coverage cannot be audited
  against annotations alone.
- `struct-guard.php`'s three negative controls were each mutated and watched
  failing before being kept; the round-trip comparison was mutated (a member
  width widened, a float made inexact) and watched failing too.
- A deliberate `_Static_assert(sizeof(VkExtent2D) == 9)` was compiled and
  produced `static assertion failed … VkExtent2D`, then reverted.

### New facts worth keeping

- **A narrower guard value hides nothing and proves nothing.** Masking a
  `uint32_t` member to 16 bits still round-trips, so that mutation does *not*
  fail. Only a value too WIDE for the member is detectable. The guard's
  seed is `0x0102030405` — five bytes — precisely so every member narrower
  than 64 bits is exercised above its own width.
- **Exactly representable floats are the only honest test values.**
  `1.5 + n` survives a 32-bit float round trip exactly, so `===` is the right
  comparison and no epsilon is needed. `0.1` does not: `VkViewport::pack(['x'
  => 0.1])` unpacks as `0.10000000149011611938`. That is the ABI, not a bug,
  and it belongs in the member table.
- **`offsetof` on a union is portable enough in practice.** C says `offsetof`
  takes a struct type; clang and gcc both accept a union, and the two union
  members of `VkClearValue` assert at offset 0 on both boxes.
- **A scratch package that runs the generator now needs
  `src/phpvk-platform.h`.** `gen-src-guard.php` and `reserved-guard.php` both
  stage a minimal package to run `gen-vk-src.php` in; the layout probe
  includes the shim, so both had to copy it. A scratch root without it stops
  the generator with a named error rather than silently skipping the probe.

---

## 2026-09-13 — Wave 2: PROOF_HEADLESS_OK on MoltenVK and V3D; installers; OKF

The wave that stops arguing from counts and draws a frame. **No binding
changed, no class was added, no generated file moved**: the surface is still
382 classes, 1751 static methods, 0 reserved, 368 structs, 2296 members. What
Wave 2 adds is a caller that uses enough of that surface, on two unrelated
drivers, to make a wrong answer visible as a wrong byte.

### What was built

| file | what |
|---|---|
| `examples/shaders/triangle.{vert,frag}` | GLSL 450, four lines each |
| `examples/shaders/triangle.{vert,frag}.spv` | **vendored** SPIR-V 1.0, compiled once on the Mac |
| `examples/shaders/README.md` | the exact command, `glslangValidator --version`, sizes and sha256s, the portability note |
| `examples/proof_headless.php` | the proof: 13 blocks, instance → device → image → render pass → pipeline → draw → readback → two pixel checks → teardown |
| `scripts/pi-verify.sh` | now runs `proof_headless.php` and gates on `PROOF_HEADLESS_OK` |
| `scripts/tests/structure-check.php` | asserts both proofs, the vendored SPIR-V, and that pi-verify runs the current wave's proof |
| `install-macos.sh`, `build-linux.sh` | closing hint names both proofs |
| `README.md` | requirements table for both platforms, install commands, quick start, the two measured proof outputs |
| `.okf/traps/no-null-cstring-parameter.md` | **new** |
| `.okf/traps/memory-types-differ-per-driver.md` | **new** |
| `.okf/traps/{moltenvk-portability,pointer-bits-only,no-window-in-ext}.md` | corrected and extended against what Wave 2 measured |

The proof uses **only generated classes** — `Vulkan\VK\VK10\VK10`, 41
`Vulkan\Struct\*` classes and `Vulkan\Bridge\Bridge`, 43 imports and not one
of them unused — and **only 1.0 commands**, which is why the same script runs on
a device that reports 1.3. Its 74 inlined `VK_*` constants are grouped under the
`vk.xml` `<enums>` block each came from; the extension still defines none.

### Measured on both boxes

Mac — Apple M1 Pro, MoltenVK 1.4.2, Homebrew loader 1.4.357.0, macOS 15.4.1:

```
device: Apple M1 Pro api 1.3.357 type 1 queueFamily 0
pixel(32,32): 255,128,64,255
pixel(0,0): 0,0,0,255
PROOF_HEADLESS_OK
```

Pi 5 — Mesa 26.2 V3D 7.1.7.0, libvulkan-dev 1.4.309.0-1, Debian 13 trixie,
gcc 14.2.0, through `scripts/pi-verify.sh`:

```
device: V3D 7.1.7.0 api 1.3.354 type 1 queueFamily 0
pixel(32,32): 255,128,64,255
pixel(0,0): 0,0,0,255
PROOF_HEADLESS_OK
pi-verify: PI_VERIFY_OK
```

**The same four bytes at (32,32) on both.** `(1.0, 0.5, 0.25, 1.0)` through an
`R8G8B8A8_UNORM` attachment is `255, 127.5, 63.75, 255`; the proof allows one
unit of slack per channel because the rounding direction is the
implementation's, and neither implementation used it — both rounded to
`255,128,64,255`. The clear colour is exact on both.

Gate, in order, all green: `gen-vk-src.php --check` → `GEN_SRC_CLEAN`;
`check-parity.php` → `PARITY_OK` → `AUDIT_OK` (`structs=368 members=2296`);
`tests/run-all.php` → `TESTS_OK` (8 checks); `install-macos.sh` →
`Version => 0.8.0`; `verify-reflection.php` → `REFLECTION_OK` (382 classes);
both proofs on the Mac; `pi-verify.sh` → `REFLECTION_OK`, `PROOF_HEADLESS_OK`,
`PI_VERIFY_OK`. The Pi's `/usr/local/php84-zts/etc/conf.d` holds exactly one
`30-vulkan.ini`, absolute, naming the `.so` build-linux.sh just installed; the
six other extensions' inis there were not touched.

### Decisions taken, and why

**The render pass carries one explicit subpass dependency.** The plan's block 5
described an attachment and a subpass; `vkCmdCopyImageToBuffer` after
`vkCmdEndRenderPass` needs the colour write to be not just *available* but
*visible* to a transfer read, and the implicit subpass→EXTERNAL dependency ends
at `BOTTOM_OF_PIPE` with an empty access mask. One `VkSubpassDependency`
(`0 → EXTERNAL`, `COLOR_ATTACHMENT_OUTPUT → TRANSFER`, `COLOR_ATTACHMENT_WRITE
→ TRANSFER_READ`) spells it out inside the `vkCreateRenderPass` the plan
already named, rather than adding a `vkCmdPipelineBarrier` the plan's recording
block did not list. Both boxes happen to produce correct pixels either way;
correct-by-accident is not a proof.

**The device is chosen by preferring `INTEGRATED_GPU`, not by taking the first
graphics queue.** On the Pi, V3D (`deviceType` 1) and llvmpipe (`deviceType` 4)
both offer a graphics family, and enumeration order is not a contract. The
proof scans every device, keeps the first with a graphics family, and upgrades
to the first `INTEGRATED_GPU` it finds. Printing `type` in the device line is
what makes that visible in the captured output.

**`glslangValidator -V` with no `--target-env`, so SPIR-V 1.0.** `-V` alone
targets Vulkan 1.0 semantics. `--target-env vulkan1.3` would emit SPIR-V 1.6
and would not load on a 1.0 or 1.1 device; nothing in these four-line shaders
needs anything newer. `glslang` is a generation-box tool like `cc`, and the
`.spv` files are committed so neither box needs it.

**`pi-verify.sh` runs only the headless proof.** It is a strictly stronger
statement than the enumerate proof — it creates the same instance and picks the
same device on the way to drawing — and a Pi round trip is expensive.
`proof_enumerate.php` stays runnable by hand on either box and is still the
README's quick start, and `structure-check.php` asserts both proofs exist and
carry both their tokens.

### Facts learned, now in traps/

- **A `const char *` parameter cannot be NULL through this binding**, and it
  does not need to be. Zephir emits `Z_PARAM_STR`, which is not nullable.
  Exactly four commands in scope take one (`vkGetInstanceProcAddr`,
  `vkGetDeviceProcAddr`, `vkEnumerate{Instance,Device}ExtensionProperties`), and
  only the last two have a meaningful NULL. Measured: the loader treats `""`
  the same as NULL for both, returning all 130 of the M1 Pro's device
  extensions. Making the parameter nullable would put a per-command judgement
  inside a layer that makes none, so it stays.
  [traps/no-null-cstring-parameter.md](/traps/no-null-cstring-parameter.md)
- **V3D has exactly one memory type, and it is `0x07`** — device-local *and*
  host-visible *and* host-coherent. MoltenVK has three (`0x01`, `0x0f`,
  `0x11`). Only a subset test — `($flags & $required) === $required` — picks
  correctly on both; an equality test finds nothing at all on the Pi. A staging
  buffer is a discrete-GPU assumption neither box has.
  [traps/memory-types-differ-per-driver.md](/traps/memory-types-differ-per-driver.md)
- **`VK_KHR_portability_subset` is required by the spec and enforced by
  nobody.** Measured on this Mac: `vkCreateDevice` with the extension
  deliberately omitted returns `VkResult 0`. There is no Khronos validation
  layer on either box (the Mac has no `explicit_layer.d` at all; the Pi has only
  Mesa's overlay/screenshot and Intel's nullhw), so an out-of-spec caller gets
  no signal here and finds out somewhere else. The previous wording of
  [traps/moltenvk-portability.md](/traps/moltenvk-portability.md) claimed
  `vkCreateDevice` *fails* without it; that claim was not checkable-true and has
  been replaced with the measurement.

### Guards watched failing

`structure-check.php`'s six new assertions were each broken and watched firing,
then restored:

| what was broken | what fired |
|---|---|
| first four bytes of `triangle.vert.spv` overwritten | `examples/shaders/triangle.vert.spv does not begin with the SPIR-V magic word` |
| `triangle.vert.spv` truncated to 819 bytes | `examples/shaders/triangle.vert.spv is not a whole number of SPIR-V words` |
| `pi-verify.sh` pointed back at `proof_enumerate.php` | `scripts/pi-verify.sh does not run the headless proof` |
| `PROOF_HEADLESS_FAILED: ` renamed in the proof | `proof_headless.php has no named failure token` |
| a second `PHP_OS_FAMILY ===` added to the proof | `proof_headless.php branches on PHP_OS_FAMILY in more than one place` |
| the shader README's command line altered | `examples/shaders/README.md does not record the command that produced the .spv files` |

### Left for later waves, deliberately

- **No validation-layer run.** Neither box has the Khronos validation layer
  installed, and installing one is a toolchain change this wave did not make.
  The proof is byte-correct on two drivers and is written to the spec's
  synchronisation rules rather than to what the drivers tolerate, but it has
  not been told so by a layer. First thing to do when a layer is available.
- **No x86_64 Linux build.** Both boxes are arm64.
  `src/vk-struct-asserts.c` is the standing trap for the day someone tries.
- **Constants still live in the proofs.** 74 of them are inlined in
  `proof_headless.php` with their `<enums>` citation. That is the correct home
  until jovian/vulkan mines `vk.xml` for enums, and the duplication between the
  two proofs is the price of the extension defining none.

---

## 2026-09-13 — Review pass over the whole branch (edab91a..HEAD)

One critical read of everything the branch added, against the spec, the house
rules and what is actually checkable-true. Nine findings; the three that
mattered are fixed here, the rest are recorded as accepted.

### Fixed

**`packInto` wrote the caller's memory even when it refused.** Spec §7 says a
refused `pack`/`packInto` makes *no write*, and
[struct-tier.md](/struct-tier.md) said "the fill stops — no partial write".
Neither was true: `phpvk_fill_<T>()` begins with `memset(s, 0, sizeof(*s))` and
writes members as it goes, so an unknown key or an over-long array warned,
refused — and left the caller's bytes zeroed or half-written. Now the generated
`packInto` fills a staging copy on its own stack and `memcpy`s over the
caller's memory only after every member was accepted. `pack` is unchanged: it
was already filling a block it owns and frees on refusal.

**A `char[N]` member longer than `N-1` was silently truncated.**
`phpvk_member_chars()` clamped the length and the generated fill discarded its
return with `(void)`. The sibling rule for `T[N]` refuses an over-long array by
name, spec §7 lists an over-long array as a warned refusal, and house rule 4 is
that nothing is silently omitted — a device name quietly losing its tail is
that omission in string clothing. `phpvk_member_chars()` now returns `-1` after
warning `"<ctx>.<member>: string is N byte(s), the member holds M plus a NUL"`,
and the fill stops. An absent key still zero-fills, and a non-string value
still zero-fills, which is what every other member kind does with a value it
cannot use.

**Two doc claims that were not checkable-true.**
[traps/moltenvk-portability.md](/traps/moltenvk-portability.md) said
`vkCreateDevice` fails on a portability device without
`VK_KHR_portability_subset`; measured, it returns `VkResult 0`, because no
validation layer is installed on either box to enforce that VU. Replaced with
the measurement. [struct-tier.md](/struct-tier.md) said `pack` "returns 0
without allocating"; it mallocs, fills, and frees on refusal — reworded.
[bridge.md](/bridge.md) typed `Bridge::read` as returning `string`; the
binding returns `var` and gives `null` on every refusal — corrected, with the
three refusals named.

### Guards watched failing

Both behaviours were reverted in a scratch build and the two new
`struct-guard.php` controls were watched firing against the old code:

```
struct-guard: VkPhysicalDeviceProperties.deviceName: pack accepted an over-long string and returned 4444052928
struct-guard: an over-long char[N] member did not warn naming VkPhysicalDeviceProperties.deviceName and the length:
struct-guard: a refused packInto rewrote the caller's memory instead of leaving it alone
```

The char control also asserts the other side: a string of exactly `N-1` bytes
is accepted and round-trips, so the check is not off by one.

### Looked at and deliberately left alone

- **`phpvk_member_array_at()` is O(n) per index**, so a scalar array member
  packs in O(n²). The longest array in scope is 32 elements
  (`VkPhysicalDeviceMemoryProperties::memoryTypes`); 1024 hash steps once per
  pack is not worth a second index.
- **Process globals, not thread-locals.** One instance and one device per
  process, stated in `src/phpvk-bridge.c`'s header comment. The Pi's PHP is
  ZTS, so a threaded SAPI driving Vulkan from two threads would collide. That
  is a design choice inherited from ext-opengl, not an oversight, and the CLI
  process model is what this targets.
- **`phpvk_arg_long()` accepts a numeric string.** So does every scalar member.
  Leniency consistent with PHP, and the typed Zephir parameters make it
  unreachable for command arguments.
- **`phpvk_registry_level()` answers `GLOBAL` for a name it does not know**, so
  `Bridge::isAvailable('vkNotACommand')` resolves at global level and gets
  NULL. That is the right answer by the right route, and
  `examples/proof_enumerate.php` checks it.
- **A device-level command called with only an instance loaded resolves
  through `vkGetInstanceProcAddr`** rather than refusing. That is legal Vulkan
  (the loader returns a dispatching trampoline) and it is what makes
  `Bridge::loadDevice()` an optimisation rather than a ceremony, which is what
  spec §5.2 calls it.
- **The union array-fill emitter indents only its first line by four extra
  spaces.** Cosmetic in generated C; not worth a regeneration of 43 files.
