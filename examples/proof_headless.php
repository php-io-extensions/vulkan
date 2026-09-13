<?php

/*
 * proof_headless.php — Wave 2's proof: one triangle, no window, both boxes.
 *
 * Draws a 64x64 offscreen frame through a real graphics pipeline built from
 * the vendored SPIR-V in examples/shaders/, copies it into a host-visible
 * buffer, and checks two pixels byte for byte:
 *
 *     (32, 32) = 255, 128, 64, 255   the fragment shader's colour
 *     ( 0,  0) =   0,   0,  0, 255   the render pass's clear colour
 *
 * Everything opinionated is HERE, not in the extension: every sType, every
 * enum, the portability extensions MoltenVK needs, the memory types, the
 * pipeline state. Constants are inlined with their vk.xml / vulkan_core.h
 * citation until jovian/vulkan mines them (AGENTS.md rule 10).
 *
 * Prints PROOF_HEADLESS_OK when all of that held; on any failure it writes
 * PROOF_HEADLESS_FAILED: <why> to stderr and exits 1.
 */

declare(strict_types=1);

use Vulkan\Bridge\Bridge;
use Vulkan\Struct\VkApplicationInfo\VkApplicationInfo;
use Vulkan\Struct\VkAttachmentDescription\VkAttachmentDescription;
use Vulkan\Struct\VkAttachmentReference\VkAttachmentReference;
use Vulkan\Struct\VkBufferCreateInfo\VkBufferCreateInfo;
use Vulkan\Struct\VkBufferImageCopy\VkBufferImageCopy;
use Vulkan\Struct\VkClearValue\VkClearValue;
use Vulkan\Struct\VkCommandBufferAllocateInfo\VkCommandBufferAllocateInfo;
use Vulkan\Struct\VkCommandBufferBeginInfo\VkCommandBufferBeginInfo;
use Vulkan\Struct\VkCommandPoolCreateInfo\VkCommandPoolCreateInfo;
use Vulkan\Struct\VkDeviceCreateInfo\VkDeviceCreateInfo;
use Vulkan\Struct\VkDeviceQueueCreateInfo\VkDeviceQueueCreateInfo;
use Vulkan\Struct\VkExtensionProperties\VkExtensionProperties;
use Vulkan\Struct\VkFramebufferCreateInfo\VkFramebufferCreateInfo;
use Vulkan\Struct\VkGraphicsPipelineCreateInfo\VkGraphicsPipelineCreateInfo;
use Vulkan\Struct\VkImageCreateInfo\VkImageCreateInfo;
use Vulkan\Struct\VkImageViewCreateInfo\VkImageViewCreateInfo;
use Vulkan\Struct\VkInstanceCreateInfo\VkInstanceCreateInfo;
use Vulkan\Struct\VkMemoryAllocateInfo\VkMemoryAllocateInfo;
use Vulkan\Struct\VkMemoryRequirements\VkMemoryRequirements;
use Vulkan\Struct\VkPhysicalDeviceMemoryProperties\VkPhysicalDeviceMemoryProperties;
use Vulkan\Struct\VkPhysicalDeviceProperties\VkPhysicalDeviceProperties;
use Vulkan\Struct\VkPipelineColorBlendAttachmentState\VkPipelineColorBlendAttachmentState;
use Vulkan\Struct\VkPipelineColorBlendStateCreateInfo\VkPipelineColorBlendStateCreateInfo;
use Vulkan\Struct\VkPipelineInputAssemblyStateCreateInfo\VkPipelineInputAssemblyStateCreateInfo;
use Vulkan\Struct\VkPipelineLayoutCreateInfo\VkPipelineLayoutCreateInfo;
use Vulkan\Struct\VkPipelineMultisampleStateCreateInfo\VkPipelineMultisampleStateCreateInfo;
use Vulkan\Struct\VkPipelineRasterizationStateCreateInfo\VkPipelineRasterizationStateCreateInfo;
use Vulkan\Struct\VkPipelineShaderStageCreateInfo\VkPipelineShaderStageCreateInfo;
use Vulkan\Struct\VkPipelineVertexInputStateCreateInfo\VkPipelineVertexInputStateCreateInfo;
use Vulkan\Struct\VkPipelineViewportStateCreateInfo\VkPipelineViewportStateCreateInfo;
use Vulkan\Struct\VkQueueFamilyProperties\VkQueueFamilyProperties;
use Vulkan\Struct\VkRect2D\VkRect2D;
use Vulkan\Struct\VkRenderPassBeginInfo\VkRenderPassBeginInfo;
use Vulkan\Struct\VkRenderPassCreateInfo\VkRenderPassCreateInfo;
use Vulkan\Struct\VkShaderModuleCreateInfo\VkShaderModuleCreateInfo;
use Vulkan\Struct\VkSubmitInfo\VkSubmitInfo;
use Vulkan\Struct\VkSubpassDependency\VkSubpassDependency;
use Vulkan\Struct\VkSubpassDescription\VkSubpassDescription;
use Vulkan\Struct\VkVertexInputAttributeDescription\VkVertexInputAttributeDescription;
use Vulkan\Struct\VkVertexInputBindingDescription\VkVertexInputBindingDescription;
use Vulkan\Struct\VkViewport\VkViewport;
use Vulkan\VK\VK10\VK10;

/* ---------------------------------------------------------------- constants --
 * Every value below is quoted from the vendored scripts/khronos/vk.xml, which
 * is the same text vulkan_core.h is generated from. jovian/vulkan will make
 * these PHP enums; this extension defines none of them.
 */

// <enums name="VkResult">
const VK_SUCCESS = 0;

// <enums name="VkStructureType">
const VK_STRUCTURE_TYPE_APPLICATION_INFO = 0;
const VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO = 1;
const VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO = 2;
const VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO = 3;
const VK_STRUCTURE_TYPE_SUBMIT_INFO = 4;
const VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO = 5;
const VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO = 12;
const VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO = 14;
const VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO = 15;
const VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO = 16;
const VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO = 18;
const VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO = 19;
const VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO = 20;
const VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO = 22;
const VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO = 23;
const VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO = 24;
const VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO = 26;
const VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO = 28;
const VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO = 30;
const VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO = 37;
const VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO = 38;
const VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO = 39;
const VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO = 40;
const VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO = 42;
const VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO = 43;

