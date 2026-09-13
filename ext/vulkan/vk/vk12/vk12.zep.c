
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
#include "src/vk-12.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Vulkan_VK_VK12_VK12)
{
	ZEPHIR_REGISTER_CLASS(Vulkan\\VK\\VK12, VK12, vulkan, vk_vk12_vk12, vulkan_vk_vk12_vk12_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Vulkan_VK_VK12_VK12, vkResetQueryPool)
{
	zval *device_param = NULL, *queryPool_param = NULL, *firstQuery_param = NULL, *queryCount_param = NULL, _0, _1, _2, _3;
	zend_long device, queryPool, firstQuery, queryCount;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(queryPool)
		Z_PARAM_LONG(firstQuery)
		Z_PARAM_LONG(queryCount)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &device_param, &queryPool_param, &firstQuery_param, &queryCount_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, queryPool);
	ZVAL_LONG(&_2, firstQuery);
	ZVAL_LONG(&_3, queryCount);
	phpvk_vk12_vkresetquerypool(&_0, &_1, &_2, &_3);
}

PHP_METHOD(Vulkan_VK_VK12_VK12, vkGetSemaphoreCounterValue)
{
	zval *device_param = NULL, *semaphore_param = NULL, *pValue_param = NULL, _0, _1, _2;
	zend_long device, semaphore, pValue;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(semaphore)
		Z_PARAM_LONG(pValue)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &device_param, &semaphore_param, &pValue_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, semaphore);
	ZVAL_LONG(&_2, pValue);
	RETURN_LONG(phpvk_vk12_vkgetsemaphorecountervalue(&_0, &_1, &_2));
}

PHP_METHOD(Vulkan_VK_VK12_VK12, vkWaitSemaphores)
{
	zval *device_param = NULL, *pWaitInfo_param = NULL, *timeout_param = NULL, _0, _1, _2;
	zend_long device, pWaitInfo, timeout;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(pWaitInfo)
		Z_PARAM_LONG(timeout)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &device_param, &pWaitInfo_param, &timeout_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, pWaitInfo);
	ZVAL_LONG(&_2, timeout);
	RETURN_LONG(phpvk_vk12_vkwaitsemaphores(&_0, &_1, &_2));
}

PHP_METHOD(Vulkan_VK_VK12_VK12, vkSignalSemaphore)
{
	zval *device_param = NULL, *pSignalInfo_param = NULL, _0, _1;
	zend_long device, pSignalInfo;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(pSignalInfo)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &device_param, &pSignalInfo_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, pSignalInfo);
	RETURN_LONG(phpvk_vk12_vksignalsemaphore(&_0, &_1));
}

PHP_METHOD(Vulkan_VK_VK12_VK12, vkGetBufferDeviceAddress)
{
	zval *device_param = NULL, *pInfo_param = NULL, _0, _1;
	zend_long device, pInfo;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(pInfo)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &device_param, &pInfo_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, pInfo);
	RETURN_LONG(phpvk_vk12_vkgetbufferdeviceaddress(&_0, &_1));
}

PHP_METHOD(Vulkan_VK_VK12_VK12, vkGetBufferOpaqueCaptureAddress)
{
	zval *device_param = NULL, *pInfo_param = NULL, _0, _1;
	zend_long device, pInfo;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(pInfo)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &device_param, &pInfo_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, pInfo);
	RETURN_LONG(phpvk_vk12_vkgetbufferopaquecaptureaddress(&_0, &_1));
}

PHP_METHOD(Vulkan_VK_VK12_VK12, vkGetDeviceMemoryOpaqueCaptureAddress)
{
	zval *device_param = NULL, *pInfo_param = NULL, _0, _1;
	zend_long device, pInfo;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(pInfo)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &device_param, &pInfo_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, pInfo);
	RETURN_LONG(phpvk_vk12_vkgetdevicememoryopaquecaptureaddress(&_0, &_1));
}

PHP_METHOD(Vulkan_VK_VK12_VK12, vkCmdDrawIndirectCount)
{
	zval *commandBuffer_param = NULL, *buffer_param = NULL, *offset_param = NULL, *countBuffer_param = NULL, *countBufferOffset_param = NULL, *maxDrawCount_param = NULL, *stride_param = NULL, _0, _1, _2, _3, _4, _5, _6;
	zend_long commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZEND_PARSE_PARAMETERS_START(7, 7)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(buffer)
		Z_PARAM_LONG(offset)
		Z_PARAM_LONG(countBuffer)
		Z_PARAM_LONG(countBufferOffset)
		Z_PARAM_LONG(maxDrawCount)
		Z_PARAM_LONG(stride)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(7, 0, &commandBuffer_param, &buffer_param, &offset_param, &countBuffer_param, &countBufferOffset_param, &maxDrawCount_param, &stride_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, buffer);
	ZVAL_LONG(&_2, offset);
	ZVAL_LONG(&_3, countBuffer);
	ZVAL_LONG(&_4, countBufferOffset);
	ZVAL_LONG(&_5, maxDrawCount);
	ZVAL_LONG(&_6, stride);
	phpvk_vk12_vkcmddrawindirectcount(&_0, &_1, &_2, &_3, &_4, &_5, &_6);
}

