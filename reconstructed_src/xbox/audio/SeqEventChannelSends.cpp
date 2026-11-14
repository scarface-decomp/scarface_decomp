// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, audio/SeqEventChannelSends.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 5 functions matched (80.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::SeqEventChannelSends::vfunc_03 (0x002D95F0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (0x002D8D80), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventChannelSends::vfunc_03 (0x002D95F0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004C04A0;

namespace audio {

class SeqEventChannelSends
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventChannelSends::vfunc_03()
{
    return DAT_004C04A0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventChannelSends::vfunc_04 (0x002D9600, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::StatePropSoundPlayer::vfunc_00 (0x00082430), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventChannelSends::vfunc_04 (0x002D9600, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00463F70[];
extern "C" void __cdecl sub_002D69E0(void);
extern "C" void __cdecl sub_002CF980(int, int);

namespace audio {

class SeqEventChannelSends
{
public:
    virtual SeqEventChannelSends* vfunc_04(int a1);
};

SeqEventChannelSends* SeqEventChannelSends::vfunc_04(int a1)
{
    sub_002D69E0();
    if (a1 & 1) {
        sub_002CF980((int)DAT_00463F70, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventChannelSends::vfunc_00 (0x002D9630, 72 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::SeqEventChannelSends::vfunc_00 (0x002D9630, 72 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_002CFAA0(int, int);
extern "C" bool __cdecl sub_002D5D40(int, int);
extern "C" bool __stdcall sub_002D6A00(int);

namespace audio {

class SeqEventChannelSends
{
public:
    virtual int vfunc_00(int a1);
    char m_pad04[0x104];
    int m_Field108; // +0x108
};

int SeqEventChannelSends::vfunc_00(int a1)
{
    if (sub_002D6A00(a1)) {
        if (!sub_002CFAA0(a1, (int)(&m_Field108))) goto L_41;
        if (!sub_002D5D40(a1, (int)this + 8)) goto L_41;
        return 1;
    }
L_41:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventChannelSends::vfunc_02 (0x002D9680, 67 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventChannelSendVolumes::vfunc_02 (0x002D8FA0), which was matched first;
// its addresses and names were swapped for this function's.
#include <stddef.h>

struct Object
{
    void sub_002E21B0(int);
};

extern "C" char DAT_003E08DC[];
extern "C" char DAT_00463F78[];
extern "C" int __cdecl sub_002CF960(int);

namespace audio {

class SeqEventChannelSends;

struct Instance
{
    void* m_vtable;
    SeqEventChannelSends* m_parent;
    int m_unk8;
    int m_unkC;
    bool m_unk10;

    void* operator new(size_t)
    {
        return (void*)sub_002CF960((int)DAT_00463F78);
    }

    Instance(SeqEventChannelSends* parent)
    {
        m_unkC = 0;
        m_unk10 = false;
        m_parent = parent;
        m_vtable = DAT_003E08DC;
    }
};

class SeqEventChannelSends
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(int a1);
    virtual int vfunc_03();
    virtual SeqEventChannelSends* vfunc_04(int a1);
};

void SeqEventChannelSends::vfunc_02(int a1)
{
    ((Object*)a1)->sub_002E21B0((int)new Instance(this));
}

}

