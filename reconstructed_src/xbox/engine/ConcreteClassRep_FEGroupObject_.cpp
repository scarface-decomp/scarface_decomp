// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/ConcreteClassRep_FEGroupObject_.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 2 functions matched (50.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ConcreteClassRep<FEGroupObject>::vfunc_02 (0x00024EF0, 64 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ConcreteClassRep<FEGroupObject>::vfunc_02 (0x00024EF0, 64 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0041AB84;
extern "C" int DAT_0041AB88;
extern "C" char DAT_0041AD1C[];
extern "C" char DAT_0041B5EC[];
extern "C" int DAT_0041B60C;
extern "C" char sub_00024C90[];
extern "C" char sub_00024CB0[];
extern "C" void __cdecl sub_00070520(int, int);
extern "C" void __cdecl sub_00073780(int, int, int, int, int, int, int, int, int);

class FEGroupObject;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
};

template <> void ConcreteClassRep<FEGroupObject>::vfunc_02()
{
    sub_00070520(DAT_0041B60C, DAT_0041AB84);
    DAT_0041AB88 = (int)DAT_0041B5EC;
    sub_00073780((int)DAT_0041AD1C, 8, 0, 0, 0, 0, 0, (int)sub_00024C90, (int)sub_00024CB0);
}

