// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, pure3d/pddiBaseShader.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::pddiBaseShader::vfunc_03 (0x0025DE60, 62 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::pddiBaseShader::vfunc_03 (Proto 0x0025DE60, 62 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B2F30[];
extern "C" char DAT_003B2F64[];
extern "C" int DAT_0048E154;
extern "C" void __cdecl sub_00025160(int);

namespace pure3d {

class pddiBaseShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual pddiBaseShader* vfunc_03(int a1);
    void sub_00264490();
};

pddiBaseShader* pddiBaseShader::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_003B2F64;
    if (DAT_0048E154 == (int)this) {
        DAT_0048E154 = 0;
    }
    *(int*)this = (int)DAT_003B2F30;
    sub_00264490();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

}

