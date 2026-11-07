#include "runtime.h"
#include "structs.h"
#include "../stubs/vk_memory_arginfo.h"

VULKAN_HANDLE_METHODS(VkDeviceMemory)
VULKAN_HANDLE_METHODS(VkBuffer)
VULKAN_HANDLE_METHODS(VkImage)
VULKAN_HANDLE_METHODS(VkImageView)
VULKAN_HANDLE_METHODS(VkSampler)

ZEND_METHOD(VkImageCreateInfo, __construct)
{
	ZEND_PARSE_PARAMETERS_NONE();
	vulkan_init_nested(Z_OBJ_P(ZEND_THIS), "extent", vulkan_ce_VkExtent3D);
}

ZEND_METHOD(VkImageViewCreateInfo, __construct)
{
	ZEND_PARSE_PARAMETERS_NONE();
	vulkan_init_nested(Z_OBJ_P(ZEND_THIS), "components", vulkan_ce_VkComponentMapping);
	vulkan_init_nested(Z_OBJ_P(ZEND_THIS), "subresourceRange", vulkan_ce_VkImageSubresourceRange);
}

#define ALLOCATOR(z) ((const VkAllocationCallbacks *) (uintptr_t) (z))

static bool vulkan_device(zval *zv, uint32_t arg_num, uint64_t *out)
{
	return vulkan_handle_value(zv, vulkan_ce_VkDevice, arg_num, out);
}

static void vulkan_box_result(zval *out, VkResult result, uint64_t value, zend_class_entry *ce, zend_object *parent)
{
	zval boxed;

	if (result == VK_SUCCESS) {
		vulkan_box(&boxed, value, ce, parent);
	} else {
		ZVAL_NULL(&boxed);
	}
	vulkan_assign(out, &boxed);
}

void vulkan_register_memory(int module_number)
{
	(void) module_number;
	zend_register_functions(NULL, ext_functions, NULL, MODULE_PERSISTENT);

	vulkan_ce_VkDeviceMemory = register_class_VkDeviceMemory();
	vulkan_handle_setup(vulkan_ce_VkDeviceMemory);
	vulkan_ce_VkBuffer = register_class_VkBuffer();
	vulkan_handle_setup(vulkan_ce_VkBuffer);
	vulkan_ce_VkImage = register_class_VkImage();
	vulkan_handle_setup(vulkan_ce_VkImage);
	vulkan_ce_VkImageView = register_class_VkImageView();
	vulkan_handle_setup(vulkan_ce_VkImageView);
	vulkan_ce_VkSampler = register_class_VkSampler();
	vulkan_handle_setup(vulkan_ce_VkSampler);

	vulkan_ce_VkMemoryAllocateInfo = register_class_VkMemoryAllocateInfo();
	vulkan_struct_setup(vulkan_ce_VkMemoryAllocateInfo);
	vulkan_ce_VkMappedMemoryRange = register_class_VkMappedMemoryRange();
	vulkan_struct_setup(vulkan_ce_VkMappedMemoryRange);
	vulkan_ce_VkBufferCreateInfo = register_class_VkBufferCreateInfo();
	vulkan_struct_setup(vulkan_ce_VkBufferCreateInfo);
	vulkan_ce_VkMemoryRequirements = register_class_VkMemoryRequirements();
	vulkan_struct_setup(vulkan_ce_VkMemoryRequirements);
	vulkan_ce_VkImageCreateInfo = register_class_VkImageCreateInfo();
	vulkan_struct_setup(vulkan_ce_VkImageCreateInfo);
	vulkan_ce_VkComponentMapping = register_class_VkComponentMapping();
	vulkan_struct_setup(vulkan_ce_VkComponentMapping);
	vulkan_ce_VkImageSubresourceRange = register_class_VkImageSubresourceRange();
	vulkan_struct_setup(vulkan_ce_VkImageSubresourceRange);
	vulkan_ce_VkImageViewCreateInfo = register_class_VkImageViewCreateInfo();
	vulkan_struct_setup(vulkan_ce_VkImageViewCreateInfo);
	vulkan_ce_VkSamplerCreateInfo = register_class_VkSamplerCreateInfo();
	vulkan_struct_setup(vulkan_ce_VkSamplerCreateInfo);
}

