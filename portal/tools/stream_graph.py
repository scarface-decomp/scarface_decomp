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
Shell, Detail, ZoneAnimation ...), then two region names and a number whose meaning isn't known. What is
loaded at a place is every package of every trigger whose outline holds it; outside them all, the nearest
trigger's. The coordinates are the map's own: in a glTF export from p3d_gltf.py, Z is mirrored, so ask for
the export's (x, -z). Layouts in docs/FORMATS.md (from the clean-room spec
docs/cleanroom/SPEC-001-lights-sky-streaming.md).

Your own copies, on your own computer; standard library only.
"""

from __future__ import annotations

import argparse
import math
import sys
from dataclasses import dataclass, field
from pathlib import Path
from typing import Dict, List, Sequence, Tuple

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
    regions: List[str] = field(default_factory=list)      # two region names: meaning not known
    flag: int = 0                                         # meaning not known


@dataclass
class Loaded:
    """What is loaded at a place: the triggers that hold it (or, when none does, the nearest one), and
    the packages of them all, each (package, slot) once, in the order the triggers give them."""
    triggers: List[Trigger]
    inside: bool                                          # False: the nearest trigger stands in
    packages: List[Tuple[str, str]]

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


def contains(t: Trigger, x: float, z: float) -> bool:
    """Whether a trigger's outline, on the ground, holds x, z (a point on the outline counts)."""
    if len(t.points) < 3:
        return False
    if distance(t, x, z) <= 1e-6:
        return True
    inside = False
    for (ax, az), (bx, bz) in _edges(t):
        if (az > z) != (bz > z) and x < ax + (z - az) * (bx - ax) / (bz - az):
            inside = not inside
    return inside


def loaded_at(found: Sequence[Trigger], x: float, z: float) -> Loaded:
    """What the game has loaded at x, z (the map's own coordinates): the union of the packages of every
    trigger whose outline holds the point; when none does, the nearest trigger's."""
    hits = [t for t in found if contains(t, x, z)]
    inside = bool(hits)
    if not hits and found:
        hits = [min(found, key=lambda t: distance(t, x, z))]
    seen, union = set(), []
    for t in hits:
        for pair in t.packages:
            if pair not in seen:
                seen.add(pair)
                union.append(pair)
    return Loaded(hits, inside, union)


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description="Show what the stream graph (streamgraph.p3d) loads where.")
    ap.add_argument("file", type=Path, help="art/levels/z04/streamgraph.p3d")
    ap.add_argument("--at", type=float, nargs=2, metavar=("X", "Z"),
                    help="what is loaded at this place (the map's own coordinates)")
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
        x, z = a.at
        got = loaded_at(found, x, z)
        names = ", ".join(f"{t.name} ({t.subzone})" for t in got.triggers)
        print(f"inside {len(got.triggers)} trigger(s): {names}" if got.inside
              else f"inside no trigger; the nearest: {names}")
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
