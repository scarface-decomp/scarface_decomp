"""Shared helpers for the test suite.

Tests that need the real compiler or the game files skip themselves when those are missing, so the
suite runs anywhere; with the compiler (portal/tools/msvc71) and binaries/ in place it covers the whole pipeline.
"""
import os
import struct
import sys
from pathlib import Path

import pytest

PORTAL = Path(__file__).resolve().parent.parent      # portal/: the server, its page, tools and scripts
ROOT = PORTAL.parent                                  # the project folder: binaries/, reports/, docs/, ...
sys.path.insert(0, str(PORTAL / "tools"))
sys.path.insert(0, str(PORTAL / "scripts"))

import msvc_verify as MV  # noqa: E402


def have_compiler() -> bool:
    """cl.exe is installed AND runs here (on Linux/macOS that needs Wine)."""
    if MV.find_msvc71_bin() is None:
        return False
    try:
        return "13.10" in MV.compiler_version()
    except Exception:
        return False


needs_compiler = pytest.mark.skipif(not have_compiler(), reason="cl.exe 13.10.3052 not installed or cannot run here "
                                                                "(portal/scripts/setup_msvc71.py; Wine on Linux/macOS)")
needs_pc = pytest.mark.skipif(not (ROOT / "binaries" / "Scarface.exe").exists(), reason="binaries/Scarface.exe missing")
needs_xbox = pytest.mark.skipif(not (ROOT / "binaries" / "default.xbe").exists(), reason="binaries/default.xbe missing")

FLAGS = "/O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4"


def launch_chromium(p):
    """Chrome from SCARFACE_TEST_CHROME, else the system Chrome on Linux, else Playwright's own Chromium
    (`python -m playwright install chromium`). Skips the test when none of them starts."""
    exe = os.environ.get("SCARFACE_TEST_CHROME") or ("/usr/bin/google-chrome" if os.path.exists("/usr/bin/google-chrome") else None)
    try:
        return p.chromium.launch(executable_path=exe, args=["--no-sandbox"]) if exe else p.chromium.launch()
    except Exception as e:  # browser not installed
        pytest.skip(f"no browser for Playwright ({e.__class__.__name__}); run: python -m playwright install chromium")


def make_xbe(path: Path, sections) -> Path:
    """Write a minimal XBE: sections = [(name, va, data, flags)], base address 0x10000."""
    base = 0x10000
    hdr_size = 0x1000
    names_off = 0x400
    shdr_off = 0x200
    blob = bytearray(hdr_size)
    blob[0:4] = b"XBEH"
    struct.pack_into("<I", blob, 0x104, base)
    struct.pack_into("<I", blob, 0x11C, len(sections))
    struct.pack_into("<I", blob, 0x120, base + shdr_off)
    raw = hdr_size
    payload = bytearray()
    name_cursor = names_off
    for i, (name, va, data, flags) in enumerate(sections):
        o = shdr_off + i * 56
        struct.pack_into("<IIIII", blob, o, flags, va, len(data), raw + len(payload), len(data))
        struct.pack_into("<I", blob, o + 20, base + name_cursor)
        nb = name.encode() + b"\0"
        blob[name_cursor:name_cursor + len(nb)] = nb
        name_cursor += len(nb)
        payload += data
    path.write_bytes(bytes(blob) + bytes(payload))
    return path


@pytest.fixture
def tiny_xbe(tmp_path):
    """.text with `mov eax, 0x00030000 / ret` at 0x11000, .data at 0x30000, a D3D library section."""
    text = bytes.fromhex("B8 00 00 03 00 C3") + b"\xCC" * 10 + bytes.fromhex("33 C0 C3")
    data = struct.pack("<I", 0x12345678) + b"\0" * 12
    from sf_binaries import BinaryImage
    p = make_xbe(tmp_path / "tiny.xbe", [(".text", 0x11000, text, 0x6), (".data", 0x30000, data, 0x7),
                                         ("D3D", 0x20000, b"\xC3" * 16, 0x6)])
    return BinaryImage(p)
