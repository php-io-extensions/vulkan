<?php

/** @generate-class-entries */

/**
 * @not-serializable
 */
final class VkRenderPass
{
    private function __construct() {}

    public function pointer(): int {}

    public static function fromPointer(int $pointer): ?static {}
}

/**
 * @not-serializable
 */
final class VkFramebuffer
{
    private function __construct() {}

    public function pointer(): int {}

    public static function fromPointer(int $pointer): ?static {}
}

/**
 * @not-serializable
 */
final class VkShaderModule
{
    private function __construct() {}

    public function pointer(): int {}

    public static function fromPointer(int $pointer): ?static {}
}

/**
 * @not-serializable
 */
final class VkPipelineLayout
{
    private function __construct() {}

    public function pointer(): int {}

    public static function fromPointer(int $pointer): ?static {}
}

/**
 * @not-serializable
 */
final class VkPipeline
{
    private function __construct() {}

    public function pointer(): int {}

    public static function fromPointer(int $pointer): ?static {}
}

/**
 * @not-serializable
 */
final class VkDescriptorSetLayout
{
    private function __construct() {}

    public function pointer(): int {}

    public static function fromPointer(int $pointer): ?static {}
}

/**
 * @not-serializable
 */
final class VkDescriptorPool
{
    private function __construct() {}

    public function pointer(): int {}

    public static function fromPointer(int $pointer): ?static {}
}

/**
 * @not-serializable
 */
final class VkDescriptorSet
{
    private function __construct() {}

    public function pointer(): int {}

    public static function fromPointer(int $pointer): ?static {}
}

/**
 * @not-serializable
 */
final class VkAttachmentDescription
{
    public int $flags = 0;

    public int $format = 0;

    public int $samples = 0;

    public int $loadOp = 0;

    public int $storeOp = 0;

    public int $stencilLoadOp = 0;

    public int $stencilStoreOp = 0;

    public int $initialLayout = 0;

    public int $finalLayout = 0;
}

/**
 * @not-serializable
 */
final class VkAttachmentReference
{
    public int $attachment = 0;

    public int $layout = 0;
}

/**
 * @not-serializable
 */
final class VkSubpassDescription
{
    public int $flags = 0;

    public int $pipelineBindPoint = 0;

    public int $inputAttachmentCount = 0;

    public array $pInputAttachments = [];

    public int $colorAttachmentCount = 0;

    public array $pColorAttachments = [];

    public ?array $pResolveAttachments = null;

    public ?VkAttachmentReference $pDepthStencilAttachment = null;

    public int $preserveAttachmentCount = 0;

    public array $pPreserveAttachments = [];
}

/**
 * @not-serializable
 */
final class VkSubpassDependency
{
    public int $srcSubpass = 0;

    public int $dstSubpass = 0;

    public int $srcStageMask = 0;

    public int $dstStageMask = 0;

    public int $srcAccessMask = 0;

    public int $dstAccessMask = 0;

    public int $dependencyFlags = 0;
}

/**
 * @not-serializable
 */
final class VkRenderPassCreateInfo
{
    public ?object $pNext = null;

    public int $flags = 0;

    public int $attachmentCount = 0;

    public array $pAttachments = [];

    public int $subpassCount = 0;

    public array $pSubpasses = [];

    public int $dependencyCount = 0;

    public array $pDependencies = [];
}

/**
 * @not-serializable
 */
final class VkFramebufferCreateInfo
{
    public ?object $pNext = null;

    public int $flags = 0;

    public ?VkRenderPass $renderPass = null;

    public int $attachmentCount = 0;

    public array $pAttachments = [];

    public int $width = 0;

    public int $height = 0;

    public int $layers = 0;
}

/**
 * @not-serializable
 */
final class VkShaderModuleCreateInfo
{
    public ?object $pNext = null;

    public int $flags = 0;

    public int $codeSize = 0;

    public string $pCode = '';
}

/**
 * @not-serializable
 */
final class VkPushConstantRange
{
    public int $stageFlags = 0;

    public int $offset = 0;

    public int $size = 0;
}

/**
 * @not-serializable
 */
final class VkPipelineLayoutCreateInfo
{
    public ?object $pNext = null;

