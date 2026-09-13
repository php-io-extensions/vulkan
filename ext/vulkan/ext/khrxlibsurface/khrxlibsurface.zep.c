
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
#include "src/vk-ext-khrxlibsurface.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Vulkan_Ext_KHRXlibSurface_KHRXlibSurface)
{
	ZEPHIR_REGISTER_CLASS(Vulkan\\Ext\\KHRXlibSurface, KHRXlibSurface, vulkan, ext_khrxlibsurface_khrxlibsurface, vulkan_ext_khrxlibsurface_khrxlibsurface_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Vulkan_Ext_KHRXlibSurface_KHRXlibSurface, vkCreateXlibSurfaceKHR)
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
	RETURN_LONG(phpvk_khrxlibsurface_vkcreatexlibsurfacekhr(&_0, &_1, &_2, &_3));
}

PHP_METHOD(Vulkan_Ext_KHRXlibSurface_KHRXlibSurface, vkGetPhysicalDeviceXlibPresentationSupportKHR)
{
	zval *physicalDevice_param = NULL, *queueFamilyIndex_param = NULL, *dpy_param = NULL, *visualID_param = NULL, _0, _1, _2, _3;
	zend_long physicalDevice, queueFamilyIndex, dpy, visualID, r = 0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(physicalDevice)
		Z_PARAM_LONG(queueFamilyIndex)
		Z_PARAM_LONG(dpy)
		Z_PARAM_LONG(visualID)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &physicalDevice_param, &queueFamilyIndex_param, &dpy_param, &visualID_param);
	ZVAL_LONG(&_0, physicalDevice);
	ZVAL_LONG(&_1, queueFamilyIndex);
	ZVAL_LONG(&_2, dpy);
	ZVAL_LONG(&_3, visualID);
	r = phpvk_khrxlibsurface_vkgetphysicaldevicexlibpresentationsupportkhr(&_0, &_1, &_2, &_3);
	RETURN_BOOL(r == 1);
}

