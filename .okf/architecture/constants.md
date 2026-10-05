---
type: Architecture
title: Constants
description: How Vulkan enums and extension names become PHP constants.
tags: [vulkan, constants, generator]
status: draft
generated: { by: grok/4.7, at: 2026-10-05T09:30:00-04:00 }
sources:
  - id: tool
    resource: tools/vk-constants.php
    title: Constant generator
---

# Floor

`tools/vk-constants.php` reads a `vulkan_core.h` and writes `stubs/vk_constants.stub.php`. The committed stub is generated from the Pi's header, `VK_HEADER_VERSION` 1.4.309, so it compiles against the Mac's newer 1.4.357 header. An optional second header drops names that header does not contain. Members inside `#ifdef VK_ENABLE_BETA_EXTENSIONS` are skipped. Aliases whose target is already in the list, and `*_MAX_ENUM` members, are skipped.[^tool]

Each enumerator is `/** @var int @cvalue NAME */ const NAME = UNKNOWN;`. Extension-name macros are `@var string` with `@cvalue`. `VK_NULL_HANDLE` is the literal `0`. `VK_KHR_PORTABILITY_SUBSET_EXTENSION_NAME` is the literal `"VK_KHR_portability_subset"`, because that macro lives in `vulkan_beta.h`.

`VK_WHOLE_SIZE` is `@cvalue`. As a PHP int it is the signed interpretation of `~0ULL`. Passing it to a `VkDeviceSize` parameter casts back to all-bits-one.

[^tool]: `tools/vk-constants.php`.
