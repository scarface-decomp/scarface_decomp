// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/Mod_CarApplyWeeble.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AICommandMods::Mod_CarApplyWeeble::vfunc_01 (0x00134EE0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AICommandMods::Mod_CarApplyWeeble::vfunc_01 (0x00134EE0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00166CE0();
    int sub_00217380();
};

namespace AICommandMods {

class Mod_CarApplyWeeble
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01(int a1, int a2);
};

void Mod_CarApplyWeeble::vfunc_01(int a1, int a2)
{
    int t1;

    t1 = ((Object*)a2)->sub_00166CE0();
    if (t1) {
        *(bool*)(((Object*)t1)->sub_00217380() + 1536) = true;
    }
}

}

// ============================================================================
// [VERIFIED] AICommandMods::Mod_CarApplyWeeble::vfunc_03 (0x00134F00, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AICommandMods::Mod_CarApplyWeeble::vfunc_03 (0x00134F00, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00166CE0();
    int sub_00217380();
};

namespace AICommandMods {

class Mod_CarApplyWeeble
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03(int a1, int a2);
};

void Mod_CarApplyWeeble::vfunc_03(int a1, int a2)
{
    int t1;

    t1 = ((Object*)a2)->sub_00166CE0();
    if (t1) {
        *(bool*)(((Object*)t1)->sub_00217380() + 1536) = false;
    }
}

}

