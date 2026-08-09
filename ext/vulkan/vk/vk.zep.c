
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"

#include "vulkan-api.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>



/**
 * Vulkan entry points (static passthrough + thin C helpers).
 *
 * Window/surface creation lives in glfw — this class is instance/device/present.
 * Named Vulkan objects are returned as Zephir DTOs with an opaque `fd`.
 * Token constants (VK_*) live in a microscrap wrapper.
 */
ZEPHIR_INIT_CLASS(Vulkan_Vk_Vk)
{
	ZEPHIR_REGISTER_CLASS(Vulkan\\Vk, Vk, vulkan, vk_vk, vulkan_vk_vk_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Vulkan_Vk_Vk, lastError)
{
	zval result;

	ZVAL_UNDEF(&result);
	
            const char *msg = php_vk_last_error();
            ZVAL_STRING(&result, msg ? msg : "");
        
	RETURN_CTORW(&result);
}

/**
 * @param array extensions List of instance extension name strings (e.g. from glfw)
 */
PHP_METHOD(Vulkan_Vk_Vk, createInstance)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, fd, extCount = 0, i = 0, n = 0;
	zval appName;
	zval *extensions_param = NULL, *appName_param = NULL, instance, ext, *_0, _1, _2;
	zval extensions;

	ZVAL_UNDEF(&extensions);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&ext);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&appName);
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(extensions)
		Z_PARAM_STR(appName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 2, &extensions_param, &appName_param);
	if (!extensions_param) {
		ZEPHIR_INIT_VAR(&extensions);
		array_init(&extensions);
	} else {
		zephir_get_arrval(&extensions, extensions_param);
	}
	if (!appName_param) {
		ZEPHIR_INIT_VAR(&appName);
		ZVAL_STRING(&appName, "php-io-extensions/vulkan");
	} else {
		zephir_get_strval(&appName, appName_param);
	}
	fd = 0;
	extCount = zephir_fast_count_int(&extensions);
	n = extCount;
	
            const char **exts = NULL;
            if (n > 0) {
                exts = (const char **) ecalloc((uint32_t) n, sizeof(char *));
            }
        
	i = 0;
	zephir_is_iterable(&extensions, 0, "vulkan/vk/vk.zep", 73);
	if (Z_TYPE_P(&extensions) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&extensions), _0)
		{
			ZEPHIR_INIT_NVAR(&ext);
			ZVAL_COPY(&ext, _0);
			if (Z_TYPE_P(&ext) == IS_STRING) {
				
                    if (exts && i < n) {
                        exts[i] = Z_STRVAL(ext);
                    }
                
			}
			i = (i + 1);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &extensions, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &extensions, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&ext, &extensions, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&ext) == IS_STRING) {
					
                    if (exts && i < n) {
                        exts[i] = Z_STRVAL(ext);
                    }
                
				}
				i = (i + 1);
			ZEPHIR_CALL_METHOD(NULL, &extensions, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&ext);
	
            fd = (zend_long) php_vk_create_instance(exts, (uint32_t) n, Z_STRVAL(appName));
            if (exts) {
                efree((void *) exts);
            }
        
	ZEPHIR_INIT_VAR(&instance);
	object_init_ex(&instance, vulkan_vk_vkinstance_ce);
	if (zephir_has_constructor(&instance)) {
		ZEPHIR_CALL_METHOD(NULL, &instance, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	ZVAL_UNDEF(&_2);
	ZVAL_LONG(&_2, fd);
	zephir_update_property_zval(&instance, ZEND_STRL("fd"), &_2);
	zephir_update_property_zval(&instance, ZEND_STRL("appName"), &appName);
	RETURN_CCTOR(&instance);
}

PHP_METHOD(Vulkan_Vk_Vk, destroyInstance)
{
	zend_long fd;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *instance, instance_sub, _0, _1;

	ZVAL_UNDEF(&instance_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(instance, zephir_get_internal_ce(SL("vulkan\\vk\\vkinstance")))
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &instance);
	ZEPHIR_SEPARATE_PARAM(instance);
	fd = 0;
	zephir_memory_observe(&_0);
	zephir_read_property(&_0, instance, ZEND_STRL("fd"), PH_NOISY_CC);
	fd = zephir_get_intval(&_0);
	
            php_vk_destroy_instance((uintptr_t) fd);
        
	ZVAL_UNDEF(&_1);
	ZVAL_LONG(&_1, 0);
	zephir_update_property_zval(instance, ZEND_STRL("fd"), &_1);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Vulkan_Vk_Vk, enumeratePhysicalDevices)
{
	zval name;
	zval result;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, instFd, deviceCount, i, fd, deviceType, vendorId, deviceId;
	zval *instance, instance_sub, phys, _0, _1$$3;

	ZVAL_UNDEF(&instance_sub);
	ZVAL_UNDEF(&phys);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&name);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(instance, zephir_get_internal_ce(SL("vulkan\\vk\\vkinstance")))
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &instance);
	instFd = 0;
	deviceCount = 0;
	i = 0;
	fd = 0;
	deviceType = 0;
	vendorId = 0;
	deviceId = 0;
	ZEPHIR_INIT_VAR(&result);
	array_init(&result);
	zephir_memory_observe(&_0);
	zephir_read_property(&_0, instance, ZEND_STRL("fd"), PH_NOISY_CC);
	instFd = zephir_get_intval(&_0);
	
            deviceCount = (zend_long) php_vk_physical_device_count((uintptr_t) instFd);
        
	while (1) {
		if (!(i < deviceCount)) {
			break;
		}
		
                char namebuf[256];
                fd = (zend_long) php_vk_physical_device_at((uintptr_t) instFd, (uint32_t) i);
                namebuf[0] = '\0';
                deviceType = 0;
                vendorId = 0;
                deviceId = 0;
                if (fd) {
                    php_vk_physical_device_name((uintptr_t) fd, namebuf, sizeof(namebuf));
                    deviceType = (zend_long) php_vk_physical_device_type((uintptr_t) fd);
                    vendorId = (zend_long) php_vk_physical_device_vendor_id((uintptr_t) fd);
                    deviceId = (zend_long) php_vk_physical_device_device_id((uintptr_t) fd);
                }
                ZVAL_STRING(&name, namebuf);
            
		ZEPHIR_INIT_NVAR(&phys);
		object_init_ex(&phys, vulkan_vk_vkphysicaldevice_ce);
		if (zephir_has_constructor(&phys)) {
			ZEPHIR_CALL_METHOD(NULL, &phys, "__construct", NULL, 0);
			zephir_check_call_status();
		}

		ZVAL_UNDEF(&_1$$3);
		ZVAL_LONG(&_1$$3, fd);
		zephir_update_property_zval(&phys, ZEND_STRL("fd"), &_1$$3);
		zephir_update_property_zval(&phys, ZEND_STRL("name"), &name);
		ZVAL_UNDEF(&_1$$3);
		ZVAL_LONG(&_1$$3, deviceType);
		zephir_update_property_zval(&phys, ZEND_STRL("deviceType"), &_1$$3);
		ZVAL_UNDEF(&_1$$3);
		ZVAL_LONG(&_1$$3, vendorId);
		zephir_update_property_zval(&phys, ZEND_STRL("vendorId"), &_1$$3);
		ZVAL_UNDEF(&_1$$3);
		ZVAL_LONG(&_1$$3, deviceId);
		zephir_update_property_zval(&phys, ZEND_STRL("deviceId"), &_1$$3);
		zephir_array_append(&result, &phys, PH_SEPARATE, "vulkan/vk/vk.zep", 133);
		i = (i + 1);
	}
	RETURN_CTOR(&result);
}

