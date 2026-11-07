<?php

declare(strict_types=1);

it('makes a surface over a CAMetalLayer and a swapchain on it', function (): void {
    $info = portabilityInstance([VK_KHR_SURFACE_EXTENSION_NAME, VK_EXT_METAL_SURFACE_EXTENSION_NAME]);
    expect(vkCreateInstance($info, 0, $instance))->toBe(VK_SUCCESS);

    $layer = CAMetalLayer::layer();
    $layer->setDevice(MTLCreateSystemDefaultDevice());
    $layer->setPixelFormat(MTLPixelFormat::BGRA8_UNORM);
    $layer->setDrawableSize(new NSSize(160.0, 120.0));
    $surfaceInfo = new VkMetalSurfaceCreateInfoEXT();
    $surfaceInfo->pLayer = $layer->pointer();

    expect(vkCreateMetalSurfaceEXT($instance, $surfaceInfo, 0, $surface))->toBe(VK_SUCCESS);

    vkEnumeratePhysicalDevices($instance, $count, null);

    vkEnumeratePhysicalDevices($instance, $count, $devices);
    $physical = $devices[0];
    vkGetPhysicalDeviceSurfaceSupportKHR($physical, 0, $surface, $supported);
    vkGetPhysicalDeviceSurfaceCapabilitiesKHR($physical, $surface, $capabilities);
    vkGetPhysicalDeviceSurfaceFormatsKHR($physical, $surface, $count, null);
    vkGetPhysicalDeviceSurfaceFormatsKHR($physical, $surface, $count, $formats);
    vkGetPhysicalDeviceSurfacePresentModesKHR($physical, $surface, $count, null);
    vkGetPhysicalDeviceSurfacePresentModesKHR($physical, $surface, $count, $modes);

    expect($supported)->toBeTrue()
        ->and(array_map(fn (VkSurfaceFormatKHR $f): int => $f->format, $formats))->toContain(VK_FORMAT_B8G8R8A8_UNORM)
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

    $swapInfo = new VkSwapchainCreateInfoKHR();
    $swapInfo->surface = $surface;
    $swapInfo->minImageCount = max(2, $capabilities->minImageCount);
    $swapInfo->imageFormat = VK_FORMAT_B8G8R8A8_UNORM;
    $swapInfo->imageColorSpace = VK_COLOR_SPACE_SRGB_NONLINEAR_KHR;
    $swapInfo->imageExtent = tap(new VkExtent2D(), fn (VkExtent2D $e) => [$e->width, $e->height] = [160, 120]);
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
    expect(vkAcquireNextImageKHR($device, $swapchain, 0, null, $fence, $index))
        ->toBeIn([VK_SUCCESS, VK_SUBOPTIMAL_KHR, VK_NOT_READY, VK_TIMEOUT]);

    vkDeviceWaitIdle($device);
    vkDestroySwapchainKHR($device, $swapchain, 0);
    vkDestroyDevice($device, 0);
    vkDestroyInstance($instance, 0);
    expect($surface->pointer())->toBe(0);
})->skip(PHP_OS_FAMILY !== 'Darwin' || ! extension_loaded('metal'), 'needs macOS and ext-metal');
