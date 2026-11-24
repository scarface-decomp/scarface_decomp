// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, ai/AIActionAimAt.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 3 functions matched (66.67%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AIActionAimAt::vfunc_02 (0x001054C0, 22 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AIActionAimAt::vfunc_02 (0x00120A60), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x001054C0
// what: Calls sub_00148D30 on m_Field08 and passes (&m_Field0C, 1) to sub_000DF100 on the returned object.
// tool: Gemini 4 Neon

struct ResultObj_001054C0
{
    void sub_000DF100(int* targetPtr, int flag);
};

struct Field08_001054C0
{
    ResultObj_001054C0* sub_00148D30();
};

class AIActionAimAt
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    char m_pad04[0x4];
    Field08_001054C0* m_Field08; // +0x08
    int m_Field0C; // +0x0C
};

void AIActionAimAt::vfunc_02()
{
    m_Field08->sub_00148D30()->sub_000DF100(&m_Field0C, 1);
}

// ============================================================================
// [VERIFIED] AIActionAimAt::vfunc_04 (0x001054E0, 18 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AIActionAimAt::vfunc_07 (0x00120A80), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x001054E0
// what: Calls sub_00148D30 on m_Field08 and calls sub_000DD780(true) on the returned object.
// tool: Gemini 4 Neon

struct ResultObj_001054E0
{
    void sub_000DD780(bool flag);
};

struct Field08_001054E0
{
    ResultObj_001054E0* sub_00148D30();
};

class AIActionAimAt
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    char m_pad04[0x4];
    Field08_001054E0* m_Field08; // +0x08
};

void AIActionAimAt::vfunc_04()
{
    m_Field08->sub_00148D30()->sub_000DD780(true);
}

