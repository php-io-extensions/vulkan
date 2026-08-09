<?php
/**
 * vulkan extension — visual proof with on-screen Quit menu
 *
 * Opens a GLFW window (peer extension, CLIENT_API = NO_API) and presents
 * with Vulkan\Vk\Vk (animated clear + accent square + Quit menu rects).
 *
 * Controls:
 *   Click the Quit bar — exit
 *   Enter / Return — activate Quit
 *   ESC or window close — exit
 *
 * Usage:
 *   php -d extension=./ext/modules/vulkan.so examples/proof_menu.php
 *
 * Requires the glfw extension. On Homebrew Darwin, MoltenVK ICD is auto-probed
 * when VK_ICD_FILENAMES is unset.
 *
 * Smoke:
 *   VULKAN_PROOF_SECONDS=2 php examples/proof_menu.php
 */

declare(strict_types=1);

use Glfw\GLFW\GLFW;
use Glfw\GLFW\GLFWError;
use Glfw\GLFW\Window\GLFWWindow;
use Glfw\GLFW\Input\GLFWInput;
use Glfw\GLFW\Vulkan\GLFWVulkan;
use Vulkan\Vk\Vk;

const GLFW_KEY_ESCAPE = 256;
const GLFW_KEY_ENTER = 257;
const GLFW_KEY_KP_ENTER = 335;
const GLFW_PRESS = 1;
const GLFW_MOUSE_BUTTON_LEFT = 0;
const GLFW_CLIENT_API = 0x00022001;
const GLFW_NO_API = 0;
const GLFW_RESIZABLE = 0x00020003;

const VK_SUCCESS = 0;
const VK_SUBOPTIMAL_KHR = 1000001003;
const VK_ERROR_OUT_OF_DATE_KHR = -1000001004;

function hsv_to_rgb(float $h, float $s, float $v): array
{
    $i = (int) floor($h * 6.0);
    $f = $h * 6.0 - $i;
    $p = $v * (1.0 - $s);
    $q = $v * (1.0 - $f * $s);
    $t = $v * (1.0 - (1.0 - $f) * $s);

    return match ($i % 6) {
        0 => [$v, $t, $p],
        1 => [$q, $v, $p],
        2 => [$p, $v, $t],
        3 => [$p, $q, $v],
        4 => [$t, $p, $v],
        default => [$v, $p, $q],
    };
}

if (!extension_loaded('glfw')) {
    fwrite(STDERR, "glfw extension is NOT loaded (needed for the window/surface).\n");
    exit(1);
}
if (!extension_loaded('vulkan')) {
    fwrite(STDERR, "vulkan extension is NOT loaded.\n");
    exit(1);
}

if (!GLFW::glfwInit()) {
    $err = GLFWError::glfwGetError();
    fwrite(STDERR, "glfwInit failed: {$err['description']}\n");
    exit(1);
}

if (!GLFWVulkan::glfwVulkanSupported()) {
    fwrite(STDERR, "glfwVulkanSupported() returned false (is libvulkan on DYLD_LIBRARY_PATH?).\n");
    GLFW::glfwTerminate();
    exit(1);
}

$required = GLFWVulkan::glfwGetRequiredInstanceExtensions();
echo 'Instance extensions: ' . implode(', ', $required) . PHP_EOL;

$instance = Vk::createInstance($required, 'php-io-extensions/vulkan');
if ($instance->fd === 0) {
    fwrite(STDERR, 'vkCreateInstance failed: ' . Vk::lastError() . PHP_EOL);
    GLFW::glfwTerminate();
    exit(1);
}

$devices = Vk::enumeratePhysicalDevices($instance);
if ($devices === [] || $devices[0]->fd === 0) {
    fwrite(STDERR, "no Vulkan physical devices\n");
    Vk::destroyInstance($instance);
    GLFW::glfwTerminate();
    exit(1);
}
$physical = $devices[0];
echo "Device: {$physical->name}\n";

GLFWWindow::glfwDefaultWindowHints();
GLFWWindow::glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
GLFWWindow::glfwWindowHint(GLFW_RESIZABLE, 1);

