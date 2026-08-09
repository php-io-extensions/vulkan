#!/bin/bash

# Debian Trixie / Raspberry Pi OS installer for the vulkan PHP extension.
#
# Builds from the pre-generated C source in ext/ using phpize — no Zephir required
# for end users when ext/ is already prepared. Maintainers may run prepare-ext.sh first.
#
# Usage:
#   bash install-debian-trixie.sh
#
# Optional env overrides:
#   PHP_BIN      — path to the php binary   (default: first php on PATH)
#   PHP_EXT_DIR  — override the install dir  (default: from php-config)

set -Eeuo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
EXTENSION_NAME="vulkan"
EXT_SRC="${SCRIPT_DIR}/ext"
BUILD_SO="${EXT_SRC}/modules/${EXTENSION_NAME}.so"
LOG_FILE="${SCRIPT_DIR}/build.log"

if [ "${EUID:-$(id -u)}" -ne 0 ]; then
    SUDO="sudo"
else
    SUDO=""
fi

die() {
    echo ""
    echo "❌  $*" >&2
    exit 1
}

require_cmd() {
    command -v "$1" >/dev/null 2>&1 || die "Required command not found: $1"
}

header() {
    echo "============================================"
    echo " Vulkan Extension Installer (Debian / Pi OS) "
    echo "============================================"
    echo ""
}

step() { echo "$*"; }
ok()   { echo "   ✓ $*"; }

show_failure_logs() {
    local f
    for f in "$LOG_FILE" "${SCRIPT_DIR}/compile-errors.log"; do
        if [ -f "$f" ]; then
            echo ""
            echo "---- Last 100 lines of $(basename "$f") ----"
            tail -100 "$f" || true
        fi
    done
}

ensure_vulkan_dev() {
    step "📚 Checking Vulkan development packages..."
    if pkg-config --exists vulkan 2>/dev/null; then
        ok "Vulkan headers/libs present"
        return
    fi
    step "Installing Vulkan packages via apt..."
    $SUDO apt-get update >>"$LOG_FILE" 2>&1 || die "apt-get update failed."
    $SUDO apt-get install -y --no-install-recommends \
        libvulkan-dev vulkan-tools pkg-config \
        >>"$LOG_FILE" 2>&1 || die "Failed to install libvulkan-dev."
    ok "Vulkan packages installed"
}

header
: >"$LOG_FILE"

step "🔎 Preflight checks..."
require_cmd php
require_cmd php-config
require_cmd phpize
require_cmd make
require_cmd pkg-config

PHP_BIN="${PHP_BIN:-$(command -v php)}"
PHP_VER_MM="$("$PHP_BIN" -r 'echo PHP_MAJOR_VERSION.".".PHP_MINOR_VERSION;')"
PHP_VER_NN="$("$PHP_BIN" -r 'echo PHP_MAJOR_VERSION.PHP_MINOR_VERSION;')"

if [ -n "${PHP_EXT_DIR:-}" ]; then
    :
elif PHP_EXT_DIR="$(php-config --extension-dir 2>/dev/null)"; then
    :
else
    die "Could not determine PHP extension dir."
fi

CLI_SCAN_DIR="$("$PHP_BIN" --ini 2>/dev/null | awk -F': ' '/Scan for additional \.ini files in:/{print $2}' || true)"

ok "PHP: $PHP_BIN ($PHP_VER_MM)"
ok "Extension dir: $PHP_EXT_DIR"

ensure_vulkan_dev
echo ""

step "🔨 Building extension from ext/..."
cd "$EXT_SRC"
if [ ! -f config.m4 ]; then
    die "ext/config.m4 missing — run scripts/prepare-ext.sh on a maintainer machine first."
fi

phpize >>"$LOG_FILE" 2>&1 || { show_failure_logs; die "phpize failed."; }
./configure --enable-vulkan >>"$LOG_FILE" 2>&1 || { show_failure_logs; die "configure failed."; }
make -j"$(nproc 2>/dev/null || echo 2)" >>"$LOG_FILE" 2>&1 || { show_failure_logs; die "make failed."; }
[ -f "$BUILD_SO" ] || { show_failure_logs; die "Build output not found at $BUILD_SO"; }
ok "Build complete"
echo ""

step "📦 Installing binary..."
$SUDO mkdir -p "$PHP_EXT_DIR"
$SUDO cp -f "$BUILD_SO" "${PHP_EXT_DIR}/${EXTENSION_NAME}.so"
$SUDO chmod 755 "${PHP_EXT_DIR}/${EXTENSION_NAME}.so"
ok "Copied to: ${PHP_EXT_DIR}/${EXTENSION_NAME}.so"
echo ""

step "⚙️  Enabling extension..."
declare -a CONF_DIRS=()
if [ -n "$CLI_SCAN_DIR" ] && [ "$CLI_SCAN_DIR" != "(none)" ] && [ -d "$CLI_SCAN_DIR" ]; then
    CONF_DIRS+=("$CLI_SCAN_DIR")
fi
for d in "/etc/php/${PHP_VER_MM}/cli/conf.d" "/etc/php/${PHP_VER_MM}/fpm/conf.d" "/etc/php/${PHP_VER_MM}/apache2/conf.d" "/etc/php${PHP_VER_NN}/conf.d"; do
    [ -d "$d" ] && CONF_DIRS+=("$d")
done

INI_NAME="30-${EXTENSION_NAME}.ini"
INI_CONTENT="extension=${EXTENSION_NAME}.so"
for confd in "${CONF_DIRS[@]:-}"; do
    echo "$INI_CONTENT" | $SUDO tee "${confd}/${INI_NAME}" >/dev/null
    ok "Written: ${confd}/${INI_NAME}"
done
echo ""

step "🔍 Verifying..."
if "$PHP_BIN" -m 2>/dev/null | grep -q "^${EXTENSION_NAME}$"; then
    ok "Extension loaded"
else
    die "Extension not detected. Check ${INI_NAME} and php --ini."
fi

"$PHP_BIN" --ri vulkan || true
echo ""
echo "✅ Installation complete!"
echo "Demo (requires glfw): php examples/proof_menu.php"
echo ""
