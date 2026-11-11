// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, fe/MapHUD2.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 7 functions matched (28.57%). NOT COMPLETE YET.
// The 5 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] MapHUD2::vfunc_00 (0x001A64F0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// MapHUD2::vfunc_00 (0x001A64F0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004378BC[];

class MapHUD2
{
public:
    virtual void* vfunc_00();
};

void* MapHUD2::vfunc_00()
{
    return DAT_004378BC;
}

// ============================================================================
// [VERIFIED] MapHUD2::vfunc_01 (0x001A6F50, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Collidable::vfunc_03 (0x00011F20), which was matched first;
// its addresses and names were swapped for this function's.
// MapHUD2::vfunc_01 (0x001A6F50, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001A6500(void);
extern "C" void __cdecl sub_00027600(int);

class MapHUD2
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual MapHUD2* vfunc_01(int a1);
};

MapHUD2* MapHUD2::vfunc_01(int a1)
{
    sub_001A6500();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

