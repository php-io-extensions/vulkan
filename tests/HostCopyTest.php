<?php

declare(strict_types=1);

/** The host image copies and vkCmdUpdateBuffer (Vulkan 1.4), on the shared device when it was made with hostImageCopy. */
it('writes bytes into an image and reads them back through host copies', function (): void {
    $bytes = random_bytes(4 * 4 * 4);
    [$image] = hostImage2D(4, 4, VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_TRANSFER_SRC_BIT);

    hostWrite($image, 4, 4, $bytes);

    expect(hostRead($image, 4, 4))->toBe($bytes);
});

it('writes and reads a sub-rect of an image by its offset', function (): void {
    [$image] = hostImage2D(4, 4, VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_TRANSFER_SRC_BIT);
    [, , $device] = gpu();
    hostWrite($image, 4, 4, str_repeat("\0", 64));

    $patch = random_bytes(2 * 2 * 4);
    $region = new VkMemoryToImageCopy();
    $region->pHostPointer = $patch;
    $region->imageSubresource->aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
    $region->imageSubresource->layerCount = 1;
    [$region->imageOffset->x, $region->imageOffset->y] = [1, 1];
    [$region->imageExtent->width, $region->imageExtent->height, $region->imageExtent->depth] = [2, 2, 1];
    $write = new VkCopyMemoryToImageInfo();
    $write->dstImage = $image;
    $write->dstImageLayout = VK_IMAGE_LAYOUT_GENERAL;
    $write->regionCount = 1;
    $write->pRegions = [$region];
    expect(vkCopyMemoryToImage($device, $write))->toBe(VK_SUCCESS);

    $whole = hostRead($image, 4, 4);
    expect(substr($whole, (1 * 4 + 1) * 4, 8))->toBe(substr($patch, 0, 8))
        ->and(substr($whole, (2 * 4 + 1) * 4, 8))->toBe(substr($patch, 8, 8))
        ->and(substr($whole, 0, 16))->toBe(str_repeat("\0", 16));
});

it('updates a buffer from a string, and the bytes reach an image the host reads', function (): void {
    [, , $device] = gpu();
    $bytes = random_bytes(4 * 4 * 4);
    [$buffer] = hostBuffer(64, VK_BUFFER_USAGE_TRANSFER_DST_BIT | VK_BUFFER_USAGE_TRANSFER_SRC_BIT);
    [$image] = hostImage2D(4, 4, VK_IMAGE_USAGE_TRANSFER_DST_BIT);

    $copy = new VkBufferImageCopy();
    $copy->imageSubresource->aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
    $copy->imageSubresource->layerCount = 1;
    [$copy->imageExtent->width, $copy->imageExtent->height, $copy->imageExtent->depth] = [4, 4, 1];
    $cmd = commands();
    vkCmdUpdateBuffer($cmd, $buffer, 0, 64, $bytes);
    $updated = new VkMemoryBarrier();
    $updated->srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
    $updated->dstAccessMask = VK_ACCESS_TRANSFER_READ_BIT;
    vkCmdPipelineBarrier($cmd, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT, 0, 1, [$updated], 0, [], 0, []);
    vkCmdCopyBufferToImage($cmd, $buffer, $image, VK_IMAGE_LAYOUT_GENERAL, 1, [$copy]);
    submitAndWait($cmd);

    expect(hostRead($image, 4, 4))->toBe($bytes);
});

it('refuses a host string shorter than the texels of its region, and an update shorter than its size', function (): void {
    [, , $device] = gpu();
    [$image] = hostImage2D(4, 4, VK_IMAGE_USAGE_TRANSFER_DST_BIT);
    $write = new VkCopyMemoryToImageInfo();
    $write->dstImage = $image;
    $write->regionCount = 1;
    $short = new VkMemoryToImageCopy();
    $short->pHostPointer = 'short';
    $short->imageSubresource->aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
    $short->imageSubresource->layerCount = 1;
    [$short->imageExtent->width, $short->imageExtent->height, $short->imageExtent->depth] = [4, 4, 1];
    $write->pRegions = [$short];
    [$buffer] = hostBuffer(64, VK_BUFFER_USAGE_TRANSFER_DST_BIT);

    expect(fn () => vkCopyMemoryToImage($device, $write))->toThrow(ValueError::class)
        ->and(fn () => vkCmdUpdateBuffer(commands(), $buffer, 0, 64, 'short'))->toThrow(ValueError::class, 'fewer than the 64 Vulkan reads');
});
