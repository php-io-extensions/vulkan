---
type: Trap
title: apiVersion is not the device's ceiling
description: >-
  VkPhysicalDeviceProperties::apiVersion can be clamped to whatever your
  VkApplicationInfo asked for. Measured: the same M1 Pro reports 1.3 or 1.4
  depending only on the request.
tags: [trap, loader, version, vulkan]
status: stable
generated:
  by: claude-fable-5.1
  at: 2026-09-13T00:00:00Z
---

# `apiVersion` is not the device's ceiling

Measured 2026-09-13 on the Mac (Homebrew loader 1.4.357, MoltenVK 1.4.2, Apple
M1 Pro), running `examples/proof_enumerate.php` unchanged except for the
version it asks for:

| `VkApplicationInfo::apiVersion` | `VkPhysicalDeviceProperties::apiVersion` |
|---|---|
| `VK_API_VERSION_1_3` | `1.3.357` |
| `VK_API_VERSION_1_4` | `1.4.357` |

`vulkaninfo --summary`, which asks for the highest version it can, reports
`1.4.357`. **The device did not change.** The loader clamped what it reported
to what the instance asked for.

The Pi, on the same run and the same 1.3 request, is not clamped the same way:

```
loader: 1.4.309
device 0: V3D 7.1.7.0 api 1.3.354
device 1: llvmpipe (LLVM 19.1.7, 128 bits) api 1.4.354
```

llvmpipe reports 1.4 despite a 1.3 request. So the clamping is a property of
the loader/ICD pair, not a rule you can rely on in either direction.

## What to do about it

- **Do not read `VkPhysicalDeviceProperties::apiVersion` as "what this GPU can
  do."** Read it as "what this instance will let me use on this GPU", which is
  what it is for.
- To discover a device's real ceiling, ask for the highest version your loader
  supports — `Bridge::version()` tells you what that is — and then read the
  device properties.
- The gate in this extension is unaffected either way: a command above the
  instance's version simply fails to resolve and warns. Resolution *is*
  availability here; the number printed by the proof is a report, not the gate.

The proof deliberately asks for 1.3, because the Pi's V3D device is a 1.3
device and the proof must be honest about the box it runs on.
