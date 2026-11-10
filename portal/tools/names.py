#!/usr/bin/env python3
"""
Names people worked out for functions that aren't matched yet: reports/names.json.

A name says what a function does before anyone has matched its C++ (for example that sub_0011E4A0 is
"Weapon::Reload"). Names reach Ghidra and IDA through portal/scripts/ghidra_scarface_names.py and
ida_scarface_names.py, together with every function's start and size from reconstructed_src/, and the
portal shows them next to the function. Once a function is matched, the name it was matched with wins.

    {"schema": "scarface_names_v1",
     "names": {"xb:0x0011E4A0": {"name": "Weapon::Reload", "by": "handle", "why": "what shows it"}}}

Keys are the registry's: a version (pc, xb, proto, ps2) and the function's address. Names are C++ names:
letters, digits and _, parts joined by ::, templates in <>. Add one with a pull request (docs/NAMES.md),
or suggest it from the portal and a maintainer adds it.
"""

from __future__ import annotations

import json
import re
from pathlib import Path
from typing import Dict, List, Optional

SCHEMA = "scarface_names_v1"
BINS = ("pc", "xb", "proto", "ps2")
KEY_RE = re.compile(r"^(pc|xb|proto|ps2):0x[0-9A-F]{8}$")
PART = r"[A-Za-z_][A-Za-z0-9_]*(?:<[A-Za-z0-9_:<>, *&]+>)?"
NAME_RE = re.compile(rf"^(?:{PART}::)*(?:{PART}|operator\S{{1,3}}|~{PART})$")
DEFAULT_RE = re.compile(r"^(sub|func|FUN|thunk)_[0-9A-Fa-f]+$")
EMPTY = {"schema": SCHEMA, "names": {}}


def load(path: Path) -> dict:
    try:
        data = json.loads(path.read_text(encoding="utf-8"))
    except (OSError, ValueError):
        return dict(EMPTY, names={})
    return data if isinstance(data, dict) else dict(EMPTY, names={})


def key_for(task: dict) -> str:
    return f"{task['bin']}:0x{int(task['fva_int']):08X}"


def problems(data: dict, known: Optional[Dict[str, set]] = None) -> List[str]:
    """What is wrong with a names file. known: the addresses each version has (to catch typos)."""
    out: List[str] = []
    if data.get("schema") != SCHEMA:
        out.append(f"reports/names.json: schema must be {SCHEMA!r}")
    names = data.get("names")
    if not isinstance(names, dict):
        return out + ["reports/names.json: 'names' must be an object"]
    seen: Dict[tuple, str] = {}
    for key, info in names.items():
        where = f"reports/names.json {key}"
        if not KEY_RE.match(key):
            out.append(f"{where}: keys look like xb:0x0011E4A0 (pc, xb, proto or ps2, then 8 upper-case hex digits)")
            continue
        if not isinstance(info, dict):
            out.append(f"{where}: must be an object with name, by and why")
            continue
        name = info.get("name")
        if not isinstance(name, str) or not NAME_RE.match(name) or DEFAULT_RE.match(name.split("::")[-1]):
            out.append(f"{where}: {name!r} isn't a C++ function name (letters, digits, _ and ::)")
        if not isinstance(info.get("by"), str) or not info["by"].strip():
            out.append(f"{where}: say who worked it out ('by')")
        if not isinstance(info.get("why"), str) or len(info["why"].strip()) < 10:
            out.append(f"{where}: say in a sentence what shows it ('why')")
        b = key.split(":")[0]
        if known is not None and b in known and int(key.split(":")[1], 16) not in known[b]:
            out.append(f"{where}: no function starts there in reconstructed_src/")
        if isinstance(name, str):
            other = seen.get((b, name))
            if other:
                out.append(f"{where}: {name} is already the name of {other}")
            seen[(b, name)] = key
    return out


if __name__ == "__main__":
    import sys
    root = Path(__file__).resolve().parents[2]
    errs = problems(load(root / "reports" / "names.json"))
    print("\n".join(errs) or "reports/names.json is fine")
    sys.exit(1 if errs else 0)
