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


def test_pc_disc_scripts_patched(tmp_path, monkeypatch):
    """The PC installer disc: cement.rcf's scripts, with patch01.rcf's (from the 1.00.2 patch) on top."""
    import game_assets as GA
    import game_files as GF
    disc = tmp_path / "pc.iso"
    disc.write_bytes(b"")
    calls = {}

    def fake_read(src, sink, progress, stop, log=print):
        calls["extra"] = src.extra
        sink.file("cement.rcf/scriptc/gui/pause/controller.cso", 3, [b"old"])
        sink.file("cement.rcf/scriptc/missions/missions.cso", 8, [b"missions"])
        sink.same("cement.rcf/scriptc/missions/copy.cso", 8, __import__("hashlib").sha1(b"missions").hexdigest())
        sink.file("cement.rcf/art/thing.p3d", 1, [b"x"])
        sink.file("Scarface.exe", 1, [b"x"])
        sink.file("patch01.rcf/scriptc/gui/pause/controller.cso", 3, [b"new"])
        sink.file("patch01.rcf/scriptc/gui/pause/win32_controller.cso", 5, [b"win32"])

    monkeypatch.setattr(GA, "read_pc_disc", fake_read)
    monkeypatch.setattr(ES, "is_pc_disc", lambda src: src == disc)
    monkeypatch.setattr(GF, "_patch_installer", lambda folder: tmp_path / "patch.exe")
    assert ES.guess_version(disc) == "pc"
    out = tmp_path / "out"
    assert ES.extract(disc, out, log=lambda *a: None) == 4
    assert calls["extra"] == str(tmp_path / "patch.exe")
    assert (out / "scriptc/gui/pause/controller.cso").read_bytes() == b"new"
    assert (out / "scriptc/gui/pause/win32_controller.cso").read_bytes() == b"win32"
    assert (out / "scriptc/missions/copy.cso").read_bytes() == b"missions"
    assert not (out / "art").exists()


def test_script_lane_reads_only_extracted_scripts():
    """The portal's script lane is binaries/scripts_and_data/, which only extract_scripts.py fills (with the
    patches applied); the full unpacker writes elsewhere and never into it."""
    import game_assets as GA
    server = (ROOT / "portal" / "decomp_portal_server.py").read_text(encoding="utf-8")
    assert 'SCRIPTS_DIR = BASE_DIR / "binaries" / "scripts_and_data"' in server
    assert ES.SCRIPTS_ROOT == ROOT / "binaries" / "scripts_and_data"
    assert GA.OUT_NAME != "scripts_and_data" and "scripts_and_data" in GA.SKIP_DIRS
