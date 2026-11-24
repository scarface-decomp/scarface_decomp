// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, ai/AIActionSkipIfFail.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AIActionSkipIfFail::vfunc_03 (0x0011FD70, 18 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AIActionSkipIfFail::vfunc_03 (Proto 0x00104A70), which was matched first;
// its addresses and names were swapped for this function's.
// AIActionSkipIfFail::vfunc_03 (Proto 0x0011FD70, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    int sub_0011E1B0();
};

class AIActionSkipIfFail
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
    char m_pad04[0x4];
    Field08* m_Field08; // +0x08
};

int AIActionSkipIfFail::vfunc_03()
{
    int r_eax;

    r_eax = m_Field08->sub_0011E1B0();
    if (!r_eax) {
        r_eax = 2;
    }
    return r_eax;
}

// ============================================================================
// [VERIFIED] AIActionSkipIfFail::vfunc_01 (0x00120040, 18 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Calls virtual method slot 1 on m_Field08 and returns 2 if it returned 0.
// ============================================================================
// bin: xb
// va: 0x00120040
// what: Calls virtual method slot 1 on m_Field08 and returns 2 if it returned 0.
// tool: Gemini 4 Neon

struct Field08_00120040
{
    virtual void vfunc_00();
    virtual int vfunc_01();
};

class AIActionSkipIfFail
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
    char m_pad04[0x4];
    Field08_00120040* m_Field08; // +0x08
};

int AIActionSkipIfFail::vfunc_01()
{
    int result = m_Field08->vfunc_01();
    if (!result) {
        result = 2;
    }
    return result;
}

