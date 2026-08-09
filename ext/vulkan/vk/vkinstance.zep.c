
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
 * Opaque VkInstance handle.
 * `fd` holds the pointer as int (0 = none).
 */
ZEPHIR_INIT_CLASS(Vulkan_Vk_VkInstance)
{
	ZEPHIR_REGISTER_CLASS(Vulkan\\Vk, VkInstance, vulkan, vk_vkinstance, NULL, 0);

	/** Opaque VkInstance pointer. 0 = none / destroyed. */
	zend_declare_property_long(vulkan_vk_vkinstance_ce, SL("fd"), 0, ZEND_ACC_PUBLIC);
	/** Application name used at create time. */
	zend_declare_property_string(vulkan_vk_vkinstance_ce, SL("appName"), "", ZEND_ACC_PUBLIC);
	return SUCCESS;
}

