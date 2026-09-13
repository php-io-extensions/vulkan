
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
#include "src/vk-ext-extdebugutils.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Vulkan_Ext_EXTDebugUtils_EXTDebugUtils)
{
	ZEPHIR_REGISTER_CLASS(Vulkan\\Ext\\EXTDebugUtils, EXTDebugUtils, vulkan, ext_extdebugutils_extdebugutils, vulkan_ext_extdebugutils_extdebugutils_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Vulkan_Ext_EXTDebugUtils_EXTDebugUtils, vkSetDebugUtilsObjectNameEXT)
{
	zval *device_param = NULL, *pNameInfo_param = NULL, _0, _1;
	zend_long device, pNameInfo;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(pNameInfo)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &device_param, &pNameInfo_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, pNameInfo);
	RETURN_LONG(phpvk_extdebugutils_vksetdebugutilsobjectnameext(&_0, &_1));
}

PHP_METHOD(Vulkan_Ext_EXTDebugUtils_EXTDebugUtils, vkSetDebugUtilsObjectTagEXT)
{
	zval *device_param = NULL, *pTagInfo_param = NULL, _0, _1;
	zend_long device, pTagInfo;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(pTagInfo)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &device_param, &pTagInfo_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, pTagInfo);
	RETURN_LONG(phpvk_extdebugutils_vksetdebugutilsobjecttagext(&_0, &_1));
}

PHP_METHOD(Vulkan_Ext_EXTDebugUtils_EXTDebugUtils, vkQueueBeginDebugUtilsLabelEXT)
{
	zval *queue_param = NULL, *pLabelInfo_param = NULL, _0, _1;
	zend_long queue, pLabelInfo;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(queue)
		Z_PARAM_LONG(pLabelInfo)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &queue_param, &pLabelInfo_param);
	ZVAL_LONG(&_0, queue);
	ZVAL_LONG(&_1, pLabelInfo);
	phpvk_extdebugutils_vkqueuebegindebugutilslabelext(&_0, &_1);
}

PHP_METHOD(Vulkan_Ext_EXTDebugUtils_EXTDebugUtils, vkQueueEndDebugUtilsLabelEXT)
{
	zval *queue_param = NULL, _0;
	zend_long queue;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(queue)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &queue_param);
	ZVAL_LONG(&_0, queue);
	phpvk_extdebugutils_vkqueueenddebugutilslabelext(&_0);
}

PHP_METHOD(Vulkan_Ext_EXTDebugUtils_EXTDebugUtils, vkQueueInsertDebugUtilsLabelEXT)
{
	zval *queue_param = NULL, *pLabelInfo_param = NULL, _0, _1;
	zend_long queue, pLabelInfo;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(queue)
		Z_PARAM_LONG(pLabelInfo)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &queue_param, &pLabelInfo_param);
	ZVAL_LONG(&_0, queue);
	ZVAL_LONG(&_1, pLabelInfo);
	phpvk_extdebugutils_vkqueueinsertdebugutilslabelext(&_0, &_1);
}

PHP_METHOD(Vulkan_Ext_EXTDebugUtils_EXTDebugUtils, vkCmdBeginDebugUtilsLabelEXT)
{
	zval *commandBuffer_param = NULL, *pLabelInfo_param = NULL, _0, _1;
	zend_long commandBuffer, pLabelInfo;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(pLabelInfo)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &commandBuffer_param, &pLabelInfo_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, pLabelInfo);
	phpvk_extdebugutils_vkcmdbegindebugutilslabelext(&_0, &_1);
}

PHP_METHOD(Vulkan_Ext_EXTDebugUtils_EXTDebugUtils, vkCmdEndDebugUtilsLabelEXT)
{
	zval *commandBuffer_param = NULL, _0;
	zend_long commandBuffer;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(commandBuffer)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &commandBuffer_param);
	ZVAL_LONG(&_0, commandBuffer);
	phpvk_extdebugutils_vkcmdenddebugutilslabelext(&_0);
}

PHP_METHOD(Vulkan_Ext_EXTDebugUtils_EXTDebugUtils, vkCmdInsertDebugUtilsLabelEXT)
{
	zval *commandBuffer_param = NULL, *pLabelInfo_param = NULL, _0, _1;
	zend_long commandBuffer, pLabelInfo;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(pLabelInfo)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &commandBuffer_param, &pLabelInfo_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, pLabelInfo);
	phpvk_extdebugutils_vkcmdinsertdebugutilslabelext(&_0, &_1);
}

PHP_METHOD(Vulkan_Ext_EXTDebugUtils_EXTDebugUtils, vkCreateDebugUtilsMessengerEXT)
{
	zval *instance_param = NULL, *pCreateInfo_param = NULL, *pAllocator_param = NULL, *pMessenger_param = NULL, _0, _1, _2, _3;
	zend_long instance, pCreateInfo, pAllocator, pMessenger;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(instance)
		Z_PARAM_LONG(pCreateInfo)
		Z_PARAM_LONG(pAllocator)
		Z_PARAM_LONG(pMessenger)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &instance_param, &pCreateInfo_param, &pAllocator_param, &pMessenger_param);
	ZVAL_LONG(&_0, instance);
	ZVAL_LONG(&_1, pCreateInfo);
	ZVAL_LONG(&_2, pAllocator);
	ZVAL_LONG(&_3, pMessenger);
	RETURN_LONG(phpvk_extdebugutils_vkcreatedebugutilsmessengerext(&_0, &_1, &_2, &_3));
}

PHP_METHOD(Vulkan_Ext_EXTDebugUtils_EXTDebugUtils, vkDestroyDebugUtilsMessengerEXT)
{
	zval *instance_param = NULL, *messenger_param = NULL, *pAllocator_param = NULL, _0, _1, _2;
	zend_long instance, messenger, pAllocator;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(instance)
		Z_PARAM_LONG(messenger)
		Z_PARAM_LONG(pAllocator)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &instance_param, &messenger_param, &pAllocator_param);
	ZVAL_LONG(&_0, instance);
	ZVAL_LONG(&_1, messenger);
	ZVAL_LONG(&_2, pAllocator);
	phpvk_extdebugutils_vkdestroydebugutilsmessengerext(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_Ext_EXTDebugUtils_EXTDebugUtils, vkSubmitDebugUtilsMessageEXT)
{
	zval *instance_param = NULL, *messageSeverity_param = NULL, *messageTypes_param = NULL, *pCallbackData_param = NULL, _0, _1, _2, _3;
	zend_long instance, messageSeverity, messageTypes, pCallbackData;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(instance)
		Z_PARAM_LONG(messageSeverity)
		Z_PARAM_LONG(messageTypes)
		Z_PARAM_LONG(pCallbackData)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &instance_param, &messageSeverity_param, &messageTypes_param, &pCallbackData_param);
	ZVAL_LONG(&_0, instance);
	ZVAL_LONG(&_1, messageSeverity);
	ZVAL_LONG(&_2, messageTypes);
	ZVAL_LONG(&_3, pCallbackData);
	phpvk_extdebugutils_vksubmitdebugutilsmessageext(&_0, &_1, &_2, &_3);
}

