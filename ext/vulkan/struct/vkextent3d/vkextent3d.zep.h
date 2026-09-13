
extern zend_class_entry *vulkan_struct_vkextent3d_vkextent3d_ce;

ZEPHIR_INIT_CLASS(Vulkan_Struct_VkExtent3D_VkExtent3D);

PHP_METHOD(Vulkan_Struct_VkExtent3D_VkExtent3D, pack);
PHP_METHOD(Vulkan_Struct_VkExtent3D_VkExtent3D, packInto);
PHP_METHOD(Vulkan_Struct_VkExtent3D_VkExtent3D, unpack);
PHP_METHOD(Vulkan_Struct_VkExtent3D_VkExtent3D, size);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_struct_vkextent3d_vkextent3d_pack, 0, 1, IS_LONG, 0)
	ZEND_ARG_ARRAY_INFO(0, members, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_struct_vkextent3d_vkextent3d_packinto, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, ptr, IS_LONG, 0)
	ZEND_ARG_ARRAY_INFO(0, members, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_struct_vkextent3d_vkextent3d_unpack, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, ptr, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_struct_vkextent3d_vkextent3d_size, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vulkan_struct_vkextent3d_vkextent3d_method_entry) {
	PHP_ME(Vulkan_Struct_VkExtent3D_VkExtent3D, pack, arginfo_vulkan_struct_vkextent3d_vkextent3d_pack, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Struct_VkExtent3D_VkExtent3D, packInto, arginfo_vulkan_struct_vkextent3d_vkextent3d_packinto, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Struct_VkExtent3D_VkExtent3D, unpack, arginfo_vulkan_struct_vkextent3d_vkextent3d_unpack, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Struct_VkExtent3D_VkExtent3D, size, arginfo_vulkan_struct_vkextent3d_vkextent3d_size, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
