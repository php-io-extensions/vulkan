#include "runtime.h"
#include "structs.h"
#include "../stubs/vk_command_arginfo.h"

VULKAN_HANDLE_METHODS(VkCommandPool)
VULKAN_HANDLE_METHODS(VkCommandBuffer)
VULKAN_HANDLE_METHODS(VkFence)
VULKAN_HANDLE_METHODS(VkSemaphore)

ZEND_METHOD(VkRenderPassBeginInfo, __construct)
{
	ZEND_PARSE_PARAMETERS_NONE();
	vulkan_init_nested(Z_OBJ_P(ZEND_THIS), "renderArea", vulkan_ce_VkRect2D);
}

ZEND_METHOD(VkBufferImageCopy, __construct)
{
	ZEND_PARSE_PARAMETERS_NONE();
	vulkan_init_nested(Z_OBJ_P(ZEND_THIS), "imageSubresource", vulkan_ce_VkImageSubresourceLayers);
	vulkan_init_nested(Z_OBJ_P(ZEND_THIS), "imageOffset", vulkan_ce_VkOffset3D);
	vulkan_init_nested(Z_OBJ_P(ZEND_THIS), "imageExtent", vulkan_ce_VkExtent3D);
}

ZEND_METHOD(VkImageBlit, __construct)
{
	ZEND_PARSE_PARAMETERS_NONE();
	vulkan_init_nested(Z_OBJ_P(ZEND_THIS), "srcSubresource", vulkan_ce_VkImageSubresourceLayers);
	vulkan_init_nested(Z_OBJ_P(ZEND_THIS), "dstSubresource", vulkan_ce_VkImageSubresourceLayers);
}

ZEND_METHOD(VkImageMemoryBarrier, __construct)
{
	ZEND_PARSE_PARAMETERS_NONE();
	vulkan_init_nested(Z_OBJ_P(ZEND_THIS), "subresourceRange", vulkan_ce_VkImageSubresourceRange);
}

ZEND_METHOD(VkClearAttachment, __construct)
{
	ZEND_PARSE_PARAMETERS_NONE();
	vulkan_init_nested(Z_OBJ_P(ZEND_THIS), "clearValue", vulkan_ce_VkClearValue);
}

ZEND_METHOD(VkClearRect, __construct)
{
	ZEND_PARSE_PARAMETERS_NONE();
	vulkan_init_nested(Z_OBJ_P(ZEND_THIS), "rect", vulkan_ce_VkRect2D);
}

static bool vulkan_in(zval *zv, zend_class_entry *ce, vulkan_from_fn from, void *dst, vulkan_scratch *scratch)
{
	HashTable visited;
	bool ok;

	if (Z_TYPE_P(zv) != IS_OBJECT || !instanceof_function(Z_OBJCE_P(zv), ce)) {
		zend_type_error("must be of type %s", ZSTR_VAL(ce->name));
		return false;
	}
	zend_hash_init(&visited, 8, NULL, NULL, 0);
	ok = from(Z_OBJ_P(zv), dst, scratch, &visited);
	zend_hash_destroy(&visited);
	return ok;
}

static bool vulkan_cmd(zval *zv, uint64_t *out)
{
	return vulkan_handle_value(zv, vulkan_ce_VkCommandBuffer, 1, out);
}

static bool vulkan_struct_array(zval *list, uint32_t arg_num, const char *what, zend_class_entry *ce, size_t size, vulkan_from_fn from, void **out, uint32_t *count, vulkan_scratch *scratch)
{
	zval *item;
	uint32_t n, i;
	HashTable visited;
	char *stored;

	if (Z_TYPE_P(list) != IS_ARRAY) {
		zend_argument_type_error(arg_num, "must be a list of %s", what);
		return false;
	}
	n = zend_hash_num_elements(Z_ARRVAL_P(list));
	*count = n;
	stored = n ? vulkan_scratch_alloc(scratch, size * n) : NULL;
	zend_hash_init(&visited, 4, NULL, NULL, 0);
	i = 0;
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(list), item) {
		zend_hash_clean(&visited);
		if (Z_TYPE_P(item) != IS_OBJECT || !from(Z_OBJ_P(item), stored + (size_t) i * size, scratch, &visited)) {
			zend_hash_destroy(&visited);
			return false;
		}
		i++;
	} ZEND_HASH_FOREACH_END();
	zend_hash_destroy(&visited);
	*out = stored;
	return true;
}

void vulkan_register_command(int module_number)
{
	(void) module_number;
	zend_register_functions(NULL, ext_functions, NULL, MODULE_PERSISTENT);
#define H(cls) do { vulkan_ce_##cls = register_class_##cls(); vulkan_handle_setup(vulkan_ce_##cls); } while (0)
#define S(cls) do { vulkan_ce_##cls = register_class_##cls(); vulkan_struct_setup(vulkan_ce_##cls); } while (0)
	H(VkCommandPool); H(VkCommandBuffer); H(VkFence); H(VkSemaphore);
	S(VkCommandPoolCreateInfo); S(VkCommandBufferAllocateInfo); S(VkCommandBufferInheritanceInfo);
	S(VkCommandBufferBeginInfo); S(VkClearColorValue); S(VkClearDepthStencilValue); S(VkClearValue);
	S(VkRenderPassBeginInfo); S(VkOffset3D); S(VkImageSubresourceLayers); S(VkBufferImageCopy);
	S(VkImageBlit); S(VkImageMemoryBarrier); S(VkSubmitInfo); S(VkFenceCreateInfo); S(VkSemaphoreCreateInfo);
	S(VkClearAttachment); S(VkClearRect);
#undef H
#undef S
}

