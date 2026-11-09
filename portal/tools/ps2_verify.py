#!/usr/bin/env python3
"""
Verify a PS2 function: compile the C++ with the game's compiler on decomp.me, then compare the result
with the game's own bytes here, on your computer.

The PS2 game was built with Metrowerks CodeWarrior for PS2 3.0.1 (build 87 to 103, 2004; see
docs/PS2.md for how that was worked out). That compiler can't be shared or installed here, but
decomp.me runs it: `mwcps2-3.0.1b103-040528`, flags `-O3 -lang c++ -str readonly`. decomp.me sends back the object
file it built, and this module checks it the same way portal/tools/msvc_verify.py checks a PC or
Xbox object:

* the compiled function must have exactly the original's size and bytes;
* fields the linker fills in (call targets, %hi/%lo halves of addresses, $gp offsets) are compared
  apart from the address itself, and the address is then checked where it can be: a symbol named
  for an address (func_XXXXXXXX, D_XXXXXXXX) must be that address, a string or constant the code
  defines must be the bytes the original reads there;
* the C++ must follow the same policy as everywhere else (no inline assembly), and must not reach
  game addresses with hard-coded numbers.

    parse_object(data) -> ElfObject
    compare(target, fn, obj, fn_va, img) -> dict      (the same fields as the PC verifier)
    compile_on_decompme(slug, source, context) -> (object bytes, compiler output)
"""

from __future__ import annotations

import base64
import json
import os
import struct
import urllib.error
import urllib.request
from dataclasses import dataclass, field
from typing import Dict, List, Optional, Tuple

from ps2_binary import address_named
from ps2_mips import decode

COMPILER = "mwcps2-3.0.1b103-040528"
FLAGS = "-O3 -lang c++ -str readonly"
PLATFORM = "ps2"
DECOMPME_URL = os.environ.get("SCARFACE_DECOMPME_URL", "https://decomp.me").rstrip("/")
USER_AGENT = "scarface-decomp-portal (+https://github.com/scarface-decomp/scarface_decomp)"

SHT_SYMTAB, SHT_REL, SHT_RELA, SHT_NOBITS = 2, 9, 4, 8
SHF_EXECINSTR = 4
STT_SECTION, STT_FUNC = 3, 2
R_MIPS_32, R_MIPS_26, R_MIPS_HI16, R_MIPS_LO16, R_MIPS_GPREL16 = 2, 4, 5, 6, 7
R_MIPS_LITERAL, R_MIPS_GOT16, R_MIPS_PC16, R_MIPS_CALL16 = 8, 9, 10, 11
FIELD_MASK = {R_MIPS_26: 0x03FFFFFF, R_MIPS_32: 0xFFFFFFFF}
HALF = (R_MIPS_HI16, R_MIPS_LO16, R_MIPS_GPREL16, R_MIPS_LITERAL, R_MIPS_GOT16, R_MIPS_PC16, R_MIPS_CALL16)
for _t in HALF:
    FIELD_MASK[_t] = 0xFFFF


@dataclass
class Section:
    index: int
    name: str
    type: int
    flags: int
    data: bytes
    link: int
    info: int
    relocs: List[Tuple[int, int, int]] = field(default_factory=list)     # (offset, type, symbol index)


@dataclass
class Symbol:
    name: str
    value: int
    size: int
    type: int
    shndx: int


@dataclass
class ElfObject:
    sections: List[Section]
    symbols: List[Symbol]

    def functions(self) -> List[Section]:
        return [s for s in self.sections if s.flags & SHF_EXECINSTR and s.data]

    def name_of(self, sec: Section) -> str:
        for s in self.symbols:
            if s.shndx == sec.index and s.type == STT_FUNC and s.name:
                return s.name
        for s in self.symbols:
            if s.shndx == sec.index and s.type != STT_SECTION and s.name:
                return s.name
        return sec.name


