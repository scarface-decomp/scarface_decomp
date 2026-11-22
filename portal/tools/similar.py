#!/usr/bin/env python3
"""
Which matched functions does an open function look most like? Their C++ is the best starting point for it.

    python portal/tools/similar.py rank                 every open function, best neighbour first -> work/nearest_open.json
    python portal/tools/similar.py rank --bin xb
    python portal/tools/similar.py show xb 0x0002AC90   the nearest matched functions to one function

The score is 1 minus the edit distance between the two functions' instruction sequences, divided by the
longer length (the measure coddog uses, github.com/ethteck/coddog). An instruction is its mnemonic and the
kind of each operand (register, memory, immediate), so register choice, offsets and addresses do not
count: two functions that differ only in those score 1.0. A memory operand also says what it is based
on: a fixed address (a global, an imported function), the stack (an argument or a local) or another
register (a member of `this` or of a pointer). Without that, `return m_Field18;` and `return a1->m_Field18;`
looked the same and the nearest function was often the wrong kind to start from. Candidates are first
picked by shared runs of three instructions, then scored exactly.

The index of matched functions is cached in work/similar_index.json (read from your copy of the game;
work/ is never committed) and rebuilt when the registry changes. `portal/agent.py packet` prints the three
nearest, and `portal/agent.py next --order similar` works through work/nearest_open.json.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import re
import sys
from collections import defaultdict
from pathlib import Path
from typing import Dict, Iterable, List, Optional, Sequence, Tuple

TOOLS = Path(__file__).resolve().parent
ROOT = TOOLS.parents[1]
sys.path.insert(0, str(TOOLS))

REGISTRY = ROOT / "reports" / "verified_registry.json"
QUEUE = ROOT / "reports" / "full_remaining_queue.json"
WORK = ROOT / "work"
CACHE = WORK / "similar_index.json"
RANKED = WORK / "nearest_open.json"
BINARIES = {"pc": ROOT / "binaries" / "Scarface.exe", "xb": ROOT / "binaries" / "default.xbe",
            "proto": ROOT / "binaries" / "game.xbe"}
INDEX_VERSION = 2         # 2: memory operands say what they are based on
NGRAM = 3
COMMON_GRAM = 3000        # a run of three instructions found in more matched functions than this says little
CANDIDATES = 40           # exact scoring for this many per query
MAX_TOKENS = 4000

_REG = re.compile(r"^(?:[re]?[abcd]x|[abcd][lh]|[re]?[sd]il?|[re]?[sb]pl?|r\d+[dwb]?|[cdefgs]s|st(?:\(\d\))?|"
                  r"[xy]mm\d+|mm\d+|cr\d|dr\d)$")
_ABS = re.compile(r"^(?:0x[0-9a-f]+|\d+)$")
_STACK = re.compile(r"^e[sb]p\b")


def _operand_kind(op: str) -> str:
    op = op.strip()
    if "[" in op:
        size = op.split("ptr")[0].strip() if "ptr" in op else ""
        kind = "m" + {"byte": "8", "word": "16", "dword": "32", "qword": "64", "xmmword": "128",
                      "tbyte": "80"}.get(size, "")
        inner = op[op.index("[") + 1:op.rindex("]")].strip()
        if _ABS.match(inner):
            return kind + "a"                     # a fixed address: a global or an import
        if _STACK.match(inner):
            return kind + "s"                     # an argument or a local
        return kind                               # based on another register: this, a pointer
    if _REG.match(op):
        if op.startswith(("xmm", "ymm")):
            return "x"
        if op.startswith("st"):
            return "f"
        return "r"
    return "i"


def tokens(code: bytes) -> List[str]:
    """The function's instructions as 'mnemonic kind,kind' (e.g. 'mov r,m32'), addresses left out."""
    import capstone
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    out = []
    for ins in md.disasm(bytes(code), 0):
        ops = [o for o in ins.op_str.split(",") if o.strip()] if ins.op_str else []
        out.append(ins.mnemonic + (" " + ",".join(_operand_kind(o) for o in ops) if ops else ""))
        if len(out) >= MAX_TOKENS:
            break
    return out


