---
type: Architecture
title: Handles
description: Identity table, parent chains, and which destroy releases which PHP handles.
tags: [vulkan, handles, lifetime]
status: draft
generated: { by: grok/4.7, at: 2026-10-05T09:30:00-04:00 }
sources:
  - id: plan
    resource: /docs/superpowers/plans/2026-10-05-slice-4-ext-vulkan.md
    title: Slice 4 plan
  - id: runtime
    resource: src/runtime.c
    title: Identity table and release tree
---

# Identity

`vulkan_handle` stores the native value as `uint64_t` and a `zend_object *` parent. The identity table is one hash per class, keyed by that value. `fromPointer` returns the live object of that class, or boxes a new one with no parent. Address 0 is refused. A value of 0 means the PHP handle has been released.[^runtime]

Dropping the last PHP reference does not destroy the native object. The child holds a reference to its parent so the parent object stays alive while a child does.

# Release

`vulkan_release_tree` releases the object and every live handle whose parent chain reaches it. The set is computed before any parent pointer is cleared. A released handle passed to any binding throws `ValueError` "`Name has been destroyed`" before the driver is called.

| Destroy or free | Releases |
|---|---|
| `vkDestroyInstance` | the instance, and every handle whose chain reaches it (physical devices, devices, and what those own) |
| `vkDestroyDevice` | the device, its queues, and every buffer, image, view, sampler, pool, pipeline, and swapchain parented to it |
| `vkDestroyCommandPool` | the pool and its command buffers |
| `vkDestroyDescriptorPool` | the pool and its descriptor sets |
| `vkDestroySwapchainKHR` | the swapchain and its images |
| `vkFreeMemory`, `vkDestroyBuffer`, `vkDestroyImage`, and the other `vkDestroy*` | that handle |
| `vkDestroySurfaceKHR` | that surface, including one that entered through `fromPointer` |

Swapchain images are parented to the swapchain. PHP does not call `vkDestroyImage` on them. A surface made by SDL enters through `VkSurfaceKHR::fromPointer()` with no parent, so only `vkDestroySurfaceKHR` releases it.[^plan]

[^runtime]: `src/runtime.c` boxes by class and value, and walks parent pointers.
[^plan]: Slice 4 plan, handle rules and the swapchain test.
