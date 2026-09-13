
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
#include "src/vk-11.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Vulkan_VK_VK11_VK11)
{
	ZEPHIR_REGISTER_CLASS(Vulkan\\VK\\VK11, VK11, vulkan, vk_vk11_vk11, vulkan_vk_vk11_vk11_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Vulkan_VK_VK11_VK11, vkEnumerateInstanceVersion)
{
	zval *pApiVersion_param = NULL, _0;
	zend_long pApiVersion;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(pApiVersion)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &pApiVersion_param);
	ZVAL_LONG(&_0, pApiVersion);
	RETURN_LONG(phpvk_vk11_vkenumerateinstanceversion(&_0));
}

PHP_METHOD(Vulkan_VK_VK11_VK11, vkBindBufferMemory2)
{
	zval *device_param = NULL, *bindInfoCount_param = NULL, *pBindInfos_param = NULL, _0, _1, _2;
	zend_long device, bindInfoCount, pBindInfos;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(bindInfoCount)
		Z_PARAM_LONG(pBindInfos)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &device_param, &bindInfoCount_param, &pBindInfos_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, bindInfoCount);
	ZVAL_LONG(&_2, pBindInfos);
	RETURN_LONG(phpvk_vk11_vkbindbuffermemory2(&_0, &_1, &_2));
}

PHP_METHOD(Vulkan_VK_VK11_VK11, vkBindImageMemory2)
{
	zval *device_param = NULL, *bindInfoCount_param = NULL, *pBindInfos_param = NULL, _0, _1, _2;
	zend_long device, bindInfoCount, pBindInfos;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(bindInfoCount)
		Z_PARAM_LONG(pBindInfos)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &device_param, &bindInfoCount_param, &pBindInfos_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, bindInfoCount);
	ZVAL_LONG(&_2, pBindInfos);
	RETURN_LONG(phpvk_vk11_vkbindimagememory2(&_0, &_1, &_2));
}

PHP_METHOD(Vulkan_VK_VK11_VK11, vkGetDeviceGroupPeerMemoryFeatures)
{
	zval *device_param = NULL, *heapIndex_param = NULL, *localDeviceIndex_param = NULL, *remoteDeviceIndex_param = NULL, *pPeerMemoryFeatures_param = NULL, _0, _1, _2, _3, _4;
	zend_long device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(heapIndex)
		Z_PARAM_LONG(localDeviceIndex)
		Z_PARAM_LONG(remoteDeviceIndex)
		Z_PARAM_LONG(pPeerMemoryFeatures)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &device_param, &heapIndex_param, &localDeviceIndex_param, &remoteDeviceIndex_param, &pPeerMemoryFeatures_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, heapIndex);
	ZVAL_LONG(&_2, localDeviceIndex);
	ZVAL_LONG(&_3, remoteDeviceIndex);
	ZVAL_LONG(&_4, pPeerMemoryFeatures);
	phpvk_vk11_vkgetdevicegrouppeermemoryfeatures(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(Vulkan_VK_VK11_VK11, vkCmdSetDeviceMask)
{
	zval *commandBuffer_param = NULL, *deviceMask_param = NULL, _0, _1;
	zend_long commandBuffer, deviceMask;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(deviceMask)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &commandBuffer_param, &deviceMask_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, deviceMask);
	phpvk_vk11_vkcmdsetdevicemask(&_0, &_1);
}

PHP_METHOD(Vulkan_VK_VK11_VK11, vkEnumeratePhysicalDeviceGroups)
{
	zval *instance_param = NULL, *pPhysicalDeviceGroupCount_param = NULL, *pPhysicalDeviceGroupProperties_param = NULL, _0, _1, _2;
	zend_long instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(instance)
		Z_PARAM_LONG(pPhysicalDeviceGroupCount)
		Z_PARAM_LONG(pPhysicalDeviceGroupProperties)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &instance_param, &pPhysicalDeviceGroupCount_param, &pPhysicalDeviceGroupProperties_param);
	ZVAL_LONG(&_0, instance);
	ZVAL_LONG(&_1, pPhysicalDeviceGroupCount);
	ZVAL_LONG(&_2, pPhysicalDeviceGroupProperties);
	RETURN_LONG(phpvk_vk11_vkenumeratephysicaldevicegroups(&_0, &_1, &_2));
}

