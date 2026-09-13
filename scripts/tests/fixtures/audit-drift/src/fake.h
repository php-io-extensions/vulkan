/*
 * NEGATIVE CONTROL: the @audit marker claims 3 commands; the registry has 2.
 */

#ifndef FIXTURE_AUDIT_H
#define FIXTURE_AUDIT_H

#include <php.h>

/*@audit feature VK\VK10 VK_VERSION_1_0 3 */
/*@audit feature VK\VK11 VK_VERSION_1_1 0 */
/*@audit feature VK\VK12 VK_VERSION_1_2 0 */
/*@audit feature VK\VK13 VK_VERSION_1_3 0 */
/*@audit feature VK\VK14 VK_VERSION_1_4 0 */
/*@audit extension Ext\KHRSurface VK_KHR_surface 0 */
/*@audit extension Ext\KHRSwapchain VK_KHR_swapchain 0 */
/*@audit extension Ext\KHRWaylandSurface VK_KHR_wayland_surface 0 */
/*@audit extension Ext\KHRXcbSurface VK_KHR_xcb_surface 0 */
/*@audit extension Ext\KHRXlibSurface VK_KHR_xlib_surface 0 */
/*@audit extension Ext\EXTMetalSurface VK_EXT_metal_surface 0 */
/*@audit extension Ext\EXTMetalObjects VK_EXT_metal_objects 0 */
/*@audit extension Ext\EXTDebugUtils VK_EXT_debug_utils 0 */

/*@zep VK\VK10 vkFakeOne(int instance) -> int */
zend_long phpvk_vk10_vkfakeone(zval *instance);

/*@zep VK\VK10 vkFakeTwo(int instance) -> void */
void phpvk_vk10_vkfaketwo(zval *instance);

/*@zep Struct\VkFakeInfo pack(array members) -> int */
zend_long phpvk_struct_vkfakeinfo_pack(zval *members);

/*@zep Struct\VkFakeInfo packInto(int ptr, array members) -> void */
void phpvk_struct_vkfakeinfo_packinto(zval *ptr, zval *members);

/*@zep Struct\VkFakeInfo unpack(int ptr) -> array */
void phpvk_struct_vkfakeinfo_unpack(zval *return_value, zval *ptr);

/*@zep Struct\VkFakeInfo size() -> int */
zend_long phpvk_struct_vkfakeinfo_size(void);

#endif
