// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/pddiDevice.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::pddiDevice::vfunc_03 (0x002922B0, 39 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: pure3d::pddiDevice's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// Same machine code as fight::Param::vfunc_03 (0x00239CE0), which was matched first;
// its addresses and names were swapped for this function's.
extern "C" char DAT_003D8AD0[];
extern "C" void __cdecl sub_00027600(void* p);

namespace pure3d {

class pddiDevice
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual pddiDevice* vfunc_03(unsigned int flags);
    void sub_002A06C0();
};

#pragma optimize("y", off)
pddiDevice* pddiDevice::vfunc_03(unsigned int flags)
{
    *(void**)this = DAT_003D8AD0;
    sub_002A06C0();
    if (flags & 1)
        sub_00027600(this);
    return this;
}
#pragma optimize("", on)

}

// ============================================================================
// [VERIFIED] pure3d::pddiDevice::vfunc_13 (0x0029E590, 15 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dExtTODFactor::vfunc_04 (0x00263ED0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x0029E590
// what: Stores a value in the global at 0x004BDC50.
// tool: Claude Opus 5.5 (generated from the shape 'set int global (framed)', checked on decomp.me preset 266 by example)
#pragma optimize("y", off)

extern "C" int DAT_004BDC50;

void __stdcall sub_0029E590(int value)
{
    DAT_004BDC50 = value;
}

