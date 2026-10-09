/*
 * vulkan: 1:1 bindings of Vulkan. Handles keep their C names. Dropping the
 * last PHP reference does not destroy the native object.
 */

#ifndef _GNU_SOURCE
# define _GNU_SOURCE /* dladdr() on glibc */
#endif
#include "runtime.h"

#include <dlfcn.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include "ext/standard/info.h"
#include "../stubs/vk_constants_arginfo.h"

ZEND_DECLARE_MODULE_GLOBALS(vulkan)

static void vulkan_destroy_class_table(zval *zv)
{
	HashTable *table = Z_PTR_P(zv);

	zend_hash_destroy(table);
	pefree(table, 1);
}

static PHP_GINIT_FUNCTION(vulkan)
{
#if defined(COMPILE_DL_VULKAN) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	zend_hash_init(&vulkan_globals->classes, 16, NULL, vulkan_destroy_class_table, 1);
}

static PHP_GSHUTDOWN_FUNCTION(vulkan)
{
	zend_hash_destroy(&vulkan_globals->classes);
}

void vulkan_register_instance(int module_number);
void vulkan_register_memory(int module_number);
void vulkan_register_pipeline(int module_number);
void vulkan_register_command(int module_number);
void vulkan_register_surface(int module_number);
void vulkan_register_external(int module_number);
#ifdef VK_USE_PLATFORM_METAL_EXT
void vulkan_register_metal(int module_number);
#endif

PHP_MINIT_FUNCTION(vulkan)
{
	register_vk_constants_symbols(module_number);
	zend_register_functions(NULL, ext_functions, NULL, MODULE_PERSISTENT);
	vulkan_register_instance(module_number);
	vulkan_register_memory(module_number);
	vulkan_register_pipeline(module_number);
	vulkan_register_command(module_number);
	vulkan_register_surface(module_number);
	vulkan_register_external(module_number);
#ifdef VK_USE_PLATFORM_METAL_EXT
	vulkan_register_metal(module_number);
#endif

	return SUCCESS;
}

PHP_RINIT_FUNCTION(vulkan)
{
#if defined(COMPILE_DL_VULKAN) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	return SUCCESS;
}

PHP_MINFO_FUNCTION(vulkan)
{
	php_info_print_table_start();
	php_info_print_table_row(2, "vulkan support", "enabled");
	php_info_print_table_row(2, "Version", PHP_VULKAN_VERSION);
	php_info_print_table_end();
}

zend_module_entry vulkan_module_entry = {
	STANDARD_MODULE_HEADER,
	"vulkan",
	NULL,
	PHP_MINIT(vulkan),
	NULL,
	PHP_RINIT(vulkan),
	NULL,
	PHP_MINFO(vulkan),
	PHP_VULKAN_VERSION,
	PHP_MODULE_GLOBALS(vulkan),
	PHP_GINIT(vulkan),
	PHP_GSHUTDOWN(vulkan),
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_VULKAN
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(vulkan)
#endif

ZEND_FUNCTION(vk_read_mapped)
{
	zend_long address, size;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(address)
		Z_PARAM_LONG(size)
	ZEND_PARSE_PARAMETERS_END();

	if (address == 0) {
		zend_argument_value_error(1, "null address");
		RETURN_THROWS();
	}
	if (size < 0) {
		zend_argument_value_error(2, "must be greater than or equal to 0");
		RETURN_THROWS();
	}

	RETVAL_STRINGL((char *) (uintptr_t) address, (size_t) size);
}

ZEND_FUNCTION(vk_write_mapped)
{
	zend_long address;
	zend_string *bytes;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(address)
		Z_PARAM_STR(bytes)
	ZEND_PARSE_PARAMETERS_END();

	if (address == 0) {
		zend_argument_value_error(1, "null address");
		RETURN_THROWS();
	}

	memcpy((void *) (uintptr_t) address, ZSTR_VAL(bytes), ZSTR_LEN(bytes));
}

ZEND_FUNCTION(vk_loader_path)
{
	Dl_info info;

	ZEND_PARSE_PARAMETERS_NONE();

	if (dladdr((const void *) (uintptr_t) vkGetInstanceProcAddr, &info) == 0 || info.dli_fname == NULL) {
		RETURN_NULL();
	}
	RETURN_STRING(info.dli_fname);
}

ZEND_FUNCTION(vk_close_fd)
{
	zend_long fd;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(fd)
	ZEND_PARSE_PARAMETERS_END();

	if (fd < 0 || fd > INT_MAX) {
		zend_argument_value_error(1, "is not a file descriptor");
		RETURN_THROWS();
	}
	if (close((int) fd) != 0) {
		if (errno == EBADF) {
			zend_argument_value_error(1, "is not an open file descriptor");
		} else {
			zend_value_error("vk_close_fd(): close() failed: %s", strerror(errno));
		}
		RETURN_THROWS();
	}
}
