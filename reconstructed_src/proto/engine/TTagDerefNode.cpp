// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/TTagDerefNode.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] TTagDerefNode::vfunc_04 (0x00063240, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as TTagDerefNode::vfunc_04 (0x0006D510), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x00063240
// what: Returns the second parameter as a zero-extended 16-bit unsigned integer.
// tool: Gemini 4 Neon

class TTagDerefNode
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual unsigned int vfunc_04(int a1, unsigned short a2, int a3);
};

unsigned int TTagDerefNode::vfunc_04(int, unsigned short a2, int)
{
    return a2;
}

