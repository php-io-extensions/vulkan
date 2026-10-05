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

static VkResult vulkan_enumerate(uint32_t *count, void **items, size_t elem, VkResult (*call)(uint32_t *count, void *data, void *ctx), void *ctx)
{
	VkResult result;
	int spins = 0;
	*items = NULL;
	do {
		uint32_t probe = 0;
		result = call(&probe, NULL, ctx);
		if (result < 0) return result;
		if (*items) efree(*items);
		*items = probe ? emalloc(elem * probe) : NULL;
		*count = probe;
		result = call(count, *items, ctx);
		spins++;
	} while (result == VK_INCOMPLETE && spins < 8);
	return result;
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

typedef struct { VkPhysicalDevice physical; VkSurfaceKHR surface; } vulkan_surface_query;

static VkResult query_formats(uint32_t *count, void *data, void *ctx)
{
	vulkan_surface_query *query = ctx;
	return vkGetPhysicalDeviceSurfaceFormatsKHR(query->physical, query->surface, count, data);
}
static VkResult query_modes(uint32_t *count, void *data, void *ctx)
{
	vulkan_surface_query *query = ctx;
	return vkGetPhysicalDeviceSurfacePresentModesKHR(query->physical, query->surface, count, data);
}
static VkResult query_images(uint32_t *count, void *data, void *ctx)
{
	VkDevice *device = ((void **) ctx)[0];
	VkSwapchainKHR *swapchain = ((void **) ctx)[1];
	return vkGetSwapchainImagesKHR(*device, *swapchain, count, data);
}

ZEND_FUNCTION(vkGetPhysicalDeviceSurfaceFormatsKHR)
{
	zval *physical, *surface, *out;
	uint64_t physical_value, surface_value;
	vulkan_surface_query query;
	VkSurfaceFormatKHR *items = NULL;
	uint32_t count = 0;
	VkResult result;
	zval arr, item;
	uint32_t i;
	ZEND_PARSE_PARAMETERS_START(3, 3) Z_PARAM_OBJECT(physical) Z_PARAM_OBJECT(surface) Z_PARAM_ZVAL(out) ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_handle_value(physical, vulkan_ce_VkPhysicalDevice, 1, &physical_value) || !vulkan_handle_value(surface, vulkan_ce_VkSurfaceKHR, 2, &surface_value)) RETURN_THROWS();
	query.physical = (VkPhysicalDevice) (uintptr_t) physical_value;
	query.surface = (VkSurfaceKHR) (uintptr_t) surface_value;
	result = vulkan_enumerate(&count, (void **) &items, sizeof(*items), query_formats, &query);
	if (result < 0) { if (items) efree(items); RETURN_LONG((zend_long) result); }
	array_init_size(&arr, count);
	for (i = 0; i < count; i++) {
		vk_VkSurfaceFormatKHR_to(&items[i], &item);
		zend_hash_next_index_insert(Z_ARRVAL(arr), &item);
	}
	if (items) efree(items);
	vulkan_assign(out, &arr);
	RETURN_LONG((zend_long) result);
}

ZEND_FUNCTION(vkGetPhysicalDeviceSurfacePresentModesKHR)
{
	zval *physical, *surface, *out;
	uint64_t physical_value, surface_value;
	vulkan_surface_query query;
	VkPresentModeKHR *items = NULL;
	uint32_t count = 0, i;
	VkResult result;
	zval arr, item;
	ZEND_PARSE_PARAMETERS_START(3, 3) Z_PARAM_OBJECT(physical) Z_PARAM_OBJECT(surface) Z_PARAM_ZVAL(out) ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_handle_value(physical, vulkan_ce_VkPhysicalDevice, 1, &physical_value) || !vulkan_handle_value(surface, vulkan_ce_VkSurfaceKHR, 2, &surface_value)) RETURN_THROWS();
	query.physical = (VkPhysicalDevice) (uintptr_t) physical_value;
	query.surface = (VkSurfaceKHR) (uintptr_t) surface_value;
	result = vulkan_enumerate(&count, (void **) &items, sizeof(*items), query_modes, &query);
	if (result < 0) { if (items) efree(items); RETURN_LONG((zend_long) result); }
	array_init_size(&arr, count);
	for (i = 0; i < count; i++) {
		ZVAL_LONG(&item, (zend_long) items[i]);
		zend_hash_next_index_insert(Z_ARRVAL(arr), &item);
	}
	if (items) efree(items);
	vulkan_assign(out, &arr);
	RETURN_LONG((zend_long) result);
}

