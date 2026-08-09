#include "vulkan-api.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VK_USE_PLATFORM_METAL_EXT 1
#include <vulkan/vulkan.h>

#ifndef VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME
#define VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME "VK_KHR_portability_enumeration"
#endif

#ifndef VK_KHR_PORTABILITY_SUBSET_EXTENSION_NAME
#define VK_KHR_PORTABILITY_SUBSET_EXTENSION_NAME "VK_KHR_portability_subset"
#endif

static char php_vk_errbuf[512] = {0};

const char *php_vk_last_error(void)
{
	return php_vk_errbuf;
}

static void php_vk_set_error(const char *msg)
{
	if (!msg) {
		php_vk_errbuf[0] = '\0';
		return;
	}
	snprintf(php_vk_errbuf, sizeof(php_vk_errbuf), "%s", msg);
}

static void php_vk_set_errorf(const char *fmt, int code)
{
	snprintf(php_vk_errbuf, sizeof(php_vk_errbuf), fmt, code);
}

void php_vk_ensure_loader(void)
{
#if defined(__APPLE__)
	const char *existing = getenv("VK_ICD_FILENAMES");
	if (existing && existing[0] != '\0') {
		return;
	}
	existing = getenv("VK_DRIVER_FILES");
	if (existing && existing[0] != '\0') {
		return;
	}

	static const char *candidates[] = {
		"/opt/homebrew/etc/vulkan/icd.d/MoltenVK_icd.json",
		"/usr/local/etc/vulkan/icd.d/MoltenVK_icd.json",
		NULL
	};
	for (int i = 0; candidates[i]; i++) {
		FILE *f = fopen(candidates[i], "r");
		if (f) {
			fclose(f);
			setenv("VK_ICD_FILENAMES", candidates[i], 0);
			setenv("VK_DRIVER_FILES", candidates[i], 0);
			return;
		}
	}
#endif
}

uintptr_t php_vk_create_instance(const char **extensions, uint32_t extension_count, const char *app_name)
{
	php_vk_ensure_loader();
	php_vk_set_error(NULL);

	const char *wanted[64];
	uint32_t wanted_count = 0;

	for (uint32_t i = 0; i < extension_count && wanted_count < 62; i++) {
		if (extensions[i] && extensions[i][0]) {
			wanted[wanted_count++] = extensions[i];
		}
	}

	int have_portability = 0;
	for (uint32_t i = 0; i < wanted_count; i++) {
		if (strcmp(wanted[i], VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME) == 0) {
			have_portability = 1;
			break;
		}
	}
#if defined(__APPLE__)
	if (!have_portability && wanted_count < 63) {
		wanted[wanted_count++] = VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME;
		have_portability = 1;
	}
#else
	(void) have_portability;
#endif

	VkApplicationInfo app_info;
	memset(&app_info, 0, sizeof(app_info));
	app_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	app_info.pApplicationName = app_name && app_name[0] ? app_name : "php-io-extensions/vulkan";
	app_info.applicationVersion = VK_MAKE_VERSION(0, 7, 0);
	app_info.pEngineName = "php-io-extensions";
	app_info.engineVersion = VK_MAKE_VERSION(0, 7, 0);
	app_info.apiVersion = VK_API_VERSION_1_1;

	VkInstanceCreateInfo ci;
	memset(&ci, 0, sizeof(ci));
	ci.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	ci.pApplicationInfo = &app_info;
	ci.enabledExtensionCount = wanted_count;
	ci.ppEnabledExtensionNames = wanted_count ? wanted : NULL;
#if defined(__APPLE__)
	ci.flags |= VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR;
#endif

	VkInstance instance = VK_NULL_HANDLE;
	VkResult r = vkCreateInstance(&ci, NULL, &instance);
	if (r != VK_SUCCESS) {
		php_vk_set_errorf("vkCreateInstance failed: %d", (int) r);
		return 0;
	}
	return (uintptr_t) instance;
}

void php_vk_destroy_instance(uintptr_t instance)
{
	if (!instance) {
		return;
	}
	vkDestroyInstance((VkInstance) instance, NULL);
}

uint32_t php_vk_physical_device_count(uintptr_t instance)
{
	if (!instance) {
		return 0;
	}
	uint32_t count = 0;
	vkEnumeratePhysicalDevices((VkInstance) instance, &count, NULL);
	return count;
}

uintptr_t php_vk_physical_device_at(uintptr_t instance, uint32_t index)
{
	if (!instance) {
		return 0;
	}
	uint32_t count = 0;
	vkEnumeratePhysicalDevices((VkInstance) instance, &count, NULL);
	if (index >= count || count == 0) {
		return 0;
	}
	VkPhysicalDevice *devs = (VkPhysicalDevice *) calloc(count, sizeof(VkPhysicalDevice));
	if (!devs) {
		return 0;
	}
	vkEnumeratePhysicalDevices((VkInstance) instance, &count, devs);
	uintptr_t out = (uintptr_t) devs[index];
	free(devs);
	return out;
}