PHP_METHOD(Vulkan_VK_VK11_VK11, vkGetImageMemoryRequirements2)
{
	zval *device_param = NULL, *pInfo_param = NULL, *pMemoryRequirements_param = NULL, _0, _1, _2;
	zend_long device, pInfo, pMemoryRequirements;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(pInfo)
		Z_PARAM_LONG(pMemoryRequirements)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &device_param, &pInfo_param, &pMemoryRequirements_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, pInfo);
	ZVAL_LONG(&_2, pMemoryRequirements);
	phpvk_vk11_vkgetimagememoryrequirements2(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK11_VK11, vkGetBufferMemoryRequirements2)
{
	zval *device_param = NULL, *pInfo_param = NULL, *pMemoryRequirements_param = NULL, _0, _1, _2;
	zend_long device, pInfo, pMemoryRequirements;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(pInfo)
		Z_PARAM_LONG(pMemoryRequirements)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &device_param, &pInfo_param, &pMemoryRequirements_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, pInfo);
	ZVAL_LONG(&_2, pMemoryRequirements);
	phpvk_vk11_vkgetbuffermemoryrequirements2(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK11_VK11, vkGetImageSparseMemoryRequirements2)
{
	zval *device_param = NULL, *pInfo_param = NULL, *pSparseMemoryRequirementCount_param = NULL, *pSparseMemoryRequirements_param = NULL, _0, _1, _2, _3;
	zend_long device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(pInfo)
		Z_PARAM_LONG(pSparseMemoryRequirementCount)
		Z_PARAM_LONG(pSparseMemoryRequirements)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &device_param, &pInfo_param, &pSparseMemoryRequirementCount_param, &pSparseMemoryRequirements_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, pInfo);
	ZVAL_LONG(&_2, pSparseMemoryRequirementCount);
	ZVAL_LONG(&_3, pSparseMemoryRequirements);
	phpvk_vk11_vkgetimagesparsememoryrequirements2(&_0, &_1, &_2, &_3);
}

PHP_METHOD(Vulkan_VK_VK11_VK11, vkGetPhysicalDeviceFeatures2)
{
	zval *physicalDevice_param = NULL, *pFeatures_param = NULL, _0, _1;
	zend_long physicalDevice, pFeatures;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(physicalDevice)
		Z_PARAM_LONG(pFeatures)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &physicalDevice_param, &pFeatures_param);
	ZVAL_LONG(&_0, physicalDevice);
	ZVAL_LONG(&_1, pFeatures);
	phpvk_vk11_vkgetphysicaldevicefeatures2(&_0, &_1);
}

PHP_METHOD(Vulkan_VK_VK11_VK11, vkGetPhysicalDeviceProperties2)
{
	zval *physicalDevice_param = NULL, *pProperties_param = NULL, _0, _1;
	zend_long physicalDevice, pProperties;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(physicalDevice)
		Z_PARAM_LONG(pProperties)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &physicalDevice_param, &pProperties_param);
	ZVAL_LONG(&_0, physicalDevice);
	ZVAL_LONG(&_1, pProperties);
	phpvk_vk11_vkgetphysicaldeviceproperties2(&_0, &_1);
}

PHP_METHOD(Vulkan_VK_VK11_VK11, vkGetPhysicalDeviceFormatProperties2)
{
	zval *physicalDevice_param = NULL, *format_param = NULL, *pFormatProperties_param = NULL, _0, _1, _2;
	zend_long physicalDevice, format, pFormatProperties;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(physicalDevice)
		Z_PARAM_LONG(format)
		Z_PARAM_LONG(pFormatProperties)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &physicalDevice_param, &format_param, &pFormatProperties_param);
	ZVAL_LONG(&_0, physicalDevice);
	ZVAL_LONG(&_1, format);
	ZVAL_LONG(&_2, pFormatProperties);
	phpvk_vk11_vkgetphysicaldeviceformatproperties2(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK11_VK11, vkGetPhysicalDeviceImageFormatProperties2)
{
	zval *physicalDevice_param = NULL, *pImageFormatInfo_param = NULL, *pImageFormatProperties_param = NULL, _0, _1, _2;
	zend_long physicalDevice, pImageFormatInfo, pImageFormatProperties;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(physicalDevice)
		Z_PARAM_LONG(pImageFormatInfo)
		Z_PARAM_LONG(pImageFormatProperties)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &physicalDevice_param, &pImageFormatInfo_param, &pImageFormatProperties_param);
	ZVAL_LONG(&_0, physicalDevice);
	ZVAL_LONG(&_1, pImageFormatInfo);
	ZVAL_LONG(&_2, pImageFormatProperties);
	RETURN_LONG(phpvk_vk11_vkgetphysicaldeviceimageformatproperties2(&_0, &_1, &_2));
}