try {
    $window = GLFWWindow::glfwCreateWindow(400, 600, 'vulkan demo — Quit menu');
} catch (Throwable $e) {
    fwrite(STDERR, $e->getMessage() . PHP_EOL);
    Vk::destroyInstance($instance);
    GLFW::glfwTerminate();
    exit(1);
}

$surfResult = GLFWVulkan::glfwCreateWindowSurface($instance->fd, $window, 0);
if (($surfResult['result'] ?? 1) !== VK_SUCCESS || ($surfResult['surface'] ?? 0) === 0) {
    fwrite(STDERR, 'glfwCreateWindowSurface failed: result=' . ($surfResult['result'] ?? '?') . PHP_EOL);
    GLFWWindow::glfwDestroyWindow($window);
    Vk::destroyInstance($instance);
    GLFW::glfwTerminate();
    exit(1);
}
$surface = Vk::wrapSurface((int) $surfResult['surface']);

$queueFamily = Vk::findGraphicsPresentQueue($physical, $surface);
if ($queueFamily < 0) {
    fwrite(STDERR, "no graphics+present queue family\n");
    Vk::destroySurface($instance, $surface);
    GLFWWindow::glfwDestroyWindow($window);
    Vk::destroyInstance($instance);
    GLFW::glfwTerminate();
    exit(1);
}

$device = Vk::createDevice($physical, $queueFamily);
if ($device->fd === 0) {
    fwrite(STDERR, 'vkCreateDevice failed: ' . Vk::lastError() . PHP_EOL);
    Vk::destroySurface($instance, $surface);
    GLFWWindow::glfwDestroyWindow($window);
    Vk::destroyInstance($instance);
    GLFW::glfwTerminate();
    exit(1);
}
$queue = Vk::getDeviceQueue($device, $queueFamily);

$fb = GLFWWindow::glfwGetFramebufferSize($window);
$fbW = max(1, (int) ($fb['width'] ?? 960));
$fbH = max(1, (int) ($fb['height'] ?? 540));

$swapchain = Vk::createSwapchain($instance, $physical, $device, $queue, $surface, $fbW, $fbH);
if ($swapchain->fd === 0) {
    fwrite(STDERR, 'createSwapchain failed: ' . Vk::lastError() . PHP_EOL);
    Vk::destroyDevice($device);
    Vk::destroySurface($instance, $surface);
    GLFWWindow::glfwDestroyWindow($window);
    Vk::destroyInstance($instance);
    GLFW::glfwTerminate();
    exit(1);
}

echo "Swapchain {$swapchain->width}x{$swapchain->height} images={$swapchain->imageCount}\n";
echo "Menu: click Quit, or press Enter / ESC.\n";

$winW = 400;
$winH = 600;
$syncSize = static function (int $win) use (&$winW, &$winH, &$fbW, &$fbH, $swapchain): void {
    $ws = GLFWWindow::glfwGetWindowSize($win);
    $fb = GLFWWindow::glfwGetFramebufferSize($win);
    $winW = max(1, (int) $ws['width']);
    $winH = max(1, (int) $ws['height']);
    $fbW = max(1, (int) $fb['width']);
    $fbH = max(1, (int) $fb['height']);
    Vk::resizeSwapchain($swapchain, $fbW, $fbH);
};
$syncSize($window);

GLFWWindow::glfwSetFramebufferSizeCallback($window, function (int $win, int $w, int $h) use ($syncSize): void {
    $syncSize($win);
});

$quit = false;
GLFWInput::glfwSetKeyCallback($window, function (int $win, int $key, int $scancode, int $action, int $mods) use (&$quit): void {
    if ($action !== GLFW_PRESS) {
        return;
    }
    if ($key === GLFW_KEY_ESCAPE || $key === GLFW_KEY_ENTER || $key === GLFW_KEY_KP_ENTER) {
        $quit = true;
        GLFWWindow::glfwSetWindowShouldClose($win, 1);
    }
});

$autoQuit = getenv('VULKAN_PROOF_SECONDS');
$t0 = GLFWInput::glfwGetTime();
$autoQuitAt = ($autoQuit !== false && $autoQuit !== '')
    ? $t0 + (float) $autoQuit
    : null;

