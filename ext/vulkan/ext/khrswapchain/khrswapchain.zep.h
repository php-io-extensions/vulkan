
extern zend_class_entry *vulkan_ext_khrswapchain_khrswapchain_ce;

ZEPHIR_INIT_CLASS(Vulkan_Ext_KHRSwapchain_KHRSwapchain);

PHP_METHOD(Vulkan_Ext_KHRSwapchain_KHRSwapchain, vkCreateSwapchainKHR);
PHP_METHOD(Vulkan_Ext_KHRSwapchain_KHRSwapchain, vkDestroySwapchainKHR);
PHP_METHOD(Vulkan_Ext_KHRSwapchain_KHRSwapchain, vkGetSwapchainImagesKHR);
PHP_METHOD(Vulkan_Ext_KHRSwapchain_KHRSwapchain, vkAcquireNextImageKHR);
PHP_METHOD(Vulkan_Ext_KHRSwapchain_KHRSwapchain, vkQueuePresentKHR);
PHP_METHOD(Vulkan_Ext_KHRSwapchain_KHRSwapchain, vkGetDeviceGroupPresentCapabilitiesKHR);
PHP_METHOD(Vulkan_Ext_KHRSwapchain_KHRSwapchain, vkGetDeviceGroupSurfacePresentModesKHR);
PHP_METHOD(Vulkan_Ext_KHRSwapchain_KHRSwapchain, vkGetPhysicalDevicePresentRectanglesKHR);
PHP_METHOD(Vulkan_Ext_KHRSwapchain_KHRSwapchain, vkAcquireNextImage2KHR);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_ext_khrswapchain_khrswapchain_vkcreateswapchainkhr, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pCreateInfo, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pSwapchain, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_ext_khrswapchain_khrswapchain_vkdestroyswapchainkhr, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, swapchain, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_ext_khrswapchain_khrswapchain_vkgetswapchainimageskhr, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, swapchain, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pSwapchainImageCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pSwapchainImages, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_ext_khrswapchain_khrswapchain_vkacquirenextimagekhr, 0, 6, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, swapchain, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, timeout, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, semaphore, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, fence, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pImageIndex, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_ext_khrswapchain_khrswapchain_vkqueuepresentkhr, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, queue, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pPresentInfo, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_ext_khrswapchain_khrswapchain_vkgetdevicegrouppresentcapabilitieskhr, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pDeviceGroupPresentCapabilities, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_ext_khrswapchain_khrswapchain_vkgetdevicegroupsurfacepresentmodeskhr, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, surface, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pModes, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_ext_khrswapchain_khrswapchain_vkgetphysicaldevicepresentrectangleskhr, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, physicalDevice, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, surface, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pRectCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pRects, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_ext_khrswapchain_khrswapchain_vkacquirenextimage2khr, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAcquireInfo, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pImageIndex, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vulkan_ext_khrswapchain_khrswapchain_method_entry) {
	PHP_ME(Vulkan_Ext_KHRSwapchain_KHRSwapchain, vkCreateSwapchainKHR, arginfo_vulkan_ext_khrswapchain_khrswapchain_vkcreateswapchainkhr, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Ext_KHRSwapchain_KHRSwapchain, vkDestroySwapchainKHR, arginfo_vulkan_ext_khrswapchain_khrswapchain_vkdestroyswapchainkhr, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Ext_KHRSwapchain_KHRSwapchain, vkGetSwapchainImagesKHR, arginfo_vulkan_ext_khrswapchain_khrswapchain_vkgetswapchainimageskhr, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Ext_KHRSwapchain_KHRSwapchain, vkAcquireNextImageKHR, arginfo_vulkan_ext_khrswapchain_khrswapchain_vkacquirenextimagekhr, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Ext_KHRSwapchain_KHRSwapchain, vkQueuePresentKHR, arginfo_vulkan_ext_khrswapchain_khrswapchain_vkqueuepresentkhr, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Ext_KHRSwapchain_KHRSwapchain, vkGetDeviceGroupPresentCapabilitiesKHR, arginfo_vulkan_ext_khrswapchain_khrswapchain_vkgetdevicegrouppresentcapabilitieskhr, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Ext_KHRSwapchain_KHRSwapchain, vkGetDeviceGroupSurfacePresentModesKHR, arginfo_vulkan_ext_khrswapchain_khrswapchain_vkgetdevicegroupsurfacepresentmodeskhr, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Ext_KHRSwapchain_KHRSwapchain, vkGetPhysicalDevicePresentRectanglesKHR, arginfo_vulkan_ext_khrswapchain_khrswapchain_vkgetphysicaldevicepresentrectangleskhr, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Ext_KHRSwapchain_KHRSwapchain, vkAcquireNextImage2KHR, arginfo_vulkan_ext_khrswapchain_khrswapchain_vkacquirenextimage2khr, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
