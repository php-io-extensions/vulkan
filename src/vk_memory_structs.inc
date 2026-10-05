bool vk_VkMemoryAllocateInfo_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkMemoryAllocateInfo *dst = raw;

	memset(dst, 0, sizeof(*dst));
	dst->sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
	if (!vulkan_enter(obj, visited) || !vulkan_pnext(obj, &dst->pNext, scratch, visited)) {
		return false;
	}
	return vulkan_u64(obj, "allocationSize", &dst->allocationSize)
		&& vulkan_u32(obj, "memoryTypeIndex", &dst->memoryTypeIndex);
}

void vk_VkMemoryAllocateInfo_to(const void *raw, zval *rv)
{
	const VkMemoryAllocateInfo *src = raw;
	zend_object *obj;

	object_init_ex(rv, vulkan_ce_VkMemoryAllocateInfo);
	obj = Z_OBJ_P(rv);
	vulkan_set_null(obj, "pNext");
	vulkan_set_long(obj, "allocationSize", (zend_long) src->allocationSize);
	vulkan_set_long(obj, "memoryTypeIndex", (zend_long) src->memoryTypeIndex);
}

bool vk_VkMappedMemoryRange_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkMappedMemoryRange *dst = raw;
	uint64_t memory;

	memset(dst, 0, sizeof(*dst));
	dst->sType = VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE;
	if (!vulkan_enter(obj, visited) || !vulkan_pnext(obj, &dst->pNext, scratch, visited)) {
		return false;
	}
	if (!vulkan_handle_prop(obj, "memory", vulkan_ce_VkDeviceMemory, &memory)) {
		return false;
	}
	dst->memory = (VkDeviceMemory) (uintptr_t) memory;
	return vulkan_u64(obj, "offset", &dst->offset) && vulkan_u64(obj, "size", &dst->size);
}

void vk_VkMappedMemoryRange_to(const void *raw, zval *rv)
{
	(void) raw;
	object_init_ex(rv, vulkan_ce_VkMappedMemoryRange);
}

bool vk_VkBufferCreateInfo_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkBufferCreateInfo *dst = raw;

	memset(dst, 0, sizeof(*dst));
	dst->sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
	if (!vulkan_enter(obj, visited) || !vulkan_pnext(obj, &dst->pNext, scratch, visited)) {
		return false;
	}
	return vulkan_u32(obj, "flags", &dst->flags)
		&& vulkan_u64(obj, "size", &dst->size)
		&& vulkan_u32(obj, "usage", &dst->usage)
		&& vulkan_u32(obj, "sharingMode", &dst->sharingMode)
		&& vulkan_u32_list(obj, "pQueueFamilyIndices", &dst->pQueueFamilyIndices, &dst->queueFamilyIndexCount, scratch);
}

void vk_VkBufferCreateInfo_to(const void *raw, zval *rv)
{
	(void) raw;
	object_init_ex(rv, vulkan_ce_VkBufferCreateInfo);
}

bool vk_VkMemoryRequirements_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkMemoryRequirements *dst = raw;

	(void) scratch;
	memset(dst, 0, sizeof(*dst));
	if (!vulkan_enter(obj, visited)) {
		return false;
	}
	return vulkan_u64(obj, "size", &dst->size)
		&& vulkan_u64(obj, "alignment", &dst->alignment)
		&& vulkan_u32(obj, "memoryTypeBits", &dst->memoryTypeBits);
}

void vk_VkMemoryRequirements_to(const void *raw, zval *rv)
{
	const VkMemoryRequirements *src = raw;
	zend_object *obj;

	object_init_ex(rv, vulkan_ce_VkMemoryRequirements);
	obj = Z_OBJ_P(rv);
	vulkan_set_long(obj, "size", (zend_long) src->size);
	vulkan_set_long(obj, "alignment", (zend_long) src->alignment);
	vulkan_set_long(obj, "memoryTypeBits", (zend_long) src->memoryTypeBits);
}

bool vk_VkImageCreateInfo_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkImageCreateInfo *dst = raw;

	memset(dst, 0, sizeof(*dst));
	dst->sType = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
	if (!vulkan_enter(obj, visited) || !vulkan_pnext(obj, &dst->pNext, scratch, visited)) {
		return false;
	}
	return vulkan_u32(obj, "flags", &dst->flags)
		&& vulkan_u32(obj, "imageType", &dst->imageType)
		&& vulkan_u32(obj, "format", &dst->format)
		&& vulkan_struct_value(obj, "extent", vulkan_ce_VkExtent3D, vk_VkExtent3D_from, &dst->extent, scratch, visited)
		&& vulkan_u32(obj, "mipLevels", &dst->mipLevels)
		&& vulkan_u32(obj, "arrayLayers", &dst->arrayLayers)
		&& vulkan_u32(obj, "samples", &dst->samples)
		&& vulkan_u32(obj, "tiling", &dst->tiling)
		&& vulkan_u32(obj, "usage", &dst->usage)
		&& vulkan_u32(obj, "sharingMode", &dst->sharingMode)
		&& vulkan_u32_list(obj, "pQueueFamilyIndices", &dst->pQueueFamilyIndices, &dst->queueFamilyIndexCount, scratch)
		&& vulkan_u32(obj, "initialLayout", &dst->initialLayout);
}

void vk_VkImageCreateInfo_to(const void *raw, zval *rv)
{
	(void) raw;
	object_init_ex(rv, vulkan_ce_VkImageCreateInfo);
}

