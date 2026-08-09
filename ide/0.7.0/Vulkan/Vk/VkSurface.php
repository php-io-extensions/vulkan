<?php

namespace Vulkan\Vk;

/**
 * Opaque VkSurfaceKHR (usually created by glfw, destroyed here).
 */
class VkSurface
{

    /**
     * Opaque VkSurfaceKHR pointer. 0 = none / destroyed.
     */
    public $fd = 0;

}
