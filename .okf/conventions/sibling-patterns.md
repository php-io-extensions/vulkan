---
type: Convention
title: Sibling patterns
description: Patterns from open-gl / posi / sdl3 / glfw / metal (not dependencies)
tags: [vulkan, convention, packaging]
status: draft
generated: { by: okf-documentation-generator/cursor-grok-4.5, at: 2026-08-09T00:12:46Z }
sources:
  - id: composer
    resource: /composer.json
    title: composer.json
  - id: prepare
    resource: /scripts/prepare-ext.sh
    title: prepare-ext.sh
  - id: opengl-sibling
    resource: ../open-gl/.okf/conventions/sibling-patterns.md
    title: open-gl sibling patterns
  - id: metal-sibling
    resource: ../metal/.okf/conventions/sibling-patterns.md
    title: metal sibling patterns
---

# Borrowed patterns (style only)

| Pattern | From | How vulkan uses it |
|---------|------|---------------------|
| Thin Zephir static classes | open-gl / posi / sdl3 / glfw | `Vulkan\Vk\Vk::*` wraps C helpers |
| Opaque int handles (`fd`) | open-gl / sdl3 / glfw / metal | Vulkan pointers as `fd` on `Vk*` DTOs |
| PIE `type: php-ext`, `build-path: ext` | siblings | Same layout in `composer.json`[^composer] |
| `prepare-ext.sh` + REGISTER fixup | open-gl / metal | Zephir generate → portable `ext/`[^prepare] |
| Windowing as **peer** | open-gl | glfw creates surface; this package wraps it |
| Version `0.7.0`, PHP ≥ 8.2 | open-gl | Aligned release |
| Windows excluded | glfw / sdl3 / open-gl | `os-families-exclude: ["windows"]` |
| IDE stubs path | siblings | `ide/0.7.0/Vulkan/Vk/` |

# Not borrowed

- No AppKit/Metal/ObjC bridge (that is metal only).[^metal-sibling]
- No `gl*` draw API (that is open-gl).[^opengl-sibling]
- No composer `require` on peer extensions — demos compose them.

Keep boundaries explicit so vulkan never grows accidental windowing or metal PHP coupling.

[^composer]: composer.json
[^prepare]: prepare-ext.sh
[^opengl-sibling]: open-gl sibling patterns
[^metal-sibling]: metal sibling patterns
