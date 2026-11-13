// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/AITask_IdleChatInitiate.cpp (6 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 6 of 13 functions matched (46.15%). NOT COMPLETE YET.
// The 7 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AITask_IdleChatInitiate::vfunc_00 (0x00101AA0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// AITask_IdleChatInitiate::vfunc_00 (0x00101AA0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00403EA4[];

class AITask_IdleChatInitiate
{
public:
    virtual void* vfunc_00();
};

void* AITask_IdleChatInitiate::vfunc_00()
{
    return DAT_00403EA4;
}

// ============================================================================
// [VERIFIED] AITask_IdleChatInitiate::vfunc_54 (0x00101AB0, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundEntityLoader::vfunc_04 (0x00064FA0), which was matched first;
// its addresses and names were swapped for this function's.
// AITask_IdleChatInitiate::vfunc_54 (0x00101AB0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0010A6F0(void);

class AITask_IdleChatInitiate
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_54();
};

void AITask_IdleChatInitiate::vfunc_54()
{
    sub_0010A6F0();
}

// ============================================================================
// [VERIFIED] AITask_IdleChatInitiate::vfunc_52 (0x0010A690, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as GlanceAtOvertakingPed::vfunc_08 (0x000EFD20), which was matched first;
// its addresses and names were swapped for this function's.
// AITask_IdleChatInitiate::vfunc_52 (0x0010A690, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_003AB1D0;

class AITask_IdleChatInitiate
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
    virtual float vfunc_52();
};

float AITask_IdleChatInitiate::vfunc_52()
{
    return DAT_003AB1D0;
}

// ============================================================================
// [VERIFIED] AITask_IdleChatInitiate::vfunc_44 (0x0010A6B0, 56 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AITask_BasicInVehicle::vfunc_40 (0x0010CDB0), which was matched first;
// its addresses and names were swapped for this function's.
// AITask_IdleChatInitiate::vfunc_44 (0x0010A6B0, 56 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0038DAB0[];
extern "C" int DAT_0045C040;
extern "C" bool DAT_0045C044;
extern "C" int __cdecl sub_00065CF0(int, int);

class AITask_IdleChatInitiate
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

int AITask_IdleChatInitiate::vfunc_44()
{
    int t1;

    if (!(1 & DAT_0045C044)) {
        *(int*)&DAT_0045C044 = *(int*)&DAT_0045C044 | 1;
        t1 = sub_00065CF0((int)DAT_0038DAB0, 0);
        DAT_0045C040 = t1;
        return t1;
    }
    return DAT_0045C040;
}

// ============================================================================
// [VERIFIED] AITask_IdleChatInitiate::vfunc_53 (0x0010B430, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundEntityLoader::vfunc_04 (0x00064FA0), which was matched first;
// its addresses and names were swapped for this function's.
// AITask_IdleChatInitiate::vfunc_53 (0x0010B430, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0010B2F0(void);

class AITask_IdleChatInitiate
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_53();
};

void AITask_IdleChatInitiate::vfunc_53()
{
    sub_0010B2F0();
}

// ============================================================================
// [VERIFIED] AITask_IdleChatInitiate::vfunc_58 (0x0010CF80, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// AITask_IdleChatInitiate::vfunc_58 (0x0010CF80, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0038D130[];

class AITask_IdleChatInitiate
{
public:
    virtual void* vfunc_58();
};

void* AITask_IdleChatInitiate::vfunc_58()
{
    return DAT_0038D130;
}