// <enums name="VkInstanceCreateFlagBits"> (VK_KHR_portability_enumeration)
const VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR = 0x00000001;

// <enums name="VkPhysicalDeviceType">
const VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU = 1;

// <enums name="VkQueueFlagBits"> bitpos 0
const VK_QUEUE_GRAPHICS_BIT = 0x00000001;

// <enums name="VkFormat">
const VK_FORMAT_R8G8B8A8_UNORM = 37;
const VK_FORMAT_R32G32_SFLOAT = 103;

// <enums name="VkImageType"> / VkImageTiling / VkSharingMode / VkImageViewType
const VK_IMAGE_TYPE_2D = 1;
const VK_IMAGE_TILING_OPTIMAL = 0;
const VK_SHARING_MODE_EXCLUSIVE = 0;
const VK_IMAGE_VIEW_TYPE_2D = 1;

// <enums name="VkSampleCountFlagBits"> bitpos 0
const VK_SAMPLE_COUNT_1_BIT = 0x00000001;

// <enums name="VkImageUsageFlagBits"> bitpos 0 and 4
const VK_IMAGE_USAGE_TRANSFER_SRC_BIT = 0x00000001;
const VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT = 0x00000010;

// <enums name="VkImageLayout">
const VK_IMAGE_LAYOUT_UNDEFINED = 0;
const VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL = 2;
const VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL = 6;

// <enums name="VkImageAspectFlagBits"> bitpos 0
const VK_IMAGE_ASPECT_COLOR_BIT = 0x00000001;

// <enums name="VkComponentSwizzle">
const VK_COMPONENT_SWIZZLE_IDENTITY = 0;

// <enums name="VkMemoryPropertyFlagBits"> bitpos 0, 1, 2
const VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT = 0x00000001;
const VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT = 0x00000002;
const VK_MEMORY_PROPERTY_HOST_COHERENT_BIT = 0x00000004;

// <enums name="VkAttachmentLoadOp"> / VkAttachmentStoreOp
const VK_ATTACHMENT_LOAD_OP_CLEAR = 1;
const VK_ATTACHMENT_LOAD_OP_DONT_CARE = 2;
const VK_ATTACHMENT_STORE_OP_STORE = 0;
const VK_ATTACHMENT_STORE_OP_DONT_CARE = 1;

// <enums name="VkPipelineBindPoint">
const VK_PIPELINE_BIND_POINT_GRAPHICS = 0;

// <type> VK_SUBPASS_EXTERNAL = (~0U)
const VK_SUBPASS_EXTERNAL = 0xFFFFFFFF;

// <enums name="VkPipelineStageFlagBits"> bitpos 10 and 12
const VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT = 0x00000400;
const VK_PIPELINE_STAGE_TRANSFER_BIT = 0x00001000;

// <enums name="VkAccessFlagBits"> bitpos 8 and 11
const VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT = 0x00000100;
const VK_ACCESS_TRANSFER_READ_BIT = 0x00000800;

// <enums name="VkShaderStageFlagBits"> bitpos 0 and 4
const VK_SHADER_STAGE_VERTEX_BIT = 0x00000001;
const VK_SHADER_STAGE_FRAGMENT_BIT = 0x00000010;

// <enums name="VkVertexInputRate"> / VkPrimitiveTopology / VkPolygonMode /
// VkCullModeFlagBits / VkFrontFace
const VK_VERTEX_INPUT_RATE_VERTEX = 0;
const VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST = 3;
const VK_POLYGON_MODE_FILL = 0;
const VK_CULL_MODE_NONE = 0;
const VK_FRONT_FACE_COUNTER_CLOCKWISE = 0;

// <enums name="VkBlendFactor"> / VkBlendOp / VkLogicOp
const VK_BLEND_FACTOR_ZERO = 0;
const VK_BLEND_FACTOR_ONE = 1;
const VK_BLEND_OP_ADD = 0;
const VK_LOGIC_OP_COPY = 3;

// <enums name="VkColorComponentFlagBits"> bitpos 0..3
const VK_COLOR_COMPONENT_RGBA_BITS = 0x0000000F;

// <enums name="VkBufferUsageFlagBits"> bitpos 1 and 7
const VK_BUFFER_USAGE_TRANSFER_DST_BIT = 0x00000002;
const VK_BUFFER_USAGE_VERTEX_BUFFER_BIT = 0x00000080;

// <enums name="VkCommandBufferLevel"> / VkCommandBufferUsageFlagBits bitpos 0 /
// VkSubpassContents
const VK_COMMAND_BUFFER_LEVEL_PRIMARY = 0;
const VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT = 0x00000001;
const VK_SUBPASS_CONTENTS_INLINE = 0;

// <enum name="VK_WHOLE_SIZE" value="(~0ULL)"> — UINT64_MAX crosses as -1
// (.okf/binding-rules.md, the 64-bit wrap).
const VK_WHOLE_SIZE = -1;

/* ------------------------------------------------------------------ script -- */

const WIDTH = 64;
const HEIGHT = 64;
const PIXEL_BYTES = 4;
const IMAGE_BYTES = WIDTH * HEIGHT * PIXEL_BYTES;

function vkVersion(int $major, int $minor, int $patch): int
{
    return ($major << 22) | ($minor << 12) | $patch;
}

function fail(string $m): never
{
    fwrite(STDERR, "PROOF_HEADLESS_FAILED: {$m}\n");
    exit(1);
}

/** Every block this script owns, newest last; all of them are freed at the end. */
$blocks = [];

/** Record a Bridge block (alloc / cstring / Struct::pack) and refuse a failed one. */
$keep = static function (int $ptr, string $what) use (&$blocks): int {
    if ($ptr === 0) {
        fail($what);
    }
    $blocks[] = $ptr;

    return $ptr;
};

/** Read a 64-bit handle a Vulkan out-parameter wrote into a block. */
$handleAt = static function (int $ptr, int $index = 0): int {
    return unpack('P', Bridge::read($ptr, $index * 8, 8))[1];
};

