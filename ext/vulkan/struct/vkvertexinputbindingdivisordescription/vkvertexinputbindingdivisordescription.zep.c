
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "src/vk-struct-14.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Vulkan_Struct_VkVertexInputBindingDivisorDescription_VkVertexInputBindingDivisorDescription)
{
	ZEPHIR_REGISTER_CLASS(Vulkan\\Struct\\VkVertexInputBindingDivisorDescription, VkVertexInputBindingDivisorDescription, vulkan, struct_vkvertexinputbindingdivisordescription_vkvertexinputbindingdivisordescription, vulkan_struct_vkvertexinputbindingdivisordescription_vkvertexinputbindingdivisordescription_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Vulkan_Struct_VkVertexInputBindingDivisorDescription_VkVertexInputBindingDivisorDescription, pack)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *members_param = NULL;
	zval members;

	ZVAL_UNDEF(&members);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(members)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &members_param);
	zephir_get_arrval(&members, members_param);
	RETURN_MM_LONG(phpvk_struct_vkvertexinputbindingdivisordescription_pack(&members));
}

PHP_METHOD(Vulkan_Struct_VkVertexInputBindingDivisorDescription_VkVertexInputBindingDivisorDescription, packInto)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval members;
	zval *ptr_param = NULL, *members_param = NULL, _0;
	zend_long ptr;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&members);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(ptr)
		Z_PARAM_ARRAY(members)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &ptr_param, &members_param);
	zephir_get_arrval(&members, members_param);
	ZVAL_LONG(&_0, ptr);
	phpvk_struct_vkvertexinputbindingdivisordescription_packinto(&_0, &members);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Vulkan_Struct_VkVertexInputBindingDivisorDescription_VkVertexInputBindingDivisorDescription, unpack)
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
	phpvk_struct_vkvertexinputbindingdivisordescription_unpack(&result, &_0);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Vulkan_Struct_VkVertexInputBindingDivisorDescription_VkVertexInputBindingDivisorDescription, size)
{

	RETURN_LONG(phpvk_struct_vkvertexinputbindingdivisordescription_size());
}