ZEND_FUNCTION(vkCreateCommandPool)
{
	zval *device, *info, *allocator, *out;
	uint64_t device_value;
	VkCommandPoolCreateInfo create;
	VkCommandPool pool = VK_NULL_HANDLE;
	vulkan_scratch scratch;
	VkResult result;
	zval boxed;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT(device) Z_PARAM_OBJECT(info) Z_PARAM_ZVAL(allocator) Z_PARAM_ZVAL(out)
	ZEND_PARSE_PARAMETERS_END();
	if (Z_TYPE_P(allocator) != IS_NULL || !vulkan_handle_value(device, vulkan_ce_VkDevice, 1, &device_value)) {
		if (Z_TYPE_P(allocator) != IS_NULL) zend_argument_type_error(3, "must be null");
		RETURN_THROWS();
	}
	vulkan_scratch_init(&scratch);
	if (!vulkan_in(info, vulkan_ce_VkCommandPoolCreateInfo, vk_VkCommandPoolCreateInfo_from, &create, &scratch)) {
		vulkan_scratch_free(&scratch);
		RETURN_THROWS();
	}
	result = vkCreateCommandPool((VkDevice) (uintptr_t) device_value, &create, NULL, &pool);
	vulkan_scratch_free(&scratch);
	if (result == VK_SUCCESS) vulkan_box(&boxed, (uint64_t) (uintptr_t) pool, vulkan_ce_VkCommandPool, Z_OBJ_P(device));
	else ZVAL_NULL(&boxed);
	vulkan_assign(out, &boxed);
	RETURN_LONG((zend_long) result);
}

ZEND_FUNCTION(vkDestroyCommandPool)
{
	zval *device, *pool, *allocator;
	uint64_t device_value, pool_value;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT(device) Z_PARAM_OBJECT(pool) Z_PARAM_ZVAL(allocator)
	ZEND_PARSE_PARAMETERS_END();
	if (Z_TYPE_P(allocator) != IS_NULL) { zend_argument_type_error(3, "must be null"); RETURN_THROWS(); }
	if (!vulkan_handle_value(device, vulkan_ce_VkDevice, 1, &device_value) || !vulkan_handle_value(pool, vulkan_ce_VkCommandPool, 2, &pool_value)) RETURN_THROWS();
	vkDestroyCommandPool((VkDevice) (uintptr_t) device_value, (VkCommandPool) (uintptr_t) pool_value, NULL);
	vulkan_release_tree(Z_OBJ_P(pool));
}

ZEND_FUNCTION(vkAllocateCommandBuffers)
{
	zval *device, *info, *out, *pool;
	uint64_t device_value;
	VkCommandBufferAllocateInfo allocate;
	VkCommandBuffer *buffers = NULL;
	vulkan_scratch scratch;
	VkResult result;
	zval arr, boxed;
	uint32_t i;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT(device) Z_PARAM_OBJECT(info) Z_PARAM_ZVAL(out)
	ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_handle_value(device, vulkan_ce_VkDevice, 1, &device_value)) RETURN_THROWS();
	vulkan_scratch_init(&scratch);
	if (!vulkan_in(info, vulkan_ce_VkCommandBufferAllocateInfo, vk_VkCommandBufferAllocateInfo_from, &allocate, &scratch)) {
		vulkan_scratch_free(&scratch);
		RETURN_THROWS();
	}
	buffers = allocate.commandBufferCount ? emalloc(sizeof(*buffers) * allocate.commandBufferCount) : NULL;
	result = vkAllocateCommandBuffers((VkDevice) (uintptr_t) device_value, &allocate, buffers);
	pool = zend_read_property(Z_OBJCE_P(info), Z_OBJ_P(info), "commandPool", sizeof("commandPool") - 1, 0, NULL);
	array_init_size(&arr, allocate.commandBufferCount);
	for (i = 0; i < allocate.commandBufferCount; i++) {
		zend_object *parent = (pool && Z_TYPE_P(pool) == IS_OBJECT) ? Z_OBJ_P(pool) : Z_OBJ_P(device);
		vulkan_box(&boxed, result == VK_SUCCESS ? (uint64_t) (uintptr_t) buffers[i] : 0, vulkan_ce_VkCommandBuffer, parent);
		zend_hash_next_index_insert(Z_ARRVAL(arr), &boxed);
	}
	vulkan_scratch_free(&scratch);
	if (buffers) efree(buffers);
	vulkan_assign(out, &arr);
	RETURN_LONG((zend_long) result);
}

