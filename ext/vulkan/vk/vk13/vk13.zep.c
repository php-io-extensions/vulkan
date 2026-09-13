
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
#include "src/vk-13.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Vulkan_VK_VK13_VK13)
{
	ZEPHIR_REGISTER_CLASS(Vulkan\\VK\\VK13, VK13, vulkan, vk_vk13_vk13, vulkan_vk_vk13_vk13_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Vulkan_VK_VK13_VK13, vkGetPhysicalDeviceToolProperties)
{
	zval *physicalDevice_param = NULL, *pToolCount_param = NULL, *pToolProperties_param = NULL, _0, _1, _2;
	zend_long physicalDevice, pToolCount, pToolProperties;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(physicalDevice)
		Z_PARAM_LONG(pToolCount)
		Z_PARAM_LONG(pToolProperties)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &physicalDevice_param, &pToolCount_param, &pToolProperties_param);
	ZVAL_LONG(&_0, physicalDevice);
	ZVAL_LONG(&_1, pToolCount);
	ZVAL_LONG(&_2, pToolProperties);
	RETURN_LONG(phpvk_vk13_vkgetphysicaldevicetoolproperties(&_0, &_1, &_2));
}

PHP_METHOD(Vulkan_VK_VK13_VK13, vkCreatePrivateDataSlot)
{
	zval *device_param = NULL, *pCreateInfo_param = NULL, *pAllocator_param = NULL, *pPrivateDataSlot_param = NULL, _0, _1, _2, _3;
	zend_long device, pCreateInfo, pAllocator, pPrivateDataSlot;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(pCreateInfo)
		Z_PARAM_LONG(pAllocator)
		Z_PARAM_LONG(pPrivateDataSlot)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &device_param, &pCreateInfo_param, &pAllocator_param, &pPrivateDataSlot_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, pCreateInfo);
	ZVAL_LONG(&_2, pAllocator);
	ZVAL_LONG(&_3, pPrivateDataSlot);
	RETURN_LONG(phpvk_vk13_vkcreateprivatedataslot(&_0, &_1, &_2, &_3));
}

PHP_METHOD(Vulkan_VK_VK13_VK13, vkDestroyPrivateDataSlot)
{
	zval *device_param = NULL, *privateDataSlot_param = NULL, *pAllocator_param = NULL, _0, _1, _2;
	zend_long device, privateDataSlot, pAllocator;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(privateDataSlot)
		Z_PARAM_LONG(pAllocator)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &device_param, &privateDataSlot_param, &pAllocator_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, privateDataSlot);
	ZVAL_LONG(&_2, pAllocator);
	phpvk_vk13_vkdestroyprivatedataslot(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK13_VK13, vkSetPrivateData)
{
	zval *device_param = NULL, *objectType_param = NULL, *objectHandle_param = NULL, *privateDataSlot_param = NULL, *data_param = NULL, _0, _1, _2, _3, _4;
	zend_long device, objectType, objectHandle, privateDataSlot, data;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(objectType)
		Z_PARAM_LONG(objectHandle)
		Z_PARAM_LONG(privateDataSlot)
		Z_PARAM_LONG(data)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &device_param, &objectType_param, &objectHandle_param, &privateDataSlot_param, &data_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, objectType);
	ZVAL_LONG(&_2, objectHandle);
	ZVAL_LONG(&_3, privateDataSlot);
	ZVAL_LONG(&_4, data);
	RETURN_LONG(phpvk_vk13_vksetprivatedata(&_0, &_1, &_2, &_3, &_4));
}

PHP_METHOD(Vulkan_VK_VK13_VK13, vkGetPrivateData)
{
	zval *device_param = NULL, *objectType_param = NULL, *objectHandle_param = NULL, *privateDataSlot_param = NULL, *pData_param = NULL, _0, _1, _2, _3, _4;
	zend_long device, objectType, objectHandle, privateDataSlot, pData;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(objectType)
		Z_PARAM_LONG(objectHandle)
		Z_PARAM_LONG(privateDataSlot)
		Z_PARAM_LONG(pData)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &device_param, &objectType_param, &objectHandle_param, &privateDataSlot_param, &pData_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, objectType);
	ZVAL_LONG(&_2, objectHandle);
	ZVAL_LONG(&_3, privateDataSlot);
	ZVAL_LONG(&_4, pData);
	phpvk_vk13_vkgetprivatedata(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(Vulkan_VK_VK13_VK13, vkCmdPipelineBarrier2)
{
	zval *commandBuffer_param = NULL, *pDependencyInfo_param = NULL, _0, _1;
	zend_long commandBuffer, pDependencyInfo;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(pDependencyInfo)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &commandBuffer_param, &pDependencyInfo_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, pDependencyInfo);
	phpvk_vk13_vkcmdpipelinebarrier2(&_0, &_1);
}

