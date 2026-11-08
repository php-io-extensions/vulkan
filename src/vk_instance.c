#include "runtime.h"
#include "structs.h"
#include "../stubs/vk_instance_arginfo.h"

VULKAN_HANDLE_METHODS(VkInstance)
VULKAN_HANDLE_METHODS(VkPhysicalDevice)
VULKAN_HANDLE_METHODS(VkDevice)
VULKAN_HANDLE_METHODS(VkQueue)

#include "struct_ctors.inc"

static void vulkan_assign_handles(zval *out, const void *values, uint32_t count, size_t stride, zend_class_entry *ce, zend_object *parent)
{
	zval arr, item;
	uint32_t i;

	array_init_size(&arr, count);
	for (i = 0; i < count; i++) {
		uint64_t value = (uint64_t) (uintptr_t) (*(void *const *) ((const char *) values + (size_t) i * stride));
		vulkan_box(&item, value, ce, parent);
		zend_hash_next_index_insert(Z_ARRVAL(arr), &item);
	}
	vulkan_assign(out, &arr);
}

static void vulkan_assign_extension_list(zval *out, const VkExtensionProperties *items, uint32_t count)
{
	zval arr, item;
	uint32_t i;

	array_init_size(&arr, count);
	for (i = 0; i < count; i++) {
		vk_VkExtensionProperties_to(&items[i], &item);
		zend_hash_next_index_insert(Z_ARRVAL(arr), &item);
	}
	vulkan_assign(out, &arr);
}

static void vulkan_assign_families(zval *out, const VkQueueFamilyProperties *items, uint32_t count)
{
	zval arr, item;
	uint32_t i;

	array_init_size(&arr, count);
	for (i = 0; i < count; i++) {
		vk_VkQueueFamilyProperties_to(&items[i], &item);
		zend_hash_next_index_insert(Z_ARRVAL(arr), &item);
	}
	vulkan_assign(out, &arr);
}

void vulkan_register_instance(int module_number)
{
	(void) module_number;

	zend_register_functions(NULL, ext_functions, NULL, MODULE_PERSISTENT);

	vulkan_ce_VkInstance = register_class_VkInstance();
	vulkan_handle_setup(vulkan_ce_VkInstance);
	vulkan_ce_VkPhysicalDevice = register_class_VkPhysicalDevice();
	vulkan_handle_setup(vulkan_ce_VkPhysicalDevice);
	vulkan_ce_VkDevice = register_class_VkDevice();
	vulkan_handle_setup(vulkan_ce_VkDevice);
	vulkan_ce_VkQueue = register_class_VkQueue();
	vulkan_handle_setup(vulkan_ce_VkQueue);

	vulkan_ce_VkApplicationInfo = register_class_VkApplicationInfo();
	vulkan_struct_setup(vulkan_ce_VkApplicationInfo);
	vulkan_ce_VkInstanceCreateInfo = register_class_VkInstanceCreateInfo();
	vulkan_struct_setup(vulkan_ce_VkInstanceCreateInfo);
	vulkan_ce_VkDeviceQueueCreateInfo = register_class_VkDeviceQueueCreateInfo();
	vulkan_struct_setup(vulkan_ce_VkDeviceQueueCreateInfo);
	vulkan_ce_VkPhysicalDeviceFeatures = register_class_VkPhysicalDeviceFeatures();
	vulkan_struct_setup(vulkan_ce_VkPhysicalDeviceFeatures);
	vulkan_ce_VkPhysicalDeviceFeatures2 = register_class_VkPhysicalDeviceFeatures2();
	vulkan_struct_setup(vulkan_ce_VkPhysicalDeviceFeatures2);
	vulkan_ce_VkPhysicalDevicePortabilitySubsetFeaturesKHR = register_class_VkPhysicalDevicePortabilitySubsetFeaturesKHR();
	vulkan_struct_setup(vulkan_ce_VkPhysicalDevicePortabilitySubsetFeaturesKHR);
	vulkan_ce_VkDeviceCreateInfo = register_class_VkDeviceCreateInfo();
	vulkan_struct_setup(vulkan_ce_VkDeviceCreateInfo);
	vulkan_ce_VkPhysicalDeviceLimits = register_class_VkPhysicalDeviceLimits();
	vulkan_struct_setup(vulkan_ce_VkPhysicalDeviceLimits);
	vulkan_ce_VkPhysicalDeviceSparseProperties = register_class_VkPhysicalDeviceSparseProperties();
	vulkan_struct_setup(vulkan_ce_VkPhysicalDeviceSparseProperties);
	vulkan_ce_VkPhysicalDeviceProperties = register_class_VkPhysicalDeviceProperties();
	vulkan_struct_setup(vulkan_ce_VkPhysicalDeviceProperties);
	vulkan_ce_VkExtent3D = register_class_VkExtent3D();
	vulkan_struct_setup(vulkan_ce_VkExtent3D);
	vulkan_ce_VkQueueFamilyProperties = register_class_VkQueueFamilyProperties();
	vulkan_struct_setup(vulkan_ce_VkQueueFamilyProperties);
	vulkan_ce_VkMemoryType = register_class_VkMemoryType();
	vulkan_struct_setup(vulkan_ce_VkMemoryType);
	vulkan_ce_VkMemoryHeap = register_class_VkMemoryHeap();
	vulkan_struct_setup(vulkan_ce_VkMemoryHeap);
	vulkan_ce_VkPhysicalDeviceMemoryProperties = register_class_VkPhysicalDeviceMemoryProperties();
	vulkan_struct_setup(vulkan_ce_VkPhysicalDeviceMemoryProperties);
	vulkan_ce_VkFormatProperties = register_class_VkFormatProperties();
	vulkan_struct_setup(vulkan_ce_VkFormatProperties);
	vulkan_ce_VkExtensionProperties = register_class_VkExtensionProperties();
	vulkan_struct_setup(vulkan_ce_VkExtensionProperties);
}

