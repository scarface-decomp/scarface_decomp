#!/usr/bin/env python3
"""
Bounds-checked container parsers for the portal's Scripts tab.

* ``parse_dso_container()`` – .cso / .dso (TorqueScript-style compiled scripts)
* ``walk_chunks()``         – .dtr / .p3d-style chunk trees (12-byte id / data-size / total-size headers)

Both parsers are *strict*: every length is checked against the remaining bytes before it is
read, nothing is allocated from an untrusted count before that check, and the result says
whether the parse consumed the file exactly.  ``parse_dso_container`` also re-serialises what
it read and compares it with the input (``roundtrip_ok``), which is a much stronger check than
"the header looked sane".

Plugging into portal/tools/cso_dso_dtr_decompiler.py
---------------------------------------------
Replace the header-reading part of ``verify_and_decompile_cso_dso()`` with:

    hdr = parse_dso_container(raw, allowed_versions=SCARFACE_DSO_VERSIONS or None)
    if not hdr["ok"]:
        return {"ok": False, "error": hdr["error"]}
    ins_words = hdr["code"]                       # decoded code words (escape bytes already expanded)
    g_strings, f_strings = hdr["global_strings"], hdr["function_strings"]   # raw tables (bytes)
    # resolve string operands with string_at(g_strings, offset) instead of a dict of start offsets
    # and validate every jump target with  0 <= target < len(ins_words)

Opcode numbering differs between Torque engine versions, so key your opcode table by
``hdr["version"]`` and stop decoding (with the position) at the first unknown opcode.
"""

from __future__ import annotations

import struct
from typing import Dict, Iterable, List, Optional, Tuple

__all__ = [
    "SCARFACE_DSO_VERSIONS",
    "DSO_MAGICS",
    "parse_dso_container",
    "serialize_dso_container",
    "string_at",
    "extract_null_strings_with_offsets",
    "walk_chunks",
    "format_chunk_tree",
]

# Fill this with the version number(s) found in the retail Scarface files once confirmed.
# While empty, any version in VERSION_FALLBACK_RANGE is accepted and the result is marked
# "version_pinned": False so the UI can say so.
SCARFACE_DSO_VERSIONS: frozenset = frozenset()
VERSION_FALLBACK_RANGE = range(1, 201)

DSO_MAGICS = (b"CSO\x00", b"DSO\x00", b"RDSC")

LAYOUT_ESCAPED = "u8_escape"   # stock Torque: one byte per code word, 0xFF => next 4 bytes hold the word
LAYOUT_RAW = "u32"             # every code word stored as a little-endian u32


class _Truncated(Exception):
    pass


class _Reader:
    __slots__ = ("buf", "pos", "n")

    def __init__(self, buf: bytes, pos: int = 0):
        self.buf, self.pos, self.n = buf, pos, len(buf)

    def remaining(self) -> int:
        return self.n - self.pos

    def need(self, count: int, what: str) -> None:
        if count < 0 or count > self.remaining():
            raise _Truncated(f"{what}: needs {count} bytes at offset 0x{self.pos:X}, only {self.remaining()} left")

    def u8(self, what: str) -> int:
        self.need(1, what)
        v = self.buf[self.pos]
        self.pos += 1
        return v

    def u32(self, what: str) -> int:
        self.need(4, what)
        v = struct.unpack_from("<I", self.buf, self.pos)[0]
        self.pos += 4
        return v

    def take(self, count: int, what: str) -> bytes:
        self.need(count, what)
        b = self.buf[self.pos:self.pos + count]
        self.pos += count
        return b


# --------------------------------------------------------------------------- #
# String helpers
# --------------------------------------------------------------------------- #

def string_at(table: bytes, offset: int) -> Optional[str]:
    """NUL-terminated string starting at ``offset`` (works for offsets into the middle of a string)."""
    if offset < 0 or offset >= len(table):
        return None
    end = table.find(b"\x00", offset)
    if end == -1:
        end = len(table)
    return table[offset:end].decode("latin-1")


