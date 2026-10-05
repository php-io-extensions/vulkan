#ifndef VULKAN_RUNTIME_H
#define VULKAN_RUNTIME_H

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "zend_exceptions.h"
#include "php_vulkan.h"
#include <vulkan/vulkan.h>

ZEND_BEGIN_MODULE_GLOBALS(vulkan)
	HashTable classes; /* class entry address => HashTable* (handle value => zend_object*, not refcounted) */
ZEND_END_MODULE_GLOBALS(vulkan)

ZEND_EXTERN_MODULE_GLOBALS(vulkan)
#define VULKAN_G(v) ZEND_MODULE_GLOBALS_ACCESSOR(vulkan, v)

typedef struct vulkan_handle {
	void *ptr;
	uint64_t value;            /* 0 once released; never a live VK_NULL_HANDLE */
	zend_object *parent;
	zval keep;                 /* a reference to parent, or UNDEF */
	zend_object std;
} vulkan_handle;

static zend_always_inline vulkan_handle *vulkan_handle_from(zend_object *obj)
{
	return (vulkan_handle *) ((char *) obj - XtOffsetOf(vulkan_handle, std));
}

typedef struct vulkan_scratch_block {
	void *ptr;
	struct vulkan_scratch_block *next;
} vulkan_scratch_block;

typedef struct vulkan_scratch {
	vulkan_scratch_block *head;
} vulkan_scratch;

void vulkan_scratch_init(vulkan_scratch *scratch);
void *vulkan_scratch_alloc(vulkan_scratch *scratch, size_t bytes);
void vulkan_scratch_free(vulkan_scratch *scratch);

void vulkan_handle_setup(zend_class_entry *ce);
void vulkan_struct_setup(zend_class_entry *ce);

/* Boxes value as ce. parent is referenced for the release tree. value 0 becomes null. */
void vulkan_box(zval *rv, uint64_t value, zend_class_entry *ce, zend_object *parent);
/* False after throwing. A released handle throws ValueError "... has been destroyed". */
bool vulkan_handle_value(zval *zv, zend_class_entry *ce, uint32_t arg_num, uint64_t *out);
/* Releases obj and every live handle whose parent chain reaches it. */
void vulkan_release_tree(zend_object *obj);

void vulkan_assign(zval *out, zval *value);

bool vulkan_enter(zend_object *obj, HashTable *visited);

bool vulkan_u32(zend_object *obj, const char *name, uint32_t *out);
bool vulkan_i32(zend_object *obj, const char *name, int32_t *out);
bool vulkan_u64(zend_object *obj, const char *name, uint64_t *out);
bool vulkan_size(zend_object *obj, const char *name, size_t *out);
bool vulkan_float(zend_object *obj, const char *name, float *out);
bool vulkan_bool32(zend_object *obj, const char *name, VkBool32 *out);
bool vulkan_cstring(zend_object *obj, const char *name, const char **out);
bool vulkan_bytes_from(zend_object *obj, const char *name, void *dst, size_t size);
bool vulkan_char_array_from(zend_object *obj, const char *name, char *dst, size_t size);
bool vulkan_u32_list(zend_object *obj, const char *name, const uint32_t **out, uint32_t *count, vulkan_scratch *scratch);
bool vulkan_i32_list(zend_object *obj, const char *name, const int32_t **out, uint32_t *count, vulkan_scratch *scratch);
bool vulkan_float_list(zend_object *obj, const char *name, const float **out, uint32_t *count, vulkan_scratch *scratch);
bool vulkan_fixed_floats(zend_object *obj, const char *name, float *dst, uint32_t count);
bool vulkan_fixed_u32s(zend_object *obj, const char *name, uint32_t *dst, uint32_t count);
bool vulkan_string_list(zend_object *obj, const char *name, const char *const **out, uint32_t *count, vulkan_scratch *scratch);
bool vulkan_handle_prop(zend_object *obj, const char *name, zend_class_entry *ce, uint64_t *out);
bool vulkan_handle_list(zend_object *obj, const char *name, zend_class_entry *ce, uint64_t **out, uint32_t *count, vulkan_scratch *scratch);

void vulkan_set_long(zend_object *obj, const char *name, zend_long value);
void vulkan_set_double(zend_object *obj, const char *name, double value);
void vulkan_set_bool(zend_object *obj, const char *name, bool value);
void vulkan_set_string(zend_object *obj, const char *name, const char *value);
void vulkan_set_bytes(zend_object *obj, const char *name, const void *bytes, size_t size);
void vulkan_set_zval(zend_object *obj, const char *name, zval *value);

void vulkan_init_nested(zend_object *obj, const char *name, zend_class_entry *ce);

#define VULKAN_HANDLE_METHODS(cls) \
	ZEND_METHOD(cls, __construct) \
	{ \
		ZEND_PARSE_PARAMETERS_NONE(); \
		zend_throw_error(NULL, "%s cannot be constructed", #cls); \
		RETURN_THROWS(); \
	} \
	ZEND_METHOD(cls, pointer) \
	{ \
		vulkan_handle *handle; \
		ZEND_PARSE_PARAMETERS_NONE(); \
		handle = vulkan_handle_from(Z_OBJ_P(ZEND_THIS)); \
		if (handle->value == 0) { \
			zend_value_error("%s has been destroyed", ZSTR_VAL(Z_OBJCE_P(ZEND_THIS)->name)); \
			RETURN_THROWS(); \
		} \
		RETURN_LONG((zend_long) handle->value); \
	} \
	ZEND_METHOD(cls, fromPointer) \
	{ \
		zend_long address; \
		ZEND_PARSE_PARAMETERS_START(1, 1) \
			Z_PARAM_LONG(address) \
		ZEND_PARSE_PARAMETERS_END(); \
		if (address == 0) { \
			zend_argument_value_error(1, "must not be a null address"); \
			RETURN_THROWS(); \
		} \
		vulkan_box(return_value, (uint64_t) address, zend_get_called_scope(execute_data), NULL); \
	}

#endif
