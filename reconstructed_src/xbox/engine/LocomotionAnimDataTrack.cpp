// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/LocomotionAnimDataTrack.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 3 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] LocomotionAnimDataTrack::vfunc_08 (0x000E9840, 25 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// LocomotionAnimDataTrack::vfunc_08 (0x000E9840, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00427184[];

class LocomotionAnimDataTrack
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

int LocomotionAnimDataTrack::vfunc_08(int a1)
{
    int r_eax;

    r_eax = 0;
    if (a1 >= 0) {
        if ((unsigned int)a1 >= (unsigned int)3) goto L_16;
        r_eax = DAT_00427184[a1];
    }
L_16:
    return r_eax;
}

// ============================================================================
// [VERIFIED] LocomotionAnimDataTrack::vfunc_03 (0x000E9890, 46 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// LocomotionAnimDataTrack::vfunc_03 (0x000E9890, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field14
{
    void sub_002A9290();
};

extern "C" char DAT_003A8C8C[];
extern "C" void __cdecl sub_0023F7A0(int);

class LocomotionAnimDataTrack
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual LocomotionAnimDataTrack* vfunc_03(int a1);
    void sub_00022970();
    char m_pad04[0x10];
    Field14 m_Field14; // +0x14
};

LocomotionAnimDataTrack* LocomotionAnimDataTrack::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_003A8C8C;
    m_Field14.sub_002A9290();
    sub_00022970();
    if (a1 & 1) {
        sub_0023F7A0((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] LocomotionAnimDataTrack::vfunc_22 (0x000E98C0, 70 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// LocomotionAnimDataTrack::vfunc_22 (0x000E98C0, 70 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_000DAFC0(int);
    bool sub_00163DB0();
};

extern "C" int __cdecl sub_0002AC90(int);

class LocomotionAnimDataTrack
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
    virtual bool vfunc_22(int a1);
};

bool LocomotionAnimDataTrack::vfunc_22(int a1)
{
    int t1;

    if (a1) {
        t1 = *(int*)(a1 + 16);
        if (!*(int*)(a1 + 16)) goto L_3F;
        if (((Object*)sub_0002AC90(*(int*)(a1 + 28)))->sub_00163DB0()) goto L_3F;
        return ((Object*)t1)->sub_000DAFC0((int)this + 20);
    }
L_3F:
    return true;
}

