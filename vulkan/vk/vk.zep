namespace Vulkan\Vk;

use Vulkan\Vk\VkInstance;
use Vulkan\Vk\VkPhysicalDevice;
use Vulkan\Vk\VkDevice;
use Vulkan\Vk\VkQueue;
use Vulkan\Vk\VkSurface;
use Vulkan\Vk\VkSwapchain;

%{
#include "vulkan-api.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>
}%

/**
 * Vulkan entry points (static passthrough + thin C helpers).
 *
 * Window/surface creation lives in glfw — this class is instance/device/present.
 * Named Vulkan objects are returned as Zephir DTOs with an opaque `fd`.
 * Token constants (VK_*) live in a microscrap wrapper.
 */
class Vk
{
    public static function lastError() -> string
    {
        string result;
        %{
            const char *msg = php_vk_last_error();
            ZVAL_STRING(&result, msg ? msg : "");
        }%
        return result;
    }

    /**
     * @param array extensions List of instance extension name strings (e.g. from glfw)
     */
    public static function createInstance(array extensions = [], string appName = "php-io-extensions/vulkan") -> <VkInstance>
    {
        var instance;
        var ext;
        int fd = 0;
        int extCount;
        int i;
        int n;

        let extCount = count(extensions);
        let n = extCount;
        %{
            const char **exts = NULL;
            if (n > 0) {
                exts = (const char **) ecalloc((uint32_t) n, sizeof(char *));
            }
        }%

        let i = 0;
        for ext in extensions {
            if typeof ext == "string" {
                %{
                    if (exts && i < n) {
                        exts[i] = Z_STRVAL(ext);
                    }
                }%
            }
            let i = i + 1;
        }

        %{
            fd = (zend_long) php_vk_create_instance(exts, (uint32_t) n, Z_STRVAL(appName));
            if (exts) {
                efree((void *) exts);
            }
        }%

        let instance = new VkInstance();
        let instance->fd = fd;
        let instance->appName = appName;
        return instance;
    }

    public static function destroyInstance(<VkInstance> instance) -> void
    {
        int fd = 0;
        let fd = (int) instance->fd;
        %{
            php_vk_destroy_instance((uintptr_t) fd);
        }%
        let instance->fd = 0;
    }

    public static function enumeratePhysicalDevices(<VkInstance> instance) -> array
    {
        array result;
        var phys;
        int instFd = 0;
        int deviceCount = 0;
        int i = 0;
        int fd = 0;
        int deviceType = 0;
        int vendorId = 0;
        int deviceId = 0;
        string name;

        let result = [];
        let instFd = (int) instance->fd;
        %{
            deviceCount = (zend_long) php_vk_physical_device_count((uintptr_t) instFd);
        }%

        while i < deviceCount {
            %{
                char namebuf[256];
                fd = (zend_long) php_vk_physical_device_at((uintptr_t) instFd, (uint32_t) i);
                namebuf[0] = '\0';
                deviceType = 0;
                vendorId = 0;
                deviceId = 0;
                if (fd) {
                    php_vk_physical_device_name((uintptr_t) fd, namebuf, sizeof(namebuf));
                    deviceType = (zend_long) php_vk_physical_device_type((uintptr_t) fd);
                    vendorId = (zend_long) php_vk_physical_device_vendor_id((uintptr_t) fd);
                    deviceId = (zend_long) php_vk_physical_device_device_id((uintptr_t) fd);
                }
                ZVAL_STRING(&name, namebuf);
            }%

            let phys = new VkPhysicalDevice();
            let phys->fd = fd;
            let phys->name = name;
            let phys->deviceType = deviceType;
            let phys->vendorId = vendorId;
            let phys->deviceId = deviceId;
            let result[] = phys;
            let i = i + 1;
        }

        return result;
    }

    public static function findGraphicsPresentQueue(<VkPhysicalDevice> physical, <VkSurface> surface) -> int
    {
        int result = -1;
        int physFd = 0;
        int surfFd = 0;
        let physFd = (int) physical->fd;
        let surfFd = (int) surface->fd;
        %{
            result = (zend_long) php_vk_find_graphics_present_queue((uintptr_t) physFd, (uintptr_t) surfFd);
        }%
        return result;
    }

    public static function createDevice(<VkPhysicalDevice> physical, int queueFamily) -> <VkDevice>
    {
        var device;
        int fd = 0;
        int physFd = 0;
        let physFd = (int) physical->fd;
        %{
            fd = (zend_long) php_vk_create_device((uintptr_t) physFd, (int) queueFamily);
        }%
        let device = new VkDevice();
        let device->fd = fd;
        let device->queueFamily = queueFamily;
        return device;
    }

    public static function destroyDevice(<VkDevice> device) -> void
    {
        int fd = 0;
        let fd = (int) device->fd;
        %{
            php_vk_destroy_device((uintptr_t) fd);
        }%
        let device->fd = 0;
        let device->queueFamily = -1;
    }

    public static function getDeviceQueue(<VkDevice> device, int queueFamily) -> <VkQueue>
    {
        var queue;
        int fd = 0;
        int devFd = 0;
        let devFd = (int) device->fd;
        %{
            fd = (zend_long) php_vk_get_device_queue((uintptr_t) devFd, (int) queueFamily);
        }%
        let queue = new VkQueue();
        let queue->fd = fd;
        let queue->familyIndex = queueFamily;
        return queue;
    }

    /**
     * Wrap an existing VkSurfaceKHR pointer (e.g. from glfwCreateWindowSurface).
     */
    public static function wrapSurface(int surfaceFd) -> <VkSurface>
    {
        var surface;
        let surface = new VkSurface();
        let surface->fd = surfaceFd;
        return surface;
    }

