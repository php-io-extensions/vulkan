
extern zend_class_entry *vulkan_vk_vk13_vk13_ce;

ZEPHIR_INIT_CLASS(Vulkan_VK_VK13_VK13);

PHP_METHOD(Vulkan_VK_VK13_VK13, vkGetPhysicalDeviceToolProperties);
PHP_METHOD(Vulkan_VK_VK13_VK13, vkCreatePrivateDataSlot);
PHP_METHOD(Vulkan_VK_VK13_VK13, vkDestroyPrivateDataSlot);
PHP_METHOD(Vulkan_VK_VK13_VK13, vkSetPrivateData);
PHP_METHOD(Vulkan_VK_VK13_VK13, vkGetPrivateData);
PHP_METHOD(Vulkan_VK_VK13_VK13, vkCmdPipelineBarrier2);
PHP_METHOD(Vulkan_VK_VK13_VK13, vkCmdWriteTimestamp2);
PHP_METHOD(Vulkan_VK_VK13_VK13, vkQueueSubmit2);
PHP_METHOD(Vulkan_VK_VK13_VK13, vkCmdCopyBuffer2);
PHP_METHOD(Vulkan_VK_VK13_VK13, vkCmdCopyImage2);
PHP_METHOD(Vulkan_VK_VK13_VK13, vkCmdCopyBufferToImage2);
PHP_METHOD(Vulkan_VK_VK13_VK13, vkCmdCopyImageToBuffer2);
PHP_METHOD(Vulkan_VK_VK13_VK13, vkGetDeviceBufferMemoryRequirements);
PHP_METHOD(Vulkan_VK_VK13_VK13, vkGetDeviceImageMemoryRequirements);
PHP_METHOD(Vulkan_VK_VK13_VK13, vkGetDeviceImageSparseMemoryRequirements);
PHP_METHOD(Vulkan_VK_VK13_VK13, vkCmdSetEvent2);
PHP_METHOD(Vulkan_VK_VK13_VK13, vkCmdResetEvent2);
PHP_METHOD(Vulkan_VK_VK13_VK13, vkCmdWaitEvents2);
PHP_METHOD(Vulkan_VK_VK13_VK13, vkCmdBlitImage2);
PHP_METHOD(Vulkan_VK_VK13_VK13, vkCmdResolveImage2);
PHP_METHOD(Vulkan_VK_VK13_VK13, vkCmdBeginRendering);
PHP_METHOD(Vulkan_VK_VK13_VK13, vkCmdEndRendering);
PHP_METHOD(Vulkan_VK_VK13_VK13, vkCmdSetCullMode);
PHP_METHOD(Vulkan_VK_VK13_VK13, vkCmdSetFrontFace);
PHP_METHOD(Vulkan_VK_VK13_VK13, vkCmdSetPrimitiveTopology);
PHP_METHOD(Vulkan_VK_VK13_VK13, vkCmdSetViewportWithCount);
PHP_METHOD(Vulkan_VK_VK13_VK13, vkCmdSetScissorWithCount);
PHP_METHOD(Vulkan_VK_VK13_VK13, vkCmdBindVertexBuffers2);
PHP_METHOD(Vulkan_VK_VK13_VK13, vkCmdSetDepthTestEnable);
PHP_METHOD(Vulkan_VK_VK13_VK13, vkCmdSetDepthWriteEnable);
PHP_METHOD(Vulkan_VK_VK13_VK13, vkCmdSetDepthCompareOp);
PHP_METHOD(Vulkan_VK_VK13_VK13, vkCmdSetDepthBoundsTestEnable);
PHP_METHOD(Vulkan_VK_VK13_VK13, vkCmdSetStencilTestEnable);
PHP_METHOD(Vulkan_VK_VK13_VK13, vkCmdSetStencilOp);
PHP_METHOD(Vulkan_VK_VK13_VK13, vkCmdSetRasterizerDiscardEnable);
PHP_METHOD(Vulkan_VK_VK13_VK13, vkCmdSetDepthBiasEnable);
PHP_METHOD(Vulkan_VK_VK13_VK13, vkCmdSetPrimitiveRestartEnable);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk13_vk13_vkgetphysicaldevicetoolproperties, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, physicalDevice, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pToolCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pToolProperties, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk13_vk13_vkcreateprivatedataslot, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pCreateInfo, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pPrivateDataSlot, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk13_vk13_vkdestroyprivatedataslot, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, privateDataSlot, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk13_vk13_vksetprivatedata, 0, 5, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, objectType, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, objectHandle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, privateDataSlot, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, data, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk13_vk13_vkgetprivatedata, 0, 5, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, objectType, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, objectHandle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, privateDataSlot, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pData, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk13_vk13_vkcmdpipelinebarrier2, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pDependencyInfo, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk13_vk13_vkcmdwritetimestamp2, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, stage, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, queryPool, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, query, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk13_vk13_vkqueuesubmit2, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, queue, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, submitCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pSubmits, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, fence, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk13_vk13_vkcmdcopybuffer2, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pCopyBufferInfo, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk13_vk13_vkcmdcopyimage2, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pCopyImageInfo, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk13_vk13_vkcmdcopybuffertoimage2, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pCopyBufferToImageInfo, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk13_vk13_vkcmdcopyimagetobuffer2, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pCopyImageToBufferInfo, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk13_vk13_vkgetdevicebuffermemoryrequirements, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pInfo, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pMemoryRequirements, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk13_vk13_vkgetdeviceimagememoryrequirements, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pInfo, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pMemoryRequirements, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk13_vk13_vkgetdeviceimagesparsememoryrequirements, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pInfo, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pSparseMemoryRequirementCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pSparseMemoryRequirements, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk13_vk13_vkcmdsetevent2, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, event, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pDependencyInfo, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk13_vk13_vkcmdresetevent2, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, event, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, stageMask, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk13_vk13_vkcmdwaitevents2, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, eventCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pEvents, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pDependencyInfos, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk13_vk13_vkcmdblitimage2, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pBlitImageInfo, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk13_vk13_vkcmdresolveimage2, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pResolveImageInfo, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk13_vk13_vkcmdbeginrendering, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pRenderingInfo, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk13_vk13_vkcmdendrendering, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk13_vk13_vkcmdsetcullmode, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, cullMode, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk13_vk13_vkcmdsetfrontface, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, frontFace, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk13_vk13_vkcmdsetprimitivetopology, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, primitiveTopology, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk13_vk13_vkcmdsetviewportwithcount, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, viewportCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pViewports, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk13_vk13_vkcmdsetscissorwithcount, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, scissorCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pScissors, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk13_vk13_vkcmdbindvertexbuffers2, 0, 7, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, firstBinding, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, bindingCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pBuffers, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pOffsets, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pSizes, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pStrides, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk13_vk13_vkcmdsetdepthtestenable, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, depthTestEnable, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk13_vk13_vkcmdsetdepthwriteenable, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, depthWriteEnable, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk13_vk13_vkcmdsetdepthcompareop, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, depthCompareOp, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk13_vk13_vkcmdsetdepthboundstestenable, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, depthBoundsTestEnable, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk13_vk13_vkcmdsetstenciltestenable, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, stencilTestEnable, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk13_vk13_vkcmdsetstencilop, 0, 6, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, faceMask, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, failOp, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, passOp, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, depthFailOp, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, compareOp, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk13_vk13_vkcmdsetrasterizerdiscardenable, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, rasterizerDiscardEnable, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk13_vk13_vkcmdsetdepthbiasenable, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, depthBiasEnable, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk13_vk13_vkcmdsetprimitiverestartenable, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, primitiveRestartEnable, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vulkan_vk_vk13_vk13_method_entry) {
	PHP_ME(Vulkan_VK_VK13_VK13, vkGetPhysicalDeviceToolProperties, arginfo_vulkan_vk_vk13_vk13_vkgetphysicaldevicetoolproperties, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK13_VK13, vkCreatePrivateDataSlot, arginfo_vulkan_vk_vk13_vk13_vkcreateprivatedataslot, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK13_VK13, vkDestroyPrivateDataSlot, arginfo_vulkan_vk_vk13_vk13_vkdestroyprivatedataslot, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK13_VK13, vkSetPrivateData, arginfo_vulkan_vk_vk13_vk13_vksetprivatedata, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK13_VK13, vkGetPrivateData, arginfo_vulkan_vk_vk13_vk13_vkgetprivatedata, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK13_VK13, vkCmdPipelineBarrier2, arginfo_vulkan_vk_vk13_vk13_vkcmdpipelinebarrier2, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK13_VK13, vkCmdWriteTimestamp2, arginfo_vulkan_vk_vk13_vk13_vkcmdwritetimestamp2, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK13_VK13, vkQueueSubmit2, arginfo_vulkan_vk_vk13_vk13_vkqueuesubmit2, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK13_VK13, vkCmdCopyBuffer2, arginfo_vulkan_vk_vk13_vk13_vkcmdcopybuffer2, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK13_VK13, vkCmdCopyImage2, arginfo_vulkan_vk_vk13_vk13_vkcmdcopyimage2, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK13_VK13, vkCmdCopyBufferToImage2, arginfo_vulkan_vk_vk13_vk13_vkcmdcopybuffertoimage2, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK13_VK13, vkCmdCopyImageToBuffer2, arginfo_vulkan_vk_vk13_vk13_vkcmdcopyimagetobuffer2, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK13_VK13, vkGetDeviceBufferMemoryRequirements, arginfo_vulkan_vk_vk13_vk13_vkgetdevicebuffermemoryrequirements, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK13_VK13, vkGetDeviceImageMemoryRequirements, arginfo_vulkan_vk_vk13_vk13_vkgetdeviceimagememoryrequirements, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK13_VK13, vkGetDeviceImageSparseMemoryRequirements, arginfo_vulkan_vk_vk13_vk13_vkgetdeviceimagesparsememoryrequirements, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK13_VK13, vkCmdSetEvent2, arginfo_vulkan_vk_vk13_vk13_vkcmdsetevent2, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK13_VK13, vkCmdResetEvent2, arginfo_vulkan_vk_vk13_vk13_vkcmdresetevent2, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK13_VK13, vkCmdWaitEvents2, arginfo_vulkan_vk_vk13_vk13_vkcmdwaitevents2, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK13_VK13, vkCmdBlitImage2, arginfo_vulkan_vk_vk13_vk13_vkcmdblitimage2, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK13_VK13, vkCmdResolveImage2, arginfo_vulkan_vk_vk13_vk13_vkcmdresolveimage2, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK13_VK13, vkCmdBeginRendering, arginfo_vulkan_vk_vk13_vk13_vkcmdbeginrendering, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK13_VK13, vkCmdEndRendering, arginfo_vulkan_vk_vk13_vk13_vkcmdendrendering, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK13_VK13, vkCmdSetCullMode, arginfo_vulkan_vk_vk13_vk13_vkcmdsetcullmode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK13_VK13, vkCmdSetFrontFace, arginfo_vulkan_vk_vk13_vk13_vkcmdsetfrontface, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK13_VK13, vkCmdSetPrimitiveTopology, arginfo_vulkan_vk_vk13_vk13_vkcmdsetprimitivetopology, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK13_VK13, vkCmdSetViewportWithCount, arginfo_vulkan_vk_vk13_vk13_vkcmdsetviewportwithcount, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK13_VK13, vkCmdSetScissorWithCount, arginfo_vulkan_vk_vk13_vk13_vkcmdsetscissorwithcount, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK13_VK13, vkCmdBindVertexBuffers2, arginfo_vulkan_vk_vk13_vk13_vkcmdbindvertexbuffers2, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK13_VK13, vkCmdSetDepthTestEnable, arginfo_vulkan_vk_vk13_vk13_vkcmdsetdepthtestenable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK13_VK13, vkCmdSetDepthWriteEnable, arginfo_vulkan_vk_vk13_vk13_vkcmdsetdepthwriteenable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK13_VK13, vkCmdSetDepthCompareOp, arginfo_vulkan_vk_vk13_vk13_vkcmdsetdepthcompareop, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK13_VK13, vkCmdSetDepthBoundsTestEnable, arginfo_vulkan_vk_vk13_vk13_vkcmdsetdepthboundstestenable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK13_VK13, vkCmdSetStencilTestEnable, arginfo_vulkan_vk_vk13_vk13_vkcmdsetstenciltestenable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK13_VK13, vkCmdSetStencilOp, arginfo_vulkan_vk_vk13_vk13_vkcmdsetstencilop, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK13_VK13, vkCmdSetRasterizerDiscardEnable, arginfo_vulkan_vk_vk13_vk13_vkcmdsetrasterizerdiscardenable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK13_VK13, vkCmdSetDepthBiasEnable, arginfo_vulkan_vk_vk13_vk13_vkcmdsetdepthbiasenable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK13_VK13, vkCmdSetPrimitiveRestartEnable, arginfo_vulkan_vk_vk13_vk13_vkcmdsetprimitiverestartenable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
