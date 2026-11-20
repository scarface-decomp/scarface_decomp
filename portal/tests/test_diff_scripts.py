"""Comparing two versions' scripts (portal/scripts/diff_scripts.py)."""

import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "portal" / "scripts"))
import diff_scripts as DS  # noqa: E402


def test_compare(tmp_path):
    a, b = tmp_path / "xbox", tmp_path / "pc"
    for root, files in ((a, {"scriptc/same.cs": b"x", "scriptc/Both.cs": b"abc", "scriptc/xonly.cs": b"1"}),
                        (b, {"scriptc/same.cs": b"x", "scriptc/both.cs": b"abd", "scriptc/ponly.cs": b"2"})):
        for k, v in files.items():
            (root / k).parent.mkdir(parents=True, exist_ok=True)
            (root / k).write_bytes(v)
    (a / ".copied").write_text("mark")
    rep = DS.compare(a, b, "xbox", "pc")
    assert rep["counts"] == {"identical": 1, "differ": 1, "xbox_only": 1, "pc_only": 1}
    d = rep["differ"][0]
    assert d["path"] == "scriptc/both.cs" and d["first_diff_off"] == 2 and d["xbox_size"] == d["pc_size"] == 3
    assert rep["xbox_only"] == ["scriptc/xonly.cs"] and rep["pc_only"] == ["scriptc/ponly.cs"]
