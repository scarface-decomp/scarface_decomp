#!/usr/bin/env python3
"""A cutscene with everybody in it, as one glTF scene.

The game keeps a cutscene (art/nis/<name>) in three places, all read here from your own copied files:

    art/nis/fsc/<name>.fsc          its script, as text: who is in it (NISResourceLoader: a name for the
                                    scene and the template to load, CharTemp_Cornelius), where each one
                                    stands (NISCharacterPosition: a position and the way they face, in
                                    degrees), which animation each plays (NISCharacterAnimation,
                                    NISVehicleAnimation) and the camera's (NISSequenceCue)
    art/nis/<name>/stream<n>.p3d    the animations, cut into pieces: <animation name>0 in stream0,
                                    <animation name>1 in stream1, and so on, one after the other
    art/characters/..., art/vehicles/...   the models: a person's file is named after the template; a
                                    vehicle's after the one joint its animation moves (sportfishing_boat)

A person's animation moves them from where the script stands them; a vehicle's and the camera's are in
the city's own coordinates. "MainCharacter" is Tony, in the suit the script changes him into
(NISSwapModel: tonynisHawaiianDrawable is art/nis/characters/tonynisHawaiian.p3d). Standard library only.
"""

from __future__ import annotations

import bisect
import math
import re
import struct
from pathlib import Path
from typing import Callable, Dict, List, Optional, Sequence, Tuple

import p3d
import p3d_gltf as G
import cutscene_fx as CFX

ACTION = "Cutscene "                   # the animation's name starts with this (Blender's script looks for it)
TONY = "maincharacter"
# What Tony wears when nothing says: the Hawaiian shirt he has for most of the game.
TONY_FILES = ("tonynishawaiian.p3d", "tonyniswhtsuit.p3d", "tonynisblksuit.p3d")
SUIT = re.compile(r'\b\w+\("(MCP_\w*Tony\w*)"')                 # a mission script changing his clothes
NAMED = re.compile(r"""["']((?:PAL_)?M?NIS_\w+)["']""")           # a cutscene's name anywhere in a script
MISSION = re.compile(r"(?:PAL_)?M?NIS_([A-Za-z]+\d+)", re.I)     # MNIS_S01_0_Tony_in_Chair is mission S01's


def suit_file(outfit: str) -> str:
    """The cutscene model (art/nis/characters) for one of Tony's outfits as the mission scripts name them:
    MCP_BlackSuitTony is tonynisBLKsuit, MCP_HawaiianShadesTony is tonynisHawaiianS. "" for an outfit
    with no cutscene model of its own (MCP_ArmyTony): his everyday model is used for those."""
    m = re.fullmatch(r"MCP_(\w+?)(Shades)?Tony", outfit, re.I)
    if not m:
        return ""
    kind = {"whitesuit": "WHTsuit", "blacksuit": "BLKsuit", "bluesuit": "BLUsuit", "bluepinsuit": "BLUPINsuit",
            "graysuit": "GRYsuit", "hawaiian": "Hawaiian", "sandy": "Sandy"}.get(m.group(1).lower())
    return "tonynis" + kind + ("S" if m.group(2) else "") if kind else ""


def outfits(scripts: Sequence[Tuple[str, str]]) -> Dict[str, str]:
    """What Tony wears in each cutscene the mission scripts tell of: {cutscene (lower, without PAL_): outfit}.
    scripts: (path, decompiled text) of the game's scripts. A script changes his clothes with a call given
    an MCP_...Tony name; a cutscene named in that script after it (or, with none before, before the first)
    has him in those. A cutscene no script dresses takes its mission's first outfit: MNIS_S01_... the first
    one set by the scripts whose names start S01."""
    out: Dict[str, str] = {}
    first: Dict[str, str] = {}                              # mission -> the first outfit its scripts set
    for path, text in sorted(scripts):
        marks = sorted([(m.start(), "suit", m.group(1)) for m in SUIT.finditer(text)]
                       + [(m.start(), "scene", m.group(1)) for m in NAMED.finditer(text)])
        opening = next((v for _at, kind, v in marks if kind == "suit"), "")
        if not opening:
            continue
        stem = re.match(r"[A-Za-z]+\d+", path.replace("\\", "/").rsplit("/", 1)[-1])
        if stem:
            first.setdefault(stem.group(0).lower(), opening)
        wearing = opening
        for _at, kind, v in marks:
            if kind == "suit":
                wearing = v
            else:
                out.setdefault(re.sub(r"^pal_", "", v.lower()), wearing)
    for mission, outfit in first.items():                   # under a key no cutscene's name can be
        out.setdefault("\0" + mission, outfit)
    return out


def outfit_for(wears: Dict[str, str], scene: str) -> str:
    """Tony's outfit in a cutscene, from outfits(): its own, else its mission's, else ""."""
    low = re.sub(r"^pal_", "", scene.lower())
    if low in wears:
        return wears[low]
    m = MISSION.match(low)
    return wears.get("\0" + m.group(1).lower(), "") if m else ""

_BLOCK = re.compile(r"\b(NISResourceLoader|NISCharacterPosition|NISObjectPosition|NISCharacterAnimation|"
                    r"NISVehicleAnimation|NISSequenceCue|NISSwapModel|NISWeaponAttach|NISExpAnimation|"
                    r"NISWeaponFire|NISStatePropState|NISRenderableTrack|NISRenderableAnimationTrack|NISFade|"
                    r"NISCharacterEffect)\s*\{")
_FIELD = re.compile(r'\b(\w+)\s+(?:"([^"]*)"|(-?[\d.]+(?:e-?\d+)?))\s*;')


class Script:
    """What a cutscene's script says: the cast, where they stand, what they play."""

    def __init__(self) -> None:
        self.cast: Dict[str, str] = {}                      # scene name -> template
        self.stands: Dict[str, Tuple[Tuple[float, float, float], float]] = {}     # name (lower) -> position, facing
        self.plays: Dict[str, str] = {}                     # person (lower) -> animation
        self.drives: Dict[str, str] = {}                    # vehicle (lower) -> animation
        self.camera = ""
        self.origin: Optional[Tuple[Tuple[float, float, float], float]] = None   # where the camera's move is set
        self.tony = ""                                      # the suit Tony is changed into (NISSwapModel)
        self.holds: Dict[str, str] = {}                     # person (lower) -> weapon template (NISWeaponAttach)
        self.faces: Dict[str, str] = {}                     # person (lower) -> their face's animation (NISExpAnimation)
        # A weapon is put in a hand at a frame, and another may take its place later; it fires from a frame
        # to a frame; a prop of the map is put in a state at a frame (a door whole, then blown apart).
        self.holds_at: Dict[str, List[Tuple[int, str]]] = {}        # person (lower) -> [(frame, weapon template)]
        # person (lower) -> [(first frame, last frame, alternate fire)]: the fire control held (SPEC-010 section 3.1)
        self.fires: Dict[str, List[Tuple[int, int, bool]]] = {}
        self.prop_states: Dict[str, List[Tuple[int, str]]] = {}     # prop's name in the script -> [(frame, state)]
        # The scene's own props (a cabinet's doors, a glass, a tray): its name for each -> the model in the
        # scene's static.p3d, and the animation that moves it.
        # The screen fading to a colour and back: (frame, frames to fade in, frames held, frames to fade out,
        # (r, g, b) 0 to 1). Effects on people: (person (lower), kind, joint, frame).
        self.fades: List[Tuple[int, int, int, int, Tuple[float, float, float]]] = []
        # (target (lower), effect type, joint, frame, source (lower) or ""): NISCharacterEffect (SPEC-010 section 2)
        self.effects: List[Tuple[str, str, str, int, str]] = []
        self.renderables: Dict[str, str] = {}
        self.renderable_moves: Dict[str, str] = {}
        self.swaps: Dict[str, str] = {}                     # person (lower) -> the cutscene model they are changed
        #                                                     into (NISSwapModel), kept in the scene's static.p3d


def _body(text: str, start: int) -> str:
    """The text of a { } block that opens just before start, inner blocks included."""
    depth, i = 1, start
    while i < len(text) and depth:
        depth += {"{": 1, "}": -1}.get(text[i], 0)
        i += 1
    return text[start:i - 1]


