// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, pure3d/d3dPrimBuffer.cpp (7 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 7 of 10 functions matched (70.00%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::d3dPrimBuffer::vfunc_05 (0x0026FDF0, 15 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x0026FDF0
// what: 
// tool: the portal's starter code (no AI)

// pure3d::d3dPrimBuffer::vfunc_05 (Proto 0x0026FDF0, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d {

class d3dPrimBuffer
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual bool vfunc_05(int a1);
    char m_pad04[0x30];
    bool m_Field34; // +0x34
};

bool d3dPrimBuffer::vfunc_05(int a1)
{
    m_Field34 = false;
    *(bool*)(a1 + 4) = false;
    return false;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dPrimBuffer::vfunc_07 (0x0026FE00, 29 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::d3dPrimBuffer::vfunc_07 (Proto 0x0026FE00, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0025F5E0(int);

namespace pure3d {

class d3dPrimBuffer
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual int vfunc_07();
    char m_pad04[0x28];
    int m_Field2C; // +0x2C
    char m_pad30[0x5];
    bool m_Field35; // +0x35
};

int d3dPrimBuffer::vfunc_07()
{
    int t1;

    t1 = *(int*)(m_Field2C + 4);
    sub_0025F5E0(0);
    m_Field35 = true;
    return t1;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dPrimBuffer::vfunc_08 (0x0026FE20, 14 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::d3dPrimBuffer::vfunc_08 (Proto 0x0026FE20, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d {

class d3dPrimBuffer
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
    virtual int vfunc_08(int a1);
    char m_pad04[0x20];
    int m_Field24; // +0x24
    char m_pad28[0xD];
    bool m_Field35; // +0x35
};

int d3dPrimBuffer::vfunc_08(int a1)
{
    m_Field35 = false;
    m_Field24 = a1;
    return a1;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dPrimBuffer::vfunc_10 (0x0026FE30, 18 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::d3dPrimBuffer::vfunc_10 (Proto 0x0026FE30, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char sub_00020001[];

namespace pure3d {

class d3dPrimBuffer
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
    virtual bool vfunc_10(int a1);
};

bool d3dPrimBuffer::vfunc_10(int a1)
{
    return a1 == (int)sub_00020001;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dPrimBuffer::vfunc_11 (0x0026FE50, 38 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::d3dPrimBuffer::vfunc_11 (Proto 0x0026FE50, 38 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0025F5E0(int);
extern "C" int __stdcall sub_0031AA30(int, int);

namespace pure3d {

class d3dPrimBuffer
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
    virtual int vfunc_11(int a1);
    char m_pad04[0x2C];
    int m_Field30; // +0x30
    char m_pad34[0x2];
    bool m_Field36; // +0x36
};

int d3dPrimBuffer::vfunc_11(int a1)
{
    int t2;

    t2 = sub_0031AA30(m_Field30, 0);
    sub_0025F5E0(0);
    m_Field36 = true;
    return t2;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dPrimBuffer::vfunc_12 (0x0026FE80, 5 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::d3dPrimBuffer::vfunc_12 (Proto 0x0026FE80, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d {

class d3dPrimBuffer
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
    char m_pad04[0x32];
    bool m_Field36; // +0x36
};

void d3dPrimBuffer::vfunc_12()
{
    m_Field36 = false;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dPrimBuffer::vfunc_03 (0x002703B0, 94 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::d3dPrimBuffer::vfunc_03 (Proto 0x002703B0, 94 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B418C[];
extern "C" char DAT_003B41D4[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_00262520(int);
extern "C" void __stdcall sub_003174F0(int);

namespace pure3d {

class d3dPrimBuffer
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual d3dPrimBuffer* vfunc_03(int a1);
    void sub_00264490();
    char m_pad04[0x28];
    int m_Field2C; // +0x2C
    int m_Field30; // +0x30
};

d3dPrimBuffer* d3dPrimBuffer::vfunc_03(int a1)
{
    int t1, t4;

    t1 = m_Field2C;
    *(int*)this = (int)DAT_003B41D4;
    if (m_Field2C) {
        sub_00262520(t1);
        sub_003174F0(m_Field2C);
    }
    t4 = m_Field30;
    if (m_Field30) {
        sub_00262520(t4);
        sub_003174F0(m_Field30);
    }
    *(int*)this = (int)DAT_003B418C;
    sub_00264490();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

}