    public int $flags = 0;

    public int $setLayoutCount = 0;

    public array $pSetLayouts = [];

    public int $pushConstantRangeCount = 0;

    public array $pPushConstantRanges = [];
}

/**
 * @not-serializable
 */
final class VkPipelineShaderStageCreateInfo
{
    public ?object $pNext = null;

    public int $flags = 0;

    public int $stage = 0;

    public ?VkShaderModule $module = null;

    public ?string $pName = null;
}

/**
 * @not-serializable
 */
final class VkVertexInputBindingDescription
{
    public int $binding = 0;

    public int $stride = 0;

    public int $inputRate = 0;
}

/**
 * @not-serializable
 */
final class VkVertexInputAttributeDescription
{
    public int $location = 0;

    public int $binding = 0;

    public int $format = 0;

    public int $offset = 0;
}

/**
 * @not-serializable
 */
final class VkPipelineVertexInputStateCreateInfo
{
    public ?object $pNext = null;

    public int $flags = 0;

    public int $vertexBindingDescriptionCount = 0;

    public array $pVertexBindingDescriptions = [];

    public int $vertexAttributeDescriptionCount = 0;

    public array $pVertexAttributeDescriptions = [];
}

/**
 * @not-serializable
 */
final class VkPipelineInputAssemblyStateCreateInfo
{
    public ?object $pNext = null;

    public int $flags = 0;

    public int $topology = 0;

    public bool $primitiveRestartEnable = false;
}

/**
 * @not-serializable
 */
final class VkPipelineViewportStateCreateInfo
{
    public ?object $pNext = null;

    public int $flags = 0;

    public int $viewportCount = 0;

    public ?array $pViewports = null;

    public int $scissorCount = 0;

    public ?array $pScissors = null;
}

/**
 * @not-serializable
 */
final class VkPipelineRasterizationStateCreateInfo
{
    public ?object $pNext = null;

    public int $flags = 0;

    public bool $depthClampEnable = false;

    public bool $rasterizerDiscardEnable = false;

    public int $polygonMode = 0;

    public int $cullMode = 0;

    public int $frontFace = 0;

    public bool $depthBiasEnable = false;

    public float $depthBiasConstantFactor = 0.0;

    public float $depthBiasClamp = 0.0;

    public float $depthBiasSlopeFactor = 0.0;

    public float $lineWidth = 0.0;
}

/**
 * @not-serializable
 */
final class VkPipelineMultisampleStateCreateInfo
{
    public ?object $pNext = null;

    public int $flags = 0;

    public int $rasterizationSamples = 0;

    public bool $sampleShadingEnable = false;

    public float $minSampleShading = 0.0;

    public ?array $pSampleMask = null;

    public bool $alphaToCoverageEnable = false;

    public bool $alphaToOneEnable = false;
}

/**
 * @not-serializable
 */
final class VkStencilOpState
{
    public int $failOp = 0;

    public int $passOp = 0;

    public int $depthFailOp = 0;

    public int $compareOp = 0;

    public int $compareMask = 0;

    public int $writeMask = 0;

    public int $reference = 0;
}

/**
 * @not-serializable
 */
final class VkPipelineDepthStencilStateCreateInfo
{
    public ?object $pNext = null;

    public int $flags = 0;

    public bool $depthTestEnable = false;

    public bool $depthWriteEnable = false;

    public int $depthCompareOp = 0;

    public bool $depthBoundsTestEnable = false;

    public bool $stencilTestEnable = false;

    public VkStencilOpState $front;

    public VkStencilOpState $back;

    public float $minDepthBounds = 0.0;

    public float $maxDepthBounds = 0.0;

    public function __construct() {}
}

/**
 * @not-serializable
 */
final class VkPipelineColorBlendAttachmentState
{
    public bool $blendEnable = false;

    public int $srcColorBlendFactor = 0;

    public int $dstColorBlendFactor = 0;

    public int $colorBlendOp = 0;

    public int $srcAlphaBlendFactor = 0;

    public int $dstAlphaBlendFactor = 0;

    public int $alphaBlendOp = 0;

    public int $colorWriteMask = 0;
}

/**
 * @not-serializable
 */
