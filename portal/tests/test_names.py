"""Function names: reports/names.json and its checks, the Ghidra and IDA scripts' reading of the function lists,
and the portal showing a name. Nothing here needs Ghidra, IDA or the game."""
import importlib.util
import json

import pytest

from conftest import PORTAL

import names as NAMES


def _script(name):
    spec = importlib.util.spec_from_file_location(name, PORTAL / "scripts" / f"{name}.py")
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)          # neither runs anything outside Ghidra or IDA
    return mod


GHIDRA, IDA = _script("ghidra_scarface_names"), _script("ida_scarface_names")

LISTING = """// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, every function in address order
// [TODO] 0x00011010 sub_00011010 (353 B)
// ============================================================================
// [VERIFIED] CoverObject::Update (0x00011180, 24 B)
// By: someone | Flags: /O2
// ============================================================================
void CoverObject::Update() {}

// [TODO] 0x000111A0 pure3d::Channel<math::Quat6>::vfunc_03 (6 B)
// [TODO] 0x000111C0 sub_000111C0 (10 B)
"""


@pytest.fixture
def repo(tmp_path):
    (tmp_path / "reconstructed_src").mkdir()
    (tmp_path / "reports").mkdir()
    (tmp_path / "reconstructed_src" / "Original_Binary_Order_Xbox.cpp").write_text(LISTING, encoding="utf-8")
    (tmp_path / "reports" / "names.json").write_text(json.dumps({"schema": NAMES.SCHEMA, "names": {
        "xb:0x000111C0": {"name": "Weapon::Reload", "by": "Alice", "why": "reads the ammo count and plays reload.rsd"},
        "xb:0x00011180": {"name": "Not::This", "by": "Bob", "why": "the verified name stays as it is"},
        "pc:0x000111C0": {"name": "Other::Version", "by": "Bob", "why": "another version's list"},
    }}), encoding="utf-8")
    return tmp_path


@pytest.mark.parametrize("mod", [GHIDRA, IDA], ids=["ghidra", "ida"])
def test_scripts_read_every_function_with_names_on_top(repo, mod):
    funcs = mod.read_functions(str(repo), mod.VERSIONS[0])
    assert funcs == [(0x11010, 353, "sub_00011010", False), (0x11180, 24, "CoverObject::Update", True),
                     (0x111A0, 6, "pure3d::Channel<math::Quat6>::vfunc_03", False),
                     (0x111C0, 10, "Weapon::Reload", False)]
    assert mod.guess_version("SLUS_211.11")[1] == "Original_Binary_Order_PS2.cpp"
    assert mod.guess_version("game.xbe")[2] == "proto" and mod.guess_version("default.xbe")[2] == "xb"


def test_ghidra_splits_names_into_namespaces():
    assert GHIDRA.split_name("pure3d::Channel<math::Quat6>::vfunc_03") == ["pure3d", "Channel<math_Quat6>", "vfunc_03"]
    assert GHIDRA.split_name("sub_00011010") == ["sub_00011010"]


def test_ida_finds_the_repository_from_any_file(repo):
    (repo / "docs").mkdir()
    (repo / "docs" / "x.md").write_text("x")
    assert IDA.find_repo(str(repo / "docs" / "x.md")) == str(repo)
    assert IDA.find_repo("/") is None


def test_the_scripts_agree():
    for a, b in zip(GHIDRA.VERSIONS, IDA.VERSIONS):
        assert a == b
    assert GHIDRA.TODO_RE.pattern == IDA.TODO_RE.pattern and GHIDRA.DONE_RE.pattern == IDA.DONE_RE.pattern


def test_names_file_checks():
    good = {"schema": NAMES.SCHEMA, "names": {"xb:0x000111C0": {"name": "Weapon::Reload", "by": "Alice",
                                                                 "why": "plays reload.rsd and resets the clip"}}}
    assert NAMES.problems(good, {"xb": {0x111C0}}) == []
    assert NAMES.problems({"schema": NAMES.SCHEMA, "names": {"xb:0x000111C0": {"name": "audio::Seq<int>::~Seq", "by": "A", "why": "destroys the sequence"}}}) == []
    overlay = {"schema": NAMES.SCHEMA, "names": {"ps2pause:0x00845500": {"name": "PauseMenu::Init", "by": "A",
                                                                         "why": "sets up the pause menu's pages"}}}
    assert NAMES.problems(overlay, {"ps2pause": {0x845500}}) == []          # a PS2 overlay's function
    bad = {"schema": "x", "names": {
        "xb:0x111c0": {"name": "A::b", "by": "x", "why": "long enough reason"},
        "xb:0x000111C0": {"name": "has space", "by": "", "why": "short"},
        "xb:0x000111D0": {"name": "sub_000111D0", "by": "x", "why": "long enough reason"},
        "ps2:0x00100000": {"name": "Dup::Name", "by": "x", "why": "long enough reason"},
        "ps2:0x00100010": {"name": "Dup::Name", "by": "x", "why": "long enough reason"},
    }}
    text = "\n".join(NAMES.problems(bad, {"xb": {0x111C0}, "ps2": {0x100000, 0x100010}}))
    for want in ("schema must be", "keys look like", "isn't a C++ function name", "say who", "say in a sentence",
                 "no function starts there", "already the name of"):
        assert want in text


