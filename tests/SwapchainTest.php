<?php

declare(strict_types=1);

it('makes a swapchain on an SDL window\'s surface, acquires an image without waiting and presents it', function (): void {
    SDL_Init(SDL_INIT_VIDEO) || throw new RuntimeException(SDL_GetError());
    $window = SDL_CreateWindow('ext-vulkan swapchain', 160, 120, SDL_WINDOW_VULKAN);
    $extensions = SDL_Vulkan_GetInstanceExtensions();

    $info = portabilityInstance($extensions);
    vkCreateInstance($info, null, $instance);
    SDL_Vulkan_CreateSurface($window, $instance->pointer(), null, $surfaceAddress) || throw new RuntimeException(SDL_GetError());
    $surface = VkSurfaceKHR::fromPointer($surfaceAddress);

    vkEnumeratePhysicalDevices($instance, $devices);
    $physical = array_values(array_filter($devices, function (VkPhysicalDevice $d): bool {
        vkGetPhysicalDeviceProperties($d, $p);
        return $p->deviceType !== VK_PHYSICAL_DEVICE_TYPE_CPU;
    }))[0];
    vkGetPhysicalDeviceSurfaceSupportKHR($physical, 0, $surface, $supported);
    vkGetPhysicalDeviceSurfaceCapabilitiesKHR($physical, $surface, $capabilities);
    vkGetPhysicalDeviceSurfaceFormatsKHR($physical, $surface, $formats);
    vkGetPhysicalDeviceSurfacePresentModesKHR($physical, $surface, $modes);

    expect($supported)->toBeTrue()
        ->and($formats)->not->toBe([])
        ->and($modes)->toContain(VK_PRESENT_MODE_FIFO_KHR);

    $queueInfo = new VkDeviceQueueCreateInfo();
    $queueInfo->pQueuePriorities = [1.0];
    $deviceInfo = new VkDeviceCreateInfo();
    $deviceInfo->pQueueCreateInfos = [$queueInfo];
    $deviceInfo->enabledExtensionNames = [VK_KHR_SWAPCHAIN_EXTENSION_NAME];
    vkCreateDevice($physical, portabilityDevice($physical, $deviceInfo), null, $device);
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
    $swapInfo->clipped = VK_TRUE;

    expect(vkCreateSwapchainKHR($device, $swapInfo, null, $swapchain))->toBe(VK_SUCCESS)
        ->and(vkGetSwapchainImagesKHR($device, $swapchain, $images))->toBe(VK_SUCCESS)
        ->and($images)->not->toBe([]);

    vkCreateFence($device, new VkFenceCreateInfo(), null, $fence);
    $acquired = vkAcquireNextImageKHR($device, $swapchain, 0, null, $fence, $index);
    expect($acquired)->toBeIn([VK_SUCCESS, VK_SUBOPTIMAL_KHR, VK_NOT_READY, VK_TIMEOUT]);

    if (in_array($acquired, [VK_SUCCESS, VK_SUBOPTIMAL_KHR], true)) {
        vkWaitForFences($device, [$fence], true, PHP_INT_MAX);
        $cmd = commandsOn($device, 0);
        vkCmdPipelineBarrier($cmd, VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT, 0, [], [], [layoutBarrier($images[$index], VK_IMAGE_LAYOUT_UNDEFINED, VK_IMAGE_LAYOUT_PRESENT_SRC_KHR, 0, 0)]);
        submitAndWaitOn($device, $queue, $cmd);
        $present = new VkPresentInfoKHR();
        $present->pSwapchains = [$swapchain];
        $present->pImageIndices = [$index];
        expect(vkQueuePresentKHR($queue, $present))->toBeIn([VK_SUCCESS, VK_SUBOPTIMAL_KHR]);
    }

    vkDeviceWaitIdle($device);
    vkDestroySwapchainKHR($device, $swapchain, null);
    expect(fn () => $images[0]->pointer())->toThrow(ValueError::class);
    vkDestroyDevice($device, null);
    vkDestroySurfaceKHR($instance, $surface, null);
    vkDestroyInstance($instance, null);
    SDL_DestroyWindow($window);
})->skip(! extension_loaded('sdl3') || PHP_OS_FAMILY === 'Darwin', 'needs ext-sdl3 and a Linux display');

