/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: b1a301d5307767b09c776f97505e127ca9fbc1e9 */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkCreateCommandPool, 0, 4, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, device, VkDevice, 0)
	ZEND_ARG_OBJ_INFO(0, pCreateInfo, VkCommandPoolCreateInfo, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_NULL, 1)
	ZEND_ARG_OBJ_INFO(1, pCommandPool, VkCommandPool, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkDestroyCommandPool, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, device, VkDevice, 0)
	ZEND_ARG_OBJ_INFO(0, commandPool, VkCommandPool, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_NULL, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkAllocateCommandBuffers, 0, 3, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, device, VkDevice, 0)
	ZEND_ARG_OBJ_INFO(0, pAllocateInfo, VkCommandBufferAllocateInfo, 0)
	ZEND_ARG_TYPE_INFO(1, pCommandBuffers, IS_ARRAY, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkFreeCommandBuffers, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, device, VkDevice, 0)
	ZEND_ARG_OBJ_INFO(0, commandPool, VkCommandPool, 0)
	ZEND_ARG_TYPE_INFO(0, pCommandBuffers, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkBeginCommandBuffer, 0, 2, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, commandBuffer, VkCommandBuffer, 0)
	ZEND_ARG_OBJ_INFO(0, pBeginInfo, VkCommandBufferBeginInfo, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkEndCommandBuffer, 0, 1, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, commandBuffer, VkCommandBuffer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkResetCommandBuffer, 0, 2, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, commandBuffer, VkCommandBuffer, 0)
	ZEND_ARG_TYPE_INFO(0, flags, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkCmdBeginRenderPass, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, commandBuffer, VkCommandBuffer, 0)
	ZEND_ARG_OBJ_INFO(0, pRenderPassBegin, VkRenderPassBeginInfo, 0)
	ZEND_ARG_TYPE_INFO(0, contents, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkCmdEndRenderPass, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, commandBuffer, VkCommandBuffer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkCmdBindPipeline, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, commandBuffer, VkCommandBuffer, 0)
	ZEND_ARG_TYPE_INFO(0, pipelineBindPoint, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, pipeline, VkPipeline, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkCmdSetViewport, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, commandBuffer, VkCommandBuffer, 0)
	ZEND_ARG_TYPE_INFO(0, firstViewport, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pViewports, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkCmdSetScissor, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, commandBuffer, VkCommandBuffer, 0)
	ZEND_ARG_TYPE_INFO(0, firstScissor, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pScissors, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkCmdSetStencilReference, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, commandBuffer, VkCommandBuffer, 0)
	ZEND_ARG_TYPE_INFO(0, faceMask, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, reference, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkCmdBindVertexBuffers, 0, 4, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, commandBuffer, VkCommandBuffer, 0)
	ZEND_ARG_TYPE_INFO(0, firstBinding, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pBuffers, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, pOffsets, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkCmdBindIndexBuffer, 0, 4, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, commandBuffer, VkCommandBuffer, 0)
	ZEND_ARG_OBJ_INFO(0, buffer, VkBuffer, 0)
	ZEND_ARG_TYPE_INFO(0, offset, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, indexType, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkCmdBindDescriptorSets, 0, 6, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, commandBuffer, VkCommandBuffer, 0)
	ZEND_ARG_TYPE_INFO(0, pipelineBindPoint, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, layout, VkPipelineLayout, 0)
	ZEND_ARG_TYPE_INFO(0, firstSet, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pDescriptorSets, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, pDynamicOffsets, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkCmdPushConstants, 0, 6, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, commandBuffer, VkCommandBuffer, 0)
	ZEND_ARG_OBJ_INFO(0, layout, VkPipelineLayout, 0)
	ZEND_ARG_TYPE_INFO(0, stageFlags, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, offset, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, size, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pValues, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkCmdDraw, 0, 5, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, commandBuffer, VkCommandBuffer, 0)
	ZEND_ARG_TYPE_INFO(0, vertexCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, instanceCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, firstVertex, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, firstInstance, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkCmdDrawIndexed, 0, 6, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, commandBuffer, VkCommandBuffer, 0)
	ZEND_ARG_TYPE_INFO(0, indexCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, instanceCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, firstIndex, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, vertexOffset, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, firstInstance, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkCmdClearAttachments, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, commandBuffer, VkCommandBuffer, 0)
	ZEND_ARG_TYPE_INFO(0, pAttachments, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, pRects, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkCmdCopyBufferToImage, 0, 5, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, commandBuffer, VkCommandBuffer, 0)
	ZEND_ARG_OBJ_INFO(0, srcBuffer, VkBuffer, 0)
	ZEND_ARG_OBJ_INFO(0, dstImage, VkImage, 0)
	ZEND_ARG_TYPE_INFO(0, dstImageLayout, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pRegions, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkCmdCopyImageToBuffer, 0, 5, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, commandBuffer, VkCommandBuffer, 0)
	ZEND_ARG_OBJ_INFO(0, srcImage, VkImage, 0)
	ZEND_ARG_TYPE_INFO(0, srcImageLayout, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, dstBuffer, VkBuffer, 0)
	ZEND_ARG_TYPE_INFO(0, pRegions, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkCmdBlitImage, 0, 7, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, commandBuffer, VkCommandBuffer, 0)
	ZEND_ARG_OBJ_INFO(0, srcImage, VkImage, 0)
	ZEND_ARG_TYPE_INFO(0, srcImageLayout, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, dstImage, VkImage, 0)
	ZEND_ARG_TYPE_INFO(0, dstImageLayout, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pRegions, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, filter, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkCmdPipelineBarrier, 0, 7, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, commandBuffer, VkCommandBuffer, 0)
	ZEND_ARG_TYPE_INFO(0, srcStageMask, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, dstStageMask, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, dependencyFlags, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pMemoryBarriers, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, pBufferMemoryBarriers, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, pImageMemoryBarriers, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkQueueSubmit, 0, 3, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, queue, VkQueue, 0)
	ZEND_ARG_TYPE_INFO(0, pSubmits, IS_ARRAY, 0)
	ZEND_ARG_OBJ_INFO(0, fence, VkFence, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkQueueWaitIdle, 0, 1, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, queue, VkQueue, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkCreateFence, 0, 4, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, device, VkDevice, 0)
	ZEND_ARG_OBJ_INFO(0, pCreateInfo, VkFenceCreateInfo, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_NULL, 1)
	ZEND_ARG_OBJ_INFO(1, pFence, VkFence, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkDestroyFence, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, device, VkDevice, 0)
	ZEND_ARG_OBJ_INFO(0, fence, VkFence, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_NULL, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkGetFenceStatus, 0, 2, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, device, VkDevice, 0)
	ZEND_ARG_OBJ_INFO(0, fence, VkFence, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkResetFences, 0, 2, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, device, VkDevice, 0)
	ZEND_ARG_TYPE_INFO(0, pFences, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkWaitForFences, 0, 4, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, device, VkDevice, 0)
	ZEND_ARG_TYPE_INFO(0, pFences, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, waitAll, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, timeout, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkCreateSemaphore, 0, 4, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, device, VkDevice, 0)
	ZEND_ARG_OBJ_INFO(0, pCreateInfo, VkSemaphoreCreateInfo, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_NULL, 1)
	ZEND_ARG_OBJ_INFO(1, pSemaphore, VkSemaphore, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkDestroySemaphore, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, device, VkDevice, 0)
	ZEND_ARG_OBJ_INFO(0, semaphore, VkSemaphore, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_NULL, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_VkCommandPool___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_VkCommandPool_pointer, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_VkCommandPool_fromPointer, 0, 1, IS_STATIC, 0)
	ZEND_ARG_TYPE_INFO(0, pointer, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_VkCommandBuffer___construct arginfo_class_VkCommandPool___construct

#define arginfo_class_VkCommandBuffer_pointer arginfo_class_VkCommandPool_pointer

#define arginfo_class_VkCommandBuffer_fromPointer arginfo_class_VkCommandPool_fromPointer

#define arginfo_class_VkFence___construct arginfo_class_VkCommandPool___construct

#define arginfo_class_VkFence_pointer arginfo_class_VkCommandPool_pointer

#define arginfo_class_VkFence_fromPointer arginfo_class_VkCommandPool_fromPointer

#define arginfo_class_VkSemaphore___construct arginfo_class_VkCommandPool___construct

#define arginfo_class_VkSemaphore_pointer arginfo_class_VkCommandPool_pointer

#define arginfo_class_VkSemaphore_fromPointer arginfo_class_VkCommandPool_fromPointer

#define arginfo_class_VkRenderPassBeginInfo___construct arginfo_class_VkCommandPool___construct

#define arginfo_class_VkBufferImageCopy___construct arginfo_class_VkCommandPool___construct

#define arginfo_class_VkImageBlit___construct arginfo_class_VkCommandPool___construct

#define arginfo_class_VkImageMemoryBarrier___construct arginfo_class_VkCommandPool___construct

#define arginfo_class_VkClearAttachment___construct arginfo_class_VkCommandPool___construct

#define arginfo_class_VkClearRect___construct arginfo_class_VkCommandPool___construct

ZEND_FUNCTION(vkCreateCommandPool);
ZEND_FUNCTION(vkDestroyCommandPool);
ZEND_FUNCTION(vkAllocateCommandBuffers);
ZEND_FUNCTION(vkFreeCommandBuffers);
ZEND_FUNCTION(vkBeginCommandBuffer);
ZEND_FUNCTION(vkEndCommandBuffer);
ZEND_FUNCTION(vkResetCommandBuffer);
ZEND_FUNCTION(vkCmdBeginRenderPass);
ZEND_FUNCTION(vkCmdEndRenderPass);
ZEND_FUNCTION(vkCmdBindPipeline);
ZEND_FUNCTION(vkCmdSetViewport);
ZEND_FUNCTION(vkCmdSetScissor);
ZEND_FUNCTION(vkCmdSetStencilReference);
ZEND_FUNCTION(vkCmdBindVertexBuffers);
ZEND_FUNCTION(vkCmdBindIndexBuffer);
ZEND_FUNCTION(vkCmdBindDescriptorSets);
ZEND_FUNCTION(vkCmdPushConstants);
ZEND_FUNCTION(vkCmdDraw);
ZEND_FUNCTION(vkCmdDrawIndexed);
ZEND_FUNCTION(vkCmdClearAttachments);
ZEND_FUNCTION(vkCmdCopyBufferToImage);
ZEND_FUNCTION(vkCmdCopyImageToBuffer);
ZEND_FUNCTION(vkCmdBlitImage);
ZEND_FUNCTION(vkCmdPipelineBarrier);
ZEND_FUNCTION(vkQueueSubmit);
ZEND_FUNCTION(vkQueueWaitIdle);
ZEND_FUNCTION(vkCreateFence);
ZEND_FUNCTION(vkDestroyFence);
ZEND_FUNCTION(vkGetFenceStatus);
ZEND_FUNCTION(vkResetFences);
ZEND_FUNCTION(vkWaitForFences);
ZEND_FUNCTION(vkCreateSemaphore);
ZEND_FUNCTION(vkDestroySemaphore);
ZEND_METHOD(VkCommandPool, __construct);
ZEND_METHOD(VkCommandPool, pointer);
ZEND_METHOD(VkCommandPool, fromPointer);
ZEND_METHOD(VkCommandBuffer, __construct);
ZEND_METHOD(VkCommandBuffer, pointer);
ZEND_METHOD(VkCommandBuffer, fromPointer);
ZEND_METHOD(VkFence, __construct);
ZEND_METHOD(VkFence, pointer);
ZEND_METHOD(VkFence, fromPointer);
ZEND_METHOD(VkSemaphore, __construct);
ZEND_METHOD(VkSemaphore, pointer);
ZEND_METHOD(VkSemaphore, fromPointer);
ZEND_METHOD(VkRenderPassBeginInfo, __construct);
ZEND_METHOD(VkBufferImageCopy, __construct);
ZEND_METHOD(VkImageBlit, __construct);
ZEND_METHOD(VkImageMemoryBarrier, __construct);
ZEND_METHOD(VkClearAttachment, __construct);
ZEND_METHOD(VkClearRect, __construct);

static const zend_function_entry ext_functions[] = {
	ZEND_FE(vkCreateCommandPool, arginfo_vkCreateCommandPool)
	ZEND_FE(vkDestroyCommandPool, arginfo_vkDestroyCommandPool)
	ZEND_FE(vkAllocateCommandBuffers, arginfo_vkAllocateCommandBuffers)
	ZEND_FE(vkFreeCommandBuffers, arginfo_vkFreeCommandBuffers)
	ZEND_FE(vkBeginCommandBuffer, arginfo_vkBeginCommandBuffer)
	ZEND_FE(vkEndCommandBuffer, arginfo_vkEndCommandBuffer)
	ZEND_FE(vkResetCommandBuffer, arginfo_vkResetCommandBuffer)
	ZEND_FE(vkCmdBeginRenderPass, arginfo_vkCmdBeginRenderPass)
	ZEND_FE(vkCmdEndRenderPass, arginfo_vkCmdEndRenderPass)
	ZEND_FE(vkCmdBindPipeline, arginfo_vkCmdBindPipeline)
	ZEND_FE(vkCmdSetViewport, arginfo_vkCmdSetViewport)
	ZEND_FE(vkCmdSetScissor, arginfo_vkCmdSetScissor)
	ZEND_FE(vkCmdSetStencilReference, arginfo_vkCmdSetStencilReference)
	ZEND_FE(vkCmdBindVertexBuffers, arginfo_vkCmdBindVertexBuffers)
	ZEND_FE(vkCmdBindIndexBuffer, arginfo_vkCmdBindIndexBuffer)
	ZEND_FE(vkCmdBindDescriptorSets, arginfo_vkCmdBindDescriptorSets)
	ZEND_FE(vkCmdPushConstants, arginfo_vkCmdPushConstants)
	ZEND_FE(vkCmdDraw, arginfo_vkCmdDraw)
	ZEND_FE(vkCmdDrawIndexed, arginfo_vkCmdDrawIndexed)
	ZEND_FE(vkCmdClearAttachments, arginfo_vkCmdClearAttachments)
	ZEND_FE(vkCmdCopyBufferToImage, arginfo_vkCmdCopyBufferToImage)
	ZEND_FE(vkCmdCopyImageToBuffer, arginfo_vkCmdCopyImageToBuffer)
	ZEND_FE(vkCmdBlitImage, arginfo_vkCmdBlitImage)
	ZEND_FE(vkCmdPipelineBarrier, arginfo_vkCmdPipelineBarrier)
	ZEND_FE(vkQueueSubmit, arginfo_vkQueueSubmit)
	ZEND_FE(vkQueueWaitIdle, arginfo_vkQueueWaitIdle)
	ZEND_FE(vkCreateFence, arginfo_vkCreateFence)
	ZEND_FE(vkDestroyFence, arginfo_vkDestroyFence)
	ZEND_FE(vkGetFenceStatus, arginfo_vkGetFenceStatus)
	ZEND_FE(vkResetFences, arginfo_vkResetFences)
	ZEND_FE(vkWaitForFences, arginfo_vkWaitForFences)
	ZEND_FE(vkCreateSemaphore, arginfo_vkCreateSemaphore)
	ZEND_FE(vkDestroySemaphore, arginfo_vkDestroySemaphore)
	ZEND_FE_END
};

static const zend_function_entry class_VkCommandPool_methods[] = {
	ZEND_ME(VkCommandPool, __construct, arginfo_class_VkCommandPool___construct, ZEND_ACC_PRIVATE)
	ZEND_ME(VkCommandPool, pointer, arginfo_class_VkCommandPool_pointer, ZEND_ACC_PUBLIC)
	ZEND_ME(VkCommandPool, fromPointer, arginfo_class_VkCommandPool_fromPointer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static const zend_function_entry class_VkCommandBuffer_methods[] = {
	ZEND_ME(VkCommandBuffer, __construct, arginfo_class_VkCommandBuffer___construct, ZEND_ACC_PRIVATE)
	ZEND_ME(VkCommandBuffer, pointer, arginfo_class_VkCommandBuffer_pointer, ZEND_ACC_PUBLIC)
	ZEND_ME(VkCommandBuffer, fromPointer, arginfo_class_VkCommandBuffer_fromPointer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static const zend_function_entry class_VkFence_methods[] = {
	ZEND_ME(VkFence, __construct, arginfo_class_VkFence___construct, ZEND_ACC_PRIVATE)
	ZEND_ME(VkFence, pointer, arginfo_class_VkFence_pointer, ZEND_ACC_PUBLIC)
	ZEND_ME(VkFence, fromPointer, arginfo_class_VkFence_fromPointer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static const zend_function_entry class_VkSemaphore_methods[] = {
	ZEND_ME(VkSemaphore, __construct, arginfo_class_VkSemaphore___construct, ZEND_ACC_PRIVATE)
	ZEND_ME(VkSemaphore, pointer, arginfo_class_VkSemaphore_pointer, ZEND_ACC_PUBLIC)
	ZEND_ME(VkSemaphore, fromPointer, arginfo_class_VkSemaphore_fromPointer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static const zend_function_entry class_VkRenderPassBeginInfo_methods[] = {
	ZEND_ME(VkRenderPassBeginInfo, __construct, arginfo_class_VkRenderPassBeginInfo___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_VkBufferImageCopy_methods[] = {
	ZEND_ME(VkBufferImageCopy, __construct, arginfo_class_VkBufferImageCopy___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_VkImageBlit_methods[] = {
	ZEND_ME(VkImageBlit, __construct, arginfo_class_VkImageBlit___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_VkImageMemoryBarrier_methods[] = {
	ZEND_ME(VkImageMemoryBarrier, __construct, arginfo_class_VkImageMemoryBarrier___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_VkClearAttachment_methods[] = {
	ZEND_ME(VkClearAttachment, __construct, arginfo_class_VkClearAttachment___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_VkClearRect_methods[] = {
	ZEND_ME(VkClearRect, __construct, arginfo_class_VkClearRect___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_VkCommandPool(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkCommandPool", class_VkCommandPool_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_VkCommandBuffer(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkCommandBuffer", class_VkCommandBuffer_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_VkFence(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkFence", class_VkFence_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_VkSemaphore(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkSemaphore", class_VkSemaphore_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_VkCommandPoolCreateInfo(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkCommandPoolCreateInfo", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_pNext_default_value;
	ZVAL_NULL(&property_pNext_default_value);
	zend_string *property_pNext_name = zend_string_init("pNext", sizeof("pNext") - 1, 1);
	zend_declare_typed_property(class_entry, property_pNext_name, &property_pNext_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_OBJECT|MAY_BE_NULL));
	zend_string_release(property_pNext_name);

	zval property_flags_default_value;
	ZVAL_LONG(&property_flags_default_value, 0);
	zend_string *property_flags_name = zend_string_init("flags", sizeof("flags") - 1, 1);
	zend_declare_typed_property(class_entry, property_flags_name, &property_flags_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_flags_name);

	zval property_queueFamilyIndex_default_value;
	ZVAL_LONG(&property_queueFamilyIndex_default_value, 0);
	zend_string *property_queueFamilyIndex_name = zend_string_init("queueFamilyIndex", sizeof("queueFamilyIndex") - 1, 1);
	zend_declare_typed_property(class_entry, property_queueFamilyIndex_name, &property_queueFamilyIndex_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_queueFamilyIndex_name);

	return class_entry;
}

static zend_class_entry *register_class_VkCommandBufferAllocateInfo(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkCommandBufferAllocateInfo", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_pNext_default_value;
	ZVAL_NULL(&property_pNext_default_value);
	zend_string *property_pNext_name = zend_string_init("pNext", sizeof("pNext") - 1, 1);
	zend_declare_typed_property(class_entry, property_pNext_name, &property_pNext_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_OBJECT|MAY_BE_NULL));
	zend_string_release(property_pNext_name);

	zval property_commandPool_default_value;
	ZVAL_NULL(&property_commandPool_default_value);
	zend_string *property_commandPool_name = zend_string_init("commandPool", sizeof("commandPool") - 1, 1);
	zend_string *property_commandPool_class_VkCommandPool = zend_string_init("VkCommandPool", sizeof("VkCommandPool")-1, 1);
	zend_declare_typed_property(class_entry, property_commandPool_name, &property_commandPool_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_commandPool_class_VkCommandPool, 0, MAY_BE_NULL));
	zend_string_release(property_commandPool_name);

	zval property_level_default_value;
	ZVAL_LONG(&property_level_default_value, 0);
	zend_string *property_level_name = zend_string_init("level", sizeof("level") - 1, 1);
	zend_declare_typed_property(class_entry, property_level_name, &property_level_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_level_name);

	zval property_commandBufferCount_default_value;
	ZVAL_LONG(&property_commandBufferCount_default_value, 0);
	zend_string *property_commandBufferCount_name = zend_string_init("commandBufferCount", sizeof("commandBufferCount") - 1, 1);
	zend_declare_typed_property(class_entry, property_commandBufferCount_name, &property_commandBufferCount_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_commandBufferCount_name);

	return class_entry;
}

static zend_class_entry *register_class_VkCommandBufferInheritanceInfo(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkCommandBufferInheritanceInfo", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_pNext_default_value;
	ZVAL_NULL(&property_pNext_default_value);
	zend_string *property_pNext_name = zend_string_init("pNext", sizeof("pNext") - 1, 1);
	zend_declare_typed_property(class_entry, property_pNext_name, &property_pNext_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_OBJECT|MAY_BE_NULL));
	zend_string_release(property_pNext_name);

	zval property_renderPass_default_value;
	ZVAL_NULL(&property_renderPass_default_value);
	zend_string *property_renderPass_name = zend_string_init("renderPass", sizeof("renderPass") - 1, 1);
	zend_string *property_renderPass_class_VkRenderPass = zend_string_init("VkRenderPass", sizeof("VkRenderPass")-1, 1);
	zend_declare_typed_property(class_entry, property_renderPass_name, &property_renderPass_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_renderPass_class_VkRenderPass, 0, MAY_BE_NULL));
	zend_string_release(property_renderPass_name);

	zval property_subpass_default_value;
	ZVAL_LONG(&property_subpass_default_value, 0);
	zend_string *property_subpass_name = zend_string_init("subpass", sizeof("subpass") - 1, 1);
	zend_declare_typed_property(class_entry, property_subpass_name, &property_subpass_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_subpass_name);

	zval property_framebuffer_default_value;
	ZVAL_NULL(&property_framebuffer_default_value);
	zend_string *property_framebuffer_name = zend_string_init("framebuffer", sizeof("framebuffer") - 1, 1);
	zend_string *property_framebuffer_class_VkFramebuffer = zend_string_init("VkFramebuffer", sizeof("VkFramebuffer")-1, 1);
	zend_declare_typed_property(class_entry, property_framebuffer_name, &property_framebuffer_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_framebuffer_class_VkFramebuffer, 0, MAY_BE_NULL));
	zend_string_release(property_framebuffer_name);

	zval property_occlusionQueryEnable_default_value;
	ZVAL_LONG(&property_occlusionQueryEnable_default_value, 0);
	zend_string *property_occlusionQueryEnable_name = zend_string_init("occlusionQueryEnable", sizeof("occlusionQueryEnable") - 1, 1);
	zend_declare_typed_property(class_entry, property_occlusionQueryEnable_name, &property_occlusionQueryEnable_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_occlusionQueryEnable_name);

	zval property_queryFlags_default_value;
	ZVAL_LONG(&property_queryFlags_default_value, 0);
	zend_string *property_queryFlags_name = zend_string_init("queryFlags", sizeof("queryFlags") - 1, 1);
	zend_declare_typed_property(class_entry, property_queryFlags_name, &property_queryFlags_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_queryFlags_name);

	zval property_pipelineStatistics_default_value;
	ZVAL_LONG(&property_pipelineStatistics_default_value, 0);
	zend_string *property_pipelineStatistics_name = zend_string_init("pipelineStatistics", sizeof("pipelineStatistics") - 1, 1);
	zend_declare_typed_property(class_entry, property_pipelineStatistics_name, &property_pipelineStatistics_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_pipelineStatistics_name);

	return class_entry;
}

static zend_class_entry *register_class_VkCommandBufferBeginInfo(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkCommandBufferBeginInfo", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_pNext_default_value;
	ZVAL_NULL(&property_pNext_default_value);
	zend_string *property_pNext_name = zend_string_init("pNext", sizeof("pNext") - 1, 1);
	zend_declare_typed_property(class_entry, property_pNext_name, &property_pNext_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_OBJECT|MAY_BE_NULL));
	zend_string_release(property_pNext_name);

	zval property_flags_default_value;
	ZVAL_LONG(&property_flags_default_value, 0);
	zend_string *property_flags_name = zend_string_init("flags", sizeof("flags") - 1, 1);
	zend_declare_typed_property(class_entry, property_flags_name, &property_flags_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_flags_name);

	zval property_pInheritanceInfo_default_value;
	ZVAL_NULL(&property_pInheritanceInfo_default_value);
	zend_string *property_pInheritanceInfo_name = zend_string_init("pInheritanceInfo", sizeof("pInheritanceInfo") - 1, 1);
	zend_string *property_pInheritanceInfo_class_VkCommandBufferInheritanceInfo = zend_string_init("VkCommandBufferInheritanceInfo", sizeof("VkCommandBufferInheritanceInfo")-1, 1);
	zend_declare_typed_property(class_entry, property_pInheritanceInfo_name, &property_pInheritanceInfo_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_pInheritanceInfo_class_VkCommandBufferInheritanceInfo, 0, MAY_BE_NULL));
	zend_string_release(property_pInheritanceInfo_name);

	return class_entry;
}

static zend_class_entry *register_class_VkClearColorValue(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkClearColorValue", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_float32_default_value;
	ZVAL_EMPTY_ARRAY(&property_float32_default_value);
	zend_string *property_float32_name = zend_string_init("float32", sizeof("float32") - 1, 1);
	zend_declare_typed_property(class_entry, property_float32_name, &property_float32_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_float32_name);

	return class_entry;
}

static zend_class_entry *register_class_VkClearDepthStencilValue(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkClearDepthStencilValue", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_depth_default_value;
	ZVAL_DOUBLE(&property_depth_default_value, 0.0);
	zend_string *property_depth_name = zend_string_init("depth", sizeof("depth") - 1, 1);
	zend_declare_typed_property(class_entry, property_depth_name, &property_depth_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_depth_name);

	zval property_stencil_default_value;
	ZVAL_LONG(&property_stencil_default_value, 0);
	zend_string *property_stencil_name = zend_string_init("stencil", sizeof("stencil") - 1, 1);
	zend_declare_typed_property(class_entry, property_stencil_name, &property_stencil_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_stencil_name);

	return class_entry;
}

static zend_class_entry *register_class_VkClearValue(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkClearValue", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_color_default_value;
	ZVAL_NULL(&property_color_default_value);
	zend_string *property_color_name = zend_string_init("color", sizeof("color") - 1, 1);
	zend_string *property_color_class_VkClearColorValue = zend_string_init("VkClearColorValue", sizeof("VkClearColorValue")-1, 1);
	zend_declare_typed_property(class_entry, property_color_name, &property_color_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_color_class_VkClearColorValue, 0, MAY_BE_NULL));
	zend_string_release(property_color_name);

	zval property_depthStencil_default_value;
	ZVAL_NULL(&property_depthStencil_default_value);
	zend_string *property_depthStencil_name = zend_string_init("depthStencil", sizeof("depthStencil") - 1, 1);
	zend_string *property_depthStencil_class_VkClearDepthStencilValue = zend_string_init("VkClearDepthStencilValue", sizeof("VkClearDepthStencilValue")-1, 1);
	zend_declare_typed_property(class_entry, property_depthStencil_name, &property_depthStencil_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_depthStencil_class_VkClearDepthStencilValue, 0, MAY_BE_NULL));
	zend_string_release(property_depthStencil_name);

	return class_entry;
}

static zend_class_entry *register_class_VkRenderPassBeginInfo(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkRenderPassBeginInfo", class_VkRenderPassBeginInfo_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_pNext_default_value;
	ZVAL_NULL(&property_pNext_default_value);
	zend_string *property_pNext_name = zend_string_init("pNext", sizeof("pNext") - 1, 1);
	zend_declare_typed_property(class_entry, property_pNext_name, &property_pNext_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_OBJECT|MAY_BE_NULL));
	zend_string_release(property_pNext_name);

	zval property_renderPass_default_value;
	ZVAL_NULL(&property_renderPass_default_value);
	zend_string *property_renderPass_name = zend_string_init("renderPass", sizeof("renderPass") - 1, 1);
	zend_string *property_renderPass_class_VkRenderPass = zend_string_init("VkRenderPass", sizeof("VkRenderPass")-1, 1);
	zend_declare_typed_property(class_entry, property_renderPass_name, &property_renderPass_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_renderPass_class_VkRenderPass, 0, MAY_BE_NULL));
	zend_string_release(property_renderPass_name);

	zval property_framebuffer_default_value;
	ZVAL_NULL(&property_framebuffer_default_value);
	zend_string *property_framebuffer_name = zend_string_init("framebuffer", sizeof("framebuffer") - 1, 1);
	zend_string *property_framebuffer_class_VkFramebuffer = zend_string_init("VkFramebuffer", sizeof("VkFramebuffer")-1, 1);
	zend_declare_typed_property(class_entry, property_framebuffer_name, &property_framebuffer_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_framebuffer_class_VkFramebuffer, 0, MAY_BE_NULL));
	zend_string_release(property_framebuffer_name);

	zval property_renderArea_default_value;
	ZVAL_UNDEF(&property_renderArea_default_value);
	zend_string *property_renderArea_name = zend_string_init("renderArea", sizeof("renderArea") - 1, 1);
	zend_string *property_renderArea_class_VkRect2D = zend_string_init("VkRect2D", sizeof("VkRect2D")-1, 1);
	zend_declare_typed_property(class_entry, property_renderArea_name, &property_renderArea_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_renderArea_class_VkRect2D, 0, 0));
	zend_string_release(property_renderArea_name);

	zval property_pClearValues_default_value;
	ZVAL_EMPTY_ARRAY(&property_pClearValues_default_value);
	zend_string *property_pClearValues_name = zend_string_init("pClearValues", sizeof("pClearValues") - 1, 1);
	zend_declare_typed_property(class_entry, property_pClearValues_name, &property_pClearValues_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_pClearValues_name);

	return class_entry;
}

static zend_class_entry *register_class_VkOffset3D(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkOffset3D", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_x_default_value;
	ZVAL_LONG(&property_x_default_value, 0);
	zend_string *property_x_name = zend_string_init("x", sizeof("x") - 1, 1);
	zend_declare_typed_property(class_entry, property_x_name, &property_x_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_x_name);

	zval property_y_default_value;
	ZVAL_LONG(&property_y_default_value, 0);
	zend_string *property_y_name = zend_string_init("y", sizeof("y") - 1, 1);
	zend_declare_typed_property(class_entry, property_y_name, &property_y_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_y_name);

	zval property_z_default_value;
	ZVAL_LONG(&property_z_default_value, 0);
	zend_string *property_z_name = zend_string_init("z", sizeof("z") - 1, 1);
	zend_declare_typed_property(class_entry, property_z_name, &property_z_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_z_name);

	return class_entry;
}

static zend_class_entry *register_class_VkImageSubresourceLayers(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkImageSubresourceLayers", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_aspectMask_default_value;
	ZVAL_LONG(&property_aspectMask_default_value, 0);
	zend_string *property_aspectMask_name = zend_string_init("aspectMask", sizeof("aspectMask") - 1, 1);
	zend_declare_typed_property(class_entry, property_aspectMask_name, &property_aspectMask_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_aspectMask_name);

	zval property_mipLevel_default_value;
	ZVAL_LONG(&property_mipLevel_default_value, 0);
	zend_string *property_mipLevel_name = zend_string_init("mipLevel", sizeof("mipLevel") - 1, 1);
	zend_declare_typed_property(class_entry, property_mipLevel_name, &property_mipLevel_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mipLevel_name);

	zval property_baseArrayLayer_default_value;
	ZVAL_LONG(&property_baseArrayLayer_default_value, 0);
	zend_string *property_baseArrayLayer_name = zend_string_init("baseArrayLayer", sizeof("baseArrayLayer") - 1, 1);
	zend_declare_typed_property(class_entry, property_baseArrayLayer_name, &property_baseArrayLayer_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_baseArrayLayer_name);

	zval property_layerCount_default_value;
	ZVAL_LONG(&property_layerCount_default_value, 0);
	zend_string *property_layerCount_name = zend_string_init("layerCount", sizeof("layerCount") - 1, 1);
	zend_declare_typed_property(class_entry, property_layerCount_name, &property_layerCount_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_layerCount_name);

	return class_entry;
}

static zend_class_entry *register_class_VkBufferImageCopy(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkBufferImageCopy", class_VkBufferImageCopy_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_bufferOffset_default_value;
	ZVAL_LONG(&property_bufferOffset_default_value, 0);
	zend_string *property_bufferOffset_name = zend_string_init("bufferOffset", sizeof("bufferOffset") - 1, 1);
	zend_declare_typed_property(class_entry, property_bufferOffset_name, &property_bufferOffset_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_bufferOffset_name);

	zval property_bufferRowLength_default_value;
	ZVAL_LONG(&property_bufferRowLength_default_value, 0);
	zend_string *property_bufferRowLength_name = zend_string_init("bufferRowLength", sizeof("bufferRowLength") - 1, 1);
	zend_declare_typed_property(class_entry, property_bufferRowLength_name, &property_bufferRowLength_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_bufferRowLength_name);

	zval property_bufferImageHeight_default_value;
	ZVAL_LONG(&property_bufferImageHeight_default_value, 0);
	zend_string *property_bufferImageHeight_name = zend_string_init("bufferImageHeight", sizeof("bufferImageHeight") - 1, 1);
	zend_declare_typed_property(class_entry, property_bufferImageHeight_name, &property_bufferImageHeight_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_bufferImageHeight_name);

	zval property_imageSubresource_default_value;
	ZVAL_UNDEF(&property_imageSubresource_default_value);
	zend_string *property_imageSubresource_name = zend_string_init("imageSubresource", sizeof("imageSubresource") - 1, 1);
	zend_string *property_imageSubresource_class_VkImageSubresourceLayers = zend_string_init("VkImageSubresourceLayers", sizeof("VkImageSubresourceLayers")-1, 1);
	zend_declare_typed_property(class_entry, property_imageSubresource_name, &property_imageSubresource_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_imageSubresource_class_VkImageSubresourceLayers, 0, 0));
	zend_string_release(property_imageSubresource_name);

	zval property_imageOffset_default_value;
	ZVAL_UNDEF(&property_imageOffset_default_value);
	zend_string *property_imageOffset_name = zend_string_init("imageOffset", sizeof("imageOffset") - 1, 1);
	zend_string *property_imageOffset_class_VkOffset3D = zend_string_init("VkOffset3D", sizeof("VkOffset3D")-1, 1);
	zend_declare_typed_property(class_entry, property_imageOffset_name, &property_imageOffset_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_imageOffset_class_VkOffset3D, 0, 0));
	zend_string_release(property_imageOffset_name);

	zval property_imageExtent_default_value;
	ZVAL_UNDEF(&property_imageExtent_default_value);
	zend_string *property_imageExtent_name = zend_string_init("imageExtent", sizeof("imageExtent") - 1, 1);
	zend_string *property_imageExtent_class_VkExtent3D = zend_string_init("VkExtent3D", sizeof("VkExtent3D")-1, 1);
	zend_declare_typed_property(class_entry, property_imageExtent_name, &property_imageExtent_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_imageExtent_class_VkExtent3D, 0, 0));
	zend_string_release(property_imageExtent_name);

	return class_entry;
}

static zend_class_entry *register_class_VkImageBlit(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkImageBlit", class_VkImageBlit_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_srcSubresource_default_value;
	ZVAL_UNDEF(&property_srcSubresource_default_value);
	zend_string *property_srcSubresource_name = zend_string_init("srcSubresource", sizeof("srcSubresource") - 1, 1);
	zend_string *property_srcSubresource_class_VkImageSubresourceLayers = zend_string_init("VkImageSubresourceLayers", sizeof("VkImageSubresourceLayers")-1, 1);
	zend_declare_typed_property(class_entry, property_srcSubresource_name, &property_srcSubresource_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_srcSubresource_class_VkImageSubresourceLayers, 0, 0));
	zend_string_release(property_srcSubresource_name);

	zval property_srcOffsets_default_value;
	ZVAL_EMPTY_ARRAY(&property_srcOffsets_default_value);
	zend_string *property_srcOffsets_name = zend_string_init("srcOffsets", sizeof("srcOffsets") - 1, 1);
	zend_declare_typed_property(class_entry, property_srcOffsets_name, &property_srcOffsets_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_srcOffsets_name);

	zval property_dstSubresource_default_value;
	ZVAL_UNDEF(&property_dstSubresource_default_value);
	zend_string *property_dstSubresource_name = zend_string_init("dstSubresource", sizeof("dstSubresource") - 1, 1);
	zend_string *property_dstSubresource_class_VkImageSubresourceLayers = zend_string_init("VkImageSubresourceLayers", sizeof("VkImageSubresourceLayers")-1, 1);
	zend_declare_typed_property(class_entry, property_dstSubresource_name, &property_dstSubresource_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_dstSubresource_class_VkImageSubresourceLayers, 0, 0));
	zend_string_release(property_dstSubresource_name);

	zval property_dstOffsets_default_value;
	ZVAL_EMPTY_ARRAY(&property_dstOffsets_default_value);
	zend_string *property_dstOffsets_name = zend_string_init("dstOffsets", sizeof("dstOffsets") - 1, 1);
	zend_declare_typed_property(class_entry, property_dstOffsets_name, &property_dstOffsets_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_dstOffsets_name);

	return class_entry;
}

static zend_class_entry *register_class_VkMemoryBarrier(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkMemoryBarrier", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_pNext_default_value;
	ZVAL_NULL(&property_pNext_default_value);
	zend_string *property_pNext_name = zend_string_init("pNext", sizeof("pNext") - 1, 1);
	zend_declare_typed_property(class_entry, property_pNext_name, &property_pNext_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_OBJECT|MAY_BE_NULL));
	zend_string_release(property_pNext_name);

	zval property_srcAccessMask_default_value;
	ZVAL_LONG(&property_srcAccessMask_default_value, 0);
	zend_string *property_srcAccessMask_name = zend_string_init("srcAccessMask", sizeof("srcAccessMask") - 1, 1);
	zend_declare_typed_property(class_entry, property_srcAccessMask_name, &property_srcAccessMask_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_srcAccessMask_name);

	zval property_dstAccessMask_default_value;
	ZVAL_LONG(&property_dstAccessMask_default_value, 0);
	zend_string *property_dstAccessMask_name = zend_string_init("dstAccessMask", sizeof("dstAccessMask") - 1, 1);
	zend_declare_typed_property(class_entry, property_dstAccessMask_name, &property_dstAccessMask_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_dstAccessMask_name);

	return class_entry;
}

static zend_class_entry *register_class_VkImageMemoryBarrier(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkImageMemoryBarrier", class_VkImageMemoryBarrier_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_pNext_default_value;
	ZVAL_NULL(&property_pNext_default_value);
	zend_string *property_pNext_name = zend_string_init("pNext", sizeof("pNext") - 1, 1);
	zend_declare_typed_property(class_entry, property_pNext_name, &property_pNext_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_OBJECT|MAY_BE_NULL));
	zend_string_release(property_pNext_name);

	zval property_srcAccessMask_default_value;
	ZVAL_LONG(&property_srcAccessMask_default_value, 0);
	zend_string *property_srcAccessMask_name = zend_string_init("srcAccessMask", sizeof("srcAccessMask") - 1, 1);
	zend_declare_typed_property(class_entry, property_srcAccessMask_name, &property_srcAccessMask_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_srcAccessMask_name);

	zval property_dstAccessMask_default_value;
	ZVAL_LONG(&property_dstAccessMask_default_value, 0);
	zend_string *property_dstAccessMask_name = zend_string_init("dstAccessMask", sizeof("dstAccessMask") - 1, 1);
	zend_declare_typed_property(class_entry, property_dstAccessMask_name, &property_dstAccessMask_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_dstAccessMask_name);

	zval property_oldLayout_default_value;
	ZVAL_LONG(&property_oldLayout_default_value, 0);
	zend_string *property_oldLayout_name = zend_string_init("oldLayout", sizeof("oldLayout") - 1, 1);
	zend_declare_typed_property(class_entry, property_oldLayout_name, &property_oldLayout_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_oldLayout_name);

	zval property_newLayout_default_value;
	ZVAL_LONG(&property_newLayout_default_value, 0);
	zend_string *property_newLayout_name = zend_string_init("newLayout", sizeof("newLayout") - 1, 1);
	zend_declare_typed_property(class_entry, property_newLayout_name, &property_newLayout_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_newLayout_name);

	zval property_srcQueueFamilyIndex_default_value;
	ZVAL_LONG(&property_srcQueueFamilyIndex_default_value, 0);
	zend_string *property_srcQueueFamilyIndex_name = zend_string_init("srcQueueFamilyIndex", sizeof("srcQueueFamilyIndex") - 1, 1);
	zend_declare_typed_property(class_entry, property_srcQueueFamilyIndex_name, &property_srcQueueFamilyIndex_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_srcQueueFamilyIndex_name);

	zval property_dstQueueFamilyIndex_default_value;
	ZVAL_LONG(&property_dstQueueFamilyIndex_default_value, 0);
	zend_string *property_dstQueueFamilyIndex_name = zend_string_init("dstQueueFamilyIndex", sizeof("dstQueueFamilyIndex") - 1, 1);
	zend_declare_typed_property(class_entry, property_dstQueueFamilyIndex_name, &property_dstQueueFamilyIndex_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_dstQueueFamilyIndex_name);

	zval property_image_default_value;
	ZVAL_NULL(&property_image_default_value);
	zend_string *property_image_name = zend_string_init("image", sizeof("image") - 1, 1);
	zend_string *property_image_class_VkImage = zend_string_init("VkImage", sizeof("VkImage")-1, 1);
	zend_declare_typed_property(class_entry, property_image_name, &property_image_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_image_class_VkImage, 0, MAY_BE_NULL));
	zend_string_release(property_image_name);

	zval property_subresourceRange_default_value;
	ZVAL_UNDEF(&property_subresourceRange_default_value);
	zend_string *property_subresourceRange_name = zend_string_init("subresourceRange", sizeof("subresourceRange") - 1, 1);
	zend_string *property_subresourceRange_class_VkImageSubresourceRange = zend_string_init("VkImageSubresourceRange", sizeof("VkImageSubresourceRange")-1, 1);
	zend_declare_typed_property(class_entry, property_subresourceRange_name, &property_subresourceRange_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_subresourceRange_class_VkImageSubresourceRange, 0, 0));
	zend_string_release(property_subresourceRange_name);

	return class_entry;
}

