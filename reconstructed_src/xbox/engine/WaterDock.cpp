// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/WaterDock.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] WaterDock::vfunc_03 (0x0014C530, 70 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// WaterDock::vfunc_03 (0x0014C530, 70 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0014CEE0();
};

extern "C" char DAT_003B2D8C[];
extern "C" void __cdecl sub_00027600(int);
extern "C" int __stdcall sub_0014D670(int);
extern "C" void __cdecl sub_0023F7A0(int);

class WaterDock
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual WaterDock* vfunc_03(int a1);
    void sub_002A6940();
    char m_pad04[0x14];
    int m_Field18; // +0x18
};

WaterDock* WaterDock::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_003B2D8C;
    sub_00027600(m_Field18);
    m_Field18 = 0;
    ((Object*)sub_0014D670((int)this))->sub_0014CEE0();
    sub_002A6940();
    if (a1 & 1) {
        sub_0023F7A0((int)this);
    }
    return this;
}