PHP_METHOD(Vulkan_VK_VK13_VK13, vkCmdWriteTimestamp2)
{
	zval *commandBuffer_param = NULL, *stage_param = NULL, *queryPool_param = NULL, *query_param = NULL, _0, _1, _2, _3;
	zend_long commandBuffer, stage, queryPool, query;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(stage)
		Z_PARAM_LONG(queryPool)
		Z_PARAM_LONG(query)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &commandBuffer_param, &stage_param, &queryPool_param, &query_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, stage);
	ZVAL_LONG(&_2, queryPool);
	ZVAL_LONG(&_3, query);
	phpvk_vk13_vkcmdwritetimestamp2(&_0, &_1, &_2, &_3);
}

PHP_METHOD(Vulkan_VK_VK13_VK13, vkQueueSubmit2)
{
	zval *queue_param = NULL, *submitCount_param = NULL, *pSubmits_param = NULL, *fence_param = NULL, _0, _1, _2, _3;
	zend_long queue, submitCount, pSubmits, fence;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(queue)
		Z_PARAM_LONG(submitCount)
		Z_PARAM_LONG(pSubmits)
		Z_PARAM_LONG(fence)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &queue_param, &submitCount_param, &pSubmits_param, &fence_param);
	ZVAL_LONG(&_0, queue);
	ZVAL_LONG(&_1, submitCount);
	ZVAL_LONG(&_2, pSubmits);
	ZVAL_LONG(&_3, fence);
	RETURN_LONG(phpvk_vk13_vkqueuesubmit2(&_0, &_1, &_2, &_3));
}

PHP_METHOD(Vulkan_VK_VK13_VK13, vkCmdCopyBuffer2)
{
	zval *commandBuffer_param = NULL, *pCopyBufferInfo_param = NULL, _0, _1;
	zend_long commandBuffer, pCopyBufferInfo;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(pCopyBufferInfo)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &commandBuffer_param, &pCopyBufferInfo_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, pCopyBufferInfo);
	phpvk_vk13_vkcmdcopybuffer2(&_0, &_1);
}

PHP_METHOD(Vulkan_VK_VK13_VK13, vkCmdCopyImage2)
{
	zval *commandBuffer_param = NULL, *pCopyImageInfo_param = NULL, _0, _1;
	zend_long commandBuffer, pCopyImageInfo;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(pCopyImageInfo)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &commandBuffer_param, &pCopyImageInfo_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, pCopyImageInfo);
	phpvk_vk13_vkcmdcopyimage2(&_0, &_1);
}

PHP_METHOD(Vulkan_VK_VK13_VK13, vkCmdCopyBufferToImage2)
{
	zval *commandBuffer_param = NULL, *pCopyBufferToImageInfo_param = NULL, _0, _1;
	zend_long commandBuffer, pCopyBufferToImageInfo;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(pCopyBufferToImageInfo)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &commandBuffer_param, &pCopyBufferToImageInfo_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, pCopyBufferToImageInfo);
	phpvk_vk13_vkcmdcopybuffertoimage2(&_0, &_1);
}

PHP_METHOD(Vulkan_VK_VK13_VK13, vkCmdCopyImageToBuffer2)
{
	zval *commandBuffer_param = NULL, *pCopyImageToBufferInfo_param = NULL, _0, _1;
	zend_long commandBuffer, pCopyImageToBufferInfo;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(pCopyImageToBufferInfo)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &commandBuffer_param, &pCopyImageToBufferInfo_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, pCopyImageToBufferInfo);
	phpvk_vk13_vkcmdcopyimagetobuffer2(&_0, &_1);
}