static zend_class_entry *register_class_VkSubmitInfo(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkSubmitInfo", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_pNext_default_value;
	ZVAL_NULL(&property_pNext_default_value);
	zend_string *property_pNext_name = zend_string_init("pNext", sizeof("pNext") - 1, 1);
	zend_declare_typed_property(class_entry, property_pNext_name, &property_pNext_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_OBJECT|MAY_BE_NULL));
	zend_string_release(property_pNext_name);

	zval property_pWaitSemaphores_default_value;
	ZVAL_EMPTY_ARRAY(&property_pWaitSemaphores_default_value);
	zend_string *property_pWaitSemaphores_name = zend_string_init("pWaitSemaphores", sizeof("pWaitSemaphores") - 1, 1);
	zend_declare_typed_property(class_entry, property_pWaitSemaphores_name, &property_pWaitSemaphores_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_pWaitSemaphores_name);

	zval property_pWaitDstStageMask_default_value;
	ZVAL_EMPTY_ARRAY(&property_pWaitDstStageMask_default_value);
	zend_string *property_pWaitDstStageMask_name = zend_string_init("pWaitDstStageMask", sizeof("pWaitDstStageMask") - 1, 1);
	zend_declare_typed_property(class_entry, property_pWaitDstStageMask_name, &property_pWaitDstStageMask_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_pWaitDstStageMask_name);

	zval property_pCommandBuffers_default_value;
	ZVAL_EMPTY_ARRAY(&property_pCommandBuffers_default_value);
	zend_string *property_pCommandBuffers_name = zend_string_init("pCommandBuffers", sizeof("pCommandBuffers") - 1, 1);
	zend_declare_typed_property(class_entry, property_pCommandBuffers_name, &property_pCommandBuffers_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_pCommandBuffers_name);

	zval property_pSignalSemaphores_default_value;
	ZVAL_EMPTY_ARRAY(&property_pSignalSemaphores_default_value);
	zend_string *property_pSignalSemaphores_name = zend_string_init("pSignalSemaphores", sizeof("pSignalSemaphores") - 1, 1);
	zend_declare_typed_property(class_entry, property_pSignalSemaphores_name, &property_pSignalSemaphores_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_pSignalSemaphores_name);

	return class_entry;
}

