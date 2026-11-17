// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/Mod_CanUse50Cal.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 3 functions matched (66.67%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AICommandMods::Mod_CanUse50Cal::vfunc_01 (0x00118EC0, 32 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AICommandMods::Mod_CanUse50Cal::vfunc_01 (Proto 0x00118EC0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00148D30();
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

    t1 = ((Object*)a2)->sub_00148D30();
    m_Field08 = *(bool*)(t1 + 1493);
    *(bool*)(t1 + 1493) = true;
}

}

// ============================================================================
// [VERIFIED] AICommandMods::Mod_CanUse50Cal::vfunc_03 (0x00118EE0, 25 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AICommandMods::Mod_CanUse50Cal::vfunc_03 (Proto 0x00118EE0, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00148D30();
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
    *(bool*)(((Object*)a2)->sub_00148D30() + 1493) = m_Field08;
}

}

