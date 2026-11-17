// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, pure3d/ParticleSphereGenerator.cpp (5 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 5 of 7 functions matched (71.43%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::ParticleSphereGenerator::vfunc_09 (0x002572D0, 34 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::ParticleSphereGenerator::vfunc_09 (Proto 0x002572D0, 34 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d {

class ParticleSphereGenerator
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
    virtual int vfunc_09(int a1, int a2);
    char m_pad04[0x34];
    int m_Field38; // +0x38
    int m_Field3C; // +0x3C
};

int ParticleSphereGenerator::vfunc_09(int a1, int a2)
{
    int r_eax;

    r_eax = a1;
    if (a1 != 3) {
        if (a1 != 6) goto L_1F;
        r_eax = a2;
        m_Field38 = a2;
        return r_eax;
    }
    m_Field3C = a2;
L_1F:
    return r_eax;
}

}

// ============================================================================
// [VERIFIED] pure3d::ParticleSphereGenerator::vfunc_10 (0x00257300, 22 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::ParticleSphereGenerator::vfunc_10 (Proto 0x00257300, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CD94;

namespace pure3d {

class ParticleSphereGenerator
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
    char m_pad04[0x34];
    float m_Field38; // +0x38
};

float ParticleSphereGenerator::vfunc_10(int a1)
{
    if (a1 != 6) {
        return DAT_0037CD94;
    }
    return m_Field38;
}

}

// ============================================================================
// [VERIFIED] pure3d::ParticleSphereGenerator::vfunc_11 (0x00257320, 12 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::ParticleSphereGenerator::vfunc_11 (Proto 0x00257320, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d {

class ParticleSphereGenerator
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
    char m_pad04[0x34];
    int m_Field38; // +0x38
    int m_Field3C; // +0x3C
};

int ParticleSphereGenerator::vfunc_11()
{
    m_Field38 = 0x3F800000;
    m_Field3C = 0x3F800000;
    return 0x3F800000;
}

}

// ============================================================================
// [VERIFIED] pure3d::ParticleSphereGenerator::vfunc_05 (0x00257CA0, 31 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::ParticleSphereGenerator::vfunc_05 (Proto 0x00257CA0, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00257B20(int);
};

extern "C" int __cdecl sub_001FCF20(int);

namespace pure3d {

class ParticleSphereGenerator
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual int vfunc_05();
};

int ParticleSphereGenerator::vfunc_05()
{
    int t1;

    t1 = sub_001FCF20(64);
    if (t1) {
        return ((Object*)t1)->sub_00257B20((int)this);
    }
    return 0;
}

}

// ============================================================================
// [VERIFIED] pure3d::ParticleSphereGenerator::vfunc_03 (0x00257D00, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionManager::CollisionManagerFlowClient::vfunc_00 (0x00016060), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::ParticleSphereGenerator::vfunc_03 (0x00257D00, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00257C30(void);
extern "C" void __cdecl sub_001FCF60(int);

namespace pure3d {

class ParticleSphereGenerator
{
public:
    virtual ParticleSphereGenerator* vfunc_03(int a1);
};

ParticleSphereGenerator* ParticleSphereGenerator::vfunc_03(int a1)
{
    sub_00257C30();
    if (a1 & 1) {
        sub_001FCF60((int)this);
    }
    return this;
}

}

