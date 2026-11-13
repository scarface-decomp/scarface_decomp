// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, pure3d/d3dContext.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 116 functions matched (1.72%). NOT COMPLETE YET.
// The 114 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::d3dContext::vfunc_103 (0x00234150, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as renderer::InstanceRenderable::vfunc_10 (0x00054F90), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dContext::vfunc_103 (0x00234150, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00314750(void);

namespace pure3d {

class d3dContext
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
    virtual void vfunc_103();
};

void d3dContext::vfunc_103()
{
    sub_00314750();
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dContext::vfunc_03 (0x0023B1F0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionManager::CollisionManagerFlowClient::vfunc_00 (0x00016060), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dContext::vfunc_03 (0x0023B1F0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_002398F0(void);
extern "C" void __cdecl sub_00025160(int);

namespace pure3d {

class d3dContext
{
public:
    virtual d3dContext* vfunc_03(int a1);
};

d3dContext* d3dContext::vfunc_03(int a1)
{
    sub_002398F0();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

}

