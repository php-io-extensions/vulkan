<?php

declare(strict_types=1);

it('copies bytes through an image and back with barriers between', function (): void {
    [, , $device] = gpu();
    $bytes = random_bytes(4 * 4 * 4);
    [$up, $upMemory] = hostBuffer(64, VK_BUFFER_USAGE_TRANSFER_SRC_BIT);
    [$down, $downMemory] = hostBuffer(64, VK_BUFFER_USAGE_TRANSFER_DST_BIT);
    vkMapMemory($device, $upMemory, 0, 64, 0, $address);
    vk_write_mapped($address, $bytes);
    vkUnmapMemory($device, $upMemory);
    [$image, $imageMemory] = image2D(VK_FORMAT_R8G8B8A8_UNORM, 4, 4, VK_IMAGE_USAGE_TRANSFER_SRC_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT);

    $layers = new VkImageSubresourceLayers();
    $layers->aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
    $layers->layerCount = 1;
    $region = new VkBufferImageCopy();
    $region->imageSubresource = $layers;
    [$region->imageExtent->width, $region->imageExtent->height, $region->imageExtent->depth] = [4, 4, 1];

    $cmd = commands();
    vkCmdPipelineBarrier($cmd, VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT, 0, [], [], [layoutBarrier($image, VK_IMAGE_LAYOUT_UNDEFINED, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, 0, VK_ACCESS_TRANSFER_WRITE_BIT)]);
    vkCmdCopyBufferToImage($cmd, $up, $image, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, [$region]);
    vkCmdPipelineBarrier($cmd, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT, 0, [], [], [layoutBarrier($image, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, VK_ACCESS_TRANSFER_WRITE_BIT, VK_ACCESS_TRANSFER_READ_BIT)]);
    vkCmdCopyImageToBuffer($cmd, $image, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, $down, [$region]);
    submitAndWait($cmd);

    vkMapMemory($device, $downMemory, 0, 64, 0, $address);
    $range = new VkMappedMemoryRange();
    $range->memory = $downMemory;
    $range->size = VK_WHOLE_SIZE;
    vkInvalidateMappedMemoryRanges($device, [$range]);
    expect(vk_read_mapped($address, 64))->toBe($bytes);
    vkUnmapMemory($device, $downMemory);
});

it('refuses push constants shorter than their size, and mismatched vertex buffer lists', function (): void {
    $cmd = commands();
    [$buffer] = hostBuffer(16, VK_BUFFER_USAGE_VERTEX_BUFFER_BIT);

    expect(fn () => vkCmdPushConstants($cmd, flatLayout(), VK_SHADER_STAGE_FRAGMENT_BIT, 0, 16, 'abc'))->toThrow(ValueError::class, 'must hold 16 bytes')
        ->and(fn () => vkCmdBindVertexBuffers($cmd, 0, [$buffer], []))->toThrow(ValueError::class, 'same length');
});

it('signals and resets a fence', function (): void {
    [, , $device, $queue] = gpu();
    vkCreateFence($device, new VkFenceCreateInfo(), null, $fence);
    vkQueueSubmit($queue, [], $fence);

    expect(vkWaitForFences($device, [$fence], true, PHP_INT_MAX))->toBe(VK_SUCCESS)
        ->and(vkGetFenceStatus($device, $fence))->toBe(VK_SUCCESS)
        ->and(vkResetFences($device, [$fence]))->toBe(VK_SUCCESS)
        ->and(vkGetFenceStatus($device, $fence))->toBe(VK_NOT_READY)
        ->and(vkQueueWaitIdle($queue))->toBe(VK_SUCCESS);

    vkDestroyFence($device, $fence, null);
});
