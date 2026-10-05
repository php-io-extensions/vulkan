#ifndef PHP_VULKAN_H
#define PHP_VULKAN_H

extern zend_module_entry vulkan_module_entry;
#define phpext_vulkan_ptr &vulkan_module_entry

#define PHP_VULKAN_VERSION "0.10.0"

#if defined(ZTS) && defined(COMPILE_DL_VULKAN)
ZEND_TSRMLS_CACHE_EXTERN()
#endif

#endif
