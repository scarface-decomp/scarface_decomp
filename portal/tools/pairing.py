#!/usr/bin/env python3
"""
Which function in one build of the game is which in another (the examiner's question E1).

The retail Xbox (default.xbe), the April 2006 Xbox prototype (game.xbe) and the PC (Scarface.exe) were
built from mostly the same source. A function matched in one build tells you the types, the names and
often the very C++ of its twin in the others. This pairs them from the code alone:

1. **Shape.** Each function's instructions with their addresses set aside: the mnemonics, registers and
   small numbers kept; addresses, call targets and jump targets turned into placeholders. A shape found
   exactly once in each build pairs those two functions.
2. **Text.** The strings a function uses (the text itself, not where it sits). A set of strings found
   in one function only, in each build, pairs them, even when the code around them changed.
3. **Calls.** For each pair, the functions they call, in order: where both call lists have the same
   length, the n-th callee on each side pairs with the other when their loose shapes (mnemonics only)
   agree. Repeated until nothing new pairs.
4. **Order.** The linker kept each source file's functions in order: between two pairs that are in the
   same order in both builds, the same number of unpaired functions on each side, alike one by one
   (loose shape), pair in turn. Then calls again.
5. **Loose shape.** Mnemonics only (the register choices of /G6 against /G7 set aside), found once in each.

    python portal/tools/pairing.py xb proto          write reports/pairing_xb_proto.json
    python portal/tools/pairing.py xb pc             (the PC's code is packed on disk: only its readable
                                                      part, about a tenth, can pair)

Only addresses, sizes and how each pair was found go into the report: no game bytes.
"""

from __future__ import annotations

import argparse
import hashlib
import json
import re
import sys
from collections import Counter, defaultdict
from dataclasses import dataclass, field
from pathlib import Path
from typing import Dict, Iterable, List, Optional, Sequence, Set, Tuple

sys.path.insert(0, str(Path(__file__).resolve().parent))
from sf_binaries import BinaryImage, _cs, collect_call_targets, function_extent  # noqa: E402

ROOT = Path(__file__).resolve().parents[2]
FILES = {"xb": "default.xbe", "proto": "game.xbe", "pc": "Scarface.exe"}
LISTS = {"xb": "Original_Binary_Order_Xbox.cpp", "proto": "Original_Binary_Order_Proto.cpp",
         "pc": "Original_Binary_Order_PC_1002.cpp"}             # the project's own lists of every function
LISTED = re.compile(r"^// \[(\w+)\] (?:0x([0-9A-Fa-f]{8}) \S+ \((\d+) B\)|\S+ \(0x([0-9A-Fa-f]{8}), (\d+) B\))", re.M)
SMALL = 0x10000                      # numbers below this are kept in a shape; larger ones may be addresses
SHORTEST = 6                         # functions this small (bytes) pair only by their calls
LONGEST = 0x4000
TEXT_LEAST = 4                       # letters a string needs to count


@dataclass
class Function:
    va: int
    size: int
    shape: str = ""                  # exact shape (hash)
    loose: str = ""                  # mnemonics only (hash)
    calls: List[int] = field(default_factory=list)
    texts: Tuple[str, ...] = ()


def _text_at(img: BinaryImage, va: int) -> Optional[str]:
    """A plain string at va (at least TEXT_LEAST printable characters ending in a zero), or None."""
    off = img.va_to_off(va)
    sec = img.section_of(va)
    if off is None or sec is None or sec.is_code:
        return None
    end = img.data.find(b"\0", off, off + 256)
    if end - off < TEXT_LEAST:
        return None
    raw = img.data[off:end]
    if not all(32 <= c < 127 or c in (9, 10, 13) for c in raw):
        return None
    return raw.decode("ascii")


