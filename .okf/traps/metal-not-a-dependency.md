---
type: Trap
title: Metal is not a dependency
description: MoltenVK ICD is not php-io-extensions/metal
tags: [vulkan, trap, metal, moltenvk, boundaries]
status: draft
generated: { by: okf-documentation-generator/cursor-grok-4.5, at: 2026-08-09T00:12:46Z }
sources:
  - id: api-c
    resource: /src/vulkan-api.c
    title: vulkan-api.c
  - id: composer
    resource: /composer.json
    title: PIE package manifest
  - id: metal-overview
    resource: ../metal/.okf/orientation/overview.md
    title: metal package overview
---

# Symptom

Docs or PRs add `composer require php-io-extensions/metal`, ObjC sources, or AppKit/Metal frameworks to this extension because “Vulkan on Apple is Metal.”

# Cause

On Darwin, the **Vulkan loader + MoltenVK ICD** translates Vulkan to Metal inside the ICD. That is orthogonal to the Darwin-only **PHP** package `php-io-extensions/metal` (AppKit windows + `CAMetalLayer`).[^metal-overview][^api-c]

`VK_USE_PLATFORM_METAL_EXT` in C is a Vulkan header platform define for MoltenVK — not a PHP metal dependency.

# Guidance

- Link `-lvulkan` / loader only; do not link Metal.framework from this package’s `config.m4`.
- Do not import metal Zephir classes or ObjC bridges here.
- Install MoltenVK/loader via Homebrew (or SDK) for Darwin demos; keep metal as a separate product for AppKit-native apps.

[^api-c]: vulkan-api.c
[^composer]: PIE package manifest
[^metal-overview]: metal package overview
