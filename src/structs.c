#include "structs.h"

zend_class_entry *vulkan_ce_VkApplicationInfo;
zend_class_entry *vulkan_ce_VkInstanceCreateInfo;
zend_class_entry *vulkan_ce_VkDeviceQueueCreateInfo;
zend_class_entry *vulkan_ce_VkPhysicalDeviceFeatures;
zend_class_entry *vulkan_ce_VkPhysicalDeviceFeatures2;
zend_class_entry *vulkan_ce_VkPhysicalDevicePortabilitySubsetFeaturesKHR;
zend_class_entry *vulkan_ce_VkDeviceCreateInfo;
zend_class_entry *vulkan_ce_VkPhysicalDeviceLimits;
zend_class_entry *vulkan_ce_VkPhysicalDeviceSparseProperties;
zend_class_entry *vulkan_ce_VkPhysicalDeviceProperties;
zend_class_entry *vulkan_ce_VkExtent3D;
zend_class_entry *vulkan_ce_VkQueueFamilyProperties;
zend_class_entry *vulkan_ce_VkMemoryType;
zend_class_entry *vulkan_ce_VkMemoryHeap;
zend_class_entry *vulkan_ce_VkPhysicalDeviceMemoryProperties;
zend_class_entry *vulkan_ce_VkFormatProperties;
zend_class_entry *vulkan_ce_VkExtensionProperties;
zend_class_entry *vulkan_ce_VkInstance;
zend_class_entry *vulkan_ce_VkPhysicalDevice;
zend_class_entry *vulkan_ce_VkDevice;
zend_class_entry *vulkan_ce_VkQueue;
zend_class_entry *vulkan_ce_VkMemoryAllocateInfo;
zend_class_entry *vulkan_ce_VkMappedMemoryRange;
zend_class_entry *vulkan_ce_VkBufferCreateInfo;
zend_class_entry *vulkan_ce_VkMemoryRequirements;
zend_class_entry *vulkan_ce_VkImageCreateInfo;
zend_class_entry *vulkan_ce_VkComponentMapping;
zend_class_entry *vulkan_ce_VkImageSubresourceRange;
zend_class_entry *vulkan_ce_VkImageViewCreateInfo;
zend_class_entry *vulkan_ce_VkSamplerCreateInfo;
zend_class_entry *vulkan_ce_VkDeviceMemory;
zend_class_entry *vulkan_ce_VkBuffer;
zend_class_entry *vulkan_ce_VkImage;
zend_class_entry *vulkan_ce_VkImageView;
zend_class_entry *vulkan_ce_VkSampler;
zend_class_entry *vulkan_ce_VkAttachmentDescription;
zend_class_entry *vulkan_ce_VkAttachmentReference;
zend_class_entry *vulkan_ce_VkSubpassDescription;
zend_class_entry *vulkan_ce_VkSubpassDependency;
zend_class_entry *vulkan_ce_VkRenderPassCreateInfo;
zend_class_entry *vulkan_ce_VkFramebufferCreateInfo;
zend_class_entry *vulkan_ce_VkShaderModuleCreateInfo;
zend_class_entry *vulkan_ce_VkPushConstantRange;
zend_class_entry *vulkan_ce_VkPipelineLayoutCreateInfo;
zend_class_entry *vulkan_ce_VkPipelineShaderStageCreateInfo;
zend_class_entry *vulkan_ce_VkVertexInputBindingDescription;
zend_class_entry *vulkan_ce_VkVertexInputAttributeDescription;
zend_class_entry *vulkan_ce_VkPipelineVertexInputStateCreateInfo;
zend_class_entry *vulkan_ce_VkPipelineInputAssemblyStateCreateInfo;
zend_class_entry *vulkan_ce_VkPipelineViewportStateCreateInfo;
zend_class_entry *vulkan_ce_VkPipelineRasterizationStateCreateInfo;
zend_class_entry *vulkan_ce_VkPipelineMultisampleStateCreateInfo;
zend_class_entry *vulkan_ce_VkStencilOpState;
zend_class_entry *vulkan_ce_VkPipelineDepthStencilStateCreateInfo;
zend_class_entry *vulkan_ce_VkPipelineColorBlendAttachmentState;
zend_class_entry *vulkan_ce_VkPipelineColorBlendStateCreateInfo;
zend_class_entry *vulkan_ce_VkPipelineDynamicStateCreateInfo;
zend_class_entry *vulkan_ce_VkPipelineTessellationStateCreateInfo;
zend_class_entry *vulkan_ce_VkGraphicsPipelineCreateInfo;
zend_class_entry *vulkan_ce_VkDescriptorSetLayoutBinding;
zend_class_entry *vulkan_ce_VkDescriptorSetLayoutCreateInfo;
zend_class_entry *vulkan_ce_VkDescriptorPoolSize;
zend_class_entry *vulkan_ce_VkDescriptorPoolCreateInfo;
zend_class_entry *vulkan_ce_VkDescriptorSetAllocateInfo;
zend_class_entry *vulkan_ce_VkDescriptorImageInfo;
zend_class_entry *vulkan_ce_VkWriteDescriptorSet;
zend_class_entry *vulkan_ce_VkViewport;
zend_class_entry *vulkan_ce_VkOffset2D;
zend_class_entry *vulkan_ce_VkExtent2D;
zend_class_entry *vulkan_ce_VkRect2D;
zend_class_entry *vulkan_ce_VkRenderPass;
zend_class_entry *vulkan_ce_VkFramebuffer;
zend_class_entry *vulkan_ce_VkShaderModule;
zend_class_entry *vulkan_ce_VkPipelineLayout;
zend_class_entry *vulkan_ce_VkPipeline;
zend_class_entry *vulkan_ce_VkDescriptorSetLayout;
zend_class_entry *vulkan_ce_VkDescriptorPool;
zend_class_entry *vulkan_ce_VkDescriptorSet;
zend_class_entry *vulkan_ce_VkCommandPoolCreateInfo;
zend_class_entry *vulkan_ce_VkCommandBufferAllocateInfo;
zend_class_entry *vulkan_ce_VkCommandBufferInheritanceInfo;
zend_class_entry *vulkan_ce_VkCommandBufferBeginInfo;
zend_class_entry *vulkan_ce_VkClearColorValue;
zend_class_entry *vulkan_ce_VkClearDepthStencilValue;
zend_class_entry *vulkan_ce_VkClearValue;
zend_class_entry *vulkan_ce_VkRenderPassBeginInfo;
zend_class_entry *vulkan_ce_VkOffset3D;
zend_class_entry *vulkan_ce_VkImageSubresourceLayers;
zend_class_entry *vulkan_ce_VkBufferImageCopy;
zend_class_entry *vulkan_ce_VkImageBlit;
zend_class_entry *vulkan_ce_VkImageMemoryBarrier;
zend_class_entry *vulkan_ce_VkSubmitInfo;
zend_class_entry *vulkan_ce_VkFenceCreateInfo;
zend_class_entry *vulkan_ce_VkSemaphoreCreateInfo;
zend_class_entry *vulkan_ce_VkClearAttachment;
zend_class_entry *vulkan_ce_VkClearRect;
zend_class_entry *vulkan_ce_VkCommandPool;
zend_class_entry *vulkan_ce_VkCommandBuffer;
zend_class_entry *vulkan_ce_VkFence;
zend_class_entry *vulkan_ce_VkSemaphore;
zend_class_entry *vulkan_ce_VkSurfaceFormatKHR;
zend_class_entry *vulkan_ce_VkSurfaceCapabilitiesKHR;
zend_class_entry *vulkan_ce_VkSwapchainCreateInfoKHR;
zend_class_entry *vulkan_ce_VkPresentInfoKHR;
zend_class_entry *vulkan_ce_VkSurfaceKHR;
zend_class_entry *vulkan_ce_VkSwapchainKHR;
zend_class_entry *vulkan_ce_VkExternalMemoryImageCreateInfo;
zend_class_entry *vulkan_ce_VkExportMemoryAllocateInfo;
zend_class_entry *vulkan_ce_VkMemoryGetFdInfoKHR;
zend_class_entry *vulkan_ce_VkImageDrmFormatModifierListCreateInfoEXT;
zend_class_entry *vulkan_ce_VkImageDrmFormatModifierPropertiesEXT;
zend_class_entry *vulkan_ce_VkImageSubresource;
zend_class_entry *vulkan_ce_VkSubresourceLayout;


static bool vulkan_struct_ptr(zend_object *obj, const char *name, zend_class_entry *ce, size_t size, vulkan_from_fn from, void **out, vulkan_scratch *scratch, HashTable *visited)
{
	zval *zv = zend_read_property(obj->ce, obj, name, strlen(name), 0, NULL);

	if (zv == NULL || EG(exception) != NULL) {
		return false;
	}
	if (Z_TYPE_P(zv) == IS_NULL) {
		*out = NULL;
		return true;
	}
	if (Z_TYPE_P(zv) != IS_OBJECT || !instanceof_function(Z_OBJCE_P(zv), ce)) {
		zend_type_error("%s::$%s must be null or an instance of %s", ZSTR_VAL(obj->ce->name), name, ZSTR_VAL(ce->name));
		return false;
	}

	*out = vulkan_scratch_alloc(scratch, size);
	return from(Z_OBJ_P(zv), *out, scratch, visited);
}

static bool vulkan_struct_value(zend_object *obj, const char *name, zend_class_entry *ce, vulkan_from_fn from, void *dst, vulkan_scratch *scratch, HashTable *visited)
{
	zval *zv = zend_read_property(obj->ce, obj, name, strlen(name), 0, NULL);

	if (zv == NULL || EG(exception) != NULL) {
		return false;
	}
	if (Z_TYPE_P(zv) != IS_OBJECT || !instanceof_function(Z_OBJCE_P(zv), ce)) {
		zend_type_error("%s::$%s must be an instance of %s", ZSTR_VAL(obj->ce->name), name, ZSTR_VAL(ce->name));
		return false;
	}

	return from(Z_OBJ_P(zv), dst, scratch, visited);
}

static bool vulkan_struct_list(zend_object *obj, const char *name, zend_class_entry *ce, size_t size, vulkan_from_fn from, void **out, uint32_t *count, vulkan_scratch *scratch, HashTable *visited)
{
	zval *zv = zend_read_property(obj->ce, obj, name, strlen(name), 0, NULL);
	zval *item;
	uint32_t n, i;
	char *stored;

	if (zv == NULL || EG(exception) != NULL) {
		return false;
	}
	if (Z_TYPE_P(zv) != IS_ARRAY) {
		zend_type_error("%s::$%s must be a list of %s", ZSTR_VAL(obj->ce->name), name, ZSTR_VAL(ce->name));
		return false;
	}

	n = zend_hash_num_elements(Z_ARRVAL_P(zv));
	*count = n;
	if (n == 0) {
		*out = NULL;
		return true;
	}

	stored = vulkan_scratch_alloc(scratch, size * n);
	i = 0;
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(zv), item) {
		if (Z_TYPE_P(item) != IS_OBJECT || !instanceof_function(Z_OBJCE_P(item), ce)) {
			zend_type_error("%s::$%s must be a list of %s", ZSTR_VAL(obj->ce->name), name, ZSTR_VAL(ce->name));
			return false;
		}
		if (!from(Z_OBJ_P(item), stored + (size_t) i * size, scratch, visited)) {
			return false;
		}
		i++;
	} ZEND_HASH_FOREACH_END();

	*out = stored;
	return true;
}

static bool vulkan_counted_struct(zend_object *obj, const char *name, zend_class_entry *ce, vulkan_from_fn from, void *dst, size_t size, uint32_t max, uint32_t *count, vulkan_scratch *scratch, HashTable *visited)
{
	zval *zv = zend_read_property(obj->ce, obj, name, strlen(name), 0, NULL);
	zval *item;
	uint32_t n, i;

	if (zv == NULL || EG(exception) != NULL) {
		return false;
	}
	if (Z_TYPE_P(zv) != IS_ARRAY) {
		zend_type_error("%s::$%s must be a list of %s", ZSTR_VAL(obj->ce->name), name, ZSTR_VAL(ce->name));
		return false;
	}

	n = zend_hash_num_elements(Z_ARRVAL_P(zv));
	if (n > max) {
		zend_value_error("%s::$%s holds at most %u values", ZSTR_VAL(obj->ce->name), name, max);
		return false;
	}
	i = 0;
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(zv), item) {
		if (Z_TYPE_P(item) != IS_OBJECT || !instanceof_function(Z_OBJCE_P(item), ce)) {
			zend_type_error("%s::$%s must be a list of %s", ZSTR_VAL(obj->ce->name), name, ZSTR_VAL(ce->name));
			return false;
		}
		if (!from(Z_OBJ_P(item), (char *) dst + (size_t) i * size, scratch, visited)) {
			return false;
		}
		i++;
	} ZEND_HASH_FOREACH_END();
	*count = n;
	return true;
}

