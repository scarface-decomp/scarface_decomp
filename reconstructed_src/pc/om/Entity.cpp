// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, om/Entity.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] om::Entity::vfunc_03 (0x006ED440, 51 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::Entity::vfunc_03 (0x002CF860), which was matched first;
// its addresses and names were swapped for this function's.
// om::Entity::vfunc_03 (0x006ED440, 51 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006F2A40(int);
};

extern "C" char DAT_0073523C[];
extern "C" char DAT_007725C0[];
extern "C" Object DAT_0085CE88;
extern "C" void __cdecl sub_0043CE70(int);

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
    *(int*)this = (int)DAT_007725C0;
    DAT_0085CE88.sub_006F2A40((int)(&m_Field04));
    *(int*)this = (int)DAT_0073523C;
    if (a1 & 1) {
        sub_0043CE70((int)this);
    }
    return this;
}

}