def read_script(text: str) -> Script:
    s = Script()
    for m in _BLOCK.finditer(text):
        body = _body(text, m.end())
        f = {}
        for k, quoted, number in _FIELD.findall(body):
            f.setdefault(k, quoted if number == "" else float(number))
        kind = m.group(1)
        if kind == "NISResourceLoader" and f.get("Name") and f.get("TemplateName"):
            s.cast.setdefault(str(f["Name"]), str(f["TemplateName"]))
        elif kind in ("NISCharacterPosition", "NISObjectPosition"):
            who = str(f.get("CharacterName") or f.get("ObjectName") or "").lower()
            if who and who not in s.stands and all(isinstance(f.get(k), float) for k in "xyz"):
                facing = f.get("Facing")
                s.stands[who] = ((f["x"], f["y"], f["z"]), facing if isinstance(facing, float) else 0.0)
        elif kind == "NISCharacterAnimation" and f.get("CharacterName") and f.get("AnimationName"):
            s.plays.setdefault(str(f["CharacterName"]).lower(), str(f["AnimationName"]))
        elif kind == "NISVehicleAnimation" and f.get("VehicleName") and f.get("AnimationName"):
            s.drives.setdefault(str(f["VehicleName"]).lower(), str(f["AnimationName"]))
        elif kind == "NISExpAnimation" and f.get("CharacterName") and f.get("AnimationName"):
            s.faces.setdefault(str(f["CharacterName"]).lower(), str(f["AnimationName"]))
        elif kind == "NISWeaponAttach" and f.get("CharacterName") and f.get("WeaponTemplateName"):
            s.holds.setdefault(str(f["CharacterName"]).lower(), str(f["WeaponTemplateName"]))
            at = int(f["FrameBegin"]) if isinstance(f.get("FrameBegin"), float) else 0
            got = s.holds_at.setdefault(str(f["CharacterName"]).lower(), [])
            if all(frame != at for frame, _w in got):
                got.append((at, str(f["WeaponTemplateName"])))
                got.sort()
        elif kind == "NISWeaponFire" and f.get("CharacterName") and isinstance(f.get("FrameBegin"), float):
            end = f.get("FrameEnd")
            s.fires.setdefault(str(f["CharacterName"]).lower(), []).append(
                (int(f["FrameBegin"]), int(end) if isinstance(end, float) else int(f["FrameBegin"]) + 6,
                 bool(f.get("IsSecondaryWeapon"))))
        elif kind == "NISFade" and isinstance(f.get("FrameBegin"), float):
            num = lambda k: int(f[k]) if isinstance(f.get(k), float) else 0
            s.fades.append((num("FrameBegin"), num("FadeInFrames"), num("DurationFrames"), num("FadeOutFrames"),
                            tuple(min(1.0, num(c) / 255.0) for c in ("Red", "Green", "Blue"))))
            s.fades.sort()
        elif kind == "NISCharacterEffect" and f.get("CharacterName") and f.get("EffectType"):
            s.effects.append((str(f["CharacterName"]).lower(), str(f["EffectType"]), str(f.get("JointName") or ""),
                              int(f["FrameBegin"]) if isinstance(f.get("FrameBegin"), float) else 0,
                              str(f.get("SourceCharacterName") or "").lower()))
        elif kind == "NISRenderableTrack" and f.get("RenderableName") and f.get("CompositeDrawableName"):
            s.renderables.setdefault(str(f["RenderableName"]), str(f["CompositeDrawableName"]))
        elif kind == "NISRenderableAnimationTrack" and f.get("RenderableName") and f.get("AnimationName"):
            s.renderable_moves.setdefault(str(f["RenderableName"]), str(f["AnimationName"]))
        elif kind == "NISStatePropState" and f.get("StatePropName") and f.get("StateName"):
            at = int(f["FrameBegin"]) if isinstance(f.get("FrameBegin"), float) else 0
            got = s.prop_states.setdefault(str(f["StatePropName"]), [])
            if all(frame != at for frame, _st in got):       # the first to name a frame: the scene's end sets
                got.append((at, str(f["StateName"])))        # every prop to how it is left, at frame 0 again
                got.sort()
        elif kind == "NISSwapModel" and str(f.get("Character", "")).lower() == TONY and f.get("newModel") and not s.tony:
            s.tony = re.sub(r"Drawable$", "", str(f["newModel"]), flags=re.I)
        elif kind == "NISSwapModel" and f.get("Character") and f.get("newModel"):
            s.swaps.setdefault(str(f["Character"]).lower(), str(f["newModel"]))
        elif kind == "NISSequenceCue" and f.get("CameraAnimationName") and not s.camera:
            s.camera = str(f["CameraAnimationName"])
            # A cue with a place of its own: the camera's move is measured from there, not from the map's
            # origin (Tony in his chair: the cue is in the office, the camera's keys a few metres round it).
            if all(isinstance(f.get(k), float) for k in "xyz") and abs(f["x"]) + abs(f["z"]) > 1.0:
                facing = f.get("Facing")
                s.origin = ((f["x"], f["y"], f["z"]), facing if isinstance(facing, float) else 0.0)
    return s


# --------------------------------------------------------------------------- spoken lines (SPEC-009 section 4)

FRAMES_A_SECOND = 30.0
CAPTION_LENGTH = 80
_CALL_TRACK = re.compile(r"\bNISScriptFunctionCallTrack\s*\{")
_LINE_CALL = re.compile(r"SubtitleManager_LocalisedDialogueEvent\(\s*\^([^^]+)\^\s*((?:,\s*-?\d+\s*)*)\)")


def spoken_lines(script: str) -> List[dict]:
    """The lines a cutscene's script puts on screen, in order: [{"name", "frame", "begin", "total",
    "priority"}]. Each is a call on a track: SubtitleManager_LocalisedDialogueEvent( ^nis\\NAME^, begin,
    total ) at a frame of the cutscene. begin and total are milliseconds: when the first caption appears
    after the call, and how long the whole line stays up."""
    out = []
    for m in _CALL_TRACK.finditer(script):
        body = _body(script, m.end())
        call = _LINE_CALL.search(body)
        frame = re.search(r"\bFrameBegin\s+(-?[\d.]+)", body)
        if not call:
            continue
        numbers = [int(n) for n in re.findall(r"-?\d+", call.group(2))]
        out.append({"name": re.sub(r"\\+", r"\\", call.group(1).strip()),          # the file doubles the backslashes
                    "frame": float(frame.group(1)) if frame else 0.0,
                    "begin": numbers[0] if numbers else 0, "total": numbers[1] if len(numbers) > 1 else 0,
                    "priority": numbers[2] if len(numbers) > 2 else 10})
    return sorted(out, key=lambda line: line["frame"])


def line_path(name: str, language: str = "english") -> str:
    """The path a line's subtitle file is named from (media.subtitle_file gives the file)."""
    return f"localised\\{language}\\{name}"


def caption_spans(text: str) -> List[Tuple[int, str, int]]:
    """A line cut into captions the way the game does (SPEC-009 section 4.4, with the examiner's answer of 19
    November 2026): [(speaker number, caption, its length as the game counts it)]. The count runs over the
    text as stored, marks and all. From a caption's first character: the rest of the line is one caption
    when (the stored length - that position + 1) is at most 80 and it has no mark in it; otherwise, among the
    80 characters from there, the first `#` or `@` ends the caption just before it, else the last `.`, `!` or
    `?`, then the last `,` or `;`, then the last space ends it, that character included. The next caption
    starts after it, skipping one `#` or `@` there; a `#` moves to the next speaker. A caption's length (first
    to last character) is what its share of the line's time goes by."""
    out: List[Tuple[int, str, int]] = []
    speaker, pos, n = 0, 0, len(text)
    while pos < n:
        rest = text[pos:]
        if n - pos + 1 <= CAPTION_LENGTH and "#" not in rest and "@" not in rest:
            piece, nxt, mark = rest, n, ""
        else:
            window = text[pos:pos + CAPTION_LENGTH]
            marks = [i for i in (window.find("#"), window.find("@")) if i >= 0]
            if marks:
                cut = min(marks)
                piece, nxt, mark = window[:cut], pos + cut + 1, window[cut]
            else:
                cut = max(window.rfind(ch) for ch in ".!?")
                if cut < 0:
                    cut = max(window.rfind(ch) for ch in ",;")
                if cut < 0:
                    cut = window.rfind(" ")
                cut = cut if cut >= 0 else len(window) - 1
                piece, nxt, mark = window[:cut + 1], pos + cut + 1, ""
                if nxt < n and text[nxt] in "#@":        # a mark right after the cut is skipped too
                    mark, nxt = text[nxt], nxt + 1
        shown = " ".join(piece.split())
        if shown:
            out.append((speaker, shown, len(piece)))
        if mark == "#":
            speaker += 1
        pos = nxt
    return out


def split_line(text: str) -> List[Tuple[int, str]]:
    """A line cut into captions the way the game does: [(speaker number, caption)] (caption_spans)."""
    return [(s, t) for s, t, _n in caption_spans(text)]


def captions(lines: List[dict], entry_of: Callable[[str], Optional[dict]]) -> List[dict]:
    """The captions of a cutscene with their times: [{"start", "end" (seconds from the cutscene's start),
    "speaker", "text", "line"}]. lines: spoken_lines' result; entry_of(name) gives the line's subtitle entry
    (media.subtitle_entries: its text, and its own times where it has them) or None when it has no file.
    A line's captions share its time in proportion to their lengths."""
    out: List[dict] = []
    for line in lines:
        entry = entry_of(line["name"])
        if not entry or not entry.get("text", "").strip():
            continue
        begin = entry.get("begin") or line["begin"]                   # the file's own times replace the script's
        total = entry.get("total") or line["total"]
        parts = caption_spans(entry["text"])
        letters = sum(n for _s, _t, n in parts)
        if not parts or total <= 0 or not letters:
            continue
        at = line["frame"] / FRAMES_A_SECOND + begin / 1000.0
        for speaker, text, count in parts:
            lasts = total / 1000.0 * count / letters
            out.append({"start": round(at, 3), "end": round(at + lasts, 3), "speaker": speaker, "text": text,
                        "line": line["name"]})
            at += lasts
    return out


def srt(caps: List[dict]) -> str:
    """Captions as a SubRip file (.srt), which Blender's sequencer and video players read."""
    def stamp(t: float) -> str:
        ms = int(round(max(t, 0.0) * 1000))
        return f"{ms // 3600000:02d}:{ms // 60000 % 60:02d}:{ms // 1000 % 60:02d},{ms % 1000:03d}"
    blocks = []
    for n, c in enumerate(sorted(caps, key=lambda c: c["start"]), 1):
        blocks.append(f"{n}\n{stamp(c['start'])} --> {stamp(c['end'])}\n{c['text']}\n")
    return "\n".join(blocks)


def scene_name(game_path: str) -> Optional[str]:
    """The cutscene a copied file belongs to (art/nis/<name>.p3d, art/nis/<name>/stream0.p3d,
    art/nis/fsc/<name>.fsc), or None."""
    low = game_path.replace("\\", "/")
    m = re.search(r"(?:^|/)art/nis/(?:fsc/([^/]+)\.fsc|([^/]+)/(?:stream\d+|static)\.p3d|([^/]+)\.p3d)$", low, re.I)
    if not m:
        return None
    name = m.group(1) or m.group(2) or m.group(3)
    return None if name.lower() in ("characters", "fsc") else name


def facing_rotation(degrees: float) -> G.Quat:
    """The way the script faces someone (a turn about the upright axis, in degrees), as glTF's rotation."""
    a = math.radians(degrees) / 2
    return G.rot((0.0, math.sin(a), 0.0, math.cos(a)))


FLASH_EVERY = 3                                              # frames from one shot's flash to the next
FLASH = 0.14                                                 # metres: half the width of a muzzle flash


def _flash_mesh(b: G.Builder) -> int:
    """A muzzle flash: two crossed squares that add their yellow light, made once for a scene. The game
    draws a particle effect there; this stands in for it, at the frames the script fires the gun."""
    made = getattr(b, "_flash", None)
    if made is None:
        f = FLASH
        corners = [(-f, -f, 0.0), (f, -f, 0.0), (f, f, 0.0), (-f, f, 0.0), (0.0, -f, -f), (0.0, -f, f), (0.0, f, f), (0.0, f, -f)]
        material = b.g.add("materials", {"name": "muzzle flash", "doubleSided": True, "alphaMode": "BLEND",
                                         "pbrMetallicRoughness": {"baseColorFactor": [1.0, 0.85, 0.35, 0.9]},
                                         "emissiveFactor": [1.0, 0.8, 0.3], "extensions": {"KHR_materials_unlit": {}},
                                         "extras": {"blend": "add", "depthWrite": False}})
        b.g.used_extensions.add("KHR_materials_unlit")
        made = b.g.add("meshes", {"name": "muzzle flash", "primitives": [{
            "attributes": {"POSITION": b.g.accessor(corners, "VEC3", bounds=True)},
            "indices": b.g.accessor([0, 1, 2, 0, 2, 3, 4, 5, 6, 4, 6, 7], "SCALAR", 5123), "material": material, "mode": 4}]})
        b._flash = made                                      # type: ignore[attr-defined]
    return made


