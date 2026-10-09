bool vk_VkExternalMemoryImageCreateInfo_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkExternalMemoryImageCreateInfo *dst = raw;
	memset(dst, 0, sizeof(*dst));
	dst->sType = VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO;
	if (!vulkan_enter(obj, visited) || !vulkan_pnext(obj, &dst->pNext, scratch, visited)) return false;
	return vulkan_u32(obj, "handleTypes", &dst->handleTypes);
}
void vk_VkExternalMemoryImageCreateInfo_to(const void *raw, zval *rv) { (void) raw; object_init_ex(rv, vulkan_ce_VkExternalMemoryImageCreateInfo); }

bool vk_VkExportMemoryAllocateInfo_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkExportMemoryAllocateInfo *dst = raw;
	memset(dst, 0, sizeof(*dst));
	dst->sType = VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO;
	if (!vulkan_enter(obj, visited) || !vulkan_pnext(obj, &dst->pNext, scratch, visited)) return false;
	return vulkan_u32(obj, "handleTypes", &dst->handleTypes);
}
void vk_VkExportMemoryAllocateInfo_to(const void *raw, zval *rv) { (void) raw; object_init_ex(rv, vulkan_ce_VkExportMemoryAllocateInfo); }

bool vk_VkMemoryDedicatedAllocateInfo_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkMemoryDedicatedAllocateInfo *dst = raw;
	uint64_t image, buffer;
	memset(dst, 0, sizeof(*dst));
	dst->sType = VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO;
	if (!vulkan_enter(obj, visited) || !vulkan_pnext(obj, &dst->pNext, scratch, visited)) return false;
	if (!vulkan_handle_prop(obj, "image", vulkan_ce_VkImage, &image) || !vulkan_handle_prop(obj, "buffer", vulkan_ce_VkBuffer, &buffer)) return false;
	dst->image = (VkImage) (uintptr_t) image;
	dst->buffer = (VkBuffer) (uintptr_t) buffer;
	return true;
}
void vk_VkMemoryDedicatedAllocateInfo_to(const void *raw, zval *rv) { (void) raw; object_init_ex(rv, vulkan_ce_VkMemoryDedicatedAllocateInfo); }

bool vk_VkMemoryGetFdInfoKHR_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkMemoryGetFdInfoKHR *dst = raw;
	uint64_t memory;
	memset(dst, 0, sizeof(*dst));
	dst->sType = VK_STRUCTURE_TYPE_MEMORY_GET_FD_INFO_KHR;
	if (!vulkan_enter(obj, visited) || !vulkan_pnext(obj, &dst->pNext, scratch, visited)) return false;
	if (!vulkan_handle_prop(obj, "memory", vulkan_ce_VkDeviceMemory, &memory)) return false;
	dst->memory = (VkDeviceMemory) (uintptr_t) memory;
	return vulkan_u32(obj, "handleType", &dst->handleType);
}
void vk_VkMemoryGetFdInfoKHR_to(const void *raw, zval *rv) { (void) raw; object_init_ex(rv, vulkan_ce_VkMemoryGetFdInfoKHR); }

bool vk_VkImageDrmFormatModifierListCreateInfoEXT_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkImageDrmFormatModifierListCreateInfoEXT *dst = raw;
	memset(dst, 0, sizeof(*dst));
	dst->sType = VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT;
	if (!vulkan_enter(obj, visited) || !vulkan_pnext(obj, &dst->pNext, scratch, visited)) return false;
	return vulkan_u64_list(obj, "pDrmFormatModifiers", &dst->pDrmFormatModifiers, &dst->drmFormatModifierCount, scratch);
}
void vk_VkImageDrmFormatModifierListCreateInfoEXT_to(const void *raw, zval *rv) { (void) raw; object_init_ex(rv, vulkan_ce_VkImageDrmFormatModifierListCreateInfoEXT); }

bool vk_VkImageDrmFormatModifierPropertiesEXT_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkImageDrmFormatModifierPropertiesEXT *dst = raw;
	(void) scratch;
	memset(dst, 0, sizeof(*dst));
	dst->sType = VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_PROPERTIES_EXT;
	if (!vulkan_enter(obj, visited)) return false;
	return vulkan_u64(obj, "drmFormatModifier", &dst->drmFormatModifier);
}
void vk_VkImageDrmFormatModifierPropertiesEXT_to(const void *raw, zval *rv)
{
	const VkImageDrmFormatModifierPropertiesEXT *src = raw;
	zend_object *obj;
	object_init_ex(rv, vulkan_ce_VkImageDrmFormatModifierPropertiesEXT);
	obj = Z_OBJ_P(rv);
	vulkan_set_long(obj, "drmFormatModifier", (zend_long) src->drmFormatModifier);
}

bool vk_VkImageSubresource_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkImageSubresource *dst = raw;
	(void) scratch;
	if (!vulkan_enter(obj, visited)) return false;
	return vulkan_u32(obj, "aspectMask", &dst->aspectMask) && vulkan_u32(obj, "mipLevel", &dst->mipLevel) && vulkan_u32(obj, "arrayLayer", &dst->arrayLayer);
}
void vk_VkImageSubresource_to(const void *raw, zval *rv) { (void) raw; object_init_ex(rv, vulkan_ce_VkImageSubresource); }

bool vk_VkSubresourceLayout_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkSubresourceLayout *dst = raw;
	(void) scratch;
	if (!vulkan_enter(obj, visited)) return false;
	return vulkan_u64(obj, "offset", &dst->offset) && vulkan_u64(obj, "size", &dst->size)
		&& vulkan_u64(obj, "rowPitch", &dst->rowPitch) && vulkan_u64(obj, "arrayPitch", &dst->arrayPitch)
		&& vulkan_u64(obj, "depthPitch", &dst->depthPitch);
}
void vk_VkSubresourceLayout_to(const void *raw, zval *rv)
{
	const VkSubresourceLayout *src = raw;
	zend_object *obj;
	object_init_ex(rv, vulkan_ce_VkSubresourceLayout);
	obj = Z_OBJ_P(rv);
	vulkan_set_long(obj, "offset", (zend_long) src->offset);
	vulkan_set_long(obj, "size", (zend_long) src->size);
	vulkan_set_long(obj, "rowPitch", (zend_long) src->rowPitch);
	vulkan_set_long(obj, "arrayPitch", (zend_long) src->arrayPitch);
	vulkan_set_long(obj, "depthPitch", (zend_long) src->depthPitch);
}
