---
type: CoreType
title: Vulkan\\Vk\\VkInstance
description: Opaque VkInstance DTO with public fd and appName
resource: /vulkan/vk/vkinstance.zep
tags: [vulkan, api, instance, fd]
status: draft
generated: { by: okf-documentation-generator/cursor-grok-4.5, at: 2026-08-09T00:12:46Z }
sources:
  - id: instance-zep
    resource: /vulkan/vk/vkinstance.zep
    title: vkinstance.zep
  - id: vk-zep
    resource: /vulkan/vk/vk.zep
    title: vk.zep
---

# Schema

| Field | Type | Notes |
|-------|------|--------|
| `fd` | `int` (public) | Opaque `VkInstance` pointer; `0` = none / destroyed |
| `appName` | `string` (public) | Application name used at create time |

[^instance-zep]

# Lifecycle

1. `Vk::createInstance($extensions, $appName)` → non-zero `fd` on success.
2. Pass to enumerate / createSwapchain / destroySurface helpers.
3. `Vk::destroyInstance($instance)` zeros `fd`.

See [fd ownership](/conventions/fd-ownership.md).

[^instance-zep]: vkinstance.zep
[^vk-zep]: vk.zep
