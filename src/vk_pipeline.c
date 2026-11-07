#include "runtime.h"
#include "structs.h"
#include "../stubs/vk_pipeline_arginfo.h"

VULKAN_HANDLE_METHODS(VkRenderPass)
VULKAN_HANDLE_METHODS(VkFramebuffer)
VULKAN_HANDLE_METHODS(VkShaderModule)
VULKAN_HANDLE_METHODS(VkPipelineLayout)
VULKAN_HANDLE_METHODS(VkPipeline)
VULKAN_HANDLE_METHODS(VkDescriptorSetLayout)
VULKAN_HANDLE_METHODS(VkDescriptorPool)
VULKAN_HANDLE_METHODS(VkDescriptorSet)

ZEND_METHOD(VkPipelineDepthStencilStateCreateInfo, __construct)
{
	ZEND_PARSE_PARAMETERS_NONE();
	vulkan_init_nested(Z_OBJ_P(ZEND_THIS), "front", vulkan_ce_VkStencilOpState);
	vulkan_init_nested(Z_OBJ_P(ZEND_THIS), "back", vulkan_ce_VkStencilOpState);
}

ZEND_METHOD(VkPipelineColorBlendStateCreateInfo, __construct)
{
	zval constants, zero;

	ZEND_PARSE_PARAMETERS_NONE();
	array_init_size(&constants, 4);
	ZVAL_DOUBLE(&zero, 0.0);
	for (int i = 0; i < 4; i++) {
		zend_hash_next_index_insert(Z_ARRVAL(constants), &zero);
	}
	zend_update_property(Z_OBJCE_P(ZEND_THIS), Z_OBJ_P(ZEND_THIS), "blendConstants", sizeof("blendConstants") - 1, &constants);
	zval_ptr_dtor(&constants);
}

ZEND_METHOD(VkRect2D, __construct)
{
	ZEND_PARSE_PARAMETERS_NONE();
	vulkan_init_nested(Z_OBJ_P(ZEND_THIS), "offset", vulkan_ce_VkOffset2D);
	vulkan_init_nested(Z_OBJ_P(ZEND_THIS), "extent", vulkan_ce_VkExtent2D);
}

#define ALLOCATOR(z) ((const VkAllocationCallbacks *) (uintptr_t) (z))

static bool vulkan_device(zval *zv, uint64_t *out)
{
	return vulkan_handle_value(zv, vulkan_ce_VkDevice, 1, out);
}

static void vulkan_box_out(zval *out, VkResult result, uint64_t value, zend_class_entry *ce, zend_object *parent)
{
	zval boxed;

	if (result == VK_SUCCESS) {
		vulkan_box(&boxed, value, ce, parent);
	} else {
		ZVAL_NULL(&boxed);
	}
	vulkan_assign(out, &boxed);
}

static void vulkan_destroy(zval *device, zval *handle, zend_long allocator, zend_class_entry *ce, void (*destroy)(VkDevice, uint64_t, const VkAllocationCallbacks *))
{
	uint64_t device_value, handle_value = 0;

	if (!vulkan_device(device, &device_value) || (handle && !vulkan_handle_value(handle, ce, 2, &handle_value))) {
		return;
	}
	destroy((VkDevice) (uintptr_t) device_value, handle_value, ALLOCATOR(allocator));
	if (handle) vulkan_release_tree(Z_OBJ_P(handle));
}

static void destroy_render_pass(VkDevice device, uint64_t handle, const VkAllocationCallbacks *allocator) { vkDestroyRenderPass(device, (VkRenderPass) (uintptr_t) handle, allocator); }
static void destroy_framebuffer(VkDevice device, uint64_t handle, const VkAllocationCallbacks *allocator) { vkDestroyFramebuffer(device, (VkFramebuffer) (uintptr_t) handle, allocator); }
static void destroy_shader(VkDevice device, uint64_t handle, const VkAllocationCallbacks *allocator) { vkDestroyShaderModule(device, (VkShaderModule) (uintptr_t) handle, allocator); }
static void destroy_layout(VkDevice device, uint64_t handle, const VkAllocationCallbacks *allocator) { vkDestroyPipelineLayout(device, (VkPipelineLayout) (uintptr_t) handle, allocator); }
static void destroy_pipeline(VkDevice device, uint64_t handle, const VkAllocationCallbacks *allocator) { vkDestroyPipeline(device, (VkPipeline) (uintptr_t) handle, allocator); }
static void destroy_set_layout(VkDevice device, uint64_t handle, const VkAllocationCallbacks *allocator) { vkDestroyDescriptorSetLayout(device, (VkDescriptorSetLayout) (uintptr_t) handle, allocator); }
static void destroy_pool(VkDevice device, uint64_t handle, const VkAllocationCallbacks *allocator) { vkDestroyDescriptorPool(device, (VkDescriptorPool) (uintptr_t) handle, allocator); }

