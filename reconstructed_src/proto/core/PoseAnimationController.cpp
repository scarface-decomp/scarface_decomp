// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, core/PoseAnimationController.cpp (5 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 5 of 8 functions matched (62.50%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::PoseAnimationController::vfunc_09 (0x0012D8D0, 5 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::PoseAnimationController::vfunc_09 (Proto 0x0012D8D0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d {

class PoseAnimationController
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
    virtual void vfunc_28();
    virtual void vfunc_29();
};

void PoseAnimationController::vfunc_09()
{
    vfunc_29();
}

}

// ============================================================================
// [VERIFIED] pure3d::PoseAnimationController::vfunc_14 (0x00242670, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as renderer::InstanceRenderable::vfunc_10 (0x00054F90), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::PoseAnimationController::vfunc_14 (0x00242670, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00225980(void);

namespace pure3d {

class PoseAnimationController
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
    virtual void vfunc_14();
};

void PoseAnimationController::vfunc_14()
{
    sub_00225980();
}

}

// ============================================================================
// [VERIFIED] pure3d::PoseAnimationController::vfunc_26 (0x00242F30, 43 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::PoseAnimationController::vfunc_26 (Proto 0x00242F30, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d {

class PoseAnimationController
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
    virtual int vfunc_26(int a1, int a2, int a3);
    void sub_00225910(int, int, int);
    int sub_002427A0();
    char m_pad04[0x30];
    int m_Field34; // +0x34
};

int PoseAnimationController::vfunc_26(int a1, int a2, int a3)
{
    int r_eax;

    r_eax = a3;
    sub_00225910(a1, a2, a3);
    r_eax = m_Field34;
    if (r_eax) {
        r_eax = sub_002427A0();
    }
    return r_eax;
}

}

// ============================================================================
// [VERIFIED] pure3d::PoseAnimationController::vfunc_05 (0x002431B0, 69 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::PoseAnimationController::vfunc_05 (Proto 0x002431B0, 69 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00225850(int);
    void sub_00242F60(int);
};

extern "C" char DAT_003B12E4[];
extern "C" int __cdecl sub_001FCF20(int);

namespace pure3d {

class PoseAnimationController
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

int PoseAnimationController::vfunc_05()
{
    int t1;

    t1 = sub_001FCF20(60);
    if (t1) {
        ((Object*)t1)->sub_00225850((int)this);
        *(int*)t1 = (int)DAT_003B12E4;
        *(int*)(t1 + 52) = 0;
        *(int*)(t1 + 56) = 0;
        ((Object*)t1)->sub_00242F60(m_Field34);
        return t1;
    }
    return 0;
}

}

// ============================================================================
// [VERIFIED] pure3d::PoseAnimationController::vfunc_07 (0x00243200, 91 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::PoseAnimationController::vfunc_07 (Proto 0x00243200, 91 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
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
    virtual int vfunc_13();
};

extern "C" char DAT_003F4548[];
extern "C" char DAT_003F7B18[];
extern "C" char DAT_0042B640[];
extern "C" int __cdecl sub_002C92F8(int, int, int, int, int);

namespace pure3d {

class PoseAnimationController
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
    void sub_00242F60(int);
};

void PoseAnimationController::vfunc_07(int a1)
{
    int t1;

    t1 = sub_002C92F8(a1, 0, (int)DAT_003F4548, (int)DAT_003F7B18, 0);
    if (t1) {
        sub_00242F60(((Object*)t1)->vfunc_13());
        return;
    }
    sub_00242F60(sub_002C92F8(a1, 0, (int)DAT_003F4548, (int)DAT_0042B640, 0));
}

}

