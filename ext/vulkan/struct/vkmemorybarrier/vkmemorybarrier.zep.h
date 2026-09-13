
extern zend_class_entry *vulkan_struct_vkmemorybarrier_vkmemorybarrier_ce;

ZEPHIR_INIT_CLASS(Vulkan_Struct_VkMemoryBarrier_VkMemoryBarrier);

PHP_METHOD(Vulkan_Struct_VkMemoryBarrier_VkMemoryBarrier, pack);
PHP_METHOD(Vulkan_Struct_VkMemoryBarrier_VkMemoryBarrier, packInto);
PHP_METHOD(Vulkan_Struct_VkMemoryBarrier_VkMemoryBarrier, unpack);
PHP_METHOD(Vulkan_Struct_VkMemoryBarrier_VkMemoryBarrier, size);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_struct_vkmemorybarrier_vkmemorybarrier_pack, 0, 1, IS_LONG, 0)
	ZEND_ARG_ARRAY_INFO(0, members, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_struct_vkmemorybarrier_vkmemorybarrier_packinto, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, ptr, IS_LONG, 0)
	ZEND_ARG_ARRAY_INFO(0, members, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_struct_vkmemorybarrier_vkmemorybarrier_unpack, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, ptr, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_struct_vkmemorybarrier_vkmemorybarrier_size, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vulkan_struct_vkmemorybarrier_vkmemorybarrier_method_entry) {
	PHP_ME(Vulkan_Struct_VkMemoryBarrier_VkMemoryBarrier, pack, arginfo_vulkan_struct_vkmemorybarrier_vkmemorybarrier_pack, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Struct_VkMemoryBarrier_VkMemoryBarrier, packInto, arginfo_vulkan_struct_vkmemorybarrier_vkmemorybarrier_packinto, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Struct_VkMemoryBarrier_VkMemoryBarrier, unpack, arginfo_vulkan_struct_vkmemorybarrier_vkmemorybarrier_unpack, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Struct_VkMemoryBarrier_VkMemoryBarrier, size, arginfo_vulkan_struct_vkmemorybarrier_vkmemorybarrier_size, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
