// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/WheeledVehicleArtTemplate.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 3 functions matched (66.67%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] WheeledVehicleArtTemplate::vfunc_00 (0x00210FC0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// WheeledVehicleArtTemplate::vfunc_00 (0x00210FC0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004497E8[];

class WheeledVehicleArtTemplate
{
public:
    virtual void* vfunc_00();
};

void* WheeledVehicleArtTemplate::vfunc_00()
{
    return DAT_004497E8;
}

// ============================================================================
// [VERIFIED] WheeledVehicleArtTemplate::vfunc_01 (0x002110B0, 71 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// WheeledVehicleArtTemplate::vfunc_01 (0x002110B0, 71 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field148
{
    void sub_000C0AE0();
};

struct Field194
{
    void sub_000878B0();
};

extern "C" char DAT_003CEC34[];
extern "C" void __cdecl sub_00027600(int);

class WheeledVehicleArtTemplate
{
public:
    virtual void vfunc_00();
    virtual WheeledVehicleArtTemplate* vfunc_01(int a1);
    void sub_0020C530();
    char m_pad04[0x144];
    Field148 m_Field148; // +0x148
    char m_pad149[0x27];
    Field194 m_Field170; // +0x170
    char m_pad171[0x23];
    Field194 m_Field194; // +0x194
};

WheeledVehicleArtTemplate* WheeledVehicleArtTemplate::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003CEC34;
    m_Field194.sub_000878B0();
    m_Field170.sub_000878B0();
    m_Field148.sub_000C0AE0();
    sub_0020C530();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

