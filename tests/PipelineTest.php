<?php

declare(strict_types=1);

it('builds the 4x render pass and both flat pipelines', function (): void {
    $pass = msaaRenderPass();
    $layout = flatLayout();

    expect(flatPipeline($pass, $layout, false, VK_COMPARE_OP_ALWAYS, VK_STENCIL_OP_INVERT))->toBeInstanceOf(VkPipeline::class)
        ->and(flatPipeline($pass, $layout, true, VK_COMPARE_OP_NOT_EQUAL, VK_STENCIL_OP_ZERO))->toBeInstanceOf(VkPipeline::class);
});

it('refuses a codeSize past the SPIR-V string', function (): void {
    $info = new VkShaderModuleCreateInfo();
    $info->pCode = "\x03\x02\x23\x07";
    $info->codeSize = 8;
    [, , $device] = gpu();

    vkCreateShaderModule($device, $info, 0, $module);
})->throws(ValueError::class, 'VkShaderModuleCreateInfo::$pCode holds 4 bytes, fewer than the 8 Vulkan reads');

it('refuses a struct count past its list', function (): void {
    $info = new VkPipelineLayoutCreateInfo();
    $info->pushConstantRangeCount = 2;
    $info->pPushConstantRanges = [new VkPushConstantRange()];
    [, , $device] = gpu();

    vkCreatePipelineLayout($device, $info, 0, $layout);
})->throws(ValueError::class, 'VkPipelineLayoutCreateInfo::$pPushConstantRanges holds 1 values, fewer than its count 2');

it('lays out, pools, allocates, writes and copies combined image samplers', function (): void {
    [, , $device] = gpu();
    $binding = new VkDescriptorSetLayoutBinding();
    $binding->descriptorType = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
    $binding->descriptorCount = 1;
    $binding->stageFlags = VK_SHADER_STAGE_FRAGMENT_BIT;
    $layoutInfo = new VkDescriptorSetLayoutCreateInfo();
    $layoutInfo->bindingCount = 1;
    $layoutInfo->pBindings = [$binding];
    vkCreateDescriptorSetLayout($device, $layoutInfo, 0, $setLayout);
    $size = new VkDescriptorPoolSize();
    $size->type = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
    $size->descriptorCount = 2;
    $poolInfo = new VkDescriptorPoolCreateInfo();
    $poolInfo->maxSets = 2;
    $poolInfo->poolSizeCount = 1;
    $poolInfo->pPoolSizes = [$size];
    vkCreateDescriptorPool($device, $poolInfo, 0, $pool);
    $allocate = new VkDescriptorSetAllocateInfo();
    $allocate->descriptorPool = $pool;
    $allocate->descriptorSetCount = 2;
    $allocate->pSetLayouts = [$setLayout, $setLayout];

    expect(vkAllocateDescriptorSets($device, $allocate, $sets))->toBe(VK_SUCCESS)->and($sets)->toHaveCount(2);

    [$image, $memory] = image2D(VK_FORMAT_R8G8B8A8_UNORM, 4, 4, VK_IMAGE_USAGE_SAMPLED_BIT);
    vkCreateSampler($device, new VkSamplerCreateInfo(), 0, $sampler);
    $imageInfo = new VkDescriptorImageInfo();
    $imageInfo->sampler = $sampler;
    $imageInfo->imageView = view2D($image, VK_FORMAT_R8G8B8A8_UNORM, VK_IMAGE_ASPECT_COLOR_BIT);
    $imageInfo->imageLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
    $write = new VkWriteDescriptorSet();
    $write->dstSet = $sets[0];
    $write->descriptorCount = 1;
    $write->descriptorType = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
    $write->pImageInfo = [$imageInfo];
    $copy = new VkCopyDescriptorSet();
    $copy->srcSet = $sets[0];
    $copy->dstSet = $sets[1];
    $copy->descriptorCount = 1;
    vkUpdateDescriptorSets($device, 1, [$write], 0, []);
    vkUpdateDescriptorSets($device, 0, [], 1, [$copy]);

    vkDestroyDescriptorPool($device, $pool, 0);
    expect($sets[0]->pointer())->toBe(0)->and($sets[1]->pointer())->toBe(0);

    vkDestroyDescriptorSetLayout($device, $setLayout, 0);
    vkDestroySampler($device, $sampler, 0);
    vkDestroyImageView($device, $imageInfo->imageView, 0);
    vkDestroyImage($device, $image, 0);
    vkFreeMemory($device, $memory, 0);
});

it('writes storage buffer descriptors through pBufferInfo', function (): void {
    [, , $device] = gpu();
    $binding = new VkDescriptorSetLayoutBinding();
    $binding->descriptorType = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;
    $binding->descriptorCount = 1;
    $binding->stageFlags = VK_SHADER_STAGE_FRAGMENT_BIT;
    $layoutInfo = new VkDescriptorSetLayoutCreateInfo();
    $layoutInfo->bindingCount = 1;
    $layoutInfo->pBindings = [$binding];
    vkCreateDescriptorSetLayout($device, $layoutInfo, 0, $setLayout);
    $size = new VkDescriptorPoolSize();
    $size->type = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;
    $size->descriptorCount = 1;
    $poolInfo = new VkDescriptorPoolCreateInfo();
    $poolInfo->maxSets = 1;
    $poolInfo->poolSizeCount = 1;
    $poolInfo->pPoolSizes = [$size];
    vkCreateDescriptorPool($device, $poolInfo, 0, $pool);
    $allocate = new VkDescriptorSetAllocateInfo();
    $allocate->descriptorPool = $pool;
    $allocate->descriptorSetCount = 1;
    $allocate->pSetLayouts = [$setLayout];
    vkAllocateDescriptorSets($device, $allocate, $sets);
    [$buffer, $memory] = hostBuffer(256, VK_BUFFER_USAGE_STORAGE_BUFFER_BIT);

    $info = new VkDescriptorBufferInfo();
    $info->buffer = $buffer;
    $info->offset = 0;
    $info->range = VK_WHOLE_SIZE;
    $write = new VkWriteDescriptorSet();
    $write->dstSet = $sets[0];
    $write->descriptorCount = 1;
    $write->descriptorType = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;
    $write->pBufferInfo = [$info];
    vkUpdateDescriptorSets($device, 1, [$write], 0, []);

    $short = new VkWriteDescriptorSet();
    $short->dstSet = $sets[0];
    $short->descriptorCount = 2;
    $short->descriptorType = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;
    $short->pBufferInfo = [$info];
    expect(fn () => vkUpdateDescriptorSets($device, 1, [$short], 0, []))
        ->toThrow(ValueError::class, 'VkWriteDescriptorSet::$pBufferInfo holds 1 values, fewer than its count 2');

    vkDestroyDescriptorPool($device, $pool, 0);
    vkDestroyDescriptorSetLayout($device, $setLayout, 0);
    vkDestroyBuffer($device, $buffer, 0);
    vkFreeMemory($device, $memory, 0);
});
