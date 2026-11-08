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

ZEND_METHOD(VkMemoryToImageCopy, __construct)
{
	ZEND_PARSE_PARAMETERS_NONE();
	vulkan_init_nested(Z_OBJ_P(ZEND_THIS), "imageSubresource", vulkan_ce_VkImageSubresourceLayers);
	vulkan_init_nested(Z_OBJ_P(ZEND_THIS), "imageOffset", vulkan_ce_VkOffset3D);
	vulkan_init_nested(Z_OBJ_P(ZEND_THIS), "imageExtent", vulkan_ce_VkExtent3D);
}

ZEND_METHOD(VkImageToMemoryCopy, __construct)
{
	ZEND_PARSE_PARAMETERS_NONE();
	vulkan_init_nested(Z_OBJ_P(ZEND_THIS), "imageSubresource", vulkan_ce_VkImageSubresourceLayers);
	vulkan_init_nested(Z_OBJ_P(ZEND_THIS), "imageOffset", vulkan_ce_VkOffset3D);
	vulkan_init_nested(Z_OBJ_P(ZEND_THIS), "imageExtent", vulkan_ce_VkExtent3D);
}

ZEND_METHOD(VkHostImageLayoutTransitionInfo, __construct)
{
	ZEND_PARSE_PARAMETERS_NONE();
	vulkan_init_nested(Z_OBJ_P(ZEND_THIS), "subresourceRange", vulkan_ce_VkImageSubresourceRange);
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

#define ALLOCATOR(z) ((const VkAllocationCallbacks *) (uintptr_t) (z))

static bool vulkan_cmd(zval *zv, uint64_t *out)
{
	return vulkan_handle_value(zv, vulkan_ce_VkCommandBuffer, 1, out);
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
	S(VkImageBlit); S(VkMemoryBarrier); S(VkBufferMemoryBarrier); S(VkImageMemoryBarrier); S(VkSubmitInfo);
	S(VkFenceCreateInfo); S(VkSemaphoreCreateInfo); S(VkClearAttachment); S(VkClearRect);
	S(VkMemoryToImageCopy); S(VkImageToMemoryCopy); S(VkCopyMemoryToImageInfo); S(VkCopyImageToMemoryInfo); S(VkHostImageLayoutTransitionInfo); S(VkPhysicalDeviceHostImageCopyFeatures);
#undef H
#undef S
}

ZEND_FUNCTION(vkCreateCommandPool)
{
	zval *device, *info, *out;
	zend_long allocator;
	uint64_t device_value;
	VkCommandPoolCreateInfo create;
	VkCommandPool pool = VK_NULL_HANDLE;
	vulkan_scratch scratch;
	VkResult result;
	zval boxed;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT(device) Z_PARAM_OBJECT(info) Z_PARAM_LONG(allocator) Z_PARAM_ZVAL(out)
	ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_handle_value(device, vulkan_ce_VkDevice, 1, &device_value)) RETURN_THROWS();
	vulkan_scratch_init(&scratch);
	if (!vulkan_arg_struct(info, vulkan_ce_VkCommandPoolCreateInfo, vk_VkCommandPoolCreateInfo_from, &create, &scratch)) {
		vulkan_scratch_free(&scratch);
		RETURN_THROWS();
	}
	result = vkCreateCommandPool((VkDevice) (uintptr_t) device_value, &create, ALLOCATOR(allocator), &pool);
	vulkan_scratch_free(&scratch);
	if (result == VK_SUCCESS) vulkan_box(&boxed, (uint64_t) (uintptr_t) pool, vulkan_ce_VkCommandPool, Z_OBJ_P(device));
	else ZVAL_NULL(&boxed);
	vulkan_assign(out, &boxed);
	RETURN_LONG((zend_long) result);
}