PHP_METHOD(Vulkan_VK_VK13_VK13, vkGetDeviceBufferMemoryRequirements)
{
	zval *device_param = NULL, *pInfo_param = NULL, *pMemoryRequirements_param = NULL, _0, _1, _2;
	zend_long device, pInfo, pMemoryRequirements;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(pInfo)
		Z_PARAM_LONG(pMemoryRequirements)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &device_param, &pInfo_param, &pMemoryRequirements_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, pInfo);
	ZVAL_LONG(&_2, pMemoryRequirements);
	phpvk_vk13_vkgetdevicebuffermemoryrequirements(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK13_VK13, vkGetDeviceImageMemoryRequirements)
{
	zval *device_param = NULL, *pInfo_param = NULL, *pMemoryRequirements_param = NULL, _0, _1, _2;
	zend_long device, pInfo, pMemoryRequirements;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(pInfo)
		Z_PARAM_LONG(pMemoryRequirements)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &device_param, &pInfo_param, &pMemoryRequirements_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, pInfo);
	ZVAL_LONG(&_2, pMemoryRequirements);
	phpvk_vk13_vkgetdeviceimagememoryrequirements(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK13_VK13, vkGetDeviceImageSparseMemoryRequirements)
{
	zval *device_param = NULL, *pInfo_param = NULL, *pSparseMemoryRequirementCount_param = NULL, *pSparseMemoryRequirements_param = NULL, _0, _1, _2, _3;
	zend_long device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(pInfo)
		Z_PARAM_LONG(pSparseMemoryRequirementCount)
		Z_PARAM_LONG(pSparseMemoryRequirements)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &device_param, &pInfo_param, &pSparseMemoryRequirementCount_param, &pSparseMemoryRequirements_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, pInfo);
	ZVAL_LONG(&_2, pSparseMemoryRequirementCount);
	ZVAL_LONG(&_3, pSparseMemoryRequirements);
	phpvk_vk13_vkgetdeviceimagesparsememoryrequirements(&_0, &_1, &_2, &_3);
}

PHP_METHOD(Vulkan_VK_VK13_VK13, vkCmdSetEvent2)
{
	zval *commandBuffer_param = NULL, *event_param = NULL, *pDependencyInfo_param = NULL, _0, _1, _2;
	zend_long commandBuffer, event, pDependencyInfo;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(event)
		Z_PARAM_LONG(pDependencyInfo)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &commandBuffer_param, &event_param, &pDependencyInfo_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, event);
	ZVAL_LONG(&_2, pDependencyInfo);
	phpvk_vk13_vkcmdsetevent2(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK13_VK13, vkCmdResetEvent2)
{
	zval *commandBuffer_param = NULL, *event_param = NULL, *stageMask_param = NULL, _0, _1, _2;
	zend_long commandBuffer, event, stageMask;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(event)
		Z_PARAM_LONG(stageMask)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &commandBuffer_param, &event_param, &stageMask_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, event);
	ZVAL_LONG(&_2, stageMask);
	phpvk_vk13_vkcmdresetevent2(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK13_VK13, vkCmdWaitEvents2)
{
	zval *commandBuffer_param = NULL, *eventCount_param = NULL, *pEvents_param = NULL, *pDependencyInfos_param = NULL, _0, _1, _2, _3;
	zend_long commandBuffer, eventCount, pEvents, pDependencyInfos;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(eventCount)
		Z_PARAM_LONG(pEvents)
		Z_PARAM_LONG(pDependencyInfos)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &commandBuffer_param, &eventCount_param, &pEvents_param, &pDependencyInfos_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, eventCount);
	ZVAL_LONG(&_2, pEvents);
	ZVAL_LONG(&_3, pDependencyInfos);
	phpvk_vk13_vkcmdwaitevents2(&_0, &_1, &_2, &_3);
}

PHP_METHOD(Vulkan_VK_VK13_VK13, vkCmdBlitImage2)
{
	zval *commandBuffer_param = NULL, *pBlitImageInfo_param = NULL, _0, _1;
	zend_long commandBuffer, pBlitImageInfo;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(pBlitImageInfo)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &commandBuffer_param, &pBlitImageInfo_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, pBlitImageInfo);
	phpvk_vk13_vkcmdblitimage2(&_0, &_1);
}

PHP_METHOD(Vulkan_VK_VK13_VK13, vkCmdResolveImage2)
{
	zval *commandBuffer_param = NULL, *pResolveImageInfo_param = NULL, _0, _1;
	zend_long commandBuffer, pResolveImageInfo;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(pResolveImageInfo)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &commandBuffer_param, &pResolveImageInfo_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, pResolveImageInfo);
	phpvk_vk13_vkcmdresolveimage2(&_0, &_1);
}

PHP_METHOD(Vulkan_VK_VK13_VK13, vkCmdBeginRendering)
{
	zval *commandBuffer_param = NULL, *pRenderingInfo_param = NULL, _0, _1;
	zend_long commandBuffer, pRenderingInfo;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(pRenderingInfo)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &commandBuffer_param, &pRenderingInfo_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, pRenderingInfo);
	phpvk_vk13_vkcmdbeginrendering(&_0, &_1);
}

PHP_METHOD(Vulkan_VK_VK13_VK13, vkCmdEndRendering)
{
	zval *commandBuffer_param = NULL, _0;
	zend_long commandBuffer;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(commandBuffer)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &commandBuffer_param);
	ZVAL_LONG(&_0, commandBuffer);
	phpvk_vk13_vkcmdendrendering(&_0);
}

