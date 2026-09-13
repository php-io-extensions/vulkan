/*
 * Fixture header: two well-formed command bindings, one of each return shape
 * the parity guard has to understand, plus one struct-tier binding, which is
 * held to the opposite composite rule (zero resolutions, zero calls).
 */

#ifndef FIXTURE_FAKE_H
#define FIXTURE_FAKE_H

#include <php.h>

/*@zep VK\VK10 vkFakeOne(int instance) -> int */
zend_long phpvk_vk10_vkfakeone(zval *instance);

/*@zep VK\VK10 vkFakeTwo(int instance) -> void */
void phpvk_vk10_vkfaketwo(zval *instance);

/*@zep Struct\VkFakeInfo size() -> int */
zend_long phpvk_struct_vkfakeinfo_size(void);

/*@zep Struct\VkFakeInfo pack(array members) -> int */
zend_long phpvk_struct_vkfakeinfo_pack(zval *members);

#endif