ZEND_FUNCTION(vkDestroyCommandPool)
{
	zval *device, *pool;
	zend_long allocator;
	uint64_t device_value, pool_value;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT(device) Z_PARAM_OBJECT_OR_NULL(pool) Z_PARAM_LONG(allocator)
	ZEND_PARSE_PARAMETERS_END();
	pool_value = 0;
	if (!vulkan_handle_value(device, vulkan_ce_VkDevice, 1, &device_value) || (pool && !vulkan_handle_value(pool, vulkan_ce_VkCommandPool, 2, &pool_value))) RETURN_THROWS();
	vkDestroyCommandPool((VkDevice) (uintptr_t) device_value, (VkCommandPool) (uintptr_t) pool_value, ALLOCATOR(allocator));
	if (pool) vulkan_release_tree(Z_OBJ_P(pool));
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
	if (!vulkan_arg_struct(info, vulkan_ce_VkCommandBufferAllocateInfo, vk_VkCommandBufferAllocateInfo_from, &allocate, &scratch)) {
		vulkan_scratch_free(&scratch);
		RETURN_THROWS();
	}
	/* Vulkan writes commandBufferCount handles: the array is sized from that member. */
	buffers = allocate.commandBufferCount ? safe_emalloc(allocate.commandBufferCount, sizeof(*buffers), 0) : NULL;
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
	zend_long count;
	uint64_t device_value, pool_value, *handles = NULL;
	vulkan_scratch scratch;
	uint32_t i = 0;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT(device) Z_PARAM_OBJECT(pool) Z_PARAM_LONG(count) Z_PARAM_ARRAY(list)
	ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_handle_value(device, vulkan_ce_VkDevice, 1, &device_value) || !vulkan_handle_value(pool, vulkan_ce_VkCommandPool, 2, &pool_value)) RETURN_THROWS();
	vulkan_scratch_init(&scratch);
	if (!vulkan_arg_handles(list, count, 3, 4, vulkan_ce_VkCommandBuffer, &handles, &scratch)) {
		vulkan_scratch_free(&scratch);
		RETURN_THROWS();
	}
	vkFreeCommandBuffers((VkDevice) (uintptr_t) device_value, (VkCommandPool) (uintptr_t) pool_value, (uint32_t) count, (const VkCommandBuffer *) handles);
	vulkan_scratch_free(&scratch);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(list), item) {
		if (i++ == (uint32_t) count) break;
		vulkan_release_tree(Z_OBJ_P(item));
	} ZEND_HASH_FOREACH_END();
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
	if (!vulkan_arg_struct(info, vulkan_ce_VkCommandBufferBeginInfo, vk_VkCommandBufferBeginInfo_from, &begin, &scratch)) {
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
	if (!vulkan_arg_struct(info, vulkan_ce_VkRenderPassBeginInfo, vk_VkRenderPassBeginInfo_from, &begin, &scratch)) { vulkan_scratch_free(&scratch); RETURN_THROWS(); }
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
	zval *command, *list; zend_long first, count; uint64_t value; void *items; vulkan_scratch scratch;
	ZEND_PARSE_PARAMETERS_START(4, 4) Z_PARAM_OBJECT(command) Z_PARAM_LONG(first) Z_PARAM_LONG(count) Z_PARAM_ZVAL(list) ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_cmd(command, &value)) RETURN_THROWS();
	vulkan_scratch_init(&scratch);
	if (!vulkan_arg_structs(list, count, 3, 4, vulkan_ce_VkViewport, sizeof(VkViewport), vk_VkViewport_from, &items, &scratch)) { vulkan_scratch_free(&scratch); RETURN_THROWS(); }
	vkCmdSetViewport((VkCommandBuffer) (uintptr_t) value, (uint32_t) first, (uint32_t) count, items);
	vulkan_scratch_free(&scratch);
}

