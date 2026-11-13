// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, fe/TeleportHUD.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 9 functions matched (44.44%). NOT COMPLETE YET.
// The 5 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] TeleportHUD::vfunc_45 (0x001B2C70, 63 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// TeleportHUD::vfunc_45 (0x001B2C70, 63 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __stdcall sub_00193D50(int);

class TeleportHUD
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
    void sub_001AF7E0();
    void sub_001B2B70();
    char m_pad04[0x84];
    int m_Field88; // +0x88
};

bool TeleportHUD::vfunc_45(int a1)
{
    if (sub_00193D50(a1)) {
        return true;
    }
    vfunc_34();
    sub_001AF7E0();
    sub_001B2B70();
    m_Field88 = -1;
    return false;
}

// ============================================================================
// [VERIFIED] TeleportHUD::vfunc_00 (0x001C1BA0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// TeleportHUD::vfunc_00 (0x001C1BA0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00437E90[];

class TeleportHUD
{
public:
    virtual void* vfunc_00();
};

void* TeleportHUD::vfunc_00()
{
    return DAT_00437E90;
}

// ============================================================================
// [VERIFIED] TeleportHUD::vfunc_48 (0x001C1D00, 49 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// TeleportHUD::vfunc_48 (0x001C1D00, 49 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003C2948[];
extern "C" int DAT_0048C898;
extern "C" void __cdecl sub_000702E0(int, int, int, int, int);
extern "C" void __cdecl sub_00193560(void);

class TeleportHUD
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
    virtual int vfunc_48();
    char m_pad04[0x6C];
    int m_Field70; // +0x70
    char m_pad74[0x18];
    int m_Field8C; // +0x8C
};

int TeleportHUD::vfunc_48()
{
    int t3;

    sub_00193560();
    sub_000702E0((int)DAT_003C2948, 0, 0, 0, -1);
    t3 = DAT_0048C898;
    m_Field8C = DAT_0048C898;
    m_Field70 = 1;
    return t3;
}

// ============================================================================
// [VERIFIED] TeleportHUD::vfunc_01 (0x001C1F00, 57 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// TeleportHUD::vfunc_01 (0x001C1F00, 57 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003C2830[];
extern "C" char DAT_003C283C[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_001AF7E0(void);

class TeleportHUD
{
public:
    virtual void vfunc_00();
    virtual TeleportHUD* vfunc_01(int a1);
    void sub_00193F80();
    void sub_001B2B30();
    char m_pad04[0x60];
    int m_Field64; // +0x64
};

TeleportHUD* TeleportHUD::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003C283C;
    m_Field64 = (int)DAT_003C2830;
    sub_001AF7E0();
    sub_001B2B30();
    sub_00193F80();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

