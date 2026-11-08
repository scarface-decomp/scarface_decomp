#!/usr/bin/env python3
"""
Look-alikes: functions whose machine code is the same once the addresses in it are set aside.

Many Scarface functions are copies of each other: the same template made for different classes
(om::MetaType<...>, ConcreteClassRep<...>), the same accessor on different globals, or the same
function in the PC and the Xbox build. Their bytes are identical except for the addresses they use.

So C++ that matches one of them usually matches the rest once the addresses (and, for class methods,
the class names) are swapped. The portal does that swap after every new match and verifies each
result with the real compiler; nothing is recorded unless it matches byte for byte like any other
submission.

  signature(code, va, image)  -> (shape, relocations)   same shape = same code apart from addresses
  name_pattern(task)          -> how the function is named, so only like-named functions are paired
  group_key(task, shape)      -> the look-alike group id stored in the queue
  annotate(tasks, images)     -> adds lookalike_group / lookalikes / lookalike_rep to queue tasks
  port_code(cpp, src, src_relocs, dst, dst_relocs) -> the C++ rewritten for dst, or None
"""

from __future__ import annotations

import hashlib
import re
from collections import defaultdict
from typing import Dict, List, Optional, Sequence, Tuple

import decompme as DME

_IDENT = re.compile(r"[A-Za-z_]\w*")
_TOKEN = re.compile(r"[A-Za-z_]\w*|\d\w*")
_HEX8 = re.compile(r"(?<![0-9A-Fa-f])([0-9A-Fa-f]{8})(?![0-9A-Fa-f])")


def signature(code: bytes, va: int, image) -> Tuple[str, List[DME.Reloc]]:
    """The function's bytes with every address field zeroed, plus where those fields are and what kind
    they are. Places inside the function (jump tables) keep their offset, so they must match too."""
    relocs = DME.find_relocations(code, va, image)
    masked = bytearray(code)
    parts = []
    for r in relocs:
        masked[r.offset:r.offset + 4] = b"\0\0\0\0"
        if r.symbol == DME.SECTION_SYMBOL:
            what = f"t{r.addend}"
        elif r.symbol == DME.SELF_SYMBOL:
            what = "s"
        else:
            what = "x"
        parts.append(f"{r.offset}:{r.kind}:{what}")
    shape = hashlib.sha1(bytes(masked) + b"|" + "|".join(parts).encode("ascii")).hexdigest()
    return shape, relocs


def _plain(task: dict) -> bool:
    ms = task.get("match_substr") or ""
    return ms.startswith("sub_") or (not ms and "::" not in task.get("symbol", ""))


def name_pattern(task: dict) -> str:
    """'plain' for sub_XXXXXXXX functions; otherwise the symbol with every name replaced by I, e.g.
    'I::I<I::I>::I'. Code is only carried between functions named the same way."""
    if _plain(task):
        return "plain"
    return _IDENT.sub("I", task.get("symbol", ""))


def group_key(task: dict, shape: str) -> str:
    return hashlib.sha1(f"{shape}|{name_pattern(task)}".encode("utf-8")).hexdigest()[:12]


def annotate(tasks: List[dict], images: Dict[str, object], progress=None) -> Dict[str, List[dict]]:
    """Add to every task:
         lookalike_group  the group id ("" when it has no look-alike)
         lookalikes       how many other functions in the queue share it
         lookalike_rep    True for one member per group (the one to show first)
    Returns {group id: [tasks]} for groups of two or more."""
    groups: Dict[str, List[dict]] = defaultdict(list)
    for i, t in enumerate(tasks):
        img = images.get(t.get("bin"))
        code = img.read(t["fva_int"], int(t["size"])) if img is not None else None
        if not code:
            continue
        shape, _ = signature(code, t["fva_int"], img)
        groups[group_key(t, shape)].append(t)
        if progress and i and i % 5000 == 0:
            progress(f"look-alikes: {i:,}/{len(tasks):,}")
    out = {}
    for t in tasks:
        t["lookalike_group"], t["lookalikes"], t["lookalike_rep"] = "", 0, False
    for g, members in groups.items():
        if len(members) < 2:
            continue
        out[g] = members
        # Retail Xbox first (all of its code is readable), then PC, then the prototype; lowest address.
        rep = min(members, key=lambda m: (m["bin"] != "xb", m["bin"] == "proto", m["fva_int"]))
        for m in members:
            m["lookalike_group"] = g
            m["lookalikes"] = len(members) - 1
            m["lookalike_rep"] = m is rep
    return out


