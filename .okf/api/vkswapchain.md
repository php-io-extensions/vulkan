---
type: CoreType
title: Vulkan\\Vk\\VkSwapchain
description: Presentable swapchain + clear/menu frame state (C-owned presenter)
resource: /vulkan/vk/vkswapchain.zep
tags: [vulkan, api, swapchain, fd]
status: draft
generated: { by: okf-documentation-generator/cursor-grok-4.5, at: 2026-08-09T00:12:46Z }
sources:
  - id: swapchain-zep
    resource: /vulkan/vk/vkswapchain.zep
    title: vkswapchain.zep
  - id: vk-zep
    resource: /vulkan/vk/vk.zep
    title: vk.zep
  - id: api-h
    resource: /src/vulkan-api.h
    title: vulkan-api.h
---

# Schema

| Field | Type | Notes |
|-------|------|--------|
| `fd` | `int` (public) | Opaque **presenter** pointer (not bare `VkSwapchainKHR` alone); `0` = none |
| `width` | `int` (public) | Framebuffer width in pixels |
| `height` | `int` (public) | Framebuffer height in pixels |
| `format` | `int` (public) | Color image `VkFormat` |
| `imageCount` | `int` (public) | Number of swapchain images |

[^swapchain-zep][^api-h]

# Lifecycle

1. `Vk::createSwapchain(...)` → presenter `fd` + schema fields.
2. Loop `Vk::presentFrame($swapchain, …)`; on out-of-date, `resizeSwapchain` / recreate as needed.
3. `Vk::destroySwapchain($swapchain)` zeros `fd` and schema ints.

Presenter owns images, views, render pass, framebuffers, command pool/buffers, and sync objects in C.[^api-h]

# Examples

```php
$r = Vk::presentFrame(
    $swapchain,
    0.05, 0.05, 0.08, 1.0,
    true, $menuX, $menuY, $menuW, $menuH, 0.2, 0.2, 0.25, 1.0
);
if ($r !== 0) {
    // handle VK_ERROR_OUT_OF_DATE_KHR / suboptimal — see vk.zep docblock
}
```

[^swapchain-zep]: vkswapchain.zep
[^vk-zep]: vk.zep
[^api-h]: vulkan-api.h
