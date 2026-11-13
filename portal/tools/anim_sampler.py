#!/usr/bin/env python3
"""The value of any animation channel at any frame, the way the game works it out.

Written from the clean-room spec docs/cleanroom/SPEC-005-animation-drawing-renderer.md, sections 1.1 to
1.3, and checked on the game's own files:

* a channel's keys are at whole frames. At a frame the game takes the last key at or before it and the one
  after: before the first key the channel holds its first value, after the last its last;
* between two keys it blends by where the frame falls, unless the channel's Channel Interpolation Mode
  (0x121110) is 0: then it holds the earlier key's value until the next key (a step);
* floats and vectors blend number by number; a Vector1DOF or 2DOF's unmoving numbers are its constants;
* a quaternion blends along the sphere, always the shorter way: when the two keys point into opposite halves
  (their dot product is negative) the second is negated first. Keys that are almost the same (dot above
  0.9995) blend straight, and the result is made length 1 again;
* a colour blends byte by byte; integers blend as if they were floats;
* a Boolean channel has a starting state and keys that each flip it; an Entity channel (a texture's name per
  key) holds the name of the last key at or before the frame;
* a looping animation (cyclic 1) wraps a frame past its end round to the start, a negative one too; one that
  doesn't loop keeps the frame between 0 and its length;
* a group belongs to a joint by name, through the game's name key (p3d.name_key), not by its place.

    anim = Animation(data, chunk)                  # an Animation chunk (0x121000) of a parsed .p3d file
    anim.value("sun_grp", "ROT", 153.5)            # (x, y, z, w)
    anim.frame_at(seconds=2.0)                     # which frame that is, looped or clamped

Standard library only.
"""

from __future__ import annotations

import bisect
import math
import struct
import sys
from pathlib import Path
from typing import Dict, List, Optional, Sequence, Tuple

sys.path.insert(0, str(Path(__file__).resolve().parent))
import p3d  # noqa: E402

ANIMATION, GROUP_LIST, GROUP, INTERPOLATION_MODE = 0x121000, 0x121002, 0x121001, 0x121110
VECTOR_1DOF, VECTOR_2DOF = 0x121102, 0x121103
NEARLY_THE_SAME = 0.9995               # two quaternion keys this alike are blended straight


def slerp(a: Sequence[float], b: Sequence[float], t: float) -> Tuple[float, float, float, float]:
    """From quaternion a to b along the sphere, the shorter way, t from 0 to 1."""
    dot = sum(x * y for x, y in zip(a, b))
    if dot < 0.0:                                            # opposite halves: the same turn, the long way round
        b, dot = [-x for x in b], -dot
    if dot > NEARLY_THE_SAME:
        out = [x + (y - x) * t for x, y in zip(a, b)]
    else:
        angle = math.acos(max(-1.0, min(1.0, dot)))
        s = math.sin(angle)
        wa, wb = math.sin((1.0 - t) * angle) / s, math.sin(t * angle) / s
        out = [x * wa + y * wb for x, y in zip(a, b)]
    length = math.sqrt(sum(x * x for x in out)) or 1.0
    return tuple(x / length for x in out)  # type: ignore[return-value]


class Channel:
    """One channel's keys, and its value at a frame."""

    def __init__(self, data: bytes, chunk: p3d.Chunk) -> None:
        self.kind = chunk.id
        self.parameter, self.frames, self.values = p3d.channel_keys(data, chunk)
        mode = chunk.find(INTERPOLATION_MODE)
        self.steps = bool(mode is not None and not p3d.fields(data, mode).get("interpolate", True))
        self.starts_on: Optional[bool] = None
        self.mapping, self.constants = None, None
        if chunk.id == p3d.BOOLEAN_CHANNEL:
            self.starts_on = p3d.fields(data, chunk)["starts on"]
        elif chunk.id in (VECTOR_1DOF, VECTOR_2DOF):
            info = p3d.fields(data, chunk)
            self.mapping, self.constants = info["mapping"], tuple(info["constants"])

    def _whole(self, value: tuple) -> tuple:
        """A Vector1DOF or 2DOF value with its unmoving numbers put back from the constants."""
        if self.constants is None:
            return value
        moving = [self.mapping] if self.kind == VECTOR_1DOF else [i for i in range(3) if i != self.mapping]
        out = list(self.constants)
        for i, v in zip(moving, value):
            out[i] = v
        return tuple(out)

    def at(self, frame: float):
        """The channel's value at a frame: a tuple of numbers (x, y, z, w for a quaternion; a, r, g, b from 0
        to 255 for a colour), a bool for a Boolean channel, a name for an Entity channel. None if it has no
        keys (a Boolean channel without keys is its starting state)."""
        if self.kind == p3d.BOOLEAN_CHANNEL:
            flips = bisect.bisect_right(self.frames, frame)          # one flip for each key at or before it
            return bool(self.starts_on) != bool(flips % 2)
        if not self.frames:
            return None
        i = bisect.bisect_right(self.frames, frame) - 1              # the last key at or before the frame
        if i < 0:
            return self._shown(self.values[0])
        if i >= len(self.frames) - 1 or self.steps or self.kind == p3d.ENTITY_CHANNEL:
            return self._shown(self.values[i])
        a, b = self.frames[i], self.frames[i + 1]
        t = (frame - a) / (b - a) if b > a else 0.0
        va, vb = self.values[i], self.values[i + 1]
        if self.kind in p3d.QUATERNION_CHANNELS:
            return slerp(va, vb, t)
        return self._whole(tuple(x + (y - x) * t for x, y in zip(va, vb)))

    def _shown(self, value: tuple):
        if self.kind == p3d.ENTITY_CHANNEL:
            return value[0]
        if self.kind in p3d.QUATERNION_CHANNELS:
            return tuple(float(x) for x in value)
        return self._whole(tuple(float(x) for x in value))


