#include "runtime.h"
#include "structs.h"

#ifdef VK_USE_PLATFORM_METAL_EXT
#include "../stubs/vk_metal_arginfo.h"

static zend_class_entry *vulkan_metal_ce;

bool vk_VkMetalSurfaceCreateInfoEXT_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkMetalSurfaceCreateInfoEXT *dst = raw;
	memset(dst, 0, sizeof(*dst));
	dst->sType = VK_STRUCTURE_TYPE_METAL_SURFACE_CREATE_INFO_EXT;
	if (!vulkan_enter(obj, visited) || !vulkan_pnext(obj, &dst->pNext, scratch, visited)) return false;
	if (!vulkan_u32(obj, "flags", &dst->flags)) return false;
	{
		zval *zv = zend_read_property(obj->ce, obj, "pLayer", sizeof("pLayer") - 1, 0, NULL);
		if (zv == NULL || Z_TYPE_P(zv) != IS_LONG) {
			zend_type_error("VkMetalSurfaceCreateInfoEXT::$pLayer must be an int");
			return false;
		}
		dst->pLayer = (const CAMetalLayer *) (uintptr_t) Z_LVAL_P(zv);
	}
	return true;
}
void vk_VkMetalSurfaceCreateInfoEXT_to(const void *raw, zval *rv) { (void) raw; object_init_ex(rv, vulkan_metal_ce); }

void vulkan_register_metal(int module_number)
{
	zend_register_functions(NULL, ext_functions, NULL, MODULE_PERSISTENT);
	vulkan_metal_ce = register_class_VkMetalSurfaceCreateInfoEXT();
	vulkan_struct_setup(vulkan_metal_ce);
	(void) module_number;
}

ZEND_FUNCTION(vkCreateMetalSurfaceEXT)
{
	zval *instance, *info, *allocator, *out;
	uint64_t instance_value;
	VkMetalSurfaceCreateInfoEXT create;
	VkSurfaceKHR surface = VK_NULL_HANDLE;
	PFN_vkCreateMetalSurfaceEXT create_surface;
	vulkan_scratch scratch;
	VkResult result;
	zval boxed;
	ZEND_PARSE_PARAMETERS_START(4, 4) Z_PARAM_OBJECT(instance) Z_PARAM_OBJECT(info) Z_PARAM_ZVAL(allocator) Z_PARAM_ZVAL(out) ZEND_PARSE_PARAMETERS_END();
	if (Z_TYPE_P(allocator) != IS_NULL) { zend_argument_type_error(3, "must be null"); RETURN_THROWS(); }
	if (!vulkan_handle_value(instance, vulkan_ce_VkInstance, 1, &instance_value)) RETURN_THROWS();
	create_surface = (PFN_vkCreateMetalSurfaceEXT) vkGetInstanceProcAddr((VkInstance) (uintptr_t) instance_value, "vkCreateMetalSurfaceEXT");
	if (create_surface == NULL) {
		ZVAL_NULL(&boxed);
		vulkan_assign(out, &boxed);
		RETURN_LONG((zend_long) VK_ERROR_EXTENSION_NOT_PRESENT);
	}
	vulkan_scratch_init(&scratch);
	if (!vulkan_enter(Z_OBJ_P(info), NULL)) { vulkan_scratch_free(&scratch); RETURN_THROWS(); }
	{
		HashTable visited;
		zend_hash_init(&visited, 2, NULL, NULL, 0);
		if (!vk_VkMetalSurfaceCreateInfoEXT_from(Z_OBJ_P(info), &create, &scratch, &visited)) {
			zend_hash_destroy(&visited);
			vulkan_scratch_free(&scratch);
			RETURN_THROWS();
		}
		zend_hash_destroy(&visited);
	}
	result = create_surface((VkInstance) (uintptr_t) instance_value, &create, NULL, &surface);
	vulkan_scratch_free(&scratch);
	if (result == VK_SUCCESS) vulkan_box(&boxed, (uint64_t) (uintptr_t) surface, vulkan_ce_VkSurfaceKHR, Z_OBJ_P(instance));
	else ZVAL_NULL(&boxed);
	vulkan_assign(out, &boxed);
	RETURN_LONG((zend_long) result);
}
#endif
