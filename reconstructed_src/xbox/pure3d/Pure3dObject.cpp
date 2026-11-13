// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/Pure3dObject.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 8 functions matched (12.50%). NOT COMPLETE YET.
// The 7 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::frontend::Pure3dObject::vfunc_03 (0x0024A800, 46 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::frontend::Pure3dObject::vfunc_03 (0x0024A800, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

extern "C" char DAT_003D5054[];
extern "C" void __cdecl sub_0023F7A0(int);
extern "C" void __cdecl sub_0024A700(void);

namespace pure3d { namespace frontend {

class Pure3dObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual Pure3dObject* vfunc_03(int a1);
    void sub_002489A0();
};

Pure3dObject* Pure3dObject::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_003D5054;
    sub_0024A700();
    sub_002489A0();
    if (a1 & 1) {
        sub_0023F7A0((int)this);
    }
    return this;
}

} }

