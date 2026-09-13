
extern zend_class_entry *vulkan_struct_vkrenderinginfo_vkrenderinginfo_ce;

ZEPHIR_INIT_CLASS(Vulkan_Struct_VkRenderingInfo_VkRenderingInfo);

PHP_METHOD(Vulkan_Struct_VkRenderingInfo_VkRenderingInfo, pack);
PHP_METHOD(Vulkan_Struct_VkRenderingInfo_VkRenderingInfo, packInto);
PHP_METHOD(Vulkan_Struct_VkRenderingInfo_VkRenderingInfo, unpack);
PHP_METHOD(Vulkan_Struct_VkRenderingInfo_VkRenderingInfo, size);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_struct_vkrenderinginfo_vkrenderinginfo_pack, 0, 1, IS_LONG, 0)
	ZEND_ARG_ARRAY_INFO(0, members, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_struct_vkrenderinginfo_vkrenderinginfo_packinto, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, ptr, IS_LONG, 0)
	ZEND_ARG_ARRAY_INFO(0, members, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_struct_vkrenderinginfo_vkrenderinginfo_unpack, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, ptr, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_struct_vkrenderinginfo_vkrenderinginfo_size, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vulkan_struct_vkrenderinginfo_vkrenderinginfo_method_entry) {
	PHP_ME(Vulkan_Struct_VkRenderingInfo_VkRenderingInfo, pack, arginfo_vulkan_struct_vkrenderinginfo_vkrenderinginfo_pack, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Struct_VkRenderingInfo_VkRenderingInfo, packInto, arginfo_vulkan_struct_vkrenderinginfo_vkrenderinginfo_packinto, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Struct_VkRenderingInfo_VkRenderingInfo, unpack, arginfo_vulkan_struct_vkrenderinginfo_vkrenderinginfo_unpack, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Struct_VkRenderingInfo_VkRenderingInfo, size, arginfo_vulkan_struct_vkrenderinginfo_vkrenderinginfo_size, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
