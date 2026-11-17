// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/PlugInRenderable.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 3 functions matched (66.67%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] renderer::PlugInRenderable::vfunc_16 (0x0004D200, 76 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// renderer::PlugInRenderable::vfunc_16 (Proto 0x0004D200, 76 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0004F510(int);
};

extern "C" char DAT_00380004[];
extern "C" char sub_00040000[];
extern "C" int __cdecl sub_001FCF20(int);

namespace renderer {

class PlugInRenderable
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
    char m_pad04[0x7C];
    int m_Field80; // +0x80
};

int PlugInRenderable::vfunc_16()
{
    int t1;

    t1 = sub_001FCF20(132);
    if (t1) {
        ((Object*)t1)->sub_0004F510((int)this);
        *(int*)(t1 + 128) = 0;
        *(int*)t1 = (int)DAT_00380004;
        *(int*)(t1 + 84) = (int)sub_00040000;
        *(int*)(t1 + 128) = m_Field80;
        return t1;
    }
    return 0;
}

}

// ============================================================================
// [VERIFIED] renderer::PlugInRenderable::vfunc_03 (0x0004D250, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as LOSManager::LOSManagerFlowClient::vfunc_00 (0x000179C0), which was matched first;
// its addresses and names were swapped for this function's.
// renderer::PlugInRenderable::vfunc_03 (0x0004D250, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00380004[];
extern "C" void __cdecl sub_001FCF60(int);
extern "C" void __cdecl sub_0004F610(void);

namespace renderer {

class PlugInRenderable
{
public:
    virtual PlugInRenderable* vfunc_03(int a1);
};

PlugInRenderable* PlugInRenderable::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_00380004;
    sub_0004F610();
    if (a1 & 1) {
        sub_001FCF60((int)this);
    }
    return this;
}

}

