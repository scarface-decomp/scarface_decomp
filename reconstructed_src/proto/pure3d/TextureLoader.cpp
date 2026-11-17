// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, pure3d/TextureLoader.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 2 functions matched (50.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::TextureLoader::vfunc_03 (0x00231E40, 75 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::TextureLoader::vfunc_03 (Proto 0x00231E40, 75 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00(int);
    void sub_0021B8A0();
};

extern "C" char DAT_0037D85C[];
extern "C" char DAT_003B048C[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_001FCF60(int);

namespace pure3d {

class TextureLoader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual TextureLoader* vfunc_03(int a1);
    char m_pad04[0x10];
    int m_Field14; // +0x14
    int m_Field18; // +0x18
};

TextureLoader* TextureLoader::vfunc_03(int a1)
{
    int t1, t4;

    t1 = m_Field14;
    *(int*)this = (int)DAT_003B048C;
    if (m_Field14) {
        ((Object*)t1)->sub_0021B8A0();
        sub_00025160(t1);
    }
    t4 = m_Field18;
    if (m_Field18) {
        ((Object*)t4)->vfunc_00(1);
    }
    *(int*)this = (int)DAT_0037D85C;
    if (a1 & 1) {
        sub_001FCF60((int)this);
    }
    return this;
}

}