def extract_null_strings_with_offsets(buf: bytes) -> Dict[int, str]:
    """Kept for existing callers: {start_offset: string}. Prefer string_at() for operand lookups."""
    out: Dict[int, str] = {}
    i, n = 0, len(buf)
    while i < n:
        end = buf.find(b"\x00", i)
        if end == -1:
            end = n
        out[i] = buf[i:end].decode("latin-1")
        i = end + 1
    return out


# --------------------------------------------------------------------------- #
# .cso / .dso
# --------------------------------------------------------------------------- #

def _read_tail(raw: bytes, pos: int, code_size: int, lbp_count: int, layout: str,
               global_str_len: int) -> dict:
    """Read code words, line-break pairs and the identifier patch table for one layout."""
    r = _Reader(raw, pos)
    warnings: List[str] = []
    code: List[int] = []

    if layout == LAYOUT_ESCAPED:
        r.need(code_size, "code stream (1 byte minimum per word)")
        buf = raw
        for i in range(code_size):
            if r.pos >= r.n:
                raise _Truncated(f"code word {i}: end of file")
            b = buf[r.pos]
            r.pos += 1
            if b == 0xFF:
                code.append(r.u32(f"escaped code word {i}"))
            else:
                code.append(b)
    else:
        r.need(code_size * 4, "code stream (4 bytes per word)")
        code = list(struct.unpack_from(f"<{code_size}I", raw, r.pos)) if code_size else []
        r.pos += code_size * 4

    r.need(lbp_count * 8, "line-break pair table")
    flat = list(struct.unpack_from(f"<{lbp_count * 2}I", raw, r.pos)) if lbp_count else []
    r.pos += lbp_count * 8
    line_breaks = [(flat[i], flat[i + 1]) for i in range(0, len(flat), 2)]

    idents: Optional[List[Tuple[int, List[int]]]] = None
    if r.remaining() > 0:
        count = r.u32("identifier table count")
        r.need(count * 8, "identifier table entries (8 bytes minimum each)")
        idents = []
        for e in range(count):
            str_off = r.u32(f"identifier {e} string offset")
            n_ips = r.u32(f"identifier {e} patch count")
            r.need(n_ips * 4, f"identifier {e} patch list")
            ips = list(struct.unpack_from(f"<{n_ips}I", raw, r.pos)) if n_ips else []
            r.pos += n_ips * 4
            bad = [ip for ip in ips if ip >= code_size]
            if bad:
                raise _Truncated(f"identifier {e}: patch location {bad[0]} is outside the code ({code_size} words)")
            if str_off >= global_str_len:
                warnings.append(f"identifier {e}: string offset {str_off} is outside the global string table")
            idents.append((str_off, ips))

    return {"code": code, "line_breaks": line_breaks, "idents": idents, "end": r.pos, "warnings": warnings}


