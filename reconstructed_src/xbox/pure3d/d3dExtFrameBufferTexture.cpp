// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/d3dExtFrameBufferTexture.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 3 functions matched (33.33%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::d3dExtFrameBufferTexture::vfunc_00 (0x00269B00, 45 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::d3dExtFrameBufferTexture::vfunc_00 (0x00269B00, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

extern "C" char DAT_003D68A4[];
extern "C" char DAT_003D6B78[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_00269AB0(void);

namespace pure3d {

class d3dExtFrameBufferTexture
{
public:
    virtual d3dExtFrameBufferTexture* vfunc_00(int a1);
};

d3dExtFrameBufferTexture* d3dExtFrameBufferTexture::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003D6B78;
    sub_00269AB0();
    *(int*)this = (int)DAT_003D68A4;
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

}

