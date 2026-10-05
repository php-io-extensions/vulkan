<?php

/** @generate-class-entries */

/**
 * @not-serializable
 */
final class VkDeviceMemory
{
    private function __construct() {}

    public function pointer(): int {}

    public static function fromPointer(int $pointer): static {}
}

/**
 * @not-serializable
 */
final class VkBuffer
{
    private function __construct() {}

    public function pointer(): int {}

    public static function fromPointer(int $pointer): static {}
}

/**
 * @not-serializable
 */
final class VkImage
{
    private function __construct() {}

    public function pointer(): int {}

    public static function fromPointer(int $pointer): static {}
}

/**
 * @not-serializable
 */
final class VkImageView
{
    private function __construct() {}

    public function pointer(): int {}

    public static function fromPointer(int $pointer): static {}
}

/**
 * @not-serializable
 */
final class VkSampler
{
    private function __construct() {}

    public function pointer(): int {}

    public static function fromPointer(int $pointer): static {}
}

/**
 * @not-serializable
 */
final class VkMemoryAllocateInfo
{
    public ?object $pNext = null;

    public int $allocationSize = 0;

    public int $memoryTypeIndex = 0;
}

/**
 * @not-serializable
 */
final class VkMappedMemoryRange
{
    public ?object $pNext = null;

    public ?VkDeviceMemory $memory = null;

    public int $offset = 0;

    public int $size = 0;
}

/**
 * @not-serializable
 */
final class VkBufferCreateInfo
{
    public ?object $pNext = null;

    public int $flags = 0;

    public int $size = 0;

    public int $usage = 0;

    public int $sharingMode = 0;

    public array $pQueueFamilyIndices = [];
}

/**
 * @not-serializable
 */
final class VkMemoryRequirements
{
    public int $size = 0;

    public int $alignment = 0;

    public int $memoryTypeBits = 0;
}

/**
 * @not-serializable
 */
final class VkImageCreateInfo
{
    public ?object $pNext = null;

    public int $flags = 0;

    public int $imageType = 0;

    public int $format = 0;

    public VkExtent3D $extent;

    public int $mipLevels = 0;

    public int $arrayLayers = 0;

    public int $samples = 0;

    public int $tiling = 0;

    public int $usage = 0;

    public int $sharingMode = 0;

    public array $pQueueFamilyIndices = [];

    public int $initialLayout = 0;

    public function __construct() {}
}

/**
 * @not-serializable
 */
final class VkComponentMapping
{
    public int $r = 0;

    public int $g = 0;

    public int $b = 0;

    public int $a = 0;
}

/**
 * @not-serializable
 */
final class VkImageSubresourceRange
{
    public int $aspectMask = 0;

    public int $baseMipLevel = 0;

    public int $levelCount = 0;

    public int $baseArrayLayer = 0;

    public int $layerCount = 0;
}

/**
 * @not-serializable
 */
final class VkImageViewCreateInfo
{
    public ?object $pNext = null;

    public int $flags = 0;

    public ?VkImage $image = null;

    public int $viewType = 0;

    public int $format = 0;

    public VkComponentMapping $components;

    public VkImageSubresourceRange $subresourceRange;

    public function __construct() {}
}

/**
 * @not-serializable
 */
final class VkSamplerCreateInfo
{
    public ?object $pNext = null;

    public int $flags = 0;

    public int $magFilter = 0;

    public int $minFilter = 0;

    public int $mipmapMode = 0;

    public int $addressModeU = 0;

    public int $addressModeV = 0;

    public int $addressModeW = 0;

    public float $mipLodBias = 0.0;

    public bool $anisotropyEnable = false;

    public float $maxAnisotropy = 0.0;

    public bool $compareEnable = false;

    public int $compareOp = 0;

    public float $minLod = 0.0;

    public float $maxLod = 0.0;

    public int $borderColor = 0;

    public bool $unnormalizedCoordinates = false;
}

function vkAllocateMemory(VkDevice $device, VkMemoryAllocateInfo $pAllocateInfo, null $pAllocator, ?VkDeviceMemory &$pMemory): int {}

function vkFreeMemory(VkDevice $device, VkDeviceMemory $memory, null $pAllocator): void {}

function vkMapMemory(VkDevice $device, VkDeviceMemory $memory, int $offset, int $size, int $flags, ?int &$ppData): int {}

function vkUnmapMemory(VkDevice $device, VkDeviceMemory $memory): void {}

function vkFlushMappedMemoryRanges(VkDevice $device, array $pMemoryRanges): int {}

function vkInvalidateMappedMemoryRanges(VkDevice $device, array $pMemoryRanges): int {}

function vkCreateBuffer(VkDevice $device, VkBufferCreateInfo $pCreateInfo, null $pAllocator, ?VkBuffer &$pBuffer): int {}

function vkDestroyBuffer(VkDevice $device, VkBuffer $buffer, null $pAllocator): void {}

function vkGetBufferMemoryRequirements(VkDevice $device, VkBuffer $buffer, ?VkMemoryRequirements &$pMemoryRequirements): void {}

function vkBindBufferMemory(VkDevice $device, VkBuffer $buffer, VkDeviceMemory $memory, int $memoryOffset): int {}

function vkCreateImage(VkDevice $device, VkImageCreateInfo $pCreateInfo, null $pAllocator, ?VkImage &$pImage): int {}

function vkDestroyImage(VkDevice $device, VkImage $image, null $pAllocator): void {}

function vkGetImageMemoryRequirements(VkDevice $device, VkImage $image, ?VkMemoryRequirements &$pMemoryRequirements): void {}

function vkBindImageMemory(VkDevice $device, VkImage $image, VkDeviceMemory $memory, int $memoryOffset): int {}

function vkCreateImageView(VkDevice $device, VkImageViewCreateInfo $pCreateInfo, null $pAllocator, ?VkImageView &$pView): int {}

function vkDestroyImageView(VkDevice $device, VkImageView $imageView, null $pAllocator): void {}

function vkCreateSampler(VkDevice $device, VkSamplerCreateInfo $pCreateInfo, null $pAllocator, ?VkSampler &$pSampler): int {}

function vkDestroySampler(VkDevice $device, VkSampler $sampler, null $pAllocator): void {}
