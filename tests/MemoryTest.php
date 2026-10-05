<?php

declare(strict_types=1);

it('maps host-visible memory to an address, writes, flushes, invalidates and reads it back', function (): void {
    [, , $device] = gpu();
    [$buffer, $memory] = hostBuffer(256, VK_BUFFER_USAGE_TRANSFER_DST_BIT);
    $bytes = random_bytes(256);

    expect(vkMapMemory($device, $memory, 0, VK_WHOLE_SIZE, 0, $address))->toBe(VK_SUCCESS)
        ->and($address)->toBeGreaterThan(0);

    vk_write_mapped($address, $bytes);
    $range = new VkMappedMemoryRange();
    $range->memory = $memory;
    $range->size = VK_WHOLE_SIZE;

    expect(vkFlushMappedMemoryRanges($device, [$range]))->toBe(VK_SUCCESS)
        ->and(vkInvalidateMappedMemoryRanges($device, [$range]))->toBe(VK_SUCCESS)
        ->and(vk_read_mapped($address, 256))->toBe($bytes);

    vkUnmapMemory($device, $memory);
    vkDestroyBuffer($device, $buffer, null);
    vkFreeMemory($device, $memory, null);
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

    vkDestroyImageView($device, $colorView, null);
    vkDestroyImageView($device, $stencilView, null);
    vkDestroyImage($device, $color, null);
    vkDestroyImage($device, $stencil, null);
    vkFreeMemory($device, $colorMemory, null);
    vkFreeMemory($device, $stencilMemory, null);
});

it('makes a sampler and refuses a freed memory object', function (): void {
    [, , $device] = gpu();
    $info = new VkSamplerCreateInfo();
    $info->magFilter = VK_FILTER_NEAREST;
    $info->minFilter = VK_FILTER_LINEAR;

    expect(vkCreateSampler($device, $info, null, $sampler))->toBe(VK_SUCCESS);
    vkDestroySampler($device, $sampler, null);

    [$buffer, $memory] = hostBuffer(64, VK_BUFFER_USAGE_TRANSFER_SRC_BIT);
    vkDestroyBuffer($device, $buffer, null);
    vkFreeMemory($device, $memory, null);
    expect(fn () => vkMapMemory($device, $memory, 0, 64, 0, $address))->toThrow(ValueError::class, 'VkDeviceMemory has been destroyed');
});