final class VkPipelineColorBlendStateCreateInfo
{
    public ?object $pNext = null;

    public int $flags = 0;

    public bool $logicOpEnable = false;

    public int $logicOp = 0;

    public int $attachmentCount = 0;

    public array $pAttachments = [];

    public array $blendConstants = [];

    public function __construct() {}
}

/**
 * @not-serializable
 */
final class VkPipelineDynamicStateCreateInfo
{
    public ?object $pNext = null;

    public int $flags = 0;

    public int $dynamicStateCount = 0;

    public array $pDynamicStates = [];
}

/**
 * @not-serializable
 */
final class VkPipelineTessellationStateCreateInfo
{
    public ?object $pNext = null;

    public int $flags = 0;

    public int $patchControlPoints = 0;
}

/**
 * @not-serializable
 */
final class VkGraphicsPipelineCreateInfo
{
    public ?object $pNext = null;

    public int $flags = 0;

    public int $stageCount = 0;

    public array $pStages = [];

    public ?VkPipelineVertexInputStateCreateInfo $pVertexInputState = null;

    public ?VkPipelineInputAssemblyStateCreateInfo $pInputAssemblyState = null;

    public ?VkPipelineTessellationStateCreateInfo $pTessellationState = null;

    public ?VkPipelineViewportStateCreateInfo $pViewportState = null;

    public ?VkPipelineRasterizationStateCreateInfo $pRasterizationState = null;

    public ?VkPipelineMultisampleStateCreateInfo $pMultisampleState = null;

    public ?VkPipelineDepthStencilStateCreateInfo $pDepthStencilState = null;

    public ?VkPipelineColorBlendStateCreateInfo $pColorBlendState = null;

    public ?VkPipelineDynamicStateCreateInfo $pDynamicState = null;

    public ?VkPipelineLayout $layout = null;

    public ?VkRenderPass $renderPass = null;

    public int $subpass = 0;

    public ?VkPipeline $basePipelineHandle = null;

    public int $basePipelineIndex = 0;
}

/**
 * @not-serializable
 */
final class VkComputePipelineCreateInfo
{
    public ?object $pNext = null;

    public int $flags = 0;

    public VkPipelineShaderStageCreateInfo $stage;

    public ?VkPipelineLayout $layout = null;

    public ?VkPipeline $basePipelineHandle = null;

    public int $basePipelineIndex = 0;

    public function __construct() {}
}

/**
 * @not-serializable
 */
final class VkDescriptorSetLayoutBinding
{
    public int $binding = 0;

    public int $descriptorType = 0;

    public int $descriptorCount = 0;

    public int $stageFlags = 0;

    public ?array $pImmutableSamplers = null;
}

/**
 * @not-serializable
 */
final class VkDescriptorSetLayoutCreateInfo
{
    public ?object $pNext = null;

    public int $flags = 0;

    public int $bindingCount = 0;

    public array $pBindings = [];
}

/**
 * @not-serializable
 */
final class VkDescriptorPoolSize
{
    public int $type = 0;

    public int $descriptorCount = 0;
}

/**
 * @not-serializable
 */
final class VkDescriptorPoolCreateInfo
{
    public ?object $pNext = null;

    public int $flags = 0;

    public int $maxSets = 0;

    public int $poolSizeCount = 0;

    public array $pPoolSizes = [];
}

/**
 * @not-serializable
 */
final class VkDescriptorSetAllocateInfo
{
    public ?object $pNext = null;

    public ?VkDescriptorPool $descriptorPool = null;

    public int $descriptorSetCount = 0;

    public array $pSetLayouts = [];
}

/**
 * @not-serializable
 */
final class VkDescriptorImageInfo
{
    public ?VkSampler $sampler = null;

    public ?VkImageView $imageView = null;

    public int $imageLayout = 0;
}

/**
 * @not-serializable
 */
final class VkDescriptorBufferInfo
{
    public ?VkBuffer $buffer = null;

    public int $offset = 0;

    public int $range = 0;
}

/**
 * @not-serializable
 */
final class VkWriteDescriptorSet
{
    public ?object $pNext = null;

    public ?VkDescriptorSet $dstSet = null;

