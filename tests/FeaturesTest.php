<?php

declare(strict_types=1);

it('fills the core features and a chained portability-subset struct in place', function (): void {
    [, $physical] = gpu();
    $portability = new VkPhysicalDevicePortabilitySubsetFeaturesKHR();
    $features = new VkPhysicalDeviceFeatures2();
    $features->pNext = $portability;

    vkGetPhysicalDeviceFeatures2($physical, $features);

    expect($features->features)->toBeInstanceOf(VkPhysicalDeviceFeatures::class)
        ->and($features->pNext)->toBe($portability);

    if (PHP_OS_FAMILY === 'Darwin') {
        // MoltenVK 1.4.2 on the M1 Pro, as vulkaninfo reports it.
        expect($portability->triangleFans)->toBeTrue()
            ->and($portability->pointPolygons)->toBeFalse()
            ->and($portability->separateStencilMaskRef)->toBeTrue();
    } else {
        // Not a portability driver: Vulkan leaves the struct it does not know untouched.
        expect($portability->triangleFans)->toBeFalse()
            ->and($portability->events)->toBeFalse();
    }
});

it('fills the core features alone with no chain', function (): void {
    [, $physical] = gpu();
    $features = new VkPhysicalDeviceFeatures2();

    vkGetPhysicalDeviceFeatures2($physical, $features);

    expect($features->pNext)->toBeNull()
        ->and($features->features->fillModeNonSolid)->toBeBool();
});

it('refuses a chain that loops back on itself', function (): void {
    [, $physical] = gpu();
    $features = new VkPhysicalDeviceFeatures2();
    $portability = new VkPhysicalDevicePortabilitySubsetFeaturesKHR();
    $features->pNext = $portability;
    $portability->pNext = $features;

    vkGetPhysicalDeviceFeatures2($physical, $features);
})->throws(ValueError::class, 'loops');

it('reads the present id and present wait features through the chain', function (): void {
    [, $physical] = gpu();
    $wait = new VkPhysicalDevicePresentWaitFeaturesKHR();
    $id = new VkPhysicalDevicePresentIdFeaturesKHR();
    $id->pNext = $wait;
    $features = new VkPhysicalDeviceFeatures2();
    $features->pNext = $id;

    vkGetPhysicalDeviceFeatures2($physical, $features);

    vkEnumerateDeviceExtensionProperties($physical, null, $available);
    $names = array_map(fn (VkExtensionProperties $e): string => $e->extensionName, $available);
    expect($id->presentId)->toBe(in_array(VK_KHR_PRESENT_ID_EXTENSION_NAME, $names, true))
        ->and($wait->presentWait)->toBe(in_array(VK_KHR_PRESENT_WAIT_EXTENSION_NAME, $names, true));
});
