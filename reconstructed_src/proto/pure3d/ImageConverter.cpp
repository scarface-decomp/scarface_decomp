// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, pure3d/ImageConverter.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 9 functions matched (33.33%). NOT COMPLETE YET.
// The 6 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::ImageConverter::vfunc_03 (0x002547E0, 88 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::ImageConverter::vfunc_03 (Proto 0x002547E0, 88 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual int vfunc_13(int, int);
    virtual void vfunc_14(int);
};

namespace pure3d {

class ImageConverter
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03(int a1, int a2, int a3, int a4);
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06(int, int, int);
};

int ImageConverter::vfunc_03(int a1, int a2, int a3, int a4)
{
    int r_ebp, r_ebx, r_esi;

    r_ebx = *(int*)(a3 + 12);
    r_ebp = ((Object*)r_ebx)->vfunc_13(a4, 0);
    r_esi = 0;
    if (a2 > 0) {
        do {
            vfunc_06(*(int*)(a1 + (r_esi * 4)), r_ebp, r_esi);
            r_esi += 1;
        } while (r_esi < a2);
    }
    ((Object*)r_ebx)->vfunc_14(a4);
    return a3;
}

}

// ============================================================================
// [VERIFIED] pure3d::ImageConverter::vfunc_04 (0x00254EB0, 67 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::ImageConverter::vfunc_04 (Proto 0x00254EB0, 67 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

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
    int sub_0021C950();
};

extern "C" int __cdecl sub_001FCF20(int);

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

    t1 = sub_001FCF20(40);
    if (t1) {
        r_esi = ((Object*)t1)->sub_0021C950();
    } else {
        r_esi = 0;
    }
    ((Object*)r_esi)->vfunc_07(*(int*)a1, *(int*)(a1 + 4));
    vfunc_08(a1, r_esi);
    return r_esi;
}

}

// ============================================================================
// [VERIFIED] pure3d::ImageConverter::vfunc_00 (0x00255130, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::BaseObject::vfunc_00 (0x00026BB0), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::ImageConverter::vfunc_00 (0x00255130, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B23FC[];
extern "C" void __cdecl sub_00025160(int);

namespace pure3d {

class ImageConverter
{
public:
    virtual ImageConverter* vfunc_00(int a1);
};

ImageConverter* ImageConverter::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003B23FC;
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

}

