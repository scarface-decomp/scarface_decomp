"""
The starter C++ the portal writes for each function (portal/tools/starter_synth.py).

A starter has to compile, name every call and global for its address (sub_XXXXXXXX / DAT_XXXXXXXX, never
a number), and for simple functions it should already compile to the original bytes.
"""
import re
import struct

import pytest

from conftest import FLAGS, ROOT, make_xbe, needs_compiler, needs_pc

import decompme as D
import disasm_synth as DS
import msvc_verify as MV
from sf_binaries import BinaryImage

FN = 0x11000           # function under test
OTHER = 0x11100        # another function in .text
DATA = 0x30000         # a global in .data


def call(at: int, target: int) -> bytes:
    return b"\xE8" + struct.pack("<i", target - (FN + at + 5))


def image_with(tmp_path, code: bytes) -> BinaryImage:
    text = bytearray(b"\xCC" * 0x200)
    text[:len(code)] = code
    text[0x100] = 0xC3
    return BinaryImage(make_xbe(tmp_path / "t.xbe", [(".text", FN, bytes(text), 0x6), (".data", DATA, b"\0" * 16, 0x7)]))


def starter(img: BinaryImage, code: bytes, symbol: str) -> str:
    return DS.synthesize_cpp(symbol, f"0x{FN:08X}", code, DS.disassemble(code), relocs=D.find_relocations(code, FN, img))


CASES = {
    # symbol: machine code. Each starter must compile back to exactly these bytes.
    "Foo::vfunc_01": bytes.fromhex("8B 41 10 C3"),                                   # return m_Field10;
    "Foo::vfunc_02": bytes.fromhex("8B 44 24 04 89 41 08 C2 04 00"),                 # m_Field08 = a1;
    "sub_00011000": b"\xA1" + struct.pack("<I", DATA) + b"\xC3",                     # return DAT_00030000;
    "Bar::vfunc_00": bytes.fromhex("56 8B F1") + call(3, OTHER) + bytes.fromhex("8B C6 5E C3"),
    "Baz::vfunc_04": bytes.fromhex("8B 41 08 85 C0 74 03 B0 01 C3 32 C0 C3"),         # return m_Field08 != 0;
    # push ebp; mov ebp, esp ... pop ebp: built with frame pointers kept.
    "Frame::vfunc_03": bytes.fromhex("55 8B EC 8B 45 08 89 41 08 5D C2 04 00"),      # m_Field08 = a1;
    "Fwd::vfunc_01": bytes.fromhex("55 8B EC 5D") + b"\xE9" + struct.pack("<i", OTHER - (FN + 9)),   # hands a1 on
    # movss: built with /arch:SSE.
    "Sse::vfunc_02": bytes.fromhex("F3 0F 10 44 24 04 F3 0F 11 41 08 C2 04 00"),     # m_Field08 = a1; (floats)
    "Bits::vfunc_01": bytes.fromhex("8A 41 1C D0 E8 24 01 C3"),                      # return (one bit of +0x1C);
    "Flag::vfunc_01": bytes.fromhex("8B 51 08 33 C0 85 D2 0F 95 C0 C3"),             # int: return m_Field08 != 0;
    "Short::vfunc_01": bytes.fromhex("66 8B 41 08 C3"),                              # return m_Field08; (a short)
    "No::vfunc_02": bytes.fromhex("32 C0 C2 08 00"),                                 # return false;
}


@pytest.mark.parametrize("symbol", sorted(CASES))
def test_starter_names_things_by_address_and_never_by_number(tmp_path, symbol):
    code = CASES[symbol]
    cpp = starter(image_with(tmp_path, code), code, symbol)
    assert "Callee" not in cpp and "TODO" not in cpp
    assert not re.search(r"\b(eax|ecx|edx|esi|edi|ebx)\b(?!_)", cpp.split("\n", 3)[-1]), cpp
    assert "196608" not in cpp and "0x30000" not in cpp.upper().replace("DAT_00030000", "")
    if code[:1] == b"\xA1":
        assert 'extern "C" int DAT_00030000;' in cpp and "return DAT_00030000;" in cpp
    if symbol.startswith("Bar"):
        assert "sub_00011100" in cpp and "return this;" in cpp


