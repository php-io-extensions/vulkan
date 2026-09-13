#!/bin/bash

# Debian and Ubuntu installer for the vulkan PHP extension.
#
# Apt package names are the same on Debian and Ubuntu (libvulkan-dev,
# libvulkan1), so one script covers both. Builds on the Linux box — do not run
# this on macOS; install-macos.sh is the Darwin half of the same source tree.
#
# No Vulkan COMMAND is referenced at link time: every one of them is resolved
# at runtime by src/phpvk-bridge.c. The loader itself IS linked, for exactly
# one symbol (vkGetInstanceProcAddr), so libvulkan-dev is a build requirement
# and libvulkan.so.1 plus a working ICD are a runtime one. Both are checked
# before building rather than after.
# See .okf/traps/runtime-resolution-not-linking.md.
#
# If ext/ has not been generated yet, this script runs scripts/prepare-ext.sh
# (requires Zephir on PATH or ZEPHIR_BIN). After ext/ is committed, only
# phpize / configure / make are required.
#
# Usage:
#   bash build-linux.sh
#
# Optional env overrides:
#   PHP_BIN      — path to the php binary   (default: first php on PATH)
#   PHP_EXT_DIR  — override the install dir  (default: from php-config)
#   ZEPHIR_BIN   — zephir binary if ext/ must be generated

set -Eeuo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
EXTENSION_NAME="vulkan"
EXT_SRC="${SCRIPT_DIR}/ext"
BUILD_SO="${EXT_SRC}/modules/${EXTENSION_NAME}.so"
LOG_FILE="${SCRIPT_DIR}/build.log"

if [ "$(uname -s)" = "Darwin" ]; then
    echo "build-linux.sh is for Debian/Ubuntu only. Do not compile vulkan on macOS; use install-macos.sh." >&2
    exit 1
fi

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
    echo " vulkan Extension Installer (Debian / Ubuntu) "
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

