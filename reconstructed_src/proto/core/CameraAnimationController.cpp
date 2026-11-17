// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, core/CameraAnimationController.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 6 functions matched (50.00%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::CameraAnimationController::vfunc_28 (0x00248150, 39 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::CameraAnimationController::vfunc_28 (Proto 0x00248150, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

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
        if (*(int*)(a1 + 36) <= 0) goto L_22;
        return *(int*)(a1 + 24) == 0x4D4143;
    }
L_22:
    return false;
}

}

// ============================================================================
// [VERIFIED] pure3d::CameraAnimationController::vfunc_05 (0x00248AC0, 81 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::CameraAnimationController::vfunc_05 (0x0028CC20), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::CameraAnimationController::vfunc_05 (0x00248AC0, 81 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00225CB0(int);
    void sub_002482F0(int);
};

extern "C" char DAT_003B165C[];
extern "C" int __cdecl sub_001FCF20(int);

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

    t1 = sub_001FCF20(176);
    if (t1) {
        ((Object*)t1)->sub_00225CB0((int)this);
        *(int*)t1 = (int)DAT_003B165C;
        *(int*)(t1 + 168) = -1;
        *(int*)(t1 + 172) = 0;
        ((Object*)t1)->sub_002482F0(m_FieldAC);
        return t1;
    }
    return 0;
}

}

// ============================================================================
// [VERIFIED] pure3d::CameraAnimationController::vfunc_07 (0x00248B20, 42 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::CameraAnimationController::vfunc_07 (Proto 0x00248B20, 42 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003F4548[];
extern "C" char DAT_003F55B0[];
extern "C" int __cdecl sub_002C92F8(int, int, int, int, int);

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
    virtual void vfunc_07(int a1);
    void sub_002482F0(int);
};

void CameraAnimationController::vfunc_07(int a1)
{
    sub_002482F0(sub_002C92F8(a1, 0, (int)DAT_003F4548, (int)DAT_003F55B0, 0));
}

}

