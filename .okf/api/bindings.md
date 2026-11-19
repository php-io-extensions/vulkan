---
type: API
title: Bindings
description: The Vulkan functions and structs this extension binds, by group.
tags: [vulkan, api]
status: draft
generated: { by: claude-sonnet/5.5, at: 2026-11-08T14:00:00Z }
sources:
  - id: stubs
    resource: stubs/
    title: Stub files
---

# Groups

| Group | Source | What it binds |
|---|---|---|
| Instance and device | `src/vk_instance.c` | `VkInstance`, `VkPhysicalDevice`, `VkDevice`, `VkQueue`; create, destroy, enumerate, properties, formats, memory properties, queues; `vkGetPhysicalDeviceImageFormatProperties` answers the `VkResult` and a `VkImageFormatProperties` by reference (zeroed when the call refuses, as C leaves it; the class has no constructor, only the call makes one); `vkGetPhysicalDeviceFeatures` answers a `VkPhysicalDeviceFeatures` by reference, as `vkGetPhysicalDeviceProperties` does; `vkGetPhysicalDeviceFeatures2` fills a `VkPhysicalDeviceFeatures2` and its `pNext` chain in place; `VkPhysicalDeviceMeshShaderFeaturesEXT` is a chain node both ways (on `VkDeviceCreateInfo->pNext` it enables, on `VkPhysicalDeviceFeatures2` it is filled); `vkGetPhysicalDeviceProperties2` fills a `VkPhysicalDeviceProperties2` and its chain in place, and `VkPhysicalDeviceMeshShaderPropertiesEXT` is output only on that chain; `VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT` is a chain node both ways like the mesh features; `vkGetInstanceProcAddr` takes `?VkInstance` and a name and answers the address as an `int` (0 is `NULL`; with `null` and its own name it is the loader's address). `VkPhysicalDevicePortabilitySubsetFeaturesKHR` is the chain node for what `VK_KHR_portability_subset` forbids |
| Memory | `src/vk_memory.c` | `VkDeviceMemory`, `VkBuffer`, `VkImage`, `VkImageView`, `VkSampler`; allocate, map, flush, invalidate, bind |
| Pipelines | `src/vk_pipeline.c` | render passes (`vkCreateRenderPass` and `vkCreateRenderPass2` with the `*2` structs, both begun by `vkCmdBeginRenderPass`; `VkMultisampledRenderToSingleSampledInfoEXT` chains on `VkSubpassDescription2->pNext`), framebuffers, shader modules, graphics pipelines, descriptor layouts, pools, sets, writes |
| Commands | `src/vk_command.c` | command pools and buffers, draw and copy and blit, barriers, submit, fences, semaphores; `vkCmdDrawMeshTasksEXT`, `vkCmdDrawMeshTasksIndirectEXT` and `vkCmdDrawMeshTasksIndirectCountEXT` (`VK_EXT_mesh_shader`) take a `VkCommandBuffer`, so the proc comes from `vkGetDeviceProcAddr` on the device at the end of the command buffer's parent chain (command buffer, pool, device) and goes through `vulkan-no-proc` |
| Surfaces | `src/vk_surface.c` | `VkSurfaceKHR`, `VkSwapchainKHR`; capabilities, formats, present modes, acquire, present; `VkPresentRegionsKHR` / `VkPresentRegionKHR` / `VkRectLayerKHR` (incremental present), `VkPresentIdKHR` and `vkWaitForPresentKHR`, `VkPhysicalDevicePresentIdFeaturesKHR` / `PresentWaitFeaturesKHR` (written back by `vkGetPhysicalDeviceFeatures2`), `VkHdrMetadataEXT` / `VkXYColorEXT` and `vkSetHdrMetadataEXT` (void, as C) |
| Metal surface | `src/vk_metal.c` | `vkCreateMetalSurfaceEXT`, macOS only, loaded with `vkGetInstanceProcAddr` |
| dmabuf | `src/vk_external.c` | `vkGetMemoryFdKHR`, `vkGetImageDrmFormatModifierPropertiesEXT` via `vkGetDeviceProcAddr`; `vkGetImageSubresourceLayout` |

Every function is a Vulkan entry point; there are no helper functions. There is no FFI: host data moves through `vkCmdUpdateBuffer` (a string, at most 65,536 bytes a call) and the Vulkan 1.4 host image copies `vkCopyMemoryToImage`, `vkCopyImageToMemory` and `vkTransitionImageLayout` (commands group). A `VkMemoryToImageCopy` or `VkImageToMemoryCopy` region carries its bytes as the string `$pHostPointer`; for a read the caller gives a string of the size to read and the call fills it. The bytes must cover the region's texels at least one byte each (site `vulkan-bytes-length`). `VkPhysicalDeviceHostImageCopyFeatures` is the `pNext` node that enables and reports the feature; the images need `VK_IMAGE_USAGE_HOST_TRANSFER_BIT`.

An extension command whose `vkGet*ProcAddr` answer is `NULL` is refused with `Error` (site `vulkan-no-proc`): calling `NULL` kills the process. The Vulkan 1.4 host copy commands (`vkCopyMemoryToImage`, `vkCopyImageToMemory`, `vkTransitionImageLayout`) come from `vkGetDeviceProcAddr` the same way, so the extension loads on a Vulkan 1.3 loader; on a device older than 1.4 they are refused at the call. Some implementations hand out the command although its extension is not enabled; the call then goes through.

# Refusals

| Site | Throws | Refused call | Probe |
|---|---|---|---|
| `vulkan-list-count` | `ValueError` | a count past its list | `tests/Probes/ListCountTest.php` |
| `vulkan-bytes-length` | `ValueError` | `codeSize` or push-constant `size` past the string | `tests/Probes/BytesLengthTest.php` |
| `vulkan-null-dispatchable` | `ValueError` | a released `VkInstance`, `VkPhysicalDevice`, `VkDevice`, `VkQueue` or `VkCommandBuffer` | `tests/Probes/NullDispatchableTest.php` |
| `vulkan-no-proc` | `Error` | an extension command with no proc address | `tests/Probes/NoProcTest.php` |

`bindings.json` lists the sites, the marshal helpers, the glue and the typemap. Probes run on a build configured with `--enable-vulkan-probes` (`VULKAN_CONFIGURE=--enable-vulkan-probes ./install-macos.sh`); the `VULKAN_PROBE_OFF` environment variable switches one site off in a child process.