def parse_object(data: bytes) -> ElfObject:
    """A relocatable 32-bit little-endian MIPS ELF object, as CodeWarrior writes it (one section per function)."""
    if data[:4] != b"\x7fELF" or data[4] != 1 or data[5] != 1:
        raise ValueError("not a 32-bit little-endian ELF object")
    shoff = struct.unpack_from("<I", data, 0x20)[0]
    shentsize, shnum, shstrndx = struct.unpack_from("<HHH", data, 0x2E)
    raw = []
    for i in range(shnum):
        name, typ, flags, _addr, off, size, link, info, _align, entsize = struct.unpack_from("<10I", data, shoff + i * shentsize)
        raw.append((name, typ, flags, off, size, link, info, entsize))
    strtab_off = raw[shstrndx][3] if shstrndx < len(raw) else 0

    def cstr(base: int, o: int) -> str:
        end = data.find(b"\0", base + o)
        return data[base + o:end].decode("latin-1")
    secs = []
    for i, (name, typ, flags, off, size, link, info, _es) in enumerate(raw):
        body = b"" if typ == SHT_NOBITS else data[off:off + size]
        secs.append(Section(i, cstr(strtab_off, name) if strtab_off else "", typ, flags, body, link, info))
    syms: List[Symbol] = []
    symsec = next((s for s in secs if s.type == SHT_SYMTAB), None)
    if symsec is not None:
        strbase = raw[symsec.link][3]
        for k in range(len(symsec.data) // 16):
            nm, val, sz, inf, _oth, shn = struct.unpack_from("<IIIBBH", symsec.data, 16 * k)
            syms.append(Symbol(cstr(strbase, nm) if nm else "", val, sz, inf & 15, shn))
    for s in secs:
        if s.type in (SHT_REL, SHT_RELA) and s.info < len(secs):
            step = 8 if s.type == SHT_REL else 12
            for k in range(len(s.data) // step):
                off, inf = struct.unpack_from("<II", s.data, step * k)
                secs[s.info].relocs.append((off, inf & 0xFF, inf >> 8))
    for s in secs:
        s.relocs.sort(key=lambda r: r[0])
    return ElfObject(secs, syms)


def _sext16(v: int) -> int:
    v &= 0xFFFF
    return v - 0x10000 if v & 0x8000 else v


def _payload_ok(obj: ElfObject, sym: Symbol, obj_off: int, img, orig_addr: int) -> Optional[bool]:
    """Do the object's own bytes at `sym`+obj_off (a string, a constant table) equal what the original has
    at orig_addr? None when there is nothing to compare (uninitialised data, unknown section)."""
    if not (0 < sym.shndx < len(obj.sections)):
        return None
    sec = obj.sections[sym.shndx]
    if sec.type == SHT_NOBITS or not sec.data or sec.flags & SHF_EXECINSTR:
        return None
    later = [s.value for s in obj.symbols if s.shndx == sym.shndx and s.type != STT_SECTION and s.value > obj_off]
    end = min([len(sec.data), obj_off + 64] + later)
    payload = sec.data[obj_off:end]
    if not payload:
        return None
    masked = {o + k for (o, _t, _s) in sec.relocs for k in range(4)}
    orig = img.read(orig_addr, len(payload)) if img is not None else None
    if orig is None:
        return None
    return all((obj_off + i) in masked or orig[i] == payload[i] for i in range(len(payload)))


def compare(target: bytes, fn: Section, obj: ElfObject, fn_va: int, img=None,
            names: Optional[Dict[str, int]] = None) -> dict:
    """Compare one compiled function with the original. Returns the fields the portal page shows
    (is_exact, matched_bytes, diff_details, reloc_checked, reloc_unverified, ...)."""
    names = names or {}
    code = fn.data
    n_t, n_c = len(target), len(code)
    status = ["match"] * max(n_t, n_c)
    mismatch: List[str] = []
    notes: List[str] = []
    checked = unverified = 0
    reloc_offsets = {off for off, _t, _s in fn.relocs}
    pending_hi: Dict[int, Tuple[int, int]] = {}      # symbol index -> (offset, compiled hi field)
    seen_ext: Dict[str, int] = {}

    def mark(off: int, st: str) -> None:
        for k in range(4):
            if off + k < len(status):
                status[off + k] = st

    def judge(off: int, sym: Symbol, orig_addr: int, addend: int) -> Tuple[str, str]:
        """'ok' / 'bad' / 'unverified' for an address the linker would put at `off`."""
        sym_va = (orig_addr - addend) & 0xFFFFFFFF
        if sym.shndx == fn.index:                                  # the function itself (recursion)
            if orig_addr == (fn_va + sym.value + addend) & 0xFFFFFFFF:
                return "ok", ""
            return "bad", f"+0x{off:X}: refers to its own code at a different place than the original"
        named = address_named(sym.name)
        if named is not None:
            return ("ok", "") if named == sym_va else ("bad", f"+0x{off:X}: '{sym.name}' is named for 0x{named:08X}, "
                                                          f"but the original uses 0x{sym_va:08X} here")
        if sym.name in names:
            return ("ok", "") if names[sym.name] == sym_va else ("bad", f"+0x{off:X}: '{sym.name}' is 0x{names[sym.name]:08X}, "
                                                                    f"but the original uses 0x{sym_va:08X} here")
        if 0 < sym.shndx < len(obj.sections):
            ok = _payload_ok(obj, sym, sym.value + addend, img, orig_addr)
            if ok is True:
                return "ok", ""
            if ok is False:
                return "bad", f"+0x{off:X}: the data this code defines is not what the original reads at 0x{orig_addr:08X}"
        prev = seen_ext.get(sym.name)
        if sym.name and prev is not None and prev != sym_va:
            return "bad", f"+0x{off:X}: '{sym.name}' is used for two different original addresses"
        if sym.name:
            seen_ext[sym.name] = sym_va
        return "unverified", ""

    for off, typ, si in fn.relocs:
        if off + 4 > n_c or off + 4 > n_t:
            mismatch.append(f"+0x{off:X}: relocation outside the original function")
            mark(off, "diff")
            continue
        mask = FIELD_MASK.get(typ)
        cw = struct.unpack_from("<I", code, off)[0]
        tw = struct.unpack_from("<I", target, off)[0]
        if mask is None:
            notes.append(f"+0x{off:X}: relocation type {typ} not checked")
            mark(off, "diff")
            continue
        if (cw & ~mask) != (tw & ~mask):
            mark(off, "diff")
            continue
        mark(off, "reloc")
        sym = obj.symbols[si] if si < len(obj.symbols) else Symbol("", 0, 0, 0, 0)
        verdict, why = "unverified", ""
        if typ == R_MIPS_26:
            orig = ((fn_va + off + 4) & 0xF0000000) | ((tw & 0x03FFFFFF) << 2)
            verdict, why = judge(off, sym, orig, (cw & 0x03FFFFFF) << 2)
        elif typ == R_MIPS_HI16:
            pending_hi[si] = (off, cw & 0xFFFF)
            continue                                              # judged with its %lo partner
        elif typ == R_MIPS_LO16 and si in pending_hi:
            hoff, chi = pending_hi[si]
            thi = struct.unpack_from("<I", target, hoff)[0] & 0xFFFF
            orig = ((thi << 16) + _sext16(tw)) & 0xFFFFFFFF
            addend = ((chi << 16) + _sext16(cw)) & 0xFFFFFFFF
            verdict, why = judge(off, sym, orig, addend)
            if verdict == "ok":
                mark(hoff, "linked")                              # the pair is one address: counted once
            elif verdict == "bad":
                mark(hoff, "diff")
        elif typ == R_MIPS_GPREL16 and img is not None and getattr(img, "gp", 0):
            orig = (img.gp + _sext16(tw)) & 0xFFFFFFFF
            verdict, why = judge(off, sym, orig, _sext16(cw))
        if verdict == "ok":
            checked += 1
            mark(off, "linked")
        elif verdict == "bad":
            mismatch.append(why)
            mark(off, "diff")
        else:
            unverified += 1
    for si, (hoff, _chi) in pending_hi.items():
        if status[hoff] == "reloc":
            unverified += 1                                       # a %hi with no %lo after it

    matched = 0
    details = []
    for i in range(max(n_t, n_c)):
        t = target[i] if i < n_t else None
        c = code[i] if i < n_c else None
        st = status[i]
        if t is None or c is None:
            st = "diff"
        elif st == "match" and t != c:
            st = "diff"
        if st in ("match", "reloc", "linked") and i < n_t:
            matched += 1
        details.append({"idx": i, "target": f"{t:02X}" if t is not None else "--",
                        "compiled": f"{c:02X}" if c is not None else "--", "status": st})
    if n_c != n_t:
        notes.append(f"Compiled function is {n_c} bytes; the original is {n_t} bytes.")
    hard = hardcoded_addresses(code, reloc_offsets, img)
    exact = n_c == n_t and matched == n_t and not mismatch
    return {"is_exact": exact, "matched_bytes": matched, "total_bytes": n_t, "compiled_size": n_c,
            "match_percent": round(matched / n_t * 100.0, 2) if n_t else 0.0, "diff_details": details,
            "reloc_checked": checked, "reloc_unverified": unverified, "reloc_mismatch": mismatch,
            "notes": notes, "hardcoded_addresses": hard}


def hardcoded_addresses(code: bytes, reloc_offsets: set, img) -> List[str]:
    """Places where the compiled code reaches a game address through plain numbers (a `lui`/`%lo` pair or a
    `jal` without a relocation): they can match the bytes, but only because the number was copied from the
    2006 program, so they block VERIFIED, like hard-coded addresses on PC and Xbox."""
    if img is None:
        return []
    out = []
    hi: Dict[int, Tuple[int, int]] = {}
    for i in range(len(code) // 4):
        off = 4 * i
        w = struct.unpack_from("<I", code, off)[0]
        ins = decode(w, off)
        if off in reloc_offsets:
            for r in ins.writes:
                hi.pop(r, None)
            continue
        if ins.kind in ("call", "jump"):
            out.append(f"+0x{off:X}: {ins.mn} to a fixed address")
            continue
        if ins.lo_base is not None and ins.lo_base in hi:
            hoff, upper = hi[ins.lo_base]
            addr = (upper + ins.imm) & 0xFFFFFFFF
            if img.in_image(addr):
                out.append(f"+0x{hoff:X}: the address 0x{addr:08X} is written as a number")
        if ins.hi_reg is not None:
            hi[ins.hi_reg] = (off, ins.imm << 16)
        else:
            for r in ins.writes:
                hi.pop(r, None)
    return out


def best_function(target: bytes, obj: ElfObject, fn_va: int, img=None,
                  names: Optional[Dict[str, int]] = None) -> Tuple[Optional[Section], dict]:
    """The compiled function that matches the original best (the source may define helpers too)."""
    best_fn, best_res, best_key = None, {}, None
    for fn in obj.functions():
        res = compare(target, fn, obj, fn_va, img, names)
        key = (bool(res["is_exact"] and not res["hardcoded_addresses"]), res["matched_bytes"],
               -abs(res["compiled_size"] - len(target)))
        if best_key is None or key > best_key:
            best_fn, best_res, best_key = fn, res, key
    return best_fn, best_res


# --------------------------------------------------------------------------- #
# decomp.me
# --------------------------------------------------------------------------- #

def _post_json(url: str, body: dict, timeout: int = 90) -> Tuple[int, dict, str]:
    req = urllib.request.Request(url, data=json.dumps(body).encode("utf-8"), method="POST",
                                 headers={"Content-Type": "application/json", "Accept": "application/json",
                                          "User-Agent": USER_AGENT})
    try:
        with urllib.request.urlopen(req, timeout=timeout) as r:
            raw = r.read().decode("utf-8", "replace")
            return r.status, json.loads(raw), raw
    except urllib.error.HTTPError as e:
        raw = e.read().decode("utf-8", "replace")[:600]
        try:
            return e.code, json.loads(raw), raw
        except ValueError:
            return e.code, {}, raw


def scratch_fields(name: str, target_asm: str, source: str, context: str = "", diff_label: str = "",
                   preset: str = "") -> dict:
    fields = {"platform": PLATFORM, "compiler": COMPILER, "compiler_flags": FLAGS, "name": name[:100],
              "target_asm": target_asm, "source_code": source.replace("\r\n", "\n"),
              "context": context.replace("\r\n", "\n"), "diff_label": diff_label}
    if preset.isdigit():
        fields["preset"] = int(preset)
    return fields


def create_scratch(fields: dict, base_url: str = DECOMPME_URL) -> dict:
    """POST /api/scratch with a target written as assembly. {ok, slug, url, claim_url} or {ok: False, error}."""
    try:
        st, data, raw = _post_json(f"{base_url}/api/scratch", fields)
    except (urllib.error.URLError, TimeoutError, OSError) as e:
        return {"ok": False, "unreachable": True, "error": f"Could not reach decomp.me ({e})."}
    except ValueError:
        return {"ok": False, "error": "decomp.me sent back something that was not JSON."}
    slug = data.get("slug") if isinstance(data, dict) else None
    if st >= 300 or not slug:
        return {"ok": False, "unreachable": st in (403, 429, 503),
                "error": f"decomp.me answered {st}: {(raw or '')[:300]}"}
    url = f"{base_url}/scratch/{slug}"
    token = data.get("claim_token")
    return {"ok": True, "slug": slug, "url": url, "claim_url": f"{url}/claim?token={token}" if token else url,
            "score": data.get("score"), "max_score": data.get("max_score")}


def compile_on_decompme(slug: str, source: str, context: str = "", base_url: str = DECOMPME_URL) -> dict:
    """Compile with the game's compiler on decomp.me, without saving anything there.
    {ok, object (bytes), output} or {ok: False, error, unreachable?, compiler_error?}."""
    body = {"compiler": COMPILER, "compiler_flags": FLAGS, "source_code": source.replace("\r\n", "\n"),
            "context": context.replace("\r\n", "\n"), "include_objects": True}
    try:
        st, data, raw = _post_json(f"{base_url}/api/scratch/{slug}/compile", body)
    except (urllib.error.URLError, TimeoutError, OSError) as e:
        return {"ok": False, "unreachable": True, "error": f"Could not reach decomp.me ({e})."}
    except ValueError:
        return {"ok": False, "error": "decomp.me sent back something that was not JSON."}
    if st >= 300 or not isinstance(data, dict):
        return {"ok": False, "unreachable": st in (403, 429, 503), "error": f"decomp.me answered {st}: {(raw or '')[:300]}"}
    out = data.get("compiler_output") or ""
    if not data.get("success") or not data.get("right_object"):
        return {"ok": False, "compiler_error": out or "The compiler did not produce an object."}
    try:
        obj = base64.b64decode(data["right_object"])
    except (ValueError, TypeError):
        return {"ok": False, "error": "decomp.me sent back an object that could not be read."}
    return {"ok": True, "object": obj, "output": out}