PHP_METHOD(Vulkan_Vk_Vk, findGraphicsPresentQueue)
{
	zend_long result, physFd, surfFd;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *physical, physical_sub, *surface, surface_sub, _0, _1;

	ZVAL_UNDEF(&physical_sub);
	ZVAL_UNDEF(&surface_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(physical, zephir_get_internal_ce(SL("vulkan\\vk\\vkphysicaldevice")))
		Z_PARAM_OBJECT_OF_CLASS(surface, zephir_get_internal_ce(SL("vulkan\\vk\\vksurface")))
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &physical, &surface);
	result = -1;
	physFd = 0;
	surfFd = 0;
	zephir_memory_observe(&_0);
	zephir_read_property(&_0, physical, ZEND_STRL("fd"), PH_NOISY_CC);
	physFd = zephir_get_intval(&_0);
	zephir_memory_observe(&_1);
	zephir_read_property(&_1, surface, ZEND_STRL("fd"), PH_NOISY_CC);
	surfFd = zephir_get_intval(&_1);
	
            result = (zend_long) php_vk_find_graphics_present_queue((uintptr_t) physFd, (uintptr_t) surfFd);
        
	RETURN_MM_LONG(result);
}

PHP_METHOD(Vulkan_Vk_Vk, createDevice)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long queueFamily, ZEPHIR_LAST_CALL_STATUS, fd, physFd;
	zval *physical, physical_sub, *queueFamily_param = NULL, device, _0, _1;

	ZVAL_UNDEF(&physical_sub);
	ZVAL_UNDEF(&device);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(physical, zephir_get_internal_ce(SL("vulkan\\vk\\vkphysicaldevice")))
		Z_PARAM_LONG(queueFamily)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &physical, &queueFamily_param);
	fd = 0;
	physFd = 0;
	zephir_memory_observe(&_0);
	zephir_read_property(&_0, physical, ZEND_STRL("fd"), PH_NOISY_CC);
	physFd = zephir_get_intval(&_0);
	
            fd = (zend_long) php_vk_create_device((uintptr_t) physFd, (int) queueFamily);
        
	ZEPHIR_INIT_VAR(&device);
	object_init_ex(&device, vulkan_vk_vkdevice_ce);
	if (zephir_has_constructor(&device)) {
		ZEPHIR_CALL_METHOD(NULL, &device, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	ZVAL_UNDEF(&_1);
	ZVAL_LONG(&_1, fd);
	zephir_update_property_zval(&device, ZEND_STRL("fd"), &_1);
	ZVAL_UNDEF(&_1);
	ZVAL_LONG(&_1, queueFamily);
	zephir_update_property_zval(&device, ZEND_STRL("queueFamily"), &_1);
	RETURN_CCTOR(&device);
}

PHP_METHOD(Vulkan_Vk_Vk, destroyDevice)
{
	zend_long fd;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *device, device_sub, _0, _1;

	ZVAL_UNDEF(&device_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(device, zephir_get_internal_ce(SL("vulkan\\vk\\vkdevice")))
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &device);
	ZEPHIR_SEPARATE_PARAM(device);
	fd = 0;
	zephir_memory_observe(&_0);
	zephir_read_property(&_0, device, ZEND_STRL("fd"), PH_NOISY_CC);
	fd = zephir_get_intval(&_0);
	
            php_vk_destroy_device((uintptr_t) fd);
        
	ZVAL_UNDEF(&_1);
	ZVAL_LONG(&_1, 0);
	zephir_update_property_zval(device, ZEND_STRL("fd"), &_1);
	ZVAL_UNDEF(&_1);
	ZVAL_LONG(&_1, -1);
	zephir_update_property_zval(device, ZEND_STRL("queueFamily"), &_1);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Vulkan_Vk_Vk, getDeviceQueue)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long queueFamily, ZEPHIR_LAST_CALL_STATUS, fd, devFd;
	zval *device, device_sub, *queueFamily_param = NULL, queue, _0, _1;

	ZVAL_UNDEF(&device_sub);
	ZVAL_UNDEF(&queue);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(device, zephir_get_internal_ce(SL("vulkan\\vk\\vkdevice")))
		Z_PARAM_LONG(queueFamily)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &device, &queueFamily_param);
	fd = 0;
	devFd = 0;
	zephir_memory_observe(&_0);
	zephir_read_property(&_0, device, ZEND_STRL("fd"), PH_NOISY_CC);
	devFd = zephir_get_intval(&_0);
	
            fd = (zend_long) php_vk_get_device_queue((uintptr_t) devFd, (int) queueFamily);
        
	ZEPHIR_INIT_VAR(&queue);
	object_init_ex(&queue, vulkan_vk_vkqueue_ce);
	if (zephir_has_constructor(&queue)) {
		ZEPHIR_CALL_METHOD(NULL, &queue, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	ZVAL_UNDEF(&_1);
	ZVAL_LONG(&_1, fd);
	zephir_update_property_zval(&queue, ZEND_STRL("fd"), &_1);
	ZVAL_UNDEF(&_1);
	ZVAL_LONG(&_1, queueFamily);
	zephir_update_property_zval(&queue, ZEND_STRL("familyIndex"), &_1);
	RETURN_CCTOR(&queue);
}

/**
 * Wrap an existing VkSurfaceKHR pointer (e.g. from glfwCreateWindowSurface).
 */
PHP_METHOD(Vulkan_Vk_Vk, wrapSurface)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *surfaceFd_param = NULL, surface, _0;
	zend_long surfaceFd, ZEPHIR_LAST_CALL_STATUS;

	ZVAL_UNDEF(&surface);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(surfaceFd)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &surfaceFd_param);
	ZEPHIR_INIT_VAR(&surface);
	object_init_ex(&surface, vulkan_vk_vksurface_ce);
	if (zephir_has_constructor(&surface)) {
		ZEPHIR_CALL_METHOD(NULL, &surface, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, surfaceFd);
	zephir_update_property_zval(&surface, ZEND_STRL("fd"), &_0);
	RETURN_CCTOR(&surface);
}

