---
type: Convention
title: No FFI
description: Extension-only binding; no PHP FFI fallback path
tags: [vulkan, convention, ffi]
status: draft
generated: { by: okf-documentation-generator/cursor-grok-4.5, at: 2026-08-09T00:12:46Z }
sources:
  - id: composer
    resource: /composer.json
    title: PIE package manifest
  - id: vk-zep
    resource: /vulkan/vk/vk.zep
    title: vk.zep
---

# Rule

Ship Vulkan to PHP **only** through this Zephir/C extension. Do not add:

- `FFI::cdef` wrappers as an alternate API
- Dual-path “if extension missing, use FFI” helpers inside this package
- Documented FFI recipes as the supported binding

# Why

Siblings (posi/sdl3/glfw/open-gl/metal) are PIE php-ext packages with a single compiled surface. FFI would fork maintenance, weaken typing, and confuse packaging.[^composer][^vk-zep]

# Guidance

If someone needs Vulkan without compiling the extension, that is a different product — not a mode of `php-io-extensions/vulkan`.

[^composer]: PIE package manifest
[^vk-zep]: vk.zep