void vulkan_register_pipeline(int module_number)
{
	(void) module_number;
	zend_register_functions(NULL, ext_functions, NULL, MODULE_PERSISTENT);

#define SETUP_HANDLE(cls) do { vulkan_ce_##cls = register_class_##cls(); vulkan_handle_setup(vulkan_ce_##cls); } while (0)
#define SETUP_STRUCT(cls) do { vulkan_ce_##cls = register_class_##cls(); vulkan_struct_setup(vulkan_ce_##cls); } while (0)
	SETUP_HANDLE(VkRenderPass);
	SETUP_HANDLE(VkFramebuffer);
	SETUP_HANDLE(VkShaderModule);
	SETUP_HANDLE(VkPipelineLayout);
	SETUP_HANDLE(VkPipeline);
	SETUP_HANDLE(VkDescriptorSetLayout);
	SETUP_HANDLE(VkDescriptorPool);
	SETUP_HANDLE(VkDescriptorSet);
	SETUP_STRUCT(VkAttachmentDescription);
	SETUP_STRUCT(VkAttachmentReference);
	SETUP_STRUCT(VkSubpassDescription);
	SETUP_STRUCT(VkSubpassDependency);
	SETUP_STRUCT(VkRenderPassCreateInfo);
	SETUP_STRUCT(VkFramebufferCreateInfo);
	SETUP_STRUCT(VkShaderModuleCreateInfo);
	SETUP_STRUCT(VkPushConstantRange);
	SETUP_STRUCT(VkPipelineLayoutCreateInfo);
	SETUP_STRUCT(VkPipelineShaderStageCreateInfo);
	SETUP_STRUCT(VkVertexInputBindingDescription);
	SETUP_STRUCT(VkVertexInputAttributeDescription);
	SETUP_STRUCT(VkPipelineVertexInputStateCreateInfo);
	SETUP_STRUCT(VkPipelineInputAssemblyStateCreateInfo);
	SETUP_STRUCT(VkViewport);
	SETUP_STRUCT(VkOffset2D);
	SETUP_STRUCT(VkExtent2D);
	SETUP_STRUCT(VkRect2D);
	SETUP_STRUCT(VkPipelineViewportStateCreateInfo);
	SETUP_STRUCT(VkPipelineRasterizationStateCreateInfo);
	SETUP_STRUCT(VkPipelineMultisampleStateCreateInfo);
	SETUP_STRUCT(VkStencilOpState);
	SETUP_STRUCT(VkPipelineDepthStencilStateCreateInfo);
	SETUP_STRUCT(VkPipelineColorBlendAttachmentState);
	SETUP_STRUCT(VkPipelineColorBlendStateCreateInfo);
	SETUP_STRUCT(VkPipelineDynamicStateCreateInfo);
	SETUP_STRUCT(VkPipelineTessellationStateCreateInfo);
	SETUP_STRUCT(VkGraphicsPipelineCreateInfo);
	SETUP_STRUCT(VkDescriptorSetLayoutBinding);
	SETUP_STRUCT(VkDescriptorSetLayoutCreateInfo);
	SETUP_STRUCT(VkDescriptorPoolSize);
	SETUP_STRUCT(VkDescriptorPoolCreateInfo);
	SETUP_STRUCT(VkDescriptorSetAllocateInfo);
	SETUP_STRUCT(VkDescriptorImageInfo);
	SETUP_STRUCT(VkWriteDescriptorSet);
	SETUP_STRUCT(VkCopyDescriptorSet);
#undef SETUP_HANDLE
#undef SETUP_STRUCT
}

