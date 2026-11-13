// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/RandomWaterObjectTemplate.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 5 functions matched (80.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] RandomWaterObjectTemplate::vfunc_05 (0x001C5640, 25 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as RandomWaterObjectTemplate::vfunc_04 (0x00200C00), which was matched first;
// its addresses and names were swapped for this function's.
// RandomWaterObjectTemplate::vfunc_05 (0x001C5640, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field24
{
    void sub_0009C990();
};

extern "C" void __stdcall sub_00028C40(int);

class RandomWaterObjectTemplate
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_05(int a1);
    char m_pad04[0x20];
    Field24 m_Field24; // +0x24
};

void RandomWaterObjectTemplate::vfunc_05(int a1)
{
    sub_00028C40(a1);
    m_Field24.sub_0009C990();
}

// ============================================================================
// [VERIFIED] RandomWaterObjectTemplate::vfunc_00 (0x001C5740, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// RandomWaterObjectTemplate::vfunc_00 (0x001C5740, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0041BDC0[];

class RandomWaterObjectTemplate
{
public:
    virtual void* vfunc_00();
};

void* RandomWaterObjectTemplate::vfunc_00()
{
    return DAT_0041BDC0;
}

// ============================================================================
// [VERIFIED] RandomWaterObjectTemplate::vfunc_12 (0x001C5770, 17 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as ParticleEffectTemplate::vfunc_11 (0x001FC130), which was matched first;
// its addresses and names were swapped for this function's.
// RandomWaterObjectTemplate::vfunc_12 (0x001C5770, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field24
{
    void sub_0009B2B0();
};

class RandomWaterObjectTemplate
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
    virtual void vfunc_12();
    char m_pad04[0x1E];
    bool m_Field22; // +0x22
    char m_pad23[0x1];
    Field24 m_Field24; // +0x24
};

void RandomWaterObjectTemplate::vfunc_12()
{
    m_Field24.sub_0009B2B0();
    m_Field22 = false;
}

// ============================================================================
// [VERIFIED] RandomWaterObjectTemplate::vfunc_01 (0x001C5800, 52 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as FireTemplate::vfunc_01 (0x00188930), which was matched first;
// its addresses and names were swapped for this function's.
// RandomWaterObjectTemplate::vfunc_01 (0x001C5800, 52 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field24
{
    void sub_0009E120();
};

extern "C" char DAT_0037F29C[];
extern "C" char DAT_003A5A7C[];
extern "C" void __cdecl sub_00025160(int);

class RandomWaterObjectTemplate
{
public:
    virtual void vfunc_00();
    virtual RandomWaterObjectTemplate* vfunc_01(int a1);
    void sub_00029C00();
    char m_pad04[0x20];
    Field24 m_Field24; // +0x24
};

RandomWaterObjectTemplate* RandomWaterObjectTemplate::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003A5A7C;
    m_Field24.sub_0009E120();
    *(int*)this = (int)DAT_0037F29C;
    sub_00029C00();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

