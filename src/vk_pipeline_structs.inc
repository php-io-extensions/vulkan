
static bool vulkan_optional_floats(zend_object *obj, const char *name, float *dst, uint32_t count)
{
	zval *zv = zend_read_property(obj->ce, obj, name, strlen(name), 0, NULL);

	if (zv == NULL || EG(exception) != NULL) {
		return false;
	}
	if (Z_TYPE_P(zv) == IS_ARRAY && zend_hash_num_elements(Z_ARRVAL_P(zv)) == 0) {
		return true;
	}
	return vulkan_fixed_floats(obj, name, dst, count);
}

static bool vulkan_opt_struct_list(zend_object *obj, const char *name, zend_class_entry *ce, size_t size, vulkan_from_fn from, void **out, uint32_t *count, vulkan_scratch *scratch, HashTable *visited)
{
	zval *zv = zend_read_property(obj->ce, obj, name, strlen(name), 0, NULL);
	uint32_t listed = 0;

	if (zv == NULL || EG(exception) != NULL) {
		return false;
	}
	if (Z_TYPE_P(zv) != IS_ARRAY) {
		zend_type_error("%s::$%s must be a list", ZSTR_VAL(obj->ce->name), name);
		return false;
	}
	if (zend_hash_num_elements(Z_ARRVAL_P(zv)) == 0) {
		*out = NULL;
		return true;
	}
	return vulkan_struct_list(obj, name, ce, size, from, out, &listed, scratch, visited) && (*count = listed, true);
}

static bool vulkan_resolve_list(zend_object *obj, const char *name, zend_class_entry *ce, vulkan_from_fn from, void **out, uint32_t color_count, vulkan_scratch *scratch, HashTable *visited)
{
	zval *zv = zend_read_property(obj->ce, obj, name, strlen(name), 0, NULL);
	uint32_t listed = 0;

	if (zv == NULL || EG(exception) != NULL) {
		return false;
	}
	if (Z_TYPE_P(zv) != IS_ARRAY) {
		zend_type_error("%s::$%s must be a list", ZSTR_VAL(obj->ce->name), name);
		return false;
	}
	if (zend_hash_num_elements(Z_ARRVAL_P(zv)) == 0) {
		*out = NULL;
		return true;
	}
	if (!vulkan_struct_list(obj, name, ce, sizeof(VkAttachmentReference), from, out, &listed, scratch, visited)) {
		return false;
	}
	if (listed != color_count) {
		zend_value_error("%s::$%s must match the colour attachments", ZSTR_VAL(obj->ce->name), name);
		return false;
	}
	(void) ce;
	return true;
}

static bool vulkan_spirv(zend_object *obj, VkShaderModuleCreateInfo *dst, vulkan_scratch *scratch)
{
	zval *zv = zend_read_property(obj->ce, obj, "code", sizeof("code") - 1, 0, NULL);
	void *copy;

	if (zv == NULL || EG(exception) != NULL) {
		return false;
	}
	if (Z_TYPE_P(zv) != IS_STRING) {
		zend_type_error("VkShaderModuleCreateInfo::$code must be a string");
		return false;
	}
	if ((Z_STRLEN_P(zv) % 4) != 0) {
		zend_value_error("SPIR-V code must be a multiple of 4 bytes");
		return false;
	}
	copy = vulkan_scratch_alloc(scratch, Z_STRLEN_P(zv) == 0 ? 1 : Z_STRLEN_P(zv));
	if (Z_STRLEN_P(zv) > 0) {
		memcpy(copy, Z_STRVAL_P(zv), Z_STRLEN_P(zv));
	}
	dst->codeSize = Z_STRLEN_P(zv);
	dst->pCode = (const uint32_t *) copy;
	return true;
}

bool vk_VkAttachmentDescription_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkAttachmentDescription *dst = raw;
	memset(dst, 0, sizeof(*dst));
	if (!vulkan_enter(obj, visited)) return false;
	if (!vulkan_u32(obj, "flags", &dst->flags)) return false;
	if (!vulkan_u32(obj, "format", &dst->format)) return false;
	if (!vulkan_u32(obj, "samples", &dst->samples)) return false;
	if (!vulkan_u32(obj, "loadOp", &dst->loadOp)) return false;
	if (!vulkan_u32(obj, "storeOp", &dst->storeOp)) return false;
	if (!vulkan_u32(obj, "stencilLoadOp", &dst->stencilLoadOp)) return false;
	if (!vulkan_u32(obj, "stencilStoreOp", &dst->stencilStoreOp)) return false;
	if (!vulkan_u32(obj, "initialLayout", &dst->initialLayout)) return false;
	if (!vulkan_u32(obj, "finalLayout", &dst->finalLayout)) return false;
	return true;
}

void vk_VkAttachmentDescription_to(const void *raw, zval *rv)
{
	(void) raw;
	object_init_ex(rv, vulkan_ce_VkAttachmentDescription);
}

bool vk_VkAttachmentReference_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkAttachmentReference *dst = raw;
	memset(dst, 0, sizeof(*dst));
	if (!vulkan_enter(obj, visited)) return false;
	if (!vulkan_u32(obj, "attachment", &dst->attachment)) return false;
	if (!vulkan_u32(obj, "layout", &dst->layout)) return false;
	return true;
}

void vk_VkAttachmentReference_to(const void *raw, zval *rv)
{
	(void) raw;
	object_init_ex(rv, vulkan_ce_VkAttachmentReference);
}