static bool vulkan_create(zval *device, zval *info, zend_long allocator, zval *out, zend_class_entry *info_ce, vulkan_from_fn from, size_t info_size, VkResult (*create)(VkDevice, const void *, const VkAllocationCallbacks *, uint64_t *), zend_class_entry *out_ce, VkResult *result_out)
{
	uint64_t device_value, created = 0;
	vulkan_scratch scratch;
	void *native;
	VkResult result;

	if (!vulkan_device(device, &device_value)) {
		return false;
	}
	native = ecalloc(1, info_size);
	vulkan_scratch_init(&scratch);
	if (!vulkan_arg_struct(info, info_ce, from, native, &scratch)) {
		vulkan_scratch_free(&scratch);
		efree(native);
		return false;
	}
	result = create((VkDevice) (uintptr_t) device_value, native, ALLOCATOR(allocator), &created);
	vulkan_scratch_free(&scratch);
	efree(native);
	vulkan_box_out(out, result, created, out_ce, Z_OBJ_P(device));
	*result_out = result;
	return true;
}

static VkResult create_render_pass(VkDevice device, const void *info, const VkAllocationCallbacks *allocator, uint64_t *out)
{
	VkRenderPass handle = VK_NULL_HANDLE;
	VkResult result = vkCreateRenderPass(device, info, allocator, &handle);
	*out = (uint64_t) (uintptr_t) handle;
	return result;
}
static VkResult create_framebuffer(VkDevice device, const void *info, const VkAllocationCallbacks *allocator, uint64_t *out)
{
	VkFramebuffer handle = VK_NULL_HANDLE;
	VkResult result = vkCreateFramebuffer(device, info, allocator, &handle);
	*out = (uint64_t) (uintptr_t) handle;
	return result;
}
static VkResult create_shader(VkDevice device, const void *info, const VkAllocationCallbacks *allocator, uint64_t *out)
{
	VkShaderModule handle = VK_NULL_HANDLE;
	VkResult result = vkCreateShaderModule(device, info, allocator, &handle);
	*out = (uint64_t) (uintptr_t) handle;
	return result;
}
static VkResult create_pipeline_layout(VkDevice device, const void *info, const VkAllocationCallbacks *allocator, uint64_t *out)
{
	VkPipelineLayout handle = VK_NULL_HANDLE;
	VkResult result = vkCreatePipelineLayout(device, info, allocator, &handle);
	*out = (uint64_t) (uintptr_t) handle;
	return result;
}
static VkResult create_set_layout(VkDevice device, const void *info, const VkAllocationCallbacks *allocator, uint64_t *out)
{
	VkDescriptorSetLayout handle = VK_NULL_HANDLE;
	VkResult result = vkCreateDescriptorSetLayout(device, info, allocator, &handle);
	*out = (uint64_t) (uintptr_t) handle;
	return result;
}
static VkResult create_pool(VkDevice device, const void *info, const VkAllocationCallbacks *allocator, uint64_t *out)
{
	VkDescriptorPool handle = VK_NULL_HANDLE;
	VkResult result = vkCreateDescriptorPool(device, info, allocator, &handle);
	*out = (uint64_t) (uintptr_t) handle;
	return result;
}

#define BIND_CREATE(php, info_ce, info_type, from_fn, create_fn, out_ce) \
	ZEND_FUNCTION(php) \
	{ \
		zval *device, *info, *out; zend_long allocator; \
		VkResult result = VK_ERROR_UNKNOWN; \
		ZEND_PARSE_PARAMETERS_START(4, 4) \
			Z_PARAM_OBJECT(device) \
			Z_PARAM_OBJECT(info) \
			Z_PARAM_LONG(allocator) \
			Z_PARAM_ZVAL(out) \
		ZEND_PARSE_PARAMETERS_END(); \
		if (!vulkan_create(device, info, allocator, out, info_ce, from_fn, sizeof(info_type), create_fn, out_ce, &result)) { \
			RETURN_THROWS(); \
		} \
		RETURN_LONG((zend_long) result); \
	}

