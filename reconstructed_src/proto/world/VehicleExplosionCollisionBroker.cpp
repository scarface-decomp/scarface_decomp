// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, world/VehicleExplosionCollisionBroker.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] VehicleExplosionCollisionBroker::vfunc_00 (0x0001C900, 81 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x0001C900
// what: 
// tool: the portal's starter code (no AI)

// VehicleExplosionCollisionBroker::vfunc_00 (Proto 0x0001C900, 81 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00018350();
    int sub_00026D50();
    int sub_00056450();
    int sub_0009F970();
    int sub_001DB8F0();
    void sub_001DC1A0(int, int);
};

class VehicleExplosionCollisionBroker
{
public:
    virtual bool vfunc_00(int a1);
};

bool VehicleExplosionCollisionBroker::vfunc_00(int a1)
{
    int r_esi, t1, t4;

    t1 = ((Object*)a1)->sub_00056450();
    r_esi = 0;
    if (*(int*)(t1 + 20)) {
        r_esi = ((Object*)*(int*)(t1 + 20))->sub_0009F970();
    }
    t4 = *(int*)(((Object*)a1)->sub_00026D50() + 20);
    if (r_esi) {
        r_esi = ((Object*)r_esi)->sub_001DB8F0();
        if (!r_esi) goto L_49;
        ((Object*)r_esi)->sub_001DC1A0(t4, ((Object*)a1)->sub_00018350());
    }
L_49:
    return false;
}

