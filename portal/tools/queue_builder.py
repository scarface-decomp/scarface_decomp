#!/usr/bin/env python3
"""
Build reports/full_remaining_queue.json: the functions contributors can claim.

Differences from the old index builder in portal/decomp_portal_server.py:
  * sizes come from recursive-descent disassembly (portal/tools/sf_binaries.function_extent), not from
    "distance to the next CC CC, else 64";
  * no fixed target count (the old builder stopped at 20,753 - 2,769 = 17,984 tasks);
  * no invented addresses (the old "prototype" lane used fake VAs);
  * starts that fall inside another function are dropped unless something calls them;
  * functions already in reports/verified_registry.json are left out;
  * starts whose bytes the compiler could never have made (data, or the middle of an instruction:
    sf_binaries.not_compiled_reason) are left out;
  * look-alikes (same machine code apart from addresses, portal/tools/lookalikes.py) are grouped, so the
    portal can show one of each group first and carry a match over to the rest.
"""

from __future__ import annotations

import json
import re
import struct
from pathlib import Path
from typing import Dict, List, Optional, Set, Tuple

import lookalikes
import ps2_overlay
from msvc_verify import decorated_hint
from sf_binaries import BinaryImage, Extent, collect_call_targets, function_extent, not_compiled_reason

# Bumped when the checks that keep data out of the queue change; the portal re-checks older queues.
CODE_CHECK = 2

PC_FLAGS = "/O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4"
# Only this part of the retail PC .text is stored as plaintext (the rest is not readable code),
# so PC tasks are limited to it. Same bounds as the original index builder.
PC_PLAINTEXT = (0x006DDC00, 0x0072EADC)
XB_FLAGS = "/O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4"
# The April 20, 2006 Xbox prototype (game.xbe, optional): unreleased code. Its functions are queued,
# verified and saved like the others, and counted on their own row. About half of them have the same
# machine code as a retail Xbox function, so look-alike porting fills those in as retail is matched.
LANES = {"pc": ("pc_", "PC Scarface.exe", "PC "), "xb": ("xb_", "Shared Engine & Gameplay", ""),
         "proto": ("proto_", "Xbox Prototype (Apr 2006)", "Proto "),
         "ps2": ("ps2_", "PS2 SLUS_211.11", "PS2 ")}
# The PS2 program's code overlays (CEMENT.RCF/Overlays/FrontEnd, portal/tools/ps2_overlay.py): code the
# program loads at 0x845480 when it needs it. Each has its own lane, as they all share those addresses.
for _o in ps2_overlay.OVERLAYS:
    LANES[_o.bin] = (_o.bin + "_", f"PS2 overlay: {_o.label}", "PS2 ")
# The PS2 game (SLUS_211.11) was built with Metrowerks CodeWarrior for PS2, not Visual C++: its functions are
# compiled on decomp.me and compared here (portal/tools/ps2_verify.py, docs/PS2.md).
PS2_FLAGS = "-O3 -lang c++ -str readonly"


_BUILTIN = {"X": "void", "D": "char", "C": "signed char", "E": "unsigned char", "F": "short",
            "G": "unsigned short", "H": "int", "I": "unsigned int", "J": "long", "K": "unsigned long",
            "M": "float", "N": "double", "O": "long double", "_N": "bool", "_J": "__int64",
            "_K": "unsigned __int64", "_W": "wchar_t"}


