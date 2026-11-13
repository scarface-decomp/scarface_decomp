// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, core/XboxSaveDrive.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 21 functions matched (14.29%). NOT COMPLETE YET.
// The 18 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] core::XboxSaveDrive::vfunc_00 (0x002BF800, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_00 (0x002AAF50), which was matched first;
// its addresses and names were swapped for this function's.
// core::XboxSaveDrive::vfunc_00 (0x002BF800, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004BFE18[];
extern "C" void __cdecl sub_00283B80(int);

namespace core {

class XboxSaveDrive
{
public:
    virtual void vfunc_00();
};

void XboxSaveDrive::vfunc_00()
{
    sub_00283B80((int)DAT_004BFE18);
}

}

// ============================================================================
// [VERIFIED] core::XboxSaveDrive::vfunc_01 (0x002BF810, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_00 (0x002AAF50), which was matched first;
// its addresses and names were swapped for this function's.
// core::XboxSaveDrive::vfunc_01 (0x002BF810, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004BFE18[];
extern "C" void __cdecl sub_00283B70(int);

namespace core {

class XboxSaveDrive
{
public:
    virtual void vfunc_01();
};

void XboxSaveDrive::vfunc_01()
{
    sub_00283B70((int)DAT_004BFE18);
}

}

// ============================================================================
// [VERIFIED] core::XboxSaveDrive::vfunc_03 (0x002C00D0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_03 (0x00248820), which was matched first;
// its addresses and names were swapped for this function's.
// core::XboxSaveDrive::vfunc_03 (0x002C00D0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0045894C;
extern "C" void __cdecl sub_002444F0(int, int);
extern "C" void __cdecl sub_002BFD90(void);

namespace core {

class XboxSaveDrive
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual XboxSaveDrive* vfunc_03(int a1);
};

XboxSaveDrive* XboxSaveDrive::vfunc_03(int a1)
{
    sub_002BFD90();
    if (a1 & 1) {
        sub_002444F0(DAT_0045894C, (int)this);
    }
    return this;
}

}