ZEND_FUNCTION(vkAllocateMemory)
{
	zval *device, *info, *out;
	zend_long allocator;
	uint64_t device_value;
	VkMemoryAllocateInfo allocate;
	VkDeviceMemory memory = VK_NULL_HANDLE;
	vulkan_scratch scratch;
	VkResult result;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT(device)
		Z_PARAM_OBJECT(info)
		Z_PARAM_LONG(allocator)
		Z_PARAM_ZVAL(out)
	ZEND_PARSE_PARAMETERS_END();

	if (!vulkan_device(device, 1, &device_value)) {
		RETURN_THROWS();
	}
	vulkan_scratch_init(&scratch);
	if (!vulkan_arg_struct(info, vulkan_ce_VkMemoryAllocateInfo, vk_VkMemoryAllocateInfo_from, &allocate, &scratch)) {
		vulkan_scratch_free(&scratch);
		RETURN_THROWS();
	}
	result = vkAllocateMemory((VkDevice) (uintptr_t) device_value, &allocate, ALLOCATOR(allocator), &memory);
	vulkan_scratch_free(&scratch);
	vulkan_box_result(out, result, (uint64_t) (uintptr_t) memory, vulkan_ce_VkDeviceMemory, Z_OBJ_P(device));
	RETURN_LONG((zend_long) result);
}

ZEND_FUNCTION(vkFreeMemory)
{
	zval *device, *memory;
	zend_long allocator;
	uint64_t device_value, memory_value = 0;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT(device)
		Z_PARAM_OBJECT_OR_NULL(memory)
		Z_PARAM_LONG(allocator)
	ZEND_PARSE_PARAMETERS_END();

	if (!vulkan_device(device, 1, &device_value)
		|| (memory && !vulkan_handle_value(memory, vulkan_ce_VkDeviceMemory, 2, &memory_value))) {
		RETURN_THROWS();
	}
	vkFreeMemory((VkDevice) (uintptr_t) device_value, (VkDeviceMemory) (uintptr_t) memory_value, ALLOCATOR(allocator));
	if (memory) {
		vulkan_release_tree(Z_OBJ_P(memory));
	}
}

ZEND_FUNCTION(vkMapMemory)
{
	zval *device, *memory, *out;
	zend_long offset, size, flags;
	uint64_t device_value, memory_value;
	void *data = NULL;
	VkResult result;
	zval boxed;

	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_OBJECT(device)
		Z_PARAM_OBJECT(memory)
		Z_PARAM_LONG(offset)
		Z_PARAM_LONG(size)
		Z_PARAM_LONG(flags)
		Z_PARAM_ZVAL(out)
	ZEND_PARSE_PARAMETERS_END();

	if (!vulkan_device(device, 1, &device_value) || !vulkan_handle_value(memory, vulkan_ce_VkDeviceMemory, 2, &memory_value)) {
		RETURN_THROWS();
	}
	result = vkMapMemory((VkDevice) (uintptr_t) device_value, (VkDeviceMemory) (uintptr_t) memory_value, (VkDeviceSize) offset, (VkDeviceSize) size, (VkMemoryMapFlags) flags, &data);
	ZVAL_LONG(&boxed, (zend_long) (uintptr_t) data);
	vulkan_assign(out, &boxed);
	RETURN_LONG((zend_long) result);
}

ZEND_FUNCTION(vkUnmapMemory)
{
	zval *device, *memory;
	uint64_t device_value, memory_value;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT(device)
		Z_PARAM_OBJECT(memory)
	ZEND_PARSE_PARAMETERS_END();

	if (!vulkan_device(device, 1, &device_value) || !vulkan_handle_value(memory, vulkan_ce_VkDeviceMemory, 2, &memory_value)) {
		RETURN_THROWS();
	}
	vkUnmapMemory((VkDevice) (uintptr_t) device_value, (VkDeviceMemory) (uintptr_t) memory_value);
}

