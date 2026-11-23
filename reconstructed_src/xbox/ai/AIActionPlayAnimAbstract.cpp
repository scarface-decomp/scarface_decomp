// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, ai/AIActionPlayAnimAbstract.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 4 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AIActionPlayAnimAbstract::vfunc_05 (0x00120B40, 39 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AIActionPlayAnimAbstract::vfunc_06 (Proto 0x001055A0), which was matched first;
// its addresses and names were swapped for this function's.
// AIActionPlayAnimAbstract::vfunc_05 (Proto 0x00120B40, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    int sub_00163D50();
};

extern "C" int DAT_0042F580;
extern "C" bool __cdecl sub_0011E190(void);

class AIActionPlayAnimAbstract
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual int vfunc_05();
    char m_pad04[0x4];
    Field08* m_Field08; // +0x08
};

int AIActionPlayAnimAbstract::vfunc_05()
{
    if (sub_0011E190()) {
        if (m_Field08->sub_00163D50() != DAT_0042F580) goto L_23;
        return 1;
    }
L_23:
    return 0;
}

// ============================================================================
// [VERIFIED] AIActionPlayAnimAbstract::vfunc_09 (0x00120B70, 25 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AIActionPlayAnimAbstract::vfunc_09 (Proto 0x001055D0), which was matched first;
// its addresses and names were swapped for this function's.
// AIActionPlayAnimAbstract::vfunc_09 (Proto 0x00120B70, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    int sub_00163D50();
};

class AIActionPlayAnimAbstract
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
    virtual void vfunc_08();
    virtual bool vfunc_09();
    char m_pad04[0x4];
    Field08* m_Field08; // +0x08
    int m_Field0C; // +0x0C
};

bool AIActionPlayAnimAbstract::vfunc_09()
{
    return m_Field08->sub_00163D50() >= m_Field0C;
}

// ============================================================================
// [VERIFIED] AIActionPlayAnimAbstract::vfunc_10 (0x00120B90, 21 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AIActionPlayAnimAbstract::vfunc_10 (Proto 0x001055F0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: proto
// va: 0x00120B90
// what: 
// tool: the portal's starter code (no AI)

// AIActionPlayAnimAbstract::vfunc_10 (Proto 0x00120B90, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    int sub_00163D50();
};

class AIActionPlayAnimAbstract
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
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual int vfunc_10();
    char m_pad04[0x4];
    Field08* m_Field08; // +0x08
    int m_Field0C; // +0x0C
};

int AIActionPlayAnimAbstract::vfunc_10()
{
    return m_Field08->sub_00163D50() == m_Field0C;
}

// ============================================================================
// [VERIFIED] AIActionPlayAnimAbstract::vfunc_07 (0x00120BB0, 11 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AIActionPlayAnimAbstract::vfunc_04 (Proto 0x00105610), which was matched first;
// its addresses and names were swapped for this function's.
// AIActionPlayAnimAbstract::vfunc_07 (Proto 0x00120BB0, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    void sub_00166020(int);
};

class AIActionPlayAnimAbstract
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
    Field08* m_Field08; // +0x08
};

void AIActionPlayAnimAbstract::vfunc_07()
{
    m_Field08->sub_00166020(0);
}

