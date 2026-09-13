
extern zend_class_entry *vulkan_vk_vk14_vk14_ce;

ZEPHIR_INIT_CLASS(Vulkan_VK_VK14_VK14);

PHP_METHOD(Vulkan_VK_VK14_VK14, vkMapMemory2);
PHP_METHOD(Vulkan_VK_VK14_VK14, vkUnmapMemory2);
PHP_METHOD(Vulkan_VK_VK14_VK14, vkGetDeviceImageSubresourceLayout);
PHP_METHOD(Vulkan_VK_VK14_VK14, vkGetImageSubresourceLayout2);
PHP_METHOD(Vulkan_VK_VK14_VK14, vkCopyMemoryToImage);
PHP_METHOD(Vulkan_VK_VK14_VK14, vkCopyImageToMemory);
PHP_METHOD(Vulkan_VK_VK14_VK14, vkCopyImageToImage);
PHP_METHOD(Vulkan_VK_VK14_VK14, vkTransitionImageLayout);
PHP_METHOD(Vulkan_VK_VK14_VK14, vkCmdPushDescriptorSet);
PHP_METHOD(Vulkan_VK_VK14_VK14, vkCmdPushDescriptorSetWithTemplate);
PHP_METHOD(Vulkan_VK_VK14_VK14, vkCmdBindDescriptorSets2);
PHP_METHOD(Vulkan_VK_VK14_VK14, vkCmdPushConstants2);
PHP_METHOD(Vulkan_VK_VK14_VK14, vkCmdPushDescriptorSet2);
PHP_METHOD(Vulkan_VK_VK14_VK14, vkCmdPushDescriptorSetWithTemplate2);
PHP_METHOD(Vulkan_VK_VK14_VK14, vkCmdSetLineStipple);
PHP_METHOD(Vulkan_VK_VK14_VK14, vkCmdBindIndexBuffer2);
PHP_METHOD(Vulkan_VK_VK14_VK14, vkGetRenderingAreaGranularity);
PHP_METHOD(Vulkan_VK_VK14_VK14, vkCmdSetRenderingAttachmentLocations);
PHP_METHOD(Vulkan_VK_VK14_VK14, vkCmdSetRenderingInputAttachmentIndices);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk14_vk14_vkmapmemory2, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pMemoryMapInfo, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ppData, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk14_vk14_vkunmapmemory2, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pMemoryUnmapInfo, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk14_vk14_vkgetdeviceimagesubresourcelayout, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pInfo, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pLayout, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk14_vk14_vkgetimagesubresourcelayout2, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, image, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pSubresource, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pLayout, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk14_vk14_vkcopymemorytoimage, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pCopyMemoryToImageInfo, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk14_vk14_vkcopyimagetomemory, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pCopyImageToMemoryInfo, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk14_vk14_vkcopyimagetoimage, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pCopyImageToImageInfo, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk14_vk14_vktransitionimagelayout, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, transitionCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pTransitions, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk14_vk14_vkcmdpushdescriptorset, 0, 6, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pipelineBindPoint, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, layout, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, set, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, descriptorWriteCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pDescriptorWrites, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk14_vk14_vkcmdpushdescriptorsetwithtemplate, 0, 5, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, descriptorUpdateTemplate, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, layout, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, set, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pData, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk14_vk14_vkcmdbinddescriptorsets2, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pBindDescriptorSetsInfo, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk14_vk14_vkcmdpushconstants2, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pPushConstantsInfo, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk14_vk14_vkcmdpushdescriptorset2, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pPushDescriptorSetInfo, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk14_vk14_vkcmdpushdescriptorsetwithtemplate2, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pPushDescriptorSetWithTemplateInfo, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk14_vk14_vkcmdsetlinestipple, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, lineStippleFactor, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, lineStipplePattern, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk14_vk14_vkcmdbindindexbuffer2, 0, 5, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, buffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, offset, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, size, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, indexType, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk14_vk14_vkgetrenderingareagranularity, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pRenderingAreaInfo, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pGranularity, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk14_vk14_vkcmdsetrenderingattachmentlocations, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pLocationInfo, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk14_vk14_vkcmdsetrenderinginputattachmentindices, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pInputAttachmentIndexInfo, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vulkan_vk_vk14_vk14_method_entry) {
	PHP_ME(Vulkan_VK_VK14_VK14, vkMapMemory2, arginfo_vulkan_vk_vk14_vk14_vkmapmemory2, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK14_VK14, vkUnmapMemory2, arginfo_vulkan_vk_vk14_vk14_vkunmapmemory2, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK14_VK14, vkGetDeviceImageSubresourceLayout, arginfo_vulkan_vk_vk14_vk14_vkgetdeviceimagesubresourcelayout, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK14_VK14, vkGetImageSubresourceLayout2, arginfo_vulkan_vk_vk14_vk14_vkgetimagesubresourcelayout2, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK14_VK14, vkCopyMemoryToImage, arginfo_vulkan_vk_vk14_vk14_vkcopymemorytoimage, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK14_VK14, vkCopyImageToMemory, arginfo_vulkan_vk_vk14_vk14_vkcopyimagetomemory, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK14_VK14, vkCopyImageToImage, arginfo_vulkan_vk_vk14_vk14_vkcopyimagetoimage, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK14_VK14, vkTransitionImageLayout, arginfo_vulkan_vk_vk14_vk14_vktransitionimagelayout, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK14_VK14, vkCmdPushDescriptorSet, arginfo_vulkan_vk_vk14_vk14_vkcmdpushdescriptorset, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK14_VK14, vkCmdPushDescriptorSetWithTemplate, arginfo_vulkan_vk_vk14_vk14_vkcmdpushdescriptorsetwithtemplate, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK14_VK14, vkCmdBindDescriptorSets2, arginfo_vulkan_vk_vk14_vk14_vkcmdbinddescriptorsets2, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK14_VK14, vkCmdPushConstants2, arginfo_vulkan_vk_vk14_vk14_vkcmdpushconstants2, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK14_VK14, vkCmdPushDescriptorSet2, arginfo_vulkan_vk_vk14_vk14_vkcmdpushdescriptorset2, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK14_VK14, vkCmdPushDescriptorSetWithTemplate2, arginfo_vulkan_vk_vk14_vk14_vkcmdpushdescriptorsetwithtemplate2, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK14_VK14, vkCmdSetLineStipple, arginfo_vulkan_vk_vk14_vk14_vkcmdsetlinestipple, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK14_VK14, vkCmdBindIndexBuffer2, arginfo_vulkan_vk_vk14_vk14_vkcmdbindindexbuffer2, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK14_VK14, vkGetRenderingAreaGranularity, arginfo_vulkan_vk_vk14_vk14_vkgetrenderingareagranularity, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK14_VK14, vkCmdSetRenderingAttachmentLocations, arginfo_vulkan_vk_vk14_vk14_vkcmdsetrenderingattachmentlocations, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK14_VK14, vkCmdSetRenderingInputAttachmentIndices, arginfo_vulkan_vk_vk14_vk14_vkcmdsetrenderinginputattachmentindices, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
