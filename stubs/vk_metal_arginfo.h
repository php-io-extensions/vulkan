/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: fc6e1a35fd292d6f7ea29b3e42d5626c8d3fa8b8 */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkCreateMetalSurfaceEXT, 0, 4, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, instance, VkInstance, 0)
	ZEND_ARG_OBJ_INFO(0, pCreateInfo, VkMetalSurfaceCreateInfoEXT, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_NULL, 1)
	ZEND_ARG_OBJ_INFO(1, pSurface, VkSurfaceKHR, 1)
ZEND_END_ARG_INFO()

ZEND_FUNCTION(vkCreateMetalSurfaceEXT);

static const zend_function_entry ext_functions[] = {
	ZEND_FE(vkCreateMetalSurfaceEXT, arginfo_vkCreateMetalSurfaceEXT)
	ZEND_FE_END
};

static zend_class_entry *register_class_VkMetalSurfaceCreateInfoEXT(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkMetalSurfaceCreateInfoEXT", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_pNext_default_value;
	ZVAL_NULL(&property_pNext_default_value);
	zend_string *property_pNext_name = zend_string_init("pNext", sizeof("pNext") - 1, 1);
	zend_declare_typed_property(class_entry, property_pNext_name, &property_pNext_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_OBJECT|MAY_BE_NULL));
	zend_string_release(property_pNext_name);

	zval property_flags_default_value;
	ZVAL_LONG(&property_flags_default_value, 0);
	zend_string *property_flags_name = zend_string_init("flags", sizeof("flags") - 1, 1);
	zend_declare_typed_property(class_entry, property_flags_name, &property_flags_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_flags_name);

	zval property_pLayer_default_value;
	ZVAL_LONG(&property_pLayer_default_value, 0);
	zend_string *property_pLayer_name = zend_string_init("pLayer", sizeof("pLayer") - 1, 1);
	zend_declare_typed_property(class_entry, property_pLayer_name, &property_pLayer_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_pLayer_name);

	return class_entry;
}
