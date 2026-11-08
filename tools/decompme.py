#!/usr/bin/env python3
"""
Send one Scarface function to decomp.me, so anyone can work on it in the browser.

decomp.me (https://decomp.me) hosts Microsoft Visual C++ 7.1 for its "Windows (9x/NT)" platform,
the same compiler this project verifies with. A scratch there needs the *target*: the original
function as an object file. This module builds that object from the game file on your own computer:

* the function's bytes go into a `.text` section, exactly as they are in the game;
* every place that holds an address of something else (a call to another function, a global
  variable, a string, a float constant) gets a COFF relocation to an address-named symbol,
  `_sub_XXXXXXXX` for code and `_DAT_XXXXXXXX` for data. That is the name MSVC gives
  `extern "C" void sub_XXXXXXXX();` / `extern "C" int DAT_XXXXXXXX;`, the convention this
  project already uses, so a correct guess scores 100% on decomp.me.

Only that one function's bytes leave your computer (the same thing every decomp.me scratch holds).
decomp.me's score is a helper; the portal's Verify button stays the check that counts.

Command line (handy for testing):

    python tools/decompme.py --bin pc --va 0x006E6730 --size 39 --obj target.obj
    python tools/decompme.py --bin pc --va 0x006E6730 --size 39 --create
"""

from __future__ import annotations

import argparse
import json
import os
import secrets
import struct
import sys
import urllib.error
import urllib.request
from dataclasses import dataclass
from pathlib import Path
from typing import Dict, List, Optional, Tuple

DECOMPME_URL = os.environ.get("SCARFACE_DECOMPME_URL", "https://decomp.me").rstrip("/")
COMPILER = "msvc7.1"
PLATFORM = "win32"
USER_AGENT = "scarface-decomp-portal (+https://github.com/scarface-decomp/scarface_decomp)"

IMAGE_REL_I386_DIR32 = 0x0006
IMAGE_REL_I386_REL32 = 0x0014
TEXT_CHARS = 0x60500020          # CNT_CODE | ALIGN_16BYTES | MEM_EXECUTE | MEM_READ, as MSVC writes it
SECTION_SYMBOL = ".text"
SELF_SYMBOL = "@self"            # the function's own start, e.g. `return &sub_00066D80;`


@dataclass(frozen=True)
class Reloc:
    offset: int          # where the 4-byte field starts, from the start of the function
    symbol: str          # "_sub_XXXXXXXX", "_DAT_XXXXXXXX", ".text" (a place inside this function) or SELF_SYMBOL
    kind: int            # IMAGE_REL_I386_DIR32 or IMAGE_REL_I386_REL32
    addend: int = 0      # value left in the field (only for ".text" targets)


def address_symbol(image, addr: int) -> str:
    sec = image.section_of(addr)
    return f"_{'sub' if sec is not None and sec.is_code else 'DAT'}_{addr:08X}"


def _address_range(image) -> Tuple[int, int]:
    lo = min(s.va for s in image.sections)
    hi = max(s.va + max(s.vsize, s.raw_size) for s in image.sections)
    return max(lo, image.image_base + 0x1000), hi


