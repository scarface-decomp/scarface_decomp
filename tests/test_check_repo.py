"""scripts/check_repo.py passes on the repository (the same check CI runs)."""
import check_repo


def test_repository_is_consistent(capsys):
    assert check_repo.main() == 0, capsys.readouterr().out


def test_queue_seed_data_is_tracked_and_valid():
    """A fresh download builds the same work queue as an old copy only if these seed files are present."""
    import queue_builder as Q
    from conftest import ROOT
    seeds = Q.seed_data(ROOT)
    assert len(seeds["known_functions"]) > 1000
    starts = seeds["extra_starts"]
    assert set(starts) <= {"pc", "xb", "proto"} and sum(len(v) for v in starts.values()) > 900
    for vas in starts.values():
        assert all(len(v) == 10 and int(v, 16) > 0 for v in vas) and vas == sorted(set(vas))


def test_registry_from_another_game_version_is_rejected(tmp_path, monkeypatch):
    """A registry re-verified against a non-US or unpatched copy must not get through CI."""
    import json
    import shutil
    from conftest import ROOT
    (tmp_path / "reports").mkdir()
    reg = json.loads((ROOT / "reports" / "verified_registry.json").read_text(encoding="utf-8"))
    reg["binaries"]["xb"]["sha256"] = "0" * 64
    (tmp_path / "reports" / "verified_registry.json").write_text(json.dumps(reg), encoding="utf-8")
    monkeypatch.setattr(check_repo, "ROOT", tmp_path)
    problems = []
    check_repo.check_registry(problems)
    assert any("not an accepted game version" in p for p in problems), problems


def test_portal_refuses_other_game_versions(tmp_path, monkeypatch):
    """A default.xbe that isn't the US disc's is not used: no functions, and the page says why."""
    import importlib
    import sys
    from conftest import ROOT
    sys.path.insert(0, str(ROOT))
    srv = importlib.import_module("decomp_portal_server")
    fake = tmp_path / "default.xbe"
    fake.write_bytes(b"XBEH" + bytes(0x400))
    monkeypatch.setattr(srv, "BINARIES", {"xb": fake})
    monkeypatch.setattr(srv, "_IMAGES", {})
    monkeypatch.setattr(srv, "BINARY_PROBLEMS", {})
    assert srv.image_for("xb") is None and srv.accepted_binaries() == {}
    assert "not the Xbox, US disc copy" in srv.BINARY_PROBLEMS["xb"]
    assert "docs/GAME_VERSIONS.md" in srv.BINARY_PROBLEMS["xb"]
