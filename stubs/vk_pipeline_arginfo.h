/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 1e23b53fe0b110a8864a89f52f88f975b70addf0 */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkCreateRenderPass, 0, 4, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, device, VkDevice, 0)
	ZEND_ARG_OBJ_INFO(0, pCreateInfo, VkRenderPassCreateInfo, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_NULL, 1)
	ZEND_ARG_OBJ_INFO(1, pRenderPass, VkRenderPass, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkDestroyRenderPass, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, device, VkDevice, 0)
	ZEND_ARG_OBJ_INFO(0, renderPass, VkRenderPass, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_NULL, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkCreateFramebuffer, 0, 4, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, device, VkDevice, 0)
	ZEND_ARG_OBJ_INFO(0, pCreateInfo, VkFramebufferCreateInfo, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_NULL, 1)
	ZEND_ARG_OBJ_INFO(1, pFramebuffer, VkFramebuffer, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkDestroyFramebuffer, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, device, VkDevice, 0)
	ZEND_ARG_OBJ_INFO(0, framebuffer, VkFramebuffer, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_NULL, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkCreateShaderModule, 0, 4, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, device, VkDevice, 0)
	ZEND_ARG_OBJ_INFO(0, pCreateInfo, VkShaderModuleCreateInfo, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_NULL, 1)
	ZEND_ARG_OBJ_INFO(1, pShaderModule, VkShaderModule, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkDestroyShaderModule, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, device, VkDevice, 0)
	ZEND_ARG_OBJ_INFO(0, shaderModule, VkShaderModule, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_NULL, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkCreatePipelineLayout, 0, 4, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, device, VkDevice, 0)
	ZEND_ARG_OBJ_INFO(0, pCreateInfo, VkPipelineLayoutCreateInfo, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_NULL, 1)
	ZEND_ARG_OBJ_INFO(1, pPipelineLayout, VkPipelineLayout, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkDestroyPipelineLayout, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, device, VkDevice, 0)
	ZEND_ARG_OBJ_INFO(0, pipelineLayout, VkPipelineLayout, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_NULL, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkCreateGraphicsPipelines, 0, 5, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, device, VkDevice, 0)
	ZEND_ARG_TYPE_INFO(0, pipelineCache, IS_NULL, 1)
	ZEND_ARG_TYPE_INFO(0, pCreateInfos, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_NULL, 1)
	ZEND_ARG_TYPE_INFO(1, pPipelines, IS_ARRAY, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkDestroyPipeline, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, device, VkDevice, 0)
	ZEND_ARG_OBJ_INFO(0, pipeline, VkPipeline, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_NULL, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkCreateDescriptorSetLayout, 0, 4, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, device, VkDevice, 0)
	ZEND_ARG_OBJ_INFO(0, pCreateInfo, VkDescriptorSetLayoutCreateInfo, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_NULL, 1)
	ZEND_ARG_OBJ_INFO(1, pSetLayout, VkDescriptorSetLayout, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkDestroyDescriptorSetLayout, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, device, VkDevice, 0)
	ZEND_ARG_OBJ_INFO(0, descriptorSetLayout, VkDescriptorSetLayout, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_NULL, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkCreateDescriptorPool, 0, 4, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, device, VkDevice, 0)
	ZEND_ARG_OBJ_INFO(0, pCreateInfo, VkDescriptorPoolCreateInfo, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_NULL, 1)
	ZEND_ARG_OBJ_INFO(1, pDescriptorPool, VkDescriptorPool, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkDestroyDescriptorPool, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, device, VkDevice, 0)
	ZEND_ARG_OBJ_INFO(0, descriptorPool, VkDescriptorPool, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_NULL, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkAllocateDescriptorSets, 0, 3, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, device, VkDevice, 0)
	ZEND_ARG_OBJ_INFO(0, pAllocateInfo, VkDescriptorSetAllocateInfo, 0)
	ZEND_ARG_TYPE_INFO(1, pDescriptorSets, IS_ARRAY, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkUpdateDescriptorSets, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, device, VkDevice, 0)
	ZEND_ARG_TYPE_INFO(0, pDescriptorWrites, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, pDescriptorCopies, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_VkRenderPass___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_VkRenderPass_pointer, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_VkRenderPass_fromPointer, 0, 1, IS_STATIC, 0)
	ZEND_ARG_TYPE_INFO(0, pointer, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_VkFramebuffer___construct arginfo_class_VkRenderPass___construct

#define arginfo_class_VkFramebuffer_pointer arginfo_class_VkRenderPass_pointer

#define arginfo_class_VkFramebuffer_fromPointer arginfo_class_VkRenderPass_fromPointer

#define arginfo_class_VkShaderModule___construct arginfo_class_VkRenderPass___construct

#define arginfo_class_VkShaderModule_pointer arginfo_class_VkRenderPass_pointer

#define arginfo_class_VkShaderModule_fromPointer arginfo_class_VkRenderPass_fromPointer

#define arginfo_class_VkPipelineLayout___construct arginfo_class_VkRenderPass___construct

#define arginfo_class_VkPipelineLayout_pointer arginfo_class_VkRenderPass_pointer

#define arginfo_class_VkPipelineLayout_fromPointer arginfo_class_VkRenderPass_fromPointer

#define arginfo_class_VkPipeline___construct arginfo_class_VkRenderPass___construct

#define arginfo_class_VkPipeline_pointer arginfo_class_VkRenderPass_pointer

#define arginfo_class_VkPipeline_fromPointer arginfo_class_VkRenderPass_fromPointer

#define arginfo_class_VkDescriptorSetLayout___construct arginfo_class_VkRenderPass___construct

#define arginfo_class_VkDescriptorSetLayout_pointer arginfo_class_VkRenderPass_pointer

#define arginfo_class_VkDescriptorSetLayout_fromPointer arginfo_class_VkRenderPass_fromPointer

#define arginfo_class_VkDescriptorPool___construct arginfo_class_VkRenderPass___construct

#define arginfo_class_VkDescriptorPool_pointer arginfo_class_VkRenderPass_pointer

#define arginfo_class_VkDescriptorPool_fromPointer arginfo_class_VkRenderPass_fromPointer

#define arginfo_class_VkDescriptorSet___construct arginfo_class_VkRenderPass___construct

#define arginfo_class_VkDescriptorSet_pointer arginfo_class_VkRenderPass_pointer

#define arginfo_class_VkDescriptorSet_fromPointer arginfo_class_VkRenderPass_fromPointer

#define arginfo_class_VkPipelineDepthStencilStateCreateInfo___construct arginfo_class_VkRenderPass___construct

#define arginfo_class_VkRect2D___construct arginfo_class_VkRenderPass___construct

ZEND_FUNCTION(vkCreateRenderPass);
ZEND_FUNCTION(vkDestroyRenderPass);
ZEND_FUNCTION(vkCreateFramebuffer);
ZEND_FUNCTION(vkDestroyFramebuffer);
ZEND_FUNCTION(vkCreateShaderModule);
ZEND_FUNCTION(vkDestroyShaderModule);
ZEND_FUNCTION(vkCreatePipelineLayout);
ZEND_FUNCTION(vkDestroyPipelineLayout);
ZEND_FUNCTION(vkCreateGraphicsPipelines);
ZEND_FUNCTION(vkDestroyPipeline);
ZEND_FUNCTION(vkCreateDescriptorSetLayout);
ZEND_FUNCTION(vkDestroyDescriptorSetLayout);
ZEND_FUNCTION(vkCreateDescriptorPool);
ZEND_FUNCTION(vkDestroyDescriptorPool);
ZEND_FUNCTION(vkAllocateDescriptorSets);
ZEND_FUNCTION(vkUpdateDescriptorSets);
ZEND_METHOD(VkRenderPass, __construct);
ZEND_METHOD(VkRenderPass, pointer);
ZEND_METHOD(VkRenderPass, fromPointer);
ZEND_METHOD(VkFramebuffer, __construct);
ZEND_METHOD(VkFramebuffer, pointer);
ZEND_METHOD(VkFramebuffer, fromPointer);
ZEND_METHOD(VkShaderModule, __construct);
ZEND_METHOD(VkShaderModule, pointer);
ZEND_METHOD(VkShaderModule, fromPointer);
ZEND_METHOD(VkPipelineLayout, __construct);
ZEND_METHOD(VkPipelineLayout, pointer);
ZEND_METHOD(VkPipelineLayout, fromPointer);
ZEND_METHOD(VkPipeline, __construct);
ZEND_METHOD(VkPipeline, pointer);
ZEND_METHOD(VkPipeline, fromPointer);
ZEND_METHOD(VkDescriptorSetLayout, __construct);
ZEND_METHOD(VkDescriptorSetLayout, pointer);
ZEND_METHOD(VkDescriptorSetLayout, fromPointer);
ZEND_METHOD(VkDescriptorPool, __construct);
ZEND_METHOD(VkDescriptorPool, pointer);
ZEND_METHOD(VkDescriptorPool, fromPointer);
ZEND_METHOD(VkDescriptorSet, __construct);
ZEND_METHOD(VkDescriptorSet, pointer);
ZEND_METHOD(VkDescriptorSet, fromPointer);
ZEND_METHOD(VkPipelineDepthStencilStateCreateInfo, __construct);
ZEND_METHOD(VkRect2D, __construct);

static const zend_function_entry ext_functions[] = {
	ZEND_FE(vkCreateRenderPass, arginfo_vkCreateRenderPass)
	ZEND_FE(vkDestroyRenderPass, arginfo_vkDestroyRenderPass)
	ZEND_FE(vkCreateFramebuffer, arginfo_vkCreateFramebuffer)
	ZEND_FE(vkDestroyFramebuffer, arginfo_vkDestroyFramebuffer)
	ZEND_FE(vkCreateShaderModule, arginfo_vkCreateShaderModule)
	ZEND_FE(vkDestroyShaderModule, arginfo_vkDestroyShaderModule)
	ZEND_FE(vkCreatePipelineLayout, arginfo_vkCreatePipelineLayout)
	ZEND_FE(vkDestroyPipelineLayout, arginfo_vkDestroyPipelineLayout)
	ZEND_FE(vkCreateGraphicsPipelines, arginfo_vkCreateGraphicsPipelines)
	ZEND_FE(vkDestroyPipeline, arginfo_vkDestroyPipeline)
	ZEND_FE(vkCreateDescriptorSetLayout, arginfo_vkCreateDescriptorSetLayout)
	ZEND_FE(vkDestroyDescriptorSetLayout, arginfo_vkDestroyDescriptorSetLayout)
	ZEND_FE(vkCreateDescriptorPool, arginfo_vkCreateDescriptorPool)
	ZEND_FE(vkDestroyDescriptorPool, arginfo_vkDestroyDescriptorPool)
	ZEND_FE(vkAllocateDescriptorSets, arginfo_vkAllocateDescriptorSets)
	ZEND_FE(vkUpdateDescriptorSets, arginfo_vkUpdateDescriptorSets)
	ZEND_FE_END
};

static const zend_function_entry class_VkRenderPass_methods[] = {
	ZEND_ME(VkRenderPass, __construct, arginfo_class_VkRenderPass___construct, ZEND_ACC_PRIVATE)
	ZEND_ME(VkRenderPass, pointer, arginfo_class_VkRenderPass_pointer, ZEND_ACC_PUBLIC)
	ZEND_ME(VkRenderPass, fromPointer, arginfo_class_VkRenderPass_fromPointer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static const zend_function_entry class_VkFramebuffer_methods[] = {
	ZEND_ME(VkFramebuffer, __construct, arginfo_class_VkFramebuffer___construct, ZEND_ACC_PRIVATE)
	ZEND_ME(VkFramebuffer, pointer, arginfo_class_VkFramebuffer_pointer, ZEND_ACC_PUBLIC)
	ZEND_ME(VkFramebuffer, fromPointer, arginfo_class_VkFramebuffer_fromPointer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static const zend_function_entry class_VkShaderModule_methods[] = {
	ZEND_ME(VkShaderModule, __construct, arginfo_class_VkShaderModule___construct, ZEND_ACC_PRIVATE)
	ZEND_ME(VkShaderModule, pointer, arginfo_class_VkShaderModule_pointer, ZEND_ACC_PUBLIC)
	ZEND_ME(VkShaderModule, fromPointer, arginfo_class_VkShaderModule_fromPointer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static const zend_function_entry class_VkPipelineLayout_methods[] = {
	ZEND_ME(VkPipelineLayout, __construct, arginfo_class_VkPipelineLayout___construct, ZEND_ACC_PRIVATE)
	ZEND_ME(VkPipelineLayout, pointer, arginfo_class_VkPipelineLayout_pointer, ZEND_ACC_PUBLIC)
	ZEND_ME(VkPipelineLayout, fromPointer, arginfo_class_VkPipelineLayout_fromPointer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static const zend_function_entry class_VkPipeline_methods[] = {
	ZEND_ME(VkPipeline, __construct, arginfo_class_VkPipeline___construct, ZEND_ACC_PRIVATE)
	ZEND_ME(VkPipeline, pointer, arginfo_class_VkPipeline_pointer, ZEND_ACC_PUBLIC)
	ZEND_ME(VkPipeline, fromPointer, arginfo_class_VkPipeline_fromPointer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static const zend_function_entry class_VkDescriptorSetLayout_methods[] = {
	ZEND_ME(VkDescriptorSetLayout, __construct, arginfo_class_VkDescriptorSetLayout___construct, ZEND_ACC_PRIVATE)
	ZEND_ME(VkDescriptorSetLayout, pointer, arginfo_class_VkDescriptorSetLayout_pointer, ZEND_ACC_PUBLIC)
	ZEND_ME(VkDescriptorSetLayout, fromPointer, arginfo_class_VkDescriptorSetLayout_fromPointer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static const zend_function_entry class_VkDescriptorPool_methods[] = {
	ZEND_ME(VkDescriptorPool, __construct, arginfo_class_VkDescriptorPool___construct, ZEND_ACC_PRIVATE)
	ZEND_ME(VkDescriptorPool, pointer, arginfo_class_VkDescriptorPool_pointer, ZEND_ACC_PUBLIC)
	ZEND_ME(VkDescriptorPool, fromPointer, arginfo_class_VkDescriptorPool_fromPointer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static const zend_function_entry class_VkDescriptorSet_methods[] = {
	ZEND_ME(VkDescriptorSet, __construct, arginfo_class_VkDescriptorSet___construct, ZEND_ACC_PRIVATE)
	ZEND_ME(VkDescriptorSet, pointer, arginfo_class_VkDescriptorSet_pointer, ZEND_ACC_PUBLIC)
	ZEND_ME(VkDescriptorSet, fromPointer, arginfo_class_VkDescriptorSet_fromPointer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static const zend_function_entry class_VkPipelineDepthStencilStateCreateInfo_methods[] = {
	ZEND_ME(VkPipelineDepthStencilStateCreateInfo, __construct, arginfo_class_VkPipelineDepthStencilStateCreateInfo___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_VkRect2D_methods[] = {
	ZEND_ME(VkRect2D, __construct, arginfo_class_VkRect2D___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_VkRenderPass(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkRenderPass", class_VkRenderPass_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_VkFramebuffer(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkFramebuffer", class_VkFramebuffer_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_VkShaderModule(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkShaderModule", class_VkShaderModule_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_VkPipelineLayout(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkPipelineLayout", class_VkPipelineLayout_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_VkPipeline(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkPipeline", class_VkPipeline_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_VkDescriptorSetLayout(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkDescriptorSetLayout", class_VkDescriptorSetLayout_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_VkDescriptorPool(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkDescriptorPool", class_VkDescriptorPool_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_VkDescriptorSet(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkDescriptorSet", class_VkDescriptorSet_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_VkAttachmentDescription(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkAttachmentDescription", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_flags_default_value;
	ZVAL_LONG(&property_flags_default_value, 0);
	zend_string *property_flags_name = zend_string_init("flags", sizeof("flags") - 1, 1);
	zend_declare_typed_property(class_entry, property_flags_name, &property_flags_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_flags_name);

	zval property_format_default_value;
	ZVAL_LONG(&property_format_default_value, 0);
	zend_string *property_format_name = zend_string_init("format", sizeof("format") - 1, 1);
	zend_declare_typed_property(class_entry, property_format_name, &property_format_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_format_name);

	zval property_samples_default_value;
	ZVAL_LONG(&property_samples_default_value, 0);
	zend_string *property_samples_name = zend_string_init("samples", sizeof("samples") - 1, 1);
	zend_declare_typed_property(class_entry, property_samples_name, &property_samples_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_samples_name);

	zval property_loadOp_default_value;
	ZVAL_LONG(&property_loadOp_default_value, 0);
	zend_string *property_loadOp_name = zend_string_init("loadOp", sizeof("loadOp") - 1, 1);
	zend_declare_typed_property(class_entry, property_loadOp_name, &property_loadOp_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_loadOp_name);

	zval property_storeOp_default_value;
	ZVAL_LONG(&property_storeOp_default_value, 0);
	zend_string *property_storeOp_name = zend_string_init("storeOp", sizeof("storeOp") - 1, 1);
	zend_declare_typed_property(class_entry, property_storeOp_name, &property_storeOp_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_storeOp_name);

	zval property_stencilLoadOp_default_value;
	ZVAL_LONG(&property_stencilLoadOp_default_value, 0);
	zend_string *property_stencilLoadOp_name = zend_string_init("stencilLoadOp", sizeof("stencilLoadOp") - 1, 1);
	zend_declare_typed_property(class_entry, property_stencilLoadOp_name, &property_stencilLoadOp_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_stencilLoadOp_name);

	zval property_stencilStoreOp_default_value;
	ZVAL_LONG(&property_stencilStoreOp_default_value, 0);
	zend_string *property_stencilStoreOp_name = zend_string_init("stencilStoreOp", sizeof("stencilStoreOp") - 1, 1);
	zend_declare_typed_property(class_entry, property_stencilStoreOp_name, &property_stencilStoreOp_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_stencilStoreOp_name);

	zval property_initialLayout_default_value;
	ZVAL_LONG(&property_initialLayout_default_value, 0);
	zend_string *property_initialLayout_name = zend_string_init("initialLayout", sizeof("initialLayout") - 1, 1);
	zend_declare_typed_property(class_entry, property_initialLayout_name, &property_initialLayout_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_initialLayout_name);

	zval property_finalLayout_default_value;
	ZVAL_LONG(&property_finalLayout_default_value, 0);
	zend_string *property_finalLayout_name = zend_string_init("finalLayout", sizeof("finalLayout") - 1, 1);
	zend_declare_typed_property(class_entry, property_finalLayout_name, &property_finalLayout_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_finalLayout_name);

	return class_entry;
}

static zend_class_entry *register_class_VkAttachmentReference(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkAttachmentReference", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_attachment_default_value;
	ZVAL_LONG(&property_attachment_default_value, 0);
	zend_string *property_attachment_name = zend_string_init("attachment", sizeof("attachment") - 1, 1);
	zend_declare_typed_property(class_entry, property_attachment_name, &property_attachment_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_attachment_name);

	zval property_layout_default_value;
	ZVAL_LONG(&property_layout_default_value, 0);
	zend_string *property_layout_name = zend_string_init("layout", sizeof("layout") - 1, 1);
	zend_declare_typed_property(class_entry, property_layout_name, &property_layout_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_layout_name);

	return class_entry;
}

static zend_class_entry *register_class_VkSubpassDescription(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkSubpassDescription", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_flags_default_value;
	ZVAL_LONG(&property_flags_default_value, 0);
	zend_string *property_flags_name = zend_string_init("flags", sizeof("flags") - 1, 1);
	zend_declare_typed_property(class_entry, property_flags_name, &property_flags_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_flags_name);

	zval property_pipelineBindPoint_default_value;
	ZVAL_LONG(&property_pipelineBindPoint_default_value, 0);
	zend_string *property_pipelineBindPoint_name = zend_string_init("pipelineBindPoint", sizeof("pipelineBindPoint") - 1, 1);
	zend_declare_typed_property(class_entry, property_pipelineBindPoint_name, &property_pipelineBindPoint_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_pipelineBindPoint_name);

	zval property_pInputAttachments_default_value;
	ZVAL_EMPTY_ARRAY(&property_pInputAttachments_default_value);
	zend_string *property_pInputAttachments_name = zend_string_init("pInputAttachments", sizeof("pInputAttachments") - 1, 1);
	zend_declare_typed_property(class_entry, property_pInputAttachments_name, &property_pInputAttachments_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_pInputAttachments_name);

	zval property_pColorAttachments_default_value;
	ZVAL_EMPTY_ARRAY(&property_pColorAttachments_default_value);
	zend_string *property_pColorAttachments_name = zend_string_init("pColorAttachments", sizeof("pColorAttachments") - 1, 1);
	zend_declare_typed_property(class_entry, property_pColorAttachments_name, &property_pColorAttachments_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_pColorAttachments_name);

	zval property_pResolveAttachments_default_value;
	ZVAL_EMPTY_ARRAY(&property_pResolveAttachments_default_value);
	zend_string *property_pResolveAttachments_name = zend_string_init("pResolveAttachments", sizeof("pResolveAttachments") - 1, 1);
	zend_declare_typed_property(class_entry, property_pResolveAttachments_name, &property_pResolveAttachments_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_pResolveAttachments_name);

	zval property_pDepthStencilAttachment_default_value;
	ZVAL_NULL(&property_pDepthStencilAttachment_default_value);
	zend_string *property_pDepthStencilAttachment_name = zend_string_init("pDepthStencilAttachment", sizeof("pDepthStencilAttachment") - 1, 1);
	zend_string *property_pDepthStencilAttachment_class_VkAttachmentReference = zend_string_init("VkAttachmentReference", sizeof("VkAttachmentReference")-1, 1);
	zend_declare_typed_property(class_entry, property_pDepthStencilAttachment_name, &property_pDepthStencilAttachment_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_pDepthStencilAttachment_class_VkAttachmentReference, 0, MAY_BE_NULL));
	zend_string_release(property_pDepthStencilAttachment_name);

	zval property_pPreserveAttachments_default_value;
	ZVAL_EMPTY_ARRAY(&property_pPreserveAttachments_default_value);
	zend_string *property_pPreserveAttachments_name = zend_string_init("pPreserveAttachments", sizeof("pPreserveAttachments") - 1, 1);
	zend_declare_typed_property(class_entry, property_pPreserveAttachments_name, &property_pPreserveAttachments_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_pPreserveAttachments_name);

	return class_entry;
}

static zend_class_entry *register_class_VkSubpassDependency(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkSubpassDependency", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_srcSubpass_default_value;
	ZVAL_LONG(&property_srcSubpass_default_value, 0);
	zend_string *property_srcSubpass_name = zend_string_init("srcSubpass", sizeof("srcSubpass") - 1, 1);
	zend_declare_typed_property(class_entry, property_srcSubpass_name, &property_srcSubpass_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_srcSubpass_name);

	zval property_dstSubpass_default_value;
	ZVAL_LONG(&property_dstSubpass_default_value, 0);
	zend_string *property_dstSubpass_name = zend_string_init("dstSubpass", sizeof("dstSubpass") - 1, 1);
	zend_declare_typed_property(class_entry, property_dstSubpass_name, &property_dstSubpass_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_dstSubpass_name);

	zval property_srcStageMask_default_value;
	ZVAL_LONG(&property_srcStageMask_default_value, 0);
	zend_string *property_srcStageMask_name = zend_string_init("srcStageMask", sizeof("srcStageMask") - 1, 1);
	zend_declare_typed_property(class_entry, property_srcStageMask_name, &property_srcStageMask_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_srcStageMask_name);

	zval property_dstStageMask_default_value;
	ZVAL_LONG(&property_dstStageMask_default_value, 0);
	zend_string *property_dstStageMask_name = zend_string_init("dstStageMask", sizeof("dstStageMask") - 1, 1);
	zend_declare_typed_property(class_entry, property_dstStageMask_name, &property_dstStageMask_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_dstStageMask_name);

	zval property_srcAccessMask_default_value;
	ZVAL_LONG(&property_srcAccessMask_default_value, 0);
	zend_string *property_srcAccessMask_name = zend_string_init("srcAccessMask", sizeof("srcAccessMask") - 1, 1);
	zend_declare_typed_property(class_entry, property_srcAccessMask_name, &property_srcAccessMask_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_srcAccessMask_name);

	zval property_dstAccessMask_default_value;
	ZVAL_LONG(&property_dstAccessMask_default_value, 0);
	zend_string *property_dstAccessMask_name = zend_string_init("dstAccessMask", sizeof("dstAccessMask") - 1, 1);
	zend_declare_typed_property(class_entry, property_dstAccessMask_name, &property_dstAccessMask_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_dstAccessMask_name);

	zval property_dependencyFlags_default_value;
	ZVAL_LONG(&property_dependencyFlags_default_value, 0);
	zend_string *property_dependencyFlags_name = zend_string_init("dependencyFlags", sizeof("dependencyFlags") - 1, 1);
	zend_declare_typed_property(class_entry, property_dependencyFlags_name, &property_dependencyFlags_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_dependencyFlags_name);

	return class_entry;
}

static zend_class_entry *register_class_VkRenderPassCreateInfo(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkRenderPassCreateInfo", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_pNext_default_value;
	ZVAL_NULL(&property_pNext_default_value);
	zend_string *property_pNext_name = zend_string_init("pNext", sizeof("pNext") - 1, 1);
	zend_declare_typed_property(class_entry, property_pNext_name, &property_pNext_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_OBJECT|MAY_BE_NULL));
	zend_string_release(property_pNext_name);

	zval property_flags_default_value;
	ZVAL_LONG(&property_flags_default_value, 0);
	zend_string *property_flags_name = zend_string_init("flags", sizeof("flags") - 1, 1);
	zend_declare_typed_property(class_entry, property_flags_name, &property_flags_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_flags_name);

	zval property_pAttachments_default_value;
	ZVAL_EMPTY_ARRAY(&property_pAttachments_default_value);
	zend_string *property_pAttachments_name = zend_string_init("pAttachments", sizeof("pAttachments") - 1, 1);
	zend_declare_typed_property(class_entry, property_pAttachments_name, &property_pAttachments_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_pAttachments_name);

	zval property_pSubpasses_default_value;
	ZVAL_EMPTY_ARRAY(&property_pSubpasses_default_value);
	zend_string *property_pSubpasses_name = zend_string_init("pSubpasses", sizeof("pSubpasses") - 1, 1);
	zend_declare_typed_property(class_entry, property_pSubpasses_name, &property_pSubpasses_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_pSubpasses_name);

	zval property_pDependencies_default_value;
	ZVAL_EMPTY_ARRAY(&property_pDependencies_default_value);
	zend_string *property_pDependencies_name = zend_string_init("pDependencies", sizeof("pDependencies") - 1, 1);
	zend_declare_typed_property(class_entry, property_pDependencies_name, &property_pDependencies_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_pDependencies_name);

	return class_entry;
}

static zend_class_entry *register_class_VkFramebufferCreateInfo(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkFramebufferCreateInfo", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_pNext_default_value;
	ZVAL_NULL(&property_pNext_default_value);
	zend_string *property_pNext_name = zend_string_init("pNext", sizeof("pNext") - 1, 1);
	zend_declare_typed_property(class_entry, property_pNext_name, &property_pNext_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_OBJECT|MAY_BE_NULL));
	zend_string_release(property_pNext_name);

	zval property_flags_default_value;
	ZVAL_LONG(&property_flags_default_value, 0);
	zend_string *property_flags_name = zend_string_init("flags", sizeof("flags") - 1, 1);
	zend_declare_typed_property(class_entry, property_flags_name, &property_flags_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_flags_name);

	zval property_renderPass_default_value;
	ZVAL_NULL(&property_renderPass_default_value);
	zend_string *property_renderPass_name = zend_string_init("renderPass", sizeof("renderPass") - 1, 1);
	zend_string *property_renderPass_class_VkRenderPass = zend_string_init("VkRenderPass", sizeof("VkRenderPass")-1, 1);
	zend_declare_typed_property(class_entry, property_renderPass_name, &property_renderPass_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_renderPass_class_VkRenderPass, 0, MAY_BE_NULL));
	zend_string_release(property_renderPass_name);

	zval property_pAttachments_default_value;
	ZVAL_EMPTY_ARRAY(&property_pAttachments_default_value);
	zend_string *property_pAttachments_name = zend_string_init("pAttachments", sizeof("pAttachments") - 1, 1);
	zend_declare_typed_property(class_entry, property_pAttachments_name, &property_pAttachments_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_pAttachments_name);

	zval property_width_default_value;
	ZVAL_LONG(&property_width_default_value, 0);
	zend_string *property_width_name = zend_string_init("width", sizeof("width") - 1, 1);
	zend_declare_typed_property(class_entry, property_width_name, &property_width_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_width_name);

	zval property_height_default_value;
	ZVAL_LONG(&property_height_default_value, 0);
	zend_string *property_height_name = zend_string_init("height", sizeof("height") - 1, 1);
	zend_declare_typed_property(class_entry, property_height_name, &property_height_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_height_name);

	zval property_layers_default_value;
	ZVAL_LONG(&property_layers_default_value, 0);
	zend_string *property_layers_name = zend_string_init("layers", sizeof("layers") - 1, 1);
	zend_declare_typed_property(class_entry, property_layers_name, &property_layers_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_layers_name);

	return class_entry;
}

static zend_class_entry *register_class_VkShaderModuleCreateInfo(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkShaderModuleCreateInfo", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_pNext_default_value;
	ZVAL_NULL(&property_pNext_default_value);
	zend_string *property_pNext_name = zend_string_init("pNext", sizeof("pNext") - 1, 1);
	zend_declare_typed_property(class_entry, property_pNext_name, &property_pNext_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_OBJECT|MAY_BE_NULL));
	zend_string_release(property_pNext_name);

	zval property_flags_default_value;
	ZVAL_LONG(&property_flags_default_value, 0);
	zend_string *property_flags_name = zend_string_init("flags", sizeof("flags") - 1, 1);
	zend_declare_typed_property(class_entry, property_flags_name, &property_flags_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_flags_name);

	zval property_code_default_value;
	ZVAL_EMPTY_STRING(&property_code_default_value);
	zend_string *property_code_name = zend_string_init("code", sizeof("code") - 1, 1);
	zend_declare_typed_property(class_entry, property_code_name, &property_code_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING));
	zend_string_release(property_code_name);

	return class_entry;
}

static zend_class_entry *register_class_VkPushConstantRange(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkPushConstantRange", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_stageFlags_default_value;
	ZVAL_LONG(&property_stageFlags_default_value, 0);
	zend_string *property_stageFlags_name = zend_string_init("stageFlags", sizeof("stageFlags") - 1, 1);
	zend_declare_typed_property(class_entry, property_stageFlags_name, &property_stageFlags_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_stageFlags_name);

	zval property_offset_default_value;
	ZVAL_LONG(&property_offset_default_value, 0);
	zend_string *property_offset_name = zend_string_init("offset", sizeof("offset") - 1, 1);
	zend_declare_typed_property(class_entry, property_offset_name, &property_offset_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_offset_name);

	zval property_size_default_value;
	ZVAL_LONG(&property_size_default_value, 0);
	zend_string *property_size_name = zend_string_init("size", sizeof("size") - 1, 1);
	zend_declare_typed_property(class_entry, property_size_name, &property_size_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_size_name);

	return class_entry;
}

static zend_class_entry *register_class_VkPipelineLayoutCreateInfo(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkPipelineLayoutCreateInfo", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_pNext_default_value;
	ZVAL_NULL(&property_pNext_default_value);
	zend_string *property_pNext_name = zend_string_init("pNext", sizeof("pNext") - 1, 1);
	zend_declare_typed_property(class_entry, property_pNext_name, &property_pNext_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_OBJECT|MAY_BE_NULL));
	zend_string_release(property_pNext_name);

	zval property_flags_default_value;
	ZVAL_LONG(&property_flags_default_value, 0);
	zend_string *property_flags_name = zend_string_init("flags", sizeof("flags") - 1, 1);
	zend_declare_typed_property(class_entry, property_flags_name, &property_flags_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_flags_name);

	zval property_pSetLayouts_default_value;
	ZVAL_EMPTY_ARRAY(&property_pSetLayouts_default_value);
	zend_string *property_pSetLayouts_name = zend_string_init("pSetLayouts", sizeof("pSetLayouts") - 1, 1);
	zend_declare_typed_property(class_entry, property_pSetLayouts_name, &property_pSetLayouts_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_pSetLayouts_name);

	zval property_pPushConstantRanges_default_value;
	ZVAL_EMPTY_ARRAY(&property_pPushConstantRanges_default_value);
	zend_string *property_pPushConstantRanges_name = zend_string_init("pPushConstantRanges", sizeof("pPushConstantRanges") - 1, 1);
	zend_declare_typed_property(class_entry, property_pPushConstantRanges_name, &property_pPushConstantRanges_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_pPushConstantRanges_name);

	return class_entry;
}

static zend_class_entry *register_class_VkPipelineShaderStageCreateInfo(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkPipelineShaderStageCreateInfo", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_pNext_default_value;
	ZVAL_NULL(&property_pNext_default_value);
	zend_string *property_pNext_name = zend_string_init("pNext", sizeof("pNext") - 1, 1);
	zend_declare_typed_property(class_entry, property_pNext_name, &property_pNext_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_OBJECT|MAY_BE_NULL));
	zend_string_release(property_pNext_name);

	zval property_flags_default_value;
	ZVAL_LONG(&property_flags_default_value, 0);
	zend_string *property_flags_name = zend_string_init("flags", sizeof("flags") - 1, 1);
	zend_declare_typed_property(class_entry, property_flags_name, &property_flags_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_flags_name);

	zval property_stage_default_value;
	ZVAL_LONG(&property_stage_default_value, 0);
	zend_string *property_stage_name = zend_string_init("stage", sizeof("stage") - 1, 1);
	zend_declare_typed_property(class_entry, property_stage_name, &property_stage_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_stage_name);

	zval property_module_default_value;
	ZVAL_NULL(&property_module_default_value);
	zend_string *property_module_name = zend_string_init("module", sizeof("module") - 1, 1);
	zend_string *property_module_class_VkShaderModule = zend_string_init("VkShaderModule", sizeof("VkShaderModule")-1, 1);
	zend_declare_typed_property(class_entry, property_module_name, &property_module_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_module_class_VkShaderModule, 0, MAY_BE_NULL));
	zend_string_release(property_module_name);

	zval property_pName_default_value;
	ZVAL_NULL(&property_pName_default_value);
	zend_string *property_pName_name = zend_string_init("pName", sizeof("pName") - 1, 1);
	zend_declare_typed_property(class_entry, property_pName_name, &property_pName_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING|MAY_BE_NULL));
	zend_string_release(property_pName_name);

	return class_entry;
}

static zend_class_entry *register_class_VkVertexInputBindingDescription(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkVertexInputBindingDescription", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_binding_default_value;
	ZVAL_LONG(&property_binding_default_value, 0);
	zend_string *property_binding_name = zend_string_init("binding", sizeof("binding") - 1, 1);
	zend_declare_typed_property(class_entry, property_binding_name, &property_binding_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_binding_name);

	zval property_stride_default_value;
	ZVAL_LONG(&property_stride_default_value, 0);
	zend_string *property_stride_name = zend_string_init("stride", sizeof("stride") - 1, 1);
	zend_declare_typed_property(class_entry, property_stride_name, &property_stride_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_stride_name);

	zval property_inputRate_default_value;
	ZVAL_LONG(&property_inputRate_default_value, 0);
	zend_string *property_inputRate_name = zend_string_init("inputRate", sizeof("inputRate") - 1, 1);
	zend_declare_typed_property(class_entry, property_inputRate_name, &property_inputRate_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_inputRate_name);

	return class_entry;
}

static zend_class_entry *register_class_VkVertexInputAttributeDescription(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkVertexInputAttributeDescription", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_location_default_value;
	ZVAL_LONG(&property_location_default_value, 0);
	zend_string *property_location_name = zend_string_init("location", sizeof("location") - 1, 1);
	zend_declare_typed_property(class_entry, property_location_name, &property_location_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_location_name);

	zval property_binding_default_value;
	ZVAL_LONG(&property_binding_default_value, 0);
	zend_string *property_binding_name = zend_string_init("binding", sizeof("binding") - 1, 1);
	zend_declare_typed_property(class_entry, property_binding_name, &property_binding_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_binding_name);

	zval property_format_default_value;
	ZVAL_LONG(&property_format_default_value, 0);
	zend_string *property_format_name = zend_string_init("format", sizeof("format") - 1, 1);
	zend_declare_typed_property(class_entry, property_format_name, &property_format_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_format_name);

	zval property_offset_default_value;
	ZVAL_LONG(&property_offset_default_value, 0);
	zend_string *property_offset_name = zend_string_init("offset", sizeof("offset") - 1, 1);
	zend_declare_typed_property(class_entry, property_offset_name, &property_offset_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_offset_name);

	return class_entry;
}

static zend_class_entry *register_class_VkPipelineVertexInputStateCreateInfo(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkPipelineVertexInputStateCreateInfo", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_pNext_default_value;
	ZVAL_NULL(&property_pNext_default_value);
	zend_string *property_pNext_name = zend_string_init("pNext", sizeof("pNext") - 1, 1);
	zend_declare_typed_property(class_entry, property_pNext_name, &property_pNext_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_OBJECT|MAY_BE_NULL));
	zend_string_release(property_pNext_name);

	zval property_flags_default_value;
	ZVAL_LONG(&property_flags_default_value, 0);
	zend_string *property_flags_name = zend_string_init("flags", sizeof("flags") - 1, 1);
	zend_declare_typed_property(class_entry, property_flags_name, &property_flags_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_flags_name);

	zval property_pVertexBindingDescriptions_default_value;
	ZVAL_EMPTY_ARRAY(&property_pVertexBindingDescriptions_default_value);
	zend_string *property_pVertexBindingDescriptions_name = zend_string_init("pVertexBindingDescriptions", sizeof("pVertexBindingDescriptions") - 1, 1);
	zend_declare_typed_property(class_entry, property_pVertexBindingDescriptions_name, &property_pVertexBindingDescriptions_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_pVertexBindingDescriptions_name);

	zval property_pVertexAttributeDescriptions_default_value;
	ZVAL_EMPTY_ARRAY(&property_pVertexAttributeDescriptions_default_value);
	zend_string *property_pVertexAttributeDescriptions_name = zend_string_init("pVertexAttributeDescriptions", sizeof("pVertexAttributeDescriptions") - 1, 1);
	zend_declare_typed_property(class_entry, property_pVertexAttributeDescriptions_name, &property_pVertexAttributeDescriptions_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_pVertexAttributeDescriptions_name);

	return class_entry;
}

static zend_class_entry *register_class_VkPipelineInputAssemblyStateCreateInfo(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkPipelineInputAssemblyStateCreateInfo", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_pNext_default_value;
	ZVAL_NULL(&property_pNext_default_value);
	zend_string *property_pNext_name = zend_string_init("pNext", sizeof("pNext") - 1, 1);
	zend_declare_typed_property(class_entry, property_pNext_name, &property_pNext_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_OBJECT|MAY_BE_NULL));
	zend_string_release(property_pNext_name);

	zval property_flags_default_value;
	ZVAL_LONG(&property_flags_default_value, 0);
	zend_string *property_flags_name = zend_string_init("flags", sizeof("flags") - 1, 1);
	zend_declare_typed_property(class_entry, property_flags_name, &property_flags_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_flags_name);

	zval property_topology_default_value;
	ZVAL_LONG(&property_topology_default_value, 0);
	zend_string *property_topology_name = zend_string_init("topology", sizeof("topology") - 1, 1);
	zend_declare_typed_property(class_entry, property_topology_name, &property_topology_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_topology_name);

	zval property_primitiveRestartEnable_default_value;
	ZVAL_LONG(&property_primitiveRestartEnable_default_value, 0);
	zend_string *property_primitiveRestartEnable_name = zend_string_init("primitiveRestartEnable", sizeof("primitiveRestartEnable") - 1, 1);
	zend_declare_typed_property(class_entry, property_primitiveRestartEnable_name, &property_primitiveRestartEnable_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_primitiveRestartEnable_name);

	return class_entry;
}

static zend_class_entry *register_class_VkPipelineViewportStateCreateInfo(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkPipelineViewportStateCreateInfo", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_pNext_default_value;
	ZVAL_NULL(&property_pNext_default_value);
	zend_string *property_pNext_name = zend_string_init("pNext", sizeof("pNext") - 1, 1);
	zend_declare_typed_property(class_entry, property_pNext_name, &property_pNext_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_OBJECT|MAY_BE_NULL));
	zend_string_release(property_pNext_name);

	zval property_flags_default_value;
	ZVAL_LONG(&property_flags_default_value, 0);
	zend_string *property_flags_name = zend_string_init("flags", sizeof("flags") - 1, 1);
	zend_declare_typed_property(class_entry, property_flags_name, &property_flags_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_flags_name);

	zval property_viewportCount_default_value;
	ZVAL_LONG(&property_viewportCount_default_value, 0);
	zend_string *property_viewportCount_name = zend_string_init("viewportCount", sizeof("viewportCount") - 1, 1);
	zend_declare_typed_property(class_entry, property_viewportCount_name, &property_viewportCount_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_viewportCount_name);

	zval property_pViewports_default_value;
	ZVAL_EMPTY_ARRAY(&property_pViewports_default_value);
	zend_string *property_pViewports_name = zend_string_init("pViewports", sizeof("pViewports") - 1, 1);
	zend_declare_typed_property(class_entry, property_pViewports_name, &property_pViewports_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_pViewports_name);

	zval property_scissorCount_default_value;
	ZVAL_LONG(&property_scissorCount_default_value, 0);
	zend_string *property_scissorCount_name = zend_string_init("scissorCount", sizeof("scissorCount") - 1, 1);
	zend_declare_typed_property(class_entry, property_scissorCount_name, &property_scissorCount_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_scissorCount_name);

	zval property_pScissors_default_value;
	ZVAL_EMPTY_ARRAY(&property_pScissors_default_value);
	zend_string *property_pScissors_name = zend_string_init("pScissors", sizeof("pScissors") - 1, 1);
	zend_declare_typed_property(class_entry, property_pScissors_name, &property_pScissors_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_pScissors_name);

	return class_entry;
}

static zend_class_entry *register_class_VkPipelineRasterizationStateCreateInfo(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkPipelineRasterizationStateCreateInfo", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_pNext_default_value;
	ZVAL_NULL(&property_pNext_default_value);
	zend_string *property_pNext_name = zend_string_init("pNext", sizeof("pNext") - 1, 1);
	zend_declare_typed_property(class_entry, property_pNext_name, &property_pNext_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_OBJECT|MAY_BE_NULL));
	zend_string_release(property_pNext_name);

	zval property_flags_default_value;
	ZVAL_LONG(&property_flags_default_value, 0);
	zend_string *property_flags_name = zend_string_init("flags", sizeof("flags") - 1, 1);
	zend_declare_typed_property(class_entry, property_flags_name, &property_flags_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_flags_name);

	zval property_depthClampEnable_default_value;
	ZVAL_LONG(&property_depthClampEnable_default_value, 0);
	zend_string *property_depthClampEnable_name = zend_string_init("depthClampEnable", sizeof("depthClampEnable") - 1, 1);
	zend_declare_typed_property(class_entry, property_depthClampEnable_name, &property_depthClampEnable_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_depthClampEnable_name);

	zval property_rasterizerDiscardEnable_default_value;
	ZVAL_LONG(&property_rasterizerDiscardEnable_default_value, 0);
	zend_string *property_rasterizerDiscardEnable_name = zend_string_init("rasterizerDiscardEnable", sizeof("rasterizerDiscardEnable") - 1, 1);
	zend_declare_typed_property(class_entry, property_rasterizerDiscardEnable_name, &property_rasterizerDiscardEnable_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_rasterizerDiscardEnable_name);

	zval property_polygonMode_default_value;
	ZVAL_LONG(&property_polygonMode_default_value, 0);
	zend_string *property_polygonMode_name = zend_string_init("polygonMode", sizeof("polygonMode") - 1, 1);
	zend_declare_typed_property(class_entry, property_polygonMode_name, &property_polygonMode_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_polygonMode_name);

	zval property_cullMode_default_value;
	ZVAL_LONG(&property_cullMode_default_value, 0);
	zend_string *property_cullMode_name = zend_string_init("cullMode", sizeof("cullMode") - 1, 1);
	zend_declare_typed_property(class_entry, property_cullMode_name, &property_cullMode_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_cullMode_name);

	zval property_frontFace_default_value;
	ZVAL_LONG(&property_frontFace_default_value, 0);
	zend_string *property_frontFace_name = zend_string_init("frontFace", sizeof("frontFace") - 1, 1);
	zend_declare_typed_property(class_entry, property_frontFace_name, &property_frontFace_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_frontFace_name);

	zval property_depthBiasEnable_default_value;
	ZVAL_LONG(&property_depthBiasEnable_default_value, 0);
	zend_string *property_depthBiasEnable_name = zend_string_init("depthBiasEnable", sizeof("depthBiasEnable") - 1, 1);
	zend_declare_typed_property(class_entry, property_depthBiasEnable_name, &property_depthBiasEnable_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_depthBiasEnable_name);

	zval property_depthBiasConstantFactor_default_value;
	ZVAL_DOUBLE(&property_depthBiasConstantFactor_default_value, 0.0);
	zend_string *property_depthBiasConstantFactor_name = zend_string_init("depthBiasConstantFactor", sizeof("depthBiasConstantFactor") - 1, 1);
	zend_declare_typed_property(class_entry, property_depthBiasConstantFactor_name, &property_depthBiasConstantFactor_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_depthBiasConstantFactor_name);

	zval property_depthBiasClamp_default_value;
	ZVAL_DOUBLE(&property_depthBiasClamp_default_value, 0.0);
	zend_string *property_depthBiasClamp_name = zend_string_init("depthBiasClamp", sizeof("depthBiasClamp") - 1, 1);
	zend_declare_typed_property(class_entry, property_depthBiasClamp_name, &property_depthBiasClamp_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_depthBiasClamp_name);

	zval property_depthBiasSlopeFactor_default_value;
	ZVAL_DOUBLE(&property_depthBiasSlopeFactor_default_value, 0.0);
	zend_string *property_depthBiasSlopeFactor_name = zend_string_init("depthBiasSlopeFactor", sizeof("depthBiasSlopeFactor") - 1, 1);
	zend_declare_typed_property(class_entry, property_depthBiasSlopeFactor_name, &property_depthBiasSlopeFactor_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_depthBiasSlopeFactor_name);

	zval property_lineWidth_default_value;
	ZVAL_DOUBLE(&property_lineWidth_default_value, 0.0);
	zend_string *property_lineWidth_name = zend_string_init("lineWidth", sizeof("lineWidth") - 1, 1);
	zend_declare_typed_property(class_entry, property_lineWidth_name, &property_lineWidth_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_lineWidth_name);

	return class_entry;
}

static zend_class_entry *register_class_VkPipelineMultisampleStateCreateInfo(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkPipelineMultisampleStateCreateInfo", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_pNext_default_value;
	ZVAL_NULL(&property_pNext_default_value);
	zend_string *property_pNext_name = zend_string_init("pNext", sizeof("pNext") - 1, 1);
	zend_declare_typed_property(class_entry, property_pNext_name, &property_pNext_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_OBJECT|MAY_BE_NULL));
	zend_string_release(property_pNext_name);

	zval property_flags_default_value;
	ZVAL_LONG(&property_flags_default_value, 0);
	zend_string *property_flags_name = zend_string_init("flags", sizeof("flags") - 1, 1);
	zend_declare_typed_property(class_entry, property_flags_name, &property_flags_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_flags_name);

	zval property_rasterizationSamples_default_value;
	ZVAL_LONG(&property_rasterizationSamples_default_value, 0);
	zend_string *property_rasterizationSamples_name = zend_string_init("rasterizationSamples", sizeof("rasterizationSamples") - 1, 1);
	zend_declare_typed_property(class_entry, property_rasterizationSamples_name, &property_rasterizationSamples_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_rasterizationSamples_name);

	zval property_sampleShadingEnable_default_value;
	ZVAL_LONG(&property_sampleShadingEnable_default_value, 0);
	zend_string *property_sampleShadingEnable_name = zend_string_init("sampleShadingEnable", sizeof("sampleShadingEnable") - 1, 1);
	zend_declare_typed_property(class_entry, property_sampleShadingEnable_name, &property_sampleShadingEnable_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_sampleShadingEnable_name);

	zval property_minSampleShading_default_value;
	ZVAL_DOUBLE(&property_minSampleShading_default_value, 0.0);
	zend_string *property_minSampleShading_name = zend_string_init("minSampleShading", sizeof("minSampleShading") - 1, 1);
	zend_declare_typed_property(class_entry, property_minSampleShading_name, &property_minSampleShading_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_minSampleShading_name);

	zval property_pSampleMask_default_value;
	ZVAL_EMPTY_ARRAY(&property_pSampleMask_default_value);
	zend_string *property_pSampleMask_name = zend_string_init("pSampleMask", sizeof("pSampleMask") - 1, 1);
	zend_declare_typed_property(class_entry, property_pSampleMask_name, &property_pSampleMask_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_pSampleMask_name);

	zval property_alphaToCoverageEnable_default_value;
	ZVAL_LONG(&property_alphaToCoverageEnable_default_value, 0);
	zend_string *property_alphaToCoverageEnable_name = zend_string_init("alphaToCoverageEnable", sizeof("alphaToCoverageEnable") - 1, 1);
	zend_declare_typed_property(class_entry, property_alphaToCoverageEnable_name, &property_alphaToCoverageEnable_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_alphaToCoverageEnable_name);

	zval property_alphaToOneEnable_default_value;
	ZVAL_LONG(&property_alphaToOneEnable_default_value, 0);
	zend_string *property_alphaToOneEnable_name = zend_string_init("alphaToOneEnable", sizeof("alphaToOneEnable") - 1, 1);
	zend_declare_typed_property(class_entry, property_alphaToOneEnable_name, &property_alphaToOneEnable_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_alphaToOneEnable_name);

	return class_entry;
}

static zend_class_entry *register_class_VkStencilOpState(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkStencilOpState", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_failOp_default_value;
	ZVAL_LONG(&property_failOp_default_value, 0);
	zend_string *property_failOp_name = zend_string_init("failOp", sizeof("failOp") - 1, 1);
	zend_declare_typed_property(class_entry, property_failOp_name, &property_failOp_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_failOp_name);

	zval property_passOp_default_value;
	ZVAL_LONG(&property_passOp_default_value, 0);
	zend_string *property_passOp_name = zend_string_init("passOp", sizeof("passOp") - 1, 1);
	zend_declare_typed_property(class_entry, property_passOp_name, &property_passOp_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_passOp_name);

	zval property_depthFailOp_default_value;
	ZVAL_LONG(&property_depthFailOp_default_value, 0);
	zend_string *property_depthFailOp_name = zend_string_init("depthFailOp", sizeof("depthFailOp") - 1, 1);
	zend_declare_typed_property(class_entry, property_depthFailOp_name, &property_depthFailOp_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_depthFailOp_name);

	zval property_compareOp_default_value;
	ZVAL_LONG(&property_compareOp_default_value, 0);
	zend_string *property_compareOp_name = zend_string_init("compareOp", sizeof("compareOp") - 1, 1);
	zend_declare_typed_property(class_entry, property_compareOp_name, &property_compareOp_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_compareOp_name);

	zval property_compareMask_default_value;
	ZVAL_LONG(&property_compareMask_default_value, 0);
	zend_string *property_compareMask_name = zend_string_init("compareMask", sizeof("compareMask") - 1, 1);
	zend_declare_typed_property(class_entry, property_compareMask_name, &property_compareMask_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_compareMask_name);

	zval property_writeMask_default_value;
	ZVAL_LONG(&property_writeMask_default_value, 0);
	zend_string *property_writeMask_name = zend_string_init("writeMask", sizeof("writeMask") - 1, 1);
	zend_declare_typed_property(class_entry, property_writeMask_name, &property_writeMask_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_writeMask_name);

	zval property_reference_default_value;
	ZVAL_LONG(&property_reference_default_value, 0);
	zend_string *property_reference_name = zend_string_init("reference", sizeof("reference") - 1, 1);
	zend_declare_typed_property(class_entry, property_reference_name, &property_reference_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_reference_name);

	return class_entry;
}

static zend_class_entry *register_class_VkPipelineDepthStencilStateCreateInfo(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkPipelineDepthStencilStateCreateInfo", class_VkPipelineDepthStencilStateCreateInfo_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_pNext_default_value;
	ZVAL_NULL(&property_pNext_default_value);
	zend_string *property_pNext_name = zend_string_init("pNext", sizeof("pNext") - 1, 1);
	zend_declare_typed_property(class_entry, property_pNext_name, &property_pNext_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_OBJECT|MAY_BE_NULL));
	zend_string_release(property_pNext_name);

	zval property_flags_default_value;
	ZVAL_LONG(&property_flags_default_value, 0);
	zend_string *property_flags_name = zend_string_init("flags", sizeof("flags") - 1, 1);
	zend_declare_typed_property(class_entry, property_flags_name, &property_flags_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_flags_name);

	zval property_depthTestEnable_default_value;
	ZVAL_LONG(&property_depthTestEnable_default_value, 0);
	zend_string *property_depthTestEnable_name = zend_string_init("depthTestEnable", sizeof("depthTestEnable") - 1, 1);
	zend_declare_typed_property(class_entry, property_depthTestEnable_name, &property_depthTestEnable_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_depthTestEnable_name);

	zval property_depthWriteEnable_default_value;
	ZVAL_LONG(&property_depthWriteEnable_default_value, 0);
	zend_string *property_depthWriteEnable_name = zend_string_init("depthWriteEnable", sizeof("depthWriteEnable") - 1, 1);
	zend_declare_typed_property(class_entry, property_depthWriteEnable_name, &property_depthWriteEnable_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_depthWriteEnable_name);

	zval property_depthCompareOp_default_value;
	ZVAL_LONG(&property_depthCompareOp_default_value, 0);
	zend_string *property_depthCompareOp_name = zend_string_init("depthCompareOp", sizeof("depthCompareOp") - 1, 1);
	zend_declare_typed_property(class_entry, property_depthCompareOp_name, &property_depthCompareOp_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_depthCompareOp_name);

	zval property_depthBoundsTestEnable_default_value;
	ZVAL_LONG(&property_depthBoundsTestEnable_default_value, 0);
	zend_string *property_depthBoundsTestEnable_name = zend_string_init("depthBoundsTestEnable", sizeof("depthBoundsTestEnable") - 1, 1);
	zend_declare_typed_property(class_entry, property_depthBoundsTestEnable_name, &property_depthBoundsTestEnable_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_depthBoundsTestEnable_name);

	zval property_stencilTestEnable_default_value;
	ZVAL_LONG(&property_stencilTestEnable_default_value, 0);
	zend_string *property_stencilTestEnable_name = zend_string_init("stencilTestEnable", sizeof("stencilTestEnable") - 1, 1);
	zend_declare_typed_property(class_entry, property_stencilTestEnable_name, &property_stencilTestEnable_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_stencilTestEnable_name);

	zval property_front_default_value;
	ZVAL_UNDEF(&property_front_default_value);
	zend_string *property_front_name = zend_string_init("front", sizeof("front") - 1, 1);
	zend_string *property_front_class_VkStencilOpState = zend_string_init("VkStencilOpState", sizeof("VkStencilOpState")-1, 1);
	zend_declare_typed_property(class_entry, property_front_name, &property_front_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_front_class_VkStencilOpState, 0, 0));
	zend_string_release(property_front_name);

	zval property_back_default_value;
	ZVAL_UNDEF(&property_back_default_value);
	zend_string *property_back_name = zend_string_init("back", sizeof("back") - 1, 1);
	zend_string *property_back_class_VkStencilOpState = zend_string_init("VkStencilOpState", sizeof("VkStencilOpState")-1, 1);
	zend_declare_typed_property(class_entry, property_back_name, &property_back_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_back_class_VkStencilOpState, 0, 0));
	zend_string_release(property_back_name);

	zval property_minDepthBounds_default_value;
	ZVAL_DOUBLE(&property_minDepthBounds_default_value, 0.0);
	zend_string *property_minDepthBounds_name = zend_string_init("minDepthBounds", sizeof("minDepthBounds") - 1, 1);
	zend_declare_typed_property(class_entry, property_minDepthBounds_name, &property_minDepthBounds_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_minDepthBounds_name);

	zval property_maxDepthBounds_default_value;
	ZVAL_DOUBLE(&property_maxDepthBounds_default_value, 0.0);
	zend_string *property_maxDepthBounds_name = zend_string_init("maxDepthBounds", sizeof("maxDepthBounds") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxDepthBounds_name, &property_maxDepthBounds_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_maxDepthBounds_name);

	return class_entry;
}

static zend_class_entry *register_class_VkPipelineColorBlendAttachmentState(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkPipelineColorBlendAttachmentState", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_blendEnable_default_value;
	ZVAL_LONG(&property_blendEnable_default_value, 0);
	zend_string *property_blendEnable_name = zend_string_init("blendEnable", sizeof("blendEnable") - 1, 1);
	zend_declare_typed_property(class_entry, property_blendEnable_name, &property_blendEnable_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_blendEnable_name);

	zval property_srcColorBlendFactor_default_value;
	ZVAL_LONG(&property_srcColorBlendFactor_default_value, 0);
	zend_string *property_srcColorBlendFactor_name = zend_string_init("srcColorBlendFactor", sizeof("srcColorBlendFactor") - 1, 1);
	zend_declare_typed_property(class_entry, property_srcColorBlendFactor_name, &property_srcColorBlendFactor_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_srcColorBlendFactor_name);

	zval property_dstColorBlendFactor_default_value;
	ZVAL_LONG(&property_dstColorBlendFactor_default_value, 0);
	zend_string *property_dstColorBlendFactor_name = zend_string_init("dstColorBlendFactor", sizeof("dstColorBlendFactor") - 1, 1);
	zend_declare_typed_property(class_entry, property_dstColorBlendFactor_name, &property_dstColorBlendFactor_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_dstColorBlendFactor_name);

	zval property_colorBlendOp_default_value;
	ZVAL_LONG(&property_colorBlendOp_default_value, 0);
	zend_string *property_colorBlendOp_name = zend_string_init("colorBlendOp", sizeof("colorBlendOp") - 1, 1);
	zend_declare_typed_property(class_entry, property_colorBlendOp_name, &property_colorBlendOp_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_colorBlendOp_name);

	zval property_srcAlphaBlendFactor_default_value;
	ZVAL_LONG(&property_srcAlphaBlendFactor_default_value, 0);
	zend_string *property_srcAlphaBlendFactor_name = zend_string_init("srcAlphaBlendFactor", sizeof("srcAlphaBlendFactor") - 1, 1);
	zend_declare_typed_property(class_entry, property_srcAlphaBlendFactor_name, &property_srcAlphaBlendFactor_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_srcAlphaBlendFactor_name);

	zval property_dstAlphaBlendFactor_default_value;
	ZVAL_LONG(&property_dstAlphaBlendFactor_default_value, 0);
	zend_string *property_dstAlphaBlendFactor_name = zend_string_init("dstAlphaBlendFactor", sizeof("dstAlphaBlendFactor") - 1, 1);
	zend_declare_typed_property(class_entry, property_dstAlphaBlendFactor_name, &property_dstAlphaBlendFactor_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_dstAlphaBlendFactor_name);

	zval property_alphaBlendOp_default_value;
	ZVAL_LONG(&property_alphaBlendOp_default_value, 0);
	zend_string *property_alphaBlendOp_name = zend_string_init("alphaBlendOp", sizeof("alphaBlendOp") - 1, 1);
	zend_declare_typed_property(class_entry, property_alphaBlendOp_name, &property_alphaBlendOp_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_alphaBlendOp_name);

	zval property_colorWriteMask_default_value;
	ZVAL_LONG(&property_colorWriteMask_default_value, 0);
	zend_string *property_colorWriteMask_name = zend_string_init("colorWriteMask", sizeof("colorWriteMask") - 1, 1);
	zend_declare_typed_property(class_entry, property_colorWriteMask_name, &property_colorWriteMask_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_colorWriteMask_name);

	return class_entry;
}

static zend_class_entry *register_class_VkPipelineColorBlendStateCreateInfo(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkPipelineColorBlendStateCreateInfo", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_pNext_default_value;
	ZVAL_NULL(&property_pNext_default_value);
	zend_string *property_pNext_name = zend_string_init("pNext", sizeof("pNext") - 1, 1);
	zend_declare_typed_property(class_entry, property_pNext_name, &property_pNext_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_OBJECT|MAY_BE_NULL));
	zend_string_release(property_pNext_name);

	zval property_flags_default_value;
	ZVAL_LONG(&property_flags_default_value, 0);
	zend_string *property_flags_name = zend_string_init("flags", sizeof("flags") - 1, 1);
	zend_declare_typed_property(class_entry, property_flags_name, &property_flags_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_flags_name);

	zval property_logicOpEnable_default_value;
	ZVAL_LONG(&property_logicOpEnable_default_value, 0);
	zend_string *property_logicOpEnable_name = zend_string_init("logicOpEnable", sizeof("logicOpEnable") - 1, 1);
	zend_declare_typed_property(class_entry, property_logicOpEnable_name, &property_logicOpEnable_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_logicOpEnable_name);

	zval property_logicOp_default_value;
	ZVAL_LONG(&property_logicOp_default_value, 0);
	zend_string *property_logicOp_name = zend_string_init("logicOp", sizeof("logicOp") - 1, 1);
	zend_declare_typed_property(class_entry, property_logicOp_name, &property_logicOp_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_logicOp_name);

	zval property_pAttachments_default_value;
	ZVAL_EMPTY_ARRAY(&property_pAttachments_default_value);
	zend_string *property_pAttachments_name = zend_string_init("pAttachments", sizeof("pAttachments") - 1, 1);
	zend_declare_typed_property(class_entry, property_pAttachments_name, &property_pAttachments_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_pAttachments_name);

	zval property_blendConstants_default_value;
	ZVAL_EMPTY_ARRAY(&property_blendConstants_default_value);
	zend_string *property_blendConstants_name = zend_string_init("blendConstants", sizeof("blendConstants") - 1, 1);
	zend_declare_typed_property(class_entry, property_blendConstants_name, &property_blendConstants_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_blendConstants_name);

	return class_entry;
}

static zend_class_entry *register_class_VkPipelineDynamicStateCreateInfo(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkPipelineDynamicStateCreateInfo", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_pNext_default_value;
	ZVAL_NULL(&property_pNext_default_value);
	zend_string *property_pNext_name = zend_string_init("pNext", sizeof("pNext") - 1, 1);
	zend_declare_typed_property(class_entry, property_pNext_name, &property_pNext_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_OBJECT|MAY_BE_NULL));
	zend_string_release(property_pNext_name);

	zval property_flags_default_value;
	ZVAL_LONG(&property_flags_default_value, 0);
	zend_string *property_flags_name = zend_string_init("flags", sizeof("flags") - 1, 1);
	zend_declare_typed_property(class_entry, property_flags_name, &property_flags_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_flags_name);

	zval property_pDynamicStates_default_value;
	ZVAL_EMPTY_ARRAY(&property_pDynamicStates_default_value);
	zend_string *property_pDynamicStates_name = zend_string_init("pDynamicStates", sizeof("pDynamicStates") - 1, 1);
	zend_declare_typed_property(class_entry, property_pDynamicStates_name, &property_pDynamicStates_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_pDynamicStates_name);

	return class_entry;
}

static zend_class_entry *register_class_VkPipelineTessellationStateCreateInfo(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkPipelineTessellationStateCreateInfo", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_pNext_default_value;
	ZVAL_NULL(&property_pNext_default_value);
	zend_string *property_pNext_name = zend_string_init("pNext", sizeof("pNext") - 1, 1);
	zend_declare_typed_property(class_entry, property_pNext_name, &property_pNext_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_OBJECT|MAY_BE_NULL));
	zend_string_release(property_pNext_name);

	zval property_flags_default_value;
	ZVAL_LONG(&property_flags_default_value, 0);
	zend_string *property_flags_name = zend_string_init("flags", sizeof("flags") - 1, 1);
	zend_declare_typed_property(class_entry, property_flags_name, &property_flags_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_flags_name);

	zval property_patchControlPoints_default_value;
	ZVAL_LONG(&property_patchControlPoints_default_value, 0);
	zend_string *property_patchControlPoints_name = zend_string_init("patchControlPoints", sizeof("patchControlPoints") - 1, 1);
	zend_declare_typed_property(class_entry, property_patchControlPoints_name, &property_patchControlPoints_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_patchControlPoints_name);

	return class_entry;
}

static zend_class_entry *register_class_VkGraphicsPipelineCreateInfo(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkGraphicsPipelineCreateInfo", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_pNext_default_value;
	ZVAL_NULL(&property_pNext_default_value);
	zend_string *property_pNext_name = zend_string_init("pNext", sizeof("pNext") - 1, 1);
	zend_declare_typed_property(class_entry, property_pNext_name, &property_pNext_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_OBJECT|MAY_BE_NULL));
	zend_string_release(property_pNext_name);

	zval property_flags_default_value;
	ZVAL_LONG(&property_flags_default_value, 0);
	zend_string *property_flags_name = zend_string_init("flags", sizeof("flags") - 1, 1);
	zend_declare_typed_property(class_entry, property_flags_name, &property_flags_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_flags_name);

	zval property_pStages_default_value;
	ZVAL_EMPTY_ARRAY(&property_pStages_default_value);
	zend_string *property_pStages_name = zend_string_init("pStages", sizeof("pStages") - 1, 1);
	zend_declare_typed_property(class_entry, property_pStages_name, &property_pStages_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_pStages_name);

	zval property_pVertexInputState_default_value;
	ZVAL_NULL(&property_pVertexInputState_default_value);
	zend_string *property_pVertexInputState_name = zend_string_init("pVertexInputState", sizeof("pVertexInputState") - 1, 1);
	zend_string *property_pVertexInputState_class_VkPipelineVertexInputStateCreateInfo = zend_string_init("VkPipelineVertexInputStateCreateInfo", sizeof("VkPipelineVertexInputStateCreateInfo")-1, 1);
	zend_declare_typed_property(class_entry, property_pVertexInputState_name, &property_pVertexInputState_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_pVertexInputState_class_VkPipelineVertexInputStateCreateInfo, 0, MAY_BE_NULL));
	zend_string_release(property_pVertexInputState_name);

	zval property_pInputAssemblyState_default_value;
	ZVAL_NULL(&property_pInputAssemblyState_default_value);
	zend_string *property_pInputAssemblyState_name = zend_string_init("pInputAssemblyState", sizeof("pInputAssemblyState") - 1, 1);
	zend_string *property_pInputAssemblyState_class_VkPipelineInputAssemblyStateCreateInfo = zend_string_init("VkPipelineInputAssemblyStateCreateInfo", sizeof("VkPipelineInputAssemblyStateCreateInfo")-1, 1);
	zend_declare_typed_property(class_entry, property_pInputAssemblyState_name, &property_pInputAssemblyState_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_pInputAssemblyState_class_VkPipelineInputAssemblyStateCreateInfo, 0, MAY_BE_NULL));
	zend_string_release(property_pInputAssemblyState_name);

	zval property_pTessellationState_default_value;
	ZVAL_NULL(&property_pTessellationState_default_value);
	zend_string *property_pTessellationState_name = zend_string_init("pTessellationState", sizeof("pTessellationState") - 1, 1);
	zend_string *property_pTessellationState_class_VkPipelineTessellationStateCreateInfo = zend_string_init("VkPipelineTessellationStateCreateInfo", sizeof("VkPipelineTessellationStateCreateInfo")-1, 1);
	zend_declare_typed_property(class_entry, property_pTessellationState_name, &property_pTessellationState_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_pTessellationState_class_VkPipelineTessellationStateCreateInfo, 0, MAY_BE_NULL));
	zend_string_release(property_pTessellationState_name);

	zval property_pViewportState_default_value;
	ZVAL_NULL(&property_pViewportState_default_value);
	zend_string *property_pViewportState_name = zend_string_init("pViewportState", sizeof("pViewportState") - 1, 1);
	zend_string *property_pViewportState_class_VkPipelineViewportStateCreateInfo = zend_string_init("VkPipelineViewportStateCreateInfo", sizeof("VkPipelineViewportStateCreateInfo")-1, 1);
	zend_declare_typed_property(class_entry, property_pViewportState_name, &property_pViewportState_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_pViewportState_class_VkPipelineViewportStateCreateInfo, 0, MAY_BE_NULL));
	zend_string_release(property_pViewportState_name);

	zval property_pRasterizationState_default_value;
	ZVAL_NULL(&property_pRasterizationState_default_value);
	zend_string *property_pRasterizationState_name = zend_string_init("pRasterizationState", sizeof("pRasterizationState") - 1, 1);
	zend_string *property_pRasterizationState_class_VkPipelineRasterizationStateCreateInfo = zend_string_init("VkPipelineRasterizationStateCreateInfo", sizeof("VkPipelineRasterizationStateCreateInfo")-1, 1);
	zend_declare_typed_property(class_entry, property_pRasterizationState_name, &property_pRasterizationState_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_pRasterizationState_class_VkPipelineRasterizationStateCreateInfo, 0, MAY_BE_NULL));
	zend_string_release(property_pRasterizationState_name);

	zval property_pMultisampleState_default_value;
	ZVAL_NULL(&property_pMultisampleState_default_value);
	zend_string *property_pMultisampleState_name = zend_string_init("pMultisampleState", sizeof("pMultisampleState") - 1, 1);
	zend_string *property_pMultisampleState_class_VkPipelineMultisampleStateCreateInfo = zend_string_init("VkPipelineMultisampleStateCreateInfo", sizeof("VkPipelineMultisampleStateCreateInfo")-1, 1);
	zend_declare_typed_property(class_entry, property_pMultisampleState_name, &property_pMultisampleState_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_pMultisampleState_class_VkPipelineMultisampleStateCreateInfo, 0, MAY_BE_NULL));
	zend_string_release(property_pMultisampleState_name);

	zval property_pDepthStencilState_default_value;
	ZVAL_NULL(&property_pDepthStencilState_default_value);
	zend_string *property_pDepthStencilState_name = zend_string_init("pDepthStencilState", sizeof("pDepthStencilState") - 1, 1);
	zend_string *property_pDepthStencilState_class_VkPipelineDepthStencilStateCreateInfo = zend_string_init("VkPipelineDepthStencilStateCreateInfo", sizeof("VkPipelineDepthStencilStateCreateInfo")-1, 1);
	zend_declare_typed_property(class_entry, property_pDepthStencilState_name, &property_pDepthStencilState_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_pDepthStencilState_class_VkPipelineDepthStencilStateCreateInfo, 0, MAY_BE_NULL));
	zend_string_release(property_pDepthStencilState_name);

	zval property_pColorBlendState_default_value;
	ZVAL_NULL(&property_pColorBlendState_default_value);
	zend_string *property_pColorBlendState_name = zend_string_init("pColorBlendState", sizeof("pColorBlendState") - 1, 1);
	zend_string *property_pColorBlendState_class_VkPipelineColorBlendStateCreateInfo = zend_string_init("VkPipelineColorBlendStateCreateInfo", sizeof("VkPipelineColorBlendStateCreateInfo")-1, 1);
	zend_declare_typed_property(class_entry, property_pColorBlendState_name, &property_pColorBlendState_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_pColorBlendState_class_VkPipelineColorBlendStateCreateInfo, 0, MAY_BE_NULL));
	zend_string_release(property_pColorBlendState_name);

	zval property_pDynamicState_default_value;
	ZVAL_NULL(&property_pDynamicState_default_value);
	zend_string *property_pDynamicState_name = zend_string_init("pDynamicState", sizeof("pDynamicState") - 1, 1);
	zend_string *property_pDynamicState_class_VkPipelineDynamicStateCreateInfo = zend_string_init("VkPipelineDynamicStateCreateInfo", sizeof("VkPipelineDynamicStateCreateInfo")-1, 1);
	zend_declare_typed_property(class_entry, property_pDynamicState_name, &property_pDynamicState_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_pDynamicState_class_VkPipelineDynamicStateCreateInfo, 0, MAY_BE_NULL));
	zend_string_release(property_pDynamicState_name);

	zval property_layout_default_value;
	ZVAL_NULL(&property_layout_default_value);
	zend_string *property_layout_name = zend_string_init("layout", sizeof("layout") - 1, 1);
	zend_string *property_layout_class_VkPipelineLayout = zend_string_init("VkPipelineLayout", sizeof("VkPipelineLayout")-1, 1);
	zend_declare_typed_property(class_entry, property_layout_name, &property_layout_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_layout_class_VkPipelineLayout, 0, MAY_BE_NULL));
	zend_string_release(property_layout_name);

	zval property_renderPass_default_value;
	ZVAL_NULL(&property_renderPass_default_value);
	zend_string *property_renderPass_name = zend_string_init("renderPass", sizeof("renderPass") - 1, 1);
	zend_string *property_renderPass_class_VkRenderPass = zend_string_init("VkRenderPass", sizeof("VkRenderPass")-1, 1);
	zend_declare_typed_property(class_entry, property_renderPass_name, &property_renderPass_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_renderPass_class_VkRenderPass, 0, MAY_BE_NULL));
	zend_string_release(property_renderPass_name);

	zval property_subpass_default_value;
	ZVAL_LONG(&property_subpass_default_value, 0);
	zend_string *property_subpass_name = zend_string_init("subpass", sizeof("subpass") - 1, 1);
	zend_declare_typed_property(class_entry, property_subpass_name, &property_subpass_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_subpass_name);

	zval property_basePipelineHandle_default_value;
	ZVAL_NULL(&property_basePipelineHandle_default_value);
	zend_string *property_basePipelineHandle_name = zend_string_init("basePipelineHandle", sizeof("basePipelineHandle") - 1, 1);
	zend_string *property_basePipelineHandle_class_VkPipeline = zend_string_init("VkPipeline", sizeof("VkPipeline")-1, 1);
	zend_declare_typed_property(class_entry, property_basePipelineHandle_name, &property_basePipelineHandle_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_basePipelineHandle_class_VkPipeline, 0, MAY_BE_NULL));
	zend_string_release(property_basePipelineHandle_name);

	zval property_basePipelineIndex_default_value;
	ZVAL_LONG(&property_basePipelineIndex_default_value, 0);
	zend_string *property_basePipelineIndex_name = zend_string_init("basePipelineIndex", sizeof("basePipelineIndex") - 1, 1);
	zend_declare_typed_property(class_entry, property_basePipelineIndex_name, &property_basePipelineIndex_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_basePipelineIndex_name);

	return class_entry;
}

