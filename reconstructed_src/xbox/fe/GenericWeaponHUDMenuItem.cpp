// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, fe/GenericWeaponHUDMenuItem.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 5 functions matched (20.00%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] GenericWeaponHUD::GenericWeaponHUDMenuItem::vfunc_03 (0x001B7080, 125 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// GenericWeaponHUD::GenericWeaponHUDMenuItem::vfunc_03 (0x001B7080, 125 bytes)
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

namespace GenericWeaponHUD {

class GenericWeaponHUDMenuItem
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
    int m_Field38; // +0x38
    int m_Field3C; // +0x3C
    int m_Field40; // +0x40
    int m_Field44; // +0x44
    int m_Field48; // +0x48
    char m_pad4C[0x8];
    int m_Field54; // +0x54
};

void GenericWeaponHUDMenuItem::vfunc_03(int a1)
{
    int r_ebp, r_esi, t1, t3, t5, t7, t9, t12;

    t1 = m_Field34;
    if (m_Field34) {
        ((Object*)t1)->vfunc_17(a1);
    }
    t3 = m_Field38;
    if (m_Field38) {
        ((Object*)t3)->vfunc_17(a1);
    }
    t5 = m_Field3C;
    if (m_Field3C) {
        if ((unsigned char)a1) goto L_34;
        ((Object*)t5)->vfunc_17(0);
    }
L_34:
    t7 = m_Field40;
    if (m_Field40) {
        ((Object*)t7)->vfunc_17(a1);
    }
    t9 = m_Field44;
    if (m_Field44) {
        ((Object*)t9)->vfunc_17(a1);
    }
    r_esi = (int)(&m_Field48);
    r_ebp = 3;
    do {
        ((Object*)*(int*)r_esi)->vfunc_17(a1);
        r_esi += 4;
        r_ebp -= 1;
    } while (r_ebp);
    t12 = m_Field54;
    if (m_Field54) {
        ((Object*)t12)->vfunc_17(a1);
    }
    m_Field05 = (unsigned char)a1;
}

}

