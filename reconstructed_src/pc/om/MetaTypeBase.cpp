// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, om/MetaTypeBase.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] om::MetaTypeBase::vfunc_00 (0x006ECB80, 74 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::MetaTypeBase::vfunc_00 (0x002CEFA0), which was matched first;
// its addresses and names were swapped for this function's.
// om::MetaTypeBase::vfunc_00 (0x006ECB80, 74 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field14
{
    void sub_006ECA90();
};

struct Object
{
    void sub_006F2A40(int);
};

extern "C" char DAT_00772564[];
extern "C" char DAT_007F64D8[];
extern "C" Object DAT_0085CE74;
extern "C" void __cdecl sub_006EE890(int, int);

namespace om {

class MetaTypeBase
{
public:
    virtual MetaTypeBase* vfunc_00(int a1);
    int m_Field04; // +0x04
    char m_pad08[0xC];
    Field14 m_Field14; // +0x14
    char m_pad15[0x13];
    Field14 m_Field28; // +0x28
    char m_pad29[0x13];
    Field14 m_Field3C; // +0x3C
};

MetaTypeBase* MetaTypeBase::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772564;
    DAT_0085CE74.sub_006F2A40((int)(&m_Field04));
    m_Field14.sub_006ECA90();
    m_Field3C.sub_006ECA90();
    m_Field28.sub_006ECA90();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F64D8, (int)this);
    }
    return this;
}

}

