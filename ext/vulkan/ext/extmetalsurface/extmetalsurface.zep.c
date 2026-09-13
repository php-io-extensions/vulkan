
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
#include "src/vk-ext-extmetalsurface.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Vulkan_Ext_EXTMetalSurface_EXTMetalSurface)
{
	ZEPHIR_REGISTER_CLASS(Vulkan\\Ext\\EXTMetalSurface, EXTMetalSurface, vulkan, ext_extmetalsurface_extmetalsurface, vulkan_ext_extmetalsurface_extmetalsurface_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Vulkan_Ext_EXTMetalSurface_EXTMetalSurface, vkCreateMetalSurfaceEXT)
{
	zval *instance_param = NULL, *pCreateInfo_param = NULL, *pAllocator_param = NULL, *pSurface_param = NULL, _0, _1, _2, _3;
	zend_long instance, pCreateInfo, pAllocator, pSurface;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(instance)
		Z_PARAM_LONG(pCreateInfo)
		Z_PARAM_LONG(pAllocator)
		Z_PARAM_LONG(pSurface)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &instance_param, &pCreateInfo_param, &pAllocator_param, &pSurface_param);
	ZVAL_LONG(&_0, instance);
	ZVAL_LONG(&_1, pCreateInfo);
	ZVAL_LONG(&_2, pAllocator);
	ZVAL_LONG(&_3, pSurface);
	RETURN_LONG(phpvk_extmetalsurface_vkcreatemetalsurfaceext(&_0, &_1, &_2, &_3));
}

