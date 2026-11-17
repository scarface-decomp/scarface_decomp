// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, core/CharacterPoseAnimationController.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 8 functions matched (50.00%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::CharacterPoseAnimationController::vfunc_14 (0x00242950, 24 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::CharacterPoseAnimationController::vfunc_14 (Proto 0x00242950, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_00226090(int);

namespace pure3d {

class CharacterPoseAnimationController
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
    virtual void vfunc_14(int a1);
    void sub_00242400();
};

void CharacterPoseAnimationController::vfunc_14(int a1)
{
    sub_00226090(a1);
    sub_00242400();
}

}

// ============================================================================
// [VERIFIED] pure3d::CharacterPoseAnimationController::vfunc_03 (0x00243010, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionManager::CollisionManagerFlowClient::vfunc_00 (0x00016060), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::CharacterPoseAnimationController::vfunc_03 (0x00243010, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00242840(void);
extern "C" void __cdecl sub_001FCF60(int);

namespace pure3d {

class CharacterPoseAnimationController
{
public:
    virtual CharacterPoseAnimationController* vfunc_03(int a1);
};

CharacterPoseAnimationController* CharacterPoseAnimationController::vfunc_03(int a1)
{
    sub_00242840();
    if (a1 & 1) {
        sub_001FCF60((int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] pure3d::CharacterPoseAnimationController::vfunc_05 (0x002430C0, 34 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::CharacterPoseAnimationController::vfunc_05 (Proto 0x002430C0, 34 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00243030(int);
};

extern "C" int __cdecl sub_001FCF20(int);

namespace pure3d {

class CharacterPoseAnimationController
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual int vfunc_05();
};

int CharacterPoseAnimationController::vfunc_05()
{
    int t1;

    t1 = sub_001FCF20(216);
    if (t1) {
        return ((Object*)t1)->sub_00243030((int)this);
    }
    return 0;
}

}

// ============================================================================
// [VERIFIED] pure3d::CharacterPoseAnimationController::vfunc_07 (0x002430F0, 99 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::CharacterPoseAnimationController::vfunc_07 (Proto 0x002430F0, 99 bytes)
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
    int sub_0022A1B0();
};

extern "C" char DAT_003F4548[];
extern "C" char DAT_003F7B18[];
extern "C" char DAT_0042B65C[];
extern "C" int __cdecl sub_002C92F8(int, int, int, int, int);

namespace pure3d {

class CharacterPoseAnimationController
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
    void sub_00242970(int);
};

void CharacterPoseAnimationController::vfunc_07(int a1)
{
    int t1;

    t1 = sub_002C92F8(a1, 0, (int)DAT_003F4548, (int)DAT_003F7B18, 0);
    if (t1) {
        sub_00242970(((Object*)*(int*)(((Object*)t1)->vfunc_13() + 8))->sub_0022A1B0());
        return;
    }
    sub_00242970(sub_002C92F8(a1, 0, (int)DAT_003F4548, (int)DAT_0042B65C, 0));
}

}

