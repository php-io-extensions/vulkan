#include "runtime.h"

static zend_object_handlers vulkan_handle_handlers;
static zend_object_handlers vulkan_struct_handlers;

static HashTable *vulkan_class_table(zend_class_entry *ce)
{
	HashTable *table = zend_hash_index_find_ptr(&VULKAN_G(classes), (zend_ulong) (uintptr_t) ce);

	if (table == NULL) {
		table = pemalloc(sizeof(HashTable), 1);
		zend_hash_init(table, 8, NULL, NULL, 1);
		zend_hash_index_update_ptr(&VULKAN_G(classes), (zend_ulong) (uintptr_t) ce, table);
	}

	return table;
}

static void vulkan_forget(vulkan_handle *handle)
{
	HashTable *table;

	if (handle->value == 0) {
		return;
	}

	table = vulkan_class_table(handle->std.ce);
	zend_hash_index_del(table, (zend_ulong) handle->value);
	handle->value = 0;
	handle->ptr = NULL;
}

static void vulkan_release(zend_object *obj)
{
	vulkan_handle *handle = vulkan_handle_from(obj);

	vulkan_forget(handle);
	handle->parent = NULL;
	if (Z_TYPE(handle->keep) != IS_UNDEF) {
		zval_ptr_dtor(&handle->keep);
		ZVAL_UNDEF(&handle->keep);
	}
}

static zend_object *vulkan_create_object(zend_class_entry *ce)
{
	vulkan_handle *intern = zend_object_alloc(sizeof(vulkan_handle), ce);

	zend_object_std_init(&intern->std, ce);
	object_properties_init(&intern->std, ce);
	intern->std.handlers = &vulkan_handle_handlers;
	intern->ptr = NULL;
	intern->value = 0;
	intern->parent = NULL;
	ZVAL_UNDEF(&intern->keep);

	return &intern->std;
}

static void vulkan_free_object(zend_object *object)
{
	vulkan_handle *intern = vulkan_handle_from(object);

	vulkan_forget(intern);
	if (Z_TYPE(intern->keep) != IS_UNDEF) {
		zval_ptr_dtor(&intern->keep);
		ZVAL_UNDEF(&intern->keep);
	}
	zend_object_std_dtor(object);
}