static zend_class_entry *register_class_VkFenceCreateInfo(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkFenceCreateInfo", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_pNext_default_value;
	ZVAL_NULL(&property_pNext_default_value);
	zend_string *property_pNext_name = zend_string_init("pNext", sizeof("pNext") - 1, 1);
	zend_declare_typed_property(class_entry, property_pNext_name, &property_pNext_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_OBJECT|MAY_BE_NULL));
	zend_string_release(property_pNext_name);

	zval property_flags_default_value;
	ZVAL_LONG(&property_flags_default_value, 0);
	zend_string *property_flags_name = zend_string_init("flags", sizeof("flags") - 1, 1);
	zend_declare_typed_property(class_entry, property_flags_name, &property_flags_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_flags_name);

	return class_entry;
}

static zend_class_entry *register_class_VkSemaphoreCreateInfo(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkSemaphoreCreateInfo", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_pNext_default_value;
	ZVAL_NULL(&property_pNext_default_value);
	zend_string *property_pNext_name = zend_string_init("pNext", sizeof("pNext") - 1, 1);
	zend_declare_typed_property(class_entry, property_pNext_name, &property_pNext_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_OBJECT|MAY_BE_NULL));
	zend_string_release(property_pNext_name);

	zval property_flags_default_value;
	ZVAL_LONG(&property_flags_default_value, 0);
	zend_string *property_flags_name = zend_string_init("flags", sizeof("flags") - 1, 1);
	zend_declare_typed_property(class_entry, property_flags_name, &property_flags_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_flags_name);

	return class_entry;
}

