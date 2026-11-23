// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, audio/d3dPrimBufferStream.cpp (13 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 13 of 18 functions matched (72.22%). NOT COMPLETE YET.
// The 5 still to do are listed in their place in Original_Binary_Order_PC_1002.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::d3dPrimBufferStream::vfunc_15 (0x00703DC0, 3 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::d3dPrimBufferStream::vfunc_15 (PC 0x00703DC0, 3 bytes)
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
// [VERIFIED] pure3d::d3dPrimBufferStream::vfunc_24 (0x00703DD0, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as renderer::InstanceRenderable::vfunc_10 (0x00054F90), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dPrimBufferStream::vfunc_24 (0x00703DD0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_007037B0(void);

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
    sub_007037B0();
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dPrimBufferStream::vfunc_00 (0x00704070, 48 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x00704070
// what: 
// tool: the portal's starter code (no AI)

// pure3d::d3dPrimBufferStream::vfunc_00 (PC 0x00704070, 48 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00703DE0(void);

namespace pure3d {

class d3dPrimBufferStream
{
public:
    virtual void vfunc_00(int a1, int a2, int a3);
    void sub_007037B0();
    char m_pad04[0x20];
    int m_Field24; // +0x24
};

void d3dPrimBufferStream::vfunc_00(int a1, int a2, int a3)
{
    sub_00703DE0();
    *(int*)m_Field24 = a1;
    *(int*)(m_Field24 + 4) = a2;
    *(int*)(m_Field24 + 8) = a3;
    sub_007037B0();
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dPrimBufferStream::vfunc_11 (0x007041B0, 42 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x007041B0
// what: 
// tool: the portal's starter code (no AI)

// pure3d::d3dPrimBufferStream::vfunc_11 (PC 0x007041B0, 42 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00703DE0(void);

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
    char m_pad34[0x10];
    int m_Field44; // +0x44
};

int d3dPrimBufferStream::vfunc_11(int a1, int a2)
{
    int r_eax, r_edx;

    sub_00703DE0();
    r_eax = a2;
    r_edx = a1;
    if (a2 < 2) {
        *(int*)(m_Field30 + (r_eax * 4)) = a1;
        return r_eax;
    }
    *(int*)(m_Field44 + (r_eax * 4) + -8) = r_edx;
    return r_eax;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dPrimBufferStream::vfunc_13 (0x007041E0, 37 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x007041E0
// what: 
// tool: the portal's starter code (no AI)

// pure3d::d3dPrimBufferStream::vfunc_13 (PC 0x007041E0, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00703DE0(void);

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
    sub_00703DE0();
    *(float*)(m_Field38 + (a3 * 8)) = a1;
    *(float*)(m_Field38 + (a3 * 8) + 4) = a2;
    return a3;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dPrimBufferStream::vfunc_16 (0x00704210, 21 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x00704210
// what: 
// tool: the portal's starter code (no AI)

// pure3d::d3dPrimBufferStream::vfunc_16 (PC 0x00704210, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00703DE0(void);

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
    int t2;

    sub_00703DE0();
    t2 = m_Field34;
    *(int*)m_Field34 = a1;
    return t2;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dPrimBufferStream::vfunc_09 (0x00704230, 41 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x00704230
// what: 
// tool: the portal's starter code (no AI)

// pure3d::d3dPrimBufferStream::vfunc_09 (PC 0x00704230, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00703DE0(void);

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
    char m_pad04[0x38];
    int m_Field3C; // +0x3C
};

int d3dPrimBufferStream::vfunc_09(int a1, int a2, int a3)
{
    sub_00703DE0();
    *(int*)m_Field3C = a1;
    *(int*)(m_Field3C + 4) = a2;
    *(int*)(m_Field3C + 8) = a3;
    return a2;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dPrimBufferStream::vfunc_10 (0x00704260, 41 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x00704260
// what: 
// tool: the portal's starter code (no AI)

// pure3d::d3dPrimBufferStream::vfunc_10 (PC 0x00704260, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00703DE0(void);

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
    char m_pad04[0x3C];
    int m_Field40; // +0x40
};

int d3dPrimBufferStream::vfunc_10(int a1, int a2, int a3)
{
    sub_00703DE0();
    *(int*)m_Field40 = a1;
    *(int*)(m_Field40 + 4) = a2;
    *(int*)(m_Field40 + 8) = a3;
    return a2;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dPrimBufferStream::vfunc_07 (0x00704290, 41 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x00704290
// what: 
// tool: the portal's starter code (no AI)

// pure3d::d3dPrimBufferStream::vfunc_07 (PC 0x00704290, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00703DE0(void);

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
    virtual int vfunc_07(int a1, int a2, int a3);
    char m_pad04[0x44];
    int m_Field48; // +0x48
};

int d3dPrimBufferStream::vfunc_07(int a1, int a2, int a3)
{
    sub_00703DE0();
    *(int*)m_Field48 = a1;
    *(int*)(m_Field48 + 4) = a2;
    *(int*)(m_Field48 + 8) = a3;
    return a2;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dPrimBufferStream::vfunc_08 (0x007042C0, 41 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x007042C0
// what: 
// tool: the portal's starter code (no AI)

// pure3d::d3dPrimBufferStream::vfunc_08 (PC 0x007042C0, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00703DE0(void);

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
    virtual int vfunc_08(int a1, int a2, int a3);
    char m_pad04[0x48];
    int m_Field4C; // +0x4C
};

int d3dPrimBufferStream::vfunc_08(int a1, int a2, int a3)
{
    sub_00703DE0();
    *(int*)m_Field4C = a1;
    *(int*)(m_Field4C + 4) = a2;
    *(int*)(m_Field4C + 8) = a3;
    return a2;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dPrimBufferStream::vfunc_18 (0x00704330, 41 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x00704330
// what: 
// tool: the portal's starter code (no AI)

// pure3d::d3dPrimBufferStream::vfunc_18 (PC 0x00704330, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00703DE0(void);

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
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual int vfunc_18(int a1, int a2, int a3);
    char m_pad04[0x50];
    int m_Field54; // +0x54
};

int d3dPrimBufferStream::vfunc_18(int a1, int a2, int a3)
{
    sub_00703DE0();
    *(int*)m_Field54 = a1;
    *(int*)(m_Field54 + 4) = a2;
    *(int*)(m_Field54 + 8) = a3;
    return a2;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dPrimBufferStream::vfunc_23 (0x00704360, 51 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x00704360
// what: 
// tool: the portal's starter code (no AI)

// pure3d::d3dPrimBufferStream::vfunc_23 (PC 0x00704360, 51 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00703DE0(void);

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
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23(int a1, int a2);
    void sub_007037B0();
    char m_pad04[0x20];
    int m_Field24; // +0x24
    char m_pad28[0x8];
    int m_Field30; // +0x30
};

void d3dPrimBufferStream::vfunc_23(int a1, int a2)
{
    int t2;

    sub_00703DE0();
    t2 = m_Field24;
    *(int*)m_Field24 = *(int*)a1;
    *(int*)(t2 + 4) = *(int*)(a1 + 4);
    *(int*)(t2 + 8) = *(int*)(a1 + 8);
    *(int*)m_Field30 = a2;
    sub_007037B0();
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dPrimBufferStream::vfunc_22 (0x007043A0, 64 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x007043A0
// what: 
// tool: the portal's starter code (no AI)

// pure3d::d3dPrimBufferStream::vfunc_22 (PC 0x007043A0, 64 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00703DE0(void);

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
    void sub_007037B0();
    char m_pad04[0x20];
    int m_Field24; // +0x24
};

void d3dPrimBufferStream::vfunc_22(int a1, int a2)
{
    int t2;

    sub_00703DE0();
    t2 = m_Field24;
    *(int*)m_Field24 = *(int*)a1;
    *(int*)(t2 + 4) = *(int*)(a1 + 4);
    *(int*)(t2 + 8) = *(int*)(a1 + 8);
    vfunc_01(*(int*)a2, *(int*)(a2 + 4), *(int*)(a2 + 8));
    sub_007037B0();
}

}

