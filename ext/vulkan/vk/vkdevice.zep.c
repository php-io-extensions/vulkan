
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
 * Opaque VkDevice handle.
 */
ZEPHIR_INIT_CLASS(Vulkan_Vk_VkDevice)
{
	ZEPHIR_REGISTER_CLASS(Vulkan\\Vk, VkDevice, vulkan, vk_vkdevice, NULL, 0);

	/** Opaque VkDevice pointer. 0 = none / destroyed. */
	zend_declare_property_long(vulkan_vk_vkdevice_ce, SL("fd"), 0, ZEND_ACC_PUBLIC);
	/** Queue family index used at create time. */
	zend_declare_property_long(vulkan_vk_vkdevice_ce, SL("queueFamily"), -1, ZEND_ACC_PUBLIC);
	return SUCCESS;
}

