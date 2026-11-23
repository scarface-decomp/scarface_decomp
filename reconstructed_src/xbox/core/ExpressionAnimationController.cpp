// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, core/ExpressionAnimationController.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 5 functions matched (40.00%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
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

// ============================================================================
// [VERIFIED] pure3d::ExpressionAnimationController::vfunc_07 (0x0028CF50, 108 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: xb
// va: 0x0028CF50
// what: 
// tool: the portal's starter code (no AI)

// pure3d::ExpressionAnimationController::vfunc_07 (0x0028CF50, 108 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" char DAT_00419538[];
extern "C" char DAT_0041D390[];
extern "C" char DAT_00431C5C[];
extern "C" int __cdecl sub_002FC034(int, int, int, int, int);

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
    void sub_0028CD40(int);
    char m_pad04[0x34];
    int m_Field38; // +0x38
};

void ExpressionAnimationController::vfunc_07(int a1)
{
    int r_esi, t1, t5;

    r_esi = a1;
    t1 = sub_002FC034(a1, 0, (int)DAT_00419538, (int)DAT_00431C5C, 0);
    if (t1) {
        sub_0028CD40(t1);
        return;
    }
    r_esi = *(int*)(sub_002FC034(r_esi, 0, (int)DAT_00419538, (int)DAT_0041D390, 0) + 104);
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

