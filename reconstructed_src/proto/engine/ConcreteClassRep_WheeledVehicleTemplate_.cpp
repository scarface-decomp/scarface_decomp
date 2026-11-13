// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/ConcreteClassRep_WheeledVehicleTemplate_.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 2 functions matched (50.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ConcreteClassRep<WheeledVehicleTemplate>::vfunc_02 (0x001D0EE0, 64 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as ConcreteClassRep<FEGroupObject>::vfunc_02 (0x00024EF0), which was matched first;
// its addresses and names were swapped for this function's.
// ConcreteClassRep<WheeledVehicleTemplate>::vfunc_02 (0x001D0EE0, 64 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004249F8;
extern "C" int DAT_004249FC;
extern "C" char DAT_00424830[];
extern "C" char DAT_00421454[];
extern "C" int DAT_00421478;
extern "C" char sub_001D0D10[];
extern "C" char sub_001D0D50[];
extern "C" void __cdecl sub_000660D0(int, int);
extern "C" void __cdecl sub_00069130(int, int, int, int, int, int, int, int, int);

class WheeledVehicleTemplate;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
};

template <> void ConcreteClassRep<WheeledVehicleTemplate>::vfunc_02()
{
    sub_000660D0(DAT_00421478, DAT_004249F8);
    DAT_004249FC = (int)DAT_00421454;
    sub_00069130((int)DAT_00424830, 8, 0, 0, 0, 0, 0, (int)sub_001D0D10, (int)sub_001D0D50);
}

