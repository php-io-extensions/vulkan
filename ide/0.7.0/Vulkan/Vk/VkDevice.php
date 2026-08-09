<?php

namespace Vulkan\Vk;

/**
 * Opaque VkDevice handle.
 */
class VkDevice
{

    /**
     * Opaque VkDevice pointer. 0 = none / destroyed.
     */
    public $fd = 0;

    /**
     * Queue family index used at create time.
     */
    public $queueFamily = -1;

}
