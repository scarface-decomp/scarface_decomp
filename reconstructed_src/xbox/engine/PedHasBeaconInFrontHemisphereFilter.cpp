// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/PedHasBeaconInFrontHemisphereFilter.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] PedHasBeaconInFrontHemisphereFilter::vfunc_00 (0x00124030, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as HasBorderWithTypeFilter::vfunc_00 (0x00116470), which was matched first;
// its addresses and names were swapped for this function's.
// PedHasBeaconInFrontHemisphereFilter::vfunc_00 (0x00124030, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00123FD0(int);
};

class PedHasBeaconInFrontHemisphereFilter
{
public:
    virtual void vfunc_00(int a1);
    int m_Field04; // +0x04
};

void PedHasBeaconInFrontHemisphereFilter::vfunc_00(int a1)
{
    ((Object*)a1)->sub_00123FD0(m_Field04);
}

