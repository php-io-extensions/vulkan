---
type: CoreType
title: Vulkan\\Vk\\VkSurface
description: Opaque VkSurfaceKHR DTO (usually created by glfw, destroyed here)
resource: /vulkan/vk/vksurface.zep
tags: [vulkan, api, surface, fd, glfw]
status: draft
generated: { by: okf-documentation-generator/cursor-grok-4.5, at: 2026-08-09T00:12:46Z }
sources:
  - id: surface-zep
    resource: /vulkan/vk/vksurface.zep
    title: vksurface.zep
  - id: vk-zep
    resource: /vulkan/vk/vk.zep
    title: vk.zep
---

# Schema

| Field | Type | Notes |
|-------|------|--------|
| `fd` | `int` (public) | Opaque `VkSurfaceKHR` pointer; `0` = none / destroyed |

[^surface-zep]

# Lifecycle

1. Peer glfw creates the surface; pass the pointer as int into `Vk::wrapSurface($surfaceFd)`.
2. Use with `findGraphicsPresentQueue` / `createSwapchain`.
3. `Vk::destroySurface($instance, $surface)` destroys the Vulkan surface and zeros `fd`.

This package does **not** create surfaces — see [No windowing](/traps/no-windowing.md).[^vk-zep]

[^surface-zep]: vksurface.zep
[^vk-zep]: vk.zep
