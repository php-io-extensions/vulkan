
extern zend_class_entry *vulkan_vk_vk12_vk12_ce;

ZEPHIR_INIT_CLASS(Vulkan_VK_VK12_VK12);

PHP_METHOD(Vulkan_VK_VK12_VK12, vkResetQueryPool);
PHP_METHOD(Vulkan_VK_VK12_VK12, vkGetSemaphoreCounterValue);
PHP_METHOD(Vulkan_VK_VK12_VK12, vkWaitSemaphores);
PHP_METHOD(Vulkan_VK_VK12_VK12, vkSignalSemaphore);
PHP_METHOD(Vulkan_VK_VK12_VK12, vkGetBufferDeviceAddress);
PHP_METHOD(Vulkan_VK_VK12_VK12, vkGetBufferOpaqueCaptureAddress);
PHP_METHOD(Vulkan_VK_VK12_VK12, vkGetDeviceMemoryOpaqueCaptureAddress);
PHP_METHOD(Vulkan_VK_VK12_VK12, vkCmdDrawIndirectCount);
PHP_METHOD(Vulkan_VK_VK12_VK12, vkCmdDrawIndexedIndirectCount);
PHP_METHOD(Vulkan_VK_VK12_VK12, vkCreateRenderPass2);
PHP_METHOD(Vulkan_VK_VK12_VK12, vkCmdBeginRenderPass2);
PHP_METHOD(Vulkan_VK_VK12_VK12, vkCmdNextSubpass2);
PHP_METHOD(Vulkan_VK_VK12_VK12, vkCmdEndRenderPass2);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk12_vk12_vkresetquerypool, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, queryPool, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, firstQuery, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, queryCount, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk12_vk12_vkgetsemaphorecountervalue, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, semaphore, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pValue, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk12_vk12_vkwaitsemaphores, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pWaitInfo, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, timeout, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk12_vk12_vksignalsemaphore, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pSignalInfo, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk12_vk12_vkgetbufferdeviceaddress, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pInfo, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk12_vk12_vkgetbufferopaquecaptureaddress, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pInfo, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk12_vk12_vkgetdevicememoryopaquecaptureaddress, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pInfo, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk12_vk12_vkcmddrawindirectcount, 0, 7, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, buffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, offset, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, countBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, countBufferOffset, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, maxDrawCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, stride, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk12_vk12_vkcmddrawindexedindirectcount, 0, 7, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, buffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, offset, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, countBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, countBufferOffset, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, maxDrawCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, stride, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk12_vk12_vkcreaterenderpass2, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pCreateInfo, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pRenderPass, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk12_vk12_vkcmdbeginrenderpass2, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pRenderPassBegin, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pSubpassBeginInfo, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk12_vk12_vkcmdnextsubpass2, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pSubpassBeginInfo, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pSubpassEndInfo, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk12_vk12_vkcmdendrenderpass2, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pSubpassEndInfo, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vulkan_vk_vk12_vk12_method_entry) {
	PHP_ME(Vulkan_VK_VK12_VK12, vkResetQueryPool, arginfo_vulkan_vk_vk12_vk12_vkresetquerypool, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK12_VK12, vkGetSemaphoreCounterValue, arginfo_vulkan_vk_vk12_vk12_vkgetsemaphorecountervalue, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK12_VK12, vkWaitSemaphores, arginfo_vulkan_vk_vk12_vk12_vkwaitsemaphores, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK12_VK12, vkSignalSemaphore, arginfo_vulkan_vk_vk12_vk12_vksignalsemaphore, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK12_VK12, vkGetBufferDeviceAddress, arginfo_vulkan_vk_vk12_vk12_vkgetbufferdeviceaddress, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK12_VK12, vkGetBufferOpaqueCaptureAddress, arginfo_vulkan_vk_vk12_vk12_vkgetbufferopaquecaptureaddress, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK12_VK12, vkGetDeviceMemoryOpaqueCaptureAddress, arginfo_vulkan_vk_vk12_vk12_vkgetdevicememoryopaquecaptureaddress, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK12_VK12, vkCmdDrawIndirectCount, arginfo_vulkan_vk_vk12_vk12_vkcmddrawindirectcount, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK12_VK12, vkCmdDrawIndexedIndirectCount, arginfo_vulkan_vk_vk12_vk12_vkcmddrawindexedindirectcount, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK12_VK12, vkCreateRenderPass2, arginfo_vulkan_vk_vk12_vk12_vkcreaterenderpass2, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK12_VK12, vkCmdBeginRenderPass2, arginfo_vulkan_vk_vk12_vk12_vkcmdbeginrenderpass2, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK12_VK12, vkCmdNextSubpass2, arginfo_vulkan_vk_vk12_vk12_vkcmdnextsubpass2, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK12_VK12, vkCmdEndRenderPass2, arginfo_vulkan_vk_vk12_vk12_vkcmdendrenderpass2, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
