#!/usr/bin/env python3
"""
Download wibo, which runs the 2003 compiler (cl.exe) on Linux without Wine, into portal/tools/wibo/.

    python3 portal/scripts/setup_wibo.py

wibo (https://github.com/decompals/wibo, MIT licence) is a small loader for 32-bit Windows command-line
programs. decomp.me runs its Windows compilers with it. With it, a compile takes about half a second, and
it does not hang the way cl.exe 13.10 can under Wine. portal/tools/msvc_verify.py uses it on its own once
it is in portal/tools/wibo/ (or on PATH, or named by SCARFACE_WIBO); SCARFACE_USE_WINE=1 goes back to Wine.

The release is pinned and its SHA-256 checked. On Windows nothing is needed: cl.exe runs natively.
On macOS keep using Wine (wibo's macOS build is experimental).
"""

from __future__ import annotations

import hashlib
import os
import platform
import sys
import urllib.request
from pathlib import Path

VERSION = "1.2.0"
URL = f"https://github.com/decompals/wibo/releases/download/{VERSION}/wibo-i686"
SHA256 = "2575d3b0a2f408b2c2b0850db56f1af5d005a138394a6774eba77b6708ecc304"
DEST = Path(__file__).resolve().parent.parent / "tools" / "wibo" / "wibo"


def main() -> int:
    if os.name == "nt":
        print("Windows runs cl.exe by itself; wibo is not needed here.")
        return 0
    if platform.system() != "Linux":
        print("wibo is set up here for Linux only. On macOS keep using Wine.")
        return 1
    if DEST.exists() and hashlib.sha256(DEST.read_bytes()).hexdigest() == SHA256:
        print(f"wibo {VERSION} is already in {DEST}")
        return 0
    print(f"Downloading wibo {VERSION} from {URL}")
    try:
        with urllib.request.urlopen(URL, timeout=120) as r:
            data = r.read()
    except Exception as e:
        print(f"Download failed: {e}", file=sys.stderr)
        return 1
    got = hashlib.sha256(data).hexdigest()
    if got != SHA256:
        print(f"SHA-256 is {got}, expected {SHA256}; not installed.", file=sys.stderr)
        return 1
    DEST.parent.mkdir(parents=True, exist_ok=True)
    DEST.write_bytes(data)
    DEST.chmod(0o755)
    print(f"Installed {DEST}. Check it with: python3 portal/doctor.py")
    return 0


if __name__ == "__main__":
    sys.exit(main())
