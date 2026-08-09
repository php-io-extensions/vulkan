
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
 * Opaque VkPhysicalDevice handle with queried schema fields.
 */
ZEPHIR_INIT_CLASS(Vulkan_Vk_VkPhysicalDevice)
{
	ZEPHIR_REGISTER_CLASS(Vulkan\\Vk, VkPhysicalDevice, vulkan, vk_vkphysicaldevice, NULL, 0);

	/** Opaque VkPhysicalDevice pointer. 0 = none. */
	zend_declare_property_long(vulkan_vk_vkphysicaldevice_ce, SL("fd"), 0, ZEND_ACC_PUBLIC);
	/** Device name from VkPhysicalDeviceProperties. */
	zend_declare_property_string(vulkan_vk_vkphysicaldevice_ce, SL("name"), "", ZEND_ACC_PUBLIC);
	/** VkPhysicalDeviceType. */
	zend_declare_property_long(vulkan_vk_vkphysicaldevice_ce, SL("deviceType"), 0, ZEND_ACC_PUBLIC);
	/** PCI-style vendor ID. */
	zend_declare_property_long(vulkan_vk_vkphysicaldevice_ce, SL("vendorId"), 0, ZEND_ACC_PUBLIC);
	/** Device ID. */
	zend_declare_property_long(vulkan_vk_vkphysicaldevice_ce, SL("deviceId"), 0, ZEND_ACC_PUBLIC);
	return SUCCESS;
}

