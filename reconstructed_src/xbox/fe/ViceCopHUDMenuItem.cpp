// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, fe/ViceCopHUDMenuItem.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 5 functions matched (40.00%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ViceCopHUD::ViceCopHUDMenuItem::vfunc_04 (0x001AEA60, 28 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ViceCopHUD::ViceCopHUDMenuItem::vfunc_04 (0x001AEA60, 28 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field3C
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06(int);
};

extern "C" void __stdcall sub_00197060(int);

namespace ViceCopHUD {

class ViceCopHUDMenuItem
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int a1);
    char m_pad04[0x38];
    Field3C* m_Field3C; // +0x3C
};

void ViceCopHUDMenuItem::vfunc_04(int a1)
{
    sub_00197060(a1);
    m_Field3C->vfunc_06(a1);
}

}

// ============================================================================
// [VERIFIED] ViceCopHUD::ViceCopHUDMenuItem::vfunc_00 (0x001B0A50, 90 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ViceCopHUD::ViceCopHUDMenuItem::vfunc_00 (0x001B0A50, 90 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00(int);
    void sub_001C5730();
};

extern "C" char DAT_003BF780[];
extern "C" void __cdecl sub_00027600(int);

namespace ViceCopHUD {

class ViceCopHUDMenuItem
{
public:
    virtual ViceCopHUDMenuItem* vfunc_00(int a1);
    void sub_001972E0();
    char m_pad04[0x4];
    int m_Field08; // +0x08
    char m_pad0C[0x30];
    int m_Field3C; // +0x3C
};

ViceCopHUDMenuItem* ViceCopHUDMenuItem::vfunc_00(int a1)
{
    int t1, t3;

    t1 = m_Field3C;
    *(int*)this = (int)DAT_003BF780;
    if (m_Field3C) {
        ((Object*)t1)->vfunc_00(1);
        m_Field3C = 0;
    }
    t3 = m_Field08;
    if (m_Field08) {
        ((Object*)t3)->sub_001C5730();
        sub_00027600(t3);
        m_Field08 = 0;
    }
    sub_001972E0();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

}

