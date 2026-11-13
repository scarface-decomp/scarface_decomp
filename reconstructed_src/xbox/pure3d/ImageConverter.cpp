// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/ImageConverter.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 9 functions matched (22.22%). NOT COMPLETE YET.
// The 7 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::ImageConverter::vfunc_04 (0x00298CB0, 70 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::ImageConverter::vfunc_04 (0x00298CB0, 70 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07(int, int);
    int sub_00263290();
};

extern "C" int __cdecl sub_0023F760(int);

namespace pure3d {

class ImageConverter
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual int vfunc_04(int a1);
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08(int, int);
};

int ImageConverter::vfunc_04(int a1)
{
    int r_esi, t1;

    t1 = sub_0023F760(40);
    if (t1) {
        r_esi = ((Object*)t1)->sub_00263290();
    } else {
        r_esi = 0;
    }
    ((Object*)r_esi)->vfunc_07(*(int*)a1, *(int*)(a1 + 4));
    vfunc_08(a1, r_esi);
    return r_esi;
}

}

// ============================================================================
// [VERIFIED] pure3d::ImageConverter::vfunc_00 (0x00298F10, 34 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as fight::ParamValue::vfunc_00 (0x0023F0C0), which was matched first;
// its addresses and names were swapped for this function's.
extern "C" char DAT_003D9230[];
extern "C" void __cdecl sub_00027600(void* p);

namespace pure3d {

class ImageConverter
{
public:
    virtual ImageConverter* vfunc_00(unsigned int flags);
};

// Deleting destructor: nothing to destroy but the vtable; frees the object when asked.
#pragma optimize("y", off)
ImageConverter* ImageConverter::vfunc_00(unsigned int flags)
{
    *(void**)this = DAT_003D9230;
    if (flags & 1)
        sub_00027600(this);
    return this;
}
#pragma optimize("", on)

}

