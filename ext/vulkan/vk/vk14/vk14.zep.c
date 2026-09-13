
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "src/vk-14.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Vulkan_VK_VK14_VK14)
{
	ZEPHIR_REGISTER_CLASS(Vulkan\\VK\\VK14, VK14, vulkan, vk_vk14_vk14, vulkan_vk_vk14_vk14_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Vulkan_VK_VK14_VK14, vkMapMemory2)
{
	zval *device_param = NULL, *pMemoryMapInfo_param = NULL, *ppData_param = NULL, _0, _1, _2;
	zend_long device, pMemoryMapInfo, ppData;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(pMemoryMapInfo)
		Z_PARAM_LONG(ppData)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &device_param, &pMemoryMapInfo_param, &ppData_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, pMemoryMapInfo);
	ZVAL_LONG(&_2, ppData);
	RETURN_LONG(phpvk_vk14_vkmapmemory2(&_0, &_1, &_2));
}

PHP_METHOD(Vulkan_VK_VK14_VK14, vkUnmapMemory2)
{
	zval *device_param = NULL, *pMemoryUnmapInfo_param = NULL, _0, _1;
	zend_long device, pMemoryUnmapInfo;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(pMemoryUnmapInfo)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &device_param, &pMemoryUnmapInfo_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, pMemoryUnmapInfo);
	RETURN_LONG(phpvk_vk14_vkunmapmemory2(&_0, &_1));
}

PHP_METHOD(Vulkan_VK_VK14_VK14, vkGetDeviceImageSubresourceLayout)
{
	zval *device_param = NULL, *pInfo_param = NULL, *pLayout_param = NULL, _0, _1, _2;
	zend_long device, pInfo, pLayout;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(pInfo)
		Z_PARAM_LONG(pLayout)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &device_param, &pInfo_param, &pLayout_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, pInfo);
	ZVAL_LONG(&_2, pLayout);
	phpvk_vk14_vkgetdeviceimagesubresourcelayout(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK14_VK14, vkGetImageSubresourceLayout2)
{
	zval *device_param = NULL, *image_param = NULL, *pSubresource_param = NULL, *pLayout_param = NULL, _0, _1, _2, _3;
	zend_long device, image, pSubresource, pLayout;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(image)
		Z_PARAM_LONG(pSubresource)
		Z_PARAM_LONG(pLayout)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &device_param, &image_param, &pSubresource_param, &pLayout_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, image);
	ZVAL_LONG(&_2, pSubresource);
	ZVAL_LONG(&_3, pLayout);
	phpvk_vk14_vkgetimagesubresourcelayout2(&_0, &_1, &_2, &_3);
}

PHP_METHOD(Vulkan_VK_VK14_VK14, vkCopyMemoryToImage)
{
	zval *device_param = NULL, *pCopyMemoryToImageInfo_param = NULL, _0, _1;
	zend_long device, pCopyMemoryToImageInfo;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(pCopyMemoryToImageInfo)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &device_param, &pCopyMemoryToImageInfo_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, pCopyMemoryToImageInfo);
	RETURN_LONG(phpvk_vk14_vkcopymemorytoimage(&_0, &_1));
}

PHP_METHOD(Vulkan_VK_VK14_VK14, vkCopyImageToMemory)
{
	zval *device_param = NULL, *pCopyImageToMemoryInfo_param = NULL, _0, _1;
	zend_long device, pCopyImageToMemoryInfo;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(pCopyImageToMemoryInfo)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &device_param, &pCopyImageToMemoryInfo_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, pCopyImageToMemoryInfo);
	RETURN_LONG(phpvk_vk14_vkcopyimagetomemory(&_0, &_1));
}

PHP_METHOD(Vulkan_VK_VK14_VK14, vkCopyImageToImage)
{
	zval *device_param = NULL, *pCopyImageToImageInfo_param = NULL, _0, _1;
	zend_long device, pCopyImageToImageInfo;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(pCopyImageToImageInfo)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &device_param, &pCopyImageToImageInfo_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, pCopyImageToImageInfo);
	RETURN_LONG(phpvk_vk14_vkcopyimagetoimage(&_0, &_1));
}

