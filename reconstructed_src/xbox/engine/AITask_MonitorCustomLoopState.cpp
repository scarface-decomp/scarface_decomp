// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/AITask_MonitorCustomLoopState.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 9 functions matched (22.22%). NOT COMPLETE YET.
// The 7 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AITask_MonitorCustomLoopState::vfunc_00 (0x001273C0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
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

