<?php

declare(strict_types=1);

if (! extension_loaded('vulkan')) {
    throw new RuntimeException('The vulkan extension is not loaded; run ./install-macos.sh or ./install-debian-trixie.sh');
}

function tap(object $object, Closure $callback): object
{
    $callback($object);

    return $object;
}

/** An instance create info with the extensions asked for, plus portability enumeration where the loader lists it. */
function portabilityInstance(array $extensions = []): VkInstanceCreateInfo
{
    $app = new VkApplicationInfo();
    $app->pApplicationName = 'ext-vulkan tests';
    $app->apiVersion = VK_API_VERSION_1_3;
    $info = new VkInstanceCreateInfo();
    $info->pApplicationInfo = $app;

    vkEnumerateInstanceExtensionProperties(null, $available);
    $names = array_map(fn (VkExtensionProperties $e): string => $e->extensionName, $available);
    if (in_array(VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME, $names, true)) {
        $extensions[] = VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME;
        $info->flags |= VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR;
    }
    $info->enabledExtensionNames = array_values(array_unique($extensions));

    return $info;
}

/** The device create info with VK_KHR_portability_subset added where the device lists it. */
function portabilityDevice(VkPhysicalDevice $physical, VkDeviceCreateInfo $info): VkDeviceCreateInfo
{
    vkEnumerateDeviceExtensionProperties($physical, null, $available);
    $names = array_map(fn (VkExtensionProperties $e): string => $e->extensionName, $available);
    if (in_array(VK_KHR_PORTABILITY_SUBSET_EXTENSION_NAME, $names, true)) {
        $info->enabledExtensionNames = array_values(array_unique([...$info->enabledExtensionNames, VK_KHR_PORTABILITY_SUBSET_EXTENSION_NAME]));
    }

    return $info;
}

/** @return array{VkInstance, VkPhysicalDevice, VkDevice, VkQueue, int}|null instance, the GPU (never the CPU device), a device with one graphics queue, that queue, its family; null where no GPU is visible */
function vulkan(): ?array
{
    static $made = false, $vulkan = null;
    if ($made) {
        return $vulkan;
    }
    $made = true;

    $create = portabilityInstance();
    if (vkCreateInstance($create, null, $instance) !== VK_SUCCESS) {
        return null;
    }

    vkEnumeratePhysicalDevices($instance, $devices);
    foreach ($devices as $candidate) {
        vkGetPhysicalDeviceProperties($candidate, $properties);
        if ($properties->deviceType !== VK_PHYSICAL_DEVICE_TYPE_CPU) {
            $physical = $candidate;
            break;
        }
    }
    if (! isset($physical)) {
        return null;
    }

    vkGetPhysicalDeviceQueueFamilyProperties($physical, $families);
    $family = array_key_first(array_filter($families, fn (VkQueueFamilyProperties $f): bool => ($f->queueFlags & VK_QUEUE_GRAPHICS_BIT) !== 0));
    $queueInfo = new VkDeviceQueueCreateInfo();
    $queueInfo->queueFamilyIndex = $family;
    $queueInfo->pQueuePriorities = [1.0];
    $deviceInfo = new VkDeviceCreateInfo();
    $deviceInfo->pQueueCreateInfos = [$queueInfo];
    vkCreateDevice($physical, portabilityDevice($physical, $deviceInfo), null, $device) === VK_SUCCESS || throw new RuntimeException('vkCreateDevice');
    vkGetDeviceQueue($device, $family, 0, $queue);

    return $vulkan = [$instance, $physical, $device, $queue, $family];
}

/** The Vulkan objects, or the test skipped where the platform has no GPU device this slice can open. */
function gpu(): array
{
    return vulkan() ?? test()->markTestSkipped('no Vulkan GPU');
}

/** First memory type whose index is set in $typeBits and whose flags include every bit of $properties. */
function memoryType(int $typeBits, int $properties): int
{
    [, $physical] = gpu();
    vkGetPhysicalDeviceMemoryProperties($physical, $memory);
    foreach ($memory->memoryTypes as $index => $type) {
        if (($typeBits & (1 << $index)) !== 0 && ($type->propertyFlags & $properties) === $properties) {
            return $index;
        }
    }

    throw new RuntimeException('no matching memory type');
}

