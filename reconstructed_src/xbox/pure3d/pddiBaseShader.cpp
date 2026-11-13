// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/pddiBaseShader.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::pddiBaseShader::vfunc_03 (0x0029A930, 65 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::pddiBaseShader::vfunc_03 (0x0029A930, 65 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

extern "C" char DAT_003D9540[];
extern "C" char DAT_003D9574[];
extern "C" int DAT_004BD50C;
extern "C" void __cdecl sub_00027600(int);

namespace pure3d {

class pddiBaseShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual pddiBaseShader* vfunc_03(int a1);
    void sub_002A06C0();
};

pddiBaseShader* pddiBaseShader::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_003D9574;
    if (DAT_004BD50C == (int)this) {
        DAT_004BD50C = 0;
    }
    *(int*)this = (int)DAT_003D9540;
    sub_002A06C0();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

}

