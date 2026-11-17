// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, om/Entity.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] om::Entity::vfunc_03 (0x00293280, 59 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// om::Entity::vfunc_03 (Proto 0x00293280, 59 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field20
{
    void sub_00291040();
};

struct Object
{
    void sub_00297380(int);
};

extern "C" char DAT_0037D85C[];
extern "C" char DAT_003B9234[];
extern "C" Object DAT_00490BC4;
extern "C" void __cdecl sub_00025160(int);

namespace om {

class Entity
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual Entity* vfunc_03(int a1);
    int m_Field04; // +0x04
    char m_pad08[0x18];
    Field20 m_Field20; // +0x20
};

Entity* Entity::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_003B9234;
    DAT_00490BC4.sub_00297380((int)(&m_Field04));
    m_Field20.sub_00291040();
    *(int*)this = (int)DAT_0037D85C;
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

}

