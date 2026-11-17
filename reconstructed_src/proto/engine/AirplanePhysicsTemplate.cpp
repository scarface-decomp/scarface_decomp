// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/AirplanePhysicsTemplate.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 3 functions matched (66.67%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AirplanePhysicsTemplate::vfunc_00 (0x001C4E80, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// AirplanePhysicsTemplate::vfunc_00 (0x001C4E80, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0041B958[];

class AirplanePhysicsTemplate
{
public:
    virtual void* vfunc_00();
};

void* AirplanePhysicsTemplate::vfunc_00()
{
    return DAT_0041B958;
}

// ============================================================================
// [VERIFIED] AirplanePhysicsTemplate::vfunc_01 (0x001C4E90, 49 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AirplanePhysicsTemplate::vfunc_01 (Proto 0x001C4E90, 49 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field204
{
    void sub_001B7A10();
};

extern "C" char DAT_003A57DC[];
extern "C" void __cdecl sub_00025160(int);

class AirplanePhysicsTemplate
{
public:
    virtual void vfunc_00();
    virtual AirplanePhysicsTemplate* vfunc_01(int a1);
    void sub_001D1AC0();
    char m_pad04[0x200];
    Field204 m_Field204; // +0x204
};

AirplanePhysicsTemplate* AirplanePhysicsTemplate::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003A57DC;
    m_Field204.sub_001B7A10();
    sub_001D1AC0();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