# Code MSVC itself writes for these, so the starter can reproduce it byte for byte (the Baz example is
# hand-made: MSVC would use setne there, so it only checks the shape of the C++).
EXACT = sorted(k for k in CASES if not k.startswith("Baz"))



@needs_compiler
@pytest.mark.parametrize("symbol", EXACT)
def test_starter_compiles_to_the_original_bytes(tmp_path, symbol):
    code = CASES[symbol]
    img = image_with(tmp_path, code)
    cpp = starter(img, code, symbol)
    res = {}
    for flags in MV.flag_options("xb", FLAGS, code):
        res = MV.verify_submission(cpp, code, flags, "", fn_va=FN, image=img)
        assert res.get("ok"), res.get("compiler_error")
        if res["is_exact"]:
            break
    assert res["is_exact"] and not res.get("hardcoded_addresses"), cpp


def test_a_frame_pointer_turns_frame_pointers_on(tmp_path):
    code = CASES["Frame::vfunc_03"]
    cpp = starter(image_with(tmp_path, code), code, "Frame::vfunc_03")
    assert '#pragma optimize("y", off)' in cpp and "m_Field08 = a1;" in cpp
    plain = CASES["Foo::vfunc_02"]
    assert "#pragma" not in starter(image_with(tmp_path, plain), plain, "Foo::vfunc_02")


def test_a_frame_pointer_and_a_jump_means_the_arguments_are_handed_on(tmp_path):
    code = CASES["Fwd::vfunc_01"]
    cpp = starter(image_with(tmp_path, code), code, "Fwd::vfunc_01")
    assert "vfunc_01(int a1)" in cpp and "sub_00011100(a1);" in cpp


def test_sse_code_reads_as_float_code(tmp_path):
    code = CASES["Sse::vfunc_02"]
    cpp = starter(image_with(tmp_path, code), code, "Sse::vfunc_02")
    assert "float m_Field08;" in cpp and "vfunc_02(float a1)" in cpp and "m_Field08 = a1;" in cpp and "TODO" not in cpp
    assert MV.uses_sse(code) and not MV.uses_sse(CASES["Foo::vfunc_02"])
    no_eh = FLAGS.replace(" /EHsc", "")               # no exception frame: also tried without /EHsc, last
    assert MV.flag_options("xb", FLAGS, code) == [FLAGS, FLAGS + " /arch:SSE", no_eh, no_eh + " /arch:SSE"]
    assert MV.flag_options("proto", FLAGS, code)[-1].endswith("/arch:SSE")
    assert MV.flag_options("xb", FLAGS, CASES["Foo::vfunc_02"]) == [FLAGS, no_eh]
    assert MV.flag_options("xb", no_eh, CASES["Foo::vfunc_02"]) == [no_eh]
    assert MV.flag_options("pc", FLAGS, code) == [FLAGS, FLAGS.replace("/G6", "/G7")]


def test_one_bit_of_a_byte_is_a_bitfield_member(tmp_path):
    code = CASES["Bits::vfunc_01"]
    cpp = starter(image_with(tmp_path, code), code, "Bits::vfunc_01")
    assert "unsigned char : 1;" in cpp and "unsigned char m_Field1C_bit1 : 1;" in cpp
    assert "bool vfunc_01()" in cpp and "return m_Field1C_bit1;" in cpp and ">>" not in cpp


def test_the_return_type_follows_how_much_of_eax_is_filled(tmp_path):
    def of(symbol):
        return starter(image_with(tmp_path, CASES[symbol]), CASES[symbol], symbol)
    assert "int vfunc_01()" in of("Flag::vfunc_01") and "return m_Field08 != 0;" in of("Flag::vfunc_01")
    assert "unsigned short vfunc_01()" in of("Short::vfunc_01")
    assert "bool vfunc_02(int a1, int a2)" in of("No::vfunc_02") and "return false;" in of("No::vfunc_02")


def test_neg_sbb_is_read_as_a_comparison(tmp_path):
    # mov eax, [ecx+8]; neg eax; sbb eax, eax; neg eax; ret  and the same ending in inc eax
    for tail, want in (("F7 D8", "return m_Field08 != 0;"), ("40", "return !m_Field08;")):
        code = bytes.fromhex("8B 41 08 F7 D8 1B C0 " + tail + " C3")
        cpp = starter(image_with(tmp_path, code), code, "Neg::vfunc_01")
        assert want in cpp and "TODO" not in cpp, cpp


