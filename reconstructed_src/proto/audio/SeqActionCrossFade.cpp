// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, audio/SeqActionCrossFade.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 5 functions matched (40.00%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::SeqActionCrossFade::vfunc_04 (0x002A9E80, 40 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::SeqActionCrossFade::vfunc_04 (Proto 0x002A9E80, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field10
{
    void sub_00297E30();
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
    void sub_0029E790(int, int);
    char m_pad04[0xC];
    Field10* m_Field10; // +0x10
};

void SeqActionCrossFade::vfunc_04(int a1)
{
    if (m_Field10) {
        m_Field10->sub_00297E30();
        m_Field10 = 0;
    }
    sub_0029E790(0, a1);
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionCrossFade::vfunc_00 (0x002AA000, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionCrossFade::vfunc_00 (0x002AA000, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B9F28[];
extern "C" char DAT_0049137C[];
extern "C" void __cdecl sub_002935D0(int, int);

namespace audio {

class SeqActionCrossFade
{
public:
    virtual SeqActionCrossFade* vfunc_00(int a1);
};

SeqActionCrossFade* SeqActionCrossFade::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003B9F28;
    if (a1 & 1) {
        sub_002935D0((int)DAT_0049137C, (int)this);
    }
    return this;
}

}

