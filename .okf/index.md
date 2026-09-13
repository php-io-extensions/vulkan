---
okf_version: "0.2"
---

# vulkan — knowledge bundle

Faithful 1:1 binding of Vulkan 1.0 .. 1.4 core into PHP, plus the window-system,
Metal-interop and debug extensions the Khronos registry defines, and a
generated flat struct tier. One `.so` serves a Mac on MoltenVK and a Raspberry
Pi 5 on Mesa, because every command is resolved at runtime.

Read this index first, then open only the concepts the task needs.

- [binding-rules.md](/binding-rules.md) — the two tables (command parameters,
  struct members) restated as law, the surface rule, and what "nothing
  silently omitted" costs.
- [bridge.md](/bridge.md) — the only glue: the three loader levels, the gate,
  the byte buffers, and the C strings.
- [struct-tier.md](/struct-tier.md) — `pack` / `packInto` / `unpack` / `size`,
  the ownership rules, unions, the 64-bit wrap, and the layout-assert
  contract. `status: stable` since Wave 1: the tier is member-audited,
  layout-asserted on both platforms and round-tripped by
  `scripts/tests/struct-guard.php`.
- [toolchain.md](/toolchain.md) — registry → src → zep → `.so`, its guards,
  and the Mac-generates / Pi-builds split.
- [traps/index.md](/traps/index.md) — runtime-resolution-not-linking,
  pointer-bits-only, no-window-in-ext, moltenvk-portability,
  no-platform-dev-packages, loader-clamps-device-version,
  no-null-cstring-parameter, memory-types-differ-per-driver.
- [log.md](/log.md) — change log, one entry per wave; each says what was built,
  what was measured on which box, and what was deliberately left undone.

## Scope

Vulkan only, and only the parts that need native code. No window, no surface
creation, no constants, no defaults, no `sType` filling, no extension
enabling. Two proofs say so, and every opinion in both of them is in the
*script*:

- `examples/proof_enumerate.php` — instance, physical devices, names and
  versions, teardown. The quick start.
- `examples/proof_headless.php` — a 64x64 offscreen triangle through a real
  graphics pipeline and the vendored SPIR-V in `examples/shaders/`, byte-checked
  at two pixels. No surface, no swapchain, no display server. This is the one
  `scripts/pi-verify.sh` gates on.

**Bound (0.8.0, Waves 0-2):** 267 Vulkan commands and 368 structs and unions
carrying 2296 members, measured from `scripts/khronos/vk.xml`
(`VK_HEADER_VERSION` 357). Waves 1 and 2 added **no binding at all** — Wave 1
added the proof that the struct tier is complete (`structs=368 members=2296`
from `audit-registry.php`, 2664 `_Static_assert`s compiled on both boxes,
`STRUCT_GUARD_OK structs=368` against the built `.so`), and Wave 2 added the
proof that the surface as a whole draws a frame on two unrelated drivers.

| class | commands |
|---|---:|
| `Vulkan\VK\VK10\VK10` | 137 |
| `Vulkan\VK\VK11\VK11` | 28 |
| `Vulkan\VK\VK12\VK12` | 13 |
| `Vulkan\VK\VK13\VK13` | 37 |
| `Vulkan\VK\VK14\VK14` | 19 |
| `Vulkan\Ext\KHRSurface\KHRSurface` | 5 |
| `Vulkan\Ext\KHRSwapchain\KHRSwapchain` | 9 |
| `Vulkan\Ext\KHRWaylandSurface\KHRWaylandSurface` | 2 |
| `Vulkan\Ext\KHRXcbSurface\KHRXcbSurface` | 2 |
| `Vulkan\Ext\KHRXlibSurface\KHRXlibSurface` | 2 |
| `Vulkan\Ext\EXTMetalSurface\EXTMetalSurface` | 1 |
| `Vulkan\Ext\EXTMetalObjects\EXTMetalObjects` | 1 |
| `Vulkan\Ext\EXTDebugUtils\EXTDebugUtils` | 11 |

Plus `Vulkan\Struct\<Name>\<Name>` × 368 (4 methods each = 1472) and
`Vulkan\Bridge\Bridge` × 12. **382 classes, 1751 static methods, 0 reserved.**

Core alone is 333 of the structs; `VK_KHR_portability_enumeration` (0),
`VK_KHR_portability_subset` (2 structs) and `VK_EXT_layer_settings` (2
structs) contribute structs but no command class, which is why they have no
entry in the table above.

**Zero reservations.** The type table covers every command in scope today. The
reservation mechanism exists and is proved able to fire —
`scripts/tests/reserved-guard.php` injects a `PFN_vkVoidFunction` parameter
into a scratch copy of the registry and checks the emitted `@reserved` line —
but nothing in the committed tree uses it. A reservation appearing is news
that belongs in [log.md](/log.md).

**Out of scope, permanently:** window or surface *creation* of any kind; every
extension not listed (ray tracing, video, mesh shaders, …); Vulkan SC;
MoltenVK's private API; constants and enums, which live in **jovian/vulkan**.

Layering, verbatim house law: **ext-vulkan = Vulkan + unavoidable glue;
jovian/vulkan = PHP projection, typed handles and constants; venusian =
composition; surface = abstraction.**
