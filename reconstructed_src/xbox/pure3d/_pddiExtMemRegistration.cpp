// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/_pddiExtMemRegistration.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::_pddiExtMemRegistration::vfunc_01 (0x0029ED50, 15 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dExtTODFactor::vfunc_04 (0x00263ED0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x0029ED50
// what: Stores a value in the global at 0x004BDC58.
// tool: Claude Opus 5.5 (generated from the shape 'set int global (framed)', checked on decomp.me preset 266 by example)
#pragma optimize("y", off)

extern "C" int DAT_004BDC58;

void __stdcall sub_0029ED50(int value)
{
    DAT_004BDC58 = value;
}

