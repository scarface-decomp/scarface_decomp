// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/VehicleArtTemplate.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 3 functions matched (66.67%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] VehicleArtTemplate::vfunc_00 (0x0020C560, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// VehicleArtTemplate::vfunc_00 (0x0020C560, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00444584[];

class VehicleArtTemplate
{
public:
    virtual void* vfunc_00();
};

void* VehicleArtTemplate::vfunc_00()
{
    return DAT_00444584;
}

// ============================================================================
// [VERIFIED] VehicleArtTemplate::vfunc_01 (0x0020C800, 60 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as VehicleArtTemplate::vfunc_01 (Proto 0x001D12E0), which was matched first;
// its addresses and names were swapped for this function's.
// VehicleArtTemplate::vfunc_01 (Proto 0x0020C800, 60 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field24
{
    void sub_002A9290();
};

struct Field34
{
    void sub_000A9160();
};

extern "C" char DAT_0039FE34[];
extern "C" char DAT_003CD164[];
extern "C" void __cdecl sub_00027600(int);

class VehicleArtTemplate
{
public:
    virtual void vfunc_00();
    virtual VehicleArtTemplate* vfunc_01(int a1);
    void sub_0002C720();
    char m_pad04[0x20];
    Field24 m_Field24; // +0x24
    char m_pad25[0xF];
    Field34 m_Field34; // +0x34
};

VehicleArtTemplate* VehicleArtTemplate::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003CD164;
    m_Field34.sub_000A9160();
    m_Field24.sub_002A9290();
    *(int*)this = (int)DAT_0039FE34;
    sub_0002C720();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

