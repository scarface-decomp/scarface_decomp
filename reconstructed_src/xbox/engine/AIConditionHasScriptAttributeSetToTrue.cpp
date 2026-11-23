// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/AIConditionHasScriptAttributeSetToTrue.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AIConditionHasScriptAttributeSetToTrue::vfunc_04 (0x00121A70, 24 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AIConditionHasScriptAttributeSetToTrue::vfunc_04 (Proto 0x001063E0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: proto
// va: 0x00121A70
// what: 
// tool: the portal's starter code (no AI)

// AIConditionHasScriptAttributeSetToTrue::vfunc_04 (Proto 0x00121A70, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    int sub_0002B540(int, int);
};

extern "C" int __cdecl sub_00099BC0(int);

class AIConditionHasScriptAttributeSetToTrue
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual int vfunc_04();
    char m_pad04[0x4];
    Field08* m_Field08; // +0x08
    int m_Field0C; // +0x0C
};

int AIConditionHasScriptAttributeSetToTrue::vfunc_04()
{
    return sub_00099BC0(m_Field08->sub_0002B540((int)(&m_Field0C), 0));
}

