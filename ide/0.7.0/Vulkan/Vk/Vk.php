<?php

namespace Vulkan\Vk;

use Vulkan\Vk\VkInstance;
use Vulkan\Vk\VkPhysicalDevice;
use Vulkan\Vk\VkDevice;
use Vulkan\Vk\VkQueue;
use Vulkan\Vk\VkSurface;
use Vulkan\Vk\VkSwapchain;

/**
 * Vulkan entry points (static passthrough + thin C helpers).
 *
 * Window/surface creation lives in glfw — this class is instance/device/present.
 * Named Vulkan objects are returned as Zephir DTOs with an opaque `fd`.
 * Token constants (VK_) live in a microscrap wrapper.
 */
class Vk
{


    /**
     * @return string
     */
    public static function lastError(): string
    {
    }

    /**
     * @param array $extensions List of instance extension name strings (e.g. from glfw)
     * @param string $appName
     * @return VkInstance
     */
    public static function createInstance(array $extensions = [], string $appName = 'php-io-extensions/vulkan'): VkInstance
    {
    }

    /**
     * @param \Vulkan\Vk\VkInstance $instance
     * @return void
     */
    public static function destroyInstance(\Vulkan\Vk\VkInstance $instance): void
    {
    }

    /**
     * @param \Vulkan\Vk\VkInstance $instance
     * @return array
     */
    public static function enumeratePhysicalDevices(\Vulkan\Vk\VkInstance $instance): array
    {
    }

    /**
     * @param \Vulkan\Vk\VkPhysicalDevice $physical
     * @param \Vulkan\Vk\VkSurface $surface
     * @return int
     */
    public static function findGraphicsPresentQueue(\Vulkan\Vk\VkPhysicalDevice $physical, \Vulkan\Vk\VkSurface $surface): int
    {
    }

    /**
     * @param \Vulkan\Vk\VkPhysicalDevice $physical
     * @param int $queueFamily
     * @return VkDevice
     */
    public static function createDevice(\Vulkan\Vk\VkPhysicalDevice $physical, int $queueFamily): VkDevice
    {
    }

    /**
     * @param \Vulkan\Vk\VkDevice $device
     * @return void
     */
    public static function destroyDevice(\Vulkan\Vk\VkDevice $device): void
    {
    }

    /**
     * @param \Vulkan\Vk\VkDevice $device
     * @param int $queueFamily
     * @return VkQueue
     */
    public static function getDeviceQueue(\Vulkan\Vk\VkDevice $device, int $queueFamily): VkQueue
    {
    }

    /**
     * Wrap an existing VkSurfaceKHR pointer (e.g. from glfwCreateWindowSurface).
     *
     * @param int $surfaceFd
     * @return VkSurface
     */
    public static function wrapSurface(int $surfaceFd): VkSurface
    {
    }

    /**
     * @param \Vulkan\Vk\VkInstance $instance
     * @param \Vulkan\Vk\VkSurface $surface
     * @return void
     */
    public static function destroySurface(\Vulkan\Vk\VkInstance $instance, \Vulkan\Vk\VkSurface $surface): void
    {
    }

    /**
     * @param \Vulkan\Vk\VkInstance $instance
     * @param \Vulkan\Vk\VkPhysicalDevice $physical
     * @param \Vulkan\Vk\VkDevice $device
     * @param \Vulkan\Vk\VkQueue $queue
     * @param \Vulkan\Vk\VkSurface $surface
     * @param int $width
     * @param int $height
     * @return VkSwapchain
     */
    public static function createSwapchain(\Vulkan\Vk\VkInstance $instance, \Vulkan\Vk\VkPhysicalDevice $physical, \Vulkan\Vk\VkDevice $device, \Vulkan\Vk\VkQueue $queue, \Vulkan\Vk\VkSurface $surface, int $width, int $height): VkSwapchain
    {
    }

    /**
     * @param \Vulkan\Vk\VkSwapchain $swapchain
     * @return void
     */
    public static function destroySwapchain(\Vulkan\Vk\VkSwapchain $swapchain): void
    {
    }

    /**
     * @param \Vulkan\Vk\VkSwapchain $swapchain
     * @param int $width
     * @param int $height
     * @return int
     */
    public static function resizeSwapchain(\Vulkan\Vk\VkSwapchain $swapchain, int $width, int $height): int
    {
    }

    /**
     * Present one frame: clear background, optional menu + inner rects (pixel coords, top-left origin).
     *
     * @return 0 success; VK_ERROR_OUT_OF_DATE_KHR (-1000001004) / VK_SUBOPTIMAL_KHR (1000001003) may occur
     * @param \Vulkan\Vk\VkSwapchain $swapchain
     * @param double $clearR
     * @param double $clearG
     * @param double $clearB
     * @param double $clearA
     * @param bool $drawMenu
     * @param int $menuX
     * @param int $menuY
     * @param int $menuW
     * @param int $menuH
     * @param double $menuR
     * @param double $menuG
     * @param double $menuB
     * @param double $menuA
     * @param bool $drawInner
     * @param int $innerX
     * @param int $innerY
     * @param int $innerW
     * @param int $innerH
     * @param double $innerR
     * @param double $innerG
     * @param double $innerB
     * @param double $innerA
     * @param bool $drawAccent
     * @param int $accentX
     * @param int $accentY
     * @param int $accentW
     * @param int $accentH
     * @param double $accentR
     * @param double $accentG
     * @param double $accentB
     * @param double $accentA
     */
    public static function presentFrame(\Vulkan\Vk\VkSwapchain $swapchain, float $clearR, float $clearG, float $clearB, float $clearA = 1.0, bool $drawMenu = false, int $menuX = 0, int $menuY = 0, int $menuW = 0, int $menuH = 0, float $menuR = 0.0, float $menuG = 0.0, float $menuB = 0.0, float $menuA = 1.0, bool $drawInner = false, int $innerX = 0, int $innerY = 0, int $innerW = 0, int $innerH = 0, float $innerR = 0.0, float $innerG = 0.0, float $innerB = 0.0, float $innerA = 1.0, bool $drawAccent = false, int $accentX = 0, int $accentY = 0, int $accentW = 0, int $accentH = 0, float $accentR = 0.0, float $accentG = 0.0, float $accentB = 0.0, float $accentA = 1.0): int
    {
    }
}
