#!/usr/bin/env python3
"""Names that the matched code's own shape makes certain (no game files needed: it reads the registry).

    python portal/scripts/names_from_shapes.py            # list what it finds
    python portal/scripts/names_from_shapes.py --write    # add the new ones to reports/names.json

Only matched functions are named, from their verified C++, and only in a class the game's own class
information (RTTI) already gives them: the name says which of that class's functions it is.

1. Deleting destructor -> Class::~Class. The body ends `if (a1 & 1) { FREE(this); } return this;`, where
   FREE is a routine that at least MIN_FREE matched functions call exactly that way (so it is the
   allocator's free, not a coincidence). What comes before is the destructor's own work. A class with more
   than one such function (a second base's thunk) is left out: which one is the destructor isn't certain.

2. Class record -> Class::GetClassRep. ConcreteClassRep<Class> is the game's own name (RTTI) for the
   record of a class; its set-up function writes the record's parent link at +0x24. A function of Class
   whose whole body returns that record's address (the record the set-up function of ConcreteClassRep<Class>,
   the same class, writes: `sub_X(root, record+0x20); record+0x24 = parent record;`) is the one that hands
   it out.

   With the game's program file in binaries/ (default.xbe, game.xbe), the record's own run-time type
   information is read too (vptr -> complete object locator -> type descriptor): a getter whose record's
   type is ConcreteClassRep<Class> is named even when the record's set-up function isn't matched yet, and
   one whose record is another class's (a class that has no record of its own and reports its parent's)
   is left alone whatever else says.

3. Create -> ConcreteClassRep<Class>::Create, or Factory<T>::Create for the fight factories
   (fight::*FactoryTemplate<T>): allocate N bytes with the allocator the class records (or the factories)
   use, and if that worked, construct the object in it and return it.

4. Set-up -> ConcreteClassRep<Class>::Init: the record's function that links its namespace under its
   parent's (classLinkNamespaces(parent record + 0x20, this record + 0x20), named from the game's own error
   message) and keeps the parent record at +0x24.

Every name records its rule and the evidence in "why".
"""

from __future__ import annotations

import argparse
import json
import re
import sys
from collections import Counter, defaultdict
from pathlib import Path
from typing import Dict, Tuple

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "portal" / "tools"))

import names as NAMES  # noqa: E402

FILES = {"xb": "default.xbe", "proto": "game.xbe", "pc": "Scarface.exe"}

BY = "the matched code's own shape (portal/scripts/names_from_shapes.py)"
MIN_FREE = 10
SYMBOL = re.compile(r"^(?P<cls>.+)::(?P<slot>vfunc_\d+|sub_[0-9A-F]{8})$")
FREE_TAIL = re.compile(r"if \(a1 & 1\) \{\s*(?P<free>sub_[0-9A-F]{8})\(\(int\)this\);\s*\}\s*return this;\s*\}\s*$")
RETURN_DAT = re.compile(r"^\{\s*return \(?[\w:<>* ]*\)?\s*&?\s*DAT_(?P<at>[0-9A-F]{8})\s*;\s*\}\s*$")
# the set-up: sub_X(DAT_root, DAT_<record + 0x20>); DAT_<record + 0x24> = (int)DAT_<parent record>;
REP_INIT = re.compile(r"sub_[0-9A-F]{8}\(DAT_[0-9A-F]{8}, DAT_(?P<at20>[0-9A-F]{8})\); "
                      r"DAT_(?P<at24>[0-9A-F]{8}) = \(int\)&?DAT_[0-9A-F]{8};")
CREATE = re.compile(r"(?P<alloc>sub_[0-9A-F]{8})\((?P<size>0x[0-9A-Fa-f]+|\d+)\b[^;]*;\s*(?:\w+\s*=\s*\w+;\s*)?"
                    r"if \(\w+\)\s*\{?\s*return\b[^;]*sub_[0-9A-F]{8}\(")


