---
type: Architecture
title: Layered stack
description: Zephir → thin C ABI → Vulkan loader / MoltenVK
resource: /config.json
tags: [vulkan, architecture, zephir]
status: draft
generated: { by: okf-documentation-generator/cursor-grok-4.5, at: 2026-08-09T00:12:46Z }
sources:
  - id: config
    resource: /config.json
    title: Zephir config
  - id: vk-zep
    resource: /vulkan/vk/vk.zep
    title: vk.zep
  - id: api-h
    resource: /src/vulkan-api.h
    title: vulkan-api.h
  - id: prepare
    resource: /scripts/prepare-ext.sh
    title: prepare-ext.sh
  - id: composer
    resource: /composer.json
    title: PIE package manifest
---

# Layers

```text
PHP (Vulkan\Vk\{Vk,VkInstance,VkPhysicalDevice,VkDevice,VkQueue,VkSurface,VkSwapchain})
        │  Zephir static methods + thin DTO classes with public fd
        ▼
Thin C ABI (src/vulkan-api.h / src/vulkan-api.c → ext/src/)
        │  opaque uintptr_t handles; php_vk_* helpers
        ▼
Vulkan loader + ICD
   Darwin: libvulkan → MoltenVK (Metal under the ICD)
   Linux:  libvulkan → vendor/Mesa ICD
```

Unlike [metal](../metal/), there is **no** Objective-C bridge in this package. Unlike [open-gl](../open-gl/), Zephir does not call the full C API 1:1 — it calls a curated C helper surface.[^vk-zep][^api-h]

# Source map

| Layer | Path | Role |
|-------|------|------|
| Zephir | `vulkan/vk/{vk,vkinstance,vkphysicaldevice,vkdevice,vkqueue,vksurface,vkswapchain}.zep` | Public PHP API |
| C ABI | `src/vulkan-api.{h,c}` → synced to `ext/src/` | Loader ensure, instance/device/swapchain |
| Zephir config | `config.json` | `extra-sources: src/vulkan-api.c`, `-lvulkan` |
| Packaging | `scripts/prepare-ext.sh` | Generate + patch into `ext/` |
| PIE | `composer.json` | `build-path: ext`, Linux+Darwin |

# Design intent

- Keep Zephir thin: static methods on `Vk` map to `php_vk_*` helpers.
- Data objects hold schema + opaque pointer-as-int in `fd` — see [Zephir static + fd](/architecture/zephir-static-and-fd.md).
- Surface must already exist (glfw) before device/swapchain helpers that need present support.
- Constants stay out of the extension — see [Constants in microscrap](/conventions/constants-microscrap.md).

[^config]: Zephir config
[^vk-zep]: vk.zep
[^api-h]: vulkan-api.h
[^prepare]: prepare-ext.sh
[^composer]: PIE package manifest
