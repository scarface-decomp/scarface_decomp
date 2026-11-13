// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/d3dFBEffectsShader.cpp (5 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 5 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::d3dFBEffectsShader::vfunc_04 (0x0029F440, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::d3dFBEffectsShader::vfunc_04 (0x0029F440, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0045EDF8;

namespace pure3d {

class d3dFBEffectsShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual int vfunc_04();
};

int d3dFBEffectsShader::vfunc_04()
{
    return DAT_0045EDF8;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dFBEffectsShader::vfunc_18 (0x0029F570, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dFBEffectsShader::vfunc_18 (0x0029F570, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0045EE58[];

namespace pure3d {

class d3dFBEffectsShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_18();
};

void* d3dFBEffectsShader::vfunc_18()
{
    return DAT_0045EE58;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dFBEffectsShader::vfunc_17 (0x0029F580, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dFBEffectsShader::vfunc_17 (0x0029F580, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0045EE88[];

namespace pure3d {

class d3dFBEffectsShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_17();
};

void* d3dFBEffectsShader::vfunc_17()
{
    return DAT_0045EE88;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dFBEffectsShader::vfunc_16 (0x0029F590, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dFBEffectsShader::vfunc_16 (0x0029F590, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0045EE10[];

namespace pure3d {

class d3dFBEffectsShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_16();
};

void* d3dFBEffectsShader::vfunc_16()
{
    return DAT_0045EE10;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dFBEffectsShader::vfunc_03 (0x0029F5F0, 39 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as fight::Param::vfunc_03 (0x00239CE0), which was matched first;
// its addresses and names were swapped for this function's.
extern "C" char DAT_003D9CD4[];
extern "C" void __cdecl sub_00027600(void* p);

namespace pure3d {

class d3dFBEffectsShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual d3dFBEffectsShader* vfunc_03(unsigned int flags);
    void sub_0029A500();
};

#pragma optimize("y", off)
d3dFBEffectsShader* d3dFBEffectsShader::vfunc_03(unsigned int flags)
{
    *(void**)this = DAT_003D9CD4;
    sub_0029A500();
    if (flags & 1)
        sub_00027600(this);
    return this;
}
#pragma optimize("", on)

}