BIND_CREATE(vkCreateRenderPass, vulkan_ce_VkRenderPassCreateInfo, VkRenderPassCreateInfo, vk_VkRenderPassCreateInfo_from, create_render_pass, vulkan_ce_VkRenderPass)
BIND_CREATE(vkCreateFramebuffer, vulkan_ce_VkFramebufferCreateInfo, VkFramebufferCreateInfo, vk_VkFramebufferCreateInfo_from, create_framebuffer, vulkan_ce_VkFramebuffer)
BIND_CREATE(vkCreateShaderModule, vulkan_ce_VkShaderModuleCreateInfo, VkShaderModuleCreateInfo, vk_VkShaderModuleCreateInfo_from, create_shader, vulkan_ce_VkShaderModule)
BIND_CREATE(vkCreatePipelineLayout, vulkan_ce_VkPipelineLayoutCreateInfo, VkPipelineLayoutCreateInfo, vk_VkPipelineLayoutCreateInfo_from, create_pipeline_layout, vulkan_ce_VkPipelineLayout)
BIND_CREATE(vkCreateDescriptorSetLayout, vulkan_ce_VkDescriptorSetLayoutCreateInfo, VkDescriptorSetLayoutCreateInfo, vk_VkDescriptorSetLayoutCreateInfo_from, create_set_layout, vulkan_ce_VkDescriptorSetLayout)
BIND_CREATE(vkCreateDescriptorPool, vulkan_ce_VkDescriptorPoolCreateInfo, VkDescriptorPoolCreateInfo, vk_VkDescriptorPoolCreateInfo_from, create_pool, vulkan_ce_VkDescriptorPool)

#define BIND_DESTROY(php, ce, destroy_fn) \
	ZEND_FUNCTION(php) \
	{ \
		zval *device, *handle; zend_long allocator; \
		ZEND_PARSE_PARAMETERS_START(3, 3) \
			Z_PARAM_OBJECT(device) \
			Z_PARAM_OBJECT_OR_NULL(handle) \
			Z_PARAM_LONG(allocator) \
		ZEND_PARSE_PARAMETERS_END(); \
		if (EG(exception)) { \
			RETURN_THROWS(); \
		} \
		vulkan_destroy(device, handle, allocator, ce, destroy_fn); \
		if (EG(exception)) { \
			RETURN_THROWS(); \
		} \
	}

BIND_DESTROY(vkDestroyRenderPass, vulkan_ce_VkRenderPass, destroy_render_pass)
BIND_DESTROY(vkDestroyFramebuffer, vulkan_ce_VkFramebuffer, destroy_framebuffer)
BIND_DESTROY(vkDestroyShaderModule, vulkan_ce_VkShaderModule, destroy_shader)
BIND_DESTROY(vkDestroyPipelineLayout, vulkan_ce_VkPipelineLayout, destroy_layout)
BIND_DESTROY(vkDestroyPipeline, vulkan_ce_VkPipeline, destroy_pipeline)
BIND_DESTROY(vkDestroyDescriptorSetLayout, vulkan_ce_VkDescriptorSetLayout, destroy_set_layout)
BIND_DESTROY(vkDestroyDescriptorPool, vulkan_ce_VkDescriptorPool, destroy_pool)

ZEND_FUNCTION(vkCreateGraphicsPipelines)
{
	zval *device, *infos, *out;
	zend_long cache, count, allocator;
	uint64_t device_value;
	uint32_t i;
	void *native;
	VkPipeline *pipelines = NULL;
	vulkan_scratch scratch;
	VkResult result;
	zval arr, boxed;

	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_OBJECT(device)
		Z_PARAM_LONG(cache)
		Z_PARAM_LONG(count)
		Z_PARAM_ZVAL(infos)
		Z_PARAM_LONG(allocator)
		Z_PARAM_ZVAL(out)
	ZEND_PARSE_PARAMETERS_END();

	if (!vulkan_device(device, &device_value)) {
		RETURN_THROWS();
	}
	vulkan_scratch_init(&scratch);
	if (!vulkan_arg_structs(infos, count, 3, 4, vulkan_ce_VkGraphicsPipelineCreateInfo, sizeof(VkGraphicsPipelineCreateInfo), vk_VkGraphicsPipelineCreateInfo_from, &native, &scratch)) {
		vulkan_scratch_free(&scratch);
		RETURN_THROWS();
	}
	/* Vulkan writes createInfoCount handles. */
	pipelines = (uint32_t) count ? safe_emalloc((uint32_t) count, sizeof(*pipelines), 0) : NULL;
	result = vkCreateGraphicsPipelines((VkDevice) (uintptr_t) device_value, (VkPipelineCache) (uintptr_t) cache, (uint32_t) count, native, ALLOCATOR(allocator), pipelines);
	vulkan_scratch_free(&scratch);
	array_init_size(&arr, (uint32_t) count);
	for (i = 0; i < (uint32_t) count; i++) {
		vulkan_box(&boxed, (uint64_t) (uintptr_t) pipelines[i], vulkan_ce_VkPipeline, Z_OBJ_P(device));
		zend_hash_next_index_insert(Z_ARRVAL(arr), &boxed);
	}
	if (pipelines != NULL) {
		efree(pipelines);
	}
	vulkan_assign(out, &arr);
	RETURN_LONG((zend_long) result);
}