static void vulkan_set_null(zend_object *obj, const char *name)
{
	zval tmp;
	ZVAL_NULL(&tmp);
	zend_update_property(obj->ce, obj, name, strlen(name), &tmp);
}

static void vulkan_set_float_array(zend_object *obj, const char *name, const float *values, uint32_t count)
{
	zval arr, item;
	uint32_t i;

	array_init_size(&arr, count);
	for (i = 0; i < count; i++) {
		ZVAL_DOUBLE(&item, (double) values[i]);
		zend_hash_next_index_insert(Z_ARRVAL(arr), &item);
	}
	vulkan_set_zval(obj, name, &arr);
}

static void vulkan_set_u32_array(zend_object *obj, const char *name, const uint32_t *values, uint32_t count)
{
	zval arr, item;
	uint32_t i;

	array_init_size(&arr, count);
	for (i = 0; i < count; i++) {
		ZVAL_LONG(&item, (zend_long) values[i]);
		zend_hash_next_index_insert(Z_ARRVAL(arr), &item);
	}
	vulkan_set_zval(obj, name, &arr);
}

static void vulkan_set_struct_value(zend_object *obj, const char *name, const void *src, vulkan_to_fn to)
{
	zval nested;
	to(src, &nested);
	vulkan_set_zval(obj, name, &nested);
}

static void vulkan_set_struct_array(zend_object *obj, const char *name, const void *src, uint32_t count, size_t size, vulkan_to_fn to)
{
	zval arr, nested;
	uint32_t i;

	array_init_size(&arr, count);
	for (i = 0; i < count; i++) {
		to((const char *) src + (size_t) i * size, &nested);
		zend_hash_next_index_insert(Z_ARRVAL(arr), &nested);
	}
	vulkan_set_zval(obj, name, &arr);
}

typedef struct vulkan_struct_kind {
	zend_class_entry **ce;
	size_t size;
	vulkan_from_fn from;
} vulkan_struct_kind;

bool vk_VkApplicationInfo_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited);
void vk_VkApplicationInfo_to(const void *raw, zval *rv);
bool vk_VkInstanceCreateInfo_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited);
void vk_VkInstanceCreateInfo_to(const void *raw, zval *rv);
bool vk_VkDeviceQueueCreateInfo_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited);
void vk_VkDeviceQueueCreateInfo_to(const void *raw, zval *rv);
bool vk_VkPhysicalDeviceFeatures_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited);
void vk_VkPhysicalDeviceFeatures_to(const void *raw, zval *rv);
bool vk_VkPhysicalDeviceFeatures2_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited);
void vk_VkPhysicalDeviceFeatures2_to(const void *raw, zval *rv);
bool vk_VkPhysicalDevicePortabilitySubsetFeaturesKHR_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited);
void vk_VkPhysicalDevicePortabilitySubsetFeaturesKHR_to(const void *raw, zval *rv);
bool vk_VkDeviceCreateInfo_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited);
void vk_VkDeviceCreateInfo_to(const void *raw, zval *rv);
bool vk_VkPhysicalDeviceLimits_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited);
void vk_VkPhysicalDeviceLimits_to(const void *raw, zval *rv);
bool vk_VkPhysicalDeviceSparseProperties_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited);
void vk_VkPhysicalDeviceSparseProperties_to(const void *raw, zval *rv);
bool vk_VkPhysicalDeviceProperties_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited);
void vk_VkPhysicalDeviceProperties_to(const void *raw, zval *rv);
bool vk_VkExtent3D_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited);
void vk_VkExtent3D_to(const void *raw, zval *rv);
bool vk_VkQueueFamilyProperties_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited);
void vk_VkQueueFamilyProperties_to(const void *raw, zval *rv);
bool vk_VkMemoryType_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited);
void vk_VkMemoryType_to(const void *raw, zval *rv);
bool vk_VkMemoryHeap_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited);
void vk_VkMemoryHeap_to(const void *raw, zval *rv);
bool vk_VkPhysicalDeviceMemoryProperties_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited);
void vk_VkPhysicalDeviceMemoryProperties_to(const void *raw, zval *rv);
bool vk_VkFormatProperties_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited);
void vk_VkFormatProperties_to(const void *raw, zval *rv);
bool vk_VkExtensionProperties_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited);
void vk_VkExtensionProperties_to(const void *raw, zval *rv);

static const vulkan_struct_kind vulkan_kinds[] = {
	{ &vulkan_ce_VkApplicationInfo, sizeof(VkApplicationInfo), vk_VkApplicationInfo_from },
	{ &vulkan_ce_VkInstanceCreateInfo, sizeof(VkInstanceCreateInfo), vk_VkInstanceCreateInfo_from },
	{ &vulkan_ce_VkDeviceQueueCreateInfo, sizeof(VkDeviceQueueCreateInfo), vk_VkDeviceQueueCreateInfo_from },
	{ &vulkan_ce_VkPhysicalDeviceFeatures, sizeof(VkPhysicalDeviceFeatures), vk_VkPhysicalDeviceFeatures_from },
	{ &vulkan_ce_VkPhysicalDeviceFeatures2, sizeof(VkPhysicalDeviceFeatures2), vk_VkPhysicalDeviceFeatures2_from },
	{ &vulkan_ce_VkPhysicalDevicePortabilitySubsetFeaturesKHR, sizeof(VkPhysicalDevicePortabilitySubsetFeaturesKHR), vk_VkPhysicalDevicePortabilitySubsetFeaturesKHR_from },
	{ &vulkan_ce_VkDeviceCreateInfo, sizeof(VkDeviceCreateInfo), vk_VkDeviceCreateInfo_from },
	{ &vulkan_ce_VkPhysicalDeviceLimits, sizeof(VkPhysicalDeviceLimits), vk_VkPhysicalDeviceLimits_from },
	{ &vulkan_ce_VkPhysicalDeviceSparseProperties, sizeof(VkPhysicalDeviceSparseProperties), vk_VkPhysicalDeviceSparseProperties_from },
	{ &vulkan_ce_VkPhysicalDeviceProperties, sizeof(VkPhysicalDeviceProperties), vk_VkPhysicalDeviceProperties_from },
	{ &vulkan_ce_VkExtent3D, sizeof(VkExtent3D), vk_VkExtent3D_from },
	{ &vulkan_ce_VkQueueFamilyProperties, sizeof(VkQueueFamilyProperties), vk_VkQueueFamilyProperties_from },
	{ &vulkan_ce_VkMemoryType, sizeof(VkMemoryType), vk_VkMemoryType_from },
	{ &vulkan_ce_VkMemoryHeap, sizeof(VkMemoryHeap), vk_VkMemoryHeap_from },
	{ &vulkan_ce_VkPhysicalDeviceMemoryProperties, sizeof(VkPhysicalDeviceMemoryProperties), vk_VkPhysicalDeviceMemoryProperties_from },
	{ &vulkan_ce_VkFormatProperties, sizeof(VkFormatProperties), vk_VkFormatProperties_from },
	{ &vulkan_ce_VkExtensionProperties, sizeof(VkExtensionProperties), vk_VkExtensionProperties_from },
	{ &vulkan_ce_VkMemoryAllocateInfo, sizeof(VkMemoryAllocateInfo), vk_VkMemoryAllocateInfo_from },
	{ &vulkan_ce_VkMappedMemoryRange, sizeof(VkMappedMemoryRange), vk_VkMappedMemoryRange_from },
	{ &vulkan_ce_VkBufferCreateInfo, sizeof(VkBufferCreateInfo), vk_VkBufferCreateInfo_from },
	{ &vulkan_ce_VkMemoryRequirements, sizeof(VkMemoryRequirements), vk_VkMemoryRequirements_from },
	{ &vulkan_ce_VkImageCreateInfo, sizeof(VkImageCreateInfo), vk_VkImageCreateInfo_from },
	{ &vulkan_ce_VkComponentMapping, sizeof(VkComponentMapping), vk_VkComponentMapping_from },
	{ &vulkan_ce_VkImageSubresourceRange, sizeof(VkImageSubresourceRange), vk_VkImageSubresourceRange_from },
	{ &vulkan_ce_VkImageViewCreateInfo, sizeof(VkImageViewCreateInfo), vk_VkImageViewCreateInfo_from },
	{ &vulkan_ce_VkSamplerCreateInfo, sizeof(VkSamplerCreateInfo), vk_VkSamplerCreateInfo_from },
	{ &vulkan_ce_VkAttachmentDescription, sizeof(VkAttachmentDescription), vk_VkAttachmentDescription_from },
	{ &vulkan_ce_VkAttachmentReference, sizeof(VkAttachmentReference), vk_VkAttachmentReference_from },
	{ &vulkan_ce_VkSubpassDescription, sizeof(VkSubpassDescription), vk_VkSubpassDescription_from },
	{ &vulkan_ce_VkSubpassDependency, sizeof(VkSubpassDependency), vk_VkSubpassDependency_from },
	{ &vulkan_ce_VkRenderPassCreateInfo, sizeof(VkRenderPassCreateInfo), vk_VkRenderPassCreateInfo_from },
	{ &vulkan_ce_VkFramebufferCreateInfo, sizeof(VkFramebufferCreateInfo), vk_VkFramebufferCreateInfo_from },
	{ &vulkan_ce_VkShaderModuleCreateInfo, sizeof(VkShaderModuleCreateInfo), vk_VkShaderModuleCreateInfo_from },
	{ &vulkan_ce_VkPushConstantRange, sizeof(VkPushConstantRange), vk_VkPushConstantRange_from },
	{ &vulkan_ce_VkPipelineLayoutCreateInfo, sizeof(VkPipelineLayoutCreateInfo), vk_VkPipelineLayoutCreateInfo_from },
	{ &vulkan_ce_VkPipelineShaderStageCreateInfo, sizeof(VkPipelineShaderStageCreateInfo), vk_VkPipelineShaderStageCreateInfo_from },
	{ &vulkan_ce_VkVertexInputBindingDescription, sizeof(VkVertexInputBindingDescription), vk_VkVertexInputBindingDescription_from },
	{ &vulkan_ce_VkVertexInputAttributeDescription, sizeof(VkVertexInputAttributeDescription), vk_VkVertexInputAttributeDescription_from },
	{ &vulkan_ce_VkPipelineVertexInputStateCreateInfo, sizeof(VkPipelineVertexInputStateCreateInfo), vk_VkPipelineVertexInputStateCreateInfo_from },
	{ &vulkan_ce_VkPipelineInputAssemblyStateCreateInfo, sizeof(VkPipelineInputAssemblyStateCreateInfo), vk_VkPipelineInputAssemblyStateCreateInfo_from },
	{ &vulkan_ce_VkPipelineViewportStateCreateInfo, sizeof(VkPipelineViewportStateCreateInfo), vk_VkPipelineViewportStateCreateInfo_from },
	{ &vulkan_ce_VkPipelineRasterizationStateCreateInfo, sizeof(VkPipelineRasterizationStateCreateInfo), vk_VkPipelineRasterizationStateCreateInfo_from },
	{ &vulkan_ce_VkPipelineMultisampleStateCreateInfo, sizeof(VkPipelineMultisampleStateCreateInfo), vk_VkPipelineMultisampleStateCreateInfo_from },
	{ &vulkan_ce_VkStencilOpState, sizeof(VkStencilOpState), vk_VkStencilOpState_from },
	{ &vulkan_ce_VkPipelineDepthStencilStateCreateInfo, sizeof(VkPipelineDepthStencilStateCreateInfo), vk_VkPipelineDepthStencilStateCreateInfo_from },
	{ &vulkan_ce_VkPipelineColorBlendAttachmentState, sizeof(VkPipelineColorBlendAttachmentState), vk_VkPipelineColorBlendAttachmentState_from },
	{ &vulkan_ce_VkPipelineColorBlendStateCreateInfo, sizeof(VkPipelineColorBlendStateCreateInfo), vk_VkPipelineColorBlendStateCreateInfo_from },
	{ &vulkan_ce_VkPipelineDynamicStateCreateInfo, sizeof(VkPipelineDynamicStateCreateInfo), vk_VkPipelineDynamicStateCreateInfo_from },
	{ &vulkan_ce_VkPipelineTessellationStateCreateInfo, sizeof(VkPipelineTessellationStateCreateInfo), vk_VkPipelineTessellationStateCreateInfo_from },
	{ &vulkan_ce_VkGraphicsPipelineCreateInfo, sizeof(VkGraphicsPipelineCreateInfo), vk_VkGraphicsPipelineCreateInfo_from },
	{ &vulkan_ce_VkDescriptorSetLayoutBinding, sizeof(VkDescriptorSetLayoutBinding), vk_VkDescriptorSetLayoutBinding_from },
	{ &vulkan_ce_VkDescriptorSetLayoutCreateInfo, sizeof(VkDescriptorSetLayoutCreateInfo), vk_VkDescriptorSetLayoutCreateInfo_from },
	{ &vulkan_ce_VkDescriptorPoolSize, sizeof(VkDescriptorPoolSize), vk_VkDescriptorPoolSize_from },
	{ &vulkan_ce_VkDescriptorPoolCreateInfo, sizeof(VkDescriptorPoolCreateInfo), vk_VkDescriptorPoolCreateInfo_from },
	{ &vulkan_ce_VkDescriptorSetAllocateInfo, sizeof(VkDescriptorSetAllocateInfo), vk_VkDescriptorSetAllocateInfo_from },
	{ &vulkan_ce_VkDescriptorImageInfo, sizeof(VkDescriptorImageInfo), vk_VkDescriptorImageInfo_from },
	{ &vulkan_ce_VkWriteDescriptorSet, sizeof(VkWriteDescriptorSet), vk_VkWriteDescriptorSet_from },
	{ &vulkan_ce_VkCommandPoolCreateInfo, sizeof(VkCommandPoolCreateInfo), vk_VkCommandPoolCreateInfo_from },
	{ &vulkan_ce_VkCommandBufferAllocateInfo, sizeof(VkCommandBufferAllocateInfo), vk_VkCommandBufferAllocateInfo_from },
	{ &vulkan_ce_VkCommandBufferInheritanceInfo, sizeof(VkCommandBufferInheritanceInfo), vk_VkCommandBufferInheritanceInfo_from },
	{ &vulkan_ce_VkCommandBufferBeginInfo, sizeof(VkCommandBufferBeginInfo), vk_VkCommandBufferBeginInfo_from },
	{ &vulkan_ce_VkClearColorValue, sizeof(VkClearColorValue), vk_VkClearColorValue_from },
	{ &vulkan_ce_VkClearDepthStencilValue, sizeof(VkClearDepthStencilValue), vk_VkClearDepthStencilValue_from },
	{ &vulkan_ce_VkClearValue, sizeof(VkClearValue), vk_VkClearValue_from },
	{ &vulkan_ce_VkRenderPassBeginInfo, sizeof(VkRenderPassBeginInfo), vk_VkRenderPassBeginInfo_from },
	{ &vulkan_ce_VkOffset3D, sizeof(VkOffset3D), vk_VkOffset3D_from },
	{ &vulkan_ce_VkImageSubresourceLayers, sizeof(VkImageSubresourceLayers), vk_VkImageSubresourceLayers_from },
	{ &vulkan_ce_VkBufferImageCopy, sizeof(VkBufferImageCopy), vk_VkBufferImageCopy_from },
	{ &vulkan_ce_VkImageBlit, sizeof(VkImageBlit), vk_VkImageBlit_from },
	{ &vulkan_ce_VkImageMemoryBarrier, sizeof(VkImageMemoryBarrier), vk_VkImageMemoryBarrier_from },
	{ &vulkan_ce_VkSubmitInfo, sizeof(VkSubmitInfo), vk_VkSubmitInfo_from },
	{ &vulkan_ce_VkFenceCreateInfo, sizeof(VkFenceCreateInfo), vk_VkFenceCreateInfo_from },
	{ &vulkan_ce_VkSemaphoreCreateInfo, sizeof(VkSemaphoreCreateInfo), vk_VkSemaphoreCreateInfo_from },
	{ &vulkan_ce_VkClearAttachment, sizeof(VkClearAttachment), vk_VkClearAttachment_from },
	{ &vulkan_ce_VkClearRect, sizeof(VkClearRect), vk_VkClearRect_from },
	{ &vulkan_ce_VkSurfaceFormatKHR, sizeof(VkSurfaceFormatKHR), vk_VkSurfaceFormatKHR_from },
	{ &vulkan_ce_VkSurfaceCapabilitiesKHR, sizeof(VkSurfaceCapabilitiesKHR), vk_VkSurfaceCapabilitiesKHR_from },
	{ &vulkan_ce_VkSwapchainCreateInfoKHR, sizeof(VkSwapchainCreateInfoKHR), vk_VkSwapchainCreateInfoKHR_from },
	{ &vulkan_ce_VkPresentInfoKHR, sizeof(VkPresentInfoKHR), vk_VkPresentInfoKHR_from },
	{ &vulkan_ce_VkExternalMemoryImageCreateInfo, sizeof(VkExternalMemoryImageCreateInfo), vk_VkExternalMemoryImageCreateInfo_from },
	{ &vulkan_ce_VkExportMemoryAllocateInfo, sizeof(VkExportMemoryAllocateInfo), vk_VkExportMemoryAllocateInfo_from },
	{ &vulkan_ce_VkMemoryGetFdInfoKHR, sizeof(VkMemoryGetFdInfoKHR), vk_VkMemoryGetFdInfoKHR_from },
	{ &vulkan_ce_VkImageDrmFormatModifierListCreateInfoEXT, sizeof(VkImageDrmFormatModifierListCreateInfoEXT), vk_VkImageDrmFormatModifierListCreateInfoEXT_from },
	{ &vulkan_ce_VkImageDrmFormatModifierPropertiesEXT, sizeof(VkImageDrmFormatModifierPropertiesEXT), vk_VkImageDrmFormatModifierPropertiesEXT_from },
	{ &vulkan_ce_VkImageSubresource, sizeof(VkImageSubresource), vk_VkImageSubresource_from },
	{ &vulkan_ce_VkSubresourceLayout, sizeof(VkSubresourceLayout), vk_VkSubresourceLayout_from },
	{ &vulkan_ce_VkViewport, sizeof(VkViewport), vk_VkViewport_from },
	{ &vulkan_ce_VkOffset2D, sizeof(VkOffset2D), vk_VkOffset2D_from },
	{ &vulkan_ce_VkExtent2D, sizeof(VkExtent2D), vk_VkExtent2D_from },
	{ &vulkan_ce_VkRect2D, sizeof(VkRect2D), vk_VkRect2D_from },
	{ NULL, 0, NULL },
};


