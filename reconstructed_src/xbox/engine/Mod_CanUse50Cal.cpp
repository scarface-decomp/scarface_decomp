// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/Mod_CanUse50Cal.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 3 functions matched (66.67%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AICommandMods::Mod_CanUse50Cal::vfunc_01 (0x001344A0, 32 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AICommandMods::Mod_CanUse50Cal::vfunc_01 (0x001344A0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_001655C0();
};

namespace AICommandMods {

class Mod_CanUse50Cal
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01(int a1, int a2);
    char m_pad04[0x4];
    bool m_Field08; // +0x08
};

void Mod_CanUse50Cal::vfunc_01(int a1, int a2)
{
    int t1;

    t1 = ((Object*)a2)->sub_001655C0();
    m_Field08 = *(bool*)(t1 + 1345);
    *(bool*)(t1 + 1345) = true;
}

}

// ============================================================================
// [VERIFIED] AICommandMods::Mod_CanUse50Cal::vfunc_03 (0x001344C0, 25 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AICommandMods::Mod_CanUse50Cal::vfunc_03 (0x001344C0, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_001655C0();
};

namespace AICommandMods {

class Mod_CanUse50Cal
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03(int a1, int a2);
    char m_pad04[0x4];
    bool m_Field08; // +0x08
};

void Mod_CanUse50Cal::vfunc_03(int a1, int a2)
{
    *(bool*)(((Object*)a2)->sub_001655C0() + 1345) = m_Field08;
}

}

