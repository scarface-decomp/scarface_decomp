// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, audio/SeqEventChannelSendVolumes.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 5 functions matched (60.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_PC_1002.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::SeqEventChannelSendVolumes::vfunc_02 (0x006F6B80, 67 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventChannelSendVolumes::vfunc_02 (0x002D8FA0), which was matched first;
// its addresses and names were swapped for this function's.
#include <stddef.h>

struct Object
{
    void sub_007007A0(int);
};

extern "C" char DAT_00772FB4[];
extern "C" char DAT_007F7144[];
extern "C" int __cdecl sub_006EE870(int);

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
        return (void*)sub_006EE870((int)DAT_007F7144);
    }

    Instance(SeqEventChannelSendVolumes* parent)
    {
        m_unkC = 0;
        m_unk10 = false;
        m_parent = parent;
        m_vtable = DAT_00772FB4;
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
    ((Object*)a1)->sub_007007A0((int)new Instance(this));
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventChannelSendVolumes::vfunc_03 (0x006F6EC0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (PC 0x006F6960), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x006F6EC0
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventChannelSendVolumes::vfunc_03 (0x006F6EC0, 6 bytes)
extern "C" int DAT_0085D4F4;

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
    return DAT_0085D4F4;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventChannelSendVolumes::vfunc_04 (0x006F6ED0, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::StatePropSoundPlayer::vfunc_00 (0x00082430), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventChannelSendVolumes::vfunc_04 (0x006F6ED0, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F713C[];
extern "C" void __cdecl sub_006F5730(void);
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqEventChannelSendVolumes
{
public:
    virtual SeqEventChannelSendVolumes* vfunc_04(int a1);
};

SeqEventChannelSendVolumes* SeqEventChannelSendVolumes::vfunc_04(int a1)
{
    sub_006F5730();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F713C, (int)this);
    }
    return this;
}

}

