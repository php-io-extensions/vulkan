/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: e6f7519fb75b4aefe26c41c07bdb1b446a12f048 */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkGetPhysicalDeviceSurfaceSupportKHR, 0, 4, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, physicalDevice, VkPhysicalDevice, 0)
	ZEND_ARG_TYPE_INFO(0, queueFamilyIndex, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, surface, VkSurfaceKHR, 0)
	ZEND_ARG_TYPE_INFO(1, pSupported, _IS_BOOL, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkGetPhysicalDeviceSurfaceCapabilitiesKHR, 0, 3, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, physicalDevice, VkPhysicalDevice, 0)
	ZEND_ARG_OBJ_INFO(0, surface, VkSurfaceKHR, 0)
	ZEND_ARG_OBJ_INFO(1, pSurfaceCapabilities, VkSurfaceCapabilitiesKHR, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkGetPhysicalDeviceSurfaceFormatsKHR, 0, 3, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, physicalDevice, VkPhysicalDevice, 0)
	ZEND_ARG_OBJ_INFO(0, surface, VkSurfaceKHR, 0)
	ZEND_ARG_TYPE_INFO(1, pSurfaceFormats, IS_ARRAY, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkGetPhysicalDeviceSurfacePresentModesKHR, 0, 3, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, physicalDevice, VkPhysicalDevice, 0)
	ZEND_ARG_OBJ_INFO(0, surface, VkSurfaceKHR, 0)
	ZEND_ARG_TYPE_INFO(1, pPresentModes, IS_ARRAY, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkCreateSwapchainKHR, 0, 4, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, device, VkDevice, 0)
	ZEND_ARG_OBJ_INFO(0, pCreateInfo, VkSwapchainCreateInfoKHR, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_NULL, 1)
	ZEND_ARG_OBJ_INFO(1, pSwapchain, VkSwapchainKHR, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkDestroySwapchainKHR, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, device, VkDevice, 0)
	ZEND_ARG_OBJ_INFO(0, swapchain, VkSwapchainKHR, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_NULL, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkGetSwapchainImagesKHR, 0, 3, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, device, VkDevice, 0)
	ZEND_ARG_OBJ_INFO(0, swapchain, VkSwapchainKHR, 0)
	ZEND_ARG_TYPE_INFO(1, pSwapchainImages, IS_ARRAY, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkAcquireNextImageKHR, 0, 6, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, device, VkDevice, 0)
	ZEND_ARG_OBJ_INFO(0, swapchain, VkSwapchainKHR, 0)
	ZEND_ARG_TYPE_INFO(0, timeout, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, semaphore, VkSemaphore, 1)
	ZEND_ARG_OBJ_INFO(0, fence, VkFence, 1)
	ZEND_ARG_TYPE_INFO(1, pImageIndex, IS_LONG, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkQueuePresentKHR, 0, 2, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, queue, VkQueue, 0)
	ZEND_ARG_OBJ_INFO(0, pPresentInfo, VkPresentInfoKHR, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkDestroySurfaceKHR, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, instance, VkInstance, 0)
	ZEND_ARG_OBJ_INFO(0, surface, VkSurfaceKHR, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_NULL, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_VkSurfaceKHR___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_VkSurfaceKHR_pointer, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_VkSurfaceKHR_fromPointer, 0, 1, IS_STATIC, 0)
	ZEND_ARG_TYPE_INFO(0, pointer, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_VkSwapchainKHR___construct arginfo_class_VkSurfaceKHR___construct

#define arginfo_class_VkSwapchainKHR_pointer arginfo_class_VkSurfaceKHR_pointer

#define arginfo_class_VkSwapchainKHR_fromPointer arginfo_class_VkSurfaceKHR_fromPointer

#define arginfo_class_VkSurfaceCapabilitiesKHR___construct arginfo_class_VkSurfaceKHR___construct

#define arginfo_class_VkSwapchainCreateInfoKHR___construct arginfo_class_VkSurfaceKHR___construct

ZEND_FUNCTION(vkGetPhysicalDeviceSurfaceSupportKHR);
ZEND_FUNCTION(vkGetPhysicalDeviceSurfaceCapabilitiesKHR);
ZEND_FUNCTION(vkGetPhysicalDeviceSurfaceFormatsKHR);
ZEND_FUNCTION(vkGetPhysicalDeviceSurfacePresentModesKHR);
ZEND_FUNCTION(vkCreateSwapchainKHR);
ZEND_FUNCTION(vkDestroySwapchainKHR);
ZEND_FUNCTION(vkGetSwapchainImagesKHR);
ZEND_FUNCTION(vkAcquireNextImageKHR);
ZEND_FUNCTION(vkQueuePresentKHR);
ZEND_FUNCTION(vkDestroySurfaceKHR);
ZEND_METHOD(VkSurfaceKHR, __construct);
ZEND_METHOD(VkSurfaceKHR, pointer);
ZEND_METHOD(VkSurfaceKHR, fromPointer);
ZEND_METHOD(VkSwapchainKHR, __construct);
ZEND_METHOD(VkSwapchainKHR, pointer);
ZEND_METHOD(VkSwapchainKHR, fromPointer);
ZEND_METHOD(VkSurfaceCapabilitiesKHR, __construct);
ZEND_METHOD(VkSwapchainCreateInfoKHR, __construct);

static const zend_function_entry ext_functions[] = {
	ZEND_FE(vkGetPhysicalDeviceSurfaceSupportKHR, arginfo_vkGetPhysicalDeviceSurfaceSupportKHR)
	ZEND_FE(vkGetPhysicalDeviceSurfaceCapabilitiesKHR, arginfo_vkGetPhysicalDeviceSurfaceCapabilitiesKHR)
	ZEND_FE(vkGetPhysicalDeviceSurfaceFormatsKHR, arginfo_vkGetPhysicalDeviceSurfaceFormatsKHR)
	ZEND_FE(vkGetPhysicalDeviceSurfacePresentModesKHR, arginfo_vkGetPhysicalDeviceSurfacePresentModesKHR)
	ZEND_FE(vkCreateSwapchainKHR, arginfo_vkCreateSwapchainKHR)
	ZEND_FE(vkDestroySwapchainKHR, arginfo_vkDestroySwapchainKHR)
	ZEND_FE(vkGetSwapchainImagesKHR, arginfo_vkGetSwapchainImagesKHR)
	ZEND_FE(vkAcquireNextImageKHR, arginfo_vkAcquireNextImageKHR)
	ZEND_FE(vkQueuePresentKHR, arginfo_vkQueuePresentKHR)
	ZEND_FE(vkDestroySurfaceKHR, arginfo_vkDestroySurfaceKHR)
	ZEND_FE_END
};

static const zend_function_entry class_VkSurfaceKHR_methods[] = {
	ZEND_ME(VkSurfaceKHR, __construct, arginfo_class_VkSurfaceKHR___construct, ZEND_ACC_PRIVATE)
	ZEND_ME(VkSurfaceKHR, pointer, arginfo_class_VkSurfaceKHR_pointer, ZEND_ACC_PUBLIC)
	ZEND_ME(VkSurfaceKHR, fromPointer, arginfo_class_VkSurfaceKHR_fromPointer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static const zend_function_entry class_VkSwapchainKHR_methods[] = {
	ZEND_ME(VkSwapchainKHR, __construct, arginfo_class_VkSwapchainKHR___construct, ZEND_ACC_PRIVATE)
	ZEND_ME(VkSwapchainKHR, pointer, arginfo_class_VkSwapchainKHR_pointer, ZEND_ACC_PUBLIC)
	ZEND_ME(VkSwapchainKHR, fromPointer, arginfo_class_VkSwapchainKHR_fromPointer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static const zend_function_entry class_VkSurfaceCapabilitiesKHR_methods[] = {
	ZEND_ME(VkSurfaceCapabilitiesKHR, __construct, arginfo_class_VkSurfaceCapabilitiesKHR___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_VkSwapchainCreateInfoKHR_methods[] = {
	ZEND_ME(VkSwapchainCreateInfoKHR, __construct, arginfo_class_VkSwapchainCreateInfoKHR___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_VkSurfaceKHR(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkSurfaceKHR", class_VkSurfaceKHR_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_VkSwapchainKHR(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkSwapchainKHR", class_VkSwapchainKHR_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_VkSurfaceFormatKHR(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkSurfaceFormatKHR", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_format_default_value;
	ZVAL_LONG(&property_format_default_value, 0);
	zend_string *property_format_name = zend_string_init("format", sizeof("format") - 1, 1);
	zend_declare_typed_property(class_entry, property_format_name, &property_format_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_format_name);

	zval property_colorSpace_default_value;
	ZVAL_LONG(&property_colorSpace_default_value, 0);
	zend_string *property_colorSpace_name = zend_string_init("colorSpace", sizeof("colorSpace") - 1, 1);
	zend_declare_typed_property(class_entry, property_colorSpace_name, &property_colorSpace_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_colorSpace_name);

	return class_entry;
}

static zend_class_entry *register_class_VkSurfaceCapabilitiesKHR(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkSurfaceCapabilitiesKHR", class_VkSurfaceCapabilitiesKHR_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_minImageCount_default_value;
	ZVAL_LONG(&property_minImageCount_default_value, 0);
	zend_string *property_minImageCount_name = zend_string_init("minImageCount", sizeof("minImageCount") - 1, 1);
	zend_declare_typed_property(class_entry, property_minImageCount_name, &property_minImageCount_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_minImageCount_name);

	zval property_maxImageCount_default_value;
	ZVAL_LONG(&property_maxImageCount_default_value, 0);
	zend_string *property_maxImageCount_name = zend_string_init("maxImageCount", sizeof("maxImageCount") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxImageCount_name, &property_maxImageCount_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxImageCount_name);

	zval property_currentExtent_default_value;
	ZVAL_UNDEF(&property_currentExtent_default_value);
	zend_string *property_currentExtent_name = zend_string_init("currentExtent", sizeof("currentExtent") - 1, 1);
	zend_string *property_currentExtent_class_VkExtent2D = zend_string_init("VkExtent2D", sizeof("VkExtent2D")-1, 1);
	zend_declare_typed_property(class_entry, property_currentExtent_name, &property_currentExtent_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_currentExtent_class_VkExtent2D, 0, 0));
	zend_string_release(property_currentExtent_name);

	zval property_minImageExtent_default_value;
	ZVAL_UNDEF(&property_minImageExtent_default_value);
	zend_string *property_minImageExtent_name = zend_string_init("minImageExtent", sizeof("minImageExtent") - 1, 1);
	zend_string *property_minImageExtent_class_VkExtent2D = zend_string_init("VkExtent2D", sizeof("VkExtent2D")-1, 1);
	zend_declare_typed_property(class_entry, property_minImageExtent_name, &property_minImageExtent_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_minImageExtent_class_VkExtent2D, 0, 0));
	zend_string_release(property_minImageExtent_name);

	zval property_maxImageExtent_default_value;
	ZVAL_UNDEF(&property_maxImageExtent_default_value);
	zend_string *property_maxImageExtent_name = zend_string_init("maxImageExtent", sizeof("maxImageExtent") - 1, 1);
	zend_string *property_maxImageExtent_class_VkExtent2D = zend_string_init("VkExtent2D", sizeof("VkExtent2D")-1, 1);
	zend_declare_typed_property(class_entry, property_maxImageExtent_name, &property_maxImageExtent_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_maxImageExtent_class_VkExtent2D, 0, 0));
	zend_string_release(property_maxImageExtent_name);

	zval property_maxImageArrayLayers_default_value;
	ZVAL_LONG(&property_maxImageArrayLayers_default_value, 0);
	zend_string *property_maxImageArrayLayers_name = zend_string_init("maxImageArrayLayers", sizeof("maxImageArrayLayers") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxImageArrayLayers_name, &property_maxImageArrayLayers_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxImageArrayLayers_name);

	zval property_supportedTransforms_default_value;
	ZVAL_LONG(&property_supportedTransforms_default_value, 0);
	zend_string *property_supportedTransforms_name = zend_string_init("supportedTransforms", sizeof("supportedTransforms") - 1, 1);
	zend_declare_typed_property(class_entry, property_supportedTransforms_name, &property_supportedTransforms_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_supportedTransforms_name);

	zval property_currentTransform_default_value;
	ZVAL_LONG(&property_currentTransform_default_value, 0);
	zend_string *property_currentTransform_name = zend_string_init("currentTransform", sizeof("currentTransform") - 1, 1);
	zend_declare_typed_property(class_entry, property_currentTransform_name, &property_currentTransform_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_currentTransform_name);

	zval property_supportedCompositeAlpha_default_value;
	ZVAL_LONG(&property_supportedCompositeAlpha_default_value, 0);
	zend_string *property_supportedCompositeAlpha_name = zend_string_init("supportedCompositeAlpha", sizeof("supportedCompositeAlpha") - 1, 1);
	zend_declare_typed_property(class_entry, property_supportedCompositeAlpha_name, &property_supportedCompositeAlpha_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_supportedCompositeAlpha_name);

	zval property_supportedUsageFlags_default_value;
	ZVAL_LONG(&property_supportedUsageFlags_default_value, 0);
	zend_string *property_supportedUsageFlags_name = zend_string_init("supportedUsageFlags", sizeof("supportedUsageFlags") - 1, 1);
	zend_declare_typed_property(class_entry, property_supportedUsageFlags_name, &property_supportedUsageFlags_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_supportedUsageFlags_name);

	return class_entry;
}

static zend_class_entry *register_class_VkSwapchainCreateInfoKHR(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkSwapchainCreateInfoKHR", class_VkSwapchainCreateInfoKHR_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_pNext_default_value;
	ZVAL_NULL(&property_pNext_default_value);
	zend_string *property_pNext_name = zend_string_init("pNext", sizeof("pNext") - 1, 1);
	zend_declare_typed_property(class_entry, property_pNext_name, &property_pNext_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_OBJECT|MAY_BE_NULL));
	zend_string_release(property_pNext_name);

	zval property_flags_default_value;
	ZVAL_LONG(&property_flags_default_value, 0);
	zend_string *property_flags_name = zend_string_init("flags", sizeof("flags") - 1, 1);
	zend_declare_typed_property(class_entry, property_flags_name, &property_flags_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_flags_name);

	zval property_surface_default_value;
	ZVAL_NULL(&property_surface_default_value);
	zend_string *property_surface_name = zend_string_init("surface", sizeof("surface") - 1, 1);
	zend_string *property_surface_class_VkSurfaceKHR = zend_string_init("VkSurfaceKHR", sizeof("VkSurfaceKHR")-1, 1);
	zend_declare_typed_property(class_entry, property_surface_name, &property_surface_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_surface_class_VkSurfaceKHR, 0, MAY_BE_NULL));
	zend_string_release(property_surface_name);

	zval property_minImageCount_default_value;
	ZVAL_LONG(&property_minImageCount_default_value, 0);
	zend_string *property_minImageCount_name = zend_string_init("minImageCount", sizeof("minImageCount") - 1, 1);
	zend_declare_typed_property(class_entry, property_minImageCount_name, &property_minImageCount_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_minImageCount_name);

	zval property_imageFormat_default_value;
	ZVAL_LONG(&property_imageFormat_default_value, 0);
	zend_string *property_imageFormat_name = zend_string_init("imageFormat", sizeof("imageFormat") - 1, 1);
	zend_declare_typed_property(class_entry, property_imageFormat_name, &property_imageFormat_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_imageFormat_name);

	zval property_imageColorSpace_default_value;
	ZVAL_LONG(&property_imageColorSpace_default_value, 0);
	zend_string *property_imageColorSpace_name = zend_string_init("imageColorSpace", sizeof("imageColorSpace") - 1, 1);
	zend_declare_typed_property(class_entry, property_imageColorSpace_name, &property_imageColorSpace_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_imageColorSpace_name);

	zval property_imageExtent_default_value;
	ZVAL_UNDEF(&property_imageExtent_default_value);
	zend_string *property_imageExtent_name = zend_string_init("imageExtent", sizeof("imageExtent") - 1, 1);
	zend_string *property_imageExtent_class_VkExtent2D = zend_string_init("VkExtent2D", sizeof("VkExtent2D")-1, 1);
	zend_declare_typed_property(class_entry, property_imageExtent_name, &property_imageExtent_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_imageExtent_class_VkExtent2D, 0, 0));
	zend_string_release(property_imageExtent_name);

	zval property_imageArrayLayers_default_value;
	ZVAL_LONG(&property_imageArrayLayers_default_value, 0);
	zend_string *property_imageArrayLayers_name = zend_string_init("imageArrayLayers", sizeof("imageArrayLayers") - 1, 1);
	zend_declare_typed_property(class_entry, property_imageArrayLayers_name, &property_imageArrayLayers_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_imageArrayLayers_name);

	zval property_imageUsage_default_value;
	ZVAL_LONG(&property_imageUsage_default_value, 0);
	zend_string *property_imageUsage_name = zend_string_init("imageUsage", sizeof("imageUsage") - 1, 1);
	zend_declare_typed_property(class_entry, property_imageUsage_name, &property_imageUsage_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_imageUsage_name);

	zval property_imageSharingMode_default_value;
	ZVAL_LONG(&property_imageSharingMode_default_value, 0);
	zend_string *property_imageSharingMode_name = zend_string_init("imageSharingMode", sizeof("imageSharingMode") - 1, 1);
	zend_declare_typed_property(class_entry, property_imageSharingMode_name, &property_imageSharingMode_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_imageSharingMode_name);

	zval property_pQueueFamilyIndices_default_value;
	ZVAL_EMPTY_ARRAY(&property_pQueueFamilyIndices_default_value);
	zend_string *property_pQueueFamilyIndices_name = zend_string_init("pQueueFamilyIndices", sizeof("pQueueFamilyIndices") - 1, 1);
	zend_declare_typed_property(class_entry, property_pQueueFamilyIndices_name, &property_pQueueFamilyIndices_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_pQueueFamilyIndices_name);

	zval property_preTransform_default_value;
	ZVAL_LONG(&property_preTransform_default_value, 0);
	zend_string *property_preTransform_name = zend_string_init("preTransform", sizeof("preTransform") - 1, 1);
	zend_declare_typed_property(class_entry, property_preTransform_name, &property_preTransform_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_preTransform_name);

	zval property_compositeAlpha_default_value;
	ZVAL_LONG(&property_compositeAlpha_default_value, 0);
	zend_string *property_compositeAlpha_name = zend_string_init("compositeAlpha", sizeof("compositeAlpha") - 1, 1);
	zend_declare_typed_property(class_entry, property_compositeAlpha_name, &property_compositeAlpha_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_compositeAlpha_name);

	zval property_presentMode_default_value;
	ZVAL_LONG(&property_presentMode_default_value, 0);
	zend_string *property_presentMode_name = zend_string_init("presentMode", sizeof("presentMode") - 1, 1);
	zend_declare_typed_property(class_entry, property_presentMode_name, &property_presentMode_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_presentMode_name);

	zval property_clipped_default_value;
	ZVAL_LONG(&property_clipped_default_value, 0);
	zend_string *property_clipped_name = zend_string_init("clipped", sizeof("clipped") - 1, 1);
	zend_declare_typed_property(class_entry, property_clipped_name, &property_clipped_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_clipped_name);

	zval property_oldSwapchain_default_value;
	ZVAL_NULL(&property_oldSwapchain_default_value);
	zend_string *property_oldSwapchain_name = zend_string_init("oldSwapchain", sizeof("oldSwapchain") - 1, 1);
	zend_string *property_oldSwapchain_class_VkSwapchainKHR = zend_string_init("VkSwapchainKHR", sizeof("VkSwapchainKHR")-1, 1);
	zend_declare_typed_property(class_entry, property_oldSwapchain_name, &property_oldSwapchain_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_oldSwapchain_class_VkSwapchainKHR, 0, MAY_BE_NULL));
	zend_string_release(property_oldSwapchain_name);

	return class_entry;
}

static zend_class_entry *register_class_VkPresentInfoKHR(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkPresentInfoKHR", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_pNext_default_value;
	ZVAL_NULL(&property_pNext_default_value);
	zend_string *property_pNext_name = zend_string_init("pNext", sizeof("pNext") - 1, 1);
	zend_declare_typed_property(class_entry, property_pNext_name, &property_pNext_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_OBJECT|MAY_BE_NULL));
	zend_string_release(property_pNext_name);

	zval property_pWaitSemaphores_default_value;
	ZVAL_EMPTY_ARRAY(&property_pWaitSemaphores_default_value);
	zend_string *property_pWaitSemaphores_name = zend_string_init("pWaitSemaphores", sizeof("pWaitSemaphores") - 1, 1);
	zend_declare_typed_property(class_entry, property_pWaitSemaphores_name, &property_pWaitSemaphores_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_pWaitSemaphores_name);

	zval property_pSwapchains_default_value;
	ZVAL_EMPTY_ARRAY(&property_pSwapchains_default_value);
	zend_string *property_pSwapchains_name = zend_string_init("pSwapchains", sizeof("pSwapchains") - 1, 1);
	zend_declare_typed_property(class_entry, property_pSwapchains_name, &property_pSwapchains_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_pSwapchains_name);

	zval property_pImageIndices_default_value;
	ZVAL_EMPTY_ARRAY(&property_pImageIndices_default_value);
	zend_string *property_pImageIndices_name = zend_string_init("pImageIndices", sizeof("pImageIndices") - 1, 1);
	zend_declare_typed_property(class_entry, property_pImageIndices_name, &property_pImageIndices_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_pImageIndices_name);

	return class_entry;
}
