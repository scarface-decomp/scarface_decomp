// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, om/SparksHeap.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] om::SparksHeap::vfunc_00 (0x006F2EF0, 14 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::SparksHeap::vfunc_00 (Proto 0x0029A0C0), which was matched first;
// its addresses and names were swapped for this function's.
// om::SparksHeap::vfunc_00 (Proto 0x006F2EF0, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_006F2C90(void);

namespace om {

class SparksHeap
{
public:
    virtual SparksHeap* vfunc_00(int a1);
};

SparksHeap* SparksHeap::vfunc_00(int a1)
{
    sub_006F2C90();
    return this;
}

}

