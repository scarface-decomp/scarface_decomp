// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, fe/LookTutorialHUD.cpp (6 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 6 of 7 functions matched (85.71%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] LookTutorialHUD::vfunc_00 (0x00185AB0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// LookTutorialHUD::vfunc_00 (0x00185AB0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0041062C[];

class LookTutorialHUD
{
public:
    virtual void* vfunc_00();
};

void* LookTutorialHUD::vfunc_00()
{
    return DAT_0041062C;
}

// ============================================================================
// [VERIFIED] LookTutorialHUD::vfunc_28 (0x00185AC0, 72 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// LookTutorialHUD::vfunc_28 (Proto 0x00185AC0, 72 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_0016E200(int);

class LookTutorialHUD
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
    virtual void vfunc_28(int a1);
    char m_pad04[0x40];
    int m_Field44; // +0x44
    char m_pad48[0x8];
    bool m_Field50; // +0x50
    bool m_Field51; // +0x51
    bool m_Field52; // +0x52
    bool m_Field53; // +0x53
    bool m_Field54; // +0x54
    bool m_Field55; // +0x55
    bool m_Field56; // +0x56
    bool m_Field57; // +0x57
};

void LookTutorialHUD::vfunc_28(int a1)
{
    int t1;

    t1 = *(int*)(a1 + 4);
    m_Field51 = *(bool*)(*(int*)(a1 + 4) + 9);
    m_Field50 = *(bool*)(t1 + 8);
    m_Field53 = *(bool*)(t1 + 11);
    m_Field52 = *(bool*)(t1 + 10);
    m_Field55 = *(bool*)(t1 + 13);
    m_Field54 = *(bool*)(t1 + 12);
    m_Field57 = *(bool*)(t1 + 15);
    m_Field56 = *(bool*)(t1 + 14);
    m_Field44 = *(int*)(t1 + 16);
    sub_0016E200(a1);
}

// ============================================================================
// [VERIFIED] LookTutorialHUD::vfunc_01 (0x00186620, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// LookTutorialHUD::vfunc_01 (0x00186620, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039C12C[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_0016E130(void);

class LookTutorialHUD
{
public:
    virtual void vfunc_00();
    virtual LookTutorialHUD* vfunc_01(int a1);
};

LookTutorialHUD* LookTutorialHUD::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_0039C12C;
    sub_0016E130();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] LookTutorialHUD::vfunc_29 (0x00186650, 95 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// LookTutorialHUD::vfunc_29 (Proto 0x00186650, 95 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00186520();
};

extern "C" int __cdecl sub_00025140(int, int);

class LookTutorialHUD
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
    void sub_0016E260();
    char m_pad04[0x28];
    int m_Field2C; // +0x2C
    char m_pad30[0x14];
    int m_Field44; // +0x44
    char m_pad48[0x8];
    bool m_Field50; // +0x50
    bool m_Field51; // +0x51
    bool m_Field52; // +0x52
    bool m_Field53; // +0x53
    bool m_Field54; // +0x54
    bool m_Field55; // +0x55
    bool m_Field56; // +0x56
    bool m_Field57; // +0x57
};

void LookTutorialHUD::vfunc_29()
{
    int r_eax;

    r_eax = sub_00025140(20, 7);
    if (r_eax) {
        r_eax = ((Object*)r_eax)->sub_00186520();
    } else {
        r_eax = 0;
    }
    *(bool*)(r_eax + 9) = m_Field51;
    *(bool*)(r_eax + 8) = m_Field50;
    *(bool*)(r_eax + 11) = m_Field53;
    *(bool*)(r_eax + 10) = m_Field52;
    *(bool*)(r_eax + 13) = m_Field55;
    *(bool*)(r_eax + 12) = m_Field54;
    *(bool*)(r_eax + 15) = m_Field57;
    *(bool*)(r_eax + 14) = m_Field56;
    *(int*)(r_eax + 16) = m_Field44;
    m_Field2C = r_eax;
    sub_0016E260();
}

// ============================================================================
// [VERIFIED] LookTutorialHUD::vfunc_39 (0x001866B0, 36 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// LookTutorialHUD::vfunc_39 (Proto 0x001866B0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __stdcall sub_0016E890(int);

class LookTutorialHUD
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
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual bool vfunc_39(int a1);
    void sub_00185B10();
};

bool LookTutorialHUD::vfunc_39(int a1)
{
    if (sub_0016E890(a1)) {
        return true;
    }
    sub_00185B10();
    return false;
}

// ============================================================================
// [VERIFIED] LookTutorialHUD::vfunc_38 (0x00187C80, 36 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// LookTutorialHUD::vfunc_38 (Proto 0x00187C80, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __stdcall sub_0016E830(int);

class LookTutorialHUD
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
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual bool vfunc_38(int a1);
    void sub_001870A0();
};

bool LookTutorialHUD::vfunc_38(int a1)
{
    if (sub_0016E830(a1)) {
        return true;
    }
    sub_001870A0();
    return false;
}

