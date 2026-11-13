// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, fe/LaunderCashHUD.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 8 functions matched (25.00%). NOT COMPLETE YET.
// The 6 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] LaunderCashHUD::vfunc_00 (0x00194D30, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// LaunderCashHUD::vfunc_00 (0x00194D30, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00436818[];

class LaunderCashHUD
{
public:
    virtual void* vfunc_00();
};

void* LaunderCashHUD::vfunc_00()
{
    return DAT_00436818;
}

// ============================================================================
// [VERIFIED] LaunderCashHUD::vfunc_01 (0x001951B0, 65 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// LaunderCashHUD::vfunc_01 (0x001951B0, 65 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00(int);
};

extern "C" char DAT_003BB1E4[];
extern "C" char DAT_003BB1EC[];
extern "C" void __cdecl sub_00027600(int);

class LaunderCashHUD
{
public:
    virtual void vfunc_00();
    virtual LaunderCashHUD* vfunc_01(int a1);
    void sub_00193F80();
    char m_pad04[0x60];
    int m_Field64; // +0x64
    char m_pad68[0x8];
    int m_Field70; // +0x70
};

LaunderCashHUD* LaunderCashHUD::vfunc_01(int a1)
{
    int t1;

    t1 = m_Field70;
    *(int*)this = (int)DAT_003BB1EC;
    m_Field64 = (int)DAT_003BB1E4;
    if (m_Field70) {
        ((Object*)t1)->vfunc_00(1);
        m_Field70 = 0;
    }
    sub_00193F80();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

