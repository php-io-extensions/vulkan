
extern zend_class_entry *vulkan_ext_khrsurface_khrsurface_ce;

ZEPHIR_INIT_CLASS(Vulkan_Ext_KHRSurface_KHRSurface);

PHP_METHOD(Vulkan_Ext_KHRSurface_KHRSurface, vkDestroySurfaceKHR);
PHP_METHOD(Vulkan_Ext_KHRSurface_KHRSurface, vkGetPhysicalDeviceSurfaceSupportKHR);
PHP_METHOD(Vulkan_Ext_KHRSurface_KHRSurface, vkGetPhysicalDeviceSurfaceCapabilitiesKHR);
PHP_METHOD(Vulkan_Ext_KHRSurface_KHRSurface, vkGetPhysicalDeviceSurfaceFormatsKHR);
PHP_METHOD(Vulkan_Ext_KHRSurface_KHRSurface, vkGetPhysicalDeviceSurfacePresentModesKHR);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_ext_khrsurface_khrsurface_vkdestroysurfacekhr, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, instance, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, surface, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_ext_khrsurface_khrsurface_vkgetphysicaldevicesurfacesupportkhr, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, physicalDevice, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, queueFamilyIndex, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, surface, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pSupported, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_ext_khrsurface_khrsurface_vkgetphysicaldevicesurfacecapabilitieskhr, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, physicalDevice, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, surface, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pSurfaceCapabilities, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_ext_khrsurface_khrsurface_vkgetphysicaldevicesurfaceformatskhr, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, physicalDevice, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, surface, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pSurfaceFormatCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pSurfaceFormats, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_ext_khrsurface_khrsurface_vkgetphysicaldevicesurfacepresentmodeskhr, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, physicalDevice, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, surface, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pPresentModeCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pPresentModes, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vulkan_ext_khrsurface_khrsurface_method_entry) {
	PHP_ME(Vulkan_Ext_KHRSurface_KHRSurface, vkDestroySurfaceKHR, arginfo_vulkan_ext_khrsurface_khrsurface_vkdestroysurfacekhr, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Ext_KHRSurface_KHRSurface, vkGetPhysicalDeviceSurfaceSupportKHR, arginfo_vulkan_ext_khrsurface_khrsurface_vkgetphysicaldevicesurfacesupportkhr, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Ext_KHRSurface_KHRSurface, vkGetPhysicalDeviceSurfaceCapabilitiesKHR, arginfo_vulkan_ext_khrsurface_khrsurface_vkgetphysicaldevicesurfacecapabilitieskhr, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Ext_KHRSurface_KHRSurface, vkGetPhysicalDeviceSurfaceFormatsKHR, arginfo_vulkan_ext_khrsurface_khrsurface_vkgetphysicaldevicesurfaceformatskhr, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Ext_KHRSurface_KHRSurface, vkGetPhysicalDeviceSurfacePresentModesKHR, arginfo_vulkan_ext_khrsurface_khrsurface_vkgetphysicaldevicesurfacepresentmodeskhr, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
