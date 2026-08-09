<?php

namespace Vulkan\Vk;

/**
 * Presentable swapchain + clear/menu frame state (C-owned).
 * `fd` points at an internal presenter struct, not a raw VkSwapchainKHR alone.
 */
class VkSwapchain
{

    /**
     * Opaque presenter pointer. 0 = none / destroyed.
     */
    public $fd = 0;

    /**
     * Framebuffer width in pixels.
     */
    public $width = 0;

    /**
     * Framebuffer height in pixels.
     */
    public $height = 0;

    /**
     * VkFormat of color images.
     */
    public $format = 0;

    /**
     * Number of swapchain images.
     */
    public $imageCount = 0;

}
