<?php

/** @generate-class-entries */

/**
 * @not-serializable
 */
final class VkCommandPool
{
    private function __construct() {}

    public function pointer(): int {}

    public static function fromPointer(int $pointer): ?static {}
}

/**
 * @not-serializable
 */
final class VkCommandBuffer
{
    private function __construct() {}

    public function pointer(): int {}

    public static function fromPointer(int $pointer): ?static {}
}

/**
 * @not-serializable
 */
final class VkFence
{
    private function __construct() {}

    public function pointer(): int {}

    public static function fromPointer(int $pointer): ?static {}
}

/**
 * @not-serializable
 */
final class VkSemaphore
{
    private function __construct() {}

    public function pointer(): int {}

    public static function fromPointer(int $pointer): ?static {}
}

/** @not-serializable */
final class VkCommandPoolCreateInfo
{
    public ?object $pNext = null;

    public int $flags = 0;

    public int $queueFamilyIndex = 0;
}

/** @not-serializable */
final class VkCommandBufferAllocateInfo
{
    public ?object $pNext = null;

    public ?VkCommandPool $commandPool = null;

    public int $level = 0;

    public int $commandBufferCount = 0;
}

/** @not-serializable */
final class VkCommandBufferInheritanceInfo
{
    public ?object $pNext = null;

    public ?VkRenderPass $renderPass = null;

    public int $subpass = 0;

    public ?VkFramebuffer $framebuffer = null;

    public bool $occlusionQueryEnable = false;

    public int $queryFlags = 0;

    public int $pipelineStatistics = 0;
}

/** @not-serializable */
final class VkCommandBufferBeginInfo
{
    public ?object $pNext = null;

    public int $flags = 0;

    public ?VkCommandBufferInheritanceInfo $pInheritanceInfo = null;
}

/** @not-serializable */
final class VkClearColorValue
{
    public array $float32 = [];
}

/** @not-serializable */
final class VkClearDepthStencilValue
{
    public float $depth = 0.0;

    public int $stencil = 0;
}

/** @not-serializable */
final class VkClearValue
{
    public ?VkClearColorValue $color = null;

    public ?VkClearDepthStencilValue $depthStencil = null;
}

/** @not-serializable */
final class VkRenderPassBeginInfo
{
    public ?object $pNext = null;

    public ?VkRenderPass $renderPass = null;

    public ?VkFramebuffer $framebuffer = null;

    public VkRect2D $renderArea;

    public int $clearValueCount = 0;

    public array $pClearValues = [];

    public function __construct() {}
}

/** @not-serializable */
final class VkOffset3D
{
    public int $x = 0;

    public int $y = 0;

    public int $z = 0;
}

/** @not-serializable */
final class VkImageSubresourceLayers
{
    public int $aspectMask = 0;

    public int $mipLevel = 0;

    public int $baseArrayLayer = 0;

    public int $layerCount = 0;
}

/** @not-serializable */
final class VkBufferImageCopy
{
    public int $bufferOffset = 0;

    public int $bufferRowLength = 0;

    public int $bufferImageHeight = 0;

    public VkImageSubresourceLayers $imageSubresource;

    public VkOffset3D $imageOffset;

    public VkExtent3D $imageExtent;

    public function __construct() {}
}

/** @not-serializable */
final class VkMemoryToImageCopy
{
    public ?object $pNext = null;

    public string $pHostPointer = '';

    public int $memoryRowLength = 0;

    public int $memoryImageHeight = 0;

    public VkImageSubresourceLayers $imageSubresource;

    public VkOffset3D $imageOffset;

    public VkExtent3D $imageExtent;

    public function __construct() {}
}

/** @not-serializable */
final class VkImageToMemoryCopy
{
    public ?object $pNext = null;

    /** The bytes of the region: the caller gives a string of the size to read, vkCopyImageToMemory() fills it. */
    public string $pHostPointer = '';

    public int $memoryRowLength = 0;

    public int $memoryImageHeight = 0;

    public VkImageSubresourceLayers $imageSubresource;

    public VkOffset3D $imageOffset;

    public VkExtent3D $imageExtent;

    public function __construct() {}
}

/** @not-serializable */
final class VkCopyMemoryToImageInfo
{
    public ?object $pNext = null;

    public int $flags = 0;

    public VkImage $dstImage;

    public int $dstImageLayout = 0;

    public int $regionCount = 0;

    public array $pRegions = [];
}

/** @not-serializable */
final class VkCopyImageToMemoryInfo
{
    public ?object $pNext = null;

    public int $flags = 0;

    public VkImage $srcImage;

    public int $srcImageLayout = 0;

