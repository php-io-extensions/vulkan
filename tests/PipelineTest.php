<?php

declare(strict_types=1);

it('builds the 4x render pass and both flat pipelines', function (): void {
    $pass = msaaRenderPass();
    $layout = flatLayout();

    expect(flatPipeline($pass, $layout, false, VK_COMPARE_OP_ALWAYS, VK_STENCIL_OP_INVERT))->toBeInstanceOf(VkPipeline::class)
        ->and(flatPipeline($pass, $layout, true, VK_COMPARE_OP_NOT_EQUAL, VK_STENCIL_OP_ZERO))->toBeInstanceOf(VkPipeline::class);
});

it('refuses SPIR-V that is not whole words', function (): void {
    $info = new VkShaderModuleCreateInfo();
    $info->code = "\x03\x02\x23";
    [, , $device] = gpu();

    vkCreateShaderModule($device, $info, null, $module);
})->throws(ValueError::class, 'multiple of 4');

it('lays out, pools, allocates and writes a combined image sampler', function (): void {
    [, , $device] = gpu();
    $binding = new VkDescriptorSetLayoutBinding();
    $binding->descriptorType = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
    $binding->descriptorCount = 1;
    $binding->stageFlags = VK_SHADER_STAGE_FRAGMENT_BIT;
    $layoutInfo = new VkDescriptorSetLayoutCreateInfo();
    $layoutInfo->pBindings = [$binding];
    vkCreateDescriptorSetLayout($device, $layoutInfo, null, $setLayout);
    $size = new VkDescriptorPoolSize();
    $size->type = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
    $size->descriptorCount = 1;
    $poolInfo = new VkDescriptorPoolCreateInfo();
    $poolInfo->maxSets = 1;
    $poolInfo->pPoolSizes = [$size];
    vkCreateDescriptorPool($device, $poolInfo, null, $pool);
    $allocate = new VkDescriptorSetAllocateInfo();
    $allocate->descriptorPool = $pool;
    $allocate->pSetLayouts = [$setLayout];

    expect(vkAllocateDescriptorSets($device, $allocate, $sets))->toBe(VK_SUCCESS)->and($sets)->toHaveCount(1);

    [$image, $memory] = image2D(VK_FORMAT_R8G8B8A8_UNORM, 4, 4, VK_IMAGE_USAGE_SAMPLED_BIT);
    vkCreateSampler($device, new VkSamplerCreateInfo(), null, $sampler);
    $imageInfo = new VkDescriptorImageInfo();
    $imageInfo->sampler = $sampler;
    $imageInfo->imageView = view2D($image, VK_FORMAT_R8G8B8A8_UNORM, VK_IMAGE_ASPECT_COLOR_BIT);
    $imageInfo->imageLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
    $write = new VkWriteDescriptorSet();
    $write->dstSet = $sets[0];
    $write->descriptorType = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
    $write->pImageInfo = [$imageInfo];
    vkUpdateDescriptorSets($device, [$write], []);

    vkDestroyDescriptorPool($device, $pool, null);
    expect(fn () => $sets[0]->pointer())->toThrow(ValueError::class, 'VkDescriptorSet has been destroyed');

    vkDestroyDescriptorSetLayout($device, $setLayout, null);
    vkDestroySampler($device, $sampler, null);
    vkDestroyImageView($device, $imageInfo->imageView, null);
    vkDestroyImage($device, $image, null);
    vkFreeMemory($device, $memory, null);
});
