/*
 * phpvk-bridge.c — loader, byte buffers and C strings. See phpvk-bridge.h.
 *
 * This file is glue: the parity guard exempts it from the composite rule and
 * from the no-link-time-call rule, because it is the one place allowed to
 * name a Vulkan symbol — and it names exactly one, vkGetInstanceProcAddr.
 * No other file in this extension may make a native call except through
 * phpvk_entry().
 */

#include "phpvk-bridge.h"
#include "phpvk-support.h"
#include "phpvk-platform.h"
#include "phpvk-registry.h"

#include <dlfcn.h>
#include <string.h>
#include <stdlib.h>

/* ------------------------------------------------------------------ state */

/*
 * Process globals, exactly like ext-opengl's: the binding assumes one PHP
 * thread talks to one instance and one device, which is the CLI process
 * model it targets. Do not drive Vulkan from parallel PHP threads.
 */
static void *phpvk_lib = NULL;                       /* libvulkan.so.1 / libvulkan.1.dylib */
static PFN_vkGetInstanceProcAddr phpvk_gipa = NULL;
static PFN_vkGetDeviceProcAddr phpvk_gdpa = NULL;    /* from gipa(instance) in loadInstance */
static VkInstance phpvk_instance = VK_NULL_HANDLE;   /* set by loadInstance */
static VkDevice phpvk_device = VK_NULL_HANDLE;       /* set by loadDevice */

/*
 * Bumped by every load*(). A slot whose generation is older than this is
 * re-resolved on next use, so a loadDevice() after a loadInstance() genuinely
 * re-resolves instead of serving a latched answer. Starts at 1 so a
 * zero-initialised slot is always stale.
 */
static unsigned int phpvk_generation = 1;

/* Tracked block registry: pointer bits -> byte size. */
static HashTable *phpvk_blocks = NULL;

#if defined(__APPLE__)
/* Homebrew's loader; found through the link-time rpath the config.m4 patch
 * adds (-Wl,-rpath,/opt/homebrew/lib). */
#define PHPVK_LIBRARY "libvulkan.1.dylib"
#else
#define PHPVK_LIBRARY "libvulkan.so.1"
#endif

static void phpvk_bump_generation(void)
{
    phpvk_generation++;
    if (phpvk_generation == 0) {
        phpvk_generation = 1; /* 0 means "never resolved" in a fresh slot */
    }
}

/* ------------------------------------------------------------------ loader */

zend_long phpvk_bridge_load(void)
{
    if (!phpvk_lib) {
        phpvk_lib = dlopen(PHPVK_LIBRARY, RTLD_NOW | RTLD_LOCAL);
    }
    if (phpvk_lib && !phpvk_gipa) {
        phpvk_gipa = (PFN_vkGetInstanceProcAddr) dlsym(phpvk_lib, "vkGetInstanceProcAddr");
    }
    if (!phpvk_gipa) {
        /* The one linked symbol: the loader is a link-time dependency of this
         * module, so this always works even when dlopen by soname does not. */
        phpvk_gipa = vkGetInstanceProcAddr;
    }

    phpvk_bump_generation();

    if (!phpvk_gipa) {
        php_error_docref(NULL, E_WARNING,
            "no Vulkan loader could be opened (%s)", PHPVK_LIBRARY);
    }

    return phpvk_gipa ? 1 : 0;
}

zend_long phpvk_bridge_load_instance(zval *instance)
{
    if (!phpvk_gipa && !phpvk_bridge_load()) {
        return 0;
    }

    phpvk_instance = (VkInstance) phpvk_arg_ptr(instance);
    phpvk_device = VK_NULL_HANDLE;
    phpvk_gdpa = phpvk_instance
        ? (PFN_vkGetDeviceProcAddr) phpvk_gipa(phpvk_instance, "vkGetDeviceProcAddr")
        : NULL;

    phpvk_bump_generation();

    return phpvk_instance ? 1 : 0;
}

zend_long phpvk_bridge_load_device(zval *device)
{
    if (!phpvk_instance) {
        php_error_docref(NULL, E_WARNING, "loadDevice: call Bridge::loadInstance() first");

        return 0;
    }

    phpvk_device = (VkDevice) phpvk_arg_ptr(device);

    phpvk_bump_generation();

    return phpvk_device ? 1 : 0;
}

static void *phpvk_resolve(const char *name, int level)
{
    if (!phpvk_gipa) {
        return NULL;
    }

    switch (level) {
        case PHPVK_LEVEL_GLOBAL:
            return (void *) phpvk_gipa(VK_NULL_HANDLE, name);
        case PHPVK_LEVEL_INSTANCE:
            return phpvk_instance ? (void *) phpvk_gipa(phpvk_instance, name) : NULL;
        default:
            /* Device level: prefer direct dispatch, fall back to the
             * instance's dispatchable pointer when no device is loaded. */
            if (phpvk_device && phpvk_gdpa) {
                void *fn = (void *) phpvk_gdpa(phpvk_device, name);

                if (fn) {
                    return fn;
                }
            }

            return phpvk_instance ? (void *) phpvk_gipa(phpvk_instance, name) : NULL;
    }
}

