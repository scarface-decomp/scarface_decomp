// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, core/BillboardQuadGroupAnimationController.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 5 functions matched (60.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::BillboardQuadGroupAnimationController::vfunc_28 (0x002A8130, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::BillboardQuadGroupAnimationController::vfunc_28 (0x002A8130, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

extern "C" char DAT_00475142[];

namespace pure3d {

class BillboardQuadGroupAnimationController
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

bool BillboardQuadGroupAnimationController::vfunc_28(int a1)
{
    if (a1) {
        return *(int*)(a1 + 24) == (int)DAT_00475142;
    }
    return false;
}

}

// ============================================================================
// [VERIFIED] pure3d::BillboardQuadGroupAnimationController::vfunc_05 (0x002A8420, 79 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::VertexAnimController::vfunc_05 (0x002A6DF0), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::BillboardQuadGroupAnimationController::vfunc_05 (0x002A8420, 79 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    void sub_00273B50(int);
};

extern "C" char DAT_003DA4C4[];
extern "C" int __cdecl sub_0023F760(int);

namespace pure3d {

class BillboardQuadGroupAnimationController
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual int vfunc_05();
};

int BillboardQuadGroupAnimationController::vfunc_05()
{
    int r_edi, r_esi, t4;

    r_edi = (int)this;
    r_esi = sub_0023F760(56);
    if (r_esi) {
        ((Object*)r_esi)->sub_00273B50((int)this);
        *(int*)r_esi = (int)DAT_003DA4C4;
        *(int*)(r_esi + 52) = 0;
        r_edi = *(int*)(r_edi + 52);
        if (r_edi) {
            ((Object*)r_edi)->vfunc_00();
        }
        t4 = *(int*)(r_esi + 52);
        if (*(int*)(r_esi + 52)) {
            ((Object*)t4)->vfunc_01();
        }
        *(int*)(r_esi + 52) = r_edi;
        return r_esi;
    }
    return 0;
}

}

// ============================================================================
// [VERIFIED] pure3d::BillboardQuadGroupAnimationController::vfunc_07 (0x002A8470, 66 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::BillboardQuadGroupAnimationController::vfunc_07 (0x002A8470, 66 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" char DAT_00419538[];
extern "C" char DAT_0041DAC4[];
extern "C" int __cdecl sub_002FC034(int, int, int, int, int);

namespace pure3d {

class BillboardQuadGroupAnimationController
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
    char m_pad04[0x30];
    int m_Field34; // +0x34
};

void BillboardQuadGroupAnimationController::vfunc_07(int a1)
{
    int r_esi, t3;

    r_esi = sub_002FC034(a1, 0, (int)DAT_00419538, (int)DAT_0041DAC4, 0);
    if (r_esi) {
        ((Object*)r_esi)->vfunc_00();
    }
    t3 = m_Field34;
    if (m_Field34) {
        ((Object*)t3)->vfunc_01();
    }
    m_Field34 = r_esi;
}

}