bool vulkan_pnext(zend_object *obj, const void **out, vulkan_scratch *scratch, HashTable *visited)
{
	zval *zv = zend_read_property(obj->ce, obj, "pNext", sizeof("pNext") - 1, 0, NULL);
	const vulkan_struct_kind *kind;
	zend_object *next;

	if (zv == NULL || EG(exception) != NULL) {
		return false;
	}
	if (Z_TYPE_P(zv) == IS_NULL) {
		*out = NULL;
		return true;
	}
	if (Z_TYPE_P(zv) != IS_OBJECT) {
		zend_type_error("%s::$pNext must be null or a Vulkan structure", ZSTR_VAL(obj->ce->name));
		return false;
	}

	next = Z_OBJ_P(zv);
	kind = NULL;
	for (size_t i = 0; vulkan_kinds[i].ce != NULL; i++) {
		if (*vulkan_kinds[i].ce == next->ce) {
			kind = &vulkan_kinds[i];
			break;
		}
	}
	if (kind == NULL) {
		zend_type_error("pNext must be a Vulkan structure, %s given", ZSTR_VAL(next->ce->name));
		return false;
	}
	if (zend_hash_index_exists(visited, (zend_ulong) (uintptr_t) next)) {
		zend_value_error("pNext chain loops");
		return false;
	}
	{
		zval marker;
		ZVAL_NULL(&marker);
		zend_hash_index_update(visited, (zend_ulong) (uintptr_t) next, &marker);
	}

	*out = vulkan_scratch_alloc(scratch, kind->size);
	return kind->from(next, *out, scratch, visited);
}

bool vk_VkApplicationInfo_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkApplicationInfo *dst = raw;
	memset(dst, 0, sizeof(*dst));
	dst->sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	if (!vulkan_enter(obj, visited)) {
		return false;
	}
	if (!vulkan_pnext(obj, &dst->pNext, scratch, visited)) {
		return false;
	}
	if (!vulkan_cstring(obj, "pApplicationName", &dst->pApplicationName)) {
		return false;
	}
	if (!vulkan_u32(obj, "applicationVersion", &dst->applicationVersion)) {
		return false;
	}
	if (!vulkan_cstring(obj, "pEngineName", &dst->pEngineName)) {
		return false;
	}
	if (!vulkan_u32(obj, "engineVersion", &dst->engineVersion)) {
		return false;
	}
	if (!vulkan_u32(obj, "apiVersion", &dst->apiVersion)) {
		return false;
	}
	return true;
}

void vk_VkApplicationInfo_to(const void *raw, zval *rv)
{
	const VkApplicationInfo *src = raw;
	object_init_ex(rv, vulkan_ce_VkApplicationInfo);
	{
		zend_object *obj = Z_OBJ_P(rv);
	vulkan_set_null(obj, "pNext");
	vulkan_set_string(obj, "pApplicationName", src->pApplicationName);
	vulkan_set_long(obj, "applicationVersion", (zend_long) src->applicationVersion);
	vulkan_set_string(obj, "pEngineName", src->pEngineName);
	vulkan_set_long(obj, "engineVersion", (zend_long) src->engineVersion);
	vulkan_set_long(obj, "apiVersion", (zend_long) src->apiVersion);
	}
}

bool vk_VkInstanceCreateInfo_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkInstanceCreateInfo *dst = raw;
	memset(dst, 0, sizeof(*dst));
	dst->sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	if (!vulkan_enter(obj, visited)) {
		return false;
	}
	if (!vulkan_pnext(obj, &dst->pNext, scratch, visited)) {
		return false;
	}
	if (!vulkan_u32(obj, "flags", &dst->flags)) {
		return false;
	}
	if (!vulkan_struct_ptr(obj, "pApplicationInfo", vulkan_ce_VkApplicationInfo, sizeof(VkApplicationInfo), vk_VkApplicationInfo_from, (void **) &dst->pApplicationInfo, scratch, visited)) {
		return false;
	}
	if (!vulkan_u32(obj, "enabledLayerCount", &dst->enabledLayerCount)) {
		return false;
	}
	if (!vulkan_string_list(obj, "enabledLayerNames", &dst->ppEnabledLayerNames, &dst->enabledLayerCount, scratch)) {
		return false;
	}
	if (!vulkan_u32(obj, "enabledExtensionCount", &dst->enabledExtensionCount)) {
		return false;
	}
	if (!vulkan_string_list(obj, "enabledExtensionNames", &dst->ppEnabledExtensionNames, &dst->enabledExtensionCount, scratch)) {
		return false;
	}
	return true;
}

void vk_VkInstanceCreateInfo_to(const void *raw, zval *rv)
{
	const VkInstanceCreateInfo *src = raw;
	object_init_ex(rv, vulkan_ce_VkInstanceCreateInfo);
	{
		zend_object *obj = Z_OBJ_P(rv);
	vulkan_set_null(obj, "pNext");
	vulkan_set_long(obj, "flags", (zend_long) src->flags);
	/* struct_ptr pApplicationInfo is an input */
	vulkan_set_long(obj, "enabledLayerCount", (zend_long) src->enabledLayerCount);
	/* string_list enabledLayerNames is an input */
	vulkan_set_long(obj, "enabledExtensionCount", (zend_long) src->enabledExtensionCount);
	/* string_list enabledExtensionNames is an input */
	}
}

