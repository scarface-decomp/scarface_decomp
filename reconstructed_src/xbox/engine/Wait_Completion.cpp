// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/Wait_Completion.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AICommandWaits::Wait_Completion::vfunc_01 (0x001383F0, 12 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AICommandWaits::Wait_Completion::vfunc_01 (Proto 0x0011D600), which was matched first;
// its addresses and names were swapped for this function's.
// AICommandWaits::Wait_Completion::vfunc_01 (Proto 0x001383F0, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001333B0();
};

namespace AICommandWaits {

class Wait_Completion
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01(int a1, int a2);
};

void Wait_Completion::vfunc_01(int a1, int a2)
{
    ((Object*)a1)->sub_001333B0();
}

}