# What the game's effects look like, in stand-in form: (half-size in metres, frames shown, colour, adds light).
# The game draws particle systems; these mark the place and the frames the script gives them.
EFFECTS = {"GoreBloodExplosion": (0.22, 10, (0.55, 0.02, 0.02, 0.9), False),
           "ShotEffectHeavy": (0.1, 6, (0.5, 0.03, 0.03, 0.85), False),
           "ShotEffectLight": (0.06, 5, (0.5, 0.03, 0.03, 0.8), False),
           "GrenadeExplosion": (1.4, 20, (1.0, 0.55, 0.15, 0.9), True)}


def _effect_look(kind: str) -> Tuple[float, int, Tuple[float, float, float, float], bool]:
    if kind in EFFECTS:
        return EFFECTS[kind]
    low = kind.lower()
    if "explo" in low or "fire" in low:
        return EFFECTS["GrenadeExplosion"]
    if "blood" in low or "gore" in low or "shot" in low:
        return EFFECTS["ShotEffectHeavy"]
    return (0.12, 8, (0.8, 0.8, 0.8, 0.6), True)


def _effect_mesh(b: G.Builder, kind: str) -> int:
    """A burst for an effect: three crossed squares of its colour, made once for each look in a scene."""
    size, _frames, rgba, add = _effect_look(kind)
    return _burst_mesh(b, size, rgba, add, kind)


def _burst_mesh(b: G.Builder, size: float, rgba, add: bool, kind: str = "effect") -> int:
    made = getattr(b, "_effects", None)
    if made is None:
        made = b._effects = {}                               # type: ignore[attr-defined]
    key = (size, rgba, add)
    if key not in made:
        f = size
        corners = [(-f, -f, 0.0), (f, -f, 0.0), (f, f, 0.0), (-f, f, 0.0), (0.0, -f, -f), (0.0, -f, f), (0.0, f, f),
                   (0.0, f, -f), (-f, 0.0, -f), (f, 0.0, -f), (f, 0.0, f), (-f, 0.0, f)]
        extras = {"blend": "add", "depthWrite": False} if add else {"blend": "alpha", "depthWrite": False}
        material = b.g.add("materials", {"name": kind, "doubleSided": True, "alphaMode": "BLEND",
                                         "pbrMetallicRoughness": {"baseColorFactor": list(rgba)},
                                         "extensions": {"KHR_materials_unlit": {}}, "extras": extras})
        b.g.used_extensions.add("KHR_materials_unlit")
        made[key] = b.g.add("meshes", {"name": kind, "primitives": [{
            "attributes": {"POSITION": b.g.accessor(corners, "VEC3", bounds=True)},
            "indices": b.g.accessor([0, 1, 2, 0, 2, 3, 4, 5, 6, 4, 6, 7, 8, 9, 10, 8, 10, 11], "SCALAR", 5123),
            "material": material, "mode": 4}]})
    return made[key]


PLACED = re.compile(rb"\x00(\w+)\x00(-?[\d.]+) (-?[\d.]+) (-?[\d.]+) (-?[\d.]+) (-?[\d.]+) (-?[\d.]+) [\d.]+ [\d.]+ [\d.]+ \d+ \w+\x00")


def _prop_states(b: G.Builder, lib: G.Library, script: Script, tracks: _Tracks, later, near,
                 fx: Optional[CFX.Effects] = None) -> List[str]:
    """The map's props the script puts in a state at a frame (NISStatePropState: the office doors whole,
    then blown apart), each state there for its frames. The script names a prop its own way ("OfficeDoors",
    "Railing"); the prop is the placed one whose model or one of whose joints has that name in it, the
    nearest to the scene. A prop the map places from a line of text in a script kept in its file
    (model, then "x y z, turn in degrees, size, a number, state") is read from there. Returns the props
    it could not find."""
    lost = []
    doc = b.g.doc
    for wanted, when in script.prop_states.items():
        key = re.sub(r"s$", "", re.sub(r"[^a-z0-9]", "", wanted.lower()))
        found = []                                           # (distance, model ref, parent, translation, rotation, scale, old node)
        for src in lib.sources:
            for c in src.chunks:
                if c.id != G.COMPOSITE:
                    continue
                name = G.chunk_name(src.data, c)
                skeleton = next((k for k in src.chunks if k.id == 0x23000 and G.chunk_name(src.data, k) == name), None)
                joints = [G.chunk_name(src.data, j) for j in (skeleton.children if skeleton else []) if j.id == 0x23001]
                if not any(key in re.sub(r"[^a-z0-9]", "", n.lower()) for n in [name] + joints):
                    continue
                ref = G.Ref(src, c)
                if len(b.states_of(ref, name)) < 2:
                    continue
                for i, n in enumerate(doc["nodes"]):          # placed the usual way: its node is in the scene
                    if (n.get("name") or "").lower() == name.lower() and "translation" in n and "mesh" not in n:
                        parent = next((p for p, q in enumerate(doc["nodes"]) if i in q.get("children", [])), None)
                        if parent is not None:
                            found.append((ref, parent, n["translation"], n.get("rotation"), n.get("scale"), i))
                for other in lib.sources:                     # placed from a line of text
                    for m in PLACED.finditer(other.data):
                        if m.group(1).decode("latin-1").lower() == name.lower():
                            x, y, z, _rx, ry, _rz = (float(v) for v in m.groups()[1:])
                            found.append((ref, None, list(G.pos((x, y, z))), list(facing_rotation(ry)), None, None))
        if not found:
            lost.append(wanted)
            continue
        if near is not None:
            found.sort(key=lambda f: (f[2][0] - near[0]) ** 2 + (f[2][2] - near[2]) ** 2)
        ref, parent, at, turn, size, old = found[0]
        name = G.chunk_name(ref.data, ref.chunk)
        states = [s.lower() for s, _shown in b.states_of(ref, name)]
        effects = _state_effects(b, ref, name)
        if old is not None:
            doc["nodes"][parent]["children"].remove(old)     # the one the map put there, in one state for good
        home = b.g.node(wanted + " (" + name + ")", parent, translation=at, rotation=turn, scale=size)
        for n, (frame, state) in enumerate(when):
            if state.lower() not in states:
                continue
            top = b.g.node(name + " (" + state + ")", home)
            b.composite(ref, top, name + " " + state, state=states.index(state.lower()))
            until = when[n + 1][0] if n + 1 < len(when) else None
            times, sizes = ([0.0], [GONE]) if frame > 0 else ([], [])
            times, sizes = times + [frame / FRAMES_A_SECOND], sizes + [(1.0, 1.0, 1.0)]
            if until is not None:
                times, sizes = times + [until / FRAMES_A_SECOND], sizes + [GONE]
            if len(times) > 1:
                tracks.add(top, "scale", later(times), sizes, step=True)
            # what the game sets off as the prop enters the state: the blast, wood flying, smoke, fire
            for k, (kind, at_, size_, begin, joint, angles) in enumerate(
                    effects.get(state.lower(), []) if frame > 0 or n > 0 else []):
                first = frame + int(round(begin * FRAMES_A_SECOND))
                if until is not None and until <= first:
                    continue
                anchor = _joint_under(b.g.doc, top, joint) if joint else top
                place = b.g.node(kind + " (" + wanted + ")", anchor, translation=list(G.pos(at_)),
                                 rotation=list(CFX.angles_turn(angles)), extras={"effect": kind})
                if fx is not None and fx.systems_of(kind):
                    # the game's own particles; a looping one (fire) until the prop leaves the state
                    fx.play(kind, place, first, tracks, later, size=size_ or 1.0, seed=n + k,
                            frames=(until - first) if until is not None else None)
                    continue
                look = _prop_effect_look(kind, size_)                  # without the effects file: a card
                b.g.doc["nodes"][place]["mesh"] = _burst_mesh(b, *look[:3])
                last = first + look[3] if until is None else min(until, first + look[3])
                tracks.add(place, "scale", later([0.0, first / FRAMES_A_SECOND, last / FRAMES_A_SECOND]),
                           [GONE, (1.0, 1.0, 1.0), GONE], step=True)
    return lost


def fade_keys(fade_in: int, hold: int, fade_out: int, rgb: Sequence[float]) -> List[Tuple[int, float]]:
    """An NISFade as (frames from its start, how much of the colour covers the screen) with straight lines
    between (SPEC-010 section 5). A black fade with no hold is the scene's end (longer in than out: to black
    over the fade-in, and it stays) or its start (black, clearing over the fade-out). Any other fade goes to
    its colour over the fade-in, holds (for ever when the hold is negative), and clears over the fade-out."""
    if not any(rgb) and hold <= 0:
        if fade_in > fade_out:
            return [(0, 0.0), (fade_in, 1.0)]
        return [(0, 1.0), (fade_out, 0.0)]
    keys = [(0, 0.0 if fade_in > 0 else 1.0), (fade_in, 1.0)]
    if hold >= 0:
        keys += [(fade_in + hold, 1.0), (fade_in + hold + fade_out, 0.0)]
    return [k for i, k in enumerate(keys) if i == 0 or k != keys[i - 1]]


