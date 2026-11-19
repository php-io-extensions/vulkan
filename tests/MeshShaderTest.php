<?php

declare(strict_types=1);

/*
 * VK_EXT_mesh_shader. MoltenVK does not list it; on this Mac only lavapipe (Mesa, a CPU device) does, so these tests
 * are the exception to "device tests skip the CPU device": they open the first device that lists the extension,
 * on its own instance and device, and skip when none does.
 */

const MESH_SIZE = 16;

/**
 * @return array{VkInstance, VkPhysicalDevice, VkDevice, VkQueue, int}|null instance, the first device listing VK_EXT_mesh_shader, a device made with meshShader (and hostImageCopy), its graphics queue, the family; null where no device lists it
 */
function meshDevice(): ?array
{
    static $made = false, $mesh = null;
    if ($made) {
        return $mesh;
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
        if (in_array('VK_EXT_mesh_shader', $names, true)) {
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
    $mesh = new VkPhysicalDeviceMeshShaderFeaturesEXT();
    $mesh->meshShader = true;
    $mesh->pNext = $hostCopy;
    $info = new VkDeviceCreateInfo();
    $info->queueCreateInfoCount = 1;
    $info->pQueueCreateInfos = [$queueInfo];
    $info->pNext = $mesh;
    $extensions = ['VK_EXT_mesh_shader'];
    if (in_array('VK_KHR_draw_indirect_count', $names, true)) {
        $extensions[] = 'VK_KHR_draw_indirect_count';
    }
    $info->ppEnabledExtensionNames = $extensions;
    $info->enabledExtensionCount = count($extensions);
    vkCreateDevice($physical, $info, 0, $device) === VK_SUCCESS || throw new RuntimeException('vkCreateDevice');
    vkGetDeviceQueue($device, $family, 0, $queue);

    return $mesh = [$instance, $physical, $device, $queue, $family];
}

function meshOrSkip(): array
{
    return meshDevice() ?? test()->markTestSkipped('no Vulkan device lists VK_EXT_mesh_shader');
}

function meshMemoryType(int $typeBits, int $properties): int
{
    [, $physical] = meshOrSkip();
    vkGetPhysicalDeviceMemoryProperties($physical, $memory);
    foreach ($memory->memoryTypes as $index => $type) {
        if (($typeBits & (1 << $index)) !== 0 && ($type->propertyFlags & $properties) === $properties) {
            return $index;
        }
    }

    throw new RuntimeException('no matching memory type');
}

/** A buffer holding $bytes, written by vkCmdUpdateBuffer, readable as an indirect buffer. */
function meshIndirectBuffer(VkCommandBuffer $cmd, string $bytes): VkBuffer
{
    [, , $device] = meshOrSkip();
    $info = new VkBufferCreateInfo();
    $info->size = strlen($bytes);
    $info->usage = VK_BUFFER_USAGE_INDIRECT_BUFFER_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT;
    vkCreateBuffer($device, $info, 0, $buffer) === VK_SUCCESS || throw new RuntimeException('vkCreateBuffer');
    vkGetBufferMemoryRequirements($device, $buffer, $requirements);
    $allocate = new VkMemoryAllocateInfo();
    $allocate->allocationSize = $requirements->size;
    $allocate->memoryTypeIndex = meshMemoryType($requirements->memoryTypeBits, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT);
    vkAllocateMemory($device, $allocate, 0, $memory) === VK_SUCCESS || throw new RuntimeException('vkAllocateMemory');
    vkBindBufferMemory($device, $buffer, $memory, 0) === VK_SUCCESS || throw new RuntimeException('vkBindBufferMemory');
    vkCmdUpdateBuffer($cmd, $buffer, 0, strlen($bytes), $bytes);

    return $buffer;
}

/** Makes the vkCmdUpdateBuffer writes visible to the indirect reads. */
function meshIndirectBarrier(VkCommandBuffer $cmd): void
{
    $barrier = new VkMemoryBarrier();
    $barrier->srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
    $barrier->dstAccessMask = VK_ACCESS_INDIRECT_COMMAND_READ_BIT;
    vkCmdPipelineBarrier($cmd, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_DRAW_INDIRECT_BIT, 0, 1, [$barrier], 0, [], 0, []);
}

/**
 * Draws the one-triangle mesh shader into a 16 x 16 image cleared to opaque black, through $draw(command buffer),
 * and returns the pixels, rows top-down, read by the host.
 *
 * @param  Closure(VkCommandBuffer): void  $draw  records the draw inside the render pass, with the pipeline bound
 * @param  Closure(VkCommandBuffer): void|null  $prepare  records what the draw reads, before the render pass
 */
function meshRender(Closure $draw, ?Closure $prepare = null): string
{
    [, , $device, $queue, $family] = meshOrSkip();

    $imageInfo = new VkImageCreateInfo();
    $imageInfo->imageType = VK_IMAGE_TYPE_2D;
    $imageInfo->format = VK_FORMAT_R8G8B8A8_UNORM;
    [$imageInfo->extent->width, $imageInfo->extent->height, $imageInfo->extent->depth] = [MESH_SIZE, MESH_SIZE, 1];
    $imageInfo->mipLevels = 1;
    $imageInfo->arrayLayers = 1;
    $imageInfo->samples = VK_SAMPLE_COUNT_1_BIT;
    $imageInfo->tiling = VK_IMAGE_TILING_OPTIMAL;
    $imageInfo->usage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT | VK_IMAGE_USAGE_HOST_TRANSFER_BIT;
    vkCreateImage($device, $imageInfo, 0, $image) === VK_SUCCESS || throw new RuntimeException('vkCreateImage');
    vkGetImageMemoryRequirements($device, $image, $requirements);
    $allocate = new VkMemoryAllocateInfo();
    $allocate->allocationSize = $requirements->size;
    $allocate->memoryTypeIndex = meshMemoryType($requirements->memoryTypeBits, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
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

    $viewInfo = new VkImageViewCreateInfo();
    $viewInfo->image = $image;
    $viewInfo->viewType = VK_IMAGE_VIEW_TYPE_2D;
    $viewInfo->format = VK_FORMAT_R8G8B8A8_UNORM;
    $viewInfo->subresourceRange = $range;
    vkCreateImageView($device, $viewInfo, 0, $view) === VK_SUCCESS || throw new RuntimeException('vkCreateImageView');

    $attachment = new VkAttachmentDescription();
    $attachment->format = VK_FORMAT_R8G8B8A8_UNORM;
    $attachment->samples = VK_SAMPLE_COUNT_1_BIT;
    $attachment->loadOp = VK_ATTACHMENT_LOAD_OP_CLEAR;
    $attachment->storeOp = VK_ATTACHMENT_STORE_OP_STORE;
    $attachment->stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
    $attachment->stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
    $attachment->initialLayout = VK_IMAGE_LAYOUT_GENERAL;
    $attachment->finalLayout = VK_IMAGE_LAYOUT_GENERAL;
    $reference = new VkAttachmentReference();
    $reference->attachment = 0;
    $reference->layout = VK_IMAGE_LAYOUT_GENERAL;
    $subpass = new VkSubpassDescription();
    $subpass->pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;
    $subpass->colorAttachmentCount = 1;
    $subpass->pColorAttachments = [$reference];
    $passInfo = new VkRenderPassCreateInfo();
    $passInfo->attachmentCount = 1;
    $passInfo->pAttachments = [$attachment];
    $passInfo->subpassCount = 1;
    $passInfo->pSubpasses = [$subpass];
    vkCreateRenderPass($device, $passInfo, 0, $pass) === VK_SUCCESS || throw new RuntimeException('vkCreateRenderPass');

    $framebufferInfo = new VkFramebufferCreateInfo();
    $framebufferInfo->renderPass = $pass;
    $framebufferInfo->attachmentCount = 1;
    $framebufferInfo->pAttachments = [$view];
    [$framebufferInfo->width, $framebufferInfo->height, $framebufferInfo->layers] = [MESH_SIZE, MESH_SIZE, 1];
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
    $viewport = new VkPipelineViewportStateCreateInfo();
    $viewport->viewportCount = 1;
    $viewport->scissorCount = 1;
    $raster = new VkPipelineRasterizationStateCreateInfo();
    $raster->polygonMode = VK_POLYGON_MODE_FILL;
    $raster->cullMode = VK_CULL_MODE_NONE;
    $raster->frontFace = VK_FRONT_FACE_COUNTER_CLOCKWISE;
    $raster->lineWidth = 1.0;
    $multisample = new VkPipelineMultisampleStateCreateInfo();
    $multisample->rasterizationSamples = VK_SAMPLE_COUNT_1_BIT;
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
    $pipelineInfo->pStages = [$stage(VK_SHADER_STAGE_MESH_BIT_EXT, 'triangle.mesh.spv'), $stage(VK_SHADER_STAGE_FRAGMENT_BIT, 'triangle.frag.spv')];
    $pipelineInfo->pViewportState = $viewport;
    $pipelineInfo->pRasterizationState = $raster;
    $pipelineInfo->pMultisampleState = $multisample;
    $pipelineInfo->pColorBlendState = $blend;
    $pipelineInfo->pDynamicState = $dynamic;
    $pipelineInfo->layout = $layout;
    $pipelineInfo->renderPass = $pass;
    vkCreateGraphicsPipelines($device, 0, 1, [$pipelineInfo], 0, $pipelines) === VK_SUCCESS || throw new RuntimeException('vkCreateGraphicsPipelines');

    $black = new VkClearValue();
    $black->color = new VkClearColorValue();
    $black->color->float32 = [0.0, 0.0, 0.0, 1.0];
    $begin = new VkRenderPassBeginInfo();
    $begin->renderPass = $pass;
    $begin->framebuffer = $framebuffer;
    [$begin->renderArea->extent->width, $begin->renderArea->extent->height] = [MESH_SIZE, MESH_SIZE];
    $begin->clearValueCount = 1;
    $begin->pClearValues = [$black];
    $port = new VkViewport();
    [$port->width, $port->height, $port->maxDepth] = [(float) MESH_SIZE, (float) MESH_SIZE, 1.0];
    $scissor = new VkRect2D();
    [$scissor->extent->width, $scissor->extent->height] = [MESH_SIZE, MESH_SIZE];

    $cmd = commandsOn($device, $family);
    $prepare?->__invoke($cmd);
    vkCmdBeginRenderPass($cmd, $begin, VK_SUBPASS_CONTENTS_INLINE);
    vkCmdBindPipeline($cmd, VK_PIPELINE_BIND_POINT_GRAPHICS, $pipelines[0]);
    vkCmdSetViewport($cmd, 0, 1, [$port]);
    vkCmdSetScissor($cmd, 0, 1, [$scissor]);
    $draw($cmd);
    vkCmdEndRenderPass($cmd);
    submitAndWaitOn($device, $queue, $cmd);

    $region = new VkImageToMemoryCopy();
    $region->pHostPointer = str_repeat("\0", MESH_SIZE * MESH_SIZE * 4);
    $region->imageSubresource->aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
    $region->imageSubresource->layerCount = 1;
    [$region->imageExtent->width, $region->imageExtent->height, $region->imageExtent->depth] = [MESH_SIZE, MESH_SIZE, 1];
    $copy = new VkCopyImageToMemoryInfo();
    $copy->srcImage = $image;
    $copy->srcImageLayout = VK_IMAGE_LAYOUT_GENERAL;
    $copy->regionCount = 1;
    $copy->pRegions = [$region];
    vkCopyImageToMemory($device, $copy) === VK_SUCCESS || throw new RuntimeException('vkCopyImageToMemory');

    return $region->pHostPointer;
}

function meshPixel(string $pixels, int $x, int $y): string
{
    return substr($pixels, ($y * MESH_SIZE + $x) * 4, 4);
}

const MESH_GREEN = "\x00\xFF\x00\xFF";
const MESH_BLACK = "\x00\x00\x00\xFF";

it('draws the mesh shader triangle with vkCmdDrawMeshTasksEXT', function (): void {
    $pixels = meshRender(fn (VkCommandBuffer $cmd) => vkCmdDrawMeshTasksEXT($cmd, 1, 1, 1));

    expect(meshPixel($pixels, 8, 8))->toBe(MESH_GREEN)
        ->and(meshPixel($pixels, 0, 0))->toBe(MESH_BLACK)
        ->and(meshPixel($pixels, 15, 15))->toBe(MESH_BLACK);
});

it('draws nothing when the group counts are zero', function (): void {
    $pixels = meshRender(fn (VkCommandBuffer $cmd) => vkCmdDrawMeshTasksEXT($cmd, 0, 1, 1));

    expect(meshPixel($pixels, 8, 8))->toBe(MESH_BLACK);
});

it('draws the triangle from group counts in a buffer with vkCmdDrawMeshTasksIndirectEXT', function (): void {
    $buffer = null;
    $pixels = meshRender(
        function (VkCommandBuffer $cmd) use (&$buffer): void {
            vkCmdDrawMeshTasksIndirectEXT($cmd, $buffer, 0, 1, 12);
        },
        function (VkCommandBuffer $cmd) use (&$buffer): void {
            $buffer = meshIndirectBuffer($cmd, pack('V3', 1, 1, 1));
            meshIndirectBarrier($cmd);
        },
    );

    expect(meshPixel($pixels, 8, 8))->toBe(MESH_GREEN)
        ->and(meshPixel($pixels, 0, 0))->toBe(MESH_BLACK);
});

it('draws nothing from an indirect buffer holding no groups, and reads the offset', function (): void {
    $buffer = null;
    $pixels = meshRender(
        function (VkCommandBuffer $cmd) use (&$buffer): void {
            vkCmdDrawMeshTasksIndirectEXT($cmd, $buffer, 12, 1, 12);
        },
        function (VkCommandBuffer $cmd) use (&$buffer): void {
            $buffer = meshIndirectBuffer($cmd, pack('V6', 1, 1, 1, 0, 0, 0));
            meshIndirectBarrier($cmd);
        },
    );

    expect(meshPixel($pixels, 8, 8))->toBe(MESH_BLACK);
});

it('draws the triangle with the draw count read from a buffer, vkCmdDrawMeshTasksIndirectCountEXT', function (): void {
    $arguments = $counter = null;
    $pixels = meshRender(
        function (VkCommandBuffer $cmd) use (&$arguments, &$counter): void {
            vkCmdDrawMeshTasksIndirectCountEXT($cmd, $arguments, 0, $counter, 0, 1, 12);
        },
        function (VkCommandBuffer $cmd) use (&$arguments, &$counter): void {
            $arguments = meshIndirectBuffer($cmd, pack('V3', 1, 1, 1));
            $counter = meshIndirectBuffer($cmd, pack('V', 1));
            meshIndirectBarrier($cmd);
        },
    );

    expect(meshPixel($pixels, 8, 8))->toBe(MESH_GREEN)
        ->and(meshPixel($pixels, 0, 0))->toBe(MESH_BLACK);
});

it('draws nothing when the count buffer says zero draws', function (): void {
    $arguments = $counter = null;
    $pixels = meshRender(
        function (VkCommandBuffer $cmd) use (&$arguments, &$counter): void {
            vkCmdDrawMeshTasksIndirectCountEXT($cmd, $arguments, 0, $counter, 0, 1, 12);
        },
        function (VkCommandBuffer $cmd) use (&$arguments, &$counter): void {
            $arguments = meshIndirectBuffer($cmd, pack('V3', 1, 1, 1));
            $counter = meshIndirectBuffer($cmd, pack('V', 0));
            meshIndirectBarrier($cmd);
        },
    );

    expect(meshPixel($pixels, 8, 8))->toBe(MESH_BLACK);
});

it('reports meshShader on a device that lists the extension, through the chain', function (): void {
    [, $physical] = meshOrSkip();
    $mesh = new VkPhysicalDeviceMeshShaderFeaturesEXT();
    $features = new VkPhysicalDeviceFeatures2();
    $features->pNext = $mesh;

    vkGetPhysicalDeviceFeatures2($physical, $features);

    expect($mesh->meshShader)->toBeTrue()
        ->and($features->pNext)->toBe($mesh);
});

it('fills the mesh shader limits chained on VkPhysicalDeviceProperties2', function (): void {
    [, $physical] = meshOrSkip();
    $mesh = new VkPhysicalDeviceMeshShaderPropertiesEXT();
    $properties = new VkPhysicalDeviceProperties2();
    $properties->pNext = $mesh;

    vkGetPhysicalDeviceProperties2($physical, $properties);

    expect($properties->pNext)->toBe($mesh)
        ->and($mesh->maxMeshOutputVertices)->toBeGreaterThan(0)
        ->and($mesh->maxMeshOutputPrimitives)->toBeGreaterThan(0)
        ->and($mesh->maxMeshWorkGroupInvocations)->toBeGreaterThan(0)
        ->and($mesh->maxTaskWorkGroupCount)->toHaveCount(3)
        ->and($mesh->maxTaskWorkGroupCount[0])->toBeGreaterThan(0)
        ->and($mesh->maxMeshWorkGroupSize)->toHaveCount(3)
        ->and($mesh->maxMeshWorkGroupSize[0])->toBeGreaterThan(0)
        ->and($properties->properties->deviceName)->not->toBe('');
});

it('leaves the mesh features at what the caller set where nothing fills them', function (): void {
    // MoltenVK lists no VK_EXT_mesh_shader: the struct stays as the caller left it
    [, $physical] = gpu();
    vkEnumerateDeviceExtensionProperties($physical, null, $count, null);
    vkEnumerateDeviceExtensionProperties($physical, null, $count, $available);
    if (in_array('VK_EXT_mesh_shader', array_map(fn (VkExtensionProperties $e): string => $e->extensionName, $available), true)) {
        test()->markTestSkipped('the shared device lists VK_EXT_mesh_shader');
    }
    $mesh = new VkPhysicalDeviceMeshShaderFeaturesEXT();
    $mesh->taskShader = true;
    $features = new VkPhysicalDeviceFeatures2();
    $features->pNext = $mesh;

    vkGetPhysicalDeviceFeatures2($physical, $features);

    expect($mesh->taskShader)->toBeTrue()
        ->and($mesh->meshShader)->toBeFalse();
});

it('returns the same features from vkGetPhysicalDeviceFeatures as from vkGetPhysicalDeviceFeatures2', function (): void {
    [, $physical] = gpu();
    $two = new VkPhysicalDeviceFeatures2();
    vkGetPhysicalDeviceFeatures2($physical, $two);

    vkGetPhysicalDeviceFeatures($physical, $one);

    expect($one)->toBeInstanceOf(VkPhysicalDeviceFeatures::class)
        ->and(get_object_vars($one))->toBe(get_object_vars($two->features))
        ->and(in_array(true, get_object_vars($one), true))->toBeTrue();
});
