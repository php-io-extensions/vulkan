---
type: CoreType
title: Vulkan\\Vk\\VkDevice
description: Opaque VkDevice DTO with public fd and queueFamily
resource: /vulkan/vk/vkdevice.zep
tags: [vulkan, api, device, fd]
status: draft
generated: { by: okf-documentation-generator/cursor-grok-4.5, at: 2026-08-09T00:12:46Z }
sources:
  - id: device-zep
    resource: /vulkan/vk/vkdevice.zep
    title: vkdevice.zep
  - id: vk-zep
    resource: /vulkan/vk/vk.zep
    title: vk.zep
---

# Schema

| Field | Type | Notes |
|-------|------|--------|
| `fd` | `int` (public) | Opaque `VkDevice` pointer; `0` = none / destroyed |
| `queueFamily` | `int` (public) | Queue family used at create; `-1` after destroy |

[^device-zep]

# Lifecycle

1. `Vk::createDevice($physical, $queueFamily)`.
2. Use with `getDeviceQueue` / `createSwapchain`.
3. `Vk::destroyDevice($device)` zeros `fd` and sets `queueFamily = -1`.

Destroy swapchains that reference the device first. See [fd ownership](/conventions/fd-ownership.md).

[^device-zep]: vkdevice.zep
[^vk-zep]: vk.zep
