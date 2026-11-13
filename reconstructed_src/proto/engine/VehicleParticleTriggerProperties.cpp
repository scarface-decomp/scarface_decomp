// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/VehicleParticleTriggerProperties.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 3 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] VehicleParticleTriggerProperties::vfunc_00 (0x001D3D40, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// VehicleParticleTriggerProperties::vfunc_00 (0x001D3D40, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004214AC[];

class VehicleParticleTriggerProperties
{
public:
    virtual void* vfunc_00();
};

void* VehicleParticleTriggerProperties::vfunc_00()
{
    return DAT_004214AC;
}

// ============================================================================
// [VERIFIED] VehicleParticleTriggerProperties::vfunc_05 (0x001D3D50, 25 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as BoatPitchClampProperties::vfunc_04 (0x00200E50), which was matched first;
// its addresses and names were swapped for this function's.
// VehicleParticleTriggerProperties::vfunc_05 (0x001D3D50, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field20
{
    void sub_0009C090();
};

extern "C" void __stdcall sub_00028C40(int);

class VehicleParticleTriggerProperties
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_05(int a1);
    char m_pad04[0x1C];
    Field20 m_Field20; // +0x20
};

void VehicleParticleTriggerProperties::vfunc_05(int a1)
{
    sub_00028C40(a1);
    m_Field20.sub_0009C090();
}

// ============================================================================
// [VERIFIED] VehicleParticleTriggerProperties::vfunc_01 (0x001D4260, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// VehicleParticleTriggerProperties::vfunc_01 (0x001D4260, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A7FCC[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_00029C00(void);

class VehicleParticleTriggerProperties
{
public:
    virtual void vfunc_00();
    virtual VehicleParticleTriggerProperties* vfunc_01(int a1);
};

VehicleParticleTriggerProperties* VehicleParticleTriggerProperties::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003A7FCC;
    sub_00029C00();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

