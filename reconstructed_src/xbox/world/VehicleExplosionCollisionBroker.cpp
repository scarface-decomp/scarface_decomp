// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, world/VehicleExplosionCollisionBroker.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] VehicleExplosionCollisionBroker::vfunc_00 (0x0001D460, 87 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// VehicleExplosionCollisionBroker::vfunc_00 (0x0001D460, 87 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_000185A0(int);
    int sub_000ABC70();
    int sub_000CE360();
    int sub_000CE970();
    int sub_00217380();
    void sub_00219DE0(int, int);
};

class VehicleExplosionCollisionBroker
{
public:
    virtual bool vfunc_00(int a1);
};

bool VehicleExplosionCollisionBroker::vfunc_00(int a1)
{
    int r_esi, t1, t3, t4, t5;

    t1 = ((Object*)a1)->sub_000CE360();
    r_esi = 0;
    if (*(int*)(t1 + 20)) {
        r_esi = ((Object*)*(int*)(t1 + 20))->sub_000ABC70();
    }
    t3 = ((Object*)a1)->sub_000CE970();
    t4 = *(int*)(*(int*)(t3 + 20) + 100);
    t5 = *(int*)(t3 + 20);
    if (r_esi) {
        r_esi = ((Object*)r_esi)->sub_00217380();
        if (!r_esi) goto L_4E;
        ((Object*)r_esi)->sub_00219DE0(t5, ((Object*)a1)->sub_000185A0(t4));
    }
L_4E:
    return 0;
}

