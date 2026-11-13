// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, fe/ExoticsHUDMenuItem.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 6 functions matched (33.33%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ExoticsHUD2::ExoticsHUDMenuItem::vfunc_03 (0x0018B740, 55 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ExoticsHUD2::ExoticsHUDMenuItem::vfunc_03 (0x0018B740, 55 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17(int);
};

namespace ExoticsHUD2 {

class ExoticsHUDMenuItem
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03(int a1);
    char m_pad04[0x1];
    unsigned char m_Field05; // +0x05
    char m_pad06[0x2A];
    int m_Field30; // +0x30
    int m_Field34; // +0x34
    char m_pad38[0x4];
    int m_Field3C; // +0x3C
};

void ExoticsHUDMenuItem::vfunc_03(int a1)
{
    int t1, t3, t5;

    t1 = m_Field34;
    if (m_Field34) {
        ((Object*)t1)->vfunc_17(a1);
    }
    t3 = m_Field30;
    if (m_Field30) {
        ((Object*)t3)->vfunc_17(a1);
    }
    t5 = m_Field3C;
    if (m_Field3C) {
        ((Object*)t5)->vfunc_17(a1);
    }
    m_Field05 = (unsigned char)a1;
}

}

// ============================================================================
// [VERIFIED] ExoticsHUD2::ExoticsHUDMenuItem::vfunc_00 (0x0018C280, 70 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ExoticsHUD2::ExoticsHUDMenuItem::vfunc_00 (0x0018C280, 70 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001C5730();
};

extern "C" char DAT_003B93D4[];
extern "C" void __cdecl sub_00027600(int);

namespace ExoticsHUD2 {

class ExoticsHUDMenuItem
{
public:
    virtual ExoticsHUDMenuItem* vfunc_00(int a1);
    void sub_001972E0();
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

ExoticsHUDMenuItem* ExoticsHUDMenuItem::vfunc_00(int a1)
{
    int t1;

    t1 = m_Field08;
    *(int*)this = (int)DAT_003B93D4;
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

