// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/Project.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::frontend::Project::vfunc_03 (0x00250DD0, 33 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::frontend::Text::vfunc_03 (0x00249C40), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x00250DD0
// what: Deleting destructor: runs the destructor, then frees the object when asked to.
// tool: Claude Opus 5.5 (byte copy of the matched 0x0023B160 with its own addresses, examiner A6: pure3d::frontend::Project::vfunc_03)

extern "C" void __cdecl sub_0023F7A0(void* p);

class Class_00250DD0
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual Class_00250DD0* sub_00250DD0(unsigned int flags);
    void sub_0024FB50();
};

#pragma optimize("y", off)
Class_00250DD0* Class_00250DD0::sub_00250DD0(unsigned int flags)
{
    sub_0024FB50();
    if (flags & 1)
        sub_0023F7A0(this);
    return this;
}
#pragma optimize("", on)

