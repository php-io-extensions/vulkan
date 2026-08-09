---
type: Orientation
title: Stack segmentation
description: Boundaries vs glfw, open-gl, metal, and microscrap
tags: [vulkan, orientation, boundaries]
status: draft
generated: { by: okf-documentation-generator/cursor-grok-4.5, at: 2026-08-09T00:12:46Z }
sources:
  - id: composer
    resource: /composer.json
    title: PIE package manifest
  - id: vk-zep
    resource: /vulkan/vk/vk.zep
    title: vk.zep
  - id: demo
    resource: /examples/proof_menu.php
    title: proof_menu.php (planned)
  - id: metal-overview
    resource: ../metal/.okf/orientation/overview.md
    title: metal package overview
  - id: opengl-seg
    resource: ../open-gl/.okf/orientation/stack-segmentation.md
    title: open-gl stack segmentation
---

# Who owns what

| Concern | Package | Notes |
|---------|---------|--------|
| Window, input, **surface** (`VkSurfaceKHR`) | `php-io-extensions/glfw` (primary demo peer) | Create surface; wrap with `Vk::wrapSurface`[^vk-zep] |
| Vulkan instance / device / swapchain / present | **`php-io-extensions/vulkan`** | This package |
| OpenGL draw API (`gl*`) | `php-io-extensions/open-gl` | Separate product; not a dep[^opengl-seg] |
| Native macOS AppKit + Metal | `php-io-extensions/metal` | Darwin-only ObjC path — **not** required here[^metal-overview] |
| Vulkan ICD on Apple | MoltenVK via system/Homebrew loader | Loader env, not PHP metal |
| Enum / constant values (`VK_*`) | microscrap (PHP enums) | Not compiled into this extension |

# Composition for demos

```text
PHP app
  ├─ glfw    → create window + VkSurfaceKHR + poll events
  └─ vulkan  → instance / device / swapchain / presentFrame (this package)
```

Canonical demo target: `examples/proof_menu.php` — glfw window + Vulkan clear + on-screen Quit menu rect.[^demo]

Quit UX: Vulkan has no native menu bar. The demo draws a menu rect via `Vk::presentFrame` (and/or uses glfw key/window-close). Contrast with metal’s AppKit menus.

# Hard rules

1. Do **not** add GLFW/SDL window APIs to this extension.
2. Do **not** `composer require` metal / open-gl / glfw as runtime deps of this package — peer composition at the app/example layer only.
3. Do **not** conflate MoltenVK (ICD) with `php-io-extensions/metal`.
4. Keep Windows out of PIE `os-families` (exclude), matching glfw/sdl3/open-gl style.[^composer]

[^composer]: PIE package manifest
[^vk-zep]: vk.zep
[^demo]: proof_menu.php (planned)
[^metal-overview]: metal package overview
[^opengl-seg]: open-gl stack segmentation
