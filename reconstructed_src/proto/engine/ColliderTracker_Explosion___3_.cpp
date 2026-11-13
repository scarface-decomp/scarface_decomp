// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/ColliderTracker_Explosion___3_.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ColliderTracker<Explosion*, 3>::vfunc_00 (0x0007DF40, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as ColliderTracker<Explosion*, 3>::vfunc_00 (0x00088380), which was matched first;
// its addresses and names were swapped for this function's.
// ColliderTracker<Explosion*, 3>::vfunc_00 (0x0007DF40, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class ColliderTracker_Explosion___3_
{
public:
    virtual int vfunc_00(int a1);
};

int ColliderTracker_Explosion___3_::vfunc_00(int a1)
{
    return *(int*)((int)this + (a1 * 4) + 16);
}

// ============================================================================
// [VERIFIED] ColliderTracker<Explosion*, 3>::vfunc_01 (0x0007DF50, 15 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as ColliderTracker<Explosion*, 3>::vfunc_01 (0x00088390), which was matched first;
// its addresses and names were swapped for this function's.
// ColliderTracker<Explosion*, 3>::vfunc_01 (0x0007DF50, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class ColliderTracker_Explosion___3_
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1, int a2);
};

int ColliderTracker_Explosion___3_::vfunc_01(int a1, int a2)
{
    *(int*)((int)this + (a1 * 4) + 16) = a2;
    return a2;
}