bool vk_VkSubpassDescription_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkSubpassDescription *dst = raw;
	const uint32_t *u32s = NULL;
	memset(dst, 0, sizeof(*dst));
	if (!vulkan_enter(obj, visited)) return false;
	if (!vulkan_u32(obj, "flags", &dst->flags)) return false;
	if (!vulkan_u32(obj, "pipelineBindPoint", &dst->pipelineBindPoint)) return false;
	if (!vulkan_struct_list(obj, "pInputAttachments", vulkan_ce_VkAttachmentReference, sizeof(VkAttachmentReference), vk_VkAttachmentReference_from, (void **) &dst->pInputAttachments, &dst->inputAttachmentCount, scratch, visited)) return false;
	if (!vulkan_struct_list(obj, "pColorAttachments", vulkan_ce_VkAttachmentReference, sizeof(VkAttachmentReference), vk_VkAttachmentReference_from, (void **) &dst->pColorAttachments, &dst->colorAttachmentCount, scratch, visited)) return false;
	if (!vulkan_resolve_list(obj, "pResolveAttachments", vulkan_ce_VkAttachmentReference, vk_VkAttachmentReference_from, (void **) &dst->pResolveAttachments, dst->colorAttachmentCount, scratch, visited)) return false;
	if (!vulkan_struct_ptr(obj, "pDepthStencilAttachment", vulkan_ce_VkAttachmentReference, sizeof(VkAttachmentReference), vk_VkAttachmentReference_from, (void **) &dst->pDepthStencilAttachment, scratch, visited)) return false;
	if (!vulkan_u32_list(obj, "pPreserveAttachments", &u32s, &dst->preserveAttachmentCount, scratch)) return false;
	dst->pPreserveAttachments = (const uint32_t *) u32s;
	return true;
}

void vk_VkSubpassDescription_to(const void *raw, zval *rv)
{
	(void) raw;
	object_init_ex(rv, vulkan_ce_VkSubpassDescription);
}

bool vk_VkSubpassDependency_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkSubpassDependency *dst = raw;
	memset(dst, 0, sizeof(*dst));
	if (!vulkan_enter(obj, visited)) return false;
	if (!vulkan_u32(obj, "srcSubpass", &dst->srcSubpass)) return false;
	if (!vulkan_u32(obj, "dstSubpass", &dst->dstSubpass)) return false;
	if (!vulkan_u32(obj, "srcStageMask", &dst->srcStageMask)) return false;
	if (!vulkan_u32(obj, "dstStageMask", &dst->dstStageMask)) return false;
	if (!vulkan_u32(obj, "srcAccessMask", &dst->srcAccessMask)) return false;
	if (!vulkan_u32(obj, "dstAccessMask", &dst->dstAccessMask)) return false;
	if (!vulkan_u32(obj, "dependencyFlags", &dst->dependencyFlags)) return false;
	return true;
}

void vk_VkSubpassDependency_to(const void *raw, zval *rv)
{
	(void) raw;
	object_init_ex(rv, vulkan_ce_VkSubpassDependency);
}

bool vk_VkRenderPassCreateInfo_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkRenderPassCreateInfo *dst = raw;
	memset(dst, 0, sizeof(*dst));
	dst->sType = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
	if (!vulkan_enter(obj, visited)) return false;
	if (!vulkan_pnext(obj, &dst->pNext, scratch, visited)) return false;
	if (!vulkan_u32(obj, "flags", &dst->flags)) return false;
	if (!vulkan_struct_list(obj, "pAttachments", vulkan_ce_VkAttachmentDescription, sizeof(VkAttachmentDescription), vk_VkAttachmentDescription_from, (void **) &dst->pAttachments, &dst->attachmentCount, scratch, visited)) return false;
	if (!vulkan_struct_list(obj, "pSubpasses", vulkan_ce_VkSubpassDescription, sizeof(VkSubpassDescription), vk_VkSubpassDescription_from, (void **) &dst->pSubpasses, &dst->subpassCount, scratch, visited)) return false;
	if (!vulkan_struct_list(obj, "pDependencies", vulkan_ce_VkSubpassDependency, sizeof(VkSubpassDependency), vk_VkSubpassDependency_from, (void **) &dst->pDependencies, &dst->dependencyCount, scratch, visited)) return false;
	return true;
}

void vk_VkRenderPassCreateInfo_to(const void *raw, zval *rv)
{
	(void) raw;
	object_init_ex(rv, vulkan_ce_VkRenderPassCreateInfo);
}

bool vk_VkFramebufferCreateInfo_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkFramebufferCreateInfo *dst = raw;
	uint64_t handle_tmp;
	uint64_t *handles = NULL;
	memset(dst, 0, sizeof(*dst));
	dst->sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
	if (!vulkan_enter(obj, visited)) return false;
	if (!vulkan_pnext(obj, &dst->pNext, scratch, visited)) return false;
	if (!vulkan_u32(obj, "flags", &dst->flags)) return false;
	if (!vulkan_handle_prop(obj, "renderPass", vulkan_ce_VkRenderPass, &handle_tmp)) return false;
	dst->renderPass = (VkRenderPass) (uintptr_t) handle_tmp;
	if (!vulkan_handle_list(obj, "pAttachments", vulkan_ce_VkImageView, &handles, &dst->attachmentCount, scratch)) return false;
	dst->pAttachments = handles == NULL ? NULL : (VkImageView const *) handles;
	if (!vulkan_u32(obj, "width", &dst->width)) return false;
	if (!vulkan_u32(obj, "height", &dst->height)) return false;
	if (!vulkan_u32(obj, "layers", &dst->layers)) return false;
	return true;
}

void vk_VkFramebufferCreateInfo_to(const void *raw, zval *rv)
{
	(void) raw;
	object_init_ex(rv, vulkan_ce_VkFramebufferCreateInfo);
}