PHP_METHOD(Vulkan_VK_VK13_VK13, vkCmdSetCullMode)
{
	zval *commandBuffer_param = NULL, *cullMode_param = NULL, _0, _1;
	zend_long commandBuffer, cullMode;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(cullMode)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &commandBuffer_param, &cullMode_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, cullMode);
	phpvk_vk13_vkcmdsetcullmode(&_0, &_1);
}

PHP_METHOD(Vulkan_VK_VK13_VK13, vkCmdSetFrontFace)
{
	zval *commandBuffer_param = NULL, *frontFace_param = NULL, _0, _1;
	zend_long commandBuffer, frontFace;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(frontFace)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &commandBuffer_param, &frontFace_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, frontFace);
	phpvk_vk13_vkcmdsetfrontface(&_0, &_1);
}

PHP_METHOD(Vulkan_VK_VK13_VK13, vkCmdSetPrimitiveTopology)
{
	zval *commandBuffer_param = NULL, *primitiveTopology_param = NULL, _0, _1;
	zend_long commandBuffer, primitiveTopology;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(primitiveTopology)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &commandBuffer_param, &primitiveTopology_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, primitiveTopology);
	phpvk_vk13_vkcmdsetprimitivetopology(&_0, &_1);
}

PHP_METHOD(Vulkan_VK_VK13_VK13, vkCmdSetViewportWithCount)
{
	zval *commandBuffer_param = NULL, *viewportCount_param = NULL, *pViewports_param = NULL, _0, _1, _2;
	zend_long commandBuffer, viewportCount, pViewports;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(viewportCount)
		Z_PARAM_LONG(pViewports)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &commandBuffer_param, &viewportCount_param, &pViewports_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, viewportCount);
	ZVAL_LONG(&_2, pViewports);
	phpvk_vk13_vkcmdsetviewportwithcount(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK13_VK13, vkCmdSetScissorWithCount)
{
	zval *commandBuffer_param = NULL, *scissorCount_param = NULL, *pScissors_param = NULL, _0, _1, _2;
	zend_long commandBuffer, scissorCount, pScissors;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(scissorCount)
		Z_PARAM_LONG(pScissors)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &commandBuffer_param, &scissorCount_param, &pScissors_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, scissorCount);
	ZVAL_LONG(&_2, pScissors);
	phpvk_vk13_vkcmdsetscissorwithcount(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK13_VK13, vkCmdBindVertexBuffers2)
{
	zval *commandBuffer_param = NULL, *firstBinding_param = NULL, *bindingCount_param = NULL, *pBuffers_param = NULL, *pOffsets_param = NULL, *pSizes_param = NULL, *pStrides_param = NULL, _0, _1, _2, _3, _4, _5, _6;
	zend_long commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZEND_PARSE_PARAMETERS_START(7, 7)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(firstBinding)
		Z_PARAM_LONG(bindingCount)
		Z_PARAM_LONG(pBuffers)
		Z_PARAM_LONG(pOffsets)
		Z_PARAM_LONG(pSizes)
		Z_PARAM_LONG(pStrides)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(7, 0, &commandBuffer_param, &firstBinding_param, &bindingCount_param, &pBuffers_param, &pOffsets_param, &pSizes_param, &pStrides_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, firstBinding);
	ZVAL_LONG(&_2, bindingCount);
	ZVAL_LONG(&_3, pBuffers);
	ZVAL_LONG(&_4, pOffsets);
	ZVAL_LONG(&_5, pSizes);
	ZVAL_LONG(&_6, pStrides);
	phpvk_vk13_vkcmdbindvertexbuffers2(&_0, &_1, &_2, &_3, &_4, &_5, &_6);
}

PHP_METHOD(Vulkan_VK_VK13_VK13, vkCmdSetDepthTestEnable)
{
	zend_bool depthTestEnable;
	zval *commandBuffer_param = NULL, *depthTestEnable_param = NULL, _0, _1;
	zend_long commandBuffer;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_BOOL(depthTestEnable)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &commandBuffer_param, &depthTestEnable_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_BOOL(&_1, (depthTestEnable ? 1 : 0));
	phpvk_vk13_vkcmdsetdepthtestenable(&_0, &_1);
}

PHP_METHOD(Vulkan_VK_VK13_VK13, vkCmdSetDepthWriteEnable)
{
	zend_bool depthWriteEnable;
	zval *commandBuffer_param = NULL, *depthWriteEnable_param = NULL, _0, _1;
	zend_long commandBuffer;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_BOOL(depthWriteEnable)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &commandBuffer_param, &depthWriteEnable_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_BOOL(&_1, (depthWriteEnable ? 1 : 0));
	phpvk_vk13_vkcmdsetdepthwriteenable(&_0, &_1);
}