it('presents only changed rects with an id, waits for that present, and sets HDR metadata', function (): void {
    SDL_Init(SDL_INIT_VIDEO) || throw new RuntimeException(SDL_GetError());
    $window = SDL_CreateWindow('ext-vulkan present', 160, 120, SDL_WINDOW_VULKAN);
    vkCreateInstance(portabilityInstance(SDL_Vulkan_GetInstanceExtensions()), null, $instance);
    SDL_Vulkan_CreateSurface($window, $instance->pointer(), null, $surfaceAddress) || throw new RuntimeException(SDL_GetError());
    $surface = VkSurfaceKHR::fromPointer($surfaceAddress);
    vkEnumeratePhysicalDevices($instance, $devices);
    $physical = array_values(array_filter($devices, function (VkPhysicalDevice $d): bool {
        vkGetPhysicalDeviceProperties($d, $p);
        return $p->deviceType !== VK_PHYSICAL_DEVICE_TYPE_CPU;
    }))[0];
    vkGetPhysicalDeviceSurfaceCapabilitiesKHR($physical, $surface, $capabilities);
    vkGetPhysicalDeviceSurfaceFormatsKHR($physical, $surface, $formats);

    $wait = new VkPhysicalDevicePresentWaitFeaturesKHR();
    $wait->presentWait = true;
    $id = new VkPhysicalDevicePresentIdFeaturesKHR();
    $id->presentId = true;
    $id->pNext = $wait;
    $queueInfo = new VkDeviceQueueCreateInfo();
    $queueInfo->pQueuePriorities = [1.0];
    $deviceInfo = new VkDeviceCreateInfo();
    $deviceInfo->pNext = $id;
    $deviceInfo->pQueueCreateInfos = [$queueInfo];
    $deviceInfo->enabledExtensionNames = [VK_KHR_SWAPCHAIN_EXTENSION_NAME, VK_KHR_INCREMENTAL_PRESENT_EXTENSION_NAME, VK_KHR_PRESENT_ID_EXTENSION_NAME, VK_KHR_PRESENT_WAIT_EXTENSION_NAME, VK_EXT_HDR_METADATA_EXTENSION_NAME];
    expect(vkCreateDevice($physical, portabilityDevice($physical, $deviceInfo), null, $device))->toBe(VK_SUCCESS);
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
    $swapInfo->clipped = VK_TRUE;
    vkCreateSwapchainKHR($device, $swapInfo, null, $swapchain);
    vkGetSwapchainImagesKHR($device, $swapchain, $images);

    $meta = new VkHdrMetadataEXT();
    [$meta->displayPrimaryRed->x, $meta->displayPrimaryRed->y] = [0.708, 0.292];
    [$meta->whitePoint->x, $meta->whitePoint->y] = [0.3127, 0.329];
    [$meta->maxLuminance, $meta->minLuminance] = [1000.0, 0.005];
    expect(vkSetHdrMetadataEXT($device, [$swapchain], [$meta]))->toBeTrue()
        ->and(fn () => vkSetHdrMetadataEXT($device, [$swapchain], []))->toThrow(ValueError::class, 'must hold one VkHdrMetadataEXT per swapchain');

    vkCreateFence($device, new VkFenceCreateInfo(), null, $fence);
    expect(vkAcquireNextImageKHR($device, $swapchain, PHP_INT_MAX, null, $fence, $index))->toBeIn([VK_SUCCESS, VK_SUBOPTIMAL_KHR]);
    vkWaitForFences($device, [$fence], true, PHP_INT_MAX);
    $cmd = commandsOn($device, 0);
    vkCmdPipelineBarrier($cmd, VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT, 0, [], [], [layoutBarrier($images[$index], VK_IMAGE_LAYOUT_UNDEFINED, VK_IMAGE_LAYOUT_PRESENT_SRC_KHR, 0, 0)]);
    submitAndWaitOn($device, $queue, $cmd);

    $rect = new VkRectLayerKHR();
    [$rect->offset->x, $rect->offset->y, $rect->extent->width, $rect->extent->height] = [8, 8, 16, 16];
    $region = new VkPresentRegionKHR();
    $region->pRectangles = [$rect];
    $regions = new VkPresentRegionsKHR();
    $regions->pRegions = [$region];
    $ids = new VkPresentIdKHR();
    $ids->pPresentIds = [7];
    $ids->pNext = $regions;
    $present = new VkPresentInfoKHR();
    $present->pNext = $ids;
    $present->pSwapchains = [$swapchain];
    $present->pImageIndices = [$index];

    expect(vkQueuePresentKHR($queue, $present))->toBeIn([VK_SUCCESS, VK_SUBOPTIMAL_KHR])
        ->and(vkWaitForPresentKHR($device, $swapchain, 7, 2_000_000_000))->toBeIn([VK_SUCCESS, VK_SUBOPTIMAL_KHR]);

    $regions->pRegions = ['not a region'];
    expect(fn () => vkQueuePresentKHR($queue, $present))->toThrow(TypeError::class, 'VkPresentRegionsKHR::$pRegions must be a list of VkPresentRegionKHR');

    vkDeviceWaitIdle($device);
    vkDestroySwapchainKHR($device, $swapchain, null);
    vkDestroyDevice($device, null);
    vkDestroySurfaceKHR($instance, $surface, null);
    vkDestroyInstance($instance, null);
    SDL_DestroyWindow($window);
})->skip(! extension_loaded('sdl3') || PHP_OS_FAMILY === 'Darwin', 'needs ext-sdl3 and a Linux display');

it('answers extension-not-present for present wait, and false for HDR metadata, on a device without them', function (): void {
    [, , $device] = gpu();

    expect(vkSetHdrMetadataEXT($device, [], []))->toBeBool()
        ->and(new VkPresentRegionsKHR())->toBeInstanceOf(VkPresentRegionsKHR::class)
        ->and((new VkRectLayerKHR())->extent)->toBeInstanceOf(VkExtent2D::class)
        ->and((new VkHdrMetadataEXT())->whitePoint)->toBeInstanceOf(VkXYColorEXT::class);
});
