// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/Mod_CarApplyWeeble.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AICommandMods::Mod_CarApplyWeeble::vfunc_01 (0x00119CE0, 30 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AICommandMods::Mod_CarApplyWeeble::vfunc_01 (Proto 0x00119CE0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_0014A290();
    int sub_001DB8F0();
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

    t1 = ((Object*)a2)->sub_0014A290();
    if (t1) {
        *(bool*)(((Object*)t1)->sub_001DB8F0() + 1520) = true;
    }
}

}

// ============================================================================
// [VERIFIED] AICommandMods::Mod_CarApplyWeeble::vfunc_03 (0x00119D00, 30 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AICommandMods::Mod_CarApplyWeeble::vfunc_03 (Proto 0x00119D00, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_0014A290();
    int sub_001DB8F0();
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

    t1 = ((Object*)a2)->sub_0014A290();
    if (t1) {
        *(bool*)(((Object*)t1)->sub_001DB8F0() + 1520) = false;
    }
}

}

