// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/AICommandSequencer.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AICommandSequencer::vfunc_00 (0x00131D00, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns AICommandSequencer's static class record (ConcreteClassRep<AICommandSequencer>), the object's run-time type.
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// AICommandSequencer::vfunc_00 (0x00131D00, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0042D7B8[];

class AICommandSequencer
{
public:
    virtual void* vfunc_00();
};

void* AICommandSequencer::vfunc_00()
{
    return DAT_0042D7B8;
}

// ============================================================================
// [VERIFIED] AICommandSequencer::vfunc_01 (0x001334D0, 50 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: AICommandSequencer's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// Same machine code as AICommandSequencer::vfunc_01 (Proto 0x00117EF0), which was matched first;
// its addresses and names were swapped for this function's.
// AICommandSequencer::vfunc_01 (Proto 0x001334D0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B15D4[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_0012F790(void);

class AICommandSequencer
{
public:
    virtual void vfunc_00();
    virtual AICommandSequencer* vfunc_01(int a1);
    void sub_0002C720();
    void sub_00131C60();
};

AICommandSequencer* AICommandSequencer::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003B15D4;
    sub_0012F790();
    sub_00131C60();
    sub_0002C720();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