static zend_class_entry *register_class_VkDescriptorSetLayoutBinding(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkDescriptorSetLayoutBinding", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_binding_default_value;
	ZVAL_LONG(&property_binding_default_value, 0);
	zend_string *property_binding_name = zend_string_init("binding", sizeof("binding") - 1, 1);
	zend_declare_typed_property(class_entry, property_binding_name, &property_binding_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_binding_name);

	zval property_descriptorType_default_value;
	ZVAL_LONG(&property_descriptorType_default_value, 0);
	zend_string *property_descriptorType_name = zend_string_init("descriptorType", sizeof("descriptorType") - 1, 1);
	zend_declare_typed_property(class_entry, property_descriptorType_name, &property_descriptorType_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_descriptorType_name);

	zval property_descriptorCount_default_value;
	ZVAL_LONG(&property_descriptorCount_default_value, 0);
	zend_string *property_descriptorCount_name = zend_string_init("descriptorCount", sizeof("descriptorCount") - 1, 1);
	zend_declare_typed_property(class_entry, property_descriptorCount_name, &property_descriptorCount_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_descriptorCount_name);

	zval property_stageFlags_default_value;
	ZVAL_LONG(&property_stageFlags_default_value, 0);
	zend_string *property_stageFlags_name = zend_string_init("stageFlags", sizeof("stageFlags") - 1, 1);
	zend_declare_typed_property(class_entry, property_stageFlags_name, &property_stageFlags_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_stageFlags_name);

	zval property_pImmutableSamplers_default_value;
	ZVAL_EMPTY_ARRAY(&property_pImmutableSamplers_default_value);
	zend_string *property_pImmutableSamplers_name = zend_string_init("pImmutableSamplers", sizeof("pImmutableSamplers") - 1, 1);
	zend_declare_typed_property(class_entry, property_pImmutableSamplers_name, &property_pImmutableSamplers_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_pImmutableSamplers_name);

	return class_entry;
}