$prevClick = false;

while (!GLFWWindow::glfwWindowShouldClose($window) && !$quit) {
    $now = GLFWInput::glfwGetTime();
    if (!is_null($autoQuitAt) && $now >= $autoQuitAt) {
        break;
    }

    $menuX0 = 40.0;
    $menuY0 = 40.0;
    $menuX1 = 280.0;
    $menuY1 = 120.0;
    $pad = 12.0;
    $itemX0 = $menuX0 + $pad;
    $itemY0 = $menuY0 + $pad;
    $itemX1 = $menuX1 - $pad;
    $itemY1 = $menuY1 - $pad;

    $cursor = GLFWInput::glfwGetCursorPos($window);
    $cx = (float) ($cursor['xpos'] ?? $cursor['x'] ?? $cursor[0] ?? 0);
    $cy = (float) ($cursor['ypos'] ?? $cursor['y'] ?? $cursor[1] ?? 0);
    $hover = ($cx >= $itemX0 && $cx <= $itemX1 && $cy >= $itemY0 && $cy <= $itemY1);

    $click = GLFWInput::glfwGetMouseButton($window, GLFW_MOUSE_BUTTON_LEFT) === GLFW_PRESS;
    if ($hover && $click && !$prevClick) {
        $quit = true;
        GLFWWindow::glfwSetWindowShouldClose($window, 1);
    }
    $prevClick = $click;

    $scaleX = $fbW / max(1.0, (float) $winW);
    $scaleY = $fbH / max(1.0, (float) $winH);

    $hue = fmod($now * 0.12, 1.0);
    [$br, $bg, $bb] = hsv_to_rgb($hue, 0.45, 0.28);
    [$tr, $tg, $tb] = hsv_to_rgb(fmod($hue + 0.35, 1.0), 0.85, 0.95);

    $cxScreen = $winW * 0.62;
    $cyScreen = $winH * 0.42;
    $s = 90.0 + 20.0 * sin($now * 2.0);

    if ($hover) {
        $itemR = 0.75;
        $itemG = 0.25;
        $itemB = 0.22;
    } else {
        $itemR = 0.35;
        $itemG = 0.38;
        $itemB = 0.45;
    }

    $rc = Vk::presentFrame(
        $swapchain,
        $br,
        $bg,
        $bb,
        1.0,
        true,
        (int) round($menuX0 * $scaleX),
        (int) round($menuY0 * $scaleY),
        (int) round(($menuX1 - $menuX0) * $scaleX),
        (int) round(($menuY1 - $menuY0) * $scaleY),
        0.08,
        0.09,
        0.12,
        1.0,
        true,
        (int) round($itemX0 * $scaleX),
        (int) round($itemY0 * $scaleY),
        (int) round(($itemX1 - $itemX0) * $scaleX),
        (int) round(($itemY1 - $itemY0) * $scaleY),
        $itemR,
        $itemG,
        $itemB,
        1.0,
        true,
        (int) round(($cxScreen - $s) * $scaleX),
        (int) round(($cyScreen - $s) * $scaleY),
        (int) round((2.0 * $s) * $scaleX),
        (int) round((2.0 * $s) * $scaleY),
        $tr,
        $tg,
        $tb,
        1.0
    );

    if ($rc === VK_ERROR_OUT_OF_DATE_KHR || $rc === VK_SUBOPTIMAL_KHR) {
        $syncSize($window);
    } elseif ($rc !== VK_SUCCESS) {
        fwrite(STDERR, 'presentFrame failed: ' . $rc . ' ' . Vk::lastError() . PHP_EOL);
        break;
    }

    GLFWWindow::glfwPollEvents();
}

Vk::destroySwapchain($swapchain);
Vk::destroyDevice($device);
Vk::destroySurface($instance, $surface);
GLFWWindow::glfwDestroyWindow($window);
Vk::destroyInstance($instance);
GLFW::glfwTerminate();

echo "Quit selected — window closed cleanly.\n";
exit(0);
