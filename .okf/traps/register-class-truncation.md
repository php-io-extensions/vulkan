---
type: Trap
title: REGISTER_CLASS truncation
description: Zephir 0.19 may truncate Vulkan\\Vk\\* in ZEPHIR_REGISTER_CLASS
tags: [vulkan, trap, zephir, register]
status: draft
generated: { by: okf-documentation-generator/cursor-grok-4.5, at: 2026-08-09T00:12:46Z }
sources:
  - id: fixup
    resource: /scripts/fixup-zephir-register.py
    title: fixup-zephir-register.py
  - id: prepare
    resource: /scripts/prepare-ext.sh
    title: prepare-ext.sh
---

# Symptom

Extension builds but classes are missing/wrong (`Class "Vulkan\Vk\VkInstance" not found`), or `ZEPHIR_REGISTER_CLASS` lines show shortened namespaces (`Vulkan\V\Vk…`).[^fixup]

# Cause

Zephir 0.19 truncates nested namespace segments when emitting register macros. Same class of bug as metal (`Metal\MTL\*` → `Metal\MT\*`) and open-gl (`Opengl\GL\*` → `Opengl\G\*`).

# Guidance

1. After `zephir generate`, run `scripts/fixup-zephir-register.py` mapping `Vulkan\V\*` → `Vulkan\Vk\{Vk,VkInstance,VkPhysicalDevice,VkDevice,VkQueue,VkSurface,VkSwapchain}` (and `Vulkan_V_*` → `Vulkan_Vk_*`).
2. Wire is already in `scripts/prepare-ext.sh` — do not skip it.[^prepare]
3. Smoke with `php --ri vulkan` and `class_exists('Vulkan\\Vk\\VkInstance')` before tagging.
4. Do not “fix” by renaming the public namespace away from `Vulkan\Vk` without an explicit product decision — prefer the fixup script.

[^fixup]: fixup-zephir-register.py
[^prepare]: prepare-ext.sh