ZEND_FUNCTION(vkFreeCommandBuffers)
{
	zval *device, *pool, *list, *item;
	uint64_t device_value, pool_value, *handles = NULL;
	uint32_t count, i;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT(device) Z_PARAM_OBJECT(pool) Z_PARAM_ZVAL(list)
	ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_handle_value(device, vulkan_ce_VkDevice, 1, &device_value) || !vulkan_handle_value(pool, vulkan_ce_VkCommandPool, 2, &pool_value)) RETURN_THROWS();
	if (Z_TYPE_P(list) != IS_ARRAY) { zend_argument_type_error(3, "must be a list of VkCommandBuffer"); RETURN_THROWS(); }
	count = zend_hash_num_elements(Z_ARRVAL_P(list));
	handles = count ? emalloc(sizeof(*handles) * count) : NULL;
	i = 0;
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(list), item) {
		if (!vulkan_handle_value(item, vulkan_ce_VkCommandBuffer, 3, &handles[i])) { if (handles) efree(handles); RETURN_THROWS(); }
		i++;
	} ZEND_HASH_FOREACH_END();
	vkFreeCommandBuffers((VkDevice) (uintptr_t) device_value, (VkCommandPool) (uintptr_t) pool_value, count, (const VkCommandBuffer *) handles);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(list), item) {
		vulkan_release_tree(Z_OBJ_P(item));
	} ZEND_HASH_FOREACH_END();
	if (handles) efree(handles);
}

ZEND_FUNCTION(vkBeginCommandBuffer)
{
	zval *command, *info;
	uint64_t command_value;
	VkCommandBufferBeginInfo begin;
	vulkan_scratch scratch;
	VkResult result;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT(command) Z_PARAM_OBJECT(info)
	ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_cmd(command, &command_value)) RETURN_THROWS();
	vulkan_scratch_init(&scratch);
	if (!vulkan_in(info, vulkan_ce_VkCommandBufferBeginInfo, vk_VkCommandBufferBeginInfo_from, &begin, &scratch)) {
		vulkan_scratch_free(&scratch); RETURN_THROWS();
	}
	result = vkBeginCommandBuffer((VkCommandBuffer) (uintptr_t) command_value, &begin);
	vulkan_scratch_free(&scratch);
	RETURN_LONG((zend_long) result);
}

ZEND_FUNCTION(vkEndCommandBuffer)
{
	zval *command; uint64_t value;
	ZEND_PARSE_PARAMETERS_START(1, 1) Z_PARAM_OBJECT(command) ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_cmd(command, &value)) RETURN_THROWS();
	RETURN_LONG((zend_long) vkEndCommandBuffer((VkCommandBuffer) (uintptr_t) value));
}

ZEND_FUNCTION(vkResetCommandBuffer)
{
	zval *command; zend_long flags; uint64_t value;
	ZEND_PARSE_PARAMETERS_START(2, 2) Z_PARAM_OBJECT(command) Z_PARAM_LONG(flags) ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_cmd(command, &value)) RETURN_THROWS();
	RETURN_LONG((zend_long) vkResetCommandBuffer((VkCommandBuffer) (uintptr_t) value, (VkCommandBufferResetFlags) flags));
}

ZEND_FUNCTION(vkCmdBeginRenderPass)
{
	zval *command, *info; zend_long contents; uint64_t value;
	VkRenderPassBeginInfo begin; vulkan_scratch scratch;
	ZEND_PARSE_PARAMETERS_START(3, 3) Z_PARAM_OBJECT(command) Z_PARAM_OBJECT(info) Z_PARAM_LONG(contents) ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_cmd(command, &value)) RETURN_THROWS();
	vulkan_scratch_init(&scratch);
	if (!vulkan_in(info, vulkan_ce_VkRenderPassBeginInfo, vk_VkRenderPassBeginInfo_from, &begin, &scratch)) { vulkan_scratch_free(&scratch); RETURN_THROWS(); }
	vkCmdBeginRenderPass((VkCommandBuffer) (uintptr_t) value, &begin, (VkSubpassContents) contents);
	vulkan_scratch_free(&scratch);
}

ZEND_FUNCTION(vkCmdEndRenderPass)
{
	zval *command; uint64_t value;
	ZEND_PARSE_PARAMETERS_START(1, 1) Z_PARAM_OBJECT(command) ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_cmd(command, &value)) RETURN_THROWS();
	vkCmdEndRenderPass((VkCommandBuffer) (uintptr_t) value);
}

ZEND_FUNCTION(vkCmdBindPipeline)
{
	zval *command, *pipeline; zend_long bind; uint64_t command_value, pipeline_value;
	ZEND_PARSE_PARAMETERS_START(3, 3) Z_PARAM_OBJECT(command) Z_PARAM_LONG(bind) Z_PARAM_OBJECT(pipeline) ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_cmd(command, &command_value) || !vulkan_handle_value(pipeline, vulkan_ce_VkPipeline, 3, &pipeline_value)) RETURN_THROWS();
	vkCmdBindPipeline((VkCommandBuffer) (uintptr_t) command_value, (VkPipelineBindPoint) bind, (VkPipeline) (uintptr_t) pipeline_value);
}

ZEND_FUNCTION(vkCmdSetViewport)
{
	zval *command, *list; zend_long first; uint64_t value; void *items = NULL; uint32_t count = 0; vulkan_scratch scratch;
	ZEND_PARSE_PARAMETERS_START(3, 3) Z_PARAM_OBJECT(command) Z_PARAM_LONG(first) Z_PARAM_ZVAL(list) ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_cmd(command, &value)) RETURN_THROWS();
	vulkan_scratch_init(&scratch);
	if (!vulkan_struct_array(list, 3, "VkViewport", vulkan_ce_VkViewport, sizeof(VkViewport), vk_VkViewport_from, &items, &count, &scratch)) { vulkan_scratch_free(&scratch); RETURN_THROWS(); }
	vkCmdSetViewport((VkCommandBuffer) (uintptr_t) value, (uint32_t) first, count, items);
	vulkan_scratch_free(&scratch);
}

