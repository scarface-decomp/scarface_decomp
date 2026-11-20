#!/usr/bin/env python3
"""
Add songs to the in-game tape player (PC), from your own copy of the game. docs/FORMATS.md, "The tape player",
says how the game keeps them.

    python portal/tools/tape_mod.py <game folder> <out folder> songs.json
    python portal/tools/tape_mod.py --check <game folder>          # read art/sound/scripts/tapeplayer.p3d as the game lays it out

<game folder> is the PC game's files (an installed game, or extracted/game_files/PC). songs.json is a list:

    {"layer": "tp_mysong", "artist": "Artist", "title": "Title",
     "ogg": "songs/mysong.ogg",   # new audio: Ogg Vorbis, best 48000 Hz stereo; leave out for a layer the game has
     "track": 42}                 # optional: replace stock track 42 (0..107) instead of adding a new one

A song without "track" becomes a new track, 108 upward (at most 127: the game reads track numbers as a signed
byte; 125 to 127 show "..." as their name, its name-length table ending at 107), and goes on CUSTOM MIX 4 (tape 12)
each time the tape player is set up. The out folder gets only the files that change, in the game's layout:
scriptc/missions/missions.cso (the library), scriptc/gui/TapePlayer.cso (the tape), textbible/HUD_textbible_E.p3d
(the names), art/sound/scripts/tapeplayer.p3d and art/sound/rsd/... (new audio). Every file is checked to rebuild
byte for byte before anything changes, and what is written is read back.

No leaked source is used. You need your own copy of the game.
"""

from __future__ import annotations

import argparse
import json
import random
import re
import struct
import sys
import time
from pathlib import Path
from typing import Dict, List, Sequence, Tuple

sys.path.insert(0, str(Path(__file__).resolve().parent))
import media  # noqa: E402
import p3d  # noqa: E402

FIRST, LAST, FULL, TAPE = 108, 127, 124, 12           # new track numbers; the last with a full name; CUSTOM MIX 4
CUE = 0x01000001                                      # a sound sequence (music cue) chunk
CUE_REL = "art/sound/scripts/tapeplayer.p3d"
BIBLE_REL = "textbible/HUD_textbible_E.p3d"
LIBRARY_REL = "scriptc/missions/missions.cso"
TAPES_REL = "scriptc/gui/TapePlayer.cso"
LAYER_FLAGS = bytes.fromhex("000000000001000000000000000000")   # the 15 bytes every stock layer has after its name
RSD_HEADER = 0x800


class ModError(ValueError):
    pass


# --------------------------------------------------------------------------- the music cue

def parse_cue(b: bytes) -> Tuple[int, int, List[Tuple[str, List[str]]]]:
    """A cue chunk's body: name, u32 1, u32 1, track name ("tape"), u32 layer count, then each layer: name,
    15 bytes, u64 id, u32 event count, each event (class name, u64 id, stream path, u32 length in bytes, u8,
    u32 channels, u32 rate, u32 bits), then u32 1, u32 1. Every string is u32 length, the bytes, a 0.
    Returns (offset of the layer count, the count, [(layer name, [stream path, ...])])."""
    q = [0]

    def u32() -> int:
        if q[0] + 4 > len(b):
            raise ModError("the cue ends early")
        v = struct.unpack_from("<I", b, q[0])[0]
        q[0] += 4
        return v

    def pstr() -> str:
        n = u32()
        if n > 255 or q[0] + n >= len(b) or b[q[0] + n] != 0:
            raise ModError(f"bad text at byte {q[0] - 4}")
        t = b[q[0]:q[0] + n].decode("latin-1")
        q[0] += n + 1
        return t

    pstr(); u32(); u32(); pstr()
    at, n = q[0], u32()
    out = []
    for _ in range(n):
        name = pstr()
        q[0] += len(LAYER_FLAGS)
        u32(); u32()
        events = []
        for _ in range(u32()):
            pstr(); u32(); u32()
            path = pstr()
            u32(); q[0] += 1; u32(); u32(); u32()
            events.append(path)
        if (u32(), u32()) != (1, 1):
            raise ModError(f"layer {name}: unexpected ending")
        out.append((name, events))
    if q[0] != len(b):
        raise ModError(f"{len(b) - q[0]} bytes left after {n} layers: the count or a layer is off")
    return at, n, out