def body(entry: dict) -> str:
    """The text of the function itself: from the line that defines it to the end."""
    code, sym = entry.get("code", ""), entry.get("symbol", "")
    tail = sym.split("::")[-1]
    i = code.rfind("::" + tail + "(") if "::" in sym else code.rfind(" " + tail + "(")
    if i < 0:
        return ""
    j = code.find("{", i)
    return re.sub(r"\s+", " ", code[j:]).strip() if j >= 0 else ""


def short(cls: str) -> str:
    """The last part of a class name, without its template arguments: the destructor's own name."""
    depth, cut = 0, 0
    for i, ch in enumerate(cls):
        depth += ch == "<"
        depth -= ch == ">"
        if depth == 0 and cls.startswith("::", i):
            cut = i + 2
    return cls[cut:].split("<")[0]


def mangled_rep(cls: str) -> str:
    """The type descriptor name MSVC gives ConcreteClassRep<cls> (a class without template arguments)."""
    return ".?AV?$ConcreteClassRep@V" + "@".join(reversed(cls.split("::"))) + "@@@@"


def record_type(img, at: int) -> str:
    """The type descriptor name of the object at `at` (its vptr's complete object locator), or ""."""
    import struct
    try:
        vt = struct.unpack("<I", img.read(at, 4))[0]
        col = struct.unpack("<I", img.read(vt - 4, 4))[0]
        td = struct.unpack("<I", img.read(col + 12, 4))[0]
        return img.read(td + 8, 256).split(b"\0")[0].decode("latin-1")
    except Exception:  # noqa: BLE001 - not an object with type information: no answer
        return ""


def images() -> dict:
    """The game's program files that are here (binaries/), by version."""
    out = {}
    for b, name in FILES.items():
        path = ROOT / "binaries" / name
        if path.exists():
            from sf_binaries import BinaryImage
            out[b] = BinaryImage(path)
    return out


