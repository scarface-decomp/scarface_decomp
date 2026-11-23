// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/TextureLoader.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::TextureLoader::vfunc_03 (0x0027FDB0, 78 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: xb
// va: 0x0027FDB0
// what: 
// tool: the portal's starter code (no AI)

// pure3d::TextureLoader::vfunc_03 (0x0027FDB0, 78 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

struct Object
{
    virtual void vfunc_00(int);
    void sub_00262260();
};

extern "C" char DAT_0039E22C[];
extern "C" char DAT_003D7CAC[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_0023F7A0(int);

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
    *(int*)this = (int)DAT_003D7CAC;
    if (m_Field14) {
        ((Object*)t1)->sub_00262260();
        sub_00027600(t1);
    }
    t4 = m_Field18;
    if (m_Field18) {
        ((Object*)t4)->vfunc_00(1);
    }
    *(int*)this = (int)DAT_0039E22C;
    if (a1 & 1) {
        sub_0023F7A0((int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] pure3d::TextureLoader::vfunc_06 (0x0027FE00, 33 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: xb
// va: 0x0027FE00
// what: 
// tool: the portal's starter code (no AI)

// pure3d::TextureLoader::vfunc_06 (0x0027FE00, 33 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

extern "C" int __stdcall sub_0027FAE0(int);

namespace pure3d {

class TextureLoader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06(int a1, int a2, int a3, int a4);
};

void TextureLoader::vfunc_06(int a1, int a2, int a3, int a4)
{
    int t1;

    t1 = sub_0027FAE0(a3);
    if (t1) {
        *(int*)a1 = t1;
        *(int*)a2 = *(int*)(t1 + 8);
    }
}

}