PHP_METHOD(Vulkan_Vk_Vk, destroySurface)
{
	zend_long instFd, surfFd;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *instance, instance_sub, *surface, surface_sub, _0, _1, _2;

	ZVAL_UNDEF(&instance_sub);
	ZVAL_UNDEF(&surface_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(instance, zephir_get_internal_ce(SL("vulkan\\vk\\vkinstance")))
		Z_PARAM_OBJECT_OF_CLASS(surface, zephir_get_internal_ce(SL("vulkan\\vk\\vksurface")))
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &instance, &surface);
	ZEPHIR_SEPARATE_PARAM(surface);
	instFd = 0;
	surfFd = 0;
	zephir_memory_observe(&_0);
	zephir_read_property(&_0, instance, ZEND_STRL("fd"), PH_NOISY_CC);
	instFd = zephir_get_intval(&_0);
	zephir_memory_observe(&_1);
	zephir_read_property(&_1, surface, ZEND_STRL("fd"), PH_NOISY_CC);
	surfFd = zephir_get_intval(&_1);
	
            php_vk_destroy_surface((uintptr_t) instFd, (uintptr_t) surfFd);
        
	ZVAL_UNDEF(&_2);
	ZVAL_LONG(&_2, 0);
	zephir_update_property_zval(surface, ZEND_STRL("fd"), &_2);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Vulkan_Vk_Vk, createSwapchain)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long width, height, ZEPHIR_LAST_CALL_STATUS, fd, instFd, physFd, devFd, queueFd, surfFd, w, h, fmt, images;
	zval *instance, instance_sub, *physical, physical_sub, *device, device_sub, *queue, queue_sub, *surface, surface_sub, *width_param = NULL, *height_param = NULL, swapchain, _0, _1, _2, _3, _4, _5;

	ZVAL_UNDEF(&instance_sub);
	ZVAL_UNDEF(&physical_sub);
	ZVAL_UNDEF(&device_sub);
	ZVAL_UNDEF(&queue_sub);
	ZVAL_UNDEF(&surface_sub);
	ZVAL_UNDEF(&swapchain);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZEND_PARSE_PARAMETERS_START(7, 7)
		Z_PARAM_OBJECT_OF_CLASS(instance, zephir_get_internal_ce(SL("vulkan\\vk\\vkinstance")))
		Z_PARAM_OBJECT_OF_CLASS(physical, zephir_get_internal_ce(SL("vulkan\\vk\\vkphysicaldevice")))
		Z_PARAM_OBJECT_OF_CLASS(device, zephir_get_internal_ce(SL("vulkan\\vk\\vkdevice")))
		Z_PARAM_OBJECT_OF_CLASS(queue, zephir_get_internal_ce(SL("vulkan\\vk\\vkqueue")))
		Z_PARAM_OBJECT_OF_CLASS(surface, zephir_get_internal_ce(SL("vulkan\\vk\\vksurface")))
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 7, 0, &instance, &physical, &device, &queue, &surface, &width_param, &height_param);
	fd = 0;
	instFd = 0;
	physFd = 0;
	devFd = 0;
	queueFd = 0;
	surfFd = 0;
	w = 0;
	h = 0;
	fmt = 0;
	images = 0;
	zephir_memory_observe(&_0);
	zephir_read_property(&_0, instance, ZEND_STRL("fd"), PH_NOISY_CC);
	instFd = zephir_get_intval(&_0);
	zephir_memory_observe(&_1);
	zephir_read_property(&_1, physical, ZEND_STRL("fd"), PH_NOISY_CC);
	physFd = zephir_get_intval(&_1);
	zephir_memory_observe(&_2);
	zephir_read_property(&_2, device, ZEND_STRL("fd"), PH_NOISY_CC);
	devFd = zephir_get_intval(&_2);
	zephir_memory_observe(&_3);
	zephir_read_property(&_3, queue, ZEND_STRL("fd"), PH_NOISY_CC);
	queueFd = zephir_get_intval(&_3);
	zephir_memory_observe(&_4);
	zephir_read_property(&_4, surface, ZEND_STRL("fd"), PH_NOISY_CC);
	surfFd = zephir_get_intval(&_4);
	
            fd = (zend_long) php_vk_swapchain_create(
                (uintptr_t) instFd,
                (uintptr_t) physFd,
                (uintptr_t) devFd,
                (uintptr_t) queueFd,
                (uintptr_t) surfFd,
                (uint32_t) width,
                (uint32_t) height
            );
            if (fd) {
                w = (zend_long) php_vk_swapchain_width((uintptr_t) fd);
                h = (zend_long) php_vk_swapchain_height((uintptr_t) fd);
                fmt = (zend_long) php_vk_swapchain_format((uintptr_t) fd);
                images = (zend_long) php_vk_swapchain_image_count((uintptr_t) fd);
            }
        
	ZEPHIR_INIT_VAR(&swapchain);
	object_init_ex(&swapchain, vulkan_vk_vkswapchain_ce);
	if (zephir_has_constructor(&swapchain)) {
		ZEPHIR_CALL_METHOD(NULL, &swapchain, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	ZVAL_UNDEF(&_5);
	ZVAL_LONG(&_5, fd);
	zephir_update_property_zval(&swapchain, ZEND_STRL("fd"), &_5);
	ZVAL_UNDEF(&_5);
	ZVAL_LONG(&_5, w);
	zephir_update_property_zval(&swapchain, ZEND_STRL("width"), &_5);
	ZVAL_UNDEF(&_5);
	ZVAL_LONG(&_5, h);
	zephir_update_property_zval(&swapchain, ZEND_STRL("height"), &_5);
	ZVAL_UNDEF(&_5);
	ZVAL_LONG(&_5, fmt);
	zephir_update_property_zval(&swapchain, ZEND_STRL("format"), &_5);
	ZVAL_UNDEF(&_5);
	ZVAL_LONG(&_5, images);
	zephir_update_property_zval(&swapchain, ZEND_STRL("imageCount"), &_5);
	RETURN_CCTOR(&swapchain);
}

PHP_METHOD(Vulkan_Vk_Vk, destroySwapchain)
{
	zend_long fd;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *swapchain, swapchain_sub, _0, _1;

	ZVAL_UNDEF(&swapchain_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(swapchain, zephir_get_internal_ce(SL("vulkan\\vk\\vkswapchain")))
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &swapchain);
	ZEPHIR_SEPARATE_PARAM(swapchain);
	fd = 0;
	zephir_memory_observe(&_0);
	zephir_read_property(&_0, swapchain, ZEND_STRL("fd"), PH_NOISY_CC);
	fd = zephir_get_intval(&_0);
	
            php_vk_swapchain_destroy((uintptr_t) fd);
        
	ZVAL_UNDEF(&_1);
	ZVAL_LONG(&_1, 0);
	zephir_update_property_zval(swapchain, ZEND_STRL("fd"), &_1);
	ZVAL_UNDEF(&_1);
	ZVAL_LONG(&_1, 0);
	zephir_update_property_zval(swapchain, ZEND_STRL("width"), &_1);
	ZVAL_UNDEF(&_1);
	ZVAL_LONG(&_1, 0);
	zephir_update_property_zval(swapchain, ZEND_STRL("height"), &_1);
	ZVAL_UNDEF(&_1);
	ZVAL_LONG(&_1, 0);
	zephir_update_property_zval(swapchain, ZEND_STRL("format"), &_1);
	ZVAL_UNDEF(&_1);
	ZVAL_LONG(&_1, 0);
	zephir_update_property_zval(swapchain, ZEND_STRL("imageCount"), &_1);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Vulkan_Vk_Vk, resizeSwapchain)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long width, height, result, fd, w, h, fmt, images;
	zval *swapchain, swapchain_sub, *width_param = NULL, *height_param = NULL, _0, _1$$3;

	ZVAL_UNDEF(&swapchain_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(swapchain, zephir_get_internal_ce(SL("vulkan\\vk\\vkswapchain")))
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &swapchain, &width_param, &height_param);
	ZEPHIR_SEPARATE_PARAM(swapchain);
	result = -1;
	fd = 0;
	w = 0;
	h = 0;
	fmt = 0;
	images = 0;
	zephir_memory_observe(&_0);
	zephir_read_property(&_0, swapchain, ZEND_STRL("fd"), PH_NOISY_CC);
	fd = zephir_get_intval(&_0);
	
            result = (zend_long) php_vk_swapchain_resize((uintptr_t) fd, (uint32_t) width, (uint32_t) height);
            if (result == 0 && fd) {
                w = (zend_long) php_vk_swapchain_width((uintptr_t) fd);
                h = (zend_long) php_vk_swapchain_height((uintptr_t) fd);
                fmt = (zend_long) php_vk_swapchain_format((uintptr_t) fd);
                images = (zend_long) php_vk_swapchain_image_count((uintptr_t) fd);
            }
        
	if (result == 0) {
		ZVAL_UNDEF(&_1$$3);
		ZVAL_LONG(&_1$$3, w);
		zephir_update_property_zval(swapchain, ZEND_STRL("width"), &_1$$3);
		ZVAL_UNDEF(&_1$$3);
		ZVAL_LONG(&_1$$3, h);
		zephir_update_property_zval(swapchain, ZEND_STRL("height"), &_1$$3);
		ZVAL_UNDEF(&_1$$3);
		ZVAL_LONG(&_1$$3, fmt);
		zephir_update_property_zval(swapchain, ZEND_STRL("format"), &_1$$3);
		ZVAL_UNDEF(&_1$$3);
		ZVAL_LONG(&_1$$3, images);
		zephir_update_property_zval(swapchain, ZEND_STRL("imageCount"), &_1$$3);
	}
	RETURN_MM_LONG(result);
}