PHP_METHOD(Vulkan_VK_VK13_VK13, vkCmdSetDepthCompareOp)
{
	zval *commandBuffer_param = NULL, *depthCompareOp_param = NULL, _0, _1;
	zend_long commandBuffer, depthCompareOp;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(depthCompareOp)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &commandBuffer_param, &depthCompareOp_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, depthCompareOp);
	phpvk_vk13_vkcmdsetdepthcompareop(&_0, &_1);
}

PHP_METHOD(Vulkan_VK_VK13_VK13, vkCmdSetDepthBoundsTestEnable)
{
	zend_bool depthBoundsTestEnable;
	zval *commandBuffer_param = NULL, *depthBoundsTestEnable_param = NULL, _0, _1;
	zend_long commandBuffer;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_BOOL(depthBoundsTestEnable)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &commandBuffer_param, &depthBoundsTestEnable_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_BOOL(&_1, (depthBoundsTestEnable ? 1 : 0));
	phpvk_vk13_vkcmdsetdepthboundstestenable(&_0, &_1);
}

PHP_METHOD(Vulkan_VK_VK13_VK13, vkCmdSetStencilTestEnable)
{
	zend_bool stencilTestEnable;
	zval *commandBuffer_param = NULL, *stencilTestEnable_param = NULL, _0, _1;
	zend_long commandBuffer;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_BOOL(stencilTestEnable)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &commandBuffer_param, &stencilTestEnable_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_BOOL(&_1, (stencilTestEnable ? 1 : 0));
	phpvk_vk13_vkcmdsetstenciltestenable(&_0, &_1);
}

PHP_METHOD(Vulkan_VK_VK13_VK13, vkCmdSetStencilOp)
{
	zval *commandBuffer_param = NULL, *faceMask_param = NULL, *failOp_param = NULL, *passOp_param = NULL, *depthFailOp_param = NULL, *compareOp_param = NULL, _0, _1, _2, _3, _4, _5;
	zend_long commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(faceMask)
		Z_PARAM_LONG(failOp)
		Z_PARAM_LONG(passOp)
		Z_PARAM_LONG(depthFailOp)
		Z_PARAM_LONG(compareOp)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(6, 0, &commandBuffer_param, &faceMask_param, &failOp_param, &passOp_param, &depthFailOp_param, &compareOp_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, faceMask);
	ZVAL_LONG(&_2, failOp);
	ZVAL_LONG(&_3, passOp);
	ZVAL_LONG(&_4, depthFailOp);
	ZVAL_LONG(&_5, compareOp);
	phpvk_vk13_vkcmdsetstencilop(&_0, &_1, &_2, &_3, &_4, &_5);
}

PHP_METHOD(Vulkan_VK_VK13_VK13, vkCmdSetRasterizerDiscardEnable)
{
	zend_bool rasterizerDiscardEnable;
	zval *commandBuffer_param = NULL, *rasterizerDiscardEnable_param = NULL, _0, _1;
	zend_long commandBuffer;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_BOOL(rasterizerDiscardEnable)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &commandBuffer_param, &rasterizerDiscardEnable_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_BOOL(&_1, (rasterizerDiscardEnable ? 1 : 0));
	phpvk_vk13_vkcmdsetrasterizerdiscardenable(&_0, &_1);
}

PHP_METHOD(Vulkan_VK_VK13_VK13, vkCmdSetDepthBiasEnable)
{
	zend_bool depthBiasEnable;
	zval *commandBuffer_param = NULL, *depthBiasEnable_param = NULL, _0, _1;
	zend_long commandBuffer;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_BOOL(depthBiasEnable)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &commandBuffer_param, &depthBiasEnable_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_BOOL(&_1, (depthBiasEnable ? 1 : 0));
	phpvk_vk13_vkcmdsetdepthbiasenable(&_0, &_1);
}

PHP_METHOD(Vulkan_VK_VK13_VK13, vkCmdSetPrimitiveRestartEnable)
{
	zend_bool primitiveRestartEnable;
	zval *commandBuffer_param = NULL, *primitiveRestartEnable_param = NULL, _0, _1;
	zend_long commandBuffer;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_BOOL(primitiveRestartEnable)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &commandBuffer_param, &primitiveRestartEnable_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_BOOL(&_1, (primitiveRestartEnable ? 1 : 0));
	phpvk_vk13_vkcmdsetprimitiverestartenable(&_0, &_1);
}

