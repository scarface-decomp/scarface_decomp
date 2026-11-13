// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/AITask_ProvokeAnotherPed.cpp (5 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 5 of 10 functions matched (50.00%). NOT COMPLETE YET.
// The 5 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AITask_ProvokeAnotherPed::vfunc_00 (0x0011C9F0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// AITask_ProvokeAnotherPed::vfunc_00 (0x0011C9F0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00429294[];

class AITask_ProvokeAnotherPed
{
public:
    virtual void* vfunc_00();
};

void* AITask_ProvokeAnotherPed::vfunc_00()
{
    return DAT_00429294;
}

// ============================================================================
// [VERIFIED] AITask_ProvokeAnotherPed::vfunc_57 (0x0011CA00, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundEntityLoader::vfunc_04 (0x00064FA0), which was matched first;
// its addresses and names were swapped for this function's.
// AITask_ProvokeAnotherPed::vfunc_57 (0x0011CA00, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001261A0(void);

class AITask_ProvokeAnotherPed
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_57();
};

void AITask_ProvokeAnotherPed::vfunc_57()
{
    sub_001261A0();
}

// ============================================================================
// [VERIFIED] AITask_ProvokeAnotherPed::vfunc_61 (0x00126150, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// AITask_ProvokeAnotherPed::vfunc_61 (0x00126150, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003AAB10[];

class AITask_ProvokeAnotherPed
{
public:
    virtual void* vfunc_61();
};

void* AITask_ProvokeAnotherPed::vfunc_61()
{
    return DAT_003AAB10;
}

// ============================================================================
// [VERIFIED] AITask_ProvokeAnotherPed::vfunc_47 (0x00126160, 56 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AITask_BasicInVehicle::vfunc_40 (0x0010CDB0), which was matched first;
// its addresses and names were swapped for this function's.
// AITask_ProvokeAnotherPed::vfunc_47 (0x00126160, 56 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003AFCFC[];
extern "C" int DAT_00489DF4;
extern "C" bool DAT_00489DF8;
extern "C" int __cdecl sub_000700C0(int, int);

class AITask_ProvokeAnotherPed
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

int AITask_ProvokeAnotherPed::vfunc_47()
{
    int t1;

    if (!(1 & DAT_00489DF8)) {
        *(int*)&DAT_00489DF8 = *(int*)&DAT_00489DF8 | 1;
        t1 = sub_000700C0((int)DAT_003AFCFC, 0);
        DAT_00489DF4 = t1;
        return t1;
    }
    return DAT_00489DF4;
}

// ============================================================================
// [VERIFIED] AITask_ProvokeAnotherPed::vfunc_58 (0x001262B0, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundEntityLoader::vfunc_04 (0x00064FA0), which was matched first;
// its addresses and names were swapped for this function's.
// AITask_ProvokeAnotherPed::vfunc_58 (0x001262B0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00128CC0(void);

class AITask_ProvokeAnotherPed
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_58();
};

void AITask_ProvokeAnotherPed::vfunc_58()
{
    sub_00128CC0();
}

