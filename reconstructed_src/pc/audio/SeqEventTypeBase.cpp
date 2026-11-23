// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, audio/SeqEventTypeBase.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::SeqEventTypeBase::vfunc_00 (0x006F5C10, 61 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: audio::SeqEventTypeBase's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// Same machine code as audio::SeqEventTypeBase::vfunc_00 (Proto 0x0029EE70), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventTypeBase::vfunc_00 (Proto 0x006F5C10, 61 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field20
{
    void sub_006EBBD0();
};

struct Object
{
    void sub_006F2A40(int);
};

extern "C" char DAT_00772DEC[];
extern "C" Object DAT_0085D4D8;
extern "C" void __cdecl sub_0043CE70(int);

namespace audio {

class SeqEventTypeBase
{
public:
    virtual SeqEventTypeBase* vfunc_00(int a1);
    int m_Field04; // +0x04
    char m_pad08[0xC];
    Field20 m_Field14; // +0x14
    char m_pad15[0xB];
    Field20 m_Field20; // +0x20
};

SeqEventTypeBase* SeqEventTypeBase::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772DEC;
    DAT_0085D4D8.sub_006F2A40((int)(&m_Field04));
    m_Field20.sub_006EBBD0();
    m_Field14.sub_006EBBD0();
    if (a1 & 1) {
        sub_0043CE70((int)this);
    }
    return this;
}

}

