// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/GenericVehicleCamera.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 7 functions matched (42.86%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] GenericVehicleCamera::vfunc_00 (0x0013CB70, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// GenericVehicleCamera::vfunc_00 (0x0013CB70, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0040A3F4[];

class GenericVehicleCamera
{
public:
    virtual void* vfunc_00();
};

void* GenericVehicleCamera::vfunc_00()
{
    return DAT_0040A3F4;
}

// ============================================================================
// [VERIFIED] GenericVehicleCamera::vfunc_41 (0x0013CC00, 33 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns a copy of a three-number vector kept in an object.
// ============================================================================
// bin: proto
// va: 0x0013CC00
// what: Returns a copy of a three-number vector kept in an object.
// tool: Claude Opus 5.5 (transplanted from xb:0x000E7920, nearest by portal/tools/similar.py)
// sub_0013CC00 (0x0013CC00, 30 bytes)

struct Struct_0013CC00
{
    float m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
};

class Class_0013CC00
{
public:
    Struct_0013CC00 sub_0013CC00() const;

    char m_pad00[0x144];
    Struct_0013CC00 m_Field144; // +0x144
};

// Returns the stored vector by value.
Struct_0013CC00 Class_0013CC00::sub_0013CC00() const
{
    return m_Field144;
}

// ============================================================================
// [VERIFIED] GenericVehicleCamera::vfunc_01 (0x0013CF00, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// GenericVehicleCamera::vfunc_01 (0x0013CF00, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00391514[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_00135B10(void);

class GenericVehicleCamera
{
public:
    virtual void vfunc_00();
    virtual GenericVehicleCamera* vfunc_01(int a1);
};

GenericVehicleCamera* GenericVehicleCamera::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_00391514;
    sub_00135B10();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