ZEND_FUNCTION(vkCmdSetScissor)
{
	zval *command, *list; zend_long first; uint64_t value; void *items = NULL; uint32_t count = 0; vulkan_scratch scratch;
	ZEND_PARSE_PARAMETERS_START(3, 3) Z_PARAM_OBJECT(command) Z_PARAM_LONG(first) Z_PARAM_ZVAL(list) ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_cmd(command, &value)) RETURN_THROWS();
	vulkan_scratch_init(&scratch);
	if (!vulkan_struct_array(list, 3, "VkRect2D", vulkan_ce_VkRect2D, sizeof(VkRect2D), vk_VkRect2D_from, &items, &count, &scratch)) { vulkan_scratch_free(&scratch); RETURN_THROWS(); }
	vkCmdSetScissor((VkCommandBuffer) (uintptr_t) value, (uint32_t) first, count, items);
	vulkan_scratch_free(&scratch);
}

ZEND_FUNCTION(vkCmdSetStencilReference)
{
	zval *command; zend_long face, reference; uint64_t value;
	ZEND_PARSE_PARAMETERS_START(3, 3) Z_PARAM_OBJECT(command) Z_PARAM_LONG(face) Z_PARAM_LONG(reference) ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_cmd(command, &value)) RETURN_THROWS();
	vkCmdSetStencilReference((VkCommandBuffer) (uintptr_t) value, (VkStencilFaceFlags) face, (uint32_t) reference);
}

ZEND_FUNCTION(vkCmdBindVertexBuffers)
{
	zval *command, *buffers, *offsets, *item; zend_long first; uint64_t value;
	uint32_t count, offsets_count, i; uint64_t *handles; VkDeviceSize *device_offsets;
	ZEND_PARSE_PARAMETERS_START(4, 4) Z_PARAM_OBJECT(command) Z_PARAM_LONG(first) Z_PARAM_ZVAL(buffers) Z_PARAM_ZVAL(offsets) ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_cmd(command, &value)) RETURN_THROWS();
	if (Z_TYPE_P(buffers) != IS_ARRAY || Z_TYPE_P(offsets) != IS_ARRAY) { zend_argument_type_error(3, "must be a list"); RETURN_THROWS(); }
	count = zend_hash_num_elements(Z_ARRVAL_P(buffers));
	offsets_count = zend_hash_num_elements(Z_ARRVAL_P(offsets));
	if (count != offsets_count) { zend_argument_value_error(4, "must be the same length"); RETURN_THROWS(); }
	handles = count ? emalloc(sizeof(*handles) * count) : NULL;
	device_offsets = count ? emalloc(sizeof(*device_offsets) * count) : NULL;
	i = 0;
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(buffers), item) {
		if (!vulkan_handle_value(item, vulkan_ce_VkBuffer, 3, &handles[i])) { efree(handles); efree(device_offsets); RETURN_THROWS(); }
		i++;
	} ZEND_HASH_FOREACH_END();
	i = 0;
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(offsets), item) {
		if (Z_TYPE_P(item) != IS_LONG) { efree(handles); efree(device_offsets); zend_argument_type_error(4, "must be a list of int"); RETURN_THROWS(); }
		device_offsets[i++] = (VkDeviceSize) Z_LVAL_P(item);
	} ZEND_HASH_FOREACH_END();
	vkCmdBindVertexBuffers((VkCommandBuffer) (uintptr_t) value, (uint32_t) first, count, (const VkBuffer *) handles, device_offsets);
	if (handles) efree(handles);
	if (device_offsets) efree(device_offsets);
}

ZEND_FUNCTION(vkCmdBindIndexBuffer)
{
	zval *command, *buffer; zend_long offset, index_type; uint64_t command_value, buffer_value;
	ZEND_PARSE_PARAMETERS_START(4, 4) Z_PARAM_OBJECT(command) Z_PARAM_OBJECT(buffer) Z_PARAM_LONG(offset) Z_PARAM_LONG(index_type) ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_cmd(command, &command_value) || !vulkan_handle_value(buffer, vulkan_ce_VkBuffer, 2, &buffer_value)) RETURN_THROWS();
	vkCmdBindIndexBuffer((VkCommandBuffer) (uintptr_t) command_value, (VkBuffer) (uintptr_t) buffer_value, (VkDeviceSize) offset, (VkIndexType) index_type);
}

