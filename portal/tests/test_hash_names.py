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
    t = {"what": "w", "named": 1, "keys": {"0x80000078": {"stx": TN.stx(0x80000078), "names": [], "ambiguous": False}}}
    H.write(t, tmp_path / "h.json")
    assert H.load(tmp_path / "h.json") == t
