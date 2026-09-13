# Agent guidelines — php-io-extensions/vulkan

## Knowledge Bundle (OKF)

This package ships an Open Knowledge Format bundle at [`.okf/`](.okf/). Before changing code or advising on this package: read [`.okf/index.md`](.okf/index.md) first, open only the concepts the task needs, prefer `status: stable` over `draft`. When you learn something durable, update the affected concept(s) and append `.okf/log.md`; new or changed concepts stay `status: draft` until a human verifies them.

## Binding rules (the spec: [`.okf/binding-rules.md`](.okf/binding-rules.md))

1. **One PHP static method = one Vulkan command.** Method name = the command name verbatim: `vkCreateInstance` → `Vulkan\VK\VK10\VK10::vkCreateInstance`, `vkAcquireNextImageKHR` → `Vulkan\Ext\KHRSwapchain\KHRSwapchain::vkAcquireNextImageKHR`. A command belongs to the feature block it *first appeared in*, not to the version you are running. A struct method (`Struct\<Name>::{pack,packInto,unpack,size}`) makes **no** Vulkan call at all — it is flat memory work.
2. **`src/vk-*.{h,c}` and `src/phpvk-registry.{h,c}` are GENERATED** from the vendored `scripts/khronos/vk.xml` by `php scripts/gen-vk-src.php`. Never hand-edit them; `scripts/tests/gen-src-guard.php` will catch you. The only hand-written C is `src/phpvk-support.{h,c}`, `src/phpvk-bridge.{h,c}` and `src/phpvk-platform.h`.
3. **Never hand-write `.zep` files or optimizers** — they are generated from the `/*@zep …*/` and `/*@reserved …*/` lines in `src/*.h` by `php scripts/gen-zep.php`.
4. **Nothing is silently omitted.** Every registry command in scope is bound (`@zep`) or kept as a commented `@reserved` signature; `bound + reserved` must equal the registry's count per class (`@audit feature` / `@audit extension` markers, re-measured against `vk.xml` by `audit-registry.php`). `@audit partial <class> <reason>` sanctions a shortfall, never an excess. Only one thing may be reserved — a `PFN_*` function-pointer parameter — and the emitted line says so; **any other unmapped type stops the generator by name**. `scripts/tests/reserved-guard.php` proves both halves.
5. **The pointer rule.** Scalars → `int`/`double`/`bool`; `const char *` parameters → `string`; **every other pointer, in or out, crosses as raw pointer bits in an `int`, 0 = NULL**. Non-dispatchable handles and every 64-bit integer cross as `int` too (values above `PHP_INT_MAX` wrap; pass `-1` for `UINT64_MAX` / `VK_WHOLE_SIZE`). No `count` parameter is invented or dropped, and no per-command judgement is made anywhere. A type the table does not cover stops the generator by name.
6. **The struct tier is flat.** One class per struct/union, four methods, members marshalled by the table in [`.okf/binding-rules.md`](.okf/binding-rules.md) §Struct members. `pNext`, every pointer and every `PFN_*` member is pointer bits and is never followed. Missing keys pack as zero; an unknown key is an `E_WARNING` and a refusal, because a typo must not silently vanish. `sType` is a plain member — the caller supplies it. **Nothing silently omitted applies member by member**: `audit-registry.php` requires every registry member to be written by its fill body, read by its read body and present in its key list (`structs=368 members=2296`), and a member the table cannot express stops the generator by name — there is no `@audit partial` for a member. `src/vk-struct-asserts.c` is GENERATED from a C probe `gen-vk-src.php` compiles and runs on the generating box, so `cc` is a generation-box requirement; its `_Static_assert`s make the second platform's build the layout proof. A mismatch there is fixed on the Mac, never on the Pi. See [`.okf/struct-tier.md`](.okf/struct-tier.md).
7. **Every command is resolved at RUNTIME** through `phpvk_entry()`. The extension links `libvulkan` for exactly one symbol, `vkGetInstanceProcAddr`; no other Vulkan symbol is referenced at link time, and a binding that names one is rejected by the parity guard. See [`.okf/traps/runtime-resolution-not-linking.md`](.okf/traps/runtime-resolution-not-linking.md).
8. **A command the loader cannot resolve raises `E_WARNING("<name> is not available on this instance/device")` and returns 0.** A command called before its level was loaded raises a distinct `E_WARNING` naming the missing `Bridge::load*()` call. No exceptions, no error side channel. Vulkan's own errors are `VkResult` ints returned untouched.
9. **All glue lives in `Vulkan\Bridge\Bridge`** (`src/phpvk-bridge.{h,c}`); no other bridge class may exist, and no other file may contain platform knowledge (except `src/phpvk-platform.h`, which is only typedef shims + Khronos includes). See [`.okf/bridge.md`](.okf/bridge.md).
10. **No constants in the ext**, no defaults, no `sType` filling, no extension enabling. Enum values become PHP enums in **jovian/vulkan**. Examples carry inline ints with `vk.xml` citations until then — `examples/proof_headless.php` has 74 of them, grouped under the `<enums>` block each came from. The same rule covers shaders: `examples/shaders/*.spv` is **vendored**, compiled once on the Mac by `glslangValidator` with the command recorded in `examples/shaders/README.md`, so `glslang` is a generation-box tool like `cc` and neither box needs it to run a proof.
11. **No window, ever.** This extension binds the WSI *surface* commands, which take platform pointer bits the caller already holds. It never creates a window or a surface's platform handle. See [`.okf/traps/no-window-in-ext.md`](.okf/traps/no-window-in-ext.md).
12. Zephir reserved words in method/parameter names get a trailing underscore; all-caps names are emitted mixed-case. No **method** name hits either rule — every Vulkan command name passes through verbatim — but several **parameter** names do (`object`, `size`, `static`, …). Positional calls are unaffected; named arguments must use the escaped spelling.

## Pipeline

```bash
export HERD_PHP_84_INI_SCAN_DIR="$(zsh -ic 'echo $HERD_PHP_84_INI_SCAN_DIR')"   # Mac, non-interactive shells

php scripts/gen-vk-src.php        # GEN_SRC_OK  (--check → GEN_SRC_CLEAN)
php scripts/gen-zep.php           # GEN_OK
php scripts/check-parity.php      # PARITY_OK, then chains audit-registry.php → AUDIT_OK
php scripts/tests/run-all.php     # TESTS_OK   ← negative controls; run before calling a wave done
php scripts/tests/struct-guard.php # STRUCT_GUARD_OK structs=368 (needs the built .so; run-all runs it too)
bash install-macos.sh             # php --ri vulkan must report config.json's version
php scripts/verify-reflection.php # REFLECTION_OK
php examples/proof_enumerate.php  # PROOF_ENUMERATE_OK — instance + physical devices
php examples/proof_headless.php   # PROOF_HEADLESS_OK — offscreen triangle, two pixels byte-checked
bash scripts/pi-verify.sh         # PI_VERIFY_OK — push, build, reflect and run the headless proof on the Pi
```

`scripts/tests/run-all.php` is not optional: every guard in this repo is proved able to *fail* against a fixture that breaks exactly what it catches. A guard nobody has watched fail is a guard nobody should trust.

**Source guards pass on sources that do not compile.** A wave is not done until `install-macos.sh` *and* `scripts/pi-verify.sh` are green. Fix on the Mac, re-push, rebuild — never edit on the Pi.

## Hygiene

After every build: `git clean -X -d -f ext && rm -rf .zephir build.log`, then `git status --short --ignored | grep '^!!'` must print nothing. phpize/libtool output is never committed.
