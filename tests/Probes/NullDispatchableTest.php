<?php

declare(strict_types=1);

// Site vulkan-null-dispatchable (outcome 1): the loader reads its dispatch table through an
// instance, physical device, device, queue or command buffer. A released one goes to Vulkan as
// NULL, and the loader reads through NULL or aborts on it.

beforeEach(fn () => requireProbeBuild());

it('refuses a released dispatchable handle, which the loader reads through (SIGSEGV or SIGABRT) without the refusal', function (string $code, string $message): void {
    $kept = vkProbe($code, null);
    $off = vkProbe($code, 'vulkan-null-dispatchable');

    expect($kept['signal'])->toBeNull()
        ->and($kept['stdout'])->toContain('REFUSED ValueError')
        ->and($kept['stdout'])->toContain($message)
        ->and($off['signal'])->toBeIn([PROBE_SIGSEGV, PROBE_SIGBUS, PROBE_SIGABRT]);
})->with([
    'VkDevice' => ["[, \$physical, , , \$family] = gpu();\n\$q = new VkDeviceQueueCreateInfo();\n\$q->queueFamilyIndex = \$family;\n\$q->queueCount = 1;\n\$q->pQueuePriorities = [1.0];\n\$d = new VkDeviceCreateInfo();\n\$d->queueCreateInfoCount = 1;\n\$d->pQueueCreateInfos = [\$q];\nvkCreateDevice(\$physical, portabilityDevice(\$physical, \$d), 0, \$device);\nvkDestroyDevice(\$device, 0);\nvkDeviceWaitIdle(\$device);", 'VkDevice has been released'],
    'VkCommandBuffer' => ["[, , \$device, , \$family] = gpu();\n\$p = new VkCommandPoolCreateInfo();\n\$p->queueFamilyIndex = \$family;\nvkCreateCommandPool(\$device, \$p, 0, \$pool);\n\$a = new VkCommandBufferAllocateInfo();\n\$a->commandPool = \$pool;\n\$a->commandBufferCount = 1;\nvkAllocateCommandBuffers(\$device, \$a, \$buffers);\nvkFreeCommandBuffers(\$device, \$pool, 1, \$buffers);\nvkEndCommandBuffer(\$buffers[0]);", 'VkCommandBuffer has been released'],
    'VkInstance' => ["vkCreateInstance(portabilityInstance(), 0, \$instance);\nvkDestroyInstance(\$instance, 0);\nvkEnumeratePhysicalDevices(\$instance, \$count, null);", 'VkInstance has been released'],
]);
