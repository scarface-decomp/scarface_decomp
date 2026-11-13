// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, core/BillboardQuadGroupAnimationController.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 5 functions matched (20.00%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::BillboardQuadGroupAnimationController::vfunc_05 (0x0025C900, 79 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::VertexAnimController::vfunc_05 (0x002A6DF0), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::BillboardQuadGroupAnimationController::vfunc_05 (0x0025C900, 79 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    void sub_00225850(int);
};

extern "C" char DAT_003B2DB4[];
extern "C" int __cdecl sub_001FCF20(int);

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
    r_esi = sub_001FCF20(56);
    if (r_esi) {
        ((Object*)r_esi)->sub_00225850((int)this);
        *(int*)r_esi = (int)DAT_003B2DB4;
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

