// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, audio/SeqEventExpression.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 3 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::SeqEventExpression::vfunc_03 (0x002DA310, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (0x002D8D80), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventExpression::vfunc_03 (0x002DA310, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004C04BC;

namespace audio {

class SeqEventExpression
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventExpression::vfunc_03()
{
    return DAT_004C04BC;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventExpression::vfunc_04 (0x002DA320, 45 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_04 (0x002D8D90), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventExpression::vfunc_04 (0x002DA320, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    void sub_002CE560();
};

extern "C" char DAT_0046428C[];
extern "C" void __cdecl sub_002CF980(int, int);

namespace audio {

class SeqEventExpression
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual SeqEventExpression* vfunc_04(int a1);
    void sub_002D69E0();
    char m_pad04[0x4];
    Field08 m_Field08; // +0x08
};

SeqEventExpression* SeqEventExpression::vfunc_04(int a1)
{
    m_Field08.sub_002CE560();
    sub_002D69E0();
    if (a1 & 1) {
        sub_002CF980((int)DAT_0046428C, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventExpression::vfunc_02 (0x002DA350, 67 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventChannelSendVolumes::vfunc_02 (0x002D8FA0), which was matched first;
// its addresses and names were swapped for this function's.
#include <stddef.h>

struct Object
{
    void sub_002E21B0(int);
};

extern "C" char DAT_003E0B18[];
extern "C" char DAT_00464294[];
extern "C" int __cdecl sub_002CF960(int);

namespace audio {

class SeqEventExpression;

struct Instance
{
    void* m_vtable;
    SeqEventExpression* m_parent;
    int m_unk8;
    int m_unkC;
    bool m_unk10;

    void* operator new(size_t)
    {
        return (void*)sub_002CF960((int)DAT_00464294);
    }

    Instance(SeqEventExpression* parent)
    {
        m_unkC = 0;
        m_unk10 = false;
        m_parent = parent;
        m_vtable = DAT_003E0B18;
    }
};

class SeqEventExpression
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(int a1);
    virtual int vfunc_03();
    virtual SeqEventExpression* vfunc_04(int a1);
};

void SeqEventExpression::vfunc_02(int a1)
{
    ((Object*)a1)->sub_002E21B0((int)new Instance(this));
}

}

