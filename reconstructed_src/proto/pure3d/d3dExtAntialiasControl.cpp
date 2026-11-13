// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, pure3d/d3dExtAntialiasControl.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 4 functions matched (25.00%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::d3dExtAntialiasControl::vfunc_03 (0x00236EF0, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dExtVisibilityTest::vfunc_02 (0x002680E0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x00236EF0
// what: Calls one other function and does nothing else.
// tool: Claude Fable 5.2 (look-alike of 0x00054F90, names and addresses swapped)
// pure3d::d3dExtAntialiasControl::vfunc_03 (0x00236EF0, 5 bytes)
extern "C" void __cdecl sub_00318CE0(void);

namespace pure3d {

class d3dExtAntialiasControl
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_03();
};

void d3dExtAntialiasControl::vfunc_03()
{
    sub_00318CE0();
}

}