int php_vk_physical_device_name(uintptr_t physical, char *buf, size_t buflen)
{
	if (!physical || !buf || buflen == 0) {
		return -1;
	}
	VkPhysicalDeviceProperties props;
	vkGetPhysicalDeviceProperties((VkPhysicalDevice) physical, &props);
	snprintf(buf, buflen, "%s", props.deviceName);
	return (int) strlen(buf);
}

uint32_t php_vk_physical_device_type(uintptr_t physical)
{
	if (!physical) {
		return 0;
	}
	VkPhysicalDeviceProperties props;
	vkGetPhysicalDeviceProperties((VkPhysicalDevice) physical, &props);
	return (uint32_t) props.deviceType;
}

uint32_t php_vk_physical_device_vendor_id(uintptr_t physical)
{
	if (!physical) {
		return 0;
	}
	VkPhysicalDeviceProperties props;
	vkGetPhysicalDeviceProperties((VkPhysicalDevice) physical, &props);
	return props.vendorID;
}

uint32_t php_vk_physical_device_device_id(uintptr_t physical)
{
	if (!physical) {
		return 0;
	}
	VkPhysicalDeviceProperties props;
	vkGetPhysicalDeviceProperties((VkPhysicalDevice) physical, &props);
	return props.deviceID;
}

int php_vk_find_graphics_present_queue(uintptr_t physical, uintptr_t surface)
{
	if (!physical || !surface) {
		return -1;
	}
	uint32_t count = 0;
	vkGetPhysicalDeviceQueueFamilyProperties((VkPhysicalDevice) physical, &count, NULL);
	if (count == 0) {
		return -1;
	}
	VkQueueFamilyProperties *props = (VkQueueFamilyProperties *) calloc(count, sizeof(VkQueueFamilyProperties));
	if (!props) {
		return -1;
	}
	vkGetPhysicalDeviceQueueFamilyProperties((VkPhysicalDevice) physical, &count, props);

	int found = -1;
	for (uint32_t i = 0; i < count; i++) {
		VkBool32 present = VK_FALSE;
		vkGetPhysicalDeviceSurfaceSupportKHR(
			(VkPhysicalDevice) physical,
			i,
			(VkSurfaceKHR) surface,
			&present
		);
		if ((props[i].queueFlags & VK_QUEUE_GRAPHICS_BIT) && present) {
			found = (int) i;
			break;
		}
	}
	free(props);
	return found;
}

uintptr_t php_vk_create_device(uintptr_t physical, int queue_family)
{
	php_vk_set_error(NULL);
	if (!physical || queue_family < 0) {
		php_vk_set_error("invalid physical device or queue family");
		return 0;
	}

	float priority = 1.0f;
	VkDeviceQueueCreateInfo qci;
	memset(&qci, 0, sizeof(qci));
	qci.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
	qci.queueFamilyIndex = (uint32_t) queue_family;
	qci.queueCount = 1;
	qci.pQueuePriorities = &priority;

	const char *exts[4];
	uint32_t ext_count = 0;
	exts[ext_count++] = VK_KHR_SWAPCHAIN_EXTENSION_NAME;
#if defined(__APPLE__)
	exts[ext_count++] = VK_KHR_PORTABILITY_SUBSET_EXTENSION_NAME;
#endif

	VkDeviceCreateInfo dci;
	memset(&dci, 0, sizeof(dci));
	dci.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
	dci.queueCreateInfoCount = 1;
	dci.pQueueCreateInfos = &qci;
	dci.enabledExtensionCount = ext_count;
	dci.ppEnabledExtensionNames = exts;

	VkDevice device = VK_NULL_HANDLE;
	VkResult r = vkCreateDevice((VkPhysicalDevice) physical, &dci, NULL, &device);
	if (r != VK_SUCCESS) {
		php_vk_set_errorf("vkCreateDevice failed: %d", (int) r);
		return 0;
	}
	return (uintptr_t) device;
}

void php_vk_destroy_device(uintptr_t device)
{
	if (!device) {
		return;
	}
	vkDestroyDevice((VkDevice) device, NULL);
}

uintptr_t php_vk_get_device_queue(uintptr_t device, int queue_family)
{
	if (!device || queue_family < 0) {
		return 0;
	}
	VkQueue queue = VK_NULL_HANDLE;
	vkGetDeviceQueue((VkDevice) device, (uint32_t) queue_family, 0, &queue);
	return (uintptr_t) queue;
}

void php_vk_destroy_surface(uintptr_t instance, uintptr_t surface)
{
	if (!instance || !surface) {
		return;
	}
	vkDestroySurfaceKHR((VkInstance) instance, (VkSurfaceKHR) surface, NULL);
}

#define PHP_VK_MAX_IMAGES 8

typedef struct php_vk_swapchain {
	VkInstance instance;
	VkPhysicalDevice physical;
	VkDevice device;
	VkQueue queue;
	VkSurfaceKHR surface;
	VkSwapchainKHR swapchain;
	VkFormat format;
	VkExtent2D extent;
	uint32_t image_count;
	VkImage images[PHP_VK_MAX_IMAGES];
	VkImageView views[PHP_VK_MAX_IMAGES];
	VkFramebuffer framebuffers[PHP_VK_MAX_IMAGES];
	VkRenderPass render_pass;
	VkCommandPool command_pool;
	VkCommandBuffer command_buffers[PHP_VK_MAX_IMAGES];
	VkSemaphore image_available;
	VkSemaphore render_finished;
	VkFence in_flight;
} php_vk_swapchain;

