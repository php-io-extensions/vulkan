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

it('copies a region from one image into another with vkCmdCopyImage', function (): void {
    $source = random_bytes(8 * 8 * 4);
    $blank = str_repeat("\0", 8 * 8 * 4);
    $usage = VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_TRANSFER_SRC_BIT;
    [$src] = hostImage2D(8, 8, $usage);
    [$dst] = hostImage2D(8, 8, $usage);
    hostWrite($src, 8, 8, $source);
    hostWrite($dst, 8, 8, $blank);

    // The 3x2 texels at (1,2) of the source land at (4,5) of the destination.
    $region = new VkImageCopy();
    $region->srcSubresource->aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
    $region->srcSubresource->layerCount = 1;
    [$region->srcOffset->x, $region->srcOffset->y] = [1, 2];
    $region->dstSubresource->aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
    $region->dstSubresource->layerCount = 1;
    [$region->dstOffset->x, $region->dstOffset->y] = [4, 5];
    [$region->extent->width, $region->extent->height, $region->extent->depth] = [3, 2, 1];
    $cmd = commands();
    vkCmdCopyImage($cmd, $src, VK_IMAGE_LAYOUT_GENERAL, $dst, VK_IMAGE_LAYOUT_GENERAL, 1, [$region]);
    submitAndWait($cmd);

    $expected = $blank;
    for ($y = 0; $y < 2; $y++) {
        $expected = substr_replace($expected, substr($source, ((2 + $y) * 8 + 1) * 4, 12), ((5 + $y) * 8 + 4) * 4, 12);
    }
    expect(hostRead($dst, 8, 8))->toBe($expected)
        ->and(fn () => vkCmdCopyImage(commands(), $src, VK_IMAGE_LAYOUT_GENERAL, $dst, VK_IMAGE_LAYOUT_GENERAL, 2, [$region]))
        ->toThrow(ValueError::class, 'must not pass the length of argument #7 ($pRegions)');
});

it('creates a compute pipeline and dispatches it into a storage buffer', function (): void {
    [, , $device] = gpu();
    $binding = new VkDescriptorSetLayoutBinding();
    $binding->descriptorType = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;
    $binding->descriptorCount = 1;
    $binding->stageFlags = VK_SHADER_STAGE_COMPUTE_BIT;
    $setInfo = new VkDescriptorSetLayoutCreateInfo();
    $setInfo->bindingCount = 1;
    $setInfo->pBindings = [$binding];
    vkCreateDescriptorSetLayout($device, $setInfo, 0, $setLayout);
    $layoutInfo = new VkPipelineLayoutCreateInfo();
    $layoutInfo->setLayoutCount = 1;
    $layoutInfo->pSetLayouts = [$setLayout];
    vkCreatePipelineLayout($device, $layoutInfo, 0, $layout);

    $info = new VkComputePipelineCreateInfo();
    $info->stage->stage = VK_SHADER_STAGE_COMPUTE_BIT;
    $info->stage->module = shaderModule('fill.comp.spv');
    $info->stage->pName = 'main';
    $info->layout = $layout;
    $info->basePipelineIndex = -1;
    expect(vkCreateComputePipelines($device, 0, 1, [$info], 0, $pipelines))->toBe(VK_SUCCESS)
        ->and($pipelines)->toHaveCount(1)
        ->and($pipelines[0])->toBeInstanceOf(VkPipeline::class);

    $size = new VkDescriptorPoolSize();
    $size->type = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;
    $size->descriptorCount = 1;
    $poolInfo = new VkDescriptorPoolCreateInfo();
    $poolInfo->maxSets = 1;
    $poolInfo->poolSizeCount = 1;
    $poolInfo->pPoolSizes = [$size];
    vkCreateDescriptorPool($device, $poolInfo, 0, $pool);
    $allocate = new VkDescriptorSetAllocateInfo();
    $allocate->descriptorPool = $pool;
    $allocate->descriptorSetCount = 1;
    $allocate->pSetLayouts = [$setLayout];
    vkAllocateDescriptorSets($device, $allocate, $sets);
    [$buffer] = hostBuffer(64, VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | VK_BUFFER_USAGE_TRANSFER_SRC_BIT);
    $bufferInfo = new VkDescriptorBufferInfo();
    $bufferInfo->buffer = $buffer;
    $bufferInfo->range = VK_WHOLE_SIZE;
    $write = new VkWriteDescriptorSet();
    $write->dstSet = $sets[0];
    $write->descriptorCount = 1;
    $write->descriptorType = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;
    $write->pBufferInfo = [$bufferInfo];
    vkUpdateDescriptorSets($device, 1, [$write], 0, []);
    [$image] = hostImage2D(4, 4, VK_IMAGE_USAGE_TRANSFER_DST_BIT);

    // Four groups of four invocations write data[i] = 3i + 1 for i in 0..15: the 64 bytes of a 4x4 RGBA8 image.
    $cmd = commands();
    vkCmdBindPipeline($cmd, VK_PIPELINE_BIND_POINT_COMPUTE, $pipelines[0]);
    vkCmdBindDescriptorSets($cmd, VK_PIPELINE_BIND_POINT_COMPUTE, $layout, 0, 1, $sets, 0, []);
    vkCmdDispatch($cmd, 4, 1, 1);
    $written = new VkMemoryBarrier();
    $written->srcAccessMask = VK_ACCESS_SHADER_WRITE_BIT;
    $written->dstAccessMask = VK_ACCESS_TRANSFER_READ_BIT;
    vkCmdPipelineBarrier($cmd, VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT, 0, 1, [$written], 0, [], 0, []);
    $copy = new VkBufferImageCopy();
    $copy->imageSubresource->aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
    $copy->imageSubresource->layerCount = 1;
    [$copy->imageExtent->width, $copy->imageExtent->height, $copy->imageExtent->depth] = [4, 4, 1];
    vkCmdCopyBufferToImage($cmd, $buffer, $image, VK_IMAGE_LAYOUT_GENERAL, 1, [$copy]);
    submitAndWait($cmd);

    expect(hostRead($image, 4, 4))->toBe(pack('V*', ...array_map(fn (int $i): int => $i * 3 + 1, range(0, 15))))
        ->and(fn () => vkCreateComputePipelines($device, 0, 2, [$info], 0, $more))
        ->toThrow(ValueError::class, 'must not pass the length of argument #4 ($pCreateInfos)');

    vkDestroyPipeline($device, $pipelines[0], 0);
    vkDestroyDescriptorPool($device, $pool, 0);
    vkDestroyPipelineLayout($device, $layout, 0);
    vkDestroyDescriptorSetLayout($device, $setLayout, 0);
});
