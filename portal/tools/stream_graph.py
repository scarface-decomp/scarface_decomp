#!/usr/bin/env python3
"""
Read the stream graph (art/levels/z04/streamgraph.p3d): which packages the game keeps loaded at each
place in the city.

    python portal/tools/stream_graph.py streamgraph.p3d              every trigger: its subzone, outline
                                                                    and packages
    python portal/tools/stream_graph.py streamgraph.p3d --at X Z     what is loaded at x, z

The file holds Stream Packages (0x8800100: a package name and a number) and Stream Triggers (0x8800101):
a name, the subzone it belongs to, its height, an outline on the ground (points x, y, z; y is its base),
the packages that must be loaded while you are inside it and the slot each goes in (Global_S, Region_D,
Shell, Detail, ZoneAnimation ...), then two region names and a number, "gives way" when not 0.

Which trigger applies (clean-room spec docs/cleanroom/SPEC-011-streaming-frame-controllers.md, sections 1
and 2): a trigger is an upright prism, its outline from the average height of its points up by its height
(no limit when the height is 0), and only one trigger applies at a time. What is loaded is exactly that
trigger's packages: no union with the triggers around it. For one fixed answer per place, the first
trigger in the file's order whose prism holds the point, the one that gives way last. Outside them all the
game keeps what it had, which depends on the way you came: above a building's street trigger, the export
takes the building's own nearest trigger that reaches the height; else the nearest trigger. The coordinates are the map's own: in a glTF
export from p3d_gltf.py, Z is mirrored, so ask for the export's (x, -z). Layouts in docs/FORMATS.md.

Interiors' furniture (packages/dzones/*_dzone.p3d) is not in the stream graph: the mission script
scriptc/missions/z04/dzone_triggers.dso loads each by its own outline (dzone_triggers below), and the
outdoor pockets (packages/azones) the same way from azone_triggers.dso.

Your own copies, on your own computer; standard library only.
"""

from __future__ import annotations

import argparse
import math
import sys
from dataclasses import dataclass, field
from pathlib import Path
from typing import Dict, List, Optional, Sequence, Tuple

sys.path.insert(0, str(Path(__file__).resolve().parent))
import p3d  # noqa: E402

STREAM_PACKAGE, STREAM_TRIGGER = 0x8800100, 0x8800101

Point = Tuple[float, float, float]


@dataclass
class Trigger:
    name: str
    subzone: str
    height: float
    points: List[Point]                                   # the outline on the ground: x, y (its base), z
    packages: List[Tuple[str, str]]                       # (package, slot), in the file's order
    regions: List[str] = field(default_factory=list)      # two region names: they load nothing
    flag: int = 0                                         # not 0: it "gives way" (SPEC-011 section 1.3)

    @property
    def gives_way(self) -> bool:
        return self.flag != 0

    @property
    def base(self) -> float:
        """The prism's floor: the average of its points' heights, kept in tenths, cut down."""
        if not self.points:
            return 0.0
        return _tenths(sum(p[1] for p in self.points) / len(self.points))

    @property
    def top(self) -> Optional[float]:
        """The prism's roof (base + height), or None when the height is 0: no limit."""
        h = _tenths(self.height)
        return None if abs(h) <= HEIGHTLESS else self.base + h


HEIGHTLESS = 1e-5                                         # a height this near 0 sets no limit
STEP = 0.1                                                # the game keeps outlines in tenths of a unit
MOST = 32767                                              # in a signed 16-bit number


def _tenths(v: float) -> float:
    """A length kept as a whole number of tenths, cut down (towards 0)."""
    return int(v * 10.0) / 10.0


@dataclass
class Loaded:
    """What is loaded at a place: the trigger that applies (or, when none holds it, the nearest one) and
    its packages, each (package, slot), in its order."""
    triggers: List[Trigger]
    inside: bool                                          # False: no prism holds the place
    packages: List[Tuple[str, str]]
    how: str = "inside"                                   # or "came through" (kept from a neighbour) or "nearest"

    def by_slot(self) -> Dict[str, List[str]]:
        out: Dict[str, List[str]] = {}
        for package, slot in self.packages:
            out.setdefault(slot, []).append(package)
        return out


def triggers(data: bytes) -> List[Trigger]:
    """Every Stream Trigger in a file, in order."""
    out = []
    for c in p3d.walk(p3d.read_tree(data)):
        if c.id != STREAM_TRIGGER:
            continue
        f = p3d.fields(data, c)
        if not f:
            continue
        out.append(Trigger(f["name"], f["subzone"], f["height"], list(f["points"]),
                           list(zip(f["packages"], f["slots"])), list(f.get("regions", [])), f.get("flag", 0)))
    return out