/** Write a 64-bit handle into a block, for an array parameter. */
$putHandle = static function (int $ptr, int $index, int $handle): void {
    Bridge::write($ptr, $index * 8, pack('P', $handle)) || fail('Bridge::write handle');
};

/** Check a VkResult. */
$ok = static function (int $r, string $what): void {
    if ($r !== VK_SUCCESS) {
        fail("{$what} returned VkResult {$r}");
    }
};

/* -- 1. Instance ------------------------------------------------------------ */

Bridge::load() || fail('Bridge::load');

/*
 * MoltenVK is a portability driver: without VK_KHR_portability_enumeration and
 * the matching instance flag the loader reports zero physical devices — no
 * error, just an empty list. The driver's rule, not this extension's; see
 * .okf/traps/moltenvk-portability.md.
 */
$isDarwin = PHP_OS_FAMILY === 'Darwin';
$instanceExtNames = $isDarwin ? ['VK_KHR_portability_enumeration'] : [];

$instanceExtPtrs = [];
foreach ($instanceExtNames as $name) {
    $instanceExtPtrs[] = $keep(Bridge::cstring($name), "Bridge::cstring({$name})");
}
$instanceExtArray = $keep(Bridge::alloc(max(1, count($instanceExtPtrs)) * 8), 'alloc instance extension array');
foreach ($instanceExtPtrs as $i => $p) {
    $putHandle($instanceExtArray, $i, $p);
}

$appName = $keep(Bridge::cstring('proof_headless'), 'Bridge::cstring(proof_headless)');
$appInfo = $keep(VkApplicationInfo::pack([
    'sType' => VK_STRUCTURE_TYPE_APPLICATION_INFO,
    'pApplicationName' => $appName,
    'applicationVersion' => 1,
    'apiVersion' => vkVersion(1, 3, 0),
]), 'VkApplicationInfo::pack');

$instanceInfo = $keep(VkInstanceCreateInfo::pack([
    'sType' => VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
    'flags' => $isDarwin ? VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR : 0,
    'pApplicationInfo' => $appInfo,
    'enabledExtensionCount' => count($instanceExtPtrs),
    'ppEnabledExtensionNames' => $instanceExtArray,
]), 'VkInstanceCreateInfo::pack');

$instanceOut = $keep(Bridge::alloc(8), 'alloc instance handle');
$ok(VK10::vkCreateInstance($instanceInfo, 0, $instanceOut), 'vkCreateInstance');
$instance = $handleAt($instanceOut);
$instance !== 0 || fail('vkCreateInstance succeeded but wrote a null handle');
Bridge::loadInstance($instance) || fail('Bridge::loadInstance');

/* -- 2. Physical device with a graphics queue family ------------------------ */

$countOut = $keep(Bridge::alloc(4), 'alloc count');
$readCount = static function () use ($countOut): int {
    return unpack('V', Bridge::read($countOut, 0, 4))[1];
};

$ok(VK10::vkEnumeratePhysicalDevices($instance, $countOut, 0), 'vkEnumeratePhysicalDevices(count)');
$deviceCount = $readCount();
$deviceCount > 0 || fail('no physical devices');

$deviceList = $keep(Bridge::alloc($deviceCount * 8), 'alloc physical device list');
$ok(VK10::vkEnumeratePhysicalDevices($instance, $countOut, $deviceList), 'vkEnumeratePhysicalDevices(list)');

$propsBlock = $keep(Bridge::alloc(VkPhysicalDeviceProperties::size()), 'alloc VkPhysicalDeviceProperties');

$physicalDevice = 0;
$queueFamily = -1;
$deviceProps = [];
$preferredType = -1;

for ($i = 0; $i < $deviceCount; $i++) {
    $candidate = $handleAt($deviceList, $i);

    VK10::vkGetPhysicalDeviceQueueFamilyProperties($candidate, $countOut, 0);
    $familyCount = $readCount();
    if ($familyCount === 0) {
        continue;
    }

    $families = $keep(Bridge::alloc($familyCount * VkQueueFamilyProperties::size()), 'alloc queue families');
    VK10::vkGetPhysicalDeviceQueueFamilyProperties($candidate, $countOut, $families);

    $family = -1;
    for ($f = 0; $f < $familyCount; $f++) {
        $qf = VkQueueFamilyProperties::unpack($families + $f * VkQueueFamilyProperties::size());
        if (($qf['queueFlags'] & VK_QUEUE_GRAPHICS_BIT) !== 0 && $qf['queueCount'] > 0) {
            $family = $f;
            break;
        }
    }
    if ($family < 0) {
        continue;
    }

    VK10::vkGetPhysicalDeviceProperties($candidate, $propsBlock);
    $p = VkPhysicalDeviceProperties::unpack($propsBlock);

    /*
     * Prefer a real GPU. On the Pi both V3D (INTEGRATED_GPU) and llvmpipe (CPU)
     * offer a graphics queue, and llvmpipe is usually enumerated second; taking
     * the first match would be a coin flip on enumeration order.
     */
    $better = $physicalDevice === 0
        || ($p['deviceType'] === VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU && $preferredType !== VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU);

    if ($better) {
        $physicalDevice = $candidate;
        $queueFamily = $family;
        $deviceProps = $p;
        $preferredType = $p['deviceType'];
    }
}

$physicalDevice !== 0 || fail('no physical device has a graphics queue family');

printf(
    "device: %s api %d.%d.%d type %d queueFamily %d\n",
    $deviceProps['deviceName'],
    $deviceProps['apiVersion'] >> 22,
    ($deviceProps['apiVersion'] >> 12) & 0x3ff,
    $deviceProps['apiVersion'] & 0xfff,
    $deviceProps['deviceType'],
    $queueFamily
);

/* -- 3. Logical device, queue ----------------------------------------------- */

$priorities = $keep(Bridge::alloc(4), 'alloc queue priority');
Bridge::write($priorities, 0, pack('f', 1.0)) || fail('Bridge::write queue priority');

$queueInfo = $keep(VkDeviceQueueCreateInfo::pack([
    'sType' => VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO,
    'queueFamilyIndex' => $queueFamily,
    'queueCount' => 1,
    'pQueuePriorities' => $priorities,
]), 'VkDeviceQueueCreateInfo::pack');