PHP_METHOD(Vulkan_VK_VK14_VK14, vkTransitionImageLayout)
{
	zval *device_param = NULL, *transitionCount_param = NULL, *pTransitions_param = NULL, _0, _1, _2;
	zend_long device, transitionCount, pTransitions;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(transitionCount)
		Z_PARAM_LONG(pTransitions)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &device_param, &transitionCount_param, &pTransitions_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, transitionCount);
	ZVAL_LONG(&_2, pTransitions);
	RETURN_LONG(phpvk_vk14_vktransitionimagelayout(&_0, &_1, &_2));
}

PHP_METHOD(Vulkan_VK_VK14_VK14, vkCmdPushDescriptorSet)
{
	zval *commandBuffer_param = NULL, *pipelineBindPoint_param = NULL, *layout_param = NULL, *set_param = NULL, *descriptorWriteCount_param = NULL, *pDescriptorWrites_param = NULL, _0, _1, _2, _3, _4, _5;
	zend_long commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(pipelineBindPoint)
		Z_PARAM_LONG(layout)
		Z_PARAM_LONG(set)
		Z_PARAM_LONG(descriptorWriteCount)
		Z_PARAM_LONG(pDescriptorWrites)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(6, 0, &commandBuffer_param, &pipelineBindPoint_param, &layout_param, &set_param, &descriptorWriteCount_param, &pDescriptorWrites_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, pipelineBindPoint);
	ZVAL_LONG(&_2, layout);
	ZVAL_LONG(&_3, set);
	ZVAL_LONG(&_4, descriptorWriteCount);
	ZVAL_LONG(&_5, pDescriptorWrites);
	phpvk_vk14_vkcmdpushdescriptorset(&_0, &_1, &_2, &_3, &_4, &_5);
}

PHP_METHOD(Vulkan_VK_VK14_VK14, vkCmdPushDescriptorSetWithTemplate)
{
	zval *commandBuffer_param = NULL, *descriptorUpdateTemplate_param = NULL, *layout_param = NULL, *set_param = NULL, *pData_param = NULL, _0, _1, _2, _3, _4;
	zend_long commandBuffer, descriptorUpdateTemplate, layout, set, pData;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(descriptorUpdateTemplate)
		Z_PARAM_LONG(layout)
		Z_PARAM_LONG(set)
		Z_PARAM_LONG(pData)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &commandBuffer_param, &descriptorUpdateTemplate_param, &layout_param, &set_param, &pData_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, descriptorUpdateTemplate);
	ZVAL_LONG(&_2, layout);
	ZVAL_LONG(&_3, set);
	ZVAL_LONG(&_4, pData);
	phpvk_vk14_vkcmdpushdescriptorsetwithtemplate(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(Vulkan_VK_VK14_VK14, vkCmdBindDescriptorSets2)
{
	zval *commandBuffer_param = NULL, *pBindDescriptorSetsInfo_param = NULL, _0, _1;
	zend_long commandBuffer, pBindDescriptorSetsInfo;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(pBindDescriptorSetsInfo)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &commandBuffer_param, &pBindDescriptorSetsInfo_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, pBindDescriptorSetsInfo);
	phpvk_vk14_vkcmdbinddescriptorsets2(&_0, &_1);
}

PHP_METHOD(Vulkan_VK_VK14_VK14, vkCmdPushConstants2)
{
	zval *commandBuffer_param = NULL, *pPushConstantsInfo_param = NULL, _0, _1;
	zend_long commandBuffer, pPushConstantsInfo;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(pPushConstantsInfo)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &commandBuffer_param, &pPushConstantsInfo_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, pPushConstantsInfo);
	phpvk_vk14_vkcmdpushconstants2(&_0, &_1);
}

