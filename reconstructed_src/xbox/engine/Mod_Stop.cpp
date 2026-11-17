// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/Mod_Stop.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AICommandMods::Mod_Stop::vfunc_05 (0x001349E0, 23 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AICommandMods::Mod_Stop::vfunc_05 (Proto 0x001194D0), which was matched first;
// its addresses and names were swapped for this function's.
// AICommandMods::Mod_Stop::vfunc_05 (Proto 0x001349E0, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000F2770();
    int sub_001655C0(int, int);
};

namespace AICommandMods {

class Mod_Stop
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int a1, int a2, int a3);
};

void Mod_Stop::vfunc_05(int a1, int a2, int a3)
{
    ((Object*)((Object*)a2)->sub_001655C0(1, 1))->sub_000F2770();
}

}

// ============================================================================
// [VERIFIED] AICommandMods::Mod_Stop::vfunc_06 (0x00134A00, 25 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AICommandMods::Mod_Stop::vfunc_06 (Proto 0x001194F0), which was matched first;
// its addresses and names were swapped for this function's.
// AICommandMods::Mod_Stop::vfunc_06 (Proto 0x00134A00, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000F2770();
    int sub_001655C0(int, int);
};

namespace AICommandMods {

class Mod_Stop
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual bool vfunc_06(int a1, int a2, int a3);
};

bool Mod_Stop::vfunc_06(int a1, int a2, int a3)
{
    ((Object*)((Object*)a2)->sub_001655C0(1, 1))->sub_000F2770();
    return true;
}

}

