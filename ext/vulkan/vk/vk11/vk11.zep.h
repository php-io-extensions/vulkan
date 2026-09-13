
extern zend_class_entry *vulkan_vk_vk11_vk11_ce;

ZEPHIR_INIT_CLASS(Vulkan_VK_VK11_VK11);

PHP_METHOD(Vulkan_VK_VK11_VK11, vkEnumerateInstanceVersion);
PHP_METHOD(Vulkan_VK_VK11_VK11, vkBindBufferMemory2);
PHP_METHOD(Vulkan_VK_VK11_VK11, vkBindImageMemory2);
PHP_METHOD(Vulkan_VK_VK11_VK11, vkGetDeviceGroupPeerMemoryFeatures);
PHP_METHOD(Vulkan_VK_VK11_VK11, vkCmdSetDeviceMask);
PHP_METHOD(Vulkan_VK_VK11_VK11, vkEnumeratePhysicalDeviceGroups);
PHP_METHOD(Vulkan_VK_VK11_VK11, vkGetImageMemoryRequirements2);
PHP_METHOD(Vulkan_VK_VK11_VK11, vkGetBufferMemoryRequirements2);
PHP_METHOD(Vulkan_VK_VK11_VK11, vkGetImageSparseMemoryRequirements2);
PHP_METHOD(Vulkan_VK_VK11_VK11, vkGetPhysicalDeviceFeatures2);
PHP_METHOD(Vulkan_VK_VK11_VK11, vkGetPhysicalDeviceProperties2);
PHP_METHOD(Vulkan_VK_VK11_VK11, vkGetPhysicalDeviceFormatProperties2);
PHP_METHOD(Vulkan_VK_VK11_VK11, vkGetPhysicalDeviceImageFormatProperties2);
PHP_METHOD(Vulkan_VK_VK11_VK11, vkGetPhysicalDeviceQueueFamilyProperties2);
PHP_METHOD(Vulkan_VK_VK11_VK11, vkGetPhysicalDeviceMemoryProperties2);
PHP_METHOD(Vulkan_VK_VK11_VK11, vkGetPhysicalDeviceSparseImageFormatProperties2);
PHP_METHOD(Vulkan_VK_VK11_VK11, vkTrimCommandPool);
PHP_METHOD(Vulkan_VK_VK11_VK11, vkGetDeviceQueue2);
PHP_METHOD(Vulkan_VK_VK11_VK11, vkGetPhysicalDeviceExternalBufferProperties);
PHP_METHOD(Vulkan_VK_VK11_VK11, vkGetPhysicalDeviceExternalFenceProperties);
PHP_METHOD(Vulkan_VK_VK11_VK11, vkGetPhysicalDeviceExternalSemaphoreProperties);
PHP_METHOD(Vulkan_VK_VK11_VK11, vkCmdDispatchBase);
PHP_METHOD(Vulkan_VK_VK11_VK11, vkCreateDescriptorUpdateTemplate);
PHP_METHOD(Vulkan_VK_VK11_VK11, vkDestroyDescriptorUpdateTemplate);
PHP_METHOD(Vulkan_VK_VK11_VK11, vkUpdateDescriptorSetWithTemplate);
PHP_METHOD(Vulkan_VK_VK11_VK11, vkGetDescriptorSetLayoutSupport);
PHP_METHOD(Vulkan_VK_VK11_VK11, vkCreateSamplerYcbcrConversion);
PHP_METHOD(Vulkan_VK_VK11_VK11, vkDestroySamplerYcbcrConversion);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk11_vk11_vkenumerateinstanceversion, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pApiVersion, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk11_vk11_vkbindbuffermemory2, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, bindInfoCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pBindInfos, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk11_vk11_vkbindimagememory2, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, bindInfoCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pBindInfos, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk11_vk11_vkgetdevicegrouppeermemoryfeatures, 0, 5, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, heapIndex, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, localDeviceIndex, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, remoteDeviceIndex, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pPeerMemoryFeatures, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk11_vk11_vkcmdsetdevicemask, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, deviceMask, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk11_vk11_vkenumeratephysicaldevicegroups, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, instance, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pPhysicalDeviceGroupCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pPhysicalDeviceGroupProperties, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk11_vk11_vkgetimagememoryrequirements2, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pInfo, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pMemoryRequirements, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk11_vk11_vkgetbuffermemoryrequirements2, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pInfo, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pMemoryRequirements, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk11_vk11_vkgetimagesparsememoryrequirements2, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pInfo, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pSparseMemoryRequirementCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pSparseMemoryRequirements, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk11_vk11_vkgetphysicaldevicefeatures2, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, physicalDevice, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pFeatures, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk11_vk11_vkgetphysicaldeviceproperties2, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, physicalDevice, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pProperties, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk11_vk11_vkgetphysicaldeviceformatproperties2, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, physicalDevice, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, format, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pFormatProperties, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk11_vk11_vkgetphysicaldeviceimageformatproperties2, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, physicalDevice, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pImageFormatInfo, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pImageFormatProperties, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk11_vk11_vkgetphysicaldevicequeuefamilyproperties2, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, physicalDevice, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pQueueFamilyPropertyCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pQueueFamilyProperties, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk11_vk11_vkgetphysicaldevicememoryproperties2, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, physicalDevice, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pMemoryProperties, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk11_vk11_vkgetphysicaldevicesparseimageformatproperties2, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, physicalDevice, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pFormatInfo, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pPropertyCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pProperties, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk11_vk11_vktrimcommandpool, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, commandPool, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, flags, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk11_vk11_vkgetdevicequeue2, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pQueueInfo, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pQueue, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk11_vk11_vkgetphysicaldeviceexternalbufferproperties, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, physicalDevice, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pExternalBufferInfo, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pExternalBufferProperties, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk11_vk11_vkgetphysicaldeviceexternalfenceproperties, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, physicalDevice, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pExternalFenceInfo, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pExternalFenceProperties, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk11_vk11_vkgetphysicaldeviceexternalsemaphoreproperties, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, physicalDevice, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pExternalSemaphoreInfo, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pExternalSemaphoreProperties, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk11_vk11_vkcmddispatchbase, 0, 7, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, commandBuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, baseGroupX, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, baseGroupY, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, baseGroupZ, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, groupCountX, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, groupCountY, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, groupCountZ, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk11_vk11_vkcreatedescriptorupdatetemplate, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pCreateInfo, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pDescriptorUpdateTemplate, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk11_vk11_vkdestroydescriptorupdatetemplate, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, descriptorUpdateTemplate, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk11_vk11_vkupdatedescriptorsetwithtemplate, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, descriptorSet, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, descriptorUpdateTemplate, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pData, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk11_vk11_vkgetdescriptorsetlayoutsupport, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pCreateInfo, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pSupport, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk11_vk11_vkcreatesamplerycbcrconversion, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pCreateInfo, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pYcbcrConversion, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vulkan_vk_vk11_vk11_vkdestroysamplerycbcrconversion, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, device, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ycbcrConversion, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vulkan_vk_vk11_vk11_method_entry) {
	PHP_ME(Vulkan_VK_VK11_VK11, vkEnumerateInstanceVersion, arginfo_vulkan_vk_vk11_vk11_vkenumerateinstanceversion, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK11_VK11, vkBindBufferMemory2, arginfo_vulkan_vk_vk11_vk11_vkbindbuffermemory2, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK11_VK11, vkBindImageMemory2, arginfo_vulkan_vk_vk11_vk11_vkbindimagememory2, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK11_VK11, vkGetDeviceGroupPeerMemoryFeatures, arginfo_vulkan_vk_vk11_vk11_vkgetdevicegrouppeermemoryfeatures, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK11_VK11, vkCmdSetDeviceMask, arginfo_vulkan_vk_vk11_vk11_vkcmdsetdevicemask, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK11_VK11, vkEnumeratePhysicalDeviceGroups, arginfo_vulkan_vk_vk11_vk11_vkenumeratephysicaldevicegroups, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK11_VK11, vkGetImageMemoryRequirements2, arginfo_vulkan_vk_vk11_vk11_vkgetimagememoryrequirements2, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK11_VK11, vkGetBufferMemoryRequirements2, arginfo_vulkan_vk_vk11_vk11_vkgetbuffermemoryrequirements2, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK11_VK11, vkGetImageSparseMemoryRequirements2, arginfo_vulkan_vk_vk11_vk11_vkgetimagesparsememoryrequirements2, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK11_VK11, vkGetPhysicalDeviceFeatures2, arginfo_vulkan_vk_vk11_vk11_vkgetphysicaldevicefeatures2, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK11_VK11, vkGetPhysicalDeviceProperties2, arginfo_vulkan_vk_vk11_vk11_vkgetphysicaldeviceproperties2, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK11_VK11, vkGetPhysicalDeviceFormatProperties2, arginfo_vulkan_vk_vk11_vk11_vkgetphysicaldeviceformatproperties2, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK11_VK11, vkGetPhysicalDeviceImageFormatProperties2, arginfo_vulkan_vk_vk11_vk11_vkgetphysicaldeviceimageformatproperties2, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK11_VK11, vkGetPhysicalDeviceQueueFamilyProperties2, arginfo_vulkan_vk_vk11_vk11_vkgetphysicaldevicequeuefamilyproperties2, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK11_VK11, vkGetPhysicalDeviceMemoryProperties2, arginfo_vulkan_vk_vk11_vk11_vkgetphysicaldevicememoryproperties2, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK11_VK11, vkGetPhysicalDeviceSparseImageFormatProperties2, arginfo_vulkan_vk_vk11_vk11_vkgetphysicaldevicesparseimageformatproperties2, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK11_VK11, vkTrimCommandPool, arginfo_vulkan_vk_vk11_vk11_vktrimcommandpool, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK11_VK11, vkGetDeviceQueue2, arginfo_vulkan_vk_vk11_vk11_vkgetdevicequeue2, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK11_VK11, vkGetPhysicalDeviceExternalBufferProperties, arginfo_vulkan_vk_vk11_vk11_vkgetphysicaldeviceexternalbufferproperties, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK11_VK11, vkGetPhysicalDeviceExternalFenceProperties, arginfo_vulkan_vk_vk11_vk11_vkgetphysicaldeviceexternalfenceproperties, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK11_VK11, vkGetPhysicalDeviceExternalSemaphoreProperties, arginfo_vulkan_vk_vk11_vk11_vkgetphysicaldeviceexternalsemaphoreproperties, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK11_VK11, vkCmdDispatchBase, arginfo_vulkan_vk_vk11_vk11_vkcmddispatchbase, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK11_VK11, vkCreateDescriptorUpdateTemplate, arginfo_vulkan_vk_vk11_vk11_vkcreatedescriptorupdatetemplate, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK11_VK11, vkDestroyDescriptorUpdateTemplate, arginfo_vulkan_vk_vk11_vk11_vkdestroydescriptorupdatetemplate, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK11_VK11, vkUpdateDescriptorSetWithTemplate, arginfo_vulkan_vk_vk11_vk11_vkupdatedescriptorsetwithtemplate, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK11_VK11, vkGetDescriptorSetLayoutSupport, arginfo_vulkan_vk_vk11_vk11_vkgetdescriptorsetlayoutsupport, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK11_VK11, vkCreateSamplerYcbcrConversion, arginfo_vulkan_vk_vk11_vk11_vkcreatesamplerycbcrconversion, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vulkan_VK_VK11_VK11, vkDestroySamplerYcbcrConversion, arginfo_vulkan_vk_vk11_vk11_vkdestroysamplerycbcrconversion, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
