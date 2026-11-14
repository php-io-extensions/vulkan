# Log

## 2026-11-14

* **VkDescriptorBufferInfo**: bound 1:1 (`?VkBuffer $buffer`, `int $offset`, `int $range`), and `VkWriteDescriptorSet::$pBufferInfo` (`?array`, read against `descriptorCount` like `pImageInfo`). A shader can now read a uniform or storage buffer through a descriptor set. Test in `tests/PipelineTest.php`: a storage-buffer write, and a list shorter than its count refused with a `ValueError`; it fails without the C change. Suite on Homebrew 8.4 NTS and ZTS, installed build: 40 passed, 14 skipped, exit 0. 

* **vkCmdCopyImage**: bound 1:1 with `VkImageCopy` (zero-init constructor builds its five nested structs; `glue` and `typemap` entries added by Angel). The nested structs are read with `vulkan_nested`, as `VkMemoryToImageCopy` reads its own. Test in `tests/HostCopyTest.php`: a 3×2 region copied between two 8×8 images lands byte-exact at its offset with the rest untouched, and a count past the region list is refused. Homebrew 8.4 NTS and ZTS, installed build: 41 passed, 14 skipped, exit 0.

* **Compute**: `vkCreateComputePipelines` and `vkCmdDispatch` bound 1:1, with `VkComputePipelineCreateInfo` (zero-init constructor builds its `stage`; `glue` and `typemap` entries, and `vulkan_i32` in `helpers.marshal`, added by Angel). `vulkan_nested` moved from `vk_command_structs.inc` into `structs.c`, ahead of the includes, so the pipeline structs read their nested `stage` with it. Test in `tests/HostCopyTest.php`: a compute shader (`tests/Fixtures/fill.comp`) dispatched as four groups of four writes 3i+1 into a storage buffer, which reaches the host byte-exact through an image; a count past the create-info list is refused. The `vkCmdCopyImage` test no longer ends its command buffer twice. `SUPPORT.md` regenerated: it also marks the host copies, `vkCmdUpdateBuffer` and `vkGetInstanceProcAddr`, which were bound but unmarked. Homebrew 8.4 NTS and ZTS, installed build: 42 passed, 14 skipped.

## 2026-11-08

* **vkGetInstanceProcAddr**: bound 1:1, `vkGetInstanceProcAddr(?VkInstance $instance, string $pName): int` (`PFN_vkVoidFunction` is the int address by typemap, `0` is `NULL`; a released instance is refused like any dispatchable handle). It replaces the `vkGetLoaderPath()` idea: `vkGetInstanceProcAddr(null, 'vkGetInstanceProcAddr')` is the loader's address, which another library's `dlsym()` (ext-posi) compares to tell whether two sides use one loader. Two tests in `tests/InstanceTest.php`. Suite from its own repo setup on MoltenVK, ZTS scratch build: 37 passed, 15 skipped (Linux, ext-sdl3 and probe tests), 1 risky, exit 0.

