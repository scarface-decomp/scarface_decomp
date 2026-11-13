// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/EnemyVehicleGenerator.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 6 functions matched (50.00%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] EnemyVehicleGenerator::vfunc_00 (0x001DF360, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// EnemyVehicleGenerator::vfunc_00 (0x001DF360, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0043D96C[];

class EnemyVehicleGenerator
{
public:
    virtual void* vfunc_00();
};

void* EnemyVehicleGenerator::vfunc_00()
{
    return DAT_0043D96C;
}

// ============================================================================
// [VERIFIED] EnemyVehicleGenerator::vfunc_56 (0x001DF370, 53 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// EnemyVehicleGenerator::vfunc_56 (0x001DF370, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field200
{
    void sub_000BA4B0(int);
};

struct Object
{
    int sub_00217470();
};

class EnemyVehicleGenerator
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
    virtual void vfunc_56(int a1);
    char m_pad04[0x1FC];
    Field200 m_Field200; // +0x200
    char m_pad201[0x7B];
    bool m_Field27C; // +0x27C
};

void EnemyVehicleGenerator::vfunc_56(int a1)
{
    int t1;

    if (a1) {
        t1 = ((Object*)a1)->sub_00217470();
        if (!t1) goto L_31;
        if (!m_Field27C) goto L_31;
        m_Field200.sub_000BA4B0(t1);
        m_Field27C = false;
    }
L_31:
    ;
}

// ============================================================================
// [VERIFIED] EnemyVehicleGenerator::vfunc_01 (0x001DF3B0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// EnemyVehicleGenerator::vfunc_01 (0x001DF3B0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003C7A7C[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_001E2B80(void);

class EnemyVehicleGenerator
{
public:
    virtual void vfunc_00();
    virtual EnemyVehicleGenerator* vfunc_01(int a1);
};

EnemyVehicleGenerator* EnemyVehicleGenerator::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003C7A7C;
    sub_001E2B80();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

