// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/d3dExtStaticShadowGen.cpp (6 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 6 of 8 functions matched (75.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::d3dExtStaticShadowGen::vfunc_12 (0x002A2B30, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::d3dExtStaticShadowGen::vfunc_12 (0x002A2B30, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

namespace pure3d {

class d3dExtStaticShadowGen
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
    virtual int vfunc_12(int a1);
    char m_pad04[0x38];
    int m_Field3C; // +0x3C
};

int d3dExtStaticShadowGen::vfunc_12(int a1)
{
    m_Field3C = a1;
    return a1;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dExtStaticShadowGen::vfunc_01 (0x002A3040, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::d3dExtStaticShadowGen::vfunc_01 (0x002A3040, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_002A2A40(void);

namespace pure3d {

class d3dExtStaticShadowGen
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    void sub_002A2AA0();
};

void d3dExtStaticShadowGen::vfunc_01()
{
    sub_002A2A40();
    sub_002A2AA0();
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dExtStaticShadowGen::vfunc_02 (0x002A3050, 73 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::d3dExtStaticShadowGen::vfunc_02 (0x002A3050, 73 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __stdcall sub_0032C6D0(int);

namespace pure3d {

class d3dExtStaticShadowGen
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02();
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    char m_pad0C[0x8];
    int m_Field14; // +0x14
    int m_Field18; // +0x18
};

int d3dExtStaticShadowGen::vfunc_02()
{
    int r_eax;

    r_eax = m_Field14;
    if (r_eax) {
        sub_0032C6D0(r_eax);
        m_Field14 = 0;
    }
    r_eax = m_Field18;
    if (r_eax) {
        sub_0032C6D0(r_eax);
        m_Field18 = 0;
    }
    r_eax = m_Field04;
    if (r_eax) {
        sub_0032C6D0(r_eax);
        m_Field04 = 0;
    }
    r_eax = m_Field08;
    if (r_eax) {
        r_eax = sub_0032C6D0(r_eax);
        m_Field08 = 0;
    }
    return r_eax;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dExtStaticShadowGen::vfunc_07 (0x002A3B40, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dExtVisibilityTest::vfunc_02 (0x002680E0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x002A3B40
// what: Calls one other function and does nothing else.
// tool: Claude Fable 5.2 (look-alike of 0x00054F90, names and addresses swapped)
// pure3d::d3dExtStaticShadowGen::vfunc_07 (0x002A3B40, 5 bytes)
extern "C" void __cdecl sub_002A3110(void);

namespace pure3d {

class d3dExtStaticShadowGen
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_07();
};

void d3dExtStaticShadowGen::vfunc_07()
{
    sub_002A3110();
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dExtStaticShadowGen::vfunc_08 (0x002A3B50, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dExtVisibilityTest::vfunc_02 (0x002680E0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x002A3B50
// what: Calls one other function and does nothing else.
// tool: Claude Fable 5.2 (look-alike of 0x00054F90, names and addresses swapped)
// pure3d::d3dExtStaticShadowGen::vfunc_08 (0x002A3B50, 5 bytes)
extern "C" void __cdecl sub_002A34A0(void);

namespace pure3d {

class d3dExtStaticShadowGen
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_08();
};

void d3dExtStaticShadowGen::vfunc_08()
{
    sub_002A34A0();
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dExtStaticShadowGen::vfunc_00 (0x002A4090, 33 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as fight::Branch::vfunc_03 (0x0023B160), which was matched first;
// its addresses and names were swapped for this function's.
extern "C" void __cdecl sub_00027600(void* p);

namespace pure3d {

class d3dExtStaticShadowGen
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual d3dExtStaticShadowGen* vfunc_00(unsigned int flags);
    void sub_002A30A0();
};

#pragma optimize("y", off)
d3dExtStaticShadowGen* d3dExtStaticShadowGen::vfunc_00(unsigned int flags)
{
    sub_002A30A0();
    if (flags & 1)
        sub_00027600(this);
    return this;
}
#pragma optimize("", on)

}

