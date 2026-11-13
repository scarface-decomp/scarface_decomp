// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, core/CompDrawVisibilityAnimationController.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 6 functions matched (50.00%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::CompDrawVisibilityAnimationController::vfunc_28 (0x002A6F00, 43 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::CompDrawVisibilityAnimationController::vfunc_28 (0x002A6F00, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

namespace pure3d {

class CompDrawVisibilityAnimationController
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

bool CompDrawVisibilityAnimationController::vfunc_28(int a1)
{
    if (a1) {
        if (*(int*)(a1 + 36) <= 0) goto L_25;
        return *(int*)(a1 + 24) == 0x53495650;
    }
L_25:
    return false;
}

}

// ============================================================================
// [VERIFIED] pure3d::CompDrawVisibilityAnimationController::vfunc_26 (0x002A71E0, 37 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::CompDrawVisibilityAnimationController::vfunc_26 (0x002A71E0, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

namespace pure3d {

class CompDrawVisibilityAnimationController
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
    virtual void vfunc_26(int a1, int a2, int a3);
    void sub_00273C10(int, int, int);
    void sub_002A70B0();
};

void CompDrawVisibilityAnimationController::vfunc_26(int a1, int a2, int a3)
{
    sub_00273C10(a1, a2, a3);
    sub_002A70B0();
}

}

// ============================================================================
// [VERIFIED] pure3d::CompDrawVisibilityAnimationController::vfunc_07 (0x002A7280, 47 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::CompDrawVisibilityAnimationController::vfunc_07 (0x002A7280, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

extern "C" char DAT_00419538[];
extern "C" char DAT_0041CF34[];
extern "C" int __cdecl sub_002FC034(int, int, int, int, int);

namespace pure3d {

class CompDrawVisibilityAnimationController
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
    void sub_002A70B0();
    char m_pad04[0x30];
    int m_Field34; // +0x34
};

void CompDrawVisibilityAnimationController::vfunc_07(int a1)
{
    m_Field34 = sub_002FC034(a1, 0, (int)DAT_00419538, (int)DAT_0041CF34, 0);
    sub_002A70B0();
}

}

