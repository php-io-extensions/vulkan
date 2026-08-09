---
type: Trap
title: MoltenVK ICD discovery
description: Darwin may need VK_ICD_FILENAMES; php_vk_ensure_loader sets it when unset
tags: [vulkan, trap, moltenvk, darwin, loader]
status: draft
generated: { by: okf-documentation-generator/cursor-grok-4.5, at: 2026-08-09T00:12:46Z }
sources:
  - id: api-c
    resource: /src/vulkan-api.c
    title: vulkan-api.c
  - id: api-h
    resource: /src/vulkan-api.h
    title: vulkan-api.h
---

# Symptom

`vkCreateInstance` fails / zero devices on macOS even though MoltenVK is installed via Homebrew; or PHP CLI works only when the shell already exported ICD paths.

# Cause

The Vulkan loader needs an ICD manifest. Homebrew typically installs:

`/opt/homebrew/etc/vulkan/icd.d/MoltenVK_icd.json`

(or `/usr/local/...` on Intel Homebrew). If env vars are unset and the helper cannot find that file, instance creation fails.[^api-c]

# Guidance

1. Prefer letting `php_vk_ensure_loader()` run (called from `php_vk_create_instance`) — it sets `VK_ICD_FILENAMES` and `VK_DRIVER_FILES` when unset and a known ICD file exists.[^api-h]
2. If needed, export before PHP:

```bash
export VK_ICD_FILENAMES=/opt/homebrew/etc/vulkan/icd.d/MoltenVK_icd.json
```

3. Do not overwrite a user’s existing ICD env (helper uses `setenv(..., 0)` / early return when already set).
4. See [Loader and portability](/architecture/loader-and-portability.md).

[^api-c]: vulkan-api.c
[^api-h]: vulkan-api.h
