#include "runtime.h"
#include "structs.h"
#include "../stubs/vk_surface_arginfo.h"

VULKAN_HANDLE_METHODS(VkSurfaceKHR)
VULKAN_HANDLE_METHODS(VkSwapchainKHR)

ZEND_METHOD(VkSurfaceCapabilitiesKHR, __construct)
{
	ZEND_PARSE_PARAMETERS_NONE();
	vulkan_init_nested(Z_OBJ_P(ZEND_THIS), "currentExtent", vulkan_ce_VkExtent2D);
	vulkan_init_nested(Z_OBJ_P(ZEND_THIS), "minImageExtent", vulkan_ce_VkExtent2D);
	vulkan_init_nested(Z_OBJ_P(ZEND_THIS), "maxImageExtent", vulkan_ce_VkExtent2D);
}

ZEND_METHOD(VkSwapchainCreateInfoKHR, __construct)
{
	ZEND_PARSE_PARAMETERS_NONE();
	vulkan_init_nested(Z_OBJ_P(ZEND_THIS), "imageExtent", vulkan_ce_VkExtent2D);
}

ZEND_METHOD(VkRectLayerKHR, __construct)
{
	ZEND_PARSE_PARAMETERS_NONE();
	vulkan_init_nested(Z_OBJ_P(ZEND_THIS), "offset", vulkan_ce_VkOffset2D);
	vulkan_init_nested(Z_OBJ_P(ZEND_THIS), "extent", vulkan_ce_VkExtent2D);
}

ZEND_METHOD(VkHdrMetadataEXT, __construct)
{
	ZEND_PARSE_PARAMETERS_NONE();
	vulkan_init_nested(Z_OBJ_P(ZEND_THIS), "displayPrimaryRed", vulkan_ce_VkXYColorEXT);
	vulkan_init_nested(Z_OBJ_P(ZEND_THIS), "displayPrimaryGreen", vulkan_ce_VkXYColorEXT);
	vulkan_init_nested(Z_OBJ_P(ZEND_THIS), "displayPrimaryBlue", vulkan_ce_VkXYColorEXT);
	vulkan_init_nested(Z_OBJ_P(ZEND_THIS), "whitePoint", vulkan_ce_VkXYColorEXT);
}

void vulkan_register_surface(int module_number)
{
	(void) module_number;
	zend_register_functions(NULL, ext_functions, NULL, MODULE_PERSISTENT);
	vulkan_ce_VkSurfaceKHR = register_class_VkSurfaceKHR();
	vulkan_handle_setup(vulkan_ce_VkSurfaceKHR);
	vulkan_ce_VkSwapchainKHR = register_class_VkSwapchainKHR();
	vulkan_handle_setup(vulkan_ce_VkSwapchainKHR);
	vulkan_ce_VkSurfaceFormatKHR = register_class_VkSurfaceFormatKHR();
	vulkan_struct_setup(vulkan_ce_VkSurfaceFormatKHR);
	vulkan_ce_VkSurfaceCapabilitiesKHR = register_class_VkSurfaceCapabilitiesKHR();
	vulkan_struct_setup(vulkan_ce_VkSurfaceCapabilitiesKHR);
	vulkan_ce_VkSwapchainCreateInfoKHR = register_class_VkSwapchainCreateInfoKHR();
	vulkan_struct_setup(vulkan_ce_VkSwapchainCreateInfoKHR);
	vulkan_ce_VkPresentInfoKHR = register_class_VkPresentInfoKHR();
	vulkan_struct_setup(vulkan_ce_VkPresentInfoKHR);
	vulkan_ce_VkRectLayerKHR = register_class_VkRectLayerKHR();
	vulkan_struct_setup(vulkan_ce_VkRectLayerKHR);
	vulkan_ce_VkPresentRegionKHR = register_class_VkPresentRegionKHR();
	vulkan_struct_setup(vulkan_ce_VkPresentRegionKHR);
	vulkan_ce_VkPresentRegionsKHR = register_class_VkPresentRegionsKHR();
	vulkan_struct_setup(vulkan_ce_VkPresentRegionsKHR);
	vulkan_ce_VkPresentIdKHR = register_class_VkPresentIdKHR();
	vulkan_struct_setup(vulkan_ce_VkPresentIdKHR);
	vulkan_ce_VkPhysicalDevicePresentIdFeaturesKHR = register_class_VkPhysicalDevicePresentIdFeaturesKHR();
	vulkan_struct_setup(vulkan_ce_VkPhysicalDevicePresentIdFeaturesKHR);
	vulkan_ce_VkPhysicalDevicePresentWaitFeaturesKHR = register_class_VkPhysicalDevicePresentWaitFeaturesKHR();
	vulkan_struct_setup(vulkan_ce_VkPhysicalDevicePresentWaitFeaturesKHR);
	vulkan_ce_VkXYColorEXT = register_class_VkXYColorEXT();
	vulkan_struct_setup(vulkan_ce_VkXYColorEXT);
	vulkan_ce_VkHdrMetadataEXT = register_class_VkHdrMetadataEXT();
	vulkan_struct_setup(vulkan_ce_VkHdrMetadataEXT);
}

