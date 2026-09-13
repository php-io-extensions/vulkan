---
type: Trap
title: MoltenVK is a portability driver — and the extension does nothing about it
description: >-
  On the Mac an instance that does not ask for portability enumeration finds
  no physical devices at all. That is the caller's job, not the binding's.
tags: [trap, darwin, moltenvk, portability, vulkan]
status: stable
generated:
  by: claude-fable-5.1
  at: 2026-09-13T00:00:00Z
---

# MoltenVK portability

Measured on this box, 2026-09-13: macOS 24.4.0, Apple M1 Pro, Homebrew
`vulkan-loader` 1.4.357.0, `vulkan-headers` 1.4.357.0, `molten-vk` 1.4.2.

## The rule that bites first

MoltenVK is a **portability driver**, not a conformant Vulkan implementation.
The loader therefore hides its physical devices from an instance that has not
opted in. An instance created without

- the `VK_KHR_portability_enumeration` instance extension enabled, **and**
- `VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR` (`0x1`) in
  `VkInstanceCreateInfo::flags`

will be created successfully and then enumerate **zero** physical devices on a
Mac that has a perfectly good GPU. The symptom is not an error; it is an empty
list.

## The rule that does NOT bite, and why that is worse

The Vulkan spec requires a device created on a physical device that advertises
`VK_KHR_portability_subset` to enable that extension
(VUID-VkDeviceCreateInfo-pProperties-04451). **That requirement is not
enforced by the driver.** Measured on this box, 2026-09-13, with
`VK_KHR_portability_subset` deliberately left out of `VkDeviceCreateInfo`:

```
vkCreateDevice WITHOUT VK_KHR_portability_subset -> VkResult 0
```

It succeeds. Neither the Homebrew loader nor MoltenVK refuses it, and there is
no Khronos validation layer installed on either box
(`/opt/homebrew/share/vulkan/explicit_layer.d` does not exist on the Mac; the
Pi has only Mesa's and Intel's layers), so nothing says a word. A caller that
omits it is out of spec and will not find out here — it will find out on
someone else's machine, or the first time validation is switched on.

`examples/proof_headless.php` enumerates the device's extensions and enables
`VK_KHR_portability_subset` when it is listed, which on this Mac it is (it is
one of the 130 the M1 Pro reports). That is correctness by choice, not by
error message.

## The extension does none of this

It fills in no `sType`, sets no flag and enables no extension — that is the
whole point of a 1:1 layer. Both proofs do it, in PHP, with the constants
inlined and cited:

```php
$isDarwin = PHP_OS_FAMILY === 'Darwin';
$instanceExtNames = $isDarwin ? ['VK_KHR_portability_enumeration'] : [];
// ... and VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR in flags
```

`structure-check.php` asserts that `PHP_OS_FAMILY` appears in exactly one place
in **each** proof: it is one decision, made once, by the caller. In
`proof_headless.php` that single `$isDarwin` covers both the instance
extension+flag and the device-extension search.

## The other Darwin facts

- The Homebrew loader discovers `/opt/homebrew/etc/vulkan/icd.d/MoltenVK_icd.json`
  with **no environment variables set**. Nothing is bundled and nothing is
  compiled in. `install-macos.sh` preflights `vulkan-headers`, `vulkan-loader`,
  `molten-vk` and that manifest, and links against the Homebrew loader with an
  `-Wl,-rpath,/opt/homebrew/lib`.
- MoltenVK implements the **portability subset**: no geometry shaders, no
  triangle fans, no wide lines. That is a device-limits fact for a caller to
  read out of `VkPhysicalDevicePortabilitySubsetPropertiesKHR` (bound here), not
  something this extension knows. `examples/proof_headless.php` steers clear of
  all three by construction — a `VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST` of three
  vertices, `lineWidth` 1.0, and only a vertex and a fragment stage — which is
  why the same script draws the same bytes on MoltenVK and on V3D.
- The `metal/moltenvk` sibling directory is retired. Interop is
  `VK_EXT_metal_objects` (bound here); configuration is `VK_EXT_layer_settings`
  (its two structs are bound here).
