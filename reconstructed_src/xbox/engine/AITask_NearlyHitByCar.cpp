// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/AITask_NearlyHitByCar.cpp (5 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 5 of 7 functions matched (71.43%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AITask_NearlyHitByCar::vfunc_49 (0x00122780, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AITask_NearlyHitByCar::vfunc_49 (0x00122780, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000CA300(int, int);
};

class AITask_NearlyHitByCar
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
};

void AITask_NearlyHitByCar::vfunc_49()
{
    ((Object*)(int)this + 120)->sub_000CA300(3000, 5500);
}

// ============================================================================
// [VERIFIED] AITask_NearlyHitByCar::vfunc_45 (0x001227A0, 57 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AITask_NearlyHitByCar::vfunc_45 (0x001227A0, 57 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field58
{
    int sub_000CA220();
    bool sub_0011E190();
};

struct Field78
{
    bool sub_000CA1C0();
};

class AITask_NearlyHitByCar
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
    virtual int vfunc_45();
    char m_pad04[0x54];
    Field58 m_Field58; // +0x58
    char m_pad59[0x1F];
    Field78 m_Field78; // +0x78
};

int AITask_NearlyHitByCar::vfunc_45()
{
    if (m_Field58.sub_0011E190()) {
        if (m_Field58.sub_000CA220() >= 250) goto L_34;
        if (!m_Field78.sub_000CA1C0()) goto L_34;
        return 1;
    }
L_34:
    return 0;
}

// ============================================================================
// [VERIFIED] AITask_NearlyHitByCar::vfunc_47 (0x001227E0, 56 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AITask_BasicInVehicle::vfunc_40 (0x0010CDB0), which was matched first;
// its addresses and names were swapped for this function's.
// AITask_NearlyHitByCar::vfunc_47 (0x001227E0, 56 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003AEFFC[];
extern "C" int DAT_00489D28;
extern "C" bool DAT_00489D2C;
extern "C" int __cdecl sub_000700C0(int, int);

class AITask_NearlyHitByCar
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
    virtual int vfunc_47();
};

int AITask_NearlyHitByCar::vfunc_47()
{
    int t1;

    if (!(1 & DAT_00489D2C)) {
        *(int*)&DAT_00489D2C = *(int*)&DAT_00489D2C | 1;
        t1 = sub_000700C0((int)DAT_003AEFFC, 0);
        DAT_00489D28 = t1;
        return t1;
    }
    return DAT_00489D28;
}

// ============================================================================
// [VERIFIED] AITask_NearlyHitByCar::vfunc_00 (0x00123420, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// AITask_NearlyHitByCar::vfunc_00 (0x00123420, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00428FA8[];

class AITask_NearlyHitByCar
{
public:
    virtual void* vfunc_00();
};

void* AITask_NearlyHitByCar::vfunc_00()
{
    return DAT_00428FA8;
}

// ============================================================================
// [VERIFIED] AITask_NearlyHitByCar::vfunc_01 (0x00123430, 40 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AITask_NearlyHitByCar::vfunc_01 (0x00123430, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field68
{
    void sub_0011DD70();
};

extern "C" void __cdecl sub_00027600(int);

class AITask_NearlyHitByCar
{
public:
    virtual void vfunc_00();
    virtual AITask_NearlyHitByCar* vfunc_01(int a1);
    void sub_00126EC0();
    char m_pad04[0x64];
    Field68 m_Field68; // +0x68
};

AITask_NearlyHitByCar* AITask_NearlyHitByCar::vfunc_01(int a1)
{
    m_Field68.sub_0011DD70();
    sub_00126EC0();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

