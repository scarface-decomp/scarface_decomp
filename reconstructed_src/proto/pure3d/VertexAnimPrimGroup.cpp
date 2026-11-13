// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, pure3d/VertexAnimPrimGroup.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 4 functions matched (50.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::VertexAnimPrimGroup::vfunc_05 (0x00250070, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::CompositeDrawable::vfunc_05 (0x002776D0), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::VertexAnimPrimGroup::vfunc_05 (0x00250070, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_0024FEB0(int);
};

extern "C" int __cdecl sub_001FCF20(int);

namespace pure3d {

class VertexAnimPrimGroup
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual int vfunc_05();
};

int VertexAnimPrimGroup::vfunc_05()
{
    int t1;

    t1 = sub_001FCF20(84);
    if (t1) {
        return ((Object*)t1)->sub_0024FEB0((int)this);
    }
    return 0;
}

}

// ============================================================================
// [VERIFIED] pure3d::VertexAnimPrimGroup::vfunc_03 (0x00250B20, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionManager::CollisionManagerFlowClient::vfunc_00 (0x00016060), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::VertexAnimPrimGroup::vfunc_03 (0x00250B20, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00250010(void);
extern "C" void __cdecl sub_001FCF60(int);

namespace pure3d {

class VertexAnimPrimGroup
{
public:
    virtual VertexAnimPrimGroup* vfunc_03(int a1);
};

VertexAnimPrimGroup* VertexAnimPrimGroup::vfunc_03(int a1)
{
    sub_00250010();
    if (a1 & 1) {
        sub_001FCF60((int)this);
    }
    return this;
}

}