static zend_class_entry *register_class_VkDescriptorSetLayoutCreateInfo(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkDescriptorSetLayoutCreateInfo", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_pNext_default_value;
	ZVAL_NULL(&property_pNext_default_value);
	zend_string *property_pNext_name = zend_string_init("pNext", sizeof("pNext") - 1, 1);
	zend_declare_typed_property(class_entry, property_pNext_name, &property_pNext_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_OBJECT|MAY_BE_NULL));
	zend_string_release(property_pNext_name);

	zval property_flags_default_value;
	ZVAL_LONG(&property_flags_default_value, 0);
	zend_string *property_flags_name = zend_string_init("flags", sizeof("flags") - 1, 1);
	zend_declare_typed_property(class_entry, property_flags_name, &property_flags_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_flags_name);

	zval property_pBindings_default_value;
	ZVAL_EMPTY_ARRAY(&property_pBindings_default_value);
	zend_string *property_pBindings_name = zend_string_init("pBindings", sizeof("pBindings") - 1, 1);
	zend_declare_typed_property(class_entry, property_pBindings_name, &property_pBindings_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_pBindings_name);

	return class_entry;
}

static zend_class_entry *register_class_VkDescriptorPoolSize(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkDescriptorPoolSize", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_type_default_value;
	ZVAL_LONG(&property_type_default_value, 0);
	zend_string *property_type_name = zend_string_init("type", sizeof("type") - 1, 1);
	zend_declare_typed_property(class_entry, property_type_name, &property_type_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_type_name);

	zval property_descriptorCount_default_value;
	ZVAL_LONG(&property_descriptorCount_default_value, 0);
	zend_string *property_descriptorCount_name = zend_string_init("descriptorCount", sizeof("descriptorCount") - 1, 1);
	zend_declare_typed_property(class_entry, property_descriptorCount_name, &property_descriptorCount_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_descriptorCount_name);

	return class_entry;
}

