<?php

/*
 * proof_enumerate.php — Wave 0's proof, on both boxes, with no window.
 *
 * Loads the Bridge, creates a real VkInstance through the struct tier,
 * loads the instance level, enumerates the physical devices, prints each
 * one's name and API version, checks the availability contract, and destroys
 * everything it made. Prints PROOF_ENUMERATE_OK when all of that held.
 *
 * Everything opinionated is HERE, not in the extension: the sType values, the
 * portability-enumeration flag MoltenVK requires, the API version asked for.
 * Constants are inlined with their vk.xml citation until jovian/vulkan mines
 * them.
 */

declare(strict_types=1);

use Vulkan\Bridge\Bridge;
use Vulkan\Struct\VkApplicationInfo\VkApplicationInfo;
use Vulkan\Struct\VkInstanceCreateInfo\VkInstanceCreateInfo;
use Vulkan\Struct\VkPhysicalDeviceProperties\VkPhysicalDeviceProperties;
use Vulkan\VK\VK10\VK10;

// vk.xml <enums name="VkStructureType"> / <enums name="VkResult"> /
// <enums name="VkInstanceCreateFlagBits"> — constants live in jovian/vulkan.
const VK_STRUCTURE_TYPE_APPLICATION_INFO = 0;
const VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO = 1;
const VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR = 0x00000001;
const VK_SUCCESS = 0;

function vkVersion(int $major, int $minor, int $patch): int
{
    return ($major << 22) | ($minor << 12) | $patch;
}

function fail(string $m): never
{
    fwrite(STDERR, "PROOF_ENUMERATE_FAILED: {$m}\n");
    exit(1);
}

Bridge::load() || fail('Bridge::load');

$loaderVersion = Bridge::version();
printf("loader: %d.%d.%d\n", $loaderVersion >> 22, ($loaderVersion >> 12) & 0x3ff, $loaderVersion & 0xfff);

/*
 * MoltenVK is a portability driver: the loader hides its physical devices
 * unless the instance asks for them. That is the driver's rule, not this
 * extension's — see .okf/traps/moltenvk-portability.md.
 */
$isDarwin = PHP_OS_FAMILY === 'Darwin';
$extNames = $isDarwin ? ['VK_KHR_portability_enumeration'] : [];

$extPtrs = array_map(static fn (string $n): int => Bridge::cstring($n), $extNames);
$extArray = Bridge::alloc(max(1, count($extPtrs)) * 8);
foreach ($extPtrs as $i => $p) {
    Bridge::write($extArray, $i * 8, pack('P', $p));
}

$appName = Bridge::cstring('proof_enumerate');
$app = VkApplicationInfo::pack([
    'sType' => VK_STRUCTURE_TYPE_APPLICATION_INFO,
    'pApplicationName' => $appName,
    'applicationVersion' => 1,
    'apiVersion' => vkVersion(1, 3, 0),
]);
$app !== 0 || fail('VkApplicationInfo::pack');

$create = VkInstanceCreateInfo::pack([
    'sType' => VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
    'flags' => $isDarwin ? VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR : 0,
    'pApplicationInfo' => $app,
    'enabledExtensionCount' => count($extPtrs),
    'ppEnabledExtensionNames' => $extArray,
]);
$create !== 0 || fail('VkInstanceCreateInfo::pack');

$instanceOut = Bridge::alloc(8);
$r = VK10::vkCreateInstance($create, 0, $instanceOut);
$r === VK_SUCCESS || fail("vkCreateInstance returned {$r}");
$instance = unpack('P', Bridge::read($instanceOut, 0, 8))[1];
$instance !== 0 || fail('vkCreateInstance succeeded but wrote a null handle');
Bridge::loadInstance($instance) || fail('loadInstance');

$countOut = Bridge::alloc(4);
VK10::vkEnumeratePhysicalDevices($instance, $countOut, 0) === VK_SUCCESS || fail('enumerate count');
$count = unpack('V', Bridge::read($countOut, 0, 4))[1];
$count > 0 || fail('no physical devices');

$devs = Bridge::alloc($count * 8);
VK10::vkEnumeratePhysicalDevices($instance, $countOut, $devs) === VK_SUCCESS || fail('enumerate list');

$props = Bridge::alloc(VkPhysicalDeviceProperties::size());
for ($i = 0; $i < $count; $i++) {
    $pd = unpack('P', Bridge::read($devs, $i * 8, 8))[1];
    VK10::vkGetPhysicalDeviceProperties($pd, $props);
    $p = VkPhysicalDeviceProperties::unpack($props);
    printf(
        "device %d: %s api %d.%d.%d\n",
        $i,
        $p['deviceName'],
        $p['apiVersion'] >> 22,
        ($p['apiVersion'] >> 12) & 0x3ff,
        $p['apiVersion'] & 0xfff
    );
}

// The availability contract: resolution IS availability here, because the
// loader answers NULL for a command the instance cannot make.
Bridge::isAvailable('vkEnumeratePhysicalDeviceGroups') || fail('a 1.1 instance command should resolve');
Bridge::isAvailable('vkNotACommand') && fail('a made-up name resolved');

VK10::vkDestroyInstance($instance, 0);

foreach ([$props, $devs, $countOut, $instanceOut, $create, $app, $appName, $extArray, ...$extPtrs] as $b) {
    Bridge::free($b);
}

echo "PROOF_ENUMERATE_OK\n";
