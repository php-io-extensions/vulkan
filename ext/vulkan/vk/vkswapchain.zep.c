
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


/**
 * Presentable swapchain + clear/menu frame state (C-owned).
 * `fd` points at an internal presenter struct, not a raw VkSwapchainKHR alone.
 */
ZEPHIR_INIT_CLASS(Vulkan_Vk_VkSwapchain)
{
	ZEPHIR_REGISTER_CLASS(Vulkan\\Vk, VkSwapchain, vulkan, vk_vkswapchain, NULL, 0);

	/** Opaque presenter pointer. 0 = none / destroyed. */
	zend_declare_property_long(vulkan_vk_vkswapchain_ce, SL("fd"), 0, ZEND_ACC_PUBLIC);
	/** Framebuffer width in pixels. */
	zend_declare_property_long(vulkan_vk_vkswapchain_ce, SL("width"), 0, ZEND_ACC_PUBLIC);
	/** Framebuffer height in pixels. */
	zend_declare_property_long(vulkan_vk_vkswapchain_ce, SL("height"), 0, ZEND_ACC_PUBLIC);
	/** VkFormat of color images. */
	zend_declare_property_long(vulkan_vk_vkswapchain_ce, SL("format"), 0, ZEND_ACC_PUBLIC);
	/** Number of swapchain images. */
	zend_declare_property_long(vulkan_vk_vkswapchain_ce, SL("imageCount"), 0, ZEND_ACC_PUBLIC);
	return SUCCESS;
}

