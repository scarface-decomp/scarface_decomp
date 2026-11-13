// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/ShadowSkin.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 5 functions matched (20.00%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::ShadowSkin::vfunc_05 (0x00292700, 55 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::ShadowMesh::vfunc_05 (0x00292630), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::ShadowSkin::vfunc_05 (0x00292700, 55 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0025AE10(int);
};

extern "C" char DAT_003D8C84[];
extern "C" int __cdecl sub_0023F760(int);

namespace pure3d {

class ShadowSkin
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual int vfunc_05();
};

int ShadowSkin::vfunc_05()
{
    int t1;

    t1 = sub_0023F760(88);
    if (t1) {
        ((Object*)t1)->sub_0025AE10((int)this);
        *(bool*)(t1 + 80) = false;
        *(int*)(t1 + 84) = 0;
        *(int*)t1 = (int)DAT_003D8C84;
        return t1;
    }
    return 0;
}

}