static void vulkan_memory_ranges(INTERNAL_FUNCTION_PARAMETERS, VkResult (*call)(VkDevice, uint32_t, const VkMappedMemoryRange *))
{
	zval *device, *ranges;
	zend_long count;
	uint64_t device_value;
	void *items;
	vulkan_scratch scratch;
	VkResult result;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT(device)
		Z_PARAM_LONG(count)
		Z_PARAM_ZVAL(ranges)
	ZEND_PARSE_PARAMETERS_END();

	if (!vulkan_device(device, 1, &device_value)) {
		RETURN_THROWS();
	}
	vulkan_scratch_init(&scratch);
	if (!vulkan_arg_structs(ranges, count, 2, 3, vulkan_ce_VkMappedMemoryRange, sizeof(VkMappedMemoryRange), vk_VkMappedMemoryRange_from, &items, &scratch)) {
		vulkan_scratch_free(&scratch);
		RETURN_THROWS();
	}
	result = call((VkDevice) (uintptr_t) device_value, (uint32_t) count, items);
	vulkan_scratch_free(&scratch);
	RETURN_LONG((zend_long) result);
}

ZEND_FUNCTION(vkFlushMappedMemoryRanges)
{
	vulkan_memory_ranges(INTERNAL_FUNCTION_PARAM_PASSTHRU, vkFlushMappedMemoryRanges);
}

ZEND_FUNCTION(vkInvalidateMappedMemoryRanges)
{
	vulkan_memory_ranges(INTERNAL_FUNCTION_PARAM_PASSTHRU, vkInvalidateMappedMemoryRanges);
}

ZEND_FUNCTION(vkCreateBuffer)
{
	zval *device, *info, *out;
	zend_long allocator;
	uint64_t device_value;
	VkBufferCreateInfo create;
	VkBuffer buffer = VK_NULL_HANDLE;
	vulkan_scratch scratch;
	VkResult result;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT(device)
		Z_PARAM_OBJECT(info)
		Z_PARAM_LONG(allocator)
		Z_PARAM_ZVAL(out)
	ZEND_PARSE_PARAMETERS_END();

	if (!vulkan_device(device, 1, &device_value)) {
		RETURN_THROWS();
	}
	vulkan_scratch_init(&scratch);
	if (!vulkan_arg_struct(info, vulkan_ce_VkBufferCreateInfo, vk_VkBufferCreateInfo_from, &create, &scratch)) {
		vulkan_scratch_free(&scratch);
		RETURN_THROWS();
	}
	result = vkCreateBuffer((VkDevice) (uintptr_t) device_value, &create, ALLOCATOR(allocator), &buffer);
	vulkan_scratch_free(&scratch);
	vulkan_box_result(out, result, (uint64_t) (uintptr_t) buffer, vulkan_ce_VkBuffer, Z_OBJ_P(device));
	RETURN_LONG((zend_long) result);
}

ZEND_FUNCTION(vkDestroyBuffer)
{
	zval *device, *buffer;
	zend_long allocator;
	uint64_t device_value, buffer_value = 0;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT(device)
		Z_PARAM_OBJECT_OR_NULL(buffer)
		Z_PARAM_LONG(allocator)
	ZEND_PARSE_PARAMETERS_END();

	if (!vulkan_device(device, 1, &device_value)
		|| (buffer && !vulkan_handle_value(buffer, vulkan_ce_VkBuffer, 2, &buffer_value))) {
		RETURN_THROWS();
	}
	vkDestroyBuffer((VkDevice) (uintptr_t) device_value, (VkBuffer) (uintptr_t) buffer_value, ALLOCATOR(allocator));
	if (buffer) {
		vulkan_release_tree(Z_OBJ_P(buffer));
	}
}

ZEND_FUNCTION(vkGetBufferMemoryRequirements)
{
	zval *device, *buffer, *out;
	uint64_t device_value, buffer_value;
	VkMemoryRequirements requirements;
	zval boxed;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT(device)
		Z_PARAM_OBJECT(buffer)
		Z_PARAM_ZVAL(out)
	ZEND_PARSE_PARAMETERS_END();

	if (!vulkan_device(device, 1, &device_value) || !vulkan_handle_value(buffer, vulkan_ce_VkBuffer, 2, &buffer_value)) {
		RETURN_THROWS();
	}
	vkGetBufferMemoryRequirements((VkDevice) (uintptr_t) device_value, (VkBuffer) (uintptr_t) buffer_value, &requirements);
	vk_VkMemoryRequirements_to(&requirements, &boxed);
	vulkan_assign(out, &boxed);
}

