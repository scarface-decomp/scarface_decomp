// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/AITask_MonitorCustomLoopState.cpp (5 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 5 of 8 functions matched (62.50%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AITask_MonitorCustomLoopState::vfunc_36 (0x0010B5B0, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundEntityLoader::vfunc_04 (0x00064FA0), which was matched first;
// its addresses and names were swapped for this function's.
// AITask_MonitorCustomLoopState::vfunc_36 (0x0010B5B0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_000DBEA0(void);

class AITask_MonitorCustomLoopState
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_36();
};

void AITask_MonitorCustomLoopState::vfunc_36()
{
    sub_000DBEA0();
}

// ============================================================================
// [VERIFIED] AITask_MonitorCustomLoopState::vfunc_43 (0x0010B5D0, 33 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns a copy of a three-number vector kept in an object.
// ============================================================================
// bin: proto
// va: 0x0010B5D0
// what: Returns a copy of a three-number vector kept in an object.
// tool: Claude Opus 5.5 (transplanted from xb:0x000E7920, nearest by portal/tools/similar.py)
// sub_0010B5D0 (0x0010B5D0, 30 bytes)

struct Struct_0010B5D0
{
    float m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
};

class Class_0010B5D0
{
public:
    Struct_0010B5D0 sub_0010B5D0() const;

    char m_pad00[0xF8];
    Struct_0010B5D0 m_FieldF8; // +0xF8
};

// Returns the stored vector by value.
Struct_0010B5D0 Class_0010B5D0::sub_0010B5D0() const
{
    return m_FieldF8;
}

// ============================================================================
// [VERIFIED] AITask_MonitorCustomLoopState::vfunc_44 (0x0010B600, 6 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AITask_MonitorCustomLoopState::vfunc_44 (Proto 0x0010B600, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class AITask_MonitorCustomLoopState
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
    virtual int vfunc_44();
};

int AITask_MonitorCustomLoopState::vfunc_44()
{
    return 10000;
}

// ============================================================================
// [VERIFIED] AITask_MonitorCustomLoopState::vfunc_00 (0x0010B8D0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// AITask_MonitorCustomLoopState::vfunc_00 (0x0010B8D0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00404298[];

class AITask_MonitorCustomLoopState
{
public:
    virtual void* vfunc_00();
};

void* AITask_MonitorCustomLoopState::vfunc_00()
{
    return DAT_00404298;
}

// ============================================================================
// [VERIFIED] AITask_MonitorCustomLoopState::vfunc_01 (0x0010B8E0, 43 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AITask_MonitorCustomLoopState::vfunc_01 (Proto 0x0010B8E0, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct FieldE8
{
    void sub_000DC2C0();
};

extern "C" void __cdecl sub_00025160(int);

class AITask_MonitorCustomLoopState
{
public:
    virtual void vfunc_00();
    virtual AITask_MonitorCustomLoopState* vfunc_01(int a1);
    void sub_000DC500();
    char m_pad04[0xE4];
    FieldE8 m_FieldE8; // +0xE8
};

AITask_MonitorCustomLoopState* AITask_MonitorCustomLoopState::vfunc_01(int a1)
{
    m_FieldE8.sub_000DC2C0();
    sub_000DC500();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

