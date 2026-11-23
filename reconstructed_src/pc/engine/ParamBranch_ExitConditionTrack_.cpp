// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, engine/ParamBranch_ExitConditionTrack_.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] fight::ParamBranch<ExitConditionTrack>::vfunc_01 (0x006E3F00, 6 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: fight::ParamBranch<ExitConditionTrack>: Always returns 9.
// ============================================================================
// Same machine code as fight::ParamBranch<ExitConditionTrack>::vfunc_01 (Proto 0x000D6C80), which was matched first;
// its addresses and names were swapped for this function's.
// fight::ParamBranch<ExitConditionTrack>::vfunc_01 (Proto 0x006E3F00, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class ExitConditionTrack;

namespace fight { 
template <class T0> class ParamBranch
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
};
}

template <> int fight::ParamBranch<ExitConditionTrack>::vfunc_01()
{
    return 9;
}

