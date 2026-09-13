---
type: Trap
title: A const char * parameter cannot be NULL — pass ""
description: >-
  The four commands that take a const char * take a PHP string, and a PHP
  string is never a null pointer. For the two where NULL is meaningful the
  Vulkan loader treats "" as none, which is why the headless proof works.
resource: examples/proof_headless.php
tags: [trap, strings, loader, extensions, vulkan]
status: stable
generated:
  by: claude-fable-5.1
  at: 2026-09-13T00:00:00Z
---

# A `const char *` parameter cannot be NULL

Spec §4's type table has one exception to the pointer rule: a `const char *`
**command parameter** crosses as a PHP `string`, not as pointer bits. Zephir
emits `Z_PARAM_STR` for it, which is not nullable, so there is no PHP value
that reaches the C as a null pointer — `null` is a `TypeError` and `""` is a
pointer to a zero-length string.

Exactly four commands in scope take one:

| command | parameter | is NULL meaningful? |
|---|---|---|
| `vkGetInstanceProcAddr` | `pName` | no — NULL is undefined behaviour |
| `vkGetDeviceProcAddr` | `pName` | no |
| `vkEnumerateInstanceExtensionProperties` | `pLayerName` | **yes** — NULL means "the implementation's own extensions" |
| `vkEnumerateDeviceExtensionProperties` | `pLayerName` | **yes** — same |

## The measurement that makes this survivable

Measured 2026-09-13 on the Mac (Homebrew `vulkan-loader` 1.4.357.0, MoltenVK
1.4.2, Apple M1 Pro), calling
`VK10::vkEnumerateDeviceExtensionProperties($physicalDevice, '', $countOut, $p)`:

```
result(empty layer)=0
extCount=130
portability_subset: LISTED
sample: VK_KHR_16bit_storage, VK_KHR_8bit_storage, VK_KHR_bind_memory2, ...
```

The Khronos loader's trampoline tests `pLayerName == NULL || strlen(pLayerName) == 0`,
so an empty string takes the same branch NULL does. `examples/proof_headless.php`
depends on that: it is how the proof finds out whether the Mac's device
advertises `VK_KHR_portability_subset`.

## What this is not

It is **not** a reason to change the binding. Making the parameter nullable
would put a per-command judgement (“this one may be NULL”) inside a layer whose
whole claim is that it makes none, and the type table would grow a second row
for a shape the registry does not distinguish. The cost is one documented
spelling, paid by four commands, two of which never wanted NULL anyway.

If a future loader stops accepting `""` where it accepts NULL, this is the file
that says what broke and where: the two `pLayerName` call sites in
`examples/proof_headless.php`.
