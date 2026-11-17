// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/AIConditionUnary.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AIConditionUnary::vfunc_05 (0x00121980, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AIConditionUnary::vfunc_05 (Proto 0x001062F0), which was matched first;
// its addresses and names were swapped for this function's.
// AIConditionUnary::vfunc_05 (Proto 0x00121980, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
};

class AIConditionUnary
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    char m_pad04[0x4];
    Field08* m_Field08; // +0x08
};

void AIConditionUnary::vfunc_05()
{
    m_Field08->vfunc_05();
}

// ============================================================================
// [VERIFIED] AIConditionUnary::vfunc_03 (0x001225D0, 50 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AIConditionUnary::vfunc_03 (Proto 0x00106ED0), which was matched first;
// its addresses and names were swapped for this function's.
// AIConditionUnary::vfunc_03 (Proto 0x001225D0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" char DAT_0039E22C[];
extern "C" void __cdecl sub_00027600(int);

class AIConditionUnary
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual AIConditionUnary* vfunc_03(int a1);
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

AIConditionUnary* AIConditionUnary::vfunc_03(int a1)
{
    int t1;

    t1 = m_Field08;
    if (m_Field08) {
        ((Object*)t1)->vfunc_01();
    }
    m_Field08 = 0;
    *(int*)this = (int)DAT_0039E22C;
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

