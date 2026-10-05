---
type: Runbook
title: Build, install, test
description: How ext-vulkan is built on the Mac and on the Pi, and what those machines measured.
tags: [vulkan, build, pi, macos]
status: draft
generated: { by: grok/4.7, at: 2026-10-05T09:30:00-04:00 }
sources:
  - id: plan
    resource: /docs/superpowers/plans/2026-10-05-slice-4-ext-vulkan.md
    title: Slice 4 plan
---

# Measured 2026-10-05

| | Pi 5 | Mac |
|---|---|---|
| Headers / loader | `vulkan_core.h` 1.4.309, `pkg-config vulkan` 1.4.309 | `/opt/homebrew/include` 1.4.357, `libvulkan.dylib` |
| Physical devices | GPU0 V3D 7.1.7.0, `DRIVER_ID_MESA_V3DV`, API 1.3, integrated; GPU1 llvmpipe (`CPU`) | MoltenVK, visible only with portability enumeration (slice 5) |
| V3DV samples | `framebufferColorSampleCounts` and `framebufferStencilSampleCounts`: 1, 4 | — |
| V3DV memory | type 0: `DEVICE_LOCAL \| HOST_VISIBLE \| HOST_COHERENT`; `nonCoherentAtomSize` 256 | — |
| V3DV extensions | `VK_KHR_external_memory_fd`, `VK_EXT_external_memory_dma_buf`, `VK_EXT_image_drm_format_modifier` | — |

# Install

Mac: `./install-macos.sh` builds a disposable copy for Homebrew `php@8.4` and `php@8.4-zts`, signs the `.so`, and writes `30-vulkan.ini`. It checks `pkg-config --exists vulkan`.

Pi: the Mac tree is authoritative. Copy with `fnk` (`COPYFILE_DISABLE=1 tar --no-mac-metadata --exclude .git`), then `./install-debian-trixie.sh`. That checks `vulkan >= 1.3` (`apt install libvulkan-dev`), prefers the distro pkg-config path, and removes the phpize output afterwards.

# Test

Pest v4, `composer install`, then `php -d memory_limit=128M vendor/bin/pest`.

On 2026-10-05 the Pi suite was 20 passed, 1210 assertions, with `WAYLAND_DISPLAY=wayland-0` and `XDG_RUNTIME_DIR=/run/user/$(id -u)`. Homebrew `php@8.4` NTS and ZTS were 5 passed, 15 skipped, 1147 assertions. The skips are the device tests: `MoltenVK needs portability enumeration: slice 5`.

The swapchain test opens a window. The gate reads back a stencil-then-cover triangle.
