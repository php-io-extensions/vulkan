---
type: Trap
title: Runtime resolution, and the one symbol that is linked
description: >-
  Every Vulkan command is resolved through vkGetInstanceProcAddr at call time;
  that one symbol is a genuine link dependency, and a second one would break
  the one-.so-two-boxes contract.
tags: [trap, loader, dlsym, linking, portability]
status: stable
generated:
  by: claude-fable-5.1
  at: 2026-09-13T00:00:00Z
---

# Runtime resolution, and the one symbol that is linked

Two facts that are easy to blur into one false one.

## Fact 1 — no COMMAND is called by name

**No Vulkan command is referenced anywhere in this extension's generated
code.** Every one of the 267 bindings goes through `phpvk_entry()`, which asks
`vkGetInstanceProcAddr` (or `vkGetDeviceProcAddr`, for direct dispatch) once,
caches the answer in a function-static slot, and re-resolves it when a
`load*()` bumps the generation.

That is what lets one `.so` serve both boxes:

- The Pi's V3D device reports Vulkan 1.3; llvmpipe on the same box reports 1.4.
- The Mac's MoltenVK reports 1.4 and has no Wayland, xcb or Xlib surface
  extension at all.

A link-time reference to `vkCmdSetLineStipple` would be satisfied on a 1.4
loader and would make the module fail to load elsewhere. A link-time reference
to `vkCreateMetalSurfaceEXT` would make the Linux build fail outright. Instead
`Vulkan\Ext\EXTMetalSurface\EXTMetalSurface` exists on the Pi and simply warns,
and `Vulkan\Ext\KHRWaylandSurface\KHRWaylandSurface` exists on the Mac and
simply warns. **There is not a single `#ifdef` in any generated binding body.**

## Fact 2 — one symbol IS linked, and it has to be

`src/phpvk-bridge.c` names `vkGetInstanceProcAddr` as the fallback when
`dlopen` by soname cannot find the loader. That is a real link-time dependency,
and `ext/config.m4` carries `-lvulkan` on both platforms to satisfy it — on
Darwin with `-L/opt/homebrew/lib` and an `-Wl,-rpath` so the module can be
loaded at all.

Measured on the built artefacts:

| | result |
|---|---|
| Darwin | `otool -L` shows `/opt/homebrew/opt/vulkan-loader/lib/libvulkan.1.dylib`; `nm -u` lists `_vkGetInstanceProcAddr` and no other `vk*` symbol |
| Linux | `-lvulkan` is genuinely needed for the same symbol; `-ldl` is empty on glibc ≥ 2.34 |

**One symbol is the seam. A second one is a bug**, and two guards say so:
`check-parity.php` rejects any body that *calls* a `vk*` name, and
`loader-guard.php` re-derives the set of `vk*` identifiers *mentioned* in any
`src/*.c` (comments and string literals blanked) and requires it to be exactly
`{vkGetInstanceProcAddr}`. `scripts/tests/fixtures/linktime`,
`.../support-linktime` and `.../struct-native-call` prove the parity half
fires.

## The Vulkan runtime is a requirement, not a warning path

- **macOS:** the Homebrew loader is a load-time dependency of the module. A Mac
  without `vulkan-loader` cannot load the extension at all; without `molten-vk`
  it loads and finds no devices. `install-macos.sh` preflights both plus
  `vulkan-headers`, and the MoltenVK ICD manifest.
- **Linux:** likewise `libvulkan.so.1`, plus an ICD (Mesa on the Pi).
  `build-linux.sh` installs `libvulkan-dev` + `libvulkan1` and checks for the
  soname before building.

## The one place platform knowledge is allowed

`src/phpvk-bridge.c` knows that Darwin means `libvulkan.1.dylib` and Linux
means `libvulkan.so.1`, and `src/phpvk-platform.h` knows which Khronos WSI
headers to include and what to forward-declare for them. Those two files are
the platform seam. Nothing else may become one.
