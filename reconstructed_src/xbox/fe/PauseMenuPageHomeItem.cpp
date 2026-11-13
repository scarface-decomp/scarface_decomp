// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, fe/PauseMenuPageHomeItem.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] PauseMenuPageHome::PauseMenuPageHomeItem::vfunc_03 (0x001CB930, 26 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// PauseMenuPageHome::PauseMenuPageHomeItem::vfunc_03 (0x001CB930, 26 bytes)
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
    virtual int vfunc_17(int);
};

namespace PauseMenuPageHome {

class PauseMenuPageHomeItem
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03(int a1);
    char m_pad04[0x1];
    unsigned char m_Field05; // +0x05
    char m_pad06[0x2E];
    int m_Field34; // +0x34
};

void PauseMenuPageHomeItem::vfunc_03(int a1)
{
    int t1, t3;

    m_Field05 = (unsigned char)a1;
    t1 = m_Field34;
    if (m_Field34) {
        a1 = a1;
        t3 = ((Object*)t1)->vfunc_17(a1);
        return;
    }
}

}

// ============================================================================
// [VERIFIED] PauseMenuPageHome::PauseMenuPageHomeItem::vfunc_00 (0x001CBCD0, 70 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as ExoticsHUD2::ExoticsHUDMenuItem::vfunc_00 (0x0018C280), which was matched first;
// its addresses and names were swapped for this function's.
// PauseMenuPageHome::PauseMenuPageHomeItem::vfunc_00 (0x001CBCD0, 70 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001C5730();
};

extern "C" char DAT_003C475C[];
extern "C" void __cdecl sub_00027600(int);

namespace PauseMenuPageHome {

class PauseMenuPageHomeItem
{
public:
    virtual PauseMenuPageHomeItem* vfunc_00(int a1);
    void sub_001972E0();
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

PauseMenuPageHomeItem* PauseMenuPageHomeItem::vfunc_00(int a1)
{
    int t1;

    t1 = m_Field08;
    *(int*)this = (int)DAT_003C475C;
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

