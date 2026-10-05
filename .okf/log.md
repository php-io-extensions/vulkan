# Log

## 2026-10-05

Created the bundle for 0.10.0. The extension binds Vulkan 1:1 against the system loader: instance and device, memory and images, render passes and pipelines, commands and fences, surfaces and swapchains, and Linux dmabuf export. Constants are generated from the Pi's `vulkan_core.h` 1.4.309. The suite is 20 passed (1210 assertions) on the Pi (Mesa 26.2 V3DV) with `WAYLAND_DISPLAY=wayland-0`, and 5 passed, 15 skipped (1147 assertions) on Homebrew PHP 8.4 NTS and ZTS. The Mac skips every test that opens a device: MoltenVK needs the portability flags of slice 5. The gate is a stencil-then-cover triangle into a 4× image, resolved in the render pass, blitted, copied out, and read back.
