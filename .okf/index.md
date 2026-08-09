---
okf_version: "0.2"
---

# php-io-extensions/vulkan

Cross-platform (Linux + macOS) PHP extension: Zephir static Vulkan bindings (`Vulkan\Vk\Vk`) plus thin data objects (`VkInstance`, `VkPhysicalDevice`, `VkDevice`, `VkQueue`, `VkSurface`, `VkSwapchain`) that store opaque handles in public `fd`. Window/surface creation belongs to peer `glfw` (like open-gl), not this package. Darwin uses the Vulkan loader + MoltenVK ICD — **not** the `metal` PHP extension.

**Prefer** concepts with `status: stable` when present; content is currently `draft` pending Angel’s human verification of the OKF docs (implementation facts are grounded in shipped Zephir/C sources). Demo verified on Apple M1 Pro (MoltenVK) via `examples/proof_menu.php`; installers are in-tree.

# Orientation

* [Package overview](orientation/overview.md) - What vulkan is, version targets, and what it deliberately is not
* [Stack segmentation](orientation/stack-segmentation.md) - Boundaries vs glfw, open-gl, metal, and microscrap

# Architecture

* [Layered stack](architecture/stack.md) - Zephir → thin C ABI → Vulkan loader / MoltenVK
* [Zephir static + fd objects](architecture/zephir-static-and-fd.md) - Static `Vk::*` + schema objects with public `fd`
* [C ABI surface](architecture/c-abi.md) - Opaque `uintptr_t` handles and `php_vk_*` entry points
* [Loader and Apple portability](architecture/loader-and-portability.md) - MoltenVK ICD env + portability extensions

# Public PHP API

* [Vulkan\\Vk\\Vk](api/vk.md) - Static instance/device/swapchain/present entry points
* [Vulkan\\Vk\\VkInstance](api/vkinstance.md) - Instance DTO (`fd`, `appName`)
* [Vulkan\\Vk\\VkPhysicalDevice](api/vkphysicaldevice.md) - Physical device DTO (`fd`, name/ids)
* [Vulkan\\Vk\\VkDevice](api/vkdevice.md) - Logical device DTO (`fd`, `queueFamily`)
* [Vulkan\\Vk\\VkQueue](api/vkqueue.md) - Queue DTO (`fd`, `familyIndex`)
* [Vulkan\\Vk\\VkSurface](api/vksurface.md) - Surface DTO (`fd`; usually from glfw)
* [Vulkan\\Vk\\VkSwapchain](api/vkswapchain.md) - Presenter DTO (`fd`, size/format/images)

# Build & packaging

* [Zephir + PIE install](build/zephir-and-pie.md) - prepare-ext, install-macos*.sh, install-debian-trixie.sh, PIE
* [Committed ext/ notes](build/packaging-ext.md) - Portable config.m4, REGISTER fixup, strip phpize junk

# Conventions

* [Sibling patterns](conventions/sibling-patterns.md) - Patterns from open-gl / posi / sdl3 / glfw (not dependencies)
* [fd ownership](conventions/fd-ownership.md) - Who creates/destroys handles behind `fd`
* [No FFI](conventions/no-ffi.md) - Extension-only binding; no PHP FFI fallback
* [Constants in microscrap](conventions/constants-microscrap.md) - No class constants; VK_* enums live elsewhere

# Traps

* [No windowing here](traps/no-windowing.md) - Window/surface creation is glfw (wrapSurface)
* [Metal is not a dependency](traps/metal-not-a-dependency.md) - MoltenVK ≠ php-io-extensions/metal
* [MoltenVK ICD discovery](traps/moltenvk-icd.md) - VK_ICD_FILENAMES / php_vk_ensure_loader
* [Apple portability extensions](traps/apple-portability.md) - enumeration + subset on Darwin
* [REGISTER_CLASS truncation](traps/register-class-truncation.md) - Zephir 0.19 may truncate `Vulkan\Vk\*`

# Playbooks

* [Minimal demo loop](playbooks/demo-loop.md) - examples/proof_menu.php + glfw peer
* [Regenerate committed ext/](playbooks/regenerate-ext.md) - Maintainer steps before tagging

# Indexes

* [Orientation](orientation/) — start here
* [Architecture](architecture/)
* [API](api/)
* [Build](build/)
* [Conventions](conventions/)
* [Traps](traps/)
* [Playbooks](playbooks/)
