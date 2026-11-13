// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/StatePropTemplate.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] StatePropTemplate::vfunc_00 (0x001D6F70, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// StatePropTemplate::vfunc_00 (0x001D6F70, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0042543C[];

class StatePropTemplate
{
public:
    virtual void* vfunc_00();
};

void* StatePropTemplate::vfunc_00()
{
    return DAT_0042543C;
}

// ============================================================================
// [VERIFIED] StatePropTemplate::vfunc_01 (0x001D71B0, 52 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as FireTemplate::vfunc_01 (0x00188930), which was matched first;
// its addresses and names were swapped for this function's.
// StatePropTemplate::vfunc_01 (0x001D71B0, 52 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field24
{
    void sub_0007D7F0();
};

extern "C" char DAT_0037F29C[];
extern "C" char DAT_003A8F94[];
extern "C" void __cdecl sub_00025160(int);

class StatePropTemplate
{
public:
    virtual void vfunc_00();
    virtual StatePropTemplate* vfunc_01(int a1);
    void sub_00029C00();
    char m_pad04[0x20];
    Field24 m_Field24; // +0x24
};

StatePropTemplate* StatePropTemplate::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003A8F94;
    m_Field24.sub_0007D7F0();
    *(int*)this = (int)DAT_0037F29C;
    sub_00029C00();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

