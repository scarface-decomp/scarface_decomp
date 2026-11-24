// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/Wait_AnimationPriority.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AICommandWaits::Wait_AnimationPriority::vfunc_01 (0x0011D520, 22 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AICommandWaits::Wait_AnimationPriority::vfunc_01 (0x001382D0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x0011D520
// what: Returns true if sub_00147B00() on the second argument is at least the threshold at +0x0C.
// tool: Gemini 4 Neon

struct Target_0011D520
{
    unsigned int sub_00147B00();
};

namespace AICommandWaits {

class Wait_AnimationPriority
{
public:
    virtual void vfunc_00();
    virtual bool vfunc_01(int a1, Target_0011D520* target);
    char m_pad04[0x8];
    unsigned int m_Field0C; // +0x0C
};

bool Wait_AnimationPriority::vfunc_01(int, Target_0011D520* target)
{
    return target->sub_00147B00() >= m_Field0C;
}

}