PHP_METHOD(Vulkan_VK_VK11_VK11, vkGetPhysicalDeviceQueueFamilyProperties2)
{
	zval *physicalDevice_param = NULL, *pQueueFamilyPropertyCount_param = NULL, *pQueueFamilyProperties_param = NULL, _0, _1, _2;
	zend_long physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(physicalDevice)
		Z_PARAM_LONG(pQueueFamilyPropertyCount)
		Z_PARAM_LONG(pQueueFamilyProperties)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &physicalDevice_param, &pQueueFamilyPropertyCount_param, &pQueueFamilyProperties_param);
	ZVAL_LONG(&_0, physicalDevice);
	ZVAL_LONG(&_1, pQueueFamilyPropertyCount);
	ZVAL_LONG(&_2, pQueueFamilyProperties);
	phpvk_vk11_vkgetphysicaldevicequeuefamilyproperties2(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK11_VK11, vkGetPhysicalDeviceMemoryProperties2)
{
	zval *physicalDevice_param = NULL, *pMemoryProperties_param = NULL, _0, _1;
	zend_long physicalDevice, pMemoryProperties;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(physicalDevice)
		Z_PARAM_LONG(pMemoryProperties)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &physicalDevice_param, &pMemoryProperties_param);
	ZVAL_LONG(&_0, physicalDevice);
	ZVAL_LONG(&_1, pMemoryProperties);
	phpvk_vk11_vkgetphysicaldevicememoryproperties2(&_0, &_1);
}

PHP_METHOD(Vulkan_VK_VK11_VK11, vkGetPhysicalDeviceSparseImageFormatProperties2)
{
	zval *physicalDevice_param = NULL, *pFormatInfo_param = NULL, *pPropertyCount_param = NULL, *pProperties_param = NULL, _0, _1, _2, _3;
	zend_long physicalDevice, pFormatInfo, pPropertyCount, pProperties;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(physicalDevice)
		Z_PARAM_LONG(pFormatInfo)
		Z_PARAM_LONG(pPropertyCount)
		Z_PARAM_LONG(pProperties)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &physicalDevice_param, &pFormatInfo_param, &pPropertyCount_param, &pProperties_param);
	ZVAL_LONG(&_0, physicalDevice);
	ZVAL_LONG(&_1, pFormatInfo);
	ZVAL_LONG(&_2, pPropertyCount);
	ZVAL_LONG(&_3, pProperties);
	phpvk_vk11_vkgetphysicaldevicesparseimageformatproperties2(&_0, &_1, &_2, &_3);
}