bool vk_VkDeviceQueueCreateInfo_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkDeviceQueueCreateInfo *dst = raw;
	memset(dst, 0, sizeof(*dst));
	dst->sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
	if (!vulkan_enter(obj, visited)) {
		return false;
	}
	if (!vulkan_pnext(obj, &dst->pNext, scratch, visited)) {
		return false;
	}
	if (!vulkan_u32(obj, "flags", &dst->flags)) {
		return false;
	}
	if (!vulkan_u32(obj, "queueFamilyIndex", &dst->queueFamilyIndex)) {
		return false;
	}
	if (!vulkan_float_list(obj, "pQueuePriorities", &dst->pQueuePriorities, &dst->queueCount, scratch)) {
		return false;
	}
	return true;
}

void vk_VkDeviceQueueCreateInfo_to(const void *raw, zval *rv)
{
	const VkDeviceQueueCreateInfo *src = raw;
	object_init_ex(rv, vulkan_ce_VkDeviceQueueCreateInfo);
	{
		zend_object *obj = Z_OBJ_P(rv);
	vulkan_set_null(obj, "pNext");
	vulkan_set_long(obj, "flags", (zend_long) src->flags);
	vulkan_set_long(obj, "queueFamilyIndex", (zend_long) src->queueFamilyIndex);
	/* float_list pQueuePriorities is an input */
	}
}

bool vk_VkPhysicalDeviceFeatures_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkPhysicalDeviceFeatures *dst = raw;
	memset(dst, 0, sizeof(*dst));
	if (!vulkan_enter(obj, visited)) {
		return false;
	}
	if (!vulkan_bool32(obj, "robustBufferAccess", &dst->robustBufferAccess)) {
		return false;
	}
	if (!vulkan_bool32(obj, "fullDrawIndexUint32", &dst->fullDrawIndexUint32)) {
		return false;
	}
	if (!vulkan_bool32(obj, "imageCubeArray", &dst->imageCubeArray)) {
		return false;
	}
	if (!vulkan_bool32(obj, "independentBlend", &dst->independentBlend)) {
		return false;
	}
	if (!vulkan_bool32(obj, "geometryShader", &dst->geometryShader)) {
		return false;
	}
	if (!vulkan_bool32(obj, "tessellationShader", &dst->tessellationShader)) {
		return false;
	}
	if (!vulkan_bool32(obj, "sampleRateShading", &dst->sampleRateShading)) {
		return false;
	}
	if (!vulkan_bool32(obj, "dualSrcBlend", &dst->dualSrcBlend)) {
		return false;
	}
	if (!vulkan_bool32(obj, "logicOp", &dst->logicOp)) {
		return false;
	}
	if (!vulkan_bool32(obj, "multiDrawIndirect", &dst->multiDrawIndirect)) {
		return false;
	}
	if (!vulkan_bool32(obj, "drawIndirectFirstInstance", &dst->drawIndirectFirstInstance)) {
		return false;
	}
	if (!vulkan_bool32(obj, "depthClamp", &dst->depthClamp)) {
		return false;
	}
	if (!vulkan_bool32(obj, "depthBiasClamp", &dst->depthBiasClamp)) {
		return false;
	}
	if (!vulkan_bool32(obj, "fillModeNonSolid", &dst->fillModeNonSolid)) {
		return false;
	}
	if (!vulkan_bool32(obj, "depthBounds", &dst->depthBounds)) {
		return false;
	}
	if (!vulkan_bool32(obj, "wideLines", &dst->wideLines)) {
		return false;
	}
	if (!vulkan_bool32(obj, "largePoints", &dst->largePoints)) {
		return false;
	}
	if (!vulkan_bool32(obj, "alphaToOne", &dst->alphaToOne)) {
		return false;
	}
	if (!vulkan_bool32(obj, "multiViewport", &dst->multiViewport)) {
		return false;
	}
	if (!vulkan_bool32(obj, "samplerAnisotropy", &dst->samplerAnisotropy)) {
		return false;
	}
	if (!vulkan_bool32(obj, "textureCompressionETC2", &dst->textureCompressionETC2)) {
		return false;
	}
	if (!vulkan_bool32(obj, "textureCompressionASTC_LDR", &dst->textureCompressionASTC_LDR)) {
		return false;
	}
	if (!vulkan_bool32(obj, "textureCompressionBC", &dst->textureCompressionBC)) {
		return false;
	}
	if (!vulkan_bool32(obj, "occlusionQueryPrecise", &dst->occlusionQueryPrecise)) {
		return false;
	}
	if (!vulkan_bool32(obj, "pipelineStatisticsQuery", &dst->pipelineStatisticsQuery)) {
		return false;
	}
	if (!vulkan_bool32(obj, "vertexPipelineStoresAndAtomics", &dst->vertexPipelineStoresAndAtomics)) {
		return false;
	}
	if (!vulkan_bool32(obj, "fragmentStoresAndAtomics", &dst->fragmentStoresAndAtomics)) {
		return false;
	}
	if (!vulkan_bool32(obj, "shaderTessellationAndGeometryPointSize", &dst->shaderTessellationAndGeometryPointSize)) {
		return false;
	}
	if (!vulkan_bool32(obj, "shaderImageGatherExtended", &dst->shaderImageGatherExtended)) {
		return false;
	}
	if (!vulkan_bool32(obj, "shaderStorageImageExtendedFormats", &dst->shaderStorageImageExtendedFormats)) {
		return false;
	}
	if (!vulkan_bool32(obj, "shaderStorageImageMultisample", &dst->shaderStorageImageMultisample)) {
		return false;
	}
	if (!vulkan_bool32(obj, "shaderStorageImageReadWithoutFormat", &dst->shaderStorageImageReadWithoutFormat)) {
		return false;
	}
	if (!vulkan_bool32(obj, "shaderStorageImageWriteWithoutFormat", &dst->shaderStorageImageWriteWithoutFormat)) {
		return false;
	}
	if (!vulkan_bool32(obj, "shaderUniformBufferArrayDynamicIndexing", &dst->shaderUniformBufferArrayDynamicIndexing)) {
		return false;
	}
	if (!vulkan_bool32(obj, "shaderSampledImageArrayDynamicIndexing", &dst->shaderSampledImageArrayDynamicIndexing)) {
		return false;
	}
	if (!vulkan_bool32(obj, "shaderStorageBufferArrayDynamicIndexing", &dst->shaderStorageBufferArrayDynamicIndexing)) {
		return false;
	}
	if (!vulkan_bool32(obj, "shaderStorageImageArrayDynamicIndexing", &dst->shaderStorageImageArrayDynamicIndexing)) {
		return false;
	}
	if (!vulkan_bool32(obj, "shaderClipDistance", &dst->shaderClipDistance)) {
		return false;
	}
	if (!vulkan_bool32(obj, "shaderCullDistance", &dst->shaderCullDistance)) {
		return false;
	}
	if (!vulkan_bool32(obj, "shaderFloat64", &dst->shaderFloat64)) {
		return false;
	}
	if (!vulkan_bool32(obj, "shaderInt64", &dst->shaderInt64)) {
		return false;
	}
	if (!vulkan_bool32(obj, "shaderInt16", &dst->shaderInt16)) {
		return false;
	}
	if (!vulkan_bool32(obj, "shaderResourceResidency", &dst->shaderResourceResidency)) {
		return false;
	}
	if (!vulkan_bool32(obj, "shaderResourceMinLod", &dst->shaderResourceMinLod)) {
		return false;
	}
	if (!vulkan_bool32(obj, "sparseBinding", &dst->sparseBinding)) {
		return false;
	}
	if (!vulkan_bool32(obj, "sparseResidencyBuffer", &dst->sparseResidencyBuffer)) {
		return false;
	}
	if (!vulkan_bool32(obj, "sparseResidencyImage2D", &dst->sparseResidencyImage2D)) {
		return false;
	}
	if (!vulkan_bool32(obj, "sparseResidencyImage3D", &dst->sparseResidencyImage3D)) {
		return false;
	}
	if (!vulkan_bool32(obj, "sparseResidency2Samples", &dst->sparseResidency2Samples)) {
		return false;
	}
	if (!vulkan_bool32(obj, "sparseResidency4Samples", &dst->sparseResidency4Samples)) {
		return false;
	}
	if (!vulkan_bool32(obj, "sparseResidency8Samples", &dst->sparseResidency8Samples)) {
		return false;
	}
	if (!vulkan_bool32(obj, "sparseResidency16Samples", &dst->sparseResidency16Samples)) {
		return false;
	}
	if (!vulkan_bool32(obj, "sparseResidencyAliased", &dst->sparseResidencyAliased)) {
		return false;
	}
	if (!vulkan_bool32(obj, "variableMultisampleRate", &dst->variableMultisampleRate)) {
		return false;
	}
	if (!vulkan_bool32(obj, "inheritedQueries", &dst->inheritedQueries)) {
		return false;
	}
	return true;
}

static void vulkan_features_apply(zend_object *obj, const VkPhysicalDeviceFeatures *src)
{
	vulkan_set_bool(obj, "robustBufferAccess", src->robustBufferAccess == VK_TRUE);
	vulkan_set_bool(obj, "fullDrawIndexUint32", src->fullDrawIndexUint32 == VK_TRUE);
	vulkan_set_bool(obj, "imageCubeArray", src->imageCubeArray == VK_TRUE);
	vulkan_set_bool(obj, "independentBlend", src->independentBlend == VK_TRUE);
	vulkan_set_bool(obj, "geometryShader", src->geometryShader == VK_TRUE);
	vulkan_set_bool(obj, "tessellationShader", src->tessellationShader == VK_TRUE);
	vulkan_set_bool(obj, "sampleRateShading", src->sampleRateShading == VK_TRUE);
	vulkan_set_bool(obj, "dualSrcBlend", src->dualSrcBlend == VK_TRUE);
	vulkan_set_bool(obj, "logicOp", src->logicOp == VK_TRUE);
	vulkan_set_bool(obj, "multiDrawIndirect", src->multiDrawIndirect == VK_TRUE);
	vulkan_set_bool(obj, "drawIndirectFirstInstance", src->drawIndirectFirstInstance == VK_TRUE);
	vulkan_set_bool(obj, "depthClamp", src->depthClamp == VK_TRUE);
	vulkan_set_bool(obj, "depthBiasClamp", src->depthBiasClamp == VK_TRUE);
	vulkan_set_bool(obj, "fillModeNonSolid", src->fillModeNonSolid == VK_TRUE);
	vulkan_set_bool(obj, "depthBounds", src->depthBounds == VK_TRUE);
	vulkan_set_bool(obj, "wideLines", src->wideLines == VK_TRUE);
	vulkan_set_bool(obj, "largePoints", src->largePoints == VK_TRUE);
	vulkan_set_bool(obj, "alphaToOne", src->alphaToOne == VK_TRUE);
	vulkan_set_bool(obj, "multiViewport", src->multiViewport == VK_TRUE);
	vulkan_set_bool(obj, "samplerAnisotropy", src->samplerAnisotropy == VK_TRUE);
	vulkan_set_bool(obj, "textureCompressionETC2", src->textureCompressionETC2 == VK_TRUE);
	vulkan_set_bool(obj, "textureCompressionASTC_LDR", src->textureCompressionASTC_LDR == VK_TRUE);
	vulkan_set_bool(obj, "textureCompressionBC", src->textureCompressionBC == VK_TRUE);
	vulkan_set_bool(obj, "occlusionQueryPrecise", src->occlusionQueryPrecise == VK_TRUE);
	vulkan_set_bool(obj, "pipelineStatisticsQuery", src->pipelineStatisticsQuery == VK_TRUE);
	vulkan_set_bool(obj, "vertexPipelineStoresAndAtomics", src->vertexPipelineStoresAndAtomics == VK_TRUE);
	vulkan_set_bool(obj, "fragmentStoresAndAtomics", src->fragmentStoresAndAtomics == VK_TRUE);
	vulkan_set_bool(obj, "shaderTessellationAndGeometryPointSize", src->shaderTessellationAndGeometryPointSize == VK_TRUE);
	vulkan_set_bool(obj, "shaderImageGatherExtended", src->shaderImageGatherExtended == VK_TRUE);
	vulkan_set_bool(obj, "shaderStorageImageExtendedFormats", src->shaderStorageImageExtendedFormats == VK_TRUE);
	vulkan_set_bool(obj, "shaderStorageImageMultisample", src->shaderStorageImageMultisample == VK_TRUE);
	vulkan_set_bool(obj, "shaderStorageImageReadWithoutFormat", src->shaderStorageImageReadWithoutFormat == VK_TRUE);
	vulkan_set_bool(obj, "shaderStorageImageWriteWithoutFormat", src->shaderStorageImageWriteWithoutFormat == VK_TRUE);
	vulkan_set_bool(obj, "shaderUniformBufferArrayDynamicIndexing", src->shaderUniformBufferArrayDynamicIndexing == VK_TRUE);
	vulkan_set_bool(obj, "shaderSampledImageArrayDynamicIndexing", src->shaderSampledImageArrayDynamicIndexing == VK_TRUE);
	vulkan_set_bool(obj, "shaderStorageBufferArrayDynamicIndexing", src->shaderStorageBufferArrayDynamicIndexing == VK_TRUE);
	vulkan_set_bool(obj, "shaderStorageImageArrayDynamicIndexing", src->shaderStorageImageArrayDynamicIndexing == VK_TRUE);
	vulkan_set_bool(obj, "shaderClipDistance", src->shaderClipDistance == VK_TRUE);
	vulkan_set_bool(obj, "shaderCullDistance", src->shaderCullDistance == VK_TRUE);
	vulkan_set_bool(obj, "shaderFloat64", src->shaderFloat64 == VK_TRUE);
	vulkan_set_bool(obj, "shaderInt64", src->shaderInt64 == VK_TRUE);
	vulkan_set_bool(obj, "shaderInt16", src->shaderInt16 == VK_TRUE);
	vulkan_set_bool(obj, "shaderResourceResidency", src->shaderResourceResidency == VK_TRUE);
	vulkan_set_bool(obj, "shaderResourceMinLod", src->shaderResourceMinLod == VK_TRUE);
	vulkan_set_bool(obj, "sparseBinding", src->sparseBinding == VK_TRUE);
	vulkan_set_bool(obj, "sparseResidencyBuffer", src->sparseResidencyBuffer == VK_TRUE);
	vulkan_set_bool(obj, "sparseResidencyImage2D", src->sparseResidencyImage2D == VK_TRUE);
	vulkan_set_bool(obj, "sparseResidencyImage3D", src->sparseResidencyImage3D == VK_TRUE);
	vulkan_set_bool(obj, "sparseResidency2Samples", src->sparseResidency2Samples == VK_TRUE);
	vulkan_set_bool(obj, "sparseResidency4Samples", src->sparseResidency4Samples == VK_TRUE);
	vulkan_set_bool(obj, "sparseResidency8Samples", src->sparseResidency8Samples == VK_TRUE);
	vulkan_set_bool(obj, "sparseResidency16Samples", src->sparseResidency16Samples == VK_TRUE);
	vulkan_set_bool(obj, "sparseResidencyAliased", src->sparseResidencyAliased == VK_TRUE);
	vulkan_set_bool(obj, "variableMultisampleRate", src->variableMultisampleRate == VK_TRUE);
	vulkan_set_bool(obj, "inheritedQueries", src->inheritedQueries == VK_TRUE);
}

