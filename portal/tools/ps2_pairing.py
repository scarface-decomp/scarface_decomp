#!/usr/bin/env python3
"""
Pair PS2 functions with the same function in the Xbox game, so a PS2 function gets a name and, once the
Xbox one is matched, its C++ as a place to start.

The PS2 program has no names, but it was built from the same C++ as the Xbox game. Two kinds of
evidence tie functions together, and only firm ones are used:

* text: a function that uses exactly the same set of strings as one Xbox function, where no other
  function on either side uses that set ("english" and "localised\\%s\\%s", say), is that function;
* virtual tables: once two functions in a PS2 virtual table are paired with functions at the same
  places in one Xbox class's table (whose class name the Xbox game's RTTI gives), the rest of that
  table lines up too, and its functions get the class's method names (Class::vfunc_03). Newly
  paired functions can line up further tables, so this is repeated until nothing changes.

The result is a hint for people, never a match: every PS2 function is still verified on its own.

    pair(ps2_img, ps2_funcs, xbox_img, xbox_tasks) -> {ps2 va: Pair}
"""

from __future__ import annotations

import re
import struct
from collections import Counter, defaultdict
from dataclasses import dataclass
from typing import Dict, FrozenSet, Iterable, List, Optional

import ps2_binary as P

_XNAME = re.compile(r"^_?(?:DAT|sub)_([0-9A-F]{8})$")
_PRINTABLE = set(range(32, 127)) | {9, 10, 13}


@dataclass
class Pair:
    xbox_va: Optional[int]           # the same function in default.xbe, when known
    name: str = ""                   # Class::vfunc_NN from the Xbox class, or Class::Method from the code
    why: str = ""


def _text_at(img_read, addr: int, min_len: int = 4) -> Optional[str]:
    b = img_read(addr, 200)
    if not b:
        return None
    end = b.find(b"\0")
    if end < min_len or not all(c in _PRINTABLE for c in b[:end]):
        return None
    return b[:end].decode("ascii")


def xbox_strings(xbox_img, task: dict) -> FrozenSet[str]:
    import decompme as DME
    code = xbox_img.read(task["fva_int"], int(task["size"]))
    if not code:
        return frozenset()
    try:
        relocs = DME.find_relocations(code, task["fva_int"], xbox_img)
    except Exception:            # Capstone missing or odd code: no strings, no pair
        return frozenset()
    out = set()
    for r in relocs:
        m = _XNAME.match(r.symbol)
        if m:
            s = _text_at(xbox_img.read, int(m.group(1), 16))
            if s:
                out.add(s)
    return frozenset(out)


def _unique(sets: Dict[int, FrozenSet[str]]) -> Dict[FrozenSet[str], int]:
    count = Counter(sets.values())
    return {s: va for va, s in sets.items() if count[s] == 1}


def _vtable_runs(img: P.Ps2Image, funcs: Dict[int, P.Func]) -> List[List[int]]:
    """Runs of two or more function addresses in a row in the data: virtual tables (and other tables). For a
    code overlay that includes the program's data, where the overlays' virtual tables are."""
    runs = []
    for s in getattr(img, "_scan", [img._main]):
        if not s.filesz:
            continue
        lo = s.off + (img.code_end - s.va) if s is img._main else s.off
        n = (s.off + s.filesz - lo) // 4
        words = struct.unpack_from(f"<{n}I", img.data, lo) if n > 0 else ()
        cur: List[int] = []
        for x in words:
            if x in funcs:
                cur.append(x)
            else:
                if len(cur) >= 2:
                    runs.append(cur)
                cur = []
        if len(cur) >= 2:
            runs.append(cur)
    return runs


def pair(ps2_img: P.Ps2Image, ps2_funcs: Dict[int, P.Func], xbox_img, xbox_tasks: Iterable[dict],
         progress=None, cache: Optional[dict] = None) -> Dict[int, Pair]:
    """cache: a dict to keep what was read from the Xbox game in, so pairing the PS2 program and then each
    of its overlays reads the Xbox game once."""
    from queue_builder import vtable_methods
    cache = {} if cache is None else cache
    if "xsets" not in cache:
        xtasks = [t for t in xbox_tasks if t.get("bin") == "xb"]
        xsets = {}
        for i, t in enumerate(xtasks):
            s = xbox_strings(xbox_img, t)
            if s:
                xsets[t["fva_int"]] = s
            if progress and i and i % 5000 == 0:
                progress(f"ps2 pairing: read the text of {i:,}/{len(xtasks):,} Xbox functions")
        cache["xsets"] = xsets
    xsets = cache["xsets"]
    psets = {}
    for va, f in ps2_funcs.items():
        if not f.library:
            s = frozenset(P.strings_used(ps2_img, va, f.size))
            if s:
                psets[va] = s
    xu, pu = _unique(xsets), _unique(psets)
    out: Dict[int, Pair] = {}
    for s, pva in pu.items():
        if s in xu:
            shown = ", ".join(f'"{x[:30]}"' for x in sorted(s)[:2])
            out[pva] = Pair(xu[s], "", f"it uses the same text as Xbox 0x{xu[s]:08X} ({shown})")
    # Class::Method strings a function prints about itself
    for va, s in psets.items():
        own = [x for x in s if re.fullmatch(r"[A-Za-z_]\w*::~?[A-Za-z_]\w*", x)]
        if len(own) == 1:
            p = out.setdefault(va, Pair(None))
            p.name = own[0]
            p.why = (p.why + "; " if p.why else "") + f'it names itself in a message ("{own[0]}")'
    # virtual tables
    if "vt" not in cache:
        cache["vt"] = vtable_methods(xbox_img)
    vt = cache["vt"]                                    # Xbox function -> (class, slot, raw RTTI name)
    by_class: Dict[str, Dict[int, int]] = defaultdict(dict)
    for fva, (cls, slot, _raw) in vt.items():
        by_class[cls].setdefault(slot, fva)
    runs = _vtable_runs(ps2_img, ps2_funcs)
    for _round in range(6):
        changed = False
        for run in runs:
            votes = Counter()
            for k, pva in enumerate(run):
                p = out.get(pva)
                if p and p.xbox_va in vt:
                    cls, slot, _ = vt[p.xbox_va]
                    votes[(cls, slot - k)] += 1
            if not votes:
                continue
            (cls, shift), n = votes.most_common(1)[0]
            if n < 2 or len(votes) > 1 and votes.most_common(2)[1][1] == n:
                continue                                  # one anchor, or two tables equally likely
            for k, pva in enumerate(run):
                slot = k + shift
                xva = by_class[cls].get(slot)
                if xva is None or ps2_funcs[pva].library:
                    continue
                p = out.get(pva)
                name = f"{cls}::vfunc_{slot:02d}"
                if p is None:
                    out[pva] = Pair(xva, name, f"its place in a virtual table lines up with {cls}'s on Xbox")
                    changed = True
                elif not p.name and p.xbox_va in (None, xva):
                    p.xbox_va, p.name = xva, name
                    p.why = (p.why + "; " if p.why else "") + f"its place in a virtual table lines up with {cls}'s on Xbox"
                    changed = True
        if not changed:
            break
    return out
