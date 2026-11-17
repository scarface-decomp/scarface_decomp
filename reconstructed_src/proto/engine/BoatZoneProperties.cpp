// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/BoatZoneProperties.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] BoatZoneProperties::vfunc_00 (0x001D3920, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// BoatZoneProperties::vfunc_00 (0x001D3920, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004212F4[];

class BoatZoneProperties
{
public:
    virtual void* vfunc_00();
};

void* BoatZoneProperties::vfunc_00()
{
    return DAT_004212F4;
}

// ============================================================================
// [VERIFIED] BoatZoneProperties::vfunc_05 (0x001D3930, 25 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// BoatZoneProperties::vfunc_05 (Proto 0x001D3930, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field64
{
    void sub_00092AF0();
};

extern "C" void __stdcall sub_001D3760(int);

class BoatZoneProperties
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int a1);
    char m_pad04[0x60];
    Field64 m_Field64; // +0x64
};

void BoatZoneProperties::vfunc_05(int a1)
{
    sub_001D3760(a1);
    m_Field64.sub_00092AF0();
}