    public int $regionCount = 0;

    public array $pRegions = [];
}

/** @not-serializable */
final class VkHostImageLayoutTransitionInfo
{
    public ?object $pNext = null;

    public VkImage $image;

    public int $oldLayout = 0;

    public int $newLayout = 0;

    public VkImageSubresourceRange $subresourceRange;

    public function __construct() {}
}

/** @not-serializable */
final class VkPhysicalDeviceHostImageCopyFeatures
{
    public ?object $pNext = null;

    public bool $hostImageCopy = false;
}

/** @not-serializable */
final class VkImageCopy
{
    public VkImageSubresourceLayers $srcSubresource;

    public VkOffset3D $srcOffset;

    public VkImageSubresourceLayers $dstSubresource;

    public VkOffset3D $dstOffset;

    public VkExtent3D $extent;

    public function __construct() {}
}

/** @not-serializable */
final class VkImageBlit
{
    public VkImageSubresourceLayers $srcSubresource;

    public array $srcOffsets = [];

    public VkImageSubresourceLayers $dstSubresource;

    public array $dstOffsets = [];

    public function __construct() {}
}

/** @not-serializable */
final class VkMemoryBarrier
{
    public ?object $pNext = null;

    public int $srcAccessMask = 0;

    public int $dstAccessMask = 0;
}

/** @not-serializable */
final class VkBufferMemoryBarrier
{
    public ?object $pNext = null;

    public int $srcAccessMask = 0;

    public int $dstAccessMask = 0;

    public int $srcQueueFamilyIndex = 0;

    public int $dstQueueFamilyIndex = 0;

    public ?VkBuffer $buffer = null;

    public int $offset = 0;

    public int $size = 0;
}

/** @not-serializable */
final class VkImageMemoryBarrier
{
    public ?object $pNext = null;

    public int $srcAccessMask = 0;

    public int $dstAccessMask = 0;

    public int $oldLayout = 0;

    public int $newLayout = 0;

    public int $srcQueueFamilyIndex = 0;

    public int $dstQueueFamilyIndex = 0;

    public ?VkImage $image = null;

    public VkImageSubresourceRange $subresourceRange;

    public function __construct() {}
}

/** @not-serializable */
final class VkSubmitInfo
{
    public ?object $pNext = null;

    public int $waitSemaphoreCount = 0;

    public array $pWaitSemaphores = [];

    public array $pWaitDstStageMask = [];

    public int $commandBufferCount = 0;

    public array $pCommandBuffers = [];

    public int $signalSemaphoreCount = 0;

    public array $pSignalSemaphores = [];
}

/** @not-serializable */
final class VkFenceCreateInfo
{
    public ?object $pNext = null;

    public int $flags = 0;
}

/** @not-serializable */
final class VkSemaphoreCreateInfo
{
    public ?object $pNext = null;

    public int $flags = 0;
}

/** @not-serializable */
final class VkClearAttachment
{
    public int $aspectMask = 0;

    public int $colorAttachment = 0;

    public VkClearValue $clearValue;

    public function __construct() {}
}

/** @not-serializable */
final class VkClearRect
{
    public VkRect2D $rect;

    public int $baseArrayLayer = 0;

    public int $layerCount = 0;

    public function __construct() {}
}

function vkCreateCommandPool(VkDevice $device, VkCommandPoolCreateInfo $pCreateInfo, int $pAllocator, ?VkCommandPool &$pCommandPool): int {}

function vkDestroyCommandPool(VkDevice $device, ?VkCommandPool $commandPool, int $pAllocator): void {}

function vkAllocateCommandBuffers(VkDevice $device, VkCommandBufferAllocateInfo $pAllocateInfo, ?array &$pCommandBuffers): int {}

function vkFreeCommandBuffers(VkDevice $device, VkCommandPool $commandPool, int $commandBufferCount, array $pCommandBuffers): void {}

function vkBeginCommandBuffer(VkCommandBuffer $commandBuffer, VkCommandBufferBeginInfo $pBeginInfo): int {}

function vkEndCommandBuffer(VkCommandBuffer $commandBuffer): int {}

function vkResetCommandBuffer(VkCommandBuffer $commandBuffer, int $flags): int {}

function vkCmdBeginRenderPass(VkCommandBuffer $commandBuffer, VkRenderPassBeginInfo $pRenderPassBegin, int $contents): void {}

function vkCmdEndRenderPass(VkCommandBuffer $commandBuffer): void {}

function vkCmdBindPipeline(VkCommandBuffer $commandBuffer, int $pipelineBindPoint, VkPipeline $pipeline): void {}