    public int $dstBinding = 0;

    public int $dstArrayElement = 0;

    public int $descriptorType = 0;

    public int $descriptorCount = 0;

    public ?array $pImageInfo = null;

    public ?array $pBufferInfo = null;
}

/**
 * @not-serializable
 */
final class VkViewport
{
    public float $x = 0.0;

    public float $y = 0.0;

    public float $width = 0.0;

    public float $height = 0.0;

    public float $minDepth = 0.0;

    public float $maxDepth = 0.0;
}

/**
 * @not-serializable
 */
final class VkOffset2D
{
    public int $x = 0;

    public int $y = 0;
}

/**
 * @not-serializable
 */
final class VkExtent2D
{
    public int $width = 0;

    public int $height = 0;
}

/**
 * @not-serializable
 */
final class VkRect2D
{
    public VkOffset2D $offset;

    public VkExtent2D $extent;

    public function __construct() {}
}

/** @not-serializable */
final class VkCopyDescriptorSet
{
    public ?object $pNext = null;

    public ?VkDescriptorSet $srcSet = null;

    public int $srcBinding = 0;

    public int $srcArrayElement = 0;

    public ?VkDescriptorSet $dstSet = null;

    public int $dstBinding = 0;

    public int $dstArrayElement = 0;

    public int $descriptorCount = 0;
}

function vkCreateRenderPass(VkDevice $device, VkRenderPassCreateInfo $pCreateInfo, int $pAllocator, ?VkRenderPass &$pRenderPass): int {}

function vkDestroyRenderPass(VkDevice $device, ?VkRenderPass $renderPass, int $pAllocator): void {}

function vkCreateFramebuffer(VkDevice $device, VkFramebufferCreateInfo $pCreateInfo, int $pAllocator, ?VkFramebuffer &$pFramebuffer): int {}

function vkDestroyFramebuffer(VkDevice $device, ?VkFramebuffer $framebuffer, int $pAllocator): void {}

function vkCreateShaderModule(VkDevice $device, VkShaderModuleCreateInfo $pCreateInfo, int $pAllocator, ?VkShaderModule &$pShaderModule): int {}

function vkDestroyShaderModule(VkDevice $device, ?VkShaderModule $shaderModule, int $pAllocator): void {}

function vkCreatePipelineLayout(VkDevice $device, VkPipelineLayoutCreateInfo $pCreateInfo, int $pAllocator, ?VkPipelineLayout &$pPipelineLayout): int {}

function vkDestroyPipelineLayout(VkDevice $device, ?VkPipelineLayout $pipelineLayout, int $pAllocator): void {}

function vkCreateGraphicsPipelines(VkDevice $device, int $pipelineCache, int $createInfoCount, array $pCreateInfos, int $pAllocator, ?array &$pPipelines): int {}

function vkCreateComputePipelines(VkDevice $device, int $pipelineCache, int $createInfoCount, array $pCreateInfos, int $pAllocator, ?array &$pPipelines): int {}

function vkDestroyPipeline(VkDevice $device, ?VkPipeline $pipeline, int $pAllocator): void {}

function vkCreateDescriptorSetLayout(VkDevice $device, VkDescriptorSetLayoutCreateInfo $pCreateInfo, int $pAllocator, ?VkDescriptorSetLayout &$pSetLayout): int {}

function vkDestroyDescriptorSetLayout(VkDevice $device, ?VkDescriptorSetLayout $descriptorSetLayout, int $pAllocator): void {}

function vkCreateDescriptorPool(VkDevice $device, VkDescriptorPoolCreateInfo $pCreateInfo, int $pAllocator, ?VkDescriptorPool &$pDescriptorPool): int {}

function vkDestroyDescriptorPool(VkDevice $device, ?VkDescriptorPool $descriptorPool, int $pAllocator): void {}

function vkAllocateDescriptorSets(VkDevice $device, VkDescriptorSetAllocateInfo $pAllocateInfo, ?array &$pDescriptorSets): int {}

function vkUpdateDescriptorSets(VkDevice $device, int $descriptorWriteCount, array $pDescriptorWrites, int $descriptorCopyCount, array $pDescriptorCopies): void {}
