/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 703d3aae4ff0a862d567f7d0751ae5b07d762965 */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkCreateInstance, 0, 3, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, pCreateInfo, VkInstanceCreateInfo, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_NULL, 1)
	ZEND_ARG_OBJ_INFO(1, pInstance, VkInstance, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkDestroyInstance, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, instance, VkInstance, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_NULL, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkEnumerateInstanceExtensionProperties, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pLayerName, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(1, pProperties, IS_ARRAY, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkEnumeratePhysicalDevices, 0, 2, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, instance, VkInstance, 0)
	ZEND_ARG_TYPE_INFO(1, pPhysicalDevices, IS_ARRAY, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkGetPhysicalDeviceProperties, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, physicalDevice, VkPhysicalDevice, 0)
	ZEND_ARG_OBJ_INFO(1, pProperties, VkPhysicalDeviceProperties, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkGetPhysicalDeviceQueueFamilyProperties, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, physicalDevice, VkPhysicalDevice, 0)
	ZEND_ARG_TYPE_INFO(1, pQueueFamilyProperties, IS_ARRAY, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkGetPhysicalDeviceMemoryProperties, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, physicalDevice, VkPhysicalDevice, 0)
	ZEND_ARG_OBJ_INFO(1, pMemoryProperties, VkPhysicalDeviceMemoryProperties, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkGetPhysicalDeviceFormatProperties, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, physicalDevice, VkPhysicalDevice, 0)
	ZEND_ARG_TYPE_INFO(0, format, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(1, pFormatProperties, VkFormatProperties, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkEnumerateDeviceExtensionProperties, 0, 3, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, physicalDevice, VkPhysicalDevice, 0)
	ZEND_ARG_TYPE_INFO(0, pLayerName, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(1, pProperties, IS_ARRAY, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkCreateDevice, 0, 4, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, physicalDevice, VkPhysicalDevice, 0)
	ZEND_ARG_OBJ_INFO(0, pCreateInfo, VkDeviceCreateInfo, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_NULL, 1)
	ZEND_ARG_OBJ_INFO(1, pDevice, VkDevice, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkDestroyDevice, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, device, VkDevice, 0)
	ZEND_ARG_TYPE_INFO(0, pAllocator, IS_NULL, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkGetDeviceQueue, 0, 4, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, device, VkDevice, 0)
	ZEND_ARG_TYPE_INFO(0, queueFamilyIndex, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, queueIndex, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(1, pQueue, VkQueue, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vkDeviceWaitIdle, 0, 1, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, device, VkDevice, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_VkInstance___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_VkInstance_pointer, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_VkInstance_fromPointer, 0, 1, IS_STATIC, 0)
	ZEND_ARG_TYPE_INFO(0, pointer, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_VkPhysicalDevice___construct arginfo_class_VkInstance___construct

#define arginfo_class_VkPhysicalDevice_pointer arginfo_class_VkInstance_pointer

#define arginfo_class_VkPhysicalDevice_fromPointer arginfo_class_VkInstance_fromPointer

#define arginfo_class_VkDevice___construct arginfo_class_VkInstance___construct

#define arginfo_class_VkDevice_pointer arginfo_class_VkInstance_pointer

#define arginfo_class_VkDevice_fromPointer arginfo_class_VkInstance_fromPointer

#define arginfo_class_VkQueue___construct arginfo_class_VkInstance___construct

#define arginfo_class_VkQueue_pointer arginfo_class_VkInstance_pointer

#define arginfo_class_VkQueue_fromPointer arginfo_class_VkInstance_fromPointer

#define arginfo_class_VkPhysicalDeviceProperties___construct arginfo_class_VkInstance___construct

#define arginfo_class_VkQueueFamilyProperties___construct arginfo_class_VkInstance___construct

ZEND_FUNCTION(vkCreateInstance);
ZEND_FUNCTION(vkDestroyInstance);
ZEND_FUNCTION(vkEnumerateInstanceExtensionProperties);
ZEND_FUNCTION(vkEnumeratePhysicalDevices);
ZEND_FUNCTION(vkGetPhysicalDeviceProperties);
ZEND_FUNCTION(vkGetPhysicalDeviceQueueFamilyProperties);
ZEND_FUNCTION(vkGetPhysicalDeviceMemoryProperties);
ZEND_FUNCTION(vkGetPhysicalDeviceFormatProperties);
ZEND_FUNCTION(vkEnumerateDeviceExtensionProperties);
ZEND_FUNCTION(vkCreateDevice);
ZEND_FUNCTION(vkDestroyDevice);
ZEND_FUNCTION(vkGetDeviceQueue);
ZEND_FUNCTION(vkDeviceWaitIdle);
ZEND_METHOD(VkInstance, __construct);
ZEND_METHOD(VkInstance, pointer);
ZEND_METHOD(VkInstance, fromPointer);
ZEND_METHOD(VkPhysicalDevice, __construct);
ZEND_METHOD(VkPhysicalDevice, pointer);
ZEND_METHOD(VkPhysicalDevice, fromPointer);
ZEND_METHOD(VkDevice, __construct);
ZEND_METHOD(VkDevice, pointer);
ZEND_METHOD(VkDevice, fromPointer);
ZEND_METHOD(VkQueue, __construct);
ZEND_METHOD(VkQueue, pointer);
ZEND_METHOD(VkQueue, fromPointer);
ZEND_METHOD(VkPhysicalDeviceProperties, __construct);
ZEND_METHOD(VkQueueFamilyProperties, __construct);

static const zend_function_entry ext_functions[] = {
	ZEND_FE(vkCreateInstance, arginfo_vkCreateInstance)
	ZEND_FE(vkDestroyInstance, arginfo_vkDestroyInstance)
	ZEND_FE(vkEnumerateInstanceExtensionProperties, arginfo_vkEnumerateInstanceExtensionProperties)
	ZEND_FE(vkEnumeratePhysicalDevices, arginfo_vkEnumeratePhysicalDevices)
	ZEND_FE(vkGetPhysicalDeviceProperties, arginfo_vkGetPhysicalDeviceProperties)
	ZEND_FE(vkGetPhysicalDeviceQueueFamilyProperties, arginfo_vkGetPhysicalDeviceQueueFamilyProperties)
	ZEND_FE(vkGetPhysicalDeviceMemoryProperties, arginfo_vkGetPhysicalDeviceMemoryProperties)
	ZEND_FE(vkGetPhysicalDeviceFormatProperties, arginfo_vkGetPhysicalDeviceFormatProperties)
	ZEND_FE(vkEnumerateDeviceExtensionProperties, arginfo_vkEnumerateDeviceExtensionProperties)
	ZEND_FE(vkCreateDevice, arginfo_vkCreateDevice)
	ZEND_FE(vkDestroyDevice, arginfo_vkDestroyDevice)
	ZEND_FE(vkGetDeviceQueue, arginfo_vkGetDeviceQueue)
	ZEND_FE(vkDeviceWaitIdle, arginfo_vkDeviceWaitIdle)
	ZEND_FE_END
};

static const zend_function_entry class_VkInstance_methods[] = {
	ZEND_ME(VkInstance, __construct, arginfo_class_VkInstance___construct, ZEND_ACC_PRIVATE)
	ZEND_ME(VkInstance, pointer, arginfo_class_VkInstance_pointer, ZEND_ACC_PUBLIC)
	ZEND_ME(VkInstance, fromPointer, arginfo_class_VkInstance_fromPointer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static const zend_function_entry class_VkPhysicalDevice_methods[] = {
	ZEND_ME(VkPhysicalDevice, __construct, arginfo_class_VkPhysicalDevice___construct, ZEND_ACC_PRIVATE)
	ZEND_ME(VkPhysicalDevice, pointer, arginfo_class_VkPhysicalDevice_pointer, ZEND_ACC_PUBLIC)
	ZEND_ME(VkPhysicalDevice, fromPointer, arginfo_class_VkPhysicalDevice_fromPointer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static const zend_function_entry class_VkDevice_methods[] = {
	ZEND_ME(VkDevice, __construct, arginfo_class_VkDevice___construct, ZEND_ACC_PRIVATE)
	ZEND_ME(VkDevice, pointer, arginfo_class_VkDevice_pointer, ZEND_ACC_PUBLIC)
	ZEND_ME(VkDevice, fromPointer, arginfo_class_VkDevice_fromPointer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static const zend_function_entry class_VkQueue_methods[] = {
	ZEND_ME(VkQueue, __construct, arginfo_class_VkQueue___construct, ZEND_ACC_PRIVATE)
	ZEND_ME(VkQueue, pointer, arginfo_class_VkQueue_pointer, ZEND_ACC_PUBLIC)
	ZEND_ME(VkQueue, fromPointer, arginfo_class_VkQueue_fromPointer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static const zend_function_entry class_VkPhysicalDeviceProperties_methods[] = {
	ZEND_ME(VkPhysicalDeviceProperties, __construct, arginfo_class_VkPhysicalDeviceProperties___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_VkQueueFamilyProperties_methods[] = {
	ZEND_ME(VkQueueFamilyProperties, __construct, arginfo_class_VkQueueFamilyProperties___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_VkInstance(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkInstance", class_VkInstance_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_VkPhysicalDevice(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkPhysicalDevice", class_VkPhysicalDevice_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_VkDevice(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkDevice", class_VkDevice_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_VkQueue(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkQueue", class_VkQueue_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_VkApplicationInfo(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkApplicationInfo", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_pNext_default_value;
	ZVAL_NULL(&property_pNext_default_value);
	zend_string *property_pNext_name = zend_string_init("pNext", sizeof("pNext") - 1, 1);
	zend_declare_typed_property(class_entry, property_pNext_name, &property_pNext_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_OBJECT|MAY_BE_NULL));
	zend_string_release(property_pNext_name);

	zval property_pApplicationName_default_value;
	ZVAL_NULL(&property_pApplicationName_default_value);
	zend_string *property_pApplicationName_name = zend_string_init("pApplicationName", sizeof("pApplicationName") - 1, 1);
	zend_declare_typed_property(class_entry, property_pApplicationName_name, &property_pApplicationName_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING|MAY_BE_NULL));
	zend_string_release(property_pApplicationName_name);

	zval property_applicationVersion_default_value;
	ZVAL_LONG(&property_applicationVersion_default_value, 0);
	zend_string *property_applicationVersion_name = zend_string_init("applicationVersion", sizeof("applicationVersion") - 1, 1);
	zend_declare_typed_property(class_entry, property_applicationVersion_name, &property_applicationVersion_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_applicationVersion_name);

	zval property_pEngineName_default_value;
	ZVAL_NULL(&property_pEngineName_default_value);
	zend_string *property_pEngineName_name = zend_string_init("pEngineName", sizeof("pEngineName") - 1, 1);
	zend_declare_typed_property(class_entry, property_pEngineName_name, &property_pEngineName_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING|MAY_BE_NULL));
	zend_string_release(property_pEngineName_name);

	zval property_engineVersion_default_value;
	ZVAL_LONG(&property_engineVersion_default_value, 0);
	zend_string *property_engineVersion_name = zend_string_init("engineVersion", sizeof("engineVersion") - 1, 1);
	zend_declare_typed_property(class_entry, property_engineVersion_name, &property_engineVersion_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_engineVersion_name);

	zval property_apiVersion_default_value;
	ZVAL_LONG(&property_apiVersion_default_value, 0);
	zend_string *property_apiVersion_name = zend_string_init("apiVersion", sizeof("apiVersion") - 1, 1);
	zend_declare_typed_property(class_entry, property_apiVersion_name, &property_apiVersion_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_apiVersion_name);

	return class_entry;
}

static zend_class_entry *register_class_VkInstanceCreateInfo(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkInstanceCreateInfo", NULL);
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

	zval property_pApplicationInfo_default_value;
	ZVAL_NULL(&property_pApplicationInfo_default_value);
	zend_string *property_pApplicationInfo_name = zend_string_init("pApplicationInfo", sizeof("pApplicationInfo") - 1, 1);
	zend_string *property_pApplicationInfo_class_VkApplicationInfo = zend_string_init("VkApplicationInfo", sizeof("VkApplicationInfo")-1, 1);
	zend_declare_typed_property(class_entry, property_pApplicationInfo_name, &property_pApplicationInfo_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_pApplicationInfo_class_VkApplicationInfo, 0, MAY_BE_NULL));
	zend_string_release(property_pApplicationInfo_name);

	zval property_enabledLayerCount_default_value;
	ZVAL_LONG(&property_enabledLayerCount_default_value, 0);
	zend_string *property_enabledLayerCount_name = zend_string_init("enabledLayerCount", sizeof("enabledLayerCount") - 1, 1);
	zend_declare_typed_property(class_entry, property_enabledLayerCount_name, &property_enabledLayerCount_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_enabledLayerCount_name);

	zval property_enabledLayerNames_default_value;
	ZVAL_EMPTY_ARRAY(&property_enabledLayerNames_default_value);
	zend_string *property_enabledLayerNames_name = zend_string_init("enabledLayerNames", sizeof("enabledLayerNames") - 1, 1);
	zend_declare_typed_property(class_entry, property_enabledLayerNames_name, &property_enabledLayerNames_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_enabledLayerNames_name);

	zval property_enabledExtensionCount_default_value;
	ZVAL_LONG(&property_enabledExtensionCount_default_value, 0);
	zend_string *property_enabledExtensionCount_name = zend_string_init("enabledExtensionCount", sizeof("enabledExtensionCount") - 1, 1);
	zend_declare_typed_property(class_entry, property_enabledExtensionCount_name, &property_enabledExtensionCount_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_enabledExtensionCount_name);

	zval property_enabledExtensionNames_default_value;
	ZVAL_EMPTY_ARRAY(&property_enabledExtensionNames_default_value);
	zend_string *property_enabledExtensionNames_name = zend_string_init("enabledExtensionNames", sizeof("enabledExtensionNames") - 1, 1);
	zend_declare_typed_property(class_entry, property_enabledExtensionNames_name, &property_enabledExtensionNames_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_enabledExtensionNames_name);

	return class_entry;
}

static zend_class_entry *register_class_VkDeviceQueueCreateInfo(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkDeviceQueueCreateInfo", NULL);
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

	zval property_queueFamilyIndex_default_value;
	ZVAL_LONG(&property_queueFamilyIndex_default_value, 0);
	zend_string *property_queueFamilyIndex_name = zend_string_init("queueFamilyIndex", sizeof("queueFamilyIndex") - 1, 1);
	zend_declare_typed_property(class_entry, property_queueFamilyIndex_name, &property_queueFamilyIndex_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_queueFamilyIndex_name);

	zval property_pQueuePriorities_default_value;
	ZVAL_EMPTY_ARRAY(&property_pQueuePriorities_default_value);
	zend_string *property_pQueuePriorities_name = zend_string_init("pQueuePriorities", sizeof("pQueuePriorities") - 1, 1);
	zend_declare_typed_property(class_entry, property_pQueuePriorities_name, &property_pQueuePriorities_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_pQueuePriorities_name);

	return class_entry;
}

static zend_class_entry *register_class_VkPhysicalDeviceFeatures(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkPhysicalDeviceFeatures", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_robustBufferAccess_default_value;
	ZVAL_FALSE(&property_robustBufferAccess_default_value);
	zend_string *property_robustBufferAccess_name = zend_string_init("robustBufferAccess", sizeof("robustBufferAccess") - 1, 1);
	zend_declare_typed_property(class_entry, property_robustBufferAccess_name, &property_robustBufferAccess_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_robustBufferAccess_name);

	zval property_fullDrawIndexUint32_default_value;
	ZVAL_FALSE(&property_fullDrawIndexUint32_default_value);
	zend_string *property_fullDrawIndexUint32_name = zend_string_init("fullDrawIndexUint32", sizeof("fullDrawIndexUint32") - 1, 1);
	zend_declare_typed_property(class_entry, property_fullDrawIndexUint32_name, &property_fullDrawIndexUint32_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_fullDrawIndexUint32_name);

	zval property_imageCubeArray_default_value;
	ZVAL_FALSE(&property_imageCubeArray_default_value);
	zend_string *property_imageCubeArray_name = zend_string_init("imageCubeArray", sizeof("imageCubeArray") - 1, 1);
	zend_declare_typed_property(class_entry, property_imageCubeArray_name, &property_imageCubeArray_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_imageCubeArray_name);

	zval property_independentBlend_default_value;
	ZVAL_FALSE(&property_independentBlend_default_value);
	zend_string *property_independentBlend_name = zend_string_init("independentBlend", sizeof("independentBlend") - 1, 1);
	zend_declare_typed_property(class_entry, property_independentBlend_name, &property_independentBlend_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_independentBlend_name);

	zval property_geometryShader_default_value;
	ZVAL_FALSE(&property_geometryShader_default_value);
	zend_string *property_geometryShader_name = zend_string_init("geometryShader", sizeof("geometryShader") - 1, 1);
	zend_declare_typed_property(class_entry, property_geometryShader_name, &property_geometryShader_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_geometryShader_name);

	zval property_tessellationShader_default_value;
	ZVAL_FALSE(&property_tessellationShader_default_value);
	zend_string *property_tessellationShader_name = zend_string_init("tessellationShader", sizeof("tessellationShader") - 1, 1);
	zend_declare_typed_property(class_entry, property_tessellationShader_name, &property_tessellationShader_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_tessellationShader_name);

	zval property_sampleRateShading_default_value;
	ZVAL_FALSE(&property_sampleRateShading_default_value);
	zend_string *property_sampleRateShading_name = zend_string_init("sampleRateShading", sizeof("sampleRateShading") - 1, 1);
	zend_declare_typed_property(class_entry, property_sampleRateShading_name, &property_sampleRateShading_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_sampleRateShading_name);

	zval property_dualSrcBlend_default_value;
	ZVAL_FALSE(&property_dualSrcBlend_default_value);
	zend_string *property_dualSrcBlend_name = zend_string_init("dualSrcBlend", sizeof("dualSrcBlend") - 1, 1);
	zend_declare_typed_property(class_entry, property_dualSrcBlend_name, &property_dualSrcBlend_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_dualSrcBlend_name);

	zval property_logicOp_default_value;
	ZVAL_FALSE(&property_logicOp_default_value);
	zend_string *property_logicOp_name = zend_string_init("logicOp", sizeof("logicOp") - 1, 1);
	zend_declare_typed_property(class_entry, property_logicOp_name, &property_logicOp_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_logicOp_name);

	zval property_multiDrawIndirect_default_value;
	ZVAL_FALSE(&property_multiDrawIndirect_default_value);
	zend_string *property_multiDrawIndirect_name = zend_string_init("multiDrawIndirect", sizeof("multiDrawIndirect") - 1, 1);
	zend_declare_typed_property(class_entry, property_multiDrawIndirect_name, &property_multiDrawIndirect_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_multiDrawIndirect_name);

	zval property_drawIndirectFirstInstance_default_value;
	ZVAL_FALSE(&property_drawIndirectFirstInstance_default_value);
	zend_string *property_drawIndirectFirstInstance_name = zend_string_init("drawIndirectFirstInstance", sizeof("drawIndirectFirstInstance") - 1, 1);
	zend_declare_typed_property(class_entry, property_drawIndirectFirstInstance_name, &property_drawIndirectFirstInstance_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_drawIndirectFirstInstance_name);

	zval property_depthClamp_default_value;
	ZVAL_FALSE(&property_depthClamp_default_value);
	zend_string *property_depthClamp_name = zend_string_init("depthClamp", sizeof("depthClamp") - 1, 1);
	zend_declare_typed_property(class_entry, property_depthClamp_name, &property_depthClamp_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_depthClamp_name);

	zval property_depthBiasClamp_default_value;
	ZVAL_FALSE(&property_depthBiasClamp_default_value);
	zend_string *property_depthBiasClamp_name = zend_string_init("depthBiasClamp", sizeof("depthBiasClamp") - 1, 1);
	zend_declare_typed_property(class_entry, property_depthBiasClamp_name, &property_depthBiasClamp_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_depthBiasClamp_name);

	zval property_fillModeNonSolid_default_value;
	ZVAL_FALSE(&property_fillModeNonSolid_default_value);
	zend_string *property_fillModeNonSolid_name = zend_string_init("fillModeNonSolid", sizeof("fillModeNonSolid") - 1, 1);
	zend_declare_typed_property(class_entry, property_fillModeNonSolid_name, &property_fillModeNonSolid_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_fillModeNonSolid_name);

	zval property_depthBounds_default_value;
	ZVAL_FALSE(&property_depthBounds_default_value);
	zend_string *property_depthBounds_name = zend_string_init("depthBounds", sizeof("depthBounds") - 1, 1);
	zend_declare_typed_property(class_entry, property_depthBounds_name, &property_depthBounds_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_depthBounds_name);

	zval property_wideLines_default_value;
	ZVAL_FALSE(&property_wideLines_default_value);
	zend_string *property_wideLines_name = zend_string_init("wideLines", sizeof("wideLines") - 1, 1);
	zend_declare_typed_property(class_entry, property_wideLines_name, &property_wideLines_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_wideLines_name);

	zval property_largePoints_default_value;
	ZVAL_FALSE(&property_largePoints_default_value);
	zend_string *property_largePoints_name = zend_string_init("largePoints", sizeof("largePoints") - 1, 1);
	zend_declare_typed_property(class_entry, property_largePoints_name, &property_largePoints_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_largePoints_name);

	zval property_alphaToOne_default_value;
	ZVAL_FALSE(&property_alphaToOne_default_value);
	zend_string *property_alphaToOne_name = zend_string_init("alphaToOne", sizeof("alphaToOne") - 1, 1);
	zend_declare_typed_property(class_entry, property_alphaToOne_name, &property_alphaToOne_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_alphaToOne_name);

	zval property_multiViewport_default_value;
	ZVAL_FALSE(&property_multiViewport_default_value);
	zend_string *property_multiViewport_name = zend_string_init("multiViewport", sizeof("multiViewport") - 1, 1);
	zend_declare_typed_property(class_entry, property_multiViewport_name, &property_multiViewport_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_multiViewport_name);

	zval property_samplerAnisotropy_default_value;
	ZVAL_FALSE(&property_samplerAnisotropy_default_value);
	zend_string *property_samplerAnisotropy_name = zend_string_init("samplerAnisotropy", sizeof("samplerAnisotropy") - 1, 1);
	zend_declare_typed_property(class_entry, property_samplerAnisotropy_name, &property_samplerAnisotropy_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_samplerAnisotropy_name);

	zval property_textureCompressionETC2_default_value;
	ZVAL_FALSE(&property_textureCompressionETC2_default_value);
	zend_string *property_textureCompressionETC2_name = zend_string_init("textureCompressionETC2", sizeof("textureCompressionETC2") - 1, 1);
	zend_declare_typed_property(class_entry, property_textureCompressionETC2_name, &property_textureCompressionETC2_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_textureCompressionETC2_name);

	zval property_textureCompressionASTC_LDR_default_value;
	ZVAL_FALSE(&property_textureCompressionASTC_LDR_default_value);
	zend_string *property_textureCompressionASTC_LDR_name = zend_string_init("textureCompressionASTC_LDR", sizeof("textureCompressionASTC_LDR") - 1, 1);
	zend_declare_typed_property(class_entry, property_textureCompressionASTC_LDR_name, &property_textureCompressionASTC_LDR_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_textureCompressionASTC_LDR_name);

	zval property_textureCompressionBC_default_value;
	ZVAL_FALSE(&property_textureCompressionBC_default_value);
	zend_string *property_textureCompressionBC_name = zend_string_init("textureCompressionBC", sizeof("textureCompressionBC") - 1, 1);
	zend_declare_typed_property(class_entry, property_textureCompressionBC_name, &property_textureCompressionBC_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_textureCompressionBC_name);

	zval property_occlusionQueryPrecise_default_value;
	ZVAL_FALSE(&property_occlusionQueryPrecise_default_value);
	zend_string *property_occlusionQueryPrecise_name = zend_string_init("occlusionQueryPrecise", sizeof("occlusionQueryPrecise") - 1, 1);
	zend_declare_typed_property(class_entry, property_occlusionQueryPrecise_name, &property_occlusionQueryPrecise_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_occlusionQueryPrecise_name);

	zval property_pipelineStatisticsQuery_default_value;
	ZVAL_FALSE(&property_pipelineStatisticsQuery_default_value);
	zend_string *property_pipelineStatisticsQuery_name = zend_string_init("pipelineStatisticsQuery", sizeof("pipelineStatisticsQuery") - 1, 1);
	zend_declare_typed_property(class_entry, property_pipelineStatisticsQuery_name, &property_pipelineStatisticsQuery_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_pipelineStatisticsQuery_name);

	zval property_vertexPipelineStoresAndAtomics_default_value;
	ZVAL_FALSE(&property_vertexPipelineStoresAndAtomics_default_value);
	zend_string *property_vertexPipelineStoresAndAtomics_name = zend_string_init("vertexPipelineStoresAndAtomics", sizeof("vertexPipelineStoresAndAtomics") - 1, 1);
	zend_declare_typed_property(class_entry, property_vertexPipelineStoresAndAtomics_name, &property_vertexPipelineStoresAndAtomics_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_vertexPipelineStoresAndAtomics_name);

	zval property_fragmentStoresAndAtomics_default_value;
	ZVAL_FALSE(&property_fragmentStoresAndAtomics_default_value);
	zend_string *property_fragmentStoresAndAtomics_name = zend_string_init("fragmentStoresAndAtomics", sizeof("fragmentStoresAndAtomics") - 1, 1);
	zend_declare_typed_property(class_entry, property_fragmentStoresAndAtomics_name, &property_fragmentStoresAndAtomics_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_fragmentStoresAndAtomics_name);

	zval property_shaderTessellationAndGeometryPointSize_default_value;
	ZVAL_FALSE(&property_shaderTessellationAndGeometryPointSize_default_value);
	zend_string *property_shaderTessellationAndGeometryPointSize_name = zend_string_init("shaderTessellationAndGeometryPointSize", sizeof("shaderTessellationAndGeometryPointSize") - 1, 1);
	zend_declare_typed_property(class_entry, property_shaderTessellationAndGeometryPointSize_name, &property_shaderTessellationAndGeometryPointSize_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_shaderTessellationAndGeometryPointSize_name);

	zval property_shaderImageGatherExtended_default_value;
	ZVAL_FALSE(&property_shaderImageGatherExtended_default_value);
	zend_string *property_shaderImageGatherExtended_name = zend_string_init("shaderImageGatherExtended", sizeof("shaderImageGatherExtended") - 1, 1);
	zend_declare_typed_property(class_entry, property_shaderImageGatherExtended_name, &property_shaderImageGatherExtended_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_shaderImageGatherExtended_name);

	zval property_shaderStorageImageExtendedFormats_default_value;
	ZVAL_FALSE(&property_shaderStorageImageExtendedFormats_default_value);
	zend_string *property_shaderStorageImageExtendedFormats_name = zend_string_init("shaderStorageImageExtendedFormats", sizeof("shaderStorageImageExtendedFormats") - 1, 1);
	zend_declare_typed_property(class_entry, property_shaderStorageImageExtendedFormats_name, &property_shaderStorageImageExtendedFormats_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_shaderStorageImageExtendedFormats_name);

	zval property_shaderStorageImageMultisample_default_value;
	ZVAL_FALSE(&property_shaderStorageImageMultisample_default_value);
	zend_string *property_shaderStorageImageMultisample_name = zend_string_init("shaderStorageImageMultisample", sizeof("shaderStorageImageMultisample") - 1, 1);
	zend_declare_typed_property(class_entry, property_shaderStorageImageMultisample_name, &property_shaderStorageImageMultisample_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_shaderStorageImageMultisample_name);

	zval property_shaderStorageImageReadWithoutFormat_default_value;
	ZVAL_FALSE(&property_shaderStorageImageReadWithoutFormat_default_value);
	zend_string *property_shaderStorageImageReadWithoutFormat_name = zend_string_init("shaderStorageImageReadWithoutFormat", sizeof("shaderStorageImageReadWithoutFormat") - 1, 1);
	zend_declare_typed_property(class_entry, property_shaderStorageImageReadWithoutFormat_name, &property_shaderStorageImageReadWithoutFormat_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_shaderStorageImageReadWithoutFormat_name);

	zval property_shaderStorageImageWriteWithoutFormat_default_value;
	ZVAL_FALSE(&property_shaderStorageImageWriteWithoutFormat_default_value);
	zend_string *property_shaderStorageImageWriteWithoutFormat_name = zend_string_init("shaderStorageImageWriteWithoutFormat", sizeof("shaderStorageImageWriteWithoutFormat") - 1, 1);
	zend_declare_typed_property(class_entry, property_shaderStorageImageWriteWithoutFormat_name, &property_shaderStorageImageWriteWithoutFormat_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_shaderStorageImageWriteWithoutFormat_name);

	zval property_shaderUniformBufferArrayDynamicIndexing_default_value;
	ZVAL_FALSE(&property_shaderUniformBufferArrayDynamicIndexing_default_value);
	zend_string *property_shaderUniformBufferArrayDynamicIndexing_name = zend_string_init("shaderUniformBufferArrayDynamicIndexing", sizeof("shaderUniformBufferArrayDynamicIndexing") - 1, 1);
	zend_declare_typed_property(class_entry, property_shaderUniformBufferArrayDynamicIndexing_name, &property_shaderUniformBufferArrayDynamicIndexing_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_shaderUniformBufferArrayDynamicIndexing_name);

	zval property_shaderSampledImageArrayDynamicIndexing_default_value;
	ZVAL_FALSE(&property_shaderSampledImageArrayDynamicIndexing_default_value);
	zend_string *property_shaderSampledImageArrayDynamicIndexing_name = zend_string_init("shaderSampledImageArrayDynamicIndexing", sizeof("shaderSampledImageArrayDynamicIndexing") - 1, 1);
	zend_declare_typed_property(class_entry, property_shaderSampledImageArrayDynamicIndexing_name, &property_shaderSampledImageArrayDynamicIndexing_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_shaderSampledImageArrayDynamicIndexing_name);

	zval property_shaderStorageBufferArrayDynamicIndexing_default_value;
	ZVAL_FALSE(&property_shaderStorageBufferArrayDynamicIndexing_default_value);
	zend_string *property_shaderStorageBufferArrayDynamicIndexing_name = zend_string_init("shaderStorageBufferArrayDynamicIndexing", sizeof("shaderStorageBufferArrayDynamicIndexing") - 1, 1);
	zend_declare_typed_property(class_entry, property_shaderStorageBufferArrayDynamicIndexing_name, &property_shaderStorageBufferArrayDynamicIndexing_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_shaderStorageBufferArrayDynamicIndexing_name);

	zval property_shaderStorageImageArrayDynamicIndexing_default_value;
	ZVAL_FALSE(&property_shaderStorageImageArrayDynamicIndexing_default_value);
	zend_string *property_shaderStorageImageArrayDynamicIndexing_name = zend_string_init("shaderStorageImageArrayDynamicIndexing", sizeof("shaderStorageImageArrayDynamicIndexing") - 1, 1);
	zend_declare_typed_property(class_entry, property_shaderStorageImageArrayDynamicIndexing_name, &property_shaderStorageImageArrayDynamicIndexing_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_shaderStorageImageArrayDynamicIndexing_name);

	zval property_shaderClipDistance_default_value;
	ZVAL_FALSE(&property_shaderClipDistance_default_value);
	zend_string *property_shaderClipDistance_name = zend_string_init("shaderClipDistance", sizeof("shaderClipDistance") - 1, 1);
	zend_declare_typed_property(class_entry, property_shaderClipDistance_name, &property_shaderClipDistance_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_shaderClipDistance_name);

	zval property_shaderCullDistance_default_value;
	ZVAL_FALSE(&property_shaderCullDistance_default_value);
	zend_string *property_shaderCullDistance_name = zend_string_init("shaderCullDistance", sizeof("shaderCullDistance") - 1, 1);
	zend_declare_typed_property(class_entry, property_shaderCullDistance_name, &property_shaderCullDistance_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_shaderCullDistance_name);

	zval property_shaderFloat64_default_value;
	ZVAL_FALSE(&property_shaderFloat64_default_value);
	zend_string *property_shaderFloat64_name = zend_string_init("shaderFloat64", sizeof("shaderFloat64") - 1, 1);
	zend_declare_typed_property(class_entry, property_shaderFloat64_name, &property_shaderFloat64_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_shaderFloat64_name);

	zval property_shaderInt64_default_value;
	ZVAL_FALSE(&property_shaderInt64_default_value);
	zend_string *property_shaderInt64_name = zend_string_init("shaderInt64", sizeof("shaderInt64") - 1, 1);
	zend_declare_typed_property(class_entry, property_shaderInt64_name, &property_shaderInt64_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_shaderInt64_name);

	zval property_shaderInt16_default_value;
	ZVAL_FALSE(&property_shaderInt16_default_value);
	zend_string *property_shaderInt16_name = zend_string_init("shaderInt16", sizeof("shaderInt16") - 1, 1);
	zend_declare_typed_property(class_entry, property_shaderInt16_name, &property_shaderInt16_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_shaderInt16_name);

	zval property_shaderResourceResidency_default_value;
	ZVAL_FALSE(&property_shaderResourceResidency_default_value);
	zend_string *property_shaderResourceResidency_name = zend_string_init("shaderResourceResidency", sizeof("shaderResourceResidency") - 1, 1);
	zend_declare_typed_property(class_entry, property_shaderResourceResidency_name, &property_shaderResourceResidency_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_shaderResourceResidency_name);

	zval property_shaderResourceMinLod_default_value;
	ZVAL_FALSE(&property_shaderResourceMinLod_default_value);
	zend_string *property_shaderResourceMinLod_name = zend_string_init("shaderResourceMinLod", sizeof("shaderResourceMinLod") - 1, 1);
	zend_declare_typed_property(class_entry, property_shaderResourceMinLod_name, &property_shaderResourceMinLod_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_shaderResourceMinLod_name);

	zval property_sparseBinding_default_value;
	ZVAL_FALSE(&property_sparseBinding_default_value);
	zend_string *property_sparseBinding_name = zend_string_init("sparseBinding", sizeof("sparseBinding") - 1, 1);
	zend_declare_typed_property(class_entry, property_sparseBinding_name, &property_sparseBinding_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_sparseBinding_name);

	zval property_sparseResidencyBuffer_default_value;
	ZVAL_FALSE(&property_sparseResidencyBuffer_default_value);
	zend_string *property_sparseResidencyBuffer_name = zend_string_init("sparseResidencyBuffer", sizeof("sparseResidencyBuffer") - 1, 1);
	zend_declare_typed_property(class_entry, property_sparseResidencyBuffer_name, &property_sparseResidencyBuffer_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_sparseResidencyBuffer_name);

	zval property_sparseResidencyImage2D_default_value;
	ZVAL_FALSE(&property_sparseResidencyImage2D_default_value);
	zend_string *property_sparseResidencyImage2D_name = zend_string_init("sparseResidencyImage2D", sizeof("sparseResidencyImage2D") - 1, 1);
	zend_declare_typed_property(class_entry, property_sparseResidencyImage2D_name, &property_sparseResidencyImage2D_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_sparseResidencyImage2D_name);

	zval property_sparseResidencyImage3D_default_value;
	ZVAL_FALSE(&property_sparseResidencyImage3D_default_value);
	zend_string *property_sparseResidencyImage3D_name = zend_string_init("sparseResidencyImage3D", sizeof("sparseResidencyImage3D") - 1, 1);
	zend_declare_typed_property(class_entry, property_sparseResidencyImage3D_name, &property_sparseResidencyImage3D_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_sparseResidencyImage3D_name);

	zval property_sparseResidency2Samples_default_value;
	ZVAL_FALSE(&property_sparseResidency2Samples_default_value);
	zend_string *property_sparseResidency2Samples_name = zend_string_init("sparseResidency2Samples", sizeof("sparseResidency2Samples") - 1, 1);
	zend_declare_typed_property(class_entry, property_sparseResidency2Samples_name, &property_sparseResidency2Samples_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_sparseResidency2Samples_name);

	zval property_sparseResidency4Samples_default_value;
	ZVAL_FALSE(&property_sparseResidency4Samples_default_value);
	zend_string *property_sparseResidency4Samples_name = zend_string_init("sparseResidency4Samples", sizeof("sparseResidency4Samples") - 1, 1);
	zend_declare_typed_property(class_entry, property_sparseResidency4Samples_name, &property_sparseResidency4Samples_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_sparseResidency4Samples_name);

	zval property_sparseResidency8Samples_default_value;
	ZVAL_FALSE(&property_sparseResidency8Samples_default_value);
	zend_string *property_sparseResidency8Samples_name = zend_string_init("sparseResidency8Samples", sizeof("sparseResidency8Samples") - 1, 1);
	zend_declare_typed_property(class_entry, property_sparseResidency8Samples_name, &property_sparseResidency8Samples_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_sparseResidency8Samples_name);

	zval property_sparseResidency16Samples_default_value;
	ZVAL_FALSE(&property_sparseResidency16Samples_default_value);
	zend_string *property_sparseResidency16Samples_name = zend_string_init("sparseResidency16Samples", sizeof("sparseResidency16Samples") - 1, 1);
	zend_declare_typed_property(class_entry, property_sparseResidency16Samples_name, &property_sparseResidency16Samples_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_sparseResidency16Samples_name);

	zval property_sparseResidencyAliased_default_value;
	ZVAL_FALSE(&property_sparseResidencyAliased_default_value);
	zend_string *property_sparseResidencyAliased_name = zend_string_init("sparseResidencyAliased", sizeof("sparseResidencyAliased") - 1, 1);
	zend_declare_typed_property(class_entry, property_sparseResidencyAliased_name, &property_sparseResidencyAliased_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_sparseResidencyAliased_name);

	zval property_variableMultisampleRate_default_value;
	ZVAL_FALSE(&property_variableMultisampleRate_default_value);
	zend_string *property_variableMultisampleRate_name = zend_string_init("variableMultisampleRate", sizeof("variableMultisampleRate") - 1, 1);
	zend_declare_typed_property(class_entry, property_variableMultisampleRate_name, &property_variableMultisampleRate_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_variableMultisampleRate_name);

	zval property_inheritedQueries_default_value;
	ZVAL_FALSE(&property_inheritedQueries_default_value);
	zend_string *property_inheritedQueries_name = zend_string_init("inheritedQueries", sizeof("inheritedQueries") - 1, 1);
	zend_declare_typed_property(class_entry, property_inheritedQueries_name, &property_inheritedQueries_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_inheritedQueries_name);

	return class_entry;
}

static zend_class_entry *register_class_VkDeviceCreateInfo(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkDeviceCreateInfo", NULL);
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

	zval property_pQueueCreateInfos_default_value;
	ZVAL_EMPTY_ARRAY(&property_pQueueCreateInfos_default_value);
	zend_string *property_pQueueCreateInfos_name = zend_string_init("pQueueCreateInfos", sizeof("pQueueCreateInfos") - 1, 1);
	zend_declare_typed_property(class_entry, property_pQueueCreateInfos_name, &property_pQueueCreateInfos_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_pQueueCreateInfos_name);

	zval property_enabledLayerCount_default_value;
	ZVAL_LONG(&property_enabledLayerCount_default_value, 0);
	zend_string *property_enabledLayerCount_name = zend_string_init("enabledLayerCount", sizeof("enabledLayerCount") - 1, 1);
	zend_declare_typed_property(class_entry, property_enabledLayerCount_name, &property_enabledLayerCount_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_enabledLayerCount_name);

	zval property_enabledLayerNames_default_value;
	ZVAL_EMPTY_ARRAY(&property_enabledLayerNames_default_value);
	zend_string *property_enabledLayerNames_name = zend_string_init("enabledLayerNames", sizeof("enabledLayerNames") - 1, 1);
	zend_declare_typed_property(class_entry, property_enabledLayerNames_name, &property_enabledLayerNames_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_enabledLayerNames_name);

	zval property_enabledExtensionCount_default_value;
	ZVAL_LONG(&property_enabledExtensionCount_default_value, 0);
	zend_string *property_enabledExtensionCount_name = zend_string_init("enabledExtensionCount", sizeof("enabledExtensionCount") - 1, 1);
	zend_declare_typed_property(class_entry, property_enabledExtensionCount_name, &property_enabledExtensionCount_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_enabledExtensionCount_name);

	zval property_enabledExtensionNames_default_value;
	ZVAL_EMPTY_ARRAY(&property_enabledExtensionNames_default_value);
	zend_string *property_enabledExtensionNames_name = zend_string_init("enabledExtensionNames", sizeof("enabledExtensionNames") - 1, 1);
	zend_declare_typed_property(class_entry, property_enabledExtensionNames_name, &property_enabledExtensionNames_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_enabledExtensionNames_name);

	zval property_pEnabledFeatures_default_value;
	ZVAL_NULL(&property_pEnabledFeatures_default_value);
	zend_string *property_pEnabledFeatures_name = zend_string_init("pEnabledFeatures", sizeof("pEnabledFeatures") - 1, 1);
	zend_string *property_pEnabledFeatures_class_VkPhysicalDeviceFeatures = zend_string_init("VkPhysicalDeviceFeatures", sizeof("VkPhysicalDeviceFeatures")-1, 1);
	zend_declare_typed_property(class_entry, property_pEnabledFeatures_name, &property_pEnabledFeatures_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_pEnabledFeatures_class_VkPhysicalDeviceFeatures, 0, MAY_BE_NULL));
	zend_string_release(property_pEnabledFeatures_name);

	return class_entry;
}

static zend_class_entry *register_class_VkPhysicalDeviceLimits(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkPhysicalDeviceLimits", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_maxImageDimension1D_default_value;
	ZVAL_LONG(&property_maxImageDimension1D_default_value, 0);
	zend_string *property_maxImageDimension1D_name = zend_string_init("maxImageDimension1D", sizeof("maxImageDimension1D") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxImageDimension1D_name, &property_maxImageDimension1D_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxImageDimension1D_name);

	zval property_maxImageDimension2D_default_value;
	ZVAL_LONG(&property_maxImageDimension2D_default_value, 0);
	zend_string *property_maxImageDimension2D_name = zend_string_init("maxImageDimension2D", sizeof("maxImageDimension2D") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxImageDimension2D_name, &property_maxImageDimension2D_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxImageDimension2D_name);

	zval property_maxImageDimension3D_default_value;
	ZVAL_LONG(&property_maxImageDimension3D_default_value, 0);
	zend_string *property_maxImageDimension3D_name = zend_string_init("maxImageDimension3D", sizeof("maxImageDimension3D") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxImageDimension3D_name, &property_maxImageDimension3D_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxImageDimension3D_name);

	zval property_maxImageDimensionCube_default_value;
	ZVAL_LONG(&property_maxImageDimensionCube_default_value, 0);
	zend_string *property_maxImageDimensionCube_name = zend_string_init("maxImageDimensionCube", sizeof("maxImageDimensionCube") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxImageDimensionCube_name, &property_maxImageDimensionCube_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxImageDimensionCube_name);

	zval property_maxImageArrayLayers_default_value;
	ZVAL_LONG(&property_maxImageArrayLayers_default_value, 0);
	zend_string *property_maxImageArrayLayers_name = zend_string_init("maxImageArrayLayers", sizeof("maxImageArrayLayers") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxImageArrayLayers_name, &property_maxImageArrayLayers_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxImageArrayLayers_name);

	zval property_maxTexelBufferElements_default_value;
	ZVAL_LONG(&property_maxTexelBufferElements_default_value, 0);
	zend_string *property_maxTexelBufferElements_name = zend_string_init("maxTexelBufferElements", sizeof("maxTexelBufferElements") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxTexelBufferElements_name, &property_maxTexelBufferElements_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxTexelBufferElements_name);

	zval property_maxUniformBufferRange_default_value;
	ZVAL_LONG(&property_maxUniformBufferRange_default_value, 0);
	zend_string *property_maxUniformBufferRange_name = zend_string_init("maxUniformBufferRange", sizeof("maxUniformBufferRange") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxUniformBufferRange_name, &property_maxUniformBufferRange_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxUniformBufferRange_name);

	zval property_maxStorageBufferRange_default_value;
	ZVAL_LONG(&property_maxStorageBufferRange_default_value, 0);
	zend_string *property_maxStorageBufferRange_name = zend_string_init("maxStorageBufferRange", sizeof("maxStorageBufferRange") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxStorageBufferRange_name, &property_maxStorageBufferRange_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxStorageBufferRange_name);

	zval property_maxPushConstantsSize_default_value;
	ZVAL_LONG(&property_maxPushConstantsSize_default_value, 0);
	zend_string *property_maxPushConstantsSize_name = zend_string_init("maxPushConstantsSize", sizeof("maxPushConstantsSize") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxPushConstantsSize_name, &property_maxPushConstantsSize_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxPushConstantsSize_name);

	zval property_maxMemoryAllocationCount_default_value;
	ZVAL_LONG(&property_maxMemoryAllocationCount_default_value, 0);
	zend_string *property_maxMemoryAllocationCount_name = zend_string_init("maxMemoryAllocationCount", sizeof("maxMemoryAllocationCount") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxMemoryAllocationCount_name, &property_maxMemoryAllocationCount_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxMemoryAllocationCount_name);

	zval property_maxSamplerAllocationCount_default_value;
	ZVAL_LONG(&property_maxSamplerAllocationCount_default_value, 0);
	zend_string *property_maxSamplerAllocationCount_name = zend_string_init("maxSamplerAllocationCount", sizeof("maxSamplerAllocationCount") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxSamplerAllocationCount_name, &property_maxSamplerAllocationCount_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxSamplerAllocationCount_name);

	zval property_bufferImageGranularity_default_value;
	ZVAL_LONG(&property_bufferImageGranularity_default_value, 0);
	zend_string *property_bufferImageGranularity_name = zend_string_init("bufferImageGranularity", sizeof("bufferImageGranularity") - 1, 1);
	zend_declare_typed_property(class_entry, property_bufferImageGranularity_name, &property_bufferImageGranularity_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_bufferImageGranularity_name);

	zval property_sparseAddressSpaceSize_default_value;
	ZVAL_LONG(&property_sparseAddressSpaceSize_default_value, 0);
	zend_string *property_sparseAddressSpaceSize_name = zend_string_init("sparseAddressSpaceSize", sizeof("sparseAddressSpaceSize") - 1, 1);
	zend_declare_typed_property(class_entry, property_sparseAddressSpaceSize_name, &property_sparseAddressSpaceSize_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_sparseAddressSpaceSize_name);

	zval property_maxBoundDescriptorSets_default_value;
	ZVAL_LONG(&property_maxBoundDescriptorSets_default_value, 0);
	zend_string *property_maxBoundDescriptorSets_name = zend_string_init("maxBoundDescriptorSets", sizeof("maxBoundDescriptorSets") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxBoundDescriptorSets_name, &property_maxBoundDescriptorSets_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxBoundDescriptorSets_name);

	zval property_maxPerStageDescriptorSamplers_default_value;
	ZVAL_LONG(&property_maxPerStageDescriptorSamplers_default_value, 0);
	zend_string *property_maxPerStageDescriptorSamplers_name = zend_string_init("maxPerStageDescriptorSamplers", sizeof("maxPerStageDescriptorSamplers") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxPerStageDescriptorSamplers_name, &property_maxPerStageDescriptorSamplers_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxPerStageDescriptorSamplers_name);

	zval property_maxPerStageDescriptorUniformBuffers_default_value;
	ZVAL_LONG(&property_maxPerStageDescriptorUniformBuffers_default_value, 0);
	zend_string *property_maxPerStageDescriptorUniformBuffers_name = zend_string_init("maxPerStageDescriptorUniformBuffers", sizeof("maxPerStageDescriptorUniformBuffers") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxPerStageDescriptorUniformBuffers_name, &property_maxPerStageDescriptorUniformBuffers_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxPerStageDescriptorUniformBuffers_name);

	zval property_maxPerStageDescriptorStorageBuffers_default_value;
	ZVAL_LONG(&property_maxPerStageDescriptorStorageBuffers_default_value, 0);
	zend_string *property_maxPerStageDescriptorStorageBuffers_name = zend_string_init("maxPerStageDescriptorStorageBuffers", sizeof("maxPerStageDescriptorStorageBuffers") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxPerStageDescriptorStorageBuffers_name, &property_maxPerStageDescriptorStorageBuffers_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxPerStageDescriptorStorageBuffers_name);

	zval property_maxPerStageDescriptorSampledImages_default_value;
	ZVAL_LONG(&property_maxPerStageDescriptorSampledImages_default_value, 0);
	zend_string *property_maxPerStageDescriptorSampledImages_name = zend_string_init("maxPerStageDescriptorSampledImages", sizeof("maxPerStageDescriptorSampledImages") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxPerStageDescriptorSampledImages_name, &property_maxPerStageDescriptorSampledImages_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxPerStageDescriptorSampledImages_name);

	zval property_maxPerStageDescriptorStorageImages_default_value;
	ZVAL_LONG(&property_maxPerStageDescriptorStorageImages_default_value, 0);
	zend_string *property_maxPerStageDescriptorStorageImages_name = zend_string_init("maxPerStageDescriptorStorageImages", sizeof("maxPerStageDescriptorStorageImages") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxPerStageDescriptorStorageImages_name, &property_maxPerStageDescriptorStorageImages_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxPerStageDescriptorStorageImages_name);

	zval property_maxPerStageDescriptorInputAttachments_default_value;
	ZVAL_LONG(&property_maxPerStageDescriptorInputAttachments_default_value, 0);
	zend_string *property_maxPerStageDescriptorInputAttachments_name = zend_string_init("maxPerStageDescriptorInputAttachments", sizeof("maxPerStageDescriptorInputAttachments") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxPerStageDescriptorInputAttachments_name, &property_maxPerStageDescriptorInputAttachments_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxPerStageDescriptorInputAttachments_name);

	zval property_maxPerStageResources_default_value;
	ZVAL_LONG(&property_maxPerStageResources_default_value, 0);
	zend_string *property_maxPerStageResources_name = zend_string_init("maxPerStageResources", sizeof("maxPerStageResources") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxPerStageResources_name, &property_maxPerStageResources_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxPerStageResources_name);

	zval property_maxDescriptorSetSamplers_default_value;
	ZVAL_LONG(&property_maxDescriptorSetSamplers_default_value, 0);
	zend_string *property_maxDescriptorSetSamplers_name = zend_string_init("maxDescriptorSetSamplers", sizeof("maxDescriptorSetSamplers") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxDescriptorSetSamplers_name, &property_maxDescriptorSetSamplers_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxDescriptorSetSamplers_name);

	zval property_maxDescriptorSetUniformBuffers_default_value;
	ZVAL_LONG(&property_maxDescriptorSetUniformBuffers_default_value, 0);
	zend_string *property_maxDescriptorSetUniformBuffers_name = zend_string_init("maxDescriptorSetUniformBuffers", sizeof("maxDescriptorSetUniformBuffers") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxDescriptorSetUniformBuffers_name, &property_maxDescriptorSetUniformBuffers_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxDescriptorSetUniformBuffers_name);

	zval property_maxDescriptorSetUniformBuffersDynamic_default_value;
	ZVAL_LONG(&property_maxDescriptorSetUniformBuffersDynamic_default_value, 0);
	zend_string *property_maxDescriptorSetUniformBuffersDynamic_name = zend_string_init("maxDescriptorSetUniformBuffersDynamic", sizeof("maxDescriptorSetUniformBuffersDynamic") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxDescriptorSetUniformBuffersDynamic_name, &property_maxDescriptorSetUniformBuffersDynamic_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxDescriptorSetUniformBuffersDynamic_name);

	zval property_maxDescriptorSetStorageBuffers_default_value;
	ZVAL_LONG(&property_maxDescriptorSetStorageBuffers_default_value, 0);
	zend_string *property_maxDescriptorSetStorageBuffers_name = zend_string_init("maxDescriptorSetStorageBuffers", sizeof("maxDescriptorSetStorageBuffers") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxDescriptorSetStorageBuffers_name, &property_maxDescriptorSetStorageBuffers_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxDescriptorSetStorageBuffers_name);

	zval property_maxDescriptorSetStorageBuffersDynamic_default_value;
	ZVAL_LONG(&property_maxDescriptorSetStorageBuffersDynamic_default_value, 0);
	zend_string *property_maxDescriptorSetStorageBuffersDynamic_name = zend_string_init("maxDescriptorSetStorageBuffersDynamic", sizeof("maxDescriptorSetStorageBuffersDynamic") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxDescriptorSetStorageBuffersDynamic_name, &property_maxDescriptorSetStorageBuffersDynamic_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxDescriptorSetStorageBuffersDynamic_name);

	zval property_maxDescriptorSetSampledImages_default_value;
	ZVAL_LONG(&property_maxDescriptorSetSampledImages_default_value, 0);
	zend_string *property_maxDescriptorSetSampledImages_name = zend_string_init("maxDescriptorSetSampledImages", sizeof("maxDescriptorSetSampledImages") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxDescriptorSetSampledImages_name, &property_maxDescriptorSetSampledImages_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxDescriptorSetSampledImages_name);

	zval property_maxDescriptorSetStorageImages_default_value;
	ZVAL_LONG(&property_maxDescriptorSetStorageImages_default_value, 0);
	zend_string *property_maxDescriptorSetStorageImages_name = zend_string_init("maxDescriptorSetStorageImages", sizeof("maxDescriptorSetStorageImages") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxDescriptorSetStorageImages_name, &property_maxDescriptorSetStorageImages_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxDescriptorSetStorageImages_name);

	zval property_maxDescriptorSetInputAttachments_default_value;
	ZVAL_LONG(&property_maxDescriptorSetInputAttachments_default_value, 0);
	zend_string *property_maxDescriptorSetInputAttachments_name = zend_string_init("maxDescriptorSetInputAttachments", sizeof("maxDescriptorSetInputAttachments") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxDescriptorSetInputAttachments_name, &property_maxDescriptorSetInputAttachments_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxDescriptorSetInputAttachments_name);

	zval property_maxVertexInputAttributes_default_value;
	ZVAL_LONG(&property_maxVertexInputAttributes_default_value, 0);
	zend_string *property_maxVertexInputAttributes_name = zend_string_init("maxVertexInputAttributes", sizeof("maxVertexInputAttributes") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxVertexInputAttributes_name, &property_maxVertexInputAttributes_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxVertexInputAttributes_name);

	zval property_maxVertexInputBindings_default_value;
	ZVAL_LONG(&property_maxVertexInputBindings_default_value, 0);
	zend_string *property_maxVertexInputBindings_name = zend_string_init("maxVertexInputBindings", sizeof("maxVertexInputBindings") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxVertexInputBindings_name, &property_maxVertexInputBindings_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxVertexInputBindings_name);

	zval property_maxVertexInputAttributeOffset_default_value;
	ZVAL_LONG(&property_maxVertexInputAttributeOffset_default_value, 0);
	zend_string *property_maxVertexInputAttributeOffset_name = zend_string_init("maxVertexInputAttributeOffset", sizeof("maxVertexInputAttributeOffset") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxVertexInputAttributeOffset_name, &property_maxVertexInputAttributeOffset_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxVertexInputAttributeOffset_name);

	zval property_maxVertexInputBindingStride_default_value;
	ZVAL_LONG(&property_maxVertexInputBindingStride_default_value, 0);
	zend_string *property_maxVertexInputBindingStride_name = zend_string_init("maxVertexInputBindingStride", sizeof("maxVertexInputBindingStride") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxVertexInputBindingStride_name, &property_maxVertexInputBindingStride_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxVertexInputBindingStride_name);

	zval property_maxVertexOutputComponents_default_value;
	ZVAL_LONG(&property_maxVertexOutputComponents_default_value, 0);
	zend_string *property_maxVertexOutputComponents_name = zend_string_init("maxVertexOutputComponents", sizeof("maxVertexOutputComponents") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxVertexOutputComponents_name, &property_maxVertexOutputComponents_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxVertexOutputComponents_name);

	zval property_maxTessellationGenerationLevel_default_value;
	ZVAL_LONG(&property_maxTessellationGenerationLevel_default_value, 0);
	zend_string *property_maxTessellationGenerationLevel_name = zend_string_init("maxTessellationGenerationLevel", sizeof("maxTessellationGenerationLevel") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxTessellationGenerationLevel_name, &property_maxTessellationGenerationLevel_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxTessellationGenerationLevel_name);

	zval property_maxTessellationPatchSize_default_value;
	ZVAL_LONG(&property_maxTessellationPatchSize_default_value, 0);
	zend_string *property_maxTessellationPatchSize_name = zend_string_init("maxTessellationPatchSize", sizeof("maxTessellationPatchSize") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxTessellationPatchSize_name, &property_maxTessellationPatchSize_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxTessellationPatchSize_name);

	zval property_maxTessellationControlPerVertexInputComponents_default_value;
	ZVAL_LONG(&property_maxTessellationControlPerVertexInputComponents_default_value, 0);
	zend_string *property_maxTessellationControlPerVertexInputComponents_name = zend_string_init("maxTessellationControlPerVertexInputComponents", sizeof("maxTessellationControlPerVertexInputComponents") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxTessellationControlPerVertexInputComponents_name, &property_maxTessellationControlPerVertexInputComponents_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxTessellationControlPerVertexInputComponents_name);

	zval property_maxTessellationControlPerVertexOutputComponents_default_value;
	ZVAL_LONG(&property_maxTessellationControlPerVertexOutputComponents_default_value, 0);
	zend_string *property_maxTessellationControlPerVertexOutputComponents_name = zend_string_init("maxTessellationControlPerVertexOutputComponents", sizeof("maxTessellationControlPerVertexOutputComponents") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxTessellationControlPerVertexOutputComponents_name, &property_maxTessellationControlPerVertexOutputComponents_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxTessellationControlPerVertexOutputComponents_name);

	zval property_maxTessellationControlPerPatchOutputComponents_default_value;
	ZVAL_LONG(&property_maxTessellationControlPerPatchOutputComponents_default_value, 0);
	zend_string *property_maxTessellationControlPerPatchOutputComponents_name = zend_string_init("maxTessellationControlPerPatchOutputComponents", sizeof("maxTessellationControlPerPatchOutputComponents") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxTessellationControlPerPatchOutputComponents_name, &property_maxTessellationControlPerPatchOutputComponents_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxTessellationControlPerPatchOutputComponents_name);

	zval property_maxTessellationControlTotalOutputComponents_default_value;
	ZVAL_LONG(&property_maxTessellationControlTotalOutputComponents_default_value, 0);
	zend_string *property_maxTessellationControlTotalOutputComponents_name = zend_string_init("maxTessellationControlTotalOutputComponents", sizeof("maxTessellationControlTotalOutputComponents") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxTessellationControlTotalOutputComponents_name, &property_maxTessellationControlTotalOutputComponents_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxTessellationControlTotalOutputComponents_name);

	zval property_maxTessellationEvaluationInputComponents_default_value;
	ZVAL_LONG(&property_maxTessellationEvaluationInputComponents_default_value, 0);
	zend_string *property_maxTessellationEvaluationInputComponents_name = zend_string_init("maxTessellationEvaluationInputComponents", sizeof("maxTessellationEvaluationInputComponents") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxTessellationEvaluationInputComponents_name, &property_maxTessellationEvaluationInputComponents_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxTessellationEvaluationInputComponents_name);

	zval property_maxTessellationEvaluationOutputComponents_default_value;
	ZVAL_LONG(&property_maxTessellationEvaluationOutputComponents_default_value, 0);
	zend_string *property_maxTessellationEvaluationOutputComponents_name = zend_string_init("maxTessellationEvaluationOutputComponents", sizeof("maxTessellationEvaluationOutputComponents") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxTessellationEvaluationOutputComponents_name, &property_maxTessellationEvaluationOutputComponents_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxTessellationEvaluationOutputComponents_name);

	zval property_maxGeometryShaderInvocations_default_value;
	ZVAL_LONG(&property_maxGeometryShaderInvocations_default_value, 0);
	zend_string *property_maxGeometryShaderInvocations_name = zend_string_init("maxGeometryShaderInvocations", sizeof("maxGeometryShaderInvocations") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxGeometryShaderInvocations_name, &property_maxGeometryShaderInvocations_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxGeometryShaderInvocations_name);

	zval property_maxGeometryInputComponents_default_value;
	ZVAL_LONG(&property_maxGeometryInputComponents_default_value, 0);
	zend_string *property_maxGeometryInputComponents_name = zend_string_init("maxGeometryInputComponents", sizeof("maxGeometryInputComponents") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxGeometryInputComponents_name, &property_maxGeometryInputComponents_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxGeometryInputComponents_name);

	zval property_maxGeometryOutputComponents_default_value;
	ZVAL_LONG(&property_maxGeometryOutputComponents_default_value, 0);
	zend_string *property_maxGeometryOutputComponents_name = zend_string_init("maxGeometryOutputComponents", sizeof("maxGeometryOutputComponents") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxGeometryOutputComponents_name, &property_maxGeometryOutputComponents_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxGeometryOutputComponents_name);

	zval property_maxGeometryOutputVertices_default_value;
	ZVAL_LONG(&property_maxGeometryOutputVertices_default_value, 0);
	zend_string *property_maxGeometryOutputVertices_name = zend_string_init("maxGeometryOutputVertices", sizeof("maxGeometryOutputVertices") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxGeometryOutputVertices_name, &property_maxGeometryOutputVertices_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxGeometryOutputVertices_name);

	zval property_maxGeometryTotalOutputComponents_default_value;
	ZVAL_LONG(&property_maxGeometryTotalOutputComponents_default_value, 0);
	zend_string *property_maxGeometryTotalOutputComponents_name = zend_string_init("maxGeometryTotalOutputComponents", sizeof("maxGeometryTotalOutputComponents") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxGeometryTotalOutputComponents_name, &property_maxGeometryTotalOutputComponents_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxGeometryTotalOutputComponents_name);

	zval property_maxFragmentInputComponents_default_value;
	ZVAL_LONG(&property_maxFragmentInputComponents_default_value, 0);
	zend_string *property_maxFragmentInputComponents_name = zend_string_init("maxFragmentInputComponents", sizeof("maxFragmentInputComponents") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxFragmentInputComponents_name, &property_maxFragmentInputComponents_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxFragmentInputComponents_name);

	zval property_maxFragmentOutputAttachments_default_value;
	ZVAL_LONG(&property_maxFragmentOutputAttachments_default_value, 0);
	zend_string *property_maxFragmentOutputAttachments_name = zend_string_init("maxFragmentOutputAttachments", sizeof("maxFragmentOutputAttachments") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxFragmentOutputAttachments_name, &property_maxFragmentOutputAttachments_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxFragmentOutputAttachments_name);

	zval property_maxFragmentDualSrcAttachments_default_value;
	ZVAL_LONG(&property_maxFragmentDualSrcAttachments_default_value, 0);
	zend_string *property_maxFragmentDualSrcAttachments_name = zend_string_init("maxFragmentDualSrcAttachments", sizeof("maxFragmentDualSrcAttachments") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxFragmentDualSrcAttachments_name, &property_maxFragmentDualSrcAttachments_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxFragmentDualSrcAttachments_name);

	zval property_maxFragmentCombinedOutputResources_default_value;
	ZVAL_LONG(&property_maxFragmentCombinedOutputResources_default_value, 0);
	zend_string *property_maxFragmentCombinedOutputResources_name = zend_string_init("maxFragmentCombinedOutputResources", sizeof("maxFragmentCombinedOutputResources") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxFragmentCombinedOutputResources_name, &property_maxFragmentCombinedOutputResources_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxFragmentCombinedOutputResources_name);

	zval property_maxComputeSharedMemorySize_default_value;
	ZVAL_LONG(&property_maxComputeSharedMemorySize_default_value, 0);
	zend_string *property_maxComputeSharedMemorySize_name = zend_string_init("maxComputeSharedMemorySize", sizeof("maxComputeSharedMemorySize") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxComputeSharedMemorySize_name, &property_maxComputeSharedMemorySize_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxComputeSharedMemorySize_name);

	zval property_maxComputeWorkGroupCount_default_value;
	ZVAL_EMPTY_ARRAY(&property_maxComputeWorkGroupCount_default_value);
	zend_string *property_maxComputeWorkGroupCount_name = zend_string_init("maxComputeWorkGroupCount", sizeof("maxComputeWorkGroupCount") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxComputeWorkGroupCount_name, &property_maxComputeWorkGroupCount_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_maxComputeWorkGroupCount_name);

	zval property_maxComputeWorkGroupInvocations_default_value;
	ZVAL_LONG(&property_maxComputeWorkGroupInvocations_default_value, 0);
	zend_string *property_maxComputeWorkGroupInvocations_name = zend_string_init("maxComputeWorkGroupInvocations", sizeof("maxComputeWorkGroupInvocations") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxComputeWorkGroupInvocations_name, &property_maxComputeWorkGroupInvocations_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxComputeWorkGroupInvocations_name);

	zval property_maxComputeWorkGroupSize_default_value;
	ZVAL_EMPTY_ARRAY(&property_maxComputeWorkGroupSize_default_value);
	zend_string *property_maxComputeWorkGroupSize_name = zend_string_init("maxComputeWorkGroupSize", sizeof("maxComputeWorkGroupSize") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxComputeWorkGroupSize_name, &property_maxComputeWorkGroupSize_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_maxComputeWorkGroupSize_name);

	zval property_subPixelPrecisionBits_default_value;
	ZVAL_LONG(&property_subPixelPrecisionBits_default_value, 0);
	zend_string *property_subPixelPrecisionBits_name = zend_string_init("subPixelPrecisionBits", sizeof("subPixelPrecisionBits") - 1, 1);
	zend_declare_typed_property(class_entry, property_subPixelPrecisionBits_name, &property_subPixelPrecisionBits_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_subPixelPrecisionBits_name);

	zval property_subTexelPrecisionBits_default_value;
	ZVAL_LONG(&property_subTexelPrecisionBits_default_value, 0);
	zend_string *property_subTexelPrecisionBits_name = zend_string_init("subTexelPrecisionBits", sizeof("subTexelPrecisionBits") - 1, 1);
	zend_declare_typed_property(class_entry, property_subTexelPrecisionBits_name, &property_subTexelPrecisionBits_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_subTexelPrecisionBits_name);

	zval property_mipmapPrecisionBits_default_value;
	ZVAL_LONG(&property_mipmapPrecisionBits_default_value, 0);
	zend_string *property_mipmapPrecisionBits_name = zend_string_init("mipmapPrecisionBits", sizeof("mipmapPrecisionBits") - 1, 1);
	zend_declare_typed_property(class_entry, property_mipmapPrecisionBits_name, &property_mipmapPrecisionBits_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mipmapPrecisionBits_name);

	zval property_maxDrawIndexedIndexValue_default_value;
	ZVAL_LONG(&property_maxDrawIndexedIndexValue_default_value, 0);
	zend_string *property_maxDrawIndexedIndexValue_name = zend_string_init("maxDrawIndexedIndexValue", sizeof("maxDrawIndexedIndexValue") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxDrawIndexedIndexValue_name, &property_maxDrawIndexedIndexValue_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxDrawIndexedIndexValue_name);

	zval property_maxDrawIndirectCount_default_value;
	ZVAL_LONG(&property_maxDrawIndirectCount_default_value, 0);
	zend_string *property_maxDrawIndirectCount_name = zend_string_init("maxDrawIndirectCount", sizeof("maxDrawIndirectCount") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxDrawIndirectCount_name, &property_maxDrawIndirectCount_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxDrawIndirectCount_name);

	zval property_maxSamplerLodBias_default_value;
	ZVAL_DOUBLE(&property_maxSamplerLodBias_default_value, 0.0);
	zend_string *property_maxSamplerLodBias_name = zend_string_init("maxSamplerLodBias", sizeof("maxSamplerLodBias") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxSamplerLodBias_name, &property_maxSamplerLodBias_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_maxSamplerLodBias_name);

	zval property_maxSamplerAnisotropy_default_value;
	ZVAL_DOUBLE(&property_maxSamplerAnisotropy_default_value, 0.0);
	zend_string *property_maxSamplerAnisotropy_name = zend_string_init("maxSamplerAnisotropy", sizeof("maxSamplerAnisotropy") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxSamplerAnisotropy_name, &property_maxSamplerAnisotropy_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_maxSamplerAnisotropy_name);

	zval property_maxViewports_default_value;
	ZVAL_LONG(&property_maxViewports_default_value, 0);
	zend_string *property_maxViewports_name = zend_string_init("maxViewports", sizeof("maxViewports") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxViewports_name, &property_maxViewports_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxViewports_name);

	zval property_maxViewportDimensions_default_value;
	ZVAL_EMPTY_ARRAY(&property_maxViewportDimensions_default_value);
	zend_string *property_maxViewportDimensions_name = zend_string_init("maxViewportDimensions", sizeof("maxViewportDimensions") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxViewportDimensions_name, &property_maxViewportDimensions_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_maxViewportDimensions_name);

	zval property_viewportBoundsRange_default_value;
	ZVAL_EMPTY_ARRAY(&property_viewportBoundsRange_default_value);
	zend_string *property_viewportBoundsRange_name = zend_string_init("viewportBoundsRange", sizeof("viewportBoundsRange") - 1, 1);
	zend_declare_typed_property(class_entry, property_viewportBoundsRange_name, &property_viewportBoundsRange_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_viewportBoundsRange_name);

	zval property_viewportSubPixelBits_default_value;
	ZVAL_LONG(&property_viewportSubPixelBits_default_value, 0);
	zend_string *property_viewportSubPixelBits_name = zend_string_init("viewportSubPixelBits", sizeof("viewportSubPixelBits") - 1, 1);
	zend_declare_typed_property(class_entry, property_viewportSubPixelBits_name, &property_viewportSubPixelBits_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_viewportSubPixelBits_name);

	zval property_minMemoryMapAlignment_default_value;
	ZVAL_LONG(&property_minMemoryMapAlignment_default_value, 0);
	zend_string *property_minMemoryMapAlignment_name = zend_string_init("minMemoryMapAlignment", sizeof("minMemoryMapAlignment") - 1, 1);
	zend_declare_typed_property(class_entry, property_minMemoryMapAlignment_name, &property_minMemoryMapAlignment_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_minMemoryMapAlignment_name);

	zval property_minTexelBufferOffsetAlignment_default_value;
	ZVAL_LONG(&property_minTexelBufferOffsetAlignment_default_value, 0);
	zend_string *property_minTexelBufferOffsetAlignment_name = zend_string_init("minTexelBufferOffsetAlignment", sizeof("minTexelBufferOffsetAlignment") - 1, 1);
	zend_declare_typed_property(class_entry, property_minTexelBufferOffsetAlignment_name, &property_minTexelBufferOffsetAlignment_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_minTexelBufferOffsetAlignment_name);

	zval property_minUniformBufferOffsetAlignment_default_value;
	ZVAL_LONG(&property_minUniformBufferOffsetAlignment_default_value, 0);
	zend_string *property_minUniformBufferOffsetAlignment_name = zend_string_init("minUniformBufferOffsetAlignment", sizeof("minUniformBufferOffsetAlignment") - 1, 1);
	zend_declare_typed_property(class_entry, property_minUniformBufferOffsetAlignment_name, &property_minUniformBufferOffsetAlignment_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_minUniformBufferOffsetAlignment_name);

	zval property_minStorageBufferOffsetAlignment_default_value;
	ZVAL_LONG(&property_minStorageBufferOffsetAlignment_default_value, 0);
	zend_string *property_minStorageBufferOffsetAlignment_name = zend_string_init("minStorageBufferOffsetAlignment", sizeof("minStorageBufferOffsetAlignment") - 1, 1);
	zend_declare_typed_property(class_entry, property_minStorageBufferOffsetAlignment_name, &property_minStorageBufferOffsetAlignment_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_minStorageBufferOffsetAlignment_name);

	zval property_minTexelOffset_default_value;
	ZVAL_LONG(&property_minTexelOffset_default_value, 0);
	zend_string *property_minTexelOffset_name = zend_string_init("minTexelOffset", sizeof("minTexelOffset") - 1, 1);
	zend_declare_typed_property(class_entry, property_minTexelOffset_name, &property_minTexelOffset_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_minTexelOffset_name);

	zval property_maxTexelOffset_default_value;
	ZVAL_LONG(&property_maxTexelOffset_default_value, 0);
	zend_string *property_maxTexelOffset_name = zend_string_init("maxTexelOffset", sizeof("maxTexelOffset") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxTexelOffset_name, &property_maxTexelOffset_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxTexelOffset_name);

	zval property_minTexelGatherOffset_default_value;
	ZVAL_LONG(&property_minTexelGatherOffset_default_value, 0);
	zend_string *property_minTexelGatherOffset_name = zend_string_init("minTexelGatherOffset", sizeof("minTexelGatherOffset") - 1, 1);
	zend_declare_typed_property(class_entry, property_minTexelGatherOffset_name, &property_minTexelGatherOffset_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_minTexelGatherOffset_name);

	zval property_maxTexelGatherOffset_default_value;
	ZVAL_LONG(&property_maxTexelGatherOffset_default_value, 0);
	zend_string *property_maxTexelGatherOffset_name = zend_string_init("maxTexelGatherOffset", sizeof("maxTexelGatherOffset") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxTexelGatherOffset_name, &property_maxTexelGatherOffset_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxTexelGatherOffset_name);

	zval property_minInterpolationOffset_default_value;
	ZVAL_DOUBLE(&property_minInterpolationOffset_default_value, 0.0);
	zend_string *property_minInterpolationOffset_name = zend_string_init("minInterpolationOffset", sizeof("minInterpolationOffset") - 1, 1);
	zend_declare_typed_property(class_entry, property_minInterpolationOffset_name, &property_minInterpolationOffset_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_minInterpolationOffset_name);

	zval property_maxInterpolationOffset_default_value;
	ZVAL_DOUBLE(&property_maxInterpolationOffset_default_value, 0.0);
	zend_string *property_maxInterpolationOffset_name = zend_string_init("maxInterpolationOffset", sizeof("maxInterpolationOffset") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxInterpolationOffset_name, &property_maxInterpolationOffset_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_maxInterpolationOffset_name);

	zval property_subPixelInterpolationOffsetBits_default_value;
	ZVAL_LONG(&property_subPixelInterpolationOffsetBits_default_value, 0);
	zend_string *property_subPixelInterpolationOffsetBits_name = zend_string_init("subPixelInterpolationOffsetBits", sizeof("subPixelInterpolationOffsetBits") - 1, 1);
	zend_declare_typed_property(class_entry, property_subPixelInterpolationOffsetBits_name, &property_subPixelInterpolationOffsetBits_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_subPixelInterpolationOffsetBits_name);

	zval property_maxFramebufferWidth_default_value;
	ZVAL_LONG(&property_maxFramebufferWidth_default_value, 0);
	zend_string *property_maxFramebufferWidth_name = zend_string_init("maxFramebufferWidth", sizeof("maxFramebufferWidth") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxFramebufferWidth_name, &property_maxFramebufferWidth_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxFramebufferWidth_name);

	zval property_maxFramebufferHeight_default_value;
	ZVAL_LONG(&property_maxFramebufferHeight_default_value, 0);
	zend_string *property_maxFramebufferHeight_name = zend_string_init("maxFramebufferHeight", sizeof("maxFramebufferHeight") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxFramebufferHeight_name, &property_maxFramebufferHeight_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxFramebufferHeight_name);

	zval property_maxFramebufferLayers_default_value;
	ZVAL_LONG(&property_maxFramebufferLayers_default_value, 0);
	zend_string *property_maxFramebufferLayers_name = zend_string_init("maxFramebufferLayers", sizeof("maxFramebufferLayers") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxFramebufferLayers_name, &property_maxFramebufferLayers_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxFramebufferLayers_name);

	zval property_framebufferColorSampleCounts_default_value;
	ZVAL_LONG(&property_framebufferColorSampleCounts_default_value, 0);
	zend_string *property_framebufferColorSampleCounts_name = zend_string_init("framebufferColorSampleCounts", sizeof("framebufferColorSampleCounts") - 1, 1);
	zend_declare_typed_property(class_entry, property_framebufferColorSampleCounts_name, &property_framebufferColorSampleCounts_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_framebufferColorSampleCounts_name);

	zval property_framebufferDepthSampleCounts_default_value;
	ZVAL_LONG(&property_framebufferDepthSampleCounts_default_value, 0);
	zend_string *property_framebufferDepthSampleCounts_name = zend_string_init("framebufferDepthSampleCounts", sizeof("framebufferDepthSampleCounts") - 1, 1);
	zend_declare_typed_property(class_entry, property_framebufferDepthSampleCounts_name, &property_framebufferDepthSampleCounts_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_framebufferDepthSampleCounts_name);

	zval property_framebufferStencilSampleCounts_default_value;
	ZVAL_LONG(&property_framebufferStencilSampleCounts_default_value, 0);
	zend_string *property_framebufferStencilSampleCounts_name = zend_string_init("framebufferStencilSampleCounts", sizeof("framebufferStencilSampleCounts") - 1, 1);
	zend_declare_typed_property(class_entry, property_framebufferStencilSampleCounts_name, &property_framebufferStencilSampleCounts_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_framebufferStencilSampleCounts_name);

	zval property_framebufferNoAttachmentsSampleCounts_default_value;
	ZVAL_LONG(&property_framebufferNoAttachmentsSampleCounts_default_value, 0);
	zend_string *property_framebufferNoAttachmentsSampleCounts_name = zend_string_init("framebufferNoAttachmentsSampleCounts", sizeof("framebufferNoAttachmentsSampleCounts") - 1, 1);
	zend_declare_typed_property(class_entry, property_framebufferNoAttachmentsSampleCounts_name, &property_framebufferNoAttachmentsSampleCounts_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_framebufferNoAttachmentsSampleCounts_name);

	zval property_maxColorAttachments_default_value;
	ZVAL_LONG(&property_maxColorAttachments_default_value, 0);
	zend_string *property_maxColorAttachments_name = zend_string_init("maxColorAttachments", sizeof("maxColorAttachments") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxColorAttachments_name, &property_maxColorAttachments_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxColorAttachments_name);

	zval property_sampledImageColorSampleCounts_default_value;
	ZVAL_LONG(&property_sampledImageColorSampleCounts_default_value, 0);
	zend_string *property_sampledImageColorSampleCounts_name = zend_string_init("sampledImageColorSampleCounts", sizeof("sampledImageColorSampleCounts") - 1, 1);
	zend_declare_typed_property(class_entry, property_sampledImageColorSampleCounts_name, &property_sampledImageColorSampleCounts_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_sampledImageColorSampleCounts_name);

	zval property_sampledImageIntegerSampleCounts_default_value;
	ZVAL_LONG(&property_sampledImageIntegerSampleCounts_default_value, 0);
	zend_string *property_sampledImageIntegerSampleCounts_name = zend_string_init("sampledImageIntegerSampleCounts", sizeof("sampledImageIntegerSampleCounts") - 1, 1);
	zend_declare_typed_property(class_entry, property_sampledImageIntegerSampleCounts_name, &property_sampledImageIntegerSampleCounts_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_sampledImageIntegerSampleCounts_name);

	zval property_sampledImageDepthSampleCounts_default_value;
	ZVAL_LONG(&property_sampledImageDepthSampleCounts_default_value, 0);
	zend_string *property_sampledImageDepthSampleCounts_name = zend_string_init("sampledImageDepthSampleCounts", sizeof("sampledImageDepthSampleCounts") - 1, 1);
	zend_declare_typed_property(class_entry, property_sampledImageDepthSampleCounts_name, &property_sampledImageDepthSampleCounts_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_sampledImageDepthSampleCounts_name);

	zval property_sampledImageStencilSampleCounts_default_value;
	ZVAL_LONG(&property_sampledImageStencilSampleCounts_default_value, 0);
	zend_string *property_sampledImageStencilSampleCounts_name = zend_string_init("sampledImageStencilSampleCounts", sizeof("sampledImageStencilSampleCounts") - 1, 1);
	zend_declare_typed_property(class_entry, property_sampledImageStencilSampleCounts_name, &property_sampledImageStencilSampleCounts_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_sampledImageStencilSampleCounts_name);

	zval property_storageImageSampleCounts_default_value;
	ZVAL_LONG(&property_storageImageSampleCounts_default_value, 0);
	zend_string *property_storageImageSampleCounts_name = zend_string_init("storageImageSampleCounts", sizeof("storageImageSampleCounts") - 1, 1);
	zend_declare_typed_property(class_entry, property_storageImageSampleCounts_name, &property_storageImageSampleCounts_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_storageImageSampleCounts_name);

	zval property_maxSampleMaskWords_default_value;
	ZVAL_LONG(&property_maxSampleMaskWords_default_value, 0);
	zend_string *property_maxSampleMaskWords_name = zend_string_init("maxSampleMaskWords", sizeof("maxSampleMaskWords") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxSampleMaskWords_name, &property_maxSampleMaskWords_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxSampleMaskWords_name);

	zval property_timestampComputeAndGraphics_default_value;
	ZVAL_FALSE(&property_timestampComputeAndGraphics_default_value);
	zend_string *property_timestampComputeAndGraphics_name = zend_string_init("timestampComputeAndGraphics", sizeof("timestampComputeAndGraphics") - 1, 1);
	zend_declare_typed_property(class_entry, property_timestampComputeAndGraphics_name, &property_timestampComputeAndGraphics_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_timestampComputeAndGraphics_name);

	zval property_timestampPeriod_default_value;
	ZVAL_DOUBLE(&property_timestampPeriod_default_value, 0.0);
	zend_string *property_timestampPeriod_name = zend_string_init("timestampPeriod", sizeof("timestampPeriod") - 1, 1);
	zend_declare_typed_property(class_entry, property_timestampPeriod_name, &property_timestampPeriod_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_timestampPeriod_name);

	zval property_maxClipDistances_default_value;
	ZVAL_LONG(&property_maxClipDistances_default_value, 0);
	zend_string *property_maxClipDistances_name = zend_string_init("maxClipDistances", sizeof("maxClipDistances") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxClipDistances_name, &property_maxClipDistances_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxClipDistances_name);

	zval property_maxCullDistances_default_value;
	ZVAL_LONG(&property_maxCullDistances_default_value, 0);
	zend_string *property_maxCullDistances_name = zend_string_init("maxCullDistances", sizeof("maxCullDistances") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxCullDistances_name, &property_maxCullDistances_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxCullDistances_name);

	zval property_maxCombinedClipAndCullDistances_default_value;
	ZVAL_LONG(&property_maxCombinedClipAndCullDistances_default_value, 0);
	zend_string *property_maxCombinedClipAndCullDistances_name = zend_string_init("maxCombinedClipAndCullDistances", sizeof("maxCombinedClipAndCullDistances") - 1, 1);
	zend_declare_typed_property(class_entry, property_maxCombinedClipAndCullDistances_name, &property_maxCombinedClipAndCullDistances_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_maxCombinedClipAndCullDistances_name);

	zval property_discreteQueuePriorities_default_value;
	ZVAL_LONG(&property_discreteQueuePriorities_default_value, 0);
	zend_string *property_discreteQueuePriorities_name = zend_string_init("discreteQueuePriorities", sizeof("discreteQueuePriorities") - 1, 1);
	zend_declare_typed_property(class_entry, property_discreteQueuePriorities_name, &property_discreteQueuePriorities_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_discreteQueuePriorities_name);

	zval property_pointSizeRange_default_value;
	ZVAL_EMPTY_ARRAY(&property_pointSizeRange_default_value);
	zend_string *property_pointSizeRange_name = zend_string_init("pointSizeRange", sizeof("pointSizeRange") - 1, 1);
	zend_declare_typed_property(class_entry, property_pointSizeRange_name, &property_pointSizeRange_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_pointSizeRange_name);

	zval property_lineWidthRange_default_value;
	ZVAL_EMPTY_ARRAY(&property_lineWidthRange_default_value);
	zend_string *property_lineWidthRange_name = zend_string_init("lineWidthRange", sizeof("lineWidthRange") - 1, 1);
	zend_declare_typed_property(class_entry, property_lineWidthRange_name, &property_lineWidthRange_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_lineWidthRange_name);

	zval property_pointSizeGranularity_default_value;
	ZVAL_DOUBLE(&property_pointSizeGranularity_default_value, 0.0);
	zend_string *property_pointSizeGranularity_name = zend_string_init("pointSizeGranularity", sizeof("pointSizeGranularity") - 1, 1);
	zend_declare_typed_property(class_entry, property_pointSizeGranularity_name, &property_pointSizeGranularity_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_pointSizeGranularity_name);

	zval property_lineWidthGranularity_default_value;
	ZVAL_DOUBLE(&property_lineWidthGranularity_default_value, 0.0);
	zend_string *property_lineWidthGranularity_name = zend_string_init("lineWidthGranularity", sizeof("lineWidthGranularity") - 1, 1);
	zend_declare_typed_property(class_entry, property_lineWidthGranularity_name, &property_lineWidthGranularity_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_lineWidthGranularity_name);

	zval property_strictLines_default_value;
	ZVAL_FALSE(&property_strictLines_default_value);
	zend_string *property_strictLines_name = zend_string_init("strictLines", sizeof("strictLines") - 1, 1);
	zend_declare_typed_property(class_entry, property_strictLines_name, &property_strictLines_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_strictLines_name);

	zval property_standardSampleLocations_default_value;
	ZVAL_FALSE(&property_standardSampleLocations_default_value);
	zend_string *property_standardSampleLocations_name = zend_string_init("standardSampleLocations", sizeof("standardSampleLocations") - 1, 1);
	zend_declare_typed_property(class_entry, property_standardSampleLocations_name, &property_standardSampleLocations_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_standardSampleLocations_name);

	zval property_optimalBufferCopyOffsetAlignment_default_value;
	ZVAL_LONG(&property_optimalBufferCopyOffsetAlignment_default_value, 0);
	zend_string *property_optimalBufferCopyOffsetAlignment_name = zend_string_init("optimalBufferCopyOffsetAlignment", sizeof("optimalBufferCopyOffsetAlignment") - 1, 1);
	zend_declare_typed_property(class_entry, property_optimalBufferCopyOffsetAlignment_name, &property_optimalBufferCopyOffsetAlignment_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_optimalBufferCopyOffsetAlignment_name);

	zval property_optimalBufferCopyRowPitchAlignment_default_value;
	ZVAL_LONG(&property_optimalBufferCopyRowPitchAlignment_default_value, 0);
	zend_string *property_optimalBufferCopyRowPitchAlignment_name = zend_string_init("optimalBufferCopyRowPitchAlignment", sizeof("optimalBufferCopyRowPitchAlignment") - 1, 1);
	zend_declare_typed_property(class_entry, property_optimalBufferCopyRowPitchAlignment_name, &property_optimalBufferCopyRowPitchAlignment_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_optimalBufferCopyRowPitchAlignment_name);

	zval property_nonCoherentAtomSize_default_value;
	ZVAL_LONG(&property_nonCoherentAtomSize_default_value, 0);
	zend_string *property_nonCoherentAtomSize_name = zend_string_init("nonCoherentAtomSize", sizeof("nonCoherentAtomSize") - 1, 1);
	zend_declare_typed_property(class_entry, property_nonCoherentAtomSize_name, &property_nonCoherentAtomSize_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_nonCoherentAtomSize_name);

	return class_entry;
}

static zend_class_entry *register_class_VkPhysicalDeviceSparseProperties(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkPhysicalDeviceSparseProperties", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_residencyStandard2DBlockShape_default_value;
	ZVAL_FALSE(&property_residencyStandard2DBlockShape_default_value);
	zend_string *property_residencyStandard2DBlockShape_name = zend_string_init("residencyStandard2DBlockShape", sizeof("residencyStandard2DBlockShape") - 1, 1);
	zend_declare_typed_property(class_entry, property_residencyStandard2DBlockShape_name, &property_residencyStandard2DBlockShape_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_residencyStandard2DBlockShape_name);

	zval property_residencyStandard2DMultisampleBlockShape_default_value;
	ZVAL_FALSE(&property_residencyStandard2DMultisampleBlockShape_default_value);
	zend_string *property_residencyStandard2DMultisampleBlockShape_name = zend_string_init("residencyStandard2DMultisampleBlockShape", sizeof("residencyStandard2DMultisampleBlockShape") - 1, 1);
	zend_declare_typed_property(class_entry, property_residencyStandard2DMultisampleBlockShape_name, &property_residencyStandard2DMultisampleBlockShape_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_residencyStandard2DMultisampleBlockShape_name);

	zval property_residencyStandard3DBlockShape_default_value;
	ZVAL_FALSE(&property_residencyStandard3DBlockShape_default_value);
	zend_string *property_residencyStandard3DBlockShape_name = zend_string_init("residencyStandard3DBlockShape", sizeof("residencyStandard3DBlockShape") - 1, 1);
	zend_declare_typed_property(class_entry, property_residencyStandard3DBlockShape_name, &property_residencyStandard3DBlockShape_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_residencyStandard3DBlockShape_name);

	zval property_residencyAlignedMipSize_default_value;
	ZVAL_FALSE(&property_residencyAlignedMipSize_default_value);
	zend_string *property_residencyAlignedMipSize_name = zend_string_init("residencyAlignedMipSize", sizeof("residencyAlignedMipSize") - 1, 1);
	zend_declare_typed_property(class_entry, property_residencyAlignedMipSize_name, &property_residencyAlignedMipSize_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_residencyAlignedMipSize_name);

	zval property_residencyNonResidentStrict_default_value;
	ZVAL_FALSE(&property_residencyNonResidentStrict_default_value);
	zend_string *property_residencyNonResidentStrict_name = zend_string_init("residencyNonResidentStrict", sizeof("residencyNonResidentStrict") - 1, 1);
	zend_declare_typed_property(class_entry, property_residencyNonResidentStrict_name, &property_residencyNonResidentStrict_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_residencyNonResidentStrict_name);

	return class_entry;
}

static zend_class_entry *register_class_VkPhysicalDeviceProperties(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkPhysicalDeviceProperties", class_VkPhysicalDeviceProperties_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_apiVersion_default_value;
	ZVAL_LONG(&property_apiVersion_default_value, 0);
	zend_string *property_apiVersion_name = zend_string_init("apiVersion", sizeof("apiVersion") - 1, 1);
	zend_declare_typed_property(class_entry, property_apiVersion_name, &property_apiVersion_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_apiVersion_name);

	zval property_driverVersion_default_value;
	ZVAL_LONG(&property_driverVersion_default_value, 0);
	zend_string *property_driverVersion_name = zend_string_init("driverVersion", sizeof("driverVersion") - 1, 1);
	zend_declare_typed_property(class_entry, property_driverVersion_name, &property_driverVersion_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_driverVersion_name);

	zval property_vendorID_default_value;
	ZVAL_LONG(&property_vendorID_default_value, 0);
	zend_string *property_vendorID_name = zend_string_init("vendorID", sizeof("vendorID") - 1, 1);
	zend_declare_typed_property(class_entry, property_vendorID_name, &property_vendorID_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_vendorID_name);

	zval property_deviceID_default_value;
	ZVAL_LONG(&property_deviceID_default_value, 0);
	zend_string *property_deviceID_name = zend_string_init("deviceID", sizeof("deviceID") - 1, 1);
	zend_declare_typed_property(class_entry, property_deviceID_name, &property_deviceID_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_deviceID_name);

	zval property_deviceType_default_value;
	ZVAL_LONG(&property_deviceType_default_value, 0);
	zend_string *property_deviceType_name = zend_string_init("deviceType", sizeof("deviceType") - 1, 1);
	zend_declare_typed_property(class_entry, property_deviceType_name, &property_deviceType_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_deviceType_name);

	zval property_deviceName_default_value;
	ZVAL_EMPTY_STRING(&property_deviceName_default_value);
	zend_string *property_deviceName_name = zend_string_init("deviceName", sizeof("deviceName") - 1, 1);
	zend_declare_typed_property(class_entry, property_deviceName_name, &property_deviceName_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING));
	zend_string_release(property_deviceName_name);

	zval property_pipelineCacheUUID_default_value;
	ZVAL_EMPTY_STRING(&property_pipelineCacheUUID_default_value);
	zend_string *property_pipelineCacheUUID_name = zend_string_init("pipelineCacheUUID", sizeof("pipelineCacheUUID") - 1, 1);
	zend_declare_typed_property(class_entry, property_pipelineCacheUUID_name, &property_pipelineCacheUUID_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING));
	zend_string_release(property_pipelineCacheUUID_name);

	zval property_limits_default_value;
	ZVAL_UNDEF(&property_limits_default_value);
	zend_string *property_limits_name = zend_string_init("limits", sizeof("limits") - 1, 1);
	zend_string *property_limits_class_VkPhysicalDeviceLimits = zend_string_init("VkPhysicalDeviceLimits", sizeof("VkPhysicalDeviceLimits")-1, 1);
	zend_declare_typed_property(class_entry, property_limits_name, &property_limits_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_limits_class_VkPhysicalDeviceLimits, 0, 0));
	zend_string_release(property_limits_name);

	zval property_sparseProperties_default_value;
	ZVAL_UNDEF(&property_sparseProperties_default_value);
	zend_string *property_sparseProperties_name = zend_string_init("sparseProperties", sizeof("sparseProperties") - 1, 1);
	zend_string *property_sparseProperties_class_VkPhysicalDeviceSparseProperties = zend_string_init("VkPhysicalDeviceSparseProperties", sizeof("VkPhysicalDeviceSparseProperties")-1, 1);
	zend_declare_typed_property(class_entry, property_sparseProperties_name, &property_sparseProperties_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_sparseProperties_class_VkPhysicalDeviceSparseProperties, 0, 0));
	zend_string_release(property_sparseProperties_name);

	return class_entry;
}

static zend_class_entry *register_class_VkExtent3D(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkExtent3D", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_width_default_value;
	ZVAL_LONG(&property_width_default_value, 0);
	zend_string *property_width_name = zend_string_init("width", sizeof("width") - 1, 1);
	zend_declare_typed_property(class_entry, property_width_name, &property_width_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_width_name);

	zval property_height_default_value;
	ZVAL_LONG(&property_height_default_value, 0);
	zend_string *property_height_name = zend_string_init("height", sizeof("height") - 1, 1);
	zend_declare_typed_property(class_entry, property_height_name, &property_height_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_height_name);

	zval property_depth_default_value;
	ZVAL_LONG(&property_depth_default_value, 0);
	zend_string *property_depth_name = zend_string_init("depth", sizeof("depth") - 1, 1);
	zend_declare_typed_property(class_entry, property_depth_name, &property_depth_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_depth_name);

	return class_entry;
}

static zend_class_entry *register_class_VkQueueFamilyProperties(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkQueueFamilyProperties", class_VkQueueFamilyProperties_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_queueFlags_default_value;
	ZVAL_LONG(&property_queueFlags_default_value, 0);
	zend_string *property_queueFlags_name = zend_string_init("queueFlags", sizeof("queueFlags") - 1, 1);
	zend_declare_typed_property(class_entry, property_queueFlags_name, &property_queueFlags_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_queueFlags_name);

	zval property_queueCount_default_value;
	ZVAL_LONG(&property_queueCount_default_value, 0);
	zend_string *property_queueCount_name = zend_string_init("queueCount", sizeof("queueCount") - 1, 1);
	zend_declare_typed_property(class_entry, property_queueCount_name, &property_queueCount_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_queueCount_name);

	zval property_timestampValidBits_default_value;
	ZVAL_LONG(&property_timestampValidBits_default_value, 0);
	zend_string *property_timestampValidBits_name = zend_string_init("timestampValidBits", sizeof("timestampValidBits") - 1, 1);
	zend_declare_typed_property(class_entry, property_timestampValidBits_name, &property_timestampValidBits_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_timestampValidBits_name);

	zval property_minImageTransferGranularity_default_value;
	ZVAL_UNDEF(&property_minImageTransferGranularity_default_value);
	zend_string *property_minImageTransferGranularity_name = zend_string_init("minImageTransferGranularity", sizeof("minImageTransferGranularity") - 1, 1);
	zend_string *property_minImageTransferGranularity_class_VkExtent3D = zend_string_init("VkExtent3D", sizeof("VkExtent3D")-1, 1);
	zend_declare_typed_property(class_entry, property_minImageTransferGranularity_name, &property_minImageTransferGranularity_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_minImageTransferGranularity_class_VkExtent3D, 0, 0));
	zend_string_release(property_minImageTransferGranularity_name);

	return class_entry;
}

static zend_class_entry *register_class_VkMemoryType(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkMemoryType", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_propertyFlags_default_value;
	ZVAL_LONG(&property_propertyFlags_default_value, 0);
	zend_string *property_propertyFlags_name = zend_string_init("propertyFlags", sizeof("propertyFlags") - 1, 1);
	zend_declare_typed_property(class_entry, property_propertyFlags_name, &property_propertyFlags_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_propertyFlags_name);

	zval property_heapIndex_default_value;
	ZVAL_LONG(&property_heapIndex_default_value, 0);
	zend_string *property_heapIndex_name = zend_string_init("heapIndex", sizeof("heapIndex") - 1, 1);
	zend_declare_typed_property(class_entry, property_heapIndex_name, &property_heapIndex_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_heapIndex_name);

	return class_entry;
}

static zend_class_entry *register_class_VkMemoryHeap(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkMemoryHeap", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_size_default_value;
	ZVAL_LONG(&property_size_default_value, 0);
	zend_string *property_size_name = zend_string_init("size", sizeof("size") - 1, 1);
	zend_declare_typed_property(class_entry, property_size_name, &property_size_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_size_name);

	zval property_flags_default_value;
	ZVAL_LONG(&property_flags_default_value, 0);
	zend_string *property_flags_name = zend_string_init("flags", sizeof("flags") - 1, 1);
	zend_declare_typed_property(class_entry, property_flags_name, &property_flags_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_flags_name);

	return class_entry;
}

static zend_class_entry *register_class_VkPhysicalDeviceMemoryProperties(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkPhysicalDeviceMemoryProperties", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_memoryTypes_default_value;
	ZVAL_EMPTY_ARRAY(&property_memoryTypes_default_value);
	zend_string *property_memoryTypes_name = zend_string_init("memoryTypes", sizeof("memoryTypes") - 1, 1);
	zend_declare_typed_property(class_entry, property_memoryTypes_name, &property_memoryTypes_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_memoryTypes_name);

	zval property_memoryHeaps_default_value;
	ZVAL_EMPTY_ARRAY(&property_memoryHeaps_default_value);
	zend_string *property_memoryHeaps_name = zend_string_init("memoryHeaps", sizeof("memoryHeaps") - 1, 1);
	zend_declare_typed_property(class_entry, property_memoryHeaps_name, &property_memoryHeaps_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_memoryHeaps_name);

	return class_entry;
}

static zend_class_entry *register_class_VkFormatProperties(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkFormatProperties", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_linearTilingFeatures_default_value;
	ZVAL_LONG(&property_linearTilingFeatures_default_value, 0);
	zend_string *property_linearTilingFeatures_name = zend_string_init("linearTilingFeatures", sizeof("linearTilingFeatures") - 1, 1);
	zend_declare_typed_property(class_entry, property_linearTilingFeatures_name, &property_linearTilingFeatures_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_linearTilingFeatures_name);

	zval property_optimalTilingFeatures_default_value;
	ZVAL_LONG(&property_optimalTilingFeatures_default_value, 0);
	zend_string *property_optimalTilingFeatures_name = zend_string_init("optimalTilingFeatures", sizeof("optimalTilingFeatures") - 1, 1);
	zend_declare_typed_property(class_entry, property_optimalTilingFeatures_name, &property_optimalTilingFeatures_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_optimalTilingFeatures_name);

	zval property_bufferFeatures_default_value;
	ZVAL_LONG(&property_bufferFeatures_default_value, 0);
	zend_string *property_bufferFeatures_name = zend_string_init("bufferFeatures", sizeof("bufferFeatures") - 1, 1);
	zend_declare_typed_property(class_entry, property_bufferFeatures_name, &property_bufferFeatures_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_bufferFeatures_name);

	return class_entry;
}

static zend_class_entry *register_class_VkExtensionProperties(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "VkExtensionProperties", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_extensionName_default_value;
	ZVAL_EMPTY_STRING(&property_extensionName_default_value);
	zend_string *property_extensionName_name = zend_string_init("extensionName", sizeof("extensionName") - 1, 1);
	zend_declare_typed_property(class_entry, property_extensionName_name, &property_extensionName_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING));
	zend_string_release(property_extensionName_name);

	zval property_specVersion_default_value;
	ZVAL_LONG(&property_specVersion_default_value, 0);
	zend_string *property_specVersion_name = zend_string_init("specVersion", sizeof("specVersion") - 1, 1);
	zend_declare_typed_property(class_entry, property_specVersion_name, &property_specVersion_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_specVersion_name);

	return class_entry;
}
