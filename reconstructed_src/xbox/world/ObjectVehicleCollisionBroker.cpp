// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, world/ObjectVehicleCollisionBroker.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ObjectVehicleCollisionBroker::vfunc_00 (0x0001D080, 69 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ObjectVehicleCollisionBroker::vfunc_00 (0x0001D080, 69 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12(int, int);
    int sub_000ABC70();
    int sub_000CE970();
    int sub_00217380();
};

class ObjectVehicleCollisionBroker
{
public:
    virtual void vfunc_00(int a1);
    void sub_0001CF90(int, int, int);
};

void ObjectVehicleCollisionBroker::vfunc_00(int a1)
{
    int t1, t2, t3;

    t1 = ((Object*)a1)->sub_000CE970();
    if (*(int*)(t1 + 20)) {
        t2 = ((Object*)*(int*)(t1 + 20))->sub_000ABC70();
        if (!t2) goto L_34;
        t3 = ((Object*)t2)->sub_00217380();
        if (!t3) goto L_34;
        ((Object*)t3)->vfunc_12(a1, 0);
    }
L_34:
    sub_0001CF90(a1, 1, 0);
}

