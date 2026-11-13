// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/d3dExtDepthOfField.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 4 functions matched (50.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::d3dExtDepthOfField::vfunc_02 (0x002A1770, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::d3dExtDepthOfField::vfunc_02 (0x002A1770, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

namespace pure3d {

class d3dExtDepthOfField
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual bool vfunc_02(bool a1);
    char m_pad04[0x4A];
    bool m_Field4E; // +0x4E
};

bool d3dExtDepthOfField::vfunc_02(bool a1)
{
    m_Field4E = a1;
    return a1;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dExtDepthOfField::vfunc_00 (0x002A2970, 33 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as fight::Branch::vfunc_03 (0x0023B160), which was matched first;
// its addresses and names were swapped for this function's.
extern "C" void __cdecl sub_00027600(void* p);

namespace pure3d {

class d3dExtDepthOfField
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual d3dExtDepthOfField* vfunc_00(unsigned int flags);
    void sub_002A1720();
};

#pragma optimize("y", off)
d3dExtDepthOfField* d3dExtDepthOfField::vfunc_00(unsigned int flags)
{
    sub_002A1720();
    if (flags & 1)
        sub_00027600(this);
    return this;
}
#pragma optimize("", on)

}