def layer_record(name: str, path: str, length: int, channels: int, rate: int,
                 rand=random.getrandbits, stamp: int = None) -> bytes:
    """One layer with one stream event, as the stock ones are written. The two 64-bit ids are a random word
    and a time stamp, like the stock ones (the game hashes the layer's name, not these)."""
    stamp = (int(time.time()) if stamp is None else stamp) & 0xFFFFFFFF
    nb, pb = name.encode("latin-1"), path.encode("latin-1")
    return (struct.pack("<I", len(nb)) + nb + b"\0" + LAYER_FLAGS
            + struct.pack("<III", rand(32), stamp, 1)
            + struct.pack("<I", 14) + b"SeqEventStream\0" + struct.pack("<II", rand(32), stamp)
            + struct.pack("<I", len(pb)) + pb + b"\0"
            + struct.pack("<I", length) + b"\0" + struct.pack("<4I", channels, rate, 16, 1) + struct.pack("<I", 1))


def ogg_info(d: bytes) -> Tuple[int, int, int]:
    """(channels, rate, samples) of an Ogg Vorbis file: the identification header and the last page's
    granule position."""
    if d[:4] != b"OggS":
        raise ModError("not an Ogg file")
    v = d.find(b"\x01vorbis")
    if v < 0:
        raise ModError("not Ogg Vorbis")
    return d[v + 11], struct.unpack_from("<I", d, v + 12)[0], struct.unpack_from("<q", d, d.rfind(b"OggS") + 6)[0]


def rsd(template: bytes, ogg: bytes, path: str) -> bytes:
    """A PC sound file: a stock one's 2 KB RSD6/OOGV header with this sound's channels, rate and source path,
    then the Ogg stream."""
    ch, rate, _ = ogg_info(ogg)
    hdr = bytearray(template[:RSD_HEADER])
    if hdr[:8] != b"RSD6OOGV":
        raise ModError("the template is not a PC .rsd")
    struct.pack_into("<3I", hdr, 8, ch, 16, rate)
    src = f"c:\\scarface\\art\\sound\\{path}.wav".encode("latin-1")
    if len(src) >= 0xA4 - 0x18:
        raise ModError(f"name too long: {path}")
    hdr[0x18:0xA4] = src + b"\0" * (0xA4 - 0x18 - len(src))
    return bytes(hdr) + ogg


# --------------------------------------------------------------------------- p3d and the text bible

def rebuild(data: bytes, chunks: Sequence[p3d.Chunk], replace: Dict[int, bytes]) -> bytes:
    """A p3d file again from its chunk tree, a chunk's own bytes replaced where replace says (by offset)."""
    def one(c):
        own = replace.get(c.offset, data[c.offset + 12:c.offset + c.head])
        kids = b"".join(one(x) for x in c.children)
        return struct.pack("<3I", c.id, 12 + len(own), 12 + len(own) + len(kids)) + own + kids
    body = b"".join(one(c) for c in chunks)
    return data[:4] + struct.pack("<II", 12, 12 + len(body)) + body


