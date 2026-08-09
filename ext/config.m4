PHP_ARG_ENABLE(vulkan, whether to enable vulkan, [ --enable-vulkan   Enable Vulkan])

if test "$PHP_VULKAN" = "yes"; then

	

	if ! test "x-L/opt/homebrew/lib -L/usr/local/lib -lvulkan" = "x"; then
		PHP_EVAL_LIBLINE(-L/opt/homebrew/lib -L/usr/local/lib -lvulkan, VULKAN_SHARED_LIBADD)
	fi

	AC_DEFINE(HAVE_VULKAN, 1, [Whether you have Vulkan])
	vulkan_sources="vulkan.c kernel/main.c kernel/memory.c kernel/exception.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/string.c kernel/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/math.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/time.c kernel/exit.c vulkan/vk/vk.zep.c
	vulkan/vk/vkdevice.zep.c
	vulkan/vk/vkinstance.zep.c
	vulkan/vk/vkphysicaldevice.zep.c
	vulkan/vk/vkqueue.zep.c
	vulkan/vk/vksurface.zep.c
	vulkan/vk/vkswapchain.zep.c src/vulkan-api.c"
	PHP_NEW_EXTENSION(vulkan, $vulkan_sources, $ext_shared,, -I/opt/homebrew/include -I/usr/local/include)
	PHP_ADD_BUILD_DIR([$ext_builddir/kernel/])
	for dir in "vulkan/vk"; do
		PHP_ADD_BUILD_DIR([$ext_builddir/$dir])
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

	PHP_INSTALL_HEADERS([ext/vulkan], [php_VULKAN.h])

fi
