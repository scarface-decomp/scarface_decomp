import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))
import hash_names as H  # noqa: E402
import p3d  # noqa: E402
import torque_names as TN  # noqa: E402


def test_folded_key_is_the_games():
    for t in ("ScriptObject", "%playerObj", "$Mission_01", "x"):
        assert H.key(t) == p3d.name_key(t)


def test_case_sensitive_key_keeps_case():
    assert H.key("Abc", fold=False) != H.key("abc", fold=False)
    assert H.key("abc", fold=False) == H.key("abc")          # nothing below 'a': the same either way
    assert H.key("Ei", fold=False) == H.key("%i")             # why scripts are matched folded only


def test_demangle():
    assert H.demangle("ScriptObject") == ["ScriptObject"]
    assert H.demangle("IRefCount@core") == ["IRefCount", "core::IRefCount"]
    assert H.demangle("?$ConcreteClassRep@VFoo@@") == ["ConcreteClassRep"]


def test_compounds_and_vocabulary():
    words = H.vocabulary(["%musicFilter", "musicBox", "setFilter", "filterOn"])
    assert "music" in words and "filter" in words
    hits = H.compounds(words, {H.key("%musicFilter")})
    assert hits[H.key("%musicFilter")] == ["%musicFilter"]


def test_best_takes_certain_names_and_skips_ambiguous():
    table = {"keys": {
        "0x80000001": {"names": [{"text": "A", "certain": True}, {"text": "$b", "certain": False}]},
        "0x80000002": {"names": [{"text": "%x", "certain": False}]},
        "0x80000003": {"names": [{"text": "p", "certain": False}, {"text": "q", "certain": False}]},
    }}
    assert H.best(table) == {0x80000001: "A"}
    assert H.best(table, dictionary=True) == {0x80000001: "A", 0x80000002: "%x"}


def test_write_round_trips(tmp_path):
    t = {"what": "w", "named": 1, "engine_callbacks": [{"bit": 0, "name": "Initialize", "key": "0xAC0E9D3E"}], "keys": {"0x80000078": {"stx": TN.stx(0x80000078), "names": [], "ambiguous": False}}}
    H.write(t, tmp_path / "h.json")
    assert H.load(tmp_path / "h.json") == t


def test_data_files_are_certain_and_short_executable_words_are_not(tmp_path):
    (tmp_path / "default.xbe").write_bytes(b"\0mad\0PauseGetCreditsLine\0")
    (tmp_path / "tree.dtr").write_bytes(b"\x01canFastTalk\x00")
    (tmp_path / "a.cs").write_text('mad(); PauseGetCreditsLine(); canFastTalk();')
    import torque_script as TS
    cso = tmp_path / "a.cso"
    cso.write_bytes(TS.compile_text((tmp_path / "a.cs").read_text()))
    (tmp_path / "a.cs").unlink()
    t = H.build(tmp_path, [cso, tmp_path / "tree.dtr"], compound=False)
    by = {v["names"][0]["text"]: v["names"][0] for v in t["keys"].values()}
    assert by["canFastTalk"]["source"] == "game data file" and by["canFastTalk"]["certain"]
    assert by["PauseGetCreditsLine"]["certain"] and by["PauseGetCreditsLine"]["source"] == "default.xbe"
    assert by["mad"]["source"] == "default.xbe" and not by["mad"]["certain"]
    assert H.key("Initialize") == 0xAC0E9D3E


def test_renumberings_keep_the_width_and_try_plain_numbers():
    r = H.renumberings("S02_01")
    assert "S02_03" in r and "S10_01" in r and "S02_01" not in r
    assert "S2_01" not in r and "S02_3" not in r          # a number written with a leading zero keeps its width
    r = H.renumberings("Wave10Driver1")
    assert "Wave9Driver1" in r and "Wave09Driver1" in r and "Wave10Driver7" in r
    assert H.renumberings("NoNumber") == [] and H.renumberings("Hash12345") == []
    assert len(r) == len(set(r))


def test_renumbered_finds_the_rest_of_a_run_and_goes_on_from_what_it_finds():
    wanted = {H.key("S02_03"), H.key("S10_03"), H.key("Other_1")}
    hits, tries = H.renumbered(["S02_01"], wanted)
    assert hits == {H.key("S02_03"): ["S02_03"], H.key("S10_03"): ["S10_03"]}     # S10_03 by way of S02_03
    assert tries > 0
    assert H.renumbered(["S02_01"], wanted, rounds=1)[0] == {H.key("S02_03"): ["S02_03"]}


def test_build_marks_renumbered_names_as_not_certain(tmp_path):
    import torque_script as TS
    (tmp_path / "default.xbe").write_bytes(b"\0MissionSlot_01\0")
    cso = tmp_path / "a.cso"
    cso.write_bytes(TS.compile_text("MissionSlot_01(); MissionSlot_02();"))
    t = H.build(tmp_path, [cso], compound=False)
    by = {v["names"][0]["text"]: v["names"][0] for v in t["keys"].values()}
    assert by["MissionSlot_01"]["certain"]
    assert by["MissionSlot_02"] == {"text": "MissionSlot_02", "fold": True, "source": H.RENUMBERED, "certain": False}
    assert "renumbered_chance_hits" in t
    off = H.build(tmp_path, [cso], compound=False, renumber=False)
    assert "MissionSlot_02" not in {v["names"][0]["text"] for v in off["keys"].values()}
    assert H.best(t) == {H.key("MissionSlot_01"): "MissionSlot_01"}
