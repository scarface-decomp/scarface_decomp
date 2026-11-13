// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/SequenceTrack.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] fight::SequenceTrack::vfunc_03 (0x0023E840, 57 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// fight::SequenceTrack::vfunc_03 (0x0023E840, 57 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

struct Field14
{
    void sub_0023F4F0();
};

struct Field20
{
    void sub_0023F2F0();
};

extern "C" char DAT_003D481C[];
extern "C" void __cdecl sub_0023F7A0(int);

namespace fight {

class SequenceTrack
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual SequenceTrack* vfunc_03(int a1);
    void sub_0023E5F0();
    char m_pad04[0x10];
    Field14 m_Field14; // +0x14
    char m_pad15[0xB];
    Field20 m_Field20; // +0x20
};

SequenceTrack* SequenceTrack::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_003D481C;
    m_Field20.sub_0023F2F0();
    m_Field14.sub_0023F4F0();
    sub_0023E5F0();
    if (a1 & 1) {
        sub_0023F7A0((int)this);
    }
    return this;
}

}