bool vk_VkShaderModuleCreateInfo_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkShaderModuleCreateInfo *dst = raw;
	memset(dst, 0, sizeof(*dst));
	dst->sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
	if (!vulkan_enter(obj, visited)) return false;
	if (!vulkan_pnext(obj, &dst->pNext, scratch, visited)) return false;
	if (!vulkan_u32(obj, "flags", &dst->flags)) return false;
	if (!vulkan_spirv(obj, dst, scratch)) return false;
	return true;
}

void vk_VkShaderModuleCreateInfo_to(const void *raw, zval *rv)
{
	(void) raw;
	object_init_ex(rv, vulkan_ce_VkShaderModuleCreateInfo);
}

bool vk_VkPushConstantRange_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkPushConstantRange *dst = raw;
	memset(dst, 0, sizeof(*dst));
	if (!vulkan_enter(obj, visited)) return false;
	if (!vulkan_u32(obj, "stageFlags", &dst->stageFlags)) return false;
	if (!vulkan_u32(obj, "offset", &dst->offset)) return false;
	if (!vulkan_u32(obj, "size", &dst->size)) return false;
	return true;
}

void vk_VkPushConstantRange_to(const void *raw, zval *rv)
{
	(void) raw;
	object_init_ex(rv, vulkan_ce_VkPushConstantRange);
}

bool vk_VkPipelineLayoutCreateInfo_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkPipelineLayoutCreateInfo *dst = raw;
	uint64_t *handles = NULL;
	memset(dst, 0, sizeof(*dst));
	dst->sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
	if (!vulkan_enter(obj, visited)) return false;
	if (!vulkan_pnext(obj, &dst->pNext, scratch, visited)) return false;
	if (!vulkan_u32(obj, "flags", &dst->flags)) return false;
	if (!vulkan_handle_list(obj, "pSetLayouts", vulkan_ce_VkDescriptorSetLayout, &handles, &dst->setLayoutCount, scratch)) return false;
	dst->pSetLayouts = handles == NULL ? NULL : (VkDescriptorSetLayout const *) handles;
	if (!vulkan_struct_list(obj, "pPushConstantRanges", vulkan_ce_VkPushConstantRange, sizeof(VkPushConstantRange), vk_VkPushConstantRange_from, (void **) &dst->pPushConstantRanges, &dst->pushConstantRangeCount, scratch, visited)) return false;
	return true;
}

void vk_VkPipelineLayoutCreateInfo_to(const void *raw, zval *rv)
{
	(void) raw;
	object_init_ex(rv, vulkan_ce_VkPipelineLayoutCreateInfo);
}

bool vk_VkPipelineShaderStageCreateInfo_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkPipelineShaderStageCreateInfo *dst = raw;
	uint64_t handle_tmp;
	memset(dst, 0, sizeof(*dst));
	dst->sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
	if (!vulkan_enter(obj, visited)) return false;
	if (!vulkan_pnext(obj, &dst->pNext, scratch, visited)) return false;
	if (!vulkan_u32(obj, "flags", &dst->flags)) return false;
	if (!vulkan_u32(obj, "stage", &dst->stage)) return false;
	if (!vulkan_handle_prop(obj, "module", vulkan_ce_VkShaderModule, &handle_tmp)) return false;
	dst->module = (VkShaderModule) (uintptr_t) handle_tmp;
	if (!vulkan_cstring(obj, "pName", &dst->pName)) return false;
	return true;
}

void vk_VkPipelineShaderStageCreateInfo_to(const void *raw, zval *rv)
{
	(void) raw;
	object_init_ex(rv, vulkan_ce_VkPipelineShaderStageCreateInfo);
}

bool vk_VkVertexInputBindingDescription_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkVertexInputBindingDescription *dst = raw;
	memset(dst, 0, sizeof(*dst));
	if (!vulkan_enter(obj, visited)) return false;
	if (!vulkan_u32(obj, "binding", &dst->binding)) return false;
	if (!vulkan_u32(obj, "stride", &dst->stride)) return false;
	if (!vulkan_u32(obj, "inputRate", &dst->inputRate)) return false;
	return true;
}

void vk_VkVertexInputBindingDescription_to(const void *raw, zval *rv)
{
	(void) raw;
	object_init_ex(rv, vulkan_ce_VkVertexInputBindingDescription);
}

bool vk_VkVertexInputAttributeDescription_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkVertexInputAttributeDescription *dst = raw;
	memset(dst, 0, sizeof(*dst));
	if (!vulkan_enter(obj, visited)) return false;
	if (!vulkan_u32(obj, "location", &dst->location)) return false;
	if (!vulkan_u32(obj, "binding", &dst->binding)) return false;
	if (!vulkan_u32(obj, "format", &dst->format)) return false;
	if (!vulkan_u32(obj, "offset", &dst->offset)) return false;
	return true;
}

void vk_VkVertexInputAttributeDescription_to(const void *raw, zval *rv)
{
	(void) raw;
	object_init_ex(rv, vulkan_ce_VkVertexInputAttributeDescription);
}