/**
 * Present one frame: clear background, optional menu + inner rects (pixel coords, top-left origin).
 * @return 0 success; VK_ERROR_OUT_OF_DATE_KHR (-1000001004) / VK_SUBOPTIMAL_KHR (1000001003) may occur
 */
PHP_METHOD(Vulkan_Vk_Vk, presentFrame)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long menuX, menuY, menuW, menuH, innerX, innerY, innerW, innerH, accentX, accentY, accentW, accentH, result, fd, dm, di, da;
	zend_bool drawMenu, drawInner, drawAccent;
	double clearR, clearG, clearB, clearA, menuR, menuG, menuB, menuA, innerR, innerG, innerB, innerA, accentR, accentG, accentB, accentA;
	zval *swapchain, swapchain_sub, *clearR_param = NULL, *clearG_param = NULL, *clearB_param = NULL, *clearA_param = NULL, *drawMenu_param = NULL, *menuX_param = NULL, *menuY_param = NULL, *menuW_param = NULL, *menuH_param = NULL, *menuR_param = NULL, *menuG_param = NULL, *menuB_param = NULL, *menuA_param = NULL, *drawInner_param = NULL, *innerX_param = NULL, *innerY_param = NULL, *innerW_param = NULL, *innerH_param = NULL, *innerR_param = NULL, *innerG_param = NULL, *innerB_param = NULL, *innerA_param = NULL, *drawAccent_param = NULL, *accentX_param = NULL, *accentY_param = NULL, *accentW_param = NULL, *accentH_param = NULL, *accentR_param = NULL, *accentG_param = NULL, *accentB_param = NULL, *accentA_param = NULL, _0;

	ZVAL_UNDEF(&swapchain_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(4, 32)
		Z_PARAM_OBJECT_OF_CLASS(swapchain, zephir_get_internal_ce(SL("vulkan\\vk\\vkswapchain")))
		Z_PARAM_ZVAL(clearR)
		Z_PARAM_ZVAL(clearG)
		Z_PARAM_ZVAL(clearB)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(clearA)
		Z_PARAM_BOOL(drawMenu)
		Z_PARAM_LONG(menuX)
		Z_PARAM_LONG(menuY)
		Z_PARAM_LONG(menuW)
		Z_PARAM_LONG(menuH)
		Z_PARAM_ZVAL(menuR)
		Z_PARAM_ZVAL(menuG)
		Z_PARAM_ZVAL(menuB)
		Z_PARAM_ZVAL(menuA)
		Z_PARAM_BOOL(drawInner)
		Z_PARAM_LONG(innerX)
		Z_PARAM_LONG(innerY)
		Z_PARAM_LONG(innerW)
		Z_PARAM_LONG(innerH)
		Z_PARAM_ZVAL(innerR)
		Z_PARAM_ZVAL(innerG)
		Z_PARAM_ZVAL(innerB)
		Z_PARAM_ZVAL(innerA)
		Z_PARAM_BOOL(drawAccent)
		Z_PARAM_LONG(accentX)
		Z_PARAM_LONG(accentY)
		Z_PARAM_LONG(accentW)
		Z_PARAM_LONG(accentH)
		Z_PARAM_ZVAL(accentR)
		Z_PARAM_ZVAL(accentG)
		Z_PARAM_ZVAL(accentB)
		Z_PARAM_ZVAL(accentA)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 4, 28, &swapchain, &clearR_param, &clearG_param, &clearB_param, &clearA_param, &drawMenu_param, &menuX_param, &menuY_param, &menuW_param, &menuH_param, &menuR_param, &menuG_param, &menuB_param, &menuA_param, &drawInner_param, &innerX_param, &innerY_param, &innerW_param, &innerH_param, &innerR_param, &innerG_param, &innerB_param, &innerA_param, &drawAccent_param, &accentX_param, &accentY_param, &accentW_param, &accentH_param, &accentR_param, &accentG_param, &accentB_param, &accentA_param);
	clearR = zephir_get_doubleval(clearR_param);
	clearG = zephir_get_doubleval(clearG_param);
	clearB = zephir_get_doubleval(clearB_param);
	if (!clearA_param) {
		clearA = 1.0;
	} else {
		clearA = zephir_get_doubleval(clearA_param);
	}
	if (!drawMenu_param) {
		drawMenu = 0;
	} else {
		}
	if (!menuX_param) {
		menuX = 0;
	} else {
		}
	if (!menuY_param) {
		menuY = 0;
	} else {
		}
	if (!menuW_param) {
		menuW = 0;
	} else {
		}
	if (!menuH_param) {
		menuH = 0;
	} else {
		}
	if (!menuR_param) {
		menuR = 0.0;
	} else {
		menuR = zephir_get_doubleval(menuR_param);
	}
	if (!menuG_param) {
		menuG = 0.0;
	} else {
		menuG = zephir_get_doubleval(menuG_param);
	}
	if (!menuB_param) {
		menuB = 0.0;
	} else {
		menuB = zephir_get_doubleval(menuB_param);
	}
	if (!menuA_param) {
		menuA = 1.0;
	} else {
		menuA = zephir_get_doubleval(menuA_param);
	}
	if (!drawInner_param) {
		drawInner = 0;
	} else {
		}
	if (!innerX_param) {
		innerX = 0;
	} else {
		}
	if (!innerY_param) {
		innerY = 0;
	} else {
		}
	if (!innerW_param) {
		innerW = 0;
	} else {
		}
	if (!innerH_param) {
		innerH = 0;
	} else {
		}
	if (!innerR_param) {
		innerR = 0.0;
	} else {
		innerR = zephir_get_doubleval(innerR_param);
	}
	if (!innerG_param) {
		innerG = 0.0;
	} else {
		innerG = zephir_get_doubleval(innerG_param);
	}
	if (!innerB_param) {
		innerB = 0.0;
	} else {
		innerB = zephir_get_doubleval(innerB_param);
	}
	if (!innerA_param) {
		innerA = 1.0;
	} else {
		innerA = zephir_get_doubleval(innerA_param);
	}
	if (!drawAccent_param) {
		drawAccent = 0;
	} else {
		}
	if (!accentX_param) {
		accentX = 0;
	} else {
		}
	if (!accentY_param) {
		accentY = 0;
	} else {
		}
	if (!accentW_param) {
		accentW = 0;
	} else {
		}
	if (!accentH_param) {
		accentH = 0;
	} else {
		}
	if (!accentR_param) {
		accentR = 0.0;
	} else {
		accentR = zephir_get_doubleval(accentR_param);
	}
	if (!accentG_param) {
		accentG = 0.0;
	} else {
		accentG = zephir_get_doubleval(accentG_param);
	}
	if (!accentB_param) {
		accentB = 0.0;
	} else {
		accentB = zephir_get_doubleval(accentB_param);
	}
	if (!accentA_param) {
		accentA = 1.0;
	} else {
		accentA = zephir_get_doubleval(accentA_param);
	}
	result = -1;
	fd = 0;
	dm = 0;
	di = 0;
	da = 0;
	zephir_memory_observe(&_0);
	zephir_read_property(&_0, swapchain, ZEND_STRL("fd"), PH_NOISY_CC);
	fd = zephir_get_intval(&_0);
	if (drawMenu) {
		dm = 1;
	}
	if (drawInner) {
		di = 1;
	}
	if (drawAccent) {
		da = 1;
	}
	
            result = (zend_long) php_vk_swapchain_frame(
                (uintptr_t) fd,
                (float) clearR,
                (float) clearG,
                (float) clearB,
                (float) clearA,
                (int) dm,
                (int) menuX,
                (int) menuY,
                (int) menuW,
                (int) menuH,
                (float) menuR,
                (float) menuG,
                (float) menuB,
                (float) menuA,
                (int) di,
                (int) innerX,
                (int) innerY,
                (int) innerW,
                (int) innerH,
                (float) innerR,
                (float) innerG,
                (float) innerB,
                (float) innerA,
                (int) da,
                (int) accentX,
                (int) accentY,
                (int) accentW,
                (int) accentH,
                (float) accentR,
                (float) accentG,
                (float) accentB,
                (float) accentA
            );
        
	RETURN_MM_LONG(result);
}

