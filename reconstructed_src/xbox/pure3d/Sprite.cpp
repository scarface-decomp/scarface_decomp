// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/Sprite.cpp (5 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 5 of 17 functions matched (29.41%). NOT COMPLETE YET.
// The 12 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::frontend::Sprite::vfunc_17 (0x0024B240, 18 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::frontend::Sprite::vfunc_17 (0x0024B240, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

extern "C" void __stdcall sub_0024B110(int, int, int);

namespace pure3d { namespace frontend {

class Sprite
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
    virtual void vfunc_17(int a1);
};

void Sprite::vfunc_17(int a1)
{
    sub_0024B110(a1, a1, a1);
}

} }

// ============================================================================
// [VERIFIED] pure3d::Sprite::vfunc_17 (0x0026D940, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::Sprite::vfunc_17 (0x0026D940, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

struct Object
{
    void sub_00019040(int);
};

namespace pure3d {

class Sprite
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
    virtual void vfunc_17(int a1);
};

void Sprite::vfunc_17(int a1)
{
    ((Object*)a1)->sub_00019040((int)this + 112);
}

}

// ============================================================================
// [VERIFIED] pure3d::Sprite::vfunc_18 (0x0026D960, 45 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::Sprite::vfunc_18 (0x0026D960, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

namespace pure3d {

class Sprite
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
    virtual int vfunc_18(int a1);
    char m_pad04[0x84];
    int m_Field88; // +0x88
    int m_Field8C; // +0x8C
    int m_Field90; // +0x90
    int m_Field94; // +0x94
};

int Sprite::vfunc_18(int a1)
{
    *(int*)a1 = m_Field88;
    *(int*)(a1 + 4) = m_Field8C;
    *(int*)(a1 + 8) = m_Field90;
    *(int*)(a1 + 12) = m_Field94;
    return a1;
}

}

// ============================================================================
// [VERIFIED] pure3d::Sprite::vfunc_10 (0x0026DAA0, 64 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::Sprite::vfunc_10 (0x0026DAA0, 64 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" void __stdcall sub_0026D2D0(int);

namespace pure3d {

class Sprite
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
    virtual void vfunc_10(int a1);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    char m_pad10[0x34];
    int m_Field44; // +0x44
};

void Sprite::vfunc_10(int a1)
{
    int r_edi, t3;

    sub_0026D2D0(m_Field44);
    r_edi = a1;
    m_Field44 = 0;
    if (a1) {
        ((Object*)r_edi)->vfunc_00();
    }
    t3 = m_Field44;
    if (m_Field44) {
        ((Object*)t3)->vfunc_01();
    }
    m_Field44 = r_edi;
    m_Field0C = 1;
}

}

// ============================================================================
// [VERIFIED] pure3d::Sprite::vfunc_03 (0x0026DB50, 33 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as fight::Branch::vfunc_03 (0x0023B160), which was matched first;
// its addresses and names were swapped for this function's.
extern "C" void __cdecl sub_0023F7A0(void* p);

namespace pure3d {

class Sprite
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual Sprite* vfunc_03(unsigned int flags);
    void sub_0026D8D0();
};

#pragma optimize("y", off)
Sprite* Sprite::vfunc_03(unsigned int flags)
{
    sub_0026D8D0();
    if (flags & 1)
        sub_0023F7A0(this);
    return this;
}
#pragma optimize("", on)

}

