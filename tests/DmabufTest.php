<?php

declare(strict_types=1);

it('exports a linear RGBA8 image\'s memory as a dmabuf fd with its layout', function (): void {
    [$instance, $physical, , , $family] = gpu();
    $queueInfo = new VkDeviceQueueCreateInfo();
    $queueInfo->queueFamilyIndex = $family;
    $queueInfo->pQueuePriorities = [1.0];
    $deviceInfo = new VkDeviceCreateInfo();
    $deviceInfo->pQueueCreateInfos = [$queueInfo];
    $deviceInfo->enabledExtensionNames = [VK_KHR_EXTERNAL_MEMORY_FD_EXTENSION_NAME, VK_EXT_EXTERNAL_MEMORY_DMA_BUF_EXTENSION_NAME, VK_EXT_IMAGE_DRM_FORMAT_MODIFIER_EXTENSION_NAME];
    vkCreateDevice($physical, portabilityDevice($physical, $deviceInfo), null, $device) === VK_SUCCESS || throw new RuntimeException('vkCreateDevice with dmabuf extensions');

    $modifiers = new VkImageDrmFormatModifierListCreateInfoEXT();
    $modifiers->pDrmFormatModifiers = [0]; // DRM_FORMAT_MOD_LINEAR
    $external = new VkExternalMemoryImageCreateInfo();
    $external->handleTypes = VK_EXTERNAL_MEMORY_HANDLE_TYPE_DMA_BUF_BIT_EXT;
    $external->pNext = $modifiers;
    $imageInfo = new VkImageCreateInfo();
    $imageInfo->pNext = $external;
    $imageInfo->imageType = VK_IMAGE_TYPE_2D;
    $imageInfo->format = VK_FORMAT_R8G8B8A8_UNORM;
    [$imageInfo->extent->width, $imageInfo->extent->height, $imageInfo->extent->depth] = [64, 32, 1];
    $imageInfo->mipLevels = 1;
    $imageInfo->arrayLayers = 1;
    $imageInfo->samples = VK_SAMPLE_COUNT_1_BIT;
    $imageInfo->tiling = VK_IMAGE_TILING_DRM_FORMAT_MODIFIER_EXT;
    $imageInfo->usage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT;
    expect(vkCreateImage($device, $imageInfo, null, $image))->toBe(VK_SUCCESS);

    vkGetImageMemoryRequirements($device, $image, $requirements);
    $export = new VkExportMemoryAllocateInfo();
    $export->handleTypes = VK_EXTERNAL_MEMORY_HANDLE_TYPE_DMA_BUF_BIT_EXT;
    $allocate = new VkMemoryAllocateInfo();
    $allocate->pNext = $export;
    $allocate->allocationSize = $requirements->size;
    $allocate->memoryTypeIndex = memoryType($requirements->memoryTypeBits, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
    vkAllocateMemory($device, $allocate, null, $memory);
    vkBindImageMemory($device, $image, $memory, 0);

    $fdInfo = new VkMemoryGetFdInfoKHR();
    $fdInfo->memory = $memory;
    $fdInfo->handleType = VK_EXTERNAL_MEMORY_HANDLE_TYPE_DMA_BUF_BIT_EXT;
    $subresource = new VkImageSubresource();
    $subresource->aspectMask = VK_IMAGE_ASPECT_MEMORY_PLANE_0_BIT_EXT;

    expect(vkGetMemoryFdKHR($device, $fdInfo, $fd))->toBe(VK_SUCCESS)
        ->and($fd)->toBeGreaterThan(2)
        ->and(vkGetImageDrmFormatModifierPropertiesEXT($device, $image, $properties))->toBe(VK_SUCCESS)
        ->and($properties->drmFormatModifier)->toBe(0);

    vkGetImageSubresourceLayout($device, $image, $subresource, $layout);
    expect($layout->rowPitch)->toBeGreaterThanOrEqual(64 * 4);

    posix_close($fd);
    vkDestroyDevice($device, null);
})->skip(PHP_OS_FAMILY === 'Darwin', 'dmabuf is Linux only');
