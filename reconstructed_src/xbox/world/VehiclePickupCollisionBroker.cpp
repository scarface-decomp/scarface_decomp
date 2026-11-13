// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, world/VehiclePickupCollisionBroker.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] VehiclePickupCollisionBroker::vfunc_01 (0x0001C010, 21 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// VehiclePickupCollisionBroker::vfunc_01 (0x0001C010, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_000ABC70();
};

class VehiclePickupCollisionBroker
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1);
};

int VehiclePickupCollisionBroker::vfunc_01(int a1)
{
    int r_eax;

    r_eax = 0;
    if (*(int*)(a1 + 20)) {
        r_eax = ((Object*)*(int*)(a1 + 20))->sub_000ABC70();
    }
    return r_eax;
}