def parse_dso_container(raw: bytes, allowed_versions: Optional[Iterable[int]] = None) -> dict:
    """
    Parse the container of a compiled TorqueScript file.

    Returns a dict with ``ok`` and, on success: magic, version, version_pinned, layout,
    global_strings, function_strings (raw bytes), global_floats, function_floats,
    code, line_breaks, idents, roundtrip_ok, first_mismatch, warnings.
    """
    n = len(raw)
    if n < 16:
        return {"ok": False, "error": "File too small (<16 bytes)."}

    r = _Reader(raw)
    magic = raw[:4] if raw[:4] in DSO_MAGICS else None
    if magic:
        r.pos = 4

    try:
        version = r.u32("version")
        allowed = frozenset(allowed_versions) if allowed_versions else None
        if allowed is not None:
            if version not in allowed:
                return {"ok": False, "error": f"Unsupported .cso/.dso version {version} (expected {sorted(allowed)})."}
            pinned = True
        else:
            if version not in VERSION_FALLBACK_RANGE:
                return {"ok": False, "error": f"Invalid .cso/.dso version: {version}"}
            pinned = False

        g_len = r.u32("global string table size")
        g_strings = r.take(g_len, "global string table")
        f_len = r.u32("function string table size")
        f_strings = r.take(f_len, "function string table")

        g_cnt = r.u32("global float count")
        r.need(g_cnt * 8, "global float table")
        g_float_bytes = r.take(g_cnt * 8, "global float table")
        f_cnt = r.u32("function float count")
        r.need(f_cnt * 8, "function float table")
        f_float_bytes = r.take(f_cnt * 8, "function float table")

        code_size = r.u32("code size")
        lbp_count = r.u32("line-break pair count")
    except _Truncated as e:
        return {"ok": False, "error": f"Truncated or corrupt header: {e}"}

    tail_pos = r.pos
    attempts = {}
    for layout in (LAYOUT_ESCAPED, LAYOUT_RAW):
        try:
            attempts[layout] = _read_tail(raw, tail_pos, code_size, lbp_count, layout, g_len)
        except _Truncated as e:
            attempts[layout] = {"error": str(e)}

    exact = [k for k, v in attempts.items() if "end" in v and v["end"] == n]
    warnings: List[str] = []
    if len(exact) == 1:
        layout = exact[0]
    elif len(exact) == 2:
        layout = LAYOUT_ESCAPED
        warnings.append("Both code layouts consume the file exactly; assuming the standard escaped-byte layout.")
    else:
        parts = []
        for k, v in attempts.items():
            if "error" in v:
                parts.append(f"{k}: {v['error']}")
            else:
                parts.append(f"{k}: stopped at 0x{v['end']:X} with {n - v['end']} unread bytes")
        return {"ok": False, "error": "Code section does not match either known layout (" + "; ".join(parts) + ")."}

    tail = attempts[layout]
    warnings.extend(tail["warnings"])
    if tail["idents"] is None:
        warnings.append("No identifier patch table after the line-break pairs.")
    if not pinned:
        warnings.append(f"Version {version} is not pinned; set SCARFACE_DSO_VERSIONS once the retail value is confirmed.")

    result = {
        "ok": True,
        "magic": magic,
        "version": version,
        "version_pinned": pinned,
        "layout": layout,
        "global_strings": g_strings,
        "function_strings": f_strings,
        "global_floats": list(struct.unpack(f"<{g_cnt}d", g_float_bytes)) if g_cnt else [],
        "function_floats": list(struct.unpack(f"<{f_cnt}d", f_float_bytes)) if f_cnt else [],
        "_global_float_bytes": g_float_bytes,
        "_function_float_bytes": f_float_bytes,
        "code": tail["code"],
        "line_breaks": tail["line_breaks"],
        "idents": tail["idents"],
        "warnings": warnings,
    }
    rebuilt = serialize_dso_container(result)
    if rebuilt == raw:
        result["roundtrip_ok"], result["first_mismatch"] = True, None
    else:
        k = next((i for i in range(min(len(rebuilt), len(raw))) if rebuilt[i] != raw[i]), min(len(rebuilt), len(raw)))
        result["roundtrip_ok"], result["first_mismatch"] = False, k
        result["warnings"].append(f"Re-serialised file differs from the input at offset 0x{k:X} (non-canonical encoding?).")
    return result