ZEND_FUNCTION(vkCmdSetScissor)
{
	zval *command, *list; zend_long first, count; uint64_t value; void *items; vulkan_scratch scratch;
	ZEND_PARSE_PARAMETERS_START(4, 4) Z_PARAM_OBJECT(command) Z_PARAM_LONG(first) Z_PARAM_LONG(count) Z_PARAM_ZVAL(list) ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_cmd(command, &value)) RETURN_THROWS();
	vulkan_scratch_init(&scratch);
	if (!vulkan_arg_structs(list, count, 3, 4, vulkan_ce_VkRect2D, sizeof(VkRect2D), vk_VkRect2D_from, &items, &scratch)) { vulkan_scratch_free(&scratch); RETURN_THROWS(); }
	vkCmdSetScissor((VkCommandBuffer) (uintptr_t) value, (uint32_t) first, (uint32_t) count, items);
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
	zval *command, *buffers, *offsets; zend_long first, count; uint64_t value, *handles, *device_offsets; vulkan_scratch scratch;
	ZEND_PARSE_PARAMETERS_START(5, 5) Z_PARAM_OBJECT(command) Z_PARAM_LONG(first) Z_PARAM_LONG(count) Z_PARAM_ZVAL(buffers) Z_PARAM_ZVAL(offsets) ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_cmd(command, &value)) RETURN_THROWS();
	vulkan_scratch_init(&scratch);
	if (!vulkan_arg_handles(buffers, count, 3, 4, vulkan_ce_VkBuffer, &handles, &scratch)
		|| !vulkan_arg_u64s(offsets, count, 3, 5, &device_offsets, &scratch)) {
		vulkan_scratch_free(&scratch); RETURN_THROWS();
	}
	vkCmdBindVertexBuffers((VkCommandBuffer) (uintptr_t) value, (uint32_t) first, (uint32_t) count, (const VkBuffer *) handles, (const VkDeviceSize *) device_offsets);
	vulkan_scratch_free(&scratch);
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
	zval *command, *layout, *sets, *offsets; zend_long bind, first, set_count, offset_count;
	uint64_t command_value, layout_value, *handles; uint32_t *dynamic; vulkan_scratch scratch;
	ZEND_PARSE_PARAMETERS_START(8, 8)
		Z_PARAM_OBJECT(command) Z_PARAM_LONG(bind) Z_PARAM_OBJECT(layout) Z_PARAM_LONG(first)
		Z_PARAM_LONG(set_count) Z_PARAM_ZVAL(sets) Z_PARAM_LONG(offset_count) Z_PARAM_ZVAL(offsets)
	ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_cmd(command, &command_value) || !vulkan_handle_value(layout, vulkan_ce_VkPipelineLayout, 3, &layout_value)) RETURN_THROWS();
	vulkan_scratch_init(&scratch);
	if (!vulkan_arg_handles(sets, set_count, 5, 6, vulkan_ce_VkDescriptorSet, &handles, &scratch)
		|| !vulkan_arg_u32s(offsets, offset_count, 7, 8, &dynamic, &scratch)) {
		vulkan_scratch_free(&scratch); RETURN_THROWS();
	}
	vkCmdBindDescriptorSets((VkCommandBuffer) (uintptr_t) command_value, (VkPipelineBindPoint) bind, (VkPipelineLayout) (uintptr_t) layout_value, (uint32_t) first, (uint32_t) set_count, (const VkDescriptorSet *) handles, (uint32_t) offset_count, dynamic);
	vulkan_scratch_free(&scratch);
}

ZEND_FUNCTION(vkCmdPushConstants)
{
	zval *command, *layout; zend_long stage, offset, size; zend_string *values; uint64_t command_value, layout_value;
	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_OBJECT(command) Z_PARAM_OBJECT(layout) Z_PARAM_LONG(stage) Z_PARAM_LONG(offset) Z_PARAM_LONG(size) Z_PARAM_STR(values)
	ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_cmd(command, &command_value) || !vulkan_handle_value(layout, vulkan_ce_VkPipelineLayout, 2, &layout_value)) RETURN_THROWS();
	if (!vulkan_bytes_length(ZSTR_LEN(values), (uint32_t) size, 6, NULL)) RETURN_THROWS();
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
	zval *command, *attachments, *rects; zend_long ac, rc; uint64_t value; void *a, *r; vulkan_scratch scratch;
	ZEND_PARSE_PARAMETERS_START(5, 5) Z_PARAM_OBJECT(command) Z_PARAM_LONG(ac) Z_PARAM_ZVAL(attachments) Z_PARAM_LONG(rc) Z_PARAM_ZVAL(rects) ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_cmd(command, &value)) RETURN_THROWS();
	vulkan_scratch_init(&scratch);
	if (!vulkan_arg_structs(attachments, ac, 2, 3, vulkan_ce_VkClearAttachment, sizeof(VkClearAttachment), vk_VkClearAttachment_from, &a, &scratch)
		|| !vulkan_arg_structs(rects, rc, 4, 5, vulkan_ce_VkClearRect, sizeof(VkClearRect), vk_VkClearRect_from, &r, &scratch)) {
		vulkan_scratch_free(&scratch); RETURN_THROWS();
	}
	vkCmdClearAttachments((VkCommandBuffer) (uintptr_t) value, (uint32_t) ac, a, (uint32_t) rc, r);
	vulkan_scratch_free(&scratch);
}

