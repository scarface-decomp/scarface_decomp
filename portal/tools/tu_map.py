#!/usr/bin/env python3
"""Raw material for a map of the Xbox game's translation units (its .cpp files): its static initializers
in link order (the examiner's round Q21-Q26).

The C++ start-up table (__xc) lists one initializer per global object, grouped by object file in link
order, and the objects each one sets up sit in .data/.bss in the same order. So: walk the initializers in
table order, take the first .bss address each one touches (its anchor), and cut the list wherever every
anchor after the cut is above every anchor before it. In this game that cut gives no useful pieces (a few
out-of-order anchors glue most of the table together, and without them the anchors only ascend), so the
tool writes the table itself: per initializer its anchor, whether it is out of order, and the game
functions it refers to (script handlers, constructors), for a boundary rule still to be found.

Limits: an object file with no static initializers is not seen (it sits between its neighbours); inline
and template functions are placed where first used and don't follow the order; a piece can be several
object files whose globals happen not to interleave.

    python portal/tools/tu_map.py            -> reports/tu_static_init_xb.json
"""
from __future__ import annotations

import json
import re
import sys
from collections import Counter
from pathlib import Path
from typing import List, Optional, Tuple

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))

import hidden_starts as H  # noqa: E402
from sf_binaries import BinaryImage  # noqa: E402

ROOT = HERE.parent.parent
GAME_END = 0x002331C0           # below this the game's own code; above it the libraries (frame-pointer map, Q10)


def anchors(md, img, s: int, bss: Tuple[int, int]) -> Tuple[Optional[int], List[int]]:
    """(first .bss address the initializer at s touches, game functions it refers to)."""
    first, refs = None, []
    for i in md.disasm(img.read(s, 0x400) or b"", s):
        ops = [o.strip() for o in i.op_str.split(",")] if i.op_str else []
        # the object being set up: a .bss address written to, or loaded into ecx (this for its constructor)
        target = None
        if i.mnemonic == "mov" and len(ops) == 2:
            m = re.fullmatch(r"(?:dword|word|byte) ptr \[0x([0-9a-f]+)(?: \+ \w+)?\]", ops[0])
            if m:
                target = int(m.group(1), 16)
            elif ops[0] == "ecx" and re.fullmatch(r"0x[0-9a-f]+", ops[1]):
                target = int(ops[1], 16)
        if target is not None and bss[0] <= target < bss[1] and first is None:
            first = target
        for h in re.findall(r"0x[0-9a-f]{5,8}", i.op_str):
            v = int(h, 16)
            sec = img.section_of(v)
            if not sec:
                continue
            if sec.is_code and not sec.library and v < GAME_END and i.mnemonic in ("push", "call", "mov"):
                refs.append(v)
        if i.mnemonic in ("ret", "int3"):
            break
    return first, refs


def pieces(rows: List[Tuple[int, Optional[int], List[int]]]) -> List[List[int]]:
    """Cut the initializers (in table order) wherever every later anchor is above every earlier one."""
    idx = [k for k, r in enumerate(rows) if r[1] is not None]
    pre, best = [], -1
    for k in idx:
        best = max(best, rows[k][1])
        pre.append(best)
    suf, low = [0] * len(idx), 1 << 32
    for j in range(len(idx) - 1, -1, -1):
        low = min(low, rows[idx[j]][1])
        suf[j] = low
    cuts = {idx[j + 1] for j in range(len(idx) - 1) if pre[j] < suf[j + 1]}
    out, cur = [], []
    for k in range(len(rows)):
        if k in cuts and cur:
            out.append(cur)
            cur = []
        cur.append(k)
    if cur:
        out.append(cur)
    return out


def lis_mask(vals: List[int]) -> List[bool]:
    """Which values lie on one longest strictly increasing subsequence."""
    import bisect
    tails, tails_i, prev = [], [], [-1] * len(vals)
    for i, v in enumerate(vals):
        j = bisect.bisect_left(tails, v)
        if j == len(tails):
            tails.append(v); tails_i.append(i)
        else:
            tails[j] = v; tails_i[j] = i
        prev[i] = tails_i[j - 1] if j else -1
    keep = [False] * len(vals)
    k = tails_i[-1] if tails_i else -1
    while k >= 0:
        keep[k] = True
        k = prev[k]
    return keep


def build(img: BinaryImage) -> dict:
    from capstone import CS_ARCH_X86, CS_MODE_32, Cs
    md = Cs(CS_ARCH_X86, CS_MODE_32)
    im = H.Img(img)
    (a, b), = [t for t in H.initializer_tables(im) if (t[1] - t[0]) > 0x100][:1]
    data = img.section_of(a)
    bss = (data.va + data.raw_size, data.va + data.vsize)
    stubs = [w for w in (im.u32(a + 4 * i) for i in range((b - a) // 4)) if w not in (0, 0xFFFFFFFF) and im.code(w)]
    rows = [(s,) + anchors(md, img, s, bss) for s in stubs]
    groups = pieces(rows)
    anchored = [r[1] for r in rows if r[1] is not None]
    on_lis = lis_mask(anchored)
    seen = Counter(f for r in rows for f in set(r[2]))
    table, k = [], 0
    for s, anchor, refs in rows:
        row = {"at": f"0x{s:08X}"}
        if anchor is not None:
            row["bss"] = f"0x{anchor:08X}"
            if not on_lis[k]:
                row["out_of_order"] = True
            k += 1
        own = sorted({r for r in refs if seen[r] <= 3})
        if own:
            row["code"] = [f"0x{r:08X}" for r in own]
        table.append(row)
    return {"what": "The Xbox game's static initializers in start-up-table order (= link order of the object "
                    "files), each with the first .bss address it sets up and the game functions it refers to "
                    "(portal/tools/tu_map.py). Raw material for an object-file map: the .bss anchors ascend "
                    "along the table but give no boundaries by themselves.",
            "initializers": len(stubs), "with_bss_anchor": len(anchored),
            "anchors_on_longest_ascending_run": sum(on_lis),
            "strict_cut_pieces": len(groups), "largest_strict_cut_piece": max(len(g) for g in groups),
            "map": table}


def main(argv=None) -> int:
    import argparse
    ap = argparse.ArgumentParser(description="Coarse object-file map from the static initializers.")
    ap.add_argument("--out", type=Path, default=ROOT / "reports" / "tu_static_init_xb.json")
    a = ap.parse_args(argv)
    sys.path.insert(0, str(ROOT / "portal"))
    import agent
    t = build(agent.image("xb"))
    a.out.write_text(json.dumps({k: v for k, v in t.items() if k != "map"}, indent=1)[:-2] + ',\n "map": [\n'
                     + ",\n".join("  " + json.dumps(p) for p in t["map"]) + "\n ]\n}\n", encoding="utf-8")
    print(f"{t['initializers']:,} initializers, {t['with_bss_anchor']:,} with a .bss anchor, "
          f"{t['anchors_on_longest_ascending_run']:,} of them in one ascending run -> {a.out}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