static zend_class_entry *register_class_VkDescriptorPoolCreateInfo(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkDescriptorPoolCreateInfo", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_pNext_default_value;
	ZVAL_NULL(&property_pNext_default_value);
	zend_string *property_pNext_name = zend_string_init("pNext", sizeof("pNext") - 1, 1);
	zend_declare_typed_property(class_entry, property_pNext_name, &property_pNext_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_OBJECT|MAY_BE_NULL));
	zend_string_release(property_pNext_name);

	zval property_flags_default_value;
	ZVAL_LONG(&property_flags_default_value, 0);
	zend_string *property_flags_name = zend_string_init("flags", sizeof("flags") - 1, 1);
	zend_declare_typed_property(class_entry, property_flags_name, &property_flags_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_flags_name);

	zval property_maxSets_default_value;
	ZVAL_LONG(&property_maxSets_default_value, 0);
	zend_string *property_maxSets_name = zend_string_init("maxSets", sizeof("maxSets") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxSets_name, &property_maxSets_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxSets_name);

	zval property_pPoolSizes_default_value;
	ZVAL_EMPTY_ARRAY(&property_pPoolSizes_default_value);
	zend_string *property_pPoolSizes_name = zend_string_init("pPoolSizes", sizeof("pPoolSizes") - 1, 1);
	zend_declare_typed_property(class_entry, property_pPoolSizes_name, &property_pPoolSizes_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_pPoolSizes_name);

	return class_entry;
}

