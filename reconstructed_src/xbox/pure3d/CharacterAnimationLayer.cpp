// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/CharacterAnimationLayer.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 9 functions matched (33.33%). NOT COMPLETE YET.
// The 6 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::CharacterAnimationLayer::vfunc_03 (0x00284F90, 48 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::CharacterAnimationLayer::vfunc_03 (0x00284F90, 48 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

struct Field28
{
    void sub_002865C0();
};

extern "C" char DAT_0039E22C[];
extern "C" char DAT_003D805C[];
extern "C" void __cdecl sub_00027600(int);

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
    *(int*)this = (int)DAT_003D805C;
    m_Field28.sub_002865C0();
    *(int*)this = (int)DAT_0039E22C;
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] pure3d::CharacterAnimationLayer::vfunc_05 (0x00285070, 73 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::CharacterAnimationLayer::vfunc_05 (0x00285070, 73 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

struct Field0C
{
    void sub_000D8160(int);
};

struct Field28
{
    int sub_0002A7C0();
    void sub_00286700(int);
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
    void sub_00286880(int);
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
    virtual void vfunc_05(int a1, int a2, int a3);
    char m_pad04[0x8];
    Field0C m_Field0C; // +0x0C
    char m_pad0D[0x13];
    int m_Field20; // +0x20
    char m_pad24[0x4];
    Field28 m_Field28; // +0x28
};

void CharacterAnimationLayer::vfunc_05(int a1, int a2, int a3)
{
    int r_ebx, r_esi;

    r_ebx = a1;
    m_Field0C.sub_000D8160(a1);
    r_esi = (int)(&m_Field28);
    if (m_Field28.sub_0002A7C0() != a2) {
        m_Field28.sub_00286700(a2);
    }
    ((Object*)r_esi)->sub_00286880(m_Field20);
    ((Object*)r_esi)->vfunc_08(r_ebx, 0);
}

}

// ============================================================================
// [VERIFIED] pure3d::CharacterAnimationLayer::vfunc_11 (0x00285180, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::CharacterAnimationLayer::vfunc_11 (0x00285180, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

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
    virtual void vfunc_10();
    virtual int vfunc_11(int a1);
    char m_pad04[0xF0];
    int m_FieldF4; // +0xF4
};

int CharacterAnimationLayer::vfunc_11(int a1)
{
    m_FieldF4 = a1;
    return a1;
}

}