ZEND_FUNCTION(vkCmdCopyBufferToImage)
{
	zval *command, *buffer, *image, *regions; zend_long layout, count; uint64_t command_value, buffer_value, image_value;
	void *items; vulkan_scratch scratch;
	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_OBJECT(command) Z_PARAM_OBJECT(buffer) Z_PARAM_OBJECT(image) Z_PARAM_LONG(layout) Z_PARAM_LONG(count) Z_PARAM_ZVAL(regions)
	ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_cmd(command, &command_value) || !vulkan_handle_value(buffer, vulkan_ce_VkBuffer, 2, &buffer_value) || !vulkan_handle_value(image, vulkan_ce_VkImage, 3, &image_value)) RETURN_THROWS();
	vulkan_scratch_init(&scratch);
	if (!vulkan_arg_structs(regions, count, 5, 6, vulkan_ce_VkBufferImageCopy, sizeof(VkBufferImageCopy), vk_VkBufferImageCopy_from, &items, &scratch)) { vulkan_scratch_free(&scratch); RETURN_THROWS(); }
	vkCmdCopyBufferToImage((VkCommandBuffer) (uintptr_t) command_value, (VkBuffer) (uintptr_t) buffer_value, (VkImage) (uintptr_t) image_value, (VkImageLayout) layout, (uint32_t) count, items);
	vulkan_scratch_free(&scratch);
}

ZEND_FUNCTION(vkCmdCopyImageToBuffer)
{
	zval *command, *image, *buffer, *regions; zend_long layout, count; uint64_t command_value, image_value, buffer_value;
	void *items; vulkan_scratch scratch;
	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_OBJECT(command) Z_PARAM_OBJECT(image) Z_PARAM_LONG(layout) Z_PARAM_OBJECT(buffer) Z_PARAM_LONG(count) Z_PARAM_ZVAL(regions)
	ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_cmd(command, &command_value) || !vulkan_handle_value(image, vulkan_ce_VkImage, 2, &image_value) || !vulkan_handle_value(buffer, vulkan_ce_VkBuffer, 4, &buffer_value)) RETURN_THROWS();
	vulkan_scratch_init(&scratch);
	if (!vulkan_arg_structs(regions, count, 5, 6, vulkan_ce_VkBufferImageCopy, sizeof(VkBufferImageCopy), vk_VkBufferImageCopy_from, &items, &scratch)) { vulkan_scratch_free(&scratch); RETURN_THROWS(); }
	vkCmdCopyImageToBuffer((VkCommandBuffer) (uintptr_t) command_value, (VkImage) (uintptr_t) image_value, (VkImageLayout) layout, (VkBuffer) (uintptr_t) buffer_value, (uint32_t) count, items);
	vulkan_scratch_free(&scratch);
}

ZEND_FUNCTION(vkCmdUpdateBuffer)
{
	zval *command, *buffer; zend_long offset, size; zend_string *data; uint64_t command_value, buffer_value;
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_OBJECT(command) Z_PARAM_OBJECT(buffer) Z_PARAM_LONG(offset) Z_PARAM_LONG(size) Z_PARAM_STR(data)
	ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_cmd(command, &command_value) || !vulkan_handle_value(buffer, vulkan_ce_VkBuffer, 2, &buffer_value) || !vulkan_bytes_length(ZSTR_LEN(data), (size_t) size, 5, "pData")) RETURN_THROWS();
	vkCmdUpdateBuffer((VkCommandBuffer) (uintptr_t) command_value, (VkBuffer) (uintptr_t) buffer_value, (VkDeviceSize) offset, (VkDeviceSize) size, ZSTR_VAL(data));
}

