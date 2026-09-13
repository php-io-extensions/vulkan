
extern zend_class_entry *vulkan_ext_extmetalsurface_extmetalsurface_ce;

ZEPHIR_INIT_CLASS(Vulkan_Ext_EXTMetalSurface_EXTMetalSurface);

PHP_METHOD(Vulkan_Ext_EXTMetalSurface_EXTMetalSurface, vkCreateMetalSurfaceEXT);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_ext_extmetalsurface_extmetalsurface_vkcreatemetalsurfaceext, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, instance, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pCreateInfo, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pSurface, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vulkan_ext_extmetalsurface_extmetalsurface_method_entry) {
	PHP_ME(Vulkan_Ext_EXTMetalSurface_EXTMetalSurface, vkCreateMetalSurfaceEXT, arginfo_vulkan_ext_extmetalsurface_extmetalsurface_vkcreatemetalsurfaceext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