void vulkan_handle_setup(zend_class_entry *ce)
{
	static bool handlers_ready = false;

	if (!handlers_ready) {
		memcpy(&vulkan_handle_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
		vulkan_handle_handlers.offset = XtOffsetOf(vulkan_handle, std);
		vulkan_handle_handlers.free_obj = vulkan_free_object;
		vulkan_handle_handlers.clone_obj = NULL;
		handlers_ready = true;
	}

	ce->create_object = vulkan_create_object;
	ce->default_object_handlers = &vulkan_handle_handlers;
	ce->ce_flags |= ZEND_ACC_NOT_SERIALIZABLE | ZEND_ACC_FINAL;
}

void vulkan_struct_setup(zend_class_entry *ce)
{
	static bool handlers_ready = false;

	if (!handlers_ready) {
		memcpy(&vulkan_struct_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
		vulkan_struct_handlers.clone_obj = NULL;
		handlers_ready = true;
	}

	ce->default_object_handlers = &vulkan_struct_handlers;
	ce->ce_flags |= ZEND_ACC_NOT_SERIALIZABLE | ZEND_ACC_FINAL;
}

void vulkan_box(zval *rv, uint64_t value, zend_class_entry *ce, zend_object *parent)
{
	HashTable *table;
	zend_object *existing;
	vulkan_handle *handle;

	if (value == 0) {
		ZVAL_NULL(rv);
		return;
	}

	table = vulkan_class_table(ce);
	existing = zend_hash_index_find_ptr(table, (zend_ulong) value);
	if (existing != NULL) {
		ZVAL_OBJ_COPY(rv, existing);
		return;
	}

	object_init_ex(rv, ce);
	handle = vulkan_handle_from(Z_OBJ_P(rv));
	handle->value = value;
	handle->ptr = (void *) (uintptr_t) value;
	handle->parent = parent;
	if (parent != NULL) {
		ZVAL_OBJ_COPY(&handle->keep, parent);
	}
	zend_hash_index_update_ptr(table, (zend_ulong) value, Z_OBJ_P(rv));
}

bool vulkan_handle_value(zval *zv, zend_class_entry *ce, uint32_t arg_num, uint64_t *out)
{
	vulkan_handle *handle;

	if (Z_TYPE_P(zv) != IS_OBJECT || !instanceof_function(Z_OBJCE_P(zv), ce)) {
		if (arg_num == 0) {
			zend_type_error("must be of type %s", ZSTR_VAL(ce->name));
		} else {
			zend_argument_type_error(arg_num, "must be of type %s", ZSTR_VAL(ce->name));
		}
		return false;
	}

	handle = vulkan_handle_from(Z_OBJ_P(zv));
	if (handle->value == 0) {
		if (arg_num == 0) {
			zend_value_error("%s has been destroyed", ZSTR_VAL(ce->name));
		} else {
			zend_argument_value_error(arg_num, "%s has been destroyed", ZSTR_VAL(ce->name));
		}
		return false;
	}

	*out = handle->value;
	return true;
}

static bool vulkan_chain_reaches(zend_object *obj, zend_object *root)
{
	vulkan_handle *handle = vulkan_handle_from(obj);
	int guard = 0;

	while (handle->parent != NULL && guard++ < 64) {
		if (handle->parent == root) {
			return true;
		}
		if (handle->parent->handlers != &vulkan_handle_handlers) {
			return false;
		}
		handle = vulkan_handle_from(handle->parent);
	}

	return false;
}

void vulkan_release_tree(zend_object *root)
{
	zend_object **snapshot;
	bool *release;
	uint32_t count = 0;
	uint32_t index = 0;
	zval *table_zv;
	zend_object *obj;

	ZEND_HASH_FOREACH_VAL(&VULKAN_G(classes), table_zv) {
		count += zend_hash_num_elements(Z_PTR_P(table_zv));
	} ZEND_HASH_FOREACH_END();

	snapshot = safe_emalloc(count + 1, sizeof(zend_object *), 0);
	release = ecalloc(count + 1, sizeof(bool));
	ZEND_HASH_FOREACH_VAL(&VULKAN_G(classes), table_zv) {
		ZEND_HASH_FOREACH_PTR(Z_PTR_P(table_zv), obj) {
			snapshot[index++] = obj;
		} ZEND_HASH_FOREACH_END();
	} ZEND_HASH_FOREACH_END();

	for (index = 0; index < count; index++) {
		release[index] = snapshot[index] == root || vulkan_chain_reaches(snapshot[index], root);
	}
	for (index = 0; index < count; index++) {
		if (release[index]) {
			vulkan_release(snapshot[index]);
		}
	}

	efree(release);
	efree(snapshot);
}

void vulkan_scratch_init(vulkan_scratch *scratch)
{
	scratch->head = NULL;
}

void *vulkan_scratch_alloc(vulkan_scratch *scratch, size_t bytes)
{
	vulkan_scratch_block *block = emalloc(sizeof(vulkan_scratch_block));

	block->ptr = emalloc(bytes == 0 ? 1 : bytes);
	block->next = scratch->head;
	scratch->head = block;
	memset(block->ptr, 0, bytes == 0 ? 1 : bytes);

	return block->ptr;
}

void vulkan_scratch_free(vulkan_scratch *scratch)
{
	vulkan_scratch_block *block = scratch->head;

	while (block != NULL) {
		vulkan_scratch_block *next = block->next;
		efree(block->ptr);
		efree(block);
		block = next;
	}

	scratch->head = NULL;
}

void vulkan_assign(zval *out, zval *value)
{
	ZEND_TRY_ASSIGN_REF_VALUE(out, value);
	ZVAL_UNDEF(value);
}

bool vulkan_enter(zend_object *obj, HashTable *visited)
{
	(void) obj;
	(void) visited;
	return true;
}

static zval *vulkan_read_prop(zend_object *obj, const char *name)
{
	zval *zv = zend_read_property(obj->ce, obj, name, strlen(name), 0, NULL);

	if (EG(exception) != NULL) {
		return NULL;
	}

	return zv;
}

static bool vulkan_long_prop(zend_object *obj, const char *name, zend_long *out)
{
	zval *zv = vulkan_read_prop(obj, name);

	if (zv == NULL) {
		return false;
	}
	if (Z_TYPE_P(zv) != IS_LONG) {
		zend_type_error("%s::$%s must be an int", ZSTR_VAL(obj->ce->name), name);
		return false;
	}

	*out = Z_LVAL_P(zv);
	return true;
}

bool vulkan_u32(zend_object *obj, const char *name, uint32_t *out)
{
	zend_long value;

	if (!vulkan_long_prop(obj, name, &value)) {
		return false;
	}

	*out = (uint32_t) value;
	return true;
}

bool vulkan_i32(zend_object *obj, const char *name, int32_t *out)
{
	zend_long value;

	if (!vulkan_long_prop(obj, name, &value)) {
		return false;
	}

	*out = (int32_t) value;
	return true;
}

bool vulkan_u64(zend_object *obj, const char *name, uint64_t *out)
{
	zend_long value;

	if (!vulkan_long_prop(obj, name, &value)) {
		return false;
	}

	*out = (uint64_t) value;
	return true;
}

bool vulkan_size(zend_object *obj, const char *name, size_t *out)
{
	zend_long value;

	if (!vulkan_long_prop(obj, name, &value)) {
		return false;
	}

	*out = (size_t) value;
	return true;
}

bool vulkan_float(zend_object *obj, const char *name, float *out)
{
	zval *zv = vulkan_read_prop(obj, name);

	if (zv == NULL) {
		return false;
	}
	if (Z_TYPE_P(zv) == IS_DOUBLE) {
		*out = (float) Z_DVAL_P(zv);
		return true;
	}
	if (Z_TYPE_P(zv) == IS_LONG) {
		*out = (float) Z_LVAL_P(zv);
		return true;
	}

	zend_type_error("%s::$%s must be a float", ZSTR_VAL(obj->ce->name), name);
	return false;
}

bool vulkan_bool32(zend_object *obj, const char *name, VkBool32 *out)
{
	zval *zv = vulkan_read_prop(obj, name);

	if (zv == NULL) {
		return false;
	}
	if (Z_TYPE_P(zv) != IS_TRUE && Z_TYPE_P(zv) != IS_FALSE) {
		zend_type_error("%s::$%s must be a bool", ZSTR_VAL(obj->ce->name), name);
		return false;
	}

	*out = Z_TYPE_P(zv) == IS_TRUE ? VK_TRUE : VK_FALSE;
	return true;
}

bool vulkan_cstring(zend_object *obj, const char *name, const char **out)
{
	zval *zv = vulkan_read_prop(obj, name);

	if (zv == NULL) {
		return false;
	}
	if (Z_TYPE_P(zv) == IS_NULL) {
		*out = NULL;
		return true;
	}
	if (Z_TYPE_P(zv) != IS_STRING) {
		zend_type_error("%s::$%s must be null or a string", ZSTR_VAL(obj->ce->name), name);
		return false;
	}

	*out = Z_STRVAL_P(zv);
	return true;
}

bool vulkan_bytes_from(zend_object *obj, const char *name, void *dst, size_t size)
{
	zval *zv = vulkan_read_prop(obj, name);

	if (zv == NULL) {
		return false;
	}
	if (Z_TYPE_P(zv) != IS_STRING || Z_STRLEN_P(zv) != size) {
		zend_type_error("%s::$%s must be a string of %zu bytes", ZSTR_VAL(obj->ce->name), name, size);
		return false;
	}

	memcpy(dst, Z_STRVAL_P(zv), size);
	return true;
}

bool vulkan_char_array_from(zend_object *obj, const char *name, char *dst, size_t size)
{
	zval *zv = vulkan_read_prop(obj, name);

	if (zv == NULL) {
		return false;
	}
	if (Z_TYPE_P(zv) != IS_STRING || Z_STRLEN_P(zv) >= size) {
		zend_type_error("%s::$%s must be a string shorter than %zu bytes", ZSTR_VAL(obj->ce->name), name, size);
		return false;
	}

	memcpy(dst, Z_STRVAL_P(zv), Z_STRLEN_P(zv));
	dst[Z_STRLEN_P(zv)] = '\0';
	return true;
}

static bool vulkan_list(zend_object *obj, const char *name, zval **items, uint32_t *count)
{
	zval *zv = vulkan_read_prop(obj, name);
	uint32_t n = 0;
	uint32_t i = 0;
	zval *item;

	if (zv == NULL) {
		return false;
	}
	if (Z_TYPE_P(zv) != IS_ARRAY) {
		zend_type_error("%s::$%s must be a list", ZSTR_VAL(obj->ce->name), name);
		return false;
	}

	n = zend_hash_num_elements(Z_ARRVAL_P(zv));
	*count = n;
	if (n == 0) {
		*items = NULL;
		return true;
	}

	*items = safe_emalloc(n, sizeof(zval), 0);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(zv), item) {
		ZVAL_COPY_VALUE(&(*items)[i], item);
		i++;
	} ZEND_HASH_FOREACH_END();

	return true;
}

bool vulkan_u32_list(zend_object *obj, const char *name, const uint32_t **out, uint32_t *count, vulkan_scratch *scratch)
{
	zval *items = NULL;
	uint32_t n, i;
	uint32_t *stored;

	if (!vulkan_list(obj, name, &items, &n)) {
		return false;
	}
	*count = n;
	if (n == 0) {
		*out = NULL;
		return true;
	}

	stored = vulkan_scratch_alloc(scratch, sizeof(uint32_t) * n);
	for (i = 0; i < n; i++) {
		if (Z_TYPE(items[i]) != IS_LONG) {
			zend_type_error("%s::$%s must be a list of int", ZSTR_VAL(obj->ce->name), name);
			efree(items);
			return false;
		}
		stored[i] = (uint32_t) Z_LVAL(items[i]);
	}
	efree(items);
	*out = stored;
	return true;
}

bool vulkan_i32_list(zend_object *obj, const char *name, const int32_t **out, uint32_t *count, vulkan_scratch *scratch)
{
	zval *items = NULL;
	uint32_t n, i;
	int32_t *stored;

	if (!vulkan_list(obj, name, &items, &n)) {
		return false;
	}
	*count = n;
	if (n == 0) {
		*out = NULL;
		return true;
	}

	stored = vulkan_scratch_alloc(scratch, sizeof(int32_t) * n);
	for (i = 0; i < n; i++) {
		if (Z_TYPE(items[i]) != IS_LONG) {
			zend_type_error("%s::$%s must be a list of int", ZSTR_VAL(obj->ce->name), name);
			efree(items);
			return false;
		}
		stored[i] = (int32_t) Z_LVAL(items[i]);
	}
	efree(items);
	*out = stored;
	return true;
}

bool vulkan_float_list(zend_object *obj, const char *name, const float **out, uint32_t *count, vulkan_scratch *scratch)
{
	zval *items = NULL;
	uint32_t n, i;
	float *stored;

	if (!vulkan_list(obj, name, &items, &n)) {
		return false;
	}
	*count = n;
	if (n == 0) {
		*out = NULL;
		return true;
	}

	stored = vulkan_scratch_alloc(scratch, sizeof(float) * n);
	for (i = 0; i < n; i++) {
		if (Z_TYPE(items[i]) == IS_DOUBLE) {
			stored[i] = (float) Z_DVAL(items[i]);
		} else if (Z_TYPE(items[i]) == IS_LONG) {
			stored[i] = (float) Z_LVAL(items[i]);
		} else {
			zend_type_error("%s::$%s must be a list of float", ZSTR_VAL(obj->ce->name), name);
			efree(items);
			return false;
		}
	}
	efree(items);
	*out = stored;
	return true;
}

bool vulkan_fixed_floats(zend_object *obj, const char *name, float *dst, uint32_t count)
{
	const float *items = NULL;
	uint32_t n = 0;
	vulkan_scratch scratch;

	vulkan_scratch_init(&scratch);
	if (!vulkan_float_list(obj, name, &items, &n, &scratch)) {
		vulkan_scratch_free(&scratch);
		return false;
	}
	if (n != count) {
		zend_value_error("%s::$%s must hold %u floats", ZSTR_VAL(obj->ce->name), name, count);
		vulkan_scratch_free(&scratch);
		return false;
	}
	if (count > 0) {
		memcpy(dst, items, sizeof(float) * count);
	}
	vulkan_scratch_free(&scratch);
	return true;
}

bool vulkan_fixed_u32s(zend_object *obj, const char *name, uint32_t *dst, uint32_t count)
{
	const uint32_t *items = NULL;
	uint32_t n = 0;
	vulkan_scratch scratch;

	vulkan_scratch_init(&scratch);
	if (!vulkan_u32_list(obj, name, &items, &n, &scratch)) {
		vulkan_scratch_free(&scratch);
		return false;
	}
	if (n != count) {
		zend_value_error("%s::$%s must hold %u ints", ZSTR_VAL(obj->ce->name), name, count);
		vulkan_scratch_free(&scratch);
		return false;
	}
	if (count > 0) {
		memcpy(dst, items, sizeof(uint32_t) * count);
	}
	vulkan_scratch_free(&scratch);
	return true;
}

bool vulkan_string_list(zend_object *obj, const char *name, const char *const **out, uint32_t *count, vulkan_scratch *scratch)
{
	zval *items = NULL;
	uint32_t n, i;
	const char **stored;

	if (!vulkan_list(obj, name, &items, &n)) {
		return false;
	}
	*count = n;
	if (n == 0) {
		*out = NULL;
		return true;
	}

	stored = vulkan_scratch_alloc(scratch, sizeof(const char *) * n);
	for (i = 0; i < n; i++) {
		char *copy;
		if (Z_TYPE(items[i]) != IS_STRING) {
			zend_type_error("%s::$%s must be a list of string", ZSTR_VAL(obj->ce->name), name);
			efree(items);
			return false;
		}
		copy = vulkan_scratch_alloc(scratch, Z_STRLEN(items[i]) + 1);
		memcpy(copy, Z_STRVAL(items[i]), Z_STRLEN(items[i]) + 1);
		stored[i] = copy;
	}
	efree(items);
	*out = stored;
	return true;
}

bool vulkan_handle_prop(zend_object *obj, const char *name, zend_class_entry *ce, uint64_t *out)
{
	zval *zv = vulkan_read_prop(obj, name);

	if (zv == NULL) {
		return false;
	}
	if (Z_TYPE_P(zv) == IS_NULL) {
		*out = 0;
		return true;
	}
	if (Z_TYPE_P(zv) != IS_OBJECT || !instanceof_function(Z_OBJCE_P(zv), ce)) {
		zend_type_error("%s::$%s must be null or an instance of %s", ZSTR_VAL(obj->ce->name), name, ZSTR_VAL(ce->name));
		return false;
	}

	return vulkan_handle_value(zv, ce, 0, out);
}

bool vulkan_handle_list(zend_object *obj, const char *name, zend_class_entry *ce, uint64_t **out, uint32_t *count, vulkan_scratch *scratch)
{
	zval *items = NULL;
	uint32_t n, i;
	uint64_t *stored;

	if (!vulkan_list(obj, name, &items, &n)) {
		return false;
	}
	*count = n;
	if (n == 0) {
		*out = NULL;
		return true;
	}

	stored = vulkan_scratch_alloc(scratch, sizeof(uint64_t) * n);
	for (i = 0; i < n; i++) {
		if (Z_TYPE(items[i]) != IS_OBJECT || !instanceof_function(Z_OBJCE(items[i]), ce)) {
			zend_type_error("%s::$%s must be a list of %s", ZSTR_VAL(obj->ce->name), name, ZSTR_VAL(ce->name));
			efree(items);
			return false;
		}
		if (!vulkan_handle_value(&items[i], ce, 0, &stored[i])) {
			efree(items);
			return false;
		}
	}
	efree(items);
	*out = stored;
	return true;
}

void vulkan_set_long(zend_object *obj, const char *name, zend_long value)
{
	zval tmp;
	ZVAL_LONG(&tmp, value);
	zend_update_property(obj->ce, obj, name, strlen(name), &tmp);
}

void vulkan_set_double(zend_object *obj, const char *name, double value)
{
	zval tmp;
	ZVAL_DOUBLE(&tmp, value);
	zend_update_property(obj->ce, obj, name, strlen(name), &tmp);
}

void vulkan_set_bool(zend_object *obj, const char *name, bool value)
{
	zval tmp;
	ZVAL_BOOL(&tmp, value);
	zend_update_property(obj->ce, obj, name, strlen(name), &tmp);
}

void vulkan_set_string(zend_object *obj, const char *name, const char *value)
{
	zval tmp;
	if (value == NULL) {
		ZVAL_NULL(&tmp);
	} else {
		ZVAL_STRING(&tmp, value);
	}
	zend_update_property(obj->ce, obj, name, strlen(name), &tmp);
	zval_ptr_dtor(&tmp);
}

void vulkan_set_bytes(zend_object *obj, const char *name, const void *bytes, size_t size)
{
	zval tmp;
	ZVAL_STRINGL(&tmp, (const char *) bytes, size);
	zend_update_property(obj->ce, obj, name, strlen(name), &tmp);
	zval_ptr_dtor(&tmp);
}

void vulkan_set_zval(zend_object *obj, const char *name, zval *value)
{
	zend_update_property(obj->ce, obj, name, strlen(name), value);
	zval_ptr_dtor(value);
}

void vulkan_init_nested(zend_object *obj, const char *name, zend_class_entry *ce)
{
	zval nested;

	object_init_ex(&nested, ce);
	if (ce->constructor != NULL) {
		zend_call_known_instance_method_with_0_params(ce->constructor, Z_OBJ(nested), NULL);
		if (EG(exception) != NULL) {
			zval_ptr_dtor(&nested);
			return;
		}
	}
	zend_update_property(obj->ce, obj, name, strlen(name), &nested);
	zval_ptr_dtor(&nested);
}
