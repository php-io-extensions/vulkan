---
type: Orientation
title: Package overview
description: What vulkan is, version targets, and what it deliberately is not
resource: /composer.json
tags: [vulkan, orientation, php-ext]
status: draft
generated: { by: okf-documentation-generator/cursor-grok-4.5, at: 2026-08-09T00:12:46Z }
sources:
  - id: composer
    resource: /composer.json
    title: PIE package manifest
  - id: config
    resource: /config.json
    title: Zephir config
  - id: vk-zep
    resource: /vulkan/vk/vk.zep
    title: vk.zep
  - id: api-h
    resource: /src/vulkan-api.h
    title: vulkan-api.h
  - id: demo
    resource: /examples/proof_menu.php
    title: proof_menu.php (planned sibling-style demo)
---

# Summary

`php-io-extensions/vulkan` is a **Linux + macOS** PHP extension (`type: php-ext`) that exposes a practical subset of the **Vulkan** instance/device/present path to PHP via Zephir and a thin C ABI. Windowing and `VkSurfaceKHR` creation are **out of scope** — demos pair this extension with peer `glfw` (same composition model as open-gl). On Darwin the Vulkan loader resolves **MoltenVK**; this package does **not** depend on `php-io-extensions/metal`.[^composer][^vk-zep]

| Fact | Value |
|------|--------|
| Package | `php-io-extensions/vulkan` |
| Extension name | `vulkan` |
| Version | `0.7.1` |
| PHP | `>= 8.2` |
| OS | Linux + Darwin; Windows excluded (`os-families-exclude: ["windows"]`) |
| Namespace | `Vulkan\Vk\*` |
| Author | Project Saturn Studios, LLC |
| License | MIT |
| Binding | Zephir + `src/vulkan-api.{h,c}` — **no FFI** |
| Link | `-lvulkan` (pkg-config / Homebrew paths) |

# End capability (v0.7)

1. Create/destroy a `VkInstance` with caller-supplied instance extensions (plus Apple portability bits on Darwin).
2. Enumerate physical devices; create a logical device + graphics/present queue; wrap a glfw-created surface.
3. Create/resize/destroy a presentable swapchain presenter and clear/present frames (optional menu/inner rects via clear attachments).
4. Hold Vulkan objects as Zephir DTOs with schema fields and opaque pointers in public `fd` (int; `0` = none).

Demo (sibling style): `examples/proof_menu.php` — glfw window + clear/menu quit.[^demo]

# What it is not

- Not a windowing / input library — that is [glfw](../glfw/) (primary peer).
- Not OpenGL draw bindings — that is [open-gl](../open-gl/).
- Not Apple Metal / AppKit — that is [metal](../metal/); MoltenVK is a Vulkan ICD, not the metal PHP package.
- Not available on Windows.
- Not an FFI wrapper and not a place for PHP class constants (`VK_*` → microscrap enums).

# Public namespace

Zephir classes live under `Vulkan\Vk\` (`vulkan/vk/*.zep`). IDE stubs path (when generated): `ide/0.7.1/Vulkan/Vk/`.

See [Stack segmentation](/orientation/stack-segmentation.md) and [Layered stack](/architecture/stack.md).

[^composer]: PIE package manifest
[^vk-zep]: vk.zep
[^demo]: proof_menu.php (planned sibling-style demo)
[^config]: Zephir config
[^api-h]: vulkan-api.h
