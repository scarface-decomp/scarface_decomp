// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, core/ExpressionAnimationController.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 5 functions matched (40.00%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::ExpressionAnimationController::vfunc_05 (0x00248DA0, 72 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::ExpressionAnimationController::vfunc_05 (Proto 0x00248DA0, 72 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00225850(int);
    void sub_00248BE0(int);
};

extern "C" char DAT_003B16FC[];
extern "C" int __cdecl sub_001FCF20(int);

namespace pure3d {

class ExpressionAnimationController
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

int ExpressionAnimationController::vfunc_05()
{
    int t1;

    t1 = sub_001FCF20(68);
    if (t1) {
        ((Object*)t1)->sub_00225850((int)this);
        *(int*)t1 = (int)DAT_003B16FC;
        *(int*)(t1 + 52) = 0;
        *(int*)(t1 + 56) = 0;
        *(int*)(t1 + 60) = 0;
        *(int*)(t1 + 64) = 0;
        ((Object*)t1)->sub_00248BE0(m_Field34);
        return t1;
    }
    return 0;
}

}

// ============================================================================
// [VERIFIED] pure3d::ExpressionAnimationController::vfunc_07 (0x00248DF0, 104 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::ExpressionAnimationController::vfunc_07 (Proto 0x00248DF0, 104 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" char DAT_003F4548[];
extern "C" char DAT_003F8210[];
extern "C" char DAT_0040CF4C[];
extern "C" int __cdecl sub_002C92F8(int, int, int, int, int);

namespace pure3d {

class ExpressionAnimationController
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
    void sub_00248BE0(int);
    char m_pad04[0x34];
    int m_Field38; // +0x38
};

void ExpressionAnimationController::vfunc_07(int a1)
{
    int r_esi, t1, t5;

    r_esi = a1;
    t1 = sub_002C92F8(a1, 0, (int)DAT_003F4548, (int)DAT_0040CF4C, 0);
    if (t1) {
        sub_00248BE0(t1);
        return;
    }
    r_esi = *(int*)(sub_002C92F8(r_esi, 0, (int)DAT_003F4548, (int)DAT_003F8210, 0) + 104);
    if (r_esi) {
        ((Object*)r_esi)->vfunc_00();
    }
    t5 = m_Field38;
    if (m_Field38) {
        ((Object*)t5)->vfunc_01();
    }
    m_Field38 = r_esi;
}

}

