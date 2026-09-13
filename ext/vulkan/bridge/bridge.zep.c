
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
#include "src/phpvk-bridge.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Vulkan_Bridge_Bridge)
{
	ZEPHIR_REGISTER_CLASS(Vulkan\\Bridge, Bridge, vulkan, bridge_bridge, vulkan_bridge_bridge_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Vulkan_Bridge_Bridge, load)
{
	zend_long r = 0;
	r = phpvk_bridge_load();
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Vulkan_Bridge_Bridge, loadInstance)
{
	zval *instance_param = NULL, _0;
	zend_long instance, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(instance)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &instance_param);
	ZVAL_LONG(&_0, instance);
	r = phpvk_bridge_load_instance(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Vulkan_Bridge_Bridge, loadDevice)
{
	zval *device_param = NULL, _0;
	zend_long device, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(device)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &device_param);
	ZVAL_LONG(&_0, device);
	r = phpvk_bridge_load_device(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Vulkan_Bridge_Bridge, isAvailable)
{
	zend_long r = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL;
	zval name;

	ZVAL_UNDEF(&name);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &name_param);
	zephir_get_strval(&name, name_param);
	r = phpvk_bridge_is_available(&name);
	RETURN_MM_BOOL(r == 1);
}

PHP_METHOD(Vulkan_Bridge_Bridge, procAddress)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL;
	zval name;

	ZVAL_UNDEF(&name);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &name_param);
	zephir_get_strval(&name, name_param);
	RETURN_MM_LONG(phpvk_bridge_proc_address(&name));
}

PHP_METHOD(Vulkan_Bridge_Bridge, version)
{

	RETURN_LONG(phpvk_bridge_version());
}

PHP_METHOD(Vulkan_Bridge_Bridge, alloc)
{
	zval *size_param = NULL, _0;
	zend_long size;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(size)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &size_param);
	ZVAL_LONG(&_0, size);
	RETURN_LONG(phpvk_bridge_alloc(&_0));
}

PHP_METHOD(Vulkan_Bridge_Bridge, free)
{
	zval *ptr_param = NULL, _0;
	zend_long ptr;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(ptr)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &ptr_param);
	ZVAL_LONG(&_0, ptr);
	phpvk_bridge_free(&_0);
}

PHP_METHOD(Vulkan_Bridge_Bridge, write)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval bytes;
	zval *ptr_param = NULL, *offset_param = NULL, *bytes_param = NULL, _0, _1;
	zend_long ptr, offset, r = 0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&bytes);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(ptr)
		Z_PARAM_LONG(offset)
		Z_PARAM_STR(bytes)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &ptr_param, &offset_param, &bytes_param);
	zephir_get_strval(&bytes, bytes_param);
	ZVAL_LONG(&_0, ptr);
	ZVAL_LONG(&_1, offset);
	r = phpvk_bridge_write(&_0, &_1, &bytes);
	RETURN_MM_BOOL(r == 1);
}

PHP_METHOD(Vulkan_Bridge_Bridge, read)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *ptr_param = NULL, *offset_param = NULL, *length_param = NULL, result, _0, _1, _2;
	zend_long ptr, offset, length;

	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(ptr)
		Z_PARAM_LONG(offset)
		Z_PARAM_LONG(length)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &ptr_param, &offset_param, &length_param);
	ZEPHIR_INIT_VAR(&result);
	ZVAL_LONG(&_0, ptr);
	ZVAL_LONG(&_1, offset);
	ZVAL_LONG(&_2, length);
	phpvk_bridge_read(&result, &_0, &_1, &_2);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Vulkan_Bridge_Bridge, cstring)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *text_param = NULL;
	zval text;

	ZVAL_UNDEF(&text);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(text)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &text_param);
	zephir_get_strval(&text, text_param);
	RETURN_MM_LONG(phpvk_bridge_cstring(&text));
}

PHP_METHOD(Vulkan_Bridge_Bridge, readCString)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *ptr_param = NULL, result, _0;
	zend_long ptr;

	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(ptr)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &ptr_param);
	ZEPHIR_INIT_VAR(&result);
	ZVAL_LONG(&_0, ptr);
	phpvk_bridge_read_cstring(&result, &_0);
	RETURN_CCTOR(&result);
}