void vk_VkPhysicalDeviceFeatures_to(const void *raw, zval *rv)
{
	object_init_ex(rv, vulkan_ce_VkPhysicalDeviceFeatures);
	vulkan_features_apply(Z_OBJ_P(rv), raw);
}

static void vulkan_features2_apply(zend_object *obj, const VkPhysicalDeviceFeatures2 *src)
{
	zval *features = zend_read_property(obj->ce, obj, "features", sizeof("features") - 1, 0, NULL);

	if (features == NULL || Z_TYPE_P(features) != IS_OBJECT) {
		return;
	}
	vulkan_features_apply(Z_OBJ_P(features), &src->features);
}

static void vulkan_portability_apply(zend_object *obj, const VkPhysicalDevicePortabilitySubsetFeaturesKHR *src)
{
	vulkan_set_bool(obj, "constantAlphaColorBlendFactors", src->constantAlphaColorBlendFactors == VK_TRUE);
	vulkan_set_bool(obj, "events", src->events == VK_TRUE);
	vulkan_set_bool(obj, "imageViewFormatReinterpretation", src->imageViewFormatReinterpretation == VK_TRUE);
	vulkan_set_bool(obj, "imageViewFormatSwizzle", src->imageViewFormatSwizzle == VK_TRUE);
	vulkan_set_bool(obj, "imageView2DOn3DImage", src->imageView2DOn3DImage == VK_TRUE);
	vulkan_set_bool(obj, "multisampleArrayImage", src->multisampleArrayImage == VK_TRUE);
	vulkan_set_bool(obj, "mutableComparisonSamplers", src->mutableComparisonSamplers == VK_TRUE);
	vulkan_set_bool(obj, "pointPolygons", src->pointPolygons == VK_TRUE);
	vulkan_set_bool(obj, "samplerMipLodBias", src->samplerMipLodBias == VK_TRUE);
	vulkan_set_bool(obj, "separateStencilMaskRef", src->separateStencilMaskRef == VK_TRUE);
	vulkan_set_bool(obj, "shaderSampleRateInterpolationFunctions", src->shaderSampleRateInterpolationFunctions == VK_TRUE);
	vulkan_set_bool(obj, "tessellationIsolines", src->tessellationIsolines == VK_TRUE);
	vulkan_set_bool(obj, "tessellationPointMode", src->tessellationPointMode == VK_TRUE);
	vulkan_set_bool(obj, "triangleFans", src->triangleFans == VK_TRUE);
	vulkan_set_bool(obj, "vertexAttributeAccessBeyondStride", src->vertexAttributeAccessBeyondStride == VK_TRUE);
}

void vulkan_store_pnext_chain(zend_object *obj, const void *raw)
{
	const VkBaseInStructure *base = raw;
	zval *next;

	if (obj->ce == vulkan_ce_VkPhysicalDeviceFeatures2) {
		vulkan_features2_apply(obj, raw);
	} else if (obj->ce == vulkan_ce_VkPhysicalDevicePortabilitySubsetFeaturesKHR) {
		vulkan_portability_apply(obj, raw);
	}

	next = zend_read_property(obj->ce, obj, "pNext", sizeof("pNext") - 1, 0, NULL);
	if (next != NULL && Z_TYPE_P(next) == IS_OBJECT && base->pNext != NULL) {
		vulkan_store_pnext_chain(Z_OBJ_P(next), base->pNext);
	}
}

bool vk_VkPhysicalDeviceFeatures2_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkPhysicalDeviceFeatures2 *dst = raw;
	const void *next = NULL;

	memset(dst, 0, sizeof(*dst));
	dst->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2;
	if (!vulkan_enter(obj, visited)) {
		return false;
	}
	if (!vulkan_pnext(obj, &next, scratch, visited)) {
		return false;
	}
	dst->pNext = (void *) next;
	return vulkan_struct_value(obj, "features", vulkan_ce_VkPhysicalDeviceFeatures, vk_VkPhysicalDeviceFeatures_from, &dst->features, scratch, visited);
}

void vk_VkPhysicalDeviceFeatures2_to(const void *raw, zval *rv)
{
	object_init_ex(rv, vulkan_ce_VkPhysicalDeviceFeatures2);
	vulkan_init_nested(Z_OBJ_P(rv), "features", vulkan_ce_VkPhysicalDeviceFeatures);
	vulkan_set_null(Z_OBJ_P(rv), "pNext");
	vulkan_features2_apply(Z_OBJ_P(rv), raw);
}

bool vk_VkPhysicalDevicePortabilitySubsetFeaturesKHR_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkPhysicalDevicePortabilitySubsetFeaturesKHR *dst = raw;
	const void *next = NULL;

	memset(dst, 0, sizeof(*dst));
	dst->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_FEATURES_KHR;
	if (!vulkan_enter(obj, visited)) {
		return false;
	}
	if (!vulkan_pnext(obj, &next, scratch, visited)) {
		return false;
	}
	dst->pNext = (void *) next;
	if (!vulkan_bool32(obj, "constantAlphaColorBlendFactors", &dst->constantAlphaColorBlendFactors)) return false;
	if (!vulkan_bool32(obj, "events", &dst->events)) return false;
	if (!vulkan_bool32(obj, "imageViewFormatReinterpretation", &dst->imageViewFormatReinterpretation)) return false;
	if (!vulkan_bool32(obj, "imageViewFormatSwizzle", &dst->imageViewFormatSwizzle)) return false;
	if (!vulkan_bool32(obj, "imageView2DOn3DImage", &dst->imageView2DOn3DImage)) return false;
	if (!vulkan_bool32(obj, "multisampleArrayImage", &dst->multisampleArrayImage)) return false;
	if (!vulkan_bool32(obj, "mutableComparisonSamplers", &dst->mutableComparisonSamplers)) return false;
	if (!vulkan_bool32(obj, "pointPolygons", &dst->pointPolygons)) return false;
	if (!vulkan_bool32(obj, "samplerMipLodBias", &dst->samplerMipLodBias)) return false;
	if (!vulkan_bool32(obj, "separateStencilMaskRef", &dst->separateStencilMaskRef)) return false;
	if (!vulkan_bool32(obj, "shaderSampleRateInterpolationFunctions", &dst->shaderSampleRateInterpolationFunctions)) return false;
	if (!vulkan_bool32(obj, "tessellationIsolines", &dst->tessellationIsolines)) return false;
	if (!vulkan_bool32(obj, "tessellationPointMode", &dst->tessellationPointMode)) return false;
	if (!vulkan_bool32(obj, "triangleFans", &dst->triangleFans)) return false;
	if (!vulkan_bool32(obj, "vertexAttributeAccessBeyondStride", &dst->vertexAttributeAccessBeyondStride)) return false;
	return true;
}

void vk_VkPhysicalDevicePortabilitySubsetFeaturesKHR_to(const void *raw, zval *rv)
{
	object_init_ex(rv, vulkan_ce_VkPhysicalDevicePortabilitySubsetFeaturesKHR);
	vulkan_set_null(Z_OBJ_P(rv), "pNext");
	vulkan_portability_apply(Z_OBJ_P(rv), raw);
}

bool vk_VkDeviceCreateInfo_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkDeviceCreateInfo *dst = raw;
	memset(dst, 0, sizeof(*dst));
	dst->sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
	if (!vulkan_enter(obj, visited)) {
		return false;
	}
	if (!vulkan_pnext(obj, &dst->pNext, scratch, visited)) {
		return false;
	}
	if (!vulkan_u32(obj, "flags", &dst->flags)) {
		return false;
	}
	if (!vulkan_struct_list(obj, "pQueueCreateInfos", vulkan_ce_VkDeviceQueueCreateInfo, sizeof(VkDeviceQueueCreateInfo), vk_VkDeviceQueueCreateInfo_from, (void **) &dst->pQueueCreateInfos, &dst->queueCreateInfoCount, scratch, visited)) {
		return false;
	}
	if (!vulkan_u32(obj, "enabledLayerCount", &dst->enabledLayerCount)) {
		return false;
	}
	if (!vulkan_string_list(obj, "enabledLayerNames", &dst->ppEnabledLayerNames, &dst->enabledLayerCount, scratch)) {
		return false;
	}
	if (!vulkan_u32(obj, "enabledExtensionCount", &dst->enabledExtensionCount)) {
		return false;
	}
	if (!vulkan_string_list(obj, "enabledExtensionNames", &dst->ppEnabledExtensionNames, &dst->enabledExtensionCount, scratch)) {
		return false;
	}
	if (!vulkan_struct_ptr(obj, "pEnabledFeatures", vulkan_ce_VkPhysicalDeviceFeatures, sizeof(VkPhysicalDeviceFeatures), vk_VkPhysicalDeviceFeatures_from, (void **) &dst->pEnabledFeatures, scratch, visited)) {
		return false;
	}
	return true;
}

void vk_VkDeviceCreateInfo_to(const void *raw, zval *rv)
{
	const VkDeviceCreateInfo *src = raw;
	object_init_ex(rv, vulkan_ce_VkDeviceCreateInfo);
	{
		zend_object *obj = Z_OBJ_P(rv);
	vulkan_set_null(obj, "pNext");
	vulkan_set_long(obj, "flags", (zend_long) src->flags);
	/* struct_list pQueueCreateInfos is an input */
	vulkan_set_long(obj, "enabledLayerCount", (zend_long) src->enabledLayerCount);
	/* string_list enabledLayerNames is an input */
	vulkan_set_long(obj, "enabledExtensionCount", (zend_long) src->enabledExtensionCount);
	/* string_list enabledExtensionNames is an input */
	/* struct_ptr pEnabledFeatures is an input */
	}
}

