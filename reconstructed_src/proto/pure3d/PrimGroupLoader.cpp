// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, pure3d/PrimGroupLoader.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::PrimGroupLoader::vfunc_03 (0x00250B40, 57 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Tears down the loader: releases its child object, cleans up, and frees itself when asked to.
// ============================================================================
// bin: proto
// va: 0x00250B40
// what: Tears down the loader: releases its child object, cleans up, and frees itself when asked to.
// tool: Claude Opus 5.5 (transplanted from xb:0x000E3ED0, nearest by portal/tools/similar.py)
struct Child
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" char DAT_003B2038[];
extern "C" void __cdecl sub_00025160(void* p);

namespace pure3d {
class PrimGroupLoader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual PrimGroupLoader* vfunc_03(unsigned int flags);
    void sub_001F7E30();

    void* m_vtable_unused;
    Child* m_child; // +0x08
};

// Deleting destructor: releases the child it owns, runs the base destructor, frees itself when asked.
// The volatile accesses keep the vtable store ahead of the read, as the compiler does in a real destructor.
PrimGroupLoader* PrimGroupLoader::vfunc_03(unsigned int flags)
{
    *(void* volatile*)this = DAT_003B2038;
    Child* child = *(Child* volatile*)&m_child;
    if (child) {
        child->vfunc_01();
        m_child = 0;
    }
    sub_001F7E30();
    if (flags & 1)
        sub_00025160(this);
    return this;
}
}

