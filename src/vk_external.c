#include "runtime.h"
#include "structs.h"
#include "../stubs/vk_external_arginfo.h"

static bool vulkan_in(zval *zv, zend_class_entry *ce, vulkan_from_fn from, void *dst, vulkan_scratch *scratch)
{
	HashTable visited;
	bool ok;
	if (Z_TYPE_P(zv) != IS_OBJECT || !instanceof_function(Z_OBJCE_P(zv), ce)) {
		zend_type_error("must be of type %s", ZSTR_VAL(ce->name));
		return false;
	}
	zend_hash_init(&visited, 4, NULL, NULL, 0);
	ok = from(Z_OBJ_P(zv), dst, scratch, &visited);
	zend_hash_destroy(&visited);
	return ok;
}

void vulkan_register_external(int module_number)
{
	(void) module_number;
	zend_register_functions(NULL, ext_functions, NULL, MODULE_PERSISTENT);
	vulkan_ce_VkExternalMemoryImageCreateInfo = register_class_VkExternalMemoryImageCreateInfo();
	vulkan_struct_setup(vulkan_ce_VkExternalMemoryImageCreateInfo);
	vulkan_ce_VkExportMemoryAllocateInfo = register_class_VkExportMemoryAllocateInfo();
	vulkan_struct_setup(vulkan_ce_VkExportMemoryAllocateInfo);
	vulkan_ce_VkMemoryGetFdInfoKHR = register_class_VkMemoryGetFdInfoKHR();
	vulkan_struct_setup(vulkan_ce_VkMemoryGetFdInfoKHR);
	vulkan_ce_VkImageDrmFormatModifierListCreateInfoEXT = register_class_VkImageDrmFormatModifierListCreateInfoEXT();
	vulkan_struct_setup(vulkan_ce_VkImageDrmFormatModifierListCreateInfoEXT);
	vulkan_ce_VkImageDrmFormatModifierPropertiesEXT = register_class_VkImageDrmFormatModifierPropertiesEXT();
	vulkan_struct_setup(vulkan_ce_VkImageDrmFormatModifierPropertiesEXT);
	vulkan_ce_VkImageSubresource = register_class_VkImageSubresource();
	vulkan_struct_setup(vulkan_ce_VkImageSubresource);
	vulkan_ce_VkSubresourceLayout = register_class_VkSubresourceLayout();
	vulkan_struct_setup(vulkan_ce_VkSubresourceLayout);
}

ZEND_FUNCTION(vkGetMemoryFdKHR)
{
	zval *device, *info, *out;
	uint64_t device_value;
	VkMemoryGetFdInfoKHR get_info;
	PFN_vkGetMemoryFdKHR get_fd;
	int fd = -1;
	VkResult result;
	zval boxed;
	vulkan_scratch scratch;

	ZEND_PARSE_PARAMETERS_START(3, 3) Z_PARAM_OBJECT(device) Z_PARAM_OBJECT(info) Z_PARAM_ZVAL(out) ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_handle_value(device, vulkan_ce_VkDevice, 1, &device_value)) RETURN_THROWS();
	get_fd = (PFN_vkGetMemoryFdKHR) vkGetDeviceProcAddr((VkDevice) (uintptr_t) device_value, "vkGetMemoryFdKHR");
	if (get_fd == NULL) {
		ZVAL_NULL(&boxed);
		vulkan_assign(out, &boxed);
		RETURN_LONG((zend_long) VK_ERROR_EXTENSION_NOT_PRESENT);
	}
	vulkan_scratch_init(&scratch);
	if (!vulkan_in(info, vulkan_ce_VkMemoryGetFdInfoKHR, vk_VkMemoryGetFdInfoKHR_from, &get_info, &scratch)) {
		vulkan_scratch_free(&scratch);
		RETURN_THROWS();
	}
	result = get_fd((VkDevice) (uintptr_t) device_value, &get_info, &fd);
	vulkan_scratch_free(&scratch);
	if (result == VK_SUCCESS) ZVAL_LONG(&boxed, fd);
	else ZVAL_NULL(&boxed);
	vulkan_assign(out, &boxed);
	RETURN_LONG((zend_long) result);
}

ZEND_FUNCTION(vkGetImageDrmFormatModifierPropertiesEXT)
{
	zval *device, *image, *out;
	uint64_t device_value, image_value;
	PFN_vkGetImageDrmFormatModifierPropertiesEXT get_props;
	VkImageDrmFormatModifierPropertiesEXT props;
	VkResult result;
	zval boxed;

	ZEND_PARSE_PARAMETERS_START(3, 3) Z_PARAM_OBJECT(device) Z_PARAM_OBJECT(image) Z_PARAM_ZVAL(out) ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_handle_value(device, vulkan_ce_VkDevice, 1, &device_value) || !vulkan_handle_value(image, vulkan_ce_VkImage, 2, &image_value)) RETURN_THROWS();
	get_props = (PFN_vkGetImageDrmFormatModifierPropertiesEXT) vkGetDeviceProcAddr((VkDevice) (uintptr_t) device_value, "vkGetImageDrmFormatModifierPropertiesEXT");
	if (get_props == NULL) {
		ZVAL_NULL(&boxed);
		vulkan_assign(out, &boxed);
		RETURN_LONG((zend_long) VK_ERROR_EXTENSION_NOT_PRESENT);
	}
	memset(&props, 0, sizeof(props));
	props.sType = VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_PROPERTIES_EXT;
	result = get_props((VkDevice) (uintptr_t) device_value, (VkImage) (uintptr_t) image_value, &props);
	if (result == VK_SUCCESS) vk_VkImageDrmFormatModifierPropertiesEXT_to(&props, &boxed);
	else ZVAL_NULL(&boxed);
	vulkan_assign(out, &boxed);
	RETURN_LONG((zend_long) result);
}

ZEND_FUNCTION(vkGetImageSubresourceLayout)
{
	zval *device, *image, *subresource, *out;
	uint64_t device_value, image_value;
	VkImageSubresource native;
	VkSubresourceLayout layout;
	vulkan_scratch scratch;
	zval boxed;

	ZEND_PARSE_PARAMETERS_START(4, 4) Z_PARAM_OBJECT(device) Z_PARAM_OBJECT(image) Z_PARAM_OBJECT(subresource) Z_PARAM_ZVAL(out) ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_handle_value(device, vulkan_ce_VkDevice, 1, &device_value) || !vulkan_handle_value(image, vulkan_ce_VkImage, 2, &image_value)) RETURN_THROWS();
	vulkan_scratch_init(&scratch);
	if (!vulkan_in(subresource, vulkan_ce_VkImageSubresource, vk_VkImageSubresource_from, &native, &scratch)) {
		vulkan_scratch_free(&scratch);
		RETURN_THROWS();
	}
	vkGetImageSubresourceLayout((VkDevice) (uintptr_t) device_value, (VkImage) (uintptr_t) image_value, &native, &layout);
	vulkan_scratch_free(&scratch);
	vk_VkSubresourceLayout_to(&layout, &boxed);
	vulkan_assign(out, &boxed);
}
