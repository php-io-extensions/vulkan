---
okf_version: "0.2"
---

# vulkan — traps

Failure modes this extension has already hit, or is structurally exposed to.
Read the one relevant to the task; these are not a tutorial.

- [runtime-resolution-not-linking.md](/traps/runtime-resolution-not-linking.md)
  — no *command* is linked, exactly one *symbol* is, and a binding that names a
  second one breaks the one-`.so`-two-boxes contract.
- [pointer-bits-only.md](/traps/pointer-bits-only.md) — what the pointer rule
  buys, what it costs, and where the only guard is.
- [no-window-in-ext.md](/traps/no-window-in-ext.md) — this extension binds the
  WSI surface commands and never creates a window or a platform handle.
- [moltenvk-portability.md](/traps/moltenvk-portability.md) — on the Mac an
  instance that does not ask for portability enumeration finds no devices at
  all, and the device is a portability subset.
- [no-platform-dev-packages.md](/traps/no-platform-dev-packages.md) — no
  wayland, xcb or X11 development package is needed to build this, and one
  header is the reason.
- [loader-clamps-device-version.md](/traps/loader-clamps-device-version.md) —
  `VkPhysicalDeviceProperties::apiVersion` is not the device's ceiling; it is
  the minimum of that and what your `VkApplicationInfo` asked for.
- [no-null-cstring-parameter.md](/traps/no-null-cstring-parameter.md) — the four
  commands taking a `const char *` take a PHP string, which is never NULL; `""`
  is the spelling, and the loader accepts it where NULL is meaningful.
- [memory-types-differ-per-driver.md](/traps/memory-types-differ-per-driver.md)
  — MoltenVK offers three memory types, V3D offers exactly one and it is both
  device-local and host-visible; only a subset test over `propertyFlags` picks
  correctly on both.