#define ALLOCATOR(z) ((const VkAllocationCallbacks *) (uintptr_t) (z))

/* A dispatchable handle Vulkan may take as NULL (the destroys): a released one goes as NULL. */
static uint64_t vulkan_or_null(zval *zv)
{
	return zv == NULL ? 0 : vulkan_handle_from(Z_OBJ_P(zv))->value;
}

ZEND_FUNCTION(vkCreateInstance)
{
	zval *create_info, *out;
	zend_long allocator;
	VkInstanceCreateInfo info;
	VkInstance instance = VK_NULL_HANDLE;
	vulkan_scratch scratch;
	VkResult result;
	zval boxed;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(create_info, vulkan_ce_VkInstanceCreateInfo)
		Z_PARAM_LONG(allocator)
		Z_PARAM_ZVAL(out)
	ZEND_PARSE_PARAMETERS_END();

	vulkan_scratch_init(&scratch);
	if (!vulkan_arg_struct(create_info, vulkan_ce_VkInstanceCreateInfo, vk_VkInstanceCreateInfo_from, &info, &scratch)) {
		vulkan_scratch_free(&scratch);
		RETURN_THROWS();
	}

	result = vkCreateInstance(&info, ALLOCATOR(allocator), &instance);
	vulkan_scratch_free(&scratch);
	if (result == VK_SUCCESS) {
		vulkan_box(&boxed, (uint64_t) (uintptr_t) instance, vulkan_ce_VkInstance, NULL);
	} else {
		ZVAL_NULL(&boxed);
	}
	vulkan_assign(out, &boxed);
	RETURN_LONG((zend_long) result);
}

ZEND_FUNCTION(vkDestroyInstance)
{
	zval *instance;
	zend_long allocator;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(instance, vulkan_ce_VkInstance)
		Z_PARAM_LONG(allocator)
	ZEND_PARSE_PARAMETERS_END();

	vkDestroyInstance((VkInstance) (uintptr_t) vulkan_or_null(instance), ALLOCATOR(allocator));
	if (instance) {
		vulkan_release_tree(Z_OBJ_P(instance));
	}
}