bool vk_VkPipelineVertexInputStateCreateInfo_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkPipelineVertexInputStateCreateInfo *dst = raw;
	memset(dst, 0, sizeof(*dst));
	dst->sType = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;
	if (!vulkan_enter(obj, visited)) return false;
	if (!vulkan_pnext(obj, &dst->pNext, scratch, visited)) return false;
	if (!vulkan_u32(obj, "flags", &dst->flags)) return false;
	if (!vulkan_struct_list(obj, "pVertexBindingDescriptions", vulkan_ce_VkVertexInputBindingDescription, sizeof(VkVertexInputBindingDescription), vk_VkVertexInputBindingDescription_from, (void **) &dst->pVertexBindingDescriptions, &dst->vertexBindingDescriptionCount, scratch, visited)) return false;
	if (!vulkan_struct_list(obj, "pVertexAttributeDescriptions", vulkan_ce_VkVertexInputAttributeDescription, sizeof(VkVertexInputAttributeDescription), vk_VkVertexInputAttributeDescription_from, (void **) &dst->pVertexAttributeDescriptions, &dst->vertexAttributeDescriptionCount, scratch, visited)) return false;
	return true;
}

void vk_VkPipelineVertexInputStateCreateInfo_to(const void *raw, zval *rv)
{
	(void) raw;
	object_init_ex(rv, vulkan_ce_VkPipelineVertexInputStateCreateInfo);
}

bool vk_VkPipelineInputAssemblyStateCreateInfo_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkPipelineInputAssemblyStateCreateInfo *dst = raw;
	memset(dst, 0, sizeof(*dst));
	dst->sType = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
	if (!vulkan_enter(obj, visited)) return false;
	if (!vulkan_pnext(obj, &dst->pNext, scratch, visited)) return false;
	if (!vulkan_u32(obj, "flags", &dst->flags)) return false;
	if (!vulkan_u32(obj, "topology", &dst->topology)) return false;
	if (!vulkan_u32(obj, "primitiveRestartEnable", &dst->primitiveRestartEnable)) return false;
	return true;
}

void vk_VkPipelineInputAssemblyStateCreateInfo_to(const void *raw, zval *rv)
{
	(void) raw;
	object_init_ex(rv, vulkan_ce_VkPipelineInputAssemblyStateCreateInfo);
}

bool vk_VkPipelineViewportStateCreateInfo_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkPipelineViewportStateCreateInfo *dst = raw;
	memset(dst, 0, sizeof(*dst));
	dst->sType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO;
	if (!vulkan_enter(obj, visited)) return false;
	if (!vulkan_pnext(obj, &dst->pNext, scratch, visited)) return false;
	if (!vulkan_u32(obj, "flags", &dst->flags)) return false;
	if (!vulkan_u32(obj, "viewportCount", &dst->viewportCount)) return false;
	if (!vulkan_opt_struct_list(obj, "pViewports", vulkan_ce_VkViewport, sizeof(VkViewport), vk_VkViewport_from, (void **) &dst->pViewports, &dst->viewportCount, scratch, visited)) return false;
	if (!vulkan_u32(obj, "scissorCount", &dst->scissorCount)) return false;
	if (!vulkan_opt_struct_list(obj, "pScissors", vulkan_ce_VkRect2D, sizeof(VkRect2D), vk_VkRect2D_from, (void **) &dst->pScissors, &dst->scissorCount, scratch, visited)) return false;
	return true;
}

void vk_VkPipelineViewportStateCreateInfo_to(const void *raw, zval *rv)
{
	(void) raw;
	object_init_ex(rv, vulkan_ce_VkPipelineViewportStateCreateInfo);
}

bool vk_VkPipelineRasterizationStateCreateInfo_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkPipelineRasterizationStateCreateInfo *dst = raw;
	memset(dst, 0, sizeof(*dst));
	dst->sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO;
	if (!vulkan_enter(obj, visited)) return false;
	if (!vulkan_pnext(obj, &dst->pNext, scratch, visited)) return false;
	if (!vulkan_u32(obj, "flags", &dst->flags)) return false;
	if (!vulkan_u32(obj, "depthClampEnable", &dst->depthClampEnable)) return false;
	if (!vulkan_u32(obj, "rasterizerDiscardEnable", &dst->rasterizerDiscardEnable)) return false;
	if (!vulkan_u32(obj, "polygonMode", &dst->polygonMode)) return false;
	if (!vulkan_u32(obj, "cullMode", &dst->cullMode)) return false;
	if (!vulkan_u32(obj, "frontFace", &dst->frontFace)) return false;
	if (!vulkan_u32(obj, "depthBiasEnable", &dst->depthBiasEnable)) return false;
	if (!vulkan_float(obj, "depthBiasConstantFactor", &dst->depthBiasConstantFactor)) return false;
	if (!vulkan_float(obj, "depthBiasClamp", &dst->depthBiasClamp)) return false;
	if (!vulkan_float(obj, "depthBiasSlopeFactor", &dst->depthBiasSlopeFactor)) return false;
	if (!vulkan_float(obj, "lineWidth", &dst->lineWidth)) return false;
	return true;
}

void vk_VkPipelineRasterizationStateCreateInfo_to(const void *raw, zval *rv)
{
	(void) raw;
	object_init_ex(rv, vulkan_ce_VkPipelineRasterizationStateCreateInfo);
}

bool vk_VkPipelineMultisampleStateCreateInfo_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkPipelineMultisampleStateCreateInfo *dst = raw;
	const uint32_t *u32s = NULL;
	uint32_t ignored_count = 0;
	memset(dst, 0, sizeof(*dst));
	dst->sType = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO;
	if (!vulkan_enter(obj, visited)) return false;
	if (!vulkan_pnext(obj, &dst->pNext, scratch, visited)) return false;
	if (!vulkan_u32(obj, "flags", &dst->flags)) return false;
	if (!vulkan_u32(obj, "rasterizationSamples", &dst->rasterizationSamples)) return false;
	if (!vulkan_u32(obj, "sampleShadingEnable", &dst->sampleShadingEnable)) return false;
	if (!vulkan_float(obj, "minSampleShading", &dst->minSampleShading)) return false;
	if (!vulkan_u32_list(obj, "pSampleMask", &u32s, &ignored_count, scratch)) return false;
	dst->pSampleMask = (const uint32_t *) u32s;
	if (!vulkan_u32(obj, "alphaToCoverageEnable", &dst->alphaToCoverageEnable)) return false;
	if (!vulkan_u32(obj, "alphaToOneEnable", &dst->alphaToOneEnable)) return false;
	return true;
}

