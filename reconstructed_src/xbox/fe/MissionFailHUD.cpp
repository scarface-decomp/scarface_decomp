// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, fe/MissionFailHUD.cpp (6 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 6 of 11 functions matched (54.55%). NOT COMPLETE YET.
// The 5 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] MissionFailHUD::vfunc_46 (0x001ACE70, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundEntityLoader::vfunc_04 (0x00064FA0), which was matched first;
// its addresses and names were swapped for this function's.
// MissionFailHUD::vfunc_46 (0x001ACE70, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00193C60(void);

class MissionFailHUD
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_46();
};

void MissionFailHUD::vfunc_46()
{
    sub_00193C60();
}

// ============================================================================
// [VERIFIED] MissionFailHUD::vfunc_54 (0x001ACF30, 14 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// MissionFailHUD::vfunc_54 (0x001ACF30, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_00193280(int);

class MissionFailHUD
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
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void vfunc_47();
    virtual void vfunc_48();
    virtual void vfunc_49();
    virtual void vfunc_50();
    virtual void vfunc_51();
    virtual void vfunc_52();
    virtual void vfunc_53();
    virtual void vfunc_54(int a1);
    char m_pad04[0x5C];
    int m_Field60; // +0x60
};

void MissionFailHUD::vfunc_54(int a1)
{
    if (m_Field60 & 1) {
        sub_00193280(a1);
        return;
    }
}

// ============================================================================
// [VERIFIED] MissionFailHUD::vfunc_42 (0x001ACF40, 25 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// MissionFailHUD::vfunc_42 (0x001ACF40, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    bool sub_00224030();
};

extern "C" int DAT_00491EF8;

class MissionFailHUD
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
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual bool vfunc_42();
};

bool MissionFailHUD::vfunc_42()
{
    if (DAT_00491EF8) {
        if (!((Object*)DAT_00491EF8)->sub_00224030()) goto L_16;
        return false;
    }
L_16:
    return true;
}

// ============================================================================
// [VERIFIED] MissionFailHUD::vfunc_00 (0x001AD250, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// MissionFailHUD::vfunc_00 (0x001AD250, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00437B24[];

class MissionFailHUD
{
public:
    virtual void* vfunc_00();
};

void* MissionFailHUD::vfunc_00()
{
    return DAT_00437B24;
}

// ============================================================================
// [VERIFIED] MissionFailHUD::vfunc_44 (0x001AD320, 247 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// MissionFailHUD::vfunc_44 (0x001AD320, 247 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000EA460(int, int);
    int sub_000EB690();
    void sub_00192020(int);
    void sub_00196030(int, int);
};

extern "C" char DAT_003B9E60[];
extern "C" char DAT_003BF28C[];
extern "C" char DAT_003BF2A8[];
extern "C" char DAT_003BF2C8[];
extern "C" int DAT_004879E8;
extern "C" int DAT_0048A21C;
extern "C" int DAT_0048C1DC;
extern "C" int DAT_0048C23C;
extern "C" void __cdecl sub_0006FB50(int, int);
extern "C" void __cdecl sub_000702E0(int, int, int, int, int);
extern "C" int __cdecl sub_00078800(int);
extern "C" void __cdecl sub_000788D0(int, int, int, int, int);
extern "C" int __stdcall sub_000EB680(int, int);
extern "C" int __cdecl sub_000EC630(void);
extern "C" bool __stdcall sub_00193620(int);
extern "C" void __cdecl sub_0022E010(int);

class MissionFailHUD
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
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual bool vfunc_44(int a1);
    void sub_001ACFE0(int);
    char m_pad04[0x90];
    int m_Field94; // +0x94
    int m_Field98; // +0x98
    int m_Field9C; // +0x9C
    unsigned char m_FieldA0; // +0xA0
};

bool MissionFailHUD::vfunc_44(int a1)
{
    int t10;
    unsigned char t11;

    if (sub_00193620(a1)) {
        return true;
    }
    ((Object*)DAT_0048C1DC)->sub_00192020(-1);
    ((Object*)DAT_0048C23C)->sub_00196030(68, 0);
    sub_000702E0((int)DAT_003BF2C8, 0, 0, 0, -1);
    ((Object*)DAT_004879E8)->sub_000EA460(1, (int)DAT_003BF2A8);
    m_Field94 = sub_000EC630();
    m_Field98 = ((Object*)sub_000EB680(18, 0))->sub_000EB690();
    t10 = ((Object*)sub_000EB680(22, 0))->sub_000EB690();
    t11 = m_FieldA0;
    m_Field9C = t10;
    sub_0006FB50((int)DAT_003BF28C, (t11 >> 4) & 1);
    sub_000788D0(sub_00078800((int)DAT_003B9E60), 500, 0, 3, 0);
    if (DAT_0048A21C) {
        m_FieldA0 &= 247;
    }
    sub_0022E010(1);
    sub_001ACFE0(1);
    return false;
}

// ============================================================================
// [VERIFIED] MissionFailHUD::vfunc_01 (0x001AD5A0, 87 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// MissionFailHUD::vfunc_01 (0x001AD5A0, 87 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01(int);
};

extern "C" char DAT_003BF18C[];
extern "C" char DAT_003BF194[];
extern "C" void __cdecl sub_00027600(int);

class MissionFailHUD
{
public:
    virtual void vfunc_00();
    virtual MissionFailHUD* vfunc_01(int a1);
    void sub_00193F80();
    char m_pad04[0x60];
    int m_Field64; // +0x64
    char m_pad68[0x10];
    int m_Field78; // +0x78
    int m_Field7C; // +0x7C
};

MissionFailHUD* MissionFailHUD::vfunc_01(int a1)
{
    int t1, t3;

    t1 = m_Field78;
    *(int*)this = (int)DAT_003BF194;
    m_Field64 = (int)DAT_003BF18C;
    if (m_Field78) {
        ((Object*)t1)->vfunc_01(1);
        m_Field78 = 0;
    }
    t3 = m_Field7C;
    if (m_Field7C) {
        ((Object*)t3)->vfunc_01(1);
        m_Field7C = 0;
    }
    sub_00193F80();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

