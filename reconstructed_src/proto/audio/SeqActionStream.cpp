// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, audio/SeqActionStream.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 5 functions matched (40.00%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::SeqActionStream::vfunc_02 (0x002A8580, 65 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::SeqActionStream::vfunc_02 (Proto 0x002A8580, 65 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_0029E790(int, int);

namespace audio {

class SeqActionStream
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02(int a1, bool a2);
    char m_pad04[0xC];
    int m_Field10; // +0x10
    int m_Field14; // +0x14
    int m_Field18; // +0x18
    char m_pad1C[0xC];
    int m_Field28; // +0x28
};

int SeqActionStream::vfunc_02(int a1, bool a2)
{
    int t2;

    sub_0029E790(1, a1);
    if (a2) {
        m_Field18 = 0;
        m_Field10 = -1;
        m_Field14 = -1;
        m_Field28 = -0x39E3C000;
        return -1;
    }
    t2 = *(int*)(a1 + 52);
    m_Field28 = *(int*)(a1 + 52);
    return t2;
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionStream::vfunc_00 (0x002A8870, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionStream::vfunc_00 (0x002A8870, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B9F28[];
extern "C" char DAT_004912BC[];
extern "C" void __cdecl sub_002935D0(int, int);

namespace audio {

class SeqActionStream
{
public:
    virtual SeqActionStream* vfunc_00(int a1);
};

SeqActionStream* SeqActionStream::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003B9F28;
    if (a1 & 1) {
        sub_002935D0((int)DAT_004912BC, (int)this);
    }
    return this;
}

}

