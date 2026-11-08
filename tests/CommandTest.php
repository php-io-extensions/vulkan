<?php

declare(strict_types=1);

it('copies bytes through an image and back with barriers between', function (): void {
    requireHostCopy();
    $bytes = random_bytes(4 * 4 * 4);
    [$up] = hostBuffer(64, VK_BUFFER_USAGE_TRANSFER_SRC_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT);
    [$down] = hostBuffer(64, VK_BUFFER_USAGE_TRANSFER_SRC_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT);
    [$image, $imageMemory] = image2D(VK_FORMAT_R8G8B8A8_UNORM, 4, 4, VK_IMAGE_USAGE_TRANSFER_SRC_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT);
    // the bytes go in with vkCmdUpdateBuffer and come out through an image the host reads
    [$out] = hostImage2D(4, 4, VK_IMAGE_USAGE_TRANSFER_DST_BIT);

    $layers = new VkImageSubresourceLayers();
    $layers->aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
    $layers->layerCount = 1;
    $region = new VkBufferImageCopy();
    $region->imageSubresource = $layers;
    [$region->imageExtent->width, $region->imageExtent->height, $region->imageExtent->depth] = [4, 4, 1];

    $cmd = commands();
    vkCmdUpdateBuffer($cmd, $up, 0, 64, $bytes);
    $transferred = new VkMemoryBarrier();
    $transferred->srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
    $transferred->dstAccessMask = VK_ACCESS_TRANSFER_READ_BIT;
    vkCmdPipelineBarrier($cmd, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT, 0, 1, [$transferred], 0, [], 0, []);
    vkCmdPipelineBarrier($cmd, VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT, 0, 0, [], 0, [], 1, [layoutBarrier($image, VK_IMAGE_LAYOUT_UNDEFINED, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, 0, VK_ACCESS_TRANSFER_WRITE_BIT)]);
    vkCmdCopyBufferToImage($cmd, $up, $image, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, 1, [$region]);
    vkCmdPipelineBarrier($cmd, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT, 0, 0, [], 0, [], 1, [layoutBarrier($image, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, VK_ACCESS_TRANSFER_WRITE_BIT, VK_ACCESS_TRANSFER_READ_BIT)]);
    vkCmdCopyImageToBuffer($cmd, $image, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, $down, 1, [$region]);
    vkCmdPipelineBarrier($cmd, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT, 0, 1, [$transferred], 0, [], 0, []);
    vkCmdCopyBufferToImage($cmd, $down, $out, VK_IMAGE_LAYOUT_GENERAL, 1, [$region]);
    submitAndWait($cmd);

    expect(hostRead($out, 4, 4))->toBe($bytes);
});

it('refuses push constants shorter than their size, and a count past its list', function (): void {
    $cmd = commands();
    [$buffer] = hostBuffer(16, VK_BUFFER_USAGE_VERTEX_BUFFER_BIT);

    expect(fn () => vkCmdPushConstants($cmd, flatLayout(), VK_SHADER_STAGE_FRAGMENT_BIT, 0, 16, 'abc'))->toThrow(ValueError::class, 'holds 3 bytes, fewer than the 16 Vulkan reads')
        ->and(fn () => vkCmdBindVertexBuffers($cmd, 0, 1, [$buffer], []))->toThrow(ValueError::class, 'must not pass the length of argument #5 ($pOffsets)');
});

it('passes the count it is given, so a list may hold more than Vulkan reads', function (): void {
    $cmd = commands();
    [$buffer] = hostBuffer(16, VK_BUFFER_USAGE_VERTEX_BUFFER_BIT);
    [$other] = hostBuffer(16, VK_BUFFER_USAGE_VERTEX_BUFFER_BIT);

    vkCmdBindVertexBuffers($cmd, 0, 1, [$buffer, $other], [0, 0]);
    vkCmdBindVertexBuffers($cmd, 0, 0, [], []);

    expect(vkEndCommandBuffer($cmd))->toBe(VK_SUCCESS);
});

it('signals and resets a fence', function (): void {
    [, , $device, $queue] = gpu();
    vkCreateFence($device, new VkFenceCreateInfo(), 0, $fence);
    vkQueueSubmit($queue, 0, [], $fence);

    expect(vkWaitForFences($device, 1, [$fence], true, PHP_INT_MAX))->toBe(VK_SUCCESS)
        ->and(vkGetFenceStatus($device, $fence))->toBe(VK_SUCCESS)
        ->and(vkResetFences($device, 1, [$fence]))->toBe(VK_SUCCESS)
        ->and(vkGetFenceStatus($device, $fence))->toBe(VK_NOT_READY)
        ->and(vkQueueWaitIdle($queue))->toBe(VK_SUCCESS);

    vkDestroyFence($device, $fence, 0);
    vkDestroyFence($device, null, 0);
});

it('refuses a barrier list holding something else', function (): void {
    $cmd = commands();

    expect(fn () => vkCmdPipelineBarrier($cmd, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_HOST_BIT, 0, 1, [new VkFenceCreateInfo()], 0, [], 0, []))->toThrow(TypeError::class);
});
