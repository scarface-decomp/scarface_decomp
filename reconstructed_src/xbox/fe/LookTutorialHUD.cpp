// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, fe/LookTutorialHUD.cpp (6 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 6 of 7 functions matched (85.71%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] LookTutorialHUD::vfunc_00 (0x001B2FC0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns LookTutorialHUD's static class record (ConcreteClassRep<LookTutorialHUD>), the object's run-time type.
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// LookTutorialHUD::vfunc_00 (0x001B2FC0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00436890[];

class LookTutorialHUD
{
public:
    virtual void* vfunc_00();
};

void* LookTutorialHUD::vfunc_00()
{
    return DAT_00436890;
}

// ============================================================================
// [VERIFIED] LookTutorialHUD::vfunc_30 (0x001B2FD0, 72 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// LookTutorialHUD::vfunc_30 (0x001B2FD0, 72 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_00193370(int);

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
    virtual void vfunc_30(int a1);
    char m_pad04[0x64];
    int m_Field68; // +0x68
    char m_pad6C[0xC];
    bool m_Field78; // +0x78
    bool m_Field79; // +0x79
    bool m_Field7A; // +0x7A
    bool m_Field7B; // +0x7B
    bool m_Field7C; // +0x7C
    bool m_Field7D; // +0x7D
    bool m_Field7E; // +0x7E
    bool m_Field7F; // +0x7F
};

void LookTutorialHUD::vfunc_30(int a1)
{
    int t1;

    t1 = *(int*)(a1 + 4);
    m_Field79 = *(bool*)(*(int*)(a1 + 4) + 9);
    m_Field78 = *(bool*)(t1 + 8);
    m_Field7B = *(bool*)(t1 + 11);
    m_Field7A = *(bool*)(t1 + 10);
    m_Field7D = *(bool*)(t1 + 13);
    m_Field7C = *(bool*)(t1 + 12);
    m_Field7F = *(bool*)(t1 + 15);
    m_Field7E = *(bool*)(t1 + 14);
    m_Field68 = *(int*)(t1 + 16);
    sub_00193370(a1);
}

// ============================================================================
// [VERIFIED] LookTutorialHUD::vfunc_01 (0x001B4880, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: LookTutorialHUD's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// LookTutorialHUD::vfunc_01 (0x001B4880, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003C072C[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_00193F80(void);

class LookTutorialHUD
{
public:
    virtual void vfunc_00();
    virtual LookTutorialHUD* vfunc_01(int a1);
};

LookTutorialHUD* LookTutorialHUD::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003C072C;
    sub_00193F80();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] LookTutorialHUD::vfunc_31 (0x001B48B0, 95 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// LookTutorialHUD::vfunc_31 (0x001B48B0, 95 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_001B4760();
};

extern "C" int __cdecl sub_000275B0(int, int);

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
    void sub_00193910();
    char m_pad04[0x48];
    int m_Field4C; // +0x4C
    char m_pad50[0x18];
    int m_Field68; // +0x68
    char m_pad6C[0xC];
    bool m_Field78; // +0x78
    bool m_Field79; // +0x79
    bool m_Field7A; // +0x7A
    bool m_Field7B; // +0x7B
    bool m_Field7C; // +0x7C
    bool m_Field7D; // +0x7D
    bool m_Field7E; // +0x7E
    bool m_Field7F; // +0x7F
};

void LookTutorialHUD::vfunc_31()
{
    int r_eax;

    r_eax = sub_000275B0(20, 7);
    if (r_eax) {
        r_eax = ((Object*)r_eax)->sub_001B4760();
    } else {
        r_eax = 0;
    }
    *(bool*)(r_eax + 9) = m_Field79;
    *(bool*)(r_eax + 8) = m_Field78;
    *(bool*)(r_eax + 11) = m_Field7B;
    *(bool*)(r_eax + 10) = m_Field7A;
    *(bool*)(r_eax + 13) = m_Field7D;
    *(bool*)(r_eax + 12) = m_Field7C;
    *(bool*)(r_eax + 15) = m_Field7F;
    *(bool*)(r_eax + 14) = m_Field7E;
    *(int*)(r_eax + 16) = m_Field68;
    m_Field4C = r_eax;
    sub_00193910();
}

// ============================================================================
// [VERIFIED] LookTutorialHUD::vfunc_45 (0x001B4910, 36 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as LookTutorialHUD::vfunc_39 (Proto 0x001866B0), which was matched first;
// its addresses and names were swapped for this function's.
// LookTutorialHUD::vfunc_45 (Proto 0x001B4910, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __stdcall sub_00193D50(int);

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
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual bool vfunc_45(int a1);
    void sub_001B3020();
};

bool LookTutorialHUD::vfunc_45(int a1)
{
    if (sub_00193D50(a1)) {
        return true;
    }
    sub_001B3020();
    return false;
}

// ============================================================================
// [VERIFIED] LookTutorialHUD::vfunc_44 (0x001B6630, 55 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// LookTutorialHUD::vfunc_44 (0x001B6630, 55 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003C0F18[];
extern "C" int __cdecl sub_00023EC0(int);
extern "C" bool __stdcall sub_00193620(int);

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
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual bool vfunc_44(int a1);
    void sub_001B5E80();
    char m_pad04[0x88];
    int m_Field8C; // +0x8C
};

bool LookTutorialHUD::vfunc_44(int a1)
{
    if (sub_00193620(a1)) {
        return true;
    }
    m_Field8C = sub_00023EC0((int)DAT_003C0F18);
    sub_001B5E80();
    return false;
}