ZEND_FUNCTION(vkAllocateDescriptorSets)
{
	zval *device, *info, *out;
	uint64_t device_value;
	VkDescriptorSetAllocateInfo allocate;
	vulkan_scratch scratch;
	VkDescriptorSet *sets = NULL;
	VkResult result;
	zval *pool;
	zval arr, boxed;
	uint32_t i;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT(device)
		Z_PARAM_OBJECT(info)
		Z_PARAM_ZVAL(out)
	ZEND_PARSE_PARAMETERS_END();

	if (!vulkan_device(device, &device_value)) {
		RETURN_THROWS();
	}
	vulkan_scratch_init(&scratch);
	if (!vulkan_arg_struct(info, vulkan_ce_VkDescriptorSetAllocateInfo, vk_VkDescriptorSetAllocateInfo_from, &allocate, &scratch)) {
		vulkan_scratch_free(&scratch);
		RETURN_THROWS();
	}
	sets = allocate.descriptorSetCount ? emalloc(sizeof(*sets) * allocate.descriptorSetCount) : NULL;
	result = vkAllocateDescriptorSets((VkDevice) (uintptr_t) device_value, &allocate, sets);
	pool = zend_read_property(Z_OBJCE_P(info), Z_OBJ_P(info), "descriptorPool", sizeof("descriptorPool") - 1, 0, NULL);
	array_init_size(&arr, allocate.descriptorSetCount);
	for (i = 0; i < allocate.descriptorSetCount; i++) {
		zend_object *parent = (pool != NULL && Z_TYPE_P(pool) == IS_OBJECT) ? Z_OBJ_P(pool) : Z_OBJ_P(device);
		vulkan_box(&boxed, result == VK_SUCCESS ? (uint64_t) (uintptr_t) sets[i] : 0, vulkan_ce_VkDescriptorSet, parent);
		zend_hash_next_index_insert(Z_ARRVAL(arr), &boxed);
	}
	vulkan_scratch_free(&scratch);
	if (sets != NULL) {
		efree(sets);
	}
	vulkan_assign(out, &arr);
	RETURN_LONG((zend_long) result);
}

ZEND_FUNCTION(vkUpdateDescriptorSets)
{
	zval *device, *writes, *copies;
	zend_long write_count, copy_count;
	uint64_t device_value;
	void *native_writes, *native_copies;
	vulkan_scratch scratch;

	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_OBJECT(device)
		Z_PARAM_LONG(write_count)
		Z_PARAM_ZVAL(writes)
		Z_PARAM_LONG(copy_count)
		Z_PARAM_ZVAL(copies)
	ZEND_PARSE_PARAMETERS_END();

	if (!vulkan_device(device, &device_value)) {
		RETURN_THROWS();
	}
	vulkan_scratch_init(&scratch);
	if (!vulkan_arg_structs(writes, write_count, 2, 3, vulkan_ce_VkWriteDescriptorSet, sizeof(VkWriteDescriptorSet), vk_VkWriteDescriptorSet_from, &native_writes, &scratch)
		|| !vulkan_arg_structs(copies, copy_count, 4, 5, vulkan_ce_VkCopyDescriptorSet, sizeof(VkCopyDescriptorSet), vk_VkCopyDescriptorSet_from, &native_copies, &scratch)) {
		vulkan_scratch_free(&scratch);
		RETURN_THROWS();
	}
	vkUpdateDescriptorSets((VkDevice) (uintptr_t) device_value, (uint32_t) write_count, native_writes, (uint32_t) copy_count, native_copies);
	vulkan_scratch_free(&scratch);
}
