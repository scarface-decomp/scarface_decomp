// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/Wait_AnimationPriority.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AICommandWaits::Wait_AnimationPriority::vfunc_01 (0x001382D0, 22 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns true if sub_00163D50() on the second argument is at least the threshold at +0x0C.
// ============================================================================
// bin: xb
// va: 0x001382D0
// what: Returns true if sub_00163D50() on the second argument is at least the threshold at +0x0C.
// tool: Gemini 4 Neon

struct Target_001382D0
{
    unsigned int sub_00163D50();
};

namespace AICommandWaits {

class Wait_AnimationPriority
{
public:
    virtual void vfunc_00();
    virtual bool vfunc_01(int a1, Target_001382D0* target);
    char m_pad04[0x8];
    unsigned int m_Field0C; // +0x0C
};

bool Wait_AnimationPriority::vfunc_01(int, Target_001382D0* target)
{
    return target->sub_00163D50() >= m_Field0C;
}

}