void vk_VkPipelineMultisampleStateCreateInfo_to(const void *raw, zval *rv)
{
	(void) raw;
	object_init_ex(rv, vulkan_ce_VkPipelineMultisampleStateCreateInfo);
}

bool vk_VkStencilOpState_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkStencilOpState *dst = raw;
	memset(dst, 0, sizeof(*dst));
	if (!vulkan_enter(obj, visited)) return false;
	if (!vulkan_u32(obj, "failOp", &dst->failOp)) return false;
	if (!vulkan_u32(obj, "passOp", &dst->passOp)) return false;
	if (!vulkan_u32(obj, "depthFailOp", &dst->depthFailOp)) return false;
	if (!vulkan_u32(obj, "compareOp", &dst->compareOp)) return false;
	if (!vulkan_u32(obj, "compareMask", &dst->compareMask)) return false;
	if (!vulkan_u32(obj, "writeMask", &dst->writeMask)) return false;
	if (!vulkan_u32(obj, "reference", &dst->reference)) return false;
	return true;
}

void vk_VkStencilOpState_to(const void *raw, zval *rv)
{
	(void) raw;
	object_init_ex(rv, vulkan_ce_VkStencilOpState);
}

bool vk_VkPipelineDepthStencilStateCreateInfo_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkPipelineDepthStencilStateCreateInfo *dst = raw;
	memset(dst, 0, sizeof(*dst));
	dst->sType = VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO;
	if (!vulkan_enter(obj, visited)) return false;
	if (!vulkan_pnext(obj, &dst->pNext, scratch, visited)) return false;
	if (!vulkan_u32(obj, "flags", &dst->flags)) return false;
	if (!vulkan_u32(obj, "depthTestEnable", &dst->depthTestEnable)) return false;
	if (!vulkan_u32(obj, "depthWriteEnable", &dst->depthWriteEnable)) return false;
	if (!vulkan_u32(obj, "depthCompareOp", &dst->depthCompareOp)) return false;
	if (!vulkan_u32(obj, "depthBoundsTestEnable", &dst->depthBoundsTestEnable)) return false;
	if (!vulkan_u32(obj, "stencilTestEnable", &dst->stencilTestEnable)) return false;
	if (!vulkan_struct_value(obj, "front", vulkan_ce_VkStencilOpState, vk_VkStencilOpState_from, &dst->front, scratch, visited)) return false;
	if (!vulkan_struct_value(obj, "back", vulkan_ce_VkStencilOpState, vk_VkStencilOpState_from, &dst->back, scratch, visited)) return false;
	if (!vulkan_float(obj, "minDepthBounds", &dst->minDepthBounds)) return false;
	if (!vulkan_float(obj, "maxDepthBounds", &dst->maxDepthBounds)) return false;
	return true;
}

void vk_VkPipelineDepthStencilStateCreateInfo_to(const void *raw, zval *rv)
{
	(void) raw;
	object_init_ex(rv, vulkan_ce_VkPipelineDepthStencilStateCreateInfo);
}

bool vk_VkPipelineColorBlendAttachmentState_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkPipelineColorBlendAttachmentState *dst = raw;
	memset(dst, 0, sizeof(*dst));
	if (!vulkan_enter(obj, visited)) return false;
	if (!vulkan_u32(obj, "blendEnable", &dst->blendEnable)) return false;
	if (!vulkan_u32(obj, "srcColorBlendFactor", &dst->srcColorBlendFactor)) return false;
	if (!vulkan_u32(obj, "dstColorBlendFactor", &dst->dstColorBlendFactor)) return false;
	if (!vulkan_u32(obj, "colorBlendOp", &dst->colorBlendOp)) return false;
	if (!vulkan_u32(obj, "srcAlphaBlendFactor", &dst->srcAlphaBlendFactor)) return false;
	if (!vulkan_u32(obj, "dstAlphaBlendFactor", &dst->dstAlphaBlendFactor)) return false;
	if (!vulkan_u32(obj, "alphaBlendOp", &dst->alphaBlendOp)) return false;
	if (!vulkan_u32(obj, "colorWriteMask", &dst->colorWriteMask)) return false;
	return true;
}

void vk_VkPipelineColorBlendAttachmentState_to(const void *raw, zval *rv)
{
	(void) raw;
	object_init_ex(rv, vulkan_ce_VkPipelineColorBlendAttachmentState);
}

bool vk_VkPipelineColorBlendStateCreateInfo_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkPipelineColorBlendStateCreateInfo *dst = raw;
	memset(dst, 0, sizeof(*dst));
	dst->sType = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;
	if (!vulkan_enter(obj, visited)) return false;
	if (!vulkan_pnext(obj, &dst->pNext, scratch, visited)) return false;
	if (!vulkan_u32(obj, "flags", &dst->flags)) return false;
	if (!vulkan_u32(obj, "logicOpEnable", &dst->logicOpEnable)) return false;
	if (!vulkan_u32(obj, "logicOp", &dst->logicOp)) return false;
	if (!vulkan_struct_list(obj, "pAttachments", vulkan_ce_VkPipelineColorBlendAttachmentState, sizeof(VkPipelineColorBlendAttachmentState), vk_VkPipelineColorBlendAttachmentState_from, (void **) &dst->pAttachments, &dst->attachmentCount, scratch, visited)) return false;
	if (!vulkan_optional_floats(obj, "blendConstants", dst->blendConstants, 4)) return false;
	return true;
}

