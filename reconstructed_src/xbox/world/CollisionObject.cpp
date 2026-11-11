// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, world/CollisionObject.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ravenphysics::CollisionObject::vfunc_03 (0x002E4A20, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionManager::CollisionManagerFlowClient::vfunc_00 (0x00016060), which was matched first;
// its addresses and names were swapped for this function's.
// ravenphysics::CollisionObject::vfunc_03 (0x002E4A20, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_002E4870(void);
extern "C" void __cdecl sub_0023F7A0(int);

namespace ravenphysics {

class CollisionObject
{
public:
    virtual CollisionObject* vfunc_03(int a1);
};

CollisionObject* CollisionObject::vfunc_03(int a1)
{
    sub_002E4870();
    if (a1 & 1) {
        sub_0023F7A0((int)this);
    }
    return this;
}

}

