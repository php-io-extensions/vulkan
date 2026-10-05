---
okf_version: "0.2"
---

# ext-vulkan

1:1 PHP bindings of Vulkan 1.3 as exposed by the system loader. Version 0.10.0.

# API

* [Bindings](api/bindings.md) — Functions and structs by group: instance, memory, pipelines, commands, surfaces, dmabuf.

# Architecture

* [Handles](architecture/handles.md) — Identity, parents, release trees, swapchain images, foreign surfaces.
* [Structs](architecture/structs.md) — Translations, `sType`, `pNext` chains, scratch, the clear-value rule.
* [Constants](architecture/constants.md) — The generator and the 1.4.309 floor.

# Runbooks

* [Build, install, test](runbooks/build.md) — Mac and Pi installers, the measured machines, Pest.
* [Adding a binding](runbooks/adding-a-binding.md) — Stub, gen_stub, one `.c`, `config.m4`, the surface test.
