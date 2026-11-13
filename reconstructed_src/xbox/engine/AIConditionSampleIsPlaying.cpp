// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/AIConditionSampleIsPlaying.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AIConditionSampleIsPlaying::vfunc_04 (0x00121940, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as LazyEvaluatorOnSidewalk::vfunc_00 (0x001078B0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x00121940
// what: Passes the call on to the object this one holds.
// tool: Claude Fable 5.2 (look-alike of 0x000E5480, names and addresses swapped)
// AIConditionSampleIsPlaying::vfunc_04 (0x00121940, 8 bytes)
struct Field08
{
    void sub_00163BD0();
};

class AIConditionSampleIsPlaying
{
public:
    virtual void vfunc_04();
    char m_pad04[0x4];
    Field08* m_Field08; // +0x08
};

void AIConditionSampleIsPlaying::vfunc_04()
{
    m_Field08->sub_00163BD0();
}

