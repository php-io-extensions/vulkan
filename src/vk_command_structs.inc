static bool vulkan_clear_color(zend_object *obj, VkClearColorValue *dst)
{
	return vulkan_fixed_floats(obj, "float32", dst->float32, 4);
}

static bool vulkan_clear_value(zend_object *obj, VkClearValue *dst, vulkan_scratch *scratch, HashTable *visited)
{
	zval *color = zend_read_property(obj->ce, obj, "color", sizeof("color") - 1, 0, NULL);
	zval *depth = zend_read_property(obj->ce, obj, "depthStencil", sizeof("depthStencil") - 1, 0, NULL);
	bool has_color, has_depth;

	(void) scratch;
	(void) visited;
	if (color == NULL || depth == NULL || EG(exception) != NULL) {
		return false;
	}
	has_color = Z_TYPE_P(color) != IS_NULL;
	has_depth = Z_TYPE_P(depth) != IS_NULL;
	if (has_color == has_depth) {
		zend_value_error("VkClearValue holds one of color or depthStencil");
		return false;
	}
	if (has_color) {
		if (Z_TYPE_P(color) != IS_OBJECT) {
			zend_type_error("VkClearValue::$color must be a VkClearColorValue");
			return false;
		}
		return vulkan_clear_color(Z_OBJ_P(color), &dst->color);
	}
	if (Z_TYPE_P(depth) != IS_OBJECT) {
		zend_type_error("VkClearValue::$depthStencil must be a VkClearDepthStencilValue");
		return false;
	}
	return vulkan_float(Z_OBJ_P(depth), "depth", &dst->depthStencil.depth)
		&& vulkan_u32(Z_OBJ_P(depth), "stencil", &dst->depthStencil.stencil);
}

/* The fixed VkOffset3D[2]: a short list is zero-filled, as a C initializer is. */
static bool vulkan_offset3_list(zend_object *obj, const char *name, VkOffset3D *dst, vulkan_scratch *scratch, HashTable *visited)
{
	zval *zv = zend_read_property(obj->ce, obj, name, strlen(name), 0, NULL);
	uint32_t count = 2;
	void *items = NULL;

	if (zv == NULL || EG(exception) != NULL) {
		return false;
	}
	if (Z_TYPE_P(zv) == IS_ARRAY && zend_hash_num_elements(Z_ARRVAL_P(zv)) < count) {
		count = zend_hash_num_elements(Z_ARRVAL_P(zv));
	}
	memset(dst, 0, sizeof(VkOffset3D) * 2);
	if (!vulkan_struct_list(obj, name, vulkan_ce_VkOffset3D, sizeof(VkOffset3D), vk_VkOffset3D_from, &items, &count, scratch, visited)) {
		return false;
	}
	if (count > 0) {
		memcpy(dst, items, sizeof(VkOffset3D) * count);
	}
	return true;
}

bool vk_VkCommandPoolCreateInfo_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkCommandPoolCreateInfo *dst = raw;
	memset(dst, 0, sizeof(*dst));
	dst->sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
	if (!vulkan_enter(obj, visited) || !vulkan_pnext(obj, &dst->pNext, scratch, visited)) return false;
	return vulkan_u32(obj, "flags", &dst->flags) && vulkan_u32(obj, "queueFamilyIndex", &dst->queueFamilyIndex);
}
void vk_VkCommandPoolCreateInfo_to(const void *raw, zval *rv) { (void) raw; object_init_ex(rv, vulkan_ce_VkCommandPoolCreateInfo); }

bool vk_VkCommandBufferAllocateInfo_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkCommandBufferAllocateInfo *dst = raw;
	uint64_t handle;
	memset(dst, 0, sizeof(*dst));
	dst->sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
	if (!vulkan_enter(obj, visited) || !vulkan_pnext(obj, &dst->pNext, scratch, visited)) return false;
	if (!vulkan_handle_prop(obj, "commandPool", vulkan_ce_VkCommandPool, &handle)) return false;
	dst->commandPool = (VkCommandPool) (uintptr_t) handle;
	return vulkan_u32(obj, "level", &dst->level) && vulkan_u32(obj, "commandBufferCount", &dst->commandBufferCount);
}
void vk_VkCommandBufferAllocateInfo_to(const void *raw, zval *rv) { (void) raw; object_init_ex(rv, vulkan_ce_VkCommandBufferAllocateInfo); }

