// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, pure3d/SpriteParticleEmitter.cpp (7 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 7 of 15 functions matched (46.67%). NOT COMPLETE YET.
// The 8 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::SpriteParticleEmitter::vfunc_21 (0x00258290, 69 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x00258290
// what: 
// tool: the portal's starter code (no AI)

// pure3d::SpriteParticleEmitter::vfunc_21 (Proto 0x00258290, 69 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
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
    char m_pad04[0x7C];
    int m_Field80; // +0x80
    char m_pad84[0xCC];
    int m_Field150; // +0x150
    char m_pad154[0xC];
    int m_Field160; // +0x160
    char m_pad164[0x8];
    int m_Field16C; // +0x16C
    char m_pad170[0x8];
    int m_Field178; // +0x178
    char m_pad17C[0x10];
    int m_Field18C; // +0x18C
    char m_pad190[0x8];
    int m_Field198; // +0x198
    char m_pad19C[0x4];
    int m_Field1A0; // +0x1A0
    char m_pad1A4[0x4];
    int m_Field1A8; // +0x1A8
};

void SpriteParticleEmitter::vfunc_21()
{
    int t1;

    m_Field150 = 0x3F800000;
    m_Field160 = 0x3F800000;
    m_Field16C = 0x3F800000;
    m_Field178 = 0x3F800000;
    m_Field18C = 0x3F800000;
    m_Field198 = 0x3F800000;
    m_Field1A0 = 0x3F800000;
    m_Field1A8 = 0x3F800000;
    t1 = m_Field80;
    if (m_Field80) {
        ((Object*)t1)->vfunc_11();
        return;
    }
}

}

// ============================================================================
// [VERIFIED] pure3d::SpriteParticleEmitter::vfunc_12 (0x00258390, 22 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::SpriteParticleEmitter::vfunc_12 (0x0025DE40), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x00258390
// what: Returns bit 2 of the flags byte at +0x16 of the object pointed to at +0xA0, or false when the pointer is null.
// tool: Gemini 4 Neon

namespace pure3d {

struct Shader_00258390
{
    char m_pad00[0x16];
    unsigned char m_Bits01 : 2;
    unsigned char m_Bit2 : 1; // +0x16 bit 2
};

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
    virtual bool vfunc_12();
    char m_pad04[0x9C];
    Shader_00258390* m_FieldA0; // +0xA0
};

bool SpriteParticleEmitter::vfunc_12()
{
    if (m_FieldA0)
        return m_FieldA0->m_Bit2;
    return false;
}

}

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
// [VERIFIED] pure3d::SpriteParticleEmitter::vfunc_30 (0x00259910, 55 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x00259910
// what: 
// tool: the portal's starter code (no AI)

// pure3d::SpriteParticleEmitter::vfunc_30 (Proto 0x00259910, 55 bytes)
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
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30(int a1);
    char m_pad04[0x78];
    int m_Field7C; // +0x7C
};

void SpriteParticleEmitter::vfunc_30(int a1)
{
    int t3;

    if (a1 != m_Field7C) {
        vfunc_20();
        if (a1 == m_Field7C) goto L_32;
        if (a1) {
            ((Object*)a1)->vfunc_00();
        }
        t3 = m_Field7C;
        if (m_Field7C) {
            ((Object*)t3)->vfunc_01();
        }
        m_Field7C = a1;
    }
L_32:
    ;
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

