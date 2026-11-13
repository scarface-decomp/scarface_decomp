// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/NISExpAnimationTrack.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 3 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] NISExpAnimationTrack::vfunc_08 (0x00163C90, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SpeedCondition::vfunc_08 (0x000DD280), which was matched first;
// its addresses and names were swapped for this function's.
// NISExpAnimationTrack::vfunc_08 (0x00163C90, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0045DEE8;

class NISExpAnimationTrack
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
    virtual int vfunc_08(int a1);
};

int NISExpAnimationTrack::vfunc_08(int a1)
{
    return *(int*)(DAT_0045DEE8 + (a1 * 4));
}

// ============================================================================
// [VERIFIED] NISExpAnimationTrack::vfunc_20 (0x00163CE0, 46 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as JointCollisionTrack::vfunc_20 (0x000E8380), which was matched first;
// its addresses and names were swapped for this function's.
// NISExpAnimationTrack::vfunc_20 (0x00163CE0, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_0015F610(int, int);
};

extern "C" int DAT_003F52D0;
extern "C" int __cdecl sub_00025140(int, int);

class NISExpAnimationTrack
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
    virtual int vfunc_20(int a1);
};

int NISExpAnimationTrack::vfunc_20(int a1)
{
    int t2;

    t2 = sub_00025140(28, DAT_003F52D0);
    if (t2) {
        return ((Object*)t2)->sub_0015F610((int)this, a1);
    }
    return 0;
}

// ============================================================================
// [VERIFIED] NISExpAnimationTrack::vfunc_03 (0x00164650, 62 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as NISCharacterAttachTrack::vfunc_03 (0x00186030), which was matched first;
// its addresses and names were swapped for this function's.
// NISExpAnimationTrack::vfunc_03 (0x00164650, 62 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field1C
{
    void sub_001B7A10();
};

extern "C" char DAT_0039540C[];
extern "C" void __cdecl sub_001FCF60(int);

class NISExpAnimationTrack
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual NISExpAnimationTrack* vfunc_03(int a1);
    void sub_00020600();
    char m_pad04[0x10];
    Field1C m_Field14; // +0x14
    char m_pad15[0x3];
    Field1C m_Field18; // +0x18
    char m_pad19[0x3];
    Field1C m_Field1C; // +0x1C
};

NISExpAnimationTrack* NISExpAnimationTrack::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_0039540C;
    m_Field1C.sub_001B7A10();
    m_Field18.sub_001B7A10();
    m_Field14.sub_001B7A10();
    sub_00020600();
    if (a1 & 1) {
        sub_001FCF60((int)this);
    }
    return this;
}

