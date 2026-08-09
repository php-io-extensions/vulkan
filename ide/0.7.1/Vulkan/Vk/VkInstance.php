<?php

namespace Vulkan\Vk;

/**
 * Opaque VkInstance handle.
 * `fd` holds the pointer as int (0 = none).
 */
class VkInstance
{

    /**
     * Opaque VkInstance pointer. 0 = none / destroyed.
     */
    public $fd = 0;

    /**
     * Application name used at create time.
     */
    public $appName = '';

}