static void php_vk_swapchain_teardown_images(php_vk_swapchain *sc)
{
	if (!sc || !sc->device) {
		return;
	}
	for (uint32_t i = 0; i < sc->image_count; i++) {
		if (sc->framebuffers[i]) {
			vkDestroyFramebuffer(sc->device, sc->framebuffers[i], NULL);
			sc->framebuffers[i] = VK_NULL_HANDLE;
		}
		if (sc->views[i]) {
			vkDestroyImageView(sc->device, sc->views[i], NULL);
			sc->views[i] = VK_NULL_HANDLE;
		}
		sc->images[i] = VK_NULL_HANDLE;
	}
	sc->image_count = 0;
	if (sc->swapchain) {
		vkDestroySwapchainKHR(sc->device, sc->swapchain, NULL);
		sc->swapchain = VK_NULL_HANDLE;
	}
}

static int php_vk_swapchain_build(php_vk_swapchain *sc, uint32_t width, uint32_t height)
{
	VkSurfaceCapabilitiesKHR caps;
	VkResult r = vkGetPhysicalDeviceSurfaceCapabilitiesKHR(sc->physical, sc->surface, &caps);
	if (r != VK_SUCCESS) {
		php_vk_set_errorf("vkGetPhysicalDeviceSurfaceCapabilitiesKHR failed: %d", (int) r);
		return (int) r;
	}

	uint32_t format_count = 0;
	vkGetPhysicalDeviceSurfaceFormatsKHR(sc->physical, sc->surface, &format_count, NULL);
	if (format_count == 0) {
		php_vk_set_error("no surface formats");
		return -1;
	}
	VkSurfaceFormatKHR *formats = (VkSurfaceFormatKHR *) calloc(format_count, sizeof(VkSurfaceFormatKHR));
	if (!formats) {
		php_vk_set_error("oom formats");
		return -1;
	}
	vkGetPhysicalDeviceSurfaceFormatsKHR(sc->physical, sc->surface, &format_count, formats);

	VkSurfaceFormatKHR chosen = formats[0];
	for (uint32_t i = 0; i < format_count; i++) {
		if (formats[i].format == VK_FORMAT_B8G8R8A8_UNORM || formats[i].format == VK_FORMAT_R8G8B8A8_UNORM) {
			chosen = formats[i];
			break;
		}
	}
	free(formats);
	sc->format = chosen.format;

	if (caps.currentExtent.width != UINT32_MAX) {
		sc->extent = caps.currentExtent;
	} else {
		sc->extent.width = width;
		sc->extent.height = height;
		if (sc->extent.width < caps.minImageExtent.width) {
			sc->extent.width = caps.minImageExtent.width;
		}
		if (sc->extent.height < caps.minImageExtent.height) {
			sc->extent.height = caps.minImageExtent.height;
		}
		if (sc->extent.width > caps.maxImageExtent.width) {
			sc->extent.width = caps.maxImageExtent.width;
		}
		if (sc->extent.height > caps.maxImageExtent.height) {
			sc->extent.height = caps.maxImageExtent.height;
		}
	}
	if (sc->extent.width == 0 || sc->extent.height == 0) {
		php_vk_set_error("swapchain extent is zero");
		return -1;
	}

	uint32_t image_count = caps.minImageCount + 1;
	if (caps.maxImageCount > 0 && image_count > caps.maxImageCount) {
		image_count = caps.maxImageCount;
	}
	if (image_count > PHP_VK_MAX_IMAGES) {
		image_count = PHP_VK_MAX_IMAGES;
	}

	/* Prefer uncapped present (MAILBOX → IMMEDIATE → FIFO). FIFO VSync half-rates
	 * PHP sketch loops when a frame exceeds one refresh (~30fps @60Hz). Sketch
	 * FramePaceNode owns the 60fps budget (same rationale as cuda-gfx swapInterval(0)). */
	VkPresentModeKHR present_mode = VK_PRESENT_MODE_FIFO_KHR;
	uint32_t mode_count = 0;
	vkGetPhysicalDeviceSurfacePresentModesKHR(sc->physical, sc->surface, &mode_count, NULL);
	if (mode_count > 0) {
		VkPresentModeKHR *modes = (VkPresentModeKHR *) calloc(mode_count, sizeof(VkPresentModeKHR));
		if (modes) {
			vkGetPhysicalDeviceSurfacePresentModesKHR(sc->physical, sc->surface, &mode_count, modes);
			int has_mailbox = 0;
			int has_immediate = 0;
			for (uint32_t i = 0; i < mode_count; i++) {
				if (modes[i] == VK_PRESENT_MODE_MAILBOX_KHR) {
					has_mailbox = 1;
				} else if (modes[i] == VK_PRESENT_MODE_IMMEDIATE_KHR) {
					has_immediate = 1;
				}
			}
			if (has_mailbox) {
				present_mode = VK_PRESENT_MODE_MAILBOX_KHR;
			} else if (has_immediate) {
				present_mode = VK_PRESENT_MODE_IMMEDIATE_KHR;
			}
			free(modes);
		}
	}

	VkSwapchainCreateInfoKHR sci;
	memset(&sci, 0, sizeof(sci));
	sci.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
	sci.surface = sc->surface;
	sci.minImageCount = image_count;
	sci.imageFormat = chosen.format;
	sci.imageColorSpace = chosen.colorSpace;
	sci.imageExtent = sc->extent;
	sci.imageArrayLayers = 1;
	sci.imageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
	sci.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
	sci.preTransform = caps.currentTransform;
	sci.compositeAlpha = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
	sci.presentMode = present_mode;
	sci.clipped = VK_TRUE;
	sci.oldSwapchain = VK_NULL_HANDLE;

	r = vkCreateSwapchainKHR(sc->device, &sci, NULL, &sc->swapchain);
	if (r != VK_SUCCESS) {
		php_vk_set_errorf("vkCreateSwapchainKHR failed: %d", (int) r);
		return (int) r;
	}

	sc->image_count = 0;
	vkGetSwapchainImagesKHR(sc->device, sc->swapchain, &sc->image_count, NULL);
	if (sc->image_count > PHP_VK_MAX_IMAGES) {
		sc->image_count = PHP_VK_MAX_IMAGES;
	}
	r = vkGetSwapchainImagesKHR(sc->device, sc->swapchain, &sc->image_count, sc->images);
	if (r != VK_SUCCESS) {
		php_vk_set_errorf("vkGetSwapchainImagesKHR failed: %d", (int) r);
		return (int) r;
	}

	for (uint32_t i = 0; i < sc->image_count; i++) {
		VkImageViewCreateInfo vci;
		memset(&vci, 0, sizeof(vci));
		vci.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
		vci.image = sc->images[i];
		vci.viewType = VK_IMAGE_VIEW_TYPE_2D;
		vci.format = sc->format;
		vci.components.r = VK_COMPONENT_SWIZZLE_IDENTITY;
		vci.components.g = VK_COMPONENT_SWIZZLE_IDENTITY;
		vci.components.b = VK_COMPONENT_SWIZZLE_IDENTITY;
		vci.components.a = VK_COMPONENT_SWIZZLE_IDENTITY;
		vci.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
		vci.subresourceRange.baseMipLevel = 0;
		vci.subresourceRange.levelCount = 1;
		vci.subresourceRange.baseArrayLayer = 0;
		vci.subresourceRange.layerCount = 1;
		r = vkCreateImageView(sc->device, &vci, NULL, &sc->views[i]);
		if (r != VK_SUCCESS) {
			php_vk_set_errorf("vkCreateImageView failed: %d", (int) r);
			return (int) r;
		}

		VkFramebufferCreateInfo fci;
		memset(&fci, 0, sizeof(fci));
		fci.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
		fci.renderPass = sc->render_pass;
		fci.attachmentCount = 1;
		fci.pAttachments = &sc->views[i];
		fci.width = sc->extent.width;
		fci.height = sc->extent.height;
		fci.layers = 1;
		r = vkCreateFramebuffer(sc->device, &fci, NULL, &sc->framebuffers[i]);
		if (r != VK_SUCCESS) {
			php_vk_set_errorf("vkCreateFramebuffer failed: %d", (int) r);
			return (int) r;
		}
	}

	return 0;
}

