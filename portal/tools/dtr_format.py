#!/usr/bin/env python3
"""
Scarface's .dtr files: the AI decision trees (ai/common.dtr; the engine's loader is DecisionTreeFileHandler).

Layout, worked out from the PS2 disc's ai/common.dtr (28,160 bytes) and checked by rebuilding it and the
April 2006 prototype's (25,478 bytes) byte for byte. Little-endian; the offsets in the header count from
byte 0x10, and each section starts on a multiple of 4 bytes (zero-filled before it).

    0x00  u32  0xDEC15109                      file id
    0x04  u32  0
    0x08  u32  key of the tree's name          the game's name hash (torque_names.name_key("common"))
    0x0C  u32  unknown                         (a checksum or build stamp; kept as it is)
    0x10  u32  -> program index                u16 start word of each program
    0x14  u32  -> program words                u32 words; a program is [n, n words]
    0x18  u16  program count, u16 word count
    0x1C  u32  -> nodes                        20 bytes each (below)
    0x20  u32  node count
    0x24  u32  -> tasks                        8 bytes each: u32 key of an AITask_* class name,
                                               u32 offset of a label in the strings (0xFFFFFFFF: none)
    0x28  u32  -> strings                      NUL-terminated, to the end of the file
    0x2C  u16  task count, u16 string bytes

    node: u16 parent (0xFFFF for the root; parents come before their children), u16 next sibling
          (0xFFFF: last), u16 kind (0 root, 1 branch, 0x101 and 0x201 two kinds of leaf), u16 program A,
          u16 program B, u16 program C, u16 program D (0xFFFF: none), u16 0, u16 first child (branches)
          or a value (leaves: 0, 1, 100, 2900, 10000, ...; a priority?), u16 task (index into the tasks)

Known: the tree shape, which task each leaf runs, the task names (all 58 recovered by their hash) and
labels. Not yet known: what the four program slots are for (condition, on-enter, on-exit, ... are
guesses) and what the program words mean (an expression bytecode of small numbers; the interpreter in
the executable has not been read yet). Those are shown as numbers.
"""

from __future__ import annotations

import struct
from dataclasses import dataclass, field
from typing import Dict, List, Optional, Tuple

MAGIC = 0xDEC15109
NODE = struct.Struct("<10H")
NONE16 = 0xFFFF
KINDS = {0: "root", 1: "branch", 0x101: "leaf", 0x201: "leaf (kind 2)"}


class DtrError(ValueError):
    pass


@dataclass
class Dtr:
    name_key: int
    unknown: int
    programs: List[List[int]]
    nodes: List[Tuple[int, ...]]
    tasks: List[Tuple[int, int]]
    strings: bytes
    extra: Dict[str, int] = field(default_factory=dict)

    def string_at(self, off: int) -> str:
        end = self.strings.find(b"\0", off)
        return self.strings[off:end if end >= 0 else len(self.strings)].decode("latin-1")


def parse(raw: bytes) -> Dtr:
    if len(raw) < 0x30:
        raise DtrError("too short for a .dtr header")
    magic, zero, key, unknown = struct.unpack_from("<4I", raw, 0)
    if magic != MAGIC:
        raise DtrError(f"not a Scarface decision tree (starts with 0x{magic:08X})")
    idx_off, words_off, nprog, nwords, nodes_off, nnodes, tasks_off, str_off, ntasks, nstr = \
        struct.unpack_from("<IIHHIIIIHH", raw, 0x10)
    base = 0x10
    spans = [(base + idx_off, 2 * nprog), (base + words_off, 4 * nwords), (base + nodes_off, NODE.size * nnodes),
             (base + tasks_off, 8 * ntasks), (base + str_off, nstr)]
    pos = 0x30
    for start, size in spans:
        if start != _align4(pos) or raw[pos:start].strip(b"\0"):     # sections start on 4 bytes, zero-filled
            raise DtrError(f"section at 0x{start:X}, expected 0x{_align4(pos):X}: layout not understood")
        pos = start + size
    if pos != len(raw) or zero != 0:
        raise DtrError(f"sections end at 0x{pos:X}, file is 0x{len(raw):X} bytes: layout not understood")
    starts = struct.unpack_from(f"<{nprog}H", raw, base + idx_off)
    words = struct.unpack_from(f"<{nwords}I", raw, base + words_off)
    programs = []
    for i, s in enumerate(starts):
        e = starts[i + 1] if i + 1 < nprog else nwords
        p = list(words[s:e])
        if not p or p[0] != len(p) - 1:
            raise DtrError(f"program {i} is not [length, words]")
        programs.append(p[1:])
    nodes = [NODE.unpack_from(raw, base + nodes_off + NODE.size * i) for i in range(nnodes)]
    tasks = [struct.unpack_from("<II", raw, base + tasks_off + 8 * i) for i in range(ntasks)]
    d = Dtr(key, unknown, programs, nodes, tasks, raw[base + str_off:])
    for i, n in enumerate(nodes):
        if n[0] != NONE16 and n[0] >= i:
            raise DtrError(f"node {i}: parent {n[0]} does not come first")
    return d


