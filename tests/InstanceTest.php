<?php

declare(strict_types=1);

it('lists the loader\'s instance extensions', function (): void {
    expect(vkEnumerateInstanceExtensionProperties(null, $extensions))->toBe(VK_SUCCESS)
        ->and(array_map(fn (VkExtensionProperties $e): string => $e->extensionName, $extensions))->toContain(VK_KHR_SURFACE_EXTENSION_NAME);
});

it('opens the GPU, its graphics queue and its limits', function (): void {
    [$instance, $physical, $device, $queue] = gpu();
    vkGetPhysicalDeviceProperties($physical, $properties);
    vkGetPhysicalDeviceMemoryProperties($physical, $memory);

    expect($properties->deviceType)->not->toBe(VK_PHYSICAL_DEVICE_TYPE_CPU)
        ->and($properties->limits->framebufferColorSampleCounts & VK_SAMPLE_COUNT_4_BIT)->toBe(VK_SAMPLE_COUNT_4_BIT)
        ->and($properties->limits->nonCoherentAtomSize)->toBeGreaterThan(0)
        ->and($memory->memoryTypes)->not->toBe([])
        ->and($queue)->toBeInstanceOf(VkQueue::class)
        ->and(vkDeviceWaitIdle($device))->toBe(VK_SUCCESS)
        ->and(VkDevice::fromPointer($device->pointer()))->toBe($device);
});

it('answers a format\'s features and the device\'s extensions', function (): void {
    [, $physical] = gpu();
    vkGetPhysicalDeviceFormatProperties($physical, VK_FORMAT_R8G8B8A8_UNORM, $format);
    vkEnumerateDeviceExtensionProperties($physical, null, $extensions);

    expect($format->optimalTilingFeatures & VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BIT)->not->toBe(0)
        ->and($extensions)->not->toBe([]);
});

it('releases everything made from a destroyed device', function (): void {
    [, $physical, , , $family] = gpu();
    $queueInfo = new VkDeviceQueueCreateInfo();
    $queueInfo->queueFamilyIndex = $family;
    $queueInfo->pQueuePriorities = [1.0];
    $info = new VkDeviceCreateInfo();
    $info->pQueueCreateInfos = [$queueInfo];
    vkCreateDevice($physical, portabilityDevice($physical, $info), null, $device);
    vkGetDeviceQueue($device, $family, 0, $queue);

    vkDestroyDevice($device, null);

    expect(fn () => vkDeviceWaitIdle($device))->toThrow(ValueError::class, 'VkDevice has been destroyed')
        ->and(fn () => $queue->pointer())->toThrow(ValueError::class, 'VkQueue has been destroyed');
});

it('reads and writes memory by address', function (): void {
    $buffer = new FbBuffer(new FbFormat(FB_LAYOUT_RGBA8888, channelOrder: FB_CHANNELS_RGBA), 2, 1);
    vk_write_mapped($buffer->pointer(), "\x01\x02\x03\x04\x05\x06\x07\x08");

    expect(vk_read_mapped($buffer->pointer(), 8))->toBe("\x01\x02\x03\x04\x05\x06\x07\x08")
        ->and(fn () => vk_read_mapped(0, 4))->toThrow(ValueError::class, 'null address');
})->skip(! class_exists(FbBuffer::class), 'needs ext-fb for a native address');

it('refuses a pNext chain that loops', function (): void {
    $info = new VkInstanceCreateInfo();
    $info->pNext = $info;

    expect(fn () => vkCreateInstance($info, null, $instance))->toThrow(ValueError::class, 'pNext chain loops');
});
