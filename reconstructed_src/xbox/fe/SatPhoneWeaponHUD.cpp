// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, fe/SatPhoneWeaponHUD.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 7 functions matched (42.86%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] SatPhoneWeaponHUD::vfunc_44 (0x001B9590, 119 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// SatPhoneWeaponHUD::vfunc_44 (0x001B9590, 119 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field78
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
    virtual void vfunc_39(int, int, int);
};

struct FieldAC
{
    void sub_00023290(int);
};

struct Object
{
    void sub_000EC0F0();
};

extern "C" char DAT_003C170C[];
extern "C" char DAT_003C1718[];
extern "C" void __cdecl sub_00080300(int);
extern "C" int __stdcall sub_000EB680(int, int, int);
extern "C" bool __stdcall sub_001B7D80(int);

class SatPhoneWeaponHUD
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
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void vfunc_47();
    virtual void vfunc_48();
    virtual void vfunc_49();
    virtual void vfunc_50();
    virtual void vfunc_51();
    virtual void vfunc_52();
    virtual void vfunc_53();
    virtual void vfunc_54();
    virtual void vfunc_55();
    virtual void vfunc_56();
    virtual void vfunc_57();
    virtual void vfunc_58();
    virtual void vfunc_59();
    virtual void vfunc_60();
    virtual void vfunc_61();
    virtual void vfunc_62();
    char m_pad04[0x74];
    Field78* m_Field78; // +0x78
    char m_pad7C[0x30];
    FieldAC* m_FieldAC; // +0xAC
    FieldAC* m_FieldB0; // +0xB0
};

bool SatPhoneWeaponHUD::vfunc_44(int a1)
{
    if (sub_001B7D80(a1)) {
        return true;
    }
    m_Field78->vfunc_39((int)DAT_003C1718, 0, 0);
    m_FieldAC->sub_00023290(2);
    m_FieldB0->sub_00023290(1);
    sub_00080300((int)DAT_003C170C);
    vfunc_62();
    ((Object*)sub_000EB680(154, 0, 0))->sub_000EC0F0();
    return false;
}

// ============================================================================
// [VERIFIED] SatPhoneWeaponHUD::vfunc_00 (0x001BC640, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns SatPhoneWeaponHUD's static class record (ConcreteClassRep<SatPhoneWeaponHUD>), the object's run-time type.
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// SatPhoneWeaponHUD::vfunc_00 (0x001BC640, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00436194[];

class SatPhoneWeaponHUD
{
public:
    virtual void* vfunc_00();
};

void* SatPhoneWeaponHUD::vfunc_00()
{
    return DAT_00436194;
}

// ============================================================================
// [VERIFIED] SatPhoneWeaponHUD::vfunc_01 (0x001BC750, 53 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: SatPhoneWeaponHUD's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// Same machine code as LockerWeaponHUD::vfunc_01 (0x001A5AB0), which was matched first;
// its addresses and names were swapped for this function's.
// SatPhoneWeaponHUD::vfunc_01 (0x001BC750, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003C1B58[];
extern "C" char DAT_003C1B60[];
extern "C" char DAT_003C1B7C[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_00190220(void);

class SatPhoneWeaponHUD
{
public:
    virtual void vfunc_00();
    virtual SatPhoneWeaponHUD* vfunc_01(int a1);
    char m_pad04[0x60];
    int m_Field64; // +0x64
    char m_pad68[0xA8];
    int m_Field110; // +0x110
};

SatPhoneWeaponHUD* SatPhoneWeaponHUD::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003C1B7C;
    m_Field64 = (int)DAT_003C1B60;
    m_Field110 = (int)DAT_003C1B58;
    sub_00190220();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

