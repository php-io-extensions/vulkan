<?php

declare(strict_types=1);

it('answers the limits of a supported image format with vkGetPhysicalDeviceImageFormatProperties', function (): void {
    [, $physical] = gpu();
    $usage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT | VK_IMAGE_USAGE_TRANSFER_SRC_BIT;

    $result = vkGetPhysicalDeviceImageFormatProperties($physical, VK_FORMAT_R8G8B8A8_UNORM, VK_IMAGE_TYPE_2D, VK_IMAGE_TILING_OPTIMAL, $usage, 0, $properties);

    expect($result)->toBe(VK_SUCCESS)
        ->and($properties)->toBeInstanceOf(VkImageFormatProperties::class)
        ->and($properties->maxExtent->width)->toBeGreaterThanOrEqual(4096)
        ->and($properties->maxExtent->height)->toBeGreaterThanOrEqual(4096)
        ->and($properties->maxMipLevels)->toBeGreaterThan(0)
        ->and($properties->maxArrayLayers)->toBeGreaterThan(0)
        ->and($properties->sampleCounts & VK_SAMPLE_COUNT_1_BIT)->toBe(VK_SAMPLE_COUNT_1_BIT)
        ->and($properties->maxResourceSize)->toBeGreaterThan(0);
});

it('answers VK_ERROR_FORMAT_NOT_SUPPORTED and zeroes the struct for a format the device lacks', function (): void {
    [, $physical] = gpu();

    $result = vkGetPhysicalDeviceImageFormatProperties($physical, VK_FORMAT_D32_SFLOAT, VK_IMAGE_TYPE_2D, VK_IMAGE_TILING_LINEAR, VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT, 0, $properties);

    expect($result)->toBe(VK_ERROR_FORMAT_NOT_SUPPORTED)
        ->and($properties->maxExtent->width)->toBe(0)
        ->and($properties->sampleCounts)->toBe(0)
        ->and($properties->maxResourceSize)->toBe(0);
});
