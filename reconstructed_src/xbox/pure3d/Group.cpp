// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/Group.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::frontend::Group::vfunc_03 (0x0028E3E0, 39 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::frontend::Drawable::vfunc_03 (0x00248C00), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x0028E3E0
// what: Deleting destructor: puts back the class's vtable, runs the destructor, then frees the object when asked to.
// tool: Claude Opus 5.5 (byte copy of the matched 0x00239CE0 with its own addresses, examiner A6: pure3d::frontend::Group::vfunc_03)

extern "C" char DAT_003D8858[];
extern "C" void __cdecl sub_0023F7A0(void* p);

class Class_0028E3E0
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual Class_0028E3E0* sub_0028E3E0(unsigned int flags);
    void sub_0028D930();
};

#pragma optimize("y", off)
Class_0028E3E0* Class_0028E3E0::sub_0028E3E0(unsigned int flags)
{
    *(void**)this = DAT_003D8858;
    sub_0028D930();
    if (flags & 1)
        sub_0023F7A0(this);
    return this;
}
#pragma optimize("", on)

