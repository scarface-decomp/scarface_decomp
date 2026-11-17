// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, ai/AIActionExitVehicle.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AIActionExitVehicle::vfunc_02 (0x00120E00, 17 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AIActionExitVehicle::vfunc_02 (0x00120E00, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001759D0(int);
};

class AIActionExitVehicle
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

void AIActionExitVehicle::vfunc_02()
{
    ((Object*)m_Field08 + 744)->sub_001759D0(-1);
}

// ============================================================================
// [VERIFIED] AIActionExitVehicle::vfunc_08 (0x00120E20, 15 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AIActionExitVehicle::vfunc_08 (Proto 0x00105880), which was matched first;
// its addresses and names were swapped for this function's.
// AIActionExitVehicle::vfunc_08 (Proto 0x00120E20, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    int sub_001655C0();
};

struct Object
{
    void sub_000F5730();
};

class AIActionExitVehicle
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    char m_pad04[0x4];
    Field08* m_Field08; // +0x08
};

void AIActionExitVehicle::vfunc_08()
{
    ((Object*)m_Field08->sub_001655C0())->sub_000F5730();
}

