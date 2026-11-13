// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, fe/DrugWarsHUDTurfMenuItem.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 4 functions matched (25.00%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] DrugWarsHUD::DrugWarsHUDTurfMenuItem::vfunc_00 (0x001B0520, 40 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// DrugWarsHUD::DrugWarsHUDTurfMenuItem::vfunc_00 (0x001B0520, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field38
{
    void sub_0018F600();
};

extern "C" void __cdecl sub_00027600(int);

namespace DrugWarsHUD {

class DrugWarsHUDTurfMenuItem
{
public:
    virtual DrugWarsHUDTurfMenuItem* vfunc_00(int a1);
    void sub_001972E0();
    char m_pad04[0x34];
    Field38 m_Field38; // +0x38
};

DrugWarsHUDTurfMenuItem* DrugWarsHUDTurfMenuItem::vfunc_00(int a1)
{
    m_Field38.sub_0018F600();
    sub_001972E0();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

}

