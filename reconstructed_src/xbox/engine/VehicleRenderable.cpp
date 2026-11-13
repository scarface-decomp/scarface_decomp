// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/VehicleRenderable.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 3 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] renderer::VehicleRenderable::vfunc_10 (0x0005D830, 27 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// renderer::VehicleRenderable::vfunc_10 (0x0005D830, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_0041DB80;

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
    virtual void vfunc_09();
    virtual void vfunc_10();
    int sub_000589C0();
};

void VehicleRenderable::vfunc_10()
{
    int r_eax;

    r_eax = *(int*)this;
    ((void (__cdecl*)(void))*(int*)(r_eax + 56))();
    r_eax = DAT_0041DB80;
    if ((unsigned char)r_eax) {
        sub_000589C0();
    }
}

}

// ============================================================================
// [VERIFIED] renderer::VehicleRenderable::vfunc_03 (0x0005E430, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionManager::CollisionManagerFlowClient::vfunc_00 (0x00016060), which was matched first;
// its addresses and names were swapped for this function's.
// renderer::VehicleRenderable::vfunc_03 (0x0005E430, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0005DCD0(void);
extern "C" void __cdecl sub_0023F7A0(int);

namespace renderer {

class VehicleRenderable
{
public:
    virtual VehicleRenderable* vfunc_03(int a1);
};

VehicleRenderable* VehicleRenderable::vfunc_03(int a1)
{
    sub_0005DCD0();
    if (a1 & 1) {
        sub_0023F7A0((int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] renderer::VehicleRenderable::vfunc_09 (0x0005EC70, 44 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// renderer::VehicleRenderable::vfunc_09 (0x0005EC70, 44 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct FieldB8
{
    void sub_0005EA40();
};

extern "C" bool DAT_0041DB80;
extern "C" void __stdcall sub_00022710(int);

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
    int sub_000585D0();
    char m_pad04[0xB4];
    FieldB8* m_FieldB8; // +0xB8
};

void VehicleRenderable::vfunc_09(int a1)
{
    int r_eax;

    r_eax = a1;
    sub_00022710(a1);
    r_eax = DAT_0041DB80;
    if ((unsigned char)r_eax) {
        m_FieldB8->sub_0005EA40();
        r_eax = sub_000585D0();
    }
}

}

