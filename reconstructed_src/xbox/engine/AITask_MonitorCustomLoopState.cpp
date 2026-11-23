// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/AITask_MonitorCustomLoopState.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 9 functions matched (44.44%). NOT COMPLETE YET.
// The 5 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AITask_MonitorCustomLoopState::vfunc_46 (0x001270B0, 33 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns a copy of the three-number vector at +0x170.
// ============================================================================
// bin: xb
// va: 0x001270B0
// what: Returns a copy of the three-number vector at +0x170.
// tool: Claude Opus 5.5 (generated from the shape 'return a vector field', checked on decomp.me preset 266 by example)
struct Vector_001270B0 { float x, y, z; };

class Class_001270B0
{
public:
    Vector_001270B0 sub_001270B0();
    char m_pad00[0x170];
    Vector_001270B0 m_Field170; // +0x170
};

Vector_001270B0 Class_001270B0::sub_001270B0()
{
    return m_Field170;
}

// ============================================================================
// [VERIFIED] AITask_MonitorCustomLoopState::vfunc_47 (0x001270E0, 6 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: AITask_MonitorCustomLoopState: Always returns 10000.
// ============================================================================
// Same machine code as AITask_MonitorCustomLoopState::vfunc_44 (Proto 0x0010B600), which was matched first;
// its addresses and names were swapped for this function's.
// AITask_MonitorCustomLoopState::vfunc_47 (Proto 0x001270E0, 6 bytes)
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
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual int vfunc_47();
};

int AITask_MonitorCustomLoopState::vfunc_47()
{
    return 10000;
}

// ============================================================================
// [VERIFIED] AITask_MonitorCustomLoopState::vfunc_00 (0x001273C0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns AITask_MonitorCustomLoopState's static class record (ConcreteClassRep<AITask_MonitorCustomLoopState>), the object's run-time type.
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// AITask_MonitorCustomLoopState::vfunc_00 (0x001273C0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00429630[];

class AITask_MonitorCustomLoopState
{
public:
    virtual void* vfunc_00();
};

void* AITask_MonitorCustomLoopState::vfunc_00()
{
    return DAT_00429630;
}

// ============================================================================
// [VERIFIED] AITask_MonitorCustomLoopState::vfunc_01 (0x001273D0, 43 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: AITask_MonitorCustomLoopState's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// AITask_MonitorCustomLoopState::vfunc_01 (0x001273D0, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field160
{
    void sub_000EF6A0();
};

extern "C" void __cdecl sub_00027600(int);

class AITask_MonitorCustomLoopState
{
public:
    virtual void vfunc_00();
    virtual AITask_MonitorCustomLoopState* vfunc_01(int a1);
    void sub_000EFC40();
    char m_pad04[0x15C];
    Field160 m_Field160; // +0x160
};

AITask_MonitorCustomLoopState* AITask_MonitorCustomLoopState::vfunc_01(int a1)
{
    m_Field160.sub_000EF6A0();
    sub_000EFC40();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

