// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/PathGroup.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 3 functions matched (66.67%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] PathGroup::vfunc_00 (0x00115FA0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns PathGroup's static class record (ConcreteClassRep<PathGroup>), the object's run-time type.
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// PathGroup::vfunc_00 (0x00115FA0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004286FC[];

class PathGroup
{
public:
    virtual void* vfunc_00();
};

void* PathGroup::vfunc_00()
{
    return DAT_004286FC;
}

// ============================================================================
// [VERIFIED] PathGroup::vfunc_01 (0x00116170, 48 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: PathGroup's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// Same machine code as PathGroup::vfunc_01 (Proto 0x000FCA30), which was matched first;
// its addresses and names were swapped for this function's.
// PathGroup::vfunc_01 (Proto 0x00116170, 48 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field54
{
    void sub_00115F20();
};

extern "C" void __cdecl sub_00027600(int);

class PathGroup
{
public:
    virtual void vfunc_00();
    virtual PathGroup* vfunc_01(int a1);
    void sub_000290C0();
    char m_pad04[0x40];
    Field54 m_Field44; // +0x44
    char m_pad45[0xF];
    Field54 m_Field54; // +0x54
};

PathGroup* PathGroup::vfunc_01(int a1)
{
    m_Field54.sub_00115F20();
    m_Field44.sub_00115F20();
    sub_000290C0();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

