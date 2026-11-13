// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/Mod_StayInVehicle.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AICommandMods::Mod_StayInVehicle::vfunc_01 (0x001349A0, 26 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AICommandMods::Mod_StayInVehicle::vfunc_01 (0x001349A0, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace AICommandMods {

class Mod_StayInVehicle
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1, int a2);
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

int Mod_StayInVehicle::vfunc_01(int a1, int a2)
{
    m_Field08 = *(int*)(a2 + 412);
    *(int*)(a2 + 412) = 4;
    return a2;
}

}

// ============================================================================
// [VERIFIED] AICommandMods::Mod_StayInVehicle::vfunc_03 (0x001349C0, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AICommandMods::Mod_StayInVehicle::vfunc_03 (0x001349C0, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace AICommandMods {

class Mod_StayInVehicle
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03(int a1, int a2);
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

int Mod_StayInVehicle::vfunc_03(int a1, int a2)
{
    int t1;

    t1 = m_Field08;
    *(int*)(a2 + 412) = m_Field08;
    return t1;
}

}

