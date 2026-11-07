<?php

declare(strict_types=1);

// Site vulkan-bytes-length (outcome 1): Vulkan reads codeSize bytes of SPIR-V and size bytes of
// push constants from the string. A shorter string is read past its end.

beforeEach(fn () => requireProbeBuild());

it('refuses a string shorter than Vulkan reads, which is read past (SIGSEGV) without the refusal', function (string $code, string $message, bool $guardOnly): void {
    // A push-constant read is at most maxPushConstantsSize (256 on the NVIDIA box): past a short
    // string it stays inside the heap unless a guard-page allocator sits behind it, and only
    // macOS has one here (libgmalloc).
    if ($guardOnly && ! MAC) {
        test()->markTestSkipped('needs libgmalloc to fault on a read this short; Linux has no guard-page allocator here');
    }
    $kept = vkProbe($code, null);
    $off = vkProbe($code, 'vulkan-bytes-length', gmalloc: true);

    expect($kept['signal'])->toBeNull()
        ->and($kept['stdout'])->toContain('REFUSED ValueError')
        ->and($kept['stdout'])->toContain($message)
        ->and($off['signal'])->toBeIn([PROBE_SIGSEGV, PROBE_SIGBUS]);
})->with([
    'VkShaderModuleCreateInfo::$codeSize' => ["[, , \$device] = gpu();\n\$i = new VkShaderModuleCreateInfo();\n\$i->pCode = \"\\x03\\x02\\x23\\x07\";\n\$i->codeSize = 256 << 20;\nvkCreateShaderModule(\$device, \$i, 0, \$module);", 'holds 4 bytes, fewer than the 268435456 Vulkan reads', false],
    'vkCmdPushConstants' => ["\$cmd = commands();\nvkCmdPushConstants(\$cmd, flatLayout(), VK_SHADER_STAGE_FRAGMENT_BIT, 0, 16, 'x');\nvkEndCommandBuffer(\$cmd);", 'holds 1 bytes, fewer than the 16 Vulkan reads', true],
]);
