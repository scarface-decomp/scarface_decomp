// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/pddiPrimBuffer.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::pddiPrimBuffer::vfunc_03 (0x002AD380, 39 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as fight::Param::vfunc_03 (0x00239CE0), which was matched first;
// its addresses and names were swapped for this function's.
extern "C" char DAT_003DAD84[];
extern "C" void __cdecl sub_00027600(void* p);

namespace pure3d {

class pddiPrimBuffer
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual pddiPrimBuffer* vfunc_03(unsigned int flags);
    void sub_002A06C0();
};

#pragma optimize("y", off)
pddiPrimBuffer* pddiPrimBuffer::vfunc_03(unsigned int flags)
{
    *(void**)this = DAT_003DAD84;
    sub_002A06C0();
    if (flags & 1)
        sub_00027600(this);
    return this;
}
#pragma optimize("", on)

}

