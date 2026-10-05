PHP_ARG_ENABLE([vulkan],
  [whether to enable vulkan support],
  [AS_HELP_STRING([--enable-vulkan], [Enable the Vulkan bindings])],
  [no])

if test "$PHP_VULKAN" != "no"; then
  PKG_CHECK_MODULES([VULKAN], [vulkan >= 1.3])
  PHP_EVAL_INCLINE([$VULKAN_CFLAGS])
  PHP_EVAL_LIBLINE([$VULKAN_LIBS], [VULKAN_SHARED_LIBADD])

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
