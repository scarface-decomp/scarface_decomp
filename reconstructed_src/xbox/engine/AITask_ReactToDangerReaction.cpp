// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/AITask_ReactToDangerReaction.cpp (6 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 6 of 9 functions matched (66.67%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AITask_ReactToDangerReaction::vfunc_47 (0x00127430, 56 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AITask_BasicInVehicle::vfunc_40 (0x0010CDB0), which was matched first;
// its addresses and names were swapped for this function's.
// AITask_ReactToDangerReaction::vfunc_47 (0x00127430, 56 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B009C[];
extern "C" int DAT_00489EA0;
extern "C" bool DAT_00489EA4;
extern "C" int __cdecl sub_000700C0(int, int);

class AITask_ReactToDangerReaction
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

int AITask_ReactToDangerReaction::vfunc_47()
{
    int t1;

    if (!(1 & DAT_00489EA4)) {
        *(int*)&DAT_00489EA4 = *(int*)&DAT_00489EA4 | 1;
        t1 = sub_000700C0((int)DAT_003B009C, 0);
        DAT_00489EA0 = t1;
        return t1;
    }
    return DAT_00489EA0;
}

// ============================================================================
// [VERIFIED] AITask_ReactToDangerReaction::vfunc_49 (0x00127480, 50 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AITask_ReactToDangerReaction::vfunc_46 (Proto 0x0010B970), which was matched first;
// its addresses and names were swapped for this function's.
// AITask_ReactToDangerReaction::vfunc_49 (Proto 0x00127480, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0016BD80();
};

extern "C" void __cdecl sub_00109460(int);

class AITask_ReactToDangerReaction
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
    int sub_00104FC0(int, int);
    char m_pad04[0x50];
    int m_Field54; // +0x54
    char m_pad58[0x1C];
    bool m_Field74; // +0x74
};

void AITask_ReactToDangerReaction::vfunc_49()
{
    int r_eax;

    if (this) {
        r_eax = (int)(&m_Field54);
    } else {
        r_eax = 0;
    }
    sub_00109460(r_eax);
    r_eax = sub_00104FC0(3, 4000);
    ((Object*)r_eax)->sub_0016BD80();
    m_Field74 = false;
}

// ============================================================================
// [VERIFIED] AITask_ReactToDangerReaction::vfunc_00 (0x001274C0, 7 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AITask_ReactToDangerReaction::vfunc_00 (Proto 0x0010B9F0), which was matched first;
// its addresses and names were swapped for this function's.
// AITask_ReactToDangerReaction::vfunc_00 (Proto 0x001274C0, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class AITask_ReactToDangerReaction
{
public:
    virtual void vfunc_00(int a1);
    char m_pad04[0x18];
    bool m_Field1C; // +0x1C
};

void AITask_ReactToDangerReaction::vfunc_00(int a1)
{
    m_Field1C = true;
}

// ============================================================================
// [VERIFIED] AITask_ReactToDangerReaction::vfunc_02 (0x00127610, 36 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AITask_ReactToDangerReaction::vfunc_02 (Proto 0x0010BC20), which was matched first;
// its addresses and names were swapped for this function's.
// AITask_ReactToDangerReaction::vfunc_02 (Proto 0x00127610, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class AITask_ReactToDangerReaction
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02(int a1);
    char m_pad04[0x4];
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    int m_Field14; // +0x14
    int m_Field18; // +0x18
};

int AITask_ReactToDangerReaction::vfunc_02(int a1)
{
    *(int*)a1 = m_Field08;
    *(int*)(a1 + 4) = m_Field0C;
    *(int*)(a1 + 8) = m_Field10;
    *(int*)(a1 + 12) = m_Field14;
    *(int*)(a1 + 16) = m_Field18;
    return a1;
}

// ============================================================================
// [VERIFIED] AITask_ReactToDangerReaction::vfunc_00 (0x001276A0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// AITask_ReactToDangerReaction::vfunc_00 (0x001276A0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004295D8[];

class AITask_ReactToDangerReaction
{
public:
    virtual void* vfunc_00();
};

void* AITask_ReactToDangerReaction::vfunc_00()
{
    return DAT_004295D8;
}

// ============================================================================
// [VERIFIED] AITask_ReactToDangerReaction::vfunc_00 (0x0017EC20, 4 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AITask_ReactToDangerReaction::vfunc_00 (Proto 0x0015E1B0), which was matched first;
// its addresses and names were swapped for this function's.
// AITask_ReactToDangerReaction::vfunc_00 (Proto 0x0017EC20, 4 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class AITask_ReactToDangerReaction
{
public:
    virtual bool vfunc_00();
    char m_pad04[0x1C];
    bool m_Field20; // +0x20
};

bool AITask_ReactToDangerReaction::vfunc_00()
{
    return m_Field20;
}

