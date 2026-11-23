// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, core/ParticleController.cpp (6 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 6 of 10 functions matched (60.00%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::ParticleController::vfunc_08 (0x00291CD0, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::ParticleController::vfunc_08 (0x00291CD0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

namespace pure3d {

class ParticleController
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
    virtual void vfunc_08(float a1, int a2);
    char m_pad04[0xC];
    float m_Field10; // +0x10
    char m_pad14[0x2C];
    float m_Field40; // +0x40
};

void ParticleController::vfunc_08(float a1, int a2)
{
    m_Field40 = (a1 * m_Field10) + m_Field40;
}

}

// ============================================================================
// [VERIFIED] pure3d::ParticleController::vfunc_12 (0x00291CF0, 4 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::ParticleController::vfunc_12 (Proto 0x0024E670), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::ParticleController::vfunc_12 (Proto 0x00291CF0, 4 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d {

class ParticleController
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
    virtual float vfunc_12();
    char m_pad04[0x38];
    float m_Field3C; // +0x3C
};

float ParticleController::vfunc_12()
{
    return m_Field3C;
}

}

// ============================================================================
// [VERIFIED] pure3d::ParticleController::vfunc_13 (0x00291D00, 4 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::ParticleController::vfunc_13 (Proto 0x000CF320), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::ParticleController::vfunc_13 (Proto 0x00291D00, 4 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d {

class ParticleController
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
    virtual float vfunc_13();
    char m_pad04[0x34];
    float m_Field38; // +0x38
};

float ParticleController::vfunc_13()
{
    return m_Field38;
}

}

// ============================================================================
// [VERIFIED] pure3d::ParticleController::vfunc_05 (0x00292030, 31 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::ParticleController::vfunc_05 (Proto 0x0024E9A0), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::ParticleController::vfunc_05 (Proto 0x00292030, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00291EC0(int);
};

extern "C" int __cdecl sub_0023F760(int);

namespace pure3d {

class ParticleController
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual int vfunc_05();
};

int ParticleController::vfunc_05()
{
    int t1;

    t1 = sub_0023F760(80);
    if (t1) {
        return ((Object*)t1)->sub_00291EC0((int)this);
    }
    return 0;
}

}

// ============================================================================
// [VERIFIED] pure3d::ParticleController::vfunc_03 (0x00292050, 33 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as fight::Branch::vfunc_03 (0x0023B160), which was matched first;
// its addresses and names were swapped for this function's.
extern "C" void __cdecl sub_0023F7A0(void* p);

namespace pure3d {

class ParticleController
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual ParticleController* vfunc_03(unsigned int flags);
    void sub_00291FD0();
};

#pragma optimize("y", off)
ParticleController* ParticleController::vfunc_03(unsigned int flags)
{
    sub_00291FD0();
    if (flags & 1)
        sub_0023F7A0(this);
    return this;
}
#pragma optimize("", on)

}

// ============================================================================
// [VERIFIED] pure3d::ParticleController::vfunc_07 (0x002921F0, 45 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::CameraAnimationController::vfunc_07 (0x0028CC80), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x002921F0
// what: 
// tool: the portal's starter code (no AI)

// pure3d::ParticleController::vfunc_07 (0x002921F0, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

extern "C" char DAT_00419538[];
extern "C" char DAT_0041C760[];
extern "C" int __cdecl sub_002FC034(int, int, int, int, int);

namespace pure3d {

class ParticleController
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07(int a1);
    void sub_00292080(int);
};

void ParticleController::vfunc_07(int a1)
{
    sub_00292080(sub_002FC034(a1, 0, (int)DAT_00419538, (int)DAT_0041C760, 0));
}

}