static zend_class_entry *register_class_VkClearAttachment(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkClearAttachment", class_VkClearAttachment_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_aspectMask_default_value;
	ZVAL_LONG(&property_aspectMask_default_value, 0);
	zend_string *property_aspectMask_name = zend_string_init("aspectMask", sizeof("aspectMask") - 1, 1);
	zend_declare_typed_property(class_entry, property_aspectMask_name, &property_aspectMask_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_aspectMask_name);

	zval property_colorAttachment_default_value;
	ZVAL_LONG(&property_colorAttachment_default_value, 0);
	zend_string *property_colorAttachment_name = zend_string_init("colorAttachment", sizeof("colorAttachment") - 1, 1);
	zend_declare_typed_property(class_entry, property_colorAttachment_name, &property_colorAttachment_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_colorAttachment_name);

	zval property_clearValue_default_value;
	ZVAL_UNDEF(&property_clearValue_default_value);
	zend_string *property_clearValue_name = zend_string_init("clearValue", sizeof("clearValue") - 1, 1);
	zend_string *property_clearValue_class_VkClearValue = zend_string_init("VkClearValue", sizeof("VkClearValue")-1, 1);
	zend_declare_typed_property(class_entry, property_clearValue_name, &property_clearValue_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_clearValue_class_VkClearValue, 0, 0));
	zend_string_release(property_clearValue_name);

	return class_entry;
}

