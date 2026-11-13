// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, audio/SeqEventCondition.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 5 functions matched (80.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::SeqEventCondition::vfunc_01 (0x002D9810, 64 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::SeqEventCondition::vfunc_01 (0x002D9810, 64 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_002CEFF0(int, int);
extern "C" bool __stdcall sub_002D6A20(int);

namespace audio {

class SeqEventCondition
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1);
    bool sub_002D6DA0(int);
};

int SeqEventCondition::vfunc_01(int a1)
{
    if (sub_002D6A20(a1)) {
        if (!sub_002D6DA0(a1)) goto L_39;
        if (!sub_002CEFF0(a1, (int)this + 16)) goto L_39;
        return 1;
    }
L_39:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventCondition::vfunc_00 (0x002D9880, 64 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventCondition::vfunc_01 (0x002D9810), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventCondition::vfunc_00 (0x002D9880, 64 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_002CF040(int, int);
extern "C" bool __stdcall sub_002D6A00(int);

namespace audio {

class SeqEventCondition
{
public:
    virtual void vfunc_00();
    virtual int vfunc_00(int a1);
    bool sub_002D6D30(int);
};

int SeqEventCondition::vfunc_00(int a1)
{
    if (sub_002D6A00(a1)) {
        if (!sub_002D6D30(a1)) goto L_39;
        if (!sub_002CF040(a1, (int)this + 16)) goto L_39;
        return 1;
    }
L_39:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventCondition::vfunc_03 (0x002D98F0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (0x002D8D80), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventCondition::vfunc_03 (0x002D98F0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004C04A4;

namespace audio {

class SeqEventCondition
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventCondition::vfunc_03()
{
    return DAT_004C04A4;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventCondition::vfunc_04 (0x002D9900, 72 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::SeqEventCondition::vfunc_04 (0x002D9900, 72 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field10
{
    void sub_002CE560();
};

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int);
};

extern "C" char DAT_003E0960[];
extern "C" char DAT_004640A4[];
extern "C" void __cdecl sub_002CF980(int, int);

namespace audio {

class SeqEventCondition
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual SeqEventCondition* vfunc_04(int a1);
    void sub_002D6F30();
    char m_pad04[0xC];
    Field10 m_Field10; // +0x10
    char m_pad11[0xB];
    int m_Field1C; // +0x1C
};

SeqEventCondition* SeqEventCondition::vfunc_04(int a1)
{
    int t1;

    t1 = m_Field1C;
    *(int*)this = (int)DAT_003E0960;
    if (m_Field1C) {
        ((Object*)t1)->vfunc_04(1);
        m_Field1C = 0;
    }
    m_Field10.sub_002CE560();
    sub_002D6F30();
    if (a1 & 1) {
        sub_002CF980((int)DAT_004640A4, (int)this);
    }
    return this;
}

}

