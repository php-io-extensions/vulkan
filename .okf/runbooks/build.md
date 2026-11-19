---
type: Runbook
title: Build, install, test
description: How ext-vulkan is built on the Mac and on the Pi, and what those machines measured.
tags: [vulkan, build, pi, macos]
status: draft
generated: { by: grok/4.7, at: 2026-10-05T09:30:00-04:00 }
sources:
  - id: installers
    resource: install-macos.sh
    title: install-macos.sh and install-debian-trixie.sh
---

# Measured 2026-10-05

| | Pi 5 | Mac |
|---|---|---|
| Headers / loader | `vulkan_core.h` 1.4.309, `pkg-config vulkan` 1.4.309 | `/opt/homebrew/include` 1.4.357, `libvulkan.dylib` |
| Physical devices | GPU0 V3D 7.1.7.0, `DRIVER_ID_MESA_V3DV`, API 1.3, integrated; GPU1 llvmpipe (`CPU`) | Apple M1 Pro, `INTEGRATED_GPU`, `DRIVER_ID_MOLTENVK`, API 1.4.357, driver 1.4.2. Visible only with portability enumeration |
| Samples | `framebufferColorSampleCounts` and `framebufferStencilSampleCounts`: 1, 4 | colour and stencil: 1, 2, 4 |
| Memory | type 0: `DEVICE_LOCAL \| HOST_VISIBLE \| HOST_COHERENT` (`0x7`); `nonCoherentAtomSize` 256 | property flags `0x1`, `0xf` (device-local, host-visible, coherent, cached), `0x11`; `nonCoherentAtomSize` 16 |
| Extensions | `VK_KHR_external_memory_fd`, `VK_EXT_external_memory_dma_buf`, `VK_EXT_image_drm_format_modifier`. No portability enumeration | Instance: `VK_KHR_portability_enumeration`, `VK_EXT_metal_surface`, `VK_KHR_surface`. Device: `VK_KHR_portability_subset` |
| Depth-stencil | `D24_UNORM_S8_UINT` | `D32_SFLOAT_S8_UINT` only |
| Portability subset | the struct is left untouched (not a portability driver) | `triangleFans` true, `pointPolygons` false, `samplerMipLodBias` false, `tessellationIsolines` false, `tessellationPointMode` false, the other ten true |

`vulkan_beta.h` on both machines declares `VkPhysicalDevicePortabilitySubsetFeaturesKHR` behind `VK_ENABLE_BETA_EXTENSIONS`. `src/runtime.h` defines that macro before `<vulkan/vulkan.h>`. No other beta declaration is bound.

# Install

Mac: `./install-macos.sh` builds a disposable copy for Homebrew `php@8.4` and `php@8.4-zts`, signs the `.so`, and writes `30-vulkan.ini`. It checks `pkg-config --exists vulkan`.

Pi: the Mac tree is authoritative. Copy with `fnk` (`COPYFILE_DISABLE=1 tar --no-mac-metadata --exclude .git`), then `./install-debian-trixie.sh`. That checks `vulkan >= 1.3` (`apt install libvulkan-dev`), prefers the distro pkg-config path, and removes the phpize output afterwards.

# Test

Pest v4, `composer install`, then `php -d memory_limit=128M vendor/bin/pest`.

On 2026-10-05, after MoltenVK, Homebrew `php@8.4` NTS and ZTS were 22 passed, 2 skipped, 1221 assertions. The skips are the Linux swapchain and dmabuf tests. The Pi was 23 passed, 1 skipped, 1223 assertions, with `WAYLAND_DISPLAY=wayland-0` and `XDG_RUNTIME_DIR=/run/user/$(id -u)`. The skip is the Metal surface test.

`tests/MeshShaderTest.php` is the exception to "device tests skip the CPU device". MoltenVK (Apple M1 Pro) lists neither `VK_EXT_mesh_shader` nor `VK_KHR_draw_indirect_count`; on this Mac the only device that lists `VK_EXT_mesh_shader` is lavapipe (Mesa 26.3 from Homebrew, `llvmpipe (LLVM 23.1.5, 128 bits)`, `VK_PHYSICAL_DEVICE_TYPE_CPU`, ICD `/opt/homebrew/share/vulkan/icd.d/lvp_icd.aarch64.json`, found by the loader with no environment variable). The mesh tests make their own instance and device on the first device that lists the extension, with `meshShader` and `hostImageCopy` on `VkDeviceCreateInfo->pNext`, and skip only where none does. The shaders are `tests/Fixtures/triangle.mesh` and `triangle.frag`, compiled with `glslangValidator -V --target-env vulkan1.3`.

`tests/MultisampledRenderToSingleSampledTest.php` is a second such exception, on the same lavapipe device: it opens the first device that lists `VK_EXT_multisampled_render_to_single_sampled` (MoltenVK does not), enables the feature on `VkDeviceCreateInfo->pNext` with `hostImageCopy`, and skips only where none does. Its vertex shader is `tests/Fixtures/triangle.vert` (fragment: `triangle.frag`), compiled the same way.

The swapchain test opens a window. The gate reads back a stencil-then-cover triangle. On macOS that gate runs through MoltenVK and picks `VK_FORMAT_D32_SFLOAT_S8_UINT`.