/*
 * Spec §9: a device that advertises VK_KHR_portability_subset must have it
 * enabled. That is every MoltenVK device. The empty layer name is how this
 * binding spells "no layer": a const char * parameter crosses as a PHP string
 * and cannot be null, and the loader treats "" as none — see
 * .okf/traps/no-null-cstring-parameter.md.
 */
$deviceExtPtrs = [];
if ($isDarwin) {
    $ok(VK10::vkEnumerateDeviceExtensionProperties($physicalDevice, '', $countOut, 0), 'vkEnumerateDeviceExtensionProperties(count)');
    $extCount = $readCount();
    if ($extCount > 0) {
        $extList = $keep(Bridge::alloc($extCount * VkExtensionProperties::size()), 'alloc device extension list');
        $ok(VK10::vkEnumerateDeviceExtensionProperties($physicalDevice, '', $countOut, $extList), 'vkEnumerateDeviceExtensionProperties(list)');
        for ($i = 0; $i < $extCount; $i++) {
            $e = VkExtensionProperties::unpack($extList + $i * VkExtensionProperties::size());
            if ($e['extensionName'] === 'VK_KHR_portability_subset') {
                $deviceExtPtrs[] = $keep(Bridge::cstring('VK_KHR_portability_subset'), 'Bridge::cstring(VK_KHR_portability_subset)');
                break;
            }
        }
    }
}

$deviceExtArray = $keep(Bridge::alloc(max(1, count($deviceExtPtrs)) * 8), 'alloc device extension array');
foreach ($deviceExtPtrs as $i => $p) {
    $putHandle($deviceExtArray, $i, $p);
}

$deviceInfo = $keep(VkDeviceCreateInfo::pack([
    'sType' => VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO,
    'queueCreateInfoCount' => 1,
    'pQueueCreateInfos' => $queueInfo,
    'enabledExtensionCount' => count($deviceExtPtrs),
    'ppEnabledExtensionNames' => $deviceExtArray,
]), 'VkDeviceCreateInfo::pack');

$deviceOut = $keep(Bridge::alloc(8), 'alloc device handle');
$ok(VK10::vkCreateDevice($physicalDevice, $deviceInfo, 0, $deviceOut), 'vkCreateDevice');
$device = $handleAt($deviceOut);
$device !== 0 || fail('vkCreateDevice succeeded but wrote a null handle');
Bridge::loadDevice($device) || fail('Bridge::loadDevice');

$queueOut = $keep(Bridge::alloc(8), 'alloc queue handle');
VK10::vkGetDeviceQueue($device, $queueFamily, 0, $queueOut);
$queue = $handleAt($queueOut);
$queue !== 0 || fail('vkGetDeviceQueue wrote a null handle');

/* -- 4. Colour image, its memory, its view ---------------------------------- */

$memPropsBlock = $keep(Bridge::alloc(VkPhysicalDeviceMemoryProperties::size()), 'alloc VkPhysicalDeviceMemoryProperties');
VK10::vkGetPhysicalDeviceMemoryProperties($physicalDevice, $memPropsBlock);
$memProps = VkPhysicalDeviceMemoryProperties::unpack($memPropsBlock);

/** First memory type allowed by memoryTypeBits that carries every required property. */
$memoryTypeIndex = static function (int $typeBits, int $required) use ($memProps): int {
    for ($i = 0; $i < $memProps['memoryTypeCount']; $i++) {
        if (($typeBits & (1 << $i)) === 0) {
            continue;
        }
        if (($memProps['memoryTypes'][$i]['propertyFlags'] & $required) === $required) {
            return $i;
        }
    }

    return -1;
};

$reqBlock = $keep(Bridge::alloc(VkMemoryRequirements::size()), 'alloc VkMemoryRequirements');

/** Allocate device memory for the requirements sitting in $reqBlock. */
$allocateFor = static function (int $required, string $what) use ($keep, $reqBlock, $memoryTypeIndex, $device, $ok): array {
    $req = VkMemoryRequirements::unpack($reqBlock);
    $type = $memoryTypeIndex($req['memoryTypeBits'], $required);
    $type >= 0 || fail("{$what}: no memory type with flags {$required} in memoryTypeBits {$req['memoryTypeBits']}");

    $info = $keep(VkMemoryAllocateInfo::pack([
        'sType' => VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO,
        'allocationSize' => $req['size'],
        'memoryTypeIndex' => $type,
    ]), "VkMemoryAllocateInfo::pack({$what})");

    $out = $keep(Bridge::alloc(8), "alloc memory handle ({$what})");
    $ok(VK10::vkAllocateMemory($device, $info, 0, $out), "vkAllocateMemory({$what})");
    $memory = unpack('P', Bridge::read($out, 0, 8))[1];
    $memory !== 0 || fail("vkAllocateMemory({$what}) wrote a null handle");

    return [$memory, $req['size']];
};

$imageInfo = $keep(VkImageCreateInfo::pack([
    'sType' => VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO,
    'imageType' => VK_IMAGE_TYPE_2D,
    'format' => VK_FORMAT_R8G8B8A8_UNORM,
    'extent' => ['width' => WIDTH, 'height' => HEIGHT, 'depth' => 1],
    'mipLevels' => 1,
    'arrayLayers' => 1,
    'samples' => VK_SAMPLE_COUNT_1_BIT,
    'tiling' => VK_IMAGE_TILING_OPTIMAL,
    'usage' => VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT | VK_IMAGE_USAGE_TRANSFER_SRC_BIT,
    'sharingMode' => VK_SHARING_MODE_EXCLUSIVE,
    'initialLayout' => VK_IMAGE_LAYOUT_UNDEFINED,
]), 'VkImageCreateInfo::pack');

$imageOut = $keep(Bridge::alloc(8), 'alloc image handle');
$ok(VK10::vkCreateImage($device, $imageInfo, 0, $imageOut), 'vkCreateImage');
$image = $handleAt($imageOut);

VK10::vkGetImageMemoryRequirements($device, $image, $reqBlock);
[$imageMemory] = $allocateFor(VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT, 'colour image');
$ok(VK10::vkBindImageMemory($device, $image, $imageMemory, 0), 'vkBindImageMemory');

