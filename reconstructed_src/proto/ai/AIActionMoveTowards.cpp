// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, ai/AIActionMoveTowards.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 3 functions matched (33.33%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AIActionMoveTowards::vfunc_04 (0x00105470, 20 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AIActionMoveTowards::vfunc_07 (0x00120A00), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x00105470
// what: Calls sub_00148D30 on m_Field08 and calls sub_000DF020(1, 0) on the returned object.
// tool: Gemini 4 Neon

struct ResultObj_00105470
{
    void sub_000DF020(int a1, int a2);
};

struct Field08_00105470
{
    ResultObj_00105470* sub_00148D30();
};

class AIActionMoveTowards
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    char m_pad04[0x4];
    Field08_00105470* m_Field08; // +0x08
};

void AIActionMoveTowards::vfunc_04()
{
    m_Field08->sub_00148D30()->sub_000DF020(1, 0);
}