uintptr_t php_vk_swapchain_create(
	uintptr_t instance,
	uintptr_t physical,
	uintptr_t device,
	uintptr_t queue,
	uintptr_t surface,
	uint32_t width,
	uint32_t height
) {
	php_vk_set_error(NULL);
	if (!instance || !physical || !device || !queue || !surface) {
		php_vk_set_error("swapchain_create: null handle");
		return 0;
	}

	php_vk_swapchain *sc = (php_vk_swapchain *) calloc(1, sizeof(php_vk_swapchain));
	if (!sc) {
		php_vk_set_error("oom swapchain");
		return 0;
	}
	sc->instance = (VkInstance) instance;
	sc->physical = (VkPhysicalDevice) physical;
	sc->device = (VkDevice) device;
	sc->queue = (VkQueue) queue;
	sc->surface = (VkSurfaceKHR) surface;

	VkAttachmentDescription color;
	memset(&color, 0, sizeof(color));
	/* format filled after surface query — temp, rebuilt after build? */
	/* We need render pass before framebuffers; pick a provisional format then recreate if mismatch. */
	uint32_t format_count = 0;
	vkGetPhysicalDeviceSurfaceFormatsKHR(sc->physical, sc->surface, &format_count, NULL);
	VkSurfaceFormatKHR *formats = (VkSurfaceFormatKHR *) calloc(format_count ? format_count : 1, sizeof(VkSurfaceFormatKHR));
	if (!formats || format_count == 0) {
		free(formats);
		free(sc);
		php_vk_set_error("no surface formats");
		return 0;
	}
	vkGetPhysicalDeviceSurfaceFormatsKHR(sc->physical, sc->surface, &format_count, formats);
	VkFormat fmt = formats[0].format;
	for (uint32_t i = 0; i < format_count; i++) {
		if (formats[i].format == VK_FORMAT_B8G8R8A8_UNORM || formats[i].format == VK_FORMAT_R8G8B8A8_UNORM) {
			fmt = formats[i].format;
			break;
		}
	}
	free(formats);
	sc->format = fmt;

	color.format = fmt;
	color.samples = VK_SAMPLE_COUNT_1_BIT;
	color.loadOp = VK_ATTACHMENT_LOAD_OP_CLEAR;
	color.storeOp = VK_ATTACHMENT_STORE_OP_STORE;
	color.stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
	color.stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
	color.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
	color.finalLayout = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;

	VkAttachmentReference color_ref;
	memset(&color_ref, 0, sizeof(color_ref));
	color_ref.attachment = 0;
	color_ref.layout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;

	VkSubpassDescription subpass;
	memset(&subpass, 0, sizeof(subpass));
	subpass.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;
	subpass.colorAttachmentCount = 1;
	subpass.pColorAttachments = &color_ref;

	VkSubpassDependency dep;
	memset(&dep, 0, sizeof(dep));
	dep.srcSubpass = VK_SUBPASS_EXTERNAL;
	dep.dstSubpass = 0;
	dep.srcStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
	dep.dstStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
	dep.srcAccessMask = 0;
	dep.dstAccessMask = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;

	VkRenderPassCreateInfo rpci;
	memset(&rpci, 0, sizeof(rpci));
	rpci.sType = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
	rpci.attachmentCount = 1;
	rpci.pAttachments = &color;
	rpci.subpassCount = 1;
	rpci.pSubpasses = &subpass;
	rpci.dependencyCount = 1;
	rpci.pDependencies = &dep;

	VkResult r = vkCreateRenderPass(sc->device, &rpci, NULL, &sc->render_pass);
	if (r != VK_SUCCESS) {
		php_vk_set_errorf("vkCreateRenderPass failed: %d", (int) r);
		free(sc);
		return 0;
	}

	VkCommandPoolCreateInfo pci;
	memset(&pci, 0, sizeof(pci));
	pci.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
	pci.flags = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
	/* queue family recovered via find — store on create path by querying */
	int qf = php_vk_find_graphics_present_queue((uintptr_t) sc->physical, (uintptr_t) sc->surface);
	if (qf < 0) {
		php_vk_set_error("no graphics+present queue for swapchain");
		vkDestroyRenderPass(sc->device, sc->render_pass, NULL);
		free(sc);
		return 0;
	}
	pci.queueFamilyIndex = (uint32_t) qf;
	r = vkCreateCommandPool(sc->device, &pci, NULL, &sc->command_pool);
	if (r != VK_SUCCESS) {
		php_vk_set_errorf("vkCreateCommandPool failed: %d", (int) r);
		vkDestroyRenderPass(sc->device, sc->render_pass, NULL);
		free(sc);
		return 0;
	}

	VkSemaphoreCreateInfo sci;
	memset(&sci, 0, sizeof(sci));
	sci.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;
	r = vkCreateSemaphore(sc->device, &sci, NULL, &sc->image_available);
	if (r != VK_SUCCESS) {
		php_vk_set_errorf("vkCreateSemaphore(image) failed: %d", (int) r);
		goto fail;
	}
	r = vkCreateSemaphore(sc->device, &sci, NULL, &sc->render_finished);
	if (r != VK_SUCCESS) {
		php_vk_set_errorf("vkCreateSemaphore(render) failed: %d", (int) r);
		goto fail;
	}
	VkFenceCreateInfo fci;
	memset(&fci, 0, sizeof(fci));
	fci.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
	fci.flags = VK_FENCE_CREATE_SIGNALED_BIT;
	r = vkCreateFence(sc->device, &fci, NULL, &sc->in_flight);
	if (r != VK_SUCCESS) {
		php_vk_set_errorf("vkCreateFence failed: %d", (int) r);
		goto fail;
	}

	if (php_vk_swapchain_build(sc, width, height) != 0) {
		goto fail;
	}

	VkCommandBufferAllocateInfo cai;
	memset(&cai, 0, sizeof(cai));
	cai.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
	cai.commandPool = sc->command_pool;
	cai.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
	cai.commandBufferCount = sc->image_count;
	r = vkAllocateCommandBuffers(sc->device, &cai, sc->command_buffers);
	if (r != VK_SUCCESS) {
		php_vk_set_errorf("vkAllocateCommandBuffers failed: %d", (int) r);
		goto fail;
	}

	return (uintptr_t) sc;

fail:
	php_vk_swapchain_destroy((uintptr_t) sc);
	return 0;
}