def _gun_fire(b: G.Builder, fx: Optional[CFX.Effects], gref: G.Ref, wanted: str, grip: int,
              muzzle: Optional[Sequence[float]], shots: Sequence[Tuple[int, int, bool]], rate: float, tracks: _Tracks,
              later, label: str, tracer_every: int = CFX.TRACER_EVERY) -> None:
    """A held gun's shots (SPEC-010 section 3.2). Without the effects file, a stand-in flash at the muzzle."""
    states = _state_effects(b, gref, wanted)
    tracer_ref = b.lib.find("composite", CFX.TRACER)
    anchors: Dict[Tuple[str, int], int] = {}
    tracer_times: List[float] = [0.0]
    tracer_sizes: List[tuple] = [GONE]
    bullet = 0
    played = 0
    for a, z, alt in sorted(shots):
        # alternate fire plays "fire2"; a gun without one (an Uzi: the cutscenes' gunmen all fire this way, and
        # are seen firing) plays its "fire1"
        effects = states.get("fire2", []) if alt else []
        launcher = bool(effects)
        effects = effects or states.get("fire1", [])
        # the grenade launcher: one grenade a press (its rate isn't known: asked in SPEC-010)
        frames = [float(a)] if launcher else CFX.shot_frames(a, z, rate)
        for k, f0 in enumerate(frames):
            bullet += 1
            # each shot enters the state again: this shot's effects start, and the last shot's wind down
            # (SPEC-010 section 1.10); the last shot's go on until the trigger is let go
            until = (frames[k + 1] if k + 1 < len(frames) else max(float(z), f0 + 1.0)) - f0
            for e, (kind, at, size, begin, joint, angles) in enumerate(effects):
                if fx is None or not fx.systems_of(kind):
                    continue
                if (kind, e) not in anchors:
                    anchors[(kind, e)] = b.g.node(label + "'s " + kind, _joint_under(b.g.doc, grip, joint) if joint else grip,
                                                  translation=list(G.pos(at)), rotation=list(CFX.angles_turn(angles)),
                                                  extras={"effect": kind})
                fx.play(kind, anchors[(kind, e)], f0 + begin * FRAMES_A_SECOND, tracks, later, size=size or 1.0,
                        seed=bullet, label=kind + " (shot " + str(bullet) + ")", frames=until - begin * FRAMES_A_SECOND)
                played += 1
            if tracer_ref is not None and effects and bullet % tracer_every == 0:
                tracer_times += [f0 / FRAMES_A_SECOND, (f0 + 1) / FRAMES_A_SECOND]
                tracer_sizes += [(1.0, 1.0, 1.0), GONE]
    if played and tracer_ref is not None and len(tracer_times) > 1:
        at = muzzle if muzzle is not None else (0.0, 0.0, 0.0)
        tracer = b.g.node(label + "'s tracers", grip, translation=list(at), extras={"effect": CFX.TRACER})
        b.composite(tracer_ref, tracer, label + "'s tracer")
        tracks.add(tracer, "scale", later(tracer_times), tracer_sizes, step=True)
    if played:
        return
    at = muzzle if muzzle is not None else (0.0, 0.0, 0.0)              # no effects file: a stand-in flash
    flash = b.g.node(label + "'s muzzle flash", grip, translation=list(at), mesh=_flash_mesh(b), extras={"effect": "flash"})
    times, sizes = [0.0], [GONE]
    for a, z, _alt in sorted(shots):
        for f0 in CFX.shot_frames(a, z, rate):
            times += [f0 / FRAMES_A_SECOND, (f0 + 1) / FRAMES_A_SECOND]
            sizes += [(1.0, 1.0, 1.0), GONE]
    tracks.add(flash, "scale", later(times), sizes, step=True)


def _in_scene(doc: dict, pose: tuple, joint: str, t: float) -> Optional[Tuple[G.Vec3, G.Quat]]:
    """A joint of someone in the scene's space at a time (seconds): their skeleton's pose put on their spot."""
    copy, keys, stand, turn = pose
    got = joint_world(doc, copy, keys, joint, t)
    if got is None:
        return None
    at, q = got
    moved = _qturn(turn, at)
    return (stand[0] + moved[0], stand[1] + moved[1], stand[2] + moved[2]), _qmul(turn, q)


def _character_effect(b: G.Builder, fx: Optional[CFX.Effects], root: int, bodies: Dict[str, G.SkeletonCopy],
                      poses: Dict[str, tuple], who: str, kind: str, joint: str, frame: int, by: str, tracks: _Tracks,
                      later, start: float, length: float) -> None:
    """An NISCharacterEffect (SPEC-010 section 2): the type's particles at the joint (the head for a
    headshot), turned to spray away from the source's neck; a blood pool, a growing decal under them."""
    body = bodies.get(who)
    if body is None:
        return
    found = CFX.character_effect(kind)
    system, size = found if found is not None else (None, 1.0)
    if found is not None and system is None:                 # a blood pool, under them, on their floor
        pose = poses.get(who)
        place = _in_scene(b.g.doc, pose, "pelvis", frame / FRAMES_A_SECOND) if pose else None
        if place is None:
            return
        floor = pose[2][1]
        pool = b.g.node("blood pool under " + who, root, translation=[place[0][0], floor + 0.01, place[0][2]],
                        mesh=CFX.pool_mesh(b), scale=list(GONE), extras={"effect": kind})
        times, sizes = CFX.pool_keys(frame)
        tracks.add(pool, "scale", later(times), sizes)
        return
    wanted = CFX.HEADSHOT_JOINT if found is not None and system == "fxSys_Blood_HeadshotShape" else joint.lower()
    node = body.nodes.get(wanted)
    if node is None:                                         # a joint this model doesn't have: the chest
        node = body.nodes.get("spine_2") or next(iter(body.nodes.values()), None)
        wanted = "spine_2"
    if node is None:
        return
    turn = None
    if by and by in poses and who in poses:                  # away from the shooter (section 2.2)
        t = frame / FRAMES_A_SECOND
        # from the shooter's neck (a model without one: its head, else its root)
        source = next((got for got in (_in_scene(b.g.doc, poses[by], j, t) for j in (CFX.SOURCE_JOINT, "head", "root"))
                       if got is not None), None)
        target = _in_scene(b.g.doc, poses[who], wanted, t)
        if source is not None and target is not None:
            way = tuple(c - d for c, d in zip(target[0], source[0]))
            if sum(c * c for c in way) > 1e-8:
                jq = target[1]
                turn = _qmul((-jq[0], -jq[1], -jq[2], jq[3]), CFX.facing(way))
    if fx is not None and system and fx.systems_of(system):
        # the game plays it again only once the last one has ended: while that one lives, it is only moved
        # (SPEC-010 section 1.9), so a hit that comes while the last is still spraying adds nothing new
        alive = getattr(b, "_alive_fx", None)
        if alive is None:
            alive = b._alive_fx = {}                         # type: ignore[attr-defined]
        key = (id(body), system.lower())
        when = start * FRAMES_A_SECOND + frame
        if alive.get(key, -1.0) > when:
            return
        place = b.g.node(kind + " on " + who, node, rotation=list(turn) if turn else None, extras={"effect": kind})
        fx.play(system, place, frame, tracks, later, size=size, seed=frame)
        alive[key] = when + fx.last_end
        return
    sz, frames, _rgba, _add = _effect_look(kind)                # without the effects file: a card
    burst = b.g.node(kind + " on " + who, node, mesh=_effect_mesh(b, kind), extras={"effect": kind})
    times = [0.0, frame / FRAMES_A_SECOND, (frame + frames) / FRAMES_A_SECOND] if frame > 0 else \
        [0.0, frames / FRAMES_A_SECOND]
    sizes = [GONE, (1.0, 1.0, 1.0), GONE] if frame > 0 else [(1.0, 1.0, 1.0), GONE]
    tracks.add(burst, "scale", later(times), sizes, step=True)


def _joint_under(doc: dict, top: int, joint: str) -> int:
    """The node of a joint under a placed prop or gun (by name, letter case aside), else the top."""
    todo, want = [top], joint.lower()
    while todo:
        i = todo.pop()
        if (doc["nodes"][i].get("name") or "").lower() == want:
            return i
        todo += doc["nodes"][i].get("children", [])
    return top


def _state_effects(b: G.Builder, ref: G.Ref, name: str) -> Dict[str, List[Tuple[str, tuple, float, float, str, tuple]]]:
    """{state (lower): [(effect name, offset from its joint, size, start in seconds, joint, angles)]}: the Prop
    State Effects (0x0802000B) of each of a prop's states (SPEC-009 section 2.5: the last float is when it
    starts; SPEC-010 section 1.10: the size multiplies the particles' size, offset and angles place it)."""
    data = b.prop_data(ref, name)
    out: Dict[str, List[Tuple[str, tuple, float, float, str, tuple]]] = {}
    if data is None:
        return out
    for st in data.chunk.children:
        if st.id != G.PROP_STATE:
            continue
        state = (p3d.fields(data.data, st).get("name") or "").lower()
        for e in st.children:
            if e.id == 0x0802000B:
                f = p3d.fields(data.data, e)
                if f.get("kind") == "Effect" and f.get("effect"):
                    out.setdefault(state, []).append((str(f["effect"]), tuple(f.get("offset") or (0, 0, 0)),
                                                      float(f.get("size") or 1.0), float(f.get("value") or 0.0),
                                                      str(f.get("joint") or ""), tuple(f.get("angles") or (0, 0, 0))))
    return out


def _prop_effect_look(kind: str, size: float) -> Tuple[float, Tuple[float, float, float, float], bool, int]:
    """A prop's effect as a stand-in: (half-size, colour, adds light, frames shown)."""
    low = kind.lower()
    if "fire" in low:
        return 0.35 * size, (1.0, 0.45, 0.1, 0.85), True, 10 * 30 if "stop" in low else 60 * 30
    if "smoke" in low:
        return 0.8 * size, (0.35, 0.35, 0.35, 0.45), False, 8 * 30 if "linger" in low else 3 * 30
    if "explo" in low or "grenade" in low:
        return 1.0 * size, (1.0, 0.6, 0.2, 0.9), True, 20
    if "debris" in low or "spark" in low:
        return 0.4 * size, (0.45, 0.32, 0.2, 0.9) if "spark" not in low else (1.0, 0.85, 0.4, 0.9), "spark" in low, 15
    return 0.3 * size, (0.8, 0.8, 0.8, 0.6), True, 15


ROOTS = ("motion_root", "balance_root", "character_root")
STANDS_IN = 0.5                                              # metres along the ground: a scene's prop this near
STANDS_IN_HEIGHT = 2.0                                       # a map's prop (and this near in height) replaces it


def _hide_map_props_at(b: G.Builder, copy) -> int:
    """Takes out the map's placed props that a scene's own prop stands in for: the mansion's gun cabinet
    has closed doors of its own (tmDoorGun, one state), and the scene brings doors that open in the same
    place. A placed prop goes when one of the scene prop's joints is within STANDS_IN of it along the
    ground and STANDS_IN_HEIGHT in height (the cabinet's doors hang 1.3 m below the cabinet's own origin). Returns how
    many went."""
    doc = b.g.doc
    parent = {c: i for i, n in enumerate(doc["nodes"]) for c in n.get("children", [])}

    def place(i: int) -> Tuple[float, float, float]:
        x = y = z = 0.0
        while True:
            t = doc["nodes"][i].get("translation") or (0.0, 0.0, 0.0)
            x, y, z = x + t[0], y + t[1], z + t[2]
            if i not in parent:
                return x, y, z
            i = parent[i]
    spots = [place(i) for i in copy.nodes.values()]
    spots = [p for p in spots if abs(p[0]) + abs(p[2]) > 1.0]
    gone = 0
    for g, n in enumerate(doc["nodes"]):
        if not (n.get("name") or "").endswith(" instances"):
            continue
        for kid in list(n.get("children", [])):
            t = doc["nodes"][kid].get("translation")
            if t and any(math.hypot(t[0] - p[0], t[2] - p[2]) < STANDS_IN and abs(t[1] - p[1]) < STANDS_IN_HEIGHT
                         for p in spots):
                n["children"].remove(kid)
                # out of the scene, and marked hidden too: an importer that brings in every node keeps it off
                doc["nodes"][kid].setdefault("extras", {})["hidden"] = True
                gone += 1
    return gone


