---
type: Architecture
title: C ABI surface
description: Opaque uintptr_t handles and php_vk_* entry points
resource: /src/vulkan-api.h
tags: [vulkan, abi, c]
status: draft
generated: { by: okf-documentation-generator/cursor-grok-4.5, at: 2026-08-09T00:12:46Z }
sources:
  - id: api-h
    resource: /src/vulkan-api.h
    title: vulkan-api.h
  - id: api-c
    resource: /src/vulkan-api.c
    title: vulkan-api.c
  - id: prepare
    resource: /scripts/prepare-ext.sh
    title: prepare-ext.sh
---

# Conventions

- Native objects: `uintptr_t` opaque handles exposed to PHP as `int`; `0` means failure or null.[^api-h]
- Headers are C-linkage (`extern "C"`) and do not expose PHP types.
- Last failure message: `php_vk_last_error()` (not thread-safe).
- Sources under `src/` are copied into `ext/src/` by `prepare-ext.sh` so PIE builds from `ext/` only.[^prepare]

# Modules (`vulkan-api.h`)

## Loader

| Function | Notes |
|----------|--------|
| `php_vk_ensure_loader` | On Darwin, if ICD env unset, set `VK_ICD_FILENAMES` / `VK_DRIVER_FILES` to Homebrew MoltenVK ICD when file exists |

## Instance / physical device

| Function | Notes |
|----------|--------|
| `php_vk_create_instance` | Extensions array + app name; Darwin adds portability enumeration |
| `php_vk_destroy_instance` | |
| `php_vk_physical_device_count` / `_at` | Enumeration |
| `php_vk_physical_device_name` / `_type` / `_vendor_id` / `_device_id` | Properties into buffers / ints |

## Device / queue / surface

| Function | Notes |
|----------|--------|
| `php_vk_find_graphics_present_queue` | Graphics + present family, or `-1` |
| `php_vk_create_device` / `php_vk_destroy_device` | Enables swapchain (+ portability subset on Apple) |
| `php_vk_get_device_queue` | |
| `php_vk_destroy_surface` | Needs instance + surface |

## Swapchain presenter

| Function | Notes |
|----------|--------|
| `php_vk_swapchain_create` | Owns images, views, render pass, framebuffers, command pool/buffers, sync |
| `php_vk_swapchain_destroy` / `_resize` | |
| `php_vk_swapchain_frame` | Acquire → clear → optional menu/inner clearAttachments → present; floats 0..1; menu coords framebuffer pixels, top-left origin |
| `php_vk_swapchain_width` / `_height` / `_image_count` / `_format` | Query presenter |
| `php_vk_last_error` | Human-readable last error |

PHP mapping: [API index](/api/index.md). Ownership: [fd ownership](/conventions/fd-ownership.md). Loader details: [Loader and portability](/architecture/loader-and-portability.md).

[^api-h]: vulkan-api.h
[^api-c]: vulkan-api.c
[^prepare]: prepare-ext.sh
