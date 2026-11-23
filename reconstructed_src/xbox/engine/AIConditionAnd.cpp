// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/AIConditionAnd.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AIConditionAnd::vfunc_04 (0x001219C0, 38 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AIConditionAnd::vfunc_04 (Proto 0x00106330), which was matched first;
// its addresses and names were swapped for this function's.
// AIConditionAnd::vfunc_04 (Proto 0x001219C0, 38 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual bool vfunc_04();
};

struct Field0C
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual bool vfunc_04();
};

class AIConditionAnd
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual int vfunc_04();
    char m_pad04[0x4];
    Field08* m_Field08; // +0x08
    Field0C* m_Field0C; // +0x0C
};

int AIConditionAnd::vfunc_04()
{
    if (m_Field08->vfunc_04()) {
        if (!m_Field0C->vfunc_04()) goto L_22;
        return 1;
    }
L_22:
    return 0;
}

// ============================================================================
// [VERIFIED] AIConditionAnd::vfunc_03 (0x00122680, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: AIConditionAnd's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// Same machine code as Collidable::vfunc_03 (0x00011F20), which was matched first;
// its addresses and names were swapped for this function's.
// AIConditionAnd::vfunc_03 (0x00122680, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00121E20(void);
extern "C" void __cdecl sub_00027600(int);

class AIConditionAnd
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual AIConditionAnd* vfunc_03(int a1);
};

AIConditionAnd* AIConditionAnd::vfunc_03(int a1)
{
    sub_00121E20();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

