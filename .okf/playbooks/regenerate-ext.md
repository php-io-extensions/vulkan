---
type: Playbook
title: Regenerate committed ext/
description: Maintainer steps before tagging
resource: /scripts/prepare-ext.sh
tags: [vulkan, playbook, packaging]
status: draft
generated: { by: okf-documentation-generator/cursor-grok-4.5, at: 2026-08-09T00:12:46Z }
sources:
  - id: prepare
    resource: /scripts/prepare-ext.sh
    title: prepare-ext.sh
  - id: fixup
    resource: /scripts/fixup-zephir-register.py
    title: fixup-zephir-register.py
  - id: demo
    resource: /examples/proof_menu.php
    title: proof_menu.php (planned)
---

# When

Before tagging a Packagist/PIE release, or after changing `.zep` / `src/*` / link scripts.

# Steps

1. On Linux or macOS with Zephir + matching PHP:

```bash
bash scripts/prepare-ext.sh
```

2. Smoke build:

```bash
cd ext && phpize && ./configure --enable-vulkan && make
php -n -d extension="$(pwd)/modules/vulkan.so" --ri vulkan
```

3. Run demo (needs glfw peer) — see [demo loop](/playbooks/demo-loop.md).

4. Commit regenerable artifacts that belong in git (`ext/` sources, `config.m4`, `ide/0.7.1/` stubs) — not phpize junk.

5. Update `.okf` + `log.md` if the public surface changed.

# Notes

- Set `ZEPHIR_BIN` if `zephir` is not on `PATH`.
- Always run REGISTER fixup for `Vulkan\Vk\*` — wired into `prepare-ext.sh`; see [REGISTER truncation](/traps/register-class-truncation.md).[^fixup][^prepare]
- Verify Darwin MoltenVK and Linux ICD paths both configure/link cleanly when touching `config.m4`.
- Smoke: `class_exists('Vulkan\\Vk\\VkInstance')`.

[^prepare]: prepare-ext.sh
[^fixup]: fixup-zephir-register.py
[^demo]: proof_menu.php (planned)