bool vk_VkCommandBufferInheritanceInfo_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkCommandBufferInheritanceInfo *dst = raw;
	uint64_t render_pass, framebuffer;
	memset(dst, 0, sizeof(*dst));
	dst->sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO;
	if (!vulkan_enter(obj, visited) || !vulkan_pnext(obj, &dst->pNext, scratch, visited)) return false;
	if (!vulkan_handle_prop(obj, "renderPass", vulkan_ce_VkRenderPass, &render_pass)) return false;
	if (!vulkan_handle_prop(obj, "framebuffer", vulkan_ce_VkFramebuffer, &framebuffer)) return false;
	dst->renderPass = (VkRenderPass) (uintptr_t) render_pass;
	dst->framebuffer = (VkFramebuffer) (uintptr_t) framebuffer;
	return vulkan_u32(obj, "subpass", &dst->subpass)
		&& vulkan_bool32(obj, "occlusionQueryEnable", &dst->occlusionQueryEnable)
		&& vulkan_u32(obj, "queryFlags", &dst->queryFlags)
		&& vulkan_u32(obj, "pipelineStatistics", &dst->pipelineStatistics);
}
void vk_VkCommandBufferInheritanceInfo_to(const void *raw, zval *rv) { (void) raw; object_init_ex(rv, vulkan_ce_VkCommandBufferInheritanceInfo); }

bool vk_VkCommandBufferBeginInfo_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkCommandBufferBeginInfo *dst = raw;
	memset(dst, 0, sizeof(*dst));
	dst->sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
	if (!vulkan_enter(obj, visited) || !vulkan_pnext(obj, &dst->pNext, scratch, visited)) return false;
	return vulkan_u32(obj, "flags", &dst->flags)
		&& vulkan_struct_ptr(obj, "pInheritanceInfo", vulkan_ce_VkCommandBufferInheritanceInfo, sizeof(VkCommandBufferInheritanceInfo), vk_VkCommandBufferInheritanceInfo_from, (void **) &dst->pInheritanceInfo, scratch, visited);
}
void vk_VkCommandBufferBeginInfo_to(const void *raw, zval *rv) { (void) raw; object_init_ex(rv, vulkan_ce_VkCommandBufferBeginInfo); }

bool vk_VkClearColorValue_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	(void) scratch;
	if (!vulkan_enter(obj, visited)) return false;
	return vulkan_clear_color(obj, raw);
}
void vk_VkClearColorValue_to(const void *raw, zval *rv) { (void) raw; object_init_ex(rv, vulkan_ce_VkClearColorValue); }

bool vk_VkClearDepthStencilValue_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkClearDepthStencilValue *dst = raw;
	(void) scratch;
	if (!vulkan_enter(obj, visited)) return false;
	return vulkan_float(obj, "depth", &dst->depth) && vulkan_u32(obj, "stencil", &dst->stencil);
}
void vk_VkClearDepthStencilValue_to(const void *raw, zval *rv) { (void) raw; object_init_ex(rv, vulkan_ce_VkClearDepthStencilValue); }

bool vk_VkClearValue_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	if (!vulkan_enter(obj, visited)) return false;
	return vulkan_clear_value(obj, raw, scratch, visited);
}
void vk_VkClearValue_to(const void *raw, zval *rv) { (void) raw; object_init_ex(rv, vulkan_ce_VkClearValue); }

bool vk_VkOffset3D_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkOffset3D *dst = raw;
	(void) scratch;
	if (!vulkan_enter(obj, visited)) return false;
	return vulkan_i32(obj, "x", &dst->x) && vulkan_i32(obj, "y", &dst->y) && vulkan_i32(obj, "z", &dst->z);
}
void vk_VkOffset3D_to(const void *raw, zval *rv) { (void) raw; object_init_ex(rv, vulkan_ce_VkOffset3D); }

