// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/AmbientLight.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 3 functions matched (66.67%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::AmbientLight::vfunc_07 (0x00260650, 10 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Activates the ambient light by calling vfunc_11 with 1.
// ============================================================================
// bin: xb
// va: 0x00260650
// what: Activates the ambient light by calling vfunc_11 with 1.
// tool: Gemini 4 Neon

namespace pure3d {

class AmbientLight
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07(unsigned int slot);
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11(bool enable);
};

#pragma optimize("s", on)
void AmbientLight::vfunc_07(unsigned int)
{
    vfunc_11(true);
}
#pragma optimize("", on)

}

// ============================================================================
// [VERIFIED] pure3d::AmbientLight::vfunc_03 (0x00260680, 39 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: pure3d::AmbientLight's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// Same machine code as fight::Param::vfunc_03 (0x00239CE0), which was matched first;
// its addresses and names were swapped for this function's.
extern "C" char DAT_003D5E5C[];
extern "C" void __cdecl sub_0023F7A0(void* p);

namespace pure3d {

class AmbientLight
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual AmbientLight* vfunc_03(unsigned int flags);
    void sub_0025FD40();
};

#pragma optimize("y", off)
AmbientLight* AmbientLight::vfunc_03(unsigned int flags)
{
    *(void**)this = DAT_003D5E5C;
    sub_0025FD40();
    if (flags & 1)
        sub_0023F7A0(this);
    return this;
}
#pragma optimize("", on)

}