def distance(a: Sequence[int], b: Sequence[int], limit: Optional[int] = None) -> int:
    """Edit distance; stops early (returns limit + 1) once it cannot come in at or under `limit`."""
    try:
        from rapidfuzz.distance import Levenshtein
        return Levenshtein.distance(a, b, score_cutoff=limit) if limit is not None else Levenshtein.distance(a, b)
    except ImportError:
        pass
    if len(a) < len(b):
        a, b = b, a
    if limit is not None and len(a) - len(b) > limit:
        return limit + 1
    prev = list(range(len(b) + 1))
    for i, x in enumerate(a, 1):
        cur = [i] + [0] * len(b)
        best = i
        for j, y in enumerate(b, 1):
            v = min(prev[j] + 1, cur[j - 1] + 1, prev[j - 1] + (x != y))
            cur[j] = v
            if v < best:
                best = v
        if limit is not None and best > limit:
            return limit + 1
        prev = cur
    return prev[-1]


def similarity(a: Sequence[int], b: Sequence[int], floor: float = 0.0) -> float:
    n = max(len(a), len(b))
    if n == 0:
        return 1.0
    limit = int(n * (1.0 - floor))
    d = distance(a, b, limit)
    return 0.0 if d > limit else 1.0 - d / n


class Index:
    """Matched functions as token-id sequences, with an inverted index on runs of three instructions."""

    def __init__(self, vocab: Dict[str, int], items: List[dict]):
        self.vocab = vocab
        self.items = items                       # {"key", "symbol", "size", "seq": [ids]}
        self.by_key = {it["key"]: i for i, it in enumerate(items)}
        self.grams: Dict[tuple, List[int]] = defaultdict(list)
        for i, it in enumerate(items):
            for g in set(_grams(it["seq"])):
                self.grams[g].append(i)

    def encode(self, toks: Iterable[str], grow: bool = False) -> List[int]:
        out = []
        for t in toks:
            if t not in self.vocab:
                if not grow:
                    out.append(-1 - (hash(t) & 0xFFFF))      # unseen instruction: never equal to a known one
                    continue
                self.vocab[t] = len(self.vocab)
            out.append(self.vocab[t])
        return out

    def nearest(self, seq: List[int], k: int = 3, exclude: Iterable[str] = (), floor: float = 0.5) -> List[Tuple[float, dict]]:
        skip = {self.by_key[x] for x in exclude if x in self.by_key}
        counts: Dict[int, int] = defaultdict(int)
        mine = set(_grams(seq))
        for g in mine:
            post = self.grams.get(g)
            if post and len(post) <= COMMON_GRAM:
                for i in post:
                    counts[i] += 1
        n = len(seq)
        cands = [i for i in counts if i not in skip and _length_ok(n, len(self.items[i]["seq"]), floor)]
        if len(mine) < 2:                         # tiny function: compare with every one of similar length
            cands = [i for i, it in enumerate(self.items) if i not in skip and _length_ok(n, len(it["seq"]), floor)
                     and abs(len(it["seq"]) - n) <= 2]
        cands.sort(key=lambda i: -counts.get(i, 0) / max(1, len(mine) + len(self.items[i]["seq"])))
        scored = []
        seen_code = set()
        for i in cands[:CANDIDATES * 3]:
            it = self.items[i]
            if it["digest"] in seen_code:         # look-alike copies of one function: show it once
                continue
            s = similarity(seq, it["seq"], floor)
            if s >= floor:
                scored.append((s, it))
                seen_code.add(it["digest"])
            if len(scored) >= CANDIDATES:
                break
        scored.sort(key=lambda x: (-x[0], x[1]["ported"], x[1]["key"]))
        return scored[:k]


def _grams(seq: Sequence[int]) -> List[tuple]:
    return [tuple(seq[i:i + NGRAM]) for i in range(max(0, len(seq) - NGRAM + 1))]


def _length_ok(a: int, b: int, floor: float) -> bool:
    return min(a, b) >= floor * max(a, b) if max(a, b) else True


def _registry_stamp() -> str:
    h = hashlib.sha256()
    h.update(str(INDEX_VERSION).encode())
    h.update(REGISTRY.read_bytes() if REGISTRY.exists() else b"")
    return h.hexdigest()[:16]


def _images() -> dict:
    from sf_binaries import BinaryImage
    return {b: BinaryImage(p) for b, p in BINARIES.items() if p.exists()}


