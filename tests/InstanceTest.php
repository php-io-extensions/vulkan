<?php

declare(strict_types=1);

it('lists the loader\'s instance extensions in two calls, as C does', function (): void {
    expect(vkEnumerateInstanceExtensionProperties(null, $count, null))->toBe(VK_SUCCESS)
        ->and($count)->toBeGreaterThan(0)
        ->and(vkEnumerateInstanceExtensionProperties(null, $count, $extensions))->toBe(VK_SUCCESS)
        ->and($extensions)->toHaveCount($count)
        ->and(array_map(fn (VkExtensionProperties $e): string => $e->extensionName, $extensions))->toContain(VK_KHR_SURFACE_EXTENSION_NAME);
});

it('answers VK_INCOMPLETE when the count is short of the list', function (): void {
    vkEnumerateInstanceExtensionProperties(null, $count, null);
    $short = $count - 1;

    expect(vkEnumerateInstanceExtensionProperties(null, $short, $extensions))->toBe(VK_INCOMPLETE)
        ->and($extensions)->toHaveCount($count - 1);
});

it('opens the GPU, its graphics queue and its limits', function (): void {
    [$instance, $physical, $device, $queue] = gpu();
    vkGetPhysicalDeviceProperties($physical, $properties);
    vkGetPhysicalDeviceMemoryProperties($physical, $memory);

    expect($properties->deviceType)->not->toBe(VK_PHYSICAL_DEVICE_TYPE_CPU)
        ->and($properties->limits->framebufferColorSampleCounts & VK_SAMPLE_COUNT_4_BIT)->toBe(VK_SAMPLE_COUNT_4_BIT)
        ->and($properties->limits->nonCoherentAtomSize)->toBeGreaterThan(0)
        ->and($memory->memoryTypeCount)->toBe(count($memory->memoryTypes))
        ->and($memory->memoryTypes)->not->toBe([])
        ->and($queue)->toBeInstanceOf(VkQueue::class)
        ->and(vkDeviceWaitIdle($device))->toBe(VK_SUCCESS)
        ->and(VkDevice::fromPointer($device->pointer()))->toBe($device)
        ->and(VkDevice::fromPointer(0))->toBeNull();
});

it('answers a format\'s features and the device\'s extensions', function (): void {
    [, $physical] = gpu();
    vkGetPhysicalDeviceFormatProperties($physical, VK_FORMAT_R8G8B8A8_UNORM, $format);
    vkEnumerateDeviceExtensionProperties($physical, null, $count, null);
    vkEnumerateDeviceExtensionProperties($physical, null, $count, $extensions);

    expect($format->optimalTilingFeatures & VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BIT)->not->toBe(0)
        ->and($extensions)->not->toBe([]);
});

it('releases everything made from a destroyed device', function (): void {
    [, $physical, , , $family] = gpu();
    $queueInfo = new VkDeviceQueueCreateInfo();
    $queueInfo->queueFamilyIndex = $family;
    $queueInfo->queueCount = 1;
    $queueInfo->pQueuePriorities = [1.0];
    $info = new VkDeviceCreateInfo();
    $info->queueCreateInfoCount = 1;
    $info->pQueueCreateInfos = [$queueInfo];
    vkCreateDevice($physical, portabilityDevice($physical, $info), 0, $device);
    vkGetDeviceQueue($device, $family, 0, $queue);

    vkDestroyDevice($device, 0);

    expect($device->pointer())->toBe(0)
        ->and($queue->pointer())->toBe(0)
        ->and(fn () => vkDeviceWaitIdle($device))->toThrow(ValueError::class, 'VkDevice has been released: Vulkan dispatches through it');

    vkDestroyDevice($device, 0);
    vkDestroyDevice(null, 0);
});

it('refuses a pNext chain that loops', function (): void {
    $info = new VkInstanceCreateInfo();
    $info->pNext = $info;

    expect(fn () => vkCreateInstance($info, 0, $instance))->toThrow(ValueError::class, 'pNext chain loops');
});
