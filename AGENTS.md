# Agent guidance — php-io-extensions/vulkan

1. **Read [`.okf/index.md`](.okf/index.md) first** before changing architecture, API, or packaging.
2. Open only the concept files you need; prefer `status: stable` when present (most are currently `draft`).
3. This package is **Linux + macOS** Vulkan **instance/device/present bindings** — no windowing, no FFI, no class constants (enums → microscrap). Metal PHP extension is **not** a dependency (Darwin uses MoltenVK via the Vulkan loader).
4. Public PHP API: `Vulkan\Vk\{Vk,VkInstance,VkPhysicalDevice,VkDevice,VkQueue,VkSurface,VkSwapchain}` — static methods on `Vk`; DTOs hold opaque handles in public `fd`.
5. Surfaces come from peer **glfw** (`Vk::wrapSurface`); destroy via `Vk::destroySurface`.
6. Build: `scripts/prepare-ext.sh` (zephir generate → copy `src/*.{h,c}` → `patch-config-m4.py` → `fixup-zephir-register.py` → strip phpize junk). Installers: `install-macos.sh`, `install-macos-herd.sh`, `install-debian-trixie.sh`.
7. Demo: `examples/proof_menu.php` (needs glfw). Darwin: `DYLD_LIBRARY_PATH` must include the Homebrew lib dir so glfw can `dlopen` libvulkan; MoltenVK ICD via `VK_ICD_FILENAMES` or `php_vk_ensure_loader`. Smoke with `VULKAN_PROOF_SECONDS`.
8. When you learn a durable package fact, **update the matching `.okf` concept**, bump `generated.at`, and append `.okf/log.md`.
9. Do not invent APIs not present in `.zep` / `src/` / `ext/`.