void php_vk_swapchain_destroy(uintptr_t swapchain)
{
	php_vk_swapchain *sc = (php_vk_swapchain *) swapchain;
	if (!sc) {
		return;
	}
	if (sc->device) {
		vkDeviceWaitIdle(sc->device);
		php_vk_swapchain_teardown_images(sc);
		if (sc->image_available) {
			vkDestroySemaphore(sc->device, sc->image_available, NULL);
		}
		if (sc->render_finished) {
			vkDestroySemaphore(sc->device, sc->render_finished, NULL);
		}
		if (sc->in_flight) {
			vkDestroyFence(sc->device, sc->in_flight, NULL);
		}
		if (sc->command_pool) {
			vkDestroyCommandPool(sc->device, sc->command_pool, NULL);
		}
		if (sc->render_pass) {
			vkDestroyRenderPass(sc->device, sc->render_pass, NULL);
		}
	}
	free(sc);
}

int php_vk_swapchain_resize(uintptr_t swapchain, uint32_t width, uint32_t height)
{
	php_vk_swapchain *sc = (php_vk_swapchain *) swapchain;
	if (!sc || !sc->device) {
		return -1;
	}
	vkDeviceWaitIdle(sc->device);
	/* Free old command buffers before tearing images (they reference pool only). */
	if (sc->image_count > 0) {
		vkFreeCommandBuffers(sc->device, sc->command_pool, sc->image_count, sc->command_buffers);
		memset(sc->command_buffers, 0, sizeof(sc->command_buffers));
	}
	php_vk_swapchain_teardown_images(sc);
	int rc = php_vk_swapchain_build(sc, width, height);
	if (rc != 0) {
		return rc;
	}
	VkCommandBufferAllocateInfo cai;
	memset(&cai, 0, sizeof(cai));
	cai.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
	cai.commandPool = sc->command_pool;
	cai.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
	cai.commandBufferCount = sc->image_count;
	VkResult r = vkAllocateCommandBuffers(sc->device, &cai, sc->command_buffers);
	if (r != VK_SUCCESS) {
		php_vk_set_errorf("vkAllocateCommandBuffers(resize) failed: %d", (int) r);
		return (int) r;
	}
	return 0;
}

