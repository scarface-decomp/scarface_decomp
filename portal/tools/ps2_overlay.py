#!/usr/bin/env python3
"""
The PS2's code overlays: CEMENT.RCF/Overlays/FrontEnd/*.bin, extra program code (front-end screens: the
pause menu, the exotics shop, the business, empire and weapon screens, the gambling mini-games) that
SLUS_211.11 loads at run time. They are CodeWarrior overlay files ("MWo3"); the whole file, header and all,
is copied to its load address.

    0x00  "MWo3"
    0x04  u32 overlay number (6 to 11)
    0x08  u32 load address (where byte 0 of the file goes)
    0x0C  u32 code size (from 0x40; the code itself starts after 0x40 bytes of zeros)
    0x10  u32 data size (after the code: text, tables, static constructors, the constructor list)
    0x14  u32 bss size (zeroed memory after the file)
    0x18  u32 start and u32 end address of the list of static constructors to call after loading
    0x20  the overlay's file name, NUL-terminated (32 bytes)
    0x40  code, then data: header + code + data is the whole file

Each overlay comes in three builds: <name>f.bin, <name>r.bin and <name>t.bin. Only the "f" ones fit the
retail program: every call they make lands on a function start in SLUS_211.11, which also lists one empty
segment for each of them at 0x845480 with exactly their size. The "r" and "t" builds load elsewhere and
call other addresses: they belong to other builds of the program, probably Radical's "release" and "tune"
configurations. The program was linked together with its overlays: their virtual tables are in its data,
and it calls into them directly.

The portal copies the six "f" overlays out of your PS2 disc (binaries/ps2_overlays/) and lists their
functions in the work queue, each overlay on its own lane (OVERLAYS below), checked against the program
with that overlay loaded (ps2_binary.Ps2Image.with_overlay).

    python portal/tools/ps2_overlay.py FILE.bin ...                    what each header says
    python portal/tools/ps2_overlay.py FILE.bin --check SLUS_211.11    how many of its calls land on functions
    python portal/tools/ps2_overlay.py FILE.bin --elf OUTDIR           an ELF file Ghidra, IDA or objdump can
                                                                       open at the right address

Your own copies, on your own computer; standard library only.
"""

from __future__ import annotations

import argparse
import hashlib
import struct
import sys
from dataclasses import dataclass
from pathlib import Path
from typing import Dict, List, Optional, Set, Tuple

MAGIC = b"MWo3"
HEADER = 0x40
E_FLAGS_R5900 = 0x20924001          # what SLUS_211.11 has


@dataclass(frozen=True)
class Known:
    """One of the six overlays the retail program loads, as the portal's work queue lists it."""
    bin: str                         # its lane in the queue and its key in reports/verified_registry.json
    file: str                        # its name on the disc, in CEMENT.RCF/Overlays/FrontEnd/
    label: str                       # what it is, in words
    sha256: str                      # the retail US disc's copy (docs/GAME_VERSIONS.md)


OVERLAYS: Tuple[Known, ...] = (
    Known("ps2pause", "PauseMenuOverlayf.bin", "pause menu",
          "6b14237b541bf2733949ea87b37340f84deee9694c5ed355d667c28283690618"),
    Known("ps2exotics", "ExoticsOverlayf.bin", "exotics shop",
          "d310690986a4a5f6395580764917a08b2fdc2da689d91609b70bae72ef753614"),
    Known("ps2modals", "ModalsOverlayf.bin", "business screens",
          "327e0f391e61c728eed2f09da6880c2378f368f56791bc10a2b67af5049295f2"),
    Known("ps2modals1", "ModalsOverlay1f.bin", "empire and mansion screens",
          "d4ea255589d9678b44d64d0d88473d8dbe2469e40b262b353bf836409e2db1f6"),
    Known("ps2modals2", "ModalsOverlay2f.bin", "weapon screens",
          "dbfdc8947d1e9eef58e56524cf0375dd91ab8db0d7482e20089768ba97f825a9"),
    Known("ps2games", "MiniGamesOverlayf.bin", "gambling mini-games",
          "e5a7f8856c285a459fb8b94a35fda8a9c26e0be1b5900b2c7dcc1538962afefc"),
)
BY_BIN: Dict[str, Known] = {o.bin: o for o in OVERLAYS}
BY_FILE: Dict[str, Known] = {o.file.lower(): o for o in OVERLAYS}
BINS: Tuple[str, ...] = tuple(o.bin for o in OVERLAYS)
FOLDER = "ps2_overlays"              # binaries/ps2_overlays/<file>: where the portal keeps them
DISC_FOLDER = "overlays/frontend/"   # their folder in CEMENT.RCF (lower case, / for \\)


