// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/WaterObstacle.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] WaterObstacle::vfunc_03 (0x0014F190, 51 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: WaterObstacle's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// Same machine code as WaterObstacle::vfunc_03 (Proto 0x001328F0), which was matched first;
// its addresses and names were swapped for this function's.
// WaterObstacle::vfunc_03 (Proto 0x0014F190, 51 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0014CEA0();
};

extern "C" char DAT_003B2E18[];
extern "C" int __stdcall sub_0014D670(int);
extern "C" void __cdecl sub_0023F7A0(int);

class WaterObstacle
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual WaterObstacle* vfunc_03(int a1);
    void sub_002A6940();
};

WaterObstacle* WaterObstacle::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_003B2E18;
    ((Object*)sub_0014D670((int)this))->sub_0014CEA0();
    sub_002A6940();
    if (a1 & 1) {
        sub_0023F7A0((int)this);
    }
    return this;
}

