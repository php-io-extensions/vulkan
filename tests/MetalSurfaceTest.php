<?php

declare(strict_types=1);

it('makes a surface over a CAMetalLayer and a swapchain on it', function (): void {
    $info = portabilityInstance([VK_KHR_SURFACE_EXTENSION_NAME, VK_EXT_METAL_SURFACE_EXTENSION_NAME]);
    expect(vkCreateInstance($info, null, $instance))->toBe(VK_SUCCESS);

    $layer = CAMetalLayer::layer();
    $layer->setDevice(MTLCreateSystemDefaultDevice());
    $layer->setPixelFormat(MTLPixelFormat::BGRA8_UNORM);
    $layer->setDrawableSize(new CGSize(160.0, 120.0));
    $surfaceInfo = new VkMetalSurfaceCreateInfoEXT();
    $surfaceInfo->pLayer = $layer->pointer();

    expect(vkCreateMetalSurfaceEXT($instance, $surfaceInfo, null, $surface))->toBe(VK_SUCCESS);

    vkEnumeratePhysicalDevices($instance, $devices);
    $physical = $devices[0];
    vkGetPhysicalDeviceSurfaceSupportKHR($physical, 0, $surface, $supported);
    vkGetPhysicalDeviceSurfaceCapabilitiesKHR($physical, $surface, $capabilities);
    vkGetPhysicalDeviceSurfaceFormatsKHR($physical, $surface, $formats);
    vkGetPhysicalDeviceSurfacePresentModesKHR($physical, $surface, $modes);

    expect($supported)->toBeTrue()
        ->and(array_map(fn (VkSurfaceFormatKHR $f): int => $f->format, $formats))->toContain(VK_FORMAT_B8G8R8A8_UNORM)
        ->and($modes)->toContain(VK_PRESENT_MODE_FIFO_KHR);

    $queueInfo = new VkDeviceQueueCreateInfo();
    $queueInfo->pQueuePriorities = [1.0];
    $deviceInfo = new VkDeviceCreateInfo();
    $deviceInfo->pQueueCreateInfos = [$queueInfo];
    $deviceInfo->enabledExtensionNames = [VK_KHR_SWAPCHAIN_EXTENSION_NAME];
    vkCreateDevice($physical, portabilityDevice($physical, $deviceInfo), null, $device);

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
    $swapInfo->clipped = VK_TRUE;

    expect(vkCreateSwapchainKHR($device, $swapInfo, null, $swapchain))->toBe(VK_SUCCESS)
        ->and(vkGetSwapchainImagesKHR($device, $swapchain, $images))->toBe(VK_SUCCESS)
        ->and($images)->not->toBe([]);

    vkCreateFence($device, new VkFenceCreateInfo(), null, $fence);
    expect(vkAcquireNextImageKHR($device, $swapchain, 0, null, $fence, $index))
        ->toBeIn([VK_SUCCESS, VK_SUBOPTIMAL_KHR, VK_NOT_READY, VK_TIMEOUT]);

    vkDeviceWaitIdle($device);
    vkDestroySwapchainKHR($device, $swapchain, null);
    vkDestroyDevice($device, null);
    vkDestroyInstance($instance, null);
    expect(fn () => $surface->pointer())->toThrow(ValueError::class, 'VkSurfaceKHR has been destroyed');
})->skip(PHP_OS_FAMILY !== 'Darwin' || ! extension_loaded('metal'), 'needs macOS and ext-metal');
