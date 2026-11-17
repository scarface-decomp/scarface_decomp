// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, pure3d/SpriteMenuItem.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 7 functions matched (42.86%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::frontend::SpriteMenuItem::vfunc_15 (0x00249830, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::frontend::SpriteMenuItem::vfunc_15 (Proto 0x00249830, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field34
{
    void sub_00208910();
};

namespace pure3d { namespace frontend {

class SpriteMenuItem
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
    char m_pad04[0x30];
    Field34* m_Field34; // +0x34
};

void SpriteMenuItem::vfunc_15()
{
    m_Field34->sub_00208910();
}

} }

// ============================================================================
// [VERIFIED] pure3d::frontend::SpriteMenuItem::vfunc_16 (0x00249840, 21 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::frontend::SpriteMenuItem::vfunc_16 (Proto 0x00249840, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d { namespace frontend {

class SpriteMenuItem
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
    virtual int vfunc_16();
    char m_pad04[0x30];
    int m_Field34; // +0x34
};

int SpriteMenuItem::vfunc_16()
{
    return ((short)((unsigned short)(*(unsigned short*)(m_Field34 + 136) << 3))) >> 3;
}

} }

// ============================================================================
// [VERIFIED] pure3d::frontend::SpriteMenuItem::vfunc_03 (0x00249DE0, 30 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::frontend::Text::vfunc_03 (Proto 0x00206FC0), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::frontend::SpriteMenuItem::vfunc_03 (Proto 0x00249DE0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001FCF60(int);
extern "C" void __cdecl sub_00249C30(void);

namespace pure3d { namespace frontend {

class SpriteMenuItem
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual SpriteMenuItem* vfunc_03(int a1);
};

SpriteMenuItem* SpriteMenuItem::vfunc_03(int a1)
{
    sub_00249C30();
    if (a1 & 1) {
        sub_001FCF60((int)this);
    }
    return this;
}

} }

