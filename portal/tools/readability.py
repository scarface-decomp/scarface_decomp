#!/usr/bin/env python3
"""How readable a matched function's C++ is. A match proves the code compiles to the game's bytes; it says
nothing about whether a person can read it. A function straight from the starter still calls sub_001B0920,
reads DAT_0045418C and keeps its members as m_Field08: correct, and not yet finished.

grade(code) counts what is left to name or retype:

  * stand-in names: sub_/func_/FUN_ and an address, DAT_/D_ and an address, m_Field08, Field08, vfunc_12,
    local t1/v3/a2 the starter makes up, Object for a class nobody has named
  * raw address work: (int)this, *(int*)(... + 8) and the like, where a named member or a proper type belongs

A function with neither is "readable"; any other is "matched". Padding members (m_pad04) are not counted:
they are the honest way to say "something is here that this function doesn't touch". Standard library only.
"""
from __future__ import annotations

import re
from typing import Dict, List

import cpp_policy

STAND_INS = re.compile(
    r"\b(?:(?:sub|func|FUN|fn|loc)_[0-9A-Fa-f]{4,}"          # a function known only by its address
    r"|(?:DAT|D|unk|byte|dword|word|flt|off)_[0-9A-Fa-f]{4,}"  # a global known only by its address
    r"|m_[Ff]ield_?[0-9A-Fa-f]{1,4}|[Ff]ield_?[0-9A-Fa-f]{2,4}"  # a member known only by its offset
    r"|vfunc_\d{1,3}"                                         # a virtual known only by its slot
    r"|Object)\b")                                            # the starter's name for an unnamed class
MADE_UP_LOCALS = re.compile(r"\b(?:int|float|char|bool|short|unsigned|long|void\s*\*)\s+([tva]\d{1,2})\b")
RAW_ADDRESS = re.compile(
    r"\(\s*(?:unsigned\s+)?(?:int|long|char\s*\*)\s*\)\s*\(?\s*this\b"       # (int)this, (char*)this
    r"|\*\s*\(\s*[A-Za-z_][\w\s]*\*+\s*\)\s*\("                               # *(int*)( ...
    r"|\(\s*[A-Za-z_]\w*\s*\*\s*\)\s*\(\s*int\s*\)")                          # (Object*)(int) ...


def grade(code: str) -> Dict[str, object]:
    """{"grade": "readable" | "matched", "stand_ins": [names, as written, most used first],
    "raw_addresses": how many, "left": how many things in all are left to name or retype}."""
    text = cpp_policy.strip_cpp_comments(code or "")
    seen: Dict[str, int] = {}
    for m in STAND_INS.finditer(text):
        seen[m.group(0)] = seen.get(m.group(0), 0) + 1
    for m in MADE_UP_LOCALS.finditer(text):
        seen[m.group(1)] = seen.get(m.group(1), 0) + 1
    names: List[str] = sorted(seen, key=lambda n: (-seen[n], n))
    raw = len(RAW_ADDRESS.findall(text))
    left = len(names) + raw
    return {"grade": "readable" if not left else "matched", "stand_ins": names, "raw_addresses": raw, "left": left}


def is_readable(code: str) -> bool:
    return grade(code)["grade"] == "readable"


def advice(code: str, limit: int = 6) -> str:
    """One line on what is left, for a person or for an AI's prompt; "" when nothing is."""
    g = grade(code)
    if not g["left"]:
        return ""
    parts = []
    if g["stand_ins"]:
        names = g["stand_ins"]
        more = f" and {len(names) - limit} more" if len(names) > limit else ""
        parts.append(f"{len(names)} stand-in name{'s' if len(names) != 1 else ''} to replace with what the thing is "
                     f"({', '.join(names[:limit])}{more})")
    if g["raw_addresses"]:
        n = g["raw_addresses"]
        parts.append(f"{n} place{'s' if n != 1 else ''} that work{'s' if n == 1 else ''} on a raw address where a named member "
                     f"or a proper type belongs")
    return "Still to do before it reads as finished C++: " + "; ".join(parts) + "."


if __name__ == "__main__":
    import json
    import sys
    from pathlib import Path
    root = Path(__file__).resolve().parents[2]
    entries = json.loads((root / "reports" / "verified_registry.json").read_text(encoding="utf-8"))["entries"]
    if len(sys.argv) > 1:
        e = entries[sys.argv[1]]
        print(json.dumps(grade(e.get("code", "")), indent=1))
        print(advice(e.get("code", "")))
    else:
        done = sum(1 for e in entries.values() if is_readable(e.get("code", "")))
        print(f"{done:,} of {len(entries):,} matched functions read as finished C++")