ZEND_FUNCTION(vkGetPhysicalDeviceSurfaceSupportKHR)
{
	zval *physical, *surface, *out;
	zend_long family;
	uint64_t physical_value, surface_value;
	VkBool32 supported = VK_FALSE;
	VkResult result;
	zval boxed;
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT(physical) Z_PARAM_LONG(family) Z_PARAM_OBJECT(surface) Z_PARAM_ZVAL(out)
	ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_handle_value(physical, vulkan_ce_VkPhysicalDevice, 1, &physical_value) || !vulkan_handle_value(surface, vulkan_ce_VkSurfaceKHR, 3, &surface_value)) RETURN_THROWS();
	result = vkGetPhysicalDeviceSurfaceSupportKHR((VkPhysicalDevice) (uintptr_t) physical_value, (uint32_t) family, (VkSurfaceKHR) (uintptr_t) surface_value, &supported);
	ZVAL_BOOL(&boxed, supported == VK_TRUE);
	vulkan_assign(out, &boxed);
	RETURN_LONG((zend_long) result);
}

ZEND_FUNCTION(vkGetPhysicalDeviceSurfaceCapabilitiesKHR)
{
	zval *physical, *surface, *out;
	uint64_t physical_value, surface_value;
	VkSurfaceCapabilitiesKHR caps;
	VkResult result;
	zval boxed;
	ZEND_PARSE_PARAMETERS_START(3, 3) Z_PARAM_OBJECT(physical) Z_PARAM_OBJECT(surface) Z_PARAM_ZVAL(out) ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_handle_value(physical, vulkan_ce_VkPhysicalDevice, 1, &physical_value) || !vulkan_handle_value(surface, vulkan_ce_VkSurfaceKHR, 2, &surface_value)) RETURN_THROWS();
	result = vkGetPhysicalDeviceSurfaceCapabilitiesKHR((VkPhysicalDevice) (uintptr_t) physical_value, (VkSurfaceKHR) (uintptr_t) surface_value, &caps);
	if (result == VK_SUCCESS) vk_VkSurfaceCapabilitiesKHR_to(&caps, &boxed);
	else ZVAL_NULL(&boxed);
	vulkan_assign(out, &boxed);
	RETURN_LONG((zend_long) result);
}

#define ALLOCATOR(z) ((const VkAllocationCallbacks *) (uintptr_t) (z))

ZEND_FUNCTION(vkGetPhysicalDeviceSurfaceFormatsKHR)
{
	zval *physical, *surface, *count, *out;
	uint64_t physical_value, surface_value;
	VkSurfaceFormatKHR *items = NULL;
	uint32_t n, i;
	bool want;
	VkResult result;
	zval arr, item;
	ZEND_PARSE_PARAMETERS_START(4, 4) Z_PARAM_OBJECT(physical) Z_PARAM_OBJECT(surface) Z_PARAM_ZVAL(count) Z_PARAM_ZVAL(out) ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_handle_value(physical, vulkan_ce_VkPhysicalDevice, 1, &physical_value) || !vulkan_handle_value(surface, vulkan_ce_VkSurfaceKHR, 2, &surface_value)) RETURN_THROWS();
	want = vulkan_enum_in(count, out, &n);
	if (want) items = safe_emalloc(n ? n : 1, sizeof(*items), 0);
	result = vkGetPhysicalDeviceSurfaceFormatsKHR((VkPhysicalDevice) (uintptr_t) physical_value, (VkSurfaceKHR) (uintptr_t) surface_value, &n, items);
	vulkan_enum_count_out(count, n);
	if (want) {
		if (result < 0) n = 0;
		array_init_size(&arr, n);
		for (i = 0; i < n; i++) {
			vk_VkSurfaceFormatKHR_to(&items[i], &item);
			zend_hash_next_index_insert(Z_ARRVAL(arr), &item);
		}
		efree(items);
		vulkan_assign(out, &arr);
	}
	RETURN_LONG((zend_long) result);
}

