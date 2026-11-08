"""The portal's Game Scripts tab: scripts grouped by game version, other versions compared with retail."""
import importlib
import sys

import pytest

from conftest import PORTAL


@pytest.fixture()
def server(tmp_path, monkeypatch):
    sys.path.insert(0, str(PORTAL))
    srv = importlib.import_module("decomp_portal_server")
    root = tmp_path / "scripts_and_data"
    files = {
        "xbox/scriptc/a.cso": b"same bytes",
        "xbox/scriptc/missions/m.cso": b"retail m",
        "xbox/ai/common.dtr": b"dtr",
        "prototype/scriptc/a.cso": b"same bytes",
        "prototype/scriptc/missions/m.cso": b"older m",
        "prototype/scriptc/editor.cso": b"cut from retail",
        "prototype/packages/azones/x/x.cs": b'Renderer_PropCreateBegin("x.p3d", "1");',
        "uploads/mine.cso": b"mine",
        "old_upload.dso": b"loaded before folders",
        "xbox/art/notes.txt": b"not a script",
    }
    for rel, data in files.items():
        (root / rel).parent.mkdir(parents=True, exist_ok=True)
        (root / rel).write_bytes(data)
    monkeypatch.setattr(srv, "SCRIPTS_DIR", root)
    monkeypatch.setitem(srv._SCRIPT_INDEX, "key", None)
    return srv


def test_index_groups_by_version_and_compares_with_retail(server):
    items, versions = server.script_index()
    by = {i["path"]: i for i in items}
    assert "xbox/art/notes.txt" not in by and len(items) == 9
    assert [v["id"] for v in versions] == ["xbox", "prototype", "uploads"]
    assert {v["id"]: v["count"] for v in versions} == {"xbox": 3, "prototype": 4, "uploads": 2}
    assert by["prototype/scriptc/a.cso"]["compare"] == "same"
    assert by["prototype/scriptc/missions/m.cso"]["compare"] == "changed"
    assert by["prototype/scriptc/editor.cso"]["compare"] == "only here"
    assert by["xbox/scriptc/a.cso"]["compare"] == "" and by["uploads/mine.cso"]["compare"] == ""
    assert by["old_upload.dso"]["version"] == "uploads"
    assert "decompiled_code" not in by["xbox/scriptc/a.cso"]        # the list stays light
    assert items[0]["version"] == "xbox"                              # retail first


def test_index_notices_new_files(server):
    assert len(server.script_index()[0]) == 9
    (server.SCRIPTS_DIR / "prototype" / "scriptc" / "b.cso").write_bytes(b"new")
    assert len(server.script_index()[0]) == 10


def test_detail_reads_one_file_and_refuses_paths_outside(server):
    cs = server.script_detail("prototype/packages/azones/x/x.cs")
    assert cs["ok"] and "Renderer_PropCreateBegin" in cs["decompiled_code"] and "source" in cs["format"]
    bad = server.script_detail("xbox/scriptc/a.cso")                  # not a real compiled script
    assert bad["ok"] and bad["format"] == "could not be read"
    for path in ("../../decomp_portal_server.py", "xbox/art/notes.txt", "", "xbox/nothing.cso"):
        assert not server.script_detail(path)["ok"], path