class _Demangler:
    """Just enough of the MSVC name decoding for RTTI type names (scopes, templates, simple args)."""

    def __init__(self, s: str):
        self.s, self.i, self.names = s, 0, []

    def peek(self, n: int = 1) -> str:
        return self.s[self.i:self.i + n]

    def take(self, n: int = 1) -> str:
        out = self.s[self.i:self.i + n]
        self.i += n
        return out

    def fragment(self) -> str:
        if self.peek().isdigit():
            return self.names[int(self.take())]
        if self.peek(2) == "?$":
            self.take(2)
            outer = self.names
            self.names = []
            name = self.ident()
            self.names.append(name)
            args = []
            while self.peek() and self.peek() != "@":
                args.append(self.type())
            self.take()                                     # '@' ends the argument list
            self.names = outer
            frag = f"{name}<{', '.join(args)}>"
            self.names.append(frag)
            return frag
        name = self.ident()
        self.names.append(name)
        return name

    def ident(self) -> str:
        j = self.s.index("@", self.i)
        name = self.s[self.i:j]
        self.i = j + 1
        return name

    def qualified(self) -> str:
        parts = []
        while self.peek() and self.peek() != "@":
            parts.append(self.fragment())
        self.take()                                         # '@' ends the qualified name
        return "::".join(reversed(parts))

    def number(self) -> str:
        neg = self.peek() == "?"
        if neg:
            self.take()
        c = self.take()
        if c.isdigit():
            v = int(c) + 1
        else:
            v = 0
            while c != "@":
                v = v * 16 + (ord(c) - ord("A"))
                c = self.take()
        return str(-v if neg else v)

    def type(self) -> str:
        c = self.take()
        if c in "VUT":
            return self.qualified()
        if c == "W":
            self.take()
            return self.qualified()
        if c in "PQRSA":
            cv = self.take()
            inner = self.type()
            const = "const " if cv in "BD" else ""
            return f"{const}{inner}{'&' if c == 'A' else '*'}"
        if c == "_":
            return _BUILTIN.get("_" + self.take(), "?")
        if c == "$":
            if self.take() == "0":
                return self.number()
            raise ValueError("unsupported template argument")
        if c in _BUILTIN:
            return _BUILTIN[c]
        raise ValueError(f"unsupported type code {c!r}")


def demangle_rtti(raw: str) -> str:
    """'.?AV?$ConcreteClassRep@VFEObject@@@@' -> 'ConcreteClassRep<FEObject>'."""
    s = raw[4:] if raw.startswith(".?A") else raw
    try:
        return _Demangler(s).qualified()
    except (ValueError, IndexError):
        parts = [p for p in s.rstrip("@").split("@") if p]
        return "::".join(reversed(parts)) if parts else raw


def rtti_match_hint(raw: str, method: str) -> str:
    """Decorated-name fragment of method in the class whose RTTI name is raw: the class part of a
    member's decorated name is written exactly as in the RTTI name ('?vfunc_00@Project@frontend@pure3d@@...')."""
    return f"{method}@{raw[4:]}" if raw.startswith(".?A") else method


def vtable_methods(img: BinaryImage) -> Dict[int, Tuple[str, int, str]]:
    """VA -> (class, slot, raw RTTI name) from MSVC RTTI complete-object locators that sit just before vtables."""
    d = img.data
    td_to_cls: Dict[int, Tuple[str, str]] = {}
    for m in re.finditer(rb"\.\?A[VU][A-Za-z0-9_@?$<>]+@@\x00", d):
        name = m.group(0)[:-1].decode("ascii", "ignore")
        off = m.start() - 8                         # TypeDescriptor: vftable ptr, spare, name
        sec = next((s for s in img.sections if s.raw <= off < s.raw + s.raw_size), None)
        if sec:
            td_to_cls[sec.va + (off - sec.raw)] = (demangle_rtti(name), name)
    col_to_cls: Dict[int, Tuple[str, str]] = {}
    data_secs = [s for s in img.sections if not s.is_code and s.raw_size]
    for s in data_secs:
        blob = d[s.raw:s.raw + s.raw_size]
        for off in range(0, len(blob) - 20, 4):
            p_td = struct.unpack_from("<I", blob, off + 12)[0]
            if p_td in td_to_cls:
                sig, _voff, cdoff = struct.unpack_from("<III", blob, off)
                if sig == 0 and cdoff == 0:
                    col_to_cls[s.va + off] = td_to_cls[p_td]
    out: Dict[int, Tuple[str, int, str]] = {}
    code = img.code_sections()

    def in_code(va: int) -> bool:
        return any(c.va <= va < c.va + c.raw_size for c in code)

    for s in data_secs:
        blob = d[s.raw:s.raw + s.raw_size]
        for off in range(0, len(blob) - 8, 4):
            ptr = struct.unpack_from("<I", blob, off)[0]
            if ptr in col_to_cls:
                cls, raw = col_to_cls[ptr]
                for slot in range(256):
                    o = off + 4 + slot * 4
                    if o + 4 > len(blob):
                        break
                    fva = struct.unpack_from("<I", blob, o)[0]
                    if not in_code(fva):
                        break
                    out.setdefault(fva, (cls, slot, raw))
    return out