bool vk_VkPhysicalDeviceLimits_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkPhysicalDeviceLimits *dst = raw;
	memset(dst, 0, sizeof(*dst));
	if (!vulkan_enter(obj, visited)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxImageDimension1D", &dst->maxImageDimension1D)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxImageDimension2D", &dst->maxImageDimension2D)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxImageDimension3D", &dst->maxImageDimension3D)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxImageDimensionCube", &dst->maxImageDimensionCube)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxImageArrayLayers", &dst->maxImageArrayLayers)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxTexelBufferElements", &dst->maxTexelBufferElements)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxUniformBufferRange", &dst->maxUniformBufferRange)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxStorageBufferRange", &dst->maxStorageBufferRange)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxPushConstantsSize", &dst->maxPushConstantsSize)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxMemoryAllocationCount", &dst->maxMemoryAllocationCount)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxSamplerAllocationCount", &dst->maxSamplerAllocationCount)) {
		return false;
	}
	if (!vulkan_u64(obj, "bufferImageGranularity", &dst->bufferImageGranularity)) {
		return false;
	}
	if (!vulkan_u64(obj, "sparseAddressSpaceSize", &dst->sparseAddressSpaceSize)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxBoundDescriptorSets", &dst->maxBoundDescriptorSets)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxPerStageDescriptorSamplers", &dst->maxPerStageDescriptorSamplers)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxPerStageDescriptorUniformBuffers", &dst->maxPerStageDescriptorUniformBuffers)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxPerStageDescriptorStorageBuffers", &dst->maxPerStageDescriptorStorageBuffers)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxPerStageDescriptorSampledImages", &dst->maxPerStageDescriptorSampledImages)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxPerStageDescriptorStorageImages", &dst->maxPerStageDescriptorStorageImages)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxPerStageDescriptorInputAttachments", &dst->maxPerStageDescriptorInputAttachments)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxPerStageResources", &dst->maxPerStageResources)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxDescriptorSetSamplers", &dst->maxDescriptorSetSamplers)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxDescriptorSetUniformBuffers", &dst->maxDescriptorSetUniformBuffers)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxDescriptorSetUniformBuffersDynamic", &dst->maxDescriptorSetUniformBuffersDynamic)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxDescriptorSetStorageBuffers", &dst->maxDescriptorSetStorageBuffers)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxDescriptorSetStorageBuffersDynamic", &dst->maxDescriptorSetStorageBuffersDynamic)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxDescriptorSetSampledImages", &dst->maxDescriptorSetSampledImages)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxDescriptorSetStorageImages", &dst->maxDescriptorSetStorageImages)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxDescriptorSetInputAttachments", &dst->maxDescriptorSetInputAttachments)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxVertexInputAttributes", &dst->maxVertexInputAttributes)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxVertexInputBindings", &dst->maxVertexInputBindings)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxVertexInputAttributeOffset", &dst->maxVertexInputAttributeOffset)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxVertexInputBindingStride", &dst->maxVertexInputBindingStride)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxVertexOutputComponents", &dst->maxVertexOutputComponents)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxTessellationGenerationLevel", &dst->maxTessellationGenerationLevel)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxTessellationPatchSize", &dst->maxTessellationPatchSize)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxTessellationControlPerVertexInputComponents", &dst->maxTessellationControlPerVertexInputComponents)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxTessellationControlPerVertexOutputComponents", &dst->maxTessellationControlPerVertexOutputComponents)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxTessellationControlPerPatchOutputComponents", &dst->maxTessellationControlPerPatchOutputComponents)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxTessellationControlTotalOutputComponents", &dst->maxTessellationControlTotalOutputComponents)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxTessellationEvaluationInputComponents", &dst->maxTessellationEvaluationInputComponents)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxTessellationEvaluationOutputComponents", &dst->maxTessellationEvaluationOutputComponents)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxGeometryShaderInvocations", &dst->maxGeometryShaderInvocations)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxGeometryInputComponents", &dst->maxGeometryInputComponents)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxGeometryOutputComponents", &dst->maxGeometryOutputComponents)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxGeometryOutputVertices", &dst->maxGeometryOutputVertices)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxGeometryTotalOutputComponents", &dst->maxGeometryTotalOutputComponents)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxFragmentInputComponents", &dst->maxFragmentInputComponents)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxFragmentOutputAttachments", &dst->maxFragmentOutputAttachments)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxFragmentDualSrcAttachments", &dst->maxFragmentDualSrcAttachments)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxFragmentCombinedOutputResources", &dst->maxFragmentCombinedOutputResources)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxComputeSharedMemorySize", &dst->maxComputeSharedMemorySize)) {
		return false;
	}
	if (!vulkan_fixed_u32s(obj, "maxComputeWorkGroupCount", dst->maxComputeWorkGroupCount, 3)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxComputeWorkGroupInvocations", &dst->maxComputeWorkGroupInvocations)) {
		return false;
	}
	if (!vulkan_fixed_u32s(obj, "maxComputeWorkGroupSize", dst->maxComputeWorkGroupSize, 3)) {
		return false;
	}
	if (!vulkan_u32(obj, "subPixelPrecisionBits", &dst->subPixelPrecisionBits)) {
		return false;
	}
	if (!vulkan_u32(obj, "subTexelPrecisionBits", &dst->subTexelPrecisionBits)) {
		return false;
	}
	if (!vulkan_u32(obj, "mipmapPrecisionBits", &dst->mipmapPrecisionBits)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxDrawIndexedIndexValue", &dst->maxDrawIndexedIndexValue)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxDrawIndirectCount", &dst->maxDrawIndirectCount)) {
		return false;
	}
	if (!vulkan_float(obj, "maxSamplerLodBias", &dst->maxSamplerLodBias)) {
		return false;
	}
	if (!vulkan_float(obj, "maxSamplerAnisotropy", &dst->maxSamplerAnisotropy)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxViewports", &dst->maxViewports)) {
		return false;
	}
	if (!vulkan_fixed_u32s(obj, "maxViewportDimensions", dst->maxViewportDimensions, 2)) {
		return false;
	}
	if (!vulkan_fixed_floats(obj, "viewportBoundsRange", dst->viewportBoundsRange, 2)) {
		return false;
	}
	if (!vulkan_u32(obj, "viewportSubPixelBits", &dst->viewportSubPixelBits)) {
		return false;
	}
	if (!vulkan_size(obj, "minMemoryMapAlignment", &dst->minMemoryMapAlignment)) {
		return false;
	}
	if (!vulkan_u64(obj, "minTexelBufferOffsetAlignment", &dst->minTexelBufferOffsetAlignment)) {
		return false;
	}
	if (!vulkan_u64(obj, "minUniformBufferOffsetAlignment", &dst->minUniformBufferOffsetAlignment)) {
		return false;
	}
	if (!vulkan_u64(obj, "minStorageBufferOffsetAlignment", &dst->minStorageBufferOffsetAlignment)) {
		return false;
	}
	if (!vulkan_i32(obj, "minTexelOffset", &dst->minTexelOffset)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxTexelOffset", &dst->maxTexelOffset)) {
		return false;
	}
	if (!vulkan_i32(obj, "minTexelGatherOffset", &dst->minTexelGatherOffset)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxTexelGatherOffset", &dst->maxTexelGatherOffset)) {
		return false;
	}
	if (!vulkan_float(obj, "minInterpolationOffset", &dst->minInterpolationOffset)) {
		return false;
	}
	if (!vulkan_float(obj, "maxInterpolationOffset", &dst->maxInterpolationOffset)) {
		return false;
	}
	if (!vulkan_u32(obj, "subPixelInterpolationOffsetBits", &dst->subPixelInterpolationOffsetBits)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxFramebufferWidth", &dst->maxFramebufferWidth)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxFramebufferHeight", &dst->maxFramebufferHeight)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxFramebufferLayers", &dst->maxFramebufferLayers)) {
		return false;
	}
	if (!vulkan_u32(obj, "framebufferColorSampleCounts", &dst->framebufferColorSampleCounts)) {
		return false;
	}
	if (!vulkan_u32(obj, "framebufferDepthSampleCounts", &dst->framebufferDepthSampleCounts)) {
		return false;
	}
	if (!vulkan_u32(obj, "framebufferStencilSampleCounts", &dst->framebufferStencilSampleCounts)) {
		return false;
	}
	if (!vulkan_u32(obj, "framebufferNoAttachmentsSampleCounts", &dst->framebufferNoAttachmentsSampleCounts)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxColorAttachments", &dst->maxColorAttachments)) {
		return false;
	}
	if (!vulkan_u32(obj, "sampledImageColorSampleCounts", &dst->sampledImageColorSampleCounts)) {
		return false;
	}
	if (!vulkan_u32(obj, "sampledImageIntegerSampleCounts", &dst->sampledImageIntegerSampleCounts)) {
		return false;
	}
	if (!vulkan_u32(obj, "sampledImageDepthSampleCounts", &dst->sampledImageDepthSampleCounts)) {
		return false;
	}
	if (!vulkan_u32(obj, "sampledImageStencilSampleCounts", &dst->sampledImageStencilSampleCounts)) {
		return false;
	}
	if (!vulkan_u32(obj, "storageImageSampleCounts", &dst->storageImageSampleCounts)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxSampleMaskWords", &dst->maxSampleMaskWords)) {
		return false;
	}
	if (!vulkan_bool32(obj, "timestampComputeAndGraphics", &dst->timestampComputeAndGraphics)) {
		return false;
	}
	if (!vulkan_float(obj, "timestampPeriod", &dst->timestampPeriod)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxClipDistances", &dst->maxClipDistances)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxCullDistances", &dst->maxCullDistances)) {
		return false;
	}
	if (!vulkan_u32(obj, "maxCombinedClipAndCullDistances", &dst->maxCombinedClipAndCullDistances)) {
		return false;
	}
	if (!vulkan_u32(obj, "discreteQueuePriorities", &dst->discreteQueuePriorities)) {
		return false;
	}
	if (!vulkan_fixed_floats(obj, "pointSizeRange", dst->pointSizeRange, 2)) {
		return false;
	}
	if (!vulkan_fixed_floats(obj, "lineWidthRange", dst->lineWidthRange, 2)) {
		return false;
	}
	if (!vulkan_float(obj, "pointSizeGranularity", &dst->pointSizeGranularity)) {
		return false;
	}
	if (!vulkan_float(obj, "lineWidthGranularity", &dst->lineWidthGranularity)) {
		return false;
	}
	if (!vulkan_bool32(obj, "strictLines", &dst->strictLines)) {
		return false;
	}
	if (!vulkan_bool32(obj, "standardSampleLocations", &dst->standardSampleLocations)) {
		return false;
	}
	if (!vulkan_u64(obj, "optimalBufferCopyOffsetAlignment", &dst->optimalBufferCopyOffsetAlignment)) {
		return false;
	}
	if (!vulkan_u64(obj, "optimalBufferCopyRowPitchAlignment", &dst->optimalBufferCopyRowPitchAlignment)) {
		return false;
	}
	if (!vulkan_u64(obj, "nonCoherentAtomSize", &dst->nonCoherentAtomSize)) {
		return false;
	}
	return true;
}

