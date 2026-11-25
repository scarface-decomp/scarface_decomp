#!/usr/bin/env python3
"""
Put the PS2 game's compiler on this computer, in portal/tools/mwcps2/, so PS2 functions are compiled here
and not through a decomp.me tab.

    python portal/scripts/setup_mwcps2.py

The PS2 game was built with Metrowerks CodeWarrior for PS2, 3.0.1 build 103 (docs/PS2.md says how that
was worked out). This downloads the copy decomp.me compiles with (`mwcps2-3.0.1b103-040528`, from the
decompme/compilers release on GitHub), checks its SHA-256 and unpacks it. Nothing is installed anywhere
else, the folder is not part of the repository (.gitignore), and deleting it undoes this.

CodeWarrior is Metrowerks' (now NXP's) commercial product: this project does not ship it, and whether
you fetch a copy is your decision. Without it everything still works; PS2 compiles then go through
decomp.me as before. If you already have the same build, put its files in portal/tools/mwcps2/ yourself
or name their folder in SCARFACE_MWCPS2.

mwccps2.exe is a Windows program: Windows runs it by itself, Linux through wibo
(portal/scripts/setup_wibo.py), macOS through Wine.
"""

from __future__ import annotations

import hashlib
import io
import sys
import tarfile
import urllib.request
from pathlib import Path

BUILD = "mwcps2-3.0.1b103-040528"
URL = f"https://github.com/decompme/compilers/releases/download/compilers/{BUILD}.tar.gz"
SHA256 = "a6db36760445e18da840bda70f3e7b97dc563ba421d13651c121e8867013c0c9"
DEST = Path(__file__).resolve().parent.parent / "tools" / "mwcps2"
EXE = "mwccps2.exe"


def unpack(data: bytes, dest: Path) -> list:
    """The archive's plain files, written flat into dest. Anything with a folder in its name, a link or a
    device is refused: the archive is a handful of programs side by side."""
    names = []
    with tarfile.open(fileobj=io.BytesIO(data), mode="r:gz") as tar:
        members = tar.getmembers()
        for m in members:
            name = m.name[2:] if m.name.startswith("./") else m.name
            if not name or name == ".":
                continue
            if not m.isfile() or "/" in name or "\\" in name or name.startswith(".."):
                raise ValueError(f"unexpected entry in the archive: {m.name!r}")
        dest.mkdir(parents=True, exist_ok=True)
        for m in members:
            name = m.name[2:] if m.name.startswith("./") else m.name
            if not name or name == ".":
                continue
            (dest / name).write_bytes(tar.extractfile(m).read())
            names.append(name)
    return names


def main() -> int:
    if (DEST / EXE).is_file():
        print(f"The PS2 compiler is already in {DEST}")
        return 0
    print(f"Downloading {BUILD} from {URL}")
    try:
        with urllib.request.urlopen(URL, timeout=180) as r:
            data = r.read()
    except Exception as e:
        print(f"Download failed: {e}", file=sys.stderr)
        return 1
    got = hashlib.sha256(data).hexdigest()
    if got != SHA256:
        print(f"SHA-256 is {got}, expected {SHA256}; nothing was unpacked.", file=sys.stderr)
        return 1
    try:
        names = unpack(data, DEST)
    except (ValueError, tarfile.TarError, OSError) as e:
        print(f"Could not unpack it: {e}", file=sys.stderr)
        return 1
    if EXE not in names:
        print(f"{EXE} was not in the archive; check {DEST}.", file=sys.stderr)
        return 1
    print(f"Unpacked {len(names)} files into {DEST}.")
    print("Restart the portal: PS2 functions are now compiled on this computer.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
