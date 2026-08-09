# php-vulkan

[![PHP](https://img.shields.io/badge/php-%E2%89%A5%208.2-777bb4?logo=php&logoColor=white)](https://www.php.net)
[![Vulkan](https://img.shields.io/badge/Vulkan-1.x-a41e22)](https://www.vulkan.org/)
[![Built with Zephir](https://img.shields.io/badge/built%20with-Zephir-ff6a00)](https://zephir-lang.com/)
[![Platform](https://img.shields.io/badge/platform-linux%20%7C%20macOS-lightgrey)](#requirements)
[![License: MIT](https://img.shields.io/badge/license-MIT-green)](#license)

> PHP extension for Vulkan — built with [Zephir](https://zephir-lang.com/), installable via [PHP PIE](https://github.com/php/pie).

`vulkan` exposes instance/device/swapchain present helpers to PHP 8.2+ as
namespaced classes under `Vulkan\Vk\…`. Static methods live on `Vulkan\Vk\Vk`;
opaque handles are Zephir DTOs with a public `fd` (pointer as int). Windowing
belongs to peer extensions (`glfw`); this package is draw/present bindings.

On macOS the loader typically needs [MoltenVK](https://github.com/KhronosGroup/MoltenVK)
(`brew install molten-vk vulkan-loader vulkan-headers`).

---

## Requirements

| Component            | Minimum version | Notes                                                                   |
| -------------------- | --------------- | ----------------------------------------------------------------------- |
| PHP                  | 8.2             | ZTS and NTS builds both supported.                                      |
| Vulkan loader        | 1.x             | Discoverable via `pkg-config vulkan`.                                   |
| OS                   | Linux / macOS   | Darwin uses MoltenVK (portability enumeration). Windows not supported.  |
| Compiler             | C11 toolchain   | `gcc`, `clang`, or Apple Clang.                                         |
| `php-dev` / `phpize` | matches PHP     | Required for any build path that is not PIE.                            |

Demo additionally requires the `glfw` extension for the window + `VkSurfaceKHR`.

---

## Installation

### Via PHP PIE (recommended)

```bash
pie install php-io-extensions/vulkan
```

### Platform installers

**macOS** (Homebrew):

```bash
bash install-macos.sh
# or Herd:
bash install-macos-herd.sh
```

**Debian Trixie / Raspberry Pi OS**:

```bash
bash install-debian-trixie.sh
```

### Manual build with Zephir (maintainers)

```bash
export PKG_CONFIG_PATH="/opt/homebrew/lib/pkgconfig:/usr/local/lib/pkgconfig:${PKG_CONFIG_PATH:-}"
# Darwin + Homebrew MoltenVK (glfw dlopen of libvulkan):
export DYLD_LIBRARY_PATH="/opt/homebrew/lib:${DYLD_LIBRARY_PATH:-}"
export VK_ICD_FILENAMES="/opt/homebrew/etc/vulkan/icd.d/MoltenVK_icd.json"
bash scripts/prepare-ext.sh
cd ext && phpize && ./configure --enable-vulkan && make -j1
php -d extension=modules/vulkan.so --ri vulkan
```

---

## Quick start

```php
use Vulkan\Vk\Vk;

$instance = Vk::createInstance($glfwRequiredExtensions, 'my-app');
$devices = Vk::enumeratePhysicalDevices($instance);
// … create device/queue/swapchain, then:
Vk::presentFrame($swapchain, 0.1, 0.2, 0.3, 1.0);
```

Visual proof (Quit menu):

```bash
export DYLD_LIBRARY_PATH="/opt/homebrew/lib:${DYLD_LIBRARY_PATH:-}"
export VK_ICD_FILENAMES="/opt/homebrew/etc/vulkan/icd.d/MoltenVK_icd.json"
VULKAN_PROOF_SECONDS=3 php -d extension=./ext/modules/vulkan.so examples/proof_menu.php
```

---

## Agent docs

Package knowledge lives in [`.okf/`](.okf/index.md). See [`AGENTS.md`](AGENTS.md).

---

## License

MIT — see [LICENSE](LICENSE).