static zend_class_entry *register_class_VkDescriptorSetAllocateInfo(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkDescriptorSetAllocateInfo", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_pNext_default_value;
	ZVAL_NULL(&property_pNext_default_value);
	zend_string *property_pNext_name = zend_string_init("pNext", sizeof("pNext") - 1, 1);
	zend_declare_typed_property(class_entry, property_pNext_name, &property_pNext_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_OBJECT|MAY_BE_NULL));
	zend_string_release(property_pNext_name);

	zval property_descriptorPool_default_value;
	ZVAL_NULL(&property_descriptorPool_default_value);
	zend_string *property_descriptorPool_name = zend_string_init("descriptorPool", sizeof("descriptorPool") - 1, 1);
	zend_string *property_descriptorPool_class_VkDescriptorPool = zend_string_init("VkDescriptorPool", sizeof("VkDescriptorPool")-1, 1);
	zend_declare_typed_property(class_entry, property_descriptorPool_name, &property_descriptorPool_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_descriptorPool_class_VkDescriptorPool, 0, MAY_BE_NULL));
	zend_string_release(property_descriptorPool_name);

	zval property_pSetLayouts_default_value;
	ZVAL_EMPTY_ARRAY(&property_pSetLayouts_default_value);
	zend_string *property_pSetLayouts_name = zend_string_init("pSetLayouts", sizeof("pSetLayouts") - 1, 1);
	zend_declare_typed_property(class_entry, property_pSetLayouts_name, &property_pSetLayouts_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_pSetLayouts_name);

	return class_entry;
}

