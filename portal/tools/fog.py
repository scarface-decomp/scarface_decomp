#!/usr/bin/env python3
"""
The fog for an hour of the day and a weather, read from the game's own files (docs/FORMATS.md, "Fog by
time of day", from the clean-room spec docs/cleanroom/SPEC-001-lights-sky-streaming.md):

    the EnvironmentObjects the compiled script scriptc/graphanims.cso creates (Miami: environment_clear_<hour>,
    environment_rainy_<hour>), or scriptc/island_envobjects.cso (the islands: island_environment_...):
    FogEnabled, FogStart, FogEnd, FogColor_Red, FogColor_Green, FogColor_Blue, FogColor_Alpha, FogClamp
    the script object tod (class todobject) in packages/z04/miami_lod.p3d: the key hours
    (prelitluminancetime_N) and, for each, the names of its two EnvironmentObjects
    (attachedclearenvparamname_N, attachedrainyenvparamname_N)

    python portal/tools/fog.py miami_lod.p3d graphanims.cso --hour 15
    python portal/tools/fog.py miami_lod.p3d graphanims.cso.cs --hour 2 --weather rain --islands

Between two key hours the fog is blended in a straight line by the clock, and the hours go round: 24 is
also 0, so 2 a.m. lies between the 24 and the 4 key. The scripts are read with the repository's own
decompiler (torque_script.py); a decompiled .cs file works too. Names in the compiled scripts are hashed
(torque_names.py), so properties and objects are matched by their hash and need no name recovery.

Your own copies, on your own computer; standard library only.
"""

from __future__ import annotations

import argparse
import json
import struct
import sys
from pathlib import Path
from typing import Dict, Iterable, List, Optional, Sequence, Tuple

sys.path.insert(0, str(Path(__file__).resolve().parent))
import p3d  # noqa: E402
import torque_ast as AST  # noqa: E402
import torque_script as TS  # noqa: E402
from torque_names import name_key  # noqa: E402
from torque_parse import ParseError, parse  # noqa: E402

MIAMI_SCRIPT, ISLAND_SCRIPT = "graphanims.cso", "island_envobjects.cso"
ISLAND_PREFIX = "island_"                # the islands' objects: island_environment_clear_4 ...
WEATHERS = ("clear", "rain")
LINKS = {"clear": "attachedclearenvparamname_", "rain": "attachedrainyenvparamname_"}
HOUR_KEY = "prelitluminancetime_"
KEYS = 6                                 # the tod object's keys, N = 0 to 5
ENVIRONMENT_CLASS = name_key("EnvironmentObject")
FOG = {name_key(n): n for n in ("FogEnabled", "FogStart", "FogEnd", "FogColor_Red", "FogColor_Green", "FogColor_Blue",
                                 "FogColor_Alpha", "FogClamp")}


class FogError(ValueError):
    pass


# --------------------------------------------------------------------------- the scripts' EnvironmentObjects

def _number(node) -> Optional[float]:
    """A property's value as a number: 25, 900.5, "800", -3."""
    if isinstance(node, AST.IntConst):
        return float(node.value)
    if isinstance(node, AST.FloatConst):
        return float(node.text) if node.text else struct.unpack("<f", node.raw)[0]
    if isinstance(node, AST.StrConst):
        try:
            return float(node.value)
        except ValueError:
            return None
    if isinstance(node, AST.FloatUnary):
        v = _number(node.expr)
        return -v if v is not None else None
    return None


def _objects(tree) -> Iterable[AST.ObjectDecl]:
    """Every object declaration anywhere in a syntax tree (inside functions, assignments, other objects)."""
    if isinstance(tree, list):
        for item in tree:
            yield from _objects(item)
        return
    if isinstance(tree, AST.ObjectDecl):
        yield tree
    for name in getattr(tree, "__dataclass_fields__", ()):
        v = getattr(tree, name)
        if isinstance(v, (list, AST.Node)) or hasattr(v, "__dataclass_fields__"):
            yield from _objects(v)


def _word(node) -> str:
    if isinstance(node, AST.StrConst):
        return node.value
    if isinstance(node, AST.Ident):
        return node.name
    return ""