bool vk_VkImageSubresourceLayers_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkImageSubresourceLayers *dst = raw;
	(void) scratch;
	if (!vulkan_enter(obj, visited)) return false;
	return vulkan_u32(obj, "aspectMask", &dst->aspectMask) && vulkan_u32(obj, "mipLevel", &dst->mipLevel)
		&& vulkan_u32(obj, "baseArrayLayer", &dst->baseArrayLayer) && vulkan_u32(obj, "layerCount", &dst->layerCount);
}
void vk_VkImageSubresourceLayers_to(const void *raw, zval *rv) { (void) raw; object_init_ex(rv, vulkan_ce_VkImageSubresourceLayers); }

bool vk_VkBufferImageCopy_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkBufferImageCopy *dst = raw;
	memset(dst, 0, sizeof(*dst));
	if (!vulkan_enter(obj, visited)) return false;
	return vulkan_u64(obj, "bufferOffset", &dst->bufferOffset)
		&& vulkan_u32(obj, "bufferRowLength", &dst->bufferRowLength)
		&& vulkan_u32(obj, "bufferImageHeight", &dst->bufferImageHeight)
		&& vulkan_struct_value(obj, "imageSubresource", vulkan_ce_VkImageSubresourceLayers, vk_VkImageSubresourceLayers_from, &dst->imageSubresource, scratch, visited)
		&& vulkan_struct_value(obj, "imageOffset", vulkan_ce_VkOffset3D, vk_VkOffset3D_from, &dst->imageOffset, scratch, visited)
		&& vulkan_struct_value(obj, "imageExtent", vulkan_ce_VkExtent3D, vk_VkExtent3D_from, &dst->imageExtent, scratch, visited);
}
void vk_VkBufferImageCopy_to(const void *raw, zval *rv) { (void) raw; object_init_ex(rv, vulkan_ce_VkBufferImageCopy); }

bool vk_VkMemoryToImageCopy_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkMemoryToImageCopy *dst = raw;
	zval *held;
	memset(dst, 0, sizeof(*dst));
	dst->sType = VK_STRUCTURE_TYPE_MEMORY_TO_IMAGE_COPY;
	if (!vulkan_enter(obj, visited) || !vulkan_pnext(obj, &dst->pNext, scratch, visited)) return false;
	/* a typed string property: always a string */
	held = zend_read_property(obj->ce, obj, "pHostPointer", sizeof("pHostPointer") - 1, 0, NULL);
	dst->pHostPointer = Z_STRVAL_P(held);
	if (!vulkan_u32(obj, "memoryRowLength", &dst->memoryRowLength)
		|| !vulkan_u32(obj, "memoryImageHeight", &dst->memoryImageHeight)
		|| !vulkan_nested(obj, "imageSubresource", vulkan_ce_VkImageSubresourceLayers, vk_VkImageSubresourceLayers_from, &dst->imageSubresource, scratch)
		|| !vulkan_nested(obj, "imageOffset", vulkan_ce_VkOffset3D, vk_VkOffset3D_from, &dst->imageOffset, scratch)
		|| !vulkan_nested(obj, "imageExtent", vulkan_ce_VkExtent3D, vk_VkExtent3D_from, &dst->imageExtent, scratch)) return false;
	/* at least one byte a texel: the bytes Vulkan reads are never fewer than the texels of the region */
	return vulkan_bytes_length(Z_STRLEN_P(held), (size_t) dst->imageExtent.width * dst->imageExtent.height * dst->imageExtent.depth, 0, "VkMemoryToImageCopy::$pHostPointer");
}
bool vk_VkImageCopy_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkImageCopy *dst = raw;
	memset(dst, 0, sizeof(*dst));
	if (!vulkan_enter(obj, visited)) return false;
	return vulkan_nested(obj, "srcSubresource", vulkan_ce_VkImageSubresourceLayers, vk_VkImageSubresourceLayers_from, &dst->srcSubresource, scratch)
		&& vulkan_nested(obj, "srcOffset", vulkan_ce_VkOffset3D, vk_VkOffset3D_from, &dst->srcOffset, scratch)
		&& vulkan_nested(obj, "dstSubresource", vulkan_ce_VkImageSubresourceLayers, vk_VkImageSubresourceLayers_from, &dst->dstSubresource, scratch)
		&& vulkan_nested(obj, "dstOffset", vulkan_ce_VkOffset3D, vk_VkOffset3D_from, &dst->dstOffset, scratch)
		&& vulkan_nested(obj, "extent", vulkan_ce_VkExtent3D, vk_VkExtent3D_from, &dst->extent, scratch);
}
void vk_VkImageCopy_to(const void *raw, zval *rv) { (void) raw; object_init_ex(rv, vulkan_ce_VkImageCopy); }

