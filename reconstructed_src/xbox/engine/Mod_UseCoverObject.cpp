// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/Mod_UseCoverObject.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AICommandMods::Mod_UseCoverObject::vfunc_05 (0x00134B30, 46 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AICommandMods::Mod_UseCoverObject::vfunc_05 (0x00134B30, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000F0FE0(int, int);
    int sub_001655C0();
};

extern "C" int __cdecl sub_0002AC90(int);

namespace AICommandMods {

class Mod_UseCoverObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int a1, int a2, int a3);
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

void Mod_UseCoverObject::vfunc_05(int a1, int a2, int a3)
{
    int t1, t3;

    t1 = ((Object*)a2)->sub_001655C0();
    t3 = sub_0002AC90(m_Field08);
    if (t3) {
        ((Object*)t1)->sub_000F0FE0(t3, 1);
    }
}

}

