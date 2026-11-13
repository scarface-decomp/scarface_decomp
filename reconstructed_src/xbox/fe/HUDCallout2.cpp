// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, fe/HUDCallout2.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 5 functions matched (40.00%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] HUDCallout2::vfunc_00 (0x00192420, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// HUDCallout2::vfunc_00 (0x00192420, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004364A8[];

class HUDCallout2
{
public:
    virtual void* vfunc_00();
};

void* HUDCallout2::vfunc_00()
{
    return DAT_004364A8;
}

// ============================================================================
// [VERIFIED] HUDCallout2::vfunc_01 (0x00192650, 76 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// HUDCallout2::vfunc_01 (0x00192650, 76 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003BA7C4[];
extern "C" int DAT_0048C1DC;
extern "C" void __cdecl sub_00027600(int);
extern "C" void __stdcall sub_00192020(int);
extern "C" void __cdecl sub_002444F0(int, int);

class HUDCallout2
{
public:
    virtual void vfunc_00();
    virtual HUDCallout2* vfunc_01(int a1);
    void sub_00193F80();
    char m_pad04[0x64];
    int m_Field68; // +0x68
    int m_Field6C; // +0x6C
};

HUDCallout2* HUDCallout2::vfunc_01(int a1)
{
    int t2;

    *(int*)this = (int)DAT_003BA7C4;
    sub_00192020(-1);
    DAT_0048C1DC = 0;
    t2 = m_Field68;
    m_Field6C = m_Field68;
    if (m_Field68) {
        sub_002444F0(7, t2);
    }
    sub_00193F80();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

