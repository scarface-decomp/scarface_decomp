// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, core/CameraAnimationController.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 6 functions matched (33.33%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::CameraAnimationController::vfunc_28 (0x0028C3C0, 43 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::CameraAnimationController::vfunc_28 (0x0028C3C0, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

extern "C" char DAT_004D4143[];

namespace pure3d {

class CameraAnimationController
{
public:
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
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual bool vfunc_28(int a1);
};

bool CameraAnimationController::vfunc_28(int a1)
{
    if (a1) {
        if (*(int*)(a1 + 36) <= 0) goto L_25;
        return *(int*)(a1 + 24) == (int)DAT_004D4143;
    }
L_25:
    return false;
}

}

// ============================================================================
// [VERIFIED] pure3d::CameraAnimationController::vfunc_05 (0x0028CC20, 81 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::CameraAnimationController::vfunc_05 (0x0028CC20, 81 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00273FC0(int);
    void sub_0028C530(int);
};

extern "C" char DAT_003D8504[];
extern "C" int __cdecl sub_0023F760(int);

namespace pure3d {

class CameraAnimationController
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual int vfunc_05();
    char m_pad04[0xA8];
    int m_FieldAC; // +0xAC
};

int CameraAnimationController::vfunc_05()
{
    int t1;

    t1 = sub_0023F760(176);
    if (t1) {
        ((Object*)t1)->sub_00273FC0((int)this);
        *(int*)t1 = (int)DAT_003D8504;
        *(int*)(t1 + 168) = -1;
        *(int*)(t1 + 172) = 0;
        ((Object*)t1)->sub_0028C530(m_FieldAC);
        return t1;
    }
    return 0;
}

}

