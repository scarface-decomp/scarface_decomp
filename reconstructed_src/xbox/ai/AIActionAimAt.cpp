// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, ai/AIActionAimAt.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 3 functions matched (66.67%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AIActionAimAt::vfunc_02 (0x00120A60, 22 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Calls sub_001655C0 on m_Field08 and passes (&m_Field0C, 1) to sub_000F2860 on the returned object.
// ============================================================================
// bin: xb
// va: 0x00120A60
// what: Calls sub_001655C0 on m_Field08 and passes (&m_Field0C, 1) to sub_000F2860 on the returned object.
// tool: Gemini 4 Neon

struct ResultObj_00120A60
{
    void sub_000F2860(int* targetPtr, int flag);
};

struct Field08_00120A60
{
    ResultObj_00120A60* sub_001655C0();
};

class AIActionAimAt
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    char m_pad04[0x4];
    Field08_00120A60* m_Field08; // +0x08
    int m_Field0C; // +0x0C
};

void AIActionAimAt::vfunc_02()
{
    m_Field08->sub_001655C0()->sub_000F2860(&m_Field0C, 1);
}

// ============================================================================
// [VERIFIED] AIActionAimAt::vfunc_07 (0x00120A80, 18 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Calls sub_001655C0 on m_Field08 and calls sub_000F0F00(true) on the returned object.
// ============================================================================
// bin: xb
// va: 0x00120A80
// what: Calls sub_001655C0 on m_Field08 and calls sub_000F0F00(true) on the returned object.
// tool: Gemini 4 Neon

struct ResultObj_00120A80
{
    void sub_000F0F00(bool flag);
};

struct Field08_00120A80
{
    ResultObj_00120A80* sub_001655C0();
};

class AIActionAimAt
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
    Field08_00120A80* m_Field08; // +0x08
};

void AIActionAimAt::vfunc_07()
{
    m_Field08->sub_001655C0()->sub_000F0F00(true);
}

