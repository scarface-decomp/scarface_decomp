// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/AITask_IdleChatResponse.cpp (5 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 5 of 16 functions matched (31.25%). NOT COMPLETE YET.
// The 11 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AITask_IdleChatResponse::vfunc_00 (0x00101A30, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// AITask_IdleChatResponse::vfunc_00 (0x00101A30, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00403E78[];

class AITask_IdleChatResponse
{
public:
    virtual void* vfunc_00();
};

void* AITask_IdleChatResponse::vfunc_00()
{
    return DAT_00403E78;
}

// ============================================================================
// [VERIFIED] AITask_IdleChatResponse::vfunc_01 (0x00101A40, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Collidable::vfunc_03 (0x00011F20), which was matched first;
// its addresses and names were swapped for this function's.
// AITask_IdleChatResponse::vfunc_01 (0x00101A40, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0010B530(void);
extern "C" void __cdecl sub_00025160(int);

class AITask_IdleChatResponse
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual AITask_IdleChatResponse* vfunc_01(int a1);
};

AITask_IdleChatResponse* AITask_IdleChatResponse::vfunc_01(int a1)
{
    sub_0010B530();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] AITask_IdleChatResponse::vfunc_21 (0x0010A920, 26 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AITask_IdleChatResponse::vfunc_23 (0x00126350), which was matched first;
// its addresses and names were swapped for this function's.
// AITask_IdleChatResponse::vfunc_21 (0x0010A920, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00029EE0(int, int, int, int);

class AITask_IdleChatResponse
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
    virtual void vfunc_21(int a1);
    char m_pad04[0xC0];
    int m_FieldC4; // +0xC4
};

void AITask_IdleChatResponse::vfunc_21(int a1)
{
    sub_00029EE0((int)this, a1, (int)(&m_FieldC4), 2);
}

// ============================================================================
// [VERIFIED] AITask_IdleChatResponse::vfunc_22 (0x0010A940, 26 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AITask_IdleChatResponse::vfunc_23 (0x00126350), which was matched first;
// its addresses and names were swapped for this function's.
// AITask_IdleChatResponse::vfunc_22 (0x0010A940, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00029F20(int, int, int, int);

class AITask_IdleChatResponse
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
    virtual void vfunc_22(int a1);
    char m_pad04[0xC0];
    int m_FieldC4; // +0xC4
};

void AITask_IdleChatResponse::vfunc_22(int a1)
{
    sub_00029F20((int)this, a1, (int)(&m_FieldC4), 2);
}

// ============================================================================
// [VERIFIED] AITask_IdleChatResponse::vfunc_44 (0x0010AAA0, 56 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AITask_BasicInVehicle::vfunc_40 (0x0010CDB0), which was matched first;
// its addresses and names were swapped for this function's.
// AITask_IdleChatResponse::vfunc_44 (0x0010AAA0, 56 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00389FC0[];
extern "C" int DAT_0045C058;
extern "C" bool DAT_0045C05C;
extern "C" int __cdecl sub_00065CF0(int, int);

class AITask_IdleChatResponse
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

int AITask_IdleChatResponse::vfunc_44()
{
    int t1;

    if (!(1 & DAT_0045C05C)) {
        *(int*)&DAT_0045C05C = *(int*)&DAT_0045C05C | 1;
        t1 = sub_00065CF0((int)DAT_00389FC0, 0);
        DAT_0045C058 = t1;
        return t1;
    }
    return DAT_0045C058;
}