static zend_class_entry *register_class_VkDescriptorImageInfo(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkDescriptorImageInfo", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_sampler_default_value;
	ZVAL_NULL(&property_sampler_default_value);
	zend_string *property_sampler_name = zend_string_init("sampler", sizeof("sampler") - 1, 1);
	zend_string *property_sampler_class_VkSampler = zend_string_init("VkSampler", sizeof("VkSampler")-1, 1);
	zend_declare_typed_property(class_entry, property_sampler_name, &property_sampler_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_sampler_class_VkSampler, 0, MAY_BE_NULL));
	zend_string_release(property_sampler_name);

	zval property_imageView_default_value;
	ZVAL_NULL(&property_imageView_default_value);
	zend_string *property_imageView_name = zend_string_init("imageView", sizeof("imageView") - 1, 1);
	zend_string *property_imageView_class_VkImageView = zend_string_init("VkImageView", sizeof("VkImageView")-1, 1);
	zend_declare_typed_property(class_entry, property_imageView_name, &property_imageView_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_imageView_class_VkImageView, 0, MAY_BE_NULL));
	zend_string_release(property_imageView_name);

	zval property_imageLayout_default_value;
	ZVAL_LONG(&property_imageLayout_default_value, 0);
	zend_string *property_imageLayout_name = zend_string_init("imageLayout", sizeof("imageLayout") - 1, 1);
	zend_declare_typed_property(class_entry, property_imageLayout_name, &property_imageLayout_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_imageLayout_name);

	return class_entry;
}