def is_ps2(b: Optional[str]) -> bool:
    """The PS2 program or one of its overlays: one compiler (CodeWarrior), checked through decomp.me."""
    return b == "ps2" or b in BY_BIN


def describe_bin(b: str) -> str:
    """'the PS2 game' or 'the PS2 game's pause menu overlay'."""
    o = BY_BIN.get(b)
    return f"the PS2 game's {o.label} overlay" if o else "the PS2 game"


def path_for(bin_dir: Path, b: str) -> Path:
    return Path(bin_dir) / FOLDER / BY_BIN[b].file


def sha256_of(path: Path) -> str:
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def refusal(path: Path, b: str) -> Optional[str]:
    """None if the file is the retail copy (or isn't there); otherwise why it can't be used."""
    path = Path(path)
    if not path.exists() or sha256_of(path) == BY_BIN[b].sha256:
        return None
    return (f"binaries/{FOLDER}/{path.name} is not the copy from the US PS2 disc this project uses, so matches "
            f"against it would not count. Delete it and the portal copies the right one out of your PS2 disc "
            f"the next time it starts.")


class OverlayError(ValueError):
    pass


@dataclass
class Overlay:
    number: int
    load: int
    text_size: int
    data_size: int
    bss_size: int
    ctors: Tuple[int, int]
    name: str
    file_size: int

    @property
    def text(self) -> Tuple[int, int]:
        """(address, size) of the code section."""
        return self.load + HEADER, self.text_size

    @property
    def data(self) -> Tuple[int, int]:
        return self.load + HEADER + self.text_size, self.data_size

    @property
    def end(self) -> int:
        """First address after the overlay and its bss."""
        return self.load + self.file_size + self.bss_size


def read_header(data: bytes) -> Overlay:
    if len(data) < HEADER or data[:4] != MAGIC:
        raise OverlayError("not a CodeWarrior overlay (MWo3)")
    number, load, text, dsize, bss, c0, c1 = struct.unpack_from("<7I", data, 4)
    name = data[0x20:0x40].split(b"\0")[0].decode("latin-1")
    if HEADER + text + dsize != len(data) or c1 < c0:
        raise OverlayError("the header's sizes don't add up to the file's")
    return Overlay(number, load, text, dsize, bss, (c0, c1), name, len(data))


def constructors(data: bytes, ov: Optional[Overlay] = None) -> List[int]:
    """Addresses of the static constructors the overlay asks to have called after loading."""
    ov = ov or read_header(data)
    c0, c1 = ov.ctors
    out = []
    for a in range(c0, c1, 4):
        off = a - ov.load
        if 0 <= off <= len(data) - 4:
            out.append(struct.unpack_from("<I", data, off)[0])
    return out


def calls(data: bytes, ov: Optional[Overlay] = None) -> Tuple[List[int], List[int]]:
    """(calls inside the overlay, calls into the program): the targets of every jal in the code."""
    ov = ov or read_header(data)
    inside, outside = [], []
    seg = ov.load & 0xF0000000
    for off in range(HEADER, HEADER + ov.text_size + ov.data_size - 3, 4):
        w = struct.unpack_from("<I", data, off)[0]
        if w >> 26 == 3:                                         # jal
            target = seg | ((w & 0x03FFFFFF) << 2)
            (inside if ov.load <= target < ov.load + ov.file_size else outside).append(target)
    return inside, outside


