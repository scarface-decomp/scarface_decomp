// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, ai/AIActionMoveTowards.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 3 functions matched (33.33%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AIActionMoveTowards::vfunc_07 (0x00120A00, 20 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Calls sub_001655C0 on m_Field08 and calls sub_000F2770(1, 0) on the returned object.
// ============================================================================
// bin: xb
// va: 0x00120A00
// what: Calls sub_001655C0 on m_Field08 and calls sub_000F2770(1, 0) on the returned object.
// tool: Gemini 4 Neon

struct ResultObj_00120A00
{
    void sub_000F2770(int a1, int a2);
};

struct Field08_00120A00
{
    ResultObj_00120A00* sub_001655C0();
};

class AIActionMoveTowards
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
    char m_pad04[0x4];
    Field08_00120A00* m_Field08; // +0x08
};

void AIActionMoveTowards::vfunc_07()
{
    m_Field08->sub_001655C0()->sub_000F2770(1, 0);
}

