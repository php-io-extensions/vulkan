
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
#include "src/vk-ext-khrsurface.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Vulkan_Ext_KHRSurface_KHRSurface)
{
	ZEPHIR_REGISTER_CLASS(Vulkan\\Ext\\KHRSurface, KHRSurface, vulkan, ext_khrsurface_khrsurface, vulkan_ext_khrsurface_khrsurface_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Vulkan_Ext_KHRSurface_KHRSurface, vkDestroySurfaceKHR)
{
	zval *instance_param = NULL, *surface_param = NULL, *pAllocator_param = NULL, _0, _1, _2;
	zend_long instance, surface, pAllocator;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(instance)
		Z_PARAM_LONG(surface)
		Z_PARAM_LONG(pAllocator)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &instance_param, &surface_param, &pAllocator_param);
	ZVAL_LONG(&_0, instance);
	ZVAL_LONG(&_1, surface);
	ZVAL_LONG(&_2, pAllocator);
	phpvk_khrsurface_vkdestroysurfacekhr(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_Ext_KHRSurface_KHRSurface, vkGetPhysicalDeviceSurfaceSupportKHR)
{
	zval *physicalDevice_param = NULL, *queueFamilyIndex_param = NULL, *surface_param = NULL, *pSupported_param = NULL, _0, _1, _2, _3;
	zend_long physicalDevice, queueFamilyIndex, surface, pSupported;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(physicalDevice)
		Z_PARAM_LONG(queueFamilyIndex)
		Z_PARAM_LONG(surface)
		Z_PARAM_LONG(pSupported)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &physicalDevice_param, &queueFamilyIndex_param, &surface_param, &pSupported_param);
	ZVAL_LONG(&_0, physicalDevice);
	ZVAL_LONG(&_1, queueFamilyIndex);
	ZVAL_LONG(&_2, surface);
	ZVAL_LONG(&_3, pSupported);
	RETURN_LONG(phpvk_khrsurface_vkgetphysicaldevicesurfacesupportkhr(&_0, &_1, &_2, &_3));
}

PHP_METHOD(Vulkan_Ext_KHRSurface_KHRSurface, vkGetPhysicalDeviceSurfaceCapabilitiesKHR)
{
	zval *physicalDevice_param = NULL, *surface_param = NULL, *pSurfaceCapabilities_param = NULL, _0, _1, _2;
	zend_long physicalDevice, surface, pSurfaceCapabilities;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(physicalDevice)
		Z_PARAM_LONG(surface)
		Z_PARAM_LONG(pSurfaceCapabilities)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &physicalDevice_param, &surface_param, &pSurfaceCapabilities_param);
	ZVAL_LONG(&_0, physicalDevice);
	ZVAL_LONG(&_1, surface);
	ZVAL_LONG(&_2, pSurfaceCapabilities);
	RETURN_LONG(phpvk_khrsurface_vkgetphysicaldevicesurfacecapabilitieskhr(&_0, &_1, &_2));
}

PHP_METHOD(Vulkan_Ext_KHRSurface_KHRSurface, vkGetPhysicalDeviceSurfaceFormatsKHR)
{
	zval *physicalDevice_param = NULL, *surface_param = NULL, *pSurfaceFormatCount_param = NULL, *pSurfaceFormats_param = NULL, _0, _1, _2, _3;
	zend_long physicalDevice, surface, pSurfaceFormatCount, pSurfaceFormats;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(physicalDevice)
		Z_PARAM_LONG(surface)
		Z_PARAM_LONG(pSurfaceFormatCount)
		Z_PARAM_LONG(pSurfaceFormats)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &physicalDevice_param, &surface_param, &pSurfaceFormatCount_param, &pSurfaceFormats_param);
	ZVAL_LONG(&_0, physicalDevice);
	ZVAL_LONG(&_1, surface);
	ZVAL_LONG(&_2, pSurfaceFormatCount);
	ZVAL_LONG(&_3, pSurfaceFormats);
	RETURN_LONG(phpvk_khrsurface_vkgetphysicaldevicesurfaceformatskhr(&_0, &_1, &_2, &_3));
}

PHP_METHOD(Vulkan_Ext_KHRSurface_KHRSurface, vkGetPhysicalDeviceSurfacePresentModesKHR)
{
	zval *physicalDevice_param = NULL, *surface_param = NULL, *pPresentModeCount_param = NULL, *pPresentModes_param = NULL, _0, _1, _2, _3;
	zend_long physicalDevice, surface, pPresentModeCount, pPresentModes;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(physicalDevice)
		Z_PARAM_LONG(surface)
		Z_PARAM_LONG(pPresentModeCount)
		Z_PARAM_LONG(pPresentModes)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &physicalDevice_param, &surface_param, &pPresentModeCount_param, &pPresentModes_param);
	ZVAL_LONG(&_0, physicalDevice);
	ZVAL_LONG(&_1, surface);
	ZVAL_LONG(&_2, pPresentModeCount);
	ZVAL_LONG(&_3, pPresentModes);
	RETURN_LONG(phpvk_khrsurface_vkgetphysicaldevicesurfacepresentmodeskhr(&_0, &_1, &_2, &_3));
}