ZEND_FUNCTION(vkCopyMemoryToImage)
{
	zval *device, *info; uint64_t device_value; VkCopyMemoryToImageInfo raw; vulkan_scratch scratch; VkResult result;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT(device) Z_PARAM_OBJECT(info)
	ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_handle_value(device, vulkan_ce_VkDevice, 1, &device_value)) RETURN_THROWS();
	vulkan_scratch_init(&scratch);
	if (!vulkan_arg_struct(info, vulkan_ce_VkCopyMemoryToImageInfo, vk_VkCopyMemoryToImageInfo_from, &raw, &scratch)) { vulkan_scratch_free(&scratch); RETURN_THROWS(); }
	result = vkCopyMemoryToImage((VkDevice) (uintptr_t) device_value, &raw);
	vulkan_scratch_free(&scratch);
	RETURN_LONG((zend_long) result);
}

/* Vulkan fills a copy of each region's string; on success the bytes go back into the region objects. */
ZEND_FUNCTION(vkCopyImageToMemory)
{
	zval *device, *info, *regions, *region; uint64_t device_value; VkCopyImageToMemoryInfo raw; vulkan_scratch scratch; VkResult result; uint32_t i = 0;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT(device) Z_PARAM_OBJECT(info)
	ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_handle_value(device, vulkan_ce_VkDevice, 1, &device_value)) RETURN_THROWS();
	vulkan_scratch_init(&scratch);
	if (!vulkan_arg_struct(info, vulkan_ce_VkCopyImageToMemoryInfo, vk_VkCopyImageToMemoryInfo_from, &raw, &scratch)) { vulkan_scratch_free(&scratch); RETURN_THROWS(); }
	result = vkCopyImageToMemory((VkDevice) (uintptr_t) device_value, &raw);
	if (result == VK_SUCCESS) {
		regions = zend_read_property(Z_OBJCE_P(info), Z_OBJ_P(info), "pRegions", sizeof("pRegions") - 1, 0, NULL);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(regions), region) {
			zval *held;
			if (i == raw.regionCount) break;
			held = zend_read_property(Z_OBJCE_P(region), Z_OBJ_P(region), "pHostPointer", sizeof("pHostPointer") - 1, 0, NULL);
			vulkan_set_bytes(Z_OBJ_P(region), "pHostPointer", raw.pRegions[i].pHostPointer, Z_STRLEN_P(held));
			i++;
		} ZEND_HASH_FOREACH_END();
	}
	vulkan_scratch_free(&scratch);
	RETURN_LONG((zend_long) result);
}

ZEND_FUNCTION(vkTransitionImageLayout)
{
	zval *device, *transitions; zend_long count; uint64_t device_value; void *items; vulkan_scratch scratch; VkResult result;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT(device) Z_PARAM_LONG(count) Z_PARAM_ZVAL(transitions)
	ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_handle_value(device, vulkan_ce_VkDevice, 1, &device_value)) RETURN_THROWS();
	vulkan_scratch_init(&scratch);
	if (!vulkan_arg_structs(transitions, count, 2, 3, vulkan_ce_VkHostImageLayoutTransitionInfo, sizeof(VkHostImageLayoutTransitionInfo), vk_VkHostImageLayoutTransitionInfo_from, &items, &scratch)) { vulkan_scratch_free(&scratch); RETURN_THROWS(); }
	result = vkTransitionImageLayout((VkDevice) (uintptr_t) device_value, (uint32_t) count, items);
	vulkan_scratch_free(&scratch);
	RETURN_LONG((zend_long) result);
}

