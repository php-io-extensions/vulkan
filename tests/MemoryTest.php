<?php

declare(strict_types=1);

it('maps host-visible memory to an address, writes, flushes, invalidates and reads it back', function (): void {
    [, , $device] = gpu();
    [$buffer, $memory] = hostBuffer(256, VK_BUFFER_USAGE_TRANSFER_DST_BIT);
    $bytes = random_bytes(256);

    expect(vkMapMemory($device, $memory, 0, VK_WHOLE_SIZE, 0, $address))->toBe(VK_SUCCESS)
        ->and($address)->toBeGreaterThan(0);

    mappedWrite($address, $bytes);
    $range = new VkMappedMemoryRange();
    $range->memory = $memory;
    $range->size = VK_WHOLE_SIZE;

    expect(vkFlushMappedMemoryRanges($device, 1, [$range]))->toBe(VK_SUCCESS)
        ->and(vkInvalidateMappedMemoryRanges($device, 1, [$range]))->toBe(VK_SUCCESS)
        ->and(mappedRead($address, 256))->toBe($bytes);

    vkUnmapMemory($device, $memory);
    vkDestroyBuffer($device, $buffer, 0);
    vkFreeMemory($device, $memory, 0);
});

it('makes a 4x colour image, a 4x stencil image and their views', function (): void {
    [, , $device] = gpu();
    [$color, $colorMemory] = image2D(VK_FORMAT_R8G8B8A8_UNORM, 8, 8, VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT, VK_SAMPLE_COUNT_4_BIT);
    [$stencil, $stencilMemory] = image2D(stencilFormat(), 8, 8, VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT, VK_SAMPLE_COUNT_4_BIT);

    $colorView = view2D($color, VK_FORMAT_R8G8B8A8_UNORM, VK_IMAGE_ASPECT_COLOR_BIT);
    $stencilView = view2D($stencil, stencilFormat(), VK_IMAGE_ASPECT_DEPTH_BIT | VK_IMAGE_ASPECT_STENCIL_BIT);
    vkGetImageMemoryRequirements($device, $color, $requirements);

    expect($colorView)->toBeInstanceOf(VkImageView::class)
        ->and($stencilView)->toBeInstanceOf(VkImageView::class)
        ->and($requirements->size)->toBeGreaterThanOrEqual(8 * 8 * 4 * 4);

    vkDestroyImageView($device, $colorView, 0);
    vkDestroyImageView($device, $stencilView, 0);
    vkDestroyImage($device, $color, 0);
    vkDestroyImage($device, $stencil, 0);
    vkFreeMemory($device, $colorMemory, 0);
    vkFreeMemory($device, $stencilMemory, 0);
});

it('makes a sampler, and a freed memory object reads 0 and frees again as NULL', function (): void {
    [, , $device] = gpu();
    $info = new VkSamplerCreateInfo();
    $info->magFilter = VK_FILTER_NEAREST;
    $info->minFilter = VK_FILTER_LINEAR;

    expect(vkCreateSampler($device, $info, 0, $sampler))->toBe(VK_SUCCESS);
    vkDestroySampler($device, $sampler, 0);

    [$buffer, $memory] = hostBuffer(64, VK_BUFFER_USAGE_TRANSFER_SRC_BIT);
    vkDestroyBuffer($device, $buffer, 0);
    vkFreeMemory($device, $memory, 0);
    vkFreeMemory($device, $memory, 0);

    expect($memory->pointer())->toBe(0)
        ->and($buffer->pointer())->toBe(0);
});

it('allocates an image\'s memory dedicated to it', function (): void {
    [, , $device] = gpu();
    $info = new VkImageCreateInfo();
    $info->imageType = VK_IMAGE_TYPE_2D;
    $info->format = VK_FORMAT_R8G8B8A8_UNORM;
    [$info->extent->width, $info->extent->height, $info->extent->depth] = [16, 8, 1];
    $info->mipLevels = 1;
    $info->arrayLayers = 1;
    $info->samples = VK_SAMPLE_COUNT_1_BIT;
    $info->tiling = VK_IMAGE_TILING_OPTIMAL;
    $info->usage = VK_IMAGE_USAGE_TRANSFER_DST_BIT;
    vkCreateImage($device, $info, 0, $image);
    vkGetImageMemoryRequirements($device, $image, $requirements);
    $dedicated = new VkMemoryDedicatedAllocateInfo();
    $dedicated->image = $image;
    $allocate = new VkMemoryAllocateInfo();
    $allocate->pNext = $dedicated;
    $allocate->allocationSize = $requirements->size;
    $allocate->memoryTypeIndex = memoryType($requirements->memoryTypeBits, 0);

    expect(vkAllocateMemory($device, $allocate, 0, $memory))->toBe(VK_SUCCESS)
        ->and(vkBindImageMemory($device, $image, $memory, 0))->toBe(VK_SUCCESS);

    vkDestroyImage($device, $image, 0);
    vkFreeMemory($device, $memory, 0);
});