def find_relocations(code: bytes, va: int, image) -> List[Reloc]:
    """Every address the function holds, as the relocations MSVC would have written for it."""
    try:
        import capstone
        from capstone import x86_const as X
    except ImportError as e:
        raise RuntimeError("The Capstone disassembler is required: pip install capstone") from e
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    n = len(code)
    end = va + n
    lo, hi = _address_range(image)
    relocs: Dict[int, Reloc] = {}
    data_regions: Dict[int, str] = {}      # start offset -> "dword" (jump table) or "byte" (index table)

    def add_abs(field_off: int, value: int) -> None:
        if value == va:
            relocs[field_off] = Reloc(field_off, SELF_SYMBOL, IMAGE_REL_I386_DIR32)
        elif va < value < end:
            relocs[field_off] = Reloc(field_off, SECTION_SYMBOL, IMAGE_REL_I386_DIR32, value - va)
        elif lo <= value < hi and image.section_of(value) is not None:
            relocs[field_off] = Reloc(field_off, address_symbol(image, value), IMAGE_REL_I386_DIR32)

    off = 0
    while off < n:
        if off in data_regions:
            kind = data_regions[off]
            nxt = min([s for s in data_regions if s > off] + [n])
            if kind == "dword":
                while off + 4 <= nxt:
                    entry = struct.unpack_from("<I", code, off)[0]
                    if not (va <= entry < end):
                        break
                    relocs[off] = Reloc(off, SECTION_SYMBOL, IMAGE_REL_I386_DIR32, entry - va)
                    off += 4
                if off < nxt and off not in data_regions:
                    continue          # whatever follows the table is decoded again
            else:
                off = nxt
            continue
        insn = next(md.disasm(code[off:off + 16], va + off, 1), None)
        if insn is None:
            off += 1
            continue
        # An instruction that would run into a known table is really padding: stop at the table.
        later = [s for s in data_regions if off < s < off + insn.size]
        if later:
            off = min(later)
            continue
        is_branch = insn.group(capstone.CS_GRP_JUMP) or insn.group(capstone.CS_GRP_CALL)
        for op in insn.operands:
            if op.type == X.X86_OP_IMM and insn.imm_size == 4 and insn.imm_offset:
                value = op.imm & 0xFFFFFFFF
                field = off + insn.imm_offset
                if is_branch:
                    # call/jmp/jcc rel32: a reloc only when it leaves this function
                    if not (va <= value < end) and image.section_of(value) is not None:
                        relocs[field] = Reloc(field, address_symbol(image, value), IMAGE_REL_I386_REL32)
                else:
                    add_abs(field, value)
            elif op.type == X.X86_OP_MEM and insn.disp_size == 4 and insn.disp_offset:
                value = op.mem.disp & 0xFFFFFFFF
                field = off + insn.disp_offset
                add_abs(field, value)
                if va <= value < end and value - va > off:
                    t = value - va
                    if is_branch and op.mem.scale == 4:
                        data_regions.setdefault(t, "dword")      # jmp dword ptr [reg*4 + table]
                    elif op.size == 1:
                        data_regions.setdefault(t, "byte")       # movzx reg, byte ptr [reg + index]
        off += insn.size
    return [relocs[k] for k in sorted(relocs)]


# --------------------------------------------------------------------------- #
# COFF object writer
# --------------------------------------------------------------------------- #

def _sym_name(name: str, strtab: bytearray) -> bytes:
    raw = name.encode("utf-8")
    if len(raw) <= 8:
        return raw.ljust(8, b"\0")
    off = 4 + len(strtab)
    strtab += raw + b"\0"
    return struct.pack("<II", 0, off)


def build_target_object(code: bytes, relocs: List[Reloc], func_name: str) -> bytes:
    """A one-function i386 COFF object, laid out the way MSVC lays out its own .obj files."""
    body = bytearray(code)
    for r in relocs:
        struct.pack_into("<I", body, r.offset, r.addend & 0xFFFFFFFF)

    externs: List[str] = []
    for r in relocs:
        if r.symbol not in (SECTION_SYMBOL, SELF_SYMBOL) and r.symbol not in externs:
            externs.append(r.symbol)
    # 0: .text (+1 aux record)   2: the function   3..: undefined externals
    index = {SECTION_SYMBOL: 0, SELF_SYMBOL: 2}
    for i, name in enumerate(externs):
        index[name] = 3 + i

    strtab = bytearray()
    syms = bytearray()
    syms += _sym_name(SECTION_SYMBOL, strtab) + struct.pack("<IhHBB", 0, 1, 0, 3, 1)
    syms += struct.pack("<IHHIHB3x", len(body), len(relocs), 0, 0, 0, 0)
    syms += _sym_name(func_name, strtab) + struct.pack("<IhHBB", 0, 1, 0x20, 2, 0)
    for name in externs:
        is_func = name.startswith("_sub_")
        syms += _sym_name(name, strtab) + struct.pack("<IhHBB", 0, 0, 0x20 if is_func else 0, 2, 0)
    nsyms = len(syms) // 18

    raw_ptr = 20 + 40
    rel_ptr = raw_ptr + len(body)
    sym_ptr = rel_ptr + 10 * len(relocs)
    out = bytearray()
    out += struct.pack("<HHIIIHH", 0x14C, 1, 0, sym_ptr, nsyms, 0, 0)
    out += struct.pack("<8sIIIIIIHHI", b".text", 0, 0, len(body), raw_ptr,
                       rel_ptr if relocs else 0, 0, len(relocs), 0, TEXT_CHARS)
    out += body
    for r in relocs:
        out += struct.pack("<IIH", r.offset, index[r.symbol], r.kind)
    out += syms
    out += struct.pack("<I", 4 + len(strtab)) + strtab
    return bytes(out)


