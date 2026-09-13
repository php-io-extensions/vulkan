#!/usr/bin/env php
<?php
/**
 * patch-config-m4.php — teach the generated ext/config.m4 that this
 * extension builds on two platforms.
 *
 * Zephir's config.json has one `extra-libs` string and emits one
 * PHP_EVAL_LIBLINE from it, which cannot say "-L/opt/homebrew/lib with an
 * rpath here, and plain -lvulkan -ldl there". This extension is one .so built
 * from one source tree on both boxes, so the split has to live in config.m4
 * itself.
 *
 * The patch is a single `case $host_os` block appended to the extension's
 * SHARED_LIBADD, inserted immediately before the AC_DEFINE line. It is
 * idempotent (a marker comment is checked first) and verified: if the block
 * is not present after writing, the script fails rather than leaving a
 * config.m4 that links nothing.
 *
 * Unlike ext-opengl's version of this file, `-lvulkan` here is a REAL link
 * dependency, not only a declaration. `src/phpvk-bridge.c` names exactly one
 * Vulkan symbol, `vkGetInstanceProcAddr`, as the fallback for a `dlopen` that
 * could not find the loader by soname; every one of the 267 bound commands is
 * still resolved at runtime through it and none is referenced at link time.
 * `nm -u` on the built module lists `_vkGetInstanceProcAddr` and nothing else
 * beginning `vk`.
 *
 * On Darwin the Homebrew loader lives outside the default search path, so the
 * block adds `-L/opt/homebrew/lib` and bakes an rpath: without the rpath the
 * module links but cannot be loaded, and `dlopen("libvulkan.1.dylib")` would
 * fail too. `pkg-config --libs vulkan` is preferred when present (it is on
 * the Pi) and the literals are the fallback.
 *
 * Usage: php scripts/patch-config-m4.php <path-to-ext/config.m4>
 */

declare(strict_types=1);

const MARKER = 'PHPVK platform link flags';

$path = $argv[1] ?? '';
if ($path === '' || !is_file($path)) {
    fwrite(STDERR, "patch-config-m4: usage: patch-config-m4.php <ext/config.m4>\n");
    exit(1);
}

$src = (string) file_get_contents($path);

if (str_contains($src, MARKER)) {
    echo "patch-config-m4: already patched\n";
    exit(0);
}

if (!preg_match('/^\s*AC_DEFINE\(HAVE_VULKAN,/m', $src, $m, PREG_OFFSET_CAPTURE)) {
    fwrite(STDERR, "patch-config-m4: AC_DEFINE(HAVE_VULKAN, ...) not found in {$path}\n");
    exit(1);
}
$at = $m[0][1];

$block = <<<'M4'

	dnl ---- PHPVK platform link flags ----
	dnl Every Vulkan COMMAND is resolved at runtime by src/phpvk-bridge.c.
	dnl The loader itself is a genuine link dependency all the same: the
	dnl Bridge names vkGetInstanceProcAddr, and that one symbol is the whole
	dnl seam. On Darwin the Homebrew loader is outside the default search
	dnl path, so an rpath is baked in as well.
	if test -n "$PKG_CONFIG" && $PKG_CONFIG --exists vulkan 2>/dev/null; then
		VULKAN_SHARED_LIBADD="$VULKAN_SHARED_LIBADD `$PKG_CONFIG --libs vulkan`"
		CPPFLAGS="$CPPFLAGS `$PKG_CONFIG --cflags vulkan`"
	else
		case $host_os in
			darwin*)
				VULKAN_SHARED_LIBADD="$VULKAN_SHARED_LIBADD -L/opt/homebrew/lib -lvulkan"
				CPPFLAGS="$CPPFLAGS -I/opt/homebrew/include"
				;;
			*)
				VULKAN_SHARED_LIBADD="$VULKAN_SHARED_LIBADD -lvulkan -ldl"
				;;
		esac
	fi
	case $host_os in
		darwin*)
			VULKAN_SHARED_LIBADD="$VULKAN_SHARED_LIBADD -Wl,-rpath,/opt/homebrew/lib"
			CPPFLAGS="$CPPFLAGS -I/opt/homebrew/include"
			;;
		*)
			VULKAN_SHARED_LIBADD="$VULKAN_SHARED_LIBADD -ldl"
			;;
	esac

M4;

$out = substr($src, 0, $at) . $block . substr($src, $at);

if (file_put_contents($path, $out) === false) {
    fwrite(STDERR, "patch-config-m4: cannot write {$path}\n");
    exit(1);
}

$check = (string) file_get_contents($path);
foreach ([MARKER, '-lvulkan', '-Wl,-rpath,/opt/homebrew/lib', '-ldl'] as $needle) {
    if (!str_contains($check, $needle)) {
        fwrite(STDERR, "patch-config-m4: '{$needle}' is not present after writing\n");
        exit(1);
    }
}

echo "patch-config-m4: PATCH_OK\n";
