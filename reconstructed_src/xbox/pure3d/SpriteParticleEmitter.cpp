// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/SpriteParticleEmitter.cpp (6 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 6 of 17 functions matched (35.29%). NOT COMPLETE YET.
// The 11 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::SpriteParticleEmitter::vfunc_19 (0x0025DD00, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::SpriteParticleEmitter::vfunc_19 (0x0025DD00, 7 bytes)
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
    virtual int vfunc_19();
    char m_pad04[0x144];
    int m_Field148; // +0x148
};

int SpriteParticleEmitter::vfunc_19()
{
    return m_Field148;
}

}

// ============================================================================
// [VERIFIED] pure3d::SpriteParticleEmitter::vfunc_22 (0x0025DD10, 75 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::SpriteParticleEmitter::vfunc_22 (0x0025DD10, 75 bytes)
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
    char m_pad04[0x7C];
    int m_Field80; // +0x80
    char m_pad84[0xC0];
    int m_Field144; // +0x144
    char m_pad148[0xC];
    int m_Field154; // +0x154
    char m_pad158[0xC];
    int m_Field164; // +0x164
    char m_pad168[0x8];
    int m_Field170; // +0x170
    char m_pad174[0x8];
    int m_Field17C; // +0x17C
    char m_pad180[0x10];
    int m_Field190; // +0x190
    char m_pad194[0x8];
    int m_Field19C; // +0x19C
    char m_pad1A0[0x4];
    int m_Field1A4; // +0x1A4
    char m_pad1A8[0x4];
    int m_Field1AC; // +0x1AC
};

void SpriteParticleEmitter::vfunc_22()
{
    int r_eax, t1;

    r_eax = 0x3F800000;
    m_Field144 = 0x3F800000;
    m_Field154 = 0x3F800000;
    m_Field164 = 0x3F800000;
    m_Field170 = 0x3F800000;
    m_Field17C = 0x3F800000;
    m_Field190 = 0x3F800000;
    m_Field19C = 0x3F800000;
    m_Field1A4 = 0x3F800000;
    m_Field1AC = 0x3F800000;
    t1 = m_Field80;
    if (m_Field80) {
        r_eax = *(int*)t1;
        ((int (__cdecl*)(void))*(int*)(r_eax + 44))();
    }
}

}

// ============================================================================
// [VERIFIED] pure3d::SpriteParticleEmitter::vfunc_09 (0x0025DE30, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::SpriteParticleEmitter::vfunc_09 (0x0025DE30, 7 bytes)
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
    virtual int vfunc_09();
    char m_pad04[0x9C];
    int m_FieldA0; // +0xA0
};

int SpriteParticleEmitter::vfunc_09()
{
    return m_FieldA0;
}

}

// ============================================================================
// [VERIFIED] pure3d::SpriteParticleEmitter::vfunc_10 (0x0025F3B0, 54 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::SpriteParticleEmitter::vfunc_10 (0x0025F3B0, 54 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

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
    int r_edi, t2;

    r_edi = a1;
    if (a1) {
        ((Object*)r_edi)->vfunc_00();
    }
    t2 = m_FieldA0;
    if (m_FieldA0) {
        ((Object*)t2)->vfunc_01();
    }
    m_FieldA0 = r_edi;
    m_Field0C = 1;
}

}

// ============================================================================
// [VERIFIED] pure3d::SpriteParticleEmitter::vfunc_05 (0x0025FCE0, 34 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::SpriteParticleEmitter::vfunc_05 (0x0025FCE0, 34 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_0025FA00(int);
};

extern "C" int __cdecl sub_0023F760(int);

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

    t1 = sub_0023F760(476);
    if (t1) {
        return ((Object*)t1)->sub_0025FA00((int)this);
    }
    return 0;
}

}

// ============================================================================
// [VERIFIED] pure3d::SpriteParticleEmitter::vfunc_03 (0x0025FD10, 33 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as fight::Branch::vfunc_03 (0x0023B160), which was matched first;
// its addresses and names were swapped for this function's.
extern "C" void __cdecl sub_0023F7A0(void* p);

namespace pure3d {

class SpriteParticleEmitter
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual SpriteParticleEmitter* vfunc_03(unsigned int flags);
    void sub_0025FBB0();
};

#pragma optimize("y", off)
SpriteParticleEmitter* SpriteParticleEmitter::vfunc_03(unsigned int flags)
{
    sub_0025FBB0();
    if (flags & 1)
        sub_0023F7A0(this);
    return this;
}
#pragma optimize("", on)

}

