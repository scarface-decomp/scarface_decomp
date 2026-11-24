// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/d3dExtVertexProgram.cpp (5 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 5 of 8 functions matched (62.50%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::d3dExtVertexProgram::vfunc_05 (0x002681E0, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::d3dExtVertexProgram::vfunc_05 (0x002681E0, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

namespace pure3d {

class d3dExtVertexProgram
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual int vfunc_05(int a1, int a2);
};

int d3dExtVertexProgram::vfunc_05(int a1, int a2)
{
    *(int*)(a1 + 60) = a2;
    return a2;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dExtVertexProgram::vfunc_06 (0x002681F0, 25 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::d3dExtVertexProgram::vfunc_06 (0x002681F0, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

namespace pure3d {

class d3dExtVertexProgram
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual int vfunc_06(int a1);
    int m_Field04; // +0x04
};

int d3dExtVertexProgram::vfunc_06(int a1)
{
    int t1;

    t1 = m_Field04;
    *(int*)(*(int*)(m_Field04 + 720) + 340) = a1;
    return t1;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dExtVertexProgram::vfunc_08 (0x00268240, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::d3dExtVertexProgram::vfunc_08 (0x00268240, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

struct Object
{
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
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21(int);
};

namespace pure3d {

class d3dExtVertexProgram
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
    virtual void vfunc_08(int a1, int a2);
};

void d3dExtVertexProgram::vfunc_08(int a1, int a2)
{
    ((Object*)a1)->vfunc_21(a2);
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dExtVertexProgram::vfunc_01 (0x00268260, 18 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Forwards two arguments to sub_0029BDA0 on the object at *(m_Field04 + 0x2D4).
// ============================================================================
// bin: xb
// va: 0x00268260
// what: Forwards two arguments to sub_0029BDA0 on the object at *(m_Field04 + 0x2D4).
// tool: Gemini 4 Neon

#pragma optimize("y", off)

struct Object_00268260
{
    void sub_0029BDA0(int a1, int a2);
};

namespace pure3d {

class d3dExtVertexProgram
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01(int a1, int a2);
    int m_Field04; // +0x04
};

void d3dExtVertexProgram::vfunc_01(int a1, int a2)
{
    ((Object_00268260*)*(int*)(m_Field04 + 0x2D4))->sub_0029BDA0(a1, a2);
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dExtVertexProgram::vfunc_03 (0x00268280, 18 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: xb
// va: 0x00268280
// what: 
// tool: the portal's starter code (no AI)

// pure3d::d3dExtVertexProgram::vfunc_03 (0x00268280, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

struct Object
{
    void sub_0029BAC0(int);
};

namespace pure3d {

class d3dExtVertexProgram
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03(int a1);
    int m_Field04; // +0x04
};

void d3dExtVertexProgram::vfunc_03(int a1)
{
    ((Object*)*(int*)(m_Field04 + 724))->sub_0029BAC0(a1);
}

}

