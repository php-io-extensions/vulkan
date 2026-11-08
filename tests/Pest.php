<?php

declare(strict_types=1);

if (! extension_loaded('vulkan')) {
    throw new RuntimeException('The vulkan extension is not loaded; run ./install-macos.sh or ./install-debian-trixie.sh');
}

const MAC = PHP_OS_FAMILY === 'Darwin';
const PROBE_SIGBUS = MAC ? 10 : 7;
const PROBE_SIGSEGV = 11;
const PROBE_SIGABRT = 6;

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
    $app->apiVersion = VK_API_VERSION_1_4;
    $info = new VkInstanceCreateInfo();
    $info->pApplicationInfo = $app;

    vkEnumerateInstanceExtensionProperties(null, $count, null);
    vkEnumerateInstanceExtensionProperties(null, $count, $available);
    $names = array_map(fn (VkExtensionProperties $e): string => $e->extensionName, $available);
    if (in_array(VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME, $names, true)) {
        $extensions[] = VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME;
        $info->flags |= VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR;
    }
    $info->ppEnabledExtensionNames = array_values(array_unique($extensions));
    $info->enabledExtensionCount = count($info->ppEnabledExtensionNames);

    return $info;
}

/** The device create info with VK_KHR_portability_subset added where the device lists it. */
function portabilityDevice(VkPhysicalDevice $physical, VkDeviceCreateInfo $info): VkDeviceCreateInfo
{
    vkEnumerateDeviceExtensionProperties($physical, null, $count, null);
    vkEnumerateDeviceExtensionProperties($physical, null, $count, $available);
    $names = array_map(fn (VkExtensionProperties $e): string => $e->extensionName, $available);
    if (in_array(VK_KHR_PORTABILITY_SUBSET_EXTENSION_NAME, $names, true)) {
        $info->ppEnabledExtensionNames = array_values(array_unique([...$info->ppEnabledExtensionNames, VK_KHR_PORTABILITY_SUBSET_EXTENSION_NAME]));
        $info->enabledExtensionCount = count($info->ppEnabledExtensionNames);
    }

    return $info;
}

/**
 * @return array{VkInstance, VkPhysicalDevice, VkDevice, VkQueue, int, bool}|null instance, the GPU (never the CPU device), a device with one graphics queue, that queue, its family, whether the device was made with host image copies (Vulkan 1.4, hostImageCopy: the tests move host data with them); null where no GPU is visible
 */
