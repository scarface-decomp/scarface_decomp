"""The April 20, 2006 Xbox prototype (binaries/game.xbe): unreleased code, counted on its own row,
built with the same compiler and flags as retail."""
from conftest import FLAGS, ROOT, needs_compiler
import pytest
import registry_outputs as RO

needs_proto = pytest.mark.skipif(not (ROOT / "binaries" / "game.xbe").exists(), reason="binaries/game.xbe missing")


def entry(b, va, size=8):
    return {"bin": b, "va": f"0x{va:08X}", "size": size, "symbol": f"sub_{va:08X}", "code": "x", "verified_by": "A"}


def test_prototype_is_counted_apart():
    reg = {"entries": {"pc:0x006DDC00": entry("pc", 0x006DDC00), "xb:0x00011000": entry("xb", 0x11000),
                       "proto:0x00011000": entry("proto", 0x11000, 100), "proto:0x00011100": entry("proto", 0x11100)}}
    queue = ([{"bin": "pc", "tier": "TIER_1_QUICK"}] * 2 + [{"bin": "xb", "tier": "TIER_1_QUICK"}] * 3
             + [{"bin": "proto", "tier": "TIER_4_LARGE"}] * 7)
    s = RO.progress_summary(reg, queue, None)
    assert s["verified"] == {"pc": 1, "xb": 1, "proto": 2, "total": 2, "bytes": 16}
    assert s["queue"]["total"] == 5 and s["queue"]["proto"] == 7 and s["queue"]["tiers"] == {"TIER_1_QUICK": 5}
    block = RO.status_block(reg)
    assert "| Verified functions | 1 | 1 | **2** |" in block and "Plus 2 in the April 2006 Xbox prototype" in block


@needs_compiler
@needs_proto
def test_prototype_only_code_matches_with_our_compiler():
    """Three functions of classes the retail game doesn't have: same compiler, same flags."""
    import msvc_verify as MV
    from sf_binaries import BinaryImage
    img = BinaryImage(ROOT / "binaries" / "game.xbe")
    cases = [
        (0x00118FE0, 18, "vfunc_01@Mod_CarStateParked@AICommandMods@@",
         'extern "C" void __cdecl sub_001188A0(void* who, int state);\n'
         "namespace AICommandMods {\n"
         "struct Mod_CarStateParked { virtual void vfunc_00(); virtual void vfunc_01(void* cmd, void* target); };\n"
         "}\n"
         "void AICommandMods::Mod_CarStateParked::vfunc_01(void* cmd, void* target) { sub_001188A0(target, 1); }\n"),
        (0x002065D0, 13, "vfunc_00@FeTextBibleString@frontend@pure3d@@",
         'extern "C" int __cdecl sub_0020B670(void* text);\n'
         "namespace pure3d { namespace frontend {\n"
         "struct FeTextBibleString { virtual int vfunc_00(); void* m_text; };\n"
         "} }\n"
         "int pure3d::frontend::FeTextBibleString::vfunc_00() { return sub_0020B670(m_text); }\n"),
        (0x001A5630, 20, "vfunc_38@CubeVanSpawnObject@@",
         "struct CubeVanSpawnObject {\n"
         "    virtual void vfunc_00();\n"
         "    virtual void vfunc_38(int unused, int event);\n"
         "    char pad[0xB8];\n"
         "    int m_spawned;\n"
         "};\n"
         "void CubeVanSpawnObject::vfunc_38(int unused, int event) { if (event == 1) m_spawned = 0; }\n"),
    ]
    for va, size, match, cpp in cases:
        res = MV.verify_submission(cpp, img.read(va, size), FLAGS, match, fn_va=va, image=img)
        assert res["ok"] and res["is_exact"] and not res["reloc_unverified"], (hex(va), res)
