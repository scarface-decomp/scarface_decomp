// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/VectorCamera.cpp (7 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 7 of 21 functions matched (33.33%). NOT COMPLETE YET.
// The 14 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::VectorCamera::vfunc_03 (0x0024AB60, 39 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as fight::Param::vfunc_03 (0x00239CE0), which was matched first;
// its addresses and names were swapped for this function's.
extern "C" char DAT_003D50C4[];
extern "C" void __cdecl sub_0023F7A0(void* p);

namespace pure3d {

class VectorCamera
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual VectorCamera* vfunc_03(unsigned int flags);
    void sub_0028BAA0();
};

#pragma optimize("y", off)
VectorCamera* VectorCamera::vfunc_03(unsigned int flags)
{
    *(void**)this = DAT_003D50C4;
    sub_0028BAA0();
    if (flags & 1)
        sub_0023F7A0(this);
    return this;
}
#pragma optimize("", on)

}

// ============================================================================
// [VERIFIED] pure3d::VectorCamera::vfunc_08 (0x0028BAB0, 23 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::VectorCamera::vfunc_08 (0x0028BAB0, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

namespace pure3d {

class VectorCamera
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
    virtual int vfunc_08(int a1, int a2);
    char m_pad04[0xC];
    int m_Field10; // +0x10
    int m_Field14; // +0x14
};

int VectorCamera::vfunc_08(int a1, int a2)
{
    int t1;

    *(int*)a1 = m_Field10;
    t1 = m_Field14;
    *(int*)a2 = m_Field14;
    return t1;
}

}

// ============================================================================
// [VERIFIED] pure3d::VectorCamera::vfunc_14 (0x0028BBD0, 43 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::VectorCamera::vfunc_14 (0x0028BBD0, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

struct Object
{
    void sub_00280A00(int);
};

namespace pure3d {

class VectorCamera
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
    virtual void vfunc_13(int, int);
    virtual void vfunc_14(int a1, int a2);
    virtual void vfunc_15();
    virtual int vfunc_16();
};

void VectorCamera::vfunc_14(int a1, int a2)
{
    vfunc_13(a1, a2);
    ((Object*)a2)->sub_00280A00(vfunc_16());
}

}

// ============================================================================
// [VERIFIED] pure3d::VectorCamera::vfunc_15 (0x0028BC00, 23 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::VectorCamera::vfunc_15 (0x0028BC00, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d {

class VectorCamera
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
    virtual void* vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    char m_pad04[0x48];
    int m_Field4C; // +0x4C
    char m_pad50[0x7C];
    bool m_FieldCC; // +0xCC
};

void* VectorCamera::vfunc_15()
{
    if (!m_FieldCC) {
        vfunc_30();
    }
    return &m_Field4C;
}

}

// ============================================================================
// [VERIFIED] pure3d::VectorCamera::vfunc_16 (0x0028BC20, 26 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::VectorCamera::vfunc_16 (0x0028BC20, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d {

class VectorCamera
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
    virtual void* vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    char m_pad04[0x88];
    int m_Field8C; // +0x8C
    char m_pad90[0x3C];
    bool m_FieldCC; // +0xCC
};

void* VectorCamera::vfunc_16()
{
    if (!m_FieldCC) {
        vfunc_30();
    }
    return &m_Field8C;
}

}

// ============================================================================
// [VERIFIED] pure3d::VectorCamera::vfunc_24 (0x0028BEE0, 55 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::VectorCamera::vfunc_24 (0x0028BEE0, 55 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

namespace pure3d {

class VectorCamera
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
    virtual void vfunc_23();
    virtual int vfunc_24(int a1);
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    char m_pad04[0xB8];
    int m_FieldBC; // +0xBC
    int m_FieldC0; // +0xC0
    int m_FieldC4; // +0xC4
    char m_padC8[0x4];
    bool m_FieldCC; // +0xCC
};

int VectorCamera::vfunc_24(int a1)
{
    if (!m_FieldCC) {
        vfunc_30();
    }
    *(int*)a1 = m_FieldBC;
    *(int*)(a1 + 4) = m_FieldC0;
    *(int*)(a1 + 8) = m_FieldC4;
    return a1;
}

}

// ============================================================================
// [VERIFIED] pure3d::VectorCamera::vfunc_27 (0x0028C080, 45 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::VectorCamera::vfunc_27 (0x0028C080, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

struct Field8C
{
    void sub_002435D0(int, int);
};

namespace pure3d {

class VectorCamera
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
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27(int a1, int a2);
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    char m_pad04[0x88];
    Field8C m_Field8C; // +0x8C
    char m_pad8D[0x3F];
    bool m_FieldCC; // +0xCC
};

void VectorCamera::vfunc_27(int a1, int a2)
{
    if (!m_FieldCC) {
        vfunc_30();
    }
    m_Field8C.sub_002435D0(a1, a2);
}

}

