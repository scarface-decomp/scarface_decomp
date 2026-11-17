// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, pure3d/BillboardObjectLoader.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 2 functions matched (50.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::BillboardObjectLoader::vfunc_06 (0x0022EC90, 119 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::BillboardObjectLoader::vfunc_06 (Proto 0x0022EC90, 119 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field14
{
    void sub_0022E570(int, int, int);
};

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
    virtual void vfunc_13();
    virtual void vfunc_14();
    int sub_001FDD90();
    void sub_00217060(int);
};

extern "C" char DAT_003B0064[];
extern "C" char sub_00017006[];
extern "C" int __cdecl sub_001FCF20(int);

namespace pure3d {

class BillboardObjectLoader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual int vfunc_06(int a1, int a2, int a3, int a4);
    char m_pad04[0x10];
    Field14* m_Field14; // +0x14
};

int BillboardObjectLoader::vfunc_06(int a1, int a2, int a3, int a4)
{
    int r_eax, r_esi;

    r_eax = ((Object*)a3)->sub_001FDD90();
    if (r_eax == (int)sub_00017006) {
        r_eax = sub_001FCF20(92);
        r_esi = r_eax;
        if (r_esi) {
            ((Object*)r_esi)->sub_00217060(1);
            *(int*)r_esi = (int)DAT_003B0064;
            *(bool*)(r_esi + 80) = false;
            *(int*)(r_esi + 88) = 0x3F800000;
            *(int*)(r_esi + 84) = 0;
        } else {
            r_esi = 0;
        }
        r_eax = a4;
        m_Field14->sub_0022E570(r_esi, a3, a4);
        ((Object*)r_esi)->vfunc_14();
        r_eax = a1;
        *(int*)r_eax = r_esi;
        *(int*)a2 = *(int*)(r_esi + 8);
    }
    return r_eax;
}

}