ZEND_FUNCTION(vkCreateSwapchainKHR)
{
	zval *device, *info, *allocator, *out;
	uint64_t device_value;
	VkSwapchainCreateInfoKHR create;
	VkSwapchainKHR swapchain = VK_NULL_HANDLE;
	vulkan_scratch scratch;
	VkResult result;
	zval boxed;
	ZEND_PARSE_PARAMETERS_START(4, 4) Z_PARAM_OBJECT(device) Z_PARAM_OBJECT(info) Z_PARAM_ZVAL(allocator) Z_PARAM_ZVAL(out) ZEND_PARSE_PARAMETERS_END();
	if (Z_TYPE_P(allocator) != IS_NULL) { zend_argument_type_error(3, "must be null"); RETURN_THROWS(); }
	if (!vulkan_handle_value(device, vulkan_ce_VkDevice, 1, &device_value)) RETURN_THROWS();
	vulkan_scratch_init(&scratch);
	if (!vulkan_in(info, vulkan_ce_VkSwapchainCreateInfoKHR, vk_VkSwapchainCreateInfoKHR_from, &create, &scratch)) { vulkan_scratch_free(&scratch); RETURN_THROWS(); }
	result = vkCreateSwapchainKHR((VkDevice) (uintptr_t) device_value, &create, NULL, &swapchain);
	vulkan_scratch_free(&scratch);
	if (result == VK_SUCCESS) vulkan_box(&boxed, (uint64_t) (uintptr_t) swapchain, vulkan_ce_VkSwapchainKHR, Z_OBJ_P(device));
	else ZVAL_NULL(&boxed);
	vulkan_assign(out, &boxed);
	RETURN_LONG((zend_long) result);
}

ZEND_FUNCTION(vkDestroySwapchainKHR)
{
	zval *device, *swapchain, *allocator;
	uint64_t device_value, swapchain_value;
	ZEND_PARSE_PARAMETERS_START(3, 3) Z_PARAM_OBJECT(device) Z_PARAM_OBJECT(swapchain) Z_PARAM_ZVAL(allocator) ZEND_PARSE_PARAMETERS_END();
	if (Z_TYPE_P(allocator) != IS_NULL) { zend_argument_type_error(3, "must be null"); RETURN_THROWS(); }
	if (!vulkan_handle_value(device, vulkan_ce_VkDevice, 1, &device_value) || !vulkan_handle_value(swapchain, vulkan_ce_VkSwapchainKHR, 2, &swapchain_value)) RETURN_THROWS();
	vkDestroySwapchainKHR((VkDevice) (uintptr_t) device_value, (VkSwapchainKHR) (uintptr_t) swapchain_value, NULL);
	vulkan_release_tree(Z_OBJ_P(swapchain));
}