void *phpvk_entry(const char *name, phpvk_slot *slot, int level)
{
    if (!phpvk_gipa) {
        php_error_docref(NULL, E_WARNING, "%s: call Bridge::load() first", name);

        return NULL;
    }
    if (level != PHPVK_LEVEL_GLOBAL && !phpvk_instance) {
        php_error_docref(NULL, E_WARNING, "%s: call Bridge::loadInstance() first", name);

        return NULL;
    }

    /* A slot from an older generation is stale: a load*() since then may
     * have changed which dispatch table answers for this name. */
    if (slot->state == 0 || slot->generation != phpvk_generation) {
        slot->fn = phpvk_resolve(name, level);
        slot->state = slot->fn ? 1 : 2;
        slot->generation = phpvk_generation;
    }
    if (slot->state != 1) {
        php_error_docref(NULL, E_WARNING, "%s is not available on this %s", name,
            level == PHPVK_LEVEL_DEVICE ? "device"
                : level == PHPVK_LEVEL_INSTANCE ? "instance" : "loader");

        return NULL;
    }

    return slot->fn;
}

zend_long phpvk_bridge_is_available(zval *name)
{
    const char *n = phpvk_arg_string(name);

    if (!n || !phpvk_gipa) {
        return 0;
    }

    return phpvk_resolve(n, phpvk_registry_level(n)) ? 1 : 0;
}

zend_long phpvk_bridge_proc_address(zval *name)
{
    const char *n = phpvk_arg_string(name);

    if (!n || !phpvk_gipa) {
        return 0;
    }

    return (zend_long) (uintptr_t) phpvk_resolve(n, phpvk_registry_level(n));
}

zend_long phpvk_bridge_version(void)
{
    typedef VkResult (*fn_enumerate_version)(uint32_t *);
    fn_enumerate_version fn;
    uint32_t version = 0;

    if (!phpvk_gipa) {
        return 0;
    }

    fn = (fn_enumerate_version) phpvk_resolve("vkEnumerateInstanceVersion", PHPVK_LEVEL_GLOBAL);
    if (!fn) {
        /* A 1.0 loader has no such command; that IS the answer. */
        return 0;
    }
    if (fn(&version) != VK_SUCCESS) {
        return 0;
    }

    return (zend_long) version;
}

void phpvk_bridge_shutdown(void)
{
    zend_ulong bits;

    /*
     * Tracked blocks are plain malloc'd and live in a process-global
     * registry, so nothing else will ever reclaim them. A caller that forgot
     * a Bridge::free is not a leak the process has to carry to its grave.
     */
    if (phpvk_blocks) {
        ZEND_HASH_FOREACH_NUM_KEY(phpvk_blocks, bits)
        {
            free((void *) (uintptr_t) bits);
        }
        ZEND_HASH_FOREACH_END();

        zend_hash_destroy(phpvk_blocks);
        pefree(phpvk_blocks, 1);
        phpvk_blocks = NULL;
    }

    /*
     * Closing the handle here rather than in a library destructor: at
     * MSHUTDOWN the module is being unloaded deliberately and PHP is still
     * up, which is the only point where dlclose is well ordered against the
     * loader's own teardown.
     */
    if (phpvk_lib) {
        dlclose(phpvk_lib);
        phpvk_lib = NULL;
    }
    phpvk_gipa = NULL;
    phpvk_gdpa = NULL;
    phpvk_instance = VK_NULL_HANDLE;
    phpvk_device = VK_NULL_HANDLE;

    /* Every cached slot is now stale. */
    phpvk_bump_generation();
}

/* ---------------------------------------------------------- tracked blocks */

static void phpvk_blocks_init(void)
{
    if (phpvk_blocks) {
        return;
    }
    phpvk_blocks = (HashTable *) pemalloc(sizeof(HashTable), 1);
    zend_hash_init(phpvk_blocks, 16, NULL, NULL, 1);
}

/* Returns 1 and writes *size when the pointer is a live tracked block. */
static int phpvk_block_size(zend_ulong bits, size_t *size)
{
    zval *found;

    if (!phpvk_blocks || bits == 0) {
        return 0;
    }
    found = zend_hash_index_find(phpvk_blocks, bits);
    if (!found) {
        return 0;
    }
    if (size) {
        *size = (size_t) Z_LVAL_P(found);
    }

    return 1;
}

void *phpvk_track(void *block, size_t size)
{
    zval entry;

    if (!block) {
        return NULL;
    }
    phpvk_blocks_init();
    ZVAL_LONG(&entry, (zend_long) size);
    zend_hash_index_update(phpvk_blocks, (zend_ulong) (uintptr_t) block, &entry);

    return block;
}