def to_elf(data: bytes) -> bytes:
    """The overlay as a small ELF file: one segment at the load address with .text, .data and .bss sections."""
    ov = read_header(data)
    names = b"\0.text\0.data\0.bss\0.mwo3\0.shstrtab\0"
    nm = {n: names.index(n.encode() + b"\0") for n in (".text", ".data", ".bss", ".mwo3", ".shstrtab")}
    ehsize, phsize, shsize = 52, 32, 40
    body_off = 0x80                                              # the overlay's bytes start here in the ELF
    strs_off = body_off + len(data)
    sh_off = (strs_off + len(names) + 3) & ~3
    sections = [
        (0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
        (nm[".mwo3"], 1, 0x2, ov.load, body_off, HEADER, 0, 0, 16, 0),                    # the header
        (nm[".text"], 1, 0x6, ov.text[0], body_off + HEADER, ov.text_size, 0, 0, 16, 0),
        (nm[".data"], 1, 0x3, ov.data[0], body_off + HEADER + ov.text_size, ov.data_size, 0, 0, 16, 0),
        (nm[".bss"], 8, 0x3, ov.load + ov.file_size, body_off + len(data), ov.bss_size, 0, 0, 16, 0),
        (nm[".shstrtab"], 3, 0, 0, strs_off, len(names), 0, 0, 1, 0),
    ]
    head = bytearray(b"\x7fELF" + bytes([1, 1, 1]) + bytes(9))
    head += struct.pack("<HHIIIIIHHHHHH", 2, 8, 1, ov.load + HEADER, ehsize, sh_off, E_FLAGS_R5900,
                        ehsize, phsize, 1, shsize, len(sections), len(sections) - 1)
    head += struct.pack("<8I", 1, body_off, ov.load, ov.load, len(data), len(data) + ov.bss_size, 7, 16)
    head = bytes(head).ljust(body_off, b"\0")
    out = bytearray(head + data + names)
    out += b"\0" * (sh_off - len(out))
    for s in sections:
        out += struct.pack("<10I", *s)
    return bytes(out)


def check(data: bytes, starts: Set[int]) -> Tuple[int, int]:
    """(calls into the program that land on one of `starts`, all calls into the program)."""
    _inside, outside = calls(data)
    return sum(1 for a in outside if a in starts), len(outside)


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description="Read the PS2's CodeWarrior overlay files (MWo3).")
    ap.add_argument("files", nargs="+", type=Path)
    ap.add_argument("--check", type=Path, metavar="SLUS_211.11",
                    help="count the calls into this program that land on the start of one of its functions")
    ap.add_argument("--elf", type=Path, metavar="FOLDER", help="write <name>.elf files there")
    a = ap.parse_args(argv)
    starts: Optional[Set[int]] = None
    if a.check:
        sys.path.insert(0, str(Path(__file__).resolve().parent))
        import ps2_binary  # noqa: E402
        starts = set(ps2_binary.find_functions(ps2_binary.Ps2Image(a.check)))
    status = 0
    for path in a.files:
        try:
            data = path.read_bytes()
            ov = read_header(data)
        except (OSError, OverlayError) as e:
            print(f"{path}: {e}", file=sys.stderr)
            status = 1
            continue
        inside, outside = calls(data, ov)
        print(f"{path.name}: overlay {ov.number} \"{ov.name}\" at {ov.load:#x}, code {ov.text_size:#x} bytes, "
              f"data {ov.data_size:#x}, bss {ov.bss_size:#x}; {len(inside)} calls inside, {len(outside)} into "
              f"the program; constructors {[hex(c) for c in constructors(data, ov)]}")
        if starts is not None:
            hit, total = check(data, starts)
            verdict = "fits" if total and hit == total else "does not fit"
            print(f"  {hit} of {total} calls land on a function start: {verdict} this program")
        if a.elf:
            a.elf.mkdir(parents=True, exist_ok=True)
            out = a.elf / (path.stem + ".elf")
            out.write_bytes(to_elf(data))
            print(f"  wrote {out}")
    return status


if __name__ == "__main__":
    sys.exit(main())
