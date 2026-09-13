---
type: Trap
title: Memory types are not a fixed menu — V3D offers exactly one
description: >-
  MoltenVK offers three memory types, V3D offers one, and that one is both
  DEVICE_LOCAL and HOST_VISIBLE. Only a subset test over propertyFlags picks
  correctly on both; an equality test picks nothing on the Pi.
resource: examples/proof_headless.php
tags: [trap, memory, v3d, moltenvk, portability, vulkan]
status: stable
generated:
  by: claude-fable-5.1
  at: 2026-09-13T00:00:00Z
---

# Memory types differ per driver, and V3D has exactly one

Measured 2026-09-13 through `VkPhysicalDeviceMemoryProperties::unpack`, the
same struct class the proof uses.

## Mac — MoltenVK 1.4.2, Apple M1 Pro

3 memory types on 1 heap (16 GiB, `DEVICE_LOCAL`):

| type | `propertyFlags` | meaning |
|---:|---|---|
| 0 | `0x01` | `DEVICE_LOCAL` |
| 1 | `0x0f` | `DEVICE_LOCAL \| HOST_VISIBLE \| HOST_COHERENT \| HOST_CACHED` |
| 2 | `0x11` | `DEVICE_LOCAL \| LAZILY_ALLOCATED` |

## Pi — Mesa 26.2 V3D 7.1.7.0

**1 memory type** on 1 heap (4 GiB, `DEVICE_LOCAL`):

| type | `propertyFlags` | meaning |
|---:|---|---|
| 0 | `0x07` | `DEVICE_LOCAL \| HOST_VISIBLE \| HOST_COHERENT` |

llvmpipe on the same box, for contrast, has one type with `0x0f`.

## What follows

- **A subset test is the only correct selector.**
  `($propertyFlags & $required) === $required` finds type 0 on the Mac for the
  colour image and type 1 for the host-visible buffers, and finds the single
  type 0 on the Pi for both. An equality test (`$propertyFlags === $required`)
  finds nothing at all on the Pi, because V3D's only type carries three bits
  and the image asks for one. `examples/proof_headless.php`'s `$memoryTypeIndex`
  closure is the subset test, and it is the only memory judgement the proof
  makes.
- **`memoryTypeBits` still has to be honoured.** It is a bitmask over type
  indices, not a set of property flags, and it comes from
  `vkGetImageMemoryRequirements` / `vkGetBufferMemoryRequirements` per resource.
  On a one-type device the mask is always `0x1`, which makes it easy to write
  code that ignores the mask and still passes on the Pi.
- **"Device-local" and "host-visible" are not opposites.** On a unified-memory
  part they are routinely the same memory. Code that assumes a staging buffer
  is *required* is carrying a discrete-GPU assumption neither of these boxes
  has.
- **`LAZILY_ALLOCATED` (`0x10`) is a real type on the Mac** and a first-match
  scan can reach it if the required mask is loose. Ask for the bits you need
  and take the first type that has all of them; do not ask for "not
  device-local" or scan backwards.

None of this is in the extension. `VkPhysicalDeviceMemoryProperties` is bound
like every other struct and reports exactly what the driver said; choosing a
type is the caller's opinion, and in this repo the caller is the proof.