PHP_METHOD(Vulkan_VK_VK14_VK14, vkCmdPushDescriptorSet2)
{
	zval *commandBuffer_param = NULL, *pPushDescriptorSetInfo_param = NULL, _0, _1;
	zend_long commandBuffer, pPushDescriptorSetInfo;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(pPushDescriptorSetInfo)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &commandBuffer_param, &pPushDescriptorSetInfo_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, pPushDescriptorSetInfo);
	phpvk_vk14_vkcmdpushdescriptorset2(&_0, &_1);
}

PHP_METHOD(Vulkan_VK_VK14_VK14, vkCmdPushDescriptorSetWithTemplate2)
{
	zval *commandBuffer_param = NULL, *pPushDescriptorSetWithTemplateInfo_param = NULL, _0, _1;
	zend_long commandBuffer, pPushDescriptorSetWithTemplateInfo;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(pPushDescriptorSetWithTemplateInfo)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &commandBuffer_param, &pPushDescriptorSetWithTemplateInfo_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, pPushDescriptorSetWithTemplateInfo);
	phpvk_vk14_vkcmdpushdescriptorsetwithtemplate2(&_0, &_1);
}

PHP_METHOD(Vulkan_VK_VK14_VK14, vkCmdSetLineStipple)
{
	zval *commandBuffer_param = NULL, *lineStippleFactor_param = NULL, *lineStipplePattern_param = NULL, _0, _1, _2;
	zend_long commandBuffer, lineStippleFactor, lineStipplePattern;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(lineStippleFactor)
		Z_PARAM_LONG(lineStipplePattern)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &commandBuffer_param, &lineStippleFactor_param, &lineStipplePattern_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, lineStippleFactor);
	ZVAL_LONG(&_2, lineStipplePattern);
	phpvk_vk14_vkcmdsetlinestipple(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK14_VK14, vkCmdBindIndexBuffer2)
{
	zval *commandBuffer_param = NULL, *buffer_param = NULL, *offset_param = NULL, *size_param = NULL, *indexType_param = NULL, _0, _1, _2, _3, _4;
	zend_long commandBuffer, buffer, offset, size, indexType;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(buffer)
		Z_PARAM_LONG(offset)
		Z_PARAM_LONG(size)
		Z_PARAM_LONG(indexType)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &commandBuffer_param, &buffer_param, &offset_param, &size_param, &indexType_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, buffer);
	ZVAL_LONG(&_2, offset);
	ZVAL_LONG(&_3, size);
	ZVAL_LONG(&_4, indexType);
	phpvk_vk14_vkcmdbindindexbuffer2(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(Vulkan_VK_VK14_VK14, vkGetRenderingAreaGranularity)
{
	zval *device_param = NULL, *pRenderingAreaInfo_param = NULL, *pGranularity_param = NULL, _0, _1, _2;
	zend_long device, pRenderingAreaInfo, pGranularity;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(pRenderingAreaInfo)
		Z_PARAM_LONG(pGranularity)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &device_param, &pRenderingAreaInfo_param, &pGranularity_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, pRenderingAreaInfo);
	ZVAL_LONG(&_2, pGranularity);
	phpvk_vk14_vkgetrenderingareagranularity(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK14_VK14, vkCmdSetRenderingAttachmentLocations)
{
	zval *commandBuffer_param = NULL, *pLocationInfo_param = NULL, _0, _1;
	zend_long commandBuffer, pLocationInfo;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(pLocationInfo)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &commandBuffer_param, &pLocationInfo_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, pLocationInfo);
	phpvk_vk14_vkcmdsetrenderingattachmentlocations(&_0, &_1);
}

PHP_METHOD(Vulkan_VK_VK14_VK14, vkCmdSetRenderingInputAttachmentIndices)
{
	zval *commandBuffer_param = NULL, *pInputAttachmentIndexInfo_param = NULL, _0, _1;
	zend_long commandBuffer, pInputAttachmentIndexInfo;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(pInputAttachmentIndexInfo)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &commandBuffer_param, &pInputAttachmentIndexInfo_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, pInputAttachmentIndexInfo);
	phpvk_vk14_vkcmdsetrenderinginputattachmentindices(&_0, &_1);
}

