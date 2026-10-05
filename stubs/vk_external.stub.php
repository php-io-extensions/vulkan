<?php

/** @generate-class-entries */

/** @not-serializable */
final class VkExternalMemoryImageCreateInfo
{
    public ?object $pNext = null;

    public int $handleTypes = 0;
}

/** @not-serializable */
final class VkExportMemoryAllocateInfo
{
    public ?object $pNext = null;

    public int $handleTypes = 0;
}

/** @not-serializable */
final class VkMemoryGetFdInfoKHR
{
    public ?object $pNext = null;

    public ?VkDeviceMemory $memory = null;

    public int $handleType = 0;
}

/** @not-serializable */
final class VkImageDrmFormatModifierListCreateInfoEXT
{
    public ?object $pNext = null;

    public array $pDrmFormatModifiers = [];
}

/** @not-serializable */
final class VkImageDrmFormatModifierPropertiesEXT
{
    public int $drmFormatModifier = 0;
}

/** @not-serializable */
final class VkImageSubresource
{
    public int $aspectMask = 0;

    public int $mipLevel = 0;

    public int $arrayLayer = 0;
}

/** @not-serializable */
final class VkSubresourceLayout
{
    public int $offset = 0;

    public int $size = 0;

    public int $rowPitch = 0;

    public int $arrayPitch = 0;

    public int $depthPitch = 0;
}

function vkGetMemoryFdKHR(VkDevice $device, VkMemoryGetFdInfoKHR $pGetFdInfo, ?int &$pFd): int {}

function vkGetImageDrmFormatModifierPropertiesEXT(VkDevice $device, VkImage $image, ?VkImageDrmFormatModifierPropertiesEXT &$pProperties): int {}

function vkGetImageSubresourceLayout(VkDevice $device, VkImage $image, VkImageSubresource $pSubresource, ?VkSubresourceLayout &$pLayout): void {}
