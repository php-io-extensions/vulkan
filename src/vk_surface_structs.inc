static void vulkan_set_extent2(zend_object *obj, const char *name, const VkExtent2D *extent)
{
	zval nested;
	zend_object *child;

	object_init_ex(&nested, vulkan_ce_VkExtent2D);
	child = Z_OBJ(nested);
	vulkan_set_long(child, "width", (zend_long) extent->width);
	vulkan_set_long(child, "height", (zend_long) extent->height);
	vulkan_set_zval(obj, name, &nested);
}

bool vk_VkSurfaceFormatKHR_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkSurfaceFormatKHR *dst = raw;
	(void) scratch;
	if (!vulkan_enter(obj, visited)) return false;
	return vulkan_u32(obj, "format", &dst->format) && vulkan_u32(obj, "colorSpace", &dst->colorSpace);
}
void vk_VkSurfaceFormatKHR_to(const void *raw, zval *rv)
{
	const VkSurfaceFormatKHR *src = raw;
	zend_object *obj;
	object_init_ex(rv, vulkan_ce_VkSurfaceFormatKHR);
	obj = Z_OBJ_P(rv);
	vulkan_set_long(obj, "format", (zend_long) src->format);
	vulkan_set_long(obj, "colorSpace", (zend_long) src->colorSpace);
}

bool vk_VkSurfaceCapabilitiesKHR_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkSurfaceCapabilitiesKHR *dst = raw;
	memset(dst, 0, sizeof(*dst));
	if (!vulkan_enter(obj, visited)) return false;
	return vulkan_u32(obj, "minImageCount", &dst->minImageCount)
		&& vulkan_u32(obj, "maxImageCount", &dst->maxImageCount)
		&& vulkan_struct_value(obj, "currentExtent", vulkan_ce_VkExtent2D, vk_VkExtent2D_from, &dst->currentExtent, scratch, visited)
		&& vulkan_struct_value(obj, "minImageExtent", vulkan_ce_VkExtent2D, vk_VkExtent2D_from, &dst->minImageExtent, scratch, visited)
		&& vulkan_struct_value(obj, "maxImageExtent", vulkan_ce_VkExtent2D, vk_VkExtent2D_from, &dst->maxImageExtent, scratch, visited)
		&& vulkan_u32(obj, "maxImageArrayLayers", &dst->maxImageArrayLayers)
		&& vulkan_u32(obj, "supportedTransforms", &dst->supportedTransforms)
		&& vulkan_u32(obj, "currentTransform", &dst->currentTransform)
		&& vulkan_u32(obj, "supportedCompositeAlpha", &dst->supportedCompositeAlpha)
		&& vulkan_u32(obj, "supportedUsageFlags", &dst->supportedUsageFlags);
}
void vk_VkSurfaceCapabilitiesKHR_to(const void *raw, zval *rv)
{
	const VkSurfaceCapabilitiesKHR *src = raw;
	zend_object *obj;
	object_init_ex(rv, vulkan_ce_VkSurfaceCapabilitiesKHR);
	obj = Z_OBJ_P(rv);
	vulkan_set_long(obj, "minImageCount", (zend_long) src->minImageCount);
	vulkan_set_long(obj, "maxImageCount", (zend_long) src->maxImageCount);
	vulkan_set_extent2(obj, "currentExtent", &src->currentExtent);
	vulkan_set_extent2(obj, "minImageExtent", &src->minImageExtent);
	vulkan_set_extent2(obj, "maxImageExtent", &src->maxImageExtent);
	vulkan_set_long(obj, "maxImageArrayLayers", (zend_long) src->maxImageArrayLayers);
	vulkan_set_long(obj, "supportedTransforms", (zend_long) src->supportedTransforms);
	vulkan_set_long(obj, "currentTransform", (zend_long) src->currentTransform);
	vulkan_set_long(obj, "supportedCompositeAlpha", (zend_long) src->supportedCompositeAlpha);
	vulkan_set_long(obj, "supportedUsageFlags", (zend_long) src->supportedUsageFlags);
}

bool vk_VkSwapchainCreateInfoKHR_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkSwapchainCreateInfoKHR *dst = raw;
	uint64_t surface, old_swapchain;
	memset(dst, 0, sizeof(*dst));
	dst->sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
	if (!vulkan_enter(obj, visited) || !vulkan_pnext(obj, &dst->pNext, scratch, visited)) return false;
	if (!vulkan_handle_prop(obj, "surface", vulkan_ce_VkSurfaceKHR, &surface)) return false;
	if (!vulkan_handle_prop(obj, "oldSwapchain", vulkan_ce_VkSwapchainKHR, &old_swapchain)) return false;
	dst->surface = (VkSurfaceKHR) (uintptr_t) surface;
	dst->oldSwapchain = (VkSwapchainKHR) (uintptr_t) old_swapchain;
	return vulkan_u32(obj, "flags", &dst->flags)
		&& vulkan_u32(obj, "minImageCount", &dst->minImageCount)
		&& vulkan_u32(obj, "imageFormat", &dst->imageFormat)
		&& vulkan_u32(obj, "imageColorSpace", &dst->imageColorSpace)
		&& vulkan_struct_value(obj, "imageExtent", vulkan_ce_VkExtent2D, vk_VkExtent2D_from, &dst->imageExtent, scratch, visited)
		&& vulkan_u32(obj, "imageArrayLayers", &dst->imageArrayLayers)
		&& vulkan_u32(obj, "imageUsage", &dst->imageUsage)
		&& vulkan_u32(obj, "imageSharingMode", &dst->imageSharingMode)
		&& vulkan_u32_list(obj, "pQueueFamilyIndices", &dst->pQueueFamilyIndices, &dst->queueFamilyIndexCount, scratch)
		&& vulkan_u32(obj, "preTransform", &dst->preTransform)
		&& vulkan_u32(obj, "compositeAlpha", &dst->compositeAlpha)
		&& vulkan_u32(obj, "presentMode", &dst->presentMode)
		&& vulkan_u32(obj, "clipped", &dst->clipped);
}
void vk_VkSwapchainCreateInfoKHR_to(const void *raw, zval *rv) { (void) raw; object_init_ex(rv, vulkan_ce_VkSwapchainCreateInfoKHR); }

bool vk_VkPresentInfoKHR_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkPresentInfoKHR *dst = raw;
	uint64_t *waits = NULL, *chains = NULL;
	const uint32_t *indices = NULL;
	uint32_t index_count = 0;

	memset(dst, 0, sizeof(*dst));
	dst->sType = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;
	if (!vulkan_enter(obj, visited) || !vulkan_pnext(obj, &dst->pNext, scratch, visited)) return false;
	if (!vulkan_handle_list(obj, "pWaitSemaphores", vulkan_ce_VkSemaphore, &waits, &dst->waitSemaphoreCount, scratch)) return false;
	if (!vulkan_handle_list(obj, "pSwapchains", vulkan_ce_VkSwapchainKHR, &chains, &dst->swapchainCount, scratch)) return false;
	if (!vulkan_u32_list(obj, "pImageIndices", &indices, &index_count, scratch)) return false;
	if (index_count != dst->swapchainCount) {
		zend_value_error("VkPresentInfoKHR::$pImageIndices must be the same length");
		return false;
	}
	dst->pWaitSemaphores = (const VkSemaphore *) waits;
	dst->pSwapchains = (const VkSwapchainKHR *) chains;
	dst->pImageIndices = indices;
	return true;
}
void vk_VkPresentInfoKHR_to(const void *raw, zval *rv) { (void) raw; object_init_ex(rv, vulkan_ce_VkPresentInfoKHR); }
