
extern zend_class_entry *vulkan_struct_vkmemorytype_vkmemorytype_ce;

ZEPHIR_INIT_CLASS(Vulkan_Struct_VkMemoryType_VkMemoryType);

PHP_METHOD(Vulkan_Struct_VkMemoryType_VkMemoryType, pack);
PHP_METHOD(Vulkan_Struct_VkMemoryType_VkMemoryType, packInto);
PHP_METHOD(Vulkan_Struct_VkMemoryType_VkMemoryType, unpack);
PHP_METHOD(Vulkan_Struct_VkMemoryType_VkMemoryType, size);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_struct_vkmemorytype_vkmemorytype_pack, 0, 1, IS_LONG, 0)
	ZEND_ARG_ARRAY_INFO(0, members, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_struct_vkmemorytype_vkmemorytype_packinto, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, ptr, IS_LONG, 0)
	ZEND_ARG_ARRAY_INFO(0, members, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_struct_vkmemorytype_vkmemorytype_unpack, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, ptr, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_struct_vkmemorytype_vkmemorytype_size, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vulkan_struct_vkmemorytype_vkmemorytype_method_entry) {
	PHP_ME(Vulkan_Struct_VkMemoryType_VkMemoryType, pack, arginfo_vulkan_struct_vkmemorytype_vkmemorytype_pack, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Struct_VkMemoryType_VkMemoryType, packInto, arginfo_vulkan_struct_vkmemorytype_vkmemorytype_packinto, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Struct_VkMemoryType_VkMemoryType, unpack, arginfo_vulkan_struct_vkmemorytype_vkmemorytype_unpack, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Struct_VkMemoryType_VkMemoryType, size, arginfo_vulkan_struct_vkmemorytype_vkmemorytype_size, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