static zend_class_entry *register_class_VkClearRect(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkClearRect", class_VkClearRect_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_rect_default_value;
	ZVAL_UNDEF(&property_rect_default_value);
	zend_string *property_rect_name = zend_string_init("rect", sizeof("rect") - 1, 1);
	zend_string *property_rect_class_VkRect2D = zend_string_init("VkRect2D", sizeof("VkRect2D")-1, 1);
	zend_declare_typed_property(class_entry, property_rect_name, &property_rect_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_rect_class_VkRect2D, 0, 0));
	zend_string_release(property_rect_name);

	zval property_baseArrayLayer_default_value;
	ZVAL_LONG(&property_baseArrayLayer_default_value, 0);
	zend_string *property_baseArrayLayer_name = zend_string_init("baseArrayLayer", sizeof("baseArrayLayer") - 1, 1);
	zend_declare_typed_property(class_entry, property_baseArrayLayer_name, &property_baseArrayLayer_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_baseArrayLayer_name);

	zval property_layerCount_default_value;
	ZVAL_LONG(&property_layerCount_default_value, 0);
	zend_string *property_layerCount_name = zend_string_init("layerCount", sizeof("layerCount") - 1, 1);
	zend_declare_typed_property(class_entry, property_layerCount_name, &property_layerCount_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_layerCount_name);

	return class_entry;
}