ZEND_FUNCTION(vkCmdBlitImage)
{
	zval *command, *src, *dst, *regions; zend_long src_layout, dst_layout, count, filter;
	uint64_t command_value, src_value, dst_value; void *items; vulkan_scratch scratch;
	ZEND_PARSE_PARAMETERS_START(8, 8)
		Z_PARAM_OBJECT(command) Z_PARAM_OBJECT(src) Z_PARAM_LONG(src_layout) Z_PARAM_OBJECT(dst) Z_PARAM_LONG(dst_layout) Z_PARAM_LONG(count) Z_PARAM_ZVAL(regions) Z_PARAM_LONG(filter)
	ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_cmd(command, &command_value) || !vulkan_handle_value(src, vulkan_ce_VkImage, 2, &src_value) || !vulkan_handle_value(dst, vulkan_ce_VkImage, 4, &dst_value)) RETURN_THROWS();
	vulkan_scratch_init(&scratch);
	if (!vulkan_arg_structs(regions, count, 6, 7, vulkan_ce_VkImageBlit, sizeof(VkImageBlit), vk_VkImageBlit_from, &items, &scratch)) { vulkan_scratch_free(&scratch); RETURN_THROWS(); }
	vkCmdBlitImage((VkCommandBuffer) (uintptr_t) command_value, (VkImage) (uintptr_t) src_value, (VkImageLayout) src_layout, (VkImage) (uintptr_t) dst_value, (VkImageLayout) dst_layout, (uint32_t) count, items, (VkFilter) filter);
	vulkan_scratch_free(&scratch);
}

ZEND_FUNCTION(vkCmdPipelineBarrier)
{
	zval *command, *memory, *buffers, *images;
	zend_long src_stage, dst_stage, flags, memory_count, buffer_count, image_count; uint64_t value;
	void *globals, *buffer_items, *image_items; vulkan_scratch scratch;
	ZEND_PARSE_PARAMETERS_START(10, 10)
		Z_PARAM_OBJECT(command) Z_PARAM_LONG(src_stage) Z_PARAM_LONG(dst_stage) Z_PARAM_LONG(flags)
		Z_PARAM_LONG(memory_count) Z_PARAM_ZVAL(memory) Z_PARAM_LONG(buffer_count) Z_PARAM_ZVAL(buffers) Z_PARAM_LONG(image_count) Z_PARAM_ZVAL(images)
	ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_cmd(command, &value)) RETURN_THROWS();
	vulkan_scratch_init(&scratch);
	if (!vulkan_arg_structs(memory, memory_count, 5, 6, vulkan_ce_VkMemoryBarrier, sizeof(VkMemoryBarrier), vk_VkMemoryBarrier_from, &globals, &scratch)
		|| !vulkan_arg_structs(buffers, buffer_count, 7, 8, vulkan_ce_VkBufferMemoryBarrier, sizeof(VkBufferMemoryBarrier), vk_VkBufferMemoryBarrier_from, &buffer_items, &scratch)
		|| !vulkan_arg_structs(images, image_count, 9, 10, vulkan_ce_VkImageMemoryBarrier, sizeof(VkImageMemoryBarrier), vk_VkImageMemoryBarrier_from, &image_items, &scratch)) {
		vulkan_scratch_free(&scratch); RETURN_THROWS();
	}
	vkCmdPipelineBarrier((VkCommandBuffer) (uintptr_t) value, (VkPipelineStageFlags) src_stage, (VkPipelineStageFlags) dst_stage, (VkDependencyFlags) flags,
		(uint32_t) memory_count, globals, (uint32_t) buffer_count, buffer_items, (uint32_t) image_count, image_items);
	vulkan_scratch_free(&scratch);
}

ZEND_FUNCTION(vkQueueSubmit)
{
	zval *queue, *submits, *fence; zend_long count; uint64_t queue_value, fence_value = 0;
	void *infos; vulkan_scratch scratch; VkResult result;
	ZEND_PARSE_PARAMETERS_START(4, 4) Z_PARAM_OBJECT(queue) Z_PARAM_LONG(count) Z_PARAM_ZVAL(submits) Z_PARAM_OBJECT_OR_NULL(fence) ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_handle_value(queue, vulkan_ce_VkQueue, 1, &queue_value)) RETURN_THROWS();
	if (fence && !vulkan_handle_value(fence, vulkan_ce_VkFence, 4, &fence_value)) RETURN_THROWS();
	vulkan_scratch_init(&scratch);
	if (!vulkan_arg_structs(submits, count, 2, 3, vulkan_ce_VkSubmitInfo, sizeof(VkSubmitInfo), vk_VkSubmitInfo_from, &infos, &scratch)) { vulkan_scratch_free(&scratch); RETURN_THROWS(); }
	result = vkQueueSubmit((VkQueue) (uintptr_t) queue_value, (uint32_t) count, infos, (VkFence) (uintptr_t) fence_value);
	vulkan_scratch_free(&scratch);
	RETURN_LONG((zend_long) result);
}

