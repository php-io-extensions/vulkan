#!/usr/bin/env python3
"""Fix Zephir 0.19 ZEPHIR_REGISTER_CLASS truncation for Vulkan\\Vk\\* classes."""

from __future__ import annotations

import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
EXT = ROOT / "ext"

FIXES = {
    "Vulkan\\V\\Vk": "Vulkan\\Vk\\Vk",
    "Vulkan\\V\\VkInstance": "Vulkan\\Vk\\VkInstance",
    "Vulkan\\V\\VkPhysicalDevice": "Vulkan\\Vk\\VkPhysicalDevice",
    "Vulkan\\V\\VkDevice": "Vulkan\\Vk\\VkDevice",
    "Vulkan\\V\\VkQueue": "Vulkan\\Vk\\VkQueue",
    "Vulkan\\V\\VkSurface": "Vulkan\\Vk\\VkSurface",
    "Vulkan\\V\\VkSwapchain": "Vulkan\\Vk\\VkSwapchain",
}


def fix_file(path: Path) -> int:
    text = path.read_text(encoding="utf-8")
    original = text
    for bad, good in FIXES.items():
        text = text.replace(bad, good)
    text = re.sub(
        r"\bVulkan_V_(Vk|VkInstance|VkPhysicalDevice|VkDevice|VkQueue|VkSurface|VkSwapchain)\b",
        r"Vulkan_Vk_\1",
        text,
    )
    if text != original:
        path.write_text(text, encoding="utf-8")
        return 1
    return 0


def main() -> None:
    if not EXT.exists():
        raise SystemExit("ext/ missing — run zephir generate first")
    changed = 0
    for path in EXT.rglob("*.c"):
        changed += fix_file(path)
    for path in EXT.rglob("*.h"):
        changed += fix_file(path)
    print(f"fixup-zephir-register: touched {changed} files")


if __name__ == "__main__":
    main()
