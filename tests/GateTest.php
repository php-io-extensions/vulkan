<?php

declare(strict_types=1);

/** RGBA8 pixel at (x, y) of a tightly packed 8-wide image; Vulkan rows run top-down. */
function pixelAt(string $bytes, int $x, int $y): string
{
    return bin2hex(substr($bytes, ($y * 8 + $x) * 4, 4));
}

it('fills a triangle by stencil-then-cover into a 4x image, resolves in the pass, blits, copies out and reads back', function (): void {
    [, , $device] = gpu();
    $pass = msaaRenderPass();
    $layout = flatLayout();
    $stencilPipeline = flatPipeline($pass, $layout, false, VK_COMPARE_OP_ALWAYS, VK_STENCIL_OP_INVERT);
    $coverPipeline = flatPipeline($pass, $layout, true, VK_COMPARE_OP_NOT_EQUAL, VK_STENCIL_OP_ZERO);

    [$msaa, $msaaMemory] = image2D(VK_FORMAT_R8G8B8A8_UNORM, 8, 8, VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT, VK_SAMPLE_COUNT_4_BIT);
    [$stencil, $stencilMemory] = image2D(stencilFormat(), 8, 8, VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT, VK_SAMPLE_COUNT_4_BIT);
    [$resolved, $resolvedMemory] = image2D(VK_FORMAT_R8G8B8A8_UNORM, 8, 8, VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT | VK_IMAGE_USAGE_TRANSFER_SRC_BIT);
    [$blitted, $blittedMemory] = image2D(VK_FORMAT_R8G8B8A8_UNORM, 8, 8, VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_TRANSFER_SRC_BIT);
    $framebufferInfo = new VkFramebufferCreateInfo();
    $framebufferInfo->renderPass = $pass;
    $framebufferInfo->pAttachments = [
        view2D($msaa, VK_FORMAT_R8G8B8A8_UNORM, VK_IMAGE_ASPECT_COLOR_BIT),
        view2D($stencil, stencilFormat(), VK_IMAGE_ASPECT_DEPTH_BIT | VK_IMAGE_ASPECT_STENCIL_BIT),
        view2D($resolved, VK_FORMAT_R8G8B8A8_UNORM, VK_IMAGE_ASPECT_COLOR_BIT),
    ];
    [$framebufferInfo->width, $framebufferInfo->height, $framebufferInfo->layers] = [8, 8, 1];
    vkCreateFramebuffer($device, $framebufferInfo, null, $framebuffer);

    // The triangle (-1,-1), (1,-1), (-1,1), then a cover quad as two triangles.
    $points = pack('g18', -1.0, -1.0, 1.0, -1.0, -1.0, 1.0,   -1.0, -1.0, 1.0, -1.0, -1.0, 1.0, -1.0, 1.0, 1.0, -1.0, 1.0, 1.0);
    [$vertices, $verticesMemory] = hostBuffer(strlen($points), VK_BUFFER_USAGE_VERTEX_BUFFER_BIT);
    vkMapMemory($device, $verticesMemory, 0, VK_WHOLE_SIZE, 0, $address);
    vk_write_mapped($address, $points);
    $range = new VkMappedMemoryRange();
    $range->memory = $verticesMemory;
    $range->size = VK_WHOLE_SIZE;
    vkFlushMappedMemoryRanges($device, [$range]);
    vkUnmapMemory($device, $verticesMemory);
    [$readback, $readbackMemory] = hostBuffer(512, VK_BUFFER_USAGE_TRANSFER_DST_BIT);

    $clearColor = new VkClearValue();
    $clearColor->color = new VkClearColorValue();
    $clearColor->color->float32 = [0.0, 0.0, 0.0, 1.0];
    $clearStencil = new VkClearValue();
    $clearStencil->depthStencil = new VkClearDepthStencilValue();
    $clearStencil->depthStencil->depth = 1.0;
    $clearStencil->depthStencil->stencil = 0;
    $begin = new VkRenderPassBeginInfo();
    $begin->renderPass = $pass;
    $begin->framebuffer = $framebuffer;
    [$begin->renderArea->extent->width, $begin->renderArea->extent->height] = [8, 8];
    $begin->pClearValues = [$clearColor, $clearStencil, $clearColor];
    $viewport = new VkViewport();
    [$viewport->width, $viewport->height, $viewport->maxDepth] = [8.0, 8.0, 1.0];
    $scissor = new VkRect2D();
    [$scissor->extent->width, $scissor->extent->height] = [8, 8];

    $cmd = commands();
    vkCmdBeginRenderPass($cmd, $begin, VK_SUBPASS_CONTENTS_INLINE);
    vkCmdSetViewport($cmd, 0, [$viewport]);
    vkCmdSetScissor($cmd, 0, [$scissor]);
    vkCmdBindVertexBuffers($cmd, 0, [$vertices], [0]);
    // Stencil: invert where the triangle covers, no colour written.
    vkCmdBindPipeline($cmd, VK_PIPELINE_BIND_POINT_GRAPHICS, $stencilPipeline);
    vkCmdDraw($cmd, 3, 1, 0, 0);
    // Cover: red where the stencil is not 0, and the stencil back to 0.
    vkCmdBindPipeline($cmd, VK_PIPELINE_BIND_POINT_GRAPHICS, $coverPipeline);
    vkCmdSetStencilReference($cmd, VK_STENCIL_FACE_FRONT_AND_BACK, 0);
    vkCmdPushConstants($cmd, $layout, VK_SHADER_STAGE_FRAGMENT_BIT, 0, 16, pack('g4', 1.0, 0.0, 0.0, 1.0));
    vkCmdDraw($cmd, 6, 1, 3, 0);
    vkCmdEndRenderPass($cmd);

    // The resolved image ends the pass TRANSFER_SRC_OPTIMAL: blit it, then copy both out.
    $layers = new VkImageSubresourceLayers();
    $layers->aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
    $layers->layerCount = 1;
    $blit = new VkImageBlit();
    $blit->srcSubresource = $layers;
    $blit->dstSubresource = $layers;
    $corner = tap(new VkOffset3D(), fn (VkOffset3D $o) => [$o->x, $o->y, $o->z] = [8, 8, 1]);
    $blit->srcOffsets = [new VkOffset3D(), $corner];
    $blit->dstOffsets = [new VkOffset3D(), $corner];
    vkCmdPipelineBarrier($cmd, VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT, 0, [], [], [layoutBarrier($blitted, VK_IMAGE_LAYOUT_UNDEFINED, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, 0, VK_ACCESS_TRANSFER_WRITE_BIT)]);
    vkCmdBlitImage($cmd, $resolved, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, $blitted, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, [$blit], VK_FILTER_NEAREST);
    vkCmdPipelineBarrier($cmd, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT, 0, [], [], [layoutBarrier($blitted, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, VK_ACCESS_TRANSFER_WRITE_BIT, VK_ACCESS_TRANSFER_READ_BIT)]);
    foreach ([$resolved, $blitted] as $i => $image) {
        $copy = new VkBufferImageCopy();
        $copy->bufferOffset = $i * 256;
        $copy->imageSubresource = $layers;
        [$copy->imageExtent->width, $copy->imageExtent->height, $copy->imageExtent->depth] = [8, 8, 1];
        vkCmdCopyImageToBuffer($cmd, $image, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, $readback, [$copy]);
    }
    submitAndWait($cmd);

    vkMapMemory($device, $readbackMemory, 0, VK_WHOLE_SIZE, 0, $address);
    $range->memory = $readbackMemory;
    vkInvalidateMappedMemoryRanges($device, [$range]);
    $both = vk_read_mapped($address, 512);
    vkUnmapMemory($device, $readbackMemory);
    [$pixels, $copied] = [substr($both, 0, 256), substr($both, 256)];

    expect($copied)->toBe($pixels)
        // Vulkan's clip space has y down: the triangle is the upper-left half of the image.
        ->and(pixelAt($pixels, 1, 1))->toBe('ff0000ff')
        ->and(pixelAt($pixels, 5, 1))->toBe('ff0000ff')
        ->and(pixelAt($pixels, 1, 5))->toBe('ff0000ff')
        ->and(pixelAt($pixels, 6, 6))->toBe('000000ff')
        // The hypotenuse runs through pixel centres (i, 7 - i): resolved from 4 samples, neither solid colour.
        ->and(array_filter(range(0, 7), fn (int $i): bool => in_array(pixelAt($pixels, $i, 7 - $i), ['ff0000ff', '000000ff'], true)))->toBe([]);

    vkDeviceWaitIdle($device);
});
