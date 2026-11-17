// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, audio/SeqEventCondition.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 7 functions matched (57.14%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::SeqEventCondition::vfunc_01 (0x002A3610, 64 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::SeqEventCondition::vfunc_01 (Proto 0x002A3610, 64 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_00292810(int, int);
extern "C" bool __stdcall sub_0029E730(int);

namespace audio {

class SeqEventCondition
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1);
    bool sub_0029ECF0(int);
};

int SeqEventCondition::vfunc_01(int a1)
{
    if (sub_0029E730(a1)) {
        if (!sub_0029ECF0(a1)) goto L_39;
        if (!sub_00292810(a1, (int)this + 56)) goto L_39;
        return 1;
    }
L_39:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventCondition::vfunc_00 (0x002A36E0, 64 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::SeqEventCondition::vfunc_00 (Proto 0x002A36E0, 64 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_002928C0(int, int);
extern "C" bool __stdcall sub_0029E710(int);

namespace audio {

class SeqEventCondition
{
public:
    virtual int vfunc_00(int a1);
    bool sub_0029EBC0(int);
};

int SeqEventCondition::vfunc_00(int a1)
{
    if (sub_0029E710(a1)) {
        if (!sub_0029EBC0(a1)) goto L_39;
        if (!sub_002928C0(a1, (int)this + 56)) goto L_39;
        return 1;
    }
L_39:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventCondition::vfunc_05 (0x002A37B0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dFBEffectsShader::vfunc_04 (0x0029F440), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventCondition::vfunc_05 (0x002A37B0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00490FD0;

namespace audio {

class SeqEventCondition
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual int vfunc_05();
};

int SeqEventCondition::vfunc_05()
{
    return DAT_00490FD0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventCondition::vfunc_06 (0x002A37C0, 72 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::SeqEventCondition::vfunc_06 (Proto 0x002A37C0, 72 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field38
{
    void sub_00291040();
};

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06(int);
};

extern "C" char DAT_003BA2C4[];
extern "C" char DAT_00490FE0[];
extern "C" void __cdecl sub_002935D0(int, int);

namespace audio {

class SeqEventCondition
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual SeqEventCondition* vfunc_06(int a1);
    void sub_0029EEB0();
    char m_pad04[0x34];
    Field38 m_Field38; // +0x38
    char m_pad39[0xB];
    int m_Field44; // +0x44
};

SeqEventCondition* SeqEventCondition::vfunc_06(int a1)
{
    int t1;

    t1 = m_Field44;
    *(int*)this = (int)DAT_003BA2C4;
    if (m_Field44) {
        ((Object*)t1)->vfunc_06(1);
        m_Field44 = 0;
    }
    m_Field38.sub_00291040();
    sub_0029EEB0();
    if (a1 & 1) {
        sub_002935D0((int)DAT_00490FE0, (int)this);
    }
    return this;
}

}

