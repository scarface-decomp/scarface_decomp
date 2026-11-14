// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, pure3d/pddiTexture.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::pddiTexture::vfunc_20 (0x0025E900, 3 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::pddiTexture::vfunc_20 (0x002994D0), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::pddiTexture::vfunc_20 (0x0025E900, 3 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d {

class pddiTexture
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
    virtual void vfunc_20(int a1, int a2, int a3, int a4, int a5, int a6, int a7);
};

void pddiTexture::vfunc_20(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
}

}

// ============================================================================
// [VERIFIED] pure3d::pddiTexture::vfunc_03 (0x0025E910, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as LOSManager::LOSManagerFlowClient::vfunc_00 (0x000179C0), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::pddiTexture::vfunc_03 (0x0025E910, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B30E4[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_00264490(void);

namespace pure3d {

class pddiTexture
{
public:
    virtual pddiTexture* vfunc_03(int a1);
};

pddiTexture* pddiTexture::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_003B30E4;
    sub_00264490();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

}

