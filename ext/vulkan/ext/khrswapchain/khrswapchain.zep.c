
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
#include "src/vk-ext-khrswapchain.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Vulkan_Ext_KHRSwapchain_KHRSwapchain)
{
	ZEPHIR_REGISTER_CLASS(Vulkan\\Ext\\KHRSwapchain, KHRSwapchain, vulkan, ext_khrswapchain_khrswapchain, vulkan_ext_khrswapchain_khrswapchain_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Vulkan_Ext_KHRSwapchain_KHRSwapchain, vkCreateSwapchainKHR)
{
	zval *device_param = NULL, *pCreateInfo_param = NULL, *pAllocator_param = NULL, *pSwapchain_param = NULL, _0, _1, _2, _3;
	zend_long device, pCreateInfo, pAllocator, pSwapchain;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(pCreateInfo)
		Z_PARAM_LONG(pAllocator)
		Z_PARAM_LONG(pSwapchain)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &device_param, &pCreateInfo_param, &pAllocator_param, &pSwapchain_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, pCreateInfo);
	ZVAL_LONG(&_2, pAllocator);
	ZVAL_LONG(&_3, pSwapchain);
	RETURN_LONG(phpvk_khrswapchain_vkcreateswapchainkhr(&_0, &_1, &_2, &_3));
}

PHP_METHOD(Vulkan_Ext_KHRSwapchain_KHRSwapchain, vkDestroySwapchainKHR)
{
	zval *device_param = NULL, *swapchain_param = NULL, *pAllocator_param = NULL, _0, _1, _2;
	zend_long device, swapchain, pAllocator;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(swapchain)
		Z_PARAM_LONG(pAllocator)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &device_param, &swapchain_param, &pAllocator_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, swapchain);
	ZVAL_LONG(&_2, pAllocator);
	phpvk_khrswapchain_vkdestroyswapchainkhr(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_Ext_KHRSwapchain_KHRSwapchain, vkGetSwapchainImagesKHR)
{
	zval *device_param = NULL, *swapchain_param = NULL, *pSwapchainImageCount_param = NULL, *pSwapchainImages_param = NULL, _0, _1, _2, _3;
	zend_long device, swapchain, pSwapchainImageCount, pSwapchainImages;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(swapchain)
		Z_PARAM_LONG(pSwapchainImageCount)
		Z_PARAM_LONG(pSwapchainImages)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &device_param, &swapchain_param, &pSwapchainImageCount_param, &pSwapchainImages_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, swapchain);
	ZVAL_LONG(&_2, pSwapchainImageCount);
	ZVAL_LONG(&_3, pSwapchainImages);
	RETURN_LONG(phpvk_khrswapchain_vkgetswapchainimageskhr(&_0, &_1, &_2, &_3));
}

PHP_METHOD(Vulkan_Ext_KHRSwapchain_KHRSwapchain, vkAcquireNextImageKHR)
{
	zval *device_param = NULL, *swapchain_param = NULL, *timeout_param = NULL, *semaphore_param = NULL, *fence_param = NULL, *pImageIndex_param = NULL, _0, _1, _2, _3, _4, _5;
	zend_long device, swapchain, timeout, semaphore, fence, pImageIndex;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(swapchain)
		Z_PARAM_LONG(timeout)
		Z_PARAM_LONG(semaphore)
		Z_PARAM_LONG(fence)
		Z_PARAM_LONG(pImageIndex)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(6, 0, &device_param, &swapchain_param, &timeout_param, &semaphore_param, &fence_param, &pImageIndex_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, swapchain);
	ZVAL_LONG(&_2, timeout);
	ZVAL_LONG(&_3, semaphore);
	ZVAL_LONG(&_4, fence);
	ZVAL_LONG(&_5, pImageIndex);
	RETURN_LONG(phpvk_khrswapchain_vkacquirenextimagekhr(&_0, &_1, &_2, &_3, &_4, &_5));
}

PHP_METHOD(Vulkan_Ext_KHRSwapchain_KHRSwapchain, vkQueuePresentKHR)
{
	zval *queue_param = NULL, *pPresentInfo_param = NULL, _0, _1;
	zend_long queue, pPresentInfo;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(queue)
		Z_PARAM_LONG(pPresentInfo)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &queue_param, &pPresentInfo_param);
	ZVAL_LONG(&_0, queue);
	ZVAL_LONG(&_1, pPresentInfo);
	RETURN_LONG(phpvk_khrswapchain_vkqueuepresentkhr(&_0, &_1));
}

PHP_METHOD(Vulkan_Ext_KHRSwapchain_KHRSwapchain, vkGetDeviceGroupPresentCapabilitiesKHR)
{
	zval *device_param = NULL, *pDeviceGroupPresentCapabilities_param = NULL, _0, _1;
	zend_long device, pDeviceGroupPresentCapabilities;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(pDeviceGroupPresentCapabilities)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &device_param, &pDeviceGroupPresentCapabilities_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, pDeviceGroupPresentCapabilities);
	RETURN_LONG(phpvk_khrswapchain_vkgetdevicegrouppresentcapabilitieskhr(&_0, &_1));
}

PHP_METHOD(Vulkan_Ext_KHRSwapchain_KHRSwapchain, vkGetDeviceGroupSurfacePresentModesKHR)
{
	zval *device_param = NULL, *surface_param = NULL, *pModes_param = NULL, _0, _1, _2;
	zend_long device, surface, pModes;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(surface)
		Z_PARAM_LONG(pModes)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &device_param, &surface_param, &pModes_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, surface);
	ZVAL_LONG(&_2, pModes);
	RETURN_LONG(phpvk_khrswapchain_vkgetdevicegroupsurfacepresentmodeskhr(&_0, &_1, &_2));
}

PHP_METHOD(Vulkan_Ext_KHRSwapchain_KHRSwapchain, vkGetPhysicalDevicePresentRectanglesKHR)
{
	zval *physicalDevice_param = NULL, *surface_param = NULL, *pRectCount_param = NULL, *pRects_param = NULL, _0, _1, _2, _3;
	zend_long physicalDevice, surface, pRectCount, pRects;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(physicalDevice)
		Z_PARAM_LONG(surface)
		Z_PARAM_LONG(pRectCount)
		Z_PARAM_LONG(pRects)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &physicalDevice_param, &surface_param, &pRectCount_param, &pRects_param);
	ZVAL_LONG(&_0, physicalDevice);
	ZVAL_LONG(&_1, surface);
	ZVAL_LONG(&_2, pRectCount);
	ZVAL_LONG(&_3, pRects);
	RETURN_LONG(phpvk_khrswapchain_vkgetphysicaldevicepresentrectangleskhr(&_0, &_1, &_2, &_3));
}

PHP_METHOD(Vulkan_Ext_KHRSwapchain_KHRSwapchain, vkAcquireNextImage2KHR)
{
	zval *device_param = NULL, *pAcquireInfo_param = NULL, *pImageIndex_param = NULL, _0, _1, _2;
	zend_long device, pAcquireInfo, pImageIndex;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(pAcquireInfo)
		Z_PARAM_LONG(pImageIndex)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &device_param, &pAcquireInfo_param, &pImageIndex_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, pAcquireInfo);
	ZVAL_LONG(&_2, pImageIndex);
	RETURN_LONG(phpvk_khrswapchain_vkacquirenextimage2khr(&_0, &_1, &_2));
}

