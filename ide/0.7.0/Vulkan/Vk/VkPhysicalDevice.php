<?php

namespace Vulkan\Vk;

/**
 * Opaque VkPhysicalDevice handle with queried schema fields.
 */
class VkPhysicalDevice
{

    /**
     * Opaque VkPhysicalDevice pointer. 0 = none.
     */
    public $fd = 0;

    /**
     * Device name from VkPhysicalDeviceProperties.
     */
    public $name = '';

    /**
     * VkPhysicalDeviceType.
     */
    public $deviceType = 0;

    /**
     * PCI-style vendor ID.
     */
    public $vendorId = 0;

    /**
     * Device ID.
     */
    public $deviceId = 0;

}