def test_the_repository_names_file_is_valid():
    from conftest import ROOT
    data = NAMES.load(ROOT / "reports" / "names.json")
    assert data["schema"] == NAMES.SCHEMA and NAMES.problems(data) == []


def test_portal_shows_a_known_name(monkeypatch, repo):
    import sys
    sys.path.insert(0, str(PORTAL))
    server = importlib.import_module("decomp_portal_server")
    monkeypatch.setattr(server, "REPORTS_DIR", repo / "reports")
    monkeypatch.setattr(server, "_NAMES_CACHE", [None, {}])
    t = {"bin": "xb", "fva_int": 0x111C0, "status": "UNCLAIMED"}
    assert server.community_name(t)["name"] == "Weapon::Reload"
    assert server.community_name(dict(t, fva_int=0x11010)) is None


def test_names_code_may_call_a_function_by(monkeypatch, repo):
    data = {"names": {"xb:0x000111C0": {"name": "Weapon::Reload"}, "pc:0x00401000": {"name": "Weapon::Reload"},
                      "xb:0x00011200": {"name": "Car::Honk"}, "xb:0x00011300": {"name": "Car::Honk"},
                      "xb:nonsense": {"name": "X"}, "xb:0x00011400": "oops"}}
    assert NAMES.addresses(data, "xb") == {"Weapon::Reload": 0x111C0}          # a name used twice is left out
    assert NAMES.addresses(data, "pc") == {"Weapon::Reload": 0x401000} and NAMES.addresses({}, "xb") == {}
    import sys
    sys.path.insert(0, str(PORTAL))
    server = importlib.import_module("decomp_portal_server")
    monkeypatch.setattr(server, "REPORTS_DIR", repo / "reports")
    monkeypatch.setattr(server, "_NAMES_CACHE", [None, {}])
    monkeypatch.setattr(server, "_KNOWN_NAMES", {})
    assert server.known_names("xb")["Weapon::Reload"] == 0x111C0
    t = {"bin": "xb", "fva_int": 0x11000}
    code = "// like sub_000111C0\nvoid sub_00011000() { sub_000111C0(); sub_000111C0(); sub_00011010(); }"
    assert server.names_to_use(t, code) == [{"now": "sub_000111C0", "name": "Weapon::Reload"}]
    assert server.names_to_use(t, "// only says sub_000111C0 in a comment\nvoid f() {}") == []
    assert server.names_to_use(dict(t, fva_int=0x111C0), "void sub_000111C0() {}") == []


def test_a_name_given_in_the_portal(monkeypatch, repo, tmp_path):
    import sys
    sys.path.insert(0, str(PORTAL))
    server = importlib.import_module("decomp_portal_server")
    monkeypatch.setattr(server, "REPORTS_DIR", repo / "reports")
    monkeypatch.setattr(server, "_NAMES_CACHE", [None, {}])
    monkeypatch.setattr(server, "_KNOWN_NAMES", {})
    monkeypatch.setattr(server, "_GRADES", {})
    monkeypatch.setattr(server, "NAMES_ADDED_JSON", tmp_path / "names_added.json")
    monkeypatch.setattr(server, "published_keys", lambda: frozenset())
    monkeypatch.setattr(server, "_PUBLISHED", {"names": {}})
    monkeypatch.setattr(server, "MAINTAINERS", {"Boss"})
    t = {"bin": "xb", "fva_int": 0x11190, "symbol": "sub_00011190"}
    code = "void sub_00011190(int count) { total = count; }"
    monkeypatch.setattr(server, "REGISTRY", {"entries": {"xb:0x00011190": {"symbol": "sub_00011190", "code": code}}})
    assert server.readable_grade("xb:0x00011190", code)["left"] == 1
    assert "isn't a C++ function name" in server.add_name(t, "not a name!", "It sets the running total.", "Alice")
    assert "what shows it" in server.add_name(t, "Hud::SetTotal", "short", "Alice")
    assert server.add_name(t, "Hud::SetTotal", "It stores its argument   in the running total.", "Alice") == ""
    saved = json.loads((repo / "reports" / "names.json").read_text(encoding="utf-8"))["names"]["xb:0x00011190"]
    assert saved == {"name": "Hud::SetTotal", "by": "Alice", "why": "It stores its argument in the running total."}
    assert server.readable_grade("xb:0x00011190", code)["left"] == 0            # its own name no longer counts against it
    assert server.community_name(t)["name"] == "Hud::SetTotal" and server.known_names("xb")["Hud::SetTotal"] == 0x11190
    assert list(server.pending_names()) == ["xb:0x00011190"]                    # sent with Submit your work
    assert "already named Hud::SetTotal (by Alice)" in server.add_name(t, "Hud::Other", "It does something else here.", "Bob")
    assert server.add_name(t, "Hud::SetRunningTotal", "It stores its argument in the running total.", "Boss") == ""   # a maintainer may
    assert "already the name" in server.add_name({"bin": "xb", "fva_int": 0x111C0, "symbol": "sub_000111C0"},
                                                 "Hud::SetRunningTotal", "Another function entirely.", "Boss")
    monkeypatch.setattr(server, "_PUBLISHED", {"names": {"xb:0x00011190": server.community_names()["xb:0x00011190"]}})
    assert server.pending_names() == {}                                         # on GitHub now
