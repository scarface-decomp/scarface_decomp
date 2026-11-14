// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, audio/d3dPrimBufferStream.cpp (8 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 8 of 16 functions matched (50.00%). NOT COMPLETE YET.
// The 8 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::d3dPrimBufferStream::vfunc_15 (0x002AD8C0, 3 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dPrimBufferStream::vfunc_15 (PC 0x00703DC0), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dPrimBufferStream::vfunc_15 (PC 0x002AD8C0, 3 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d {

class d3dPrimBufferStream
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
    virtual void vfunc_14();
    virtual void vfunc_15(int a1, int a2, int a3, int a4, int a5);
};

void d3dPrimBufferStream::vfunc_15(int a1, int a2, int a3, int a4, int a5)
{
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dPrimBufferStream::vfunc_09 (0x002AD9B0, 33 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::d3dPrimBufferStream::vfunc_09 (0x002AD9B0, 33 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

namespace pure3d {

class d3dPrimBufferStream
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
    virtual int vfunc_09(int a1, int a2, int a3);
    char m_pad04[0x40];
    int m_Field44; // +0x44
};

int d3dPrimBufferStream::vfunc_09(int a1, int a2, int a3)
{
    int t1;

    *(int*)m_Field44 = a1;
    *(int*)(m_Field44 + 4) = a2;
    t1 = m_Field44;
    *(int*)(m_Field44 + 8) = a3;
    return t1;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dPrimBufferStream::vfunc_10 (0x002AD9E0, 33 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::d3dPrimBufferStream::vfunc_10 (0x002AD9E0, 33 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

namespace pure3d {

class d3dPrimBufferStream
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
    virtual int vfunc_10(int a1, int a2, int a3);
    char m_pad04[0x44];
    int m_Field48; // +0x48
};

int d3dPrimBufferStream::vfunc_10(int a1, int a2, int a3)
{
    int t1;

    *(int*)m_Field48 = a1;
    *(int*)(m_Field48 + 4) = a2;
    t1 = m_Field48;
    *(int*)(m_Field48 + 8) = a3;
    return t1;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dPrimBufferStream::vfunc_11 (0x002ADA10, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::d3dPrimBufferStream::vfunc_11 (0x002ADA10, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

namespace pure3d {

class d3dPrimBufferStream
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
    virtual int vfunc_11(int a1, int a2);
    char m_pad04[0x2C];
    int m_Field30; // +0x30
};

int d3dPrimBufferStream::vfunc_11(int a1, int a2)
{
    int t1;

    t1 = m_Field30;
    *(int*)(m_Field30 + (a2 * 4)) = a1;
    return t1;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dPrimBufferStream::vfunc_13 (0x002ADA30, 29 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::d3dPrimBufferStream::vfunc_13 (0x002ADA30, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

namespace pure3d {

class d3dPrimBufferStream
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
    virtual int vfunc_13(float a1, float a2, int a3);
    char m_pad04[0x34];
    int m_Field38; // +0x38
};

int d3dPrimBufferStream::vfunc_13(float a1, float a2, int a3)
{
    *(float*)(m_Field38 + (a3 * 8)) = a1;
    *(float*)(m_Field38 + (a3 * 8) + 4) = a2;
    return a3;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dPrimBufferStream::vfunc_16 (0x002ADA50, 15 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::d3dPrimBufferStream::vfunc_16 (0x002ADA50, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

namespace pure3d {

class d3dPrimBufferStream
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
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual int vfunc_16(int a1);
    char m_pad04[0x30];
    int m_Field34; // +0x34
};

int d3dPrimBufferStream::vfunc_16(int a1)
{
    int t1;

    t1 = m_Field34;
    *(int*)m_Field34 = a1;
    return t1;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dPrimBufferStream::vfunc_22 (0x002ADB30, 61 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::d3dPrimBufferStream::vfunc_22 (0x002ADB30, 61 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

namespace pure3d {

class d3dPrimBufferStream
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01(int, int, int);
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
    virtual void vfunc_21();
    virtual void vfunc_22(int a1, int a2);
    void sub_002AD4B0();
    char m_pad04[0x20];
    int m_Field24; // +0x24
};

void d3dPrimBufferStream::vfunc_22(int a1, int a2)
{
    int t1;

    t1 = m_Field24;
    *(int*)m_Field24 = *(int*)a1;
    *(int*)(t1 + 4) = *(int*)(a1 + 4);
    *(int*)(t1 + 8) = *(int*)(a1 + 8);
    vfunc_01(*(int*)a2, *(int*)(a2 + 4), *(int*)(a2 + 8));
    sub_002AD4B0();
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dPrimBufferStream::vfunc_24 (0x002ADC40, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as renderer::InstanceRenderable::vfunc_10 (0x00054F90), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dPrimBufferStream::vfunc_24 (0x002ADC40, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_002AD4B0(void);

namespace pure3d {

class d3dPrimBufferStream
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
    virtual void vfunc_24();
};

void d3dPrimBufferStream::vfunc_24()
{
    sub_002AD4B0();
}

}

