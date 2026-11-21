// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/StatePropData.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::prop::StatePropData::vfunc_03 (0x0026EB50, 33 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::frontend::Text::vfunc_03 (0x00249C40), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x0026EB50
// what: Deleting destructor: runs the destructor, then frees the object when asked to.
// tool: Claude Opus 5.5 (byte copy of the matched 0x0023B160 with its own addresses, examiner A6: pure3d::prop::StatePropData::vfunc_03)

extern "C" void __cdecl sub_0023F7A0(void* p);

class Class_0026EB50
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual Class_0026EB50* sub_0026EB50(unsigned int flags);
    void sub_0026EAA0();
};

#pragma optimize("y", off)
Class_0026EB50* Class_0026EB50::sub_0026EB50(unsigned int flags)
{
    sub_0026EAA0();
    if (flags & 1)
        sub_0023F7A0(this);
    return this;
}
#pragma optimize("", on)