void vk_VkMemoryToImageCopy_to(const void *raw, zval *rv) { (void) raw; object_init_ex(rv, vulkan_ce_VkMemoryToImageCopy); }

/* The region's bytes are filled by Vulkan: a copy of the caller's string (its length is the size to read) in scratch; vkCopyImageToMemory() puts them back in the property. */
bool vk_VkImageToMemoryCopy_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkImageToMemoryCopy *dst = raw;
	zval *held;
	char *bytes;
	memset(dst, 0, sizeof(*dst));
	dst->sType = VK_STRUCTURE_TYPE_IMAGE_TO_MEMORY_COPY;
	if (!vulkan_enter(obj, visited) || !vulkan_pnext(obj, &dst->pNext, scratch, visited)) return false;
	if (!vulkan_u32(obj, "memoryRowLength", &dst->memoryRowLength)
		|| !vulkan_u32(obj, "memoryImageHeight", &dst->memoryImageHeight)
		|| !vulkan_nested(obj, "imageSubresource", vulkan_ce_VkImageSubresourceLayers, vk_VkImageSubresourceLayers_from, &dst->imageSubresource, scratch)
		|| !vulkan_nested(obj, "imageOffset", vulkan_ce_VkOffset3D, vk_VkOffset3D_from, &dst->imageOffset, scratch)
		|| !vulkan_nested(obj, "imageExtent", vulkan_ce_VkExtent3D, vk_VkExtent3D_from, &dst->imageExtent, scratch)) return false;
	/* a typed string property: always a string */
	held = zend_read_property(obj->ce, obj, "pHostPointer", sizeof("pHostPointer") - 1, 0, NULL);
	if (!vulkan_bytes_length(Z_STRLEN_P(held), (size_t) dst->imageExtent.width * dst->imageExtent.height * dst->imageExtent.depth, 0, "VkImageToMemoryCopy::$pHostPointer")) return false;
	bytes = vulkan_scratch_alloc(scratch, Z_STRLEN_P(held) ? Z_STRLEN_P(held) : 1);
	memcpy(bytes, Z_STRVAL_P(held), Z_STRLEN_P(held));
	dst->pHostPointer = bytes;
	return true;
}
void vk_VkImageToMemoryCopy_to(const void *raw, zval *rv) { (void) raw; object_init_ex(rv, vulkan_ce_VkImageToMemoryCopy); }

bool vk_VkCopyMemoryToImageInfo_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkCopyMemoryToImageInfo *dst = raw;
	uint64_t image;
	memset(dst, 0, sizeof(*dst));
	dst->sType = VK_STRUCTURE_TYPE_COPY_MEMORY_TO_IMAGE_INFO;
	if (!vulkan_enter(obj, visited) || !vulkan_pnext(obj, &dst->pNext, scratch, visited)) return false;
	if (!vulkan_handle_prop(obj, "dstImage", vulkan_ce_VkImage, &image)) return false;
	dst->dstImage = (VkImage) (uintptr_t) image;
	return vulkan_u32(obj, "flags", &dst->flags)
		&& vulkan_u32(obj, "dstImageLayout", &dst->dstImageLayout)
		&& vulkan_u32(obj, "regionCount", &dst->regionCount)
		&& vulkan_struct_list(obj, "pRegions", vulkan_ce_VkMemoryToImageCopy, sizeof(VkMemoryToImageCopy), vk_VkMemoryToImageCopy_from, (void **) &dst->pRegions, &dst->regionCount, scratch, visited);
}
void vk_VkCopyMemoryToImageInfo_to(const void *raw, zval *rv) { (void) raw; object_init_ex(rv, vulkan_ce_VkCopyMemoryToImageInfo); }

