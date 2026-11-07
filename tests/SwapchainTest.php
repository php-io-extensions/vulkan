<?php

declare(strict_types=1);

it('makes a swapchain on an SDL window\'s surface, acquires an image without waiting and presents it', function (): void {
    SDL_Init(SDL_INIT_VIDEO) || throw new RuntimeException(SDL_GetError());
    $window = SDL_CreateWindow('ext-vulkan swapchain', 160, 120, SDL_WINDOW_VULKAN);
    $extensions = SDL_Vulkan_GetInstanceExtensions();

    $info = portabilityInstance($extensions);
    vkCreateInstance($info, 0, $instance);
    SDL_Vulkan_CreateSurface($window, $instance->pointer(), null, $surfaceAddress) || throw new RuntimeException(SDL_GetError());
    $surface = VkSurfaceKHR::fromPointer($surfaceAddress);

    vkEnumeratePhysicalDevices($instance, $count, null);
    vkEnumeratePhysicalDevices($instance, $count, $devices);
    $physical = array_values(array_filter($devices, function (VkPhysicalDevice $d): bool {
        vkGetPhysicalDeviceProperties($d, $p);
        return $p->deviceType !== VK_PHYSICAL_DEVICE_TYPE_CPU;
    }))[0];
    vkGetPhysicalDeviceSurfaceSupportKHR($physical, 0, $surface, $supported);
    vkGetPhysicalDeviceSurfaceCapabilitiesKHR($physical, $surface, $capabilities);
    vkGetPhysicalDeviceSurfaceFormatsKHR($physical, $surface, $count, null);
    vkGetPhysicalDeviceSurfaceFormatsKHR($physical, $surface, $count, $formats);
    vkGetPhysicalDeviceSurfacePresentModesKHR($physical, $surface, $count, null);
    vkGetPhysicalDeviceSurfacePresentModesKHR($physical, $surface, $count, $modes);

    expect($supported)->toBeTrue()
        ->and($formats)->not->toBe([])
        ->and($modes)->toContain(VK_PRESENT_MODE_FIFO_KHR);

    $queueInfo = new VkDeviceQueueCreateInfo();
    $queueInfo->queueCount = 1;
    $queueInfo->pQueuePriorities = [1.0];
    $deviceInfo = new VkDeviceCreateInfo();
    $deviceInfo->queueCreateInfoCount = 1;
    $deviceInfo->pQueueCreateInfos = [$queueInfo];
    $deviceInfo->ppEnabledExtensionNames = [VK_KHR_SWAPCHAIN_EXTENSION_NAME];
    $deviceInfo->enabledExtensionCount = count($deviceInfo->ppEnabledExtensionNames);
    vkCreateDevice($physical, portabilityDevice($physical, $deviceInfo), 0, $device);
    vkGetDeviceQueue($device, 0, 0, $queue);

    $swapInfo = new VkSwapchainCreateInfoKHR();
    $swapInfo->surface = $surface;
    $swapInfo->minImageCount = max(2, $capabilities->minImageCount);
    $swapInfo->imageFormat = $formats[0]->format;
    $swapInfo->imageColorSpace = $formats[0]->colorSpace;
    $swapInfo->imageExtent = $capabilities->currentExtent->width === 0xFFFFFFFF
        ? tap(new VkExtent2D(), fn (VkExtent2D $e) => [$e->width, $e->height] = [160, 120])
        : $capabilities->currentExtent;
    $swapInfo->imageArrayLayers = 1;
    $swapInfo->imageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT;
    $swapInfo->preTransform = $capabilities->currentTransform;
    $swapInfo->compositeAlpha = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
    $swapInfo->presentMode = VK_PRESENT_MODE_FIFO_KHR;
    $swapInfo->clipped = true;

    expect(vkCreateSwapchainKHR($device, $swapInfo, 0, $swapchain))->toBe(VK_SUCCESS)
        ->and(vkGetSwapchainImagesKHR($device, $swapchain, $count, null))->toBe(VK_SUCCESS)
        ->and(vkGetSwapchainImagesKHR($device, $swapchain, $count, $images))->toBe(VK_SUCCESS)
        ->and($images)->not->toBe([]);

    vkCreateFence($device, new VkFenceCreateInfo(), 0, $fence);
    $acquired = vkAcquireNextImageKHR($device, $swapchain, 0, null, $fence, $index);
    expect($acquired)->toBeIn([VK_SUCCESS, VK_SUBOPTIMAL_KHR, VK_NOT_READY, VK_TIMEOUT]);

    if (in_array($acquired, [VK_SUCCESS, VK_SUBOPTIMAL_KHR], true)) {
        vkWaitForFences($device, 1, [$fence], true, PHP_INT_MAX);
        $cmd = commandsOn($device, 0);
        vkCmdPipelineBarrier($cmd, VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT, 0, 0, [], 0, [], 1, [layoutBarrier($images[$index], VK_IMAGE_LAYOUT_UNDEFINED, VK_IMAGE_LAYOUT_PRESENT_SRC_KHR, 0, 0)]);
        submitAndWaitOn($device, $queue, $cmd);
        $present = new VkPresentInfoKHR();
        $present->swapchainCount = 1;
        $present->pSwapchains = [$swapchain];
        $present->pImageIndices = [$index];
        expect(vkQueuePresentKHR($queue, $present))->toBeIn([VK_SUCCESS, VK_SUBOPTIMAL_KHR]);
    }

    vkDeviceWaitIdle($device);
    vkDestroySwapchainKHR($device, $swapchain, 0);
    expect($images[0]->pointer())->toBe(0);
    vkDestroyDevice($device, 0);
    vkDestroySurfaceKHR($instance, $surface, 0);
    vkDestroyInstance($instance, 0);
    SDL_DestroyWindow($window);
})->skip(! extension_loaded('sdl3') || PHP_OS_FAMILY === 'Darwin', 'needs ext-sdl3 and a Linux display');

