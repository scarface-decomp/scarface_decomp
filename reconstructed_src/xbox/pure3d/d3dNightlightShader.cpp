// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/d3dNightlightShader.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 5 functions matched (60.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::d3dNightlightShader::vfunc_04 (0x002C6140, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dVehicleShader::vfunc_04 (0x002829C0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x002C6140
// what: Returns the address of a fixed block in the game's data.
// tool: Claude Fable 5.2 (look-alike of 0x0004A760, names and addresses swapped)
// pure3d::d3dNightlightShader::vfunc_04 (0x002C6140, 6 bytes)
extern "C" char DAT_003D5848[];

namespace pure3d {

class d3dNightlightShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void* vfunc_04();
};

void* d3dNightlightShader::vfunc_04()
{
    return DAT_003D5848;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dNightlightShader::vfunc_23 (0x002C6320, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dNightlightShader::vfunc_23 (0x002C6320, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003D97BC[];

namespace pure3d {

class d3dNightlightShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_23();
};

void* d3dNightlightShader::vfunc_23()
{
    return DAT_003D97BC;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dNightlightShader::vfunc_03 (0x002C6330, 39 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as fight::Param::vfunc_03 (0x00239CE0), which was matched first;
// its addresses and names were swapped for this function's.
extern "C" char DAT_003DBB94[];
extern "C" void __cdecl sub_00027600(void* p);

namespace pure3d {

class d3dNightlightShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual d3dNightlightShader* vfunc_03(unsigned int flags);
    void sub_0029F6D0();
};

#pragma optimize("y", off)
d3dNightlightShader* d3dNightlightShader::vfunc_03(unsigned int flags)
{
    *(void**)this = DAT_003DBB94;
    sub_0029F6D0();
    if (flags & 1)
        sub_00027600(this);
    return this;
}
#pragma optimize("", on)

}