/**
 * Present one frame from a packed RGBA8 buffer (width*height*4 bytes).
 * scaleX/scaleY map logical pixels to framebuffer pixels (Retina).
 * @return 0 success; OUT_OF_DATE / SUBOPTIMAL may occur
 */
PHP_METHOD(Vulkan_Vk_Vk, presentRgba8)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	double scaleX, scaleY, clearR, clearG, clearB, clearA;
	zend_long width, height, result, fd;
	zval pixels;
	zval *swapchain, swapchain_sub, *pixels_param = NULL, *width_param = NULL, *height_param = NULL, *scaleX_param = NULL, *scaleY_param = NULL, *clearR_param = NULL, *clearG_param = NULL, *clearB_param = NULL, *clearA_param = NULL, _0;

	ZVAL_UNDEF(&swapchain_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&pixels);
	ZEND_PARSE_PARAMETERS_START(4, 10)
		Z_PARAM_OBJECT_OF_CLASS(swapchain, zephir_get_internal_ce(SL("vulkan\\vk\\vkswapchain")))
		Z_PARAM_STR(pixels)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(scaleX)
		Z_PARAM_ZVAL(scaleY)
		Z_PARAM_ZVAL(clearR)
		Z_PARAM_ZVAL(clearG)
		Z_PARAM_ZVAL(clearB)
		Z_PARAM_ZVAL(clearA)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 4, 6, &swapchain, &pixels_param, &width_param, &height_param, &scaleX_param, &scaleY_param, &clearR_param, &clearG_param, &clearB_param, &clearA_param);
	zephir_get_strval(&pixels, pixels_param);
	if (!scaleX_param) {
		scaleX = 1.0;
	} else {
		scaleX = zephir_get_doubleval(scaleX_param);
	}
	if (!scaleY_param) {
		scaleY = 1.0;
	} else {
		scaleY = zephir_get_doubleval(scaleY_param);
	}
	if (!clearR_param) {
		clearR = 0.0;
	} else {
		clearR = zephir_get_doubleval(clearR_param);
	}
	if (!clearG_param) {
		clearG = 0.0;
	} else {
		clearG = zephir_get_doubleval(clearG_param);
	}
	if (!clearB_param) {
		clearB = 0.0;
	} else {
		clearB = zephir_get_doubleval(clearB_param);
	}
	if (!clearA_param) {
		clearA = 1.0;
	} else {
		clearA = zephir_get_doubleval(clearA_param);
	}
	result = -1;
	fd = 0;
	zephir_memory_observe(&_0);
	zephir_read_property(&_0, swapchain, ZEND_STRL("fd"), PH_NOISY_CC);
	fd = zephir_get_intval(&_0);
	
            size_t need = (size_t) width * (size_t) height * 4u;
            if (width <= 0 || height <= 0 || Z_STRLEN(pixels) < need) {
                result = -1;
            } else {
                result = (zend_long) php_vk_swapchain_present_rgba8(
                    (uintptr_t) fd,
                    (const uint8_t *) Z_STRVAL(pixels),
                    (uint32_t) width,
                    (uint32_t) height,
                    (float) scaleX,
                    (float) scaleY,
                    (float) clearR,
                    (float) clearG,
                    (float) clearB,
                    (float) clearA
                );
            }
        
	RETURN_MM_LONG(result);
}

