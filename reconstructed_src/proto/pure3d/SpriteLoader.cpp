// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, pure3d/SpriteLoader.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 5 functions matched (40.00%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::SpriteLoader::vfunc_07 (0x0021EBC0, 10 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::SpriteLoader::vfunc_07 (Proto 0x0021EBC0, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d {

class SpriteLoader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual bool vfunc_07(bool a1);
    char m_pad04[0x1D];
    bool m_Field21; // +0x21
};

bool SpriteLoader::vfunc_07(bool a1)
{
    m_Field21 = a1;
    return a1;
}

}

// ============================================================================
// [VERIFIED] pure3d::SpriteLoader::vfunc_03 (0x0021F230, 83 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::SpriteLoader::vfunc_03 (Proto 0x0021F230, 83 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00(int);
    virtual void vfunc_01();
    void sub_0021B8A0();
};

extern "C" char DAT_0037D85C[];
extern "C" char DAT_003AF680[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_001FCF60(int);

namespace pure3d {

class SpriteLoader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual SpriteLoader* vfunc_03(int a1);
    char m_pad04[0x10];
    int m_Field14; // +0x14
    int m_Field18; // +0x18
    int m_Field1C; // +0x1C
};

SpriteLoader* SpriteLoader::vfunc_03(int a1)
{
    int t1, t3, t5;

    t1 = m_Field18;
    *(int*)this = (int)DAT_003AF680;
    ((Object*)t1)->vfunc_01();
    t3 = m_Field14;
    if (m_Field14) {
        ((Object*)t3)->vfunc_00(1);
    }
    t5 = m_Field1C;
    if (m_Field1C) {
        ((Object*)t5)->sub_0021B8A0();
        sub_00025160(t5);
    }
    *(int*)this = (int)DAT_0037D85C;
    if (a1 & 1) {
        sub_001FCF60((int)this);
    }
    return this;
}

}

