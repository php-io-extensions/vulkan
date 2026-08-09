<?php

namespace Vulkan\Vk;

/**
 * Opaque VkQueue handle.
 */
class VkQueue
{

    /**
     * Opaque VkQueue pointer. 0 = none.
     */
    public $fd = 0;

    /**
     * Queue family index.
     */
    public $familyIndex = -1;

}