$viewInfo = $keep(VkImageViewCreateInfo::pack([
    'sType' => VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
    'image' => $image,
    'viewType' => VK_IMAGE_VIEW_TYPE_2D,
    'format' => VK_FORMAT_R8G8B8A8_UNORM,
    'components' => [
        'r' => VK_COMPONENT_SWIZZLE_IDENTITY,
        'g' => VK_COMPONENT_SWIZZLE_IDENTITY,
        'b' => VK_COMPONENT_SWIZZLE_IDENTITY,
        'a' => VK_COMPONENT_SWIZZLE_IDENTITY,
    ],
    'subresourceRange' => [
        'aspectMask' => VK_IMAGE_ASPECT_COLOR_BIT,
        'baseMipLevel' => 0,
        'levelCount' => 1,
        'baseArrayLayer' => 0,
        'layerCount' => 1,
    ],
]), 'VkImageViewCreateInfo::pack');

$viewOut = $keep(Bridge::alloc(8), 'alloc image view handle');
$ok(VK10::vkCreateImageView($device, $viewInfo, 0, $viewOut), 'vkCreateImageView');
$imageView = $handleAt($viewOut);

/* -- 5. Render pass and framebuffer ----------------------------------------- */

$attachments = $keep(Bridge::alloc(VkAttachmentDescription::size()), 'alloc VkAttachmentDescription[1]');
VkAttachmentDescription::packInto($attachments, [
    'format' => VK_FORMAT_R8G8B8A8_UNORM,
    'samples' => VK_SAMPLE_COUNT_1_BIT,
    'loadOp' => VK_ATTACHMENT_LOAD_OP_CLEAR,
    'storeOp' => VK_ATTACHMENT_STORE_OP_STORE,
    'stencilLoadOp' => VK_ATTACHMENT_LOAD_OP_DONT_CARE,
    'stencilStoreOp' => VK_ATTACHMENT_STORE_OP_DONT_CARE,
    'initialLayout' => VK_IMAGE_LAYOUT_UNDEFINED,
    'finalLayout' => VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
]);

$colorRefs = $keep(Bridge::alloc(VkAttachmentReference::size()), 'alloc VkAttachmentReference[1]');
VkAttachmentReference::packInto($colorRefs, [
    'attachment' => 0,
    'layout' => VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL,
]);

$subpasses = $keep(Bridge::alloc(VkSubpassDescription::size()), 'alloc VkSubpassDescription[1]');
VkSubpassDescription::packInto($subpasses, [
    'pipelineBindPoint' => VK_PIPELINE_BIND_POINT_GRAPHICS,
    'colorAttachmentCount' => 1,
    'pColorAttachments' => $colorRefs,
]);

/*
 * The colour write has to be finished and visible before vkCmdCopyImageToBuffer
 * reads the image. The implicit subpass-to-EXTERNAL dependency ends at
 * BOTTOM_OF_PIPE with an empty access mask, which makes the write available but
 * not visible to a transfer read, so the dependency is spelled out here.
 */
$dependencies = $keep(Bridge::alloc(VkSubpassDependency::size()), 'alloc VkSubpassDependency[1]');
VkSubpassDependency::packInto($dependencies, [
    'srcSubpass' => 0,
    'dstSubpass' => VK_SUBPASS_EXTERNAL,
    'srcStageMask' => VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT,
    'dstStageMask' => VK_PIPELINE_STAGE_TRANSFER_BIT,
    'srcAccessMask' => VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT,
    'dstAccessMask' => VK_ACCESS_TRANSFER_READ_BIT,
]);

$renderPassInfo = $keep(VkRenderPassCreateInfo::pack([
    'sType' => VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO,
    'attachmentCount' => 1,
    'pAttachments' => $attachments,
    'subpassCount' => 1,
    'pSubpasses' => $subpasses,
    'dependencyCount' => 1,
    'pDependencies' => $dependencies,
]), 'VkRenderPassCreateInfo::pack');

$renderPassOut = $keep(Bridge::alloc(8), 'alloc render pass handle');
$ok(VK10::vkCreateRenderPass($device, $renderPassInfo, 0, $renderPassOut), 'vkCreateRenderPass');
$renderPass = $handleAt($renderPassOut);

$fbAttachments = $keep(Bridge::alloc(8), 'alloc framebuffer attachment array');
$putHandle($fbAttachments, 0, $imageView);

$framebufferInfo = $keep(VkFramebufferCreateInfo::pack([
    'sType' => VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO,
    'renderPass' => $renderPass,
    'attachmentCount' => 1,
    'pAttachments' => $fbAttachments,
    'width' => WIDTH,
    'height' => HEIGHT,
    'layers' => 1,
]), 'VkFramebufferCreateInfo::pack');

$framebufferOut = $keep(Bridge::alloc(8), 'alloc framebuffer handle');
$ok(VK10::vkCreateFramebuffer($device, $framebufferInfo, 0, $framebufferOut), 'vkCreateFramebuffer');
$framebuffer = $handleAt($framebufferOut);

/* -- 6. Shader modules from the vendored SPIR-V ----------------------------- */

/** Upload one .spv file and create its VkShaderModule. */
$shaderModule = static function (string $file) use ($keep, $device, $ok): int {
    $path = __DIR__ . '/shaders/' . $file;
    $code = @file_get_contents($path);
    is_string($code) && $code !== '' || fail("cannot read {$path}");
    strlen($code) % 4 === 0 || fail("{$file} is not a whole number of SPIR-V words");

    $bytes = $keep(Bridge::alloc(strlen($code)), "alloc {$file}");
    Bridge::write($bytes, 0, $code) || fail("Bridge::write {$file}");

    $info = $keep(VkShaderModuleCreateInfo::pack([
        'sType' => VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO,
        'codeSize' => strlen($code),
        'pCode' => $bytes,
    ]), "VkShaderModuleCreateInfo::pack({$file})");

    $out = $keep(Bridge::alloc(8), "alloc shader module handle ({$file})");
    $ok(VK10::vkCreateShaderModule($device, $info, 0, $out), "vkCreateShaderModule({$file})");

    return unpack('P', Bridge::read($out, 0, 8))[1];
};