void vk_VkPhysicalDeviceLimits_to(const void *raw, zval *rv)
{
	const VkPhysicalDeviceLimits *src = raw;
	object_init_ex(rv, vulkan_ce_VkPhysicalDeviceLimits);
	{
		zend_object *obj = Z_OBJ_P(rv);
	vulkan_set_long(obj, "maxImageDimension1D", (zend_long) src->maxImageDimension1D);
	vulkan_set_long(obj, "maxImageDimension2D", (zend_long) src->maxImageDimension2D);
	vulkan_set_long(obj, "maxImageDimension3D", (zend_long) src->maxImageDimension3D);
	vulkan_set_long(obj, "maxImageDimensionCube", (zend_long) src->maxImageDimensionCube);
	vulkan_set_long(obj, "maxImageArrayLayers", (zend_long) src->maxImageArrayLayers);
	vulkan_set_long(obj, "maxTexelBufferElements", (zend_long) src->maxTexelBufferElements);
	vulkan_set_long(obj, "maxUniformBufferRange", (zend_long) src->maxUniformBufferRange);
	vulkan_set_long(obj, "maxStorageBufferRange", (zend_long) src->maxStorageBufferRange);
	vulkan_set_long(obj, "maxPushConstantsSize", (zend_long) src->maxPushConstantsSize);
	vulkan_set_long(obj, "maxMemoryAllocationCount", (zend_long) src->maxMemoryAllocationCount);
	vulkan_set_long(obj, "maxSamplerAllocationCount", (zend_long) src->maxSamplerAllocationCount);
	vulkan_set_long(obj, "bufferImageGranularity", (zend_long) src->bufferImageGranularity);
	vulkan_set_long(obj, "sparseAddressSpaceSize", (zend_long) src->sparseAddressSpaceSize);
	vulkan_set_long(obj, "maxBoundDescriptorSets", (zend_long) src->maxBoundDescriptorSets);
	vulkan_set_long(obj, "maxPerStageDescriptorSamplers", (zend_long) src->maxPerStageDescriptorSamplers);
	vulkan_set_long(obj, "maxPerStageDescriptorUniformBuffers", (zend_long) src->maxPerStageDescriptorUniformBuffers);
	vulkan_set_long(obj, "maxPerStageDescriptorStorageBuffers", (zend_long) src->maxPerStageDescriptorStorageBuffers);
	vulkan_set_long(obj, "maxPerStageDescriptorSampledImages", (zend_long) src->maxPerStageDescriptorSampledImages);
	vulkan_set_long(obj, "maxPerStageDescriptorStorageImages", (zend_long) src->maxPerStageDescriptorStorageImages);
	vulkan_set_long(obj, "maxPerStageDescriptorInputAttachments", (zend_long) src->maxPerStageDescriptorInputAttachments);
	vulkan_set_long(obj, "maxPerStageResources", (zend_long) src->maxPerStageResources);
	vulkan_set_long(obj, "maxDescriptorSetSamplers", (zend_long) src->maxDescriptorSetSamplers);
	vulkan_set_long(obj, "maxDescriptorSetUniformBuffers", (zend_long) src->maxDescriptorSetUniformBuffers);
	vulkan_set_long(obj, "maxDescriptorSetUniformBuffersDynamic", (zend_long) src->maxDescriptorSetUniformBuffersDynamic);
	vulkan_set_long(obj, "maxDescriptorSetStorageBuffers", (zend_long) src->maxDescriptorSetStorageBuffers);
	vulkan_set_long(obj, "maxDescriptorSetStorageBuffersDynamic", (zend_long) src->maxDescriptorSetStorageBuffersDynamic);
	vulkan_set_long(obj, "maxDescriptorSetSampledImages", (zend_long) src->maxDescriptorSetSampledImages);
	vulkan_set_long(obj, "maxDescriptorSetStorageImages", (zend_long) src->maxDescriptorSetStorageImages);
	vulkan_set_long(obj, "maxDescriptorSetInputAttachments", (zend_long) src->maxDescriptorSetInputAttachments);
	vulkan_set_long(obj, "maxVertexInputAttributes", (zend_long) src->maxVertexInputAttributes);
	vulkan_set_long(obj, "maxVertexInputBindings", (zend_long) src->maxVertexInputBindings);
	vulkan_set_long(obj, "maxVertexInputAttributeOffset", (zend_long) src->maxVertexInputAttributeOffset);
	vulkan_set_long(obj, "maxVertexInputBindingStride", (zend_long) src->maxVertexInputBindingStride);
	vulkan_set_long(obj, "maxVertexOutputComponents", (zend_long) src->maxVertexOutputComponents);
	vulkan_set_long(obj, "maxTessellationGenerationLevel", (zend_long) src->maxTessellationGenerationLevel);
	vulkan_set_long(obj, "maxTessellationPatchSize", (zend_long) src->maxTessellationPatchSize);
	vulkan_set_long(obj, "maxTessellationControlPerVertexInputComponents", (zend_long) src->maxTessellationControlPerVertexInputComponents);
	vulkan_set_long(obj, "maxTessellationControlPerVertexOutputComponents", (zend_long) src->maxTessellationControlPerVertexOutputComponents);
	vulkan_set_long(obj, "maxTessellationControlPerPatchOutputComponents", (zend_long) src->maxTessellationControlPerPatchOutputComponents);
	vulkan_set_long(obj, "maxTessellationControlTotalOutputComponents", (zend_long) src->maxTessellationControlTotalOutputComponents);
	vulkan_set_long(obj, "maxTessellationEvaluationInputComponents", (zend_long) src->maxTessellationEvaluationInputComponents);
	vulkan_set_long(obj, "maxTessellationEvaluationOutputComponents", (zend_long) src->maxTessellationEvaluationOutputComponents);
	vulkan_set_long(obj, "maxGeometryShaderInvocations", (zend_long) src->maxGeometryShaderInvocations);
	vulkan_set_long(obj, "maxGeometryInputComponents", (zend_long) src->maxGeometryInputComponents);
	vulkan_set_long(obj, "maxGeometryOutputComponents", (zend_long) src->maxGeometryOutputComponents);
	vulkan_set_long(obj, "maxGeometryOutputVertices", (zend_long) src->maxGeometryOutputVertices);
	vulkan_set_long(obj, "maxGeometryTotalOutputComponents", (zend_long) src->maxGeometryTotalOutputComponents);
	vulkan_set_long(obj, "maxFragmentInputComponents", (zend_long) src->maxFragmentInputComponents);
	vulkan_set_long(obj, "maxFragmentOutputAttachments", (zend_long) src->maxFragmentOutputAttachments);
	vulkan_set_long(obj, "maxFragmentDualSrcAttachments", (zend_long) src->maxFragmentDualSrcAttachments);
	vulkan_set_long(obj, "maxFragmentCombinedOutputResources", (zend_long) src->maxFragmentCombinedOutputResources);
	vulkan_set_long(obj, "maxComputeSharedMemorySize", (zend_long) src->maxComputeSharedMemorySize);
	vulkan_set_u32_array(obj, "maxComputeWorkGroupCount", src->maxComputeWorkGroupCount, 3);
	vulkan_set_long(obj, "maxComputeWorkGroupInvocations", (zend_long) src->maxComputeWorkGroupInvocations);
	vulkan_set_u32_array(obj, "maxComputeWorkGroupSize", src->maxComputeWorkGroupSize, 3);
	vulkan_set_long(obj, "subPixelPrecisionBits", (zend_long) src->subPixelPrecisionBits);
	vulkan_set_long(obj, "subTexelPrecisionBits", (zend_long) src->subTexelPrecisionBits);
	vulkan_set_long(obj, "mipmapPrecisionBits", (zend_long) src->mipmapPrecisionBits);
	vulkan_set_long(obj, "maxDrawIndexedIndexValue", (zend_long) src->maxDrawIndexedIndexValue);
	vulkan_set_long(obj, "maxDrawIndirectCount", (zend_long) src->maxDrawIndirectCount);
	vulkan_set_double(obj, "maxSamplerLodBias", (double) src->maxSamplerLodBias);
	vulkan_set_double(obj, "maxSamplerAnisotropy", (double) src->maxSamplerAnisotropy);
	vulkan_set_long(obj, "maxViewports", (zend_long) src->maxViewports);
	vulkan_set_u32_array(obj, "maxViewportDimensions", src->maxViewportDimensions, 2);
	vulkan_set_float_array(obj, "viewportBoundsRange", src->viewportBoundsRange, 2);
	vulkan_set_long(obj, "viewportSubPixelBits", (zend_long) src->viewportSubPixelBits);
	vulkan_set_long(obj, "minMemoryMapAlignment", (zend_long) src->minMemoryMapAlignment);
	vulkan_set_long(obj, "minTexelBufferOffsetAlignment", (zend_long) src->minTexelBufferOffsetAlignment);
	vulkan_set_long(obj, "minUniformBufferOffsetAlignment", (zend_long) src->minUniformBufferOffsetAlignment);
	vulkan_set_long(obj, "minStorageBufferOffsetAlignment", (zend_long) src->minStorageBufferOffsetAlignment);
	vulkan_set_long(obj, "minTexelOffset", (zend_long) src->minTexelOffset);
	vulkan_set_long(obj, "maxTexelOffset", (zend_long) src->maxTexelOffset);
	vulkan_set_long(obj, "minTexelGatherOffset", (zend_long) src->minTexelGatherOffset);
	vulkan_set_long(obj, "maxTexelGatherOffset", (zend_long) src->maxTexelGatherOffset);
	vulkan_set_double(obj, "minInterpolationOffset", (double) src->minInterpolationOffset);
	vulkan_set_double(obj, "maxInterpolationOffset", (double) src->maxInterpolationOffset);
	vulkan_set_long(obj, "subPixelInterpolationOffsetBits", (zend_long) src->subPixelInterpolationOffsetBits);
	vulkan_set_long(obj, "maxFramebufferWidth", (zend_long) src->maxFramebufferWidth);
	vulkan_set_long(obj, "maxFramebufferHeight", (zend_long) src->maxFramebufferHeight);
	vulkan_set_long(obj, "maxFramebufferLayers", (zend_long) src->maxFramebufferLayers);
	vulkan_set_long(obj, "framebufferColorSampleCounts", (zend_long) src->framebufferColorSampleCounts);
	vulkan_set_long(obj, "framebufferDepthSampleCounts", (zend_long) src->framebufferDepthSampleCounts);
	vulkan_set_long(obj, "framebufferStencilSampleCounts", (zend_long) src->framebufferStencilSampleCounts);
	vulkan_set_long(obj, "framebufferNoAttachmentsSampleCounts", (zend_long) src->framebufferNoAttachmentsSampleCounts);
	vulkan_set_long(obj, "maxColorAttachments", (zend_long) src->maxColorAttachments);
	vulkan_set_long(obj, "sampledImageColorSampleCounts", (zend_long) src->sampledImageColorSampleCounts);
	vulkan_set_long(obj, "sampledImageIntegerSampleCounts", (zend_long) src->sampledImageIntegerSampleCounts);
	vulkan_set_long(obj, "sampledImageDepthSampleCounts", (zend_long) src->sampledImageDepthSampleCounts);
	vulkan_set_long(obj, "sampledImageStencilSampleCounts", (zend_long) src->sampledImageStencilSampleCounts);
	vulkan_set_long(obj, "storageImageSampleCounts", (zend_long) src->storageImageSampleCounts);
	vulkan_set_long(obj, "maxSampleMaskWords", (zend_long) src->maxSampleMaskWords);
	vulkan_set_bool(obj, "timestampComputeAndGraphics", src->timestampComputeAndGraphics == VK_TRUE);
	vulkan_set_double(obj, "timestampPeriod", (double) src->timestampPeriod);
	vulkan_set_long(obj, "maxClipDistances", (zend_long) src->maxClipDistances);
	vulkan_set_long(obj, "maxCullDistances", (zend_long) src->maxCullDistances);
	vulkan_set_long(obj, "maxCombinedClipAndCullDistances", (zend_long) src->maxCombinedClipAndCullDistances);
	vulkan_set_long(obj, "discreteQueuePriorities", (zend_long) src->discreteQueuePriorities);
	vulkan_set_float_array(obj, "pointSizeRange", src->pointSizeRange, 2);
	vulkan_set_float_array(obj, "lineWidthRange", src->lineWidthRange, 2);
	vulkan_set_double(obj, "pointSizeGranularity", (double) src->pointSizeGranularity);
	vulkan_set_double(obj, "lineWidthGranularity", (double) src->lineWidthGranularity);
	vulkan_set_bool(obj, "strictLines", src->strictLines == VK_TRUE);
	vulkan_set_bool(obj, "standardSampleLocations", src->standardSampleLocations == VK_TRUE);
	vulkan_set_long(obj, "optimalBufferCopyOffsetAlignment", (zend_long) src->optimalBufferCopyOffsetAlignment);
	vulkan_set_long(obj, "optimalBufferCopyRowPitchAlignment", (zend_long) src->optimalBufferCopyRowPitchAlignment);
	vulkan_set_long(obj, "nonCoherentAtomSize", (zend_long) src->nonCoherentAtomSize);
	}
}

