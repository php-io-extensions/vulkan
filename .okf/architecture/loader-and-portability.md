---
type: Architecture
title: Loader and Apple portability
description: MoltenVK ICD discovery and VK_KHR_portability_* on Darwin
resource: /src/vulkan-api.c
tags: [vulkan, architecture, moltenvk, portability, darwin]
status: draft
generated: { by: okf-documentation-generator/cursor-grok-4.5, at: 2026-08-09T00:12:46Z }
sources:
  - id: api-c
    resource: /src/vulkan-api.c
    title: vulkan-api.c
  - id: api-h
    resource: /src/vulkan-api.h
    title: vulkan-api.h
  - id: config
    resource: /config.json
    title: Zephir config
  - id: patch
    resource: /scripts/patch-config-m4.py
    title: patch-config-m4.py
---

# Linking

PIE / `config.m4` discovers Vulkan via `pkg-config vulkan` when available, else `-lvulkan`, plus Homebrew `/opt/homebrew` and `/usr/local` include/lib paths.[^patch][^config]

# Darwin ICD discovery

`php_vk_ensure_loader()` (called from `php_vk_create_instance`) on Apple:[^api-c]

1. If `VK_ICD_FILENAMES` or `VK_DRIVER_FILES` is already set and non-empty → leave alone.
2. Else try readable candidates:
   - `/opt/homebrew/etc/vulkan/icd.d/MoltenVK_icd.json`
   - `/usr/local/etc/vulkan/icd.d/MoltenVK_icd.json`
3. On first hit, `setenv` both `VK_ICD_FILENAMES` and `VK_DRIVER_FILES` (do not overwrite if already set).

Operators may still export the ICD path manually before PHP starts — see [MoltenVK ICD trap](/traps/moltenvk-icd.md).

# Portability extensions (Apple)

| Layer | Extension / flag | Where |
|-------|------------------|--------|
| Instance | `VK_KHR_portability_enumeration` | Auto-appended on Darwin if missing; `VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR` set |
| Device | `VK_KHR_portability_subset` | Enabled in `php_vk_create_device` on Darwin |
| Device | `VK_KHR_swapchain` | Always enabled |

C also defines `VK_USE_PLATFORM_METAL_EXT` when including `<vulkan/vulkan.h>` — that is a **Vulkan header platform** flag for MoltenVK/Metal surfaces, not a link to the metal PHP extension.[^api-c]

# Linux

No MoltenVK ICD helper; rely on the system Vulkan loader and installed ICDs. Portability enumeration/subset paths are `#if defined(__APPLE__)` only.

[^api-c]: vulkan-api.c
[^api-h]: vulkan-api.h
[^config]: Zephir config
[^patch]: patch-config-m4.py
