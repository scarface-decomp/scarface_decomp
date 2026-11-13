// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/StatePropPhysicsTemplate.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 3 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] StatePropPhysicsTemplate::vfunc_05 (0x001D6E70, 25 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as RandomWaterObjectTemplate::vfunc_04 (0x00200C00), which was matched first;
// its addresses and names were swapped for this function's.
// StatePropPhysicsTemplate::vfunc_05 (0x001D6E70, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field24
{
    void sub_0007CD80();
};

extern "C" void __stdcall sub_00028C40(int);

class StatePropPhysicsTemplate
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_05(int a1);
    char m_pad04[0x20];
    Field24 m_Field24; // +0x24
};

void StatePropPhysicsTemplate::vfunc_05(int a1)
{
    sub_00028C40(a1);
    m_Field24.sub_0007CD80();
}

// ============================================================================
// [VERIFIED] StatePropPhysicsTemplate::vfunc_00 (0x001D6ED0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// StatePropPhysicsTemplate::vfunc_00 (0x001D6ED0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004253F8[];

class StatePropPhysicsTemplate
{
public:
    virtual void* vfunc_00();
};

void* StatePropPhysicsTemplate::vfunc_00()
{
    return DAT_004253F8;
}

// ============================================================================
// [VERIFIED] StatePropPhysicsTemplate::vfunc_01 (0x001D6EE0, 52 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as FireTemplate::vfunc_01 (0x00188930), which was matched first;
// its addresses and names were swapped for this function's.
// StatePropPhysicsTemplate::vfunc_01 (0x001D6EE0, 52 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field24
{
    void sub_001B7A10();
};

extern "C" char DAT_0037F29C[];
extern "C" char DAT_003A8F1C[];
extern "C" void __cdecl sub_00025160(int);

class StatePropPhysicsTemplate
{
public:
    virtual void vfunc_00();
    virtual StatePropPhysicsTemplate* vfunc_01(int a1);
    void sub_00029C00();
    char m_pad04[0x20];
    Field24 m_Field24; // +0x24
};

StatePropPhysicsTemplate* StatePropPhysicsTemplate::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003A8F1C;
    m_Field24.sub_001B7A10();
    *(int*)this = (int)DAT_0037F29C;
    sub_00029C00();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