ZEND_FUNCTION(vkBindBufferMemory)
{
	zval *device, *buffer, *memory;
	zend_long offset;
	uint64_t device_value, buffer_value, memory_value;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT(device)
		Z_PARAM_OBJECT(buffer)
		Z_PARAM_OBJECT(memory)
		Z_PARAM_LONG(offset)
	ZEND_PARSE_PARAMETERS_END();

	if (!vulkan_device(device, 1, &device_value)
		|| !vulkan_handle_value(buffer, vulkan_ce_VkBuffer, 2, &buffer_value)
		|| !vulkan_handle_value(memory, vulkan_ce_VkDeviceMemory, 3, &memory_value)) {
		RETURN_THROWS();
	}
	RETURN_LONG((zend_long) vkBindBufferMemory((VkDevice) (uintptr_t) device_value, (VkBuffer) (uintptr_t) buffer_value, (VkDeviceMemory) (uintptr_t) memory_value, (VkDeviceSize) offset));
}

ZEND_FUNCTION(vkCreateImage)
{
	zval *device, *info, *out;
	zend_long allocator;
	uint64_t device_value;
	VkImageCreateInfo create;
	VkImage image = VK_NULL_HANDLE;
	vulkan_scratch scratch;
	VkResult result;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT(device)
		Z_PARAM_OBJECT(info)
		Z_PARAM_LONG(allocator)
		Z_PARAM_ZVAL(out)
	ZEND_PARSE_PARAMETERS_END();

	if (!vulkan_device(device, 1, &device_value)) {
		RETURN_THROWS();
	}
	vulkan_scratch_init(&scratch);
	if (!vulkan_arg_struct(info, vulkan_ce_VkImageCreateInfo, vk_VkImageCreateInfo_from, &create, &scratch)) {
		vulkan_scratch_free(&scratch);
		RETURN_THROWS();
	}
	result = vkCreateImage((VkDevice) (uintptr_t) device_value, &create, ALLOCATOR(allocator), &image);
	vulkan_scratch_free(&scratch);
	vulkan_box_result(out, result, (uint64_t) (uintptr_t) image, vulkan_ce_VkImage, Z_OBJ_P(device));
	RETURN_LONG((zend_long) result);
}

ZEND_FUNCTION(vkDestroyImage)
{
	zval *device, *image;
	zend_long allocator;
	uint64_t device_value, image_value = 0;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT(device)
		Z_PARAM_OBJECT_OR_NULL(image)
		Z_PARAM_LONG(allocator)
	ZEND_PARSE_PARAMETERS_END();

	if (!vulkan_device(device, 1, &device_value)
		|| (image && !vulkan_handle_value(image, vulkan_ce_VkImage, 2, &image_value))) {
		RETURN_THROWS();
	}
	vkDestroyImage((VkDevice) (uintptr_t) device_value, (VkImage) (uintptr_t) image_value, ALLOCATOR(allocator));
	if (image) {
		vulkan_release_tree(Z_OBJ_P(image));
	}
}

ZEND_FUNCTION(vkGetImageMemoryRequirements)
{
	zval *device, *image, *out;
	uint64_t device_value, image_value;
	VkMemoryRequirements requirements;
	zval boxed;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT(device)
		Z_PARAM_OBJECT(image)
		Z_PARAM_ZVAL(out)
	ZEND_PARSE_PARAMETERS_END();

	if (!vulkan_device(device, 1, &device_value) || !vulkan_handle_value(image, vulkan_ce_VkImage, 2, &image_value)) {
		RETURN_THROWS();
	}
	vkGetImageMemoryRequirements((VkDevice) (uintptr_t) device_value, (VkImage) (uintptr_t) image_value, &requirements);
	vk_VkMemoryRequirements_to(&requirements, &boxed);
	vulkan_assign(out, &boxed);
}

ZEND_FUNCTION(vkBindImageMemory)
{
	zval *device, *image, *memory;
	zend_long offset;
	uint64_t device_value, image_value, memory_value;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT(device)
		Z_PARAM_OBJECT(image)
		Z_PARAM_OBJECT(memory)
		Z_PARAM_LONG(offset)
	ZEND_PARSE_PARAMETERS_END();

	if (!vulkan_device(device, 1, &device_value)
		|| !vulkan_handle_value(image, vulkan_ce_VkImage, 2, &image_value)
		|| !vulkan_handle_value(memory, vulkan_ce_VkDeviceMemory, 3, &memory_value)) {
		RETURN_THROWS();
	}
	RETURN_LONG((zend_long) vkBindImageMemory((VkDevice) (uintptr_t) device_value, (VkImage) (uintptr_t) image_value, (VkDeviceMemory) (uintptr_t) memory_value, (VkDeviceSize) offset));
}

