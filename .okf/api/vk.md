---
type: CoreType
title: Vulkan\\Vk\\Vk
description: Static instance/device/swapchain/present entry points
resource: /vulkan/vk/vk.zep
tags: [vulkan, api, vk]
status: draft
generated: { by: okf-documentation-generator/cursor-grok-4.5, at: 2026-08-09T00:12:46Z }
sources:
  - id: vk-zep
    resource: /vulkan/vk/vk.zep
    title: vk.zep
  - id: api-h
    resource: /src/vulkan-api.h
    title: vulkan-api.h
  - id: demo
    resource: /examples/proof_menu.php
    title: proof_menu.php (planned)
---

# Role

Static facade for Vulkan helpers used by PHP demos: instance/device lifecycle, surface wrap/destroy, swapchain present. Window/surface **creation** stays in glfw.[^vk-zep]

# Schema

## Errors

| Method | Returns | Notes |
|--------|---------|--------|
| `lastError()` | `string` | Last C helper error (`php_vk_last_error`); may be empty |

## Instance / physical devices

| Method | Returns | Notes |
|--------|---------|--------|
| `createInstance(array $extensions = [], string $appName = "php-io-extensions/vulkan")` | `VkInstance` | Sets `fd`, `appName`; Darwin portability bits added in C |
| `destroyInstance(VkInstance)` | `void` | Zeros `fd` |
| `enumeratePhysicalDevices(VkInstance)` | `array` of `VkPhysicalDevice` | Fills name/type/vendor/device ids |

## Device / queue

| Method | Returns | Notes |
|--------|---------|--------|
| `findGraphicsPresentQueue(VkPhysicalDevice, VkSurface)` | `int` | Family index or `-1` |
| `createDevice(VkPhysicalDevice, int $queueFamily)` | `VkDevice` | |
| `destroyDevice(VkDevice)` | `void` | Zeros `fd`, resets `queueFamily` |
| `getDeviceQueue(VkDevice, int $queueFamily)` | `VkQueue` | |

## Surface

| Method | Returns | Notes |
|--------|---------|--------|
| `wrapSurface(int $surfaceFd)` | `VkSurface` | Wrap existing `VkSurfaceKHR` pointer (e.g. glfw) |
| `destroySurface(VkInstance, VkSurface)` | `void` | Zeros surface `fd` |

## Swapchain / present

| Method | Returns | Notes |
|--------|---------|--------|
| `createSwapchain(VkInstance, VkPhysicalDevice, VkDevice, VkQueue, VkSurface, int $width, int $height)` | `VkSwapchain` | Fills size/format/imageCount |
| `destroySwapchain(VkSwapchain)` | `void` | |
| `resizeSwapchain(VkSwapchain, int $width, int $height)` | `int` | `0` success; refreshes schema fields |
| `presentFrame(VkSwapchain, float $clearR/G/B, float $clearA = 1.0, … menu/inner rects)` | `int` | `0` success; may return out-of-date / suboptimal VkResult codes |

`presentFrame` clear/menu/inner colors are **floats 0..1**. Menu/inner coordinates are framebuffer pixels, origin **top-left**. Optional bools `drawMenu` / `drawInner` gate clearAttachments rects.[^vk-zep][^api-h]

All methods are `public static` on `Vulkan\Vk\Vk`.

# Examples

```php
use Vulkan\Vk\Vk;

$instance = Vk::createInstance($glfwRequiredExtensions);
$devices = Vk::enumeratePhysicalDevices($instance);
$surface = Vk::wrapSurface($glfwSurfacePointerAsInt);
$family = Vk::findGraphicsPresentQueue($devices[0], $surface);
$device = Vk::createDevice($devices[0], $family);
$queue = Vk::getDeviceQueue($device, $family);
$swapchain = Vk::createSwapchain($instance, $devices[0], $device, $queue, $surface, $w, $h);
Vk::presentFrame($swapchain, 0.1, 0.2, 0.3, 1.0);
```

Demo: [proof_menu.php](/playbooks/demo-loop.md).[^demo]

# Implementation notes

- No class constants — pass enum/`int` values from microscrap.
- Do not add window APIs — see [No windowing](/traps/no-windowing.md).
- No FFI — see [No FFI](/conventions/no-ffi.md).

[^vk-zep]: vk.zep
[^api-h]: vulkan-api.h
[^demo]: proof_menu.php (planned)
