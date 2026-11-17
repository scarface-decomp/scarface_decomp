// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/BillboardObject.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 3 functions matched (66.67%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::BillboardObject::vfunc_05 (0x0027A220, 55 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::BillboardObject::vfunc_05 (Proto 0x0022BC00), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::BillboardObject::vfunc_05 (Proto 0x0027A220, 55 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0025AE10(int);
};

extern "C" char DAT_003D7874[];
extern "C" int __cdecl sub_0023F760(int);

namespace pure3d {

class BillboardObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual int vfunc_05();
};

int BillboardObject::vfunc_05()
{
    int t1;

    t1 = sub_0023F760(92);
    if (t1) {
        ((Object*)t1)->sub_0025AE10((int)this);
        *(int*)t1 = (int)DAT_003D7874;
        *(bool*)(t1 + 80) = false;
        *(int*)(t1 + 84) = 0;
        return t1;
    }
    return 0;
}

}

// ============================================================================
// [VERIFIED] pure3d::BillboardObject::vfunc_03 (0x0027AFE0, 39 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as fight::Param::vfunc_03 (0x00239CE0), which was matched first;
// its addresses and names were swapped for this function's.
extern "C" char DAT_003D7874[];
extern "C" void __cdecl sub_0023F7A0(void* p);

namespace pure3d {

class BillboardObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual BillboardObject* vfunc_03(unsigned int flags);
    void sub_0025AFE0();
};

#pragma optimize("y", off)
BillboardObject* BillboardObject::vfunc_03(unsigned int flags)
{
    *(void**)this = DAT_003D7874;
    sub_0025AFE0();
    if (flags & 1)
        sub_0023F7A0(this);
    return this;
}
#pragma optimize("", on)

}