* **Host copies, no FFI**: `vkCmdUpdateBuffer`, `vkCopyMemoryToImage`, `vkCopyImageToMemory`, `vkTransitionImageLayout` and the structs `VkMemoryToImageCopy`, `VkImageToMemoryCopy`, `VkCopyMemoryToImageInfo`, `VkCopyImageToMemoryInfo`, `VkHostImageLayoutTransitionInfo`, `VkPhysicalDeviceHostImageCopyFeatures` (a `pNext` node, written back by `vkGetPhysicalDeviceFeatures2`); constant `VK_API_VERSION_1_4`. `pHostPointer` is a PHP string (a read fills the caller's string of the size to read). `tests/HostCopyTest.php`; the suite's helpers (`hostImage2D`, `hostWrite`, `hostRead`) replace `mappedRead`, `mappedWrite` and libc, so no test uses FFI; the shared device is a 1.4 device with `hostImageCopy` where the GPU has it, and the tests that need it skip without. `MemoryTest` checks the bytes of host-visible memory through the GPU: `vkCmdUpdateBuffer` writes them into a buffer bound to the mapped memory, `vkCmdCopyBufferToImage` moves them into a host-transfer image, `vkCopyImageToMemory` reads them back; the map, flush, invalidate and unmap results are still checked. MoltenVK, ZTS, installed build: 32 passed, 3 skipped (the Linux tests). `vkGetLoaderPath()` is not bound: the guard maps a symbol to a native function and demands its signature, which dladdr() cannot give.

## 2026-11-06

* **1:1 sweep** (`f11a63d`): counts are explicit arguments and struct members, enumerate calls take `?int &count` and `?array &list` as C's two calls, `pAllocator` and `pipelineCache` are int addresses (0 is `NULL`), `VkBool32` is bool, SPIR-V is `codeSize` + `pCode`, destroys take `null`, `fromPointer(0)` is `null`. `VkCopyDescriptorSet` and `VkBufferMemoryBarrier` are bound. `vkSetHdrMetadataEXT` is void.
* **Removed**: `vk_read_mapped`, `vk_write_mapped`, `vk_close_fd`, `vk_loader_path`, `VK_NULL_HANDLE` and the Wayland/XCB/Xlib names. They are not Vulkan; FFI does the mapped reads and writes and the close.
* **Refusals**: four sites in `bindings.json` (`541bf9c`), each with a probe in `tests/Probes` (`7781b43`): `vulkan-list-count`, `vulkan-bytes-length`, `vulkan-null-dispatchable`, `vulkan-no-proc`. Probes need `--enable-vulkan-probes`. On the NVIDIA x86_64 box (headers 1.4.309 from Vulkan-Headers) the push-constant probe skips (no guard-page allocator) and the no-proc probes skip (the implementation hands out the commands).
* **Tests**: Homebrew PHP 8.4 NTS and ZTS, 44 passed, 3 skipped each. The x86_64 box: everything passes but the two SDL swapchain tests, which need a display.

## 2026-10-28

* **Version**: 0.11.0 in `PHP_VULKAN_VERSION` (`php_vulkan.h`), `AGENTS.md`, README and the index; `branch-alias` `dev-main` is `0.11.x-dev`. Promoted with the Venusian 0.11 ecosystem. No API or behaviour change. Built and loaded on Homebrew PHP 8.4 NTS and ZTS (28 passed, 3 skipped each) and the Pi on 8.4 ZTS (30 passed, 1 skipped).
* **Open — older Vulkan headers**: an x86_64 Ubuntu-family box's distribution headers are older than 1.4.309, so `configure` refuses and 0.7.1 stays installed there until newer headers (KhronosGroup/Vulkan-Headers) are installed.
* **Coverage**: `scripts/support.php` writes `SUPPORT.md` and the README's API badge: every command of vk.xml at Vulkan-Headers v1.4.309 (the floor) that a core version or a supported, not deprecated or obsoleted extension requires for the `vulkan` API, grouped under the first that requires it; alias commands and Vulkan SC only commands are not counted. Bound when a stub declares the function of the same name. vk.xml downloads once into `scripts/.support-cache/` (gitignored); `--check` exits 1 when the list or badge is stale. 97 / 605 (16.0%).

## 2026-10-09


## 2026-10-08

Staged-window presentation: incremental present regions, present id and `vkWaitForPresentKHR`, the present id / wait feature structs, HDR metadata, and the five extension-name constants. `vulkan_u64_list` moved to the runtime. Suite: Homebrew php@8.4 NTS and ZTS 28 passed, 3 skipped; Pi (V3DV) 30 passed, 1 skipped, the present with regions, id and wait included.

## 2026-10-06

`VkMemoryDedicatedAllocateInfo`; `vk_loader_path()` (dladdr of `vkGetInstanceProcAddr`); the X11 surface extension names (`VK_KHR_xcb_surface`, `VK_KHR_xlib_surface`). Suite: Homebrew php@8.4 NTS and ZTS 26 passed, 2 skipped; Pi 27 passed, 1 skipped.

`vk_close_fd()` closes a descriptor `vkGetMemoryFdKHR` handed out (`EBADF` is a `ValueError`). The generator writes everything the committed stub holds: `VK_API_VERSION_1_1`, the Wayland surface and properties2 names, `vk_close_fd`. Suite: Homebrew php@8.4 NTS and ZTS 24 passed, 2 skipped; Pi 25 passed, 1 skipped.

## 2026-10-05

MoltenVK. `vkGetPhysicalDeviceFeatures2` fills `VkPhysicalDeviceFeatures2` and a chained `VkPhysicalDevicePortabilitySubsetFeaturesKHR` in place (`VK_ENABLE_BETA_EXTENSIONS` before `<vulkan/vulkan.h>`). The test helpers enable `VK_KHR_portability_enumeration` and `VK_KHR_portability_subset` only where the loader and the device list them. On this M1 Pro, MoltenVK 1.4.2 reports `triangleFans` true, `pointPolygons` false, and depth-stencil `D32_SFLOAT_S8_UINT` only. A `VkSurfaceKHR` over ext-metal's `CAMetalLayer` carries a swapchain. Suite: Homebrew php@8.4 NTS and ZTS 22 passed, 2 skipped, 1221 assertions; Pi 23 passed, 1 skipped, 1223 assertions.

## 2026-10-05

Created the bundle for 0.10.0. The extension binds Vulkan 1:1 against the system loader: instance and device, memory and images, render passes and pipelines, commands and fences, surfaces and swapchains, and Linux dmabuf export. Constants are generated from the Pi's `vulkan_core.h` 1.4.309. The suite is 20 passed (1210 assertions) on the Pi (Mesa 26.2 V3DV) with `WAYLAND_DISPLAY=wayland-0`, and 5 passed, 15 skipped (1147 assertions) on Homebrew PHP 8.4 NTS and ZTS. The Mac skips every test that opens a device: MoltenVK needs the portability flags of slice 5. The gate is a stencil-then-cover triangle into a 4× image, resolved in the render pass, blitted, copied out, and read back.
