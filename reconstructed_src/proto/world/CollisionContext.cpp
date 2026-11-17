// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, world/CollisionContext.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ravenphysics::CollisionContext::vfunc_03 (0x002B7FC0, 45 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as fight::ScriptReader::vfunc_03 (Proto 0x001FB3F0), which was matched first;
// its addresses and names were swapped for this function's.
// ravenphysics::CollisionContext::vfunc_03 (Proto 0x002B7FC0, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" char DAT_0037D85C[];
extern "C" char DAT_003BB818[];
extern "C" void __cdecl sub_001FCF60(int);

namespace ravenphysics {

class CollisionContext
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual CollisionContext* vfunc_03(int a1);
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

CollisionContext* CollisionContext::vfunc_03(int a1)
{
    int t1;

    t1 = m_Field08;
    *(int*)this = (int)DAT_003BB818;
    ((Object*)t1)->vfunc_01();
    *(int*)this = (int)DAT_0037D85C;
    if (a1 & 1) {
        sub_001FCF60((int)this);
    }
    return this;
}

}

