<?php

declare(strict_types=1);

/**
 * Generate stubs/vk_constants.stub.php from a vulkan_core.h.
 *
 * The type list is the enums and flags the bound signatures and structs use.
 * VkStructureType is omitted: sType is filled by the binding, never a property.
 * Members come from the Pi's 1.4.309 header so the stub compiles against a newer one.
 *
 *   php tools/vk-constants.php /path/to/vulkan_core.h
 */

$types = [
    'VkResult',
    'VkFormat',
    'VkImageType',
    'VkImageTiling',
    'VkImageUsageFlagBits',
    'VkImageLayout',
    'VkImageAspectFlagBits',
    'VkImageViewType',
    'VkSampleCountFlagBits',
    'VkSharingMode',
    'VkMemoryPropertyFlagBits',
    'VkBufferUsageFlagBits',
    'VkFilter',
    'VkSamplerMipmapMode',
    'VkSamplerAddressMode',
    'VkBorderColor',
    'VkCompareOp',
    'VkStencilOp',
    'VkAttachmentLoadOp',
    'VkAttachmentStoreOp',
    'VkPipelineBindPoint',
    'VkPipelineStageFlagBits',
    'VkAccessFlagBits',
    'VkDependencyFlagBits',
    'VkShaderStageFlagBits',
    'VkVertexInputRate',
    'VkPrimitiveTopology',
    'VkPolygonMode',
    'VkCullModeFlagBits',
    'VkFrontFace',
    'VkLogicOp',
    'VkBlendFactor',
    'VkBlendOp',
    'VkColorComponentFlagBits',
    'VkDynamicState',
    'VkDescriptorType',
    'VkCommandPoolCreateFlagBits',
    'VkCommandBufferLevel',
    'VkCommandBufferUsageFlagBits',
    'VkSubpassContents',
    'VkIndexType',
    'VkFenceCreateFlagBits',
    'VkQueueFlagBits',
    'VkPhysicalDeviceType',
    'VkFormatFeatureFlagBits',
    'VkComponentSwizzle',
    'VkPresentModeKHR',
    'VkColorSpaceKHR',
    'VkCompositeAlphaFlagBitsKHR',
    'VkSurfaceTransformFlagBitsKHR',
    'VkExternalMemoryHandleTypeFlagBits',
    'VkInstanceCreateFlagBits',
    'VkStencilFaceFlagBits',
];

$extensionNames = [
    'VK_KHR_SURFACE_EXTENSION_NAME',
    'VK_KHR_SWAPCHAIN_EXTENSION_NAME',
    'VK_KHR_EXTERNAL_MEMORY_FD_EXTENSION_NAME',
    'VK_EXT_EXTERNAL_MEMORY_DMA_BUF_EXTENSION_NAME',
    'VK_EXT_IMAGE_DRM_FORMAT_MODIFIER_EXTENSION_NAME',
    'VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME',
];

$path = $argv[1] ?? null;
$also = $argv[2] ?? null;
if (! is_string($path) || ! is_file($path)) {
    fwrite(STDERR, "usage: php tools/vk-constants.php /path/to/vulkan_core.h [newer-vulkan_core.h]\n");
    exit(1);
}

$header = file_get_contents($path);
if (! is_string($header)) {
    fwrite(STDERR, "could not read {$path}\n");
    exit(1);
}
$header = preg_replace('/#ifdef VK_ENABLE_BETA_EXTENSIONS\R.*?\R#endif/', '', $header) ?? $header;

$alsoHeader = null;
if (is_string($also)) {
    if (! is_file($also)) {
        fwrite(STDERR, "could not read {$also}\n");
        exit(1);
    }
    $alsoHeader = file_get_contents($also);
}

preg_match('/#define\s+VK_HEADER_VERSION\s+(\d+)/', $header, $version) || throw new RuntimeException('VK_HEADER_VERSION not found');
$headerVersion = $version[1];

/** @return list<array{0: string, 1: string}> */
function enumMembers(string $header, string $type): array
{
    $pattern = '/typedef\s+enum\s+' . preg_quote($type, '/') . '\s*\{(.*?)\n\}/s';
    if (! preg_match($pattern, $header, $match)) {
        return [];
    }

    $members = [];
    foreach (preg_split('/\n/', $match[1]) as $line) {
        $line = preg_replace('#/\*.*?\*/#', '', $line) ?? $line;
        $line = preg_replace('#//.*$#', '', $line) ?? $line;
        if (preg_match('/^\s*(VK_[A-Z0-9_]+)\s*=\s*([^,]+)/', $line, $member)) {
            $members[] = [$member[1], trim($member[2])];
        }
    }

    return $members;
}

