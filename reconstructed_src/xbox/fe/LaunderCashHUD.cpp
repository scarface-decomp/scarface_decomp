// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, fe/LaunderCashHUD.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 8 functions matched (37.50%). NOT COMPLETE YET.
// The 5 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] LaunderCashHUD::vfunc_00 (0x00194D30, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// LaunderCashHUD::vfunc_00 (0x00194D30, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00436818[];

class LaunderCashHUD
{
public:
    virtual void* vfunc_00();
};

void* LaunderCashHUD::vfunc_00()
{
    return DAT_00436818;
}

// ============================================================================
// [VERIFIED] LaunderCashHUD::vfunc_45 (0x001950C0, 83 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// LaunderCashHUD::vfunc_45 (0x001950C0, 83 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00(int);
    void sub_0022D730(int);
};

extern "C" char DAT_003A5800[];
extern "C" int DAT_0049201C;
extern "C" void __cdecl sub_000702E0(int, int, int, int, int);
extern "C" bool __stdcall sub_00193D50(int);

class LaunderCashHUD
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
    char m_pad04[0x6C];
    int m_Field70; // +0x70
};

bool LaunderCashHUD::vfunc_45(int a1)
{
    int t3;

    if (sub_00193D50(a1)) {
        return true;
    }
    ((Object*)DAT_0049201C)->sub_0022D730(0);
    t3 = m_Field70;
    if (m_Field70) {
        ((Object*)t3)->vfunc_00(1);
        m_Field70 = 0;
    }
    sub_000702E0((int)DAT_003A5800, 0, 0, 0, -1);
    return false;
}

// ============================================================================
// [VERIFIED] LaunderCashHUD::vfunc_01 (0x001951B0, 65 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// LaunderCashHUD::vfunc_01 (0x001951B0, 65 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00(int);
};

extern "C" char DAT_003BB1E4[];
extern "C" char DAT_003BB1EC[];
extern "C" void __cdecl sub_00027600(int);

class LaunderCashHUD
{
public:
    virtual void vfunc_00();
    virtual LaunderCashHUD* vfunc_01(int a1);
    void sub_00193F80();
    char m_pad04[0x60];
    int m_Field64; // +0x64
    char m_pad68[0x8];
    int m_Field70; // +0x70
};

LaunderCashHUD* LaunderCashHUD::vfunc_01(int a1)
{
    int t1;

    t1 = m_Field70;
    *(int*)this = (int)DAT_003BB1EC;
    m_Field64 = (int)DAT_003BB1E4;
    if (m_Field70) {
        ((Object*)t1)->vfunc_00(1);
        m_Field70 = 0;
    }
    sub_00193F80();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