def serialize_dso_container(c: dict) -> bytes:
    """Inverse of parse_dso_container() (canonical encoding)."""
    out = bytearray()
    if c.get("magic"):
        out += c["magic"]
    out += struct.pack("<I", c["version"])
    out += struct.pack("<I", len(c["global_strings"])) + c["global_strings"]
    out += struct.pack("<I", len(c["function_strings"])) + c["function_strings"]
    gfb = c.get("_global_float_bytes")
    if gfb is None:
        gfb = struct.pack(f"<{len(c['global_floats'])}d", *c["global_floats"])
    ffb = c.get("_function_float_bytes")
    if ffb is None:
        ffb = struct.pack(f"<{len(c['function_floats'])}d", *c["function_floats"])
    out += struct.pack("<I", len(gfb) // 8) + gfb
    out += struct.pack("<I", len(ffb) // 8) + ffb
    out += struct.pack("<II", len(c["code"]), len(c["line_breaks"]))
    if c["layout"] == LAYOUT_ESCAPED:
        for w in c["code"]:
            if w < 0xFF:
                out.append(w)
            else:
                out.append(0xFF)
                out += struct.pack("<I", w)
    else:
        if c["code"]:
            out += struct.pack(f"<{len(c['code'])}I", *c["code"])
    for a, b in c["line_breaks"]:
        out += struct.pack("<II", a, b)
    if c.get("idents") is not None:
        out += struct.pack("<I", len(c["idents"]))
        for str_off, ips in c["idents"]:
            out += struct.pack("<II", str_off, len(ips))
            if ips:
                out += struct.pack(f"<{len(ips)}I", *ips)
    return bytes(out)


# --------------------------------------------------------------------------- #
# .dtr / Pure3D-style chunk trees
# --------------------------------------------------------------------------- #

def walk_chunks(raw: bytes, header_size: int = 12, max_depth: int = 64, max_chunks: int = 2_000_000) -> dict:
    """
    Walk a chunk tree where each chunk header is ``u32 id, u32 data_size, u32 total_size``:
      * data_size  counts the header + the chunk's own data (not its children)
      * total_size counts data_size + all child chunks
    Rules enforced: header_size <= data_size <= total_size, a chunk never extends past its
    parent (or the file), children exactly fill [data_size, total_size), depth <= max_depth.

    Returns {"ok", "chunks": [ {id, offset, data_size, total_size, depth, children:[...]} ],
             "count", "consumed", "trailing", "error"?}
    """
    n = len(raw)
    roots: List[dict] = []
    count = 0
    # stack of (start, end, depth, children_list) regions still to parse
    stack: List[Tuple[int, int, int, List[dict]]] = [(0, n, 0, roots)]
    try:
        while stack:
            start, end, depth, sink = stack.pop()
            pos = start
            pending: List[Tuple[int, int, int, List[dict]]] = []
            while pos < end:
                if end - pos < header_size:
                    raise ValueError(f"{end - pos} stray bytes at 0x{pos:X} (smaller than a chunk header)")
                cid, data_size, total_size = struct.unpack_from("<III", raw, pos)
                if data_size < header_size:
                    raise ValueError(f"chunk 0x{cid:08X} at 0x{pos:X}: data size {data_size} is smaller than the header")
                if total_size < data_size:
                    raise ValueError(f"chunk 0x{cid:08X} at 0x{pos:X}: total size {total_size} < data size {data_size}")
                if total_size > end - pos:
                    raise ValueError(f"chunk 0x{cid:08X} at 0x{pos:X}: total size {total_size} runs past its parent (0x{end:X})")
                count += 1
                if count > max_chunks:
                    raise ValueError(f"more than {max_chunks} chunks; refusing to continue")
                node = {"id": cid, "offset": pos, "data_size": data_size, "total_size": total_size,
                        "depth": depth, "children": []}
                sink.append(node)
                if total_size > data_size:
                    if depth + 1 > max_depth:
                        raise ValueError(f"chunk nesting deeper than {max_depth} at 0x{pos:X}")
                    pending.append((pos + data_size, pos + total_size, depth + 1, node["children"]))
                pos += total_size
            stack.extend(reversed(pending))     # keep children in file order
    except ValueError as e:
        return {"ok": False, "error": str(e), "chunks": roots, "count": count}
    return {"ok": True, "chunks": roots, "count": count, "consumed": n, "trailing": 0}


def format_chunk_tree(chunks: List[dict], names: Optional[Dict[int, str]] = None) -> str:
    """Indented text listing for the disassembly pane."""
    names = names or {}
    lines: List[str] = []
    stack = [(c, 0) for c in reversed(chunks)]
    while stack:
        c, d = stack.pop()
        label = names.get(c["id"], "")
        lines.append(f"{'  ' * d}0x{c['offset']:08X}  ID 0x{c['id']:08X}{(' ' + label) if label else ''}"
                     f"  data {c['data_size']}  total {c['total_size']}  children {len(c['children'])}")
        stack.extend((ch, d + 1) for ch in reversed(c["children"]))
    return "\n".join(lines)