/** @return list<array{0: string, 1: string}> */
function staticMembers(string $header, string $type): array
{
    $pattern = '/static\s+const\s+' . preg_quote($type, '/') . '\s+(VK_[A-Z0-9_]+)\s*=\s*([^;]+);/';
    preg_match_all($pattern, $header, $matches, PREG_SET_ORDER);
    $members = [];
    foreach ($matches as $match) {
        $members[] = [$match[1], trim($match[2])];
    }

    return $members;
}

$collected = [];
foreach ($types as $type) {
    foreach ([...enumMembers($header, $type), ...staticMembers($header, $type)] as [$name, $value]) {
        $collected[$name] = $value;
    }
}

$names = array_keys($collected);
$kept = [];
foreach ($collected as $name => $value) {
    if (str_ends_with($name, '_MAX_ENUM')) {
        continue;
    }
    if (preg_match('/^[A-Za-z_][A-Za-z0-9_]*$/', $value) === 1 && in_array($value, $names, true)) {
        continue;
    }
    // A name present on the floor header but removed from a newer one would not compile there.
    if (is_string($alsoHeader) && preg_match('/\b' . preg_quote($name, '/') . '\b/', $alsoHeader) !== 1) {
        continue;
    }
    $kept[$name] = $value;
}

$out = [];
$out[] = '<?php';
$out[] = '';
$out[] = '/** @generate-class-entries */';
$out[] = '';
$out[] = '/** Generated from vulkan_core.h VK_HEADER_VERSION ' . $headerVersion . '. */';
$out[] = '';

$emitInt = static function (string $name, ?string $cvalue = null) use (&$out): void {
    $out[] = '/**';
    $out[] = ' * @var int';
    if (is_string($cvalue)) {
        $out[] = ' * @cvalue ' . $cvalue;
    }
    $out[] = ' */';
    $out[] = $cvalue === null ? "const {$name} = 0;" : "const {$name} = UNKNOWN;";
    $out[] = '';
};

$emitString = static function (string $name, ?string $literal = null) use (&$out): void {
    $out[] = '/**';
    $out[] = ' * @var string';
    if ($literal === null) {
        $out[] = ' * @cvalue ' . $name;
    }
    $out[] = ' */';
    $out[] = $literal === null ? "const {$name} = UNKNOWN;" : 'const ' . $name . ' = ' . var_export($literal, true) . ';';
    $out[] = '';
};

foreach (array_keys($kept) as $name) {
    $emitInt($name, $name);
}

foreach ([
    'VK_API_VERSION_1_3',
    'VK_WHOLE_SIZE',
    'VK_QUEUE_FAMILY_IGNORED',
    'VK_SUBPASS_EXTERNAL',
    'VK_TRUE',
    'VK_FALSE',
] as $name) {
    $emitInt($name, $name);
}

$emitInt('VK_NULL_HANDLE', null);

foreach ($extensionNames as $name) {
    $emitString($name);
}

// These macros live outside vulkan_core.h: portability subset in vulkan_beta.h, metal surface in vulkan_metal.h.
$emitString('VK_KHR_PORTABILITY_SUBSET_EXTENSION_NAME', 'VK_KHR_portability_subset');
$emitString('VK_EXT_METAL_SURFACE_EXTENSION_NAME', 'VK_EXT_metal_surface');

$out[] = '/** An address of 0 is refused. Any other address is trusted. */';
$out[] = 'function vk_read_mapped(int $address, int $size): string {}';
$out[] = '';
$out[] = '/** An address of 0 is refused. Any other address is trusted. */';
$out[] = 'function vk_write_mapped(int $address, string $bytes): void {}';
$out[] = '';

$target = dirname(__DIR__) . '/stubs/vk_constants.stub.php';
if (! is_dir(dirname($target))) {
    mkdir(dirname($target), 0777, true);
}
file_put_contents($target, implode("\n", $out));
fwrite(STDOUT, 'wrote ' . $target . ' (' . count($kept) . " enum members, header {$headerVersion})\n");