static void php_vk_clear_rect(VkCommandBuffer cmd, int x, int y, int w, int h, float r, float g, float b, float a, uint32_t fb_w, uint32_t fb_h)
{
	if (w <= 0 || h <= 0) {
		return;
	}
	if (x < 0) {
		w += x;
		x = 0;
	}
	if (y < 0) {
		h += y;
		y = 0;
	}
	if (x >= (int) fb_w || y >= (int) fb_h || w <= 0 || h <= 0) {
		return;
	}
	if (x + w > (int) fb_w) {
		w = (int) fb_w - x;
	}
	if (y + h > (int) fb_h) {
		h = (int) fb_h - y;
	}

	VkClearAttachment ca;
	memset(&ca, 0, sizeof(ca));
	ca.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
	ca.colorAttachment = 0;
	ca.clearValue.color.float32[0] = r;
	ca.clearValue.color.float32[1] = g;
	ca.clearValue.color.float32[2] = b;
	ca.clearValue.color.float32[3] = a;

	VkClearRect rect;
	memset(&rect, 0, sizeof(rect));
	rect.rect.offset.x = x;
	rect.rect.offset.y = y;
	rect.rect.extent.width = (uint32_t) w;
	rect.rect.extent.height = (uint32_t) h;
	rect.baseArrayLayer = 0;
	rect.layerCount = 1;

	vkCmdClearAttachments(cmd, 1, &ca, 1, &rect);
}