def describe(img: BinaryImage, va: int, size: int) -> Optional[Function]:
    """A function's shapes, calls and strings, or None when its code doesn't disassemble (packed)."""
    from capstone import x86_const as X
    blob = img.read(va, size)
    if not blob:
        return None
    md = _cs()
    md.detail = True
    exact, loose, calls, texts = [], [], [], []
    n = 0
    for ins in md.disasm(blob, va):
        n += ins.size
        ops = []
        for op in ins.operands:
            if op.type == X.X86_OP_REG:
                ops.append(ins.reg_name(op.reg))
            elif op.type == X.X86_OP_IMM:
                v = op.imm & 0xFFFFFFFF
                if ins.group(X.X86_GRP_JUMP) or ins.group(X.X86_GRP_CALL):
                    ops.append("T")
                    if ins.mnemonic == "call":
                        calls.append(v)
                elif v < SMALL or v > 0xFFFF0000:
                    ops.append(str(op.imm))
                else:
                    ops.append("A")
                    t = _text_at(img, v)
                    if t is not None:
                        texts.append(t)
            elif op.type == X.X86_OP_MEM:
                m = op.mem
                disp = m.disp & 0xFFFFFFFF
                d = str(m.disp) if (disp < SMALL or disp > 0xFFFF0000) else "A"
                if d == "A":
                    t = _text_at(img, disp)
                    if t is not None:
                        texts.append(t)
                ops.append("[%s+%s*%d+%s]" % (ins.reg_name(m.base) if m.base else "", ins.reg_name(m.index) if m.index else "",
                                              m.scale, d))
        exact.append(ins.mnemonic + " " + ",".join(ops))
        loose.append(ins.mnemonic)
    if n < size * 0.9 or not exact:
        return None
    h = lambda parts: hashlib.sha1("\n".join(parts).encode()).hexdigest()[:20]
    return Function(va, size, h(exact), h(loose), calls, tuple(sorted(set(texts))))


def listed(path: Path) -> Dict[int, Tuple[int, bool]]:
    """{address: (size, verified)} from a reconstructed_src/Original_Binary_Order_*.cpp list."""
    out: Dict[int, Tuple[int, bool]] = {}
    try:
        text = path.read_text(encoding="utf-8", errors="replace")
    except OSError:
        return out
    for m in LISTED.finditer(text):
        va = int(m.group(2) or m.group(4), 16)
        out[va] = (int(m.group(3) or m.group(5)), m.group(1) == "VERIFIED")
    return out


def functions(img: BinaryImage, known_list: Optional[Dict[int, Tuple[int, bool]]] = None) -> Dict[int, Function]:
    """Every function of the program's own code (.text), described: those of the project's list when there
    is one, else those its calls reach."""
    out: Dict[int, Function] = {}
    if known_list:
        for va, (size, _done) in sorted(known_list.items()):
            sec = img.section_of(va)
            if sec is not None and sec.name == ".text" and 0 < size <= LONGEST:
                f = describe(img, va, size)
                if f is not None:
                    out[va] = f
        return out
    starts = sorted(collect_call_targets(img))
    known = set(starts)
    for va in starts:
        sec = img.section_of(va)
        if sec is None or sec.name != ".text":
            continue
        ext = function_extent(img, va, known_starts=known, max_size=LONGEST)
        if not ext.ok or ext.size < 1:
            continue
        f = describe(img, va, ext.size)
        if f is not None:
            out[va] = f
    return out


def _unique(funcs: Dict[int, Function], key) -> Dict[object, int]:
    count = Counter(key(f) for f in funcs.values())
    return {key(f): va for va, f in funcs.items() if key(f) and count[key(f)] == 1}


def _after(seq: List[int], v: int) -> int:
    import bisect
    return bisect.bisect_right(seq, v)


