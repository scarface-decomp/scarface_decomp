"""The verifier end to end with the real cl.exe 13.10.3052 (skipped when it is not installed)."""
import msvc_verify as MV

from conftest import FLAGS, needs_compiler, needs_pc

pytestmark = needs_compiler


def compiled(src, match="", flags=FLAGS):
    cr = MV.compile_cpp(src, flags)
    assert cr.ok, cr.error
    coff = MV.CoffObject(cr.obj)
    fn, why = MV.select_function(coff.functions(), match)
    assert fn is not None, why
    return coff, fn


def test_compiler_version():
    assert MV.compiler_build() in MV.TOOLKIT_BUILDS       # Toolkit 1.0 (13.10.3052) or 1.01 (13.10.3077)
    assert MV.compiler_build() in MV.compiler_version()


def test_identical_bytes_are_exact():
    coff, fn = compiled("int add(int a, int b) { return a + b; }")
    r = MV.compare_function(fn.code, fn, coff)
    assert r.is_exact and r.matched == r.total == len(fn.code)


def test_one_byte_off_is_not_exact():
    coff, fn = compiled("int add(int a, int b) { return a + b; }")
    bad = bytearray(fn.code)
    bad[0] ^= 0xFF
    r = MV.compare_function(bytes(bad), fn, coff)
    assert not r.is_exact and r.matched == len(fn.code) - 1


def test_length_must_match_exactly():
    coff, fn = compiled("int add(int a, int b) { return a + b; }")
    r = MV.compare_function(fn.code + b"\xCC", fn, coff)       # original one byte longer
    assert not r.is_exact
    r = MV.compare_function(fn.code[:-1], fn, coff)
    assert not r.is_exact


def test_address_named_symbol_is_checked(tiny_xbe):
    src = 'extern "C" char DAT_00030000; void* __cdecl get(void) { return &DAT_00030000; }'
    good = MV.verify_submission(src, bytes.fromhex("B8 00 00 03 00 C3"), FLAGS, "get", fn_va=0x11000, image=tiny_xbe)
    assert good["ok"] and good["is_exact"] and good["reloc_checked"] == 1 and good["reloc_unverified"] == 0
    wrong = MV.verify_submission(src, bytes.fromhex("B8 04 00 03 00 C3"), FLAGS, "get", fn_va=0x11000, image=tiny_xbe)
    assert wrong["ok"] and not wrong["is_exact"] and wrong["reloc_mismatch"]


def test_hardcoded_address_is_flagged(tiny_xbe):
    src = "void* __cdecl get(void) { return (void*)0x00030000; }"
    r = MV.verify_submission(src, bytes.fromhex("B8 00 00 03 00 C3"), FLAGS, "get", fn_va=0x11000, image=tiny_xbe)
    assert r["ok"] and r["is_exact"]                    # the bytes do match...
    assert r["hardcoded_addresses"]                     # ...but it cannot count


def test_policy_rejects_asm_hidden_in_a_macro():
    src = "#define X __asm nop\nvoid f() { X }"
    cr = MV.compile_cpp(src, FLAGS)
    assert not cr.ok and cr.policy_violation


def test_rejects_output_flags_in_task_flags():
    cr = MV.compile_cpp("void f() {}", FLAGS + " /Fo..\\evil.obj")
    assert not cr.ok


def test_fatal_error_returns_instead_of_hanging():
    cr = MV.compile_cpp('#include "does_not_exist.h"\nvoid f() {}', FLAGS, timeout=120)
    assert not cr.ok and "does_not_exist" in cr.error


# ---------------------------------------------------------------- code generation facts in docs/METHODOLOGY.md

def test_void_call_cleans_with_pop_ecx_and_returning_call_with_add_esp():
    void_src = 'extern "C" void* __cdecl R(void*); struct D { int a; void* p; void f(); }; void D::f() { R(p); }'
    ret_src = 'extern "C" void* __cdecl R(void*); struct D { int a; void* p; void* f(); }; void* D::f() { return R(p); }'
    _, fv = compiled(void_src, "f@D@")
    _, fr = compiled(ret_src, "f@D@")
    assert fv.code.endswith(b"\x59\xC3")                # pop ecx; ret
    assert fr.code.endswith(b"\x83\xC4\x04\xC3")        # add esp, 4; ret


def test_g7_uses_add_1_instead_of_inc():
    src = "struct L { virtual void Lock(); virtual void Unlock(); int n; void AddRef() { Lock(); ++n; Unlock(); } };" \
          "struct D { char pad[8]; L l; void f(); }; void D::f() { l.AddRef(); }"
    _, g6 = compiled(src, "f@D@")
    _, g7 = compiled(src, "f@D@", FLAGS.replace("/G6", "/G7"))
    assert b"\x83\x46\x04\x01" in g7.code and b"\x83\x46\x04\x01" not in g6.code


# ---------------------------------------------------------------- against the game (needs binaries/)

@needs_pc
def test_drivethread_vfunc_00_matches_as_void():
    from sf_binaries import BinaryImage
    from conftest import ROOT
    img = BinaryImage(ROOT / "binaries" / "Scarface.exe")
    target = img.read(0x006E7EB0, 11)
    src = ("void* __cdecl ResolveDescA(void* p);\n"
           "class DriveThread { public: int m_Field04; void* m_pDesc08; virtual void vfunc_00(); };\n"
           "void DriveThread::vfunc_00() { ResolveDescA(m_pDesc08); }\n")
    r = MV.verify_submission(src, target, FLAGS, "vfunc_00@DriveThread@", fn_va=0x006E7EB0, image=img)
    assert r["ok"] and r["is_exact"] and not r["hardcoded_addresses"]
    returning = src.replace("virtual void vfunc_00", "virtual void* vfunc_00").replace(
        "void DriveThread::vfunc_00() { ResolveDescA", "void* DriveThread::vfunc_00() { return ResolveDescA")
    r = MV.verify_submission(returning, target, FLAGS, "vfunc_00@DriveThread@", fn_va=0x006E7EB0, image=img)
    assert r["ok"] and not r["is_exact"]


def test_a_call_by_a_known_name_is_checked_against_its_address(tiny_xbe):
    """Code may call a function by the name reports/names.json gives its address; a name nobody has
    tied to an address stays unchecked, and a name tied to another address is a mismatch."""
    src = ('class Weapon { public: void Reload(); void sub_00011000(); int m_ammo; };\n'
           'void Weapon::sub_00011000() { m_ammo = 0; Reload(); }')
    coff, fn = compiled(src, "sub_00011000")
    at = [off for off, _, _ in fn.relocs][0]
    target = bytearray(fn.code)
    target[at:at + 4] = (0x11200 - (0x11000 + at + 4)).to_bytes(4, "little", signed=True)   # the call goes to 0x11200
    args = dict(fn_va=0x11000, image=tiny_xbe)
    named = MV.compare_function(bytes(target), fn, coff, known_names={"Weapon::Reload": 0x11200}, **args)
    assert named.is_exact and named.reloc_checked == 1 and named.reloc_unverified == 0
    unknown = MV.compare_function(bytes(target), fn, coff, **args)
    assert unknown.is_exact and unknown.reloc_checked == 0 and unknown.reloc_unverified == 1
    wrong = MV.compare_function(bytes(target), fn, coff, known_names={"Weapon::Reload": 0x11300}, **args)
    assert not wrong.is_exact and "Weapon::Reload" in wrong.reloc_mismatch[0]