MISSION_FOLDER = re.compile(r"/scriptc/missionscripts/([^/]+)/[^/]+$")
STAGE = re.compile(r"m?nis_[a-z]+\d+[a-z]?_(\d+)_")
MOST = 12                                                    # a mission's film: this many cutscenes at most


def mission_films(scripts: Sequence[Tuple[str, str]], known: Dict[str, str]) -> Dict[str, List[str]]:
    """{mission: its cutscenes, in the order its scripts first name them}, for a mission with at least
    two. scripts: (path, decompiled text) of the copied scripts; known: {cutscene name (lower): its name}.
    The mission's functions script is read first (it plays them as the mission goes), then its other
    files. A cutscene's second version (<name>_Alt, played instead of it) is left out when the first is
    there, and so is a copy for European televisions. The order is the stages in their names, then the
    order the script names them: not a record of a played mission, and two endings of one mission
    (the daughter killed, the daughter rescued) both come."""
    by: Dict[str, List[Tuple[str, str]]] = {}
    label: Dict[str, str] = {}
    for path, text in scripts:
        m = MISSION_FOLDER.search(path.replace("\\", "/"))
        if m:
            by.setdefault(m.group(1).lower(), []).append((path, text))
            label.setdefault(m.group(1).lower(), Path(path.replace("\\", "/")).parent.name)
    films: Dict[str, List[str]] = {}
    for mission, files in by.items():
        files.sort(key=lambda f: ("functions" not in f[0].lower(), f[0].lower()))
        seen: List[str] = []
        for _path, text in files:
            for name in NAMED.findall(text):
                low = re.sub(r"^pal_", "", name.lower())
                if low in known and low not in seen:
                    seen.append(low)
        seen = [s for s in seen if not (s.endswith("_alt") and s[:-4] in seen)]
        # A mission's cutscenes carry their stage in their names (MNIS_A51a_0_..., _2_..., _3_...): by
        # that first, and the order the script names them within a stage; ones without a stage (a way
        # to die, MNIS_AMB_...) after them.
        stage = {s: int(m.group(1)) for s in seen for m in [STAGE.match(s)] if m}
        seen.sort(key=lambda s: (s not in stage, stage.get(s, 0)))
        if len(seen) >= 2:
            films[label[mission].upper()] = [known[s] for s in seen[:MOST]]
    return films
SUNK = 0.08                                                  # deeper in the floor than this (metres): on purpose


def _first_step(keys: Dict[str, Dict[str, Tuple[List[float], List[tuple]]]], facing: G.Quat) -> Tuple[float, float]:
    """How far from their spot an animation's first pose puts someone, along the ground (x, z): the root
    joints' first positions, turned the way the person faces."""
    x = z = 0.0
    for joint, paths in keys.items():
        if joint.lower() in ROOTS and paths.get("translation") and paths["translation"][1]:
            first = paths["translation"][1][0]
            x += first[0]
            z += first[2]
    qx, qy, qz, qw = facing                                   # a turn about the upright axis
    s, c = 2 * qw * qy, 1 - 2 * qy * qy
    return c * x + s * z, -s * x + c * z


def _pieces(b: G.Builder, name: str) -> List[G.Ref]:
    """An animation's pieces in order: <name>0, <name>1, ... (or <name> itself when it isn't cut up)."""
    found, n = [], 0
    while True:
        ref = b.find_animation(f"{name}{n}")
        if ref is None:
            break
        found.append(ref)
        n += 1
    whole = b.find_animation(name)
    return found or ([whole] if whole else [])


class _Tracks:
    """One glTF animation gathering every actor's channels."""

    def __init__(self, b: G.Builder) -> None:
        self.b, self.channels, self.samplers = b, [], []

    def add(self, node: int, path: str, times: List[float], values: List[tuple], step: bool = False) -> None:
        keep_t, keep_v, last = [], [], -1.0
        for t, v in zip(times, values):
            if t > last + 1e-6:
                keep_t.append(t)
                keep_v.append(v)
                last = t
        if not keep_t:
            return
        if path == "rotation":                              # the short way round from each key to the next
            for i in range(1, len(keep_v)):
                if sum(a * c for a, c in zip(keep_v[i], keep_v[i - 1])) < 0:
                    keep_v[i] = tuple(-a for a in keep_v[i])
        kind = "VEC4" if path == "rotation" else "VEC3"
        self.samplers.append({"input": self.b.g.accessor([(t,) for t in keep_t], "SCALAR", bounds=True),
                              "output": self.b.g.accessor(keep_v, kind), "interpolation": "STEP" if step else "LINEAR"})
        self.channels.append({"sampler": len(self.samplers) - 1, "target": {"node": node, "path": path}})

    def weights(self, node: int, times: List[float], rows: List[List[float]]) -> None:
        """How far a mesh's shapes are on at each time (glTF: every shape's weight, key after key)."""
        if not times:
            return
        flat = [w for row in rows for w in row]
        self.samplers.append({"input": self.b.g.accessor([(t,) for t in times], "SCALAR", bounds=True),
                              "output": self.b.g.accessor(flat, "SCALAR"), "interpolation": "LINEAR"})
        self.channels.append({"sampler": len(self.samplers) - 1, "target": {"node": node, "path": "weights"}})


def slider_keys(pieces: Sequence[G.Ref]) -> Dict[str, Tuple[List[float], List[float]]]:
    """A face animation's sliders over its pieces laid end to end: {slider (lower): (times, values)}. Each
    slider is an animation group named after it, with one Float1 channel (0x121100)."""
    out: Dict[str, Tuple[List[float], List[float]]] = {}
    start = 0.0
    for ref in pieces:
        data, c = ref.data, ref.chunk
        info = p3d.fields(data, c)
        rate = info.get("frame rate") or 30.0
        gl = c.find(G.ANIM_GROUP_LIST)
        for gc in (gl.children if gl else []):
            if gc.id != G.ANIM_GROUP:
                continue
            name = p3d.fields(data, gc).get("name", "").lower()
            for ch in gc.children:
                if ch.id != 0x121100:
                    continue
                try:
                    _param, frames, values = p3d.channel_keys(data, ch)
                except (p3d.P3dError, struct.error, IndexError, KeyError):
                    continue
                times, kept = out.setdefault(name, ([], []))
                for f, v in zip(frames, values):
                    t = start + f / rate
                    if not times or t > times[-1] + 1e-6:
                        times.append(t)
                        kept.append(v[0])
        start += (info.get("frames") or 0.0) / rate
    return out


def _value_at(times: List[float], values: List[float], t: float) -> float:
    if not times or t <= times[0]:
        return values[0] if values else 0.0
    if t >= times[-1]:
        return values[-1]
    i = bisect.bisect_right(times, t)
    a, b = times[i - 1], times[i]
    return values[i - 1] + (values[i] - values[i - 1]) * ((t - a) / (b - a) if b > a else 0.0)


def shape_weights(sliders: Sequence[Tuple[str, List[Tuple[float, int]]]], count: int,
                  keys: Dict[str, Tuple[List[float], List[float]]]) -> Tuple[List[float], List[List[float]]]:
    """How far each of a mesh's shapes is on through a face animation: (times, a row of count weights per
    time). A slider's shape is fully on when the slider is at the shape's value (a lip slider at -1 is
    all the way down, at 1 all the way up), and off at 0 or on the other side."""
    times = sorted({t for name, _k in sliders for t in keys.get(name.lower(), ([], []))[0]})
    rows = []
    for t in times:
        row = [0.0] * count
        for name, ends in sliders:
            got = keys.get(name.lower())
            if not got:
                continue
            at = _value_at(got[0], got[1], t)
            for value, shape in ends:
                if 0 <= shape < count and value:
                    row[shape] = max(0.0, min(1.0, at / value))
        rows.append(row)
    return times, rows


def _length(pieces: Sequence[G.Ref]) -> float:
    """How long an animation's pieces run, laid end to end (seconds)."""
    total = 0.0
    for ref in pieces:
        info = p3d.fields(ref.data, ref.chunk)
        total += (info.get("frames") or 0.0) / (info.get("frame rate") or 30.0)
    return total


def _joint_keys(pieces: Sequence[G.Ref]) -> Tuple[Dict[str, Dict[str, Tuple[List[float], List[tuple]]]], float]:
    """{joint (lower): {"translation"|"rotation": (times, values)}} over an animation's pieces laid end to
    end, and how long they run together (seconds)."""
    out: Dict[str, Dict[str, Tuple[List[float], List[tuple]]]] = {}
    start = 0.0
    for ref in pieces:
        data, c = ref.data, ref.chunk
        info = p3d.fields(data, c)
        rate = info.get("frame rate") or 30.0
        gl = c.find(G.ANIM_GROUP_LIST)
        for gc in (gl.children if gl else []):
            if gc.id != G.ANIM_GROUP:
                continue
            joint = p3d.fields(data, gc).get("name", "").lower()
            for ch in gc.children:
                try:
                    if ch.id in p3d.QUATERNION_CHANNELS:
                        _param, frames, values = p3d.channel_keys(data, ch)
                        path, vals = "rotation", [G.rot(v) for v in values]
                    elif ch.id in G.VECTOR_CHANNELS:
                        param, frames, values = G._vector_keys(data, ch)
                        if param not in ("TRAN", "TRA"):
                            continue
                        path, vals = "translation", [G.pos(v) for v in values]
                    else:
                        continue
                except (p3d.P3dError, struct.error, IndexError, KeyError):
                    continue
                times, kept = out.setdefault(joint, {}).setdefault(path, ([], []))
                times += [start + f / rate for f in frames]
                kept += vals
        start += (info.get("frames") or 0.0) / rate
    return out, start


def _camera_keys(pieces: Sequence[G.Ref]) -> Dict[str, Tuple[List[float], List[tuple]]]:
    """The camera's place and the way it looks over the pieces: {"translation"|"rotation": (times, values)}."""
    out: Dict[str, Tuple[List[float], List[tuple]]] = {"translation": ([], []), "rotation": ([], [])}
    start = 0.0
    for ref in pieces:
        data, c = ref.data, ref.chunk
        info = p3d.fields(data, c)
        rate = info.get("frame rate") or 30.0
        keys: Dict[str, Tuple[List[int], List[tuple]]] = {}
        for ch in p3d.walk(c.children):
            if ch.id in G.VECTOR_CHANNELS:
                try:
                    param, frames, vals = G._vector_keys(data, ch)
                except (p3d.P3dError, struct.error, IndexError, KeyError):
                    continue
                if frames:
                    keys[param] = (frames, vals)
        if "TRAN" in keys:
            frames, vals = keys["TRAN"]
            out["translation"][0].extend(start + f / rate for f in frames)
            out["translation"][1].extend(G.pos(v) for v in vals)
        if "LOOK" in keys:
            look = keys["LOOK"]
            up = keys.get("UP", ([0], [(0.0, 1.0, 0.0)]))
            for f in sorted(set(look[0]) | set(up[0])):
                out["rotation"][0].append(start + f / rate)
                out["rotation"][1].append(G.camera_rotation(G._at(*look, f), G._at(*up, f)))
        start += (info.get("frames") or 0.0) / rate
    return out