def wrap(frame: float, length: float, loops: bool) -> float:
    """The frame the game plays for a frame asked for: wrapped round a looping animation's length (a negative
    one brought back into range), kept between 0 and the length otherwise."""
    if length <= 0.0:
        return 0.0
    if loops:
        return math.fmod(math.fmod(frame, length) + length, length)
    return max(0.0, min(length, frame))


class Animation:
    """An Animation chunk (0x121000): its length, rate and looping, and its groups' channels."""

    def __init__(self, data: bytes, chunk: p3d.Chunk) -> None:
        info = p3d.fields(data, chunk)
        self.name, self.kind = info.get("name", ""), info.get("type", "")
        self.length = float(info.get("frames") or 0.0)               # in frames
        self.rate = float(info.get("frame rate") or 30.0)            # frames a second
        self.loops = info.get("cyclic") == 1
        self.groups: Dict[int, Dict[str, Channel]] = {}              # the group's name key -> parameter -> channel
        self.names: Dict[int, str] = {}
        groups = chunk.find(GROUP_LIST)
        for g in (groups.children if groups else []):
            if g.id != GROUP:
                continue
            name = p3d.fields(data, g).get("name", "")
            key = p3d.name_key(name)
            self.names[key] = name
            channels = self.groups.setdefault(key, {})
            for ch in g.children:
                if ch.id not in p3d.FIELDS or ch.id in (GROUP, INTERPOLATION_MODE):
                    continue
                try:
                    c = Channel(data, ch)
                except (p3d.P3dError, struct.error, IndexError, ValueError, KeyError):
                    continue                                 # a kind with no reader, or cut short: the others still play
                channels.setdefault(c.parameter, c)

    def channel(self, group: str, parameter: str) -> Optional[Channel]:
        return self.groups.get(p3d.name_key(group), {}).get(parameter)

    def frame_at(self, seconds: float) -> float:
        return wrap(seconds * self.rate, self.length, self.loops)

    def value(self, group: str, parameter: str, frame: float):
        """A group's channel at a frame (wrapped or clamped as the animation plays it); None without one."""
        c = self.channel(group, parameter)
        return c.at(wrap(frame, self.length, self.loops)) if c is not None else None


def animations(data: bytes, tree: Optional[List[p3d.Chunk]] = None) -> List[Animation]:
    """Every animation in a .p3d file."""
    tree = p3d.read_tree(data) if tree is None else tree
    return [Animation(data, c) for c in p3d.walk(tree) if c.id == ANIMATION]


def main(argv: Optional[List[str]] = None) -> int:
    import argparse
    ap = argparse.ArgumentParser(description="An animation's values at a frame, as the game plays it.")
    ap.add_argument("file")
    ap.add_argument("--animation", help="its name (the first one otherwise)")
    ap.add_argument("--frame", type=float, default=0.0)
    args = ap.parse_args(argv)
    found = animations(Path(args.file).read_bytes())
    anim = next((a for a in found if not args.animation or a.name.lower() == args.animation.lower()), None)
    if anim is None:
        print("No such animation. This file has:", ", ".join(a.name for a in found) or "none")
        return 1
    print(f"{anim.name}: {anim.length:g} frames at {anim.rate:g} a second, {'loops' if anim.loops else 'plays once'}")
    for key, channels in anim.groups.items():
        for parameter, c in channels.items():
            print(f"  {anim.names[key]} {parameter}: {c.at(wrap(args.frame, anim.length, anim.loops))}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