int php_vk_swapchain_frame(
	uintptr_t swapchain,
	float clear_r,
	float clear_g,
	float clear_b,
	float clear_a,
	int draw_menu,
	int menu_x,
	int menu_y,
	int menu_w,
	int menu_h,
	float menu_r,
	float menu_g,
	float menu_b,
	float menu_a,
	int draw_inner,
	int inner_x,
	int inner_y,
	int inner_w,
	int inner_h,
	float inner_r,
	float inner_g,
	float inner_b,
	float inner_a,
	int draw_accent,
	int accent_x,
	int accent_y,
	int accent_w,
	int accent_h,
	float accent_r,
	float accent_g,
	float accent_b,
	float accent_a
) {
	php_vk_swapchain *sc = (php_vk_swapchain *) swapchain;
	if (!sc || !sc->device) {
		return -1;
	}

	vkWaitForFences(sc->device, 1, &sc->in_flight, VK_TRUE, UINT64_MAX);
	vkResetFences(sc->device, 1, &sc->in_flight);

	uint32_t image_index = 0;
	VkResult r = vkAcquireNextImageKHR(
		sc->device,
		sc->swapchain,
		UINT64_MAX,
		sc->image_available,
		VK_NULL_HANDLE,
		&image_index
	);
	if (r == VK_ERROR_OUT_OF_DATE_KHR) {
		return (int) r;
	}
	if (r != VK_SUCCESS && r != VK_SUBOPTIMAL_KHR) {
		php_vk_set_errorf("vkAcquireNextImageKHR failed: %d", (int) r);
		return (int) r;
	}

	VkCommandBuffer cmd = sc->command_buffers[image_index];
	vkResetCommandBuffer(cmd, 0);

	VkCommandBufferBeginInfo begin;
	memset(&begin, 0, sizeof(begin));
	begin.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
	vkBeginCommandBuffer(cmd, &begin);

	VkClearValue clear_value;
	memset(&clear_value, 0, sizeof(clear_value));
	clear_value.color.float32[0] = clear_r;
	clear_value.color.float32[1] = clear_g;
	clear_value.color.float32[2] = clear_b;
	clear_value.color.float32[3] = clear_a;

	VkRenderPassBeginInfo rpbi;
	memset(&rpbi, 0, sizeof(rpbi));
	rpbi.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
	rpbi.renderPass = sc->render_pass;
	rpbi.framebuffer = sc->framebuffers[image_index];
	rpbi.renderArea.offset.x = 0;
	rpbi.renderArea.offset.y = 0;
	rpbi.renderArea.extent = sc->extent;
	rpbi.clearValueCount = 1;
	rpbi.pClearValues = &clear_value;

	vkCmdBeginRenderPass(cmd, &rpbi, VK_SUBPASS_CONTENTS_INLINE);

	if (draw_accent) {
		php_vk_clear_rect(cmd, accent_x, accent_y, accent_w, accent_h, accent_r, accent_g, accent_b, accent_a, sc->extent.width, sc->extent.height);
	}
	if (draw_menu) {
		php_vk_clear_rect(cmd, menu_x, menu_y, menu_w, menu_h, menu_r, menu_g, menu_b, menu_a, sc->extent.width, sc->extent.height);
	}
	if (draw_inner) {
		php_vk_clear_rect(cmd, inner_x, inner_y, inner_w, inner_h, inner_r, inner_g, inner_b, inner_a, sc->extent.width, sc->extent.height);
	}

	vkCmdEndRenderPass(cmd);
	vkEndCommandBuffer(cmd);

	VkPipelineStageFlags wait_stage = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
	VkSubmitInfo submit;
	memset(&submit, 0, sizeof(submit));
	submit.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
	submit.waitSemaphoreCount = 1;
	submit.pWaitSemaphores = &sc->image_available;
	submit.pWaitDstStageMask = &wait_stage;
	submit.commandBufferCount = 1;
	submit.pCommandBuffers = &cmd;
	submit.signalSemaphoreCount = 1;
	submit.pSignalSemaphores = &sc->render_finished;

	r = vkQueueSubmit(sc->queue, 1, &submit, sc->in_flight);
	if (r != VK_SUCCESS) {
		php_vk_set_errorf("vkQueueSubmit failed: %d", (int) r);
		return (int) r;
	}

	VkPresentInfoKHR present;
	memset(&present, 0, sizeof(present));
	present.sType = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;
	present.waitSemaphoreCount = 1;
	present.pWaitSemaphores = &sc->render_finished;
	present.swapchainCount = 1;
	present.pSwapchains = &sc->swapchain;
	present.pImageIndices = &image_index;

	r = vkQueuePresentKHR(sc->queue, &present);
	if (r == VK_ERROR_OUT_OF_DATE_KHR || r == VK_SUBOPTIMAL_KHR) {
		return (int) r;
	}
	if (r != VK_SUCCESS) {
		php_vk_set_errorf("vkQueuePresentKHR failed: %d", (int) r);
		return (int) r;
	}
	return 0;
}