HAND = "right_hand_attach"             # the joint a person's weapon hangs on
# A weapon's model has its grip at its own origin, its barrel along its own forward axis (its muzzle joint
# says so) and its top upwards. A handgun hangs on the hand joint just as its model lies. A long gun lies
# another way round: the barrel along the hand joint's sideways axis, towards the fingers, and its top
# along the joint's forward axis. Measured from the cutscenes: someone with a rifle keeps the palm of the
# other hand a fixed 0.28 to 0.43 m along that sideways axis from the hand joint (a rifle's length from grip
# to handguard), with the world's "up" close to the joint's forward axis; someone with a pistol brings the
# joint's forward axis, not its sideways one, to bear on the people around.
GRIP = (0.5, -0.5, -0.5, 0.5)                                    # a long gun's turn, as glTF's rotation
LONG = 0.45                            # metres from grip to muzzle: from here on a gun takes both hands


def _qmul(a: Sequence[float], b: Sequence[float]) -> Tuple[float, float, float, float]:
    ax, ay, az, aw = a
    bx, by, bz, bw = b
    return (aw * bx + ax * bw + ay * bz - az * by, aw * by - ax * bz + ay * bw + az * bx,
            aw * bz + ax * by - ay * bx + az * bw, aw * bw - ax * bx - ay * by - az * bz)


def _qturn(q: Sequence[float], v: Sequence[float]) -> Tuple[float, float, float]:
    x, y, z, w = q
    tx, ty, tz = 2 * (y * v[2] - z * v[1]), 2 * (z * v[0] - x * v[2]), 2 * (x * v[1] - y * v[0])
    return (v[0] + w * tx + y * tz - z * ty, v[1] + w * ty + z * tx - x * tz, v[2] + w * tz + x * ty - y * tx)


def _unit(v: Sequence[float]) -> Tuple[float, float, float]:
    n = math.sqrt(sum(c * c for c in v)) or 1.0
    return (v[0] / n, v[1] / n, v[2] / n)


def _muzzle(doc: dict, grip: int) -> Optional[Tuple[float, float, float]]:
    """Where a held weapon's muzzle is from its grip (the weapon's own muzzle_position joint), or None."""
    todo = list(doc["nodes"][grip].get("children", []))
    while todo:
        n = doc["nodes"][todo.pop()]
        if n.get("name", "").lower() == "muzzle_position" and "translation" in n:
            return tuple(n["translation"])
        todo += n.get("children", [])
    return None


def joint_world(doc: dict, copy: G.SkeletonCopy, keys: Dict[str, Dict[str, Tuple[List[float], List[tuple]]]],
                joint: str, t: float) -> Optional[Tuple[G.Vec3, G.Quat]]:
    """Where a joint of someone's skeleton is, and its turn, at a time (seconds) of their animation (keys),
    in the space of the node they stand on. None if they have no such joint."""
    i = copy.nodes.get(joint.lower())
    if i is None:
        return None
    nodes = doc["nodes"]
    parent = {c: k for k in copy.order for c in nodes[k].get("children", [])}
    names = {v: k for k, v in copy.nodes.items()}

    def local(k: int):
        mine = keys.get(names.get(k, ""), {})
        n = nodes[k]
        at = n.get("translation", (0.0, 0.0, 0.0))
        turn = n.get("rotation", (0.0, 0.0, 0.0, 1.0))
        if "translation" in mine:
            times, values = mine["translation"]
            at = values[max(0, min(len(times) - 1, bisect.bisect_right(times, t) - 1))]
        if "rotation" in mine:
            times, values = mine["rotation"]
            turn = values[max(0, min(len(times) - 1, bisect.bisect_right(times, t) - 1))]
        return at, turn

    chain = [i]
    while chain[-1] in parent:
        chain.append(parent[chain[-1]])
    at, turn = (0.0, 0.0, 0.0), (0.0, 0.0, 0.0, 1.0)
    for k in reversed(chain):
        a, q = local(k)
        moved = _qturn(turn, a)
        at, turn = (at[0] + moved[0], at[1] + moved[1], at[2] + moved[2]), _qmul(turn, q)
    return at, turn


class Ground:
    """The map's surfaces in a scene being built, for standing people on. A script places someone a few
    centimetres off the floor (the game sets them on the ground itself); height() finds the floor."""

    def __init__(self, b: G.Builder) -> None:
        self.g = b.g
        self.upto = len(b.g.doc["nodes"])                    # the map is what was there before the cast
        self._world: Dict[int, List[List[float]]] = {}
        self._parent: Optional[Dict[int, int]] = None
        self._tris: Dict[Tuple[int, int], List[Tuple[G.Vec3, G.Vec3, G.Vec3]]] = {}

    def _matrix(self, i: int) -> List[List[float]]:
        if i in self._world:
            return self._world[i]
        nodes = self.g.doc["nodes"]
        if self._parent is None:
            self._parent = {c: k for k, n in enumerate(nodes[:self.upto]) for c in n.get("children", [])}
        n = nodes[i]
        if "matrix" in n:
            m = [[n["matrix"][c * 4 + r] for c in range(4)] for r in range(4)]
        else:
            x, y, z, w = n.get("rotation", (0.0, 0.0, 0.0, 1.0))
            sx, sy, sz = n.get("scale", (1.0, 1.0, 1.0))
            tx, ty, tz = n.get("translation", (0.0, 0.0, 0.0))
            m = [[(1 - 2 * (y * y + z * z)) * sx, 2 * (x * y - z * w) * sy, 2 * (x * z + y * w) * sz, tx],
                 [2 * (x * y + z * w) * sx, (1 - 2 * (x * x + z * z)) * sy, 2 * (y * z - x * w) * sz, ty],
                 [2 * (x * z - y * w) * sx, 2 * (y * z + x * w) * sy, (1 - 2 * (x * x + y * y)) * sz, tz],
                 [0.0, 0.0, 0.0, 1.0]]
        up = self._parent.get(i)
        if up is not None:
            p = self._matrix(up)
            m = [[sum(p[r][k] * m[k][c] for k in range(4)) for c in range(4)] for r in range(4)]
        self._world[i] = m
        return m

    def _read(self, index: int, code: str, width: int) -> List:
        acc = self.g.doc["accessors"][index]
        view = self.g.doc["bufferViews"][acc["bufferView"]]
        at = view.get("byteOffset", 0) + acc.get("byteOffset", 0)
        flat = struct.unpack_from(f"<{acc['count'] * width}{code}", self.g.bin, at)
        return [flat[k:k + width] for k in range(0, len(flat), width)] if width > 1 else list(flat)

    def height(self, x: float, y: float, z: float, reach: float = 0.5) -> Optional[float]:
        """The height of the map's surface at x, z that is nearest to y, within reach; None when there is
        none (no map, or nothing under the spot)."""
        doc = self.g.doc
        best: Optional[float] = None
        for i, n in enumerate(doc["nodes"][:self.upto]):
            if "mesh" not in n or "skin" in n:
                continue
            m = None
            for pi, prim in enumerate(doc["meshes"][n["mesh"]]["primitives"]):
                acc = doc["accessors"][prim["attributes"]["POSITION"]]
                if prim.get("mode", 4) != 4 or "indices" not in prim or "min" not in acc:
                    continue
                m = m or self._matrix(i)
                lo, hi = acc["min"], acc["max"]
                corners = [[sum(m[r][k] * v for k, v in enumerate((cx, cy, cz))) + m[r][3] for r in range(3)]
                           for cx in (lo[0], hi[0]) for cy in (lo[1], hi[1]) for cz in (lo[2], hi[2])]
                if not (min(c[0] for c in corners) <= x <= max(c[0] for c in corners)
                        and min(c[2] for c in corners) <= z <= max(c[2] for c in corners)
                        and min(c[1] for c in corners) - reach <= y <= max(c[1] for c in corners) + reach):
                    continue
                key = (i, pi)
                if key not in self._tris:
                    pts = [tuple(sum(m[r][k] * v for k, v in enumerate(p)) + m[r][3] for r in range(3))
                           for p in self._read(prim["attributes"]["POSITION"], "f", 3)]
                    ia = doc["accessors"][prim["indices"]]
                    idx = self._read(prim["indices"], {5123: "H", 5125: "I", 5121: "B"}[ia["componentType"]], 1)
                    self._tris[key] = [(pts[idx[k]], pts[idx[k + 1]], pts[idx[k + 2]])
                                       for k in range(0, len(idx) - 2, 3)]
                for a, b_, c in self._tris[key]:
                    if (min(a[0], b_[0], c[0]) > x or max(a[0], b_[0], c[0]) < x
                            or min(a[2], b_[2], c[2]) > z or max(a[2], b_[2], c[2]) < z):
                        continue
                    ux, uy, uz = b_[0] - a[0], b_[1] - a[1], b_[2] - a[2]
                    vx, vy, vz = c[0] - a[0], c[1] - a[1], c[2] - a[2]
                    den = ux * vz - vx * uz
                    if abs(den) < 1e-12:
                        continue                             # a wall: no height of its own here
                    s = ((x - a[0]) * vz - vx * (z - a[2])) / den
                    t = (ux * (z - a[2]) - (x - a[0]) * uz) / den
                    if s < -1e-6 or t < -1e-6 or s + t > 1 + 1e-6:
                        continue
                    h = a[1] + s * uy + t * vy
                    if abs(h - y) <= reach and (best is None or abs(h - y) < abs(best - y)):
                        best = h
        return best
WEAPON = re.compile(r"^WeaponTemplate", re.I)


