// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, pure3d/SpriteParticleEmitter.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 15 functions matched (26.67%). NOT COMPLETE YET.
// The 11 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::SpriteParticleEmitter::vfunc_26 (0x002583B0, 7 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::SpriteParticleEmitter::vfunc_26 (Proto 0x002583B0, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d {

class SpriteParticleEmitter
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
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual bool vfunc_26();
    char m_pad04[0x12C];
    bool m_Field130; // +0x130
};

bool SpriteParticleEmitter::vfunc_26()
{
    return m_Field130;
}

}

// ============================================================================
// [VERIFIED] pure3d::SpriteParticleEmitter::vfunc_10 (0x002598D0, 51 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::SpriteParticleEmitter::vfunc_10 (Proto 0x002598D0, 51 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

namespace pure3d {

class SpriteParticleEmitter
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
    virtual void vfunc_10(int a1);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    char m_pad10[0x90];
    int m_FieldA0; // +0xA0
};

void SpriteParticleEmitter::vfunc_10(int a1)
{
    int t2;

    if (a1) {
        ((Object*)a1)->vfunc_00();
    }
    t2 = m_FieldA0;
    if (m_FieldA0) {
        ((Object*)t2)->vfunc_01();
    }
    m_FieldA0 = a1;
    m_Field0C = 1;
}

}

// ============================================================================
// [VERIFIED] pure3d::SpriteParticleEmitter::vfunc_05 (0x0025A950, 34 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::SpriteParticleEmitter::vfunc_05 (Proto 0x0025A950, 34 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_0025A690(int);
};

extern "C" int __cdecl sub_001FCF20(int);

namespace pure3d {

class SpriteParticleEmitter
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual int vfunc_05();
};

int SpriteParticleEmitter::vfunc_05()
{
    int t1;

    t1 = sub_001FCF20(472);
    if (t1) {
        return ((Object*)t1)->sub_0025A690((int)this);
    }
    return 0;
}

}

// ============================================================================
// [VERIFIED] pure3d::SpriteParticleEmitter::vfunc_03 (0x0025AD60, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionManager::CollisionManagerFlowClient::vfunc_00 (0x00016060), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::SpriteParticleEmitter::vfunc_03 (0x0025AD60, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0025A830(void);
extern "C" void __cdecl sub_001FCF60(int);

namespace pure3d {

class SpriteParticleEmitter
{
public:
    virtual SpriteParticleEmitter* vfunc_03(int a1);
};

SpriteParticleEmitter* SpriteParticleEmitter::vfunc_03(int a1)
{
    sub_0025A830();
    if (a1 & 1) {
        sub_001FCF60((int)this);
    }
    return this;
}

}

