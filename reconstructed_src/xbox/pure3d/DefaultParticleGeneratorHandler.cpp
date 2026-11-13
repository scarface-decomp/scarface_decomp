// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/DefaultParticleGeneratorHandler.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 2 functions matched (50.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::DefaultParticleGeneratorHandler::vfunc_04 (0x00270AC0, 32 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::DefaultParticleGeneratorHandler::vfunc_04 (0x00270AC0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

extern "C" char sub_00015B00[];
extern "C" char sub_00015B02[];

namespace pure3d {

class DefaultParticleGeneratorHandler
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual bool vfunc_04(int a1);
};

bool DefaultParticleGeneratorHandler::vfunc_04(int a1)
{
    if ((unsigned int)a1 >= (unsigned int)sub_00015B00) {
        if ((unsigned int)a1 > (unsigned int)sub_00015B02) goto L_1A;
        return true;
    }
L_1A:
    return false;
}

}

