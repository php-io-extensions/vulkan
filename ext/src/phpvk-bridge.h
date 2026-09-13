/*
 * phpvk-bridge.h — the only glue in the extension.
 *
 * Three jobs, and nothing else:
 *
 *   1. The loader, which is also the gate. No Vulkan command is linked; the
 *      extension references exactly one Vulkan symbol at link time,
 *      vkGetInstanceProcAddr, and every command is resolved through it at
 *      call time by phpvk_entry(). The loader answers NULL for a command
 *      above the instance's or device's API version and for an extension
 *      that was not enabled, so "resolved" IS "available" here — which is
 *      why this binding needs no version table of its own (spec §5.2).
 *
 *      Three levels, three load calls: Bridge::load() resolves global-level
 *      commands against a NULL instance; Bridge::loadInstance(bits) resolves
 *      instance- and device-level commands through vkGetInstanceProcAddr;
 *      Bridge::loadDevice(bits) re-resolves device-level commands through
 *      vkGetDeviceProcAddr for direct dispatch. Each bumps a generation
 *      counter, which invalidates every cached slot.
 *
 *   2. Byte buffers. The pointer rule sends every pointer across as raw
 *      bits, so PHP needs somewhere to put bytes. alloc/free/write/read are
 *      that somewhere; pack()/unpack() do the typing.
 *
 *   3. C strings. pApplicationName, ppEnabledExtensionNames and pName are
 *      pointers to NUL-terminated bytes, and nothing else in the type table
 *      produces one. cstring/readCString are primitives, not opinions
 *      (spec §5.3).
 *
 * Nothing here decides anything about how Vulkan is used. No sType is
 * filled, no extension is enabled, no structure is built.
 */

#ifndef PHPVK_BRIDGE_H
#define PHPVK_BRIDGE_H

#include <php.h>
#include <stdint.h>
#include <stddef.h>

#define PHPVK_LEVEL_GLOBAL 0
#define PHPVK_LEVEL_INSTANCE 1
#define PHPVK_LEVEL_DEVICE 2

/*
 * One cached entry point. Generated bodies declare a function-static slot,
 * so a resolved pointer costs one predictable branch per call. generation is
 * the load() epoch this answer came from; a slot from an older epoch is
 * re-resolved rather than serving a latched "missing" forever.
 */
typedef struct {
    void *fn;
    int state;                /* 0 = unresolved, 1 = resolved, 2 = missing */
    unsigned int generation;
} phpvk_slot;

#define PHPVK_SLOT_INIT {NULL, 0, 0}

/*
 * Resolve one command at `level`, or warn and return NULL. Two distinct
 * warnings, because they mean different things to the caller:
 *   "<name>: call Bridge::loadInstance() first"      — you skipped a step
 *   "<name> is not available on this instance/device" — the loader said no
 */
void *phpvk_entry(const char *name, phpvk_slot *slot, int level);

/*
 * Register a malloc'd block so Bridge::free and the module teardown can
 * reclaim it. Returns the block. Used by Bridge::alloc, Bridge::cstring and
 * every Struct::pack.
 */
void *phpvk_track(void *block, size_t size);

/*
 * Module teardown: free every tracked block the caller did not, destroy the
 * registry, close the loader handle and invalidate every cached slot. Called
 * from the extension's MSHUTDOWN, which scripts/patch-mshutdown.php wires
 * into the generated ext/vulkan.c (Zephir compiles its own MSHUTDOWN out of
 * a release build). Safe to call more than once.
 */
void phpvk_bridge_shutdown(void);

/* ---- Vulkan\Bridge\Bridge ---- */

/*@zep Bridge\Bridge load() -> bool */
zend_long phpvk_bridge_load(void);

/*@zep Bridge\Bridge loadInstance(int instance) -> bool */
zend_long phpvk_bridge_load_instance(zval *instance);

/*@zep Bridge\Bridge loadDevice(int device) -> bool */
zend_long phpvk_bridge_load_device(zval *device);

/*@zep Bridge\Bridge isAvailable(string name) -> bool */
zend_long phpvk_bridge_is_available(zval *name);

/*@zep Bridge\Bridge procAddress(string name) -> int */
zend_long phpvk_bridge_proc_address(zval *name);

/*@zep Bridge\Bridge version() -> int */
zend_long phpvk_bridge_version(void);

/*@zep Bridge\Bridge alloc(int size) -> int */
zend_long phpvk_bridge_alloc(zval *size);

/*@zep Bridge\Bridge free(int ptr) -> void */
void phpvk_bridge_free(zval *ptr);

/*@zep Bridge\Bridge write(int ptr, int offset, string bytes) -> bool */
zend_long phpvk_bridge_write(zval *ptr, zval *offset, zval *bytes);

/*@zep Bridge\Bridge read(int ptr, int offset, int length) -> var */
void phpvk_bridge_read(zval *return_value, zval *ptr, zval *offset, zval *length);

/*@zep Bridge\Bridge cstring(string text) -> int */
zend_long phpvk_bridge_cstring(zval *text);

/*@zep Bridge\Bridge readCString(int ptr) -> string */
void phpvk_bridge_read_cstring(zval *return_value, zval *ptr);

#endif /* PHPVK_BRIDGE_H */
