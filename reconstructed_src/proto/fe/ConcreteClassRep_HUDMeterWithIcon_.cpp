// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, fe/ConcreteClassRep_HUDMeterWithIcon_.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 2 functions matched (50.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ConcreteClassRep<HUDMeterWithIcon>::vfunc_02 (0x0018AA40, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as ConcreteClassRep<CollisionSurfaceType>::vfunc_02 (0x00011450), which was matched first;
// its addresses and names were swapped for this function's.
// ConcreteClassRep<HUDMeterWithIcon>::vfunc_02 (0x0018AA40, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00410788;
extern "C" int DAT_0041078C;
extern "C" char DAT_0041052C[];
extern "C" int DAT_00410550;
extern "C" void __cdecl sub_0018A8A0(void);
extern "C" void __cdecl sub_000660D0(int, int);

class HUDMeterWithIcon;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
};

template <> void ConcreteClassRep<HUDMeterWithIcon>::vfunc_02()
{
    sub_000660D0(DAT_00410550, DAT_00410788);
    DAT_0041078C = (int)DAT_0041052C;
    sub_0018A8A0();
}

