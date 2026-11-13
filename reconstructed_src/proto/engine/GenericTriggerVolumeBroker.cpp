// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/GenericTriggerVolumeBroker.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] GenericTriggerVolumeBroker::vfunc_00 (0x0001C210, 52 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as GenericTriggerVolumeBroker::vfunc_00 (0x0001CD70), which was matched first;
// its addresses and names were swapped for this function's.

struct Object
{
    void sub_0008C320(int);
    int sub_00056450();
    int sub_00026D50();
};

class GenericTriggerVolumeBroker
{
public:
    virtual bool vfunc_00(int a1);
};

bool GenericTriggerVolumeBroker::vfunc_00(int a1)
{
    int t2, t4;

    t2 = *(int*)(((Object*)a1)->sub_00056450() + 20);
    t4 = *(int*)(((Object*)a1)->sub_00026D50() + 20);
    if (t2) {
        if (!t4) goto L_2D;
        ((Object*)t2)->sub_0008C320(*(int*)(t4 + 16));
    }
L_2D:
    return 0;
}

