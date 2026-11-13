// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/AirplaneZoneProperties.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AirplaneZoneProperties::vfunc_00 (0x0020EA80, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// AirplaneZoneProperties::vfunc_00 (0x0020EA80, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00447980[];

class AirplaneZoneProperties
{
public:
    virtual void* vfunc_00();
};

void* AirplaneZoneProperties::vfunc_00()
{
    return DAT_00447980;
}

// ============================================================================
// [VERIFIED] AirplaneZoneProperties::vfunc_04 (0x0020EA90, 25 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as BoatZoneProperties::vfunc_04 (0x0020EA30), which was matched first;
// its addresses and names were swapped for this function's.
// AirplaneZoneProperties::vfunc_04 (0x0020EA90, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field60
{
    void sub_0009AE50();
};

extern "C" void __stdcall sub_0020E870(int);

class AirplaneZoneProperties
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int a1);
    char m_pad04[0x5C];
    Field60 m_Field60; // +0x60
};

void AirplaneZoneProperties::vfunc_04(int a1)
{
    sub_0020E870(a1);
    m_Field60.sub_0009AE50();
}