def environment_objects(script) -> Dict[int, dict]:
    """The EnvironmentObjects a script creates, by the key of their name (torque_names.name_key: letter
    case doesn't matter, and a hashed name matches the word it stands for): {key: {"name", "fog": {property:
    number}}}, fog holding the fog properties the object sets. script: a compiled script's bytes (.cso), or
    TorqueScript text (a decompiled .cs)."""
    try:
        text = TS.decompile(script) if isinstance(script, (bytes, bytearray)) else str(script)
        tree = parse(text)
    except (TS.ScriptError, ParseError) as e:
        raise FogError(f"can't read the script: {e}") from e
    out: Dict[int, dict] = {}
    for obj in _objects(tree):
        name = _word(obj.name_expr)
        if not name or name_key(_word(obj.class_expr) or "-") != ENVIRONMENT_CLASS:
            continue
        values = {}
        for slot in obj.slots:
            prop = FOG.get(name_key(slot.slot))
            v = _number(slot.value)
            if prop and v is not None and slot.index is None:
                values[prop] = v
        out.setdefault(name_key(name), {"name": name, "fog": values})
    return out


# --------------------------------------------------------------------------- the tod object (miami_lod.p3d)

def tod_object(data: bytes, chunks: Optional[List[p3d.Chunk]] = None) -> Dict[str, str]:
    """The text properties (name in lower case: value) of the script object tod (class todobject) in a
    .p3d file: a Script Object Data chunk (0x9900190) and its properties (0x9900192). {} when it has none.
    chunks: the file's chunk tree, if it has been read already."""
    for c in p3d.walk(chunks if chunks is not None else p3d.read_tree(data)):
        if c.id != 0x9900190:
            continue
        info = p3d.fields(data, c)
        if info.get("class", "").lower() != "todobject" and info.get("name", "").lower() != "tod":
            continue
        props = {}
        for k in c.children:
            f = p3d.fields(data, k) if k.id == 0x9900192 else {}
            if "value" in f:
                props[f["name"].lower()] = f["value"]
        return props
    return {}


def key_hours(tod: Dict[str, str], weather: str = "clear") -> List[Tuple[float, str]]:
    """(hour, the name of that hour's EnvironmentObject for the weather) for each of the tod object's keys
    that has both, by hour."""
    out = []
    for n in range(KEYS):
        hour, link = tod.get(f"{HOUR_KEY}{n}"), tod.get(f"{LINKS[weather]}{n}")
        try:
            h = float(hour) if hour is not None else None
        except ValueError:
            h = None
        if h is not None and link:
            out.append((h, link.strip()))
    return sorted(out)


def _blend(a: dict, b: dict, t: float) -> dict:
    out = {}
    for prop in FOG.values():
        if prop in a and prop in b:
            out[prop] = a[prop] + (b[prop] - a[prop]) * t
        elif prop in a or prop in b:
            out[prop] = a.get(prop, b.get(prop))
    if "FogEnabled" in a or "FogEnabled" in b:           # on when the key it is at, or either side of it, has it on
        on = [k.get("FogEnabled", 0) for k in ((a,) if t <= 0 else (b,) if t >= 1 else (a, b))]
        out["FogEnabled"] = 1.0 if any(on) else 0.0
    return out