ZEND_FUNCTION(vkGetPhysicalDeviceSurfacePresentModesKHR)
{
	zval *physical, *surface, *count, *out;
	uint64_t physical_value, surface_value;
	VkPresentModeKHR *items = NULL;
	uint32_t n, i;
	bool want;
	VkResult result;
	zval arr, item;
	ZEND_PARSE_PARAMETERS_START(4, 4) Z_PARAM_OBJECT(physical) Z_PARAM_OBJECT(surface) Z_PARAM_ZVAL(count) Z_PARAM_ZVAL(out) ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_handle_value(physical, vulkan_ce_VkPhysicalDevice, 1, &physical_value) || !vulkan_handle_value(surface, vulkan_ce_VkSurfaceKHR, 2, &surface_value)) RETURN_THROWS();
	want = vulkan_enum_in(count, out, &n);
	if (want) items = safe_emalloc(n ? n : 1, sizeof(*items), 0);
	result = vkGetPhysicalDeviceSurfacePresentModesKHR((VkPhysicalDevice) (uintptr_t) physical_value, (VkSurfaceKHR) (uintptr_t) surface_value, &n, items);
	vulkan_enum_count_out(count, n);
	if (want) {
		if (result < 0) n = 0;
		array_init_size(&arr, n);
		for (i = 0; i < n; i++) {
			ZVAL_LONG(&item, (zend_long) items[i]);
			zend_hash_next_index_insert(Z_ARRVAL(arr), &item);
		}
		efree(items);
		vulkan_assign(out, &arr);
	}
	RETURN_LONG((zend_long) result);
}

ZEND_FUNCTION(vkCreateSwapchainKHR)
{
	zval *device, *info, *out;
	zend_long allocator;
	uint64_t device_value;
	VkSwapchainCreateInfoKHR create;
	VkSwapchainKHR swapchain = VK_NULL_HANDLE;
	vulkan_scratch scratch;
	VkResult result;
	zval boxed;
	ZEND_PARSE_PARAMETERS_START(4, 4) Z_PARAM_OBJECT(device) Z_PARAM_OBJECT(info) Z_PARAM_LONG(allocator) Z_PARAM_ZVAL(out) ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_handle_value(device, vulkan_ce_VkDevice, 1, &device_value)) RETURN_THROWS();
	vulkan_scratch_init(&scratch);
	if (!vulkan_arg_struct(info, vulkan_ce_VkSwapchainCreateInfoKHR, vk_VkSwapchainCreateInfoKHR_from, &create, &scratch)) { vulkan_scratch_free(&scratch); RETURN_THROWS(); }
	result = vkCreateSwapchainKHR((VkDevice) (uintptr_t) device_value, &create, ALLOCATOR(allocator), &swapchain);
	vulkan_scratch_free(&scratch);
	if (result == VK_SUCCESS) vulkan_box(&boxed, (uint64_t) (uintptr_t) swapchain, vulkan_ce_VkSwapchainKHR, Z_OBJ_P(device));
	else ZVAL_NULL(&boxed);
	vulkan_assign(out, &boxed);
	RETURN_LONG((zend_long) result);
}