def weapon_model(template: str, models: Sequence[str], texts: Sequence[str] = ()) -> Optional[str]:
    """The model a weapon template stands for, among the weapons file's models. The template's own text in
    the weapons' script (texts) names it where it can (WeaponTemplateM16Mortar names M16_upgrade2, the M16
    with the grenade launcher); without the script, by the template's name: WeaponTemplateMetalPipe is
    metal_pipe, WeaponTemplateSniper is sniper_rifle."""
    lower = {m.lower(): m for m in models}
    for t in texts:
        if t.lower() in lower:
            return lower[t.lower()]
    flat = lambda t: re.sub(r"[^a-z0-9]", "", t.lower())
    want = flat(WEAPON.sub("", template))
    if not want:
        return None
    by = {flat(m): m for m in models}
    if want in by:
        return by[want]
    longer = sorted((k for k in by if k.startswith(want)), key=len)
    if longer:
        return by[longer[0]]
    shorter = sorted((k for k in by if want.startswith(k)), key=len, reverse=True)
    return by[shorter[0]] if shorter else None


def floor_spot(script: Script) -> Optional[Tuple[float, float, float]]:
    """Where someone in the cutscene stands, height and all (the map's own x, y, z), or None: for finding
    the room they stand in. The camera's start is no use for that: it hangs in the air."""
    for at, _facing in script.stands.values():
        if abs(at[0]) + abs(at[2]) > 30.0:                   # a place on the map, not a step from its origin
            return at
    return script.origin[0] if script.origin else None


def where(script: Script, streams: Sequence[Tuple[str, bytes]]) -> Optional[Tuple[float, float]]:
    """Where in the city a cutscene happens (the map's own x and z): where the script first stands
    someone, or else where its camera starts. None for a scene with no place of its own (the ones played
    wherever Tony happens to be are set at 0, 0, 0)."""
    for at, _facing in script.stands.values():
        if abs(at[0]) + abs(at[2]) > 1.0:
            return at[0], at[2]
    if script.origin:
        return script.origin[0][0], script.origin[0][2]
    if script.stands:                                        # everyone at 0, 0: played wherever Tony is
        return None
    if script.camera:
        lib = G.Library()
        for label, data in streams:
            lib.add(label, data, main=False)
        for ref in _pieces(G.Builder(lib), script.camera):
            for ch in p3d.walk(ref.chunk.children):
                if ch.id in G.VECTOR_CHANNELS:
                    try:
                        param, frames, vals = G._vector_keys(ref.data, ch)
                    except (p3d.P3dError, struct.error, IndexError, KeyError):
                        continue
                    if param == "TRAN" and vals and abs(vals[0][0]) + abs(vals[0][2]) > 1.0:
                        return vals[0][0], vals[0][2]
    return None


GONE = (1e-4, 1e-4, 1e-4)              # the size of someone whose part of a joined cutscene isn't playing
PLAY = re.compile(r'\b\w+\("((?:PAL_)?M?NIS_\w+)"\s*(?:,\s*"([\w:]*)")?')


def plays_next(texts: Sequence[str], hashed: Callable[[str], str]) -> Dict[str, str]:
    """Which cutscene the game starts as soon as another ends: {cutscene (lower): the next (lower)}.
    texts: the game's mission scripts, decompiled. A script starts a cutscene with a call whose first
    argument is its name and whose second names the function to run when it is over; where that
    function's first act with a cutscene is to start another, the two play back to back. hashed gives
    the form a function's name has in the compiled scripts."""
    starts: Dict[str, List[str]] = {}                       # function (lower) -> the cutscenes it starts
    calls: List[Tuple[str, str]] = []                       # (cutscene, the function run after it)
    for text in texts:
        for part in re.split(r"(?m)^function ", text)[1:]:
            fn = part.split("(", 1)[0].strip().split("::")[-1].lower()
            for m in PLAY.finditer(part):
                starts.setdefault(fn, []).append(m.group(1).lower())
                if m.group(2):
                    calls.append((m.group(1).lower(), m.group(2)))
    out: Dict[str, str] = {}
    for scene, after in calls:
        for key in (after.lower(), hashed(after).lower()):
            then = starts.get(key)
            if then and then[0] != scene:
                out.setdefault(scene, then[0])
                break
    return out


def export(name: str, script: Script, streams: Sequence[Tuple[str, bytes]],
           model: Callable[[str, str], Optional[Tuple[str, bytes]]],
           area: Sequence[Tuple[str, bytes]] = (), library: Sequence[Tuple[str, bytes]] = (),
           then: Sequence[Tuple[str, Script, Sequence[Tuple[str, bytes]]]] = ()) -> Tuple[bytes, G.Report]:
    """The cutscene as a .glb. streams: its stream files (name, bytes) in order. model(kind, name) hands
    over a model's file (name, bytes) or None: kind "person" with a template's name, "tony" with his
    suit's, "vehicle" with the name of the joint its animation moves, or "weapons".
    area: the files of the map where it happens, and library the shared files they need (see
    blender_export.area_from_files): the cast then stands on the street or in the room.
    then: the cutscenes the game plays straight after it (name, script, streams), joined on: each one's
    cast is there only while its own part plays."""
    lib = G.Library()
    have = set()
    for label, data in area:
        if label.lower() not in have:
            have.add(label.lower())
            lib.add(label, data, main=True)
    for label, data in library:
        if label.lower() not in have:
            have.add(label.lower())
            lib.add(label, data, main=False)
    for part in [streams] + [st for _n, _s, st in then]:
        for label, data in part:
            lib.add(label, data, main=False)
    found: List[str] = []

    def cast(b: G.Builder) -> None:
        b._animations = None                                 # the stream files came after the map's
        tracks = _Tracks(b)
        ground = Ground(b)
        loaded: Dict[str, Optional[G.Source]] = {}
        scenes = [(name, script)] + [(n, s) for n, s, _st in then]
        spans = []
        start = 0.0
        for n, sc in scenes:
            went_in, nodes, length = _cast(b, lib, n, sc, model, tracks, loaded, start, ground)
            found.extend(went_in)
            spans.append((nodes, start, start + length))
            start += length
        if len(scenes) > 1:                                  # each cast is there for its own part only
            for i, (nodes, begin, end) in enumerate(spans):
                times, sizes = [begin], [(1.0, 1.0, 1.0)]
                if begin > 0:
                    times, sizes = [0.0] + times, [GONE] + sizes
                if i < len(spans) - 1:
                    times, sizes = times + [end], sizes + [GONE]
                for node in nodes:
                    tracks.add(node, "scale", times, sizes, step=True)
        # Each part's name, when it runs (seconds) and its camera: in the report, and in the scene's extras
        # for the Blender script, which changes camera and starts each part's sound at its start.
        b.report.parts = [{"name": n, "start": round(begin, 4), "end": round(end, 4), "camera": sc.camera,
                           # the screen's fades, in seconds from the part's start (the Blender script plays them)
                           "fades": [{"at": round(at / FRAMES_A_SECOND, 4), "in": round(fi / FRAMES_A_SECOND, 4),
                                      "hold": round(hold / FRAMES_A_SECOND, 4), "out": round(fo / FRAMES_A_SECOND, 4),
                                      "colour": list(rgb),
                                      "keys": [[round((at + f) / FRAMES_A_SECOND, 4), a]
                                               for f, a in fade_keys(fi, hold, fo, rgb)]}
                                     for at, fi, hold, fo, rgb in sc.fades]}
                          for (n, sc), (_nodes, begin, end) in zip(scenes, spans)]
        b.g.doc["scenes"][0].setdefault("extras", {})["parts"] = b.report.parts
        b.report.models += found
        if tracks.channels:
            # The only animation in the file. Blender plays a file's first animation and parks the rest: with
            # the map's own (a door swinging) ahead of it, everybody stood with their arms out.
            b.g.doc["animations"] = [{"name": ACTION + name, "channels": tracks.channels, "samplers": tracks.samplers}]
            b.report.animations = [ACTION + name]
    glb, report = G.export(lib, map_mode=True, also=cast)
    if not found:
        raise G.ExportError("none of this cutscene's people or vehicles are in your copied game files")
    return glb, report


def _person(b: G.Builder, lib: G.Library, src: G.Source, spot: int, label: str,
            wanted: str = "") -> Optional[G.SkeletonCopy]:
    """Someone's model from their file, under spot: their skeleton, or None when nothing went in. A file
    with a composite drawable that holds the body (Tony's cutscene suits) is put in whole, eyes and teeth
    on their joints; otherwise the full-detail skins on their skeleton. wanted: the composite's name, in a
    file that holds several people (a scene's static.p3d): only that one, or nothing."""
    skin_names = {G.chunk_name(src.data, c).lower() for c in src.chunks if c.id == G.SKIN}
    for c in src.chunks:
        if c.id != G.COMPOSITE or (wanted and G.chunk_name(src.data, c).lower() != wanted.lower()):
            continue
        parts = [G.composite_prop(src.data, k)[0].lower() for k in c.children if k.id == G.COMPOSITE_PROP]
        if any(p in skin_names for p in parts):
            before = len(b.copies)
            b.composite(G.Ref(src, c), spot, label + " skeleton")
            if len(b.copies) > before:
                return b.copies[before]
    if wanted:
        return None
    skins = [c for c in src.chunks if c.id == G.SKIN]
    full = [c for c in skins if "_low" not in G.chunk_name(src.data, c).lower()] or skins
    copy, placed = None, False
    for c in full:
        r = p3d._R(src.data, *c.body)
        r.text()
        r.u32()
        skel_name = r.text()
        if copy is None:
            sref = lib.find("skeleton", skel_name, (src,))
            if not sref:
                break
            copy = b.skeleton(sref, spot, label + " skeleton")
        if b.skin(G.Ref(src, c), copy, copy.group) is not None:    # type: ignore[attr-defined]
            placed = True
    return copy if placed else None