def tier(size: int) -> dict:
    if size < 20:
        return {"tier": "TIER_1_QUICK", "tier_label": "Tier 1: Quick (<20 B)", "est_label": "~5 mins", "lease_minutes": 15}
    if size < 40:
        return {"tier": "TIER_2_SMALL", "tier_label": "Tier 2: Small (20-39 B)", "est_label": "~15 mins", "lease_minutes": 30}
    if size < 80:
        return {"tier": "TIER_3_MEDIUM", "tier_label": "Tier 3: Medium (40-79 B)", "est_label": "~30 mins", "lease_minutes": 60}
    return {"tier": "TIER_4_LARGE", "tier_label": "Tier 4: Large (80+ B)", "est_label": "~60+ mins", "lease_minutes": 120}


def seed_data(root: Path) -> dict:
    """The tracked inputs that, with the game files, decide the queue: reports/known_functions.json and
    reports/extra_function_starts.json. Pass as build_queue(..., **seed_data(root))."""
    def load(name: str) -> dict:
        p = root / "reports" / name
        try:
            return json.loads(p.read_text(encoding="utf-8")) if p.exists() else {}
        except ValueError:
            return {}
    return {"known_functions": load("known_functions.json").get("functions", []),
            "extra_starts": load("extra_function_starts.json").get("starts", {})}


