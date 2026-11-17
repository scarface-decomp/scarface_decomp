// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, ai/AIActionWaitForCondition.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AIActionWaitForCondition::vfunc_06 (0x00105C80, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AIActionWaitForCondition::vfunc_06 (Proto 0x00105C80, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
};

class AIActionWaitForCondition
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    char m_pad04[0x4];
    Field08* m_Field08; // +0x08
};

void AIActionWaitForCondition::vfunc_06()
{
    m_Field08->vfunc_04();
}

// ============================================================================
// [VERIFIED] AIActionWaitForCondition::vfunc_00 (0x00106250, 39 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AIActionSetSharedIntToRandom::vfunc_00 (0x00121540), which was matched first;
// its addresses and names were swapped for this function's.
// AIActionWaitForCondition::vfunc_00 (0x00106250, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    void sub_000DC2C0();
};

extern "C" char DAT_0038C664[];
extern "C" void __cdecl sub_00025160(int);

class AIActionWaitForCondition
{
public:
    virtual AIActionWaitForCondition* vfunc_00(int a1);
    char m_pad04[0x4];
    Field08 m_Field08; // +0x08
};

AIActionWaitForCondition* AIActionWaitForCondition::vfunc_00(int a1)
{
    m_Field08.sub_000DC2C0();
    *(int*)this = (int)DAT_0038C664;
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

