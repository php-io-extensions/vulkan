
extern zend_class_entry *vulkan_struct_vkimageresolve_vkimageresolve_ce;

ZEPHIR_INIT_CLASS(Vulkan_Struct_VkImageResolve_VkImageResolve);

PHP_METHOD(Vulkan_Struct_VkImageResolve_VkImageResolve, pack);
PHP_METHOD(Vulkan_Struct_VkImageResolve_VkImageResolve, packInto);
PHP_METHOD(Vulkan_Struct_VkImageResolve_VkImageResolve, unpack);
PHP_METHOD(Vulkan_Struct_VkImageResolve_VkImageResolve, size);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_struct_vkimageresolve_vkimageresolve_pack, 0, 1, IS_LONG, 0)
	ZEND_ARG_ARRAY_INFO(0, members, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_struct_vkimageresolve_vkimageresolve_packinto, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, ptr, IS_LONG, 0)
	ZEND_ARG_ARRAY_INFO(0, members, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_struct_vkimageresolve_vkimageresolve_unpack, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, ptr, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_struct_vkimageresolve_vkimageresolve_size, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vulkan_struct_vkimageresolve_vkimageresolve_method_entry) {
	PHP_ME(Vulkan_Struct_VkImageResolve_VkImageResolve, pack, arginfo_vulkan_struct_vkimageresolve_vkimageresolve_pack, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Struct_VkImageResolve_VkImageResolve, packInto, arginfo_vulkan_struct_vkimageresolve_vkimageresolve_packinto, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Struct_VkImageResolve_VkImageResolve, unpack, arginfo_vulkan_struct_vkimageresolve_vkimageresolve_unpack, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Struct_VkImageResolve_VkImageResolve, size, arginfo_vulkan_struct_vkimageresolve_vkimageresolve_size, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