PHP_METHOD(Vulkan_VK_VK11_VK11, vkTrimCommandPool)
{
	zval *device_param = NULL, *commandPool_param = NULL, *flags_param = NULL, _0, _1, _2;
	zend_long device, commandPool, flags;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(commandPool)
		Z_PARAM_LONG(flags)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &device_param, &commandPool_param, &flags_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, commandPool);
	ZVAL_LONG(&_2, flags);
	phpvk_vk11_vktrimcommandpool(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK11_VK11, vkGetDeviceQueue2)
{
	zval *device_param = NULL, *pQueueInfo_param = NULL, *pQueue_param = NULL, _0, _1, _2;
	zend_long device, pQueueInfo, pQueue;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(pQueueInfo)
		Z_PARAM_LONG(pQueue)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &device_param, &pQueueInfo_param, &pQueue_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, pQueueInfo);
	ZVAL_LONG(&_2, pQueue);
	phpvk_vk11_vkgetdevicequeue2(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK11_VK11, vkGetPhysicalDeviceExternalBufferProperties)
{
	zval *physicalDevice_param = NULL, *pExternalBufferInfo_param = NULL, *pExternalBufferProperties_param = NULL, _0, _1, _2;
	zend_long physicalDevice, pExternalBufferInfo, pExternalBufferProperties;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(physicalDevice)
		Z_PARAM_LONG(pExternalBufferInfo)
		Z_PARAM_LONG(pExternalBufferProperties)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &physicalDevice_param, &pExternalBufferInfo_param, &pExternalBufferProperties_param);
	ZVAL_LONG(&_0, physicalDevice);
	ZVAL_LONG(&_1, pExternalBufferInfo);
	ZVAL_LONG(&_2, pExternalBufferProperties);
	phpvk_vk11_vkgetphysicaldeviceexternalbufferproperties(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK11_VK11, vkGetPhysicalDeviceExternalFenceProperties)
{
	zval *physicalDevice_param = NULL, *pExternalFenceInfo_param = NULL, *pExternalFenceProperties_param = NULL, _0, _1, _2;
	zend_long physicalDevice, pExternalFenceInfo, pExternalFenceProperties;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(physicalDevice)
		Z_PARAM_LONG(pExternalFenceInfo)
		Z_PARAM_LONG(pExternalFenceProperties)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &physicalDevice_param, &pExternalFenceInfo_param, &pExternalFenceProperties_param);
	ZVAL_LONG(&_0, physicalDevice);
	ZVAL_LONG(&_1, pExternalFenceInfo);
	ZVAL_LONG(&_2, pExternalFenceProperties);
	phpvk_vk11_vkgetphysicaldeviceexternalfenceproperties(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK11_VK11, vkGetPhysicalDeviceExternalSemaphoreProperties)
{
	zval *physicalDevice_param = NULL, *pExternalSemaphoreInfo_param = NULL, *pExternalSemaphoreProperties_param = NULL, _0, _1, _2;
	zend_long physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(physicalDevice)
		Z_PARAM_LONG(pExternalSemaphoreInfo)
		Z_PARAM_LONG(pExternalSemaphoreProperties)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &physicalDevice_param, &pExternalSemaphoreInfo_param, &pExternalSemaphoreProperties_param);
	ZVAL_LONG(&_0, physicalDevice);
	ZVAL_LONG(&_1, pExternalSemaphoreInfo);
	ZVAL_LONG(&_2, pExternalSemaphoreProperties);
	phpvk_vk11_vkgetphysicaldeviceexternalsemaphoreproperties(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK11_VK11, vkCmdDispatchBase)
{
	zval *commandBuffer_param = NULL, *baseGroupX_param = NULL, *baseGroupY_param = NULL, *baseGroupZ_param = NULL, *groupCountX_param = NULL, *groupCountY_param = NULL, *groupCountZ_param = NULL, _0, _1, _2, _3, _4, _5, _6;
	zend_long commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZEND_PARSE_PARAMETERS_START(7, 7)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(baseGroupX)
		Z_PARAM_LONG(baseGroupY)
		Z_PARAM_LONG(baseGroupZ)
		Z_PARAM_LONG(groupCountX)
		Z_PARAM_LONG(groupCountY)
		Z_PARAM_LONG(groupCountZ)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(7, 0, &commandBuffer_param, &baseGroupX_param, &baseGroupY_param, &baseGroupZ_param, &groupCountX_param, &groupCountY_param, &groupCountZ_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, baseGroupX);
	ZVAL_LONG(&_2, baseGroupY);
	ZVAL_LONG(&_3, baseGroupZ);
	ZVAL_LONG(&_4, groupCountX);
	ZVAL_LONG(&_5, groupCountY);
	ZVAL_LONG(&_6, groupCountZ);
	phpvk_vk11_vkcmddispatchbase(&_0, &_1, &_2, &_3, &_4, &_5, &_6);
}

