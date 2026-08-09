---
type: CoreType
title: Vulkan\\Vk\\VkQueue
description: Opaque VkQueue DTO with public fd and familyIndex
resource: /vulkan/vk/vkqueue.zep
tags: [vulkan, api, queue, fd]
status: draft
generated: { by: okf-documentation-generator/cursor-grok-4.5, at: 2026-08-09T00:12:46Z }
sources:
  - id: queue-zep
    resource: /vulkan/vk/vkqueue.zep
    title: vkqueue.zep
  - id: vk-zep
    resource: /vulkan/vk/vk.zep
    title: vk.zep
---

# Schema

| Field | Type | Notes |
|-------|------|--------|
| `fd` | `int` (public) | Opaque `VkQueue` pointer; `0` = none |
| `familyIndex` | `int` (public) | Queue family index; `-1` unset |

Obtained via `Vk::getDeviceQueue`. Queues are owned by the device — no separate destroy helper.[^queue-zep][^vk-zep]

[^queue-zep]: vkqueue.zep
[^vk-zep]: vk.zep
