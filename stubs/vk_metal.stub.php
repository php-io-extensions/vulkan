<?php

/** @generate-class-entries */

/** @not-serializable */
final class VkMetalSurfaceCreateInfoEXT
{
    public ?object $pNext = null;

    public int $flags = 0;

    public int $pLayer = 0;
}

function vkCreateMetalSurfaceEXT(VkInstance $instance, VkMetalSurfaceCreateInfoEXT $pCreateInfo, null $pAllocator, ?VkSurfaceKHR &$pSurface): int {}