ZEND_FUNCTION(vkCmdBindDescriptorSets)
{
	zval *command, *layout, *sets, *offsets, *item; zend_long bind, first; uint64_t command_value, layout_value;
	uint32_t set_count, offset_count, i; uint64_t *handles; uint32_t *dynamic;
	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_OBJECT(command) Z_PARAM_LONG(bind) Z_PARAM_OBJECT(layout) Z_PARAM_LONG(first) Z_PARAM_ZVAL(sets) Z_PARAM_ZVAL(offsets)
	ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_cmd(command, &command_value) || !vulkan_handle_value(layout, vulkan_ce_VkPipelineLayout, 3, &layout_value)) RETURN_THROWS();
	if (Z_TYPE_P(sets) != IS_ARRAY || Z_TYPE_P(offsets) != IS_ARRAY) { zend_argument_type_error(5, "must be a list"); RETURN_THROWS(); }
	set_count = zend_hash_num_elements(Z_ARRVAL_P(sets));
	offset_count = zend_hash_num_elements(Z_ARRVAL_P(offsets));
	handles = set_count ? emalloc(sizeof(*handles) * set_count) : NULL;
	dynamic = offset_count ? emalloc(sizeof(*dynamic) * offset_count) : NULL;
	i = 0;
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(sets), item) {
		if (!vulkan_handle_value(item, vulkan_ce_VkDescriptorSet, 5, &handles[i])) { if (handles) efree(handles); if (dynamic) efree(dynamic); RETURN_THROWS(); }
		i++;
	} ZEND_HASH_FOREACH_END();
	i = 0;
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(offsets), item) {
		if (Z_TYPE_P(item) != IS_LONG) { if (handles) efree(handles); if (dynamic) efree(dynamic); zend_argument_type_error(6, "must be a list of int"); RETURN_THROWS(); }
		dynamic[i++] = (uint32_t) Z_LVAL_P(item);
	} ZEND_HASH_FOREACH_END();
	vkCmdBindDescriptorSets((VkCommandBuffer) (uintptr_t) command_value, (VkPipelineBindPoint) bind, (VkPipelineLayout) (uintptr_t) layout_value, (uint32_t) first, set_count, (const VkDescriptorSet *) handles, offset_count, dynamic);
	if (handles) efree(handles);
	if (dynamic) efree(dynamic);
}

ZEND_FUNCTION(vkCmdPushConstants)
{
	zval *command, *layout; zend_long stage, offset, size; zend_string *values; uint64_t command_value, layout_value;
	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_OBJECT(command) Z_PARAM_OBJECT(layout) Z_PARAM_LONG(stage) Z_PARAM_LONG(offset) Z_PARAM_LONG(size) Z_PARAM_STR(values)
	ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_cmd(command, &command_value) || !vulkan_handle_value(layout, vulkan_ce_VkPipelineLayout, 2, &layout_value)) RETURN_THROWS();
	if (size < 0 || ZSTR_LEN(values) < (size_t) size) {
		zend_argument_value_error(6, "must hold " ZEND_LONG_FMT " bytes", size);
		RETURN_THROWS();
	}
	vkCmdPushConstants((VkCommandBuffer) (uintptr_t) command_value, (VkPipelineLayout) (uintptr_t) layout_value, (VkShaderStageFlags) stage, (uint32_t) offset, (uint32_t) size, ZSTR_VAL(values));
}

ZEND_FUNCTION(vkCmdDraw)
{
	zval *command; zend_long a, b, c, d; uint64_t value;
	ZEND_PARSE_PARAMETERS_START(5, 5) Z_PARAM_OBJECT(command) Z_PARAM_LONG(a) Z_PARAM_LONG(b) Z_PARAM_LONG(c) Z_PARAM_LONG(d) ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_cmd(command, &value)) RETURN_THROWS();
	vkCmdDraw((VkCommandBuffer) (uintptr_t) value, (uint32_t) a, (uint32_t) b, (uint32_t) c, (uint32_t) d);
}

ZEND_FUNCTION(vkCmdDrawIndexed)
{
	zval *command; zend_long a, b, c, d, e; uint64_t value;
	ZEND_PARSE_PARAMETERS_START(6, 6) Z_PARAM_OBJECT(command) Z_PARAM_LONG(a) Z_PARAM_LONG(b) Z_PARAM_LONG(c) Z_PARAM_LONG(d) Z_PARAM_LONG(e) ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_cmd(command, &value)) RETURN_THROWS();
	vkCmdDrawIndexed((VkCommandBuffer) (uintptr_t) value, (uint32_t) a, (uint32_t) b, (uint32_t) c, (int32_t) d, (uint32_t) e);
}

ZEND_FUNCTION(vkCmdClearAttachments)
{
	zval *command, *attachments, *rects; uint64_t value; void *a = NULL, *r = NULL; uint32_t ac = 0, rc = 0; vulkan_scratch scratch;
	ZEND_PARSE_PARAMETERS_START(3, 3) Z_PARAM_OBJECT(command) Z_PARAM_ZVAL(attachments) Z_PARAM_ZVAL(rects) ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_cmd(command, &value)) RETURN_THROWS();
	vulkan_scratch_init(&scratch);
	if (!vulkan_struct_array(attachments, 2, "VkClearAttachment", vulkan_ce_VkClearAttachment, sizeof(VkClearAttachment), vk_VkClearAttachment_from, &a, &ac, &scratch)
		|| !vulkan_struct_array(rects, 3, "VkClearRect", vulkan_ce_VkClearRect, sizeof(VkClearRect), vk_VkClearRect_from, &r, &rc, &scratch)) {
		vulkan_scratch_free(&scratch); RETURN_THROWS();
	}
	vkCmdClearAttachments((VkCommandBuffer) (uintptr_t) value, ac, a, rc, r);
	vulkan_scratch_free(&scratch);
}

