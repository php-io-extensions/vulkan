# php-io-extensions/vulkan

Vulkan **1.0 through 1.4 core**, bound 1:1 into PHP, plus the window-system,
Metal-interop and debug extensions the Khronos registry defines. Structs cross
the boundary through a generated, flat pack/unpack tier.

```php
use Vulkan\Bridge\Bridge;
use Vulkan\Struct\VkApplicationInfo\VkApplicationInfo;
use Vulkan\Struct\VkInstanceCreateInfo\VkInstanceCreateInfo;
use Vulkan\VK\VK10\VK10;

Bridge::load();

$app = VkApplicationInfo::pack([
    'sType' => 0,                                   // VK_STRUCTURE_TYPE_APPLICATION_INFO
    'pApplicationName' => Bridge::cstring('demo'),
    'apiVersion' => (1 << 22) | (3 << 12),
]);
$create = VkInstanceCreateInfo::pack(['sType' => 1, 'pApplicationInfo' => $app]);
$out = Bridge::alloc(8);
VK10::vkCreateInstance($create, 0, $out);           // returns a VkResult int
$instance = unpack('P', Bridge::read($out, 0, 8))[1];
Bridge::loadInstance($instance);
```

That is the whole idea: a C tutorial reads as PHP with `VK10::` in front of
it. `vkCreateInstance` is `vkCreateInstance` — not `createInstance`, not
`Instance::create`. **Nothing is renamed and nothing is invented.**

The extension fills in nothing: no `sType` default, no enabled extension, no
constant, no convenience. Those are opinions, and opinions live in
**jovian/vulkan**, never here.

## What is here

| | classes |
|---|---|
| `Vulkan\VK\VK10\VK10` .. `Vulkan\VK\VK14\VK14` — one per feature block | 5 |
| `Vulkan\Ext\<Name>\<Name>` — `KHRSurface`, `KHRSwapchain`, `EXTDebugUtils`, `KHRWaylandSurface`, `KHRXcbSurface`, `KHRXlibSurface`, `EXTMetalSurface`, `EXTMetalObjects` | 8 |
| `Vulkan\Struct\<Name>\<Name>` — `pack`, `packInto`, `unpack`, `size` | many |
| `Vulkan\Bridge\Bridge` — the only glue | 1 |

A command lives on the class for the feature block it **first appeared in**.
`vkCreateInstance` is `VK10::vkCreateInstance` on a 1.4 loader.

Exact per-class counts are in [`.okf/index.md`](.okf/index.md) and are
re-measured against `scripts/khronos/vk.xml` by `scripts/audit-registry.php`
on every run.

## One `.so`, three levels

No Vulkan command is called by name. The extension links `libvulkan` for
exactly one symbol — `vkGetInstanceProcAddr` — and every command is resolved
through it at call time:

```php
Bridge::load();                 // global-level commands (NULL instance)
Bridge::loadInstance($vkInstance);  // instance- and device-level commands
Bridge::loadDevice($vkDevice);      // device-level commands, direct dispatch
```

The loader returns NULL for a command above the instance's or device's API
version and for an extension that is not enabled, so the same binary serves a
Mac on MoltenVK 1.4 and a Pi 5 whose V3D device reports 1.3 — and tells you
honestly which one you are on:

```php
Bridge::isAvailable('vkCmdSetLineStipple');  // a 1.4 command
VK14::vkCmdSetLineStipple(...);              // where it is missing: E_WARNING, returns 0
```

Calling a command before its level was loaded is a *different* warning, which
names the `Bridge::load*()` you are missing.

## Pointers and structs

Every pointer that is not a `const char *` parameter crosses as **raw pointer
bits in an `int`**, `0 = NULL`. `Bridge::alloc/free/write/read` give you the
bytes; `pack()`/`unpack()` give you the types; `Bridge::cstring` /
`Bridge::readCString` give you C strings, which nothing else in the table can
produce.

Structs are a flat tier — no nesting through pointers, ever:

```php
$p = Bridge::alloc(VkPhysicalDeviceProperties::size());
VK10::vkGetPhysicalDeviceProperties($physicalDevice, $p);
$props = VkPhysicalDeviceProperties::unpack($p);   // deviceName is a string
Bridge::free($p);
```

`pack()` mallocs and fills, returning bits you free with `Bridge::free`;
`packInto()` fills memory you already own (that is how you build an array of
structs); `unpack()` reads one back; `size()` is `sizeof`. A member that is a
pointer — including `pNext` — is bits, and is never followed or produced. A
member key the struct does not have is an `E_WARNING` and a refusal: a typo
must not silently vanish.

## Requirements

