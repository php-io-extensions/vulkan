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
