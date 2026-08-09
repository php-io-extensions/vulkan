
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#include "php_ext.h"
#include "vulkan.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *vulkan_vk_vk_ce;
zend_class_entry *vulkan_vk_vkdevice_ce;
zend_class_entry *vulkan_vk_vkinstance_ce;
zend_class_entry *vulkan_vk_vkphysicaldevice_ce;
zend_class_entry *vulkan_vk_vkqueue_ce;
zend_class_entry *vulkan_vk_vksurface_ce;
zend_class_entry *vulkan_vk_vkswapchain_ce;

ZEND_DECLARE_MODULE_GLOBALS(vulkan)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(vulkan)
{
	REGISTER_INI_ENTRIES();
	zephir_module_init();
	ZEPHIR_INIT(Vulkan_Vk_Vk);
	ZEPHIR_INIT(Vulkan_Vk_VkDevice);
	ZEPHIR_INIT(Vulkan_Vk_VkInstance);
	ZEPHIR_INIT(Vulkan_Vk_VkPhysicalDevice);
	ZEPHIR_INIT(Vulkan_Vk_VkQueue);
	ZEPHIR_INIT(Vulkan_Vk_VkSurface);
	ZEPHIR_INIT(Vulkan_Vk_VkSwapchain);
	
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(vulkan)
{
	
	zephir_deinitialize_memory();
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_vulkan_globals *vulkan_globals)
{
	vulkan_globals->initialized = 0;

	/* Cache Enabled */
	vulkan_globals->cache_enabled = 1;

	/* Recursive Lock */
	vulkan_globals->recursive_lock = 0;

	/* Static cache */
	memset(vulkan_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);

	
	
}

/**
 * Initialize globals only on each thread started
 */
static void php_zephir_init_module_globals(zend_vulkan_globals *vulkan_globals)
{
	
}

static PHP_RINIT_FUNCTION(vulkan)
{
	zend_vulkan_globals *vulkan_globals_ptr;
	vulkan_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(vulkan_globals_ptr);
	zephir_initialize_memory(vulkan_globals_ptr);

	
	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(vulkan)
{
	
	zephir_deinitialize_memory();
	return SUCCESS;
}



static PHP_MINFO_FUNCTION(vulkan)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_VULKAN_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_VULKAN_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_VULKAN_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_VULKAN_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_VULKAN_ZEPVERSION);
	php_info_print_table_end();
	
	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(vulkan)
{
#if defined(COMPILE_DL_VULKAN) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	php_zephir_init_globals(vulkan_globals);
	php_zephir_init_module_globals(vulkan_globals);
}

static PHP_GSHUTDOWN_FUNCTION(vulkan)
{
	
}


zend_function_entry php_vulkan_functions[] = {
	ZEND_FE_END

};

static const zend_module_dep php_vulkan_deps[] = {
	
	ZEND_MOD_END
};

zend_module_entry vulkan_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	php_vulkan_deps,
	PHP_VULKAN_EXTNAME,
	php_vulkan_functions,
	PHP_MINIT(vulkan),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(vulkan),
#else
	NULL,
#endif
	PHP_RINIT(vulkan),
	PHP_RSHUTDOWN(vulkan),
	PHP_MINFO(vulkan),
	PHP_VULKAN_VERSION,
	ZEND_MODULE_GLOBALS(vulkan),
	PHP_GINIT(vulkan),
	PHP_GSHUTDOWN(vulkan),
#ifdef ZEPHIR_POST_REQUEST
	PHP_PRSHUTDOWN(vulkan),
#else
	NULL,
#endif
	STANDARD_MODULE_PROPERTIES_EX
};

/* implement standard "stub" routine to introduce ourselves to Zend */
#ifdef COMPILE_DL_VULKAN
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(vulkan)
#endif
