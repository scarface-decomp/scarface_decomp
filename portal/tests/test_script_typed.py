"""
Typed script bindings (portal/tools/script_typed.py), on a made-up Xbox program: no game bytes.
"""
import struct

import pytest
from conftest import make_xbe

import script_commands as SC
import script_typed as T
from sf_binaries import BinaryImage

pytest.importorskip("capstone")
TEXT, DATA = 0x11000, 0x400000


def test_signature_from_the_functors_class_name():
    assert T.signature("Method", 5, "X_NW4EMeleeAttackType@CharacterObject@@H_NPBD") == (
        "void", ["bool", "CharacterObject::EMeleeAttackType", "int", "bool", "const char*"])
    assert T.signature("Function", 2, "MVVector@math@@V12@") == ("float", ["math::Vector", "math::Vector"])
    assert T.signature("Function", 2, "PAVScriptObject@@PBDI") == ("ScriptObject*", ["const char*", "unsigned int"])
    with pytest.raises(T.BadType):
        T.signature("Function", 2, "XH")                       # one argument short


def u32(v):
    return struct.pack("<I", v)


def program(tmp_path):
    data = bytearray(b"\0" * 4)                                 # "" at DATA
    where = {"": DATA}
    for s in ("SetSpeed", "Thing", "Go"):
        where[s] = DATA + len(data)
        data += s.encode() + b"\0"
    while len(data) % 4:
        data += b"\0"
    td = DATA + len(data)
    data += u32(0) * 2 + b".?AV?$Method1@XM@CScript@@\0"
    while len(data) % 4:
        data += b"\0"
    col = DATA + len(data)
    data += u32(0) * 3 + u32(td) + u32(0)
    data += u32(col)
    vt = DATA + len(data)
    data += u32(TEXT + 0x400)                                   # the functor's invoke
    code = bytearray(b"\xCC" * 0x1000)

    def put(at, b):
        code[at:at + len(b)] = b

    put(0x100, b"\xC7\x06" + u32(vt) + b"\xC3")                 # the helper: mov [esi], vtable; ret
    site = b"\x33\xDB"                                          # xor ebx, ebx (the this adjustment, kept in a register)
    site += b"\x68" + u32(where[""]) + b"\x6A\x03\x6A\x03" + b"\x53" + b"\x68" + u32(TEXT + 0x300)
    site += b"\x68" + u32(where[""]) + b"\x68" + u32(where["SetSpeed"]) + b"\x68" + u32(where["Thing"])
    call_at = 0x200 + len(site)
    site += b"\xE8" + struct.pack("<i", (TEXT + 0x100) - (TEXT + call_at + 5)) + b"\x83\xC4\x20\xC3"
    put(0x200, site)
    put(0x300, b"\xC2\x04\x00")                                 # Thing::SetSpeed itself
    put(0x400, b"\xC3")
    put(0x500, b"\x8B\x4C\x24\x04\xE9" + struct.pack("<i", (TEXT + 0x600) - (TEXT + 0x500 + 9)))   # a forwarding handler
    put(0x600, b"\xC3")
    path = make_xbe(tmp_path / "default.xbe", [(".text", TEXT, bytes(code), 0x6), (".data", DATA, bytes(data), 0x1)])
    functions = {TEXT + 0x100: {"size": 7, "symbol": "sub_00011100"}, TEXT + 0x200: {"size": len(site), "symbol": "sub_00011200"},
                 TEXT + 0x300: {"size": 3, "symbol": "sub_00011300"}, TEXT + 0x600: {"size": 1, "symbol": "sub_00011600"}}
    return BinaryImage(path), functions, TEXT + call_at


def test_a_registration_is_read_with_its_signature(tmp_path):
    img, functions, call_at = program(tmp_path)
    rows, problems = T.find(img, functions)
    assert problems == []
    assert [(r["at"], r["cls"], r["name"], r["fn"], r["fewest"], r["most"], r["ret"], r["args"]) for r in rows] == [
        (call_at, "Thing", "SetSpeed", TEXT + 0x300, 3, 3, "void", ["float"])]
    assert T.prototype(rows[0]) == "void Thing::SetSpeed(float)"


def test_names_for_bound_functions_and_forward_targets(tmp_path):
    img, functions, _ = program(tmp_path)
    rows, _ = T.find(img, functions)
    fwd = T.forwards(img, functions, [SC.Command("Thing", "Go", TEXT + 0x500, 2, 2, TEXT + 0x700)])
    assert [(r["how"], r["target"]) for r in fwd] == [("jmp", TEXT + 0x600)]
    names = T.names_for(rows, fwd, functions, "xb")
    assert names["xb:0x00011300"]["name"] == "Thing::SetSpeed" and "void Thing::SetSpeed(float)" in names["xb:0x00011300"]["why"]
    assert names["xb:0x00011600"]["name"] == "Thing::Go" and names["xb:0x00011600"]["by"] == T.BY_FORWARD
    assert SC.NAMES.problems({"schema": SC.NAMES.SCHEMA, "names": names}) == []
    data = {"names": {"xb:0x00011300": {"name": "Mine", "by": "Alice", "why": "I read it."}}}
    assert T.merge(data, names) == 1 and data["names"]["xb:0x00011300"]["name"] == "Mine"


def test_returns_come_from_the_record_constructor(tmp_path):
    code = bytearray(b"\xCC" * 0x100)
    code[0x00:0x06] = b"\x89\x48\x04\xC2\x18\x00"               # mov [eax+4], ecx; ret 0x18  -> int
    code[0x10:0x15] = b"\x89\x08\xC2\x18\x00"                   # mov [eax], ecx; ret 0x18    -> string
    code[0x20:0x26] = b"\x89\x48\x10\xC2\x18\x00"               # -> bool
    img = BinaryImage(make_xbe(tmp_path / "default.xbe", [(".text", TEXT, bytes(code), 0x6), (".data", DATA, b"\0" * 16, 0x1)]))
    assert [SC.returns_of(img, TEXT + a) for a in (0x00, 0x10, 0x20, 0x40)] == ["int", "string", "bool", ""]
