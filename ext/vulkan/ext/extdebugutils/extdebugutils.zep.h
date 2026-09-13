
extern zend_class_entry *vulkan_ext_extdebugutils_extdebugutils_ce;

ZEPHIR_INIT_CLASS(Vulkan_Ext_EXTDebugUtils_EXTDebugUtils);

PHP_METHOD(Vulkan_Ext_EXTDebugUtils_EXTDebugUtils, vkSetDebugUtilsObjectNameEXT);
PHP_METHOD(Vulkan_Ext_EXTDebugUtils_EXTDebugUtils, vkSetDebugUtilsObjectTagEXT);
PHP_METHOD(Vulkan_Ext_EXTDebugUtils_EXTDebugUtils, vkQueueBeginDebugUtilsLabelEXT);
PHP_METHOD(Vulkan_Ext_EXTDebugUtils_EXTDebugUtils, vkQueueEndDebugUtilsLabelEXT);
PHP_METHOD(Vulkan_Ext_EXTDebugUtils_EXTDebugUtils, vkQueueInsertDebugUtilsLabelEXT);
PHP_METHOD(Vulkan_Ext_EXTDebugUtils_EXTDebugUtils, vkCmdBeginDebugUtilsLabelEXT);
PHP_METHOD(Vulkan_Ext_EXTDebugUtils_EXTDebugUtils, vkCmdEndDebugUtilsLabelEXT);
PHP_METHOD(Vulkan_Ext_EXTDebugUtils_EXTDebugUtils, vkCmdInsertDebugUtilsLabelEXT);
PHP_METHOD(Vulkan_Ext_EXTDebugUtils_EXTDebugUtils, vkCreateDebugUtilsMessengerEXT);
PHP_METHOD(Vulkan_Ext_EXTDebugUtils_EXTDebugUtils, vkDestroyDebugUtilsMessengerEXT);
PHP_METHOD(Vulkan_Ext_EXTDebugUtils_EXTDebugUtils, vkSubmitDebugUtilsMessageEXT);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_ext_extdebugutils_extdebugutils_vksetdebugutilsobjectnameext, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pNameInfo, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_ext_extdebugutils_extdebugutils_vksetdebugutilsobjecttagext, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pTagInfo, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_ext_extdebugutils_extdebugutils_vkqueuebegindebugutilslabelext, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, queue, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pLabelInfo, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_ext_extdebugutils_extdebugutils_vkqueueenddebugutilslabelext, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, queue, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_ext_extdebugutils_extdebugutils_vkqueueinsertdebugutilslabelext, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, queue, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pLabelInfo, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_ext_extdebugutils_extdebugutils_vkcmdbegindebugutilslabelext, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pLabelInfo, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_ext_extdebugutils_extdebugutils_vkcmdenddebugutilslabelext, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_ext_extdebugutils_extdebugutils_vkcmdinsertdebugutilslabelext, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pLabelInfo, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_ext_extdebugutils_extdebugutils_vkcreatedebugutilsmessengerext, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, instance, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pCreateInfo, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pMessenger, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_ext_extdebugutils_extdebugutils_vkdestroydebugutilsmessengerext, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, instance, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, messenger, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_ext_extdebugutils_extdebugutils_vksubmitdebugutilsmessageext, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, instance, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, messageSeverity, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, messageTypes, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pCallbackData, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vulkan_ext_extdebugutils_extdebugutils_method_entry) {
	PHP_ME(Vulkan_Ext_EXTDebugUtils_EXTDebugUtils, vkSetDebugUtilsObjectNameEXT, arginfo_vulkan_ext_extdebugutils_extdebugutils_vksetdebugutilsobjectnameext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Ext_EXTDebugUtils_EXTDebugUtils, vkSetDebugUtilsObjectTagEXT, arginfo_vulkan_ext_extdebugutils_extdebugutils_vksetdebugutilsobjecttagext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Ext_EXTDebugUtils_EXTDebugUtils, vkQueueBeginDebugUtilsLabelEXT, arginfo_vulkan_ext_extdebugutils_extdebugutils_vkqueuebegindebugutilslabelext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Ext_EXTDebugUtils_EXTDebugUtils, vkQueueEndDebugUtilsLabelEXT, arginfo_vulkan_ext_extdebugutils_extdebugutils_vkqueueenddebugutilslabelext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Ext_EXTDebugUtils_EXTDebugUtils, vkQueueInsertDebugUtilsLabelEXT, arginfo_vulkan_ext_extdebugutils_extdebugutils_vkqueueinsertdebugutilslabelext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Ext_EXTDebugUtils_EXTDebugUtils, vkCmdBeginDebugUtilsLabelEXT, arginfo_vulkan_ext_extdebugutils_extdebugutils_vkcmdbegindebugutilslabelext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Ext_EXTDebugUtils_EXTDebugUtils, vkCmdEndDebugUtilsLabelEXT, arginfo_vulkan_ext_extdebugutils_extdebugutils_vkcmdenddebugutilslabelext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Ext_EXTDebugUtils_EXTDebugUtils, vkCmdInsertDebugUtilsLabelEXT, arginfo_vulkan_ext_extdebugutils_extdebugutils_vkcmdinsertdebugutilslabelext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Ext_EXTDebugUtils_EXTDebugUtils, vkCreateDebugUtilsMessengerEXT, arginfo_vulkan_ext_extdebugutils_extdebugutils_vkcreatedebugutilsmessengerext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Ext_EXTDebugUtils_EXTDebugUtils, vkDestroyDebugUtilsMessengerEXT, arginfo_vulkan_ext_extdebugutils_extdebugutils_vkdestroydebugutilsmessengerext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_Ext_EXTDebugUtils_EXTDebugUtils, vkSubmitDebugUtilsMessageEXT, arginfo_vulkan_ext_extdebugutils_extdebugutils_vksubmitdebugutilsmessageext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
