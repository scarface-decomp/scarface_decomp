// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, fe/ExoticsHUDMenuItem.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 5 functions matched (40.00%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ExoticsHUD2::ExoticsHUDMenuItem::vfunc_03 (0x00168D00, 55 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ExoticsHUD2::ExoticsHUDMenuItem::vfunc_03 (Proto 0x00168D00, 55 bytes)
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
    virtual void vfunc_17();
    virtual void vfunc_18(int);
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
    char m_pad06[0x2];
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    char m_pad10[0x4];
    int m_Field14; // +0x14
};

void ExoticsHUDMenuItem::vfunc_03(int a1)
{
    int t1, t3, t5;

    t1 = m_Field0C;
    if (m_Field0C) {
        ((Object*)t1)->vfunc_18(a1);
    }
    t3 = m_Field08;
    if (m_Field08) {
        ((Object*)t3)->vfunc_18(a1);
    }
    t5 = m_Field14;
    if (m_Field14) {
        ((Object*)t5)->vfunc_18(a1);
    }
    m_Field05 = (unsigned char)a1;
}

}

// ============================================================================
// [VERIFIED] ExoticsHUD2::ExoticsHUDMenuItem::vfunc_00 (0x00169250, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionManager::CollisionManagerFlowClient::vfunc_00 (0x00016060), which was matched first;
// its addresses and names were swapped for this function's.
// ExoticsHUD2::ExoticsHUDMenuItem::vfunc_00 (0x00169250, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0016FA10(void);
extern "C" void __cdecl sub_00025160(int);

namespace ExoticsHUD2 {

class ExoticsHUDMenuItem
{
public:
    virtual ExoticsHUDMenuItem* vfunc_00(int a1);
};

ExoticsHUDMenuItem* ExoticsHUDMenuItem::vfunc_00(int a1)
{
    sub_0016FA10();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

}

