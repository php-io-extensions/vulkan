
extern zend_class_entry *vulkan_ext_khrxlibsurface_khrxlibsurface_ce;

ZEPHIR_INIT_CLASS(Vulkan_Ext_KHRXlibSurface_KHRXlibSurface);

PHP_METHOD(Vulkan_Ext_KHRXlibSurface_KHRXlibSurface, vkCreateXlibSurfaceKHR);
PHP_METHOD(Vulkan_Ext_KHRXlibSurface_KHRXlibSurface, vkGetPhysicalDeviceXlibPresentationSupportKHR);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_ext_khrxlibsurface_khrxlibsurface_vkcreatexlibsurfacekhr, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, instance, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pCreateInfo, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pSurface, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_ext_khrxlibsurface_khrxlibsurface_vkgetphysicaldevicexlibpresentationsupportkhr, 0, 4, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, physicalDevice, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, queueFamilyIndex, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, dpy, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, visualID, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vulkan_ext_khrxlibsurface_khrxlibsurface_method_entry) {
	PHP_ME(Vulkan_Ext_KHRXlibSurface_KHRXlibSurface, vkCreateXlibSurfaceKHR, arginfo_vulkan_ext_khrxlibsurface_khrxlibsurface_vkcreatexlibsurfacekhr, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Ext_KHRXlibSurface_KHRXlibSurface, vkGetPhysicalDeviceXlibPresentationSupportKHR, arginfo_vulkan_ext_khrxlibsurface_khrxlibsurface_vkgetphysicaldevicexlibpresentationsupportkhr, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