ZEND_FUNCTION(vkCmdCopyBufferToImage)
{
	zval *command, *buffer, *image, *regions; zend_long layout; uint64_t command_value, buffer_value, image_value;
	void *items = NULL; uint32_t count = 0; vulkan_scratch scratch;
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_OBJECT(command) Z_PARAM_OBJECT(buffer) Z_PARAM_OBJECT(image) Z_PARAM_LONG(layout) Z_PARAM_ZVAL(regions)
	ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_cmd(command, &command_value) || !vulkan_handle_value(buffer, vulkan_ce_VkBuffer, 2, &buffer_value) || !vulkan_handle_value(image, vulkan_ce_VkImage, 3, &image_value)) RETURN_THROWS();
	vulkan_scratch_init(&scratch);
	if (!vulkan_struct_array(regions, 5, "VkBufferImageCopy", vulkan_ce_VkBufferImageCopy, sizeof(VkBufferImageCopy), vk_VkBufferImageCopy_from, &items, &count, &scratch)) { vulkan_scratch_free(&scratch); RETURN_THROWS(); }
	vkCmdCopyBufferToImage((VkCommandBuffer) (uintptr_t) command_value, (VkBuffer) (uintptr_t) buffer_value, (VkImage) (uintptr_t) image_value, (VkImageLayout) layout, count, items);
	vulkan_scratch_free(&scratch);
}

ZEND_FUNCTION(vkCmdCopyImageToBuffer)
{
	zval *command, *image, *buffer, *regions; zend_long layout; uint64_t command_value, image_value, buffer_value;
	void *items = NULL; uint32_t count = 0; vulkan_scratch scratch;
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_OBJECT(command) Z_PARAM_OBJECT(image) Z_PARAM_LONG(layout) Z_PARAM_OBJECT(buffer) Z_PARAM_ZVAL(regions)
	ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_cmd(command, &command_value) || !vulkan_handle_value(image, vulkan_ce_VkImage, 2, &image_value) || !vulkan_handle_value(buffer, vulkan_ce_VkBuffer, 4, &buffer_value)) RETURN_THROWS();
	vulkan_scratch_init(&scratch);
	if (!vulkan_struct_array(regions, 5, "VkBufferImageCopy", vulkan_ce_VkBufferImageCopy, sizeof(VkBufferImageCopy), vk_VkBufferImageCopy_from, &items, &count, &scratch)) { vulkan_scratch_free(&scratch); RETURN_THROWS(); }
	vkCmdCopyImageToBuffer((VkCommandBuffer) (uintptr_t) command_value, (VkImage) (uintptr_t) image_value, (VkImageLayout) layout, (VkBuffer) (uintptr_t) buffer_value, count, items);
	vulkan_scratch_free(&scratch);
}

ZEND_FUNCTION(vkCmdBlitImage)
{
	zval *command, *src, *dst, *regions; zend_long src_layout, dst_layout, filter;
	uint64_t command_value, src_value, dst_value; void *items = NULL; uint32_t count = 0; vulkan_scratch scratch;
	ZEND_PARSE_PARAMETERS_START(7, 7)
		Z_PARAM_OBJECT(command) Z_PARAM_OBJECT(src) Z_PARAM_LONG(src_layout) Z_PARAM_OBJECT(dst) Z_PARAM_LONG(dst_layout) Z_PARAM_ZVAL(regions) Z_PARAM_LONG(filter)
	ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_cmd(command, &command_value) || !vulkan_handle_value(src, vulkan_ce_VkImage, 2, &src_value) || !vulkan_handle_value(dst, vulkan_ce_VkImage, 4, &dst_value)) RETURN_THROWS();
	vulkan_scratch_init(&scratch);
	if (!vulkan_struct_array(regions, 6, "VkImageBlit", vulkan_ce_VkImageBlit, sizeof(VkImageBlit), vk_VkImageBlit_from, &items, &count, &scratch)) { vulkan_scratch_free(&scratch); RETURN_THROWS(); }
	vkCmdBlitImage((VkCommandBuffer) (uintptr_t) command_value, (VkImage) (uintptr_t) src_value, (VkImageLayout) src_layout, (VkImage) (uintptr_t) dst_value, (VkImageLayout) dst_layout, count, items, (VkFilter) filter);
	vulkan_scratch_free(&scratch);
}

ZEND_FUNCTION(vkCmdPipelineBarrier)
{
	zval *command, *memory, *buffer_barriers, *image_barriers;
	zend_long src_stage, dst_stage, flags; uint64_t value;
	void *images = NULL; uint32_t image_count = 0; vulkan_scratch scratch;
	ZEND_PARSE_PARAMETERS_START(7, 7)
		Z_PARAM_OBJECT(command) Z_PARAM_LONG(src_stage) Z_PARAM_LONG(dst_stage) Z_PARAM_LONG(flags) Z_PARAM_ZVAL(memory) Z_PARAM_ZVAL(buffer_barriers) Z_PARAM_ZVAL(image_barriers)
	ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_cmd(command, &value)) RETURN_THROWS();
	if (Z_TYPE_P(memory) != IS_ARRAY || zend_hash_num_elements(Z_ARRVAL_P(memory)) != 0) {
		zend_argument_value_error(5, "VkMemoryBarrier is not bound"); RETURN_THROWS();
	}
	if (Z_TYPE_P(buffer_barriers) != IS_ARRAY || zend_hash_num_elements(Z_ARRVAL_P(buffer_barriers)) != 0) {
		zend_argument_value_error(6, "VkBufferMemoryBarrier is not bound"); RETURN_THROWS();
	}
	vulkan_scratch_init(&scratch);
	if (!vulkan_struct_array(image_barriers, 7, "VkImageMemoryBarrier", vulkan_ce_VkImageMemoryBarrier, sizeof(VkImageMemoryBarrier), vk_VkImageMemoryBarrier_from, &images, &image_count, &scratch)) {
		vulkan_scratch_free(&scratch); RETURN_THROWS();
	}
	vkCmdPipelineBarrier((VkCommandBuffer) (uintptr_t) value, (VkPipelineStageFlags) src_stage, (VkPipelineStageFlags) dst_stage, (VkDependencyFlags) flags, 0, NULL, 0, NULL, image_count, images);
	vulkan_scratch_free(&scratch);
}