def fog_at(hour: float, tod: Dict[str, str], objects: Dict[int, dict], weather: str = "clear",
           islands: bool = False) -> Optional[dict]:
    """The fog at an hour (0 to 24) in a weather ("clear" or "rain"): {"hour", "weather", "place", "enabled",
    "start", "end", "color" (r, g, b over 255), "alpha", "clamp", "keys" (the two objects blended), "blend"
    (how far from the first to the second)}. The tod object's key hours, each linked to an EnvironmentObject
    by name, blended in a straight line between the two key hours around the hour; the hours go round (24 is
    also 0). With islands, a linked name is looked for with island_ in front too (the islands' objects are
    island_environment_...). None when the tod object or the objects it names aren't there."""
    if weather not in WEATHERS:
        raise FogError(f"the weather is clear or rain, not {weather!r}")
    found = []
    for h, link in key_hours(tod, weather):
        names = (ISLAND_PREFIX + link, link) if islands else (link,)
        obj = next((objects[name_key(n)] for n in names if name_key(n) in objects), None)
        if obj is not None and obj["fog"]:
            found.append((h % 24.0, obj))                  # 24 is also 0
    if not found:
        return None
    found.sort(key=lambda k: k[0])
    ring = [(h - 24.0, o) for h, o in found] + found + [(h + 24.0, o) for h, o in found]
    at = float(hour) % 24.0
    i = max(k for k, (x, _o) in enumerate(ring) if x <= at)     # the last key at or before the hour
    (h0, a), (h1, b) = ring[i], ring[i + 1]
    t = (at - h0) / (h1 - h0) if h1 > h0 else 0.0
    v = _blend(a["fog"], b["fog"], t)
    colour = [round(v.get(f"FogColor_{c}", 0.0) / 255.0, 4) for c in ("Red", "Green", "Blue")]
    out = {"hour": hour, "weather": weather, "place": "islands" if islands else "miami",
           "enabled": bool(v.get("FogEnabled", 0)), "start": round(v.get("FogStart", 0.0), 3),
           "end": round(v.get("FogEnd", 0.0), 3), "color": colour,
           "keys": [a["name"], b["name"]], "blend": round(t, 4)}
    for prop, key in (("FogColor_Alpha", "alpha"), ("FogClamp", "clamp")):
        if prop in v:
            out[key] = round(v[prop], 4)
    return out


# --------------------------------------------------------------------------- finding the files

def find_scripts(paths: Sequence[Path]) -> Dict[str, Path]:
    """The game's scripts for the fog among paths (files, or folders holding them or a scriptc folder):
    {"miami": .../graphanims.cso, "islands": .../island_envobjects.cso}, each also as a decompiled .cs
    (graphanims.cso.cs) when the compiled one isn't there. Letter case doesn't matter."""
    want = {MIAMI_SCRIPT: "miami", ISLAND_SCRIPT: "islands"}
    out: Dict[str, Path] = {}

    def take(p: Path) -> None:
        low = p.name.lower()
        for name, place in want.items():
            if low == name:
                out[place] = p
            elif low == name + ".cs":
                out.setdefault(place, p)
    for p in paths:
        p = Path(p)
        if p.is_file():
            take(p)
        elif p.is_dir():
            for folder in (p, p / "scriptc"):
                try:
                    for q in sorted(folder.iterdir()):
                        if q.is_file():
                            take(q)
                except OSError:
                    continue
    return out


def read_objects(script: Path) -> Dict[int, dict]:
    raw = script.read_bytes()
    if script.suffix.lower() == ".cs":
        return environment_objects(raw.decode("latin-1"))
    return environment_objects(raw)


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description="The fog the game shows at an hour, from miami_lod.p3d's tod object and "
                                             "the EnvironmentObjects in scriptc/graphanims.cso.")
    ap.add_argument("tod", type=Path, help="the .p3d with the tod object (packages/z04/miami_lod.p3d)")
    ap.add_argument("script", type=Path, help="scriptc/graphanims.cso or island_envobjects.cso (or a decompiled .cs)")
    ap.add_argument("--hour", type=float, required=True, help="0 to 24")
    ap.add_argument("--weather", choices=WEATHERS, default="clear")
    ap.add_argument("--islands", action="store_true", help="the islands' objects (island_environment_...)")
    a = ap.parse_args(argv)
    try:
        if not 0 <= a.hour <= 24:
            raise FogError("--hour is from 0 to 24")
        tod = tod_object(a.tod.read_bytes())
        if not tod:
            raise FogError(f"no tod object in {a.tod.name}")
        fog = fog_at(a.hour, tod, read_objects(a.script), a.weather, a.islands)
        if fog is None:
            raise FogError(f"{a.script.name} has none of the EnvironmentObjects the tod object names")
    except (OSError, p3d.P3dError, FogError) as e:
        print(f"fog: {e}", file=sys.stderr)
        return 1
    print(json.dumps(fog, indent=1))
    return 0


if __name__ == "__main__":
    sys.exit(main())