$vertModule = $shaderModule('triangle.vert.spv');
$fragModule = $shaderModule('triangle.frag.spv');

/* -- 7. Pipeline layout and graphics pipeline -------------------------------- */

$layoutInfo = $keep(VkPipelineLayoutCreateInfo::pack([
    'sType' => VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO,
]), 'VkPipelineLayoutCreateInfo::pack');

$layoutOut = $keep(Bridge::alloc(8), 'alloc pipeline layout handle');
$ok(VK10::vkCreatePipelineLayout($device, $layoutInfo, 0, $layoutOut), 'vkCreatePipelineLayout');
$pipelineLayout = $handleAt($layoutOut);

$entryPoint = $keep(Bridge::cstring('main'), 'Bridge::cstring(main)');

$stages = $keep(Bridge::alloc(2 * VkPipelineShaderStageCreateInfo::size()), 'alloc VkPipelineShaderStageCreateInfo[2]');
VkPipelineShaderStageCreateInfo::packInto($stages, [
    'sType' => VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO,
    'stage' => VK_SHADER_STAGE_VERTEX_BIT,
    'module' => $vertModule,
    'pName' => $entryPoint,
]);
VkPipelineShaderStageCreateInfo::packInto($stages + VkPipelineShaderStageCreateInfo::size(), [
    'sType' => VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO,
    'stage' => VK_SHADER_STAGE_FRAGMENT_BIT,
    'module' => $fragModule,
    'pName' => $entryPoint,
]);

$bindings = $keep(Bridge::alloc(VkVertexInputBindingDescription::size()), 'alloc VkVertexInputBindingDescription[1]');
VkVertexInputBindingDescription::packInto($bindings, [
    'binding' => 0,
    'stride' => 8,                          // vec2 of 32-bit floats
    'inputRate' => VK_VERTEX_INPUT_RATE_VERTEX,
]);

$attributes = $keep(Bridge::alloc(VkVertexInputAttributeDescription::size()), 'alloc VkVertexInputAttributeDescription[1]');
VkVertexInputAttributeDescription::packInto($attributes, [
    'location' => 0,
    'binding' => 0,
    'format' => VK_FORMAT_R32G32_SFLOAT,
    'offset' => 0,
]);

$vertexInputState = $keep(VkPipelineVertexInputStateCreateInfo::pack([
    'sType' => VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO,
    'vertexBindingDescriptionCount' => 1,
    'pVertexBindingDescriptions' => $bindings,
    'vertexAttributeDescriptionCount' => 1,
    'pVertexAttributeDescriptions' => $attributes,
]), 'VkPipelineVertexInputStateCreateInfo::pack');

$inputAssemblyState = $keep(VkPipelineInputAssemblyStateCreateInfo::pack([
    'sType' => VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO,
    'topology' => VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST,
    'primitiveRestartEnable' => false,
]), 'VkPipelineInputAssemblyStateCreateInfo::pack');

$viewports = $keep(Bridge::alloc(VkViewport::size()), 'alloc VkViewport[1]');
VkViewport::packInto($viewports, [
    'x' => 0.0,
    'y' => 0.0,
    'width' => (float) WIDTH,
    'height' => (float) HEIGHT,
    'minDepth' => 0.0,
    'maxDepth' => 1.0,
]);

$scissors = $keep(Bridge::alloc(VkRect2D::size()), 'alloc VkRect2D[1]');
VkRect2D::packInto($scissors, [
    'offset' => ['x' => 0, 'y' => 0],
    'extent' => ['width' => WIDTH, 'height' => HEIGHT],
]);

$viewportState = $keep(VkPipelineViewportStateCreateInfo::pack([
    'sType' => VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO,
    'viewportCount' => 1,
    'pViewports' => $viewports,
    'scissorCount' => 1,
    'pScissors' => $scissors,
]), 'VkPipelineViewportStateCreateInfo::pack');

$rasterizationState = $keep(VkPipelineRasterizationStateCreateInfo::pack([
    'sType' => VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO,
    'depthClampEnable' => false,
    'rasterizerDiscardEnable' => false,
    'polygonMode' => VK_POLYGON_MODE_FILL,
    'cullMode' => VK_CULL_MODE_NONE,
    'frontFace' => VK_FRONT_FACE_COUNTER_CLOCKWISE,
    'depthBiasEnable' => false,
    'lineWidth' => 1.0,                     // MoltenVK has no wide lines; 1.0 is always legal
]), 'VkPipelineRasterizationStateCreateInfo::pack');

$multisampleState = $keep(VkPipelineMultisampleStateCreateInfo::pack([
    'sType' => VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO,
    'rasterizationSamples' => VK_SAMPLE_COUNT_1_BIT,
    'sampleShadingEnable' => false,
    'minSampleShading' => 0.0,
    'alphaToCoverageEnable' => false,
    'alphaToOneEnable' => false,
]), 'VkPipelineMultisampleStateCreateInfo::pack');

$blendAttachments = $keep(Bridge::alloc(VkPipelineColorBlendAttachmentState::size()), 'alloc VkPipelineColorBlendAttachmentState[1]');
VkPipelineColorBlendAttachmentState::packInto($blendAttachments, [
    'blendEnable' => false,
    'srcColorBlendFactor' => VK_BLEND_FACTOR_ONE,
    'dstColorBlendFactor' => VK_BLEND_FACTOR_ZERO,
    'colorBlendOp' => VK_BLEND_OP_ADD,
    'srcAlphaBlendFactor' => VK_BLEND_FACTOR_ONE,
    'dstAlphaBlendFactor' => VK_BLEND_FACTOR_ZERO,
    'alphaBlendOp' => VK_BLEND_OP_ADD,
    'colorWriteMask' => VK_COLOR_COMPONENT_RGBA_BITS,
]);

$colorBlendState = $keep(VkPipelineColorBlendStateCreateInfo::pack([
    'sType' => VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO,
    'logicOpEnable' => false,
    'logicOp' => VK_LOGIC_OP_COPY,
    'attachmentCount' => 1,
    'pAttachments' => $blendAttachments,
    'blendConstants' => [0.0, 0.0, 0.0, 0.0],
]), 'VkPipelineColorBlendStateCreateInfo::pack');