ZEND_FUNCTION(vkQueueSubmit)
{
	zval *queue, *submits, *fence, *item; uint64_t queue_value, fence_value = 0;
	void *infos = NULL; uint32_t count = 0; vulkan_scratch scratch; VkResult result;
	ZEND_PARSE_PARAMETERS_START(3, 3) Z_PARAM_OBJECT(queue) Z_PARAM_ZVAL(submits) Z_PARAM_ZVAL(fence) ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_handle_value(queue, vulkan_ce_VkQueue, 1, &queue_value)) RETURN_THROWS();
	if (Z_TYPE_P(fence) == IS_NULL) fence_value = 0;
	else if (!vulkan_handle_value(fence, vulkan_ce_VkFence, 3, &fence_value)) RETURN_THROWS();
	vulkan_scratch_init(&scratch);
	if (Z_TYPE_P(submits) != IS_ARRAY) { vulkan_scratch_free(&scratch); zend_argument_type_error(2, "must be a list of VkSubmitInfo"); RETURN_THROWS(); }
	if (!vulkan_struct_array(submits, 2, "VkSubmitInfo", vulkan_ce_VkSubmitInfo, sizeof(VkSubmitInfo), vk_VkSubmitInfo_from, &infos, &count, &scratch)) { vulkan_scratch_free(&scratch); RETURN_THROWS(); }
	result = vkQueueSubmit((VkQueue) (uintptr_t) queue_value, count, infos, (VkFence) (uintptr_t) fence_value);
	vulkan_scratch_free(&scratch);
	(void) item;
	RETURN_LONG((zend_long) result);
}

ZEND_FUNCTION(vkQueueWaitIdle)
{
	zval *queue; uint64_t value;
	ZEND_PARSE_PARAMETERS_START(1, 1) Z_PARAM_OBJECT(queue) ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_handle_value(queue, vulkan_ce_VkQueue, 1, &value)) RETURN_THROWS();
	RETURN_LONG((zend_long) vkQueueWaitIdle((VkQueue) (uintptr_t) value));
}

static bool vulkan_sync_create(zval *device, zval *info, zval *allocator, zval *out, zend_class_entry *info_ce, vulkan_from_fn from, size_t size, VkResult (*create)(VkDevice, const void *, uint64_t *), zend_class_entry *out_ce, VkResult *result_out)
{
	uint64_t device_value, created = 0; vulkan_scratch scratch; void *native; VkResult result; zval boxed;
	if (Z_TYPE_P(allocator) != IS_NULL) { zend_argument_type_error(3, "must be null"); return false; }
	if (!vulkan_handle_value(device, vulkan_ce_VkDevice, 1, &device_value)) return false;
	native = emalloc(size); memset(native, 0, size);
	vulkan_scratch_init(&scratch);
	if (!vulkan_in(info, info_ce, from, native, &scratch)) { vulkan_scratch_free(&scratch); efree(native); return false; }
	result = create((VkDevice) (uintptr_t) device_value, native, &created);
	vulkan_scratch_free(&scratch); efree(native);
	if (result == VK_SUCCESS) vulkan_box(&boxed, created, out_ce, Z_OBJ_P(device)); else ZVAL_NULL(&boxed);
	vulkan_assign(out, &boxed);
	*result_out = result;
	return true;
}

static VkResult create_fence(VkDevice device, const void *info, uint64_t *out)
{
	VkFence handle = VK_NULL_HANDLE; VkResult result = vkCreateFence(device, info, NULL, &handle); *out = (uint64_t) (uintptr_t) handle; return result;
}
static VkResult create_semaphore(VkDevice device, const void *info, uint64_t *out)
{
	VkSemaphore handle = VK_NULL_HANDLE; VkResult result = vkCreateSemaphore(device, info, NULL, &handle); *out = (uint64_t) (uintptr_t) handle; return result;
}

ZEND_FUNCTION(vkCreateFence)
{
	zval *device, *info, *allocator, *out;
	VkResult result = VK_ERROR_UNKNOWN;
	ZEND_PARSE_PARAMETERS_START(4, 4) Z_PARAM_OBJECT(device) Z_PARAM_OBJECT(info) Z_PARAM_ZVAL(allocator) Z_PARAM_ZVAL(out) ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_sync_create(device, info, allocator, out, vulkan_ce_VkFenceCreateInfo, vk_VkFenceCreateInfo_from, sizeof(VkFenceCreateInfo), create_fence, vulkan_ce_VkFence, &result)) RETURN_THROWS();
	RETURN_LONG((zend_long) result);
}

