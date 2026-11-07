<?php

declare(strict_types=1);

// Site vulkan-no-proc (outcome 1): an extension's command comes from vkGetDeviceProcAddr, which
// answers NULL when the device has not enabled that extension. Calling the NULL is a crash.

beforeEach(fn () => requireProbeBuild());

it('refuses an extension command the device has not enabled, which is a call through NULL (SIGSEGV) without the refusal', function (string $code, string $message): void {
    $kept = vkProbe($code, null);
    if (! str_contains($kept['stdout'], 'REFUSED') && str_contains($kept['stdout'], 'SURVIVED')) {
        test()->markTestSkipped('this Vulkan implementation hands out the command although its extension is not enabled: there is no NULL to call');
    }
    $off = vkProbe($code, 'vulkan-no-proc');

    expect($kept['signal'])->toBeNull()
        ->and($kept['stdout'])->toContain('REFUSED Error')
        ->and($kept['stdout'])->toContain($message)
        ->and($off['signal'])->toBeIn([PROBE_SIGSEGV, PROBE_SIGBUS]);
})->with([
    'vkSetHdrMetadataEXT' => ["[, , \$device] = gpu();\nvkSetHdrMetadataEXT(\$device, 0, [], []);", 'the loader has no vkSetHdrMetadataEXT here'],
    'vkGetMemoryFdKHR' => ["[, , \$device] = gpu();\n\$i = new VkMemoryGetFdInfoKHR();\nvkGetMemoryFdKHR(\$device, \$i, \$fd);", 'the loader has no vkGetMemoryFdKHR here'],
]);
