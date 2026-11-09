"""Scarface's script identifiers are hashed: every name (variables, functions, fields, classes) is stored
as "stx" + 8 letters a-p, the 32-bit key of the name, lowest 4 bits first. The key is Radical's string
hash, case-insensitive (default.xbe 0x00243FA0, decoded by 0x00076760):

    h = 0
    for each byte c:  h = (h * 65599) & 0x7FFFFFFF;  if c < 'a': c += 0x20;  h ^= signed(c)
    key = h | 0x80000000

So a name can be checked against its hash, and names can be recovered by trying candidate words.
The April 2006 prototype writes the same key in decimal: "ste" + str(key)."""
from __future__ import annotations

import re
from collections import Counter
from typing import Dict, Iterable

STX = re.compile(r"stx[a-p]{8}$")
STE = re.compile(r"ste\d{1,10}$")


def is_hashed(name: str) -> bool:
    return bool(STX.match(name) or (STE.match(name) and int(name[3:]) < 1 << 32))


def name_key(name: str) -> int:
    """The engine's key for a name (a stx/ste name stands for its own key)."""
    if STX.match(name):
        return sum((ord(ch) - 97) << (4 * i) for i, ch in enumerate(name[3:]))
    if STE.match(name) and int(name[3:]) < 1 << 32:
        return int(name[3:])
    h = 0
    for c in name.encode("latin-1"):
        h = (h * 0x1003F) & 0x7FFFFFFF
        if c < 0x61:
            c += 0x20
        if c >= 0x80:
            c -= 0x100
        h = (h ^ c) & 0xFFFFFFFF
    return h | 0x80000000


def stx(key: int) -> str:
    return "stx" + "".join(chr(97 + ((key >> (4 * i)) & 15)) for i in range(8))


def compiled_name(name: str, style: str = "stx") -> str:
    """How the game's compiler writes a name: "stx" (retail) or "ste" (April 2006 prototype)."""
    key = name_key(name)
    return stx(key) if style == "stx" else f"ste{key}"


def style_of(names) -> str:
    """Which way a script writes its names."""
    for n in names:
        if STE.match(n):
            return "ste"
        if STX.match(n):
            return "stx"
    return "stx"


PARENT_KEY = name_key("Parent")


# ---------------------------------------------------------------------------- name recovery
# A hash can't be reversed, but a candidate word can be checked: hash it, and if the key is one the scripts
# use, that is (almost certainly) the name. Candidates come from the user's own game files: the words in
# the executables (the engine registers its script functions, classes and fields by name) and the strings
# and plain .cs files among the scripts. Variables are hashed with their % or $. With about 13,000 hashed
# names and 300,000 candidate words, a wrong word matching by chance is expected once or twice in the game.

WORD = re.compile(rb"[A-Za-z_][A-Za-z0-9_]*(?:::[A-Za-z_][A-Za-z0-9_]*)*")
RUN = re.compile(rb"[\x20-\x7e]{2,}")


def casing_score(w: str) -> int:
    core = w.lstrip("$%")
    if w.startswith("%") and core[:1].islower() and casing_score(w[1:]) == 3:
        return 4                      # local variables: %count, %i, %playerObj
    if re.fullmatch(r"[a-z][a-z0-9]*(_[a-z0-9]+)*", core) or re.fullmatch(r"[a-z]+([A-Z][a-z0-9]*)+", core) \
            or re.fullmatch(r"([A-Z][a-z0-9]+)+[A-Z]?", core) or re.fullmatch(r"([A-Z][a-z0-9]*_?)+", core):
        return 3
    if re.fullmatch(r"[A-Z][A-Z0-9_]*", core) or "::" in core:
        return 2
    return 1


def candidates(binaries: Iterable[bytes], texts: Iterable[str]) -> Counter:
    """Words to try, with a weight: script strings count more than executable strings (they are the
    scripters' own spelling)."""
    c: Counter = Counter()
    for data in binaries:
        for run in RUN.findall(data):
            for t in WORD.findall(run):
                if len(t) <= 64:
                    c[t.decode()] += 1
    for s in texts:
        for t in WORD.findall(s.encode("latin-1", "replace")):
            if len(t) <= 64:
                c[t.decode()] += 5
    return c


def recover(wanted: Iterable[int], cands: Counter) -> Dict[int, str]:
    """{key: name} for the keys some candidate hashes to; the best-looking spelling wins."""
    wanted = set(wanted)
    hits: Dict[int, Counter] = {}
    for w, n in cands.items():
        for pre in ("", "$", "%"):
            name = pre + w
            k = name_key(name)
            if k in wanted:
                hits.setdefault(k, Counter())[name] += n
    return {k: max(v.items(), key=lambda kv: (casing_score(kv[0]), kv[1], kv[0]))[0] for k, v in hits.items()}