def _address_of(symbol: str) -> Optional[int]:
    m = re.search(r"_([0-9A-Fa-f]{8})$", symbol)
    return int(m.group(1), 16) if m else None


def address_map(src: dict, src_relocs: Sequence[DME.Reloc], dst: dict,
                dst_relocs: Sequence[DME.Reloc]) -> Optional[Dict[int, int]]:
    """Which address in src's code becomes which in dst's. None if the two do not line up, or if one
    address in src would have to stand for two different addresses in dst."""
    if [(r.offset, r.kind) for r in src_relocs] != [(r.offset, r.kind) for r in dst_relocs]:
        return None
    amap = {src["fva_int"]: dst["fva_int"]}
    for a, b in zip(src_relocs, dst_relocs):
        inner = (DME.SECTION_SYMBOL, DME.SELF_SYMBOL)
        if a.symbol in inner or b.symbol in inner:
            if a.symbol != b.symbol or a.addend != b.addend:
                return None
            continue
        sa, sb = _address_of(a.symbol), _address_of(b.symbol)
        if sa is None or sb is None:
            return None
        if amap.get(sa, sb) != sb:
            return None
        amap[sa] = sb
    return amap


def name_map(src: dict, dst: dict) -> Optional[Dict[str, str]]:
    """Names to swap in the C++ so it defines dst's function: for class methods, the class, namespace
    and method names that differ between the two symbols (om::MetaType<audio::Mix>::vfunc_02 ->
    om::MetaType<audio::SeqEvent>::vfunc_02 swaps Mix for SeqEvent)."""
    if name_pattern(src) != name_pattern(dst):
        return None
    if name_pattern(src) == "plain":
        return {}
    a, b = _IDENT.findall(src["symbol"]), _IDENT.findall(dst["symbol"])
    if len(a) != len(b):
        return None
    out: Dict[str, str] = {}
    for x, y in zip(a, b):
        if x == y:
            continue
        if out.get(x, y) != y:
            return None
        out[x] = y
    return out


def _swap_hex(token: str, amap: Dict[int, int]) -> str:
    def one(m: re.Match) -> str:
        v = int(m.group(1), 16)
        if v not in amap:
            return m.group(1)
        s = f"{amap[v]:08X}"
        return s.lower() if m.group(1).islower() else s
    return _HEX8.sub(one, token)


def rewrite(cpp: str, amap: Dict[int, int], names: Dict[str, str]) -> str:
    """One pass over the code, so a swap is never swapped again."""
    def tok(m: re.Match) -> str:
        t = m.group(0)
        if t in names:
            return names[t]
        return _swap_hex(t, amap)
    return _TOKEN.sub(tok, cpp)


def port_code(cpp: str, src: dict, src_relocs: Sequence[DME.Reloc], dst: dict,
              dst_relocs: Sequence[DME.Reloc]) -> Optional[str]:
    """src's matched C++ rewritten for dst, or None when the two cannot be paired this way.
    The result still has to be compiled and verified; this only does the renaming."""
    amap = address_map(src, src_relocs, dst, dst_relocs)
    names = name_map(src, dst)
    if amap is None or names is None:
        return None
    lines = cpp.splitlines(keepends=True)
    while lines and lines[0].startswith(PORT_HEADER):      # a port of a port: one header is enough
        lines = lines[2:] if len(lines) > 1 and lines[1].startswith("// its addresses") else lines[1:]
    head = (f"{PORT_HEADER}{src['symbol']} ({src['va']}), which was matched first;\n"
            f"// its addresses and names were swapped for this function's.\n")
    return head + rewrite("".join(lines), amap, names)


PORT_HEADER = "// Same machine code as "


def members(groups: Dict[str, List[dict]], task: dict) -> List[dict]:
    g = task.get("lookalike_group")
    return [m for m in groups.get(g, []) if m is not task] if g else []