void vk_VkPipelineColorBlendStateCreateInfo_to(const void *raw, zval *rv)
{
	(void) raw;
	object_init_ex(rv, vulkan_ce_VkPipelineColorBlendStateCreateInfo);
}

bool vk_VkPipelineDynamicStateCreateInfo_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkPipelineDynamicStateCreateInfo *dst = raw;
	const uint32_t *u32s = NULL;
	memset(dst, 0, sizeof(*dst));
	dst->sType = VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO;
	if (!vulkan_enter(obj, visited)) return false;
	if (!vulkan_pnext(obj, &dst->pNext, scratch, visited)) return false;
	if (!vulkan_u32(obj, "flags", &dst->flags)) return false;
	if (!vulkan_u32_list(obj, "pDynamicStates", &u32s, &dst->dynamicStateCount, scratch)) return false;
	dst->pDynamicStates = (const VkDynamicState *) u32s;
	return true;
}

void vk_VkPipelineDynamicStateCreateInfo_to(const void *raw, zval *rv)
{
	(void) raw;
	object_init_ex(rv, vulkan_ce_VkPipelineDynamicStateCreateInfo);
}

bool vk_VkPipelineTessellationStateCreateInfo_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkPipelineTessellationStateCreateInfo *dst = raw;
	memset(dst, 0, sizeof(*dst));
	dst->sType = VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_STATE_CREATE_INFO;
	if (!vulkan_enter(obj, visited)) return false;
	if (!vulkan_pnext(obj, &dst->pNext, scratch, visited)) return false;
	if (!vulkan_u32(obj, "flags", &dst->flags)) return false;
	if (!vulkan_u32(obj, "patchControlPoints", &dst->patchControlPoints)) return false;
	return true;
}

void vk_VkPipelineTessellationStateCreateInfo_to(const void *raw, zval *rv)
{
	(void) raw;
	object_init_ex(rv, vulkan_ce_VkPipelineTessellationStateCreateInfo);
}

bool vk_VkGraphicsPipelineCreateInfo_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkGraphicsPipelineCreateInfo *dst = raw;
	uint64_t handle_tmp;
	memset(dst, 0, sizeof(*dst));
	dst->sType = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;
	if (!vulkan_enter(obj, visited)) return false;
	if (!vulkan_pnext(obj, &dst->pNext, scratch, visited)) return false;
	if (!vulkan_u32(obj, "flags", &dst->flags)) return false;
	if (!vulkan_struct_list(obj, "pStages", vulkan_ce_VkPipelineShaderStageCreateInfo, sizeof(VkPipelineShaderStageCreateInfo), vk_VkPipelineShaderStageCreateInfo_from, (void **) &dst->pStages, &dst->stageCount, scratch, visited)) return false;
	if (!vulkan_struct_ptr(obj, "pVertexInputState", vulkan_ce_VkPipelineVertexInputStateCreateInfo, sizeof(VkPipelineVertexInputStateCreateInfo), vk_VkPipelineVertexInputStateCreateInfo_from, (void **) &dst->pVertexInputState, scratch, visited)) return false;
	if (!vulkan_struct_ptr(obj, "pInputAssemblyState", vulkan_ce_VkPipelineInputAssemblyStateCreateInfo, sizeof(VkPipelineInputAssemblyStateCreateInfo), vk_VkPipelineInputAssemblyStateCreateInfo_from, (void **) &dst->pInputAssemblyState, scratch, visited)) return false;
	if (!vulkan_struct_ptr(obj, "pTessellationState", vulkan_ce_VkPipelineTessellationStateCreateInfo, sizeof(VkPipelineTessellationStateCreateInfo), vk_VkPipelineTessellationStateCreateInfo_from, (void **) &dst->pTessellationState, scratch, visited)) return false;
	if (!vulkan_struct_ptr(obj, "pViewportState", vulkan_ce_VkPipelineViewportStateCreateInfo, sizeof(VkPipelineViewportStateCreateInfo), vk_VkPipelineViewportStateCreateInfo_from, (void **) &dst->pViewportState, scratch, visited)) return false;
	if (!vulkan_struct_ptr(obj, "pRasterizationState", vulkan_ce_VkPipelineRasterizationStateCreateInfo, sizeof(VkPipelineRasterizationStateCreateInfo), vk_VkPipelineRasterizationStateCreateInfo_from, (void **) &dst->pRasterizationState, scratch, visited)) return false;
	if (!vulkan_struct_ptr(obj, "pMultisampleState", vulkan_ce_VkPipelineMultisampleStateCreateInfo, sizeof(VkPipelineMultisampleStateCreateInfo), vk_VkPipelineMultisampleStateCreateInfo_from, (void **) &dst->pMultisampleState, scratch, visited)) return false;
	if (!vulkan_struct_ptr(obj, "pDepthStencilState", vulkan_ce_VkPipelineDepthStencilStateCreateInfo, sizeof(VkPipelineDepthStencilStateCreateInfo), vk_VkPipelineDepthStencilStateCreateInfo_from, (void **) &dst->pDepthStencilState, scratch, visited)) return false;
	if (!vulkan_struct_ptr(obj, "pColorBlendState", vulkan_ce_VkPipelineColorBlendStateCreateInfo, sizeof(VkPipelineColorBlendStateCreateInfo), vk_VkPipelineColorBlendStateCreateInfo_from, (void **) &dst->pColorBlendState, scratch, visited)) return false;
	if (!vulkan_struct_ptr(obj, "pDynamicState", vulkan_ce_VkPipelineDynamicStateCreateInfo, sizeof(VkPipelineDynamicStateCreateInfo), vk_VkPipelineDynamicStateCreateInfo_from, (void **) &dst->pDynamicState, scratch, visited)) return false;
	if (!vulkan_handle_prop(obj, "layout", vulkan_ce_VkPipelineLayout, &handle_tmp)) return false;
	dst->layout = (VkPipelineLayout) (uintptr_t) handle_tmp;
	if (!vulkan_handle_prop(obj, "renderPass", vulkan_ce_VkRenderPass, &handle_tmp)) return false;
	dst->renderPass = (VkRenderPass) (uintptr_t) handle_tmp;
	if (!vulkan_u32(obj, "subpass", &dst->subpass)) return false;
	if (!vulkan_handle_prop(obj, "basePipelineHandle", vulkan_ce_VkPipeline, &handle_tmp)) return false;
	dst->basePipelineHandle = (VkPipeline) (uintptr_t) handle_tmp;
	if (!vulkan_i32(obj, "basePipelineIndex", &dst->basePipelineIndex)) return false;
	return true;
}

