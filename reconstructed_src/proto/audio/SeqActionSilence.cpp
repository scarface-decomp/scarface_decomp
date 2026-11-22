// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, audio/SeqActionSilence.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 4 functions matched (75.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::SeqActionSilence::vfunc_02 (0x002A9020, 34 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Sends command 2 with the value given and, when asked to, clears the number at +0x10.
// ============================================================================
// bin: proto
// va: 0x002A9020
// what: Sends command 2 with the value given and, when asked to, clears the number at +0x10.
// tool: Claude Opus 5.5 (transplanted from xb:0x002DCAA0, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_0029E790(int, int);

namespace audio {

class SeqActionSilence
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(int a1, bool a2);
    char m_pad04[0xC];
    int m_Field10; // +0x10
};

void SeqActionSilence::vfunc_02(int a1, bool a2)
{
    int r_eax;

    r_eax = a1;
    sub_0029E790(2, a1);
    r_eax = a2;
    if (a2) {
        m_Field10 = 0;
    }
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionSilence::vfunc_01 (0x002A9050, 29 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::SeqActionSilence::vfunc_01 (Proto 0x002A9050, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_001FFF50(void);

namespace audio {

class SeqActionSilence
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01(int a1);
    void sub_0029E790(int, int);
    char m_pad04[0x14];
    int m_Field18; // +0x18
};

void SeqActionSilence::vfunc_01(int a1)
{
    m_Field18 = sub_001FFF50();
    sub_0029E790(3, a1);
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionSilence::vfunc_00 (0x002A9270, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionSilence::vfunc_00 (0x002A9270, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B9F28[];
extern "C" char DAT_004912EC[];
extern "C" void __cdecl sub_002935D0(int, int);

namespace audio {

class SeqActionSilence
{
public:
    virtual SeqActionSilence* vfunc_00(int a1);
};

SeqActionSilence* SeqActionSilence::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003B9F28;
    if (a1 & 1) {
        sub_002935D0((int)DAT_004912EC, (int)this);
    }
    return this;
}

}

