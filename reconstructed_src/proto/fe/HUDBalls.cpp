// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, fe/HUDBalls.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 6 functions matched (33.33%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] HUDBalls::vfunc_00 (0x001712B0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// HUDBalls::vfunc_00 (0x001712B0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00410790[];

class HUDBalls
{
public:
    virtual void* vfunc_00();
};

void* HUDBalls::vfunc_00()
{
    return DAT_00410790;
}

// ============================================================================
// [VERIFIED] HUDBalls::vfunc_01 (0x00171F30, 87 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// HUDBalls::vfunc_01 (Proto 0x00171F30, 87 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00(int);
};

extern "C" char DAT_003987C8[];
extern "C" char DAT_003987D4[];
extern "C" char DAT_00398894[];
extern "C" char DAT_0039889C[];
extern "C" void __cdecl sub_00025160(int);

class HUDBalls
{
public:
    virtual void vfunc_00();
    virtual HUDBalls* vfunc_01(int a1);
    void sub_0016E130();
    char m_pad04[0x3C];
    int m_Field40; // +0x40
    int m_Field44; // +0x44
    char m_pad48[0x30];
    int m_Field78; // +0x78
};

HUDBalls* HUDBalls::vfunc_01(int a1)
{
    int t1, t3;

    t1 = m_Field78;
    *(int*)this = (int)DAT_0039889C;
    m_Field40 = (int)DAT_00398894;
    if (m_Field78) {
        sub_00025160(t1);
    }
    t3 = m_Field44;
    *(int*)this = (int)DAT_003987D4;
    m_Field40 = (int)DAT_003987C8;
    if (m_Field44) {
        ((Object*)t3)->vfunc_00(1);
    }
    sub_0016E130();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