ZEND_FUNCTION(vkDestroySwapchainKHR)
{
	zval *device, *swapchain;
	zend_long allocator;
	uint64_t device_value, swapchain_value = 0;
	ZEND_PARSE_PARAMETERS_START(3, 3) Z_PARAM_OBJECT(device) Z_PARAM_OBJECT_OR_NULL(swapchain) Z_PARAM_LONG(allocator) ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_handle_value(device, vulkan_ce_VkDevice, 1, &device_value) || (swapchain && !vulkan_handle_value(swapchain, vulkan_ce_VkSwapchainKHR, 2, &swapchain_value))) RETURN_THROWS();
	vkDestroySwapchainKHR((VkDevice) (uintptr_t) device_value, (VkSwapchainKHR) (uintptr_t) swapchain_value, ALLOCATOR(allocator));
	if (swapchain) vulkan_release_tree(Z_OBJ_P(swapchain));
}

ZEND_FUNCTION(vkGetSwapchainImagesKHR)
{
	zval *device, *swapchain, *count, *out;
	uint64_t device_value, swapchain_value;
	VkImage *items = NULL;
	uint32_t n, i;
	bool want;
	VkResult result;
	zval arr, boxed;
	ZEND_PARSE_PARAMETERS_START(4, 4) Z_PARAM_OBJECT(device) Z_PARAM_OBJECT(swapchain) Z_PARAM_ZVAL(count) Z_PARAM_ZVAL(out) ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_handle_value(device, vulkan_ce_VkDevice, 1, &device_value) || !vulkan_handle_value(swapchain, vulkan_ce_VkSwapchainKHR, 2, &swapchain_value)) RETURN_THROWS();
	want = vulkan_enum_in(count, out, &n);
	if (want) items = safe_emalloc(n ? n : 1, sizeof(*items), 0);
	result = vkGetSwapchainImagesKHR((VkDevice) (uintptr_t) device_value, (VkSwapchainKHR) (uintptr_t) swapchain_value, &n, items);
	vulkan_enum_count_out(count, n);
	if (want) {
		if (result < 0) n = 0;
		array_init_size(&arr, n);
		for (i = 0; i < n; i++) {
			vulkan_box(&boxed, (uint64_t) (uintptr_t) items[i], vulkan_ce_VkImage, Z_OBJ_P(swapchain));
			zend_hash_next_index_insert(Z_ARRVAL(arr), &boxed);
		}
		efree(items);
		vulkan_assign(out, &arr);
	}
	RETURN_LONG((zend_long) result);
}

ZEND_FUNCTION(vkAcquireNextImageKHR)
{
	zval *device, *swapchain, *semaphore, *fence, *out;
	zend_long timeout;
	uint64_t device_value, swapchain_value, semaphore_value = 0, fence_value = 0;
	uint32_t index = 0;
	VkResult result;
	zval boxed;
	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_OBJECT(device) Z_PARAM_OBJECT(swapchain) Z_PARAM_LONG(timeout) Z_PARAM_OBJECT_OR_NULL(semaphore) Z_PARAM_OBJECT_OR_NULL(fence) Z_PARAM_ZVAL(out)
	ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_handle_value(device, vulkan_ce_VkDevice, 1, &device_value) || !vulkan_handle_value(swapchain, vulkan_ce_VkSwapchainKHR, 2, &swapchain_value)) RETURN_THROWS();
	if (semaphore && !vulkan_handle_value(semaphore, vulkan_ce_VkSemaphore, 4, &semaphore_value)) RETURN_THROWS();
	if (fence && !vulkan_handle_value(fence, vulkan_ce_VkFence, 5, &fence_value)) RETURN_THROWS();
	result = vkAcquireNextImageKHR((VkDevice) (uintptr_t) device_value, (VkSwapchainKHR) (uintptr_t) swapchain_value, (uint64_t) timeout, (VkSemaphore) (uintptr_t) semaphore_value, (VkFence) (uintptr_t) fence_value, &index);
	ZVAL_LONG(&boxed, (zend_long) index);
	vulkan_assign(out, &boxed);
	RETURN_LONG((zend_long) result);
}

ZEND_FUNCTION(vkQueuePresentKHR)
{
	zval *queue, *info;
	uint64_t queue_value;
	VkPresentInfoKHR present;
	vulkan_scratch scratch;
	VkResult result;
	ZEND_PARSE_PARAMETERS_START(2, 2) Z_PARAM_OBJECT(queue) Z_PARAM_OBJECT(info) ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_handle_value(queue, vulkan_ce_VkQueue, 1, &queue_value)) RETURN_THROWS();
	vulkan_scratch_init(&scratch);
	if (!vulkan_arg_struct(info, vulkan_ce_VkPresentInfoKHR, vk_VkPresentInfoKHR_from, &present, &scratch)) { vulkan_scratch_free(&scratch); RETURN_THROWS(); }
	result = vkQueuePresentKHR((VkQueue) (uintptr_t) queue_value, &present);
	vulkan_scratch_free(&scratch);
	RETURN_LONG((zend_long) result);
}

