#!/usr/bin/env python3
"""
Copy the game's script files out of your own copy of the game, for the script work (docs/SCRIPTS.md).

    python portal/scripts/extract_scripts.py "C:\\Games\\Scarface\\cement.rcf"                 # installed PC game
    python portal/scripts/extract_scripts.py "binaries\\Scarface - The World Is Yours (XBOX).7z"
    python portal/scripts/extract_scripts.py "binaries\\Scarface - The World Is Yours (Apr 20, 2006 prototype).zip"
    python portal/scripts/extract_scripts.py "..\\SLUS_211.11.SCARFACEps2.iso"                # PS2 disc

Takes any of:
  * cement.rcf from an installed copy (the PC disc keeps its files inside DATA*.CAB, so use the
    installed game's cement.rcf for the PC version);
  * a disc image (.iso) with cement.rcf on it: the PS2 disc, or an Xbox disc image;
  * a .7z or .zip holding an Xbox disc image (cement.rcf is read out of it without unpacking the
    whole image);
  * a .zip of a game folder with the script files loose in it, like the April 2006 prototype.

Each version goes in its own folder under binaries/scripts_and_data/ (xbox, ps2, pc, prototype),
where the portal's Game Scripts tab finds them and compares other versions with the retail game.
binaries/ is never committed, so the files stay on your computer. Use --list to only show what is
there, and --out to choose the folder yourself.
"""

from __future__ import annotations

import argparse
import collections
import sys
import tempfile
import zipfile
from pathlib import Path
from typing import Iterator, List, Optional, Tuple

PORTAL = Path(__file__).resolve().parent.parent      # portal/
ROOT = PORTAL.parent                                  # the project folder
sys.path.insert(0, str(PORTAL / "tools"))

from rcf import SCRIPT_EXTENSIONS, RcfError, open_rcf, safe_output_path  # noqa: E402
import game_files as GF  # noqa: E402

SCRIPTS_ROOT = ROOT / "binaries" / "scripts_and_data"


def guess_version(src: Path) -> str:
    low = src.name.lower()
    if "prototype" in low or "proto" in low:
        return "prototype"
    if "xbox" in low or (low.endswith(GF.DISC_IMAGES) and GF._is_xbox_image(src)):
        return "xbox"
    if "slus" in low or "ps2" in low:
        return "ps2"
    if low == "cement.rcf":
        return "pc"
    return "other"


def loose_scripts_in_zip(src: Path) -> List[Tuple[zipfile.ZipInfo, str]]:
    """Script files sitting loose in a .zip, with one shared top folder (like 'Scarface/') removed
    so the paths line up with the ones inside cement.rcf."""
    with zipfile.ZipFile(src) as z:
        found = [i for i in z.infolist() if not i.is_dir() and Path(i.filename).suffix.lower() in SCRIPT_EXTENSIONS]
    tops = {i.filename.split("/", 1)[0] for i in found}
    strip = len(tops) == 1 and all("/" in i.filename for i in found)
    return [(i, i.filename.split("/", 1)[1] if strip else i.filename) for i in found]


def rcf_from_disc(src: Path, tmp: Path) -> Optional[Path]:
    """cement.rcf out of an Xbox disc image (loose or in a .7z/.zip), written to tmp."""
    dest = tmp / "cement.rcf"
    if src.suffix.lower() in GF.DISC_IMAGES:
        data = GF.read_from_disc_file(src, "cement.rcf")
        if data:
            dest.write_bytes(data)
            return dest
        return None
    for member, size in GF.disc_images_in(src):
        print(f"Reading cement.rcf from {Path(member).name} inside {src.name} (a minute or two)...")
        if GF._disc_in_archive(src, member, size, "cement.rcf", print, dest=dest):
            return dest
    return None


def entries(src: Path, tmp: Path) -> Iterator[Tuple[str, int, callable]]:
    """(name inside the game's files, size, read()) for every script file in src."""
    low = src.name.lower()
    if low.endswith(".zip"):
        loose = loose_scripts_in_zip(src)
        if loose:
            z = zipfile.ZipFile(src)
            for info, name in loose:
                yield name, info.file_size, (lambda i=info: z.read(i))
            return
    if low.endswith(GF.ARCHIVES) or (low.endswith(GF.DISC_IMAGES) and GF._is_xbox_image(src)):
        rcf = rcf_from_disc(src, tmp)
        if not rcf:
            raise RcfError(f"no cement.rcf found in {src.name}")
        src = rcf
    arc = open_rcf(src)
    print(f"{src.name}: {len(arc.entries):,} files in the archive")
    for e in arc.find(SCRIPT_EXTENSIONS):
        yield e.name, e.size, (lambda e=e: arc.read(e))


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("source", type=Path, help="cement.rcf, a disc image, a .7z/.zip with a disc image, "
                                              "or a .zip of a game folder")
    ap.add_argument("--out", type=Path, default=None,
                    help="where to write (default: binaries/scripts_and_data/<version>)")
    ap.add_argument("--list", action="store_true", help="list the script files without extracting")
    a = ap.parse_args(argv)
    if not a.source.is_file():
        print(f"Not found: {a.source}")
        return 1
    out = a.out or SCRIPTS_ROOT / guess_version(a.source)
    with tempfile.TemporaryDirectory() as tmp:
        try:
            found = list(entries(a.source, Path(tmp)))
        except (RcfError, OSError, RuntimeError, zipfile.BadZipFile) as e:
            print(f"Could not read {a.source}: {e}")
            return 1
        kinds = collections.Counter(Path(n).suffix.lower() for n, _, _ in found)
        print(f"{len(found):,} script files: " + ", ".join(f"{n} {k}" for k, n in sorted(kinds.items())))
        if a.list:
            for name, size, _ in found:
                print(f"  {size:>8,}  {name}")
            return 0
        written = 0
        for name, _, read in found:
            dest = safe_output_path(out, name)
            if dest is None:
                print(f"  skipped unsafe name: {name!r}")
                continue
            dest.parent.mkdir(parents=True, exist_ok=True)
            dest.write_bytes(read())
            written += 1
    print(f"Wrote {written:,} files to {out}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