def test_the_other_reading_differs_in_whether_a_value_is_returned(tmp_path):
    # mov eax, [ecx+8]; push eax; call OTHER; add esp, 4; ret: it may or may not pass the result on.
    code = bytes.fromhex("8B 41 08 50") + call(4, OTHER) + bytes.fromhex("83 C4 04 C3")
    img = image_with(tmp_path, code)
    all_ = DS.synthesize_all("Pass::vfunc_01", f"0x{FN:08X}", code, DS.disassemble(code), relocs=D.find_relocations(code, FN, img))
    assert len(all_) == 2 and all_[0] == starter(img, code, "Pass::vfunc_01")
    assert "void vfunc_01()" in all_[0] and "int vfunc_01()" in all_[1] and "return sub_00011100(m_Field08);" in all_[1]


def test_a_signed_test_makes_the_member_signed(tmp_path):
    # cmp word ptr [ecx+8], 0; jle +3; mov al, 1; ret; xor al, al; ret
    code = bytes.fromhex("66 83 79 08 00 7E 03 B0 01 C3 32 C0 C3")
    cpp = starter(image_with(tmp_path, code), code, "Signed::vfunc_01")
    assert "    short m_Field08;" in cpp and "unsigned short" not in cpp


def test_a_byte_compare_reads_one_byte(tmp_path):
    # mov eax, [ecx+8]; cmp byte ptr [eax], 0; je +3; mov al, 1; ret; xor al, al; ret
    code = bytes.fromhex("8B 41 08 80 38 00 74 03 B0 01 C3 32 C0 C3")
    cpp = starter(image_with(tmp_path, code), code, "Byte::vfunc_01")
    assert "*(unsigned char*)" in cpp and "*(int*)" not in cpp


def test_a_built_in_template_argument_is_not_declared(tmp_path):
    code = CASES["Foo::vfunc_01"]
    cpp = starter(image_with(tmp_path, code), code, "om::Command0<void>::vfunc_01")
    assert "class void" not in cpp and "Command0<void>::vfunc_01" in cpp


def test_a_bool_call_result_can_be_passed_on(tmp_path):
    # mov al, [ecx+8]; test al, al; jne +3; xor al, al; ret; call OTHER; ret
    code = bytes.fromhex("8A 41 08 84 C0 75 03 32 C0 C3") + call(10, OTHER) + b"\xC3"
    cpp = starter(image_with(tmp_path, code), code, "Pass::vfunc_02")
    assert "bool vfunc_02()" in cpp and "bool __cdecl sub_00011100" in cpp, cpp


def test_branches_become_if_blocks(tmp_path):
    code = CASES["Baz::vfunc_04"]
    cpp = starter(image_with(tmp_path, code), code, "Baz::vfunc_04")
    assert "bool vfunc_04()" in cpp and "goto" not in cpp and "return true;" in cpp and "return false;" in cpp


def test_garbage_never_breaks_the_starter():
    code = bytes.fromhex("FF FF 0F 0B C7 C7 9A 12 34")
    cpp = DS.synthesize_cpp("sub_00401000", "0x00401000", code, DS.disassemble(code))
    assert "sub_00401000" in cpp


def test_disassembly_keeps_one_format():
    lines = DS.disassemble(bytes.fromhex("8B 44 24 08 0F B6 41 04 C6 41 05 01 C3"))
    assert "mov eax, [esp+0x8]" in lines[0]                 # small displacements are hex too
    assert "movzx eax, byte ptr [ecx+0x4]" in lines[1]      # the size is kept where it is the only clue
    assert "mov byte ptr [ecx+0x5], 1" in lines[2]


REAL = [
    # (game file, id, symbol, address, size, match). Their starters match the game exactly.
    ("Scarface.exe", "pc_006F7EC0", "audio::SeqEventNestTrack::vfunc_01", 0x006F7EC0, 52,
     "vfunc_01@SeqEventNestTrack@audio@@|vfunc_01@SeqEventNestTrack@audio@"),
    ("default.xbe", "xb_0020E7E0", "sub_0020E7E0", 0x0020E7E0, 48, "sub_0020E7E0"),
]


def _real(file: str):
    return pytest.mark.skipif(not (ROOT / "binaries" / file).exists(), reason=f"binaries/{file} missing")