void vk_VkGraphicsPipelineCreateInfo_to(const void *raw, zval *rv)
{
	(void) raw;
	object_init_ex(rv, vulkan_ce_VkGraphicsPipelineCreateInfo);
}

bool vk_VkDescriptorSetLayoutBinding_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkDescriptorSetLayoutBinding *dst = raw;
	uint64_t *handles = NULL;
	uint32_t ignored_count = 0;
	memset(dst, 0, sizeof(*dst));
	if (!vulkan_enter(obj, visited)) return false;
	if (!vulkan_u32(obj, "binding", &dst->binding)) return false;
	if (!vulkan_u32(obj, "descriptorType", &dst->descriptorType)) return false;
	if (!vulkan_u32(obj, "descriptorCount", &dst->descriptorCount)) return false;
	if (!vulkan_u32(obj, "stageFlags", &dst->stageFlags)) return false;
	if (!vulkan_handle_list(obj, "pImmutableSamplers", vulkan_ce_VkSampler, &handles, &ignored_count, scratch)) return false;
	dst->pImmutableSamplers = handles == NULL ? NULL : (VkSampler const *) handles;
	return true;
}

void vk_VkDescriptorSetLayoutBinding_to(const void *raw, zval *rv)
{
	(void) raw;
	object_init_ex(rv, vulkan_ce_VkDescriptorSetLayoutBinding);
}

bool vk_VkDescriptorSetLayoutCreateInfo_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkDescriptorSetLayoutCreateInfo *dst = raw;
	memset(dst, 0, sizeof(*dst));
	dst->sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
	if (!vulkan_enter(obj, visited)) return false;
	if (!vulkan_pnext(obj, &dst->pNext, scratch, visited)) return false;
	if (!vulkan_u32(obj, "flags", &dst->flags)) return false;
	if (!vulkan_struct_list(obj, "pBindings", vulkan_ce_VkDescriptorSetLayoutBinding, sizeof(VkDescriptorSetLayoutBinding), vk_VkDescriptorSetLayoutBinding_from, (void **) &dst->pBindings, &dst->bindingCount, scratch, visited)) return false;
	return true;
}

void vk_VkDescriptorSetLayoutCreateInfo_to(const void *raw, zval *rv)
{
	(void) raw;
	object_init_ex(rv, vulkan_ce_VkDescriptorSetLayoutCreateInfo);
}

bool vk_VkDescriptorPoolSize_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkDescriptorPoolSize *dst = raw;
	memset(dst, 0, sizeof(*dst));
	if (!vulkan_enter(obj, visited)) return false;
	if (!vulkan_u32(obj, "type", &dst->type)) return false;
	if (!vulkan_u32(obj, "descriptorCount", &dst->descriptorCount)) return false;
	return true;
}

void vk_VkDescriptorPoolSize_to(const void *raw, zval *rv)
{
	(void) raw;
	object_init_ex(rv, vulkan_ce_VkDescriptorPoolSize);
}

bool vk_VkDescriptorPoolCreateInfo_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkDescriptorPoolCreateInfo *dst = raw;
	memset(dst, 0, sizeof(*dst));
	dst->sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
	if (!vulkan_enter(obj, visited)) return false;
	if (!vulkan_pnext(obj, &dst->pNext, scratch, visited)) return false;
	if (!vulkan_u32(obj, "flags", &dst->flags)) return false;
	if (!vulkan_u32(obj, "maxSets", &dst->maxSets)) return false;
	if (!vulkan_struct_list(obj, "pPoolSizes", vulkan_ce_VkDescriptorPoolSize, sizeof(VkDescriptorPoolSize), vk_VkDescriptorPoolSize_from, (void **) &dst->pPoolSizes, &dst->poolSizeCount, scratch, visited)) return false;
	return true;
}

void vk_VkDescriptorPoolCreateInfo_to(const void *raw, zval *rv)
{
	(void) raw;
	object_init_ex(rv, vulkan_ce_VkDescriptorPoolCreateInfo);
}

