---
type: Trap
title: No wayland, xcb or X11 development package is needed
description: >-
  src/phpvk-platform.h forward-declares what the Khronos WSI headers name, so
  the whole WSI surface builds on a box with none of those libraries' headers.
resource: src/phpvk-platform.h
tags: [trap, build, wsi, headers, vulkan]
status: stable
generated:
  by: claude-fable-5.1
  at: 2026-09-13T00:00:00Z
---

# No platform development packages

`<vulkan/vulkan.h>` includes `vulkan_wayland.h`, `vulkan_xcb.h` and
`vulkan_xlib.h` when the matching `VK_USE_PLATFORM_*` macro is set, and each of
those includes the real `<wayland-client.h>`, `<xcb/xcb.h>` or `<X11/Xlib.h>`.
Including it would make three development packages a build requirement for a
binding that does not touch a single one of their symbols.

So this extension never includes `<vulkan/vulkan.h>`. `src/phpvk-platform.h` is
the only place any Khronos header is included, and it:

1. includes `<vulkan/vulkan_core.h>` for the core API;
2. forward-declares or typedefs exactly what the WSI headers name —
   `struct wl_display`, `struct wl_surface`, `xcb_connection_t`,
   `xcb_window_t`, `xcb_visualid_t`, `Display`, `Window`, `VisualID`;
3. includes `vulkan_wayland.h`, `vulkan_xcb.h`, `vulkan_xlib.h` and
   `vulkan_metal.h` **directly**, which is legal because step 2 satisfied
   everything they reference;
4. defines `VK_ENABLE_BETA_EXTENSIONS` and includes `vulkan_beta.h`, where
   `VK_KHR_portability_subset`'s two structs live.

`vulkan_metal.h` is pure C while `__OBJC__` is undefined — `CAMetalLayer`
becomes `typedef void CAMetalLayer` and every `id<MTL…>` becomes `void *` —
which is why the Metal classes compile on Linux too.

## The half that can drift

The type table in `scripts/gen-vk-src.php` has a `PLATFORM_TYPES` entry for
every scalar this header typedefs, because the registry names those types but
does not define them. **The two must agree** — the shim is what the compiler
sees. A registry that introduces a new platform spelling stops the generator by
name rather than guessing, which is the only way that drift can surface.

`sizeof` and `offsetof` still come from the real Khronos headers, so the struct
tier's layout is the ABI's layout and not a reconstruction.