function vulkan(): ?array
{
    static $made = false, $vulkan = null;
    if ($made) {
        return $vulkan;
    }
    $made = true;

    $create = portabilityInstance();
    if (vkCreateInstance($create, 0, $instance) !== VK_SUCCESS) {
        return null;
    }

    vkEnumeratePhysicalDevices($instance, $count, null);
    vkEnumeratePhysicalDevices($instance, $count, $devices);
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

    vkGetPhysicalDeviceQueueFamilyProperties($physical, $count, null);
    vkGetPhysicalDeviceQueueFamilyProperties($physical, $count, $families);
    $family = array_key_first(array_filter($families, fn (VkQueueFamilyProperties $f): bool => ($f->queueFlags & VK_QUEUE_GRAPHICS_BIT) !== 0));
    $queueInfo = new VkDeviceQueueCreateInfo();
    $queueInfo->queueFamilyIndex = $family;
    $queueInfo->queueCount = 1;
    $queueInfo->pQueuePriorities = [1.0];
    $deviceInfo = new VkDeviceCreateInfo();
    $deviceInfo->queueCreateInfoCount = 1;
    $deviceInfo->pQueueCreateInfos = [$queueInfo];
    $offered = new VkPhysicalDeviceHostImageCopyFeatures();
    $probe = new VkPhysicalDeviceFeatures2();
    $probe->pNext = $offered;
    vkGetPhysicalDeviceFeatures2($physical, $probe);
    $hostCopy = $properties->apiVersion >= VK_API_VERSION_1_4 && $offered->hostImageCopy;
    if ($hostCopy) {
        $enable = new VkPhysicalDeviceHostImageCopyFeatures();
        $enable->hostImageCopy = true;
        $deviceInfo->pNext = $enable;
    }
    vkCreateDevice($physical, portabilityDevice($physical, $deviceInfo), 0, $device) === VK_SUCCESS || throw new RuntimeException('vkCreateDevice');
    vkGetDeviceQueue($device, $family, 0, $queue);

    return $vulkan = [$instance, $physical, $device, $queue, $family, $hostCopy];
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
    vkCreateBuffer($device, $info, 0, $buffer) === VK_SUCCESS || throw new RuntimeException('vkCreateBuffer');
    vkGetBufferMemoryRequirements($device, $buffer, $requirements);
    $allocate = new VkMemoryAllocateInfo();
    $allocate->allocationSize = $requirements->size;
    $allocate->memoryTypeIndex = memoryType($requirements->memoryTypeBits, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT);
    vkAllocateMemory($device, $allocate, 0, $memory) === VK_SUCCESS || throw new RuntimeException('vkAllocateMemory');
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
    vkCreateImage($device, $info, 0, $image) === VK_SUCCESS || throw new RuntimeException('vkCreateImage');
    vkGetImageMemoryRequirements($device, $image, $requirements);
    $allocate = new VkMemoryAllocateInfo();
    $allocate->allocationSize = $requirements->size;
    $allocate->memoryTypeIndex = memoryType($requirements->memoryTypeBits, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
    vkAllocateMemory($device, $allocate, 0, $memory) === VK_SUCCESS || throw new RuntimeException('vkAllocateMemory');
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
    vkCreateImageView($device, $info, 0, $view) === VK_SUCCESS || throw new RuntimeException('vkCreateImageView');

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
    $subpass->colorAttachmentCount = 1;
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
    $info->attachmentCount = 3;
    $info->pAttachments = [$color, $stencil, $resolve];
    $info->subpassCount = 1;
    $info->dependencyCount = 1;
    $info->pSubpasses = [$subpass];
    $info->pDependencies = [$dependency];
    vkCreateRenderPass($device, $info, 0, $pass) === VK_SUCCESS || throw new RuntimeException('vkCreateRenderPass');

    return $pass;
}

function shaderModule(string $file): VkShaderModule
{
    [, , $device] = gpu();
    $info = new VkShaderModuleCreateInfo();
    $info->pCode = file_get_contents(__DIR__ . '/Fixtures/' . $file);
    $info->codeSize = strlen($info->pCode);
    vkCreateShaderModule($device, $info, 0, $module) === VK_SUCCESS || throw new RuntimeException("vkCreateShaderModule {$file}");

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
    $info->pushConstantRangeCount = 1;
    $info->pPushConstantRanges = [$range];
    vkCreatePipelineLayout($device, $info, 0, $layout) === VK_SUCCESS || throw new RuntimeException('vkCreatePipelineLayout');

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
    $vertexInput->vertexBindingDescriptionCount = 1;
    $vertexInput->vertexAttributeDescriptionCount = 1;
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
    $depthStencil->stencilTestEnable = true;
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
    $blend->attachmentCount = 1;
    $blend->pAttachments = [$attachment];
    $dynamic = new VkPipelineDynamicStateCreateInfo();
    $dynamic->dynamicStateCount = 2;
    $dynamic->pDynamicStates = [VK_DYNAMIC_STATE_VIEWPORT, VK_DYNAMIC_STATE_SCISSOR];

    $info = new VkGraphicsPipelineCreateInfo();
    $info->stageCount = 2;
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
    vkCreateGraphicsPipelines($device, 0, 1, [$info], 0, $pipelines) === VK_SUCCESS || throw new RuntimeException('vkCreateGraphicsPipelines');

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
    vkCreateCommandPool($device, $poolInfo, 0, $pool) === VK_SUCCESS || throw new RuntimeException('vkCreateCommandPool');
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
    $submit->commandBufferCount = 1;
    $submit->pCommandBuffers = [$commandBuffer];
    vkCreateFence($device, new VkFenceCreateInfo(), 0, $fence) === VK_SUCCESS || throw new RuntimeException('vkCreateFence');
    vkQueueSubmit($queue, 1, [$submit], $fence) === VK_SUCCESS || throw new RuntimeException('vkQueueSubmit');
    vkWaitForFences($device, 1, [$fence], true, PHP_INT_MAX) === VK_SUCCESS || throw new RuntimeException('vkWaitForFences');
    vkDestroyFence($device, $fence, 0);
}

function submitAndWait(VkCommandBuffer $commandBuffer): void
{
    [, , $device, $queue] = gpu();
    submitAndWaitOn($device, $queue, $commandBuffer);
}



/** The test is skipped where the shared device has no host image copies (Vulkan 1.4, hostImageCopy). */
function requireHostCopy(): void
{
    gpu()[5] || test()->markTestSkipped('the device lacks hostImageCopy (Vulkan 1.4)');
}

/**
 * A device-local RGBA8 image the host can write and read, in GENERAL from the start (the host moved it there).
 *
 * @return array{VkImage, VkDeviceMemory}
 */
function hostImage2D(int $w, int $h, int $usage): array
{
    requireHostCopy();
    [, , $device] = gpu();
    [$image, $memory] = image2D(VK_FORMAT_R8G8B8A8_UNORM, $w, $h, $usage | VK_IMAGE_USAGE_HOST_TRANSFER_BIT);
    $transition = new VkHostImageLayoutTransitionInfo();
    $transition->image = $image;
    $transition->oldLayout = VK_IMAGE_LAYOUT_UNDEFINED;
    $transition->newLayout = VK_IMAGE_LAYOUT_GENERAL;
    $transition->subresourceRange->aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
    $transition->subresourceRange->levelCount = 1;
    $transition->subresourceRange->layerCount = 1;
    vkTransitionImageLayout($device, 1, [$transition]) === VK_SUCCESS || throw new RuntimeException('vkTransitionImageLayout');

    return [$image, $memory];
}

/** $bytes (rows top-down) over all of a host image, written by the host. */
function hostWrite(VkImage $image, int $w, int $h, string $bytes): void
{
    [, , $device] = gpu();
    $region = new VkMemoryToImageCopy();
    $region->pHostPointer = $bytes;
    $region->imageSubresource->aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
    $region->imageSubresource->layerCount = 1;
    [$region->imageExtent->width, $region->imageExtent->height, $region->imageExtent->depth] = [$w, $h, 1];
    $info = new VkCopyMemoryToImageInfo();
    $info->dstImage = $image;
    $info->dstImageLayout = VK_IMAGE_LAYOUT_GENERAL;
    $info->regionCount = 1;
    $info->pRegions = [$region];
    vkCopyMemoryToImage($device, $info) === VK_SUCCESS || throw new RuntimeException('vkCopyMemoryToImage');
}

/** All of a host image, rows top-down, read by the host. */
function hostRead(VkImage $image, int $w, int $h): string
{
    [, , $device] = gpu();
    $region = new VkImageToMemoryCopy();
    $region->pHostPointer = str_repeat("\0", $w * $h * 4);
    $region->imageSubresource->aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
    $region->imageSubresource->layerCount = 1;
    [$region->imageExtent->width, $region->imageExtent->height, $region->imageExtent->depth] = [$w, $h, 1];
    $info = new VkCopyImageToMemoryInfo();
    $info->srcImage = $image;
    $info->srcImageLayout = VK_IMAGE_LAYOUT_GENERAL;
    $info->regionCount = 1;
    $info->pRegions = [$region];
    vkCopyImageToMemory($device, $info) === VK_SUCCESS || throw new RuntimeException('vkCopyImageToMemory');

    return $region->pHostPointer;
}

/** Skips a tests/Probes test unless the loaded ext-vulkan is a probe build (--enable-vulkan-probes). */
function requireProbeBuild(): void
{
    if (! defined('VULKAN_PROBES')) {
        test()->markTestSkipped('ext-vulkan is not a probe build (configure --enable-vulkan-probes): VULKAN_PROBES is undefined');
    }
}

/**
 * Runs $code in a child of this PHP with only ext-vulkan loaded (env VULKAN_SO names the module,
 * else the extension directory's), after this file's helpers. With $siteOff, VULKAN_PROBE_OFF
 * turns that kept site off; null keeps every site. $gmalloc runs the child under libgmalloc
 * (macOS) with Zend's allocator off, so an over-read faults at the guard page after the allocation.
 *
 * @return array{signal: ?int, stdout: string}
 */
function vkProbe(string $code, ?string $siteOff, bool $gmalloc = false): array
{
    $script = "<?php\ndeclare(strict_types=1);\nrequire " . var_export(__FILE__, true) . ";\n"
        . "function test(): object { return new class { public function markTestSkipped(string \$m): never { echo \"SKIPPED \$m\\n\"; exit(0); } }; }\n"
        . "try {\n" . $code . "\n} catch (Throwable \$t) {\n    echo 'REFUSED ', get_class(\$t), ': ', \$t->getMessage(), \"\\n\";\n}\necho \"SURVIVED\\n\";\n";
    $file = tempnam(sys_get_temp_dir(), 'vulkan-probe');
    file_put_contents($file, $script);

    $env = getenv();
    unset($env['VULKAN_PROBE_OFF'], $env['DYLD_INSERT_LIBRARIES'], $env['USE_ZEND_ALLOC']);
    $env['XDEBUG_MODE'] = 'off';
    if ($siteOff !== null) {
        $env['VULKAN_PROBE_OFF'] = $siteOff;
    }
    if ($gmalloc && MAC) {
        $env['DYLD_INSERT_LIBRARIES'] = '/usr/lib/libgmalloc.dylib';
        $env['USE_ZEND_ALLOC'] = '0';
    }

    $command = [PHP_BINARY, '-n', '-d', 'memory_limit=1G', '-d', 'extension=' . (getenv('VULKAN_SO') ?: ini_get('extension_dir') . '/vulkan.so'), $file];
    $process = proc_open($command, [0 => ['file', '/dev/null', 'r'], 1 => ['pipe', 'w'], 2 => ['file', '/dev/null', 'w']], $pipes, null, $env);
    $stdout = (string) stream_get_contents($pipes[1]);
    fclose($pipes[1]);
    do {
        $status = proc_get_status($process);
        if ($status['running']) {
            usleep(20_000);
        }
    } while ($status['running']);
    proc_close($process);
    @unlink($file);

    return ['signal' => $status['signaled'] ? $status['termsig'] : null, 'stdout' => $stdout];
}
