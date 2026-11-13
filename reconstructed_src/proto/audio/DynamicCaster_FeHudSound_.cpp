// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, audio/DynamicCaster_FeHudSound_.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] content::LoadInventory::DynamicCaster<FeHudSound>::vfunc_00 (0x0006DEA0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as content::LoadInventory::DynamicCaster<NavMesh>::vfunc_00 (0x00035AD0), which was matched first;
// its addresses and names were swapped for this function's.
// content::LoadInventory::DynamicCaster<FeHudSound>::vfunc_00 (0x0006DEA0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003F4504[];
extern "C" char DAT_003F9354[];
extern "C" void __cdecl sub_002C92F8(int, int, int, int, int);

class FeHudSound;

namespace content { namespace LoadInventory { 
template <class T0> class DynamicCaster
{
public:
    virtual void vfunc_00(int a1);
};
} }

template <> void content::LoadInventory::DynamicCaster<FeHudSound>::vfunc_00(int a1)
{
    sub_002C92F8(a1, 0, (int)DAT_003F4504, (int)DAT_003F9354, 0);
}