bool vk_VkPhysicalDeviceSparseProperties_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkPhysicalDeviceSparseProperties *dst = raw;
	memset(dst, 0, sizeof(*dst));
	if (!vulkan_enter(obj, visited)) {
		return false;
	}
	if (!vulkan_bool32(obj, "residencyStandard2DBlockShape", &dst->residencyStandard2DBlockShape)) {
		return false;
	}
	if (!vulkan_bool32(obj, "residencyStandard2DMultisampleBlockShape", &dst->residencyStandard2DMultisampleBlockShape)) {
		return false;
	}
	if (!vulkan_bool32(obj, "residencyStandard3DBlockShape", &dst->residencyStandard3DBlockShape)) {
		return false;
	}
	if (!vulkan_bool32(obj, "residencyAlignedMipSize", &dst->residencyAlignedMipSize)) {
		return false;
	}
	if (!vulkan_bool32(obj, "residencyNonResidentStrict", &dst->residencyNonResidentStrict)) {
		return false;
	}
	return true;
}

void vk_VkPhysicalDeviceSparseProperties_to(const void *raw, zval *rv)
{
	const VkPhysicalDeviceSparseProperties *src = raw;
	object_init_ex(rv, vulkan_ce_VkPhysicalDeviceSparseProperties);
	{
		zend_object *obj = Z_OBJ_P(rv);
	vulkan_set_bool(obj, "residencyStandard2DBlockShape", src->residencyStandard2DBlockShape == VK_TRUE);
	vulkan_set_bool(obj, "residencyStandard2DMultisampleBlockShape", src->residencyStandard2DMultisampleBlockShape == VK_TRUE);
	vulkan_set_bool(obj, "residencyStandard3DBlockShape", src->residencyStandard3DBlockShape == VK_TRUE);
	vulkan_set_bool(obj, "residencyAlignedMipSize", src->residencyAlignedMipSize == VK_TRUE);
	vulkan_set_bool(obj, "residencyNonResidentStrict", src->residencyNonResidentStrict == VK_TRUE);
	}
}

bool vk_VkPhysicalDeviceProperties_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkPhysicalDeviceProperties *dst = raw;
	memset(dst, 0, sizeof(*dst));
	if (!vulkan_enter(obj, visited)) {
		return false;
	}
	if (!vulkan_u32(obj, "apiVersion", &dst->apiVersion)) {
		return false;
	}
	if (!vulkan_u32(obj, "driverVersion", &dst->driverVersion)) {
		return false;
	}
	if (!vulkan_u32(obj, "vendorID", &dst->vendorID)) {
		return false;
	}
	if (!vulkan_u32(obj, "deviceID", &dst->deviceID)) {
		return false;
	}
	if (!vulkan_u32(obj, "deviceType", &dst->deviceType)) {
		return false;
	}
	if (!vulkan_char_array_from(obj, "deviceName", dst->deviceName, 256)) {
		return false;
	}
	if (!vulkan_bytes_from(obj, "pipelineCacheUUID", dst->pipelineCacheUUID, 16)) {
		return false;
	}
	if (!vulkan_struct_value(obj, "limits", vulkan_ce_VkPhysicalDeviceLimits, vk_VkPhysicalDeviceLimits_from, &dst->limits, scratch, visited)) {
		return false;
	}
	if (!vulkan_struct_value(obj, "sparseProperties", vulkan_ce_VkPhysicalDeviceSparseProperties, vk_VkPhysicalDeviceSparseProperties_from, &dst->sparseProperties, scratch, visited)) {
		return false;
	}
	return true;
}

void vk_VkPhysicalDeviceProperties_to(const void *raw, zval *rv)
{
	const VkPhysicalDeviceProperties *src = raw;
	object_init_ex(rv, vulkan_ce_VkPhysicalDeviceProperties);
	{
		zend_object *obj = Z_OBJ_P(rv);
	vulkan_set_long(obj, "apiVersion", (zend_long) src->apiVersion);
	vulkan_set_long(obj, "driverVersion", (zend_long) src->driverVersion);
	vulkan_set_long(obj, "vendorID", (zend_long) src->vendorID);
	vulkan_set_long(obj, "deviceID", (zend_long) src->deviceID);
	vulkan_set_long(obj, "deviceType", (zend_long) src->deviceType);
	vulkan_set_string(obj, "deviceName", src->deviceName);
	vulkan_set_bytes(obj, "pipelineCacheUUID", src->pipelineCacheUUID, 16);
	vulkan_set_struct_value(obj, "limits", &src->limits, vk_VkPhysicalDeviceLimits_to);
	vulkan_set_struct_value(obj, "sparseProperties", &src->sparseProperties, vk_VkPhysicalDeviceSparseProperties_to);
	}
}

bool vk_VkExtent3D_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkExtent3D *dst = raw;
	memset(dst, 0, sizeof(*dst));
	if (!vulkan_enter(obj, visited)) {
		return false;
	}
	if (!vulkan_u32(obj, "width", &dst->width)) {
		return false;
	}
	if (!vulkan_u32(obj, "height", &dst->height)) {
		return false;
	}
	if (!vulkan_u32(obj, "depth", &dst->depth)) {
		return false;
	}
	return true;
}

void vk_VkExtent3D_to(const void *raw, zval *rv)
{
	const VkExtent3D *src = raw;
	object_init_ex(rv, vulkan_ce_VkExtent3D);
	{
		zend_object *obj = Z_OBJ_P(rv);
	vulkan_set_long(obj, "width", (zend_long) src->width);
	vulkan_set_long(obj, "height", (zend_long) src->height);
	vulkan_set_long(obj, "depth", (zend_long) src->depth);
	}
}

bool vk_VkQueueFamilyProperties_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkQueueFamilyProperties *dst = raw;
	memset(dst, 0, sizeof(*dst));
	if (!vulkan_enter(obj, visited)) {
		return false;
	}
	if (!vulkan_u32(obj, "queueFlags", &dst->queueFlags)) {
		return false;
	}
	if (!vulkan_u32(obj, "queueCount", &dst->queueCount)) {
		return false;
	}
	if (!vulkan_u32(obj, "timestampValidBits", &dst->timestampValidBits)) {
		return false;
	}
	if (!vulkan_struct_value(obj, "minImageTransferGranularity", vulkan_ce_VkExtent3D, vk_VkExtent3D_from, &dst->minImageTransferGranularity, scratch, visited)) {
		return false;
	}
	return true;
}

void vk_VkQueueFamilyProperties_to(const void *raw, zval *rv)
{
	const VkQueueFamilyProperties *src = raw;
	object_init_ex(rv, vulkan_ce_VkQueueFamilyProperties);
	{
		zend_object *obj = Z_OBJ_P(rv);
	vulkan_set_long(obj, "queueFlags", (zend_long) src->queueFlags);
	vulkan_set_long(obj, "queueCount", (zend_long) src->queueCount);
	vulkan_set_long(obj, "timestampValidBits", (zend_long) src->timestampValidBits);
	vulkan_set_struct_value(obj, "minImageTransferGranularity", &src->minImageTransferGranularity, vk_VkExtent3D_to);
	}
}

bool vk_VkMemoryType_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkMemoryType *dst = raw;
	memset(dst, 0, sizeof(*dst));
	if (!vulkan_enter(obj, visited)) {
		return false;
	}
	if (!vulkan_u32(obj, "propertyFlags", &dst->propertyFlags)) {
		return false;
	}
	if (!vulkan_u32(obj, "heapIndex", &dst->heapIndex)) {
		return false;
	}
	return true;
}

void vk_VkMemoryType_to(const void *raw, zval *rv)
{
	const VkMemoryType *src = raw;
	object_init_ex(rv, vulkan_ce_VkMemoryType);
	{
		zend_object *obj = Z_OBJ_P(rv);
	vulkan_set_long(obj, "propertyFlags", (zend_long) src->propertyFlags);
	vulkan_set_long(obj, "heapIndex", (zend_long) src->heapIndex);
	}
}

bool vk_VkMemoryHeap_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkMemoryHeap *dst = raw;
	memset(dst, 0, sizeof(*dst));
	if (!vulkan_enter(obj, visited)) {
		return false;
	}
	if (!vulkan_u64(obj, "size", &dst->size)) {
		return false;
	}
	if (!vulkan_u32(obj, "flags", &dst->flags)) {
		return false;
	}
	return true;
}

void vk_VkMemoryHeap_to(const void *raw, zval *rv)
{
	const VkMemoryHeap *src = raw;
	object_init_ex(rv, vulkan_ce_VkMemoryHeap);
	{
		zend_object *obj = Z_OBJ_P(rv);
	vulkan_set_long(obj, "size", (zend_long) src->size);
	vulkan_set_long(obj, "flags", (zend_long) src->flags);
	}
}

bool vk_VkPhysicalDeviceMemoryProperties_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkPhysicalDeviceMemoryProperties *dst = raw;
	memset(dst, 0, sizeof(*dst));
	if (!vulkan_enter(obj, visited)) {
		return false;
	}
	if (!vulkan_counted_struct(obj, "memoryTypes", vulkan_ce_VkMemoryType, vk_VkMemoryType_from, dst->memoryTypes, sizeof(VkMemoryType), 32, &dst->memoryTypeCount, scratch, visited)) {
		return false;
	}
	if (!vulkan_counted_struct(obj, "memoryHeaps", vulkan_ce_VkMemoryHeap, vk_VkMemoryHeap_from, dst->memoryHeaps, sizeof(VkMemoryHeap), 16, &dst->memoryHeapCount, scratch, visited)) {
		return false;
	}
	return true;
}

void vk_VkPhysicalDeviceMemoryProperties_to(const void *raw, zval *rv)
{
	const VkPhysicalDeviceMemoryProperties *src = raw;
	object_init_ex(rv, vulkan_ce_VkPhysicalDeviceMemoryProperties);
	{
		zend_object *obj = Z_OBJ_P(rv);
	vulkan_set_struct_array(obj, "memoryTypes", src->memoryTypes, src->memoryTypeCount, sizeof(VkMemoryType), vk_VkMemoryType_to);
	vulkan_set_struct_array(obj, "memoryHeaps", src->memoryHeaps, src->memoryHeapCount, sizeof(VkMemoryHeap), vk_VkMemoryHeap_to);
	}
}

bool vk_VkFormatProperties_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkFormatProperties *dst = raw;
	memset(dst, 0, sizeof(*dst));
	if (!vulkan_enter(obj, visited)) {
		return false;
	}
	if (!vulkan_u32(obj, "linearTilingFeatures", &dst->linearTilingFeatures)) {
		return false;
	}
	if (!vulkan_u32(obj, "optimalTilingFeatures", &dst->optimalTilingFeatures)) {
		return false;
	}
	if (!vulkan_u32(obj, "bufferFeatures", &dst->bufferFeatures)) {
		return false;
	}
	return true;
}

void vk_VkFormatProperties_to(const void *raw, zval *rv)
{
	const VkFormatProperties *src = raw;
	object_init_ex(rv, vulkan_ce_VkFormatProperties);
	{
		zend_object *obj = Z_OBJ_P(rv);
	vulkan_set_long(obj, "linearTilingFeatures", (zend_long) src->linearTilingFeatures);
	vulkan_set_long(obj, "optimalTilingFeatures", (zend_long) src->optimalTilingFeatures);
	vulkan_set_long(obj, "bufferFeatures", (zend_long) src->bufferFeatures);
	}
}

bool vk_VkExtensionProperties_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkExtensionProperties *dst = raw;
	memset(dst, 0, sizeof(*dst));
	if (!vulkan_enter(obj, visited)) {
		return false;
	}
	if (!vulkan_char_array_from(obj, "extensionName", dst->extensionName, 256)) {
		return false;
	}
	if (!vulkan_u32(obj, "specVersion", &dst->specVersion)) {
		return false;
	}
	return true;
}

void vk_VkExtensionProperties_to(const void *raw, zval *rv)
{
	const VkExtensionProperties *src = raw;
	object_init_ex(rv, vulkan_ce_VkExtensionProperties);
	{
		zend_object *obj = Z_OBJ_P(rv);
		vulkan_set_string(obj, "extensionName", src->extensionName);
		vulkan_set_long(obj, "specVersion", (zend_long) src->specVersion);
	}
}

#include "vk_memory_structs.inc"

#include "vk_pipeline_structs.inc"

#include "vk_command_structs.inc"

#include "vk_surface_structs.inc"

#include "vk_external_structs.inc"