ZEND_FUNCTION(vkQueueWaitIdle)
{
	zval *queue; uint64_t value;
	ZEND_PARSE_PARAMETERS_START(1, 1) Z_PARAM_OBJECT(queue) ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_handle_value(queue, vulkan_ce_VkQueue, 1, &value)) RETURN_THROWS();
	RETURN_LONG((zend_long) vkQueueWaitIdle((VkQueue) (uintptr_t) value));
}

static bool vulkan_sync_create(zval *device, zval *info, zend_long allocator, zval *out, zend_class_entry *info_ce, vulkan_from_fn from, size_t size, VkResult (*create)(VkDevice, const void *, const VkAllocationCallbacks *, uint64_t *), zend_class_entry *out_ce, VkResult *result_out)
{
	uint64_t device_value, created = 0; vulkan_scratch scratch; void *native; VkResult result; zval boxed;
	if (!vulkan_handle_value(device, vulkan_ce_VkDevice, 1, &device_value)) return false;
	native = ecalloc(1, size);
	vulkan_scratch_init(&scratch);
	if (!vulkan_arg_struct(info, info_ce, from, native, &scratch)) { vulkan_scratch_free(&scratch); efree(native); return false; }
	result = create((VkDevice) (uintptr_t) device_value, native, ALLOCATOR(allocator), &created);
	vulkan_scratch_free(&scratch); efree(native);
	if (result == VK_SUCCESS) vulkan_box(&boxed, created, out_ce, Z_OBJ_P(device)); else ZVAL_NULL(&boxed);
	vulkan_assign(out, &boxed);
	*result_out = result;
	return true;
}

static VkResult create_fence(VkDevice device, const void *info, const VkAllocationCallbacks *allocator, uint64_t *out)
{
	VkFence handle = VK_NULL_HANDLE; VkResult result = vkCreateFence(device, info, allocator, &handle); *out = (uint64_t) (uintptr_t) handle; return result;
}
static VkResult create_semaphore(VkDevice device, const void *info, const VkAllocationCallbacks *allocator, uint64_t *out)
{
	VkSemaphore handle = VK_NULL_HANDLE; VkResult result = vkCreateSemaphore(device, info, allocator, &handle); *out = (uint64_t) (uintptr_t) handle; return result;
}

ZEND_FUNCTION(vkCreateFence)
{
	zval *device, *info, *out; zend_long allocator;
	VkResult result = VK_ERROR_UNKNOWN;
	ZEND_PARSE_PARAMETERS_START(4, 4) Z_PARAM_OBJECT(device) Z_PARAM_OBJECT(info) Z_PARAM_LONG(allocator) Z_PARAM_ZVAL(out) ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_sync_create(device, info, allocator, out, vulkan_ce_VkFenceCreateInfo, vk_VkFenceCreateInfo_from, sizeof(VkFenceCreateInfo), create_fence, vulkan_ce_VkFence, &result)) RETURN_THROWS();
	RETURN_LONG((zend_long) result);
}

ZEND_FUNCTION(vkDestroyFence)
{
	zval *device, *fence; zend_long allocator; uint64_t device_value, fence_value = 0;
	ZEND_PARSE_PARAMETERS_START(3, 3) Z_PARAM_OBJECT(device) Z_PARAM_OBJECT_OR_NULL(fence) Z_PARAM_LONG(allocator) ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_handle_value(device, vulkan_ce_VkDevice, 1, &device_value) || (fence && !vulkan_handle_value(fence, vulkan_ce_VkFence, 2, &fence_value))) RETURN_THROWS();
	vkDestroyFence((VkDevice) (uintptr_t) device_value, (VkFence) (uintptr_t) fence_value, ALLOCATOR(allocator));
	if (fence) vulkan_release_tree(Z_OBJ_P(fence));
}

