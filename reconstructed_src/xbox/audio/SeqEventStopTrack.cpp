// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, audio/SeqEventStopTrack.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 5 functions matched (80.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::SeqEventStopTrack::vfunc_00 (0x002DA590, 103 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::SeqEventStopTrack::vfunc_00 (0x002DA590, 103 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_002CF040(int, int);
extern "C" bool __cdecl sub_002D6250(int, int);
extern "C" bool __cdecl sub_002D6320(int, int);
extern "C" bool __stdcall sub_002D6A00(int);

namespace audio {

class SeqEventStopTrack
{
public:
    virtual int vfunc_00(int a1);
    char m_pad04[0x4];
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
};

int SeqEventStopTrack::vfunc_00(int a1)
{
    if (sub_002D6A00(a1)) {
        if (!sub_002D6320(a1, (int)(&m_Field08))) goto L_60;
        if (!sub_002D6320(a1, (int)(&m_Field0C))) goto L_60;
        if (!sub_002CF040(a1, (int)(&m_Field10))) goto L_60;
        if (!sub_002D6250(a1, (int)this + 28)) goto L_60;
        return 1;
    }
L_60:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventStopTrack::vfunc_03 (0x002DA620, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (0x002D8D80), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventStopTrack::vfunc_03 (0x002DA620, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004C04C0;

namespace audio {

class SeqEventStopTrack
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventStopTrack::vfunc_03()
{
    return DAT_004C04C0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventStopTrack::vfunc_04 (0x002DA660, 45 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::SeqEventStopTrack::vfunc_04 (0x002DA660, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field10
{
    void sub_002CE560();
};

extern "C" char DAT_00464330[];
extern "C" void __cdecl sub_002CF980(int, int);

namespace audio {

class SeqEventStopTrack
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual SeqEventStopTrack* vfunc_04(int a1);
    void sub_002D69E0();
    char m_pad04[0xC];
    Field10 m_Field10; // +0x10
};

SeqEventStopTrack* SeqEventStopTrack::vfunc_04(int a1)
{
    m_Field10.sub_002CE560();
    sub_002D69E0();
    if (a1 & 1) {
        sub_002CF980((int)DAT_00464330, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventStopTrack::vfunc_02 (0x002DA690, 67 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventChannelSendVolumes::vfunc_02 (0x002D8FA0), which was matched first;
// its addresses and names were swapped for this function's.
#include <stddef.h>

struct Object
{
    void sub_002E21B0(int);
};

extern "C" char DAT_003E0BBC[];
extern "C" char DAT_00464338[];
extern "C" int __cdecl sub_002CF960(int);

namespace audio {

class SeqEventStopTrack;

struct Instance
{
    void* m_vtable;
    SeqEventStopTrack* m_parent;
    int m_unk8;
    int m_unkC;
    bool m_unk10;

    void* operator new(size_t)
    {
        return (void*)sub_002CF960((int)DAT_00464338);
    }

    Instance(SeqEventStopTrack* parent)
    {
        m_unkC = 0;
        m_unk10 = false;
        m_parent = parent;
        m_vtable = DAT_003E0BBC;
    }
};

class SeqEventStopTrack
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(int a1);
    virtual int vfunc_03();
    virtual SeqEventStopTrack* vfunc_04(int a1);
};

void SeqEventStopTrack::vfunc_02(int a1)
{
    ((Object*)a1)->sub_002E21B0((int)new Instance(this));
}

}