def packages(data: bytes) -> Dict[str, int]:
    """Every Stream Package in a file: its name and its number (what the number means isn't known)."""
    out = {}
    for c in p3d.walk(p3d.read_tree(data)):
        if c.id == STREAM_PACKAGE:
            f = p3d.fields(data, c)
            if f:
                out[f["name"]] = f["number"]
    return out


def _edges(t: Trigger):
    pts = [(p[0], p[2]) for p in t.points]
    return [(pts[i], pts[(i + 1) % len(pts)]) for i in range(len(pts))]


def _segment_distance(x: float, z: float, a: Tuple[float, float], b: Tuple[float, float]) -> float:
    dx, dz = b[0] - a[0], b[1] - a[1]
    length = dx * dx + dz * dz
    k = 0.0 if length == 0 else max(0.0, min(1.0, ((x - a[0]) * dx + (z - a[1]) * dz) / length))
    return math.hypot(x - (a[0] + k * dx), z - (a[1] + k * dz))


def distance(t: Trigger, x: float, z: float) -> float:
    """How far x, z is from a trigger's outline, on the ground (0 on it)."""
    if not t.points:
        return math.inf
    return min(_segment_distance(x, z, a, b) for a, b in _edges(t))


def _grid(t: Trigger) -> Tuple[float, float, float]:
    """How the game keeps an outline: its smallest x and z, and the step its points are counted in
    (tenths, or coarser when the outline is too wide for a 16-bit count: SPEC-011 section 1.1, (check)
    the coarser step)."""
    xs, zs = [p[0] for p in t.points], [p[2] for p in t.points]
    wide = max(max(xs) - min(xs), max(zs) - min(zs))
    return min(xs), min(zs), max(STEP, wide / MOST)


def contains(t: Trigger, x: float, z: float, y: Optional[float] = None) -> bool:
    """Whether a trigger holds a place (SPEC-011 section 1.2): x and z in its outline's box and in its outline
    (the crossing count, on the outline counted in the game's tenths), and y, when given, from its base
    to base + height, both ends in; a trigger of no height holds every y."""
    if len(t.points) < 3:
        return False
    xs, zs = [p[0] for p in t.points], [p[2] for p in t.points]
    if not (math.floor(min(xs)) <= x <= math.ceil(max(xs)) and math.floor(min(zs)) <= z <= math.ceil(max(zs))):
        return False
    if y is not None and not contains_height(t, y):
        return False
    if distance(t, x, z) <= 1e-6:                          # on the outline: in
        return True
    x0, z0, step = _grid(t)
    q = [(int((p[0] - x0) / step), int((p[2] - z0) / step)) for p in t.points]
    px, pz = (x - x0) / step, (z - z0) / step
    inside = False
    for (ax, az), (bx, bz) in zip(q, q[1:] + q[:1]):
        if (az > pz) != (bz > pz) and px < ax + (pz - az) * (bx - ax) / (bz - az):
            inside = not inside
    return inside


def current(found: Sequence[Trigger], x: float, z: float, y: Optional[float] = None) -> Optional[Trigger]:
    """The trigger that applies at a place, for one fixed answer (SPEC-011 section 1.3): the first in the
    file's order whose prism holds it, any other before the one that gives way. None when none holds it.
    (In the game the current trigger is sticky: coming in from another side can keep an overlapping one.)"""
    hits = [t for t in found if contains(t, x, z, y)]
    return next((t for t in hits if not t.gives_way), hits[0] if hits else None)


def loaded_at(found: Sequence[Trigger], x: float, z: float, y: Optional[float] = None) -> Loaded:
    """What the game has loaded at x, z (and y: the height, for the triggers that have one), in the map's
    own coordinates: exactly the packages of the one trigger that applies (SPEC-011 section 2). When no
    trigger holds the place, the game keeps what it had: the nearest trigger stands in."""
    hit = current(found, x, z, y)
    inside = hit is not None
    how = "inside"
    if hit is None and y is not None:
        hit, how = _came_through(found, x, z, y), "came through"
    if hit is None and found:
        hit, how = min(found, key=lambda t: distance(t, x, z)), "nearest"
    if hit is None:
        return Loaded([], False, [], "nearest")
    seen, packages_ = set(), []
    for pair in hit.packages:
        if pair not in seen:
            seen.add(pair)
            packages_.append(pair)
    return Loaded([hit], inside, packages_, how)