bool vk_VkComponentMapping_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkComponentMapping *dst = raw;

	(void) scratch;
	memset(dst, 0, sizeof(*dst));
	if (!vulkan_enter(obj, visited)) {
		return false;
	}
	return vulkan_u32(obj, "r", &dst->r) && vulkan_u32(obj, "g", &dst->g)
		&& vulkan_u32(obj, "b", &dst->b) && vulkan_u32(obj, "a", &dst->a);
}

void vk_VkComponentMapping_to(const void *raw, zval *rv)
{
	const VkComponentMapping *src = raw;
	zend_object *obj;

	object_init_ex(rv, vulkan_ce_VkComponentMapping);
	obj = Z_OBJ_P(rv);
	vulkan_set_long(obj, "r", (zend_long) src->r);
	vulkan_set_long(obj, "g", (zend_long) src->g);
	vulkan_set_long(obj, "b", (zend_long) src->b);
	vulkan_set_long(obj, "a", (zend_long) src->a);
}

bool vk_VkImageSubresourceRange_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkImageSubresourceRange *dst = raw;

	(void) scratch;
	memset(dst, 0, sizeof(*dst));
	if (!vulkan_enter(obj, visited)) {
		return false;
	}
	return vulkan_u32(obj, "aspectMask", &dst->aspectMask)
		&& vulkan_u32(obj, "baseMipLevel", &dst->baseMipLevel)
		&& vulkan_u32(obj, "levelCount", &dst->levelCount)
		&& vulkan_u32(obj, "baseArrayLayer", &dst->baseArrayLayer)
		&& vulkan_u32(obj, "layerCount", &dst->layerCount);
}

void vk_VkImageSubresourceRange_to(const void *raw, zval *rv)
{
	const VkImageSubresourceRange *src = raw;
	zend_object *obj;

	object_init_ex(rv, vulkan_ce_VkImageSubresourceRange);
	obj = Z_OBJ_P(rv);
	vulkan_set_long(obj, "aspectMask", (zend_long) src->aspectMask);
	vulkan_set_long(obj, "baseMipLevel", (zend_long) src->baseMipLevel);
	vulkan_set_long(obj, "levelCount", (zend_long) src->levelCount);
	vulkan_set_long(obj, "baseArrayLayer", (zend_long) src->baseArrayLayer);
	vulkan_set_long(obj, "layerCount", (zend_long) src->layerCount);
}

bool vk_VkImageViewCreateInfo_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkImageViewCreateInfo *dst = raw;
	uint64_t image;

	memset(dst, 0, sizeof(*dst));
	dst->sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
	if (!vulkan_enter(obj, visited) || !vulkan_pnext(obj, &dst->pNext, scratch, visited)) {
		return false;
	}
	if (!vulkan_handle_prop(obj, "image", vulkan_ce_VkImage, &image)) {
		return false;
	}
	dst->image = (VkImage) (uintptr_t) image;
	return vulkan_u32(obj, "flags", &dst->flags)
		&& vulkan_u32(obj, "viewType", &dst->viewType)
		&& vulkan_u32(obj, "format", &dst->format)
		&& vulkan_struct_value(obj, "components", vulkan_ce_VkComponentMapping, vk_VkComponentMapping_from, &dst->components, scratch, visited)
		&& vulkan_struct_value(obj, "subresourceRange", vulkan_ce_VkImageSubresourceRange, vk_VkImageSubresourceRange_from, &dst->subresourceRange, scratch, visited);
}

void vk_VkImageViewCreateInfo_to(const void *raw, zval *rv)
{
	(void) raw;
	object_init_ex(rv, vulkan_ce_VkImageViewCreateInfo);
}

bool vk_VkSamplerCreateInfo_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkSamplerCreateInfo *dst = raw;

	memset(dst, 0, sizeof(*dst));
	dst->sType = VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO;
	if (!vulkan_enter(obj, visited) || !vulkan_pnext(obj, &dst->pNext, scratch, visited)) {
		return false;
	}
	return vulkan_u32(obj, "flags", &dst->flags)
		&& vulkan_u32(obj, "magFilter", &dst->magFilter)
		&& vulkan_u32(obj, "minFilter", &dst->minFilter)
		&& vulkan_u32(obj, "mipmapMode", &dst->mipmapMode)
		&& vulkan_u32(obj, "addressModeU", &dst->addressModeU)
		&& vulkan_u32(obj, "addressModeV", &dst->addressModeV)
		&& vulkan_u32(obj, "addressModeW", &dst->addressModeW)
		&& vulkan_float(obj, "mipLodBias", &dst->mipLodBias)
		&& vulkan_bool32(obj, "anisotropyEnable", &dst->anisotropyEnable)
		&& vulkan_float(obj, "maxAnisotropy", &dst->maxAnisotropy)
		&& vulkan_bool32(obj, "compareEnable", &dst->compareEnable)
		&& vulkan_u32(obj, "compareOp", &dst->compareOp)
		&& vulkan_float(obj, "minLod", &dst->minLod)
		&& vulkan_float(obj, "maxLod", &dst->maxLod)
		&& vulkan_u32(obj, "borderColor", &dst->borderColor)
		&& vulkan_bool32(obj, "unnormalizedCoordinates", &dst->unnormalizedCoordinates);
}

void vk_VkSamplerCreateInfo_to(const void *raw, zval *rv)
{
	(void) raw;
	object_init_ex(rv, vulkan_ce_VkSamplerCreateInfo);
}
