---
type: Trap
title: Pointer bits only — what the rule buys and what it costs
description: >-
  Every pointer crosses as a raw integer. That is what keeps the layer
  opinion-free; it also means the extension cannot protect you from a pointer
  it did not allocate.
tags: [trap, pointers, memory, safety, vulkan]
status: stable
generated:
  by: claude-fable-5.1
  at: 2026-09-13T00:00:00Z
---

# Pointer bits only

Every pointer in this binding — parameter, return value or struct member —
crosses the boundary as **raw pointer bits in a PHP `int`, `0 = NULL`**. The
single exception is a `const char *` command parameter, which is a PHP string.

## What it buys

Marshalling `uint32_t *pPhysicalDeviceCount` as a PHP reference, or
`VkPhysicalDevice *pPhysicalDevices` as a PHP array, would mean the extension
holding a table of how many elements every out-parameter of every command
writes, and in what order the two-call idiom must be used. That is exactly the
Vulkan opinion a 1:1 layer must not hold. It lives one layer up, in
jovian/vulkan.

The rule is also what makes the generator possible: 267 commands and 368
structs are emitted from a table with no per-command branch in it.

## What it costs

`Bridge::alloc`, `Bridge::cstring` and `Struct::pack` register the blocks they
create, so `Bridge::write` and `Bridge::read` bounds-check those and
`Bridge::free` refuses a pointer this extension never allocated.

**Nothing else is checked, and nothing else can be.** A pointer that came from
`vkMapMemory`, from another extension, or from arithmetic you did in PHP has no
extent this extension knows, and `write`/`read`/`packInto` will use it as
given. Negative offsets and lengths are always refused; that is the whole of
the protection.

That is deliberate — writing into mapped device memory is the normal way to
feed Vulkan and must work — but it means **a wrong integer here is a
segfault, not an exception.** Treat a pointer int the way you would treat a
pointer in C.

`examples/proof_headless.php` is the live demonstration on both boxes: it fills
its vertex buffer with

```php
$ok(VK10::vkMapMemory($device, $vertexMemory, 0, VK_WHOLE_SIZE, 0, $mappedOut), 'vkMapMemory(vertex)');
$mapped = unpack('P', Bridge::read($mappedOut, 0, 8))[1];
Bridge::write($mapped, 0, pack('f*', -0.5, 0.5, 0.5, 0.5, 0.0, -0.5));
```

`$mappedOut` is a tracked 8-byte block and `Bridge::read` bounds-checks it;
`$mapped` is the driver's own address and `Bridge::write` does not. Both halves
of the rule, three lines apart. Note also `VK_WHOLE_SIZE`, which is `(~0ULL)`
and reaches the C as `-1` — the 64-bit wrap, exercised for real.

## The idiom

```php
$countOut = Bridge::alloc(4);
VK10::vkEnumeratePhysicalDevices($instance, $countOut, 0);
$count = unpack('V', Bridge::read($countOut, 0, 4))[1];

$devs = Bridge::alloc($count * 8);
VK10::vkEnumeratePhysicalDevices($instance, $countOut, $devs);
$first = unpack('P', Bridge::read($devs, 0, 8))[1];

Bridge::free($devs);
Bridge::free($countOut);
```

`pack()`/`unpack()` do the typing; `V` is `uint32`, `P` is a 64-bit pointer or
handle. Free what you allocate — the module teardown sweeps what you miss, but
only at process exit.
