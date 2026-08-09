/**
 * Thin C ABI for php-io-extensions/vulkan.
 * Opaque handles are uintptr_t (0 = none / failure).
 */
#ifndef PHP_VULKAN_API_H
#define PHP_VULKAN_API_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/** Ensure MoltenVK ICD is discoverable on Homebrew Darwin when unset. */
void php_vk_ensure_loader(void);

/**
 * Create a VkInstance requesting the given extensions plus portability bits on Darwin.
 * @return opaque VkInstance, or 0 on failure
 */
uintptr_t php_vk_create_instance(const char **extensions, uint32_t extension_count, const char *app_name);

void php_vk_destroy_instance(uintptr_t instance);

uint32_t php_vk_physical_device_count(uintptr_t instance);
uintptr_t php_vk_physical_device_at(uintptr_t instance, uint32_t index);

/** Copy device name into buf; returns length written (excluding NUL), or -1. */
int php_vk_physical_device_name(uintptr_t physical, char *buf, size_t buflen);
uint32_t php_vk_physical_device_type(uintptr_t physical);
uint32_t php_vk_physical_device_vendor_id(uintptr_t physical);
uint32_t php_vk_physical_device_device_id(uintptr_t physical);

/** Graphics + present queue family index, or -1. */
int php_vk_find_graphics_present_queue(uintptr_t physical, uintptr_t surface);

uintptr_t php_vk_create_device(uintptr_t physical, int queue_family);
void php_vk_destroy_device(uintptr_t device);
uintptr_t php_vk_get_device_queue(uintptr_t device, int queue_family);

void php_vk_destroy_surface(uintptr_t instance, uintptr_t surface);

/**
 * Create a presentable swapchain + clear/menu helpers.
 * Owns images, views, render pass, framebuffers, command pool/buffers, sync objects.
 */
uintptr_t php_vk_swapchain_create(
	uintptr_t instance,
	uintptr_t physical,
	uintptr_t device,
	uintptr_t queue,
	uintptr_t surface,
	uint32_t width,
	uint32_t height
);

void php_vk_swapchain_destroy(uintptr_t swapchain);

int php_vk_swapchain_resize(uintptr_t swapchain, uint32_t width, uint32_t height);

/**
 * Acquire → clear background → optional menu rect via clearAttachments → present.
 * Menu coordinates are in framebuffer pixels (origin top-left).
 * @return 0 on success, VkResult (positive/negative) on failure; VK_ERROR_OUT_OF_DATE_KHR may be returned
 */
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
);

/**
 * Acquire → clear → paint packed RGBA8 pixels as horizontal clearAttachment runs → present.
 * pixels is width*height*4 bytes (R,G,B,A). Pixels matching clear are skipped (bg already cleared).
 * Coordinates are logical; scale_x/scale_y map to FB pixels.
 * @return 0 on success, VkResult on failure
 */
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
);

uint32_t php_vk_swapchain_width(uintptr_t swapchain);
uint32_t php_vk_swapchain_height(uintptr_t swapchain);
uint32_t php_vk_swapchain_image_count(uintptr_t swapchain);
uint32_t php_vk_swapchain_format(uintptr_t swapchain);

/** Last human-readable error from a failed C helper (not thread-safe). */
const char *php_vk_last_error(void);

#ifdef __cplusplus
}
#endif

#endif /* PHP_VULKAN_API_H */
