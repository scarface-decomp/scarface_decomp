// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/ParticlePointGenerator.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 7 functions matched (57.14%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::ParticlePointGenerator::vfunc_10 (0x002A55A0, 46 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: xb
// va: 0x002A55A0
// what: 
// tool: the portal's starter code (no AI)

// pure3d::ParticlePointGenerator::vfunc_10 (0x002A55A0, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

extern "C" float DAT_0039D584;

namespace pure3d {

class ParticlePointGenerator
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
    virtual float vfunc_10(int a1);
    char m_pad04[0x38];
    float m_Field3C; // +0x3C
    float m_Field40; // +0x40
    float m_Field44; // +0x44
};

float ParticlePointGenerator::vfunc_10(int a1)
{
    int r_eax;

    r_eax = a1;
    r_eax -= 1;
    if (r_eax) {
        r_eax -= 1;
        if (r_eax) {
            r_eax -= 1;
            if (r_eax) {
                return DAT_0039D584;
            }
            return m_Field44;
        }
        return m_Field40;
    }
    return m_Field3C;
}

}

// ============================================================================
// [VERIFIED] pure3d::ParticlePointGenerator::vfunc_11 (0x002A55D0, 15 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::ParticlePointGenerator::vfunc_11 (Proto 0x00256900), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::ParticlePointGenerator::vfunc_11 (Proto 0x002A55D0, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d {

class ParticlePointGenerator
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
    virtual int vfunc_11();
    char m_pad04[0x38];
    int m_Field3C; // +0x3C
    int m_Field40; // +0x40
    int m_Field44; // +0x44
};

int ParticlePointGenerator::vfunc_11()
{
    m_Field3C = 0x3F800000;
    m_Field40 = 0x3F800000;
    m_Field44 = 0x3F800000;
    return 0x3F800000;
}

}

// ============================================================================
// [VERIFIED] pure3d::ParticlePointGenerator::vfunc_05 (0x002A64A0, 31 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::ParticlePointGenerator::vfunc_05 (Proto 0x002578B0), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::ParticlePointGenerator::vfunc_05 (Proto 0x002A64A0, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_002A6310(int);
};

extern "C" int __cdecl sub_0023F760(int);

namespace pure3d {

class ParticlePointGenerator
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual int vfunc_05();
};

int ParticlePointGenerator::vfunc_05()
{
    int t1;

    t1 = sub_0023F760(72);
    if (t1) {
        return ((Object*)t1)->sub_002A6310((int)this);
    }
    return 0;
}

}

// ============================================================================
// [VERIFIED] pure3d::ParticlePointGenerator::vfunc_03 (0x002A68B0, 33 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as fight::Branch::vfunc_03 (0x0023B160), which was matched first;
// its addresses and names were swapped for this function's.
extern "C" void __cdecl sub_0023F7A0(void* p);

namespace pure3d {

class ParticlePointGenerator
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual ParticlePointGenerator* vfunc_03(unsigned int flags);
    void sub_002A6440();
};

#pragma optimize("y", off)
ParticlePointGenerator* ParticlePointGenerator::vfunc_03(unsigned int flags)
{
    sub_002A6440();
    if (flags & 1)
        sub_0023F7A0(this);
    return this;
}
#pragma optimize("", on)

}