bool vk_VkCopyImageToMemoryInfo_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkCopyImageToMemoryInfo *dst = raw;
	uint64_t image;
	memset(dst, 0, sizeof(*dst));
	dst->sType = VK_STRUCTURE_TYPE_COPY_IMAGE_TO_MEMORY_INFO;
	if (!vulkan_enter(obj, visited) || !vulkan_pnext(obj, &dst->pNext, scratch, visited)) return false;
	if (!vulkan_handle_prop(obj, "srcImage", vulkan_ce_VkImage, &image)) return false;
	dst->srcImage = (VkImage) (uintptr_t) image;
	return vulkan_u32(obj, "flags", &dst->flags)
		&& vulkan_u32(obj, "srcImageLayout", &dst->srcImageLayout)
		&& vulkan_u32(obj, "regionCount", &dst->regionCount)
		&& vulkan_struct_list(obj, "pRegions", vulkan_ce_VkImageToMemoryCopy, sizeof(VkImageToMemoryCopy), vk_VkImageToMemoryCopy_from, (void **) &dst->pRegions, &dst->regionCount, scratch, visited);
}
void vk_VkCopyImageToMemoryInfo_to(const void *raw, zval *rv) { (void) raw; object_init_ex(rv, vulkan_ce_VkCopyImageToMemoryInfo); }

bool vk_VkHostImageLayoutTransitionInfo_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkHostImageLayoutTransitionInfo *dst = raw;
	uint64_t image;
	memset(dst, 0, sizeof(*dst));
	dst->sType = VK_STRUCTURE_TYPE_HOST_IMAGE_LAYOUT_TRANSITION_INFO;
	if (!vulkan_enter(obj, visited) || !vulkan_pnext(obj, &dst->pNext, scratch, visited)) return false;
	if (!vulkan_handle_prop(obj, "image", vulkan_ce_VkImage, &image)) return false;
	dst->image = (VkImage) (uintptr_t) image;
	return vulkan_u32(obj, "oldLayout", &dst->oldLayout)
		&& vulkan_u32(obj, "newLayout", &dst->newLayout)
		&& vulkan_nested(obj, "subresourceRange", vulkan_ce_VkImageSubresourceRange, vk_VkImageSubresourceRange_from, &dst->subresourceRange, scratch);
}
void vk_VkHostImageLayoutTransitionInfo_to(const void *raw, zval *rv) { (void) raw; object_init_ex(rv, vulkan_ce_VkHostImageLayoutTransitionInfo); }

bool vk_VkPhysicalDeviceHostImageCopyFeatures_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkPhysicalDeviceHostImageCopyFeatures *dst = raw;
	const void *next = NULL;
	memset(dst, 0, sizeof(*dst));
	dst->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_FEATURES;
	if (!vulkan_enter(obj, visited) || !vulkan_pnext(obj, &next, scratch, visited)) return false;
	dst->pNext = (void *) next;
	return vulkan_bool32(obj, "hostImageCopy", &dst->hostImageCopy);
}

bool vk_VkImageBlit_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkImageBlit *dst = raw;
	memset(dst, 0, sizeof(*dst));
	if (!vulkan_enter(obj, visited)) return false;
	return vulkan_struct_value(obj, "srcSubresource", vulkan_ce_VkImageSubresourceLayers, vk_VkImageSubresourceLayers_from, &dst->srcSubresource, scratch, visited)
		&& vulkan_offset3_list(obj, "srcOffsets", dst->srcOffsets, scratch, visited)
		&& vulkan_struct_value(obj, "dstSubresource", vulkan_ce_VkImageSubresourceLayers, vk_VkImageSubresourceLayers_from, &dst->dstSubresource, scratch, visited)
		&& vulkan_offset3_list(obj, "dstOffsets", dst->dstOffsets, scratch, visited);
}
void vk_VkImageBlit_to(const void *raw, zval *rv) { (void) raw; object_init_ex(rv, vulkan_ce_VkImageBlit); }

bool vk_VkMemoryBarrier_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkMemoryBarrier *dst = raw;
	memset(dst, 0, sizeof(*dst));
	dst->sType = VK_STRUCTURE_TYPE_MEMORY_BARRIER;
	if (!vulkan_enter(obj, visited) || !vulkan_pnext(obj, &dst->pNext, scratch, visited)) return false;
	return vulkan_u32(obj, "srcAccessMask", &dst->srcAccessMask)
		&& vulkan_u32(obj, "dstAccessMask", &dst->dstAccessMask);
}
void vk_VkMemoryBarrier_to(const void *raw, zval *rv) { (void) raw; object_init_ex(rv, vulkan_ce_VkMemoryBarrier); }

