// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, fe/PauseMenuPageRewards.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 12 functions matched (33.33%). NOT COMPLETE YET.
// The 8 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] PauseMenuPageRewards::vfunc_00 (0x001CC770, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// PauseMenuPageRewards::vfunc_00 (0x001CC770, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00439DD0[];

class PauseMenuPageRewards
{
public:
    virtual void* vfunc_00();
};

void* PauseMenuPageRewards::vfunc_00()
{
    return DAT_00439DD0;
}

// ============================================================================
// [VERIFIED] PauseMenuPageRewards::vfunc_45 (0x001CC780, 49 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// PauseMenuPageRewards::vfunc_45 (0x001CC780, 49 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00(int);
};

extern "C" bool __stdcall sub_001CA7F0(int);

class PauseMenuPageRewards
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
    char m_pad04[0x78];
    int m_Field7C; // +0x7C
};

bool PauseMenuPageRewards::vfunc_45(int a1)
{
    int t2;

    if (sub_001CA7F0(a1)) {
        return true;
    }
    t2 = m_Field7C;
    if (m_Field7C) {
        ((Object*)t2)->vfunc_00(1);
        m_Field7C = 0;
    }
    return false;
}

// ============================================================================
// [VERIFIED] PauseMenuPageRewards::vfunc_65 (0x001CCBC0, 40 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// PauseMenuPageRewards::vfunc_65 (0x001CCBC0, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003BE4B8[];
extern "C" int __cdecl sub_000802E0(int);
extern "C" int __cdecl sub_001CA940(void);
extern "C" void __stdcall sub_001CC9F0(int);

class PauseMenuPageRewards
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
    virtual void vfunc_54();
    virtual void vfunc_55();
    virtual void vfunc_56();
    virtual void vfunc_57();
    virtual void vfunc_58();
    virtual void vfunc_59();
    virtual void vfunc_60();
    virtual void vfunc_61();
    virtual void vfunc_62();
    virtual void vfunc_63();
    virtual void vfunc_64();
    virtual void vfunc_65();
    char m_pad04[0x7C];
    int m_Field80; // +0x80
};

void PauseMenuPageRewards::vfunc_65()
{
    int r_eax;

    r_eax = m_Field80;
    if (r_eax == 1) {
        sub_001CA940();
    }
    if (r_eax == 2) {
        sub_001CC9F0(1);
        r_eax = sub_000802E0((int)DAT_003BE4B8);
    }
}

// ============================================================================
// [VERIFIED] PauseMenuPageRewards::vfunc_01 (0x001CD060, 65 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// PauseMenuPageRewards::vfunc_01 (0x001CD060, 65 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00(int);
};

extern "C" char DAT_003C4D84[];
extern "C" char DAT_003C4D9C[];
extern "C" void __cdecl sub_00027600(int);

class PauseMenuPageRewards
{
public:
    virtual void vfunc_00();
    virtual PauseMenuPageRewards* vfunc_01(int a1);
    void sub_001CAA10();
    char m_pad04[0x60];
    int m_Field64; // +0x64
    char m_pad68[0x14];
    int m_Field7C; // +0x7C
};

PauseMenuPageRewards* PauseMenuPageRewards::vfunc_01(int a1)
{
    int t1;

    t1 = m_Field7C;
    *(int*)this = (int)DAT_003C4D9C;
    m_Field64 = (int)DAT_003C4D84;
    if (m_Field7C) {
        ((Object*)t1)->vfunc_00(1);
        m_Field7C = 0;
    }
    sub_001CAA10();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