static zend_class_entry *register_class_VkWriteDescriptorSet(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkWriteDescriptorSet", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_pNext_default_value;
	ZVAL_NULL(&property_pNext_default_value);
	zend_string *property_pNext_name = zend_string_init("pNext", sizeof("pNext") - 1, 1);
	zend_declare_typed_property(class_entry, property_pNext_name, &property_pNext_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_OBJECT|MAY_BE_NULL));
	zend_string_release(property_pNext_name);

	zval property_dstSet_default_value;
	ZVAL_NULL(&property_dstSet_default_value);
	zend_string *property_dstSet_name = zend_string_init("dstSet", sizeof("dstSet") - 1, 1);
	zend_string *property_dstSet_class_VkDescriptorSet = zend_string_init("VkDescriptorSet", sizeof("VkDescriptorSet")-1, 1);
	zend_declare_typed_property(class_entry, property_dstSet_name, &property_dstSet_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_dstSet_class_VkDescriptorSet, 0, MAY_BE_NULL));
	zend_string_release(property_dstSet_name);

	zval property_dstBinding_default_value;
	ZVAL_LONG(&property_dstBinding_default_value, 0);
	zend_string *property_dstBinding_name = zend_string_init("dstBinding", sizeof("dstBinding") - 1, 1);
	zend_declare_typed_property(class_entry, property_dstBinding_name, &property_dstBinding_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_dstBinding_name);

	zval property_dstArrayElement_default_value;
	ZVAL_LONG(&property_dstArrayElement_default_value, 0);
	zend_string *property_dstArrayElement_name = zend_string_init("dstArrayElement", sizeof("dstArrayElement") - 1, 1);
	zend_declare_typed_property(class_entry, property_dstArrayElement_name, &property_dstArrayElement_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_dstArrayElement_name);

	zval property_descriptorType_default_value;
	ZVAL_LONG(&property_descriptorType_default_value, 0);
	zend_string *property_descriptorType_name = zend_string_init("descriptorType", sizeof("descriptorType") - 1, 1);
	zend_declare_typed_property(class_entry, property_descriptorType_name, &property_descriptorType_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_descriptorType_name);

	zval property_pImageInfo_default_value;
	ZVAL_EMPTY_ARRAY(&property_pImageInfo_default_value);
	zend_string *property_pImageInfo_name = zend_string_init("pImageInfo", sizeof("pImageInfo") - 1, 1);
	zend_declare_typed_property(class_entry, property_pImageInfo_name, &property_pImageInfo_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_pImageInfo_name);

	return class_entry;
}

