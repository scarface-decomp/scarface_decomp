// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, core/CompDrawVisibilityAnimationController.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 6 functions matched (66.67%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::CompDrawVisibilityAnimationController::vfunc_28 (0x0025B310, 39 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::CompDrawVisibilityAnimationController::vfunc_28 (Proto 0x0025B310, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

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
        if (*(int*)(a1 + 36) <= 0) goto L_22;
        return *(int*)(a1 + 24) == 0x53495650;
    }
L_22:
    return false;
}

}

// ============================================================================
// [VERIFIED] pure3d::CompDrawVisibilityAnimationController::vfunc_26 (0x0025B5F0, 36 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::CompDrawVisibilityAnimationController::vfunc_26 (Proto 0x0025B5F0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

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
    void sub_00225910(int, int, int);
    void sub_0025B4C0();
};

void CompDrawVisibilityAnimationController::vfunc_26(int a1, int a2, int a3)
{
    sub_00225910(a1, a2, a3);
    sub_0025B4C0();
}

}

// ============================================================================
// [VERIFIED] pure3d::CompDrawVisibilityAnimationController::vfunc_05 (0x0025B630, 77 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::CompDrawVisibilityAnimationController::vfunc_05 (Proto 0x0025B630, 77 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00225850(int);
    void sub_0025B4C0();
};

extern "C" char DAT_003B2B4C[];
extern "C" int __cdecl sub_001FCF20(int);

namespace pure3d {

class CompDrawVisibilityAnimationController
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual int vfunc_05();
    char m_pad04[0x30];
    int m_Field34; // +0x34
};

int CompDrawVisibilityAnimationController::vfunc_05()
{
    int t1;

    t1 = sub_001FCF20(80);
    if (t1) {
        ((Object*)t1)->sub_00225850((int)this);
        *(int*)(t1 + 52) = 0;
        *(int*)t1 = (int)DAT_003B2B4C;
        *(int*)(t1 + 56) = 0;
        *(int*)(t1 + 60) = 0;
        *(int*)(t1 + 68) = 0;
        *(int*)(t1 + 72) = 0;
        *(int*)(t1 + 52) = m_Field34;
        ((Object*)t1)->sub_0025B4C0();
        return t1;
    }
    return 0;
}

}

// ============================================================================
// [VERIFIED] pure3d::CompDrawVisibilityAnimationController::vfunc_07 (0x0025B680, 44 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::CompDrawVisibilityAnimationController::vfunc_07 (Proto 0x0025B680, 44 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003F4548[];
extern "C" char DAT_003F7B18[];
extern "C" int __cdecl sub_002C92F8(int, int, int, int, int);

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
    void sub_0025B4C0();
    char m_pad04[0x30];
    int m_Field34; // +0x34
};

void CompDrawVisibilityAnimationController::vfunc_07(int a1)
{
    m_Field34 = sub_002C92F8(a1, 0, (int)DAT_003F4548, (int)DAT_003F7B18, 0);
    sub_0025B4C0();
}

}

