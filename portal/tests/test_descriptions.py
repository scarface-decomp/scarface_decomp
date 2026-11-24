"""One-line descriptions: where each came from, the quality gate, the counts, and copying to twins."""
import json
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "portal" / "tools"))
sys.path.insert(0, str(ROOT / "portal" / "scripts"))
import descriptions as D  # noqa: E402
import describe_twins as T  # noqa: E402


def test_where_a_description_came_from():
    ai = "Claude (AI), for RRutherrfordd"
    assert D.how_of({"what": ""}) == ""
    assert D.how_of({"what": "Turns the headlights on.", "what_by": "lemiur"}) == "human"
    assert D.how_of({"what": "X", "what_by": "lemiur", "what_how": "read"}) == "read"     # stored wins
    for shape in ("Foo's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.",
                  "Returns Foo's static class record (ConcreteClassRep<Foo>), the object's run-time type.",
                  "Static initialiser for Foo's class record: fills in two of its fields (one through sub_00070520) at program start.",
                  "Foo::vfunc_03: Returns 0.", "Does nothing (an empty function, e.g. a base-class default)."):
        assert D.how_of({"what": shape, "what_by": ai}) == "shape", shape
    assert D.how_of({"what": "AI condition 'not': true when the condition it wraps is false.", "what_by": ai}) == "read"
    assert [D.normal_how(x) for x in ("by shape", "read", "", "twin", "whatever", "bound")] == \
        ["shape", "read", "human", "twin", "human", "bound"]


def test_the_quality_gate():
    assert D.problem("Turns the car's headlights on or off.") is None
    assert "longer than 160" in D.problem("x" * 161)
    assert "restates the code" in D.problem("Calls sub_00012340(DAT_00450000, 0x20, 8).")
    assert D.problem("Calls sub_00012340 to reset the car.") is None
    assert D.problem("   ") == "empty"


def test_counts_split_by_version_and_origin():
    entries = [{"bin": "xb", "what": "A thing.", "what_how": "read"},
               {"bin": "xb", "what": "B.", "what_how": "shape"},
               {"bin": "pc", "what": "C."},
               {"bin": "proto", "what": "D.", "what_how": "twin"},
               {"bin": "xb", "what": ""}]
    c = D.counts(entries)
    assert (c["xb"], c["pc"], c["proto"], c["total"]) == (2, 1, 1, 3)
    assert c["how"] == {"human": 1, "read": 1, "bound": 0, "shape": 1, "twin": 0}          # the released game only


def test_twins_take_the_description_only_when_the_code_is_the_same():
    entries = {
        "xb:0x00010000": {"symbol": "Foo::vfunc_01", "what": "Foo: returns 4.", "what_by": "lemiur"},
        "proto:0x00020000": {"symbol": "Foo::vfunc_01"},                                     # same shape: copied
        "xb:0x00010100": {"symbol": "Bar::vfunc_00", "what": "Bar thing.", "what_by": "lemiur"},
        "proto:0x00020100": {"symbol": "Bar::vfunc_00"},                                     # paired by text only
        "xb:0x00010200": {"symbol": "Baz::vfunc_00", "what": "Baz thing.", "what_by": "lemiur"},
        "proto:0x00020200": {"symbol": "Qux::vfunc_00"},                                     # another class
        "xb:0x00010300": {"symbol": "sub_00010300", "what": "Old.", "what_by": "lemiur"},
        "proto:0x00020300": {"symbol": "sub_00020300", "what": "Its own."},                 # described already
    }
    pairing = {"pairs": [["0x00010000", "0x00020000", 8, "shape", ""], ["0x00010100", "0x00020100", 8, "text", ""],
                         ["0x00010200", "0x00020200", 8, "shape", ""], ["0x00010300", "0x00020300", 8, "shape", ""],
                         ["0x00010400", "0x00020400", 8, "shape", ""]]}
    out = T.plan(entries, {"proto": pairing})
    assert list(out) == ["proto:0x00020000"]
    assert out["proto:0x00020000"] == {"what": "Foo: returns 4.", "by": "lemiur (from the Xbox twin)", "how": "twin",
                                       "from": "xb:0x00010000"}


def test_the_recorded_descriptions_pass_the_gate():
    entries = json.loads((ROOT / "reports" / "verified_registry.json").read_text(encoding="utf-8"))["entries"]
    bad = {k: D.problem(e["what"]) for k, e in entries.items() if (e.get("what") or "").strip() and D.problem(e["what"])}
    assert not bad, list(bad.items())[:5]
