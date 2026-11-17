// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/Mod_UseVehicleExtentsForAccuracy.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AICommandMods::Mod_UseVehicleExtentsForAccuracy::vfunc_01 (0x00119620, 34 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AICommandMods::Mod_UseVehicleExtentsForAccuracy::vfunc_01 (Proto 0x00119620, 34 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00148D30();
};

namespace AICommandMods {

class Mod_UseVehicleExtentsForAccuracy
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01(int a1, int a2);
    char m_pad04[0x4];
    bool m_Field08; // +0x08
    bool m_Field09; // +0x09
};

void Mod_UseVehicleExtentsForAccuracy::vfunc_01(int a1, int a2)
{
    int t1;
    bool t2;

    t1 = ((Object*)a2)->sub_00148D30();
    t2 = m_Field08;
    m_Field09 = *(bool*)(t1 + 1528);
    *(bool*)(t1 + 1528) = t2;
}

}

// ============================================================================
// [VERIFIED] AICommandMods::Mod_UseVehicleExtentsForAccuracy::vfunc_03 (0x00119650, 25 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AICommandMods::Mod_UseVehicleExtentsForAccuracy::vfunc_03 (Proto 0x00119650, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00148D30();
};

namespace AICommandMods {

class Mod_UseVehicleExtentsForAccuracy
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03(int a1, int a2);
    char m_pad04[0x5];
    bool m_Field09; // +0x09
};

void Mod_UseVehicleExtentsForAccuracy::vfunc_03(int a1, int a2)
{
    *(bool*)(((Object*)a2)->sub_00148D30() + 1528) = m_Field09;
}

}

