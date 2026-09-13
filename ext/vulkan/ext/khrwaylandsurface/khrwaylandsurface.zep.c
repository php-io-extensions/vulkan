
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
#include "src/vk-ext-khrwaylandsurface.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Vulkan_Ext_KHRWaylandSurface_KHRWaylandSurface)
{
	ZEPHIR_REGISTER_CLASS(Vulkan\\Ext\\KHRWaylandSurface, KHRWaylandSurface, vulkan, ext_khrwaylandsurface_khrwaylandsurface, vulkan_ext_khrwaylandsurface_khrwaylandsurface_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Vulkan_Ext_KHRWaylandSurface_KHRWaylandSurface, vkCreateWaylandSurfaceKHR)
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
	RETURN_LONG(phpvk_khrwaylandsurface_vkcreatewaylandsurfacekhr(&_0, &_1, &_2, &_3));
}

PHP_METHOD(Vulkan_Ext_KHRWaylandSurface_KHRWaylandSurface, vkGetPhysicalDeviceWaylandPresentationSupportKHR)
{
	zval *physicalDevice_param = NULL, *queueFamilyIndex_param = NULL, *display_param = NULL, _0, _1, _2;
	zend_long physicalDevice, queueFamilyIndex, display, r = 0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(physicalDevice)
		Z_PARAM_LONG(queueFamilyIndex)
		Z_PARAM_LONG(display)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &physicalDevice_param, &queueFamilyIndex_param, &display_param);
	ZVAL_LONG(&_0, physicalDevice);
	ZVAL_LONG(&_1, queueFamilyIndex);
	ZVAL_LONG(&_2, display);
	r = phpvk_khrwaylandsurface_vkgetphysicaldevicewaylandpresentationsupportkhr(&_0, &_1, &_2);
	RETURN_BOOL(r == 1);
}