/** @return array{VkBuffer, VkDeviceMemory} */
function hostBuffer(int $size, int $usage): array
{
    [, , $device] = gpu();
    $info = new VkBufferCreateInfo();
    $info->size = $size;
    $info->usage = $usage;
    vkCreateBuffer($device, $info, null, $buffer) === VK_SUCCESS || throw new RuntimeException('vkCreateBuffer');
    vkGetBufferMemoryRequirements($device, $buffer, $requirements);
    $allocate = new VkMemoryAllocateInfo();
    $allocate->allocationSize = $requirements->size;
    $allocate->memoryTypeIndex = memoryType($requirements->memoryTypeBits, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT);
    vkAllocateMemory($device, $allocate, null, $memory) === VK_SUCCESS || throw new RuntimeException('vkAllocateMemory');
    vkBindBufferMemory($device, $buffer, $memory, 0) === VK_SUCCESS || throw new RuntimeException('vkBindBufferMemory');

    return [$buffer, $memory];
}

/** @return array{VkImage, VkDeviceMemory} */
function image2D(int $format, int $w, int $h, int $usage, int $samples = VK_SAMPLE_COUNT_1_BIT): array
{
    [, , $device] = gpu();
    $info = new VkImageCreateInfo();
    $info->imageType = VK_IMAGE_TYPE_2D;
    $info->format = $format;
    $info->extent->width = $w;
    $info->extent->height = $h;
    $info->extent->depth = 1;
    $info->mipLevels = 1;
    $info->arrayLayers = 1;
    $info->samples = $samples;
    $info->tiling = VK_IMAGE_TILING_OPTIMAL;
    $info->usage = $usage;
    vkCreateImage($device, $info, null, $image) === VK_SUCCESS || throw new RuntimeException('vkCreateImage');
    vkGetImageMemoryRequirements($device, $image, $requirements);
    $allocate = new VkMemoryAllocateInfo();
    $allocate->allocationSize = $requirements->size;
    $allocate->memoryTypeIndex = memoryType($requirements->memoryTypeBits, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
    vkAllocateMemory($device, $allocate, null, $memory) === VK_SUCCESS || throw new RuntimeException('vkAllocateMemory');
    vkBindImageMemory($device, $image, $memory, 0) === VK_SUCCESS || throw new RuntimeException('vkBindImageMemory');

    return [$image, $memory];
}

function view2D(VkImage $image, int $format, int $aspect): VkImageView
{
    [, , $device] = gpu();
    $info = new VkImageViewCreateInfo();
    $info->image = $image;
    $info->viewType = VK_IMAGE_VIEW_TYPE_2D;
    $info->format = $format;
    $info->subresourceRange->aspectMask = $aspect;
    $info->subresourceRange->levelCount = 1;
    $info->subresourceRange->layerCount = 1;
    vkCreateImageView($device, $info, null, $view) === VK_SUCCESS || throw new RuntimeException('vkCreateImageView');

    return $view;
}

function stencilFormat(): int
{
    [, $physical] = gpu();
    foreach ([VK_FORMAT_D24_UNORM_S8_UINT, VK_FORMAT_D32_SFLOAT_S8_UINT] as $format) {
        vkGetPhysicalDeviceFormatProperties($physical, $format, $properties);
        if (($properties->optimalTilingFeatures & VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT) !== 0) {
            return $format;
        }
    }

    throw new RuntimeException('no stencil format');
}

/** Attachment 0: 4x colour, cleared, DONT_CARE stored; 1: 4x depth-stencil, cleared; 2: the single-sample resolve, ending TRANSFER_SRC_OPTIMAL. One subpass resolving 0 into 2. */
function msaaRenderPass(): VkRenderPass
{
    [, , $device] = gpu();
    $color = new VkAttachmentDescription();
    $color->format = VK_FORMAT_R8G8B8A8_UNORM;
    $color->samples = VK_SAMPLE_COUNT_4_BIT;
    $color->loadOp = VK_ATTACHMENT_LOAD_OP_CLEAR;
    $color->storeOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
    $color->stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
    $color->stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
    $color->initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
    $color->finalLayout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
    $stencil = new VkAttachmentDescription();
    $stencil->format = stencilFormat();
    $stencil->samples = VK_SAMPLE_COUNT_4_BIT;
    $stencil->loadOp = VK_ATTACHMENT_LOAD_OP_CLEAR;
    $stencil->storeOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
    $stencil->stencilLoadOp = VK_ATTACHMENT_LOAD_OP_CLEAR;
    $stencil->stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
    $stencil->initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
    $stencil->finalLayout = VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL;
    $resolve = new VkAttachmentDescription();
    $resolve->format = VK_FORMAT_R8G8B8A8_UNORM;
    $resolve->samples = VK_SAMPLE_COUNT_1_BIT;
    $resolve->loadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
    $resolve->storeOp = VK_ATTACHMENT_STORE_OP_STORE;
    $resolve->stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
    $resolve->stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
    $resolve->initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
    $resolve->finalLayout = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;

    $reference = fn (int $attachment, int $layout): VkAttachmentReference => tap(new VkAttachmentReference(), function (VkAttachmentReference $r) use ($attachment, $layout): void {
        $r->attachment = $attachment;
        $r->layout = $layout;
    });
    $subpass = new VkSubpassDescription();
    $subpass->pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;
    $subpass->pColorAttachments = [$reference(0, VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL)];
    $subpass->pResolveAttachments = [$reference(2, VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL)];
    $subpass->pDepthStencilAttachment = $reference(1, VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL);

    $dependency = new VkSubpassDependency();
    $dependency->srcSubpass = 0;
    $dependency->dstSubpass = VK_SUBPASS_EXTERNAL;
    $dependency->srcStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
    $dependency->dstStageMask = VK_PIPELINE_STAGE_TRANSFER_BIT;
    $dependency->srcAccessMask = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;
    $dependency->dstAccessMask = VK_ACCESS_TRANSFER_READ_BIT;

    $info = new VkRenderPassCreateInfo();
    $info->pAttachments = [$color, $stencil, $resolve];
    $info->pSubpasses = [$subpass];
    $info->pDependencies = [$dependency];
    vkCreateRenderPass($device, $info, null, $pass) === VK_SUCCESS || throw new RuntimeException('vkCreateRenderPass');

    return $pass;
}

function shaderModule(string $file): VkShaderModule
{
    [, , $device] = gpu();
    $info = new VkShaderModuleCreateInfo();
    $info->code = file_get_contents(__DIR__ . '/Fixtures/' . $file);
    vkCreateShaderModule($device, $info, null, $module) === VK_SUCCESS || throw new RuntimeException("vkCreateShaderModule {$file}");

    return $module;
}

/** The fragment push-constant layout: one vec4. */
function flatLayout(): VkPipelineLayout
{
    [, , $device] = gpu();
    $range = new VkPushConstantRange();
    $range->stageFlags = VK_SHADER_STAGE_FRAGMENT_BIT;
    $range->size = 16;
    $info = new VkPipelineLayoutCreateInfo();
    $info->pPushConstantRanges = [$range];
    vkCreatePipelineLayout($device, $info, null, $layout) === VK_SUCCESS || throw new RuntimeException('vkCreatePipelineLayout');

    return $layout;
}

/** A flat pipeline at 4x with a stencil test (compare, pass op on both faces), colour written or not, viewport and scissor dynamic. */
function flatPipeline(VkRenderPass $pass, VkPipelineLayout $layout, bool $writeColor, int $compare, int $passOp): VkPipeline
{
    [, , $device] = gpu();
    $stage = function (int $bit, string $file): VkPipelineShaderStageCreateInfo {
        $s = new VkPipelineShaderStageCreateInfo();
        $s->stage = $bit;
        $s->module = shaderModule($file);
        $s->pName = 'main';

        return $s;
    };

    $binding = new VkVertexInputBindingDescription();
    $binding->stride = 8;
    $binding->inputRate = VK_VERTEX_INPUT_RATE_VERTEX;
    $attribute = new VkVertexInputAttributeDescription();
    $attribute->format = VK_FORMAT_R32G32_SFLOAT;
    $vertexInput = new VkPipelineVertexInputStateCreateInfo();
    $vertexInput->pVertexBindingDescriptions = [$binding];
    $vertexInput->pVertexAttributeDescriptions = [$attribute];

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
    $multisample->rasterizationSamples = VK_SAMPLE_COUNT_4_BIT;

    $depthStencil = new VkPipelineDepthStencilStateCreateInfo();
    $depthStencil->stencilTestEnable = VK_TRUE;
    foreach ([$depthStencil->front, $depthStencil->back] as $face) {
        $face->failOp = VK_STENCIL_OP_KEEP;
        $face->passOp = $passOp;
        $face->depthFailOp = VK_STENCIL_OP_KEEP;
        $face->compareOp = $compare;
        $face->compareMask = 0xFF;
        $face->writeMask = 0xFF;
        $face->reference = 0;
    }

    $attachment = new VkPipelineColorBlendAttachmentState();
    $attachment->colorWriteMask = $writeColor
        ? VK_COLOR_COMPONENT_R_BIT | VK_COLOR_COMPONENT_G_BIT | VK_COLOR_COMPONENT_B_BIT | VK_COLOR_COMPONENT_A_BIT
        : 0;
    $blend = new VkPipelineColorBlendStateCreateInfo();
    $blend->pAttachments = [$attachment];
    $dynamic = new VkPipelineDynamicStateCreateInfo();
    $dynamic->pDynamicStates = [VK_DYNAMIC_STATE_VIEWPORT, VK_DYNAMIC_STATE_SCISSOR];

    $info = new VkGraphicsPipelineCreateInfo();
    $info->pStages = [$stage(VK_SHADER_STAGE_VERTEX_BIT, 'flat.vert.spv'), $stage(VK_SHADER_STAGE_FRAGMENT_BIT, 'flat.frag.spv')];
    $info->pVertexInputState = $vertexInput;
    $info->pInputAssemblyState = $assembly;
    $info->pViewportState = $viewport;
    $info->pRasterizationState = $raster;
    $info->pMultisampleState = $multisample;
    $info->pDepthStencilState = $depthStencil;
    $info->pColorBlendState = $blend;
    $info->pDynamicState = $dynamic;
    $info->layout = $layout;
    $info->renderPass = $pass;
    vkCreateGraphicsPipelines($device, null, [$info], null, $pipelines) === VK_SUCCESS || throw new RuntimeException('vkCreateGraphicsPipelines');

    return $pipelines[0];
}

function layoutBarrier(VkImage $image, int $old, int $new, int $srcAccess, int $dstAccess): VkImageMemoryBarrier
{
    $barrier = new VkImageMemoryBarrier();
    $barrier->srcAccessMask = $srcAccess;
    $barrier->dstAccessMask = $dstAccess;
    $barrier->oldLayout = $old;
    $barrier->newLayout = $new;
    $barrier->srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
    $barrier->dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
    $barrier->image = $image;
    $barrier->subresourceRange->aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
    $barrier->subresourceRange->levelCount = 1;
    $barrier->subresourceRange->layerCount = 1;

    return $barrier;
}

function commandsOn(VkDevice $device, int $family): VkCommandBuffer
{
    $poolInfo = new VkCommandPoolCreateInfo();
    $poolInfo->queueFamilyIndex = $family;
    vkCreateCommandPool($device, $poolInfo, null, $pool) === VK_SUCCESS || throw new RuntimeException('vkCreateCommandPool');
    $allocate = new VkCommandBufferAllocateInfo();
    $allocate->commandPool = $pool;
    $allocate->level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    $allocate->commandBufferCount = 1;
    vkAllocateCommandBuffers($device, $allocate, $buffers) === VK_SUCCESS || throw new RuntimeException('vkAllocateCommandBuffers');
    $begin = new VkCommandBufferBeginInfo();
    $begin->flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;
    vkBeginCommandBuffer($buffers[0], $begin) === VK_SUCCESS || throw new RuntimeException('vkBeginCommandBuffer');

    return $buffers[0];
}

function commands(): VkCommandBuffer
{
    [, , $device, , $family] = gpu();

    return commandsOn($device, $family);
}

function submitAndWaitOn(VkDevice $device, VkQueue $queue, VkCommandBuffer $commandBuffer): void
{
    vkEndCommandBuffer($commandBuffer) === VK_SUCCESS || throw new RuntimeException('vkEndCommandBuffer');
    $submit = new VkSubmitInfo();
    $submit->pCommandBuffers = [$commandBuffer];
    vkCreateFence($device, new VkFenceCreateInfo(), null, $fence) === VK_SUCCESS || throw new RuntimeException('vkCreateFence');
    vkQueueSubmit($queue, [$submit], $fence) === VK_SUCCESS || throw new RuntimeException('vkQueueSubmit');
    vkWaitForFences($device, [$fence], true, PHP_INT_MAX) === VK_SUCCESS || throw new RuntimeException('vkWaitForFences');
    vkDestroyFence($device, $fence, null);
}

function submitAndWait(VkCommandBuffer $commandBuffer): void
{
    [, , $device, $queue] = gpu();
    submitAndWaitOn($device, $queue, $commandBuffer);
}


