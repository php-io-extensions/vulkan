---
type: Convention
title: Constants in microscrap
description: No class constants in the extension; VK_* enums live in microscrap
tags: [vulkan, convention, enums, microscrap]
status: draft
generated: { by: okf-documentation-generator/cursor-grok-4.5, at: 2026-08-09T00:12:46Z }
sources:
  - id: vk-zep
    resource: /vulkan/vk/vk.zep
    title: vk.zep
  - id: composer
    resource: /composer.json
    title: PIE package manifest
---

# Rule

Do **not** define PHP class constants (or Zephir class constants) for `VK_*` values inside this extension.[^vk-zep]

House backed enums / constant catalogs in **microscrap** (or another shared PHP package). Call sites pass `int` / enum-backed values into `Vulkan\Vk\*` methods when raw Vulkan enums are needed.

# Why

- Project convention: prefer PHP Enums (FULLY UPPERCASE cases) over class-level constants.
- Keeps the extension binary smaller and avoids duplicating huge constant tables in C.
- Lets enum packages evolve without rebuilding the extension for every constant add.

# Guidance

```php
// preferred (illustrative)
$family = Vk::findGraphicsPresentQueue($phys, $surface);
// pass microscrap-backed ints for formats / results when comparing presentFrame returns

// avoid in this extension
// class Vk { public const SUCCESS = 0; }
```

When documenting APIs, say “pass microscrap enum / int” rather than inventing extension constants. Token constants (`VK_*`) are deferred to microscrap per package design.[^vk-zep]

[^vk-zep]: vk.zep
[^composer]: PIE package manifest