def bible_body(bdy: bytes, add: Sequence[Tuple[str, str]]) -> bytes:
    """A text bible chunk's body with lines added or replaced ([(key, text)]); with none, as it was. Keys are
    kept ascending (the game looks them up by key)."""
    for q in range(0, max(0, min(len(bdy) - 12, 300))):
        n, mark, size = struct.unpack_from("<3I", bdy, q)
        table = q + 12 + 8 * n
        if mark != media.BIBLE_MARK or n > 100_000 or not 0 <= len(bdy) - table - size < 4:
            continue
        keys = struct.unpack_from(f"<{n}I", bdy, q + 12)
        starts = struct.unpack_from(f"<{n}I", bdy, q + 12 + 4 * n)
        text = bdy[table:table + size]
        unit = 1 if all(x % 2 == 0 for x in starts) and (not starts or max(starts) < size) else 2
        lines = {}
        for key, st in zip(keys, starts):
            st *= unit
            e = st
            while text[e:e + 2] != b"\0\0":
                e += 2
            lines[key] = text[st:e]
        order = list(keys)
        for key, t in add:
            k = p3d.name_key(key)
            if k not in lines:
                order.append(k)
            lines[k] = t.encode("utf-16-le")
        if add:
            order = sorted(set(order))
        blob, st = b"", []
        for k in order:
            st.append(len(blob) // unit)
            blob += lines[k] + b"\0\0"
        pad = len(bdy) - table - size if not add else (-(q + 12 + 8 * len(order) + len(blob))) % 4
        return (bdy[:q] + struct.pack("<3I", len(order), mark, len(blob)) + struct.pack(f"<{len(order)}I", *order)
                + struct.pack(f"<{len(order)}I", *st) + blob + b"\0" * pad)
    raise ModError("not a text bible")


# --------------------------------------------------------------------------- the songs

def numbers(songs: Sequence[dict]) -> Dict[str, int]:
    """Each song's track number: its "track", else the next new one from 108."""
    out, k = {}, FIRST
    for s in songs:
        if not re.fullmatch(r"[A-Za-z0-9_]{1,40}", s.get("layer", "")):
            raise ModError(f"layer name {s.get('layer')!r}: use letters, digits and _")
        if "track" in s:
            if not 0 <= int(s["track"]) <= FIRST - 1:
                raise ModError(f"{s['layer']}: \"track\" must be 0..{FIRST - 1}")
            out[s["layer"]] = int(s["track"])
        else:
            out[s["layer"]] = k
            k += 1
    if k - 1 > LAST:
        raise ModError(f"{k - FIRST} new tracks: at most {LAST - FIRST + 1} ({FIRST}..{LAST}); "
                       "replace stock tracks with \"track\" for more")
    return out


def build(game: Path, out: Path, songs: Sequence[dict], log=print) -> Dict[str, bytes]:
    """The changed files {game-relative path: bytes}, written under out."""
    import torque_script as TS
    game, out = Path(game), Path(out)
    nums = numbers(songs)
    new = [s for s in songs if "track" not in s]
    if max(nums.values(), default=0) > FULL:
        log(f"note: tracks {FULL + 1}..{max(nums.values())} will show '...' instead of their names")
    written: Dict[str, bytes] = {}

    def read(rel):
        return (game / rel).read_bytes()

    # the music: new layers and their sounds
    raw = read(CUE_REL)
    tree = p3d.read_tree(raw)
    cue = next((c for c in tree if c.id == CUE and raw[c.offset + 16:c.offset + 27] == b"tapeplayer\0"), None)
    if cue is None:
        raise ModError(f"no tapeplayer cue in {CUE_REL}")
    body = raw[cue.offset + 12:cue.offset + cue.head]
    if rebuild(raw, tree, {cue.offset: body}) != raw:
        raise ModError(f"{CUE_REL} does not rebuild unchanged")
    count_at, count, cue_layers = parse_cue(body)
    have = {n.lower() for n, _ in cue_layers}
    template = read(media.sound_file("music/tapeplayer/tp_2020"))
    added = b""
    for s in songs:
        if "ogg" not in s:
            if s["layer"].lower() not in have:
                raise ModError(f"no layer {s['layer']} in the game: give it an \"ogg\"")
            continue
        if s["layer"].lower() in have:
            raise ModError(f"layer {s['layer']} is already in the game: pick another name")
        ogg = Path(s["ogg"]).read_bytes()
        ch, rate, samples = ogg_info(ogg)
        if (ch, rate) != (2, 48000):
            log(f"warning: {s['ogg']} is {ch} channel(s) at {rate} Hz; the game's own tapes are 2 at 48000")
        path = "music\\tapeplayer\\" + s["layer"]
        written[media.sound_file("music/tapeplayer/" + s["layer"])] = rsd(template, ogg, path)
        added += layer_record(s["layer"], path, samples * ch * 2, ch, rate)
        have.add(s["layer"].lower())
        count += 1
    if added:
        nb = bytearray(body + added)
        struct.pack_into("<I", nb, count_at, count)
        cue_bytes = rebuild(raw, tree, {cue.offset: bytes(nb)})
        parse_cue(bytes(nb))
        written[CUE_REL] = cue_bytes

    # the names
    raw = read(BIBLE_REL)
    tree = p3d.read_tree(raw)
    tb = next(c for c in p3d.walk(tree) if c.id == media.TEXT_BIBLE)
    own = raw[tb.offset + 12:tb.offset + tb.head]
    if rebuild(raw, tree, {tb.offset: bible_body(own, [])}) != raw:
        raise ModError(f"{BIBLE_REL} does not rebuild unchanged")
    add = []
    for s in songs:
        n = nums[s["layer"]]
        add += [(f"TAPE_PLAYER_TRACK_{n}_ARTIST", s["artist"]), (f"TAPE_PLAYER_TRACK_{n}_TITLE", s["title"])]
    nb = rebuild(raw, tree, {tb.offset: bible_body(own, add)})
    got, old = dict(media.text_bible(nb)), dict(media.text_bible(raw))
    keys = {p3d.name_key(k) for k, _ in add}
    if not all(got.get(p3d.name_key(k)) == t for k, t in add) or \
            not all(got.get(k) == v for k, v in old.items() if k not in keys):
        raise ModError("the rebuilt text bible doesn't read back")
    written[BIBLE_REL] = nb

    # the library: TapeTrack objects (stxbkecbojn; LayerName = stxocihbejk, UnlockList = stxaklkeccn,
    # IsUnlocked = stxpgegeiml) after Track107, or a stock track's layer replaced
    text, exact, msg = TS.check(read(LIBRARY_REL))
    if not exact:
        raise ModError(f"{LIBRARY_REL}: {msg}")
    for s in songs:
        if "track" in s:
            m = re.search(rf'(new stxbkecbojn\("Track{int(s["track"])}"\)\s*\{{\s*stxocihbejk = )"[^"]*"', text)
            if not m:
                raise ModError(f"Track{s['track']} is not in the library")
            text = text[:m.end(1)] + f'"{s["layer"]}"' + text[m.end():]
    end = text.index("};", text.index('"Track107"')) + 2
    text = text[:end] + "".join(
        f'\n        new stxbkecbojn("Track{nums[s["layer"]]}")\n        {{\n            stxocihbejk = "{s["layer"]}";\n'
        f'            stxaklkeccn = 0;\n            stxpgegeiml = 1;\n        }};' for s in new) + text[end:]
    lib = TS.compile_text(text)
    if not TS.check(lib)[1]:
        raise ModError("the rebuilt library doesn't decompile back exactly")
    written[LIBRARY_REL] = lib

    # the tape: HUDTapePlayer_SetSongAt (stxfibopekp) in the tape player's set-up, after its screen is found
    if new:
        text, exact, msg = TS.check(read(TAPES_REL))
        if not exact:
            raise ModError(f"{TAPES_REL}: {msg}")
        hook = text.index('$stxaogfahhi = "Track";', text.index("function stxedllpdln()"))
        calls = "".join(f"    stxfibopekp({TAPE}, {i}, {nums[s['layer']]});\n" for i, s in enumerate(new))
        gui = TS.compile_text(text[:hook] + calls + "    " + text[hook:])
        if not TS.check(gui)[1]:
            raise ModError("the rebuilt tape script doesn't decompile back exactly")
        written[TAPES_REL] = gui

    for rel, data in written.items():
        p = out / rel
        p.parent.mkdir(parents=True, exist_ok=True)
        p.write_bytes(data)
    for s in songs:
        log(f"track {nums[s['layer']]:3}: {s['artist']} - {s['title']}  [{s['layer']}]" +
            ("  (new audio)" if "ogg" in s else ""))
    return written


def check(game: Path, log=print) -> int:
    """Read the game's (or a hand-edited) tapeplayer.p3d and say whether it holds together. Problems found."""
    game = Path(game)
    raw = (game / CUE_REL).read_bytes()
    bad = 0
    if len(raw) != struct.unpack_from("<I", raw, 8)[0]:
        log("file size field: WRONG (the total size at byte 8 doesn't match the file)")
        bad += 1
    cue = next((c for c in p3d.read_tree(raw) if c.id == CUE and raw[c.offset + 16:c.offset + 27] == b"tapeplayer\0"), None)
    if cue is None:
        log("no tapeplayer cue")
        return bad + 1
    try:
        _at, n, found = parse_cue(raw[cue.offset + 12:cue.offset + cue.head])
    except ModError as e:
        log(f"the tapeplayer cue doesn't read: {e}")
        return bad + 1
    log(f"layer count {n}: every layer reads and the cue ends exactly")
    for name, paths in found:
        if not paths:
            log(f"  {name}: no stream (silent)")
        for path in paths:
            f = media.sound_file(path)
            if not (game / f).is_file():
                bad += 1
                log(f"  {name}: no sound file for {path} (expected {f})")
    return bad


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    ap.add_argument("--check", metavar="GAME", type=Path, help="check the game's tapeplayer.p3d and stop")
    ap.add_argument("game", nargs="?", type=Path)
    ap.add_argument("out", nargs="?", type=Path)
    ap.add_argument("songs", nargs="?", type=Path)
    a = ap.parse_args(argv)
    try:
        if a.check:
            return 1 if check(a.check) else 0
        if not (a.game and a.out and a.songs):
            ap.error("give the game folder, an out folder and songs.json (or --check GAME)")
        build(a.game, a.out, json.loads(a.songs.read_text(encoding="utf-8")))
    except (ModError, OSError, ValueError) as e:
        print(f"error: {e}", file=sys.stderr)
        return 1
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