ZEND_FUNCTION(vkEnumerateInstanceExtensionProperties)
{
	char *layer = NULL;
	size_t layer_len = 0;
	zval *count, *out;
	VkExtensionProperties *items = NULL;
	uint32_t n;
	bool want;
	VkResult result;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STRING_OR_NULL(layer, layer_len)
		Z_PARAM_ZVAL(count)
		Z_PARAM_ZVAL(out)
	ZEND_PARSE_PARAMETERS_END();

	(void) layer_len;
	want = vulkan_enum_in(count, out, &n);
	if (want) {
		items = safe_emalloc(n ? n : 1, sizeof(*items), 0);
	}
	result = vkEnumerateInstanceExtensionProperties(layer, &n, items);
	vulkan_enum_count_out(count, n);
	if (want) {
		vulkan_assign_extension_list(out, items, result < 0 ? 0 : n);
		efree(items);
	}
	RETURN_LONG((zend_long) result);
}

ZEND_FUNCTION(vkEnumeratePhysicalDevices)
{
	zval *instance, *count, *out;
	uint64_t value;
	VkPhysicalDevice *items = NULL;
	uint32_t n;
	bool want;
	VkResult result;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT(instance)
		Z_PARAM_ZVAL(count)
		Z_PARAM_ZVAL(out)
	ZEND_PARSE_PARAMETERS_END();

	if (!vulkan_handle_value(instance, vulkan_ce_VkInstance, 1, &value)) {
		RETURN_THROWS();
	}
	want = vulkan_enum_in(count, out, &n);
	if (want) {
		items = safe_emalloc(n ? n : 1, sizeof(*items), 0);
	}
	result = vkEnumeratePhysicalDevices((VkInstance) (uintptr_t) value, &n, items);
	vulkan_enum_count_out(count, n);
	if (want) {
		vulkan_assign_handles(out, items, result < 0 ? 0 : n, sizeof(VkPhysicalDevice), vulkan_ce_VkPhysicalDevice, Z_OBJ_P(instance));
		efree(items);
	}
	RETURN_LONG((zend_long) result);
}

ZEND_FUNCTION(vkGetPhysicalDeviceProperties)
{
	zval *physical, *out;
	uint64_t value;
	VkPhysicalDeviceProperties props;
	zval boxed;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT(physical)
		Z_PARAM_ZVAL(out)
	ZEND_PARSE_PARAMETERS_END();

	if (!vulkan_handle_value(physical, vulkan_ce_VkPhysicalDevice, 1, &value)) {
		RETURN_THROWS();
	}

	vkGetPhysicalDeviceProperties((VkPhysicalDevice) (uintptr_t) value, &props);
	vk_VkPhysicalDeviceProperties_to(&props, &boxed);
	vulkan_assign(out, &boxed);
}

ZEND_FUNCTION(vkGetPhysicalDeviceQueueFamilyProperties)
{
	zval *physical, *count, *out;
	uint64_t value;
	uint32_t n;
	bool want;
	VkQueueFamilyProperties *items = NULL;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT(physical)
		Z_PARAM_ZVAL(count)
		Z_PARAM_ZVAL(out)
	ZEND_PARSE_PARAMETERS_END();

	if (!vulkan_handle_value(physical, vulkan_ce_VkPhysicalDevice, 1, &value)) {
		RETURN_THROWS();
	}
	want = vulkan_enum_in(count, out, &n);
	if (want) {
		items = safe_emalloc(n ? n : 1, sizeof(*items), 0);
	}
	vkGetPhysicalDeviceQueueFamilyProperties((VkPhysicalDevice) (uintptr_t) value, &n, items);
	vulkan_enum_count_out(count, n);
	if (want) {
		vulkan_assign_families(out, items, n);
		efree(items);
	}
}