def _came_through(found: Sequence[Trigger], x: float, z: float, y: float) -> Optional[Trigger]:
    """Above (or below) every prism at a place, the current trigger does not change (SPEC-011 section 1.3:
    the update at 0x90990 finds none and keeps the pointer at 0x481AF4), so what is loaded is the trigger
    you were last inside. You reach a height no prism holds by leaving, at that height, a prism that holds
    it: one whose outline meets the outline of a trigger standing under you. So: the nearest trigger that
    reaches y and touches a trigger holding x, z on the ground, any other before one that gives way; with
    none, the one under you (the examiner's "directly below"). Jerry's office in the Coconut Grove bank
    (y 13.87) is above loadTrigger_448 (top 10); its neighbour loadTrigger_400, the bank's stair column with
    no height limit, reaches it, and alone loads the upstairs furniture (luxurybank_02_detailB)."""
    below = [t for t in found if contains(t, x, z)]
    if not below:
        return None
    reach = [t for t in found if t not in below and contains_height(t, y) and any(touches(t, b) for b in below)]
    if reach:
        reach.sort(key=lambda t: (t.gives_way, distance(t, x, z)))
        return reach[0]
    return next((t for t in below if not t.gives_way), below[0])


def touches(a: Trigger, b: Trigger) -> bool:
    """Whether two triggers' outlines meet (on the ground): a corner of one inside the other, or two edges
    that cross."""
    if any(contains(b, p[0], p[2]) for p in a.points) or any(contains(a, p[0], p[2]) for p in b.points):
        return True
    ea = list(zip(a.points, a.points[1:] + a.points[:1]))
    eb = list(zip(b.points, b.points[1:] + b.points[:1]))

    def side(p, q, r):
        return (q[0] - p[0]) * (r[2] - p[2]) - (q[2] - p[2]) * (r[0] - p[0])

    for p1, p2 in ea:
        for q1, q2 in eb:
            if side(p1, p2, q1) * side(p1, p2, q2) < 0 and side(q1, q2, p1) * side(q1, q2, p2) < 0:
                return True
    return False


def contains_height(t: Trigger, y: float) -> bool:
    """Whether a trigger's prism reaches a height (a trigger of no height reaches every one)."""
    top = t.top
    return top is None or t.base <= y <= top


@dataclass
class ScriptTrigger:
    """A mission script's trigger (dzone_triggers.dso, azone_triggers.dso): its name, its outline (x, y, z)
    and the packages its load command names."""
    name: str
    points: List[Point]
    packages: List[str]

    def holds(self, x: float, z: float) -> bool:
        return contains(Trigger(self.name, "", 0.0, self.points, []), x, z)


def script_triggers(text: str) -> List[ScriptTrigger]:
    """The triggers of a decompiled zone-trigger script: each object whose words hold its outline's points
    ("x y z", in order) and a load command, LoadDzone('...') or LoadAzone('...')."""
    import re
    out = []
    for m in re.finditer(r'new \w+\("(\w+)"\)\s*\{([^{}]*)\}', text):
        body = m.group(2)
        points = [tuple(float(v) for v in found.split())
                  for found in re.findall(r'=\s*"(-?[\d.]+(?:e-?\d+)? -?[\d.]+(?:e-?\d+)? -?[\d.]+(?:e-?\d+)?)"\s*;', body)]
        loads = re.findall(r"(?<![A-Za-z])Load[AD]zone\('(\w+)'\)", body)
        if len(points) >= 3 and loads:
            out.append(ScriptTrigger(m.group(1), points, loads))  # type: ignore[arg-type]
    return out


def script_loaded_at(found: Sequence[ScriptTrigger], x: float, z: float) -> List[str]:
    """The packages every script trigger holding x, z loads (the map's own coordinates), each once."""
    out: List[str] = []
    for t in found:
        if t.holds(x, z):
            out += [p for p in t.packages if p not in out]
    return out


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description="Show what the stream graph (streamgraph.p3d) loads where.")
    ap.add_argument("file", type=Path, help="art/levels/z04/streamgraph.p3d")
    ap.add_argument("--at", type=float, nargs="+", metavar="X Z [Y]",
                    help="what is loaded at this place (the map's own coordinates; the height too, if known)")
    a = ap.parse_args(argv)
    try:
        data = a.file.read_bytes()
        found = triggers(data)
    except (OSError, p3d.P3dError) as e:
        print(f"{a.file}: {e}", file=sys.stderr)
        return 1
    if not found:
        print(f"{a.file}: no stream triggers in it", file=sys.stderr)
        return 1
    if a.at:
        x, z = a.at[0], a.at[1]
        got = loaded_at(found, x, z, a.at[2] if len(a.at) > 2 else None)
        names = ", ".join(f"{t.name} ({t.subzone})" for t in got.triggers)
        print(f"the trigger that applies: {names}" if got.inside else f"inside no trigger; the nearest: {names}")
        for slot, names_ in got.by_slot().items():
            print(f"  {slot}: {', '.join(names_)}")
        return 0
    print(f"{len(packages(data))} stream package(s), {len(found)} trigger(s)")
    for t in found:
        print(f"{t.name}  subzone={t.subzone}  height={t.height}  points={len(t.points)}  "
              + ", ".join(f"{p} ({s})" for p, s in t.packages))
    return 0


if __name__ == "__main__":
    sys.exit(main())
