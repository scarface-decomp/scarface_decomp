// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, fe/BusinessHUDMenuItem.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 2 functions matched (50.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] BusinessHUD::BusinessHUDMenuItem::vfunc_00 (0x001B1710, 70 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as ExoticsHUD2::ExoticsHUDMenuItem::vfunc_00 (0x0018C280), which was matched first;
// its addresses and names were swapped for this function's.
// BusinessHUD::BusinessHUDMenuItem::vfunc_00 (0x001B1710, 70 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001C5730();
};

extern "C" char DAT_003BFA18[];
extern "C" void __cdecl sub_00027600(int);

namespace BusinessHUD {

class BusinessHUDMenuItem
{
public:
    virtual BusinessHUDMenuItem* vfunc_00(int a1);
    void sub_001972E0();
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

BusinessHUDMenuItem* BusinessHUDMenuItem::vfunc_00(int a1)
{
    int t1;

    t1 = m_Field08;
    *(int*)this = (int)DAT_003BFA18;
    if (m_Field08) {
        ((Object*)t1)->sub_001C5730();
        sub_00027600(t1);
        m_Field08 = 0;
    }
    sub_001972E0();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

}

