<?php

declare(strict_types=1);

require_once __DIR__ . '/../scripts/support.php';

$registry = <<<'XML'
<registry>
    <commands>
        <command><proto><type>VkResult</type> <name>vkCreateInstance</name></proto></command>
        <command api="vulkan"><proto><type>VkResult</type> <name>vkCreateDevice</name></proto></command>
        <command api="vulkansc"><proto><type>VkResult</type> <name>vkCreateDevice</name></proto></command>
        <command api="vulkansc"><proto><type>VkResult</type> <name>vkGetFaultData</name></proto></command>
        <command><proto><type>void</type> <name>vkTrimCommandPool</name></proto></command>
        <command name="vkTrimCommandPoolKHR" alias="vkTrimCommandPool"/>
        <command><proto><type>VkResult</type> <name>vkCreateSwapchainKHR</name></proto></command>
        <command><proto><type>VkResult</type> <name>vkDebugReportOld</name></proto></command>
    </commands>
    <feature api="vulkan,vulkansc" name="VK_VERSION_1_0">
        <require><command name="vkCreateInstance"/><command name="vkCreateDevice"/></require>
        <require><feature name="robustBufferAccess" struct="VkPhysicalDeviceFeatures"/></require>
    </feature>
    <feature api="vulkansc" name="VKSC_VERSION_1_0"><require><command name="vkGetFaultData"/></require></feature>
    <feature api="vulkan" name="VK_VERSION_1_1"><require><command name="vkTrimCommandPool"/><command name="vkCreateInstance"/></require></feature>
    <extensions>
        <extension name="VK_KHR_maintenance1" supported="vulkan"><require><command name="vkTrimCommandPoolKHR"/></require></extension>
        <extension name="VK_KHR_swapchain" supported="vulkan,vulkansc"><require><command name="vkCreateSwapchainKHR"/></require></extension>
        <extension name="VK_EXT_old" supported="vulkan" deprecatedby=""><require><command name="vkDebugReportOld"/></require></extension>
        <extension name="VK_EXT_off" supported="disabled"><require><command name="vkDebugReportOld"/></require></extension>
    </extensions>
</registry>
XML;

it('counts the commands Vulkan requires, under the first version or extension, without aliases, SC-only or deprecated', function () use ($registry): void {
    expect(support_counted($registry))->toBe([
        'VK_VERSION_1_0' => ['vkCreateDevice', 'vkCreateInstance'],
        'VK_VERSION_1_1' => ['vkTrimCommandPool'],
        'VK_KHR_swapchain' => ['vkCreateSwapchainKHR'],
    ]);
});

it('reads the top-level functions of a stub, not class methods', function (): void {
    $stub = "<?php\nfunction vkCreateInstance(VkInstanceCreateInfo \$info): VkInstance {}\nfinal class VkInstance { public function pointer(): int {} }\nfunction vk_loader_path(): ?string {}\n";

    expect(support_functions($stub))->toBe(['vkCreateInstance', 'vk_loader_path']);
});

it('renders one line per command and lists the bindings that match none', function (): void {
    $md = support_render(['VK_VERSION_1_0' => ['vkCreateDevice', 'vkCreateInstance']], ['vkCreateInstance' => true, 'vk_loader_path' => true], 'Vulkan 1.4.309', '2026-10-28');

    expect($md)->toContain('- [x] `vkCreateInstance`')
        ->toContain('- [ ] `vkCreateDevice`')
        ->toContain('## VK_VERSION_1_0 (1 / 2)')
        ->toContain('Vulkan 1.4.309 — 1 / 2 members bound (50.0%) — 2026-10-28')
        ->toContain('- `vk_loader_path`');
});

it('computes the badge from the counts', function (): void {
    expect(support_badge('Vulkan API', 97, 605))
        ->toBe('[![Vulkan API](https://img.shields.io/badge/Vulkan_API-16.0%25_%2897%2F605%29-blue?style=flat-square)](SUPPORT.md)');
});

it('compares a support list without its date', function (): void {
    expect(support_same("Vulkan 1.4.309 — 2 / 4 members bound (50.0%) — 2026-10-28\n", "Vulkan 1.4.309 — 2 / 4 members bound (50.0%) — 2026-11-01\n"))->toBeTrue();
});
