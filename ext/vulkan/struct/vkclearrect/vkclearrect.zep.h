
extern zend_class_entry *vulkan_struct_vkclearrect_vkclearrect_ce;

ZEPHIR_INIT_CLASS(Vulkan_Struct_VkClearRect_VkClearRect);

PHP_METHOD(Vulkan_Struct_VkClearRect_VkClearRect, pack);
PHP_METHOD(Vulkan_Struct_VkClearRect_VkClearRect, packInto);
PHP_METHOD(Vulkan_Struct_VkClearRect_VkClearRect, unpack);
PHP_METHOD(Vulkan_Struct_VkClearRect_VkClearRect, size);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_struct_vkclearrect_vkclearrect_pack, 0, 1, IS_LONG, 0)
	ZEND_ARG_ARRAY_INFO(0, members, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_struct_vkclearrect_vkclearrect_packinto, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, ptr, IS_LONG, 0)
	ZEND_ARG_ARRAY_INFO(0, members, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_struct_vkclearrect_vkclearrect_unpack, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, ptr, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_struct_vkclearrect_vkclearrect_size, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vulkan_struct_vkclearrect_vkclearrect_method_entry) {
	PHP_ME(Vulkan_Struct_VkClearRect_VkClearRect, pack, arginfo_vulkan_struct_vkclearrect_vkclearrect_pack, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Struct_VkClearRect_VkClearRect, packInto, arginfo_vulkan_struct_vkclearrect_vkclearrect_packinto, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Struct_VkClearRect_VkClearRect, unpack, arginfo_vulkan_struct_vkclearrect_vkclearrect_unpack, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Struct_VkClearRect_VkClearRect, size, arginfo_vulkan_struct_vkclearrect_vkclearrect_size, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
