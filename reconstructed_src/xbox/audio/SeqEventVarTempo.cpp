// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, audio/SeqEventVarTempo.cpp (5 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 5 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::SeqEventVarTempo::vfunc_01 (0x002DB7A0, 65 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::SeqEventVarTempo::vfunc_01 (0x002DB7A0, 65 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    bool sub_002D58C0(int);
};

extern "C" bool __cdecl sub_002D6340(int, int);
extern "C" bool __stdcall sub_002D6A20(int);

namespace audio {

class SeqEventVarTempo
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1);
    char m_pad04[0x4];
    Field08 m_Field08; // +0x08
    char m_pad09[0x7];
    int m_Field10; // +0x10
};

int SeqEventVarTempo::vfunc_01(int a1)
{
    if (sub_002D6A20(a1)) {
        if (!m_Field08.sub_002D58C0(a1)) goto L_3A;
        if (!sub_002D6340(a1, m_Field10)) goto L_3A;
        return 1;
    }
L_3A:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventVarTempo::vfunc_00 (0x002DB7F0, 65 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::SeqEventVarTempo::vfunc_00 (0x002DB7F0, 65 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    bool sub_002D5880(int);
};

extern "C" bool __cdecl sub_002D6320(int, int);
extern "C" bool __stdcall sub_002D6A00(int);

namespace audio {

class SeqEventVarTempo
{
public:
    virtual int vfunc_00(int a1);
    char m_pad04[0x4];
    Field08 m_Field08; // +0x08
};

int SeqEventVarTempo::vfunc_00(int a1)
{
    if (sub_002D6A00(a1)) {
        if (!m_Field08.sub_002D5880(a1)) goto L_3A;
        if (!sub_002D6320(a1, (int)this + 16)) goto L_3A;
        return 1;
    }
L_3A:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventVarTempo::vfunc_03 (0x002DB870, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (0x002D8D80), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventVarTempo::vfunc_03 (0x002DB870, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004C04D8;

namespace audio {

class SeqEventVarTempo
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventVarTempo::vfunc_03()
{
    return DAT_004C04D8;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventVarTempo::vfunc_04 (0x002DB880, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::StatePropSoundPlayer::vfunc_00 (0x00082430), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventVarTempo::vfunc_04 (0x002DB880, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004646B8[];
extern "C" void __cdecl sub_002D69E0(void);
extern "C" void __cdecl sub_002CF980(int, int);

namespace audio {

class SeqEventVarTempo
{
public:
    virtual SeqEventVarTempo* vfunc_04(int a1);
};

SeqEventVarTempo* SeqEventVarTempo::vfunc_04(int a1)
{
    sub_002D69E0();
    if (a1 & 1) {
        sub_002CF980((int)DAT_004646B8, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventVarTempo::vfunc_02 (0x002DB8B0, 67 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventChannelSendVolumes::vfunc_02 (0x002D8FA0), which was matched first;
// its addresses and names were swapped for this function's.
#include <stddef.h>

struct Object
{
    void sub_002E21B0(int);
};

extern "C" char DAT_003E0DF4[];
extern "C" char DAT_004646C0[];
extern "C" int __cdecl sub_002CF960(int);

namespace audio {

class SeqEventVarTempo;

struct Instance
{
    void* m_vtable;
    SeqEventVarTempo* m_parent;
    int m_unk8;
    int m_unkC;
    bool m_unk10;

    void* operator new(size_t)
    {
        return (void*)sub_002CF960((int)DAT_004646C0);
    }

    Instance(SeqEventVarTempo* parent)
    {
        m_unkC = 0;
        m_unk10 = false;
        m_parent = parent;
        m_vtable = DAT_003E0DF4;
    }
};

class SeqEventVarTempo
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(int a1);
    virtual int vfunc_03();
    virtual SeqEventVarTempo* vfunc_04(int a1);
};

void SeqEventVarTempo::vfunc_02(int a1)
{
    ((Object*)a1)->sub_002E21B0((int)new Instance(this));
}

}