static zend_class_entry *register_class_VkViewport(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkViewport", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_x_default_value;
	ZVAL_DOUBLE(&property_x_default_value, 0.0);
	zend_string *property_x_name = zend_string_init("x", sizeof("x") - 1, 1);
	zend_declare_typed_property(class_entry, property_x_name, &property_x_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_x_name);

	zval property_y_default_value;
	ZVAL_DOUBLE(&property_y_default_value, 0.0);
	zend_string *property_y_name = zend_string_init("y", sizeof("y") - 1, 1);
	zend_declare_typed_property(class_entry, property_y_name, &property_y_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_y_name);

	zval property_width_default_value;
	ZVAL_DOUBLE(&property_width_default_value, 0.0);
	zend_string *property_width_name = zend_string_init("width", sizeof("width") - 1, 1);
	zend_declare_typed_property(class_entry, property_width_name, &property_width_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_width_name);

	zval property_height_default_value;
	ZVAL_DOUBLE(&property_height_default_value, 0.0);
	zend_string *property_height_name = zend_string_init("height", sizeof("height") - 1, 1);
	zend_declare_typed_property(class_entry, property_height_name, &property_height_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_height_name);

	zval property_minDepth_default_value;
	ZVAL_DOUBLE(&property_minDepth_default_value, 0.0);
	zend_string *property_minDepth_name = zend_string_init("minDepth", sizeof("minDepth") - 1, 1);
	zend_declare_typed_property(class_entry, property_minDepth_name, &property_minDepth_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_minDepth_name);

	zval property_maxDepth_default_value;
	ZVAL_DOUBLE(&property_maxDepth_default_value, 0.0);
	zend_string *property_maxDepth_name = zend_string_init("maxDepth", sizeof("maxDepth") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxDepth_name, &property_maxDepth_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_maxDepth_name);

	return class_entry;
}

static zend_class_entry *register_class_VkOffset2D(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkOffset2D", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_x_default_value;
	ZVAL_LONG(&property_x_default_value, 0);
	zend_string *property_x_name = zend_string_init("x", sizeof("x") - 1, 1);
	zend_declare_typed_property(class_entry, property_x_name, &property_x_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_x_name);

	zval property_y_default_value;
	ZVAL_LONG(&property_y_default_value, 0);
	zend_string *property_y_name = zend_string_init("y", sizeof("y") - 1, 1);
	zend_declare_typed_property(class_entry, property_y_name, &property_y_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_y_name);

	return class_entry;
}

static zend_class_entry *register_class_VkExtent2D(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkExtent2D", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_width_default_value;
	ZVAL_LONG(&property_width_default_value, 0);
	zend_string *property_width_name = zend_string_init("width", sizeof("width") - 1, 1);
	zend_declare_typed_property(class_entry, property_width_name, &property_width_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_width_name);

	zval property_height_default_value;
	ZVAL_LONG(&property_height_default_value, 0);
	zend_string *property_height_name = zend_string_init("height", sizeof("height") - 1, 1);
	zend_declare_typed_property(class_entry, property_height_name, &property_height_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_height_name);

	return class_entry;
}

static zend_class_entry *register_class_VkRect2D(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkRect2D", class_VkRect2D_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_offset_default_value;
	ZVAL_UNDEF(&property_offset_default_value);
	zend_string *property_offset_name = zend_string_init("offset", sizeof("offset") - 1, 1);
	zend_string *property_offset_class_VkOffset2D = zend_string_init("VkOffset2D", sizeof("VkOffset2D")-1, 1);
	zend_declare_typed_property(class_entry, property_offset_name, &property_offset_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_offset_class_VkOffset2D, 0, 0));
	zend_string_release(property_offset_name);

	zval property_extent_default_value;
	ZVAL_UNDEF(&property_extent_default_value);
	zend_string *property_extent_name = zend_string_init("extent", sizeof("extent") - 1, 1);
	zend_string *property_extent_class_VkExtent2D = zend_string_init("VkExtent2D", sizeof("VkExtent2D")-1, 1);
	zend_declare_typed_property(class_entry, property_extent_name, &property_extent_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_extent_class_VkExtent2D, 0, 0));
	zend_string_release(property_extent_name);

	return class_entry;
}
