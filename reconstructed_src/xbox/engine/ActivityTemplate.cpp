// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/ActivityTemplate.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 3 functions matched (66.67%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ActivityTemplate::vfunc_00 (0x0010EF70, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// ActivityTemplate::vfunc_00 (0x0010EF70, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00429134[];

class ActivityTemplate
{
public:
    virtual void* vfunc_00();
};

void* ActivityTemplate::vfunc_00()
{
    return DAT_00429134;
}

// ============================================================================
// [VERIFIED] ActivityTemplate::vfunc_01 (0x0010EF80, 48 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ActivityTemplate::vfunc_01 (0x0010EF80, 48 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field34
{
    void sub_002A9290();
};

extern "C" void __cdecl sub_00027600(int);

class ActivityTemplate
{
public:
    virtual void vfunc_00();
    virtual ActivityTemplate* vfunc_01(int a1);
    void sub_00029F90();
    char m_pad04[0x2C];
    Field34 m_Field30; // +0x30
    char m_pad31[0x3];
    Field34 m_Field34; // +0x34
};

ActivityTemplate* ActivityTemplate::vfunc_01(int a1)
{
    m_Field34.sub_002A9290();
    m_Field30.sub_002A9290();
    sub_00029F90();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