$pipelineInfo = $keep(VkGraphicsPipelineCreateInfo::pack([
    'sType' => VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO,
    'stageCount' => 2,
    'pStages' => $stages,
    'pVertexInputState' => $vertexInputState,
    'pInputAssemblyState' => $inputAssemblyState,
    'pViewportState' => $viewportState,
    'pRasterizationState' => $rasterizationState,
    'pMultisampleState' => $multisampleState,
    'pColorBlendState' => $colorBlendState,
    'layout' => $pipelineLayout,
    'renderPass' => $renderPass,
    'subpass' => 0,
    'basePipelineHandle' => 0,
    'basePipelineIndex' => -1,
]), 'VkGraphicsPipelineCreateInfo::pack');

$pipelineOut = $keep(Bridge::alloc(8), 'alloc pipeline handle');
$ok(VK10::vkCreateGraphicsPipelines($device, 0, 1, $pipelineInfo, 0, $pipelineOut), 'vkCreateGraphicsPipelines');
$pipeline = $handleAt($pipelineOut);
$pipeline !== 0 || fail('vkCreateGraphicsPipelines wrote a null handle');

/* -- 8. Vertex buffer, written through vkMapMemory's pointer ---------------- */

/*
 * Three clip-space vertices. Vulkan's Y axis points down, and cullMode is NONE,
 * so the winding does not matter; what matters is that the triangle covers the
 * centre of the image and none of its corners.
 */
$vertexData = pack('f*', -0.5, 0.5, 0.5, 0.5, 0.0, -0.5);
strlen($vertexData) === 24 || fail('vertex data is not 24 bytes');

$vertexBufferInfo = $keep(VkBufferCreateInfo::pack([
    'sType' => VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO,
    'size' => strlen($vertexData),
    'usage' => VK_BUFFER_USAGE_VERTEX_BUFFER_BIT,
    'sharingMode' => VK_SHARING_MODE_EXCLUSIVE,
]), 'VkBufferCreateInfo::pack(vertex)');

$vertexBufferOut = $keep(Bridge::alloc(8), 'alloc vertex buffer handle');
$ok(VK10::vkCreateBuffer($device, $vertexBufferInfo, 0, $vertexBufferOut), 'vkCreateBuffer(vertex)');
$vertexBuffer = $handleAt($vertexBufferOut);

VK10::vkGetBufferMemoryRequirements($device, $vertexBuffer, $reqBlock);
[$vertexMemory] = $allocateFor(
    VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT,
    'vertex buffer'
);

$mappedOut = $keep(Bridge::alloc(8), 'alloc mapped pointer');
$ok(VK10::vkMapMemory($device, $vertexMemory, 0, VK_WHOLE_SIZE, 0, $mappedOut), 'vkMapMemory(vertex)');
$mapped = $handleAt($mappedOut);
$mapped !== 0 || fail('vkMapMemory(vertex) wrote a null pointer');

/*
 * $mapped is the driver's memory, not a block this extension allocated, so
 * Bridge::write has no extent to bounds-check it against and writes it as
 * given — the price of the pointer rule (.okf/traps/pointer-bits-only.md).
 */
Bridge::write($mapped, 0, $vertexData) || fail('Bridge::write vertex data');
VK10::vkUnmapMemory($device, $vertexMemory);
$ok(VK10::vkBindBufferMemory($device, $vertexBuffer, $vertexMemory, 0), 'vkBindBufferMemory(vertex)');

/* -- 9. Host-visible readback buffer ---------------------------------------- */

$readBufferInfo = $keep(VkBufferCreateInfo::pack([
    'sType' => VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO,
    'size' => IMAGE_BYTES,
    'usage' => VK_BUFFER_USAGE_TRANSFER_DST_BIT,
    'sharingMode' => VK_SHARING_MODE_EXCLUSIVE,
]), 'VkBufferCreateInfo::pack(readback)');

$readBufferOut = $keep(Bridge::alloc(8), 'alloc readback buffer handle');
$ok(VK10::vkCreateBuffer($device, $readBufferInfo, 0, $readBufferOut), 'vkCreateBuffer(readback)');
$readBuffer = $handleAt($readBufferOut);

VK10::vkGetBufferMemoryRequirements($device, $readBuffer, $reqBlock);
[$readMemory] = $allocateFor(
    VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT,
    'readback buffer'
);
$ok(VK10::vkBindBufferMemory($device, $readBuffer, $readMemory, 0), 'vkBindBufferMemory(readback)');

/* -- 10. Command pool, command buffer, recording ---------------------------- */

$poolInfo = $keep(VkCommandPoolCreateInfo::pack([
    'sType' => VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO,
    'queueFamilyIndex' => $queueFamily,
]), 'VkCommandPoolCreateInfo::pack');

$poolOut = $keep(Bridge::alloc(8), 'alloc command pool handle');
$ok(VK10::vkCreateCommandPool($device, $poolInfo, 0, $poolOut), 'vkCreateCommandPool');
$commandPool = $handleAt($poolOut);

$cmdAllocInfo = $keep(VkCommandBufferAllocateInfo::pack([
    'sType' => VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO,
    'commandPool' => $commandPool,
    'level' => VK_COMMAND_BUFFER_LEVEL_PRIMARY,
    'commandBufferCount' => 1,
]), 'VkCommandBufferAllocateInfo::pack');

$commandBuffers = $keep(Bridge::alloc(8), 'alloc command buffer array');
$ok(VK10::vkAllocateCommandBuffers($device, $cmdAllocInfo, $commandBuffers), 'vkAllocateCommandBuffers');
$commandBuffer = $handleAt($commandBuffers);
$commandBuffer !== 0 || fail('vkAllocateCommandBuffers wrote a null handle');

$beginInfo = $keep(VkCommandBufferBeginInfo::pack([
    'sType' => VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO,
    'flags' => VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT,
]), 'VkCommandBufferBeginInfo::pack');

$clearValues = $keep(VkClearValue::pack([
    'color' => ['float32' => [0.0, 0.0, 0.0, 1.0]],
]), 'VkClearValue::pack');

