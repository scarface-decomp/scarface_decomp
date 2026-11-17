// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/AITask_FleeFromExplodingCar.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 6 functions matched (50.00%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AITask_FleeFromExplodingCar::vfunc_36 (0x000F07A0, 41 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AITask_FleeFromExplodingCar::vfunc_36 (Proto 0x000F07A0, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct FieldB8
{
    void sub_0008D4C0(int);
};

class AITask_FleeFromExplodingCar
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
    void sub_000EFC40(int);
    char m_pad04[0xB4];
    FieldB8 m_FieldB8; // +0xB8
    char m_padB9[0x1F];
    bool m_FieldD8; // +0xD8
    bool m_FieldD9; // +0xD9
};

void AITask_FleeFromExplodingCar::vfunc_36()
{
    m_FieldD9 = false;
    m_FieldD8 = false;
    m_FieldB8.sub_0008D4C0(0);
    sub_000EFC40(0);
}

// ============================================================================
// [VERIFIED] AITask_FleeFromExplodingCar::vfunc_00 (0x000F0D90, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// AITask_FleeFromExplodingCar::vfunc_00 (0x000F0D90, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004042C4[];

class AITask_FleeFromExplodingCar
{
public:
    virtual void* vfunc_00();
};

void* AITask_FleeFromExplodingCar::vfunc_00()
{
    return DAT_004042C4;
}

// ============================================================================
// [VERIFIED] AITask_FleeFromExplodingCar::vfunc_01 (0x000F0DA0, 51 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AITask_FleeFromExplodingCar::vfunc_01 (Proto 0x000F0DA0, 51 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field4C
{
    void sub_000DBE80();
};

struct FieldA8
{
    void sub_00102BA0();
};

extern "C" void __cdecl sub_00025160(int);

class AITask_FleeFromExplodingCar
{
public:
    virtual void vfunc_00();
    virtual AITask_FleeFromExplodingCar* vfunc_01(int a1);
    void sub_000DC430();
    char m_pad04[0x48];
    Field4C m_Field4C; // +0x4C
    char m_pad4D[0x5B];
    FieldA8 m_FieldA8; // +0xA8
};

AITask_FleeFromExplodingCar* AITask_FleeFromExplodingCar::vfunc_01(int a1)
{
    m_FieldA8.sub_00102BA0();
    m_Field4C.sub_000DBE80();
    sub_000DC430();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

