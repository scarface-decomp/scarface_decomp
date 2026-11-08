import os
import struct
import sys

sys.path.insert(0, os.path.join(os.path.dirname(__file__), "..", "tools"))

from script_formats import (  # noqa: E402
    LAYOUT_ESCAPED, LAYOUT_RAW, format_chunk_tree, parse_dso_container,
    serialize_dso_container, string_at, walk_chunks,
)


def make_dso(layout, code, magic=b"", version=33, gstr=b"hello\x00world\x00", fstr=b"fn\x00",
             gflt=(1.5,), fflt=(), lbps=((0, 1),), idents=((6, [1]),)):
    c = {
        "magic": magic or None, "version": version, "layout": layout,
        "global_strings": gstr, "function_strings": fstr,
        "global_floats": list(gflt), "function_floats": list(fflt),
        "code": list(code), "line_breaks": list(lbps),
        "idents": [(o, list(ips)) for o, ips in idents] if idents is not None else None,
    }
    return serialize_dso_container(c)


CODE = [0x45, 3, 0x1000, 0xFE, 0x0B]


def test_escaped_layout_roundtrip():
    raw = make_dso(LAYOUT_ESCAPED, CODE)
    r = parse_dso_container(raw)
    assert r["ok"], r
    assert r["layout"] == LAYOUT_ESCAPED
    assert r["code"] == CODE
    assert r["roundtrip_ok"] is True
    assert r["version_pinned"] is False


def test_raw_layout_roundtrip_with_magic():
    raw = make_dso(LAYOUT_RAW, CODE, magic=b"RDSC")
    r = parse_dso_container(raw)
    assert r["ok"], r
    assert r["layout"] == LAYOUT_RAW and r["magic"] == b"RDSC"
    assert r["code"] == CODE and r["roundtrip_ok"]


def test_version_pinning():
    raw = make_dso(LAYOUT_ESCAPED, CODE, version=33)
    assert parse_dso_container(raw, allowed_versions={33})["version_pinned"] is True
    bad = parse_dso_container(raw, allowed_versions={36})
    assert not bad["ok"] and "Unsupported" in bad["error"]


def test_out_of_range_version_rejected():
    raw = make_dso(LAYOUT_ESCAPED, CODE, version=5000)
    assert not parse_dso_container(raw)["ok"]


def test_truncation_everywhere_is_an_error_not_a_crash():
    raw = make_dso(LAYOUT_ESCAPED, CODE)
    for cut in range(len(raw)):
        r = parse_dso_container(raw[:cut])
        assert r["ok"] is False or r.get("roundtrip_ok") is not None


def test_huge_counts_rejected_without_allocation():
    raw = bytearray(make_dso(LAYOUT_ESCAPED, CODE))
    # global string table size field sits right after the version (no magic)
    struct.pack_into("<I", raw, 4, 0xFFFFFFF0)
    r = parse_dso_container(bytes(raw))
    assert not r["ok"] and "global string table" in r["error"]


def test_trailing_garbage_detected():
    raw = make_dso(LAYOUT_ESCAPED, CODE, idents=None, lbps=())
    r = parse_dso_container(raw + b"\x01\x02\x03")
    assert not r["ok"]


def test_ident_patch_outside_code_rejected():
    raw = make_dso(LAYOUT_ESCAPED, CODE, idents=((0, [99]),))
    r = parse_dso_container(raw)
    assert not r["ok"]


def test_non_canonical_escape_flagged_by_roundtrip():
    # Encode the value 3 as 0xFF + u32 (legal to read, but not what the canonical writer emits).
    good = make_dso(LAYOUT_ESCAPED, [3], idents=None, lbps=())
    head_len = len(good) - 1
    weird = good[:head_len] + b"\xFF" + struct.pack("<I", 3)
    r = parse_dso_container(weird)
    assert r["ok"] and r["code"] == [3]
    assert r["roundtrip_ok"] is False and r["first_mismatch"] is not None


def test_string_at_handles_mid_string_offsets():
    table = b"hello\x00world\x00"
    assert string_at(table, 0) == "hello"
    assert string_at(table, 2) == "llo"
    assert string_at(table, 6) == "world"
    assert string_at(table, 99) is None


# ---------------- chunk trees ----------------

def chunk(cid, data=b"", children=b""):
    data_size = 12 + len(data)
    return struct.pack("<III", cid, data_size, data_size + len(children)) + data + children


def test_chunk_tree_walk():
    leaf1 = chunk(0x100, b"abcd")
    leaf2 = chunk(0x101)
    mid = chunk(0x200, b"xy", leaf1 + leaf2)
    root = chunk(0xFF443350, b"", mid)
    r = walk_chunks(root)
    assert r["ok"], r
    assert r["count"] == 4
    top = r["chunks"][0]
    assert top["id"] == 0xFF443350 and top["children"][0]["id"] == 0x200
    assert [c["id"] for c in top["children"][0]["children"]] == [0x100, 0x101]
    txt = format_chunk_tree(r["chunks"])
    assert "ID 0xFF443350" in txt and "    0x" in txt


def test_chunk_child_overflowing_parent():
    bad_child = struct.pack("<III", 1, 12, 64)          # claims 64 bytes, parent only has 12
    root = struct.pack("<III", 2, 12, 24) + bad_child
    r = walk_chunks(root)
    assert not r["ok"] and "runs past its parent" in r["error"]


def test_chunk_bad_sizes():
    assert not walk_chunks(struct.pack("<III", 1, 4, 12))["ok"]      # data < header
    assert not walk_chunks(struct.pack("<III", 1, 20, 16) + b"\0" * 8)["ok"]   # total < data
    assert not walk_chunks(chunk(1) + b"\x00\x01")["ok"]             # stray bytes


def test_chunk_depth_limit():
    blob = chunk(1)
    for i in range(80):
        blob = chunk(2, b"", blob)
    r = walk_chunks(blob, max_depth=64)
    assert not r["ok"] and "deeper" in r["error"]
