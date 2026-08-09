---
type: Playbook
title: Minimal demo loop
description: examples/proof_menu.php — glfw window, Vulkan clear, on-screen Quit
resource: /examples/proof_menu.php
tags: [vulkan, playbook, demo, glfw]
status: draft
generated: { by: okf-documentation-generator/cursor-grok-4.5, at: 2026-08-09T00:12:46Z }
sources:
  - id: demo
    resource: /examples/proof_menu.php
    title: proof_menu.php (planned sibling-style demo)
  - id: vk-zep
    resource: /vulkan/vk/vk.zep
    title: vk.zep
  - id: api-h
    resource: /src/vulkan-api.h
    title: vulkan-api.h
---

# Goal

Prove the extension can present a cleared frame into a **glfw**-created Vulkan surface and offer an on-screen Quit option (menu rect via `presentFrame`).[^demo][^vk-zep]

# Prerequisites

- Built `vulkan.so` and peer `glfw` extension loaded
- Working Vulkan loader + ICD (Darwin: MoltenVK)
- Instance extensions required by glfw for surface creation

# Canonical demo

```bash
php -d extension=./ext/modules/vulkan.so examples/proof_menu.php
```

Load glfw’s `.so` as well if it is not already installed for the SAPI. On Darwin, set ICD env if needed — see [MoltenVK ICD](/traps/moltenvk-icd.md).

Optional smoke auto-quit env (when implemented, mirror open-gl’s `OPENGL_PROOF_SECONDS` naming style, e.g. `VULKAN_PROOF_SECONDS`).

# What the demo should do[^demo]

1. glfw: create window; get required Vulkan instance extensions; create `VkSurfaceKHR`
2. `Vk::createInstance` → enumerate devices → wrap surface → find graphics/present queue → create device/queue
3. `Vk::createSwapchain` for framebuffer size
4. Loop: `Vk::presentFrame` with animated clear + Quit menu rect; poll glfw; handle resize / out-of-date
5. Quit via: click Quit, Enter/ESC, window close, or smoke timer
6. Destroy swapchain → device → surface → instance; destroy glfw window

# Acceptance criteria

- Window appears; background clears; Quit hit-target works.
- No AppKit/Metal PHP symbols; no window APIs inside the vulkan extension.
- Darwin runs via MoltenVK ICD without requiring `php-io-extensions/metal`.

# Status

Demo path is specified to match open-gl’s `proof_menu.php` composition. Confirm the file exists under `examples/` before treating this playbook as executable; OKF remains `draft` until verified.

[^demo]: proof_menu.php (planned sibling-style demo)
[^vk-zep]: vk.zep
[^api-h]: vulkan-api.h
