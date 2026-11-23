// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/VehicleDropObjectProperties.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] VehicleDropObjectProperties::vfunc_05 (0x001C5130, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 /arch:SSE
// ============================================================================
// bin: proto
// va: 0x001C5130
// what: 
// tool: the portal's starter code (no AI)

// VehicleDropObjectProperties::vfunc_05 (Proto 0x001C5130, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0041AFBC;
extern "C" void __stdcall sub_00028C40(int);

class VehicleDropObjectProperties
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int a1);
    char m_pad04[0x40];
    float m_Field44; // +0x44
    float m_Field48; // +0x48
};

void VehicleDropObjectProperties::vfunc_05(int a1)
{
    sub_00028C40(a1);
    m_Field44 = m_Field48 * DAT_0041AFBC;
}

// ============================================================================
// [VERIFIED] VehicleDropObjectProperties::vfunc_00 (0x001C52E0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// VehicleDropObjectProperties::vfunc_00 (0x001C52E0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0041BA94[];

class VehicleDropObjectProperties
{
public:
    virtual void* vfunc_00();
};

void* VehicleDropObjectProperties::vfunc_00()
{
    return DAT_0041BA94;
}

