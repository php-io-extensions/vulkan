
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
 * Opaque VkSurfaceKHR (usually created by glfw, destroyed here).
 */
ZEPHIR_INIT_CLASS(Vulkan_Vk_VkSurface)
{
	ZEPHIR_REGISTER_CLASS(Vulkan\\Vk, VkSurface, vulkan, vk_vksurface, NULL, 0);

	/** Opaque VkSurfaceKHR pointer. 0 = none / destroyed. */
	zend_declare_property_long(vulkan_vk_vksurface_ce, SL("fd"), 0, ZEND_ACC_PUBLIC);
	return SUCCESS;
}

