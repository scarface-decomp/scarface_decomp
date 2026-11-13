// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, ai/AIActionUnary.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 2 functions matched (50.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AIActionUnary::vfunc_04 (0x001047E0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as LazyEvaluatorOnSidewalk::vfunc_00 (0x001078B0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x001047E0
// what: Passes the call on to the object this one holds.
// tool: Claude Fable 5.2 (look-alike of 0x000E5480, names and addresses swapped)
// AIActionUnary::vfunc_04 (0x001047E0, 8 bytes)
struct Field08
{
    void sub_00102F90();
};

class AIActionUnary
{
public:
    virtual void vfunc_04();
    char m_pad04[0x4];
    Field08* m_Field08; // +0x08
};

void AIActionUnary::vfunc_04()
{
    m_Field08->sub_00102F90();
}