def object_symbol_name(symbol: str, va: int) -> str:
    """A readable label for the target function (decomp.me shows it above the assembly)."""
    name = "".join(ch if ch.isalnum() or ch in "_:?$@<>~" else "_" for ch in (symbol or ""))
    return name or f"sub_{va:08X}"


# --------------------------------------------------------------------------- #
# What the scratch starts with
# --------------------------------------------------------------------------- #

def scratch_source(symbol: str, va_label: str, starter_cpp: str) -> str:
    header = (
        f"// Scarface: The World Is Yours - {symbol} ({va_label})\n"
        "//\n"
        "// Goal: change this C++ until decomp.me shows 100% (no red or yellow lines).\n"
        "// Then copy it into your Scarface portal and press Verify there.\n"
        "//\n"
        "// Unknown globals and functions use their address as a name, declared extern \"C\":\n"
        "//     extern \"C\" int  DAT_007A1234;        // a global at 0x007A1234\n"
        "//     extern \"C\" void sub_00401000(void);  // a function at 0x00401000\n"
        "\n"
    )
    return header + (starter_cpp or "").strip() + "\n"


def _inline_project_includes(code: str, include_dirs: List[Path]) -> Tuple[str, str]:
    """decomp.me only has the compiler's own headers: move `#include "x.h"` of ours into the context."""
    context_parts: List[str] = []
    kept: List[str] = []
    for line in code.splitlines():
        s = line.strip()
        if s.startswith("#include") and '"' in s:
            name = s.split('"')[1]
            hit = next((d / name for d in include_dirs if (d / name).is_file()), None)
            if hit is not None:
                text = hit.read_text(encoding="utf-8", errors="ignore").replace("#pragma once", "")
                context_parts.append(f"// ---- {name} ----\n{text}")
                continue
        kept.append(line)
    return "\n".join(kept), "\n".join(context_parts)


# --------------------------------------------------------------------------- #
# decomp.me API
# --------------------------------------------------------------------------- #

def _multipart(fields: Dict[str, str], files: Dict[str, Tuple[str, bytes]]) -> Tuple[bytes, str]:
    boundary = "----scarface" + secrets.token_hex(12)
    out = bytearray()
    for k, v in fields.items():
        out += f"--{boundary}\r\nContent-Disposition: form-data; name=\"{k}\"\r\n\r\n".encode()
        out += v.encode("utf-8") + b"\r\n"
    for k, (filename, data) in files.items():
        out += (f"--{boundary}\r\nContent-Disposition: form-data; name=\"{k}\"; filename=\"{filename}\"\r\n"
                "Content-Type: application/octet-stream\r\n\r\n").encode()
        out += data + b"\r\n"
    out += f"--{boundary}--\r\n".encode()
    return bytes(out), f"multipart/form-data; boundary={boundary}"


def scratch_fields(name: str, flags: str, source: str, context: str) -> Dict[str, str]:
    # decomp.me compiles as C unless told otherwise; /TP makes it C++ like our own .cpp compiles.
    if "/TP" not in flags.split():
        flags = ("/TP " + flags).strip()
    return {"name": name[:100], "compiler": COMPILER, "platform": PLATFORM,
            "compiler_flags": flags, "source_code": source, "context": context, "diff_label": ""}