ensure_vulkan_runtime() {
    step "🌋 Checking the Vulkan loader..."
    require_cmd apt-get
    $SUDO apt-get update -q

    $SUDO apt-get install -y --no-install-recommends libvulkan-dev libvulkan1 \
        || die "Failed to install libvulkan-dev / libvulkan1. On Debian/Ubuntu: sudo apt-get install libvulkan-dev libvulkan1"

    # ldconfig lives in /sbin, which is not on a plain user's PATH over ssh.
    local LDCONFIG
    LDCONFIG="$(command -v ldconfig || true)"
    [ -n "$LDCONFIG" ] || LDCONFIG="/sbin/ldconfig"

    local missing=0
    local lib
    for lib in libvulkan.so.1; do
        if "$LDCONFIG" -p 2>/dev/null | grep -q "$lib" \
            || ls /usr/lib/*/"$lib" /usr/lib/"$lib" >/dev/null 2>&1; then
            ok "$lib present"
        else
            echo "   ⚠️  $lib not found — the Bridge loader will have nothing to dlopen"
            missing=$((missing + 1))
        fi
    done
    [ "$missing" -eq 0 ] || die "The Vulkan loader is missing; the extension would build but resolve nothing."

    if command -v pkg-config >/dev/null 2>&1 && pkg-config --exists vulkan; then
        ok "pkg-config vulkan $(pkg-config --modversion vulkan)"
    else
        echo "   ⚠️  pkg-config has no 'vulkan' module; config.m4 falls back to -lvulkan"
    fi
}

ensure_php_dev() {
    step "🐘 Checking PHP dev headers..."

    if command -v phpize >/dev/null 2>&1; then
        ok "phpize found: $(command -v phpize)"
        return
    fi

    local ver
    ver="$(${PHP_BIN:-php} -r 'echo PHP_MAJOR_VERSION.".".PHP_MINOR_VERSION;' 2>/dev/null || true)"

    step "phpize not found — installing PHP dev headers..."
    require_cmd apt-get
    $SUDO apt-get update -q

    local installed=0
    for pkg in "php${ver}-dev" "php-dev"; do
        if $SUDO apt-get install -y --no-install-recommends "$pkg" 2>/dev/null; then
            installed=1
            ok "Installed $pkg"
            break
        fi
    done

    [ "$installed" -eq 1 ] || die "Could not install PHP dev headers. Try: sudo apt-get install php-dev"
    command -v phpize >/dev/null 2>&1 || die "phpize still not found after installing php-dev."
    ok "phpize ready: $(command -v phpize)"
}

# SHA-256 over every generation input. Must stay in lockstep with
# compute_gen_stamp in scripts/prepare-ext.sh.
compute_gen_stamp() {
    local hasher
    if command -v sha256sum >/dev/null 2>&1; then
        hasher="sha256sum"
    else
        hasher="shasum -a 256"
    fi
    (
        cd "$SCRIPT_DIR"
        find src vulkan optimizers config.json -type f \
            \( -name '*.h' -o -name '*.c' -o -name '*.zep' -o -name '*.php' \
               -o -name 'config.json' \) 2>/dev/null \
            | LC_ALL=C sort \
            | while IFS= read -r f; do
                  $hasher "$f"
              done \
            | $hasher \
            | awk '{print $1}'
    )
}

ensure_generated_ext() {
    local want have
    if [ -f "${EXT_SRC}/vulkan.c" ] && [ -f "${EXT_SRC}/config.m4" ]; then
        # Stale-build trap: a committed ext/ that no longer matches the
        # sources it was generated from must never be silently compiled.
        want="$(compute_gen_stamp)"
        have="$(cat "${EXT_SRC}/.gen-stamp" 2>/dev/null || echo missing)"
        if [ "$want" = "$have" ]; then
            ok "Committed/generated ext/ present and matches .gen-stamp"
            return
        fi
        step "⚠️  ext/ is stale (.gen-stamp ${have} != sources ${want}) — regenerating..."
    else
        step "⚙️  ext/ not generated — running scripts/prepare-ext.sh (needs Zephir)..."
    fi

    bash "${SCRIPT_DIR}/scripts/prepare-ext.sh" >>"$LOG_FILE" 2>&1 \
        || { show_failure_logs; die "zephir generate / prepare-ext.sh failed. ext/ is missing or stale; regenerate on the dev machine (scripts/prepare-ext.sh needs Zephir) and copy the repo over again."; }

    [ -f "${EXT_SRC}/vulkan.c" ] || die "prepare-ext.sh finished but ext/vulkan.c is missing."
    ok "ext/ generated"
}

header

step "🔎 Preflight checks..."

PHP_BIN="${PHP_BIN:-$(command -v php || true)}"
[ -x "$PHP_BIN" ] || die "PHP not found. Install PHP first (e.g. sudo apt-get install php)."
ok "PHP binary: $PHP_BIN"

require_cmd gcc
require_cmd make
ok "gcc / make present"

ensure_php_dev
ensure_vulkan_runtime
ensure_generated_ext

PHP_VER_MM="$("$PHP_BIN" -r 'echo PHP_MAJOR_VERSION.".".PHP_MINOR_VERSION;')"
PHP_VER_NN="$("$PHP_BIN" -r 'echo PHP_MAJOR_VERSION.PHP_MINOR_VERSION;')"

PHP_BIN_DIR="$(dirname "$(realpath "$PHP_BIN")")"
PHP_CONFIG="${PHP_BIN_DIR}/php-config"
[ -x "$PHP_CONFIG" ] || PHP_CONFIG="$(command -v php-config 2>/dev/null || true)"
[ -x "$PHP_CONFIG" ] || die "php-config not found. Try: sudo apt-get install php${PHP_VER_MM}-dev"

if [ -z "${PHP_EXT_DIR:-}" ]; then
    PHP_EXT_DIR="$("$PHP_CONFIG" --extension-dir)"
fi
[ -n "$PHP_EXT_DIR" ] || die "Could not determine PHP extension dir."

PHP_PHPIZE="${PHP_BIN_DIR}/phpize"
[ -x "$PHP_PHPIZE" ] || PHP_PHPIZE="$(command -v phpize)"

CLI_SCAN_DIR="$("$PHP_BIN" --ini 2>/dev/null \
    | awk -F': ' '/Scan for additional \.ini files in:/{print $2}' || true)"

ok "PHP version    : ${PHP_VER_MM}"
ok "Extension dir  : ${PHP_EXT_DIR}"
ok "phpize         : ${PHP_PHPIZE}"
[ -n "$CLI_SCAN_DIR" ] && ok "INI scan dir   : ${CLI_SCAN_DIR}"
echo ""

step "🧹 Cleaning previous build artifacts..."
cd "$EXT_SRC"

if [ -f Makefile ]; then
    make distclean >>"$LOG_FILE" 2>&1 || true
fi

"$PHP_PHPIZE" --clean >>"$LOG_FILE" 2>&1 || true
ok "ext/ cleaned"
echo ""

export CFLAGS="${CFLAGS:-} -Wno-error -Wno-error=incompatible-pointer-types -Wno-pointer-compare"
export CPPFLAGS="${CPPFLAGS:-} -Wno-error -Wno-error=incompatible-pointer-types"

step "⚙️  Running phpize..."
"$PHP_PHPIZE" >>"$LOG_FILE" 2>&1 || { show_failure_logs; die "phpize failed."; }
ok "phpize complete"

step "⚙️  Configuring (--enable-vulkan)..."
./configure --with-php-config="$PHP_CONFIG" --enable-vulkan \
    >>"$LOG_FILE" 2>&1 || { show_failure_logs; die "./configure failed."; }
ok "configure complete"
echo ""

step "🔨 Building extension ($(nproc) cores)..."
make -j"$(nproc)" >>"$LOG_FILE" 2>&1 || { show_failure_logs; die "make failed. See ${LOG_FILE}."; }

[ -f "$BUILD_SO" ] || { show_failure_logs; die "Build succeeded but ${BUILD_SO} not found."; }
ok "Build complete → ${BUILD_SO}"
echo ""

step "📦 Installing binary..."
$SUDO mkdir -p "$PHP_EXT_DIR"
$SUDO cp -f "$BUILD_SO" "${PHP_EXT_DIR}/${EXTENSION_NAME}.so"
$SUDO chmod 755 "${PHP_EXT_DIR}/${EXTENSION_NAME}.so"
ok "Installed → ${PHP_EXT_DIR}/${EXTENSION_NAME}.so"
echo ""

step "⚙️  Enabling extension..."

# Only $PHP_BIN's OWN scan dir, plus an fpm sibling under the same prefix.
#
# The inherited version wrote this ini into every /etc/php/*/conf.d it could
# find. That is wrong the moment a box has more than one PHP: the .so is built
# against exactly one of them, and dropping an `extension=` line into a
# distro NTS php's conf.d next to a ZTS build makes that php fail to start.
# The extension is enabled for the interpreter it was built for, and for
# nothing else. See .okf/toolchain.md.
declare -a CONF_CANDIDATES=()
[ -n "$CLI_SCAN_DIR" ] && [ "$CLI_SCAN_DIR" != "(none)" ] && [ -d "$CLI_SCAN_DIR" ] \
    && CONF_CANDIDATES+=("$CLI_SCAN_DIR")

# An fpm conf.d belonging to the same installation (…/etc/php.d ->
# …/etc/php-fpm.d, …/cli/conf.d -> …/fpm/conf.d) counts as the same
# interpreter; anything outside this prefix does not.
if [ -n "$CLI_SCAN_DIR" ] && [ -d "$CLI_SCAN_DIR" ]; then
    _fpm_sibling="${CLI_SCAN_DIR%/cli/conf.d}"
    if [ "$_fpm_sibling" != "$CLI_SCAN_DIR" ] && [ -d "${_fpm_sibling}/fpm/conf.d" ]; then
        CONF_CANDIDATES+=("${_fpm_sibling}/fpm/conf.d")
    fi
fi

CONF_DIRS=()
while IFS= read -r _dir; do
    CONF_DIRS+=("$_dir")
done < <(printf "%s\n" "${CONF_CANDIDATES[@]:-}" | awk 'NF && !seen[$0]++')

INI_NAME="30-${EXTENSION_NAME}.ini"
INI_CONTENT="extension=${PHP_EXT_DIR}/${EXTENSION_NAME}.so"

if [ "${#CONF_DIRS[@]}" -eq 0 ]; then
    echo "   ⚠️  No conf.d directories found. Enabling for CLI context only."
fi

# EXACTLY ONE ini may name this extension. The Pi carried a 0.7.x
# 30-vulkan.ini pointing at an older vulkan.so; two `extension=` lines for one
# extension make PHP warn on every startup and load whichever it finds first,
# which is how a stale .so silently wins a green build. Every ini in this
# interpreter's scan dirs that names the extension is replaced by the single
# line above.
for confd in "${CONF_DIRS[@]:-}"; do
    while IFS= read -r stale; do
        [ -n "$stale" ] || continue
        if [ "$(basename "$stale")" = "$INI_NAME" ]; then
            continue
        fi
        $SUDO rm -f "$stale"
        ok "Removed stale ini: ${stale}"
    done < <(grep -rl "${EXTENSION_NAME}\.so" "$confd" 2>/dev/null || true)

    echo "$INI_CONTENT" | $SUDO tee "${confd}/${INI_NAME}" >/dev/null
    ok "Written: ${confd}/${INI_NAME}"

    _inis="$(grep -rl "${EXTENSION_NAME}\.so" "$confd" 2>/dev/null | wc -l | tr -d ' ')"
    [ "$_inis" = "1" ] \
        || die "${confd} holds ${_inis} ini file(s) naming ${EXTENSION_NAME}.so; exactly one is allowed"
    ok "${confd}: exactly one ${EXTENSION_NAME} ini"
done
echo ""

step "🔍 Verifying installation (CLI)..."
if "$PHP_BIN" -m 2>/dev/null | grep -q "^${EXTENSION_NAME}$"; then
    ok "Extension loaded successfully"
else
    die "Extension not detected by PHP. Check php --ini and ${INI_NAME} placement."
fi

# config.json is the single source of truth for the version; a .so that
# reports anything else is stale, and a green build must not hide that.
# Ported from install-macos.sh so both platforms assert the same thing.
EXPECTED_VERSION="$(sed -n 's/.*"version"[[:space:]]*:[[:space:]]*"\([^"]*\)".*/\1/p' "${SCRIPT_DIR}/config.json" | head -1)"
[ -n "$EXPECTED_VERSION" ] || die "Could not read \"version\" from config.json"
RI_OUT="$("$PHP_BIN" --ri "${EXTENSION_NAME}" 2>&1)" || die "php --ri ${EXTENSION_NAME} failed"
if ! printf '%s\n' "$RI_OUT" \
    | grep -qE "Version[[:space:]]*=>[[:space:]]*${EXPECTED_VERSION//./\\.}([[:space:]]|$)"; then
    printf '%s\n' "$RI_OUT"
    die "php --ri ${EXTENSION_NAME} did not report version ${EXPECTED_VERSION} (from config.json); the installed .so is stale"
fi
ok "php --ri ${EXTENSION_NAME} reports ${EXPECTED_VERSION}"
echo ""

step "============================================"
step " Extension Information"
step "============================================"
"$PHP_BIN" --ri "${EXTENSION_NAME}" || true
echo ""

if command -v systemctl >/dev/null 2>&1; then
    for svc in "php${PHP_VER_MM}-fpm" "php-fpm"; do
        if systemctl is-active --quiet "${svc}.service" 2>/dev/null; then
            step "🔁 Reloading ${svc}..."
            $SUDO systemctl reload "${svc}" || true
            ok "${svc} reloaded"
            break
        fi
    done
fi

echo "✅  Installation complete!"
echo ""
echo "File locations:"
echo "  • Binary : ${PHP_EXT_DIR}/${EXTENSION_NAME}.so"
if [ "${#CONF_DIRS[@]}" -gt 0 ]; then
    for d in "${CONF_DIRS[@]}"; do
        echo "  • Config : ${d}/${INI_NAME}"
    done
else
    echo "  • Config : (check php --ini)"
fi
echo ""
echo "Proofs (no window, no display server):"
echo "  php ${SCRIPT_DIR}/examples/proof_enumerate.php   # instance + physical devices"
echo "  php ${SCRIPT_DIR}/examples/proof_headless.php    # offscreen triangle, byte-checked"
echo ""
echo "Reflection check:"
echo "  php ${SCRIPT_DIR}/scripts/verify-reflection.php"
echo ""
