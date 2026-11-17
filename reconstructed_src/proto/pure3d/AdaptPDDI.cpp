// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, pure3d/AdaptPDDI.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::AdaptPDDI::vfunc_00 (0x0024EB80, 14 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::AdaptPDDI::vfunc_00 (Proto 0x0024EB80, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001B7A10(int);

namespace pure3d {

class AdaptPDDI
{
public:
    virtual void vfunc_00(int a1);
};

void AdaptPDDI::vfunc_00(int a1)
{
    sub_001B7A10(a1);
}

}

// ============================================================================
// [VERIFIED] pure3d::AdaptPDDI::vfunc_02 (0x0024EB90, 26 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::AdaptPDDI::vfunc_02 (Proto 0x0024EB90, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00200120(int, int, int);

namespace pure3d {

class AdaptPDDI
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(int a1, int a2, int a3);
};

void AdaptPDDI::vfunc_02(int a1, int a2, int a3)
{
    sub_00200120(a1, a2, a3);
}

}

