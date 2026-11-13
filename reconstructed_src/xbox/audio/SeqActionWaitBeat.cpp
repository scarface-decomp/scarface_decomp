// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, audio/SeqActionWaitBeat.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 5 functions matched (40.00%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::SeqActionWaitBeat::vfunc_00 (0x002DA030, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionWaitBeat::vfunc_00 (0x002DA030, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003E07F4[];
extern "C" char DAT_004641F0[];
extern "C" void __cdecl sub_002CF980(int, int);

namespace audio {

class SeqActionWaitBeat
{
public:
    virtual SeqActionWaitBeat* vfunc_00(int a1);
};

SeqActionWaitBeat* SeqActionWaitBeat::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003E07F4;
    if (a1 & 1) {
        sub_002CF980((int)DAT_004641F0, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionWaitBeat::vfunc_02 (0x002DA2A0, 60 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::SeqActionWaitBeat::vfunc_02 (0x002DA2A0, 60 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_002D2600(int);
};

namespace audio {

class SeqActionWaitBeat
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(int a1, int a2);
    void sub_002D6A60(int, int);
    int m_Field04; // +0x04
    char m_pad08[0xC];
    int m_Field14; // +0x14
    int m_Field18; // +0x18
};

void SeqActionWaitBeat::vfunc_02(int a1, int a2)
{
    int t2;

    t2 = ((Object*)*(int*)(*(int*)(*(int*)(a1 + 20) + 36) + 52) + 44)->sub_002D2600(m_Field04 + 16);
    m_Field18 = t2;
    if (t2) {
        m_Field14 = *(int*)(t2 + 56);
    }
    sub_002D6A60(2, a1);
}

}

