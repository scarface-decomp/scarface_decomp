// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/AIConditionHasScriptAttributeSetToTrue.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AIConditionHasScriptAttributeSetToTrue::vfunc_04 (0x001063E0, 24 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x001063E0
// what: 
// tool: the portal's starter code (no AI)

// AIConditionHasScriptAttributeSetToTrue::vfunc_04 (Proto 0x001063E0, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    int sub_00028A80(int, int);
};

extern "C" int __cdecl sub_0008E600(int);

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
    return sub_0008E600(m_Field08->sub_00028A80((int)(&m_Field0C), 0));
}

