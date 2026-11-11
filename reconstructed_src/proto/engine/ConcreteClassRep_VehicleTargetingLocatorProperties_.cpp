// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/ConcreteClassRep_VehicleTargetingLocatorProperties_.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 2 functions matched (50.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ConcreteClassRep<VehicleTargetingLocatorProperties>::vfunc_02 (0x001C9510, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as ConcreteClassRep<CollisionSurfaceType>::vfunc_02 (0x00011450), which was matched first;
// its addresses and names were swapped for this function's.
// ConcreteClassRep<VehicleTargetingLocatorProperties>::vfunc_02 (0x001C9510, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0041DE94;
extern "C" int DAT_0041DE98;
extern "C" char DAT_003F6D24[];
extern "C" int DAT_003F6D48;
extern "C" void __cdecl sub_001C9340(void);
extern "C" void __cdecl sub_000660D0(int, int);

class VehicleTargetingLocatorProperties;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
};

template <> void ConcreteClassRep<VehicleTargetingLocatorProperties>::vfunc_02()
{
    sub_000660D0(DAT_003F6D48, DAT_0041DE94);
    DAT_0041DE98 = (int)DAT_003F6D24;
    sub_001C9340();
}