PHP_METHOD(Vulkan_VK_VK12_VK12, vkCmdDrawIndexedIndirectCount)
{
	zval *commandBuffer_param = NULL, *buffer_param = NULL, *offset_param = NULL, *countBuffer_param = NULL, *countBufferOffset_param = NULL, *maxDrawCount_param = NULL, *stride_param = NULL, _0, _1, _2, _3, _4, _5, _6;
	zend_long commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZEND_PARSE_PARAMETERS_START(7, 7)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(buffer)
		Z_PARAM_LONG(offset)
		Z_PARAM_LONG(countBuffer)
		Z_PARAM_LONG(countBufferOffset)
		Z_PARAM_LONG(maxDrawCount)
		Z_PARAM_LONG(stride)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(7, 0, &commandBuffer_param, &buffer_param, &offset_param, &countBuffer_param, &countBufferOffset_param, &maxDrawCount_param, &stride_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, buffer);
	ZVAL_LONG(&_2, offset);
	ZVAL_LONG(&_3, countBuffer);
	ZVAL_LONG(&_4, countBufferOffset);
	ZVAL_LONG(&_5, maxDrawCount);
	ZVAL_LONG(&_6, stride);
	phpvk_vk12_vkcmddrawindexedindirectcount(&_0, &_1, &_2, &_3, &_4, &_5, &_6);
}

PHP_METHOD(Vulkan_VK_VK12_VK12, vkCreateRenderPass2)
{
	zval *device_param = NULL, *pCreateInfo_param = NULL, *pAllocator_param = NULL, *pRenderPass_param = NULL, _0, _1, _2, _3;
	zend_long device, pCreateInfo, pAllocator, pRenderPass;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(pCreateInfo)
		Z_PARAM_LONG(pAllocator)
		Z_PARAM_LONG(pRenderPass)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &device_param, &pCreateInfo_param, &pAllocator_param, &pRenderPass_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, pCreateInfo);
	ZVAL_LONG(&_2, pAllocator);
	ZVAL_LONG(&_3, pRenderPass);
	RETURN_LONG(phpvk_vk12_vkcreaterenderpass2(&_0, &_1, &_2, &_3));
}

PHP_METHOD(Vulkan_VK_VK12_VK12, vkCmdBeginRenderPass2)
{
	zval *commandBuffer_param = NULL, *pRenderPassBegin_param = NULL, *pSubpassBeginInfo_param = NULL, _0, _1, _2;
	zend_long commandBuffer, pRenderPassBegin, pSubpassBeginInfo;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(pRenderPassBegin)
		Z_PARAM_LONG(pSubpassBeginInfo)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &commandBuffer_param, &pRenderPassBegin_param, &pSubpassBeginInfo_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, pRenderPassBegin);
	ZVAL_LONG(&_2, pSubpassBeginInfo);
	phpvk_vk12_vkcmdbeginrenderpass2(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK12_VK12, vkCmdNextSubpass2)
{
	zval *commandBuffer_param = NULL, *pSubpassBeginInfo_param = NULL, *pSubpassEndInfo_param = NULL, _0, _1, _2;
	zend_long commandBuffer, pSubpassBeginInfo, pSubpassEndInfo;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(pSubpassBeginInfo)
		Z_PARAM_LONG(pSubpassEndInfo)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &commandBuffer_param, &pSubpassBeginInfo_param, &pSubpassEndInfo_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, pSubpassBeginInfo);
	ZVAL_LONG(&_2, pSubpassEndInfo);
	phpvk_vk12_vkcmdnextsubpass2(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK12_VK12, vkCmdEndRenderPass2)
{
	zval *commandBuffer_param = NULL, *pSubpassEndInfo_param = NULL, _0, _1;
	zend_long commandBuffer, pSubpassEndInfo;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(pSubpassEndInfo)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &commandBuffer_param, &pSubpassEndInfo_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, pSubpassEndInfo);
	phpvk_vk12_vkcmdendrenderpass2(&_0, &_1);
}

