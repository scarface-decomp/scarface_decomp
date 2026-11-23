"""The one-line descriptions ("// what:") of rebuilt functions: where each one came from, and counts.

Where a description came from is kept with it as "what_how":

    human   written by a person (in the portal, or when they verified the function)
    read    written by someone (a person or an AI) who read the function and what it calls
    shape   produced by a rule from the shape of the code alone (a deleting destructor, a class record
            getter, a create() of the class system ...): right, but boilerplate
    twin    copied from a function with the same bytes in another version of the game

Descriptions recorded before "what_how" existed get one worked out here: the first 2,085 written by an AI
(Nov 22) came from rules, and their sentences are recognisable; everything else counts as "human".
"""

from __future__ import annotations

import re
from collections import defaultdict
from typing import Dict, Iterable, Optional

HOWS = ("human", "read", "shape", "twin")
WHAT_MAX = 160
TWIN_SUFFIX = " (from the {version} twin)"

# The sentences the Nov 22 rules wrote (portal: descriptions_batch1.json); any of them means "shape".
_SHAPE = re.compile(
    r"deleting destructor: destroys the object"
    r"|static class record \(ConcreteClassRep<"
    r"|a new \S.* for the class system: allocates"
    r"|^(?:[\w:<>,* ]+: )?(?:Does|Returns) nothing \(an empty function"
    r"|^(?:Static )?[Ii]nitialiser for .*'s class record"
    r"|: allocates a new one \(\d+ bytes\), constructs it"
    r"|its own address, which serves as a unique tag"
    r"|dynamic_cast to \S+ \(the C\+\+ run-time cast"
    r"|^(?:[\w:<>,* ]+: )?Adds one to the counter at offset"
    r"|^(?:[\w:<>,* ]+: )?(?:Always )?[Rr]eturns -?(?:\d+|0x[0-9A-Fa-f]+|true|false)\.$"
    r"|: just calls \S+'s version of this slot")


def how_of(entry: dict) -> str:
    """Where an entry's description came from ("" when it has none)."""
    if not (entry.get("what") or "").strip():
        return ""
    how = entry.get("what_how")
    if how in HOWS:
        return how
    if str(entry.get("what_by") or "").startswith("Claude (AI)"):
        return "shape" if _SHAPE.search(entry["what"]) else "read"
    return "human"


def normal_how(value) -> str:
    """A submitted "how" ("by shape", "read", "human" ...) as one of HOWS; anything else is "human"."""
    v = str(value or "").strip().lower()
    if "shape" in v:
        return "shape"
    if v.startswith("read"):
        return "read"
    if "twin" in v:
        return "twin"
    return "human"


def problem(what: str) -> Optional[str]:
    """Why a description can't be taken as it is, or None. One sentence of plain text, at most WHAT_MAX
    characters, that says more than the code: not mostly sub_/DAT_ names and offsets."""
    if not what.strip():
        return "empty"
    if len(what) > WHAT_MAX:
        return f"longer than {WHAT_MAX} characters ({len(what)}): it would be cut off"
    words = re.findall(r"[\w]+", what)
    raw = [w for w in words if re.fullmatch(r"(?:sub|DAT|FUN|LAB)_[0-9A-Fa-f]+|0x[0-9A-Fa-f]+|\d+|m_(?:Field|pad)\w*", w)]
    if words and len(raw) * 2 > len(words):
        return "mostly addresses and offsets: it restates the code instead of saying what it does"
    return None


def counts(entries: Iterable[dict], is_ps2=lambda b: False) -> Dict[str, object]:
    """{"pc", "xb", "proto", "ps2", "total", "how": {human, read, shape, twin}} for described functions.
    "total" and "how" are the released game (PC + Xbox), as everywhere in progress.json."""
    by: Dict[str, int] = defaultdict(int)
    how: Dict[str, int] = {h: 0 for h in HOWS}
    for e in entries:
        h = how_of(e)
        if not h:
            continue
        b = "ps2" if is_ps2(e.get("bin", "")) else e.get("bin", "")
        by[b] += 1
        if b in ("pc", "xb"):
            how[h] += 1
    return {"pc": by["pc"], "xb": by["xb"], "proto": by["proto"], "ps2": by["ps2"],
            "total": by["pc"] + by["xb"], "how": how}
