---
type: Playbook
title: Zephir + PIE install
description: Generate, prepare-ext, configure, install on Linux and macOS
resource: /composer.json
tags: [vulkan, build, pie, zephir]
status: draft
generated: { by: okf-documentation-generator/cursor-grok-4.5, at: 2026-08-09T00:12:46Z }
sources:
  - id: composer
    resource: /composer.json
    title: PIE package manifest
  - id: prepare
    resource: /scripts/prepare-ext.sh
    title: prepare-ext.sh
  - id: install
    resource: /install-macos.sh
    title: install-macos.sh (planned sibling installer)
  - id: herd
    resource: /install-macos-herd.sh
    title: install-macos-herd.sh (planned)
  - id: debian
    resource: /install-debian-trixie.sh
    title: install-debian-trixie.sh (planned)
  - id: config-m4
    resource: /ext/config.m4
    title: Portable ext/config.m4
  - id: config
    resource: /config.json
    title: Zephir config
---

# Requirements

| Component | Notes |
|-----------|--------|
| OS | Linux or macOS (Windows excluded) |
| PHP | ≥ 8.2 with matching `phpize` / headers |
| Vulkan SDK / loader | Darwin: Homebrew `vulkan-loader` + MoltenVK ICD; Linux: `libvulkan` + ICD |
| Zephir | For regenerating `ext/` (`ZEPHIR_BIN` optional) |
| Peer (demos) | `glfw` extension for window/surface |

# PIE (consumers)

```bash
pie install php-io-extensions/vulkan
```

Uses `type: php-ext`, `extension-name: vulkan`, `build-path: "ext"`, `--enable-vulkan`.[^composer]

# Platform installers

Sibling-style installer entry points (create/maintain to match open-gl):

```bash
bash install-macos.sh
bash install-macos-herd.sh      # Laravel Herd
bash install-debian-trixie.sh   # Debian Trixie / Raspberry Pi OS
```

[^install][^herd][^debian]

# Manual maintainer build

```bash
bash scripts/prepare-ext.sh
cd ext && phpize && ./configure --enable-vulkan && make
php -n -d extension="$(pwd)/modules/vulkan.so" --ri vulkan
```

`prepare-ext.sh`: `zephir generate` → copy `src/*.{h,c}` → `ext/src/` → `patch-config-m4.py` → `fixup-zephir-register.py` → strip phpize junk.[^prepare]

# Verify

```bash
php -n -d extension=./ext/modules/vulkan.so --ri vulkan
php -d extension=./ext/modules/vulkan.so examples/proof_menu.php
```

Demo also needs the `glfw` extension loaded — see [demo loop](/playbooks/demo-loop.md). On Darwin, confirm MoltenVK ICD discovery — see [MoltenVK ICD](/traps/moltenvk-icd.md).

[^composer]: PIE package manifest
[^prepare]: prepare-ext.sh
[^install]: install-macos.sh (planned sibling installer)
[^herd]: install-macos-herd.sh (planned)
[^debian]: install-debian-trixie.sh (planned)
[^config-m4]: Portable ext/config.m4
[^config]: Zephir config