def _cast(b: G.Builder, lib: G.Library, name: str, script: Script,
          model: Callable[[str, str], Optional[Tuple[str, bytes]]], tracks: _Tracks,
          loaded: Dict[str, Optional[G.Source]], start: float,
          ground: Optional[Ground] = None) -> Tuple[List[str], List[int], float]:
    """Puts one cutscene's people, vehicles and camera into b's scene, its animations beginning at start
    (seconds): who went in, their nodes, and how long it runs."""
    root = b.g.node(name)
    left_out: List[str] = []
    went_in: List[str] = []
    nodes: List[int] = []
    length = 0.0

    def later(times: List[float]) -> List[float]:
        return [start + t for t in times] if start else times

    def source(kind: str, wanted: str) -> Optional[G.Source]:
        key = kind + ":" + wanted.lower()
        if key not in loaded:
            got = model(kind, wanted)
            try:
                loaded[key] = lib.add(got[0], got[1], main=False) if got else None
            except p3d.P3dError:
                loaded[key] = None
        return loaded[key]

    bodies: Dict[str, G.SkeletonCopy] = {}                   # person (lower) -> their skeleton, for the effects
    poses: Dict[str, tuple] = {}                             # person (lower) -> (skeleton, keys, spot, turn)
    fx = getattr(b, "_fx", None)
    if fx is None:                                           # the game's particle effects (Common.p3d)
        fx = b._fx = CFX.Effects(b, source("effects", ""))   # type: ignore[attr-defined]
        got = model("script", "templates/weapons.cso")
        b._weapons = CFX.weapon_settings(got[1]) if got else {}  # type: ignore[attr-defined]
    weapons: Dict[str, Dict[str, float]] = getattr(b, "_weapons", {})
    rates = {k: v["FiringRate"] for k, v in weapons.items() if v.get("FiringRate")}
    people = [(who, anim) for who, anim in script.plays.items()]
    for who in script.cast:                                  # loaded and stood somewhere, but playing nothing
        if who.lower() not in script.plays and who.lower() not in script.drives and who.lower() in script.stands:
            people.append((who.lower(), ""))
    cast = {k.lower(): v for k, v in script.cast.items()}
    for who, anim in people:
        # someone the script doesn't load was already in the game: their template has their name
        src = source("tony", script.tony) if who == TONY else source("person", cast.get(who) or "CharTemp_" + who)
        label = "Tony" if who == TONY else next((k for k in script.cast if k.lower() == who), who)
        # who they are in the report: the model they got, and whether their body and face move
        # The model the scene changes someone into (SPEC-009 section 3.1) is in the scene's own static.p3d,
        # with the shapes their face moves by; without it, the everyday model their template names.
        swapped = ""
        if who != TONY and who in script.swaps:
            own = source("scene", name)
            if own is not None and any(c.id == G.COMPOSITE and G.chunk_name(own.data, c).lower() == script.swaps[who].lower()
                                       for c in own.chunks):
                src, swapped = own, script.swaps[who]
        role = {"name": label, "template": script.tony if who == TONY else cast.get(who) or "CharTemp_" + who,
                "model": (swapped or src.label) if src is not None else "", "body": "", "face": ""}
        b.report.cast.append(role)
        if src is None:
            left_out.append(label)
            continue
        at, facing = script.stands.get(who, ((0.0, 0.0, 0.0), 0.0))
        stand = list(G.pos(at))
        moves = _joint_keys(_pieces(b, anim)) if anim else None
        # The floor is looked for under their feet, which the animation may put metres from the spot the
        # script names (a whole scene's cast is often given one spot, and a clerk behind his desk is given
        # the same one a little lower: the floor there is lower, and his hands rest on the desk).
        feet = list(stand)
        if moves is not None:
            dx, dz = _first_step(moves[0], facing_rotation(facing))
            feet[0] += dx
            feet[2] += dz
        floor = ground.height(*feet) if ground is not None and who in script.stands else None
        # On the floor, not the few centimetres in it. Someone the script sinks well into it is meant to be
        # there: the hotel clerk is 16 cm down so that his hands reach his desk.
        if floor is not None and floor - stand[1] <= SUNK:
            stand[1] = floor
        spot = b.g.node(label, root, translation=stand, rotation=list(facing_rotation(facing)))
        before = len(b.g.doc["nodes"])
        copy = _person(b, lib, src, spot, label, swapped)
        if copy is None:
            b.g.doc["nodes"][root]["children"].remove(spot)
            left_out.append(label)
            role["model"] = ""
            continue
        went_in.append(label)
        nodes.append(spot)
        bodies[who] = copy
        poses[who] = (copy, moves[0] if moves is not None else {}, tuple(stand), facing_rotation(facing))
        hand = copy.nodes.get(HAND)
        held = script.holds_at.get(who) or ([(0, script.holds[who])] if who in script.holds else [])
        for n, (frame, template) in enumerate(held if hand is not None else []):
            guns = source("weapons", "")
            names = [G.chunk_name(guns.data, c) for c in guns.chunks if c.id == G.COMPOSITE] if guns else []
            wanted = weapon_model(template, names, (weapons.get(template.lower()) or {}).get("texts", ()))
            gref = lib.find("composite", wanted, (guns,)) if wanted and guns else None
            if not gref:
                left_out.append(label + "'s " + WEAPON.sub("", template))
                continue
            grip = b.g.node(label + "'s grip", hand)
            b.composite(gref, grip, label + "'s " + wanted)
            muzzle = _muzzle(b.g.doc, grip)
            # Every weapon is turned the same way in the hand: its barrel (its own -Z) along the forearm and
            # its top up. Measured on NIS_100_office_politics: with the turn, the barrels of the Uzis, the
            # pistol and the M16s point along the forearm (0.89 to 0.99 of the way); without it, the short
            # guns pointed at the sky.
            b.g.doc["nodes"][grip]["rotation"] = list(GRIP)
            # In the hand from its frame, until the next weapon's: the grip is shrunk away outside that.
            until = held[n + 1][0] if n + 1 < len(held) else None
            if frame > 0 or until is not None:
                holder = b.g.node(label + "'s " + wanted + " (from frame " + str(frame) + ")", hand)
                kids = b.g.doc["nodes"][hand]["children"]
                kids.remove(grip)
                b.g.doc["nodes"][holder]["children"] = [grip]
                times, sizes = ([0.0], [GONE]) if frame > 0 else ([], [])
                times, sizes = times + [frame / FRAMES_A_SECOND], sizes + [(1.0, 1.0, 1.0)]
                if until is not None:
                    times, sizes = times + [until / FRAMES_A_SECOND], sizes + [GONE]
                tracks.add(holder, "scale", later(times), sizes, step=True)
            # Its fire (SPEC-010 section 3): while the script holds the fire control and it is the gun in the
            # hand, a shot every FiringRate milliseconds, each playing the gun's "fire1" state's effects (the
            # muzzle flash and the casing; "fire2" for alternate fire) at their places on the gun, and a
            # tracer every second bullet.
            shots = [(max(a, frame), min(z, until if until is not None else z), alt)
                     for a, z, alt in script.fires.get(who, [])]
            shots = [s_ for s_ in shots if s_[1] > s_[0]]
            if shots:
                every = int((weapons.get(template.lower()) or {}).get("TracerFrequency") or CFX.TRACER_EVERY)
                _gun_fire(b, fx, gref, wanted, grip, muzzle, shots, CFX.firing_rate(template, rates), tracks, later,
                          label, max(1, every))
        shapes = [i for i in range(before, len(b.g.doc["nodes"])) if b.g.doc["nodes"][i].get("mesh") in b.shaped]
        if who in script.faces:                              # the lips, brows and eyelids
            sliding = slider_keys(_pieces(b, script.faces[who]))
            moved = 0
            for i in shapes:
                mesh = b.g.doc["nodes"][i]["mesh"]
                if sliding:
                    count = len(b.g.doc["meshes"][mesh]["weights"])
                    times, rows = shape_weights(b.shaped[mesh], count, sliding)
                    tracks.weights(i, later(times), rows)
                    moved += any(any(row) for row in rows)
            role["face"] = ("moves" if moved else "animation not found" if not sliding
                            else "model has no face shapes" if not shapes else "no slider matches a shape")
        else:
            role["face"] = "no face animation in the script" + ("" if shapes else ", and the model has no face shapes")
        if anim:
            role["body"] = "moves" if _pieces(b, anim) else "animation not found"
            keys, ran = moves
            length = max(length, ran)
            for joint, paths in keys.items():
                node = copy.nodes.get(joint)
                if node is not None:
                    for path, (times, values) in paths.items():
                        tracks.add(node, path, later(times), values)
    for who, kind, joint, frame, by in script.effects:       # hits, blood, a grenade going off on someone
        _character_effect(b, fx, root, bodies, poses, who, kind, joint, frame, by, tracks, later, start, length)
    for who, anim in script.drives.items():
        label = next((k for k in script.cast if k.lower() == who), who)
        keys, ran = _joint_keys(_pieces(b, anim))
        length = max(length, ran)
        joint = next(iter(keys), "")
        src = source("vehicle", joint) if joint else None
        cref = None
        if src is not None:
            cref = next((G.Ref(src, c) for c in src.chunks if c.id == G.COMPOSITE and G._has_model(lib, G.Ref(src, c))), None)
        if cref is None:
            left_out.append(label)
            continue
        mover = b.g.node(label, root)
        b.composite(cref, mover)
        went_in.append(label)
        nodes.append(b.g.node(label + " in the scene", root))
        b.g.doc["nodes"][root]["children"].remove(mover)     # under a node of its own, to be shown and hidden
        b.g.doc["nodes"][nodes[-1]]["children"] = [mover]
        for path, (times, values) in keys[joint].items():
            tracks.add(mover, path, later(times), values)
    if script.camera:
        pieces = _pieces(b, script.camera)
        if pieces:
            length = max(length, _length(pieces))
            ci = b.g.add("cameras", {"name": script.camera, "type": "perspective",
                                     "perspective": {"aspectRatio": 4 / 3, "yfov": 0.75, "znear": 0.1, "zfar": 5000.0}})
            place = root
            if script.origin:
                place = b.g.node(script.camera + "'s place", root, translation=list(G.pos(script.origin[0])),
                                 rotation=list(facing_rotation(script.origin[1])))
            cam = b.g.node(script.camera, place, camera=ci)
            for path, (times, values) in _camera_keys(pieces).items():
                tracks.add(cam, path, later(times), values)
            went_in.append("camera")
    for what, drawn in script.renderables.items():           # the scene's own props: the cabinet's doors
        own = source("scene", name)
        ref = next((G.Ref(own, c) for c in (own.chunks if own else []) if c.id == G.COMPOSITE
                    and G.chunk_name(own.data, c).lower() == drawn.lower()), None) or lib.find("composite", drawn)
        if ref is None:
            left_out.append(what)
            continue
        before = len(b.copies)
        top = b.composite(ref, root, what)                   # its joints carry their places on the map
        copy = b.copies[before] if len(b.copies) > before else None
        if copy is None:
            continue
        nodes.append(top)
        went_in.append(what)
        b.report.scene_props.append(what)
        _hide_map_props_at(b, copy)
        anim = script.renderable_moves.get(what)
        if anim:
            keys, ran = _joint_keys(_pieces(b, anim))
            length = max(length, ran)
            for joint, paths in keys.items():
                node = copy.nodes.get(joint)
                if node is not None:
                    for path, (times, values) in paths.items():
                        tracks.add(node, path, later(times), values)
    if script.prop_states:                                   # the map's props the scene changes: a door blown in
        spot = next((G.pos(at) for at, _f in script.stands.values() if abs(at[0]) + abs(at[2]) > 30.0), None)
        for lost in _prop_states(b, lib, script, tracks, later, spot, fx):
            left_out.append(lost + " (a prop the script changes)")
    for label in left_out:
        b.report.missing_drawables.add(label)
    return went_in, nodes, length
