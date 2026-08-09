---
type: Trap
title: No windowing here
description: Window and VkSurfaceKHR creation belong to glfw — not vulkan
tags: [vulkan, trap, boundaries]
status: draft
generated: { by: okf-documentation-generator/cursor-grok-4.5, at: 2026-08-09T00:12:46Z }
sources:
  - id: vk-zep
    resource: /vulkan/vk/vk.zep
    title: vk.zep
  - id: seg
    resource: /orientation/stack-segmentation.md
    title: Stack segmentation
  - id: demo
    resource: /examples/proof_menu.php
    title: proof_menu.php (planned)
---

# Symptom

Someone expects `Vulkan\Vk\*` to create a window, poll input, or call `vkCreate*Surface`, or PRs start adding GLFW/SDL headers to this package.

# Cause

This extension is **instance/device/present bindings**. Surface creation is intentionally a peer concern (`wrapSurface` only).[^vk-zep][^seg]

# Guidance

- Create window + `VkSurfaceKHR` with `glfw`.
- Wrap with `Vk::wrapSurface((int) $surfacePointer)`.
- Destroy with `Vk::destroySurface($instance, $surface)`.
- Implement Quit as on-screen UI via `presentFrame` menu rect and/or glfw key/close — see [proof_menu.php](/playbooks/demo-loop.md).[^demo]
- Reject PRs that couple this tree to window-kit link flags except as documented peer demo deps.

[^vk-zep]: vk.zep
[^seg]: Stack segmentation
[^demo]: proof_menu.php (planned)
