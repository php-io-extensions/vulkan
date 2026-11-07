<?php

declare(strict_types=1);

// Site vulkan-list-count (outcome 1): Vulkan reads count elements of the C array built from the
// list, a function's count argument or a struct's count member. A count past the list is read
// past the array; past an empty list Vulkan reads NULL.

beforeEach(fn () => requireProbeBuild());

it('refuses a count past its list, which Vulkan reads past (SIGSEGV) without the refusal', function (string $code, string $message): void {
    $kept = vkProbe($code, null);
    $off = vkProbe($code, 'vulkan-list-count', gmalloc: true);

    expect($kept['signal'])->toBeNull()
        ->and($kept['stdout'])->toContain('REFUSED ValueError')
        ->and($kept['stdout'])->toContain($message)
        ->and($off['signal'])->toBeIn([PROBE_SIGSEGV, PROBE_SIGBUS]);
})->with([
    'vkCmdSetViewport' => ["\$cmd = commands();\nvkCmdSetViewport(\$cmd, 0, 1 << 20, []);\nvkEndCommandBuffer(\$cmd);", 'must not pass the length of argument #4 ($pViewports)'],
    'vkCmdBindVertexBuffers' => ["\$cmd = commands();\nvkCmdBindVertexBuffers(\$cmd, 0, 1, [], []);\nvkEndCommandBuffer(\$cmd);", 'must not pass the length of argument #4 ($pBuffers)'],
    'VkSubmitInfo::$commandBufferCount' => ["[, , , \$queue] = gpu();\n\$cmd = commands();\nvkEndCommandBuffer(\$cmd);\n\$s = new VkSubmitInfo();\n\$s->commandBufferCount = 1 << 20;\n\$s->pCommandBuffers = [\$cmd];\nvkQueueSubmit(\$queue, 1, [\$s], null);\nvkQueueWaitIdle(\$queue);", 'VkSubmitInfo::$pCommandBuffers holds 1 values, fewer than its count 1048576'],
    'VkPipelineLayoutCreateInfo::$setLayoutCount' => ["[, , \$device] = gpu();\n\$i = new VkPipelineLayoutCreateInfo();\n\$i->setLayoutCount = 1 << 20;\nvkCreatePipelineLayout(\$device, \$i, 0, \$layout);", 'VkPipelineLayoutCreateInfo::$pSetLayouts holds 0 values, fewer than its count 1048576'],
]);
