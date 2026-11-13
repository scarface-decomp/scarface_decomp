// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/VertexAnimPrimGroup.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 4 functions matched (50.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::VertexAnimPrimGroup::vfunc_05 (0x002937D0, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::CompositeDrawable::vfunc_05 (0x002776D0), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::VertexAnimPrimGroup::vfunc_05 (0x002937D0, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00293620(int);
};

extern "C" int __cdecl sub_0023F760(int);

namespace pure3d {

class VertexAnimPrimGroup
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual int vfunc_05();
};

int VertexAnimPrimGroup::vfunc_05()
{
    int t1;

    t1 = sub_0023F760(84);
    if (t1) {
        return ((Object*)t1)->sub_00293620((int)this);
    }
    return 0;
}

}

// ============================================================================
// [VERIFIED] pure3d::VertexAnimPrimGroup::vfunc_03 (0x00294260, 33 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as fight::Branch::vfunc_03 (0x0023B160), which was matched first;
// its addresses and names were swapped for this function's.
extern "C" void __cdecl sub_0023F7A0(void* p);

namespace pure3d {

class VertexAnimPrimGroup
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual VertexAnimPrimGroup* vfunc_03(unsigned int flags);
    void sub_00293770();
};

#pragma optimize("y", off)
VertexAnimPrimGroup* VertexAnimPrimGroup::vfunc_03(unsigned int flags)
{
    sub_00293770();
    if (flags & 1)
        sub_0023F7A0(this);
    return this;
}
#pragma optimize("", on)

}

