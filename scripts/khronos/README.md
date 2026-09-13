# Vendored Khronos registry

`vk.xml` here is the **audit truth** for this extension. `scripts/gen-vk-src.php`
generates every `src/vk-*.{h,c}` and `src/phpvk-registry.{h,c}` from it, and
`scripts/audit-registry.php` re-measures every `@audit` marker against it. No
other copy of the registry on any box is consulted by anything in this repo.

## Provenance

| | |
|---|---|
| source path | `/opt/homebrew/share/vulkan/registry/vk.xml` |
| Homebrew package | `vulkan-headers` 1.4.357.0 |
| `VK_HEADER_VERSION` | 357 (`/opt/homebrew/include/vulkan/vulkan_core.h`) |
| md5 | `f750004aa051f3a36e34966236662acf` |
| size | 3 290 524 bytes |
| harvested | 2026-09-13, macOS 24.4.0 (Apple M1 Pro) |

The Pi 5's `/usr/share/vulkan/registry/vk.xml` is **1.4.309** and is *not* the
audit truth. The Pi builds what the Mac generated; it never re-generates. A
version skew between the two registries cannot change the surface, because the
surface is decided here and the Pi only compiles it — and the build fails loudly
on the Pi if its headers cannot satisfy what was generated.

**Re-vendoring is a deliberate act.** Copy the new file in, re-run
`php scripts/gen-vk-src.php`, and expect the audit to report every count that
moved; update this README's table and md5 in the same commit. A re-vendored
registry that silently changed the surface is exactly what `audit-registry.php`
exists to refuse.

## Scope measured from this file

Commands, per class (spec §2; sub-blocks `VK_BASE_/VK_COMPUTE_/VK_GRAPHICS_
VERSION_1_x` merged into their core version, aliases excluded because their
target is bound):

| class | registry block | commands | structs first required here |
|---|---|---:|---:|
| `VK\VK10` | `VK_VERSION_1_0` | 137 | 110 |
| `VK\VK11` | `VK_VERSION_1_1` | 28 | 68 |
| `VK\VK12` | `VK_VERSION_1_2` | 13 | 51 |
| `VK\VK13` | `VK_VERSION_1_3` | 37 | 53 |
| `VK\VK14` | `VK_VERSION_1_4` | 19 | 51 |
| `Ext\KHRSurface` | `VK_KHR_surface` | 5 | 2 |
| `Ext\KHRSwapchain` | `VK_KHR_swapchain` | 9 | 8 |
| `Ext\KHRWaylandSurface` | `VK_KHR_wayland_surface` | 2 | 1 |
| `Ext\KHRXcbSurface` | `VK_KHR_xcb_surface` | 2 | 1 |
| `Ext\KHRXlibSurface` | `VK_KHR_xlib_surface` | 2 | 1 |
| `Ext\EXTMetalSurface` | `VK_EXT_metal_surface` | 1 | 1 |
| `Ext\EXTMetalObjects` | `VK_EXT_metal_objects` | 1 | 12 |
| `Ext\EXTDebugUtils` | `VK_EXT_debug_utils` | 11 | 5 |
| — (structs only) | `VK_KHR_portability_enumeration` | 0 | 0 |
| — (structs only) | `VK_KHR_portability_subset` | 0 | 2 |
| — (structs only) | `VK_EXT_layer_settings` | 0 | 2 |
| **total** | | **267** | **368** |

Core alone is **333** structs and unions, which is the number spec §2 quoted.
The struct column counts the bucket a struct was *first* required by, plus
every struct reachable from it **by value**; a pointer member is opaque bits
and is never followed, so it pulls nothing into scope.

Everything else in this file — ray tracing, video, mesh shaders, every other
extension, and Vulkan SC — is out of scope and is not read.
