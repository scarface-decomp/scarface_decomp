// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/Mod_DefendPosition.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 2 functions matched (50.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AICommandMods::Mod_DefendPosition::vfunc_03 (0x001345B0, 27 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AICommandMods::Mod_DefendPosition::vfunc_03 (Proto 0x00119060), which was matched first;
// its addresses and names were swapped for this function's.
// AICommandMods::Mod_DefendPosition::vfunc_03 (Proto 0x001345B0, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000F0FA0();
    int sub_001655C0();
};

namespace AICommandMods {

class Mod_DefendPosition
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03(int a1, int a2);
    char m_pad04[0x14];
    bool m_Field18; // +0x18
};

void Mod_DefendPosition::vfunc_03(int a1, int a2)
{
    ((Object*)((Object*)a2)->sub_001655C0())->sub_000F0FA0();
    m_Field18 = false;
}

}

