
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_VULKAN_H
#define PHP_VULKAN_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_VULKAN_NAME        "vulkan"
#define PHP_VULKAN_VERSION     "0.7.0"
#define PHP_VULKAN_EXTNAME     "vulkan"
#define PHP_VULKAN_AUTHOR      "Project Saturn Studios, LLC"
#define PHP_VULKAN_ZEPVERSION  "0.19.0-$Id$"
#define PHP_VULKAN_DESCRIPTION "PHP-Controllable Vulkan Rendering Extension"



ZEND_BEGIN_MODULE_GLOBALS(vulkan)

	int initialized;

	/** Function cache */
	HashTable *fcache;

	zephir_fcall_cache_entry *scache[ZEPHIR_MAX_CACHE_SLOTS];

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	
ZEND_END_MODULE_GLOBALS(vulkan)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(vulkan)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) ZEND_MODULE_GLOBALS_ACCESSOR(vulkan, v)
#else
	#define ZEPHIR_GLOBAL(v) (vulkan_globals.v)
#endif

#ifdef ZTS
	ZEND_TSRMLS_CACHE_EXTERN()
	#define ZEPHIR_VGLOBAL ((zend_vulkan_globals *) (*((void ***) tsrm_get_ls_cache()))[TSRM_UNSHUFFLE_RSRC_ID(vulkan_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(vulkan_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def vulkan_globals
#define zend_zephir_globals_def zend_vulkan_globals

extern zend_module_entry vulkan_module_entry;
#define phpext_vulkan_ptr &vulkan_module_entry

#endif
