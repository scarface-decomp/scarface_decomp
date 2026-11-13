// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, audio/SeqEventCondition.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 5 functions matched (60.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_PC_1002.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::SeqEventCondition::vfunc_01 (0x006F7410, 64 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventCondition::vfunc_01 (0x002D9810), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventCondition::vfunc_01 (0x006F7410, 64 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_006ECBD0(int, int);
extern "C" bool __stdcall sub_006F5760(int);

namespace audio {

class SeqEventCondition
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1);
    bool sub_006F5AC0(int);
};

int SeqEventCondition::vfunc_01(int a1)
{
    if (sub_006F5760(a1)) {
        if (!sub_006F5AC0(a1)) goto L_39;
        if (!sub_006ECBD0(a1, (int)this + 16)) goto L_39;
        return 1;
    }
L_39:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventCondition::vfunc_00 (0x006F7480, 64 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventCondition::vfunc_01 (0x002D9810), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventCondition::vfunc_00 (0x006F7480, 64 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_006ECC20(int, int);
extern "C" bool __stdcall sub_006F5740(int);

namespace audio {

class SeqEventCondition
{
public:
    virtual void vfunc_00();
    virtual int vfunc_00(int a1);
    bool sub_006F5A60(int);
};

int SeqEventCondition::vfunc_00(int a1)
{
    if (sub_006F5740(a1)) {
        if (!sub_006F5A60(a1)) goto L_39;
        if (!sub_006ECC20(a1, (int)this + 16)) goto L_39;
        return 1;
    }
L_39:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventCondition::vfunc_04 (0x006F7500, 72 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventCondition::vfunc_04 (0x002D9900), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventCondition::vfunc_04 (0x006F7500, 72 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field10
{
    void sub_006EBBD0();
};

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int);
};

extern "C" char DAT_007730EC[];
extern "C" char DAT_007F732C[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqEventCondition
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual SeqEventCondition* vfunc_04(int a1);
    void sub_006F5C50();
    char m_pad04[0xC];
    Field10 m_Field10; // +0x10
    char m_pad11[0xB];
    int m_Field1C; // +0x1C
};

SeqEventCondition* SeqEventCondition::vfunc_04(int a1)
{
    int t1;

    t1 = m_Field1C;
    *(int*)this = (int)DAT_007730EC;
    if (m_Field1C) {
        ((Object*)t1)->vfunc_04(1);
        m_Field1C = 0;
    }
    m_Field10.sub_006EBBD0();
    sub_006F5C50();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F732C, (int)this);
    }
    return this;
}

}

