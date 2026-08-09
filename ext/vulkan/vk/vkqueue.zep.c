
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
 * Opaque VkQueue handle.
 */
ZEPHIR_INIT_CLASS(Vulkan_Vk_VkQueue)
{
	ZEPHIR_REGISTER_CLASS(Vulkan\\Vk, VkQueue, vulkan, vk_vkqueue, NULL, 0);

	/** Opaque VkQueue pointer. 0 = none. */
	zend_declare_property_long(vulkan_vk_vkqueue_ce, SL("fd"), 0, ZEND_ACC_PUBLIC);
	/** Queue family index. */
	zend_declare_property_long(vulkan_vk_vkqueue_ce, SL("familyIndex"), -1, ZEND_ACC_PUBLIC);
	return SUCCESS;
}

