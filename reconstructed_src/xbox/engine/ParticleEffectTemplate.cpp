// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/ParticleEffectTemplate.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 4 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ParticleEffectTemplate::vfunc_00 (0x001FC100, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns ParticleEffectTemplate's static class record (ConcreteClassRep<ParticleEffectTemplate>), the object's run-time type.
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// ParticleEffectTemplate::vfunc_00 (0x001FC100, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00440180[];

class ParticleEffectTemplate
{
public:
    virtual void* vfunc_00();
};

void* ParticleEffectTemplate::vfunc_00()
{
    return DAT_00440180;
}

// ============================================================================
// [VERIFIED] ParticleEffectTemplate::vfunc_10 (0x001FC110, 20 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Marks the particle effect template active at +0x22 and calls sub_00087430 on m_Field24 with m_Field20.
// ============================================================================
// bin: xb
// va: 0x001FC110
// what: Marks the particle effect template active at +0x22 and calls sub_00087430 on m_Field24 with m_Field20.
// tool: Gemini 4 Neon

struct Field24_001FC110
{
    void sub_00087430(unsigned short value);
};

class ParticleEffectTemplate
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
    char m_pad04[0x1C];
    unsigned short m_Field20; // +0x20
    bool m_Field22; // +0x22
    char m_pad23[0x1];
    Field24_001FC110 m_Field24; // +0x24
};

void ParticleEffectTemplate::vfunc_10()
{
    m_Field22 = true;
    m_Field24.sub_00087430(m_Field20);
}

// ============================================================================
// [VERIFIED] ParticleEffectTemplate::vfunc_11 (0x001FC130, 17 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ParticleEffectTemplate::vfunc_11 (0x001FC130, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field24
{
    void sub_002A9290();
};

class ParticleEffectTemplate
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
    char m_pad04[0x1E];
    bool m_Field22; // +0x22
    char m_pad23[0x1];
    Field24 m_Field24; // +0x24
};

void ParticleEffectTemplate::vfunc_11()
{
    m_Field24.sub_002A9290();
    m_Field22 = false;
}

// ============================================================================
// [VERIFIED] ParticleEffectTemplate::vfunc_01 (0x001FC1E0, 52 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: ParticleEffectTemplate's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// Same machine code as FireTemplate::vfunc_01 (0x00188930), which was matched first;
// its addresses and names were swapped for this function's.
// ParticleEffectTemplate::vfunc_01 (0x001FC1E0, 52 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field24
{
    void sub_002A9290();
};

extern "C" char DAT_0039FE34[];
extern "C" char DAT_003CAEBC[];
extern "C" void __cdecl sub_00027600(int);

class ParticleEffectTemplate
{
public:
    virtual void vfunc_00();
    virtual ParticleEffectTemplate* vfunc_01(int a1);
    void sub_0002C720();
    char m_pad04[0x20];
    Field24 m_Field24; // +0x24
};

ParticleEffectTemplate* ParticleEffectTemplate::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003CAEBC;
    m_Field24.sub_002A9290();
    *(int*)this = (int)DAT_0039FE34;
    sub_0002C720();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

