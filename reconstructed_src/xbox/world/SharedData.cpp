// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, world/SharedData.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ravenphysics::CollisionMesh::SharedData::vfunc_03 (0x002EA6B0, 30 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: ravenphysics::CollisionMesh::SharedData's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// Same machine code as pure3d::frontend::Text::vfunc_03 (Proto 0x00206FC0), which was matched first;
// its addresses and names were swapped for this function's.
// ravenphysics::CollisionMesh::SharedData::vfunc_03 (Proto 0x002EA6B0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_002EA3D0(void);

namespace ravenphysics { namespace CollisionMesh {

class SharedData
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual SharedData* vfunc_03(int a1);
};

SharedData* SharedData::vfunc_03(int a1)
{
    sub_002EA3D0();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

} }