Two platforms, `darwin` and `linux`; never Windows. The versions in brackets
are the ones 0.8.0 was built and proved against.

| | macOS | Debian / Raspberry Pi OS |
|---|---|---|
| CPU | arm64 (Apple Silicon) [M1 Pro, macOS 15.4.1] | arm64 or x86_64 [Pi 5, Debian 13 trixie] |
| PHP | 8.4 with `phpize` [Herd 8.4.23] | 8.4 with `phpize` [`/usr/local/php84-zts` 8.4.20 ZTS] |
| Vulkan headers + loader | Homebrew `vulkan-headers`, `vulkan-loader` [1.4.357.0] | `libvulkan-dev` [1.4.309.0-1] |
| ICD (driver) | Homebrew `molten-vk` [1.4.2] | any; Mesa supplies V3D and llvmpipe [26.2.0] |
| C compiler | Apple clang [17.0.0] | gcc [Debian 14.2.0-19] |
| Zephir | 0.19 + the `zephir_parser` extension | **not needed** — `ext/` ships generated |
| Window-system dev packages | none | **none** |

`x86_64` Linux is supported by the same sources and has not been built on;
`src/vk-struct-asserts.c` would fail the build loudly rather than quietly
disagree about a struct layout.

No wayland, xcb or X11 development package is needed on either box: the WSI
structs' platform members are opaque bits, and `src/phpvk-platform.h`
forward-declares what the Khronos WSI headers name.

Changing what is *bound* additionally needs the generation box's tools — PHP,
`cc`, and `glslangValidator` only if the example shaders change. Using the
extension needs none of them.

## Install

**macOS:**

```bash
brew install vulkan-headers vulkan-loader molten-vk
composer global require phalcon/zephir          # plus the zephir_parser extension
export HERD_PHP_84_INI_SCAN_DIR="$(zsh -ic 'echo $HERD_PHP_84_INI_SCAN_DIR')"
bash install-macos.sh
```

**Debian / Ubuntu / Raspberry Pi OS:**

```bash
sudo apt install libvulkan-dev mesa-vulkan-drivers
bash build-linux.sh
```

`ext/` ships generated, so the Linux build needs only `phpize`/`make` — but it
refuses a committed `ext/` whose `.gen-stamp` no longer matches `src/`.

Both installers write a single `30-vulkan.ini` naming the absolute path of the
`.so` they just installed, and both refuse to finish unless `php --ri vulkan`
reports the version in `config.json`.

## Quick start

```bash
php examples/proof_enumerate.php
```

```
loader: 1.4.357
device 0: Apple M1 Pro api 1.3.357
PROOF_ENUMERATE_OK
```

That script is the shortest complete statement of how this extension is used,
and it runs on both boxes with no window: it loads the Bridge, creates an
instance (with portability enumeration on Darwin), loads the instance level,
enumerates the physical devices, prints each device's name and API version
through the struct tier, checks the availability contract, and destroys
everything it made. Every opinion in it — the `sType` values, the portability
flag, the API version asked for — is in the *script*.

## Proof

`examples/proof_headless.php` is the harder statement: a 64x64 offscreen frame
drawn through a real graphics pipeline — device, colour image, render pass,
framebuffer, the vendored SPIR-V in [`examples/shaders/`](examples/shaders/),
a host-visible vertex buffer written through `vkMapMemory`'s pointer, one
`vkCmdDraw(3, 1, 0, 0)`, a copy into a readback buffer — and then two pixels
checked byte for byte. No window, no display server, no swapchain.

```
device: Apple M1 Pro api 1.3.357 type 1 queueFamily 0
pixel(32,32): 255,128,64,255
pixel(0,0): 0,0,0,255
PROOF_HEADLESS_OK
```

```
device: V3D 7.1.7.0 api 1.3.354 type 1 queueFamily 0
pixel(32,32): 255,128,64,255
pixel(0,0): 0,0,0,255
PROOF_HEADLESS_OK
```

Same script, same bytes, MoltenVK on Metal and V3D on Mesa.

From the Mac, `bash scripts/pi-verify.sh` does the whole Pi round trip — push,
build, reflect, prove — and prints `PI_VERIFY_OK` only when the Pi does.

## Layering

**ext-vulkan = Vulkan + unavoidable glue. jovian/vulkan = PHP projection,
typed handles and constants. venusian = composition. surface = abstraction.**

No opinions live here. No window is opened here. No constant is defined here.

## Documentation

The knowledge bundle is [`.okf/`](.okf/) — start at
[`.okf/index.md`](.okf/index.md). [`AGENTS.md`](AGENTS.md) is the short form
for agents working on this package.

MIT. Project Saturn Studios, LLC.
