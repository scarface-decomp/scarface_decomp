// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/d3dDecalShader.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 4 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::d3dDecalShader::vfunc_04 (0x002C5660, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dVehicleShader::vfunc_04 (0x002829C0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x002C5660
// what: Returns the address of a fixed block in the game's data.
// tool: Claude Fable 5.2 (look-alike of 0x0004A760, names and addresses swapped)
// pure3d::d3dDecalShader::vfunc_04 (0x002C5660, 6 bytes)
extern "C" char DAT_003D585C[];

namespace pure3d {

class d3dDecalShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void* vfunc_04();
};

void* d3dDecalShader::vfunc_04()
{
    return DAT_003D585C;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dDecalShader::vfunc_14 (0x002C5670, 88 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: xb
// va: 0x002C5670
// what: 
// tool: the portal's starter code (no AI)

// pure3d::d3dDecalShader::vfunc_14 (0x002C5670, 88 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

extern "C" bool DAT_004BD4B4;
extern "C" int sub_0033A678;
extern "C" int sub_0033A6AC;
extern "C" int sub_0033AA1C;
extern "C" void __stdcall sub_0029FEE0(int);

namespace pure3d {

class d3dDecalShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14(int a1);
    char m_pad04[0x14];
    int m_Field18; // +0x18
};

void d3dDecalShader::vfunc_14(int a1)
{
    int t2;

    sub_0029FEE0(a1);
    if (m_Field18 == 1) {
        sub_0033A678 |= 1;
        sub_0033A6AC = 4;
    }
    if (DAT_004BD4B4) {
        t2 = sub_0033A678 | 12288;
        DAT_004BD4B4 = false;
        sub_0033A678 = t2;
        sub_0033AA1C = 0;
    }
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dDecalShader::vfunc_13 (0x002C56D0, 38 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dDecalShader::vfunc_13 (Proto 0x00288790), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dDecalShader::vfunc_13 (Proto 0x002C56D0, 38 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int sub_0033A678;
extern "C" int sub_0033A6AC;
extern "C" void __cdecl sub_0029FD70(void);

namespace pure3d {

class d3dDecalShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual int vfunc_13();
    char m_pad04[0x14];
    int m_Field18; // +0x18
};

int d3dDecalShader::vfunc_13()
{
    int r_eax;

    sub_0029FD70();
    r_eax = 1;
    if (m_Field18 == 1) {
        sub_0033A678 |= 1;
        sub_0033A6AC = 0;
    }
    return r_eax;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dDecalShader::vfunc_03 (0x002C5700, 39 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as fight::Param::vfunc_03 (0x00239CE0), which was matched first;
// its addresses and names were swapped for this function's.
extern "C" char DAT_003DBA7C[];
extern "C" void __cdecl sub_00027600(void* p);

namespace pure3d {

class d3dDecalShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual d3dDecalShader* vfunc_03(unsigned int flags);
    void sub_0029F6D0();
};

#pragma optimize("y", off)
d3dDecalShader* d3dDecalShader::vfunc_03(unsigned int flags)
{
    *(void**)this = DAT_003DBA7C;
    sub_0029F6D0();
    if (flags & 1)
        sub_00027600(this);
    return this;
}
#pragma optimize("", on)

}