def build_queue(binaries: Dict[str, Path], old_queue: Optional[List[dict]] = None,
                verified_keys: Optional[Set[str]] = None, progress=None,
                known_functions: Optional[List[dict]] = None,
                extra_starts: Optional[Dict[str, List[str]]] = None) -> List[dict]:
    """known_functions: [{bin, va, size, symbol, match}] whose start and size were proven earlier by an
    exact byte match (reports/known_functions.json). They are always queued, with that size, even where
    the scanner alone would not find them (tiny stubs, starts inside padding).
    extra_starts: {bin: ["0x...", ...]} starts that calls and vtables do not reveal
    (reports/extra_function_starts.json), so a fresh copy builds the same queue as an old one."""
    verified_keys = verified_keys or set()
    old_by_key = {}
    for t in old_queue or []:
        if "fva_int" in t and t.get("bin") in LANES:
            old_by_key[f"{t['bin']}:0x{t['fva_int']:08X}"] = t
    tasks: List[dict] = []
    images: Dict[str, BinaryImage] = {}
    classes: Dict[str, Set[str]] = {}
    for b in LANES:
        p = binaries.get(b)
        if not p or not Path(p).exists():
            continue
        if ps2_overlay.is_ps2(b):
            continue                            # after the Xbox game: its functions name the PS2 ones
        img = images[b] = BinaryImage(p)
        calls = collect_call_targets(img)
        vt = vtable_methods(img)
        classes[b] = {cls for cls, _slot, _raw in vt.values()}
        kf = {int(f["va"], 16): f for f in (known_functions or []) if f.get("bin") == b}
        starts: Set[int] = set(vt) | set(kf) | {t["fva_int"] for k, t in old_by_key.items() if k.startswith(b + ":")}
        starts |= {int(v, 16) for v in (extra_starts or {}).get(b, [])}
        if b != "pc":
            starts |= {c for c in calls}
        else:
            lo, hi = PC_PLAINTEXT
            starts = {s for s in starts | calls if lo <= s < hi}
        known = set(calls) | set(vt) | set(kf)
        extents = {}
        for i, va in enumerate(sorted(starts)):
            sec = img.section_of(va)
            if not sec or not sec.is_code or sec.library:
                continue                        # data, or Xbox XDK / Bink library code
            e = function_extent(img, va, known)
            if va in kf:
                e = Extent(va, int(kf[va]["size"]), True, "size proven by an earlier exact match",
                           has_jump_table=e.has_jump_table if e.ok else False)
            if b == "pc" and e.ok and va + e.size > PC_PLAINTEXT[1]:
                continue
            if e.ok and e.size >= 1 and (va in kf or not not_compiled_reason(img, va, e.size)):
                extents[va] = e
            if progress and i % 2000 == 0:
                progress(f"{b}: sized {i:,}/{len(starts):,} candidate starts")
        # drop starts that sit inside another function unless they are called or in a vtable
        ordered = sorted(extents)
        keep = []
        cover_end = 0
        for va in ordered:
            if va < cover_end and va not in known:
                continue
            keep.append(va)
            cover_end = max(cover_end, va + extents[va].size)
        for va in keep:
            key = f"{b}:0x{va:08X}"
            if key in verified_keys:
                continue
            e = extents[va]
            old = old_by_key.get(key, {})
            if va in vt:
                cls, slot, raw = vt[va]
                sym = f"{cls}::vfunc_{slot:02d}"
                match = rtti_match_hint(raw, f"vfunc_{slot:02d}") + "|" + decorated_hint(cls, f"vfunc_{slot:02d}")
                hint = f"Virtual method of {cls} (vtable slot {slot}, offset +0x{slot * 4:02X})."
            elif va in kf and kf[va].get("symbol"):
                sym, match = kf[va]["symbol"], kf[va].get("match") or ""
                hint = f"Matched before the 2026-11-08 reset; {e.size} bytes."
            else:
                sym = old.get("symbol") if old.get("symbol") and not old.get("symbol", "").startswith("sub_") else f"sub_{va:08X}"
                match = "" if "::" in sym else sym
                hint = "Called directly" if va in calls else "Found by scanning for function starts"
                hint += f"; {e.size} bytes" + ("; contains a switch jump table" if e.has_jump_table else "") + "."
            t = {
                "id": LANES[b][0] + f"{va:08X}",
                "bin": b,
                "lane": LANES[b][1],
                "symbol": sym,
                "match_substr": match,
                "va": f"{LANES[b][2]}0x{va:08X}",
                "fva_int": va,
                "size": e.size,
                "flags": PC_FLAGS if b == "pc" else XB_FLAGS,
                "status": "UNCLAIMED",
                "claimed_by": "",
                "hint": hint,
                "code_check": CODE_CHECK,
            }
            if b == "proto" and va in vt and "xb" in classes and vt[va][0] not in classes["xb"]:
                # Its class has no virtual methods in the retail Xbox game: cut or renamed before release.
                t["lane"] += ", class not in retail"
                t["hint"] += " This class is not in the retail game (cut or renamed before release)."
            t.update(tier(e.size))
            tasks.append(t)
    p = binaries.get("ps2")
    if p and Path(p).exists():
        import ps2_binary
        images["ps2"] = ps2_binary.Ps2Image(p)
        xbox_tasks = list(tasks)
        cache: dict = {}
        tasks += ps2_tasks(images["ps2"], images.get("xb"), xbox_tasks, old_by_key, verified_keys,
                           [int(v, 16) for v in (extra_starts or {}).get("ps2", [])], progress, cache=cache)
        for o in ps2_overlay.OVERLAYS:
            op = binaries.get(o.bin)
            if not op or not Path(op).exists():
                continue
            images[o.bin] = ps2_binary.Ps2Image.with_overlay(images["ps2"], Path(op).read_bytes(), o.file)
            tasks += ps2_tasks(images[o.bin], images.get("xb"), xbox_tasks, old_by_key, verified_keys,
                               [int(v, 16) for v in (extra_starts or {}).get(o.bin, [])], progress, b=o.bin,
                               cache=cache)
    lookalikes.annotate(tasks, images, progress=progress)
    return tasks


