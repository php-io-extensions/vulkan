/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 2d6e0527b8c45b8c261a884483310c1c4792b346 */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkGetMemoryFdKHR, 0, 3, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, device, VkDevice, 0)
	ZEND_ARG_OBJ_INFO(0, pGetFdInfo, VkMemoryGetFdInfoKHR, 0)
	ZEND_ARG_TYPE_INFO(1, pFd, IS_LONG, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkGetImageDrmFormatModifierPropertiesEXT, 0, 3, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, device, VkDevice, 0)
	ZEND_ARG_OBJ_INFO(0, image, VkImage, 0)
	ZEND_ARG_OBJ_INFO(1, pProperties, VkImageDrmFormatModifierPropertiesEXT, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkGetImageSubresourceLayout, 0, 4, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, device, VkDevice, 0)
	ZEND_ARG_OBJ_INFO(0, image, VkImage, 0)
	ZEND_ARG_OBJ_INFO(0, pSubresource, VkImageSubresource, 0)
	ZEND_ARG_OBJ_INFO(1, pLayout, VkSubresourceLayout, 1)
ZEND_END_ARG_INFO()

ZEND_FUNCTION(vkGetMemoryFdKHR);
ZEND_FUNCTION(vkGetImageDrmFormatModifierPropertiesEXT);
ZEND_FUNCTION(vkGetImageSubresourceLayout);

static const zend_function_entry ext_functions[] = {
	ZEND_FE(vkGetMemoryFdKHR, arginfo_vkGetMemoryFdKHR)
	ZEND_FE(vkGetImageDrmFormatModifierPropertiesEXT, arginfo_vkGetImageDrmFormatModifierPropertiesEXT)
	ZEND_FE(vkGetImageSubresourceLayout, arginfo_vkGetImageSubresourceLayout)
	ZEND_FE_END
};

static zend_class_entry *register_class_VkExternalMemoryImageCreateInfo(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkExternalMemoryImageCreateInfo", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_pNext_default_value;
	ZVAL_NULL(&property_pNext_default_value);
	zend_string *property_pNext_name = zend_string_init("pNext", sizeof("pNext") - 1, 1);
	zend_declare_typed_property(class_entry, property_pNext_name, &property_pNext_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_OBJECT|MAY_BE_NULL));
	zend_string_release(property_pNext_name);

	zval property_handleTypes_default_value;
	ZVAL_LONG(&property_handleTypes_default_value, 0);
	zend_string *property_handleTypes_name = zend_string_init("handleTypes", sizeof("handleTypes") - 1, 1);
	zend_declare_typed_property(class_entry, property_handleTypes_name, &property_handleTypes_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_handleTypes_name);

	return class_entry;
}

static zend_class_entry *register_class_VkExportMemoryAllocateInfo(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkExportMemoryAllocateInfo", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_pNext_default_value;
	ZVAL_NULL(&property_pNext_default_value);
	zend_string *property_pNext_name = zend_string_init("pNext", sizeof("pNext") - 1, 1);
	zend_declare_typed_property(class_entry, property_pNext_name, &property_pNext_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_OBJECT|MAY_BE_NULL));
	zend_string_release(property_pNext_name);

	zval property_handleTypes_default_value;
	ZVAL_LONG(&property_handleTypes_default_value, 0);
	zend_string *property_handleTypes_name = zend_string_init("handleTypes", sizeof("handleTypes") - 1, 1);
	zend_declare_typed_property(class_entry, property_handleTypes_name, &property_handleTypes_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_handleTypes_name);

	return class_entry;
}

static zend_class_entry *register_class_VkMemoryDedicatedAllocateInfo(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkMemoryDedicatedAllocateInfo", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_pNext_default_value;
	ZVAL_NULL(&property_pNext_default_value);
	zend_string *property_pNext_name = zend_string_init("pNext", sizeof("pNext") - 1, 1);
	zend_declare_typed_property(class_entry, property_pNext_name, &property_pNext_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_OBJECT|MAY_BE_NULL));
	zend_string_release(property_pNext_name);

	zval property_image_default_value;
	ZVAL_NULL(&property_image_default_value);
	zend_string *property_image_name = zend_string_init("image", sizeof("image") - 1, 1);
	zend_string *property_image_class_VkImage = zend_string_init("VkImage", sizeof("VkImage")-1, 1);
	zend_declare_typed_property(class_entry, property_image_name, &property_image_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_image_class_VkImage, 0, MAY_BE_NULL));
	zend_string_release(property_image_name);

	zval property_buffer_default_value;
	ZVAL_NULL(&property_buffer_default_value);
	zend_string *property_buffer_name = zend_string_init("buffer", sizeof("buffer") - 1, 1);
	zend_string *property_buffer_class_VkBuffer = zend_string_init("VkBuffer", sizeof("VkBuffer")-1, 1);
	zend_declare_typed_property(class_entry, property_buffer_name, &property_buffer_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_buffer_class_VkBuffer, 0, MAY_BE_NULL));
	zend_string_release(property_buffer_name);

	return class_entry;
}

