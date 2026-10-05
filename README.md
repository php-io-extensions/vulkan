# ext-vulkan

1:1 PHP bindings of Vulkan: instance and device, memory, images, buffers, render
passes, pipelines, descriptors, commands, sync, surfaces and swapchains, and the
Linux dmabuf export GTK needs. Written in C against the Zend API and
`<vulkan/vulkan.h>`, linked to the system Vulkan loader. PHP 8.4+, NTS and ZTS.
Version 0.10.0.

Functions are global PHP functions under their C names. Enums and flags are PHP
constants under their C names, values taken from the headers. Each handle is a
final class. Each struct is a final class whose properties are the C members.

## Requirements

- The Vulkan loader and headers. Debian and Raspberry Pi OS: `libvulkan-dev`.
  macOS: `brew install vulkan-loader vulkan-headers molten-vk`.
- A GPU device. Tests skip the CPU device (llvmpipe). On macOS, MoltenVK is
  visible only with the portability enumeration flags, which are slice 5, so
  device tests skip there with that reason. The Mac build still links and the
  device-free tests run.
- The measured Pi is Mesa 26.2 V3DV, Vulkan headers 1.4.309, API 1.3. The Mac
  headers measured here are 1.4.357.

## Install

Through PIE:

```bash
pie install php-io-extensions/vulkan
```

From a checkout:

```bash
./install-macos.sh            # Homebrew php@8.4 and php@8.4-zts, or pass PHP binaries
./install-debian-trixie.sh    # Debian trixie, Raspberry Pi OS
```

`./install-macos.sh` refuses to start unless `pkg-config` finds `vulkan`, and
tells you to `brew install vulkan-loader vulkan-headers molten-vk`.

## Translations

Bindings are 1:1. There are no defaults and no composites. The only translations:

- A pointer + count pair is one PHP list.
- The enumerate-twice calls (`vkEnumerate*`, `vkGet*Properties` with a count,
  `vkGetSwapchainImagesKHR`) fill a by-reference list. The binding calls twice
  and retries while the result is `VK_INCOMPLETE`.
- An out-handle or out-struct is a by-reference parameter.
- `sType` is not a property. Each struct class fills its own.
- `pNext` is `?object`, a chain of struct objects. A chain that loops is a
  `ValueError` before the binding walks it. A struct of the wrong kind for its
  parent is linked as given.
- `pAllocator` is `null`. There is no custom allocator.
- `VkShaderModuleCreateInfo::$code` is one string. `codeSize` is its length. A
  length that is not a multiple of 4 is a `ValueError`.
- `vkCmdPushConstants` takes a string. A string shorter than `size` is a
  `ValueError`.
- Results are the `VkResult` int, as in C.
- `vkMapMemory` writes the mapped address to `$ppData` (`int`). PHP reads and
  writes that address with `vk_read_mapped(int $address, int $size): string` and
  `vk_write_mapped(int $address, string $bytes): void`. Address 0 is refused.
  Any other address is trusted. `vkFlushMappedMemoryRanges` and
  `vkInvalidateMappedMemoryRanges` are what make non-coherent memory correct.

`VkCopyDescriptorSet`, `VkMemoryBarrier`, and `VkBufferMemoryBarrier` are not
bound. `vkUpdateDescriptorSets` refuses a non-empty copy list.
`vkCmdPipelineBarrier` refuses a non-empty memory-barrier or buffer-barrier list.

## Handles and parents

Handles are `final`, not constructable, not cloneable, not serializable, with
`pointer(): int` and `static fromPointer(int $pointer): static`. Address 0 is
refused. One PHP object per class and native value.

Destroying a parent releases every PHP handle whose parent chain reaches it.
After `vkDestroyDevice`, a `VkBuffer` or `VkQueue` from that device throws
`ValueError` ("VkBuffer has been destroyed") instead of reaching the driver.
`vkDestroyCommandPool` releases its command buffers. `vkDestroyDescriptorPool`
releases its descriptor sets. Swapchain images are owned by the swapchain:
`vkDestroySwapchainKHR` releases them, and PHP does not destroy them.
A surface created outside this extension (SDL's `SDL_Vulkan_CreateSurface`)
enters through `VkSurfaceKHR::fromPointer()`. Its parent is unknown, so only
`vkDestroySurfaceKHR` releases it.

## Device selection

Skip `VK_PHYSICAL_DEVICE_TYPE_CPU`. The integrated or discrete GPU is the
device. Pick a stencil format with `vkGetPhysicalDeviceFormatProperties`:
`VK_FORMAT_D24_UNORM_S8_UINT`, otherwise `VK_FORMAT_D32_SFLOAT_S8_UINT`.

## Example

Clear an 8×8 image and copy it out. This skips the CPU device and uses the
first graphics queue.

```php
$app = new VkApplicationInfo();
$app->apiVersion = VK_API_VERSION_1_3;
$instanceInfo = new VkInstanceCreateInfo();
$instanceInfo->pApplicationInfo = $app;
vkCreateInstance($instanceInfo, null, $instance);

vkEnumeratePhysicalDevices($instance, $devices);
foreach ($devices as $candidate) {
    vkGetPhysicalDeviceProperties($candidate, $properties);
    if ($properties->deviceType !== VK_PHYSICAL_DEVICE_TYPE_CPU) {
        $physical = $candidate;
        break;
    }
}
vkGetPhysicalDeviceQueueFamilyProperties($physical, $families);
$family = array_key_first(array_filter(
    $families,
    fn (VkQueueFamilyProperties $family): bool => ($family->queueFlags & VK_QUEUE_GRAPHICS_BIT) !== 0,
));
$queueInfo = new VkDeviceQueueCreateInfo();
$queueInfo->queueFamilyIndex = $family;
$queueInfo->pQueuePriorities = [1.0];
$deviceInfo = new VkDeviceCreateInfo();
$deviceInfo->pQueueCreateInfos = [$queueInfo];
vkCreateDevice($physical, $deviceInfo, null, $device);
vkGetDeviceQueue($device, $family, 0, $queue);

$imageInfo = new VkImageCreateInfo();
$imageInfo->imageType = VK_IMAGE_TYPE_2D;
$imageInfo->format = VK_FORMAT_R8G8B8A8_UNORM;
[$imageInfo->extent->width, $imageInfo->extent->height, $imageInfo->extent->depth] = [8, 8, 1];
$imageInfo->mipLevels = 1;
$imageInfo->arrayLayers = 1;
$imageInfo->samples = VK_SAMPLE_COUNT_1_BIT;
$imageInfo->tiling = VK_IMAGE_TILING_OPTIMAL;
$imageInfo->usage = VK_IMAGE_USAGE_TRANSFER_SRC_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT;
vkCreateImage($device, $imageInfo, null, $image);
```

Map the destination buffer with `vkMapMemory`, then `vk_read_mapped` on the
address it wrote. Call `vkFlushMappedMemoryRanges` after a write and
`vkInvalidateMappedMemoryRanges` before a read when the memory is not coherent.

## Testing

```bash
php84 -d memory_limit=128M vendor/bin/pest   # Homebrew NTS
zhp   -d memory_limit=128M vendor/bin/pest   # Homebrew ZTS
php   -d memory_limit=128M vendor/bin/pest   # the Pi
```

On the Pi the swapchain test needs `WAYLAND_DISPLAY=wayland-0` and
`XDG_RUNTIME_DIR=/run/user/$(id -u)`. A window appears. The gate draws a
stencil-then-cover triangle into a 4× image, resolves it in the render pass,
blits, copies out, and reads the pixels back.
