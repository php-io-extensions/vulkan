
extern zend_class_entry *vulkan_vk_vk10_vk10_ce;

ZEPHIR_INIT_CLASS(Vulkan_VK_VK10_VK10);

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCreateInstance);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkDestroyInstance);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkEnumeratePhysicalDevices);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkGetPhysicalDeviceFeatures);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkGetPhysicalDeviceFormatProperties);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkGetPhysicalDeviceImageFormatProperties);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkGetPhysicalDeviceProperties);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkGetPhysicalDeviceQueueFamilyProperties);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkGetPhysicalDeviceMemoryProperties);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkGetInstanceProcAddr);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkGetDeviceProcAddr);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCreateDevice);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkDestroyDevice);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkEnumerateInstanceExtensionProperties);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkEnumerateDeviceExtensionProperties);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkEnumerateInstanceLayerProperties);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkEnumerateDeviceLayerProperties);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkGetDeviceQueue);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkQueueSubmit);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkQueueWaitIdle);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkDeviceWaitIdle);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkAllocateMemory);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkFreeMemory);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkMapMemory);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkUnmapMemory);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkFlushMappedMemoryRanges);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkInvalidateMappedMemoryRanges);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkGetDeviceMemoryCommitment);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkBindBufferMemory);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkBindImageMemory);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkGetBufferMemoryRequirements);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkGetImageMemoryRequirements);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkGetImageSparseMemoryRequirements);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkGetPhysicalDeviceSparseImageFormatProperties);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkQueueBindSparse);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCreateFence);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkDestroyFence);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkResetFences);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkGetFenceStatus);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkWaitForFences);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCreateSemaphore);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkDestroySemaphore);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCreateQueryPool);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkDestroyQueryPool);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkGetQueryPoolResults);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCreateBuffer);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkDestroyBuffer);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCreateImage);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkDestroyImage);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkGetImageSubresourceLayout);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCreateImageView);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkDestroyImageView);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCreateCommandPool);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkDestroyCommandPool);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkResetCommandPool);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkAllocateCommandBuffers);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkFreeCommandBuffers);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkBeginCommandBuffer);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkEndCommandBuffer);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkResetCommandBuffer);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdCopyBuffer);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdCopyImage);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdCopyBufferToImage);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdCopyImageToBuffer);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdUpdateBuffer);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdFillBuffer);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdPipelineBarrier);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdBeginQuery);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdEndQuery);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdResetQueryPool);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdWriteTimestamp);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdCopyQueryPoolResults);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdExecuteCommands);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCreateEvent);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkDestroyEvent);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkGetEventStatus);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkSetEvent);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkResetEvent);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCreateBufferView);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkDestroyBufferView);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCreateShaderModule);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkDestroyShaderModule);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCreatePipelineCache);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkDestroyPipelineCache);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkGetPipelineCacheData);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkMergePipelineCaches);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCreateComputePipelines);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkDestroyPipeline);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCreatePipelineLayout);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkDestroyPipelineLayout);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCreateSampler);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkDestroySampler);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCreateDescriptorSetLayout);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkDestroyDescriptorSetLayout);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCreateDescriptorPool);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkDestroyDescriptorPool);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkResetDescriptorPool);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkAllocateDescriptorSets);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkFreeDescriptorSets);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkUpdateDescriptorSets);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdBindPipeline);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdBindDescriptorSets);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdClearColorImage);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdDispatch);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdDispatchIndirect);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdSetEvent);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdResetEvent);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdWaitEvents);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdPushConstants);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCreateGraphicsPipelines);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCreateFramebuffer);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkDestroyFramebuffer);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCreateRenderPass);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkDestroyRenderPass);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkGetRenderAreaGranularity);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdSetViewport);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdSetScissor);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdSetLineWidth);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdSetDepthBias);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdSetBlendConstants);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdSetDepthBounds);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdSetStencilCompareMask);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdSetStencilWriteMask);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdSetStencilReference);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdBindIndexBuffer);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdBindVertexBuffers);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdDraw);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdDrawIndexed);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdDrawIndirect);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdDrawIndexedIndirect);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdBlitImage);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdClearDepthStencilImage);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdClearAttachments);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdResolveImage);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdBeginRenderPass);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdNextSubpass);
PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdEndRenderPass);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcreateinstance, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pCreateInfo, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pInstance, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkdestroyinstance, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, instance, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkenumeratephysicaldevices, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, instance, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pPhysicalDeviceCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pPhysicalDevices, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkgetphysicaldevicefeatures, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, physicalDevice, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pFeatures, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkgetphysicaldeviceformatproperties, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, physicalDevice, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, format, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pFormatProperties, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkgetphysicaldeviceimageformatproperties, 0, 7, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, physicalDevice, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, format, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, tiling, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, usage, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, flags, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pImageFormatProperties, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkgetphysicaldeviceproperties, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, physicalDevice, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pProperties, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkgetphysicaldevicequeuefamilyproperties, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, physicalDevice, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pQueueFamilyPropertyCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pQueueFamilyProperties, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkgetphysicaldevicememoryproperties, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, physicalDevice, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pMemoryProperties, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkgetinstanceprocaddr, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, instance, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkgetdeviceprocaddr, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcreatedevice, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, physicalDevice, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pCreateInfo, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pDevice, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkdestroydevice, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkenumerateinstanceextensionproperties, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pLayerName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, pPropertyCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pProperties, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkenumeratedeviceextensionproperties, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, physicalDevice, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pLayerName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, pPropertyCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pProperties, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkenumerateinstancelayerproperties, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pPropertyCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pProperties, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkenumeratedevicelayerproperties, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, physicalDevice, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pPropertyCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pProperties, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkgetdevicequeue, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, queueFamilyIndex, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, queueIndex, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pQueue, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkqueuesubmit, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, queue, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, submitCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pSubmits, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, fence, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkqueuewaitidle, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, queue, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkdevicewaitidle, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkallocatememory, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocateInfo, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pMemory, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkfreememory, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, memory, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkmapmemory, 0, 6, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, memory, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, offset, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, size, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, flags, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ppData, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkunmapmemory, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, memory, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkflushmappedmemoryranges, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, memoryRangeCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pMemoryRanges, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkinvalidatemappedmemoryranges, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, memoryRangeCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pMemoryRanges, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkgetdevicememorycommitment, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, memory, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pCommittedMemoryInBytes, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkbindbuffermemory, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, buffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, memory, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, memoryOffset, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkbindimagememory, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, image, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, memory, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, memoryOffset, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkgetbuffermemoryrequirements, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, buffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pMemoryRequirements, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkgetimagememoryrequirements, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, image, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pMemoryRequirements, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkgetimagesparsememoryrequirements, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, image, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pSparseMemoryRequirementCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pSparseMemoryRequirements, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkgetphysicaldevicesparseimageformatproperties, 0, 8, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, physicalDevice, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, format, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, samples, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, usage, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, tiling, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pPropertyCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pProperties, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkqueuebindsparse, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, queue, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, bindInfoCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pBindInfo, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, fence, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcreatefence, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pCreateInfo, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pFence, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkdestroyfence, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, fence, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkresetfences, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, fenceCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pFences, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkgetfencestatus, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, fence, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkwaitforfences, 0, 5, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, fenceCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pFences, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, waitAll, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, timeout, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcreatesemaphore, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pCreateInfo, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pSemaphore, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkdestroysemaphore, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, semaphore, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcreatequerypool, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pCreateInfo, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pQueryPool, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkdestroyquerypool, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, queryPool, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkgetquerypoolresults, 0, 8, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, queryPool, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, firstQuery, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, queryCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, dataSize, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pData, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, stride, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, flags, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcreatebuffer, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pCreateInfo, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pBuffer, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkdestroybuffer, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, buffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcreateimage, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pCreateInfo, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pImage, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkdestroyimage, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, image, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkgetimagesubresourcelayout, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, image, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pSubresource, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pLayout, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcreateimageview, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pCreateInfo, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pView, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkdestroyimageview, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, imageView, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcreatecommandpool, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pCreateInfo, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pCommandPool, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkdestroycommandpool, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, commandPool, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkresetcommandpool, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, commandPool, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, flags, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkallocatecommandbuffers, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocateInfo, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pCommandBuffers, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkfreecommandbuffers, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, commandPool, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, commandBufferCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pCommandBuffers, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkbegincommandbuffer, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pBeginInfo, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkendcommandbuffer, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkresetcommandbuffer, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, flags, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcmdcopybuffer, 0, 5, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, srcBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, dstBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, regionCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pRegions, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcmdcopyimage, 0, 7, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, srcImage, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, srcImageLayout, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, dstImage, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, dstImageLayout, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, regionCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pRegions, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcmdcopybuffertoimage, 0, 6, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, srcBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, dstImage, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, dstImageLayout, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, regionCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pRegions, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcmdcopyimagetobuffer, 0, 6, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, srcImage, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, srcImageLayout, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, dstBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, regionCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pRegions, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcmdupdatebuffer, 0, 5, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, dstBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, dstOffset, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, dataSize, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pData, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcmdfillbuffer, 0, 5, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, dstBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, dstOffset, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, size, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, data, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcmdpipelinebarrier, 0, 10, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, srcStageMask, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, dstStageMask, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, dependencyFlags, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, memoryBarrierCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pMemoryBarriers, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, bufferMemoryBarrierCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pBufferMemoryBarriers, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, imageMemoryBarrierCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pImageMemoryBarriers, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcmdbeginquery, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, queryPool, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, query, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, flags, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcmdendquery, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, queryPool, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, query, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcmdresetquerypool, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, queryPool, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, firstQuery, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, queryCount, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcmdwritetimestamp, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pipelineStage, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, queryPool, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, query, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcmdcopyquerypoolresults, 0, 8, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, queryPool, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, firstQuery, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, queryCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, dstBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, dstOffset, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, stride, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, flags, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcmdexecutecommands, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, commandBufferCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pCommandBuffers, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcreateevent, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pCreateInfo, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pEvent, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkdestroyevent, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, event, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkgeteventstatus, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, event, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vksetevent, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, event, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkresetevent, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, event, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcreatebufferview, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pCreateInfo, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pView, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkdestroybufferview, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, bufferView, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcreateshadermodule, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pCreateInfo, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pShaderModule, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkdestroyshadermodule, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, shaderModule, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcreatepipelinecache, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pCreateInfo, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pPipelineCache, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkdestroypipelinecache, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pipelineCache, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkgetpipelinecachedata, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pipelineCache, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pDataSize, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pData, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkmergepipelinecaches, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, dstCache, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, srcCacheCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pSrcCaches, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcreatecomputepipelines, 0, 6, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pipelineCache, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, createInfoCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pCreateInfos, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pPipelines, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkdestroypipeline, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pipeline, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcreatepipelinelayout, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pCreateInfo, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pPipelineLayout, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkdestroypipelinelayout, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pipelineLayout, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcreatesampler, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pCreateInfo, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pSampler, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkdestroysampler, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, sampler, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcreatedescriptorsetlayout, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pCreateInfo, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pSetLayout, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkdestroydescriptorsetlayout, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, descriptorSetLayout, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcreatedescriptorpool, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pCreateInfo, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pDescriptorPool, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkdestroydescriptorpool, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, descriptorPool, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkresetdescriptorpool, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, descriptorPool, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, flags, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkallocatedescriptorsets, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocateInfo, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pDescriptorSets, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkfreedescriptorsets, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, descriptorPool, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, descriptorSetCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pDescriptorSets, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkupdatedescriptorsets, 0, 5, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, descriptorWriteCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pDescriptorWrites, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, descriptorCopyCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pDescriptorCopies, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcmdbindpipeline, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pipelineBindPoint, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pipeline, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcmdbinddescriptorsets, 0, 8, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pipelineBindPoint, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, layout, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, firstSet, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, descriptorSetCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pDescriptorSets, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, dynamicOffsetCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pDynamicOffsets, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcmdclearcolorimage, 0, 6, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, image, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, imageLayout, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pColor, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, rangeCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pRanges, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcmddispatch, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, groupCountX, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, groupCountY, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, groupCountZ, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcmddispatchindirect, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, buffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, offset, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcmdsetevent, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, event, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, stageMask, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcmdresetevent, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, event, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, stageMask, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcmdwaitevents, 0, 11, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, eventCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pEvents, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, srcStageMask, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, dstStageMask, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, memoryBarrierCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pMemoryBarriers, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, bufferMemoryBarrierCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pBufferMemoryBarriers, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, imageMemoryBarrierCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pImageMemoryBarriers, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcmdpushconstants, 0, 6, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, layout, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, stageFlags, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, offset, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, size, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pValues, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcreategraphicspipelines, 0, 6, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pipelineCache, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, createInfoCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pCreateInfos, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pPipelines, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcreateframebuffer, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pCreateInfo, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pFramebuffer, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkdestroyframebuffer, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, framebuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcreaterenderpass, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pCreateInfo, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pRenderPass, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkdestroyrenderpass, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, renderPass, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkgetrenderareagranularity, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, renderPass, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pGranularity, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcmdsetviewport, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, firstViewport, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, viewportCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pViewports, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcmdsetscissor, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, firstScissor, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, scissorCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pScissors, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcmdsetlinewidth, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, lineWidth, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcmdsetdepthbias, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, depthBiasConstantFactor, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, depthBiasClamp, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, depthBiasSlopeFactor, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcmdsetblendconstants, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, blendConstants, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcmdsetdepthbounds, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, minDepthBounds, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, maxDepthBounds, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcmdsetstencilcomparemask, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, faceMask, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, compareMask, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcmdsetstencilwritemask, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, faceMask, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, writeMask, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcmdsetstencilreference, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, faceMask, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, reference, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcmdbindindexbuffer, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, buffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, offset, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, indexType, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcmdbindvertexbuffers, 0, 5, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, firstBinding, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, bindingCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pBuffers, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pOffsets, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcmddraw, 0, 5, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, vertexCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, instanceCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, firstVertex, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, firstInstance, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcmddrawindexed, 0, 6, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, indexCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, instanceCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, firstIndex, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, vertexOffset, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, firstInstance, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcmddrawindirect, 0, 5, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, buffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, offset, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, drawCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, stride, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcmddrawindexedindirect, 0, 5, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, buffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, offset, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, drawCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, stride, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcmdblitimage, 0, 8, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, srcImage, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, srcImageLayout, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, dstImage, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, dstImageLayout, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, regionCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pRegions, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, filter, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcmdcleardepthstencilimage, 0, 6, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, image, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, imageLayout, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pDepthStencil, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, rangeCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pRanges, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcmdclearattachments, 0, 5, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, attachmentCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAttachments, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, rectCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pRects, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcmdresolveimage, 0, 7, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, srcImage, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, srcImageLayout, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, dstImage, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, dstImageLayout, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, regionCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pRegions, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcmdbeginrenderpass, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pRenderPassBegin, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, contents, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcmdnextsubpass, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, contents, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk10_vk10_vkcmdendrenderpass, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vulkan_vk_vk10_vk10_method_entry) {
	PHP_ME(Vulkan_VK_VK10_VK10, vkCreateInstance, arginfo_vulkan_vk_vk10_vk10_vkcreateinstance, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkDestroyInstance, arginfo_vulkan_vk_vk10_vk10_vkdestroyinstance, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkEnumeratePhysicalDevices, arginfo_vulkan_vk_vk10_vk10_vkenumeratephysicaldevices, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkGetPhysicalDeviceFeatures, arginfo_vulkan_vk_vk10_vk10_vkgetphysicaldevicefeatures, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkGetPhysicalDeviceFormatProperties, arginfo_vulkan_vk_vk10_vk10_vkgetphysicaldeviceformatproperties, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkGetPhysicalDeviceImageFormatProperties, arginfo_vulkan_vk_vk10_vk10_vkgetphysicaldeviceimageformatproperties, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkGetPhysicalDeviceProperties, arginfo_vulkan_vk_vk10_vk10_vkgetphysicaldeviceproperties, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkGetPhysicalDeviceQueueFamilyProperties, arginfo_vulkan_vk_vk10_vk10_vkgetphysicaldevicequeuefamilyproperties, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkGetPhysicalDeviceMemoryProperties, arginfo_vulkan_vk_vk10_vk10_vkgetphysicaldevicememoryproperties, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkGetInstanceProcAddr, arginfo_vulkan_vk_vk10_vk10_vkgetinstanceprocaddr, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkGetDeviceProcAddr, arginfo_vulkan_vk_vk10_vk10_vkgetdeviceprocaddr, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCreateDevice, arginfo_vulkan_vk_vk10_vk10_vkcreatedevice, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkDestroyDevice, arginfo_vulkan_vk_vk10_vk10_vkdestroydevice, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkEnumerateInstanceExtensionProperties, arginfo_vulkan_vk_vk10_vk10_vkenumerateinstanceextensionproperties, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkEnumerateDeviceExtensionProperties, arginfo_vulkan_vk_vk10_vk10_vkenumeratedeviceextensionproperties, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkEnumerateInstanceLayerProperties, arginfo_vulkan_vk_vk10_vk10_vkenumerateinstancelayerproperties, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkEnumerateDeviceLayerProperties, arginfo_vulkan_vk_vk10_vk10_vkenumeratedevicelayerproperties, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkGetDeviceQueue, arginfo_vulkan_vk_vk10_vk10_vkgetdevicequeue, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkQueueSubmit, arginfo_vulkan_vk_vk10_vk10_vkqueuesubmit, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkQueueWaitIdle, arginfo_vulkan_vk_vk10_vk10_vkqueuewaitidle, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkDeviceWaitIdle, arginfo_vulkan_vk_vk10_vk10_vkdevicewaitidle, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkAllocateMemory, arginfo_vulkan_vk_vk10_vk10_vkallocatememory, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkFreeMemory, arginfo_vulkan_vk_vk10_vk10_vkfreememory, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkMapMemory, arginfo_vulkan_vk_vk10_vk10_vkmapmemory, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkUnmapMemory, arginfo_vulkan_vk_vk10_vk10_vkunmapmemory, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkFlushMappedMemoryRanges, arginfo_vulkan_vk_vk10_vk10_vkflushmappedmemoryranges, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkInvalidateMappedMemoryRanges, arginfo_vulkan_vk_vk10_vk10_vkinvalidatemappedmemoryranges, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkGetDeviceMemoryCommitment, arginfo_vulkan_vk_vk10_vk10_vkgetdevicememorycommitment, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkBindBufferMemory, arginfo_vulkan_vk_vk10_vk10_vkbindbuffermemory, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkBindImageMemory, arginfo_vulkan_vk_vk10_vk10_vkbindimagememory, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkGetBufferMemoryRequirements, arginfo_vulkan_vk_vk10_vk10_vkgetbuffermemoryrequirements, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkGetImageMemoryRequirements, arginfo_vulkan_vk_vk10_vk10_vkgetimagememoryrequirements, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkGetImageSparseMemoryRequirements, arginfo_vulkan_vk_vk10_vk10_vkgetimagesparsememoryrequirements, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkGetPhysicalDeviceSparseImageFormatProperties, arginfo_vulkan_vk_vk10_vk10_vkgetphysicaldevicesparseimageformatproperties, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkQueueBindSparse, arginfo_vulkan_vk_vk10_vk10_vkqueuebindsparse, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCreateFence, arginfo_vulkan_vk_vk10_vk10_vkcreatefence, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkDestroyFence, arginfo_vulkan_vk_vk10_vk10_vkdestroyfence, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkResetFences, arginfo_vulkan_vk_vk10_vk10_vkresetfences, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkGetFenceStatus, arginfo_vulkan_vk_vk10_vk10_vkgetfencestatus, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkWaitForFences, arginfo_vulkan_vk_vk10_vk10_vkwaitforfences, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCreateSemaphore, arginfo_vulkan_vk_vk10_vk10_vkcreatesemaphore, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkDestroySemaphore, arginfo_vulkan_vk_vk10_vk10_vkdestroysemaphore, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCreateQueryPool, arginfo_vulkan_vk_vk10_vk10_vkcreatequerypool, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkDestroyQueryPool, arginfo_vulkan_vk_vk10_vk10_vkdestroyquerypool, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkGetQueryPoolResults, arginfo_vulkan_vk_vk10_vk10_vkgetquerypoolresults, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCreateBuffer, arginfo_vulkan_vk_vk10_vk10_vkcreatebuffer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkDestroyBuffer, arginfo_vulkan_vk_vk10_vk10_vkdestroybuffer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCreateImage, arginfo_vulkan_vk_vk10_vk10_vkcreateimage, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkDestroyImage, arginfo_vulkan_vk_vk10_vk10_vkdestroyimage, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkGetImageSubresourceLayout, arginfo_vulkan_vk_vk10_vk10_vkgetimagesubresourcelayout, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCreateImageView, arginfo_vulkan_vk_vk10_vk10_vkcreateimageview, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkDestroyImageView, arginfo_vulkan_vk_vk10_vk10_vkdestroyimageview, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCreateCommandPool, arginfo_vulkan_vk_vk10_vk10_vkcreatecommandpool, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkDestroyCommandPool, arginfo_vulkan_vk_vk10_vk10_vkdestroycommandpool, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkResetCommandPool, arginfo_vulkan_vk_vk10_vk10_vkresetcommandpool, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkAllocateCommandBuffers, arginfo_vulkan_vk_vk10_vk10_vkallocatecommandbuffers, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkFreeCommandBuffers, arginfo_vulkan_vk_vk10_vk10_vkfreecommandbuffers, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkBeginCommandBuffer, arginfo_vulkan_vk_vk10_vk10_vkbegincommandbuffer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkEndCommandBuffer, arginfo_vulkan_vk_vk10_vk10_vkendcommandbuffer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkResetCommandBuffer, arginfo_vulkan_vk_vk10_vk10_vkresetcommandbuffer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCmdCopyBuffer, arginfo_vulkan_vk_vk10_vk10_vkcmdcopybuffer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCmdCopyImage, arginfo_vulkan_vk_vk10_vk10_vkcmdcopyimage, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCmdCopyBufferToImage, arginfo_vulkan_vk_vk10_vk10_vkcmdcopybuffertoimage, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCmdCopyImageToBuffer, arginfo_vulkan_vk_vk10_vk10_vkcmdcopyimagetobuffer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCmdUpdateBuffer, arginfo_vulkan_vk_vk10_vk10_vkcmdupdatebuffer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCmdFillBuffer, arginfo_vulkan_vk_vk10_vk10_vkcmdfillbuffer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCmdPipelineBarrier, arginfo_vulkan_vk_vk10_vk10_vkcmdpipelinebarrier, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCmdBeginQuery, arginfo_vulkan_vk_vk10_vk10_vkcmdbeginquery, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCmdEndQuery, arginfo_vulkan_vk_vk10_vk10_vkcmdendquery, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCmdResetQueryPool, arginfo_vulkan_vk_vk10_vk10_vkcmdresetquerypool, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCmdWriteTimestamp, arginfo_vulkan_vk_vk10_vk10_vkcmdwritetimestamp, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCmdCopyQueryPoolResults, arginfo_vulkan_vk_vk10_vk10_vkcmdcopyquerypoolresults, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCmdExecuteCommands, arginfo_vulkan_vk_vk10_vk10_vkcmdexecutecommands, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCreateEvent, arginfo_vulkan_vk_vk10_vk10_vkcreateevent, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkDestroyEvent, arginfo_vulkan_vk_vk10_vk10_vkdestroyevent, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkGetEventStatus, arginfo_vulkan_vk_vk10_vk10_vkgeteventstatus, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkSetEvent, arginfo_vulkan_vk_vk10_vk10_vksetevent, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkResetEvent, arginfo_vulkan_vk_vk10_vk10_vkresetevent, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCreateBufferView, arginfo_vulkan_vk_vk10_vk10_vkcreatebufferview, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkDestroyBufferView, arginfo_vulkan_vk_vk10_vk10_vkdestroybufferview, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCreateShaderModule, arginfo_vulkan_vk_vk10_vk10_vkcreateshadermodule, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkDestroyShaderModule, arginfo_vulkan_vk_vk10_vk10_vkdestroyshadermodule, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCreatePipelineCache, arginfo_vulkan_vk_vk10_vk10_vkcreatepipelinecache, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkDestroyPipelineCache, arginfo_vulkan_vk_vk10_vk10_vkdestroypipelinecache, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkGetPipelineCacheData, arginfo_vulkan_vk_vk10_vk10_vkgetpipelinecachedata, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkMergePipelineCaches, arginfo_vulkan_vk_vk10_vk10_vkmergepipelinecaches, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCreateComputePipelines, arginfo_vulkan_vk_vk10_vk10_vkcreatecomputepipelines, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkDestroyPipeline, arginfo_vulkan_vk_vk10_vk10_vkdestroypipeline, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCreatePipelineLayout, arginfo_vulkan_vk_vk10_vk10_vkcreatepipelinelayout, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkDestroyPipelineLayout, arginfo_vulkan_vk_vk10_vk10_vkdestroypipelinelayout, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCreateSampler, arginfo_vulkan_vk_vk10_vk10_vkcreatesampler, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkDestroySampler, arginfo_vulkan_vk_vk10_vk10_vkdestroysampler, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCreateDescriptorSetLayout, arginfo_vulkan_vk_vk10_vk10_vkcreatedescriptorsetlayout, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkDestroyDescriptorSetLayout, arginfo_vulkan_vk_vk10_vk10_vkdestroydescriptorsetlayout, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCreateDescriptorPool, arginfo_vulkan_vk_vk10_vk10_vkcreatedescriptorpool, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkDestroyDescriptorPool, arginfo_vulkan_vk_vk10_vk10_vkdestroydescriptorpool, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkResetDescriptorPool, arginfo_vulkan_vk_vk10_vk10_vkresetdescriptorpool, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkAllocateDescriptorSets, arginfo_vulkan_vk_vk10_vk10_vkallocatedescriptorsets, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkFreeDescriptorSets, arginfo_vulkan_vk_vk10_vk10_vkfreedescriptorsets, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkUpdateDescriptorSets, arginfo_vulkan_vk_vk10_vk10_vkupdatedescriptorsets, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCmdBindPipeline, arginfo_vulkan_vk_vk10_vk10_vkcmdbindpipeline, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCmdBindDescriptorSets, arginfo_vulkan_vk_vk10_vk10_vkcmdbinddescriptorsets, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCmdClearColorImage, arginfo_vulkan_vk_vk10_vk10_vkcmdclearcolorimage, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCmdDispatch, arginfo_vulkan_vk_vk10_vk10_vkcmddispatch, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCmdDispatchIndirect, arginfo_vulkan_vk_vk10_vk10_vkcmddispatchindirect, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCmdSetEvent, arginfo_vulkan_vk_vk10_vk10_vkcmdsetevent, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCmdResetEvent, arginfo_vulkan_vk_vk10_vk10_vkcmdresetevent, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCmdWaitEvents, arginfo_vulkan_vk_vk10_vk10_vkcmdwaitevents, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCmdPushConstants, arginfo_vulkan_vk_vk10_vk10_vkcmdpushconstants, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCreateGraphicsPipelines, arginfo_vulkan_vk_vk10_vk10_vkcreategraphicspipelines, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCreateFramebuffer, arginfo_vulkan_vk_vk10_vk10_vkcreateframebuffer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkDestroyFramebuffer, arginfo_vulkan_vk_vk10_vk10_vkdestroyframebuffer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCreateRenderPass, arginfo_vulkan_vk_vk10_vk10_vkcreaterenderpass, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkDestroyRenderPass, arginfo_vulkan_vk_vk10_vk10_vkdestroyrenderpass, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkGetRenderAreaGranularity, arginfo_vulkan_vk_vk10_vk10_vkgetrenderareagranularity, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCmdSetViewport, arginfo_vulkan_vk_vk10_vk10_vkcmdsetviewport, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCmdSetScissor, arginfo_vulkan_vk_vk10_vk10_vkcmdsetscissor, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCmdSetLineWidth, arginfo_vulkan_vk_vk10_vk10_vkcmdsetlinewidth, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCmdSetDepthBias, arginfo_vulkan_vk_vk10_vk10_vkcmdsetdepthbias, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCmdSetBlendConstants, arginfo_vulkan_vk_vk10_vk10_vkcmdsetblendconstants, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCmdSetDepthBounds, arginfo_vulkan_vk_vk10_vk10_vkcmdsetdepthbounds, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCmdSetStencilCompareMask, arginfo_vulkan_vk_vk10_vk10_vkcmdsetstencilcomparemask, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCmdSetStencilWriteMask, arginfo_vulkan_vk_vk10_vk10_vkcmdsetstencilwritemask, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCmdSetStencilReference, arginfo_vulkan_vk_vk10_vk10_vkcmdsetstencilreference, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCmdBindIndexBuffer, arginfo_vulkan_vk_vk10_vk10_vkcmdbindindexbuffer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCmdBindVertexBuffers, arginfo_vulkan_vk_vk10_vk10_vkcmdbindvertexbuffers, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCmdDraw, arginfo_vulkan_vk_vk10_vk10_vkcmddraw, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCmdDrawIndexed, arginfo_vulkan_vk_vk10_vk10_vkcmddrawindexed, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCmdDrawIndirect, arginfo_vulkan_vk_vk10_vk10_vkcmddrawindirect, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCmdDrawIndexedIndirect, arginfo_vulkan_vk_vk10_vk10_vkcmddrawindexedindirect, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCmdBlitImage, arginfo_vulkan_vk_vk10_vk10_vkcmdblitimage, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCmdClearDepthStencilImage, arginfo_vulkan_vk_vk10_vk10_vkcmdcleardepthstencilimage, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCmdClearAttachments, arginfo_vulkan_vk_vk10_vk10_vkcmdclearattachments, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCmdResolveImage, arginfo_vulkan_vk_vk10_vk10_vkcmdresolveimage, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCmdBeginRenderPass, arginfo_vulkan_vk_vk10_vk10_vkcmdbeginrenderpass, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCmdNextSubpass, arginfo_vulkan_vk_vk10_vk10_vkcmdnextsubpass, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK10_VK10, vkCmdEndRenderPass, arginfo_vulkan_vk_vk10_vk10_vkcmdendrenderpass, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