def pair(a: Dict[int, Function], b: Dict[int, Function]) -> Dict[int, Tuple[int, str]]:
    """{a's address: (b's address, how)}: shape, text, calls, order and loose shape, in that order of trust."""
    pairs: Dict[int, Tuple[int, str]] = {}
    taken: Set[int] = set()

    def add(x: int, y: int, how: str) -> bool:
        if x in pairs or y in taken:
            return False
        pairs[x] = (y, how)
        taken.add(y)
        return True

    big = lambda f: f.shape if f.size >= SHORTEST else ""
    ua, ub = _unique(a, big), _unique(b, big)
    for k, x in ua.items():
        if k in ub:
            add(x, ub[k], "shape")
    ta, tb = _unique(a, lambda f: f.texts), _unique(b, lambda f: f.texts)
    for k, x in ta.items():
        if k in tb:
            add(x, tb[k], "text")
    def by_calls(todo):
        # the n-th callee of a pair is the n-th callee of its twin
        while todo:
            nxt = []
            for x, (y, _how) in todo:
                ca, cb = a[x].calls if x in a else [], b[y].calls if y in b else []
                if len(ca) != len(cb):
                    continue
                for p, q in zip(ca, cb):
                    if p in a and q in b and a[p].loose == b[q].loose and add(p, q, "calls"):
                        nxt.append((p, (q, "calls")))
            todo = nxt

    def by_order() -> list:
        # the linker kept each file's functions in order: between two pairs in the same order, as many
        # unpaired functions on each side, alike one by one, pair in turn
        made = []
        xs, ys = sorted(a), sorted(b)
        anchors = sorted(pairs.items())
        for (x1, (y1, _h1)), (x2, (y2, _h2)) in zip(anchors, anchors[1:]):
            if not y1 < y2:
                continue
            ga = [v for v in xs[_after(xs, x1):_after(xs, x2 - 1)] if v not in pairs and x1 < v < x2]
            gb = [v for v in ys[_after(ys, y1):_after(ys, y2 - 1)] if v not in taken and y1 < v < y2]
            if ga and len(ga) == len(gb) and all(a[p].loose == b[q].loose for p, q in zip(ga, gb)):
                for p, q in zip(ga, gb):
                    if add(p, q, "order"):
                        made.append((p, (q, "order")))
        return made

    by_calls(list(pairs.items()))
    for _round in range(4):
        made = by_order()
        if not made:
            break
        by_calls(made)
    rest_a = {va: f for va, f in a.items() if va not in pairs}
    rest_b = {va: f for va, f in b.items() if va not in taken}
    la = _unique(rest_a, lambda f: f.loose if f.size >= 16 else "")
    lb = _unique(rest_b, lambda f: f.loose if f.size >= 16 else "")
    for k, x in la.items():
        if k in lb:
            add(x, lb[k], "loose shape")
    return pairs


def report(bin_dir: Path, first: str, second: str, lists: Optional[Path] = None) -> dict:
    lists = lists or ROOT / "reconstructed_src"
    la, lb = listed(lists / LISTS[first]), listed(lists / LISTS[second])
    a_img, b_img = BinaryImage(bin_dir / FILES[first]), BinaryImage(bin_dir / FILES[second])
    a, b = functions(a_img, la), functions(b_img, lb)
    got = pair(a, b)
    hows = Counter(how for _y, how in got.values())
    done = lambda lst, va: bool(lst.get(va, (0, False))[1])
    ports = [(x, y) for x, (y, _how) in got.items() if done(la, x) != done(lb, y)]
    return {"what": f"functions of {FILES[first]} paired with their twins in {FILES[second]} "
                    "(portal/tools/pairing.py; the examiner's question E1)",
            "first": first, "second": second,
            "functions": {first: len(a), second: len(b)}, "paired": len(got), "by": dict(hows),
            "one_side_matched": len(ports),
            "columns": [first, second, "size", "how", "matched in"],
            "pairs": [[f"0x{x:08X}", f"0x{y:08X}", a[x].size, how,
                       "+".join(s for s, lst, va in ((first, la, x), (second, lb, y)) if done(lst, va))]
                      for x, (y, how) in sorted(got.items())]}


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    ap.add_argument("first", choices=sorted(FILES))
    ap.add_argument("second", choices=sorted(FILES))
    ap.add_argument("--bin-dir", type=Path, default=ROOT / "binaries")
    ap.add_argument("--out", type=Path)
    a = ap.parse_args(argv)
    for b in (a.first, a.second):
        if not (a.bin_dir / FILES[b]).exists():
            print(f"{FILES[b]} isn't in {a.bin_dir}.")
            return 1
    got = report(a.bin_dir, a.first, a.second)
    out = a.out or ROOT / "reports" / f"pairing_{a.first}_{a.second}.json"
    body = ",\n".join(json.dumps(row) for row in got["pairs"])
    head = json.dumps({k: v for k, v in got.items() if k != "pairs"}, indent=1)[:-2]
    out.write_text(head + ',\n "pairs": [\n' + body + "\n]}\n", encoding="utf-8")
    print(f"{got['functions'][a.first]:,} and {got['functions'][a.second]:,} functions; {got['paired']:,} paired "
          f"({', '.join(f'{v:,} by {k}' for k, v in got['by'].items())}); {got['one_side_matched']:,} pairs have "
          f"one side matched and the other not. Written {out.name}.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
