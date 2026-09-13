---
type: Trap
title: No window, ever — including no surface
description: >-
  This extension binds the WSI surface commands. It never creates a window, a
  CAMetalLayer, a wl_surface or an X11 Window, and it never will.
tags: [trap, wsi, surface, scope, vulkan]
status: stable
generated:
  by: claude-fable-5.1
  at: 2026-09-13T00:00:00Z
---

# No window, ever

`vkCreateWaylandSurfaceKHR`, `vkCreateXcbSurfaceKHR`, `vkCreateXlibSurfaceKHR`
and `vkCreateMetalSurfaceEXT` are all bound. Every one of them takes a
`VkXxxSurfaceCreateInfoKHR` whose platform members — `wl_display *`,
`xcb_connection_t *`, `Display *`, `Window`, `const CAMetalLayer *` — are
**pointer bits the caller already holds**.

Where do those bits come from? Another extension:

- macOS: a `CAMetalLayer` from ext-metal.
- Linux: SDL3's Vulkan surface support through jovian/sdl3. GTK4 has no public
  Vulkan widget.

This extension will not open a window, will not create a layer, and will not
link a window-system library to do it. That is the same line ext-opengl draws
(`GtkGLArea` and `NSOpenGLView` are other repos' waves), and it is the reason
both proofs run on a headless Pi over ssh with no display server and no seat.

`examples/proof_headless.php` is the point made in full: a complete graphics
pipeline — render pass, framebuffer, SPIR-V shader modules, vertex buffer, draw,
readback — with **no surface and no swapchain anywhere in it**. A frame does not
need a window; only *showing* one does, and showing one is somebody else's
layer.

The surface *commands* are in scope because they are Vulkan commands, and
binding them 1:1 costs nothing. Surface *creation* — deciding what a window is
— is an opinion, and opinions live in venusian and surface.