ZEND_FUNCTION(vkGetSwapchainImagesKHR)
{
	zval *device, *swapchain, *out;
	uint64_t device_value, swapchain_value;
	VkDevice device_handle;
	VkSwapchainKHR swapchain_handle;
	void *ctx[2];
	VkImage *items = NULL;
	uint32_t count = 0, i;
	VkResult result;
	zval arr, boxed;
	ZEND_PARSE_PARAMETERS_START(3, 3) Z_PARAM_OBJECT(device) Z_PARAM_OBJECT(swapchain) Z_PARAM_ZVAL(out) ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_handle_value(device, vulkan_ce_VkDevice, 1, &device_value) || !vulkan_handle_value(swapchain, vulkan_ce_VkSwapchainKHR, 2, &swapchain_value)) RETURN_THROWS();
	device_handle = (VkDevice) (uintptr_t) device_value;
	swapchain_handle = (VkSwapchainKHR) (uintptr_t) swapchain_value;
	ctx[0] = &device_handle;
	ctx[1] = &swapchain_handle;
	result = vulkan_enumerate(&count, (void **) &items, sizeof(*items), query_images, ctx);
	if (result < 0) { if (items) efree(items); RETURN_LONG((zend_long) result); }
	array_init_size(&arr, count);
	for (i = 0; i < count; i++) {
		vulkan_box(&boxed, (uint64_t) (uintptr_t) items[i], vulkan_ce_VkImage, Z_OBJ_P(swapchain));
		zend_hash_next_index_insert(Z_ARRVAL(arr), &boxed);
	}
	if (items) efree(items);
	vulkan_assign(out, &arr);
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
		Z_PARAM_OBJECT(device) Z_PARAM_OBJECT(swapchain) Z_PARAM_LONG(timeout) Z_PARAM_ZVAL(semaphore) Z_PARAM_ZVAL(fence) Z_PARAM_ZVAL(out)
	ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_handle_value(device, vulkan_ce_VkDevice, 1, &device_value) || !vulkan_handle_value(swapchain, vulkan_ce_VkSwapchainKHR, 2, &swapchain_value)) RETURN_THROWS();
	if (Z_TYPE_P(semaphore) != IS_NULL && !vulkan_handle_value(semaphore, vulkan_ce_VkSemaphore, 4, &semaphore_value)) RETURN_THROWS();
	if (Z_TYPE_P(fence) != IS_NULL && !vulkan_handle_value(fence, vulkan_ce_VkFence, 5, &fence_value)) RETURN_THROWS();
	result = vkAcquireNextImageKHR((VkDevice) (uintptr_t) device_value, (VkSwapchainKHR) (uintptr_t) swapchain_value, (uint64_t) timeout, (VkSemaphore) (uintptr_t) semaphore_value, (VkFence) (uintptr_t) fence_value, &index);
	if (result == VK_SUCCESS || result == VK_SUBOPTIMAL_KHR) ZVAL_LONG(&boxed, (zend_long) index);
	else ZVAL_NULL(&boxed);
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
	if (!vulkan_in(info, vulkan_ce_VkPresentInfoKHR, vk_VkPresentInfoKHR_from, &present, &scratch)) { vulkan_scratch_free(&scratch); RETURN_THROWS(); }
	result = vkQueuePresentKHR((VkQueue) (uintptr_t) queue_value, &present);
	vulkan_scratch_free(&scratch);
	RETURN_LONG((zend_long) result);
}

ZEND_FUNCTION(vkDestroySurfaceKHR)
{
	zval *instance, *surface, *allocator;
	uint64_t instance_value, surface_value;
	ZEND_PARSE_PARAMETERS_START(3, 3) Z_PARAM_OBJECT(instance) Z_PARAM_OBJECT(surface) Z_PARAM_ZVAL(allocator) ZEND_PARSE_PARAMETERS_END();
	if (Z_TYPE_P(allocator) != IS_NULL) { zend_argument_type_error(3, "must be null"); RETURN_THROWS(); }
	if (!vulkan_handle_value(instance, vulkan_ce_VkInstance, 1, &instance_value) || !vulkan_handle_value(surface, vulkan_ce_VkSurfaceKHR, 2, &surface_value)) RETURN_THROWS();
	vkDestroySurfaceKHR((VkInstance) (uintptr_t) instance_value, (VkSurfaceKHR) (uintptr_t) surface_value, NULL);
	vulkan_release_tree(Z_OBJ_P(surface));
}