function vkCmdSetViewport(VkCommandBuffer $commandBuffer, int $firstViewport, int $viewportCount, array $pViewports): void {}

function vkCmdSetScissor(VkCommandBuffer $commandBuffer, int $firstScissor, int $scissorCount, array $pScissors): void {}

function vkCmdSetStencilReference(VkCommandBuffer $commandBuffer, int $faceMask, int $reference): void {}

function vkCmdBindVertexBuffers(VkCommandBuffer $commandBuffer, int $firstBinding, int $bindingCount, array $pBuffers, array $pOffsets): void {}

function vkCmdBindIndexBuffer(VkCommandBuffer $commandBuffer, VkBuffer $buffer, int $offset, int $indexType): void {}

function vkCmdBindDescriptorSets(VkCommandBuffer $commandBuffer, int $pipelineBindPoint, VkPipelineLayout $layout, int $firstSet, int $descriptorSetCount, array $pDescriptorSets, int $dynamicOffsetCount, array $pDynamicOffsets): void {}

function vkCmdUpdateBuffer(VkCommandBuffer $commandBuffer, VkBuffer $dstBuffer, int $dstOffset, int $dataSize, string $pData): void {}

function vkCopyMemoryToImage(VkDevice $device, VkCopyMemoryToImageInfo $pCopyMemoryToImageInfo): int {}

function vkCopyImageToMemory(VkDevice $device, VkCopyImageToMemoryInfo $pCopyImageToMemoryInfo): int {}

function vkTransitionImageLayout(VkDevice $device, int $transitionCount, array $pTransitions): int {}

function vkCmdPushConstants(VkCommandBuffer $commandBuffer, VkPipelineLayout $layout, int $stageFlags, int $offset, int $size, string $pValues): void {}

function vkCmdDraw(VkCommandBuffer $commandBuffer, int $vertexCount, int $instanceCount, int $firstVertex, int $firstInstance): void {}

function vkCmdDispatch(VkCommandBuffer $commandBuffer, int $groupCountX, int $groupCountY, int $groupCountZ): void {}

function vkCmdDrawIndexed(VkCommandBuffer $commandBuffer, int $indexCount, int $instanceCount, int $firstIndex, int $vertexOffset, int $firstInstance): void {}

function vkCmdClearAttachments(VkCommandBuffer $commandBuffer, int $attachmentCount, array $pAttachments, int $rectCount, array $pRects): void {}

function vkCmdCopyBufferToImage(VkCommandBuffer $commandBuffer, VkBuffer $srcBuffer, VkImage $dstImage, int $dstImageLayout, int $regionCount, array $pRegions): void {}

function vkCmdCopyImageToBuffer(VkCommandBuffer $commandBuffer, VkImage $srcImage, int $srcImageLayout, VkBuffer $dstBuffer, int $regionCount, array $pRegions): void {}

function vkCmdCopyImage(VkCommandBuffer $commandBuffer, VkImage $srcImage, int $srcImageLayout, VkImage $dstImage, int $dstImageLayout, int $regionCount, array $pRegions): void {}

function vkCmdBlitImage(VkCommandBuffer $commandBuffer, VkImage $srcImage, int $srcImageLayout, VkImage $dstImage, int $dstImageLayout, int $regionCount, array $pRegions, int $filter): void {}

function vkCmdPipelineBarrier(VkCommandBuffer $commandBuffer, int $srcStageMask, int $dstStageMask, int $dependencyFlags, int $memoryBarrierCount, array $pMemoryBarriers, int $bufferMemoryBarrierCount, array $pBufferMemoryBarriers, int $imageMemoryBarrierCount, array $pImageMemoryBarriers): void {}

function vkQueueSubmit(VkQueue $queue, int $submitCount, array $pSubmits, ?VkFence $fence): int {}

function vkQueueWaitIdle(VkQueue $queue): int {}

function vkCreateFence(VkDevice $device, VkFenceCreateInfo $pCreateInfo, int $pAllocator, ?VkFence &$pFence): int {}

function vkDestroyFence(VkDevice $device, ?VkFence $fence, int $pAllocator): void {}

function vkGetFenceStatus(VkDevice $device, VkFence $fence): int {}

function vkResetFences(VkDevice $device, int $fenceCount, array $pFences): int {}

function vkWaitForFences(VkDevice $device, int $fenceCount, array $pFences, bool $waitAll, int $timeout): int {}

function vkCreateSemaphore(VkDevice $device, VkSemaphoreCreateInfo $pCreateInfo, int $pAllocator, ?VkSemaphore &$pSemaphore): int {}

function vkDestroySemaphore(VkDevice $device, ?VkSemaphore $semaphore, int $pAllocator): void {}
