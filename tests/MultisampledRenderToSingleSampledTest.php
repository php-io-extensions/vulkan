<?php

declare(strict_types=1);

/*
 * VK_EXT_multisampled_render_to_single_sampled. MoltenVK does not list it; on this Mac only lavapipe (Mesa, a CPU device)
 * does, so these tests are an exception to "device tests skip the CPU device": they open the first device that lists the
 * extension, on their own instance and device, and skip when none does.
 */

const MSRTSS_SIZE = 16;
const MSRTSS_BLUE = "\x00\x00\xFF\xFF";
const MSRTSS_GREEN = "\x00\xFF\x00\xFF";

/**
 * @return array{VkInstance, VkPhysicalDevice, VkDevice, VkQueue, int}|null instance, the first device listing VK_EXT_multisampled_render_to_single_sampled, a device made with that feature (and hostImageCopy), its graphics queue, the family; null where no device lists it
 */
function msrtssDevice(): ?array
{
    static $made = false, $msrtss = null;
    if ($made) {
        return $msrtss;
    }
    $made = true;

    if (vkCreateInstance(portabilityInstance(), 0, $instance) !== VK_SUCCESS) {
        return null;
    }
    vkEnumeratePhysicalDevices($instance, $count, null);
    vkEnumeratePhysicalDevices($instance, $count, $devices);
    foreach ($devices as $physical) {
        vkEnumerateDeviceExtensionProperties($physical, null, $count, null);
        vkEnumerateDeviceExtensionProperties($physical, null, $count, $available);
        $names = array_map(fn (VkExtensionProperties $e): string => $e->extensionName, $available);
        if (in_array(VK_EXT_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_EXTENSION_NAME, $names, true)) {
            break;
        }
        unset($physical);
    }
    if (! isset($physical)) {
        return null;
    }

    vkGetPhysicalDeviceQueueFamilyProperties($physical, $count, null);
    vkGetPhysicalDeviceQueueFamilyProperties($physical, $count, $families);
    $family = array_key_first(array_filter($families, fn (VkQueueFamilyProperties $f): bool => ($f->queueFlags & VK_QUEUE_GRAPHICS_BIT) !== 0));
    $queueInfo = new VkDeviceQueueCreateInfo();
    $queueInfo->queueFamilyIndex = $family;
    $queueInfo->queueCount = 1;
    $queueInfo->pQueuePriorities = [1.0];

    $hostCopy = new VkPhysicalDeviceHostImageCopyFeatures();
    $hostCopy->hostImageCopy = true;
    $feature = new VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT();
    $feature->multisampledRenderToSingleSampled = true;
    $feature->pNext = $hostCopy;
    $info = new VkDeviceCreateInfo();
    $info->queueCreateInfoCount = 1;
    $info->pQueueCreateInfos = [$queueInfo];
    $info->pNext = $feature;
    $info->ppEnabledExtensionNames = [VK_EXT_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_EXTENSION_NAME];
    $info->enabledExtensionCount = 1;
    vkCreateDevice($physical, $info, 0, $device) === VK_SUCCESS || throw new RuntimeException('vkCreateDevice');
    vkGetDeviceQueue($device, $family, 0, $queue);

    return $msrtss = [$instance, $physical, $device, $queue, $family];
}

function msrtssOrSkip(): array
{
    return msrtssDevice() ?? test()->markTestSkipped('no Vulkan device lists VK_EXT_multisampled_render_to_single_sampled');
}

function msrtssMemoryType(int $typeBits, int $properties): int
{
    [, $physical] = msrtssOrSkip();
    vkGetPhysicalDeviceMemoryProperties($physical, $memory);
    foreach ($memory->memoryTypes as $index => $type) {
        if (($typeBits & (1 << $index)) !== 0 && ($type->propertyFlags & $properties) === $properties) {
            return $index;
        }
    }

    throw new RuntimeException('no matching memory type');
}

/**
 * Loads a 16 x 16 single-sampled image filled with opaque blue, draws the green triangle over it with $rasterizationSamples
 * samples per pixel through a render pass whose subpass chains VkMultisampledRenderToSingleSampledInfoEXT, and returns the
 * pixels, rows top-down, read by the host.
 */
