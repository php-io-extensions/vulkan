# Directory Update Log

## 2026-08-08
* **Initialization**: Created OKF v0.2 knowledge bundle for `php-io-extensions/vulkan` grounded in `composer.json` (`0.5.0`), `config.json`, `src/vulkan-api.{h,c}`, `vulkan/vk/*.zep`, and `scripts/{prepare-ext.sh,patch-config-m4.py,fixup-zephir-register.py}`. Structure and tone matched sibling bundles at `open-gl/.okf` and `metal/.okf`.
* **Creation**: Orientation (overview, stack segmentation), architecture (stack, zephir+fd, C ABI, loader/portability), API (`Vk` + six DTOs), build/packaging, conventions, traps, and playbooks; package-root `AGENTS.md`.
* **Note**: Bundle marked `draft` pending Angel human verification. `examples/proof_menu.php` and `install-*.sh` are documented to sibling convention and may not be present in-tree yet — treat those paths as planned product surface.

## 2026-08-09
* **Demo verified**: `examples/proof_menu.php` ran on Apple M1 Pro (MoltenVK) with `VULKAN_PROOF_SECONDS=3` — instance/device/swapchain present + Quit menu. Requires `DYLD_LIBRARY_PATH=/opt/homebrew/lib` for glfw `dlopen(libvulkan)` and MoltenVK ICD path (auto via `php_vk_ensure_loader` or env).
* **Packaging**: installers landed; `ide/0.5.0` stubs generated; `scripts/prepare-ext.sh` leaves deploy-ready `ext/` (no Makefile/configure/modules).

## 2026-08-09
* **Version bump**: Package → **`0.7.1`** (`composer.json`, `config.json`, `PHP_VULKAN_VERSION`, stubs `ide/0.7.1/`). Ready to push before publish.
* **Present mode**: `createSwapchain` / rebuild prefers MAILBOX → IMMEDIATE → FIFO (was hard FIFO). Avoids ~30fps half-rate with tubes MetalCanvas when frames >16.6ms; sketch `FramePaceNode` paces. Sync `src/vulkan-api.c` + `ext/src/vulkan-api.c`.
* **Version bump**: Package/docs line promoted to **0.7.0 / 0.7.x** for publish alignment with metal/open-gl. (Superseded by 0.7.1 above.)
