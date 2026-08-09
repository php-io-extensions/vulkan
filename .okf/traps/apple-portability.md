---
type: Trap
title: Apple portability extensions
description: VK_KHR_portability_enumeration and portability_subset required on Darwin
tags: [vulkan, trap, darwin, portability]
status: draft
generated: { by: okf-documentation-generator/cursor-grok-4.5, at: 2026-08-09T00:12:46Z }
sources:
  - id: api-c
    resource: /src/vulkan-api.c
    title: vulkan-api.c
---

# Symptom

Instance or device creation fails on Apple silicon/macOS with MoltenVK when portability extensions/flags are omitted; Linux builds work with the same PHP call sites.

# Cause

MoltenVK exposes devices via the Vulkan portability subset. Instance creation needs `VK_KHR_portability_enumeration` (+ `VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR`); devices need `VK_KHR_portability_subset` alongside `VK_KHR_swapchain`.[^api-c]

# Guidance

- Prefer the packaged C helpers — they auto-add enumeration on Darwin and enable subset at device create.
- If calling lower-level Vulkan elsewhere, mirror those extensions/flags on Apple.
- Do not remove the `#if defined(__APPLE__)` portability paths from `vulkan-api.c` without an explicit product decision.

[^api-c]: vulkan-api.c
