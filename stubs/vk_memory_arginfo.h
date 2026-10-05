/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: c4d0a1e986974eca19704f8b58ec69ab2d938869 */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkAllocateMemory, 0, 4, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, device, VkDevice, 0)
	ZEND_ARG_OBJ_INFO(0, pAllocateInfo, VkMemoryAllocateInfo, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_NULL, 1)
	ZEND_ARG_OBJ_INFO(1, pMemory, VkDeviceMemory, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkFreeMemory, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, device, VkDevice, 0)
	ZEND_ARG_OBJ_INFO(0, memory, VkDeviceMemory, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_NULL, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkMapMemory, 0, 6, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, device, VkDevice, 0)
	ZEND_ARG_OBJ_INFO(0, memory, VkDeviceMemory, 0)
	ZEND_ARG_TYPE_INFO(0, offset, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, size, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, flags, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(1, ppData, IS_LONG, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkUnmapMemory, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, device, VkDevice, 0)
	ZEND_ARG_OBJ_INFO(0, memory, VkDeviceMemory, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkFlushMappedMemoryRanges, 0, 2, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, device, VkDevice, 0)
	ZEND_ARG_TYPE_INFO(0, pMemoryRanges, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

#define arginfo_vkInvalidateMappedMemoryRanges arginfo_vkFlushMappedMemoryRanges

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkCreateBuffer, 0, 4, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, device, VkDevice, 0)
	ZEND_ARG_OBJ_INFO(0, pCreateInfo, VkBufferCreateInfo, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_NULL, 1)
	ZEND_ARG_OBJ_INFO(1, pBuffer, VkBuffer, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkDestroyBuffer, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, device, VkDevice, 0)
	ZEND_ARG_OBJ_INFO(0, buffer, VkBuffer, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_NULL, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkGetBufferMemoryRequirements, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, device, VkDevice, 0)
	ZEND_ARG_OBJ_INFO(0, buffer, VkBuffer, 0)
	ZEND_ARG_OBJ_INFO(1, pMemoryRequirements, VkMemoryRequirements, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkBindBufferMemory, 0, 4, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, device, VkDevice, 0)
	ZEND_ARG_OBJ_INFO(0, buffer, VkBuffer, 0)
	ZEND_ARG_OBJ_INFO(0, memory, VkDeviceMemory, 0)
	ZEND_ARG_TYPE_INFO(0, memoryOffset, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkCreateImage, 0, 4, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, device, VkDevice, 0)
	ZEND_ARG_OBJ_INFO(0, pCreateInfo, VkImageCreateInfo, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_NULL, 1)
	ZEND_ARG_OBJ_INFO(1, pImage, VkImage, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkDestroyImage, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, device, VkDevice, 0)
	ZEND_ARG_OBJ_INFO(0, image, VkImage, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_NULL, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkGetImageMemoryRequirements, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, device, VkDevice, 0)
	ZEND_ARG_OBJ_INFO(0, image, VkImage, 0)
	ZEND_ARG_OBJ_INFO(1, pMemoryRequirements, VkMemoryRequirements, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkBindImageMemory, 0, 4, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, device, VkDevice, 0)
	ZEND_ARG_OBJ_INFO(0, image, VkImage, 0)
	ZEND_ARG_OBJ_INFO(0, memory, VkDeviceMemory, 0)
	ZEND_ARG_TYPE_INFO(0, memoryOffset, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkCreateImageView, 0, 4, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, device, VkDevice, 0)
	ZEND_ARG_OBJ_INFO(0, pCreateInfo, VkImageViewCreateInfo, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_NULL, 1)
	ZEND_ARG_OBJ_INFO(1, pView, VkImageView, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkDestroyImageView, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, device, VkDevice, 0)
	ZEND_ARG_OBJ_INFO(0, imageView, VkImageView, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_NULL, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkCreateSampler, 0, 4, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, device, VkDevice, 0)
	ZEND_ARG_OBJ_INFO(0, pCreateInfo, VkSamplerCreateInfo, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_NULL, 1)
	ZEND_ARG_OBJ_INFO(1, pSampler, VkSampler, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkDestroySampler, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, device, VkDevice, 0)
	ZEND_ARG_OBJ_INFO(0, sampler, VkSampler, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_NULL, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_VkDeviceMemory___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_VkDeviceMemory_pointer, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_VkDeviceMemory_fromPointer, 0, 1, IS_STATIC, 0)
	ZEND_ARG_TYPE_INFO(0, pointer, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_VkBuffer___construct arginfo_class_VkDeviceMemory___construct

#define arginfo_class_VkBuffer_pointer arginfo_class_VkDeviceMemory_pointer

#define arginfo_class_VkBuffer_fromPointer arginfo_class_VkDeviceMemory_fromPointer

#define arginfo_class_VkImage___construct arginfo_class_VkDeviceMemory___construct

#define arginfo_class_VkImage_pointer arginfo_class_VkDeviceMemory_pointer

#define arginfo_class_VkImage_fromPointer arginfo_class_VkDeviceMemory_fromPointer

#define arginfo_class_VkImageView___construct arginfo_class_VkDeviceMemory___construct

#define arginfo_class_VkImageView_pointer arginfo_class_VkDeviceMemory_pointer

#define arginfo_class_VkImageView_fromPointer arginfo_class_VkDeviceMemory_fromPointer

#define arginfo_class_VkSampler___construct arginfo_class_VkDeviceMemory___construct

#define arginfo_class_VkSampler_pointer arginfo_class_VkDeviceMemory_pointer

#define arginfo_class_VkSampler_fromPointer arginfo_class_VkDeviceMemory_fromPointer

#define arginfo_class_VkImageCreateInfo___construct arginfo_class_VkDeviceMemory___construct

#define arginfo_class_VkImageViewCreateInfo___construct arginfo_class_VkDeviceMemory___construct

ZEND_FUNCTION(vkAllocateMemory);
ZEND_FUNCTION(vkFreeMemory);
ZEND_FUNCTION(vkMapMemory);
ZEND_FUNCTION(vkUnmapMemory);
ZEND_FUNCTION(vkFlushMappedMemoryRanges);
ZEND_FUNCTION(vkInvalidateMappedMemoryRanges);
ZEND_FUNCTION(vkCreateBuffer);
ZEND_FUNCTION(vkDestroyBuffer);
ZEND_FUNCTION(vkGetBufferMemoryRequirements);
ZEND_FUNCTION(vkBindBufferMemory);
ZEND_FUNCTION(vkCreateImage);
ZEND_FUNCTION(vkDestroyImage);
ZEND_FUNCTION(vkGetImageMemoryRequirements);
ZEND_FUNCTION(vkBindImageMemory);
ZEND_FUNCTION(vkCreateImageView);
ZEND_FUNCTION(vkDestroyImageView);
ZEND_FUNCTION(vkCreateSampler);
ZEND_FUNCTION(vkDestroySampler);
ZEND_METHOD(VkDeviceMemory, __construct);
ZEND_METHOD(VkDeviceMemory, pointer);
ZEND_METHOD(VkDeviceMemory, fromPointer);
ZEND_METHOD(VkBuffer, __construct);
ZEND_METHOD(VkBuffer, pointer);
ZEND_METHOD(VkBuffer, fromPointer);
ZEND_METHOD(VkImage, __construct);
ZEND_METHOD(VkImage, pointer);
ZEND_METHOD(VkImage, fromPointer);
ZEND_METHOD(VkImageView, __construct);
ZEND_METHOD(VkImageView, pointer);
ZEND_METHOD(VkImageView, fromPointer);
ZEND_METHOD(VkSampler, __construct);
ZEND_METHOD(VkSampler, pointer);
ZEND_METHOD(VkSampler, fromPointer);
ZEND_METHOD(VkImageCreateInfo, __construct);
ZEND_METHOD(VkImageViewCreateInfo, __construct);

static const zend_function_entry ext_functions[] = {
	ZEND_FE(vkAllocateMemory, arginfo_vkAllocateMemory)
	ZEND_FE(vkFreeMemory, arginfo_vkFreeMemory)
	ZEND_FE(vkMapMemory, arginfo_vkMapMemory)
	ZEND_FE(vkUnmapMemory, arginfo_vkUnmapMemory)
	ZEND_FE(vkFlushMappedMemoryRanges, arginfo_vkFlushMappedMemoryRanges)
	ZEND_FE(vkInvalidateMappedMemoryRanges, arginfo_vkInvalidateMappedMemoryRanges)
	ZEND_FE(vkCreateBuffer, arginfo_vkCreateBuffer)
	ZEND_FE(vkDestroyBuffer, arginfo_vkDestroyBuffer)
	ZEND_FE(vkGetBufferMemoryRequirements, arginfo_vkGetBufferMemoryRequirements)
	ZEND_FE(vkBindBufferMemory, arginfo_vkBindBufferMemory)
	ZEND_FE(vkCreateImage, arginfo_vkCreateImage)
	ZEND_FE(vkDestroyImage, arginfo_vkDestroyImage)
	ZEND_FE(vkGetImageMemoryRequirements, arginfo_vkGetImageMemoryRequirements)
	ZEND_FE(vkBindImageMemory, arginfo_vkBindImageMemory)
	ZEND_FE(vkCreateImageView, arginfo_vkCreateImageView)
	ZEND_FE(vkDestroyImageView, arginfo_vkDestroyImageView)
	ZEND_FE(vkCreateSampler, arginfo_vkCreateSampler)
	ZEND_FE(vkDestroySampler, arginfo_vkDestroySampler)
	ZEND_FE_END
};

static const zend_function_entry class_VkDeviceMemory_methods[] = {
	ZEND_ME(VkDeviceMemory, __construct, arginfo_class_VkDeviceMemory___construct, ZEND_ACC_PRIVATE)
	ZEND_ME(VkDeviceMemory, pointer, arginfo_class_VkDeviceMemory_pointer, ZEND_ACC_PUBLIC)
	ZEND_ME(VkDeviceMemory, fromPointer, arginfo_class_VkDeviceMemory_fromPointer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static const zend_function_entry class_VkBuffer_methods[] = {
	ZEND_ME(VkBuffer, __construct, arginfo_class_VkBuffer___construct, ZEND_ACC_PRIVATE)
	ZEND_ME(VkBuffer, pointer, arginfo_class_VkBuffer_pointer, ZEND_ACC_PUBLIC)
	ZEND_ME(VkBuffer, fromPointer, arginfo_class_VkBuffer_fromPointer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static const zend_function_entry class_VkImage_methods[] = {
	ZEND_ME(VkImage, __construct, arginfo_class_VkImage___construct, ZEND_ACC_PRIVATE)
	ZEND_ME(VkImage, pointer, arginfo_class_VkImage_pointer, ZEND_ACC_PUBLIC)
	ZEND_ME(VkImage, fromPointer, arginfo_class_VkImage_fromPointer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static const zend_function_entry class_VkImageView_methods[] = {
	ZEND_ME(VkImageView, __construct, arginfo_class_VkImageView___construct, ZEND_ACC_PRIVATE)
	ZEND_ME(VkImageView, pointer, arginfo_class_VkImageView_pointer, ZEND_ACC_PUBLIC)
	ZEND_ME(VkImageView, fromPointer, arginfo_class_VkImageView_fromPointer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static const zend_function_entry class_VkSampler_methods[] = {
	ZEND_ME(VkSampler, __construct, arginfo_class_VkSampler___construct, ZEND_ACC_PRIVATE)
	ZEND_ME(VkSampler, pointer, arginfo_class_VkSampler_pointer, ZEND_ACC_PUBLIC)
	ZEND_ME(VkSampler, fromPointer, arginfo_class_VkSampler_fromPointer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static const zend_function_entry class_VkImageCreateInfo_methods[] = {
	ZEND_ME(VkImageCreateInfo, __construct, arginfo_class_VkImageCreateInfo___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_VkImageViewCreateInfo_methods[] = {
	ZEND_ME(VkImageViewCreateInfo, __construct, arginfo_class_VkImageViewCreateInfo___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_VkDeviceMemory(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkDeviceMemory", class_VkDeviceMemory_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_VkBuffer(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkBuffer", class_VkBuffer_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_VkImage(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkImage", class_VkImage_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_VkImageView(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkImageView", class_VkImageView_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_VkSampler(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkSampler", class_VkSampler_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_VkMemoryAllocateInfo(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkMemoryAllocateInfo", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_pNext_default_value;
	ZVAL_NULL(&property_pNext_default_value);
	zend_string *property_pNext_name = zend_string_init("pNext", sizeof("pNext") - 1, 1);
	zend_declare_typed_property(class_entry, property_pNext_name, &property_pNext_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_OBJECT|MAY_BE_NULL));
	zend_string_release(property_pNext_name);

	zval property_allocationSize_default_value;
	ZVAL_LONG(&property_allocationSize_default_value, 0);
	zend_string *property_allocationSize_name = zend_string_init("allocationSize", sizeof("allocationSize") - 1, 1);
	zend_declare_typed_property(class_entry, property_allocationSize_name, &property_allocationSize_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_allocationSize_name);

	zval property_memoryTypeIndex_default_value;
	ZVAL_LONG(&property_memoryTypeIndex_default_value, 0);
	zend_string *property_memoryTypeIndex_name = zend_string_init("memoryTypeIndex", sizeof("memoryTypeIndex") - 1, 1);
	zend_declare_typed_property(class_entry, property_memoryTypeIndex_name, &property_memoryTypeIndex_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_memoryTypeIndex_name);

	return class_entry;
}

static zend_class_entry *register_class_VkMappedMemoryRange(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkMappedMemoryRange", NULL);
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

	return class_entry;
}

static zend_class_entry *register_class_VkBufferCreateInfo(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkBufferCreateInfo", NULL);
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

	zval property_size_default_value;
	ZVAL_LONG(&property_size_default_value, 0);
	zend_string *property_size_name = zend_string_init("size", sizeof("size") - 1, 1);
	zend_declare_typed_property(class_entry, property_size_name, &property_size_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_size_name);

	zval property_usage_default_value;
	ZVAL_LONG(&property_usage_default_value, 0);
	zend_string *property_usage_name = zend_string_init("usage", sizeof("usage") - 1, 1);
	zend_declare_typed_property(class_entry, property_usage_name, &property_usage_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_usage_name);

	zval property_sharingMode_default_value;
	ZVAL_LONG(&property_sharingMode_default_value, 0);
	zend_string *property_sharingMode_name = zend_string_init("sharingMode", sizeof("sharingMode") - 1, 1);
	zend_declare_typed_property(class_entry, property_sharingMode_name, &property_sharingMode_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_sharingMode_name);

	zval property_pQueueFamilyIndices_default_value;
	ZVAL_EMPTY_ARRAY(&property_pQueueFamilyIndices_default_value);
	zend_string *property_pQueueFamilyIndices_name = zend_string_init("pQueueFamilyIndices", sizeof("pQueueFamilyIndices") - 1, 1);
	zend_declare_typed_property(class_entry, property_pQueueFamilyIndices_name, &property_pQueueFamilyIndices_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_pQueueFamilyIndices_name);

	return class_entry;
}

static zend_class_entry *register_class_VkMemoryRequirements(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkMemoryRequirements", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_size_default_value;
	ZVAL_LONG(&property_size_default_value, 0);
	zend_string *property_size_name = zend_string_init("size", sizeof("size") - 1, 1);
	zend_declare_typed_property(class_entry, property_size_name, &property_size_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_size_name);

	zval property_alignment_default_value;
	ZVAL_LONG(&property_alignment_default_value, 0);
	zend_string *property_alignment_name = zend_string_init("alignment", sizeof("alignment") - 1, 1);
	zend_declare_typed_property(class_entry, property_alignment_name, &property_alignment_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_alignment_name);

	zval property_memoryTypeBits_default_value;
	ZVAL_LONG(&property_memoryTypeBits_default_value, 0);
	zend_string *property_memoryTypeBits_name = zend_string_init("memoryTypeBits", sizeof("memoryTypeBits") - 1, 1);
	zend_declare_typed_property(class_entry, property_memoryTypeBits_name, &property_memoryTypeBits_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_memoryTypeBits_name);

	return class_entry;
}

static zend_class_entry *register_class_VkImageCreateInfo(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkImageCreateInfo", class_VkImageCreateInfo_methods);
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

	zval property_imageType_default_value;
	ZVAL_LONG(&property_imageType_default_value, 0);
	zend_string *property_imageType_name = zend_string_init("imageType", sizeof("imageType") - 1, 1);
	zend_declare_typed_property(class_entry, property_imageType_name, &property_imageType_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_imageType_name);

	zval property_format_default_value;
	ZVAL_LONG(&property_format_default_value, 0);
	zend_string *property_format_name = zend_string_init("format", sizeof("format") - 1, 1);
	zend_declare_typed_property(class_entry, property_format_name, &property_format_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_format_name);

	zval property_extent_default_value;
	ZVAL_UNDEF(&property_extent_default_value);
	zend_string *property_extent_name = zend_string_init("extent", sizeof("extent") - 1, 1);
	zend_string *property_extent_class_VkExtent3D = zend_string_init("VkExtent3D", sizeof("VkExtent3D")-1, 1);
	zend_declare_typed_property(class_entry, property_extent_name, &property_extent_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_extent_class_VkExtent3D, 0, 0));
	zend_string_release(property_extent_name);

	zval property_mipLevels_default_value;
	ZVAL_LONG(&property_mipLevels_default_value, 0);
	zend_string *property_mipLevels_name = zend_string_init("mipLevels", sizeof("mipLevels") - 1, 1);
	zend_declare_typed_property(class_entry, property_mipLevels_name, &property_mipLevels_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mipLevels_name);

	zval property_arrayLayers_default_value;
	ZVAL_LONG(&property_arrayLayers_default_value, 0);
	zend_string *property_arrayLayers_name = zend_string_init("arrayLayers", sizeof("arrayLayers") - 1, 1);
	zend_declare_typed_property(class_entry, property_arrayLayers_name, &property_arrayLayers_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_arrayLayers_name);

	zval property_samples_default_value;
	ZVAL_LONG(&property_samples_default_value, 0);
	zend_string *property_samples_name = zend_string_init("samples", sizeof("samples") - 1, 1);
	zend_declare_typed_property(class_entry, property_samples_name, &property_samples_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_samples_name);

	zval property_tiling_default_value;
	ZVAL_LONG(&property_tiling_default_value, 0);
	zend_string *property_tiling_name = zend_string_init("tiling", sizeof("tiling") - 1, 1);
	zend_declare_typed_property(class_entry, property_tiling_name, &property_tiling_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_tiling_name);

	zval property_usage_default_value;
	ZVAL_LONG(&property_usage_default_value, 0);
	zend_string *property_usage_name = zend_string_init("usage", sizeof("usage") - 1, 1);
	zend_declare_typed_property(class_entry, property_usage_name, &property_usage_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_usage_name);

	zval property_sharingMode_default_value;
	ZVAL_LONG(&property_sharingMode_default_value, 0);
	zend_string *property_sharingMode_name = zend_string_init("sharingMode", sizeof("sharingMode") - 1, 1);
	zend_declare_typed_property(class_entry, property_sharingMode_name, &property_sharingMode_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_sharingMode_name);

	zval property_pQueueFamilyIndices_default_value;
	ZVAL_EMPTY_ARRAY(&property_pQueueFamilyIndices_default_value);
	zend_string *property_pQueueFamilyIndices_name = zend_string_init("pQueueFamilyIndices", sizeof("pQueueFamilyIndices") - 1, 1);
	zend_declare_typed_property(class_entry, property_pQueueFamilyIndices_name, &property_pQueueFamilyIndices_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_pQueueFamilyIndices_name);

	zval property_initialLayout_default_value;
	ZVAL_LONG(&property_initialLayout_default_value, 0);
	zend_string *property_initialLayout_name = zend_string_init("initialLayout", sizeof("initialLayout") - 1, 1);
	zend_declare_typed_property(class_entry, property_initialLayout_name, &property_initialLayout_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_initialLayout_name);

	return class_entry;
}

static zend_class_entry *register_class_VkComponentMapping(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkComponentMapping", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_r_default_value;
	ZVAL_LONG(&property_r_default_value, 0);
	zend_string *property_r_name = zend_string_init("r", sizeof("r") - 1, 1);
	zend_declare_typed_property(class_entry, property_r_name, &property_r_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_r_name);

	zval property_g_default_value;
	ZVAL_LONG(&property_g_default_value, 0);
	zend_string *property_g_name = zend_string_init("g", sizeof("g") - 1, 1);
	zend_declare_typed_property(class_entry, property_g_name, &property_g_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_g_name);

	zval property_b_default_value;
	ZVAL_LONG(&property_b_default_value, 0);
	zend_string *property_b_name = zend_string_init("b", sizeof("b") - 1, 1);
	zend_declare_typed_property(class_entry, property_b_name, &property_b_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_b_name);

	zval property_a_default_value;
	ZVAL_LONG(&property_a_default_value, 0);
	zend_string *property_a_name = zend_string_init("a", sizeof("a") - 1, 1);
	zend_declare_typed_property(class_entry, property_a_name, &property_a_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_a_name);

	return class_entry;
}

static zend_class_entry *register_class_VkImageSubresourceRange(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkImageSubresourceRange", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_aspectMask_default_value;
	ZVAL_LONG(&property_aspectMask_default_value, 0);
	zend_string *property_aspectMask_name = zend_string_init("aspectMask", sizeof("aspectMask") - 1, 1);
	zend_declare_typed_property(class_entry, property_aspectMask_name, &property_aspectMask_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_aspectMask_name);

	zval property_baseMipLevel_default_value;
	ZVAL_LONG(&property_baseMipLevel_default_value, 0);
	zend_string *property_baseMipLevel_name = zend_string_init("baseMipLevel", sizeof("baseMipLevel") - 1, 1);
	zend_declare_typed_property(class_entry, property_baseMipLevel_name, &property_baseMipLevel_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_baseMipLevel_name);

	zval property_levelCount_default_value;
	ZVAL_LONG(&property_levelCount_default_value, 0);
	zend_string *property_levelCount_name = zend_string_init("levelCount", sizeof("levelCount") - 1, 1);
	zend_declare_typed_property(class_entry, property_levelCount_name, &property_levelCount_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_levelCount_name);

	zval property_baseArrayLayer_default_value;
	ZVAL_LONG(&property_baseArrayLayer_default_value, 0);
	zend_string *property_baseArrayLayer_name = zend_string_init("baseArrayLayer", sizeof("baseArrayLayer") - 1, 1);
	zend_declare_typed_property(class_entry, property_baseArrayLayer_name, &property_baseArrayLayer_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_baseArrayLayer_name);

	zval property_layerCount_default_value;
	ZVAL_LONG(&property_layerCount_default_value, 0);
	zend_string *property_layerCount_name = zend_string_init("layerCount", sizeof("layerCount") - 1, 1);
	zend_declare_typed_property(class_entry, property_layerCount_name, &property_layerCount_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_layerCount_name);

	return class_entry;
}

static zend_class_entry *register_class_VkImageViewCreateInfo(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkImageViewCreateInfo", class_VkImageViewCreateInfo_methods);
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

	zval property_image_default_value;
	ZVAL_NULL(&property_image_default_value);
	zend_string *property_image_name = zend_string_init("image", sizeof("image") - 1, 1);
	zend_string *property_image_class_VkImage = zend_string_init("VkImage", sizeof("VkImage")-1, 1);
	zend_declare_typed_property(class_entry, property_image_name, &property_image_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_image_class_VkImage, 0, MAY_BE_NULL));
	zend_string_release(property_image_name);

	zval property_viewType_default_value;
	ZVAL_LONG(&property_viewType_default_value, 0);
	zend_string *property_viewType_name = zend_string_init("viewType", sizeof("viewType") - 1, 1);
	zend_declare_typed_property(class_entry, property_viewType_name, &property_viewType_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_viewType_name);

	zval property_format_default_value;
	ZVAL_LONG(&property_format_default_value, 0);
	zend_string *property_format_name = zend_string_init("format", sizeof("format") - 1, 1);
	zend_declare_typed_property(class_entry, property_format_name, &property_format_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_format_name);

	zval property_components_default_value;
	ZVAL_UNDEF(&property_components_default_value);
	zend_string *property_components_name = zend_string_init("components", sizeof("components") - 1, 1);
	zend_string *property_components_class_VkComponentMapping = zend_string_init("VkComponentMapping", sizeof("VkComponentMapping")-1, 1);
	zend_declare_typed_property(class_entry, property_components_name, &property_components_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_components_class_VkComponentMapping, 0, 0));
	zend_string_release(property_components_name);

	zval property_subresourceRange_default_value;
	ZVAL_UNDEF(&property_subresourceRange_default_value);
	zend_string *property_subresourceRange_name = zend_string_init("subresourceRange", sizeof("subresourceRange") - 1, 1);
	zend_string *property_subresourceRange_class_VkImageSubresourceRange = zend_string_init("VkImageSubresourceRange", sizeof("VkImageSubresourceRange")-1, 1);
	zend_declare_typed_property(class_entry, property_subresourceRange_name, &property_subresourceRange_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_subresourceRange_class_VkImageSubresourceRange, 0, 0));
	zend_string_release(property_subresourceRange_name);

	return class_entry;
}

static zend_class_entry *register_class_VkSamplerCreateInfo(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkSamplerCreateInfo", NULL);
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

	zval property_magFilter_default_value;
	ZVAL_LONG(&property_magFilter_default_value, 0);
	zend_string *property_magFilter_name = zend_string_init("magFilter", sizeof("magFilter") - 1, 1);
	zend_declare_typed_property(class_entry, property_magFilter_name, &property_magFilter_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_magFilter_name);

	zval property_minFilter_default_value;
	ZVAL_LONG(&property_minFilter_default_value, 0);
	zend_string *property_minFilter_name = zend_string_init("minFilter", sizeof("minFilter") - 1, 1);
	zend_declare_typed_property(class_entry, property_minFilter_name, &property_minFilter_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_minFilter_name);

	zval property_mipmapMode_default_value;
	ZVAL_LONG(&property_mipmapMode_default_value, 0);
	zend_string *property_mipmapMode_name = zend_string_init("mipmapMode", sizeof("mipmapMode") - 1, 1);
	zend_declare_typed_property(class_entry, property_mipmapMode_name, &property_mipmapMode_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mipmapMode_name);

	zval property_addressModeU_default_value;
	ZVAL_LONG(&property_addressModeU_default_value, 0);
	zend_string *property_addressModeU_name = zend_string_init("addressModeU", sizeof("addressModeU") - 1, 1);
	zend_declare_typed_property(class_entry, property_addressModeU_name, &property_addressModeU_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_addressModeU_name);

	zval property_addressModeV_default_value;
	ZVAL_LONG(&property_addressModeV_default_value, 0);
	zend_string *property_addressModeV_name = zend_string_init("addressModeV", sizeof("addressModeV") - 1, 1);
	zend_declare_typed_property(class_entry, property_addressModeV_name, &property_addressModeV_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_addressModeV_name);

	zval property_addressModeW_default_value;
	ZVAL_LONG(&property_addressModeW_default_value, 0);
	zend_string *property_addressModeW_name = zend_string_init("addressModeW", sizeof("addressModeW") - 1, 1);
	zend_declare_typed_property(class_entry, property_addressModeW_name, &property_addressModeW_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_addressModeW_name);

	zval property_mipLodBias_default_value;
	ZVAL_DOUBLE(&property_mipLodBias_default_value, 0.0);
	zend_string *property_mipLodBias_name = zend_string_init("mipLodBias", sizeof("mipLodBias") - 1, 1);
	zend_declare_typed_property(class_entry, property_mipLodBias_name, &property_mipLodBias_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mipLodBias_name);

	zval property_anisotropyEnable_default_value;
	ZVAL_FALSE(&property_anisotropyEnable_default_value);
	zend_string *property_anisotropyEnable_name = zend_string_init("anisotropyEnable", sizeof("anisotropyEnable") - 1, 1);
	zend_declare_typed_property(class_entry, property_anisotropyEnable_name, &property_anisotropyEnable_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_anisotropyEnable_name);

	zval property_maxAnisotropy_default_value;
	ZVAL_DOUBLE(&property_maxAnisotropy_default_value, 0.0);
	zend_string *property_maxAnisotropy_name = zend_string_init("maxAnisotropy", sizeof("maxAnisotropy") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxAnisotropy_name, &property_maxAnisotropy_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_maxAnisotropy_name);

	zval property_compareEnable_default_value;
	ZVAL_FALSE(&property_compareEnable_default_value);
	zend_string *property_compareEnable_name = zend_string_init("compareEnable", sizeof("compareEnable") - 1, 1);
	zend_declare_typed_property(class_entry, property_compareEnable_name, &property_compareEnable_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_compareEnable_name);

	zval property_compareOp_default_value;
	ZVAL_LONG(&property_compareOp_default_value, 0);
	zend_string *property_compareOp_name = zend_string_init("compareOp", sizeof("compareOp") - 1, 1);
	zend_declare_typed_property(class_entry, property_compareOp_name, &property_compareOp_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_compareOp_name);

	zval property_minLod_default_value;
	ZVAL_DOUBLE(&property_minLod_default_value, 0.0);
	zend_string *property_minLod_name = zend_string_init("minLod", sizeof("minLod") - 1, 1);
	zend_declare_typed_property(class_entry, property_minLod_name, &property_minLod_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_minLod_name);

	zval property_maxLod_default_value;
	ZVAL_DOUBLE(&property_maxLod_default_value, 0.0);
	zend_string *property_maxLod_name = zend_string_init("maxLod", sizeof("maxLod") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxLod_name, &property_maxLod_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_maxLod_name);

	zval property_borderColor_default_value;
	ZVAL_LONG(&property_borderColor_default_value, 0);
	zend_string *property_borderColor_name = zend_string_init("borderColor", sizeof("borderColor") - 1, 1);
	zend_declare_typed_property(class_entry, property_borderColor_name, &property_borderColor_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_borderColor_name);

	zval property_unnormalizedCoordinates_default_value;
	ZVAL_FALSE(&property_unnormalizedCoordinates_default_value);
	zend_string *property_unnormalizedCoordinates_name = zend_string_init("unnormalizedCoordinates", sizeof("unnormalizedCoordinates") - 1, 1);
	zend_declare_typed_property(class_entry, property_unnormalizedCoordinates_name, &property_unnormalizedCoordinates_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_unnormalizedCoordinates_name);

	return class_entry;
}
