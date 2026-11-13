// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/Stats.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] content::Stats::vfunc_00 (0x00240C50, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::BaseObject::vfunc_00 (0x00026BB0), which was matched first;
// its addresses and names were swapped for this function's.
// content::Stats::vfunc_00 (0x00240C50, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003D4C1C[];
extern "C" void __cdecl sub_00027600(int);

namespace content {

class Stats
{
public:
    virtual Stats* vfunc_00(int a1);
};

Stats* Stats::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003D4C1C;
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

}

