// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, audio/SeqActionChannelSends.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::SeqActionChannelSends::vfunc_00 (0x002A2720, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionChannelSends::vfunc_00 (0x002A2720, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B9F28[];
extern "C" char DAT_00490FBC[];
extern "C" void __cdecl sub_002935D0(int, int);

namespace audio {

class SeqActionChannelSends
{
public:
    virtual SeqActionChannelSends* vfunc_00(int a1);
};

SeqActionChannelSends* SeqActionChannelSends::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003B9F28;
    if (a1 & 1) {
        sub_002935D0((int)DAT_00490FBC, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionChannelSends::vfunc_06 (0x002A28A0, 37 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x002A28A0
// what: 
// tool: the portal's starter code (no AI)

// audio::SeqActionChannelSends::vfunc_06 (Proto 0x002A28A0, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00296A60(int);
};

namespace audio {

class SeqActionChannelSends
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual int vfunc_06(int a1);
    int m_Field04; // +0x04
};

int SeqActionChannelSends::vfunc_06(int a1)
{
    int t2;

    t2 = ((Object*)*(int*)(a1 + 20))->sub_00296A60(m_Field04 + 304);
    *(int*)(t2 + 80) = m_Field04 + 48;
    return t2;
}

}

