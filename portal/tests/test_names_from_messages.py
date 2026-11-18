"""
Function names the program's own log messages give (portal/scripts/names_from_messages.py).
"""
import importlib.util
import struct
import types

from conftest import ROOT

spec = importlib.util.spec_from_file_location("names_from_messages", ROOT / "portal" / "scripts" / "names_from_messages.py")
NM = importlib.util.module_from_spec(spec)
spec.loader.exec_module(NM)

BASE = 0x10000


def image(code: bytes, text: bytes):
    data = code.ljust(0x100, b"\x90") + text
    sec = types.SimpleNamespace(va=BASE, raw=0, raw_size=len(data), is_code=True)
    return types.SimpleNamespace(data=data, sections=[sec])


def at(text: bytes, word: bytes) -> bytes:
    return struct.pack("<I", BASE + 0x100 + text.index(word))


def test_a_message_names_the_one_function_that_pushes_it():
    text = b"\0SaveGame::Init\0Hud::Show (state %d)\0Con::prompt\0Twice::Used\0Lone::Data\0plain words\0"
    code = (b"\x68" + at(text, b"SaveGame::Init") + b"\xC3").ljust(0x10, b"\x90")            # f0: push; ret
    code += (b"\x68" + at(text, b"Hud::Show") + b"\x68" + at(text, b"Con::prompt") + b"\xC3").ljust(0x10, b"\x90")   # f1
    code += (b"\x68" + at(text, b"Twice::Used") + b"\xC3").ljust(0x10, b"\x90")                # f2 and f3 both use one
    code += (b"\x68" + at(text, b"Twice::Used") + b"\xC3").ljust(0x10, b"\x90")
    code += (b"\xA1" + at(text, b"Lone::Data") + b"\xC3").ljust(0x10, b"\x90")                 # f4 reads it, no push
    funcs = [(BASE + 0x10 * i, 0x10, s) for i, s in enumerate(
        ["sub_00010000", "Hud::vfunc_03", "sub_00010020", "sub_00010030", "sub_00010040"])]
    got = NM.messages(image(code, text), funcs)
    assert got == [("SaveGame::Init", "SaveGame::Init", BASE, "sub_00010000"),
                   ("Hud::Show", "Hud::Show (state %d)", BASE + 0x10, "Hud::vfunc_03")]


def test_a_message_about_another_class_is_not_taken(monkeypatch):
    text = b"\0Other::Thing\0Mine::Go\0"
    code = (b"\x68" + at(text, b"Other::Thing") + b"\xC3").ljust(0x10, b"\x90") + (b"\x68" + at(text, b"Mine::Go") + b"\xC3")
    known = {BASE: {"size": 0x10, "symbol": "Mine::vfunc_02"}, BASE + 0x10: {"size": 0x10, "symbol": "ns::Mine::vfunc_05"}}
    monkeypatch.setattr(NM, "hierarchy", lambda img: ({}, {}))
    found = NM.find("xb", image(code, text), known)
    assert list(found) == [BASE + 0x10] and found[BASE + 0x10][0] == "ns::Mine::Go"
    assert "Mine::Go" in found[BASE + 0x10][1] and "class information" in found[BASE + 0x10][1]


def test_a_slot_two_classes_name_is_carried_to_the_others(monkeypatch):
    text = b"\0A::Open\0B::Open\0C::Close\0"
    code = b""
    for word in (b"A::Open", b"B::Open", b"C::Close"):
        code += (b"\x68" + at(text, word) + b"\xC3").ljust(0x10, b"\x90")
    code += b"\xC3".ljust(0x10, b"\x90") * 2                                                    # D's slot 1, D's slot 2
    syms = ["A::vfunc_01", "B::vfunc_01", "C::vfunc_02", "D::vfunc_01", "D::vfunc_02"]
    known = {BASE + 0x10 * i: {"size": 0x10, "symbol": s} for i, s in enumerate(syms)}
    f = [BASE + 0x10 * i for i in range(5)]
    bases = {"A": ["Base"], "B": ["Base"], "C": ["Base"], "D": ["Base"], "Base": [], "Loner": []}
    tables = {"A": [0, f[0], 0], "B": [0, f[1], 0], "C": [0, 0, f[2]], "D": [0, f[3], f[4]], "Base": [0, 0, 0], "Loner": [0, f[3]]}
    monkeypatch.setattr(NM, "hierarchy", lambda img: (bases, tables))
    found = NM.find("xb", image(code, text), known)
    assert {va: n for va, (n, _w) in found.items()} == {f[0]: "A::Open", f[1]: "B::Open", f[2]: "C::Close", f[3]: "D::Open"}
    assert "Slot 1 of Base" in found[f[3]][1] and "2 of its derived classes (A, B)" in found[f[3]][1]
    # C alone says slot 2 is Close: not enough to name D's slot 2


def test_a_ps2_function_takes_its_xbox_twins_name():
    spec2 = importlib.util.spec_from_file_location("names_to_ps2", ROOT / "portal" / "scripts" / "names_to_ps2.py")
    P2 = importlib.util.module_from_spec(spec2)
    spec2.loader.exec_module(P2)
    names = {"xb:0x000C7EC0": {"name": "SaveGameController::SaveInit"}, "xb:0x0018B960": {"name": "ExoticsHUD2::DeactivateElement"}}
    same = "Stored in the data; 140 bytes. Same function as Xbox 0x%s: %s."
    tasks = [
        {"bin": "ps2", "fva_int": 0x49FE30, "xbox_twin": "0x000C7EC0", "hint": same % ("000C7EC0", 'it uses the same text ("SaveInit")')},
        {"bin": "ps2", "fva_int": 0x3D7EB0, "xbox_twin": "0x0018B960", "hint": same % ("0018B960", "its place in a table lines up")},
        {"bin": "ps2", "fva_int": 0x3FA6C0, "xbox_twin": "0x0018B960", "hint": same % ("0018B960", "its place in a table lines up")},
        {"bin": "ps2exotics", "fva_int": 0x845AF0, "xbox_twin": "0x0018B960", "hint": same % ("0018B960", "its place in a table lines up")},
        {"bin": "ps2", "fva_int": 0x100, "xbox_twin": "0x00011000", "hint": same % ("00011000", "same text")},    # twin not named
        {"bin": "ps2", "fva_int": 0x200, "xbox_twin": "0x000C7EC0", "hint": "Found after a call; 8 bytes."},      # no reason given
        {"bin": "xb", "fva_int": 0xC7EC0, "hint": ""},
    ]
    got = P2.twins(tasks, names)
    # the reasonless one is not counted, so SaveInit has one claim; two ps2 functions claim one twin: neither is taken
    assert [(k, n) for k, n, _w in got] == [("ps2:0x0049FE30", "SaveGameController::SaveInit"),
                                            ("ps2exotics:0x00845AF0", "ExoticsHUD2::DeactivateElement")]
    assert 'it uses the same text ("SaveInit")' in got[0][2] and "0x000C7EC0" in got[0][2]
