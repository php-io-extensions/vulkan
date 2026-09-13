
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
#include "src/vk-ext-extmetalobjects.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Vulkan_Ext_EXTMetalObjects_EXTMetalObjects)
{
	ZEPHIR_REGISTER_CLASS(Vulkan\\Ext\\EXTMetalObjects, EXTMetalObjects, vulkan, ext_extmetalobjects_extmetalobjects, vulkan_ext_extmetalobjects_extmetalobjects_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Vulkan_Ext_EXTMetalObjects_EXTMetalObjects, vkExportMetalObjectsEXT)
{
	zval *device_param = NULL, *pMetalObjectsInfo_param = NULL, _0, _1;
	zend_long device, pMetalObjectsInfo;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(pMetalObjectsInfo)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &device_param, &pMetalObjectsInfo_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, pMetalObjectsInfo);
	phpvk_extmetalobjects_vkexportmetalobjectsext(&_0, &_1);
}