static zend_class_entry *register_class_VkMemoryGetFdInfoKHR(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkMemoryGetFdInfoKHR", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_pNext_default_value;
	ZVAL_NULL(&property_pNext_default_value);
	zend_string *property_pNext_name = zend_string_init("pNext", sizeof("pNext") - 1, 1);
	zend_declare_typed_property(class_entry, property_pNext_name, &property_pNext_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_OBJECT|MAY_BE_NULL));
	zend_string_release(property_pNext_name);

	zval property_memory_default_value;
	ZVAL_NULL(&property_memory_default_value);
	zend_string *property_memory_name = zend_string_init("memory", sizeof("memory") - 1, 1);
	zend_string *property_memory_class_VkDeviceMemory = zend_string_init("VkDeviceMemory", sizeof("VkDeviceMemory")-1, 1);
	zend_declare_typed_property(class_entry, property_memory_name, &property_memory_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_memory_class_VkDeviceMemory, 0, MAY_BE_NULL));
	zend_string_release(property_memory_name);

	zval property_handleType_default_value;
	ZVAL_LONG(&property_handleType_default_value, 0);
	zend_string *property_handleType_name = zend_string_init("handleType", sizeof("handleType") - 1, 1);
	zend_declare_typed_property(class_entry, property_handleType_name, &property_handleType_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_handleType_name);

	return class_entry;
}

static zend_class_entry *register_class_VkImageDrmFormatModifierListCreateInfoEXT(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkImageDrmFormatModifierListCreateInfoEXT", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_pNext_default_value;
	ZVAL_NULL(&property_pNext_default_value);
	zend_string *property_pNext_name = zend_string_init("pNext", sizeof("pNext") - 1, 1);
	zend_declare_typed_property(class_entry, property_pNext_name, &property_pNext_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_OBJECT|MAY_BE_NULL));
	zend_string_release(property_pNext_name);

	zval property_pDrmFormatModifiers_default_value;
	ZVAL_EMPTY_ARRAY(&property_pDrmFormatModifiers_default_value);
	zend_string *property_pDrmFormatModifiers_name = zend_string_init("pDrmFormatModifiers", sizeof("pDrmFormatModifiers") - 1, 1);
	zend_declare_typed_property(class_entry, property_pDrmFormatModifiers_name, &property_pDrmFormatModifiers_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_pDrmFormatModifiers_name);

	return class_entry;
}

static zend_class_entry *register_class_VkImageDrmFormatModifierPropertiesEXT(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkImageDrmFormatModifierPropertiesEXT", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_drmFormatModifier_default_value;
	ZVAL_LONG(&property_drmFormatModifier_default_value, 0);
	zend_string *property_drmFormatModifier_name = zend_string_init("drmFormatModifier", sizeof("drmFormatModifier") - 1, 1);
	zend_declare_typed_property(class_entry, property_drmFormatModifier_name, &property_drmFormatModifier_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_drmFormatModifier_name);

	return class_entry;
}

static zend_class_entry *register_class_VkImageSubresource(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkImageSubresource", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_aspectMask_default_value;
	ZVAL_LONG(&property_aspectMask_default_value, 0);
	zend_string *property_aspectMask_name = zend_string_init("aspectMask", sizeof("aspectMask") - 1, 1);
	zend_declare_typed_property(class_entry, property_aspectMask_name, &property_aspectMask_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_aspectMask_name);

	zval property_mipLevel_default_value;
	ZVAL_LONG(&property_mipLevel_default_value, 0);
	zend_string *property_mipLevel_name = zend_string_init("mipLevel", sizeof("mipLevel") - 1, 1);
	zend_declare_typed_property(class_entry, property_mipLevel_name, &property_mipLevel_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mipLevel_name);

	zval property_arrayLayer_default_value;
	ZVAL_LONG(&property_arrayLayer_default_value, 0);
	zend_string *property_arrayLayer_name = zend_string_init("arrayLayer", sizeof("arrayLayer") - 1, 1);
	zend_declare_typed_property(class_entry, property_arrayLayer_name, &property_arrayLayer_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_arrayLayer_name);

	return class_entry;
}

static zend_class_entry *register_class_VkSubresourceLayout(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkSubresourceLayout", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_offset_default_value;
	ZVAL_LONG(&property_offset_default_value, 0);
	zend_string *property_offset_name = zend_string_init("offset", sizeof("offset") - 1, 1);
	zend_declare_typed_property(class_entry, property_offset_name, &property_offset_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_offset_name);

	zval property_size_default_value;
	ZVAL_LONG(&property_size_default_value, 0);
	zend_string *property_size_name = zend_string_init("size", sizeof("size") - 1, 1);
	zend_declare_typed_property(class_entry, property_size_name, &property_size_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_size_name);

	zval property_rowPitch_default_value;
	ZVAL_LONG(&property_rowPitch_default_value, 0);
	zend_string *property_rowPitch_name = zend_string_init("rowPitch", sizeof("rowPitch") - 1, 1);
	zend_declare_typed_property(class_entry, property_rowPitch_name, &property_rowPitch_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_rowPitch_name);

	zval property_arrayPitch_default_value;
	ZVAL_LONG(&property_arrayPitch_default_value, 0);
	zend_string *property_arrayPitch_name = zend_string_init("arrayPitch", sizeof("arrayPitch") - 1, 1);
	zend_declare_typed_property(class_entry, property_arrayPitch_name, &property_arrayPitch_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_arrayPitch_name);

	zval property_depthPitch_default_value;
	ZVAL_LONG(&property_depthPitch_default_value, 0);
	zend_string *property_depthPitch_name = zend_string_init("depthPitch", sizeof("depthPitch") - 1, 1);
	zend_declare_typed_property(class_entry, property_depthPitch_name, &property_depthPitch_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_depthPitch_name);

	return class_entry;
}
