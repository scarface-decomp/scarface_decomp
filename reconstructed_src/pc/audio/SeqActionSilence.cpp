// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, audio/SeqActionSilence.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 4 functions matched (50.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_PC_1002.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::SeqActionSilence::vfunc_01 (0x006FA680, 29 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqActionSilence::vfunc_01 (0x002DCAD0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionSilence::vfunc_01 (0x006FA680, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_006DC040(void);

namespace audio {

class SeqActionSilence
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01(int a1);
    void sub_006F57A0(int, int);
    char m_pad04[0x18];
    int m_Field1C; // +0x1C
};

void SeqActionSilence::vfunc_01(int a1)
{
    m_Field1C = sub_006DC040();
    sub_006F57A0(3, a1);
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionSilence::vfunc_00 (0x006FA780, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionSilence::vfunc_00 (0x006FA780, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772F80[];
extern "C" char DAT_007F7C54[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqActionSilence
{
public:
    virtual SeqActionSilence* vfunc_00(int a1);
};

SeqActionSilence* SeqActionSilence::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772F80;
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7C54, (int)this);
    }
    return this;
}

}