ZEND_FUNCTION(vkGetPhysicalDeviceMemoryProperties)
{
	zval *physical, *out;
	uint64_t value;
	VkPhysicalDeviceMemoryProperties props;
	zval boxed;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT(physical)
		Z_PARAM_ZVAL(out)
	ZEND_PARSE_PARAMETERS_END();

	if (!vulkan_handle_value(physical, vulkan_ce_VkPhysicalDevice, 1, &value)) {
		RETURN_THROWS();
	}

	vkGetPhysicalDeviceMemoryProperties((VkPhysicalDevice) (uintptr_t) value, &props);
	vk_VkPhysicalDeviceMemoryProperties_to(&props, &boxed);
	vulkan_assign(out, &boxed);
}

ZEND_FUNCTION(vkGetPhysicalDeviceFormatProperties)
{
	zval *physical, *out;
	zend_long format;
	uint64_t value;
	VkFormatProperties props;
	zval boxed;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT(physical)
		Z_PARAM_LONG(format)
		Z_PARAM_ZVAL(out)
	ZEND_PARSE_PARAMETERS_END();

	if (!vulkan_handle_value(physical, vulkan_ce_VkPhysicalDevice, 1, &value)) {
		RETURN_THROWS();
	}

	vkGetPhysicalDeviceFormatProperties((VkPhysicalDevice) (uintptr_t) value, (VkFormat) format, &props);
	vk_VkFormatProperties_to(&props, &boxed);
	vulkan_assign(out, &boxed);
}

ZEND_FUNCTION(vkEnumerateDeviceExtensionProperties)
{
	zval *physical, *count, *out;
	char *layer = NULL;
	size_t layer_len = 0;
	uint64_t value;
	VkExtensionProperties *items = NULL;
	uint32_t n;
	bool want;
	VkResult result;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT(physical)
		Z_PARAM_STRING_OR_NULL(layer, layer_len)
		Z_PARAM_ZVAL(count)
		Z_PARAM_ZVAL(out)
	ZEND_PARSE_PARAMETERS_END();

	(void) layer_len;
	if (!vulkan_handle_value(physical, vulkan_ce_VkPhysicalDevice, 1, &value)) {
		RETURN_THROWS();
	}
	want = vulkan_enum_in(count, out, &n);
	if (want) {
		items = safe_emalloc(n ? n : 1, sizeof(*items), 0);
	}
	result = vkEnumerateDeviceExtensionProperties((VkPhysicalDevice) (uintptr_t) value, layer, &n, items);
	vulkan_enum_count_out(count, n);
	if (want) {
		vulkan_assign_extension_list(out, items, result < 0 ? 0 : n);
		efree(items);
	}
	RETURN_LONG((zend_long) result);
}

ZEND_FUNCTION(vkCreateDevice)
{
	zval *physical, *create_info, *out;
	zend_long allocator;
	uint64_t value;
	VkDeviceCreateInfo info;
	VkDevice device = VK_NULL_HANDLE;
	vulkan_scratch scratch;
	VkResult result;
	zval boxed;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT(physical)
		Z_PARAM_OBJECT(create_info)
		Z_PARAM_LONG(allocator)
		Z_PARAM_ZVAL(out)
	ZEND_PARSE_PARAMETERS_END();

	if (!vulkan_handle_value(physical, vulkan_ce_VkPhysicalDevice, 1, &value)) {
		RETURN_THROWS();
	}

	vulkan_scratch_init(&scratch);
	if (!vulkan_arg_struct(create_info, vulkan_ce_VkDeviceCreateInfo, vk_VkDeviceCreateInfo_from, &info, &scratch)) {
		vulkan_scratch_free(&scratch);
		RETURN_THROWS();
	}

	result = vkCreateDevice((VkPhysicalDevice) (uintptr_t) value, &info, ALLOCATOR(allocator), &device);
	vulkan_scratch_free(&scratch);
	if (result == VK_SUCCESS) {
		vulkan_box(&boxed, (uint64_t) (uintptr_t) device, vulkan_ce_VkDevice, Z_OBJ_P(physical));
	} else {
		ZVAL_NULL(&boxed);
	}
	vulkan_assign(out, &boxed);
	RETURN_LONG((zend_long) result);
}

