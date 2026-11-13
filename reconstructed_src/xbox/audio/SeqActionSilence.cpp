// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, audio/SeqActionSilence.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 4 functions matched (75.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::SeqActionSilence::vfunc_02 (0x002DCAA0, 34 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::SeqActionSilence::vfunc_02 (0x002DCAA0, 34 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_002D6A60(int, int);

namespace audio {

class SeqActionSilence
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(int a1, bool a2);
    char m_pad04[0x10];
    int m_Field14; // +0x14
};

void SeqActionSilence::vfunc_02(int a1, bool a2)
{
    int r_eax;

    r_eax = a1;
    sub_002D6A60(2, a1);
    r_eax = a2;
    if (a2) {
        m_Field14 = 0;
    }
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionSilence::vfunc_01 (0x002DCAD0, 29 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::SeqActionSilence::vfunc_01 (0x002DCAD0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00242A50(void);

namespace audio {

class SeqActionSilence
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01(int a1);
    void sub_002D6A60(int, int);
    char m_pad04[0x18];
    int m_Field1C; // +0x1C
};

void SeqActionSilence::vfunc_01(int a1)
{
    m_Field1C = sub_00242A50();
    sub_002D6A60(3, a1);
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionSilence::vfunc_00 (0x002DCB90, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionSilence::vfunc_00 (0x002DCB90, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003E07F4[];
extern "C" char DAT_004649CC[];
extern "C" void __cdecl sub_002CF980(int, int);

namespace audio {

class SeqActionSilence
{
public:
    virtual SeqActionSilence* vfunc_00(int a1);
};

SeqActionSilence* SeqActionSilence::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003E07F4;
    if (a1 & 1) {
        sub_002CF980((int)DAT_004649CC, (int)this);
    }
    return this;
}

}

