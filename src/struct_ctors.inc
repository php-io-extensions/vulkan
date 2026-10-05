ZEND_METHOD(VkPhysicalDeviceProperties, __construct)
{
	ZEND_PARSE_PARAMETERS_NONE();
	vulkan_init_nested(Z_OBJ_P(ZEND_THIS), "limits", vulkan_ce_VkPhysicalDeviceLimits);
	vulkan_init_nested(Z_OBJ_P(ZEND_THIS), "sparseProperties", vulkan_ce_VkPhysicalDeviceSparseProperties);
}

ZEND_METHOD(VkQueueFamilyProperties, __construct)
{
	ZEND_PARSE_PARAMETERS_NONE();
	vulkan_init_nested(Z_OBJ_P(ZEND_THIS), "minImageTransferGranularity", vulkan_ce_VkExtent3D);
}

