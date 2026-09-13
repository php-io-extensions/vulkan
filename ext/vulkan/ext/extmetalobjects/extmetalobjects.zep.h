
extern zend_class_entry *vulkan_ext_extmetalobjects_extmetalobjects_ce;

ZEPHIR_INIT_CLASS(Vulkan_Ext_EXTMetalObjects_EXTMetalObjects);

PHP_METHOD(Vulkan_Ext_EXTMetalObjects_EXTMetalObjects, vkExportMetalObjectsEXT);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_ext_extmetalobjects_extmetalobjects_vkexportmetalobjectsext, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pMetalObjectsInfo, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vulkan_ext_extmetalobjects_extmetalobjects_method_entry) {
	PHP_ME(Vulkan_Ext_EXTMetalObjects_EXTMetalObjects, vkExportMetalObjectsEXT, arginfo_vulkan_ext_extmetalobjects_extmetalobjects_vkexportmetalobjectsext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
