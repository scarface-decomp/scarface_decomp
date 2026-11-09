#!/usr/bin/env python3
"""
Scripts tab of the portal: .cso / .dso (Scarface's compiled TorqueScript) and .dtr files from your
own copy of the game.

* .cso / .dso are decompiled to readable TorqueScript (portal/tools/torque_script.py), and the text is
  compiled again with the same code generation as the game's compiler: the file is only called
  decompiled when that gives back the identical bytes. All 635 compiled scripts on the PS2 disc do.
  The game stores names hashed (stx + 8 letters); names recovered from the game's own files are shown
  as words.
* .dtr: Scarface's AI decision trees (portal/tools/dtr_format.py): the layout is decoded and rebuilt
  byte for byte, and shown as the tree with its task names; the small programs inside are listed as
  numbers (not decoded yet). Other chunk files are shown as a chunk tree.
"""

from __future__ import annotations

import sys
from pathlib import Path
from typing import Dict, Optional

sys.path.insert(0, str(Path(__file__).resolve().parent))
from script_formats import format_chunk_tree, walk_chunks  # noqa: E402
import torque_dso as TD  # noqa: E402
import torque_script as TS  # noqa: E402
from torque_decompile import listing  # noqa: E402


def verify_and_decompile_cso_dso(raw: bytes, filename: str = "script.cso",
                                 names: Optional[Dict[int, str]] = None) -> dict:
    """Readable TorqueScript for a Scarface .cso/.dso, and whether it compiles back to these bytes.
    names: recovered names ({key: word}, torque_script.names_for), or None to keep them hashed."""
    try:
        s = TD.parse(raw)
    except TD.DsoError as e:
        return {"ok": False, "error": f"Not a Scarface compiled script: {e}"}
    try:
        text, exact, msg = TS.check(raw, names)
        code = TS.header(filename, text, exact, msg, names) + text
        disasm = listing(s, names)
        fmt = ("Compiled TorqueScript, decompiled: compiles back byte for byte" if exact
               else f"Compiled TorqueScript, decompiled but NOT exact: {msg}")
    except TS.ScriptError as e:
        exact = False
        code = f"// {filename}: could not be decompiled ({e}).\n\n" + TD.listing(raw, filename)
        disasm = TD.hex_codes(s)
        fmt = f"Compiled TorqueScript v{s.version} (not decompiled: {e})"
    return {
        "ok": True,
        "format": fmt,
        "size": len(raw),
        "opcode_count": len(s.codes),
        "disasm": disasm,
        "decompiled_code": code,
        "complete": exact,
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


def verify_and_decompile_dtr(raw: bytes, filename: str = "data.dtr", bin_dir: Optional[Path] = None) -> dict:
    """An AI decision tree (portal/tools/dtr_format.py): its layout is decoded and rebuilt byte for byte;
    the task names are recovered from the game's executables (bin_dir) by their hash."""
    import dtr_format as DT
    from torque_names import candidates, recover
    try:
        d = DT.parse(raw)
    except DT.DtrError:
        d = None
    if d is not None:
        exes = [(bin_dir / e).read_bytes() for e in TS.EXECUTABLES if bin_dir and (bin_dir / e).is_file()]
        strings = [s.decode("latin-1") for s in d.strings.split(b"\0") if s]
        names = recover({d.name_key} | {k for k, _ in d.tasks}, candidates(exes, strings + [filename.split(".")[0]]))
        exact, msg = DT.round_trip(raw)
        programs = "\n".join(f"#{i:<4} [{' '.join(str(w) for w in p)}]" for i, p in enumerate(d.programs))
        return {
            "ok": True,
            "format": f"AI decision tree: layout decoded ({msg}); program words not decoded yet",
            "size": len(raw),
            "opcode_count": len(d.nodes),
            "disasm": "// programs: [words]\n" + programs + "\n",
            "decompiled_code": DT.describe(raw, filename, names),
            "roundtrip_exact": exact,
        }
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
