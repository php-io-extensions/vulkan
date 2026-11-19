<?php

declare(strict_types=1);

/*
 * vkCreateRenderPass2 (Vulkan 1.2) and its structs. The render pass it makes is begun with the same vkCmdBeginRenderPass
 * as one from vkCreateRenderPass: the pass is the handle, whichever call made it.
 */

it('creates a render pass with vkCreateRenderPass2 that clears an image', function (): void {
    requireHostCopy();
    [, , $device, $queue, $family] = gpu();
    [$image] = hostImage2D(4, 4, VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT);
    $view = view2D($image, VK_FORMAT_R8G8B8A8_UNORM, VK_IMAGE_ASPECT_COLOR_BIT);

    $attachment = new VkAttachmentDescription2();
    $attachment->format = VK_FORMAT_R8G8B8A8_UNORM;
    $attachment->samples = VK_SAMPLE_COUNT_1_BIT;
    $attachment->loadOp = VK_ATTACHMENT_LOAD_OP_CLEAR;
    $attachment->storeOp = VK_ATTACHMENT_STORE_OP_STORE;
    $attachment->stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
    $attachment->stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
    $attachment->initialLayout = VK_IMAGE_LAYOUT_GENERAL;
    $attachment->finalLayout = VK_IMAGE_LAYOUT_GENERAL;
    $reference = new VkAttachmentReference2();
    $reference->attachment = 0;
    $reference->layout = VK_IMAGE_LAYOUT_GENERAL;
    $reference->aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
    $subpass = new VkSubpassDescription2();
    $subpass->pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;
    $subpass->colorAttachmentCount = 1;
    $subpass->pColorAttachments = [$reference];
    $dependency = new VkSubpassDependency2();
    $dependency->srcSubpass = VK_SUBPASS_EXTERNAL;
    $dependency->dstSubpass = 0;
    $dependency->srcStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
    $dependency->dstStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
    $dependency->dstAccessMask = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;
    $passInfo = new VkRenderPassCreateInfo2();
    $passInfo->attachmentCount = 1;
    $passInfo->pAttachments = [$attachment];
    $passInfo->subpassCount = 1;
    $passInfo->pSubpasses = [$subpass];
    $passInfo->dependencyCount = 1;
    $passInfo->pDependencies = [$dependency];

    expect(vkCreateRenderPass2($device, $passInfo, 0, $pass))->toBe(VK_SUCCESS)
        ->and($pass)->toBeInstanceOf(VkRenderPass::class);

    $framebufferInfo = new VkFramebufferCreateInfo();
    $framebufferInfo->renderPass = $pass;
    $framebufferInfo->attachmentCount = 1;
    $framebufferInfo->pAttachments = [$view];
    [$framebufferInfo->width, $framebufferInfo->height, $framebufferInfo->layers] = [4, 4, 1];
    vkCreateFramebuffer($device, $framebufferInfo, 0, $framebuffer) === VK_SUCCESS || throw new RuntimeException('vkCreateFramebuffer');

    $magenta = new VkClearValue();
    $magenta->color = new VkClearColorValue();
    $magenta->color->float32 = [1.0, 0.0, 1.0, 1.0];
    $begin = new VkRenderPassBeginInfo();
    $begin->renderPass = $pass;
    $begin->framebuffer = $framebuffer;
    [$begin->renderArea->extent->width, $begin->renderArea->extent->height] = [4, 4];
    $begin->clearValueCount = 1;
    $begin->pClearValues = [$magenta];
    $cmd = commandsOn($device, $family);
    vkCmdBeginRenderPass($cmd, $begin, VK_SUBPASS_CONTENTS_INLINE);
    vkCmdEndRenderPass($cmd);
    submitAndWaitOn($device, $queue, $cmd);

    $pixels = hostRead($image, 4, 4);
    expect(substr($pixels, 0, 4))->toBe("\xFF\x00\xFF\xFF")
        ->and(substr($pixels, 4 * 4 * 4 - 4))->toBe("\xFF\x00\xFF\xFF");
});
