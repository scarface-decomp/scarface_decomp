// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, core/LightAnimationController.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 6 functions matched (16.67%). NOT COMPLETE YET.
// The 5 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::LightAnimationController::vfunc_05 (0x0025C0C0, 81 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::CameraAnimationController::vfunc_05 (0x0028CC20), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::LightAnimationController::vfunc_05 (0x0025C0C0, 81 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00225CB0(int);
    void sub_0025B8C0(int);
};

extern "C" char DAT_003B2BE4[];
extern "C" int __cdecl sub_001FCF20(int);

namespace pure3d {

class LightAnimationController
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

int LightAnimationController::vfunc_05()
{
    int t1;

    t1 = sub_001FCF20(176);
    if (t1) {
        ((Object*)t1)->sub_00225CB0((int)this);
        *(int*)t1 = (int)DAT_003B2BE4;
        *(int*)(t1 + 168) = -1;
        *(int*)(t1 + 172) = 0;
        ((Object*)t1)->sub_0025B8C0(m_FieldAC);
        return t1;
    }
    return 0;
}

}