bool vk_VkDescriptorSetAllocateInfo_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkDescriptorSetAllocateInfo *dst = raw;
	uint64_t handle_tmp;
	uint64_t *handles = NULL;
	memset(dst, 0, sizeof(*dst));
	dst->sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;
	if (!vulkan_enter(obj, visited)) return false;
	if (!vulkan_pnext(obj, &dst->pNext, scratch, visited)) return false;
	if (!vulkan_handle_prop(obj, "descriptorPool", vulkan_ce_VkDescriptorPool, &handle_tmp)) return false;
	dst->descriptorPool = (VkDescriptorPool) (uintptr_t) handle_tmp;
	if (!vulkan_handle_list(obj, "pSetLayouts", vulkan_ce_VkDescriptorSetLayout, &handles, &dst->descriptorSetCount, scratch)) return false;
	dst->pSetLayouts = handles == NULL ? NULL : (VkDescriptorSetLayout const *) handles;
	return true;
}

void vk_VkDescriptorSetAllocateInfo_to(const void *raw, zval *rv)
{
	(void) raw;
	object_init_ex(rv, vulkan_ce_VkDescriptorSetAllocateInfo);
}

bool vk_VkDescriptorImageInfo_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkDescriptorImageInfo *dst = raw;
	uint64_t handle_tmp;
	memset(dst, 0, sizeof(*dst));
	if (!vulkan_enter(obj, visited)) return false;
	if (!vulkan_handle_prop(obj, "sampler", vulkan_ce_VkSampler, &handle_tmp)) return false;
	dst->sampler = (VkSampler) (uintptr_t) handle_tmp;
	if (!vulkan_handle_prop(obj, "imageView", vulkan_ce_VkImageView, &handle_tmp)) return false;
	dst->imageView = (VkImageView) (uintptr_t) handle_tmp;
	if (!vulkan_u32(obj, "imageLayout", &dst->imageLayout)) return false;
	return true;
}

void vk_VkDescriptorImageInfo_to(const void *raw, zval *rv)
{
	(void) raw;
	object_init_ex(rv, vulkan_ce_VkDescriptorImageInfo);
}

bool vk_VkWriteDescriptorSet_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkWriteDescriptorSet *dst = raw;
	uint64_t handle_tmp;
	memset(dst, 0, sizeof(*dst));
	dst->sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
	if (!vulkan_enter(obj, visited)) return false;
	if (!vulkan_pnext(obj, &dst->pNext, scratch, visited)) return false;
	if (!vulkan_handle_prop(obj, "dstSet", vulkan_ce_VkDescriptorSet, &handle_tmp)) return false;
	dst->dstSet = (VkDescriptorSet) (uintptr_t) handle_tmp;
	if (!vulkan_u32(obj, "dstBinding", &dst->dstBinding)) return false;
	if (!vulkan_u32(obj, "dstArrayElement", &dst->dstArrayElement)) return false;
	if (!vulkan_u32(obj, "descriptorType", &dst->descriptorType)) return false;
	if (!vulkan_struct_list(obj, "pImageInfo", vulkan_ce_VkDescriptorImageInfo, sizeof(VkDescriptorImageInfo), vk_VkDescriptorImageInfo_from, (void **) &dst->pImageInfo, &dst->descriptorCount, scratch, visited)) return false;
	return true;
}

void vk_VkWriteDescriptorSet_to(const void *raw, zval *rv)
{
	(void) raw;
	object_init_ex(rv, vulkan_ce_VkWriteDescriptorSet);
}

bool vk_VkViewport_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkViewport *dst = raw;
	memset(dst, 0, sizeof(*dst));
	if (!vulkan_enter(obj, visited)) return false;
	if (!vulkan_float(obj, "x", &dst->x)) return false;
	if (!vulkan_float(obj, "y", &dst->y)) return false;
	if (!vulkan_float(obj, "width", &dst->width)) return false;
	if (!vulkan_float(obj, "height", &dst->height)) return false;
	if (!vulkan_float(obj, "minDepth", &dst->minDepth)) return false;
	if (!vulkan_float(obj, "maxDepth", &dst->maxDepth)) return false;
	return true;
}

void vk_VkViewport_to(const void *raw, zval *rv)
{
	(void) raw;
	object_init_ex(rv, vulkan_ce_VkViewport);
}

bool vk_VkOffset2D_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkOffset2D *dst = raw;
	memset(dst, 0, sizeof(*dst));
	if (!vulkan_enter(obj, visited)) return false;
	if (!vulkan_i32(obj, "x", &dst->x)) return false;
	if (!vulkan_i32(obj, "y", &dst->y)) return false;
	return true;
}

void vk_VkOffset2D_to(const void *raw, zval *rv)
{
	(void) raw;
	object_init_ex(rv, vulkan_ce_VkOffset2D);
}

bool vk_VkExtent2D_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkExtent2D *dst = raw;
	memset(dst, 0, sizeof(*dst));
	if (!vulkan_enter(obj, visited)) return false;
	if (!vulkan_u32(obj, "width", &dst->width)) return false;
	if (!vulkan_u32(obj, "height", &dst->height)) return false;
	return true;
}

void vk_VkExtent2D_to(const void *raw, zval *rv)
{
	(void) raw;
	object_init_ex(rv, vulkan_ce_VkExtent2D);
}

bool vk_VkRect2D_from(zend_object *obj, void *raw, vulkan_scratch *scratch, HashTable *visited)
{
	VkRect2D *dst = raw;
	memset(dst, 0, sizeof(*dst));
	if (!vulkan_enter(obj, visited)) return false;
	if (!vulkan_struct_value(obj, "offset", vulkan_ce_VkOffset2D, vk_VkOffset2D_from, &dst->offset, scratch, visited)) return false;
	if (!vulkan_struct_value(obj, "extent", vulkan_ce_VkExtent2D, vk_VkExtent2D_from, &dst->extent, scratch, visited)) return false;
	return true;
}

void vk_VkRect2D_to(const void *raw, zval *rv)
{
	(void) raw;
	object_init_ex(rv, vulkan_ce_VkRect2D);
}