function msrtssRender(int $rasterizationSamples, int $tiling = VK_IMAGE_TILING_OPTIMAL): string
{
    [, , $device, $queue, $family] = msrtssOrSkip();

    $imageInfo = new VkImageCreateInfo();
    $imageInfo->flags = VK_IMAGE_CREATE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_BIT_EXT;
    $imageInfo->imageType = VK_IMAGE_TYPE_2D;
    $imageInfo->format = VK_FORMAT_R8G8B8A8_UNORM;
    [$imageInfo->extent->width, $imageInfo->extent->height, $imageInfo->extent->depth] = [MSRTSS_SIZE, MSRTSS_SIZE, 1];
    $imageInfo->mipLevels = 1;
    $imageInfo->arrayLayers = 1;
    $imageInfo->samples = VK_SAMPLE_COUNT_1_BIT;
    $imageInfo->tiling = $tiling;
    $imageInfo->usage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT | VK_IMAGE_USAGE_HOST_TRANSFER_BIT;
    vkCreateImage($device, $imageInfo, 0, $image) === VK_SUCCESS || throw new RuntimeException('vkCreateImage');
    vkGetImageMemoryRequirements($device, $image, $requirements);
    $allocate = new VkMemoryAllocateInfo();
    $allocate->allocationSize = $requirements->size;
    $allocate->memoryTypeIndex = msrtssMemoryType($requirements->memoryTypeBits, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
    vkAllocateMemory($device, $allocate, 0, $memory) === VK_SUCCESS || throw new RuntimeException('vkAllocateMemory');
    vkBindImageMemory($device, $image, $memory, 0) === VK_SUCCESS || throw new RuntimeException('vkBindImageMemory');

    $range = new VkImageSubresourceRange();
    $range->aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
    $range->levelCount = 1;
    $range->layerCount = 1;
    $transition = new VkHostImageLayoutTransitionInfo();
    $transition->image = $image;
    $transition->oldLayout = VK_IMAGE_LAYOUT_UNDEFINED;
    $transition->newLayout = VK_IMAGE_LAYOUT_GENERAL;
    $transition->subresourceRange = $range;
    vkTransitionImageLayout($device, 1, [$transition]) === VK_SUCCESS || throw new RuntimeException('vkTransitionImageLayout');

    $region = new VkMemoryToImageCopy();
    $region->pHostPointer = str_repeat(MSRTSS_BLUE, MSRTSS_SIZE * MSRTSS_SIZE);
    $region->imageSubresource->aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
    $region->imageSubresource->layerCount = 1;
    [$region->imageExtent->width, $region->imageExtent->height, $region->imageExtent->depth] = [MSRTSS_SIZE, MSRTSS_SIZE, 1];
    $fill = new VkCopyMemoryToImageInfo();
    $fill->dstImage = $image;
    $fill->dstImageLayout = VK_IMAGE_LAYOUT_GENERAL;
    $fill->regionCount = 1;
    $fill->pRegions = [$region];
    vkCopyMemoryToImage($device, $fill) === VK_SUCCESS || throw new RuntimeException('vkCopyMemoryToImage');

    $viewInfo = new VkImageViewCreateInfo();
    $viewInfo->image = $image;
    $viewInfo->viewType = VK_IMAGE_VIEW_TYPE_2D;
    $viewInfo->format = VK_FORMAT_R8G8B8A8_UNORM;
    $viewInfo->subresourceRange = $range;
    vkCreateImageView($device, $viewInfo, 0, $view) === VK_SUCCESS || throw new RuntimeException('vkCreateImageView');

    $attachment = new VkAttachmentDescription2();
    $attachment->format = VK_FORMAT_R8G8B8A8_UNORM;
    $attachment->samples = VK_SAMPLE_COUNT_1_BIT;
    $attachment->loadOp = VK_ATTACHMENT_LOAD_OP_LOAD;
    $attachment->storeOp = VK_ATTACHMENT_STORE_OP_STORE;
    $attachment->stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
    $attachment->stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
    $attachment->initialLayout = VK_IMAGE_LAYOUT_GENERAL;
    $attachment->finalLayout = VK_IMAGE_LAYOUT_GENERAL;
    $reference = new VkAttachmentReference2();
    $reference->attachment = 0;
    $reference->layout = VK_IMAGE_LAYOUT_GENERAL;
    $reference->aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
    $single = new VkMultisampledRenderToSingleSampledInfoEXT();
    $single->multisampledRenderToSingleSampledEnable = true;
    $single->rasterizationSamples = $rasterizationSamples;
    $subpass = new VkSubpassDescription2();
    $subpass->pNext = $single;
    $subpass->pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;
    $subpass->colorAttachmentCount = 1;
    $subpass->pColorAttachments = [$reference];
    $passInfo = new VkRenderPassCreateInfo2();
    $passInfo->attachmentCount = 1;
    $passInfo->pAttachments = [$attachment];
    $passInfo->subpassCount = 1;
    $passInfo->pSubpasses = [$subpass];
    vkCreateRenderPass2($device, $passInfo, 0, $pass) === VK_SUCCESS || throw new RuntimeException('vkCreateRenderPass2');

    $framebufferInfo = new VkFramebufferCreateInfo();
    $framebufferInfo->renderPass = $pass;
    $framebufferInfo->attachmentCount = 1;
    $framebufferInfo->pAttachments = [$view];
    [$framebufferInfo->width, $framebufferInfo->height, $framebufferInfo->layers] = [MSRTSS_SIZE, MSRTSS_SIZE, 1];
    vkCreateFramebuffer($device, $framebufferInfo, 0, $framebuffer) === VK_SUCCESS || throw new RuntimeException('vkCreateFramebuffer');

    vkCreatePipelineLayout($device, new VkPipelineLayoutCreateInfo(), 0, $layout) === VK_SUCCESS || throw new RuntimeException('vkCreatePipelineLayout');
    $stage = function (int $bit, string $file) use ($device): VkPipelineShaderStageCreateInfo {
        $code = new VkShaderModuleCreateInfo();
        $code->pCode = file_get_contents(__DIR__ . '/Fixtures/' . $file);
        $code->codeSize = strlen($code->pCode);
        vkCreateShaderModule($device, $code, 0, $module) === VK_SUCCESS || throw new RuntimeException("vkCreateShaderModule {$file}");
        $s = new VkPipelineShaderStageCreateInfo();
        $s->stage = $bit;
        $s->module = $module;
        $s->pName = 'main';

        return $s;
    };
    $assembly = new VkPipelineInputAssemblyStateCreateInfo();
    $assembly->topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
    $viewport = new VkPipelineViewportStateCreateInfo();
    $viewport->viewportCount = 1;
    $viewport->scissorCount = 1;
    $raster = new VkPipelineRasterizationStateCreateInfo();
    $raster->polygonMode = VK_POLYGON_MODE_FILL;
    $raster->cullMode = VK_CULL_MODE_NONE;
    $raster->frontFace = VK_FRONT_FACE_COUNTER_CLOCKWISE;
    $raster->lineWidth = 1.0;
    $multisample = new VkPipelineMultisampleStateCreateInfo();
    $multisample->rasterizationSamples = $rasterizationSamples;
    $blendAttachment = new VkPipelineColorBlendAttachmentState();
    $blendAttachment->colorWriteMask = VK_COLOR_COMPONENT_R_BIT | VK_COLOR_COMPONENT_G_BIT | VK_COLOR_COMPONENT_B_BIT | VK_COLOR_COMPONENT_A_BIT;
    $blend = new VkPipelineColorBlendStateCreateInfo();
    $blend->attachmentCount = 1;
    $blend->pAttachments = [$blendAttachment];
    $dynamic = new VkPipelineDynamicStateCreateInfo();
    $dynamic->dynamicStateCount = 2;
    $dynamic->pDynamicStates = [VK_DYNAMIC_STATE_VIEWPORT, VK_DYNAMIC_STATE_SCISSOR];
    $pipelineInfo = new VkGraphicsPipelineCreateInfo();
    $pipelineInfo->stageCount = 2;
    $pipelineInfo->pStages = [$stage(VK_SHADER_STAGE_VERTEX_BIT, 'triangle.vert.spv'), $stage(VK_SHADER_STAGE_FRAGMENT_BIT, 'triangle.frag.spv')];
    $pipelineInfo->pVertexInputState = new VkPipelineVertexInputStateCreateInfo();
    $pipelineInfo->pInputAssemblyState = $assembly;
    $pipelineInfo->pViewportState = $viewport;
    $pipelineInfo->pRasterizationState = $raster;
    $pipelineInfo->pMultisampleState = $multisample;
    $pipelineInfo->pColorBlendState = $blend;
    $pipelineInfo->pDynamicState = $dynamic;
    $pipelineInfo->layout = $layout;
    $pipelineInfo->renderPass = $pass;
    vkCreateGraphicsPipelines($device, 0, 1, [$pipelineInfo], 0, $pipelines) === VK_SUCCESS || throw new RuntimeException('vkCreateGraphicsPipelines');

    $begin = new VkRenderPassBeginInfo();
    $begin->renderPass = $pass;
    $begin->framebuffer = $framebuffer;
    [$begin->renderArea->extent->width, $begin->renderArea->extent->height] = [MSRTSS_SIZE, MSRTSS_SIZE];
    $port = new VkViewport();
    [$port->width, $port->height, $port->maxDepth] = [(float) MSRTSS_SIZE, (float) MSRTSS_SIZE, 1.0];
    $scissor = new VkRect2D();
    [$scissor->extent->width, $scissor->extent->height] = [MSRTSS_SIZE, MSRTSS_SIZE];

    $cmd = commandsOn($device, $family);
    vkCmdBeginRenderPass($cmd, $begin, VK_SUBPASS_CONTENTS_INLINE);
    vkCmdBindPipeline($cmd, VK_PIPELINE_BIND_POINT_GRAPHICS, $pipelines[0]);
    vkCmdSetViewport($cmd, 0, 1, [$port]);
    vkCmdSetScissor($cmd, 0, 1, [$scissor]);
    vkCmdDraw($cmd, 3, 1, 0, 0);
    vkCmdEndRenderPass($cmd);
    submitAndWaitOn($device, $queue, $cmd);

    $out = new VkImageToMemoryCopy();
    $out->pHostPointer = str_repeat("\0", MSRTSS_SIZE * MSRTSS_SIZE * 4);
    $out->imageSubresource->aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
    $out->imageSubresource->layerCount = 1;
    [$out->imageExtent->width, $out->imageExtent->height, $out->imageExtent->depth] = [MSRTSS_SIZE, MSRTSS_SIZE, 1];
    $copy = new VkCopyImageToMemoryInfo();
    $copy->srcImage = $image;
    $copy->srcImageLayout = VK_IMAGE_LAYOUT_GENERAL;
    $copy->regionCount = 1;
    $copy->pRegions = [$out];
    vkCopyImageToMemory($device, $copy) === VK_SUCCESS || throw new RuntimeException('vkCopyImageToMemory');

    return $out->pHostPointer;
}

function msrtssPixel(string $pixels, int $x, int $y): string
{
    return substr($pixels, ($y * MSRTSS_SIZE + $x) * 4, 4);
}

/** Pixels that are neither the loaded blue nor the triangle's green. */
function msrtssPartial(string $pixels): int
{
    $partial = 0;
    foreach (str_split($pixels, 4) as $pixel) {
        $partial += $pixel !== MSRTSS_BLUE && $pixel !== MSRTSS_GREEN ? 1 : 0;
    }

    return $partial;
}

it('reports the multisampledRenderToSingleSampled feature from vkGetPhysicalDeviceFeatures2', function (): void {
    [, $physical] = msrtssOrSkip();
    $feature = new VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT();
    $features = new VkPhysicalDeviceFeatures2();
    $features->pNext = $feature;
    vkGetPhysicalDeviceFeatures2($physical, $features);

    expect($feature->multisampledRenderToSingleSampled)->toBeTrue();
});

it('antialiases a triangle over the loaded single-sampled image with 4 samples', function (): void {
    $pixels = msrtssRender(VK_SAMPLE_COUNT_4_BIT);

    expect(msrtssPixel($pixels, 8, 8))->toBe(MSRTSS_GREEN)
        ->and(msrtssPixel($pixels, 0, 0))->toBe(MSRTSS_BLUE)
        ->and(msrtssPixel($pixels, 15, 15))->toBe(MSRTSS_BLUE)
        ->and(msrtssPartial($pixels))->toBeGreaterThan(0);
});

it('antialiases the same way on a LINEAR-tiled image', function (): void {
    $pixels = msrtssRender(VK_SAMPLE_COUNT_4_BIT, VK_IMAGE_TILING_LINEAR);

    expect(msrtssPixel($pixels, 8, 8))->toBe(MSRTSS_GREEN)
        ->and(msrtssPixel($pixels, 0, 0))->toBe(MSRTSS_BLUE)
        ->and(msrtssPartial($pixels))->toBeGreaterThan(0);
});

it('lists the multisampled-render-to-single-sampled image as supported for RGBA8 and BGRA8, LINEAR and OPTIMAL', function (): void {
    [, $physical] = msrtssOrSkip();
    $usage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_TRANSFER_SRC_BIT;

    foreach ([VK_FORMAT_R8G8B8A8_UNORM, VK_FORMAT_B8G8R8A8_UNORM] as $format) {
        $result = vkGetPhysicalDeviceImageFormatProperties($physical, $format, VK_IMAGE_TYPE_2D, VK_IMAGE_TILING_OPTIMAL, $usage, VK_IMAGE_CREATE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_BIT_EXT, $optimal);
        expect($result)->toBe(VK_SUCCESS)
            ->and($optimal->sampleCounts & VK_SAMPLE_COUNT_4_BIT)->toBe(VK_SAMPLE_COUNT_4_BIT);

        $result = vkGetPhysicalDeviceImageFormatProperties($physical, $format, VK_IMAGE_TYPE_2D, VK_IMAGE_TILING_LINEAR, $usage, VK_IMAGE_CREATE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_BIT_EXT, $linear);
        expect($result)->toBe(VK_SUCCESS)
            ->and($linear->sampleCounts)->toBe(VK_SAMPLE_COUNT_1_BIT);
    }
});

it('leaves no partial pixels with 1 sample per pixel', function (): void {
    $pixels = msrtssRender(VK_SAMPLE_COUNT_1_BIT);

    expect(msrtssPixel($pixels, 8, 8))->toBe(MSRTSS_GREEN)
        ->and(msrtssPixel($pixels, 0, 0))->toBe(MSRTSS_BLUE)
        ->and(msrtssPartial($pixels))->toBe(0);
});