int php_vk_swapchain_present_rgba8(
	uintptr_t swapchain,
	const uint8_t *pixels,
	uint32_t width,
	uint32_t height,
	float scale_x,
	float scale_y,
	float clear_r,
	float clear_g,
	float clear_b,
	float clear_a
) {
	php_vk_swapchain *sc = (php_vk_swapchain *) swapchain;
	if (!sc || !sc->device || !pixels || width == 0 || height == 0) {
		php_vk_set_error("present_rgba8: bad args");
		return -1;
	}
	if (scale_x <= 0.0f) {
		scale_x = 1.0f;
	}
	if (scale_y <= 0.0f) {
		scale_y = 1.0f;
	}

	uint8_t clear_ru = (uint8_t) lroundf(clear_r * 255.0f);
	uint8_t clear_gu = (uint8_t) lroundf(clear_g * 255.0f);
	uint8_t clear_bu = (uint8_t) lroundf(clear_b * 255.0f);
	uint8_t clear_au = (uint8_t) lroundf(clear_a * 255.0f);

	vkWaitForFences(sc->device, 1, &sc->in_flight, VK_TRUE, UINT64_MAX);
	vkResetFences(sc->device, 1, &sc->in_flight);

	uint32_t image_index = 0;
	VkResult r = vkAcquireNextImageKHR(
		sc->device,
		sc->swapchain,
		UINT64_MAX,
		sc->image_available,
		VK_NULL_HANDLE,
		&image_index
	);
	if (r == VK_ERROR_OUT_OF_DATE_KHR) {
		return (int) r;
	}
	if (r != VK_SUCCESS && r != VK_SUBOPTIMAL_KHR) {
		php_vk_set_errorf("vkAcquireNextImageKHR failed: %d", (int) r);
		return (int) r;
	}

	VkCommandBuffer cmd = sc->command_buffers[image_index];
	vkResetCommandBuffer(cmd, 0);

	VkCommandBufferBeginInfo begin;
	memset(&begin, 0, sizeof(begin));
	begin.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
	vkBeginCommandBuffer(cmd, &begin);

	VkClearValue clear_value;
	memset(&clear_value, 0, sizeof(clear_value));
	clear_value.color.float32[0] = clear_r;
	clear_value.color.float32[1] = clear_g;
	clear_value.color.float32[2] = clear_b;
	clear_value.color.float32[3] = clear_a;

	VkRenderPassBeginInfo rpbi;
	memset(&rpbi, 0, sizeof(rpbi));
	rpbi.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
	rpbi.renderPass = sc->render_pass;
	rpbi.framebuffer = sc->framebuffers[image_index];
	rpbi.renderArea.offset.x = 0;
	rpbi.renderArea.offset.y = 0;
	rpbi.renderArea.extent = sc->extent;
	rpbi.clearValueCount = 1;
	rpbi.pClearValues = &clear_value;

	vkCmdBeginRenderPass(cmd, &rpbi, VK_SUBPASS_CONTENTS_INLINE);

	for (uint32_t y = 0; y < height; y++) {
		const uint8_t *row = pixels + ((size_t) y * (size_t) width * 4u);
		uint32_t x = 0;
		while (x < width) {
			const uint8_t *p = row + ((size_t) x * 4u);
			uint8_t r8 = p[0], g8 = p[1], b8 = p[2], a8 = p[3];
			if (r8 == clear_ru && g8 == clear_gu && b8 == clear_bu && a8 == clear_au) {
				x++;
				continue;
			}
			uint32_t x0 = x;
			x++;
			while (x < width) {
				const uint8_t *q = row + ((size_t) x * 4u);
				if (q[0] != r8 || q[1] != g8 || q[2] != b8 || q[3] != a8) {
					break;
				}
				x++;
			}
			int rx = (int) lroundf((float) x0 * scale_x);
			int ry = (int) lroundf((float) y * scale_y);
			int rw = (int) lroundf((float) (x - x0) * scale_x);
			int rh = (int) lroundf(scale_y);
			if (rw < 1) {
				rw = 1;
			}
			if (rh < 1) {
				rh = 1;
			}
			php_vk_clear_rect(
				cmd,
				rx,
				ry,
				rw,
				rh,
				(float) r8 / 255.0f,
				(float) g8 / 255.0f,
				(float) b8 / 255.0f,
				(float) a8 / 255.0f,
				sc->extent.width,
				sc->extent.height
			);
		}
	}

	vkCmdEndRenderPass(cmd);
	vkEndCommandBuffer(cmd);

	VkPipelineStageFlags wait_stage = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
	VkSubmitInfo submit;
	memset(&submit, 0, sizeof(submit));
	submit.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
	submit.waitSemaphoreCount = 1;
	submit.pWaitSemaphores = &sc->image_available;
	submit.pWaitDstStageMask = &wait_stage;
	submit.commandBufferCount = 1;
	submit.pCommandBuffers = &cmd;
	submit.signalSemaphoreCount = 1;
	submit.pSignalSemaphores = &sc->render_finished;

	r = vkQueueSubmit(sc->queue, 1, &submit, sc->in_flight);
	if (r != VK_SUCCESS) {
		php_vk_set_errorf("vkQueueSubmit failed: %d", (int) r);
		return (int) r;
	}

	VkPresentInfoKHR present;
	memset(&present, 0, sizeof(present));
	present.sType = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;
	present.waitSemaphoreCount = 1;
	present.pWaitSemaphores = &sc->render_finished;
	present.swapchainCount = 1;
	present.pSwapchains = &sc->swapchain;
	present.pImageIndices = &image_index;

	r = vkQueuePresentKHR(sc->queue, &present);
	if (r == VK_ERROR_OUT_OF_DATE_KHR || r == VK_SUBOPTIMAL_KHR) {
		return (int) r;
	}
	if (r != VK_SUCCESS) {
		php_vk_set_errorf("vkQueuePresentKHR failed: %d", (int) r);
		return (int) r;
	}
	return 0;
}

uint32_t php_vk_swapchain_width(uintptr_t swapchain)
{
	php_vk_swapchain *sc = (php_vk_swapchain *) swapchain;
	return sc ? sc->extent.width : 0;
}

uint32_t php_vk_swapchain_height(uintptr_t swapchain)
{
	php_vk_swapchain *sc = (php_vk_swapchain *) swapchain;
	return sc ? sc->extent.height : 0;
}

uint32_t php_vk_swapchain_image_count(uintptr_t swapchain)
{
	php_vk_swapchain *sc = (php_vk_swapchain *) swapchain;
	return sc ? sc->image_count : 0;
}

uint32_t php_vk_swapchain_format(uintptr_t swapchain)
{
	php_vk_swapchain *sc = (php_vk_swapchain *) swapchain;
	return sc ? (uint32_t) sc->format : 0;
}
