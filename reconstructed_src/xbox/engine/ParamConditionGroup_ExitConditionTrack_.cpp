// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/ParamConditionGroup_ExitConditionTrack_.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 4 functions matched (25.00%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] fight::ParamConditionGroup<ExitConditionTrack>::vfunc_01 (0x000E9310, 6 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: fight::ParamConditionGroup<ExitConditionTrack>: Always returns 10.
// ============================================================================
// Same machine code as fight::ParamConditionGroup<ExitConditionTrack>::vfunc_01 (Proto 0x000D6C90), which was matched first;
// its addresses and names were swapped for this function's.
// fight::ParamConditionGroup<ExitConditionTrack>::vfunc_01 (Proto 0x000E9310, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class ExitConditionTrack;

namespace fight { 
template <class T0> class ParamConditionGroup
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
};
}

template <> int fight::ParamConditionGroup<ExitConditionTrack>::vfunc_01()
{
    return 10;
}