def load_index(quiet: bool = False) -> Index:
    stamp = _registry_stamp()
    if CACHE.exists():
        try:
            data = json.loads(CACHE.read_text(encoding="utf-8"))
            if data.get("stamp") == stamp:
                return Index(data["vocab"], data["items"])
        except (ValueError, KeyError):
            pass
    if not quiet:
        print("Indexing the matched functions (once per registry change)...", file=sys.stderr)
    entries = json.loads(REGISTRY.read_text(encoding="utf-8")).get("entries", {}) if REGISTRY.exists() else {}
    imgs = _images()
    vocab: Dict[str, int] = {}
    idx = Index(vocab, [])
    items = []
    for key, e in sorted(entries.items()):
        b = key.split(":")[0]
        if b not in imgs or e.get("excerpt"):
            continue
        va, size = int(key.split(":")[1], 16), int(e.get("size") or 0)
        code = imgs[b].read(va, size) if size else None
        if not code:
            continue
        seq = idx.encode(tokens(code), grow=True)
        items.append({"key": key, "symbol": e.get("symbol", ""), "size": size, "seq": seq,
                      "ported": 1 if e.get("ported_from") else 0,
                      "digest": hashlib.sha1(json.dumps(seq).encode() + (e.get("code") or "").encode()).hexdigest()[:12]})
    WORK.mkdir(exist_ok=True)
    CACHE.write_text(json.dumps({"stamp": stamp, "vocab": vocab, "items": items}), encoding="utf-8")
    return Index(vocab, items)


def nearest_for(b: str, va: int, size: int, k: int = 3, index: Optional[Index] = None, code: Optional[bytes] = None,
                floor: float = 0.5) -> List[Tuple[float, dict]]:
    index = index or load_index()
    if code is None:
        code = _images()[b].read(va, size)
    return index.nearest(index.encode(tokens(code or b"")), k=k, exclude=[f"{b}:0x{va:08X}"], floor=floor)


def cmd_show(args) -> int:
    va = int(args.va, 16)
    queue = json.loads(QUEUE.read_text(encoding="utf-8")) if QUEUE.exists() else []
    t = next((t for t in queue if t.get("bin") == args.bin and t.get("fva_int") == va), None)
    entries = json.loads(REGISTRY.read_text(encoding="utf-8")).get("entries", {})
    size = int((t or entries.get(f"{args.bin}:0x{va:08X}") or {}).get("size") or 0)
    if not size:
        sys.exit(f"{args.bin}:0x{va:08X}: size unknown (not in the queue or the registry).")
    for s, it in nearest_for(args.bin, va, size, k=args.k, floor=args.floor):
        print(f"{s:5.2f}  {it['key']}  {it['size']:>5} B  {it['symbol']}")
    return 0


def cmd_rank(args) -> int:
    index = load_index()
    entries = json.loads(REGISTRY.read_text(encoding="utf-8")).get("entries", {})
    queue = json.loads(QUEUE.read_text(encoding="utf-8")) if QUEUE.exists() else []
    imgs = _images()
    rows = [t for t in queue if t.get("bin") in imgs and "fva_int" in t
            and f"{t['bin']}:0x{t['fva_int']:08X}" not in entries
            and (not args.bin or t["bin"] == args.bin) and int(t.get("size") or 0) <= args.max_size]
    out = []
    for n, t in enumerate(rows, 1):
        b, va, size = t["bin"], t["fva_int"], int(t["size"])
        best = nearest_for(b, va, size, k=3, index=index, code=imgs[b].read(va, size), floor=args.floor)
        if best:
            out.append({"bin": b, "va": f"0x{va:08X}", "size": size, "symbol": t.get("symbol", ""),
                        "score": round(best[0][0], 4),
                        "nearest": [{"key": it["key"], "score": round(s, 4), "symbol": it["symbol"]} for s, it in best]})
        if n % 1000 == 0:
            print(f"  {n:,}/{len(rows):,}", file=sys.stderr)
    out.sort(key=lambda r: (-r["score"], r["size"], r["bin"], r["va"]))
    WORK.mkdir(exist_ok=True)
    RANKED.write_text(json.dumps(out, indent=0), encoding="utf-8")
    print(f"{len(out):,} of {len(rows):,} open functions have a matched neighbour scoring {args.floor} or more "
          f"-> {RANKED.relative_to(ROOT)}")
    for r in out[:args.show]:
        print(f"  {r['score']:5.2f}  {r['bin']:<5} {r['va']}  {r['size']:>5} B  <- {r['nearest'][0]['key']}")
    return 0


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    s = sub.add_parser("show")
    s.add_argument("bin", choices=sorted(BINARIES))
    s.add_argument("va")
    s.add_argument("-k", type=int, default=5)
    s.add_argument("--floor", type=float, default=0.5)
    s.set_defaults(fn=cmd_show)
    r = sub.add_parser("rank")
    r.add_argument("--bin", choices=sorted(BINARIES))
    r.add_argument("--max-size", type=int, default=2000)
    r.add_argument("--floor", type=float, default=0.6)
    r.add_argument("--show", type=int, default=15)
    r.set_defaults(fn=cmd_rank)
    args = ap.parse_args(argv)
    return args.fn(args)


if __name__ == "__main__":
    sys.exit(main())
