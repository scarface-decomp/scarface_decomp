// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, audio/SeqEventChannelSendVolumes.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 5 functions matched (60.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::SeqEventChannelSendVolumes::vfunc_02 (0x002D8FA0, 67 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
#include <stddef.h>

struct Object
{
    void sub_002E21B0(int);
};

extern "C" char DAT_003E0828[];
extern "C" char DAT_00463EBC[];
extern "C" int __cdecl sub_002CF960(int);

namespace audio {

class SeqEventChannelSendVolumes;

struct Instance
{
    void* m_vtable;
    SeqEventChannelSendVolumes* m_parent;
    int m_unk8;
    int m_unkC;
    bool m_unk10;

    void* operator new(size_t)
    {
        return (void*)sub_002CF960((int)DAT_00463EBC);
    }

    Instance(SeqEventChannelSendVolumes* parent)
    {
        m_unkC = 0;
        m_unk10 = false;
        m_parent = parent;
        m_vtable = DAT_003E0828;
    }
};

class SeqEventChannelSendVolumes
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(int a1);
    virtual int vfunc_03();
    virtual SeqEventChannelSendVolumes* vfunc_04(int a1);
};

void SeqEventChannelSendVolumes::vfunc_02(int a1)
{
    ((Object*)a1)->sub_002E21B0((int)new Instance(this));
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventChannelSendVolumes::vfunc_03 (0x002D92D0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (0x002D8D80), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventChannelSendVolumes::vfunc_03 (0x002D92D0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004C0498;

namespace audio {

class SeqEventChannelSendVolumes
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventChannelSendVolumes::vfunc_03()
{
    return DAT_004C0498;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventChannelSendVolumes::vfunc_04 (0x002D92E0, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::StatePropSoundPlayer::vfunc_00 (0x00082430), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventChannelSendVolumes::vfunc_04 (0x002D92E0, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00463EB4[];
extern "C" void __cdecl sub_002D69E0(void);
extern "C" void __cdecl sub_002CF980(int, int);

namespace audio {

class SeqEventChannelSendVolumes
{
public:
    virtual SeqEventChannelSendVolumes* vfunc_04(int a1);
};

SeqEventChannelSendVolumes* SeqEventChannelSendVolumes::vfunc_04(int a1)
{
    sub_002D69E0();
    if (a1 & 1) {
        sub_002CF980((int)DAT_00463EB4, (int)this);
    }
    return this;
}

}

