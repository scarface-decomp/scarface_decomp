// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, pure3d/CharacterAnimationLayer.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 8 functions matched (50.00%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::CharacterAnimationLayer::vfunc_03 (0x00241220, 45 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::CharacterAnimationLayer::vfunc_03 (Proto 0x00241220, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field28
{
    void sub_00242840();
};

extern "C" char DAT_0037D85C[];
extern "C" char DAT_003B11C0[];
extern "C" void __cdecl sub_00025160(int);

namespace pure3d {

class CharacterAnimationLayer
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual CharacterAnimationLayer* vfunc_03(int a1);
    char m_pad04[0x24];
    Field28 m_Field28; // +0x28
};

CharacterAnimationLayer* CharacterAnimationLayer::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_003B11C0;
    m_Field28.sub_00242840();
    *(int*)this = (int)DAT_0037D85C;
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] pure3d::CharacterAnimationLayer::vfunc_04 (0x002412C0, 71 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::CharacterAnimationLayer::vfunc_04 (Proto 0x002412C0, 71 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    void sub_000C6670(int);
};

struct Field28
{
    int sub_001DA6E0();
    void sub_00242970(int);
};

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
    virtual void vfunc_08(int, int);
    void sub_00242AF0(int);
};

namespace pure3d {

class CharacterAnimationLayer
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int a1, int a2, int a3);
    char m_pad04[0x8];
    Field0C m_Field0C; // +0x0C
    char m_pad0D[0x13];
    int m_Field20; // +0x20
    char m_pad24[0x4];
    Field28 m_Field28; // +0x28
};

void CharacterAnimationLayer::vfunc_04(int a1, int a2, int a3)
{
    int r_esi;

    m_Field0C.sub_000C6670(a1);
    r_esi = (int)(&m_Field28);
    if (m_Field28.sub_001DA6E0() != a2) {
        m_Field28.sub_00242970(a2);
    }
    ((Object*)r_esi)->sub_00242AF0(m_Field20);
    ((Object*)r_esi)->vfunc_08(a1, 0);
}

}

// ============================================================================
// [VERIFIED] pure3d::CharacterAnimationLayer::vfunc_06 (0x00241320, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::CharacterAnimationLayer::vfunc_06 (Proto 0x00241320, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00242010();
};

namespace pure3d {

class CharacterAnimationLayer
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
};

void CharacterAnimationLayer::vfunc_06()
{
    ((Object*)(int)this + 40)->sub_00242010();
}

}

// ============================================================================
// [VERIFIED] pure3d::CharacterAnimationLayer::vfunc_10 (0x002413C0, 13 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::CharacterAnimationLayer::vfunc_10 (Proto 0x002413C0, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d {

class CharacterAnimationLayer
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
    virtual int vfunc_10(int a1);
    char m_pad04[0xF0];
    int m_FieldF4; // +0xF4
};

int CharacterAnimationLayer::vfunc_10(int a1)
{
    m_FieldF4 = a1;
    return a1;
}

}