zend_long phpvk_bridge_alloc(zval *size)
{
    zend_long want = phpvk_arg_long(size);
    void *block;

    if (want <= 0) {
        php_error_docref(NULL, E_WARNING, "Bridge::alloc size must be greater than zero");

        return 0;
    }

    /*
     * Plain malloc, NOT pemalloc. pemalloc routes a failed allocation through
     * zend_out_of_memory(), which prints and calls exit(1) — so asking for a
     * buffer that cannot exist would kill the process instead of returning an
     * error a caller can see. malloc returns NULL instead, which is the whole
     * point. It is also the right lifetime: the registry is a process global
     * and a request-scoped block would dangle in it after request shutdown.
     */
    block = malloc((size_t) want);
    if (!block) {
        php_error_docref(NULL, E_WARNING,
            "Bridge::alloc could not allocate " ZEND_LONG_FMT " byte(s)", want);

        return 0;
    }
    memset(block, 0, (size_t) want);

    return (zend_long) (uintptr_t) phpvk_track(block, (size_t) want);
}

void phpvk_bridge_free(zval *ptr)
{
    zend_ulong bits = (zend_ulong) phpvk_arg_long(ptr);

    if (bits == 0) {
        return;
    }
    if (!phpvk_block_size(bits, NULL)) {
        php_error_docref(NULL, E_WARNING,
            "Bridge::free was given a pointer this extension did not allocate");

        return;
    }
    zend_hash_index_del(phpvk_blocks, bits);
    free((void *) (uintptr_t) bits);
}

zend_long phpvk_bridge_write(zval *ptr, zval *offset, zval *bytes)
{
    zend_ulong bits = (zend_ulong) phpvk_arg_long(ptr);
    zend_long off = phpvk_arg_long(offset);
    size_t size = 0;
    size_t len;

    if (!bytes || Z_TYPE_P(bytes) != IS_STRING) {
        php_error_docref(NULL, E_WARNING, "Bridge::write expects a string");

        return 0;
    }
    if (bits == 0) {
        php_error_docref(NULL, E_WARNING, "Bridge::write was given a NULL pointer");

        return 0;
    }
    if (off < 0) {
        php_error_docref(NULL, E_WARNING, "Bridge::write offset is negative");

        return 0;
    }
    len = Z_STRLEN_P(bytes);

    /*
     * Foreign memory is the caller's responsibility (spec §7). A tracked
     * block's extent is known, so it is checked; a pointer this extension
     * never allocated — vkMapMemory's result is the case that matters — has
     * no extent to check against and is written as given. That is the price
     * of the pointer rule, and it is the same price GL's callers pay when
     * they hand a pointer to GL.
     */
    if (phpvk_block_size(bits, &size)
        && ((size_t) off > size || len > size - (size_t) off)) {
        php_error_docref(NULL, E_WARNING,
            "Bridge::write of " ZEND_LONG_FMT " byte(s) at offset " ZEND_LONG_FMT
            " exceeds the " ZEND_LONG_FMT " byte allocation",
            (zend_long) len, off, (zend_long) size);

        return 0;
    }

    memcpy((char *) (uintptr_t) bits + off, Z_STRVAL_P(bytes), len);

    return 1;
}

void phpvk_bridge_read(zval *return_value, zval *ptr, zval *offset, zval *length)
{
    zend_ulong bits = (zend_ulong) phpvk_arg_long(ptr);
    zend_long off = phpvk_arg_long(offset);
    zend_long len = phpvk_arg_long(length);
    size_t size = 0;

    if (bits == 0) {
        php_error_docref(NULL, E_WARNING, "Bridge::read was given a NULL pointer");
        ZVAL_NULL(return_value);

        return;
    }
    if (off < 0 || len < 0) {
        php_error_docref(NULL, E_WARNING,
            "Bridge::read offset and length must not be negative");
        ZVAL_NULL(return_value);

        return;
    }
    if (phpvk_block_size(bits, &size)
        && ((size_t) off > size || (size_t) len > size - (size_t) off)) {
        php_error_docref(NULL, E_WARNING,
            "Bridge::read of " ZEND_LONG_FMT " byte(s) at offset " ZEND_LONG_FMT
            " exceeds the " ZEND_LONG_FMT " byte allocation",
            len, off, (zend_long) size);
        ZVAL_NULL(return_value);

        return;
    }

    ZVAL_STRINGL(return_value, (const char *) (uintptr_t) bits + off, (size_t) len);
}

/* -------------------------------------------------------------- C strings */

zend_long phpvk_bridge_cstring(zval *text)
{
    const char *s = phpvk_arg_string(text);
    size_t len;
    char *block;

    if (!s) {
        php_error_docref(NULL, E_WARNING, "Bridge::cstring expects a string");

        return 0;
    }
    len = Z_STRLEN_P(text);
    block = (char *) malloc(len + 1);
    if (!block) {
        php_error_docref(NULL, E_WARNING, "Bridge::cstring could not allocate %zu byte(s)", len + 1);

        return 0;
    }
    memcpy(block, s, len);
    block[len] = '\0';

    return (zend_long) (uintptr_t) phpvk_track(block, len + 1);
}

void phpvk_bridge_read_cstring(zval *return_value, zval *ptr)
{
    const char *s = (const char *) phpvk_arg_ptr(ptr);

    if (!s) {
        ZVAL_EMPTY_STRING(return_value);

        return;
    }

    ZVAL_STRINGL(return_value, s, strlen(s));
}
