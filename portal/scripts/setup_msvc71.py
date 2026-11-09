#!/usr/bin/env python3
"""
Install the Visual C++ Toolkit 2003 compiler into portal/tools/msvc71/ from the installer you already have,
including the CRT/STL headers (include/) and libraries (lib/) that the old manual unpack left out.

Both releases of the Toolkit work: 1.0 (cl.exe 13.10.3052) and 1.01 (cl.exe 13.10.3077). Microsoft only
renumbered the compiler in 1.01, with no change to the code it generates. Each verified match records which
one was used. Anything else (a later Visual Studio compiler, say) is refused: it makes different code.

    python portal/scripts/setup_msvc71.py source_archives/VCToolkitSetup.exe

How: the installer's payload is an InstallShield stream holding an .msi. Each file in the stream
is obfuscated with a key derived from its file name; this script decodes the .msi and then unpacks it.
On Windows that is done by portal/tools/msi_reader.py with Windows' own expand.exe, not by running the
installer or `msiexec /a`: the package starts InstallShield's 2004 script engine even for those, and it
fails on Windows 10 and 11 (error 1603, or an "IDS_ERROR26" box). On Linux/macOS: `msiextract`
(package "msitools").
The compiler is not redistributed by this project; you need your own copy of the installer.
"""

from __future__ import annotations

import argparse
import os
import shutil
import struct
import subprocess
import sys
import tempfile
from pathlib import Path

PORTAL = Path(__file__).resolve().parent.parent      # portal/
ROOT = PORTAL.parent                                  # the project folder
DEST = PORTAL / "tools" / "msvc71"
sys.path.insert(0, str(PORTAL / "tools"))
MAGIC = bytes([0x13, 0x35, 0x86, 0x07])
SWAP = bytes(((b >> 4) | (b << 4)) & 0xFF for b in range(256))
MSI_NAME = b"Microsoft Visual C++ Toolkit 2003.msi"


def find_stream(exe: bytes) -> int:
    """The payload header is 'InstallShield\\0' + file count, then 312-byte file headers.
    The same text also appears inside the setup program, so check each hit for a sane header."""
    i = exe.find(b"InstallShield\x00")
    while i >= 0:
        count = struct.unpack_from("<H", exe, i + 14)[0] if i + 16 <= len(exe) else 0
        name = exe[i + 0x2E:i + 0x2E + 260].split(b"\0")[0]
        if 0 < count < 256 and name and all(32 <= c < 127 for c in name):
            return i
        i = exe.find(b"InstallShield\x00", i + 1)
    raise SystemExit("This does not look like VCToolkitSetup.exe (no InstallShield stream found).")


def extract_msi(exe_path: Path, out_dir: Path) -> Path:
    data = exe_path.read_bytes()
    base = find_stream(data)
    count = struct.unpack_from("<H", data, base + 14)[0]
    pos = base + 0x2E
    for _ in range(count):
        name = data[pos:pos + 260].split(b"\0")[0]
        _flags, _unk, length = struct.unpack_from("<III", data, pos + 260)
        start = pos + 312
        if name == MSI_NAME:
            key = bytes(name[k] ^ MAGIC[k % 4] for k in range(len(name)))
            tables = [bytes((~(key[k] ^ SWAP[b])) & 0xFF for b in range(256)) for k in range(len(key))]
            blob = data[start:start + length]
            kl = len(key)
            out = bytearray(length)
            for k in range(kl):                       # decode one key position at a time (fast)
                out[k::kl] = blob[k::kl].translate(tables[k])
            msi = out_dir / "toolkit.msi"
            msi.write_bytes(out)
            if out[:8] != b"\xD0\xCF\x11\xE0\xA1\xB1\x1A\xE1":
                raise SystemExit("Decoded .msi has an unexpected header; is this the 2004 Visual C++ Toolkit 2003 installer?")
            return msi
        pos = start + length
    raise SystemExit("The Toolkit .msi was not found inside the installer.")


def unpack_msi(msi: Path, out_dir: Path) -> Path:
    target = out_dir / "unpacked"
    target.mkdir()
    if os.name == "nt":
        import msi_reader
        try:
            n = msi_reader.unpack(msi.read_bytes(), target)
        except (RuntimeError, ValueError, KeyError, OSError) as e:
            raise SystemExit(f"Could not unpack the compiler from the installer: {e}")
        print(f"unpacked {n} files from the installer")
    else:
        if not shutil.which("msiextract"):
            raise SystemExit("Install msitools (e.g. `sudo apt install msitools`) for msiextract.")
        subprocess.run(["msiextract", "-C", str(target), str(msi)], check=True, stdout=subprocess.DEVNULL)
    hits = list(target.rglob("cl.exe"))
    if not hits:
        raise SystemExit("cl.exe was not found after unpacking the .msi.")
    return hits[0].parent.parent                  # .../Microsoft Visual C++ Toolkit 2003


TOOLKIT_BUILDS = {
    "13.10.3052": "Visual C++ Toolkit 2003 1.0 (April 2004)",
    "13.10.3077": "Visual C++ Toolkit 2003 1.01 (July 2004), same code generation as 1.0",
}


def file_version(path: Path) -> str:
    """'13.10.3052' from the version resource of a Windows program, without running it."""
    data = path.read_bytes()
    i = data.find(b"\xBD\x04\xEF\xFE")                 # VS_FIXEDFILEINFO signature
    if i < 0:
        return ""
    ms, ls = struct.unpack_from("<II", data, i + 8)
    return f"{ms >> 16}.{ms & 0xFFFF}.{ls >> 16}"


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("installer", nargs="?", default=str(ROOT / "source_archives" / "VCToolkitSetup.exe"))
    a = ap.parse_args()
    exe = Path(a.installer)
    if not exe.exists():
        raise SystemExit(f"{exe} not found")
    with tempfile.TemporaryDirectory() as tmp:
        tmp = Path(tmp)
        msi = extract_msi(exe, tmp)
        tk = unpack_msi(msi, tmp)
        build = file_version(tk / "bin" / "cl.exe")
        if build not in TOOLKIT_BUILDS:
            raise SystemExit(f"This installer's cl.exe is version {build or 'unknown'}, not the Visual C++ Toolkit 2003 "
                             "(13.10.3052 or 13.10.3077). The game was built with that compiler; others make different code.")
        print(f"cl.exe {build}: {TOOLKIT_BUILDS[build]}")
        DEST.mkdir(parents=True, exist_ok=True)
        for sub in ("bin", "include", "lib"):
            src = tk / sub
            if src.exists():
                shutil.copytree(src, DEST / sub, dirs_exist_ok=True)
                print(f"installed portal/tools/msvc71/{sub} ({sum(1 for _ in (DEST / sub).rglob('*'))} files)")
    print("Done. Check with:  python portal/verify.py --status")
    return 0


if __name__ == "__main__":
    sys.exit(main())