ZEND_FUNCTION(vkDestroyFence)
{
	zval *device, *fence, *allocator; uint64_t device_value, fence_value;
	ZEND_PARSE_PARAMETERS_START(3, 3) Z_PARAM_OBJECT(device) Z_PARAM_OBJECT(fence) Z_PARAM_ZVAL(allocator) ZEND_PARSE_PARAMETERS_END();
	if (Z_TYPE_P(allocator) != IS_NULL) { zend_argument_type_error(3, "must be null"); RETURN_THROWS(); }
	if (!vulkan_handle_value(device, vulkan_ce_VkDevice, 1, &device_value) || !vulkan_handle_value(fence, vulkan_ce_VkFence, 2, &fence_value)) RETURN_THROWS();
	vkDestroyFence((VkDevice) (uintptr_t) device_value, (VkFence) (uintptr_t) fence_value, NULL);
	vulkan_release_tree(Z_OBJ_P(fence));
}

ZEND_FUNCTION(vkGetFenceStatus)
{
	zval *device, *fence; uint64_t device_value, fence_value;
	ZEND_PARSE_PARAMETERS_START(2, 2) Z_PARAM_OBJECT(device) Z_PARAM_OBJECT(fence) ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_handle_value(device, vulkan_ce_VkDevice, 1, &device_value) || !vulkan_handle_value(fence, vulkan_ce_VkFence, 2, &fence_value)) RETURN_THROWS();
	RETURN_LONG((zend_long) vkGetFenceStatus((VkDevice) (uintptr_t) device_value, (VkFence) (uintptr_t) fence_value));
}

static bool vulkan_fence_list(zval *list, uint64_t **out, uint32_t *count)
{
	zval *item; uint32_t n, i;
	if (Z_TYPE_P(list) != IS_ARRAY) { zend_argument_type_error(2, "must be a list of VkFence"); return false; }
	n = zend_hash_num_elements(Z_ARRVAL_P(list));
	*count = n;
	*out = n ? emalloc(sizeof(uint64_t) * n) : NULL;
	i = 0;
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(list), item) {
		if (!vulkan_handle_value(item, vulkan_ce_VkFence, 2, &(*out)[i])) { if (*out) efree(*out); return false; }
		i++;
	} ZEND_HASH_FOREACH_END();
	return true;
}

ZEND_FUNCTION(vkResetFences)
{
	zval *device, *fences; uint64_t device_value, *handles = NULL; uint32_t count = 0;
	ZEND_PARSE_PARAMETERS_START(2, 2) Z_PARAM_OBJECT(device) Z_PARAM_ZVAL(fences) ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_handle_value(device, vulkan_ce_VkDevice, 1, &device_value) || !vulkan_fence_list(fences, &handles, &count)) RETURN_THROWS();
	RETVAL_LONG((zend_long) vkResetFences((VkDevice) (uintptr_t) device_value, count, (const VkFence *) handles));
	if (handles) efree(handles);
}

ZEND_FUNCTION(vkWaitForFences)
{
	zval *device, *fences; bool wait_all; zend_long timeout; uint64_t device_value, *handles = NULL; uint32_t count = 0;
	ZEND_PARSE_PARAMETERS_START(4, 4) Z_PARAM_OBJECT(device) Z_PARAM_ZVAL(fences) Z_PARAM_BOOL(wait_all) Z_PARAM_LONG(timeout) ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_handle_value(device, vulkan_ce_VkDevice, 1, &device_value) || !vulkan_fence_list(fences, &handles, &count)) RETURN_THROWS();
	RETVAL_LONG((zend_long) vkWaitForFences((VkDevice) (uintptr_t) device_value, count, (const VkFence *) handles, wait_all ? VK_TRUE : VK_FALSE, (uint64_t) timeout));
	if (handles) efree(handles);
}

ZEND_FUNCTION(vkCreateSemaphore)
{
	zval *device, *info, *allocator, *out;
	VkResult result = VK_ERROR_UNKNOWN;
	ZEND_PARSE_PARAMETERS_START(4, 4) Z_PARAM_OBJECT(device) Z_PARAM_OBJECT(info) Z_PARAM_ZVAL(allocator) Z_PARAM_ZVAL(out) ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_sync_create(device, info, allocator, out, vulkan_ce_VkSemaphoreCreateInfo, vk_VkSemaphoreCreateInfo_from, sizeof(VkSemaphoreCreateInfo), create_semaphore, vulkan_ce_VkSemaphore, &result)) RETURN_THROWS();
	RETURN_LONG((zend_long) result);
}

ZEND_FUNCTION(vkDestroySemaphore)
{
	zval *device, *semaphore, *allocator; uint64_t device_value, semaphore_value;
	ZEND_PARSE_PARAMETERS_START(3, 3) Z_PARAM_OBJECT(device) Z_PARAM_OBJECT(semaphore) Z_PARAM_ZVAL(allocator) ZEND_PARSE_PARAMETERS_END();
	if (Z_TYPE_P(allocator) != IS_NULL) { zend_argument_type_error(3, "must be null"); RETURN_THROWS(); }
	if (!vulkan_handle_value(device, vulkan_ce_VkDevice, 1, &device_value) || !vulkan_handle_value(semaphore, vulkan_ce_VkSemaphore, 2, &semaphore_value)) RETURN_THROWS();
	vkDestroySemaphore((VkDevice) (uintptr_t) device_value, (VkSemaphore) (uintptr_t) semaphore_value, NULL);
	vulkan_release_tree(Z_OBJ_P(semaphore));
}
