/* Fixture implementation. */

#include "fake.h"
#include "phpvk-bridge.h"
#include "phpvk-support.h"

zend_long phpvk_vk10_vkfakeone(zval *instance)
{
    static phpvk_slot slot = PHPVK_SLOT_INIT;
    PFN_vkFakeOne fn = (PFN_vkFakeOne) phpvk_entry("vkFakeOne", &slot, PHPVK_LEVEL_INSTANCE);

    if (!fn) {
        return 0;
    }

    return (zend_long) fn((VkInstance) phpvk_arg_ptr(instance));
}

void phpvk_vk10_vkfaketwo(zval *instance)
{
    static phpvk_slot slot = PHPVK_SLOT_INIT;
    PFN_vkFakeTwo fn = (PFN_vkFakeTwo) phpvk_entry("vkFakeTwo", &slot, PHPVK_LEVEL_INSTANCE);

    if (!fn) {
        return;
    }

    /* NEGATIVE CONTROL: two calls through one resolved entry point. */
    fn((VkInstance) phpvk_arg_ptr(instance));
    fn((VkInstance) phpvk_arg_ptr(instance));
}

zend_long phpvk_struct_vkfakeinfo_size(void)
{
    return (zend_long) sizeof(VkFakeInfo);
}