def _align4(n: int) -> int:
    return (n + 3) & ~3


def build(d: Dtr) -> bytes:
    starts, words = [], []
    for p in d.programs:
        starts.append(len(words))
        words += [len(p)] + list(p)
    nprog, nwords = len(starts), len(words)
    idx_off = 0x20
    words_off = _align4(idx_off + 2 * nprog)
    nodes_off = _align4(words_off + 4 * nwords)
    tasks_off = _align4(nodes_off + NODE.size * len(d.nodes))
    str_off = _align4(tasks_off + 8 * len(d.tasks))
    out = bytearray(struct.pack("<4I", MAGIC, 0, d.name_key, d.unknown))
    out += struct.pack("<IIHHIIIIHH", idx_off, words_off, nprog, nwords, nodes_off, len(d.nodes), tasks_off,
                       str_off, len(d.tasks), len(d.strings))
    def section(data: bytes, at: int):
        out.extend(b"\0" * (0x10 + at - len(out)))
        out.extend(data)

    section(struct.pack(f"<{nprog}H", *starts), idx_off)
    section(struct.pack(f"<{nwords}I", *words), words_off)
    section(b"".join(NODE.pack(*n) for n in d.nodes), nodes_off)
    section(b"".join(struct.pack("<II", *t) for t in d.tasks), tasks_off)
    section(d.strings, str_off)
    return bytes(out)


def round_trip(raw: bytes) -> Tuple[bool, str]:
    try:
        again = build(parse(raw))
    except DtrError as e:
        return False, str(e)
    return (True, "rebuilt byte for byte") if again == raw else (False, "rebuilt file differs")


def describe(raw: bytes, filename: str = "tree.dtr", names: Optional[Dict[int, str]] = None) -> str:
    """The tree as indented text: each node with its kind, task, weight and programs."""
    d = parse(raw)
    names = names or {}
    exact, msg = round_trip(raw)

    def task(i: int) -> str:
        if i >= len(d.tasks):
            return f"task #{i}?"
        key, label = d.tasks[i]
        name = names.get(key, f"0x{key:08X}")
        return name + (f' "{d.string_at(label)}"' if label != 0xFFFFFFFF else "")

    def prog(i: int) -> str:
        return "-" if i == NONE16 else f"#{i} [{' '.join(str(w) for w in d.programs[i])}]"

    kids: Dict[int, List[int]] = {}
    for i, n in enumerate(d.nodes):
        kids.setdefault(n[0], []).append(i)
    lines = [f"// {filename}: Scarface AI decision tree '{names.get(d.name_key, hex(d.name_key))}'",
             f"// {len(d.nodes)} nodes, {len(d.programs)} programs, {len(d.tasks)} tasks, "
             f"{len(d.strings):,} bytes of strings. Layout check: {msg}.",
             "// Program slots A-D and the program words are not decoded yet (docs/SCRIPTS.md).", ""]
    stack = [(r, 0) for r in reversed(kids.get(NONE16, []))]
    seen = set()
    while stack:
        i, depth = stack.pop()
        if i in seen:
            continue
        seen.add(i)
        n = d.nodes[i]
        kind = KINDS.get(n[2], f"kind 0x{n[2]:X}")
        head = f"{'    ' * depth}node {i} ({kind})"
        if n[2] in (0x101, 0x201):
            head += f": {task(n[9])}" + (f"  value {n[8]}" if n[8] else "")
        lines.append(head)
        slots = [("A", n[3]), ("B", n[4]), ("C", n[5]), ("D", n[6])]
        for label, v in slots:
            if v != NONE16:
                lines.append(f"{'    ' * depth}    {label}: {prog(v)}")
        stack.extend((c, depth + 1) for c in reversed(kids.get(i, [])))
    lines += ["", "// tasks:"]
    lines += [f"//   {i}: {task(i)}" for i in range(len(d.tasks))]
    if not exact:
        lines.insert(1, f"// WARNING: {msg}")
    return "\n".join(lines) + "\n"
