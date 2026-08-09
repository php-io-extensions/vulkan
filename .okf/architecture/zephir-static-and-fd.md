---
type: Architecture
title: Zephir static + fd objects
description: Static Vk::* helpers plus Vk* schema classes with public fd
tags: [vulkan, architecture, zephir, fd]
status: draft
generated: { by: okf-documentation-generator/cursor-grok-4.5, at: 2026-08-09T00:12:46Z }
sources:
  - id: vk-zep
    resource: /vulkan/vk/vk.zep
    title: vk.zep
  - id: instance-zep
    resource: /vulkan/vk/vkinstance.zep
    title: vkinstance.zep
  - id: swapchain-zep
    resource: /vulkan/vk/vkswapchain.zep
    title: vkswapchain.zep
  - id: sibling
    resource: /conventions/sibling-patterns.md
    title: Sibling patterns
---

# Two surfaces

| Kind | Example | Pattern |
|------|---------|---------|
| Static API class | `Vulkan\Vk\Vk` | Static methods wrapping `php_vk_*` (create instance, present frame, …) |
| Data objects | `VkInstance`, `VkPhysicalDevice`, `VkDevice`, `VkQueue`, `VkSurface`, `VkSwapchain` | Zephir DTOs with typed schema fields + public `int $fd` |

# `fd` meaning

- `fd` is a **public int** holding an opaque native pointer (`uintptr_t`), not a POSIX file descriptor.
- Name chosen for consistency with other php-io-extensions “opaque handle as int” habits (open-gl, glfw, sdl3, metal).[^vk-zep][^instance-zep]
- `0` means none / failure / destroyed.

# Ownership sketch

```text
$inst = Vk::createInstance($extensions);   // pointer in $inst->fd
$surface = Vk::wrapSurface($glfwSurfaceFd); // glfw-owned surface pointer
$sw = Vk::createSwapchain(...);             // C presenter struct in $sw->fd
Vk::presentFrame($sw, ...);
Vk::destroySwapchain($sw);                  // zeros fd
```

`VkSwapchain::fd` points at an **internal presenter** (swapchain + images/views/pass/sync), not a bare `VkSwapchainKHR` alone.[^swapchain-zep]

See [fd ownership](/conventions/fd-ownership.md) and API concepts under `/api/`.

# What stays out of Zephir classes

- No PHP class-level constants for `VK_*` enums.
- No FFI stubs or dual-path loaders inside the extension.
- No window creation APIs.

[^vk-zep]: vk.zep
[^instance-zep]: vkinstance.zep
[^swapchain-zep]: vkswapchain.zep
[^sibling]: Sibling patterns
