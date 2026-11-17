// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, pure3d/ParticlePointGenerator.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 7 functions matched (42.86%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::ParticlePointGenerator::vfunc_11 (0x00256900, 15 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::ParticlePointGenerator::vfunc_11 (Proto 0x00256900, 15 bytes)
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
// [VERIFIED] pure3d::ParticlePointGenerator::vfunc_05 (0x002578B0, 31 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::ParticlePointGenerator::vfunc_05 (Proto 0x002578B0, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00257730(int);
};

extern "C" int __cdecl sub_001FCF20(int);

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

    t1 = sub_001FCF20(72);
    if (t1) {
        return ((Object*)t1)->sub_00257730((int)this);
    }
    return 0;
}

}

// ============================================================================
// [VERIFIED] pure3d::ParticlePointGenerator::vfunc_03 (0x00257CC0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionManager::CollisionManagerFlowClient::vfunc_00 (0x00016060), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::ParticlePointGenerator::vfunc_03 (0x00257CC0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00257840(void);
extern "C" void __cdecl sub_001FCF60(int);

namespace pure3d {

class ParticlePointGenerator
{
public:
    virtual ParticlePointGenerator* vfunc_03(int a1);
};

ParticlePointGenerator* ParticlePointGenerator::vfunc_03(int a1)
{
    sub_00257840();
    if (a1 & 1) {
        sub_001FCF60((int)this);
    }
    return this;
}

}

