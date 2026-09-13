
extern zend_class_entry *vulkan_bridge_bridge_ce;

ZEPHIR_INIT_CLASS(Vulkan_Bridge_Bridge);

PHP_METHOD(Vulkan_Bridge_Bridge, load);
PHP_METHOD(Vulkan_Bridge_Bridge, loadInstance);
PHP_METHOD(Vulkan_Bridge_Bridge, loadDevice);
PHP_METHOD(Vulkan_Bridge_Bridge, isAvailable);
PHP_METHOD(Vulkan_Bridge_Bridge, procAddress);
PHP_METHOD(Vulkan_Bridge_Bridge, version);
PHP_METHOD(Vulkan_Bridge_Bridge, alloc);
PHP_METHOD(Vulkan_Bridge_Bridge, free);
PHP_METHOD(Vulkan_Bridge_Bridge, write);
PHP_METHOD(Vulkan_Bridge_Bridge, read);
PHP_METHOD(Vulkan_Bridge_Bridge, cstring);
PHP_METHOD(Vulkan_Bridge_Bridge, readCString);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_bridge_bridge_load, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_bridge_bridge_loadinstance, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, instance, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_bridge_bridge_loaddevice, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_bridge_bridge_isavailable, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_bridge_bridge_procaddress, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_bridge_bridge_version, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_bridge_bridge_alloc, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, size, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_bridge_bridge_free, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, ptr, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_bridge_bridge_write, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, ptr, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, offset, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, bytes, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vulkan_bridge_bridge_read, 0, 0, 3)
	ZEND_ARG_TYPE_INFO(0, ptr, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, offset, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, length, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_bridge_bridge_cstring, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_bridge_bridge_readcstring, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, ptr, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vulkan_bridge_bridge_method_entry) {
	PHP_ME(Vulkan_Bridge_Bridge, load, arginfo_vulkan_bridge_bridge_load, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Bridge_Bridge, loadInstance, arginfo_vulkan_bridge_bridge_loadinstance, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Bridge_Bridge, loadDevice, arginfo_vulkan_bridge_bridge_loaddevice, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Bridge_Bridge, isAvailable, arginfo_vulkan_bridge_bridge_isavailable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Bridge_Bridge, procAddress, arginfo_vulkan_bridge_bridge_procaddress, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Bridge_Bridge, version, arginfo_vulkan_bridge_bridge_version, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Bridge_Bridge, alloc, arginfo_vulkan_bridge_bridge_alloc, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Bridge_Bridge, free, arginfo_vulkan_bridge_bridge_free, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Bridge_Bridge, write, arginfo_vulkan_bridge_bridge_write, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Bridge_Bridge, read, arginfo_vulkan_bridge_bridge_read, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Bridge_Bridge, cstring, arginfo_vulkan_bridge_bridge_cstring, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Bridge_Bridge, readCString, arginfo_vulkan_bridge_bridge_readcstring, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