bool vk_VkBufferMemoryBarrier_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkBufferMemoryBarrier *dst = raw;
	uint64_t buffer;
	memset(dst, 0, sizeof(*dst));
	dst->sType = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER;
	if (!vulkan_enter(obj, visited) || !vulkan_pnext(obj, &dst->pNext, scratch, visited)) return false;
	if (!vulkan_handle_prop(obj, "buffer", vulkan_ce_VkBuffer, &buffer)) return false;
	dst->buffer = (VkBuffer) (uintptr_t) buffer;
	return vulkan_u32(obj, "srcAccessMask", &dst->srcAccessMask)
		&& vulkan_u32(obj, "dstAccessMask", &dst->dstAccessMask)
		&& vulkan_u32(obj, "srcQueueFamilyIndex", &dst->srcQueueFamilyIndex)
		&& vulkan_u32(obj, "dstQueueFamilyIndex", &dst->dstQueueFamilyIndex)
		&& vulkan_u64(obj, "offset", &dst->offset)
		&& vulkan_u64(obj, "size", &dst->size);
}

bool vk_VkImageMemoryBarrier_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkImageMemoryBarrier *dst = raw;
	uint64_t image;
	memset(dst, 0, sizeof(*dst));
	dst->sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
	if (!vulkan_enter(obj, visited) || !vulkan_pnext(obj, &dst->pNext, scratch, visited)) return false;
	if (!vulkan_handle_prop(obj, "image", vulkan_ce_VkImage, &image)) return false;
	dst->image = (VkImage) (uintptr_t) image;
	return vulkan_u32(obj, "srcAccessMask", &dst->srcAccessMask)
		&& vulkan_u32(obj, "dstAccessMask", &dst->dstAccessMask)
		&& vulkan_u32(obj, "oldLayout", &dst->oldLayout)
		&& vulkan_u32(obj, "newLayout", &dst->newLayout)
		&& vulkan_u32(obj, "srcQueueFamilyIndex", &dst->srcQueueFamilyIndex)
		&& vulkan_u32(obj, "dstQueueFamilyIndex", &dst->dstQueueFamilyIndex)
		&& vulkan_struct_value(obj, "subresourceRange", vulkan_ce_VkImageSubresourceRange, vk_VkImageSubresourceRange_from, &dst->subresourceRange, scratch, visited);
}
void vk_VkImageMemoryBarrier_to(const void *raw, zval *rv) { (void) raw; object_init_ex(rv, vulkan_ce_VkImageMemoryBarrier); }

bool vk_VkSubmitInfo_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkSubmitInfo *dst = raw;
	uint64_t *waits = NULL, *buffers = NULL, *signals = NULL;
	const uint32_t *stages = NULL;
	uint32_t stage_count;

	memset(dst, 0, sizeof(*dst));
	dst->sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
	if (!vulkan_enter(obj, visited) || !vulkan_pnext(obj, &dst->pNext, scratch, visited)) {
		return false;
	}
	if (!vulkan_u32(obj, "waitSemaphoreCount", &dst->waitSemaphoreCount)
		|| !vulkan_u32(obj, "commandBufferCount", &dst->commandBufferCount)
		|| !vulkan_u32(obj, "signalSemaphoreCount", &dst->signalSemaphoreCount)) return false;
	stage_count = dst->waitSemaphoreCount;
	if (!vulkan_handle_list(obj, "pWaitSemaphores", vulkan_ce_VkSemaphore, &waits, &dst->waitSemaphoreCount, scratch)) return false;
	if (!vulkan_u32_list(obj, "pWaitDstStageMask", &stages, &stage_count, scratch)) return false;
	if (!vulkan_handle_list(obj, "pCommandBuffers", vulkan_ce_VkCommandBuffer, &buffers, &dst->commandBufferCount, scratch)) return false;
	if (!vulkan_handle_list(obj, "pSignalSemaphores", vulkan_ce_VkSemaphore, &signals, &dst->signalSemaphoreCount, scratch)) return false;
	dst->pWaitSemaphores = (const VkSemaphore *) waits;
	dst->pWaitDstStageMask = (const VkPipelineStageFlags *) stages;
	dst->pCommandBuffers = (const VkCommandBuffer *) buffers;
	dst->pSignalSemaphores = (const VkSemaphore *) signals;
	return true;
}
void vk_VkSubmitInfo_to(const void *raw, zval *rv) { (void) raw; object_init_ex(rv, vulkan_ce_VkSubmitInfo); }