ZEND_FUNCTION(vkGetFenceStatus)
{
	zval *device, *fence; uint64_t device_value, fence_value;
	ZEND_PARSE_PARAMETERS_START(2, 2) Z_PARAM_OBJECT(device) Z_PARAM_OBJECT(fence) ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_handle_value(device, vulkan_ce_VkDevice, 1, &device_value) || !vulkan_handle_value(fence, vulkan_ce_VkFence, 2, &fence_value)) RETURN_THROWS();
	RETURN_LONG((zend_long) vkGetFenceStatus((VkDevice) (uintptr_t) device_value, (VkFence) (uintptr_t) fence_value));
}

ZEND_FUNCTION(vkResetFences)
{
	zval *device, *fences; zend_long count; uint64_t device_value, *handles; vulkan_scratch scratch;
	ZEND_PARSE_PARAMETERS_START(3, 3) Z_PARAM_OBJECT(device) Z_PARAM_LONG(count) Z_PARAM_ZVAL(fences) ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_handle_value(device, vulkan_ce_VkDevice, 1, &device_value)) RETURN_THROWS();
	vulkan_scratch_init(&scratch);
	if (!vulkan_arg_handles(fences, count, 2, 3, vulkan_ce_VkFence, &handles, &scratch)) { vulkan_scratch_free(&scratch); RETURN_THROWS(); }
	RETVAL_LONG((zend_long) vkResetFences((VkDevice) (uintptr_t) device_value, (uint32_t) count, (const VkFence *) handles));
	vulkan_scratch_free(&scratch);
}

ZEND_FUNCTION(vkWaitForFences)
{
	zval *device, *fences; zend_long count; bool wait_all; zend_long timeout; uint64_t device_value, *handles; vulkan_scratch scratch;
	ZEND_PARSE_PARAMETERS_START(5, 5) Z_PARAM_OBJECT(device) Z_PARAM_LONG(count) Z_PARAM_ZVAL(fences) Z_PARAM_BOOL(wait_all) Z_PARAM_LONG(timeout) ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_handle_value(device, vulkan_ce_VkDevice, 1, &device_value)) RETURN_THROWS();
	vulkan_scratch_init(&scratch);
	if (!vulkan_arg_handles(fences, count, 2, 3, vulkan_ce_VkFence, &handles, &scratch)) { vulkan_scratch_free(&scratch); RETURN_THROWS(); }
	RETVAL_LONG((zend_long) vkWaitForFences((VkDevice) (uintptr_t) device_value, (uint32_t) count, (const VkFence *) handles, wait_all ? VK_TRUE : VK_FALSE, (uint64_t) timeout));
	vulkan_scratch_free(&scratch);
}

ZEND_FUNCTION(vkCreateSemaphore)
{
	zval *device, *info, *out; zend_long allocator;
	VkResult result = VK_ERROR_UNKNOWN;
	ZEND_PARSE_PARAMETERS_START(4, 4) Z_PARAM_OBJECT(device) Z_PARAM_OBJECT(info) Z_PARAM_LONG(allocator) Z_PARAM_ZVAL(out) ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_sync_create(device, info, allocator, out, vulkan_ce_VkSemaphoreCreateInfo, vk_VkSemaphoreCreateInfo_from, sizeof(VkSemaphoreCreateInfo), create_semaphore, vulkan_ce_VkSemaphore, &result)) RETURN_THROWS();
	RETURN_LONG((zend_long) result);
}

ZEND_FUNCTION(vkDestroySemaphore)
{
	zval *device, *semaphore; zend_long allocator; uint64_t device_value, semaphore_value = 0;
	ZEND_PARSE_PARAMETERS_START(3, 3) Z_PARAM_OBJECT(device) Z_PARAM_OBJECT_OR_NULL(semaphore) Z_PARAM_LONG(allocator) ZEND_PARSE_PARAMETERS_END();
	if (!vulkan_handle_value(device, vulkan_ce_VkDevice, 1, &device_value) || (semaphore && !vulkan_handle_value(semaphore, vulkan_ce_VkSemaphore, 2, &semaphore_value))) RETURN_THROWS();
	vkDestroySemaphore((VkDevice) (uintptr_t) device_value, (VkSemaphore) (uintptr_t) semaphore_value, ALLOCATOR(allocator));
	if (semaphore) vulkan_release_tree(Z_OBJ_P(semaphore));
}
