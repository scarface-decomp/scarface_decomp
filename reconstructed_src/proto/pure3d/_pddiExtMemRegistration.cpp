// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, pure3d/_pddiExtMemRegistration.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::_pddiExtMemRegistration::vfunc_01 (0x00262C60, 12 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dExtTODFactor::vfunc_04 (Proto 0x00232B20), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::_pddiExtMemRegistration::vfunc_01 (Proto 0x00262C60, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0048E89C;

namespace pure3d {

class _pddiExtMemRegistration
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1);
};

int _pddiExtMemRegistration::vfunc_01(int a1)
{
    DAT_0048E89C = a1;
    return a1;
}

}

