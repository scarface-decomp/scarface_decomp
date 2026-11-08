#!/usr/bin/env python3
"""
Scripts tab of the portal: .cso / .dso (Scarface's compiled TorqueScript) and .dtr files from your
own copy of the game.

* .cso / .dso are read by tools/torque_dso.py, which takes a file apart and rebuilds it byte for
  byte. On all 635 compiled scripts in the PS2 release's cement.rcf the rebuild is exact. The tab
  shows the strings, numbers and bytecode; turning the bytecode into readable TorqueScript is the
  next step (docs/SCRIPTS.md). An older decoder that guessed with stock Torque opcode numbers was
  removed: it failed on every real file.
* .dtr: the format isn't worked out yet. Files that happen to be Pure3D-style chunk files are shown
  as a chunk tree; anything else is reported as unknown.
"""

from __future__ import annotations

import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from script_formats import format_chunk_tree, walk_chunks  # noqa: E402
import torque_dso as TD  # noqa: E402

def verify_and_decompile_cso_dso(raw: bytes, filename: str = "script.cso") -> dict:
    """Read a Scarface .cso/.dso exactly (tools/torque_dso.py) and describe what it holds.

    The old decoder here guessed with stock Torque opcode numbers and failed on every real file, so it
    was replaced. This reports only what is proven: the exact round trip, the strings and the numbers.
    Readable TorqueScript comes next (docs/SCRIPTS.md, step 3)."""
    try:
        s = TD.parse(raw)
    except TD.DsoError as e:
        return {"ok": False, "error": f"Not a Scarface compiled script: {e}"}
    exact, msg = TD.round_trip(raw)
    return {
        "ok": True,
        "format": f"Compiled TorqueScript v{s.version} ({'exact round trip' if exact else 'round trip FAILED: ' + msg})",
        "size": len(raw),
        "opcode_count": len(s.codes),
        "disasm": TD.hex_codes(s),
        "decompiled_code": TD.listing(raw, filename),
        "complete": False,
        "roundtrip_exact": exact,
    }


P3D_CHUNK_NAMES = {
    0xFF443350: "Pure3D::DataFileRoot",
    0x00027000: "Scarface::DataTemplateChunk",
    0x00027001: "Scarface::AttributeTableChunk",
    0x00027002: "Scarface::VehiclePhysicsRecord",
    0x00027003: "Scarface::WeaponBalanceRecord",
    0x00027004: "Scarface::EmpireTurfRecord",
    0x00010000: "Pure3D::MeshChunk",
    0x00011000: "Pure3D::ShaderChunk",
    0x00019000: "Pure3D::TextureChunk",
}


def verify_and_decompile_dtr(raw: bytes, filename: str = "data.dtr") -> dict:
    tree = walk_chunks(raw)
    if not tree["ok"]:
        return {"ok": False, "error": "The .dtr format isn't worked out yet (docs/SCRIPTS.md, step 5)."}
    lines = [
        "// ============================================================================",
        f"// {filename}: {tree['count']} chunks, {len(raw):,} bytes, structure fully consumed",
        "// Chunk IDs/record layouts below are labels and guesses, not confirmed formats.",
        "// ============================================================================",
        "",
    ]
    stack = [(c, 0) for c in reversed(tree["chunks"])]
    while stack:
        c, d = stack.pop()
        label = P3D_CHUNK_NAMES.get(c["id"], f"Chunk_0x{c['id']:08X}")
        payload = raw[c["offset"] + 12: c["offset"] + c["data_size"]]
        lines.append("    " * d + f"// {label} @0x{c['offset']:X}: {len(payload)} payload bytes, {len(c['children'])} children")
        stack.extend((ch, d + 1) for ch in reversed(c["children"]))
    return {
        "ok": True,
        "format": "Pure3D-style chunk file",
        "size": len(raw),
        "opcode_count": tree["count"],
        "disasm": format_chunk_tree(tree["chunks"], P3D_CHUNK_NAMES),
        "decompiled_code": "\n".join(lines),
    }


if __name__ == "__main__":
    import argparse
    ap = argparse.ArgumentParser(description="Parse .cso/.dso/.dtr files from your own copy of the game.")
    ap.add_argument("files", nargs="+")
    a = ap.parse_args()
    for f in a.files:
        raw = Path(f).read_bytes()
        res = verify_and_decompile_dtr(raw, Path(f).name) if f.lower().endswith(".dtr") else verify_and_decompile_cso_dso(raw, Path(f).name)
        print(("[OK] " if res["ok"] else "[FAIL] ") + f + ": " + (res.get("format") or res.get("error", "")))
