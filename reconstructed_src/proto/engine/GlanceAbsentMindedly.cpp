// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/GlanceAbsentMindedly.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 4 functions matched (25.00%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] GlanceAbsentMindedly::vfunc_00 (0x000DC600, 14 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as GlanceAbsentMindedly::vfunc_00 (0x000EFDE0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x000DC600
// what: Says whether sub_000BAE80 on the member at +0x10 answers no.
// tool: Claude Opus 5.5 (generated from the shape 'not of a member's answer', checked on decomp.me preset 266 by example)
class Member_000DC600
{
public:
    bool sub_000BAE80();
};

class Class_000DC600
{
public:
    int sub_000DC600();
    char m_pad00[0x10];
    Member_000DC600 m_Field10; // +0x10
};

int Class_000DC600::sub_000DC600()
{
    return !m_Field10.sub_000BAE80();
}