ZEND_FUNCTION(vkDestroySurfaceKHR)
{
	zval *instance, *surface;
	zend_long allocator;
	uint64_t instance_value, surface_value = 0;
	ZEND_PARSE_PARAMETERS_START(3, 3) Z_PARAM_OBJECT(instance) Z_PARAM_OBJECT_OR_NULL(surface) Z_PARAM_LONG(allocator) ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_handle_value(instance, vulkan_ce_VkInstance, 1, &instance_value) || (surface && !vulkan_handle_value(surface, vulkan_ce_VkSurfaceKHR, 2, &surface_value))) RETURN_THROWS();
	vkDestroySurfaceKHR((VkInstance) (uintptr_t) instance_value, (VkSurfaceKHR) (uintptr_t) surface_value, ALLOCATOR(allocator));
	if (surface) vulkan_release_tree(Z_OBJ_P(surface));
}
ZEND_FUNCTION(vkWaitForPresentKHR)
{
	zval *device, *swapchain;
	zend_long present_id, timeout;
	uint64_t device_value, swapchain_value;
	PFN_vkWaitForPresentKHR wait;

	ZEND_PARSE_PARAMETERS_START(4, 4) Z_PARAM_OBJECT(device) Z_PARAM_OBJECT(swapchain) Z_PARAM_LONG(present_id) Z_PARAM_LONG(timeout) ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_handle_value(device, vulkan_ce_VkDevice, 1, &device_value) || !vulkan_handle_value(swapchain, vulkan_ce_VkSwapchainKHR, 2, &swapchain_value)) RETURN_THROWS();
	wait = (PFN_vkWaitForPresentKHR) vkGetDeviceProcAddr((VkDevice) (uintptr_t) device_value, "vkWaitForPresentKHR");
	if (!vulkan_proc((void (*)(void)) wait, "vkWaitForPresentKHR")) RETURN_THROWS();
	RETURN_LONG((zend_long) wait((VkDevice) (uintptr_t) device_value, (VkSwapchainKHR) (uintptr_t) swapchain_value, (uint64_t) present_id, (uint64_t) timeout));
}


ZEND_FUNCTION(vkSetHdrMetadataEXT)
{
	zval *device, *swapchains, *metadata;
	zend_long count;
	uint64_t device_value, *chains;
	void *metas;
	PFN_vkSetHdrMetadataEXT set;
	vulkan_scratch scratch;

	ZEND_PARSE_PARAMETERS_START(4, 4) Z_PARAM_OBJECT(device) Z_PARAM_LONG(count) Z_PARAM_ZVAL(swapchains) Z_PARAM_ZVAL(metadata) ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_handle_value(device, vulkan_ce_VkDevice, 1, &device_value)) RETURN_THROWS();
	set = (PFN_vkSetHdrMetadataEXT) vkGetDeviceProcAddr((VkDevice) (uintptr_t) device_value, "vkSetHdrMetadataEXT");
	if (!vulkan_proc((void (*)(void)) set, "vkSetHdrMetadataEXT")) RETURN_THROWS();
	vulkan_scratch_init(&scratch);
	if (!vulkan_arg_handles(swapchains, count, 2, 3, vulkan_ce_VkSwapchainKHR, &chains, &scratch)
		|| !vulkan_arg_structs(metadata, count, 2, 4, vulkan_ce_VkHdrMetadataEXT, sizeof(VkHdrMetadataEXT), vk_VkHdrMetadataEXT_from, &metas, &scratch)) {
		vulkan_scratch_free(&scratch);
		RETURN_THROWS();
	}
	set((VkDevice) (uintptr_t) device_value, (uint32_t) count, (const VkSwapchainKHR *) chains, metas);
	vulkan_scratch_free(&scratch);
}
