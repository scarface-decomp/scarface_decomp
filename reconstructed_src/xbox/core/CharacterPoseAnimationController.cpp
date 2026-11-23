// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, core/CharacterPoseAnimationController.cpp (5 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 5 of 9 functions matched (55.56%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::CharacterPoseAnimationController::vfunc_29 (0x00286270, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::CharacterPoseAnimationController::vfunc_29 (0x00286270, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_002748A0(void);

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
    char m_pad04[0xD0];
    unsigned char m_FieldD4; // +0xD4
};

void CharacterPoseAnimationController::vfunc_29()
{
    m_FieldD4 |= 1;
    sub_002748A0();
}

}

// ============================================================================
// [VERIFIED] pure3d::CharacterPoseAnimationController::vfunc_14 (0x002866E0, 27 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::CharacterPoseAnimationController::vfunc_14 (0x002866E0, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

extern "C" void __stdcall sub_002743B0(int);

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
    void sub_002861C0();
};

void CharacterPoseAnimationController::vfunc_14(int a1)
{
    sub_002743B0(a1);
    sub_002861C0();
}

}

// ============================================================================
// [VERIFIED] pure3d::CharacterPoseAnimationController::vfunc_03 (0x00286DB0, 33 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as fight::Branch::vfunc_03 (0x0023B160), which was matched first;
// its addresses and names were swapped for this function's.
extern "C" void __cdecl sub_0023F7A0(void* p);

namespace pure3d {

class CharacterPoseAnimationController
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual CharacterPoseAnimationController* vfunc_03(unsigned int flags);
    void sub_002865C0();
};

#pragma optimize("y", off)
CharacterPoseAnimationController* CharacterPoseAnimationController::vfunc_03(unsigned int flags)
{
    sub_002865C0();
    if (flags & 1)
        sub_0023F7A0(this);
    return this;
}
#pragma optimize("", on)

}

// ============================================================================
// [VERIFIED] pure3d::CharacterPoseAnimationController::vfunc_05 (0x00286E70, 34 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::CharacterPoseAnimationController::vfunc_05 (Proto 0x002430C0), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::CharacterPoseAnimationController::vfunc_05 (Proto 0x00286E70, 34 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00286DE0(int);
};

extern "C" int __cdecl sub_0023F760(int);

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

    t1 = sub_0023F760(216);
    if (t1) {
        return ((Object*)t1)->sub_00286DE0((int)this);
    }
    return 0;
}

}

// ============================================================================
// [VERIFIED] pure3d::CharacterPoseAnimationController::vfunc_07 (0x00286EA0, 103 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: xb
// va: 0x00286EA0
// what: 
// tool: the portal's starter code (no AI)

// pure3d::CharacterPoseAnimationController::vfunc_07 (0x00286EA0, 103 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

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
    int sub_00278710();
};

extern "C" char DAT_00419538[];
extern "C" char DAT_0041CF34[];
extern "C" char DAT_0045AC34[];
extern "C" int __cdecl sub_002FC034(int, int, int, int, int);

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
    void sub_00286700(int);
};

void CharacterPoseAnimationController::vfunc_07(int a1)
{
    int r_edi, t1;

    r_edi = a1;
    t1 = sub_002FC034(a1, 0, (int)DAT_00419538, (int)DAT_0041CF34, 0);
    if (t1) {
        sub_00286700(((Object*)*(int*)(((Object*)t1)->vfunc_13() + 8))->sub_00278710());
        return;
    }
    sub_00286700(sub_002FC034(r_edi, 0, (int)DAT_00419538, (int)DAT_0045AC34, 0));
}

}

