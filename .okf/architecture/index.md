# Architecture

* [Layered stack](stack.md) - Zephir → thin C ABI → Vulkan loader / MoltenVK
* [Zephir static + fd objects](zephir-static-and-fd.md) - Static `Vk::*` + schema objects with public `fd`
* [C ABI surface](c-abi.md) - Opaque `uintptr_t` handles and `php_vk_*` entry points
* [Loader and Apple portability](loader-and-portability.md) - MoltenVK ICD env + portability extensions
