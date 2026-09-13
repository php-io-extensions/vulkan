
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
#include "src/vk-10.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Vulkan_VK_VK10_VK10)
{
	ZEPHIR_REGISTER_CLASS(Vulkan\\VK\\VK10, VK10, vulkan, vk_vk10_vk10, vulkan_vk_vk10_vk10_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCreateInstance)
{
	zval *pCreateInfo_param = NULL, *pAllocator_param = NULL, *pInstance_param = NULL, _0, _1, _2;
	zend_long pCreateInfo, pAllocator, pInstance;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(pCreateInfo)
		Z_PARAM_LONG(pAllocator)
		Z_PARAM_LONG(pInstance)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &pCreateInfo_param, &pAllocator_param, &pInstance_param);
	ZVAL_LONG(&_0, pCreateInfo);
	ZVAL_LONG(&_1, pAllocator);
	ZVAL_LONG(&_2, pInstance);
	RETURN_LONG(phpvk_vk10_vkcreateinstance(&_0, &_1, &_2));
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkDestroyInstance)
{
	zval *instance_param = NULL, *pAllocator_param = NULL, _0, _1;
	zend_long instance, pAllocator;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(instance)
		Z_PARAM_LONG(pAllocator)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &instance_param, &pAllocator_param);
	ZVAL_LONG(&_0, instance);
	ZVAL_LONG(&_1, pAllocator);
	phpvk_vk10_vkdestroyinstance(&_0, &_1);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkEnumeratePhysicalDevices)
{
	zval *instance_param = NULL, *pPhysicalDeviceCount_param = NULL, *pPhysicalDevices_param = NULL, _0, _1, _2;
	zend_long instance, pPhysicalDeviceCount, pPhysicalDevices;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(instance)
		Z_PARAM_LONG(pPhysicalDeviceCount)
		Z_PARAM_LONG(pPhysicalDevices)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &instance_param, &pPhysicalDeviceCount_param, &pPhysicalDevices_param);
	ZVAL_LONG(&_0, instance);
	ZVAL_LONG(&_1, pPhysicalDeviceCount);
	ZVAL_LONG(&_2, pPhysicalDevices);
	RETURN_LONG(phpvk_vk10_vkenumeratephysicaldevices(&_0, &_1, &_2));
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkGetPhysicalDeviceFeatures)
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
	phpvk_vk10_vkgetphysicaldevicefeatures(&_0, &_1);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkGetPhysicalDeviceFormatProperties)
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
	phpvk_vk10_vkgetphysicaldeviceformatproperties(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkGetPhysicalDeviceImageFormatProperties)
{
	zval *physicalDevice_param = NULL, *format_param = NULL, *type_param = NULL, *tiling_param = NULL, *usage_param = NULL, *flags_param = NULL, *pImageFormatProperties_param = NULL, _0, _1, _2, _3, _4, _5, _6;
	zend_long physicalDevice, format, type, tiling, usage, flags, pImageFormatProperties;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZEND_PARSE_PARAMETERS_START(7, 7)
		Z_PARAM_LONG(physicalDevice)
		Z_PARAM_LONG(format)
		Z_PARAM_LONG(type)
		Z_PARAM_LONG(tiling)
		Z_PARAM_LONG(usage)
		Z_PARAM_LONG(flags)
		Z_PARAM_LONG(pImageFormatProperties)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(7, 0, &physicalDevice_param, &format_param, &type_param, &tiling_param, &usage_param, &flags_param, &pImageFormatProperties_param);
	ZVAL_LONG(&_0, physicalDevice);
	ZVAL_LONG(&_1, format);
	ZVAL_LONG(&_2, type);
	ZVAL_LONG(&_3, tiling);
	ZVAL_LONG(&_4, usage);
	ZVAL_LONG(&_5, flags);
	ZVAL_LONG(&_6, pImageFormatProperties);
	RETURN_LONG(phpvk_vk10_vkgetphysicaldeviceimageformatproperties(&_0, &_1, &_2, &_3, &_4, &_5, &_6));
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkGetPhysicalDeviceProperties)
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
	phpvk_vk10_vkgetphysicaldeviceproperties(&_0, &_1);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkGetPhysicalDeviceQueueFamilyProperties)
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
	phpvk_vk10_vkgetphysicaldevicequeuefamilyproperties(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkGetPhysicalDeviceMemoryProperties)
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
	phpvk_vk10_vkgetphysicaldevicememoryproperties(&_0, &_1);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkGetInstanceProcAddr)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval pName;
	zval *instance_param = NULL, *pName_param = NULL, _0;
	zend_long instance;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&pName);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(instance)
		Z_PARAM_STR(pName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &instance_param, &pName_param);
	zephir_get_strval(&pName, pName_param);
	ZVAL_LONG(&_0, instance);
	RETURN_MM_LONG(phpvk_vk10_vkgetinstanceprocaddr(&_0, &pName));
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkGetDeviceProcAddr)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval pName;
	zval *device_param = NULL, *pName_param = NULL, _0;
	zend_long device;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&pName);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(device)
		Z_PARAM_STR(pName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &device_param, &pName_param);
	zephir_get_strval(&pName, pName_param);
	ZVAL_LONG(&_0, device);
	RETURN_MM_LONG(phpvk_vk10_vkgetdeviceprocaddr(&_0, &pName));
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCreateDevice)
{
	zval *physicalDevice_param = NULL, *pCreateInfo_param = NULL, *pAllocator_param = NULL, *pDevice_param = NULL, _0, _1, _2, _3;
	zend_long physicalDevice, pCreateInfo, pAllocator, pDevice;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(physicalDevice)
		Z_PARAM_LONG(pCreateInfo)
		Z_PARAM_LONG(pAllocator)
		Z_PARAM_LONG(pDevice)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &physicalDevice_param, &pCreateInfo_param, &pAllocator_param, &pDevice_param);
	ZVAL_LONG(&_0, physicalDevice);
	ZVAL_LONG(&_1, pCreateInfo);
	ZVAL_LONG(&_2, pAllocator);
	ZVAL_LONG(&_3, pDevice);
	RETURN_LONG(phpvk_vk10_vkcreatedevice(&_0, &_1, &_2, &_3));
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkDestroyDevice)
{
	zval *device_param = NULL, *pAllocator_param = NULL, _0, _1;
	zend_long device, pAllocator;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(pAllocator)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &device_param, &pAllocator_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, pAllocator);
	phpvk_vk10_vkdestroydevice(&_0, &_1);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkEnumerateInstanceExtensionProperties)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long pPropertyCount, pProperties;
	zval *pLayerName_param = NULL, *pPropertyCount_param = NULL, *pProperties_param = NULL, _0, _1;
	zval pLayerName;

	ZVAL_UNDEF(&pLayerName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(pLayerName)
		Z_PARAM_LONG(pPropertyCount)
		Z_PARAM_LONG(pProperties)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &pLayerName_param, &pPropertyCount_param, &pProperties_param);
	zephir_get_strval(&pLayerName, pLayerName_param);
	ZVAL_LONG(&_0, pPropertyCount);
	ZVAL_LONG(&_1, pProperties);
	RETURN_MM_LONG(phpvk_vk10_vkenumerateinstanceextensionproperties(&pLayerName, &_0, &_1));
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkEnumerateDeviceExtensionProperties)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval pLayerName;
	zval *physicalDevice_param = NULL, *pLayerName_param = NULL, *pPropertyCount_param = NULL, *pProperties_param = NULL, _0, _1, _2;
	zend_long physicalDevice, pPropertyCount, pProperties;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&pLayerName);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(physicalDevice)
		Z_PARAM_STR(pLayerName)
		Z_PARAM_LONG(pPropertyCount)
		Z_PARAM_LONG(pProperties)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 4, 0, &physicalDevice_param, &pLayerName_param, &pPropertyCount_param, &pProperties_param);
	zephir_get_strval(&pLayerName, pLayerName_param);
	ZVAL_LONG(&_0, physicalDevice);
	ZVAL_LONG(&_1, pPropertyCount);
	ZVAL_LONG(&_2, pProperties);
	RETURN_MM_LONG(phpvk_vk10_vkenumeratedeviceextensionproperties(&_0, &pLayerName, &_1, &_2));
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkEnumerateInstanceLayerProperties)
{
	zval *pPropertyCount_param = NULL, *pProperties_param = NULL, _0, _1;
	zend_long pPropertyCount, pProperties;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(pPropertyCount)
		Z_PARAM_LONG(pProperties)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &pPropertyCount_param, &pProperties_param);
	ZVAL_LONG(&_0, pPropertyCount);
	ZVAL_LONG(&_1, pProperties);
	RETURN_LONG(phpvk_vk10_vkenumerateinstancelayerproperties(&_0, &_1));
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkEnumerateDeviceLayerProperties)
{
	zval *physicalDevice_param = NULL, *pPropertyCount_param = NULL, *pProperties_param = NULL, _0, _1, _2;
	zend_long physicalDevice, pPropertyCount, pProperties;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(physicalDevice)
		Z_PARAM_LONG(pPropertyCount)
		Z_PARAM_LONG(pProperties)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &physicalDevice_param, &pPropertyCount_param, &pProperties_param);
	ZVAL_LONG(&_0, physicalDevice);
	ZVAL_LONG(&_1, pPropertyCount);
	ZVAL_LONG(&_2, pProperties);
	RETURN_LONG(phpvk_vk10_vkenumeratedevicelayerproperties(&_0, &_1, &_2));
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkGetDeviceQueue)
{
	zval *device_param = NULL, *queueFamilyIndex_param = NULL, *queueIndex_param = NULL, *pQueue_param = NULL, _0, _1, _2, _3;
	zend_long device, queueFamilyIndex, queueIndex, pQueue;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(queueFamilyIndex)
		Z_PARAM_LONG(queueIndex)
		Z_PARAM_LONG(pQueue)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &device_param, &queueFamilyIndex_param, &queueIndex_param, &pQueue_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, queueFamilyIndex);
	ZVAL_LONG(&_2, queueIndex);
	ZVAL_LONG(&_3, pQueue);
	phpvk_vk10_vkgetdevicequeue(&_0, &_1, &_2, &_3);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkQueueSubmit)
{
	zval *queue_param = NULL, *submitCount_param = NULL, *pSubmits_param = NULL, *fence_param = NULL, _0, _1, _2, _3;
	zend_long queue, submitCount, pSubmits, fence;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(queue)
		Z_PARAM_LONG(submitCount)
		Z_PARAM_LONG(pSubmits)
		Z_PARAM_LONG(fence)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &queue_param, &submitCount_param, &pSubmits_param, &fence_param);
	ZVAL_LONG(&_0, queue);
	ZVAL_LONG(&_1, submitCount);
	ZVAL_LONG(&_2, pSubmits);
	ZVAL_LONG(&_3, fence);
	RETURN_LONG(phpvk_vk10_vkqueuesubmit(&_0, &_1, &_2, &_3));
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkQueueWaitIdle)
{
	zval *queue_param = NULL, _0;
	zend_long queue;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(queue)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &queue_param);
	ZVAL_LONG(&_0, queue);
	RETURN_LONG(phpvk_vk10_vkqueuewaitidle(&_0));
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkDeviceWaitIdle)
{
	zval *device_param = NULL, _0;
	zend_long device;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(device)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &device_param);
	ZVAL_LONG(&_0, device);
	RETURN_LONG(phpvk_vk10_vkdevicewaitidle(&_0));
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkAllocateMemory)
{
	zval *device_param = NULL, *pAllocateInfo_param = NULL, *pAllocator_param = NULL, *pMemory_param = NULL, _0, _1, _2, _3;
	zend_long device, pAllocateInfo, pAllocator, pMemory;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(pAllocateInfo)
		Z_PARAM_LONG(pAllocator)
		Z_PARAM_LONG(pMemory)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &device_param, &pAllocateInfo_param, &pAllocator_param, &pMemory_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, pAllocateInfo);
	ZVAL_LONG(&_2, pAllocator);
	ZVAL_LONG(&_3, pMemory);
	RETURN_LONG(phpvk_vk10_vkallocatememory(&_0, &_1, &_2, &_3));
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkFreeMemory)
{
	zval *device_param = NULL, *memory_param = NULL, *pAllocator_param = NULL, _0, _1, _2;
	zend_long device, memory, pAllocator;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(memory)
		Z_PARAM_LONG(pAllocator)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &device_param, &memory_param, &pAllocator_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, memory);
	ZVAL_LONG(&_2, pAllocator);
	phpvk_vk10_vkfreememory(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkMapMemory)
{
	zval *device_param = NULL, *memory_param = NULL, *offset_param = NULL, *size_param = NULL, *flags_param = NULL, *ppData_param = NULL, _0, _1, _2, _3, _4, _5;
	zend_long device, memory, offset, size, flags, ppData;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(memory)
		Z_PARAM_LONG(offset)
		Z_PARAM_LONG(size)
		Z_PARAM_LONG(flags)
		Z_PARAM_LONG(ppData)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(6, 0, &device_param, &memory_param, &offset_param, &size_param, &flags_param, &ppData_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, memory);
	ZVAL_LONG(&_2, offset);
	ZVAL_LONG(&_3, size);
	ZVAL_LONG(&_4, flags);
	ZVAL_LONG(&_5, ppData);
	RETURN_LONG(phpvk_vk10_vkmapmemory(&_0, &_1, &_2, &_3, &_4, &_5));
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkUnmapMemory)
{
	zval *device_param = NULL, *memory_param = NULL, _0, _1;
	zend_long device, memory;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(memory)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &device_param, &memory_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, memory);
	phpvk_vk10_vkunmapmemory(&_0, &_1);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkFlushMappedMemoryRanges)
{
	zval *device_param = NULL, *memoryRangeCount_param = NULL, *pMemoryRanges_param = NULL, _0, _1, _2;
	zend_long device, memoryRangeCount, pMemoryRanges;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(memoryRangeCount)
		Z_PARAM_LONG(pMemoryRanges)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &device_param, &memoryRangeCount_param, &pMemoryRanges_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, memoryRangeCount);
	ZVAL_LONG(&_2, pMemoryRanges);
	RETURN_LONG(phpvk_vk10_vkflushmappedmemoryranges(&_0, &_1, &_2));
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkInvalidateMappedMemoryRanges)
{
	zval *device_param = NULL, *memoryRangeCount_param = NULL, *pMemoryRanges_param = NULL, _0, _1, _2;
	zend_long device, memoryRangeCount, pMemoryRanges;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(memoryRangeCount)
		Z_PARAM_LONG(pMemoryRanges)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &device_param, &memoryRangeCount_param, &pMemoryRanges_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, memoryRangeCount);
	ZVAL_LONG(&_2, pMemoryRanges);
	RETURN_LONG(phpvk_vk10_vkinvalidatemappedmemoryranges(&_0, &_1, &_2));
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkGetDeviceMemoryCommitment)
{
	zval *device_param = NULL, *memory_param = NULL, *pCommittedMemoryInBytes_param = NULL, _0, _1, _2;
	zend_long device, memory, pCommittedMemoryInBytes;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(memory)
		Z_PARAM_LONG(pCommittedMemoryInBytes)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &device_param, &memory_param, &pCommittedMemoryInBytes_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, memory);
	ZVAL_LONG(&_2, pCommittedMemoryInBytes);
	phpvk_vk10_vkgetdevicememorycommitment(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkBindBufferMemory)
{
	zval *device_param = NULL, *buffer_param = NULL, *memory_param = NULL, *memoryOffset_param = NULL, _0, _1, _2, _3;
	zend_long device, buffer, memory, memoryOffset;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(buffer)
		Z_PARAM_LONG(memory)
		Z_PARAM_LONG(memoryOffset)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &device_param, &buffer_param, &memory_param, &memoryOffset_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, buffer);
	ZVAL_LONG(&_2, memory);
	ZVAL_LONG(&_3, memoryOffset);
	RETURN_LONG(phpvk_vk10_vkbindbuffermemory(&_0, &_1, &_2, &_3));
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkBindImageMemory)
{
	zval *device_param = NULL, *image_param = NULL, *memory_param = NULL, *memoryOffset_param = NULL, _0, _1, _2, _3;
	zend_long device, image, memory, memoryOffset;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(image)
		Z_PARAM_LONG(memory)
		Z_PARAM_LONG(memoryOffset)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &device_param, &image_param, &memory_param, &memoryOffset_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, image);
	ZVAL_LONG(&_2, memory);
	ZVAL_LONG(&_3, memoryOffset);
	RETURN_LONG(phpvk_vk10_vkbindimagememory(&_0, &_1, &_2, &_3));
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkGetBufferMemoryRequirements)
{
	zval *device_param = NULL, *buffer_param = NULL, *pMemoryRequirements_param = NULL, _0, _1, _2;
	zend_long device, buffer, pMemoryRequirements;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(buffer)
		Z_PARAM_LONG(pMemoryRequirements)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &device_param, &buffer_param, &pMemoryRequirements_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, buffer);
	ZVAL_LONG(&_2, pMemoryRequirements);
	phpvk_vk10_vkgetbuffermemoryrequirements(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkGetImageMemoryRequirements)
{
	zval *device_param = NULL, *image_param = NULL, *pMemoryRequirements_param = NULL, _0, _1, _2;
	zend_long device, image, pMemoryRequirements;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(image)
		Z_PARAM_LONG(pMemoryRequirements)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &device_param, &image_param, &pMemoryRequirements_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, image);
	ZVAL_LONG(&_2, pMemoryRequirements);
	phpvk_vk10_vkgetimagememoryrequirements(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkGetImageSparseMemoryRequirements)
{
	zval *device_param = NULL, *image_param = NULL, *pSparseMemoryRequirementCount_param = NULL, *pSparseMemoryRequirements_param = NULL, _0, _1, _2, _3;
	zend_long device, image, pSparseMemoryRequirementCount, pSparseMemoryRequirements;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(image)
		Z_PARAM_LONG(pSparseMemoryRequirementCount)
		Z_PARAM_LONG(pSparseMemoryRequirements)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &device_param, &image_param, &pSparseMemoryRequirementCount_param, &pSparseMemoryRequirements_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, image);
	ZVAL_LONG(&_2, pSparseMemoryRequirementCount);
	ZVAL_LONG(&_3, pSparseMemoryRequirements);
	phpvk_vk10_vkgetimagesparsememoryrequirements(&_0, &_1, &_2, &_3);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkGetPhysicalDeviceSparseImageFormatProperties)
{
	zval *physicalDevice_param = NULL, *format_param = NULL, *type_param = NULL, *samples_param = NULL, *usage_param = NULL, *tiling_param = NULL, *pPropertyCount_param = NULL, *pProperties_param = NULL, _0, _1, _2, _3, _4, _5, _6, _7;
	zend_long physicalDevice, format, type, samples, usage, tiling, pPropertyCount, pProperties;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZEND_PARSE_PARAMETERS_START(8, 8)
		Z_PARAM_LONG(physicalDevice)
		Z_PARAM_LONG(format)
		Z_PARAM_LONG(type)
		Z_PARAM_LONG(samples)
		Z_PARAM_LONG(usage)
		Z_PARAM_LONG(tiling)
		Z_PARAM_LONG(pPropertyCount)
		Z_PARAM_LONG(pProperties)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(8, 0, &physicalDevice_param, &format_param, &type_param, &samples_param, &usage_param, &tiling_param, &pPropertyCount_param, &pProperties_param);
	ZVAL_LONG(&_0, physicalDevice);
	ZVAL_LONG(&_1, format);
	ZVAL_LONG(&_2, type);
	ZVAL_LONG(&_3, samples);
	ZVAL_LONG(&_4, usage);
	ZVAL_LONG(&_5, tiling);
	ZVAL_LONG(&_6, pPropertyCount);
	ZVAL_LONG(&_7, pProperties);
	phpvk_vk10_vkgetphysicaldevicesparseimageformatproperties(&_0, &_1, &_2, &_3, &_4, &_5, &_6, &_7);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkQueueBindSparse)
{
	zval *queue_param = NULL, *bindInfoCount_param = NULL, *pBindInfo_param = NULL, *fence_param = NULL, _0, _1, _2, _3;
	zend_long queue, bindInfoCount, pBindInfo, fence;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(queue)
		Z_PARAM_LONG(bindInfoCount)
		Z_PARAM_LONG(pBindInfo)
		Z_PARAM_LONG(fence)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &queue_param, &bindInfoCount_param, &pBindInfo_param, &fence_param);
	ZVAL_LONG(&_0, queue);
	ZVAL_LONG(&_1, bindInfoCount);
	ZVAL_LONG(&_2, pBindInfo);
	ZVAL_LONG(&_3, fence);
	RETURN_LONG(phpvk_vk10_vkqueuebindsparse(&_0, &_1, &_2, &_3));
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCreateFence)
{
	zval *device_param = NULL, *pCreateInfo_param = NULL, *pAllocator_param = NULL, *pFence_param = NULL, _0, _1, _2, _3;
	zend_long device, pCreateInfo, pAllocator, pFence;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(pCreateInfo)
		Z_PARAM_LONG(pAllocator)
		Z_PARAM_LONG(pFence)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &device_param, &pCreateInfo_param, &pAllocator_param, &pFence_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, pCreateInfo);
	ZVAL_LONG(&_2, pAllocator);
	ZVAL_LONG(&_3, pFence);
	RETURN_LONG(phpvk_vk10_vkcreatefence(&_0, &_1, &_2, &_3));
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkDestroyFence)
{
	zval *device_param = NULL, *fence_param = NULL, *pAllocator_param = NULL, _0, _1, _2;
	zend_long device, fence, pAllocator;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(fence)
		Z_PARAM_LONG(pAllocator)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &device_param, &fence_param, &pAllocator_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, fence);
	ZVAL_LONG(&_2, pAllocator);
	phpvk_vk10_vkdestroyfence(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkResetFences)
{
	zval *device_param = NULL, *fenceCount_param = NULL, *pFences_param = NULL, _0, _1, _2;
	zend_long device, fenceCount, pFences;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(fenceCount)
		Z_PARAM_LONG(pFences)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &device_param, &fenceCount_param, &pFences_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, fenceCount);
	ZVAL_LONG(&_2, pFences);
	RETURN_LONG(phpvk_vk10_vkresetfences(&_0, &_1, &_2));
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkGetFenceStatus)
{
	zval *device_param = NULL, *fence_param = NULL, _0, _1;
	zend_long device, fence;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(fence)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &device_param, &fence_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, fence);
	RETURN_LONG(phpvk_vk10_vkgetfencestatus(&_0, &_1));
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkWaitForFences)
{
	zend_bool waitAll;
	zval *device_param = NULL, *fenceCount_param = NULL, *pFences_param = NULL, *waitAll_param = NULL, *timeout_param = NULL, _0, _1, _2, _3, _4;
	zend_long device, fenceCount, pFences, timeout;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(fenceCount)
		Z_PARAM_LONG(pFences)
		Z_PARAM_BOOL(waitAll)
		Z_PARAM_LONG(timeout)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &device_param, &fenceCount_param, &pFences_param, &waitAll_param, &timeout_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, fenceCount);
	ZVAL_LONG(&_2, pFences);
	ZVAL_BOOL(&_3, (waitAll ? 1 : 0));
	ZVAL_LONG(&_4, timeout);
	RETURN_LONG(phpvk_vk10_vkwaitforfences(&_0, &_1, &_2, &_3, &_4));
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCreateSemaphore)
{
	zval *device_param = NULL, *pCreateInfo_param = NULL, *pAllocator_param = NULL, *pSemaphore_param = NULL, _0, _1, _2, _3;
	zend_long device, pCreateInfo, pAllocator, pSemaphore;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(pCreateInfo)
		Z_PARAM_LONG(pAllocator)
		Z_PARAM_LONG(pSemaphore)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &device_param, &pCreateInfo_param, &pAllocator_param, &pSemaphore_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, pCreateInfo);
	ZVAL_LONG(&_2, pAllocator);
	ZVAL_LONG(&_3, pSemaphore);
	RETURN_LONG(phpvk_vk10_vkcreatesemaphore(&_0, &_1, &_2, &_3));
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkDestroySemaphore)
{
	zval *device_param = NULL, *semaphore_param = NULL, *pAllocator_param = NULL, _0, _1, _2;
	zend_long device, semaphore, pAllocator;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(semaphore)
		Z_PARAM_LONG(pAllocator)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &device_param, &semaphore_param, &pAllocator_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, semaphore);
	ZVAL_LONG(&_2, pAllocator);
	phpvk_vk10_vkdestroysemaphore(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCreateQueryPool)
{
	zval *device_param = NULL, *pCreateInfo_param = NULL, *pAllocator_param = NULL, *pQueryPool_param = NULL, _0, _1, _2, _3;
	zend_long device, pCreateInfo, pAllocator, pQueryPool;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(pCreateInfo)
		Z_PARAM_LONG(pAllocator)
		Z_PARAM_LONG(pQueryPool)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &device_param, &pCreateInfo_param, &pAllocator_param, &pQueryPool_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, pCreateInfo);
	ZVAL_LONG(&_2, pAllocator);
	ZVAL_LONG(&_3, pQueryPool);
	RETURN_LONG(phpvk_vk10_vkcreatequerypool(&_0, &_1, &_2, &_3));
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkDestroyQueryPool)
{
	zval *device_param = NULL, *queryPool_param = NULL, *pAllocator_param = NULL, _0, _1, _2;
	zend_long device, queryPool, pAllocator;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(queryPool)
		Z_PARAM_LONG(pAllocator)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &device_param, &queryPool_param, &pAllocator_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, queryPool);
	ZVAL_LONG(&_2, pAllocator);
	phpvk_vk10_vkdestroyquerypool(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkGetQueryPoolResults)
{
	zval *device_param = NULL, *queryPool_param = NULL, *firstQuery_param = NULL, *queryCount_param = NULL, *dataSize_param = NULL, *pData_param = NULL, *stride_param = NULL, *flags_param = NULL, _0, _1, _2, _3, _4, _5, _6, _7;
	zend_long device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZEND_PARSE_PARAMETERS_START(8, 8)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(queryPool)
		Z_PARAM_LONG(firstQuery)
		Z_PARAM_LONG(queryCount)
		Z_PARAM_LONG(dataSize)
		Z_PARAM_LONG(pData)
		Z_PARAM_LONG(stride)
		Z_PARAM_LONG(flags)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(8, 0, &device_param, &queryPool_param, &firstQuery_param, &queryCount_param, &dataSize_param, &pData_param, &stride_param, &flags_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, queryPool);
	ZVAL_LONG(&_2, firstQuery);
	ZVAL_LONG(&_3, queryCount);
	ZVAL_LONG(&_4, dataSize);
	ZVAL_LONG(&_5, pData);
	ZVAL_LONG(&_6, stride);
	ZVAL_LONG(&_7, flags);
	RETURN_LONG(phpvk_vk10_vkgetquerypoolresults(&_0, &_1, &_2, &_3, &_4, &_5, &_6, &_7));
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCreateBuffer)
{
	zval *device_param = NULL, *pCreateInfo_param = NULL, *pAllocator_param = NULL, *pBuffer_param = NULL, _0, _1, _2, _3;
	zend_long device, pCreateInfo, pAllocator, pBuffer;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(pCreateInfo)
		Z_PARAM_LONG(pAllocator)
		Z_PARAM_LONG(pBuffer)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &device_param, &pCreateInfo_param, &pAllocator_param, &pBuffer_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, pCreateInfo);
	ZVAL_LONG(&_2, pAllocator);
	ZVAL_LONG(&_3, pBuffer);
	RETURN_LONG(phpvk_vk10_vkcreatebuffer(&_0, &_1, &_2, &_3));
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkDestroyBuffer)
{
	zval *device_param = NULL, *buffer_param = NULL, *pAllocator_param = NULL, _0, _1, _2;
	zend_long device, buffer, pAllocator;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(buffer)
		Z_PARAM_LONG(pAllocator)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &device_param, &buffer_param, &pAllocator_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, buffer);
	ZVAL_LONG(&_2, pAllocator);
	phpvk_vk10_vkdestroybuffer(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCreateImage)
{
	zval *device_param = NULL, *pCreateInfo_param = NULL, *pAllocator_param = NULL, *pImage_param = NULL, _0, _1, _2, _3;
	zend_long device, pCreateInfo, pAllocator, pImage;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(pCreateInfo)
		Z_PARAM_LONG(pAllocator)
		Z_PARAM_LONG(pImage)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &device_param, &pCreateInfo_param, &pAllocator_param, &pImage_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, pCreateInfo);
	ZVAL_LONG(&_2, pAllocator);
	ZVAL_LONG(&_3, pImage);
	RETURN_LONG(phpvk_vk10_vkcreateimage(&_0, &_1, &_2, &_3));
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkDestroyImage)
{
	zval *device_param = NULL, *image_param = NULL, *pAllocator_param = NULL, _0, _1, _2;
	zend_long device, image, pAllocator;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(image)
		Z_PARAM_LONG(pAllocator)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &device_param, &image_param, &pAllocator_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, image);
	ZVAL_LONG(&_2, pAllocator);
	phpvk_vk10_vkdestroyimage(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkGetImageSubresourceLayout)
{
	zval *device_param = NULL, *image_param = NULL, *pSubresource_param = NULL, *pLayout_param = NULL, _0, _1, _2, _3;
	zend_long device, image, pSubresource, pLayout;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(image)
		Z_PARAM_LONG(pSubresource)
		Z_PARAM_LONG(pLayout)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &device_param, &image_param, &pSubresource_param, &pLayout_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, image);
	ZVAL_LONG(&_2, pSubresource);
	ZVAL_LONG(&_3, pLayout);
	phpvk_vk10_vkgetimagesubresourcelayout(&_0, &_1, &_2, &_3);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCreateImageView)
{
	zval *device_param = NULL, *pCreateInfo_param = NULL, *pAllocator_param = NULL, *pView_param = NULL, _0, _1, _2, _3;
	zend_long device, pCreateInfo, pAllocator, pView;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(pCreateInfo)
		Z_PARAM_LONG(pAllocator)
		Z_PARAM_LONG(pView)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &device_param, &pCreateInfo_param, &pAllocator_param, &pView_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, pCreateInfo);
	ZVAL_LONG(&_2, pAllocator);
	ZVAL_LONG(&_3, pView);
	RETURN_LONG(phpvk_vk10_vkcreateimageview(&_0, &_1, &_2, &_3));
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkDestroyImageView)
{
	zval *device_param = NULL, *imageView_param = NULL, *pAllocator_param = NULL, _0, _1, _2;
	zend_long device, imageView, pAllocator;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(imageView)
		Z_PARAM_LONG(pAllocator)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &device_param, &imageView_param, &pAllocator_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, imageView);
	ZVAL_LONG(&_2, pAllocator);
	phpvk_vk10_vkdestroyimageview(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCreateCommandPool)
{
	zval *device_param = NULL, *pCreateInfo_param = NULL, *pAllocator_param = NULL, *pCommandPool_param = NULL, _0, _1, _2, _3;
	zend_long device, pCreateInfo, pAllocator, pCommandPool;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(pCreateInfo)
		Z_PARAM_LONG(pAllocator)
		Z_PARAM_LONG(pCommandPool)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &device_param, &pCreateInfo_param, &pAllocator_param, &pCommandPool_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, pCreateInfo);
	ZVAL_LONG(&_2, pAllocator);
	ZVAL_LONG(&_3, pCommandPool);
	RETURN_LONG(phpvk_vk10_vkcreatecommandpool(&_0, &_1, &_2, &_3));
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkDestroyCommandPool)
{
	zval *device_param = NULL, *commandPool_param = NULL, *pAllocator_param = NULL, _0, _1, _2;
	zend_long device, commandPool, pAllocator;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(commandPool)
		Z_PARAM_LONG(pAllocator)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &device_param, &commandPool_param, &pAllocator_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, commandPool);
	ZVAL_LONG(&_2, pAllocator);
	phpvk_vk10_vkdestroycommandpool(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkResetCommandPool)
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
	RETURN_LONG(phpvk_vk10_vkresetcommandpool(&_0, &_1, &_2));
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkAllocateCommandBuffers)
{
	zval *device_param = NULL, *pAllocateInfo_param = NULL, *pCommandBuffers_param = NULL, _0, _1, _2;
	zend_long device, pAllocateInfo, pCommandBuffers;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(pAllocateInfo)
		Z_PARAM_LONG(pCommandBuffers)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &device_param, &pAllocateInfo_param, &pCommandBuffers_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, pAllocateInfo);
	ZVAL_LONG(&_2, pCommandBuffers);
	RETURN_LONG(phpvk_vk10_vkallocatecommandbuffers(&_0, &_1, &_2));
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkFreeCommandBuffers)
{
	zval *device_param = NULL, *commandPool_param = NULL, *commandBufferCount_param = NULL, *pCommandBuffers_param = NULL, _0, _1, _2, _3;
	zend_long device, commandPool, commandBufferCount, pCommandBuffers;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(commandPool)
		Z_PARAM_LONG(commandBufferCount)
		Z_PARAM_LONG(pCommandBuffers)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &device_param, &commandPool_param, &commandBufferCount_param, &pCommandBuffers_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, commandPool);
	ZVAL_LONG(&_2, commandBufferCount);
	ZVAL_LONG(&_3, pCommandBuffers);
	phpvk_vk10_vkfreecommandbuffers(&_0, &_1, &_2, &_3);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkBeginCommandBuffer)
{
	zval *commandBuffer_param = NULL, *pBeginInfo_param = NULL, _0, _1;
	zend_long commandBuffer, pBeginInfo;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(pBeginInfo)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &commandBuffer_param, &pBeginInfo_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, pBeginInfo);
	RETURN_LONG(phpvk_vk10_vkbegincommandbuffer(&_0, &_1));
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkEndCommandBuffer)
{
	zval *commandBuffer_param = NULL, _0;
	zend_long commandBuffer;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(commandBuffer)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &commandBuffer_param);
	ZVAL_LONG(&_0, commandBuffer);
	RETURN_LONG(phpvk_vk10_vkendcommandbuffer(&_0));
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkResetCommandBuffer)
{
	zval *commandBuffer_param = NULL, *flags_param = NULL, _0, _1;
	zend_long commandBuffer, flags;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(flags)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &commandBuffer_param, &flags_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, flags);
	RETURN_LONG(phpvk_vk10_vkresetcommandbuffer(&_0, &_1));
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdCopyBuffer)
{
	zval *commandBuffer_param = NULL, *srcBuffer_param = NULL, *dstBuffer_param = NULL, *regionCount_param = NULL, *pRegions_param = NULL, _0, _1, _2, _3, _4;
	zend_long commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(srcBuffer)
		Z_PARAM_LONG(dstBuffer)
		Z_PARAM_LONG(regionCount)
		Z_PARAM_LONG(pRegions)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &commandBuffer_param, &srcBuffer_param, &dstBuffer_param, &regionCount_param, &pRegions_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, srcBuffer);
	ZVAL_LONG(&_2, dstBuffer);
	ZVAL_LONG(&_3, regionCount);
	ZVAL_LONG(&_4, pRegions);
	phpvk_vk10_vkcmdcopybuffer(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdCopyImage)
{
	zval *commandBuffer_param = NULL, *srcImage_param = NULL, *srcImageLayout_param = NULL, *dstImage_param = NULL, *dstImageLayout_param = NULL, *regionCount_param = NULL, *pRegions_param = NULL, _0, _1, _2, _3, _4, _5, _6;
	zend_long commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZEND_PARSE_PARAMETERS_START(7, 7)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(srcImage)
		Z_PARAM_LONG(srcImageLayout)
		Z_PARAM_LONG(dstImage)
		Z_PARAM_LONG(dstImageLayout)
		Z_PARAM_LONG(regionCount)
		Z_PARAM_LONG(pRegions)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(7, 0, &commandBuffer_param, &srcImage_param, &srcImageLayout_param, &dstImage_param, &dstImageLayout_param, &regionCount_param, &pRegions_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, srcImage);
	ZVAL_LONG(&_2, srcImageLayout);
	ZVAL_LONG(&_3, dstImage);
	ZVAL_LONG(&_4, dstImageLayout);
	ZVAL_LONG(&_5, regionCount);
	ZVAL_LONG(&_6, pRegions);
	phpvk_vk10_vkcmdcopyimage(&_0, &_1, &_2, &_3, &_4, &_5, &_6);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdCopyBufferToImage)
{
	zval *commandBuffer_param = NULL, *srcBuffer_param = NULL, *dstImage_param = NULL, *dstImageLayout_param = NULL, *regionCount_param = NULL, *pRegions_param = NULL, _0, _1, _2, _3, _4, _5;
	zend_long commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(srcBuffer)
		Z_PARAM_LONG(dstImage)
		Z_PARAM_LONG(dstImageLayout)
		Z_PARAM_LONG(regionCount)
		Z_PARAM_LONG(pRegions)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(6, 0, &commandBuffer_param, &srcBuffer_param, &dstImage_param, &dstImageLayout_param, &regionCount_param, &pRegions_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, srcBuffer);
	ZVAL_LONG(&_2, dstImage);
	ZVAL_LONG(&_3, dstImageLayout);
	ZVAL_LONG(&_4, regionCount);
	ZVAL_LONG(&_5, pRegions);
	phpvk_vk10_vkcmdcopybuffertoimage(&_0, &_1, &_2, &_3, &_4, &_5);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdCopyImageToBuffer)
{
	zval *commandBuffer_param = NULL, *srcImage_param = NULL, *srcImageLayout_param = NULL, *dstBuffer_param = NULL, *regionCount_param = NULL, *pRegions_param = NULL, _0, _1, _2, _3, _4, _5;
	zend_long commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(srcImage)
		Z_PARAM_LONG(srcImageLayout)
		Z_PARAM_LONG(dstBuffer)
		Z_PARAM_LONG(regionCount)
		Z_PARAM_LONG(pRegions)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(6, 0, &commandBuffer_param, &srcImage_param, &srcImageLayout_param, &dstBuffer_param, &regionCount_param, &pRegions_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, srcImage);
	ZVAL_LONG(&_2, srcImageLayout);
	ZVAL_LONG(&_3, dstBuffer);
	ZVAL_LONG(&_4, regionCount);
	ZVAL_LONG(&_5, pRegions);
	phpvk_vk10_vkcmdcopyimagetobuffer(&_0, &_1, &_2, &_3, &_4, &_5);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdUpdateBuffer)
{
	zval *commandBuffer_param = NULL, *dstBuffer_param = NULL, *dstOffset_param = NULL, *dataSize_param = NULL, *pData_param = NULL, _0, _1, _2, _3, _4;
	zend_long commandBuffer, dstBuffer, dstOffset, dataSize, pData;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(dstBuffer)
		Z_PARAM_LONG(dstOffset)
		Z_PARAM_LONG(dataSize)
		Z_PARAM_LONG(pData)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &commandBuffer_param, &dstBuffer_param, &dstOffset_param, &dataSize_param, &pData_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, dstBuffer);
	ZVAL_LONG(&_2, dstOffset);
	ZVAL_LONG(&_3, dataSize);
	ZVAL_LONG(&_4, pData);
	phpvk_vk10_vkcmdupdatebuffer(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdFillBuffer)
{
	zval *commandBuffer_param = NULL, *dstBuffer_param = NULL, *dstOffset_param = NULL, *size_param = NULL, *data_param = NULL, _0, _1, _2, _3, _4;
	zend_long commandBuffer, dstBuffer, dstOffset, size, data;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(dstBuffer)
		Z_PARAM_LONG(dstOffset)
		Z_PARAM_LONG(size)
		Z_PARAM_LONG(data)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &commandBuffer_param, &dstBuffer_param, &dstOffset_param, &size_param, &data_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, dstBuffer);
	ZVAL_LONG(&_2, dstOffset);
	ZVAL_LONG(&_3, size);
	ZVAL_LONG(&_4, data);
	phpvk_vk10_vkcmdfillbuffer(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdPipelineBarrier)
{
	zval *commandBuffer_param = NULL, *srcStageMask_param = NULL, *dstStageMask_param = NULL, *dependencyFlags_param = NULL, *memoryBarrierCount_param = NULL, *pMemoryBarriers_param = NULL, *bufferMemoryBarrierCount_param = NULL, *pBufferMemoryBarriers_param = NULL, *imageMemoryBarrierCount_param = NULL, *pImageMemoryBarriers_param = NULL, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9;
	zend_long commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZEND_PARSE_PARAMETERS_START(10, 10)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(srcStageMask)
		Z_PARAM_LONG(dstStageMask)
		Z_PARAM_LONG(dependencyFlags)
		Z_PARAM_LONG(memoryBarrierCount)
		Z_PARAM_LONG(pMemoryBarriers)
		Z_PARAM_LONG(bufferMemoryBarrierCount)
		Z_PARAM_LONG(pBufferMemoryBarriers)
		Z_PARAM_LONG(imageMemoryBarrierCount)
		Z_PARAM_LONG(pImageMemoryBarriers)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(10, 0, &commandBuffer_param, &srcStageMask_param, &dstStageMask_param, &dependencyFlags_param, &memoryBarrierCount_param, &pMemoryBarriers_param, &bufferMemoryBarrierCount_param, &pBufferMemoryBarriers_param, &imageMemoryBarrierCount_param, &pImageMemoryBarriers_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, srcStageMask);
	ZVAL_LONG(&_2, dstStageMask);
	ZVAL_LONG(&_3, dependencyFlags);
	ZVAL_LONG(&_4, memoryBarrierCount);
	ZVAL_LONG(&_5, pMemoryBarriers);
	ZVAL_LONG(&_6, bufferMemoryBarrierCount);
	ZVAL_LONG(&_7, pBufferMemoryBarriers);
	ZVAL_LONG(&_8, imageMemoryBarrierCount);
	ZVAL_LONG(&_9, pImageMemoryBarriers);
	phpvk_vk10_vkcmdpipelinebarrier(&_0, &_1, &_2, &_3, &_4, &_5, &_6, &_7, &_8, &_9);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdBeginQuery)
{
	zval *commandBuffer_param = NULL, *queryPool_param = NULL, *query_param = NULL, *flags_param = NULL, _0, _1, _2, _3;
	zend_long commandBuffer, queryPool, query, flags;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(queryPool)
		Z_PARAM_LONG(query)
		Z_PARAM_LONG(flags)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &commandBuffer_param, &queryPool_param, &query_param, &flags_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, queryPool);
	ZVAL_LONG(&_2, query);
	ZVAL_LONG(&_3, flags);
	phpvk_vk10_vkcmdbeginquery(&_0, &_1, &_2, &_3);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdEndQuery)
{
	zval *commandBuffer_param = NULL, *queryPool_param = NULL, *query_param = NULL, _0, _1, _2;
	zend_long commandBuffer, queryPool, query;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(queryPool)
		Z_PARAM_LONG(query)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &commandBuffer_param, &queryPool_param, &query_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, queryPool);
	ZVAL_LONG(&_2, query);
	phpvk_vk10_vkcmdendquery(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdResetQueryPool)
{
	zval *commandBuffer_param = NULL, *queryPool_param = NULL, *firstQuery_param = NULL, *queryCount_param = NULL, _0, _1, _2, _3;
	zend_long commandBuffer, queryPool, firstQuery, queryCount;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(queryPool)
		Z_PARAM_LONG(firstQuery)
		Z_PARAM_LONG(queryCount)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &commandBuffer_param, &queryPool_param, &firstQuery_param, &queryCount_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, queryPool);
	ZVAL_LONG(&_2, firstQuery);
	ZVAL_LONG(&_3, queryCount);
	phpvk_vk10_vkcmdresetquerypool(&_0, &_1, &_2, &_3);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdWriteTimestamp)
{
	zval *commandBuffer_param = NULL, *pipelineStage_param = NULL, *queryPool_param = NULL, *query_param = NULL, _0, _1, _2, _3;
	zend_long commandBuffer, pipelineStage, queryPool, query;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(pipelineStage)
		Z_PARAM_LONG(queryPool)
		Z_PARAM_LONG(query)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &commandBuffer_param, &pipelineStage_param, &queryPool_param, &query_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, pipelineStage);
	ZVAL_LONG(&_2, queryPool);
	ZVAL_LONG(&_3, query);
	phpvk_vk10_vkcmdwritetimestamp(&_0, &_1, &_2, &_3);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdCopyQueryPoolResults)
{
	zval *commandBuffer_param = NULL, *queryPool_param = NULL, *firstQuery_param = NULL, *queryCount_param = NULL, *dstBuffer_param = NULL, *dstOffset_param = NULL, *stride_param = NULL, *flags_param = NULL, _0, _1, _2, _3, _4, _5, _6, _7;
	zend_long commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZEND_PARSE_PARAMETERS_START(8, 8)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(queryPool)
		Z_PARAM_LONG(firstQuery)
		Z_PARAM_LONG(queryCount)
		Z_PARAM_LONG(dstBuffer)
		Z_PARAM_LONG(dstOffset)
		Z_PARAM_LONG(stride)
		Z_PARAM_LONG(flags)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(8, 0, &commandBuffer_param, &queryPool_param, &firstQuery_param, &queryCount_param, &dstBuffer_param, &dstOffset_param, &stride_param, &flags_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, queryPool);
	ZVAL_LONG(&_2, firstQuery);
	ZVAL_LONG(&_3, queryCount);
	ZVAL_LONG(&_4, dstBuffer);
	ZVAL_LONG(&_5, dstOffset);
	ZVAL_LONG(&_6, stride);
	ZVAL_LONG(&_7, flags);
	phpvk_vk10_vkcmdcopyquerypoolresults(&_0, &_1, &_2, &_3, &_4, &_5, &_6, &_7);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdExecuteCommands)
{
	zval *commandBuffer_param = NULL, *commandBufferCount_param = NULL, *pCommandBuffers_param = NULL, _0, _1, _2;
	zend_long commandBuffer, commandBufferCount, pCommandBuffers;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(commandBufferCount)
		Z_PARAM_LONG(pCommandBuffers)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &commandBuffer_param, &commandBufferCount_param, &pCommandBuffers_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, commandBufferCount);
	ZVAL_LONG(&_2, pCommandBuffers);
	phpvk_vk10_vkcmdexecutecommands(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCreateEvent)
{
	zval *device_param = NULL, *pCreateInfo_param = NULL, *pAllocator_param = NULL, *pEvent_param = NULL, _0, _1, _2, _3;
	zend_long device, pCreateInfo, pAllocator, pEvent;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(pCreateInfo)
		Z_PARAM_LONG(pAllocator)
		Z_PARAM_LONG(pEvent)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &device_param, &pCreateInfo_param, &pAllocator_param, &pEvent_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, pCreateInfo);
	ZVAL_LONG(&_2, pAllocator);
	ZVAL_LONG(&_3, pEvent);
	RETURN_LONG(phpvk_vk10_vkcreateevent(&_0, &_1, &_2, &_3));
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkDestroyEvent)
{
	zval *device_param = NULL, *event_param = NULL, *pAllocator_param = NULL, _0, _1, _2;
	zend_long device, event, pAllocator;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(event)
		Z_PARAM_LONG(pAllocator)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &device_param, &event_param, &pAllocator_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, event);
	ZVAL_LONG(&_2, pAllocator);
	phpvk_vk10_vkdestroyevent(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkGetEventStatus)
{
	zval *device_param = NULL, *event_param = NULL, _0, _1;
	zend_long device, event;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(event)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &device_param, &event_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, event);
	RETURN_LONG(phpvk_vk10_vkgeteventstatus(&_0, &_1));
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkSetEvent)
{
	zval *device_param = NULL, *event_param = NULL, _0, _1;
	zend_long device, event;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(event)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &device_param, &event_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, event);
	RETURN_LONG(phpvk_vk10_vksetevent(&_0, &_1));
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkResetEvent)
{
	zval *device_param = NULL, *event_param = NULL, _0, _1;
	zend_long device, event;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(event)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &device_param, &event_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, event);
	RETURN_LONG(phpvk_vk10_vkresetevent(&_0, &_1));
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCreateBufferView)
{
	zval *device_param = NULL, *pCreateInfo_param = NULL, *pAllocator_param = NULL, *pView_param = NULL, _0, _1, _2, _3;
	zend_long device, pCreateInfo, pAllocator, pView;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(pCreateInfo)
		Z_PARAM_LONG(pAllocator)
		Z_PARAM_LONG(pView)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &device_param, &pCreateInfo_param, &pAllocator_param, &pView_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, pCreateInfo);
	ZVAL_LONG(&_2, pAllocator);
	ZVAL_LONG(&_3, pView);
	RETURN_LONG(phpvk_vk10_vkcreatebufferview(&_0, &_1, &_2, &_3));
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkDestroyBufferView)
{
	zval *device_param = NULL, *bufferView_param = NULL, *pAllocator_param = NULL, _0, _1, _2;
	zend_long device, bufferView, pAllocator;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(bufferView)
		Z_PARAM_LONG(pAllocator)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &device_param, &bufferView_param, &pAllocator_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, bufferView);
	ZVAL_LONG(&_2, pAllocator);
	phpvk_vk10_vkdestroybufferview(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCreateShaderModule)
{
	zval *device_param = NULL, *pCreateInfo_param = NULL, *pAllocator_param = NULL, *pShaderModule_param = NULL, _0, _1, _2, _3;
	zend_long device, pCreateInfo, pAllocator, pShaderModule;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(pCreateInfo)
		Z_PARAM_LONG(pAllocator)
		Z_PARAM_LONG(pShaderModule)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &device_param, &pCreateInfo_param, &pAllocator_param, &pShaderModule_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, pCreateInfo);
	ZVAL_LONG(&_2, pAllocator);
	ZVAL_LONG(&_3, pShaderModule);
	RETURN_LONG(phpvk_vk10_vkcreateshadermodule(&_0, &_1, &_2, &_3));
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkDestroyShaderModule)
{
	zval *device_param = NULL, *shaderModule_param = NULL, *pAllocator_param = NULL, _0, _1, _2;
	zend_long device, shaderModule, pAllocator;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(shaderModule)
		Z_PARAM_LONG(pAllocator)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &device_param, &shaderModule_param, &pAllocator_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, shaderModule);
	ZVAL_LONG(&_2, pAllocator);
	phpvk_vk10_vkdestroyshadermodule(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCreatePipelineCache)
{
	zval *device_param = NULL, *pCreateInfo_param = NULL, *pAllocator_param = NULL, *pPipelineCache_param = NULL, _0, _1, _2, _3;
	zend_long device, pCreateInfo, pAllocator, pPipelineCache;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(pCreateInfo)
		Z_PARAM_LONG(pAllocator)
		Z_PARAM_LONG(pPipelineCache)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &device_param, &pCreateInfo_param, &pAllocator_param, &pPipelineCache_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, pCreateInfo);
	ZVAL_LONG(&_2, pAllocator);
	ZVAL_LONG(&_3, pPipelineCache);
	RETURN_LONG(phpvk_vk10_vkcreatepipelinecache(&_0, &_1, &_2, &_3));
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkDestroyPipelineCache)
{
	zval *device_param = NULL, *pipelineCache_param = NULL, *pAllocator_param = NULL, _0, _1, _2;
	zend_long device, pipelineCache, pAllocator;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(pipelineCache)
		Z_PARAM_LONG(pAllocator)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &device_param, &pipelineCache_param, &pAllocator_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, pipelineCache);
	ZVAL_LONG(&_2, pAllocator);
	phpvk_vk10_vkdestroypipelinecache(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkGetPipelineCacheData)
{
	zval *device_param = NULL, *pipelineCache_param = NULL, *pDataSize_param = NULL, *pData_param = NULL, _0, _1, _2, _3;
	zend_long device, pipelineCache, pDataSize, pData;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(pipelineCache)
		Z_PARAM_LONG(pDataSize)
		Z_PARAM_LONG(pData)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &device_param, &pipelineCache_param, &pDataSize_param, &pData_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, pipelineCache);
	ZVAL_LONG(&_2, pDataSize);
	ZVAL_LONG(&_3, pData);
	RETURN_LONG(phpvk_vk10_vkgetpipelinecachedata(&_0, &_1, &_2, &_3));
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkMergePipelineCaches)
{
	zval *device_param = NULL, *dstCache_param = NULL, *srcCacheCount_param = NULL, *pSrcCaches_param = NULL, _0, _1, _2, _3;
	zend_long device, dstCache, srcCacheCount, pSrcCaches;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(dstCache)
		Z_PARAM_LONG(srcCacheCount)
		Z_PARAM_LONG(pSrcCaches)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &device_param, &dstCache_param, &srcCacheCount_param, &pSrcCaches_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, dstCache);
	ZVAL_LONG(&_2, srcCacheCount);
	ZVAL_LONG(&_3, pSrcCaches);
	RETURN_LONG(phpvk_vk10_vkmergepipelinecaches(&_0, &_1, &_2, &_3));
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCreateComputePipelines)
{
	zval *device_param = NULL, *pipelineCache_param = NULL, *createInfoCount_param = NULL, *pCreateInfos_param = NULL, *pAllocator_param = NULL, *pPipelines_param = NULL, _0, _1, _2, _3, _4, _5;
	zend_long device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(pipelineCache)
		Z_PARAM_LONG(createInfoCount)
		Z_PARAM_LONG(pCreateInfos)
		Z_PARAM_LONG(pAllocator)
		Z_PARAM_LONG(pPipelines)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(6, 0, &device_param, &pipelineCache_param, &createInfoCount_param, &pCreateInfos_param, &pAllocator_param, &pPipelines_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, pipelineCache);
	ZVAL_LONG(&_2, createInfoCount);
	ZVAL_LONG(&_3, pCreateInfos);
	ZVAL_LONG(&_4, pAllocator);
	ZVAL_LONG(&_5, pPipelines);
	RETURN_LONG(phpvk_vk10_vkcreatecomputepipelines(&_0, &_1, &_2, &_3, &_4, &_5));
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkDestroyPipeline)
{
	zval *device_param = NULL, *pipeline_param = NULL, *pAllocator_param = NULL, _0, _1, _2;
	zend_long device, pipeline, pAllocator;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(pipeline)
		Z_PARAM_LONG(pAllocator)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &device_param, &pipeline_param, &pAllocator_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, pipeline);
	ZVAL_LONG(&_2, pAllocator);
	phpvk_vk10_vkdestroypipeline(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCreatePipelineLayout)
{
	zval *device_param = NULL, *pCreateInfo_param = NULL, *pAllocator_param = NULL, *pPipelineLayout_param = NULL, _0, _1, _2, _3;
	zend_long device, pCreateInfo, pAllocator, pPipelineLayout;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(pCreateInfo)
		Z_PARAM_LONG(pAllocator)
		Z_PARAM_LONG(pPipelineLayout)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &device_param, &pCreateInfo_param, &pAllocator_param, &pPipelineLayout_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, pCreateInfo);
	ZVAL_LONG(&_2, pAllocator);
	ZVAL_LONG(&_3, pPipelineLayout);
	RETURN_LONG(phpvk_vk10_vkcreatepipelinelayout(&_0, &_1, &_2, &_3));
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkDestroyPipelineLayout)
{
	zval *device_param = NULL, *pipelineLayout_param = NULL, *pAllocator_param = NULL, _0, _1, _2;
	zend_long device, pipelineLayout, pAllocator;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(pipelineLayout)
		Z_PARAM_LONG(pAllocator)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &device_param, &pipelineLayout_param, &pAllocator_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, pipelineLayout);
	ZVAL_LONG(&_2, pAllocator);
	phpvk_vk10_vkdestroypipelinelayout(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCreateSampler)
{
	zval *device_param = NULL, *pCreateInfo_param = NULL, *pAllocator_param = NULL, *pSampler_param = NULL, _0, _1, _2, _3;
	zend_long device, pCreateInfo, pAllocator, pSampler;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(pCreateInfo)
		Z_PARAM_LONG(pAllocator)
		Z_PARAM_LONG(pSampler)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &device_param, &pCreateInfo_param, &pAllocator_param, &pSampler_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, pCreateInfo);
	ZVAL_LONG(&_2, pAllocator);
	ZVAL_LONG(&_3, pSampler);
	RETURN_LONG(phpvk_vk10_vkcreatesampler(&_0, &_1, &_2, &_3));
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkDestroySampler)
{
	zval *device_param = NULL, *sampler_param = NULL, *pAllocator_param = NULL, _0, _1, _2;
	zend_long device, sampler, pAllocator;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(sampler)
		Z_PARAM_LONG(pAllocator)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &device_param, &sampler_param, &pAllocator_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, sampler);
	ZVAL_LONG(&_2, pAllocator);
	phpvk_vk10_vkdestroysampler(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCreateDescriptorSetLayout)
{
	zval *device_param = NULL, *pCreateInfo_param = NULL, *pAllocator_param = NULL, *pSetLayout_param = NULL, _0, _1, _2, _3;
	zend_long device, pCreateInfo, pAllocator, pSetLayout;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(pCreateInfo)
		Z_PARAM_LONG(pAllocator)
		Z_PARAM_LONG(pSetLayout)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &device_param, &pCreateInfo_param, &pAllocator_param, &pSetLayout_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, pCreateInfo);
	ZVAL_LONG(&_2, pAllocator);
	ZVAL_LONG(&_3, pSetLayout);
	RETURN_LONG(phpvk_vk10_vkcreatedescriptorsetlayout(&_0, &_1, &_2, &_3));
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkDestroyDescriptorSetLayout)
{
	zval *device_param = NULL, *descriptorSetLayout_param = NULL, *pAllocator_param = NULL, _0, _1, _2;
	zend_long device, descriptorSetLayout, pAllocator;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(descriptorSetLayout)
		Z_PARAM_LONG(pAllocator)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &device_param, &descriptorSetLayout_param, &pAllocator_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, descriptorSetLayout);
	ZVAL_LONG(&_2, pAllocator);
	phpvk_vk10_vkdestroydescriptorsetlayout(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCreateDescriptorPool)
{
	zval *device_param = NULL, *pCreateInfo_param = NULL, *pAllocator_param = NULL, *pDescriptorPool_param = NULL, _0, _1, _2, _3;
	zend_long device, pCreateInfo, pAllocator, pDescriptorPool;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(pCreateInfo)
		Z_PARAM_LONG(pAllocator)
		Z_PARAM_LONG(pDescriptorPool)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &device_param, &pCreateInfo_param, &pAllocator_param, &pDescriptorPool_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, pCreateInfo);
	ZVAL_LONG(&_2, pAllocator);
	ZVAL_LONG(&_3, pDescriptorPool);
	RETURN_LONG(phpvk_vk10_vkcreatedescriptorpool(&_0, &_1, &_2, &_3));
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkDestroyDescriptorPool)
{
	zval *device_param = NULL, *descriptorPool_param = NULL, *pAllocator_param = NULL, _0, _1, _2;
	zend_long device, descriptorPool, pAllocator;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(descriptorPool)
		Z_PARAM_LONG(pAllocator)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &device_param, &descriptorPool_param, &pAllocator_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, descriptorPool);
	ZVAL_LONG(&_2, pAllocator);
	phpvk_vk10_vkdestroydescriptorpool(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkResetDescriptorPool)
{
	zval *device_param = NULL, *descriptorPool_param = NULL, *flags_param = NULL, _0, _1, _2;
	zend_long device, descriptorPool, flags;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(descriptorPool)
		Z_PARAM_LONG(flags)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &device_param, &descriptorPool_param, &flags_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, descriptorPool);
	ZVAL_LONG(&_2, flags);
	RETURN_LONG(phpvk_vk10_vkresetdescriptorpool(&_0, &_1, &_2));
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkAllocateDescriptorSets)
{
	zval *device_param = NULL, *pAllocateInfo_param = NULL, *pDescriptorSets_param = NULL, _0, _1, _2;
	zend_long device, pAllocateInfo, pDescriptorSets;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(pAllocateInfo)
		Z_PARAM_LONG(pDescriptorSets)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &device_param, &pAllocateInfo_param, &pDescriptorSets_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, pAllocateInfo);
	ZVAL_LONG(&_2, pDescriptorSets);
	RETURN_LONG(phpvk_vk10_vkallocatedescriptorsets(&_0, &_1, &_2));
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkFreeDescriptorSets)
{
	zval *device_param = NULL, *descriptorPool_param = NULL, *descriptorSetCount_param = NULL, *pDescriptorSets_param = NULL, _0, _1, _2, _3;
	zend_long device, descriptorPool, descriptorSetCount, pDescriptorSets;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(descriptorPool)
		Z_PARAM_LONG(descriptorSetCount)
		Z_PARAM_LONG(pDescriptorSets)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &device_param, &descriptorPool_param, &descriptorSetCount_param, &pDescriptorSets_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, descriptorPool);
	ZVAL_LONG(&_2, descriptorSetCount);
	ZVAL_LONG(&_3, pDescriptorSets);
	RETURN_LONG(phpvk_vk10_vkfreedescriptorsets(&_0, &_1, &_2, &_3));
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkUpdateDescriptorSets)
{
	zval *device_param = NULL, *descriptorWriteCount_param = NULL, *pDescriptorWrites_param = NULL, *descriptorCopyCount_param = NULL, *pDescriptorCopies_param = NULL, _0, _1, _2, _3, _4;
	zend_long device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(descriptorWriteCount)
		Z_PARAM_LONG(pDescriptorWrites)
		Z_PARAM_LONG(descriptorCopyCount)
		Z_PARAM_LONG(pDescriptorCopies)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &device_param, &descriptorWriteCount_param, &pDescriptorWrites_param, &descriptorCopyCount_param, &pDescriptorCopies_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, descriptorWriteCount);
	ZVAL_LONG(&_2, pDescriptorWrites);
	ZVAL_LONG(&_3, descriptorCopyCount);
	ZVAL_LONG(&_4, pDescriptorCopies);
	phpvk_vk10_vkupdatedescriptorsets(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdBindPipeline)
{
	zval *commandBuffer_param = NULL, *pipelineBindPoint_param = NULL, *pipeline_param = NULL, _0, _1, _2;
	zend_long commandBuffer, pipelineBindPoint, pipeline;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(pipelineBindPoint)
		Z_PARAM_LONG(pipeline)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &commandBuffer_param, &pipelineBindPoint_param, &pipeline_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, pipelineBindPoint);
	ZVAL_LONG(&_2, pipeline);
	phpvk_vk10_vkcmdbindpipeline(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdBindDescriptorSets)
{
	zval *commandBuffer_param = NULL, *pipelineBindPoint_param = NULL, *layout_param = NULL, *firstSet_param = NULL, *descriptorSetCount_param = NULL, *pDescriptorSets_param = NULL, *dynamicOffsetCount_param = NULL, *pDynamicOffsets_param = NULL, _0, _1, _2, _3, _4, _5, _6, _7;
	zend_long commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZEND_PARSE_PARAMETERS_START(8, 8)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(pipelineBindPoint)
		Z_PARAM_LONG(layout)
		Z_PARAM_LONG(firstSet)
		Z_PARAM_LONG(descriptorSetCount)
		Z_PARAM_LONG(pDescriptorSets)
		Z_PARAM_LONG(dynamicOffsetCount)
		Z_PARAM_LONG(pDynamicOffsets)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(8, 0, &commandBuffer_param, &pipelineBindPoint_param, &layout_param, &firstSet_param, &descriptorSetCount_param, &pDescriptorSets_param, &dynamicOffsetCount_param, &pDynamicOffsets_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, pipelineBindPoint);
	ZVAL_LONG(&_2, layout);
	ZVAL_LONG(&_3, firstSet);
	ZVAL_LONG(&_4, descriptorSetCount);
	ZVAL_LONG(&_5, pDescriptorSets);
	ZVAL_LONG(&_6, dynamicOffsetCount);
	ZVAL_LONG(&_7, pDynamicOffsets);
	phpvk_vk10_vkcmdbinddescriptorsets(&_0, &_1, &_2, &_3, &_4, &_5, &_6, &_7);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdClearColorImage)
{
	zval *commandBuffer_param = NULL, *image_param = NULL, *imageLayout_param = NULL, *pColor_param = NULL, *rangeCount_param = NULL, *pRanges_param = NULL, _0, _1, _2, _3, _4, _5;
	zend_long commandBuffer, image, imageLayout, pColor, rangeCount, pRanges;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(image)
		Z_PARAM_LONG(imageLayout)
		Z_PARAM_LONG(pColor)
		Z_PARAM_LONG(rangeCount)
		Z_PARAM_LONG(pRanges)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(6, 0, &commandBuffer_param, &image_param, &imageLayout_param, &pColor_param, &rangeCount_param, &pRanges_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, image);
	ZVAL_LONG(&_2, imageLayout);
	ZVAL_LONG(&_3, pColor);
	ZVAL_LONG(&_4, rangeCount);
	ZVAL_LONG(&_5, pRanges);
	phpvk_vk10_vkcmdclearcolorimage(&_0, &_1, &_2, &_3, &_4, &_5);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdDispatch)
{
	zval *commandBuffer_param = NULL, *groupCountX_param = NULL, *groupCountY_param = NULL, *groupCountZ_param = NULL, _0, _1, _2, _3;
	zend_long commandBuffer, groupCountX, groupCountY, groupCountZ;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(groupCountX)
		Z_PARAM_LONG(groupCountY)
		Z_PARAM_LONG(groupCountZ)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &commandBuffer_param, &groupCountX_param, &groupCountY_param, &groupCountZ_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, groupCountX);
	ZVAL_LONG(&_2, groupCountY);
	ZVAL_LONG(&_3, groupCountZ);
	phpvk_vk10_vkcmddispatch(&_0, &_1, &_2, &_3);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdDispatchIndirect)
{
	zval *commandBuffer_param = NULL, *buffer_param = NULL, *offset_param = NULL, _0, _1, _2;
	zend_long commandBuffer, buffer, offset;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(buffer)
		Z_PARAM_LONG(offset)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &commandBuffer_param, &buffer_param, &offset_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, buffer);
	ZVAL_LONG(&_2, offset);
	phpvk_vk10_vkcmddispatchindirect(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdSetEvent)
{
	zval *commandBuffer_param = NULL, *event_param = NULL, *stageMask_param = NULL, _0, _1, _2;
	zend_long commandBuffer, event, stageMask;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(event)
		Z_PARAM_LONG(stageMask)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &commandBuffer_param, &event_param, &stageMask_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, event);
	ZVAL_LONG(&_2, stageMask);
	phpvk_vk10_vkcmdsetevent(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdResetEvent)
{
	zval *commandBuffer_param = NULL, *event_param = NULL, *stageMask_param = NULL, _0, _1, _2;
	zend_long commandBuffer, event, stageMask;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(event)
		Z_PARAM_LONG(stageMask)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &commandBuffer_param, &event_param, &stageMask_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, event);
	ZVAL_LONG(&_2, stageMask);
	phpvk_vk10_vkcmdresetevent(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdWaitEvents)
{
	zval *commandBuffer_param = NULL, *eventCount_param = NULL, *pEvents_param = NULL, *srcStageMask_param = NULL, *dstStageMask_param = NULL, *memoryBarrierCount_param = NULL, *pMemoryBarriers_param = NULL, *bufferMemoryBarrierCount_param = NULL, *pBufferMemoryBarriers_param = NULL, *imageMemoryBarrierCount_param = NULL, *pImageMemoryBarriers_param = NULL, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10;
	zend_long commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZEND_PARSE_PARAMETERS_START(11, 11)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(eventCount)
		Z_PARAM_LONG(pEvents)
		Z_PARAM_LONG(srcStageMask)
		Z_PARAM_LONG(dstStageMask)
		Z_PARAM_LONG(memoryBarrierCount)
		Z_PARAM_LONG(pMemoryBarriers)
		Z_PARAM_LONG(bufferMemoryBarrierCount)
		Z_PARAM_LONG(pBufferMemoryBarriers)
		Z_PARAM_LONG(imageMemoryBarrierCount)
		Z_PARAM_LONG(pImageMemoryBarriers)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(11, 0, &commandBuffer_param, &eventCount_param, &pEvents_param, &srcStageMask_param, &dstStageMask_param, &memoryBarrierCount_param, &pMemoryBarriers_param, &bufferMemoryBarrierCount_param, &pBufferMemoryBarriers_param, &imageMemoryBarrierCount_param, &pImageMemoryBarriers_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, eventCount);
	ZVAL_LONG(&_2, pEvents);
	ZVAL_LONG(&_3, srcStageMask);
	ZVAL_LONG(&_4, dstStageMask);
	ZVAL_LONG(&_5, memoryBarrierCount);
	ZVAL_LONG(&_6, pMemoryBarriers);
	ZVAL_LONG(&_7, bufferMemoryBarrierCount);
	ZVAL_LONG(&_8, pBufferMemoryBarriers);
	ZVAL_LONG(&_9, imageMemoryBarrierCount);
	ZVAL_LONG(&_10, pImageMemoryBarriers);
	phpvk_vk10_vkcmdwaitevents(&_0, &_1, &_2, &_3, &_4, &_5, &_6, &_7, &_8, &_9, &_10);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdPushConstants)
{
	zval *commandBuffer_param = NULL, *layout_param = NULL, *stageFlags_param = NULL, *offset_param = NULL, *size_param = NULL, *pValues_param = NULL, _0, _1, _2, _3, _4, _5;
	zend_long commandBuffer, layout, stageFlags, offset, size, pValues;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(layout)
		Z_PARAM_LONG(stageFlags)
		Z_PARAM_LONG(offset)
		Z_PARAM_LONG(size)
		Z_PARAM_LONG(pValues)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(6, 0, &commandBuffer_param, &layout_param, &stageFlags_param, &offset_param, &size_param, &pValues_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, layout);
	ZVAL_LONG(&_2, stageFlags);
	ZVAL_LONG(&_3, offset);
	ZVAL_LONG(&_4, size);
	ZVAL_LONG(&_5, pValues);
	phpvk_vk10_vkcmdpushconstants(&_0, &_1, &_2, &_3, &_4, &_5);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCreateGraphicsPipelines)
{
	zval *device_param = NULL, *pipelineCache_param = NULL, *createInfoCount_param = NULL, *pCreateInfos_param = NULL, *pAllocator_param = NULL, *pPipelines_param = NULL, _0, _1, _2, _3, _4, _5;
	zend_long device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(pipelineCache)
		Z_PARAM_LONG(createInfoCount)
		Z_PARAM_LONG(pCreateInfos)
		Z_PARAM_LONG(pAllocator)
		Z_PARAM_LONG(pPipelines)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(6, 0, &device_param, &pipelineCache_param, &createInfoCount_param, &pCreateInfos_param, &pAllocator_param, &pPipelines_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, pipelineCache);
	ZVAL_LONG(&_2, createInfoCount);
	ZVAL_LONG(&_3, pCreateInfos);
	ZVAL_LONG(&_4, pAllocator);
	ZVAL_LONG(&_5, pPipelines);
	RETURN_LONG(phpvk_vk10_vkcreategraphicspipelines(&_0, &_1, &_2, &_3, &_4, &_5));
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCreateFramebuffer)
{
	zval *device_param = NULL, *pCreateInfo_param = NULL, *pAllocator_param = NULL, *pFramebuffer_param = NULL, _0, _1, _2, _3;
	zend_long device, pCreateInfo, pAllocator, pFramebuffer;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(pCreateInfo)
		Z_PARAM_LONG(pAllocator)
		Z_PARAM_LONG(pFramebuffer)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &device_param, &pCreateInfo_param, &pAllocator_param, &pFramebuffer_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, pCreateInfo);
	ZVAL_LONG(&_2, pAllocator);
	ZVAL_LONG(&_3, pFramebuffer);
	RETURN_LONG(phpvk_vk10_vkcreateframebuffer(&_0, &_1, &_2, &_3));
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkDestroyFramebuffer)
{
	zval *device_param = NULL, *framebuffer_param = NULL, *pAllocator_param = NULL, _0, _1, _2;
	zend_long device, framebuffer, pAllocator;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(framebuffer)
		Z_PARAM_LONG(pAllocator)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &device_param, &framebuffer_param, &pAllocator_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, framebuffer);
	ZVAL_LONG(&_2, pAllocator);
	phpvk_vk10_vkdestroyframebuffer(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCreateRenderPass)
{
	zval *device_param = NULL, *pCreateInfo_param = NULL, *pAllocator_param = NULL, *pRenderPass_param = NULL, _0, _1, _2, _3;
	zend_long device, pCreateInfo, pAllocator, pRenderPass;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(pCreateInfo)
		Z_PARAM_LONG(pAllocator)
		Z_PARAM_LONG(pRenderPass)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &device_param, &pCreateInfo_param, &pAllocator_param, &pRenderPass_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, pCreateInfo);
	ZVAL_LONG(&_2, pAllocator);
	ZVAL_LONG(&_3, pRenderPass);
	RETURN_LONG(phpvk_vk10_vkcreaterenderpass(&_0, &_1, &_2, &_3));
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkDestroyRenderPass)
{
	zval *device_param = NULL, *renderPass_param = NULL, *pAllocator_param = NULL, _0, _1, _2;
	zend_long device, renderPass, pAllocator;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(renderPass)
		Z_PARAM_LONG(pAllocator)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &device_param, &renderPass_param, &pAllocator_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, renderPass);
	ZVAL_LONG(&_2, pAllocator);
	phpvk_vk10_vkdestroyrenderpass(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkGetRenderAreaGranularity)
{
	zval *device_param = NULL, *renderPass_param = NULL, *pGranularity_param = NULL, _0, _1, _2;
	zend_long device, renderPass, pGranularity;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(device)
		Z_PARAM_LONG(renderPass)
		Z_PARAM_LONG(pGranularity)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &device_param, &renderPass_param, &pGranularity_param);
	ZVAL_LONG(&_0, device);
	ZVAL_LONG(&_1, renderPass);
	ZVAL_LONG(&_2, pGranularity);
	phpvk_vk10_vkgetrenderareagranularity(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdSetViewport)
{
	zval *commandBuffer_param = NULL, *firstViewport_param = NULL, *viewportCount_param = NULL, *pViewports_param = NULL, _0, _1, _2, _3;
	zend_long commandBuffer, firstViewport, viewportCount, pViewports;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(firstViewport)
		Z_PARAM_LONG(viewportCount)
		Z_PARAM_LONG(pViewports)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &commandBuffer_param, &firstViewport_param, &viewportCount_param, &pViewports_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, firstViewport);
	ZVAL_LONG(&_2, viewportCount);
	ZVAL_LONG(&_3, pViewports);
	phpvk_vk10_vkcmdsetviewport(&_0, &_1, &_2, &_3);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdSetScissor)
{
	zval *commandBuffer_param = NULL, *firstScissor_param = NULL, *scissorCount_param = NULL, *pScissors_param = NULL, _0, _1, _2, _3;
	zend_long commandBuffer, firstScissor, scissorCount, pScissors;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(firstScissor)
		Z_PARAM_LONG(scissorCount)
		Z_PARAM_LONG(pScissors)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &commandBuffer_param, &firstScissor_param, &scissorCount_param, &pScissors_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, firstScissor);
	ZVAL_LONG(&_2, scissorCount);
	ZVAL_LONG(&_3, pScissors);
	phpvk_vk10_vkcmdsetscissor(&_0, &_1, &_2, &_3);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdSetLineWidth)
{
	double lineWidth;
	zval *commandBuffer_param = NULL, *lineWidth_param = NULL, _0, _1;
	zend_long commandBuffer;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_ZVAL(lineWidth)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &commandBuffer_param, &lineWidth_param);
	lineWidth = zephir_get_doubleval(lineWidth_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_DOUBLE(&_1, lineWidth);
	phpvk_vk10_vkcmdsetlinewidth(&_0, &_1);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdSetDepthBias)
{
	double depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor;
	zval *commandBuffer_param = NULL, *depthBiasConstantFactor_param = NULL, *depthBiasClamp_param = NULL, *depthBiasSlopeFactor_param = NULL, _0, _1, _2, _3;
	zend_long commandBuffer;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_ZVAL(depthBiasConstantFactor)
		Z_PARAM_ZVAL(depthBiasClamp)
		Z_PARAM_ZVAL(depthBiasSlopeFactor)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &commandBuffer_param, &depthBiasConstantFactor_param, &depthBiasClamp_param, &depthBiasSlopeFactor_param);
	depthBiasConstantFactor = zephir_get_doubleval(depthBiasConstantFactor_param);
	depthBiasClamp = zephir_get_doubleval(depthBiasClamp_param);
	depthBiasSlopeFactor = zephir_get_doubleval(depthBiasSlopeFactor_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_DOUBLE(&_1, depthBiasConstantFactor);
	ZVAL_DOUBLE(&_2, depthBiasClamp);
	ZVAL_DOUBLE(&_3, depthBiasSlopeFactor);
	phpvk_vk10_vkcmdsetdepthbias(&_0, &_1, &_2, &_3);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdSetBlendConstants)
{
	zval *commandBuffer_param = NULL, *blendConstants_param = NULL, _0, _1;
	zend_long commandBuffer, blendConstants;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(blendConstants)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &commandBuffer_param, &blendConstants_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, blendConstants);
	phpvk_vk10_vkcmdsetblendconstants(&_0, &_1);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdSetDepthBounds)
{
	double minDepthBounds, maxDepthBounds;
	zval *commandBuffer_param = NULL, *minDepthBounds_param = NULL, *maxDepthBounds_param = NULL, _0, _1, _2;
	zend_long commandBuffer;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_ZVAL(minDepthBounds)
		Z_PARAM_ZVAL(maxDepthBounds)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &commandBuffer_param, &minDepthBounds_param, &maxDepthBounds_param);
	minDepthBounds = zephir_get_doubleval(minDepthBounds_param);
	maxDepthBounds = zephir_get_doubleval(maxDepthBounds_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_DOUBLE(&_1, minDepthBounds);
	ZVAL_DOUBLE(&_2, maxDepthBounds);
	phpvk_vk10_vkcmdsetdepthbounds(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdSetStencilCompareMask)
{
	zval *commandBuffer_param = NULL, *faceMask_param = NULL, *compareMask_param = NULL, _0, _1, _2;
	zend_long commandBuffer, faceMask, compareMask;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(faceMask)
		Z_PARAM_LONG(compareMask)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &commandBuffer_param, &faceMask_param, &compareMask_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, faceMask);
	ZVAL_LONG(&_2, compareMask);
	phpvk_vk10_vkcmdsetstencilcomparemask(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdSetStencilWriteMask)
{
	zval *commandBuffer_param = NULL, *faceMask_param = NULL, *writeMask_param = NULL, _0, _1, _2;
	zend_long commandBuffer, faceMask, writeMask;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(faceMask)
		Z_PARAM_LONG(writeMask)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &commandBuffer_param, &faceMask_param, &writeMask_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, faceMask);
	ZVAL_LONG(&_2, writeMask);
	phpvk_vk10_vkcmdsetstencilwritemask(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdSetStencilReference)
{
	zval *commandBuffer_param = NULL, *faceMask_param = NULL, *reference_param = NULL, _0, _1, _2;
	zend_long commandBuffer, faceMask, reference;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(faceMask)
		Z_PARAM_LONG(reference)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &commandBuffer_param, &faceMask_param, &reference_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, faceMask);
	ZVAL_LONG(&_2, reference);
	phpvk_vk10_vkcmdsetstencilreference(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdBindIndexBuffer)
{
	zval *commandBuffer_param = NULL, *buffer_param = NULL, *offset_param = NULL, *indexType_param = NULL, _0, _1, _2, _3;
	zend_long commandBuffer, buffer, offset, indexType;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(buffer)
		Z_PARAM_LONG(offset)
		Z_PARAM_LONG(indexType)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &commandBuffer_param, &buffer_param, &offset_param, &indexType_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, buffer);
	ZVAL_LONG(&_2, offset);
	ZVAL_LONG(&_3, indexType);
	phpvk_vk10_vkcmdbindindexbuffer(&_0, &_1, &_2, &_3);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdBindVertexBuffers)
{
	zval *commandBuffer_param = NULL, *firstBinding_param = NULL, *bindingCount_param = NULL, *pBuffers_param = NULL, *pOffsets_param = NULL, _0, _1, _2, _3, _4;
	zend_long commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(firstBinding)
		Z_PARAM_LONG(bindingCount)
		Z_PARAM_LONG(pBuffers)
		Z_PARAM_LONG(pOffsets)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &commandBuffer_param, &firstBinding_param, &bindingCount_param, &pBuffers_param, &pOffsets_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, firstBinding);
	ZVAL_LONG(&_2, bindingCount);
	ZVAL_LONG(&_3, pBuffers);
	ZVAL_LONG(&_4, pOffsets);
	phpvk_vk10_vkcmdbindvertexbuffers(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdDraw)
{
	zval *commandBuffer_param = NULL, *vertexCount_param = NULL, *instanceCount_param = NULL, *firstVertex_param = NULL, *firstInstance_param = NULL, _0, _1, _2, _3, _4;
	zend_long commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(vertexCount)
		Z_PARAM_LONG(instanceCount)
		Z_PARAM_LONG(firstVertex)
		Z_PARAM_LONG(firstInstance)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &commandBuffer_param, &vertexCount_param, &instanceCount_param, &firstVertex_param, &firstInstance_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, vertexCount);
	ZVAL_LONG(&_2, instanceCount);
	ZVAL_LONG(&_3, firstVertex);
	ZVAL_LONG(&_4, firstInstance);
	phpvk_vk10_vkcmddraw(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdDrawIndexed)
{
	zval *commandBuffer_param = NULL, *indexCount_param = NULL, *instanceCount_param = NULL, *firstIndex_param = NULL, *vertexOffset_param = NULL, *firstInstance_param = NULL, _0, _1, _2, _3, _4, _5;
	zend_long commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(indexCount)
		Z_PARAM_LONG(instanceCount)
		Z_PARAM_LONG(firstIndex)
		Z_PARAM_LONG(vertexOffset)
		Z_PARAM_LONG(firstInstance)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(6, 0, &commandBuffer_param, &indexCount_param, &instanceCount_param, &firstIndex_param, &vertexOffset_param, &firstInstance_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, indexCount);
	ZVAL_LONG(&_2, instanceCount);
	ZVAL_LONG(&_3, firstIndex);
	ZVAL_LONG(&_4, vertexOffset);
	ZVAL_LONG(&_5, firstInstance);
	phpvk_vk10_vkcmddrawindexed(&_0, &_1, &_2, &_3, &_4, &_5);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdDrawIndirect)
{
	zval *commandBuffer_param = NULL, *buffer_param = NULL, *offset_param = NULL, *drawCount_param = NULL, *stride_param = NULL, _0, _1, _2, _3, _4;
	zend_long commandBuffer, buffer, offset, drawCount, stride;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(buffer)
		Z_PARAM_LONG(offset)
		Z_PARAM_LONG(drawCount)
		Z_PARAM_LONG(stride)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &commandBuffer_param, &buffer_param, &offset_param, &drawCount_param, &stride_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, buffer);
	ZVAL_LONG(&_2, offset);
	ZVAL_LONG(&_3, drawCount);
	ZVAL_LONG(&_4, stride);
	phpvk_vk10_vkcmddrawindirect(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdDrawIndexedIndirect)
{
	zval *commandBuffer_param = NULL, *buffer_param = NULL, *offset_param = NULL, *drawCount_param = NULL, *stride_param = NULL, _0, _1, _2, _3, _4;
	zend_long commandBuffer, buffer, offset, drawCount, stride;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(buffer)
		Z_PARAM_LONG(offset)
		Z_PARAM_LONG(drawCount)
		Z_PARAM_LONG(stride)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &commandBuffer_param, &buffer_param, &offset_param, &drawCount_param, &stride_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, buffer);
	ZVAL_LONG(&_2, offset);
	ZVAL_LONG(&_3, drawCount);
	ZVAL_LONG(&_4, stride);
	phpvk_vk10_vkcmddrawindexedindirect(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdBlitImage)
{
	zval *commandBuffer_param = NULL, *srcImage_param = NULL, *srcImageLayout_param = NULL, *dstImage_param = NULL, *dstImageLayout_param = NULL, *regionCount_param = NULL, *pRegions_param = NULL, *filter_param = NULL, _0, _1, _2, _3, _4, _5, _6, _7;
	zend_long commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZEND_PARSE_PARAMETERS_START(8, 8)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(srcImage)
		Z_PARAM_LONG(srcImageLayout)
		Z_PARAM_LONG(dstImage)
		Z_PARAM_LONG(dstImageLayout)
		Z_PARAM_LONG(regionCount)
		Z_PARAM_LONG(pRegions)
		Z_PARAM_LONG(filter)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(8, 0, &commandBuffer_param, &srcImage_param, &srcImageLayout_param, &dstImage_param, &dstImageLayout_param, &regionCount_param, &pRegions_param, &filter_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, srcImage);
	ZVAL_LONG(&_2, srcImageLayout);
	ZVAL_LONG(&_3, dstImage);
	ZVAL_LONG(&_4, dstImageLayout);
	ZVAL_LONG(&_5, regionCount);
	ZVAL_LONG(&_6, pRegions);
	ZVAL_LONG(&_7, filter);
	phpvk_vk10_vkcmdblitimage(&_0, &_1, &_2, &_3, &_4, &_5, &_6, &_7);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdClearDepthStencilImage)
{
	zval *commandBuffer_param = NULL, *image_param = NULL, *imageLayout_param = NULL, *pDepthStencil_param = NULL, *rangeCount_param = NULL, *pRanges_param = NULL, _0, _1, _2, _3, _4, _5;
	zend_long commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(image)
		Z_PARAM_LONG(imageLayout)
		Z_PARAM_LONG(pDepthStencil)
		Z_PARAM_LONG(rangeCount)
		Z_PARAM_LONG(pRanges)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(6, 0, &commandBuffer_param, &image_param, &imageLayout_param, &pDepthStencil_param, &rangeCount_param, &pRanges_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, image);
	ZVAL_LONG(&_2, imageLayout);
	ZVAL_LONG(&_3, pDepthStencil);
	ZVAL_LONG(&_4, rangeCount);
	ZVAL_LONG(&_5, pRanges);
	phpvk_vk10_vkcmdcleardepthstencilimage(&_0, &_1, &_2, &_3, &_4, &_5);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdClearAttachments)
{
	zval *commandBuffer_param = NULL, *attachmentCount_param = NULL, *pAttachments_param = NULL, *rectCount_param = NULL, *pRects_param = NULL, _0, _1, _2, _3, _4;
	zend_long commandBuffer, attachmentCount, pAttachments, rectCount, pRects;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(attachmentCount)
		Z_PARAM_LONG(pAttachments)
		Z_PARAM_LONG(rectCount)
		Z_PARAM_LONG(pRects)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &commandBuffer_param, &attachmentCount_param, &pAttachments_param, &rectCount_param, &pRects_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, attachmentCount);
	ZVAL_LONG(&_2, pAttachments);
	ZVAL_LONG(&_3, rectCount);
	ZVAL_LONG(&_4, pRects);
	phpvk_vk10_vkcmdclearattachments(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdResolveImage)
{
	zval *commandBuffer_param = NULL, *srcImage_param = NULL, *srcImageLayout_param = NULL, *dstImage_param = NULL, *dstImageLayout_param = NULL, *regionCount_param = NULL, *pRegions_param = NULL, _0, _1, _2, _3, _4, _5, _6;
	zend_long commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZEND_PARSE_PARAMETERS_START(7, 7)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(srcImage)
		Z_PARAM_LONG(srcImageLayout)
		Z_PARAM_LONG(dstImage)
		Z_PARAM_LONG(dstImageLayout)
		Z_PARAM_LONG(regionCount)
		Z_PARAM_LONG(pRegions)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(7, 0, &commandBuffer_param, &srcImage_param, &srcImageLayout_param, &dstImage_param, &dstImageLayout_param, &regionCount_param, &pRegions_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, srcImage);
	ZVAL_LONG(&_2, srcImageLayout);
	ZVAL_LONG(&_3, dstImage);
	ZVAL_LONG(&_4, dstImageLayout);
	ZVAL_LONG(&_5, regionCount);
	ZVAL_LONG(&_6, pRegions);
	phpvk_vk10_vkcmdresolveimage(&_0, &_1, &_2, &_3, &_4, &_5, &_6);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdBeginRenderPass)
{
	zval *commandBuffer_param = NULL, *pRenderPassBegin_param = NULL, *contents_param = NULL, _0, _1, _2;
	zend_long commandBuffer, pRenderPassBegin, contents;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(pRenderPassBegin)
		Z_PARAM_LONG(contents)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &commandBuffer_param, &pRenderPassBegin_param, &contents_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, pRenderPassBegin);
	ZVAL_LONG(&_2, contents);
	phpvk_vk10_vkcmdbeginrenderpass(&_0, &_1, &_2);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdNextSubpass)
{
	zval *commandBuffer_param = NULL, *contents_param = NULL, _0, _1;
	zend_long commandBuffer, contents;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(commandBuffer)
		Z_PARAM_LONG(contents)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &commandBuffer_param, &contents_param);
	ZVAL_LONG(&_0, commandBuffer);
	ZVAL_LONG(&_1, contents);
	phpvk_vk10_vkcmdnextsubpass(&_0, &_1);
}

PHP_METHOD(Vulkan_VK_VK10_VK10, vkCmdEndRenderPass)
{
	zval *commandBuffer_param = NULL, _0;
	zend_long commandBuffer;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(commandBuffer)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &commandBuffer_param);
	ZVAL_LONG(&_0, commandBuffer);
	phpvk_vk10_vkcmdendrenderpass(&_0);
}