def find(entries: Dict[str, dict], imgs: dict = None) -> Dict[str, Tuple[str, str]]:
    """{key: (name, why)} for every version in the registry. imgs: the game's program files by version
    (images()), for the run-time type check of class records; without them only the code is used."""
    imgs = imgs or {}
    out: Dict[str, Tuple[str, str]] = {}
    for b in sorted({k.split(":")[0] for k in entries}):
        mine = {k: e for k, e in entries.items() if k.startswith(b + ":")}
        texts = {k: body(e) for k, e in mine.items()}
        frees = Counter(m.group("free") for t in texts.values() for m in [FREE_TAIL.search(t)] if m)
        frees = {f for f, n in frees.items() if n >= MIN_FREE}

        # 1. deleting destructors, one per class
        dtors = defaultdict(list)
        for k, t in texts.items():
            m, s = FREE_TAIL.search(t), SYMBOL.match(mine[k].get("symbol", ""))
            if m and s and m.group("free") in frees:
                dtors[s.group("cls")].append((k, m.group("free")))
        for cls, found in dtors.items():
            if len(found) == 1:
                k, free = found[0]
                out[k] = (f"{cls}::~{short(cls)}",
                          f"Deleting destructor: it ends `if (a1 & 1) {free}(this); return this;` ({free} is "
                          f"called that way by {sum(1 for t in texts.values() if f'{free}((int)this)' in t)} "
                          f"matched functions), and it is the only function of {cls} that does.")

        # 2. class records: ConcreteClassRep<C>'s set-up writes the record's +0x24
        record_of = {}
        for k, e in mine.items():
            s = SYMBOL.match(e.get("symbol", ""))
            m = REP_INIT.search(texts[k])
            if s and m and s.group("cls").startswith("ConcreteClassRep<") and \
                    int(m.group("at24"), 16) == int(m.group("at20"), 16) + 4:
                record_of[int(m.group("at24"), 16) - 0x24] = (s.group("cls")[len("ConcreteClassRep<"):-1], k)
        getters = defaultdict(list)
        img = imgs.get(b)
        for k, t in texts.items():
            m, s = RETURN_DAT.match(t), SYMBOL.match(mine[k].get("symbol", ""))
            if not (m and s):
                continue
            at, cls = int(m.group("at"), 16), s.group("cls")
            rtti = record_type(img, at) if img is not None and "<" not in cls else ""
            if rtti and rtti != mangled_rep(cls):
                continue                                    # another class's record: inherited, not its own
            if record_of.get(at, ("",))[0] == cls:
                getters[cls].append((k, at, f"its set-up function ({record_of[at][1]}) writes that record's +0x24"))
            elif rtti:
                getters[cls].append((k, at, f"the record's own run-time type information says {rtti}"))
        for cls, found in getters.items():
            if len(found) == 1:
                k, at, how = found[0]
                out[k] = (f"{cls}::GetClassRep", f"Returns 0x{at:08X}, the record of ConcreteClassRep<{cls}>: {how}.")

        # 4. the record's set-up: link its namespace under the parent's, keep the parent record
        for k, t in texts.items():
            s = SYMBOL.match(mine[k].get("symbol", ""))
            m = REP_INIT.search(t)
            if s and m and s.group("cls").startswith("ConcreteClassRep<") and \
                    int(m.group("at24"), 16) == int(m.group("at20"), 16) + 4:
                cls = s.group("cls")
                link = re.search(r"(sub_[0-9A-F]{8})\(DAT_", t).group(1)
                out[k] = (f"{cls}::Init",
                          f"Links the record's namespace (+0x20) under its parent record's with {link} "
                          f"(classLinkNamespaces, named from the game's own error message) and keeps the parent "
                          f"record at +0x24.")

        # 3. create(): allocate, construct, return
        for k, t in texts.items():
            s = SYMBOL.match(mine[k].get("symbol", ""))
            if not s:
                continue
            cls = s.group("cls")
            m = CREATE.search(t)
            if not m:
                continue
            if cls.startswith("ConcreteClassRep<") or re.match(r"^fight::\w*FactoryTemplate<", cls):
                out.setdefault(k, (f"{cls}::Create",
                                   f"Allocates {int(m.group('size'), 0)} bytes ({m.group('alloc')}) and, if that "
                                   f"worked, constructs the object in them and returns it."))
    return out


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    ap.add_argument("--write", action="store_true", help="add the new names to reports/names.json")
    args = ap.parse_args()
    entries = json.loads((ROOT / "reports" / "verified_registry.json").read_text(encoding="utf-8"))["entries"]
    path = ROOT / "reports" / "names.json"
    data = NAMES.load(path)
    names = data.setdefault("names", {})
    found = find(entries, images())
    taken = defaultdict(set)
    for k, v in names.items():
        taken[k.split(":")[0]].add(v["name"])
    added = Counter()
    for key, (name, why) in sorted(found.items()):
        b = key.split(":")[0]
        if key in names or name in taken[b] or not NAMES.NAME_RE.match(name):
            continue
        taken[b].add(name)
        added[b] += 1
        if args.write:
            names[key] = {"name": name, "by": BY, "why": why}
        else:
            print(f"  {key}  {name}")
    kinds = Counter(n.split("::")[-1] if not n.split("::")[-1].startswith("~") else "~ (destructor)"
                    for n, _ in found.values())
    print(f"{len(found)} functions named by their shape ({', '.join(f'{v} {k}' for k, v in kinds.most_common())}); "
          f"not recorded yet: {', '.join(f'{v} {b}' for b, v in sorted(added.items())) or 'none'}")
    if args.write and added:
        path.write_text(json.dumps(data, indent=2, ensure_ascii=False) + "\n", encoding="utf-8", newline="\n")
        print(f"Added {sum(added.values())} names to reports/names.json.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