it('presents only changed rects with an id, waits for that present, and sets HDR metadata', function (): void {
    SDL_Init(SDL_INIT_VIDEO) || throw new RuntimeException(SDL_GetError());
    $window = SDL_CreateWindow('ext-vulkan present', 160, 120, SDL_WINDOW_VULKAN);
    vkCreateInstance(portabilityInstance(SDL_Vulkan_GetInstanceExtensions()), 0, $instance);
    SDL_Vulkan_CreateSurface($window, $instance->pointer(), null, $surfaceAddress) || throw new RuntimeException(SDL_GetError());
    $surface = VkSurfaceKHR::fromPointer($surfaceAddress);
    vkEnumeratePhysicalDevices($instance, $count, null);
    vkEnumeratePhysicalDevices($instance, $count, $devices);
    $physical = array_values(array_filter($devices, function (VkPhysicalDevice $d): bool {
        vkGetPhysicalDeviceProperties($d, $p);
        return $p->deviceType !== VK_PHYSICAL_DEVICE_TYPE_CPU;
    }))[0];
    vkGetPhysicalDeviceSurfaceCapabilitiesKHR($physical, $surface, $capabilities);
    vkGetPhysicalDeviceSurfaceFormatsKHR($physical, $surface, $count, null);
    vkGetPhysicalDeviceSurfaceFormatsKHR($physical, $surface, $count, $formats);

    $wait = new VkPhysicalDevicePresentWaitFeaturesKHR();
    $wait->presentWait = true;
    $id = new VkPhysicalDevicePresentIdFeaturesKHR();
    $id->presentId = true;
    $id->pNext = $wait;
    $queueInfo = new VkDeviceQueueCreateInfo();
    $queueInfo->queueCount = 1;
    $queueInfo->pQueuePriorities = [1.0];
    $deviceInfo = new VkDeviceCreateInfo();
    $deviceInfo->pNext = $id;
    $deviceInfo->queueCreateInfoCount = 1;
    $deviceInfo->pQueueCreateInfos = [$queueInfo];
    $deviceInfo->ppEnabledExtensionNames = [VK_KHR_SWAPCHAIN_EXTENSION_NAME, VK_KHR_INCREMENTAL_PRESENT_EXTENSION_NAME, VK_KHR_PRESENT_ID_EXTENSION_NAME, VK_KHR_PRESENT_WAIT_EXTENSION_NAME, VK_EXT_HDR_METADATA_EXTENSION_NAME];
    $deviceInfo->enabledExtensionCount = count($deviceInfo->ppEnabledExtensionNames);
    expect(vkCreateDevice($physical, portabilityDevice($physical, $deviceInfo), 0, $device))->toBe(VK_SUCCESS);
    vkGetDeviceQueue($device, 0, 0, $queue);

    $swapInfo = new VkSwapchainCreateInfoKHR();
    $swapInfo->surface = $surface;
    $swapInfo->minImageCount = max(2, $capabilities->minImageCount);
    $swapInfo->imageFormat = $formats[0]->format;
    $swapInfo->imageColorSpace = $formats[0]->colorSpace;
    $swapInfo->imageExtent = $capabilities->currentExtent->width === 0xFFFFFFFF
        ? tap(new VkExtent2D(), fn (VkExtent2D $e) => [$e->width, $e->height] = [160, 120])
        : $capabilities->currentExtent;
    $swapInfo->imageArrayLayers = 1;
    $swapInfo->imageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
    $swapInfo->preTransform = $capabilities->currentTransform;
    $swapInfo->compositeAlpha = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
    $swapInfo->presentMode = VK_PRESENT_MODE_FIFO_KHR;
    $swapInfo->clipped = true;
    vkCreateSwapchainKHR($device, $swapInfo, 0, $swapchain);
    vkGetSwapchainImagesKHR($device, $swapchain, $count, null);
    vkGetSwapchainImagesKHR($device, $swapchain, $count, $images);

    $meta = new VkHdrMetadataEXT();
    [$meta->displayPrimaryRed->x, $meta->displayPrimaryRed->y] = [0.708, 0.292];
    [$meta->whitePoint->x, $meta->whitePoint->y] = [0.3127, 0.329];
    [$meta->maxLuminance, $meta->minLuminance] = [1000.0, 0.005];
    vkSetHdrMetadataEXT($device, 1, [$swapchain], [$meta]);
    expect(fn () => vkSetHdrMetadataEXT($device, 1, [$swapchain], []))->toThrow(ValueError::class, 'must not pass the length of argument #4 ($pMetadata)');

    vkCreateFence($device, new VkFenceCreateInfo(), 0, $fence);
    expect(vkAcquireNextImageKHR($device, $swapchain, PHP_INT_MAX, null, $fence, $index))->toBeIn([VK_SUCCESS, VK_SUBOPTIMAL_KHR]);
    vkWaitForFences($device, 1, [$fence], true, PHP_INT_MAX);
    $cmd = commandsOn($device, 0);
    vkCmdPipelineBarrier($cmd, VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT, 0, 0, [], 0, [], 1, [layoutBarrier($images[$index], VK_IMAGE_LAYOUT_UNDEFINED, VK_IMAGE_LAYOUT_PRESENT_SRC_KHR, 0, 0)]);
    submitAndWaitOn($device, $queue, $cmd);

    $rect = new VkRectLayerKHR();
    [$rect->offset->x, $rect->offset->y, $rect->extent->width, $rect->extent->height] = [8, 8, 16, 16];
    $region = new VkPresentRegionKHR();
    $region->rectangleCount = 1;
    $region->pRectangles = [$rect];
    $regions = new VkPresentRegionsKHR();
    $regions->swapchainCount = 1;
    $regions->pRegions = [$region];
    $ids = new VkPresentIdKHR();
    $ids->swapchainCount = 1;
    $ids->pPresentIds = [7];
    $ids->pNext = $regions;
    $present = new VkPresentInfoKHR();
    $present->pNext = $ids;
    $present->swapchainCount = 1;
    $present->pSwapchains = [$swapchain];
    $present->pImageIndices = [$index];

    expect(vkQueuePresentKHR($queue, $present))->toBeIn([VK_SUCCESS, VK_SUBOPTIMAL_KHR])
        ->and(vkWaitForPresentKHR($device, $swapchain, 7, 2_000_000_000))->toBeIn([VK_SUCCESS, VK_SUBOPTIMAL_KHR]);

    $regions->pRegions = ['not a region'];
    expect(fn () => vkQueuePresentKHR($queue, $present))->toThrow(TypeError::class, 'VkPresentRegionsKHR::$pRegions must be a list of VkPresentRegionKHR');

    vkDeviceWaitIdle($device);
    vkDestroySwapchainKHR($device, $swapchain, 0);
    vkDestroyDevice($device, 0);
    vkDestroySurfaceKHR($instance, $surface, 0);
    vkDestroyInstance($instance, 0);
    SDL_DestroyWindow($window);
})->skip(! extension_loaded('sdl3') || PHP_OS_FAMILY === 'Darwin', 'needs ext-sdl3 and a Linux display');

it('refuses HDR metadata on a device without its extension', function (): void {
    [, , $device] = gpu();

    try {
        vkSetHdrMetadataEXT($device, 0, [], []);
        $refused = null;
    } catch (Error $e) {
        $refused = $e->getMessage();
    }
    if ($refused === null) {
        test()->markTestSkipped('this Vulkan implementation hands out vkSetHdrMetadataEXT although its extension is not enabled');
    }

    expect($refused)->toBe('vkSetHdrMetadataEXT(): the loader has no vkSetHdrMetadataEXT here: its extension is not enabled')
        ->and(new VkPresentRegionsKHR())->toBeInstanceOf(VkPresentRegionsKHR::class)
        ->and((new VkRectLayerKHR())->extent)->toBeInstanceOf(VkExtent2D::class)
        ->and((new VkHdrMetadataEXT())->whitePoint)->toBeInstanceOf(VkXYColorEXT::class);
});
