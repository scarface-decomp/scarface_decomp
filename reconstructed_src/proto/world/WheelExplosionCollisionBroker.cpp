// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, world/WheelExplosionCollisionBroker.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] WheelExplosionCollisionBroker::vfunc_00 (0x0001C250, 49 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x0001C250
// what: 
// tool: the portal's starter code (no AI)

// WheelExplosionCollisionBroker::vfunc_00 (Proto 0x0001C250, 49 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00026D50();
    int sub_00056450();
    void sub_000B1E90(int);
};

class WheelExplosionCollisionBroker
{
public:
    virtual bool vfunc_00(int a1);
};

bool WheelExplosionCollisionBroker::vfunc_00(int a1)
{
    int t1, t2, t3, t4;

    t1 = ((Object*)a1)->sub_00056450();
    t2 = *(int*)(t1 + 20);
    if (*(int*)(t1 + 20)) {
        t3 = ((Object*)a1)->sub_00026D50();
        t4 = *(int*)(t3 + 20);
        if (!*(int*)(t3 + 20)) goto L_2A;
        ((Object*)t2)->sub_000B1E90(t4);
    }
L_2A:
    return false;
}

