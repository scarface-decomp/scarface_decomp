// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, om/Entity.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] om::Entity::vfunc_03 (0x002CF860, 51 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// om::Entity::vfunc_03 (0x002CF860, 51 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_002D4B90(int);
};

extern "C" char DAT_0039E22C[];
extern "C" char DAT_003DFD20[];
extern "C" Object DAT_004BFF1C;
extern "C" void __cdecl sub_00027600(int);

namespace om {

class Entity
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual Entity* vfunc_03(int a1);
    int m_Field04; // +0x04
};

Entity* Entity::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_003DFD20;
    DAT_004BFF1C.sub_002D4B90((int)(&m_Field04));
    *(int*)this = (int)DAT_0039E22C;
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

}

