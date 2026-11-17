// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, core/ExpressionAnimationController.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 5 functions matched (20.00%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::ExpressionAnimationController::vfunc_05 (0x0028CF00, 72 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::ExpressionAnimationController::vfunc_05 (Proto 0x00248DA0), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::ExpressionAnimationController::vfunc_05 (Proto 0x0028CF00, 72 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00273B50(int);
    void sub_0028CD40(int);
};

extern "C" char DAT_003D85AC[];
extern "C" int __cdecl sub_0023F760(int);

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

    t1 = sub_0023F760(68);
    if (t1) {
        ((Object*)t1)->sub_00273B50((int)this);
        *(int*)t1 = (int)DAT_003D85AC;
        *(int*)(t1 + 52) = 0;
        *(int*)(t1 + 56) = 0;
        *(int*)(t1 + 60) = 0;
        *(int*)(t1 + 64) = 0;
        ((Object*)t1)->sub_0028CD40(m_Field34);
        return t1;
    }
    return 0;
}

}

