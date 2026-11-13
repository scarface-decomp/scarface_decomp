// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, audio/SeqActionCrossFade.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 5 functions matched (40.00%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_PC_1002.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::SeqActionCrossFade::vfunc_04 (0x006FAFB0, 40 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqActionCrossFade::vfunc_04 (0x002DD3A0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionCrossFade::vfunc_04 (0x006FAFB0, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field14
{
    void sub_006FDB80();
};

namespace audio {

class SeqActionCrossFade
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int a1);
    void sub_006F57A0(int, int);
    char m_pad04[0x10];
    Field14* m_Field14; // +0x14
};

void SeqActionCrossFade::vfunc_04(int a1)
{
    if (m_Field14) {
        m_Field14->sub_006FDB80();
        m_Field14 = 0;
    }
    sub_006F57A0(0, a1);
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionCrossFade::vfunc_00 (0x006FB100, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionCrossFade::vfunc_00 (0x006FB100, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772F80[];
extern "C" char DAT_007F7E40[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqActionCrossFade
{
public:
    virtual SeqActionCrossFade* vfunc_00(int a1);
};

SeqActionCrossFade* SeqActionCrossFade::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772F80;
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7E40, (int)this);
    }
    return this;
}

}

