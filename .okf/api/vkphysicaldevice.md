---
type: CoreType
title: Vulkan\\Vk\\VkPhysicalDevice
description: Opaque VkPhysicalDevice DTO with queried schema fields
resource: /vulkan/vk/vkphysicaldevice.zep
tags: [vulkan, api, physical-device, fd]
status: draft
generated: { by: okf-documentation-generator/cursor-grok-4.5, at: 2026-08-09T00:12:46Z }
sources:
  - id: phys-zep
    resource: /vulkan/vk/vkphysicaldevice.zep
    title: vkphysicaldevice.zep
  - id: vk-zep
    resource: /vulkan/vk/vk.zep
    title: vk.zep
---

# Schema

| Field | Type | Notes |
|-------|------|--------|
| `fd` | `int` (public) | Opaque `VkPhysicalDevice` pointer; `0` = none |
| `name` | `string` (public) | From `VkPhysicalDeviceProperties.deviceName` |
| `deviceType` | `int` (public) | `VkPhysicalDeviceType` value |
| `vendorId` | `int` (public) | Vendor ID |
| `deviceId` | `int` (public) | Device ID |

Filled by `Vk::enumeratePhysicalDevices`.[^phys-zep][^vk-zep]

# Lifecycle

Physical devices are not destroyed individually; they are invalidated when the owning instance is destroyed. Do not retain `fd` after `destroyInstance`.

[^phys-zep]: vkphysicaldevice.zep
[^vk-zep]: vk.zep
