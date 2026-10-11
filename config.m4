PHP_ARG_ENABLE([vulkan],
  [whether to enable vulkan support],
  [AS_HELP_STRING([--enable-vulkan], [Enable the Vulkan bindings])],
  [no])

if test "$PHP_VULKAN" != "no"; then
  PKG_CHECK_MODULES([VULKAN], [vulkan >= 1.3])
  PHP_EVAL_INCLINE([$VULKAN_CFLAGS])

  dnl stubs/vk_constants.stub.php is generated from vulkan_core.h header 309 (1.4.309): an
  dnl older header lacks enumerators the constants table names, and vulkan.pc only reports the
  dnl loader's version, so the header is checked on its own.
  vulkan_saved_CPPFLAGS=$CPPFLAGS
  CPPFLAGS="$CPPFLAGS $VULKAN_CFLAGS"
  AC_MSG_CHECKING([for Vulkan header 309 (1.4.309) or newer])
  AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#include <vulkan/vulkan.h>
#if VK_HEADER_VERSION < 309
#error Vulkan header older than 309
#endif
  ]], [[]])],
    [AC_MSG_RESULT([yes])],
    [AC_MSG_RESULT([no])
     AC_MSG_ERROR([ext-vulkan needs Vulkan headers 1.4.309 or newer: Debian Trixie libvulkan-dev, Homebrew vulkan-headers, or KhronosGroup/Vulkan-Headers installed over an older distribution header])])
  CPPFLAGS=$vulkan_saved_CPPFLAGS
  PHP_EVAL_LIBLINE([$VULKAN_LIBS], [VULKAN_SHARED_LIBADD])
  dnl Compiled into PHP, the flags PHP_EVAL_LIBLINE drops (a static library's -framework
  dnl pairs and -Wl, flags on macOS) join PHP's program link line.
  if test "$ext_shared" != "yes"; then
    for vulkan_flag in $VULKAN_LIBS; do
      case $vulkan_flag in
        -l*|-L*|-pthread) ;;
        *) EXTRA_LDFLAGS_PROGRAM="$EXTRA_LDFLAGS_PROGRAM $vulkan_flag" ;;
      esac
    done
  fi

  VULKAN_SOURCES="src/vulkan.c src/runtime.c src/structs.c src/vk_instance.c src/vk_memory.c src/vk_pipeline.c src/vk_command.c src/vk_surface.c src/vk_external.c"
  VULKAN_CFLAGS_EXTRA="-DZEND_ENABLE_STATIC_TSRMLS_CACHE=1"
  case $host_os in
    darwin*)
      VULKAN_SOURCES="$VULKAN_SOURCES src/vk_metal.c"
      VULKAN_CFLAGS_EXTRA="$VULKAN_CFLAGS_EXTRA -DVK_USE_PLATFORM_METAL_EXT"
      ;;
  esac

  PHP_SUBST([VULKAN_SHARED_LIBADD])
  PHP_NEW_EXTENSION([vulkan], [$VULKAN_SOURCES], [$ext_shared],, [$VULKAN_CFLAGS_EXTRA])
  PHP_ADD_BUILD_DIR([$ext_builddir/src])
fi
