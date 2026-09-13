
extern zend_class_entry *vulkan_ext_khrwaylandsurface_khrwaylandsurface_ce;

ZEPHIR_INIT_CLASS(Vulkan_Ext_KHRWaylandSurface_KHRWaylandSurface);

PHP_METHOD(Vulkan_Ext_KHRWaylandSurface_KHRWaylandSurface, vkCreateWaylandSurfaceKHR);
PHP_METHOD(Vulkan_Ext_KHRWaylandSurface_KHRWaylandSurface, vkGetPhysicalDeviceWaylandPresentationSupportKHR);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_ext_khrwaylandsurface_khrwaylandsurface_vkcreatewaylandsurfacekhr, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, instance, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pCreateInfo, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pSurface, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_ext_khrwaylandsurface_khrwaylandsurface_vkgetphysicaldevicewaylandpresentationsupportkhr, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, physicalDevice, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, queueFamilyIndex, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, display, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vulkan_ext_khrwaylandsurface_khrwaylandsurface_method_entry) {
	PHP_ME(Vulkan_Ext_KHRWaylandSurface_KHRWaylandSurface, vkCreateWaylandSurfaceKHR, arginfo_vulkan_ext_khrwaylandsurface_khrwaylandsurface_vkcreatewaylandsurfacekhr, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Ext_KHRWaylandSurface_KHRWaylandSurface, vkGetPhysicalDeviceWaylandPresentationSupportKHR, arginfo_vulkan_ext_khrwaylandsurface_khrwaylandsurface_vkgetphysicaldevicewaylandpresentationsupportkhr, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
