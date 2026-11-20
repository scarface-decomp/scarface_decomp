"""The PC's patch archives replace cement.rcf's scripts when they are copied out (extract_scripts.py)."""

import hashlib
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "portal" / "tools"))
sys.path.insert(0, str(ROOT / "portal" / "scripts"))
import extract_scripts as ES  # noqa: E402
from rcf import build_rcf  # noqa: E402


def test_patch01_replaces_cement(tmp_path):
    game = tmp_path / "game"
    game.mkdir()
    (game / "cement.rcf").write_bytes(build_rcf([
        ("scriptc\\gui\\pause\\controller.cso", b"old controller"),
        ("scriptc\\worldgameplay\\decor.cso", b"old decor"),
        ("scriptc\\missions\\missions.cso", b"missions")]))
    (game / "patch01.rcf").write_bytes(build_rcf([
        ("scriptc\\gui\\pause\\controller.cso", b"new controller"),
        ("scriptc\\gui\\pause\\win32_controller.cso", b"new win32"),
        ("scriptc\\worldgameplay\\decor.cso", b"new decor")]))
    (game / "patch02.rcf").write_bytes(build_rcf([("scriptc\\worldgameplay\\decor.cso", b"newest decor")]))
    assert [p.name for p in ES.patch_archives(game / "cement.rcf")] == ["patch01.rcf", "patch02.rcf"]
    out = tmp_path / "out"
    assert ES.extract(game / "cement.rcf", out, log=lambda *a: None) == 4
    read = lambda rel: (out / rel).read_bytes()
    assert read("scriptc/gui/pause/controller.cso") == b"new controller"
    assert read("scriptc/gui/pause/win32_controller.cso") == b"new win32"
    assert read("scriptc/worldgameplay/decor.cso") == b"newest decor"
    assert read("scriptc/missions/missions.cso") == b"missions"
    assert hashlib.sha256(read("scriptc/worldgameplay/decor.cso")).hexdigest() == hashlib.sha256(b"newest decor").hexdigest()


def test_no_patches_for_other_sources(tmp_path):
    (tmp_path / "patch01.rcf").write_bytes(b"")
    assert ES.patch_archives(tmp_path / "game.iso") == []
    assert ES.patch_archives(tmp_path / "cement.rcf") == [tmp_path / "patch01.rcf"]
