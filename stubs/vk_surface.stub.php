<?php

/** @generate-class-entries */

/**
 * @not-serializable
 */
final class VkSurfaceKHR
{
    private function __construct() {}

    public function pointer(): int {}

    public static function fromPointer(int $pointer): static {}
}

/**
 * @not-serializable
 */
final class VkSwapchainKHR
{
    private function __construct() {}

    public function pointer(): int {}

    public static function fromPointer(int $pointer): static {}
}

/** @not-serializable */
final class VkSurfaceFormatKHR
{
    public int $format = 0;

    public int $colorSpace = 0;
}

/** @not-serializable */
final class VkSurfaceCapabilitiesKHR
{
    public int $minImageCount = 0;

    public int $maxImageCount = 0;

    public VkExtent2D $currentExtent;

    public VkExtent2D $minImageExtent;

    public VkExtent2D $maxImageExtent;

    public int $maxImageArrayLayers = 0;

    public int $supportedTransforms = 0;

    public int $currentTransform = 0;

    public int $supportedCompositeAlpha = 0;

    public int $supportedUsageFlags = 0;

    public function __construct() {}
}

/** @not-serializable */
final class VkSwapchainCreateInfoKHR
{
    public ?object $pNext = null;

    public int $flags = 0;

    public ?VkSurfaceKHR $surface = null;

    public int $minImageCount = 0;

    public int $imageFormat = 0;

    public int $imageColorSpace = 0;

    public VkExtent2D $imageExtent;

    public int $imageArrayLayers = 0;

    public int $imageUsage = 0;

    public int $imageSharingMode = 0;

    public array $pQueueFamilyIndices = [];

    public int $preTransform = 0;

    public int $compositeAlpha = 0;

    public int $presentMode = 0;

    public int $clipped = 0;

    public ?VkSwapchainKHR $oldSwapchain = null;

    public function __construct() {}
}

/** @not-serializable */
final class VkPresentInfoKHR
{
    public ?object $pNext = null;

    public array $pWaitSemaphores = [];

    public array $pSwapchains = [];

    public array $pImageIndices = [];
}

/**
 * VK_KHR_incremental_present: one rectangle of a present region, in swapchain image pixels.
 *
 * @not-serializable
 */
final class VkRectLayerKHR
{
    public VkOffset2D $offset;

    public VkExtent2D $extent;

    public int $layer = 0;

    public function __construct() {}
}

/** @not-serializable */
final class VkPresentRegionKHR
{
    /** @var list<VkRectLayerKHR> */
    public array $pRectangles = [];
}

/**
 * Chained on VkPresentInfoKHR: one region per swapchain, the parts of the image that changed.
 *
 * @not-serializable
 */
final class VkPresentRegionsKHR
{
    public ?object $pNext = null;

    /** @var list<VkPresentRegionKHR> */
    public array $pRegions = [];
}

/**
 * VK_KHR_present_id: chained on VkPresentInfoKHR, one id per swapchain.
 *
 * @not-serializable
 */
final class VkPresentIdKHR
{
    public ?object $pNext = null;

    /** @var list<int> */
    public array $pPresentIds = [];
}

/** @not-serializable */
final class VkPhysicalDevicePresentIdFeaturesKHR
{
    public ?object $pNext = null;

    public bool $presentId = false;
}

/** @not-serializable */
final class VkPhysicalDevicePresentWaitFeaturesKHR
{
    public ?object $pNext = null;

    public bool $presentWait = false;
}

/** @not-serializable */
final class VkXYColorEXT
{
    public float $x = 0.0;

    public float $y = 0.0;
}

/**
 * VK_EXT_hdr_metadata: the mastering display and content light levels, in CIE 1931 xy and nits.
 *
 * @not-serializable
 */
final class VkHdrMetadataEXT
{
    public ?object $pNext = null;

    public VkXYColorEXT $displayPrimaryRed;

    public VkXYColorEXT $displayPrimaryGreen;

    public VkXYColorEXT $displayPrimaryBlue;

    public VkXYColorEXT $whitePoint;

    public float $maxLuminance = 0.0;

    public float $minLuminance = 0.0;

    public float $maxContentLightLevel = 0.0;

    public float $maxFrameAverageLightLevel = 0.0;

    public function __construct() {}
}

function vkGetPhysicalDeviceSurfaceSupportKHR(VkPhysicalDevice $physicalDevice, int $queueFamilyIndex, VkSurfaceKHR $surface, ?bool &$pSupported): int {}

function vkGetPhysicalDeviceSurfaceCapabilitiesKHR(VkPhysicalDevice $physicalDevice, VkSurfaceKHR $surface, ?VkSurfaceCapabilitiesKHR &$pSurfaceCapabilities): int {}

function vkGetPhysicalDeviceSurfaceFormatsKHR(VkPhysicalDevice $physicalDevice, VkSurfaceKHR $surface, ?array &$pSurfaceFormats): int {}

function vkGetPhysicalDeviceSurfacePresentModesKHR(VkPhysicalDevice $physicalDevice, VkSurfaceKHR $surface, ?array &$pPresentModes): int {}

function vkCreateSwapchainKHR(VkDevice $device, VkSwapchainCreateInfoKHR $pCreateInfo, null $pAllocator, ?VkSwapchainKHR &$pSwapchain): int {}

function vkDestroySwapchainKHR(VkDevice $device, VkSwapchainKHR $swapchain, null $pAllocator): void {}

function vkGetSwapchainImagesKHR(VkDevice $device, VkSwapchainKHR $swapchain, ?array &$pSwapchainImages): int {}

function vkAcquireNextImageKHR(VkDevice $device, VkSwapchainKHR $swapchain, int $timeout, ?VkSemaphore $semaphore, ?VkFence $fence, ?int &$pImageIndex): int {}

function vkQueuePresentKHR(VkQueue $queue, VkPresentInfoKHR $pPresentInfo): int {}

function vkDestroySurfaceKHR(VkInstance $instance, VkSurfaceKHR $surface, null $pAllocator): void {}

/** VK_KHR_present_wait, through vkGetDeviceProcAddr: VK_ERROR_EXTENSION_NOT_PRESENT when the device does not expose it. */
function vkWaitForPresentKHR(VkDevice $device, VkSwapchainKHR $swapchain, int $presentId, int $timeout): int {}

/**
 * VK_EXT_hdr_metadata, through vkGetDeviceProcAddr: false when the device does not expose it.
 * $pSwapchains and $pMetadata are lists of the same length.
 */
function vkSetHdrMetadataEXT(VkDevice $device, array $pSwapchains, array $pMetadata): bool {}
