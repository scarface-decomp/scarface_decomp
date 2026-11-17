// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, pure3d/Sprite.cpp (9 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 9 of 17 functions matched (52.94%). NOT COMPLETE YET.
// The 8 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::Sprite::vfunc_09 (0x00020D30, 4 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::Sprite::vfunc_09 (Proto 0x00020D30, 4 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

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
    virtual int vfunc_09();
    char m_pad04[0x40];
    int m_Field44; // +0x44
};

int Sprite::vfunc_09()
{
    return m_Field44;
}

}

// ============================================================================
// [VERIFIED] pure3d::frontend::Sprite::vfunc_16 (0x002086F0, 20 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::frontend::Sprite::vfunc_16 (Proto 0x002086F0, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field48
{
    void sub_002003C0();
};

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
    char m_pad04[0x44];
    Field48 m_Field48; // +0x48
    char m_pad49[0x41];
    unsigned char m_Field8A; // +0x8A
};

void Sprite::vfunc_16()
{
    m_Field48.sub_002003C0();
    m_Field8A &= 247;
}

} }

// ============================================================================
// [VERIFIED] pure3d::frontend::Sprite::vfunc_15 (0x002087C0, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::frontend::Sprite::vfunc_15 (Proto 0x002087C0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

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
    char m_pad04[0x86];
    unsigned char m_Field8A; // +0x8A
};

void Sprite::vfunc_15()
{
    m_Field8A |= 1;
}

} }

// ============================================================================
// [VERIFIED] pure3d::frontend::Sprite::vfunc_17 (0x00208900, 15 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::frontend::Sprite::vfunc_17 (Proto 0x00208900, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_00208860(int, int, int);

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
    sub_00208860(a1, a1, a1);
}

} }

// ============================================================================
// [VERIFIED] pure3d::frontend::Sprite::vfunc_03 (0x00209030, 30 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::frontend::Sprite::vfunc_03 (Proto 0x00209030, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001FCF60(int);
extern "C" void __cdecl sub_00208F80(void);

namespace pure3d { namespace frontend {

class Sprite
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual Sprite* vfunc_03(int a1);
};

Sprite* Sprite::vfunc_03(int a1)
{
    sub_00208F80();
    if (a1 & 1) {
        sub_001FCF60((int)this);
    }
    return this;
}

} }

// ============================================================================
// [VERIFIED] pure3d::Sprite::vfunc_16 (0x0021E9B0, 16 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::Sprite::vfunc_16 (Proto 0x0021E9B0, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00018E10(int);
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
    virtual void vfunc_16(int a1);
};

void Sprite::vfunc_16(int a1)
{
    ((Object*)a1)->sub_00018E10((int)this + 112);
}

}

// ============================================================================
// [VERIFIED] pure3d::Sprite::vfunc_17 (0x0021E9C0, 42 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::Sprite::vfunc_17 (Proto 0x0021E9C0, 42 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

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
    virtual int vfunc_17(int a1);
    char m_pad04[0x84];
    int m_Field88; // +0x88
    int m_Field8C; // +0x8C
    int m_Field90; // +0x90
    int m_Field94; // +0x94
};

int Sprite::vfunc_17(int a1)
{
    *(int*)a1 = m_Field88;
    *(int*)(a1 + 4) = m_Field8C;
    *(int*)(a1 + 8) = m_Field90;
    *(int*)(a1 + 12) = m_Field94;
    return a1;
}

}

// ============================================================================
// [VERIFIED] pure3d::Sprite::vfunc_10 (0x0021EB30, 61 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::Sprite::vfunc_10 (Proto 0x0021EB30, 61 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" void __stdcall sub_0021E340(int);

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
    int t3;

    sub_0021E340(m_Field44);
    m_Field44 = 0;
    if (a1) {
        ((Object*)a1)->vfunc_00();
    }
    t3 = m_Field44;
    if (m_Field44) {
        ((Object*)t3)->vfunc_01();
    }
    m_Field44 = a1;
    m_Field0C = 1;
}

}

// ============================================================================
// [VERIFIED] pure3d::Sprite::vfunc_03 (0x0021EBD0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionManager::CollisionManagerFlowClient::vfunc_00 (0x00016060), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::Sprite::vfunc_03 (0x0021EBD0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0021E940(void);
extern "C" void __cdecl sub_001FCF60(int);

namespace pure3d {

class Sprite
{
public:
    virtual Sprite* vfunc_03(int a1);
};

Sprite* Sprite::vfunc_03(int a1)
{
    sub_0021E940();
    if (a1 & 1) {
        sub_001FCF60((int)this);
    }
    return this;
}

}