def create_scratch(obj: bytes, fields: Dict[str, str], base_url: str = DECOMPME_URL, timeout: int = 60) -> dict:
    """POST /api/scratch. Returns {ok, slug, url, claim_url, score, max_score} or {ok: False, error}."""
    body, ctype = _multipart(fields, {"target_obj": ("target.obj", obj)})
    req = urllib.request.Request(f"{base_url}/api/scratch", data=body, method="POST",
                                 headers={"Content-Type": ctype, "Accept": "application/json",
                                          "User-Agent": USER_AGENT})
    try:
        with urllib.request.urlopen(req, timeout=timeout) as r:
            data = json.loads(r.read().decode("utf-8", "replace"))
    except urllib.error.HTTPError as e:
        detail = e.read().decode("utf-8", "replace")[:400]
        return {"ok": False, "error": f"decomp.me answered {e.code}: {detail}"}
    except (urllib.error.URLError, TimeoutError, OSError) as e:
        return {"ok": False, "error": f"Could not reach decomp.me ({e}). Check your internet connection."}
    except ValueError:
        return {"ok": False, "error": "decomp.me sent back something that was not JSON."}
    slug = data.get("slug")
    if not slug:
        return {"ok": False, "error": f"decomp.me did not create a scratch: {json.dumps(data)[:400]}"}
    url = f"{base_url}/scratch/{slug}"
    token = data.get("claim_token")
    return {"ok": True, "slug": slug, "url": url,
            "claim_url": f"{url}/claim?token={token}" if token else url,
            "score": data.get("score"), "max_score": data.get("max_score")}


def prepare(image, va: int, size: int, symbol: str, flags: str, starter_cpp: str,
            include_dirs: Optional[List[Path]] = None) -> Tuple[bytes, Dict[str, str]]:
    """The target object and the form fields for one function."""
    code = image.read(va, size)
    if code is None:
        raise ValueError(f"0x{va:08X}+{size} is outside the game file")
    obj = build_target_object(code, find_relocations(code, va, image), object_symbol_name(symbol, va))
    src, ctx = _inline_project_includes(starter_cpp or "", include_dirs or [])
    fields = scratch_fields(f"Scarface {symbol or f'sub_{va:08X}'}", flags,
                            scratch_source(symbol, f"0x{va:08X}, {size} bytes", src), ctx)
    return obj, fields


def main(argv: Optional[List[str]] = None) -> int:
    here = Path(__file__).resolve().parent
    sys.path.insert(0, str(here))
    from sf_binaries import BinaryImage

    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--bin", choices=["pc", "xb", "proto"], required=True)
    ap.add_argument("--va", required=True)
    ap.add_argument("--size", type=int, required=True)
    ap.add_argument("--symbol", default="")
    ap.add_argument("--flags", default="/O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4")
    ap.add_argument("--source", type=Path, help="C++ file to start the scratch with")
    ap.add_argument("--obj", type=Path, help="write the target object here")
    ap.add_argument("--create", action="store_true", help="create the scratch on decomp.me")
    a = ap.parse_args(argv)
    root = here.parent / "binaries"
    path = {"pc": root / "Scarface.exe", "xb": root / "default.xbe", "proto": root / "game.xbe"}[a.bin]
    image = BinaryImage(path)
    va = int(a.va, 0)
    starter = a.source.read_text(encoding="utf-8") if a.source else f"void sub_{va:08X}(void)\n{{\n}}\n"
    obj, fields = prepare(image, va, a.size, a.symbol, a.flags, starter, [here.parent / "include"])
    if a.obj:
        a.obj.write_bytes(obj)
        print(f"wrote {a.obj} ({len(obj)} bytes)")
    if a.create:
        res = create_scratch(obj, fields)
        print(json.dumps(res, indent=2))
        return 0 if res.get("ok") else 1
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
