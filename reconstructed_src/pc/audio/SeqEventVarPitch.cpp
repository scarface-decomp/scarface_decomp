// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, audio/SeqEventVarPitch.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 4 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::SeqEventVarPitch::vfunc_00 (0x006F9A40, 52 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_01 (0x002D8D00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventVarPitch::vfunc_00 (0x006F9A40, 52 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_006F33D0(int, int);
extern "C" bool __stdcall sub_006F5740(int);

namespace audio {

class SeqEventVarPitch
{
public:
    virtual void vfunc_00();
    virtual int vfunc_00(int a1);
};

int SeqEventVarPitch::vfunc_00(int a1)
{
    if (sub_006F5740(a1)) {
        if (!sub_006F33D0(a1, (int)this + 8)) goto L_2D;
        return 1;
    }
L_2D:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventVarPitch::vfunc_03 (0x006F9AB0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (PC 0x006F6960), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x006F9AB0
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventVarPitch::vfunc_03 (0x006F9AB0, 6 bytes)
extern "C" int DAT_0085D540;

namespace audio {

class SeqEventVarPitch
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventVarPitch::vfunc_03()
{
    return DAT_0085D540;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventVarPitch::vfunc_04 (0x006F9AC0, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::StatePropSoundPlayer::vfunc_00 (0x00082430), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventVarPitch::vfunc_04 (0x006F9AC0, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F7B3C[];
extern "C" void __cdecl sub_006F5730(void);
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqEventVarPitch
{
public:
    virtual SeqEventVarPitch* vfunc_04(int a1);
};

SeqEventVarPitch* SeqEventVarPitch::vfunc_04(int a1)
{
    sub_006F5730();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7B3C, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventVarPitch::vfunc_02 (0x006F9AF0, 67 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventChannelSendVolumes::vfunc_02 (0x002D8FA0), which was matched first;
// its addresses and names were swapped for this function's.
#include <stddef.h>

struct Object
{
    void sub_007007A0(int);
};

extern "C" char DAT_007736D8[];
extern "C" char DAT_007F7B44[];
extern "C" int __cdecl sub_006EE870(int);

namespace audio {

class SeqEventVarPitch;

struct Instance
{
    void* m_vtable;
    SeqEventVarPitch* m_parent;
    int m_unk8;
    int m_unkC;
    bool m_unk10;

    void* operator new(size_t)
    {
        return (void*)sub_006EE870((int)DAT_007F7B44);
    }

    Instance(SeqEventVarPitch* parent)
    {
        m_unkC = 0;
        m_unk10 = false;
        m_parent = parent;
        m_vtable = DAT_007736D8;
    }
};

class SeqEventVarPitch
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(int a1);
    virtual int vfunc_03();
    virtual SeqEventVarPitch* vfunc_04(int a1);
};

void SeqEventVarPitch::vfunc_02(int a1)
{
    ((Object*)a1)->sub_007007A0((int)new Instance(this));
}

}