$renderPassBegin = $keep(VkRenderPassBeginInfo::pack([
    'sType' => VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO,
    'renderPass' => $renderPass,
    'framebuffer' => $framebuffer,
    'renderArea' => [
        'offset' => ['x' => 0, 'y' => 0],
        'extent' => ['width' => WIDTH, 'height' => HEIGHT],
    ],
    'clearValueCount' => 1,
    'pClearValues' => $clearValues,
]), 'VkRenderPassBeginInfo::pack');

$vertexBuffers = $keep(Bridge::alloc(8), 'alloc vertex buffer array');
$putHandle($vertexBuffers, 0, $vertexBuffer);
$vertexOffsets = $keep(Bridge::alloc(8), 'alloc vertex offset array');   // one VkDeviceSize, zero

$regions = $keep(VkBufferImageCopy::pack([
    'bufferOffset' => 0,
    'bufferRowLength' => 0,                 // 0 = tightly packed, WIDTH texels per row
    'bufferImageHeight' => 0,
    'imageSubresource' => [
        'aspectMask' => VK_IMAGE_ASPECT_COLOR_BIT,
        'mipLevel' => 0,
        'baseArrayLayer' => 0,
        'layerCount' => 1,
    ],
    'imageOffset' => ['x' => 0, 'y' => 0, 'z' => 0],
    'imageExtent' => ['width' => WIDTH, 'height' => HEIGHT, 'depth' => 1],
]), 'VkBufferImageCopy::pack');

$ok(VK10::vkBeginCommandBuffer($commandBuffer, $beginInfo), 'vkBeginCommandBuffer');
VK10::vkCmdBeginRenderPass($commandBuffer, $renderPassBegin, VK_SUBPASS_CONTENTS_INLINE);
VK10::vkCmdBindPipeline($commandBuffer, VK_PIPELINE_BIND_POINT_GRAPHICS, $pipeline);
VK10::vkCmdBindVertexBuffers($commandBuffer, 0, 1, $vertexBuffers, $vertexOffsets);
VK10::vkCmdDraw($commandBuffer, 3, 1, 0, 0);
VK10::vkCmdEndRenderPass($commandBuffer);
VK10::vkCmdCopyImageToBuffer($commandBuffer, $image, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, $readBuffer, 1, $regions);
$ok(VK10::vkEndCommandBuffer($commandBuffer), 'vkEndCommandBuffer');

/* -- 11. Submit and wait ---------------------------------------------------- */

$submitInfo = $keep(VkSubmitInfo::pack([
    'sType' => VK_STRUCTURE_TYPE_SUBMIT_INFO,
    'commandBufferCount' => 1,
    'pCommandBuffers' => $commandBuffers,
]), 'VkSubmitInfo::pack');

$ok(VK10::vkQueueSubmit($queue, 1, $submitInfo, 0), 'vkQueueSubmit');
$ok(VK10::vkQueueWaitIdle($queue), 'vkQueueWaitIdle');

/* -- 12. Read the pixels back ----------------------------------------------- */

$ok(VK10::vkMapMemory($device, $readMemory, 0, VK_WHOLE_SIZE, 0, $mappedOut), 'vkMapMemory(readback)');
$readPtr = $handleAt($mappedOut);
$readPtr !== 0 || fail('vkMapMemory(readback) wrote a null pointer');

$pixels = Bridge::read($readPtr, 0, IMAGE_BYTES);
strlen($pixels) === IMAGE_BYTES || fail('Bridge::read returned ' . strlen($pixels) . ' bytes, wanted ' . IMAGE_BYTES);

$pixelAt = static function (string $bytes, int $x, int $y): array {
    $o = ($y * WIDTH + $x) * PIXEL_BYTES;

    return [ord($bytes[$o]), ord($bytes[$o + 1]), ord($bytes[$o + 2]), ord($bytes[$o + 3])];
};

$centre = $pixelAt($pixels, 32, 32);
$corner = $pixelAt($pixels, 0, 0);

printf("pixel(32,32): %d,%d,%d,%d\n", ...$centre);
printf("pixel(0,0): %d,%d,%d,%d\n", ...$corner);

VK10::vkUnmapMemory($device, $readMemory);

/*
 * (1.0, 0.5, 0.25, 1.0) through an R8G8B8A8_UNORM attachment is 255, 127.5, 63.75,
 * 255; the rounding direction is the implementation's, so each channel is allowed
 * one unit of slack. The clear colour is exact.
 */
$wantCentre = [255, 128, 64, 255];
foreach ($wantCentre as $c => $want) {
    if (abs($centre[$c] - $want) > 1) {
        fail('pixel(32,32) is ' . implode(',', $centre) . ', wanted ' . implode(',', $wantCentre) . ' +/-1 per channel');
    }
}
if ($corner !== [0, 0, 0, 255]) {
    fail('pixel(0,0) is ' . implode(',', $corner) . ', wanted 0,0,0,255');
}

/* -- 13. Tear everything down in reverse ------------------------------------ */

VK10::vkDestroyCommandPool($device, $commandPool, 0);       // frees its command buffers
VK10::vkDestroyBuffer($device, $readBuffer, 0);
VK10::vkFreeMemory($device, $readMemory, 0);
VK10::vkDestroyBuffer($device, $vertexBuffer, 0);
VK10::vkFreeMemory($device, $vertexMemory, 0);
VK10::vkDestroyPipeline($device, $pipeline, 0);
VK10::vkDestroyPipelineLayout($device, $pipelineLayout, 0);
VK10::vkDestroyShaderModule($device, $fragModule, 0);
VK10::vkDestroyShaderModule($device, $vertModule, 0);
VK10::vkDestroyFramebuffer($device, $framebuffer, 0);
VK10::vkDestroyRenderPass($device, $renderPass, 0);
VK10::vkDestroyImageView($device, $imageView, 0);
VK10::vkDestroyImage($device, $image, 0);
VK10::vkFreeMemory($device, $imageMemory, 0);
VK10::vkDestroyDevice($device, 0);
VK10::vkDestroyInstance($instance, 0);

foreach (array_reverse($blocks) as $b) {
    Bridge::free($b);
}
$blocks = [];

echo "PROOF_HEADLESS_OK\n";
