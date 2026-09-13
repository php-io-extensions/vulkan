/*
 * phpvk-platform.h — the only place the Khronos headers are included.
 *
 * Platform handles cross to PHP as opaque pointer bits, so the platform
 * headers are never needed: forward-declare / typedef what the WSI headers
 * name and include those headers directly. <vulkan/vulkan.h> would pull
 * <wayland-client.h>, <xcb/xcb.h> and <X11/Xlib.h> in, which would make
 * three development packages a build requirement for a binding that does not
 * touch a single one of their symbols (spec §5.4).
 *
 * sizeof and offsetof still come from the real Khronos headers, so the
 * struct tier's layout is the ABI's layout and not a guess.
 *
 * This header carries no binding annotations; the parity guard skips it.
 */

#ifndef PHPVK_PLATFORM_H
#define PHPVK_PLATFORM_H

#include <stdint.h>
#include <stddef.h>

#include <vulkan/vulkan_core.h>

/* ---- Wayland: wl_display * and wl_surface * are opaque bits ---- */
struct wl_display;
struct wl_surface;
#include <vulkan/vulkan_wayland.h>

/* ---- XCB ---- */
typedef struct xcb_connection_t xcb_connection_t;
typedef uint32_t xcb_window_t;
typedef uint32_t xcb_visualid_t;
#include <vulkan/vulkan_xcb.h>

/* ---- Xlib ---- */
typedef struct _XDisplay Display;
typedef unsigned long Window;
typedef unsigned long VisualID;
#include <vulkan/vulkan_xlib.h>

/*
 * ---- Metal ----
 * vulkan_metal.h is pure C while __OBJC__ is undefined: CAMetalLayer becomes
 * `typedef void CAMetalLayer;` and every id<MTL...> becomes void *. Nothing
 * here needs Objective-C, and nothing here is Darwin-only: the header
 * compiles on Linux too, which is why EXTMetalSurface and EXTMetalObjects
 * are built on both platforms and simply fail to resolve on the one that
 * has no Metal ICD.
 */
#include <vulkan/vulkan_metal.h>

/* ---- VK_KHR_portability_subset lives in vulkan_beta.h ---- */
#ifndef VK_ENABLE_BETA_EXTENSIONS
#define VK_ENABLE_BETA_EXTENSIONS 1
#endif
#include <vulkan/vulkan_beta.h>

#endif /* PHPVK_PLATFORM_H */
