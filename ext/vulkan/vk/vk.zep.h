
extern zend_class_entry *vulkan_vk_vk_ce;

ZEPHIR_INIT_CLASS(Vulkan_Vk_Vk);

PHP_METHOD(Vulkan_Vk_Vk, lastError);
PHP_METHOD(Vulkan_Vk_Vk, createInstance);
PHP_METHOD(Vulkan_Vk_Vk, destroyInstance);
PHP_METHOD(Vulkan_Vk_Vk, enumeratePhysicalDevices);
PHP_METHOD(Vulkan_Vk_Vk, findGraphicsPresentQueue);
PHP_METHOD(Vulkan_Vk_Vk, createDevice);
PHP_METHOD(Vulkan_Vk_Vk, destroyDevice);
PHP_METHOD(Vulkan_Vk_Vk, getDeviceQueue);
PHP_METHOD(Vulkan_Vk_Vk, wrapSurface);
PHP_METHOD(Vulkan_Vk_Vk, destroySurface);
PHP_METHOD(Vulkan_Vk_Vk, createSwapchain);
PHP_METHOD(Vulkan_Vk_Vk, destroySwapchain);
PHP_METHOD(Vulkan_Vk_Vk, resizeSwapchain);
PHP_METHOD(Vulkan_Vk_Vk, presentFrame);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk_lasterror, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_vulkan_vk_vk_createinstance, 0, 0, Vulkan\\Vk\\VkInstance, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, extensions, IS_ARRAY, 0, "[]")
	ZEND_ARG_TYPE_INFO(0, appName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk_destroyinstance, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, instance, Vulkan\\Vk\\VkInstance, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk_enumeratephysicaldevices, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_OBJ_INFO(0, instance, Vulkan\\Vk\\VkInstance, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk_findgraphicspresentqueue, 0, 2, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, physical, Vulkan\\Vk\\VkPhysicalDevice, 0)
	ZEND_ARG_OBJ_INFO(0, surface, Vulkan\\Vk\\VkSurface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_vulkan_vk_vk_createdevice, 0, 2, Vulkan\\Vk\\VkDevice, 0)
	ZEND_ARG_OBJ_INFO(0, physical, Vulkan\\Vk\\VkPhysicalDevice, 0)
	ZEND_ARG_TYPE_INFO(0, queueFamily, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk_destroydevice, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, device, Vulkan\\Vk\\VkDevice, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_vulkan_vk_vk_getdevicequeue, 0, 2, Vulkan\\Vk\\VkQueue, 0)
	ZEND_ARG_OBJ_INFO(0, device, Vulkan\\Vk\\VkDevice, 0)
	ZEND_ARG_TYPE_INFO(0, queueFamily, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_vulkan_vk_vk_wrapsurface, 0, 1, Vulkan\\Vk\\VkSurface, 0)
	ZEND_ARG_TYPE_INFO(0, surfaceFd, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk_destroysurface, 0, 2, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, instance, Vulkan\\Vk\\VkInstance, 0)
	ZEND_ARG_OBJ_INFO(0, surface, Vulkan\\Vk\\VkSurface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_vulkan_vk_vk_createswapchain, 0, 7, Vulkan\\Vk\\VkSwapchain, 0)
	ZEND_ARG_OBJ_INFO(0, instance, Vulkan\\Vk\\VkInstance, 0)
	ZEND_ARG_OBJ_INFO(0, physical, Vulkan\\Vk\\VkPhysicalDevice, 0)
	ZEND_ARG_OBJ_INFO(0, device, Vulkan\\Vk\\VkDevice, 0)
	ZEND_ARG_OBJ_INFO(0, queue, Vulkan\\Vk\\VkQueue, 0)
	ZEND_ARG_OBJ_INFO(0, surface, Vulkan\\Vk\\VkSurface, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk_destroyswapchain, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, swapchain, Vulkan\\Vk\\VkSwapchain, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk_resizeswapchain, 0, 3, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, swapchain, Vulkan\\Vk\\VkSwapchain, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk_presentframe, 0, 4, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, swapchain, Vulkan\\Vk\\VkSwapchain, 0)
	ZEND_ARG_TYPE_INFO(0, clearR, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, clearG, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, clearB, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, clearA, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, drawMenu, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, menuX, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, menuY, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, menuW, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, menuH, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, menuR, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, menuG, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, menuB, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, menuA, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, drawInner, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, innerX, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, innerY, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, innerW, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, innerH, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, innerR, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, innerG, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, innerB, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, innerA, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, drawAccent, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, accentX, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, accentY, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, accentW, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, accentH, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, accentR, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, accentG, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, accentB, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, accentA, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vulkan_vk_vk_method_entry) {
	PHP_ME(Vulkan_Vk_Vk, lastError, arginfo_vulkan_vk_vk_lasterror, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Vk_Vk, createInstance, arginfo_vulkan_vk_vk_createinstance, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Vk_Vk, destroyInstance, arginfo_vulkan_vk_vk_destroyinstance, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Vk_Vk, enumeratePhysicalDevices, arginfo_vulkan_vk_vk_enumeratephysicaldevices, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Vk_Vk, findGraphicsPresentQueue, arginfo_vulkan_vk_vk_findgraphicspresentqueue, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Vk_Vk, createDevice, arginfo_vulkan_vk_vk_createdevice, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Vk_Vk, destroyDevice, arginfo_vulkan_vk_vk_destroydevice, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Vk_Vk, getDeviceQueue, arginfo_vulkan_vk_vk_getdevicequeue, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Vk_Vk, wrapSurface, arginfo_vulkan_vk_vk_wrapsurface, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Vk_Vk, destroySurface, arginfo_vulkan_vk_vk_destroysurface, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Vk_Vk, createSwapchain, arginfo_vulkan_vk_vk_createswapchain, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Vk_Vk, destroySwapchain, arginfo_vulkan_vk_vk_destroyswapchain, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Vk_Vk, resizeSwapchain, arginfo_vulkan_vk_vk_resizeswapchain, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Vk_Vk, presentFrame, arginfo_vulkan_vk_vk_presentframe, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
