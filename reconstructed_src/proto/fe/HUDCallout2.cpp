// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, fe/HUDCallout2.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 5 functions matched (40.00%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] HUDCallout2::vfunc_00 (0x0016D5B0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// HUDCallout2::vfunc_00 (0x0016D5B0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00410324[];

class HUDCallout2
{
public:
    virtual void* vfunc_00();
};

void* HUDCallout2::vfunc_00()
{
    return DAT_00410324;
}

// ============================================================================
// [VERIFIED] HUDCallout2::vfunc_01 (0x0016D7C0, 76 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// HUDCallout2::vfunc_01 (Proto 0x0016D7C0, 76 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003979D4[];
extern "C" int DAT_0045E044;
extern "C" void __cdecl sub_00025160(int);
extern "C" void __stdcall sub_0016D4C0(int);
extern "C" void __cdecl sub_00201990(int, int);

class HUDCallout2
{
public:
    virtual void vfunc_00();
    virtual HUDCallout2* vfunc_01(int a1);
    void sub_0016E130();
    char m_pad04[0x3C];
    int m_Field40; // +0x40
    int m_Field44; // +0x44
};

HUDCallout2* HUDCallout2::vfunc_01(int a1)
{
    int t2;

    *(int*)this = (int)DAT_003979D4;
    sub_0016D4C0(-1);
    DAT_0045E044 = 0;
    t2 = m_Field40;
    m_Field44 = m_Field40;
    if (m_Field40) {
        sub_00201990(7, t2);
    }
    sub_0016E130();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

