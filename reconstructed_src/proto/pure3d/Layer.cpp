// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, pure3d/Layer.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::frontend::Layer::vfunc_03 (0x0024ABC0, 36 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::frontend::Drawable::vfunc_03 (Proto 0x00206010), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::frontend::Layer::vfunc_03 (Proto 0x0024ABC0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B1B60[];
extern "C" void __cdecl sub_001FCF60(int);
extern "C" void __cdecl sub_00249530(void);

namespace pure3d { namespace frontend {

class Layer
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual Layer* vfunc_03(int a1);
};

Layer* Layer::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_003B1B60;
    sub_00249530();
    if (a1 & 1) {
        sub_001FCF60((int)this);
    }
    return this;
}

} }

