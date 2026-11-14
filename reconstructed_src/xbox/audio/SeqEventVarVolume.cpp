// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, audio/SeqEventVarVolume.cpp (5 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 5 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::SeqEventVarVolume::vfunc_01 (0x002DB5B0, 52 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::SeqEventVarVolume::vfunc_01 (0x002DB5B0, 52 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_002D6340(int, int);
extern "C" bool __stdcall sub_002D6A20(int);

namespace audio {

class SeqEventVarVolume
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1);
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

int SeqEventVarVolume::vfunc_01(int a1)
{
    if (sub_002D6A20(a1)) {
        if (!sub_002D6340(a1, m_Field08)) goto L_2D;
        return 1;
    }
L_2D:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventVarVolume::vfunc_00 (0x002DB5F0, 32 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::SeqEventVarVolume::vfunc_00 (0x002DB5F0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_002D6320(int, int);
extern "C" void __stdcall sub_002D6A00(int);

namespace audio {

class SeqEventVarVolume
{
public:
    virtual void vfunc_00(int a1);
};

void SeqEventVarVolume::vfunc_00(int a1)
{
    sub_002D6A00(a1);
    sub_002D6320(a1, (int)this + 8);
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventVarVolume::vfunc_03 (0x002DB640, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (0x002D8D80), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventVarVolume::vfunc_03 (0x002DB640, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004C04D4;

namespace audio {

class SeqEventVarVolume
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventVarVolume::vfunc_03()
{
    return DAT_004C04D4;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventVarVolume::vfunc_04 (0x002DB650, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::StatePropSoundPlayer::vfunc_00 (0x00082430), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventVarVolume::vfunc_04 (0x002DB650, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00464614[];
extern "C" void __cdecl sub_002D69E0(void);
extern "C" void __cdecl sub_002CF980(int, int);

namespace audio {

class SeqEventVarVolume
{
public:
    virtual SeqEventVarVolume* vfunc_04(int a1);
};

SeqEventVarVolume* SeqEventVarVolume::vfunc_04(int a1)
{
    sub_002D69E0();
    if (a1 & 1) {
        sub_002CF980((int)DAT_00464614, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventVarVolume::vfunc_02 (0x002DB680, 67 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventChannelSendVolumes::vfunc_02 (0x002D8FA0), which was matched first;
// its addresses and names were swapped for this function's.
#include <stddef.h>

struct Object
{
    void sub_002E21B0(int);
};

extern "C" char DAT_003E0D84[];
extern "C" char DAT_0046461C[];
extern "C" int __cdecl sub_002CF960(int);

namespace audio {

class SeqEventVarVolume;

struct Instance
{
    void* m_vtable;
    SeqEventVarVolume* m_parent;
    int m_unk8;
    int m_unkC;
    bool m_unk10;

    void* operator new(size_t)
    {
        return (void*)sub_002CF960((int)DAT_0046461C);
    }

    Instance(SeqEventVarVolume* parent)
    {
        m_unkC = 0;
        m_unk10 = false;
        m_parent = parent;
        m_vtable = DAT_003E0D84;
    }
};

class SeqEventVarVolume
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(int a1);
    virtual int vfunc_03();
    virtual SeqEventVarVolume* vfunc_04(int a1);
};

void SeqEventVarVolume::vfunc_02(int a1)
{
    ((Object*)a1)->sub_002E21B0((int)new Instance(this));
}

}

