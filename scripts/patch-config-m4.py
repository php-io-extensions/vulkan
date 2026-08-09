#!/usr/bin/env python3
"""Rewrite ext/config.m4 for portable Vulkan linking (pkg-config vulkan / Homebrew)."""

from __future__ import annotations

from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
CONFIG_M4 = ROOT / "ext" / "config.m4"

CONFIG = r"""PHP_ARG_ENABLE(vulkan, whether to enable vulkan, [ --enable-vulkan   Enable Vulkan])

if test "$PHP_VULKAN" = "yes"; then

	dnl GCC 14+ promotes long-standing warnings to errors; Zephir-generated C
	dnl trips some of them. Demote back to warnings.
	CFLAGS="$CFLAGS -Wno-error=incompatible-pointer-types -Wno-error=int-conversion -Wno-error=implicit-function-declaration -Wno-error=implicit-int"

	AC_DEFINE(HAVE_VULKAN, 1, [Whether you have Vulkan])
	vulkan_sources="vulkan.c kernel/main.c kernel/memory.c kernel/exception.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/string.c kernel/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/math.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/time.c kernel/exit.c vulkan/vk/vk.zep.c
	vulkan/vk/vkdevice.zep.c
	vulkan/vk/vkinstance.zep.c
	vulkan/vk/vkphysicaldevice.zep.c
	vulkan/vk/vkqueue.zep.c
	vulkan/vk/vksurface.zep.c
	vulkan/vk/vkswapchain.zep.c
	src/vulkan-api.c "
	PHP_NEW_EXTENSION(vulkan, $vulkan_sources, $ext_shared,, )
	PHP_ADD_BUILD_DIR([$ext_builddir/kernel/])
	for dir in "vulkan/vk" "src"; do
		PHP_ADD_BUILD_DIR([$ext_builddir/$dir])
	done

	dnl Discover Vulkan via pkg-config when available; fall back to common prefixes.
	VULKAN_CFLAGS=""
	VULKAN_LIBS="-lvulkan"
	if test -n "$PKG_CONFIG" || command -v pkg-config >/dev/null 2>&1; then
		if test -z "$PKG_CONFIG"; then
			PKG_CONFIG=pkg-config
		fi
		if $PKG_CONFIG --exists vulkan 2>/dev/null; then
			VULKAN_CFLAGS=`$PKG_CONFIG --cflags vulkan 2>/dev/null`
			VULKAN_LIBS=`$PKG_CONFIG --libs vulkan 2>/dev/null`
		fi
	fi

	PHP_EVAL_INCLINE($VULKAN_CFLAGS)
	PHP_EVAL_LIBLINE($VULKAN_LIBS, VULKAN_SHARED_LIBADD)

	dnl Extra search paths for Homebrew / local installs.
	for prefix in /opt/homebrew /usr/local; do
		if test -d "$prefix/include"; then
			PHP_ADD_INCLUDE([$prefix/include])
		fi
		if test -d "$prefix/lib"; then
			VULKAN_SHARED_LIBADD="$[]VULKAN_SHARED_LIBADD -L$prefix/lib"
		fi
	done

	PHP_SUBST(VULKAN_SHARED_LIBADD)

	old_CPPFLAGS=$CPPFLAGS
	CPPFLAGS="$CPPFLAGS $INCLUDES"

	AC_CHECK_DECL(
		[HAVE_BUNDLED_PCRE],
		[
			AC_CHECK_HEADERS(
				[ext/pcre/php_pcre.h],
				[
					PHP_ADD_EXTENSION_DEP([vulkan], [pcre])
					AC_DEFINE([ZEPHIR_USE_PHP_PCRE], [1], [Whether PHP pcre extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_JSON],
		[
			AC_CHECK_HEADERS(
				[ext/json/php_json.h],
				[
					PHP_ADD_EXTENSION_DEP([vulkan], [json])
					AC_DEFINE([ZEPHIR_USE_PHP_JSON], [1], [Whether PHP json extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	CPPFLAGS=$old_CPPFLAGS

	PHP_ADD_INCLUDE([$ext_srcdir/src])
	PHP_ADD_INCLUDE([$ext_builddir/src])

	PHP_INSTALL_HEADERS([ext/vulkan], [php_VULKAN.h])

fi
"""


def main() -> None:
    if not CONFIG_M4.exists():
        raise SystemExit(f"missing {CONFIG_M4} — run zephir generate first")
    CONFIG_M4.write_text(CONFIG, encoding="utf-8")
    print(f"patched {CONFIG_M4}")


if __name__ == "__main__":
    main()