@needs_compiler
@pytest.mark.parametrize("file,tid,symbol,va,size,match", [pytest.param(*r, marks=_real(r[0])) for r in REAL])
def test_real_functions_match_from_the_starter_alone(file, tid, symbol, va, size, match):
    img = BinaryImage(ROOT / "binaries" / file)
    code = img.read(va, size)
    cpp = DS.synthesize_cpp(symbol, f"0x{va:08X}", code, DS.disassemble(code), relocs=D.find_relocations(code, va, img))
    res = MV.verify_submission(cpp, code, FLAGS, match, fn_va=va, image=img)
    assert res.get("ok"), res.get("compiler_error")
    assert res["is_exact"] and not res.get("hardcoded_addresses"), cpp


@needs_compiler
@needs_pc
def test_the_scratch_target_uses_the_names_the_starter_compiles_to():
    """decomp.me compares symbol names, so the target object must name each call the way MSVC will
    name it from the scratch's own C++ (here a __stdcall function and plain ones)."""
    img = BinaryImage(ROOT / "binaries" / "Scarface.exe")
    va, size, symbol = 0x006F7EC0, 52, "audio::SeqEventNestTrack::vfunc_01"
    code = img.read(va, size)
    cpp = DS.synthesize_cpp(symbol, f"0x{va:08X}", code, DS.disassemble(code), relocs=D.find_relocations(code, va, img))
    obj, fields = D.prepare(img, va, size, symbol, FLAGS, cpp, [], build="pc")
    cr = MV.compile_cpp(fields["source_code"], FLAGS)
    assert cr.ok, cr.error
    mine = MV.CoffObject(cr.obj)
    fn, _ = MV.select_function(mine.functions(), "vfunc_01@SeqEventNestTrack@audio@@")
    target = MV.CoffObject(obj).functions()[0]
    tobj = MV.CoffObject(obj)
    got = {o: mine.symbols[si].name for o, si, _t in fn.relocs}
    want = {o: tobj.symbols[si].name for o, si, _t in target.relocs}
    assert got == want and fn.code == target.code


def test_adjustor_thunk_starter_declares_the_class_instead_of_a_body():
    import starter_synth as SS
    target = bytes.fromhex("83E904E908000000")                        # sub ecx, 4; jmp +8
    assert SS.adjustor_thunk(target, 0x248810) == (4, 0x248820)
    assert SS.adjustor_thunk(bytes.fromhex("81E900010000E900000000"), 0x1000) == (0x100, 0x100B)
    assert SS.adjustor_thunk(bytes.fromhex("83E904C390909090"), 0x1000) is None      # not a jump
    assert SS.adjustor_thunk(bytes.fromhex("83E903E908000000"), 0x1000) is None      # not a whole number of words
    assert SS.adjustor_thunk(target, None) is None
    code = DS.synthesize_cpp("core::ControllerSystemXBox::vfunc_00", "0x00248810", target, [])
    assert "An adjustor thunk" in code and "namespace core {" in code and "__asm" not in code
    assert "class ControllerSystemXBox : public ControllerSystemXBox_Base0, public ControllerSystemXBox_Base1" in code
    assert code.count("virtual void sub_00248820();") == 3 and "ControllerSystemXBox::ControllerSystemXBox() {}" in code
    wide = DS.synthesize_cpp("sub_00001000", "0x00001000", bytes.fromhex("83E90CE900000000"), [])
    assert "class Class_00001000_Base0 { public: virtual void sub_00001008(); char m_pad04[0x8]; };" in wide and "namespace" not in wide
    tmpl = DS.synthesize_cpp("core::Rep<a::B>::vfunc_01", "0x00001000", target, [])
    assert "class Class_00001000 :" in tmpl and "namespace" not in tmpl


@needs_compiler
def test_adjustor_thunk_starter_compiles_to_the_thunk():
    target = bytes.fromhex("83E904E908000000")
    code = DS.synthesize_cpp("core::ControllerSystemXBox::vfunc_00", "0x00248810", target, [])
    cr = MV.compile_cpp(code, FLAGS)
    assert cr.ok, cr.error
    fn, why = MV.select_function(MV.CoffObject(cr.obj).functions(), "vfunc_00@ControllerSystemXBox@core@@")
    assert fn is not None and fn.code[:4] == target[:4] and len(fn.code) == 8 and len(fn.relocs) == 1, why