bool vk_VkFenceCreateInfo_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkFenceCreateInfo *dst = raw;
	memset(dst, 0, sizeof(*dst));
	dst->sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
	if (!vulkan_enter(obj, visited) || !vulkan_pnext(obj, &dst->pNext, scratch, visited)) return false;
	return vulkan_u32(obj, "flags", &dst->flags);
}
void vk_VkFenceCreateInfo_to(const void *raw, zval *rv) { (void) raw; object_init_ex(rv, vulkan_ce_VkFenceCreateInfo); }

bool vk_VkSemaphoreCreateInfo_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkSemaphoreCreateInfo *dst = raw;
	memset(dst, 0, sizeof(*dst));
	dst->sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;
	if (!vulkan_enter(obj, visited) || !vulkan_pnext(obj, &dst->pNext, scratch, visited)) return false;
	return vulkan_u32(obj, "flags", &dst->flags);
}
void vk_VkSemaphoreCreateInfo_to(const void *raw, zval *rv) { (void) raw; object_init_ex(rv, vulkan_ce_VkSemaphoreCreateInfo); }

bool vk_VkRenderPassBeginInfo_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkRenderPassBeginInfo *dst = raw;
	uint64_t render_pass, framebuffer;
	void *clears = NULL;
	memset(dst, 0, sizeof(*dst));
	dst->sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
	if (!vulkan_enter(obj, visited) || !vulkan_pnext(obj, &dst->pNext, scratch, visited)) return false;
	if (!vulkan_handle_prop(obj, "renderPass", vulkan_ce_VkRenderPass, &render_pass)) return false;
	if (!vulkan_handle_prop(obj, "framebuffer", vulkan_ce_VkFramebuffer, &framebuffer)) return false;
	dst->renderPass = (VkRenderPass) (uintptr_t) render_pass;
	dst->framebuffer = (VkFramebuffer) (uintptr_t) framebuffer;
	if (!vulkan_struct_value(obj, "renderArea", vulkan_ce_VkRect2D, vk_VkRect2D_from, &dst->renderArea, scratch, visited)) return false;
	if (!vulkan_u32(obj, "clearValueCount", &dst->clearValueCount)) return false;
	if (!vulkan_struct_list(obj, "pClearValues", vulkan_ce_VkClearValue, sizeof(VkClearValue), vk_VkClearValue_from, &clears, &dst->clearValueCount, scratch, visited)) return false;
	dst->pClearValues = clears;
	return true;
}
void vk_VkRenderPassBeginInfo_to(const void *raw, zval *rv) { (void) raw; object_init_ex(rv, vulkan_ce_VkRenderPassBeginInfo); }

bool vk_VkClearAttachment_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkClearAttachment *dst = raw;
	memset(dst, 0, sizeof(*dst));
	if (!vulkan_enter(obj, visited)) return false;
	return vulkan_u32(obj, "aspectMask", &dst->aspectMask)
		&& vulkan_u32(obj, "colorAttachment", &dst->colorAttachment)
		&& vulkan_struct_value(obj, "clearValue", vulkan_ce_VkClearValue, vk_VkClearValue_from, &dst->clearValue, scratch, visited);
}
void vk_VkClearAttachment_to(const void *raw, zval *rv) { (void) raw; object_init_ex(rv, vulkan_ce_VkClearAttachment); }

bool vk_VkClearRect_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkClearRect *dst = raw;
	memset(dst, 0, sizeof(*dst));
	if (!vulkan_enter(obj, visited)) return false;
	return vulkan_struct_value(obj, "rect", vulkan_ce_VkRect2D, vk_VkRect2D_from, &dst->rect, scratch, visited)
		&& vulkan_u32(obj, "baseArrayLayer", &dst->baseArrayLayer)
		&& vulkan_u32(obj, "layerCount", &dst->layerCount);
}
void vk_VkClearRect_to(const void *raw, zval *rv) { (void) raw; object_init_ex(rv, vulkan_ce_VkClearRect); }
