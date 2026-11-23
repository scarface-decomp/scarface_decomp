// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/VehicleArtTemplate.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 3 functions matched (66.67%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] VehicleArtTemplate::vfunc_00 (0x001D1040, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// VehicleArtTemplate::vfunc_00 (0x001D1040, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0041DE44[];

class VehicleArtTemplate
{
public:
    virtual void* vfunc_00();
};

void* VehicleArtTemplate::vfunc_00()
{
    return DAT_0041DE44;
}

// ============================================================================
// [VERIFIED] VehicleArtTemplate::vfunc_01 (0x001D12E0, 60 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: VehicleArtTemplate's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// VehicleArtTemplate::vfunc_01 (Proto 0x001D12E0, 60 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field24
{
    void sub_001B7A10();
};

struct Field34
{
    void sub_0009D1E0();
};

extern "C" char DAT_0037F29C[];
extern "C" char DAT_003A6F64[];
extern "C" void __cdecl sub_00025160(int);

class VehicleArtTemplate
{
public:
    virtual void vfunc_00();
    virtual VehicleArtTemplate* vfunc_01(int a1);
    void sub_00029C00();
    char m_pad04[0x20];
    Field24 m_Field24; // +0x24
    char m_pad25[0xF];
    Field34 m_Field34; // +0x34
};

VehicleArtTemplate* VehicleArtTemplate::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003A6F64;
    m_Field34.sub_0009D1E0();
    m_Field24.sub_001B7A10();
    *(int*)this = (int)DAT_0037F29C;
    sub_00029C00();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

