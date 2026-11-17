// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/VehicleRenderable.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 3 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] renderer::VehicleRenderable::vfunc_10 (0x000531F0, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dExtStaticShadowGen::vfunc_01 (0x002A3040), which was matched first;
// its addresses and names were swapped for this function's.
// renderer::VehicleRenderable::vfunc_10 (0x000531F0, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0004EB40(void);

namespace renderer {

class VehicleRenderable
{
public:
    virtual void vfunc_00();
    virtual void vfunc_10();
    void sub_0004EF40();
};

void VehicleRenderable::vfunc_10()
{
    sub_0004EB40();
    sub_0004EF40();
}

}

// ============================================================================
// [VERIFIED] renderer::VehicleRenderable::vfunc_03 (0x00053BA0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionManager::CollisionManagerFlowClient::vfunc_00 (0x00016060), which was matched first;
// its addresses and names were swapped for this function's.
// renderer::VehicleRenderable::vfunc_03 (0x00053BA0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_000536F0(void);
extern "C" void __cdecl sub_001FCF60(int);

namespace renderer {

class VehicleRenderable
{
public:
    virtual VehicleRenderable* vfunc_03(int a1);
};

VehicleRenderable* VehicleRenderable::vfunc_03(int a1)
{
    sub_000536F0();
    if (a1 & 1) {
        sub_001FCF60((int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] renderer::VehicleRenderable::vfunc_09 (0x00054370, 25 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// renderer::VehicleRenderable::vfunc_09 (Proto 0x00054370, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct FieldAC
{
    void sub_00054140();
};

namespace renderer {

class VehicleRenderable
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
    virtual void vfunc_09(int a1);
    void sub_0004EB90();
    char m_pad04[0xA8];
    FieldAC* m_FieldAC; // +0xAC
};

void VehicleRenderable::vfunc_09(int a1)
{
    m_FieldAC->sub_00054140();
    sub_0004EB90();
}

}

