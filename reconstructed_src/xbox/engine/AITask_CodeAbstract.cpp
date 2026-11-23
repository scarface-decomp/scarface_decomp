// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/AITask_CodeAbstract.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AITask_CodeAbstract::vfunc_00 (0x00106DA0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns AITask_CodeAbstract's static class record (ConcreteClassRep<AITask_CodeAbstract>), the object's run-time type.
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// AITask_CodeAbstract::vfunc_00 (0x00106DA0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00428EA0[];

class AITask_CodeAbstract
{
public:
    virtual void* vfunc_00();
};

void* AITask_CodeAbstract::vfunc_00()
{
    return DAT_00428EA0;
}

// ============================================================================
// [VERIFIED] AITask_CodeAbstract::vfunc_01 (0x0011CA10, 40 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: AITask_CodeAbstract's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// Same machine code as AITask_CodeAbstract::vfunc_01 (Proto 0x00101AC0), which was matched first;
// its addresses and names were swapped for this function's.
// AITask_CodeAbstract::vfunc_01 (Proto 0x0011CA10, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field38
{
    void sub_000EFB30();
};

extern "C" void __cdecl sub_00027600(int);

class AITask_CodeAbstract
{
public:
    virtual void vfunc_00();
    virtual AITask_CodeAbstract* vfunc_01(int a1);
    void sub_0002C720();
    char m_pad04[0x34];
    Field38 m_Field38; // +0x38
};

AITask_CodeAbstract* AITask_CodeAbstract::vfunc_01(int a1)
{
    m_Field38.sub_000EFB30();
    sub_0002C720();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

