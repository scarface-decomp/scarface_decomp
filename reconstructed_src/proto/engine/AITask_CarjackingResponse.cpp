// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/AITask_CarjackingResponse.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 7 functions matched (57.14%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AITask_CarjackingResponse::vfunc_44 (0x0010DC80, 56 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AITask_BasicInVehicle::vfunc_40 (0x0010CDB0), which was matched first;
// its addresses and names were swapped for this function's.
// AITask_CarjackingResponse::vfunc_44 (0x0010DC80, 56 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0038EB24[];
extern "C" int DAT_0045C170;
extern "C" bool DAT_0045C174;
extern "C" int __cdecl sub_00065CF0(int, int);

class AITask_CarjackingResponse
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
    virtual int vfunc_44();
};

int AITask_CarjackingResponse::vfunc_44()
{
    int t1;

    if (!(1 & DAT_0045C174)) {
        *(int*)&DAT_0045C174 = *(int*)&DAT_0045C174 | 1;
        t1 = sub_00065CF0((int)DAT_0038EB24, 0);
        DAT_0045C170 = t1;
        return t1;
    }
    return DAT_0045C170;
}

// ============================================================================
// [VERIFIED] AITask_CarjackingResponse::vfunc_47 (0x0010DD00, 24 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AITask_CarjackingResponse::vfunc_47 (Proto 0x0010DD00, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000DF020(int, int);
};

extern "C" int __cdecl sub_00028120(int);

class AITask_CarjackingResponse
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
    char m_pad04[0x20];
    int m_Field24; // +0x24
};

void AITask_CarjackingResponse::vfunc_47()
{
    ((Object*)sub_00028120(m_Field24))->sub_000DF020(1, 0);
}

// ============================================================================
// [VERIFIED] AITask_CarjackingResponse::vfunc_00 (0x0010DF10, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// AITask_CarjackingResponse::vfunc_00 (0x0010DF10, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00404190[];

class AITask_CarjackingResponse
{
public:
    virtual void* vfunc_00();
};

void* AITask_CarjackingResponse::vfunc_00()
{
    return DAT_00404190;
}

// ============================================================================
// [VERIFIED] AITask_CarjackingResponse::vfunc_01 (0x0010DF20, 48 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AITask_CarjackingResponse::vfunc_01 (Proto 0x0010DF20, 48 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field58
{
    void sub_000DBE80();
};

struct Field68
{
    void sub_00102BA0();
};

extern "C" void __cdecl sub_00025160(int);

class AITask_CarjackingResponse
{
public:
    virtual void vfunc_00();
    virtual AITask_CarjackingResponse* vfunc_01(int a1);
    void sub_000DC430();
    char m_pad04[0x54];
    Field58 m_Field58; // +0x58
    char m_pad59[0xF];
    Field68 m_Field68; // +0x68
};

AITask_CarjackingResponse* AITask_CarjackingResponse::vfunc_01(int a1)
{
    m_Field68.sub_00102BA0();
    m_Field58.sub_000DBE80();
    sub_000DC430();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

