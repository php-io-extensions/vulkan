# Public PHP API

All public classes live under `Vulkan\Vk`. Entry points are **static** methods on `Vk`. Named Vulkan objects are Zephir DTOs with schema fields and opaque native pointers in public `fd` (`0` = none). Surfaces are typically created by peer **glfw** and wrapped here.

**Status:** implemented in Zephir/C source; OKF concepts remain `draft` until Angel marks them `stable`.

* [Vulkan\\Vk\\Vk](vk.md) - Static instance/device/swapchain/present entry points
* [Vulkan\\Vk\\VkInstance](vkinstance.md) - Instance DTO (`fd`, `appName`)
* [Vulkan\\Vk\\VkPhysicalDevice](vkphysicaldevice.md) - Physical device DTO (`fd`, name/ids)
* [Vulkan\\Vk\\VkDevice](vkdevice.md) - Logical device DTO (`fd`, `queueFamily`)
* [Vulkan\\Vk\\VkQueue](vkqueue.md) - Queue DTO (`fd`, `familyIndex`)
* [Vulkan\\Vk\\VkSurface](vksurface.md) - Surface DTO (`fd`; usually from glfw)
* [Vulkan\\Vk\\VkSwapchain](vkswapchain.md) - Presenter DTO (`fd`, size/format/images)
