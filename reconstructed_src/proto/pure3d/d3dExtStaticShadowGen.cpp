// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, pure3d/d3dExtStaticShadowGen.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 8 functions matched (37.50%). NOT COMPLETE YET.
// The 5 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::d3dExtStaticShadowGen::vfunc_00 (0x00268360, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionManager::CollisionManagerFlowClient::vfunc_00 (0x00016060), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dExtStaticShadowGen::vfunc_00 (0x00268360, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_002677F0(void);
extern "C" void __cdecl sub_00025160(int);

namespace pure3d {

class d3dExtStaticShadowGen
{
public:
    virtual d3dExtStaticShadowGen* vfunc_00(int a1);
};

d3dExtStaticShadowGen* d3dExtStaticShadowGen::vfunc_00(int a1)
{
    sub_002677F0();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dExtStaticShadowGen::vfunc_05 (0x00269B00, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dExtVisibilityTest::vfunc_02 (0x002680E0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x00269B00
// what: Calls one other function and does nothing else.
// tool: Claude Fable 5.2 (look-alike of 0x00054F90, names and addresses swapped)
// pure3d::d3dExtStaticShadowGen::vfunc_05 (0x00269B00, 5 bytes)
extern "C" void __cdecl sub_00269010(void);

namespace pure3d {

class d3dExtStaticShadowGen
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_05();
};

void d3dExtStaticShadowGen::vfunc_05()
{
    sub_00269010();
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dExtStaticShadowGen::vfunc_06 (0x00269B10, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dExtVisibilityTest::vfunc_02 (0x002680E0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x00269B10
// what: Calls one other function and does nothing else.
// tool: Claude Fable 5.2 (look-alike of 0x00054F90, names and addresses swapped)
// pure3d::d3dExtStaticShadowGen::vfunc_06 (0x00269B10, 5 bytes)
extern "C" void __cdecl sub_002693F0(void);

namespace pure3d {

class d3dExtStaticShadowGen
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_06();
};

void d3dExtStaticShadowGen::vfunc_06()
{
    sub_002693F0();
}

}