    public static function destroySurface(<VkInstance> instance, <VkSurface> surface) -> void
    {
        int instFd = 0;
        int surfFd = 0;
        let instFd = (int) instance->fd;
        let surfFd = (int) surface->fd;
        %{
            php_vk_destroy_surface((uintptr_t) instFd, (uintptr_t) surfFd);
        }%
        let surface->fd = 0;
    }

    public static function createSwapchain(
        <VkInstance> instance,
        <VkPhysicalDevice> physical,
        <VkDevice> device,
        <VkQueue> queue,
        <VkSurface> surface,
        int width,
        int height
    ) -> <VkSwapchain> {
        var swapchain;
        int fd = 0;
        int instFd = 0;
        int physFd = 0;
        int devFd = 0;
        int queueFd = 0;
        int surfFd = 0;
        int w = 0;
        int h = 0;
        int fmt = 0;
        int images = 0;

        let instFd = (int) instance->fd;
        let physFd = (int) physical->fd;
        let devFd = (int) device->fd;
        let queueFd = (int) queue->fd;
        let surfFd = (int) surface->fd;

        %{
            fd = (zend_long) php_vk_swapchain_create(
                (uintptr_t) instFd,
                (uintptr_t) physFd,
                (uintptr_t) devFd,
                (uintptr_t) queueFd,
                (uintptr_t) surfFd,
                (uint32_t) width,
                (uint32_t) height
            );
            if (fd) {
                w = (zend_long) php_vk_swapchain_width((uintptr_t) fd);
                h = (zend_long) php_vk_swapchain_height((uintptr_t) fd);
                fmt = (zend_long) php_vk_swapchain_format((uintptr_t) fd);
                images = (zend_long) php_vk_swapchain_image_count((uintptr_t) fd);
            }
        }%

        let swapchain = new VkSwapchain();
        let swapchain->fd = fd;
        let swapchain->width = w;
        let swapchain->height = h;
        let swapchain->format = fmt;
        let swapchain->imageCount = images;
        return swapchain;
    }

    public static function destroySwapchain(<VkSwapchain> swapchain) -> void
    {
        int fd = 0;
        let fd = (int) swapchain->fd;
        %{
            php_vk_swapchain_destroy((uintptr_t) fd);
        }%
        let swapchain->fd = 0;
        let swapchain->width = 0;
        let swapchain->height = 0;
        let swapchain->format = 0;
        let swapchain->imageCount = 0;
    }

    public static function resizeSwapchain(<VkSwapchain> swapchain, int width, int height) -> int
    {
        int result = -1;
        int fd = 0;
        int w = 0;
        int h = 0;
        int fmt = 0;
        int images = 0;
        let fd = (int) swapchain->fd;
        %{
            result = (zend_long) php_vk_swapchain_resize((uintptr_t) fd, (uint32_t) width, (uint32_t) height);
            if (result == 0 && fd) {
                w = (zend_long) php_vk_swapchain_width((uintptr_t) fd);
                h = (zend_long) php_vk_swapchain_height((uintptr_t) fd);
                fmt = (zend_long) php_vk_swapchain_format((uintptr_t) fd);
                images = (zend_long) php_vk_swapchain_image_count((uintptr_t) fd);
            }
        }%
        if result == 0 {
            let swapchain->width = w;
            let swapchain->height = h;
            let swapchain->format = fmt;
            let swapchain->imageCount = images;
        }
        return result;
    }

    /**
     * Present one frame: clear background, optional menu + inner rects (pixel coords, top-left origin).
     * @return 0 success; VK_ERROR_OUT_OF_DATE_KHR (-1000001004) / VK_SUBOPTIMAL_KHR (1000001003) may occur
     */
    public static function presentFrame(
        <VkSwapchain> swapchain,
        float clearR,
        float clearG,
        float clearB,
        float clearA = 1.0,
        bool drawMenu = false,
        int menuX = 0,
        int menuY = 0,
        int menuW = 0,
        int menuH = 0,
        float menuR = 0.0,
        float menuG = 0.0,
        float menuB = 0.0,
        float menuA = 1.0,
        bool drawInner = false,
        int innerX = 0,
        int innerY = 0,
        int innerW = 0,
        int innerH = 0,
        float innerR = 0.0,
        float innerG = 0.0,
        float innerB = 0.0,
        float innerA = 1.0,
        bool drawAccent = false,
        int accentX = 0,
        int accentY = 0,
        int accentW = 0,
        int accentH = 0,
        float accentR = 0.0,
        float accentG = 0.0,
        float accentB = 0.0,
        float accentA = 1.0
    ) -> int {
        int result = -1;
        int fd = 0;
        int dm = 0;
        int di = 0;
        int da = 0;
        let fd = (int) swapchain->fd;
        if drawMenu {
            let dm = 1;
        }
        if drawInner {
            let di = 1;
        }
        if drawAccent {
            let da = 1;
        }
        %{
            result = (zend_long) php_vk_swapchain_frame(
                (uintptr_t) fd,
                (float) clearR,
                (float) clearG,
                (float) clearB,
                (float) clearA,
                (int) dm,
                (int) menuX,
                (int) menuY,
                (int) menuW,
                (int) menuH,
                (float) menuR,
                (float) menuG,
                (float) menuB,
                (float) menuA,
                (int) di,
                (int) innerX,
                (int) innerY,
                (int) innerW,
                (int) innerH,
                (float) innerR,
                (float) innerG,
                (float) innerB,
                (float) innerA,
                (int) da,
                (int) accentX,
                (int) accentY,
                (int) accentW,
                (int) accentH,
                (float) accentR,
                (float) accentG,
                (float) accentB,
                (float) accentA
            );
        }%
        return result;
    }
}
