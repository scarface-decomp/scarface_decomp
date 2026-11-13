"""Verifier pieces that need neither the compiler nor the game files."""
import msvc_verify as MV
import queue_builder as QB
import reverify_all as RV
import name_hardcoded_addresses as NH
from msvc_verify import ObjFunction


# ---------------------------------------------------------------- address-named symbols

def test_address_named_symbols():
    assert MV.address_named("_DAT_00439DA4") == 0x00439DA4
    assert MV.address_named("?DAT_00439DA4@@3DA") == 0x00439DA4        # C++ decorated
    assert MV.address_named("?sub_00412340@@YAXXZ") == 0x00412340
    assert MV.address_named("?g_007F5A70@core@@3PAXA") == 0x007F5A70
    assert MV.address_named("_g_pCoreMemoryPool") is None
    assert MV.address_named("_DAT_0043") is None                       # needs all 8 digits
    assert MV.address_named("_mySub_00412340") is None


# ---------------------------------------------------------------- decorated-name hints

def test_split_scopes_respects_templates():
    assert MV._split_scopes("a::B<c::D>::E") == ["a", "B<c::D>", "E"]


def test_decorated_hint_forms():
    assert MV.decorated_hint("content::Stats", "vfunc_03") == "vfunc_03@Stats@content@"
    assert MV.decorated_hint("Stats", "~Stats") == "??_GStats@|??1Stats@"
    assert MV.decorated_hint("Path", "Path") == "??0Path@"
    assert MV.decorated_hint("ConcreteClassRep<EmpireHUD>", "CreateFromPool") == (
        "CreateFromPool@?$ConcreteClassRep@VEmpireHUD@@@|CreateFromPool@?$ConcreteClassRep@UEmpireHUD@@@")


def test_reverify_symbol_matching():
    assert RV.match_from_symbol("core::MemorySpaceAsyncRequest_Copy::vfunc_01") == "vfunc_01@MemorySpaceAsyncRequest_Copy@core@"
    assert RV.member_match("Stats", "~Stats") == "??_GStats@|??1Stats@"


def _fn(name):
    return ObjFunction(name, 1, 0, 1, b"\xC3", [])


def test_select_function_alternatives_and_ambiguity():
    funcs = [_fn("??_GStats@content@@UAEPAXI@Z"), _fn("??1Stats@content@@UAE@XZ"), _fn("?vfunc_25@FileFix@core@@UAEPADXZ")]
    fn, _ = MV.select_function(funcs, "??_GStats@|??1Stats@")
    assert fn.name.startswith("??_GStats@")
    fn, _ = MV.select_function(funcs, "??_GNope@|??1Stats@")
    assert fn.name.startswith("??1Stats@")
    fn, why = MV.select_function(funcs, "Stats@")
    assert fn is None and "Several functions" in why                    # never guesses
    fn, why = MV.select_function(funcs, "")
    assert fn is None                                                   # several and no hint: no fallback


def test_select_function_ignores_eh_helpers():
    funcs = [_fn("?f@A@@QAEXXZ"), _fn("__ehhandler$?f@A@@QAEXXZ"), _fn("__unwindfunclet$?f@A@@QAEXXZ$0")]
    fn, _ = MV.select_function(funcs, "")
    assert fn.name == "?f@A@@QAEXXZ"


# ---------------------------------------------------------------- RTTI names

def test_demangle_rtti():
    assert QB.demangle_rtti(".?AVString@core@@") == "core::String"
    assert QB.demangle_rtti(".?AV?$ConcreteClassRep@VFEObject@@@@") == "ConcreteClassRep<FEObject>"
    assert QB.demangle_rtti(".?AV?$Function2@XPBDPBD@CScript@@") == "CScript::Function2<void, const char*, const char*>"
    assert QB.demangle_rtti(".?AV?$TrackFactoryTemplate@V?$FightActionController@VEnterExitScriptTrack@fight@@@FightTree@@@fight@@") == \
        "fight::TrackFactoryTemplate<FightTree::FightActionController<fight::EnterExitScriptTrack>>"


def test_rtti_match_hint_matches_member_decoration():
    # ?vfunc_00@?$ConcreteClassRep@VFEObject@@@@UAEPAXXZ is how cl decorates the member
    hint = QB.rtti_match_hint(".?AV?$ConcreteClassRep@VFEObject@@@@", "vfunc_00")
    assert hint in "?vfunc_00@?$ConcreteClassRep@VFEObject@@@@UAEPAXXZ"


# ---------------------------------------------------------------- binaries

def test_xbe_sections_are_classified_by_name(tiny_xbe):
    kinds = {s.name: (s.is_code, s.library) for s in tiny_xbe.sections}
    assert kinds[".text"] == (True, False)
    assert kinds[".data"] == (False, False)          # flagged executable in the header, but it is data
    assert kinds["D3D"] == (True, True)              # XDK library code, not game code
    assert [s.name for s in tiny_xbe.game_code_sections()] == [".text"]


def test_xbe_read_by_address(tiny_xbe):
    assert tiny_xbe.read(0x11000, 6) == bytes.fromhex("B8 00 00 03 00 C3")
    assert tiny_xbe.read(0x30000, 4) == bytes.fromhex("78 56 34 12")
    assert tiny_xbe.read(0x11000 + 18, 4) is None    # runs past the section


def test_function_extent(tiny_xbe):
    from sf_binaries import function_extent
    e = function_extent(tiny_xbe, 0x11000, set())
    assert e.ok and e.size == 6


# ---------------------------------------------------------------- hard-coded address rewrite

def test_hardcoded_shapes():
    rx, make = NH.SHAPES[0]
    m = rx.match("unsigned int __cdecl sub_001CDC80(void) { return 0x00439DA4; }")
    assert make(m.group(1), "00439DA4", False) == \
        'extern "C" char DAT_00439DA4; void* __cdecl sub_001CDC80(void) { return &DAT_00439DA4; }'
    assert make("sub_000111A0", "000111A0", True) == "void* __cdecl sub_000111A0(void) { return (void*)&sub_000111A0; }"
    rx, make = NH.SHAPES[1]
    m = rx.match("unsigned int __cdecl sub_00012340(void) { return *(const unsigned int*)0x00419E48; }")
    assert "return DAT_00419E48;" in make(m.group(1), "00419E48", False)
    rx, make = NH.SHAPES[2]
    m = rx.match("float __cdecl sub_0001EF60(void) { return *(const float*)0x00471508; }")
    assert make(m.group(1), "00471508", False).startswith('extern "C" const float DAT_00471508;')


def test_names_are_read_off_compiled_symbols_only_when_that_takes_no_guessing():
    q = MV.qualified_name
    assert q("?Reload@Weapon@game@@QAEXXZ") == "game::Weapon::Reload"
    assert q("?Tick@@YAXXZ") == "Tick" and q("_Tick") == "Tick" and q("_Tick@8") == "Tick"
    assert q("??0Weapon@@QAE@XZ") is None                 # a constructor
    assert q("?Get@?$List@H@@QAEHXZ") is None             # a template
    assert q("?Fire@Weapon@1@QAEXXZ") is None             # a back-reference in the scope
    assert q("__imp__Sleep@4") is None and q("sub_00011000") is None