def ps2_tasks(img, xbox_img, xbox_tasks: List[dict], old_by_key: Dict[str, dict], verified_keys: Set[str],
              extra_starts: List[int], progress=None, b: str = "ps2", cache: Optional[dict] = None) -> List[dict]:
    """The PS2 game's own functions (the GCC-built Sony libraries linked in are left out), or one overlay's
    (b: its lane, img: the program with that overlay loaded). Where a function is the same as one in the
    Xbox game (portal/tools/ps2_pairing.py), it gets that function's name and a pointer to it, so its C++
    can be the starting point."""
    import ps2_binary
    funcs = ps2_binary.find_functions(img, extra_starts)
    pairs = {}
    if xbox_img is not None:
        import ps2_pairing
        if progress:
            progress(f"{b}: pairing functions with the Xbox game")
        pairs = ps2_pairing.pair(img, funcs, xbox_img, xbox_tasks, progress, cache=cache)
    overlay = ps2_overlay.BY_BIN.get(b)
    xbox_symbol = {t["fva_int"]: t["symbol"] for t in xbox_tasks if t.get("bin") == "xb"}
    out = []
    for va in sorted(funcs):
        f = funcs[va]
        if f.library or f.size < 4:
            continue
        key = f"{b}:0x{va:08X}"
        if key in verified_keys:
            continue
        old = old_by_key.get(key, {})
        pr = pairs.get(va)
        sym = old.get("symbol") if old.get("symbol") and not old["symbol"].startswith("func_") else ""
        if not sym and pr and pr.name:
            sym = pr.name
        if not sym and pr and pr.xbox_va is not None:
            xs = xbox_symbol.get(pr.xbox_va, "")
            sym = xs if "::" in xs else ""
        sym = sym or ps2_binary.func_name(va)
        hint = f.how[0].upper() + f.how[1:] + f"; {f.size} bytes"
        if f.jump_table:
            hint += "; contains a switch jump table"
        hint += "."
        if overlay:
            hint += (f" It is in the {overlay.label} overlay ({overlay.file}), which the game loads at"
                     f" 0x{img._main.va:08X} when it needs it.")
        if pr:
            hint += f" Same function as {'Xbox 0x%08X' % pr.xbox_va if pr.xbox_va is not None else 'the one named here'}: {pr.why}."
        t = {
            "id": f"{b}_{va:08X}", "bin": b, "lane": LANES[b][1], "symbol": sym, "match_substr": "",
            "va": f"PS2 0x{va:08X}", "fva_int": va, "size": f.size, "flags": PS2_FLAGS, "status": "UNCLAIMED",
            "claimed_by": "", "hint": hint, "code_check": CODE_CHECK,
        }
        if pr and pr.xbox_va is not None:
            t["xbox_twin"] = f"0x{pr.xbox_va:08X}"
        t.update(tier(f.size))
        out.append(t)
    if progress:
        named = sum(1 for t in out if not t["symbol"].startswith("func_"))
        progress(f"{b}: {len(out):,} game functions ({named:,} named from the Xbox game)")
    return out


def main() -> int:
    """Rebuild reports/full_remaining_queue.json from the binaries in binaries/."""
    import argparse
    root = Path(__file__).resolve().parents[2]           # the project folder
    ap = argparse.ArgumentParser(description=main.__doc__)
    ap.add_argument("--out", default=str(root / "reports" / "full_remaining_queue.json"))
    args = ap.parse_args()
    out = Path(args.out)
    from game_files import refusal
    binaries = {}
    for b, name in (("pc", "Scarface.exe"), ("xb", "default.xbe"), ("proto", "game.xbe"), ("ps2", "SLUS_211.11")):
        p = root / "binaries" / name
        problem = refusal(p) if p.exists() else None
        if problem:
            print(f"[!] NOT USED: {problem}")
        elif p.exists():
            binaries[b] = p
    for o in ps2_overlay.OVERLAYS:
        p = ps2_overlay.path_for(root / "binaries", o.bin)
        problem = ps2_overlay.refusal(p, o.bin)
        if problem:
            print(f"[!] NOT USED: {problem}")
        elif p.exists() and "ps2" in binaries:
            binaries[o.bin] = p
    old = json.loads(out.read_text(encoding="utf-8")) if out.exists() else None
    reg_path = root / "reports" / "verified_registry.json"
    verified = set(json.loads(reg_path.read_text(encoding="utf-8")).get("entries", {})) if reg_path.exists() else set()
    tasks = build_queue(binaries, old, verified, progress=print, **seed_data(root))
    tmp = out.with_suffix(".tmp")
    tmp.write_text(json.dumps(tasks, indent=1), encoding="utf-8")
    tmp.replace(out)
    by = {}
    for t in tasks:
        by[t["bin"]] = by.get(t["bin"], 0) + 1
    print(f"{len(tasks):,} tasks ({', '.join(f'{k}: {v:,}' for k, v in sorted(by.items()))}) -> {out}")
    groups = sum(1 for t in tasks if t.get("lookalike_rep"))
    covered = sum(1 for t in tasks if t.get("lookalikes") and not t.get("lookalike_rep"))
    print(f"{groups:,} groups of look-alikes: matching one function of each also covers {covered:,} more")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
