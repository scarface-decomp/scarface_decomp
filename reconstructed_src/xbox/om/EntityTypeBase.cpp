// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, om/EntityTypeBase.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] om::EntityTypeBase::vfunc_00 (0x002CF7D0, 45 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// om::EntityTypeBase::vfunc_00 (0x002CF7D0, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_002D4B90(int);
};

extern "C" char DAT_003DFD0C[];
extern "C" Object DAT_004BFF30;
extern "C" void __cdecl sub_00027600(int);

namespace om {

class EntityTypeBase
{
public:
    virtual EntityTypeBase* vfunc_00(int a1);
    char m_pad04[0x18];
    int m_Field1C; // +0x1C
};

EntityTypeBase* EntityTypeBase::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003DFD0C;
    DAT_004BFF30.sub_002D4B90((int)(&m_Field1C));
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

}

