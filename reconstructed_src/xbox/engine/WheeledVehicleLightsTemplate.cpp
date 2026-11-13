// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/WheeledVehicleLightsTemplate.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] WheeledVehicleLightsTemplate::vfunc_04 (0x00211630, 25 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as RandomWaterObjectTemplate::vfunc_04 (0x00200C00), which was matched first;
// its addresses and names were swapped for this function's.
// WheeledVehicleLightsTemplate::vfunc_04 (0x00211630, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field24
{
    void sub_002A9290();
};

extern "C" void __stdcall sub_0002B700(int);

class WheeledVehicleLightsTemplate
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int a1);
    char m_pad04[0x20];
    Field24 m_Field24; // +0x24
};

void WheeledVehicleLightsTemplate::vfunc_04(int a1)
{
    sub_0002B700(a1);
    m_Field24.sub_002A9290();
}

// ============================================================================
// [VERIFIED] WheeledVehicleLightsTemplate::vfunc_00 (0x00211730, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// WheeledVehicleLightsTemplate::vfunc_00 (0x00211730, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0044AFF8[];

class WheeledVehicleLightsTemplate
{
public:
    virtual void* vfunc_00();
};

void* WheeledVehicleLightsTemplate::vfunc_00()
{
    return DAT_0044AFF8;
}

