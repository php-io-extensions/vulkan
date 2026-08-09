---
type: Convention
title: fd ownership
description: Who creates and destroys opaque handles stored in public fd
tags: [vulkan, convention, memory, fd]
status: draft
generated: { by: okf-documentation-generator/cursor-grok-4.5, at: 2026-08-09T00:12:46Z }
sources:
  - id: vk-zep
    resource: /vulkan/vk/vk.zep
    title: vk.zep
  - id: api-h
    resource: /src/vulkan-api.h
    title: vulkan-api.h
  - id: swapchain-zep
    resource: /vulkan/vk/vkswapchain.zep
    title: vkswapchain.zep
---

# Rules

| Object | Create | Destroy |
|--------|--------|---------|
| `VkInstance` | `Vk::createInstance` | `Vk::destroyInstance` zeros `fd` |
| `VkPhysicalDevice` | `enumeratePhysicalDevices` | Invalid after instance destroy (no per-device destroy) |
| `VkDevice` | `Vk::createDevice` | `Vk::destroyDevice` |
| `VkQueue` | `Vk::getDeviceQueue` | Owned by device |
| `VkSurface` | glfw create + `Vk::wrapSurface` | `Vk::destroySurface` |
| `VkSwapchain` | `Vk::createSwapchain` | `Vk::destroySwapchain` (frees C presenter) |

# Semantics

- `fd` is a **public int** wrapping `uintptr_t`, not a POSIX file descriptor.[^vk-zep]
- `0` means “no object”; do not destroy `0`.
- `VkSwapchain::fd` is a C **presenter** struct, not a lone `VkSwapchainKHR`.[^swapchain-zep][^api-h]
- Destroying the PHP object **without** calling the matching destroy helper leaks native resources until process exit.
- Destroy order: swapchain → device → surface → instance (typical).

# Checklist

1. Obtain glfw surface before device queue selection that needs present support.
2. Destroy swapchains before devices; destroy surfaces with a live instance.
3. Zero `fd` after successful destroy (helpers already do this).

[^vk-zep]: vk.zep
[^api-h]: vulkan-api.h
[^swapchain-zep]: vkswapchain.zep