ZEND_FUNCTION(vkCreateImageView)
{
	zval *device, *info, *out;
	zend_long allocator;
	uint64_t device_value;
	VkImageViewCreateInfo create;
	VkImageView view = VK_NULL_HANDLE;
	vulkan_scratch scratch;
	VkResult result;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT(device)
		Z_PARAM_OBJECT(info)
		Z_PARAM_LONG(allocator)
		Z_PARAM_ZVAL(out)
	ZEND_PARSE_PARAMETERS_END();

	if (!vulkan_device(device, 1, &device_value)) {
		RETURN_THROWS();
	}
	vulkan_scratch_init(&scratch);
	if (!vulkan_arg_struct(info, vulkan_ce_VkImageViewCreateInfo, vk_VkImageViewCreateInfo_from, &create, &scratch)) {
		vulkan_scratch_free(&scratch);
		RETURN_THROWS();
	}
	result = vkCreateImageView((VkDevice) (uintptr_t) device_value, &create, ALLOCATOR(allocator), &view);
	vulkan_scratch_free(&scratch);
	vulkan_box_result(out, result, (uint64_t) (uintptr_t) view, vulkan_ce_VkImageView, Z_OBJ_P(device));
	RETURN_LONG((zend_long) result);
}

ZEND_FUNCTION(vkDestroyImageView)
{
	zval *device, *view;
	zend_long allocator;
	uint64_t device_value, view_value = 0;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT(device)
		Z_PARAM_OBJECT_OR_NULL(view)
		Z_PARAM_LONG(allocator)
	ZEND_PARSE_PARAMETERS_END();

	if (!vulkan_device(device, 1, &device_value)
		|| (view && !vulkan_handle_value(view, vulkan_ce_VkImageView, 2, &view_value))) {
		RETURN_THROWS();
	}
	vkDestroyImageView((VkDevice) (uintptr_t) device_value, (VkImageView) (uintptr_t) view_value, ALLOCATOR(allocator));
	if (view) {
		vulkan_release_tree(Z_OBJ_P(view));
	}
}

ZEND_FUNCTION(vkCreateSampler)
{
	zval *device, *info, *out;
	zend_long allocator;
	uint64_t device_value;
	VkSamplerCreateInfo create;
	VkSampler sampler = VK_NULL_HANDLE;
	vulkan_scratch scratch;
	VkResult result;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT(device)
		Z_PARAM_OBJECT(info)
		Z_PARAM_LONG(allocator)
		Z_PARAM_ZVAL(out)
	ZEND_PARSE_PARAMETERS_END();

	if (!vulkan_device(device, 1, &device_value)) {
		RETURN_THROWS();
	}
	vulkan_scratch_init(&scratch);
	if (!vulkan_arg_struct(info, vulkan_ce_VkSamplerCreateInfo, vk_VkSamplerCreateInfo_from, &create, &scratch)) {
		vulkan_scratch_free(&scratch);
		RETURN_THROWS();
	}
	result = vkCreateSampler((VkDevice) (uintptr_t) device_value, &create, ALLOCATOR(allocator), &sampler);
	vulkan_scratch_free(&scratch);
	vulkan_box_result(out, result, (uint64_t) (uintptr_t) sampler, vulkan_ce_VkSampler, Z_OBJ_P(device));
	RETURN_LONG((zend_long) result);
}

ZEND_FUNCTION(vkDestroySampler)
{
	zval *device, *sampler;
	zend_long allocator;
	uint64_t device_value, sampler_value = 0;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT(device)
		Z_PARAM_OBJECT_OR_NULL(sampler)
		Z_PARAM_LONG(allocator)
	ZEND_PARSE_PARAMETERS_END();

	if (!vulkan_device(device, 1, &device_value)
		|| (sampler && !vulkan_handle_value(sampler, vulkan_ce_VkSampler, 2, &sampler_value))) {
		RETURN_THROWS();
	}
	vkDestroySampler((VkDevice) (uintptr_t) device_value, (VkSampler) (uintptr_t) sampler_value, ALLOCATOR(allocator));
	if (sampler) {
		vulkan_release_tree(Z_OBJ_P(sampler));
	}
}