PHP_METHOD(Vulkan_VK_VK11_VK11, vkCreateDescriptorUpdateTemplate)
{
	zval *device_param = NULL, *pCreateInfo_param = NULL, *pAllocator_param = NULL, *pDescriptorUpdateTemplate_param = NULL, _0, _1, _2, _3;
	zend_long device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(pCreateInfo)
		Z_PARAM_LONG(pAllocator)
		Z_PARAM_LONG(pDescriptorUpdateTemplate)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &device_param, &pCreateInfo_param, &pAllocator_param, &pDescriptorUpdateTemplate_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, pCreateInfo);
	ZVAL_LONG(&_2, pAllocator);
	ZVAL_LONG(&_3, pDescriptorUpdateTemplate);
	RETURN_LONG(phpvk_vk11_vkcreatedescriptorupdatetemplate(&_0, &_1, &_2, &_3));
}

PHP_METHOD(Vulkan_VK_VK11_VK11, vkDestroyDescriptorUpdateTemplate)
{
	zval *device_param = NULL, *descriptorUpdateTemplate_param = NULL, *pAllocator_param = NULL, _0, _1, _2;
	zend_long device, descriptorUpdateTemplate, pAllocator;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(descriptorUpdateTemplate)
		Z_PARAM_LONG(pAllocator)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &device_param, &descriptorUpdateTemplate_param, &pAllocator_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, descriptorUpdateTemplate);
	ZVAL_LONG(&_2, pAllocator);
	phpvk_vk11_vkdestroydescriptorupdatetemplate(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK11_VK11, vkUpdateDescriptorSetWithTemplate)
{
	zval *device_param = NULL, *descriptorSet_param = NULL, *descriptorUpdateTemplate_param = NULL, *pData_param = NULL, _0, _1, _2, _3;
	zend_long device, descriptorSet, descriptorUpdateTemplate, pData;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(descriptorSet)
		Z_PARAM_LONG(descriptorUpdateTemplate)
		Z_PARAM_LONG(pData)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &device_param, &descriptorSet_param, &descriptorUpdateTemplate_param, &pData_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, descriptorSet);
	ZVAL_LONG(&_2, descriptorUpdateTemplate);
	ZVAL_LONG(&_3, pData);
	phpvk_vk11_vkupdatedescriptorsetwithtemplate(&_0, &_1, &_2, &_3);
}

PHP_METHOD(Vulkan_VK_VK11_VK11, vkGetDescriptorSetLayoutSupport)
{
	zval *device_param = NULL, *pCreateInfo_param = NULL, *pSupport_param = NULL, _0, _1, _2;
	zend_long device, pCreateInfo, pSupport;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(pCreateInfo)
		Z_PARAM_LONG(pSupport)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &device_param, &pCreateInfo_param, &pSupport_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, pCreateInfo);
	ZVAL_LONG(&_2, pSupport);
	phpvk_vk11_vkgetdescriptorsetlayoutsupport(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK11_VK11, vkCreateSamplerYcbcrConversion)
{
	zval *device_param = NULL, *pCreateInfo_param = NULL, *pAllocator_param = NULL, *pYcbcrConversion_param = NULL, _0, _1, _2, _3;
	zend_long device, pCreateInfo, pAllocator, pYcbcrConversion;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(pCreateInfo)
		Z_PARAM_LONG(pAllocator)
		Z_PARAM_LONG(pYcbcrConversion)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &device_param, &pCreateInfo_param, &pAllocator_param, &pYcbcrConversion_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, pCreateInfo);
	ZVAL_LONG(&_2, pAllocator);
	ZVAL_LONG(&_3, pYcbcrConversion);
	RETURN_LONG(phpvk_vk11_vkcreatesamplerycbcrconversion(&_0, &_1, &_2, &_3));
}

PHP_METHOD(Vulkan_VK_VK11_VK11, vkDestroySamplerYcbcrConversion)
{
	zval *device_param = NULL, *ycbcrConversion_param = NULL, *pAllocator_param = NULL, _0, _1, _2;
	zend_long device, ycbcrConversion, pAllocator;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(ycbcrConversion)
		Z_PARAM_LONG(pAllocator)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &device_param, &ycbcrConversion_param, &pAllocator_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, ycbcrConversion);
	ZVAL_LONG(&_2, pAllocator);
	phpvk_vk11_vkdestroysamplerycbcrconversion(&_0, &_1, &_2);
}