ZEND_FUNCTION(vkDestroyDevice)
{
	zval *device;
	zend_long allocator;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(device, vulkan_ce_VkDevice)
		Z_PARAM_LONG(allocator)
	ZEND_PARSE_PARAMETERS_END();

	vkDestroyDevice((VkDevice) (uintptr_t) vulkan_or_null(device), ALLOCATOR(allocator));
	if (device) {
		vulkan_release_tree(Z_OBJ_P(device));
	}
}
ZEND_FUNCTION(vkGetDeviceQueue)
{
	zval *device, *out;
	zend_long family, index;
	uint64_t value;
	VkQueue queue = VK_NULL_HANDLE;
	zval boxed;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT(device)
		Z_PARAM_LONG(family)
		Z_PARAM_LONG(index)
		Z_PARAM_ZVAL(out)
	ZEND_PARSE_PARAMETERS_END();

	if (!vulkan_handle_value(device, vulkan_ce_VkDevice, 1, &value)) {
		RETURN_THROWS();
	}

	vkGetDeviceQueue((VkDevice) (uintptr_t) value, (uint32_t) family, (uint32_t) index, &queue);
	vulkan_box(&boxed, (uint64_t) (uintptr_t) queue, vulkan_ce_VkQueue, Z_OBJ_P(device));
	vulkan_assign(out, &boxed);
}

ZEND_FUNCTION(vkDeviceWaitIdle)
{
	zval *device;
	uint64_t value;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT(device)
	ZEND_PARSE_PARAMETERS_END();

	if (!vulkan_handle_value(device, vulkan_ce_VkDevice, 1, &value)) {
		RETURN_THROWS();
	}

	RETURN_LONG((zend_long) vkDeviceWaitIdle((VkDevice) (uintptr_t) value));
}

ZEND_FUNCTION(vkGetPhysicalDeviceFeatures2)
{
	zval *physical, *features;
	uint64_t value;
	vulkan_scratch scratch;
	HashTable visited;
	VkPhysicalDeviceFeatures2 info;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT(physical)
		Z_PARAM_OBJECT(features)
	ZEND_PARSE_PARAMETERS_END();

	if (!vulkan_handle_value(physical, vulkan_ce_VkPhysicalDevice, 1, &value)) {
		RETURN_THROWS();
	}
	if (!instanceof_function(Z_OBJCE_P(features), vulkan_ce_VkPhysicalDeviceFeatures2)) {
		zend_argument_type_error(2, "must be of type %s, %s given", "VkPhysicalDeviceFeatures2", zend_zval_value_name(features));
		RETURN_THROWS();
	}

	vulkan_scratch_init(&scratch);
	zend_hash_init(&visited, 4, NULL, NULL, 0);
	if (!vk_VkPhysicalDeviceFeatures2_from(Z_OBJ_P(features), &info, &scratch, &visited)) {
		zend_hash_destroy(&visited);
		vulkan_scratch_free(&scratch);
		RETURN_THROWS();
	}
	zend_hash_destroy(&visited);

	vkGetPhysicalDeviceFeatures2((VkPhysicalDevice) (uintptr_t) value, &info);
	vulkan_store_pnext_chain(Z_OBJ_P(features), &info);
	vulkan_scratch_free(&scratch);
}

ZEND_FUNCTION(vkGetInstanceProcAddr)
{
	zval *instance;
	char *name;
	size_t name_len;
	uint64_t value = 0;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(instance, vulkan_ce_VkInstance)
		Z_PARAM_STRING(name, name_len)
	ZEND_PARSE_PARAMETERS_END();

	(void) name_len;
	if (instance && !vulkan_handle_value(instance, vulkan_ce_VkInstance, 1, &value)) {
		RETURN_THROWS();
	}

	/* PFN_vkVoidFunction as the int address; 0 is NULL, a name the loader does not know. */
	RETURN_LONG((zend_long) (uintptr_t) vkGetInstanceProcAddr((VkInstance) (uintptr_t) value, name));
}
