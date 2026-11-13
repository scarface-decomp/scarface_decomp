// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/NISObjectPositionTrack.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 3 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] NISObjectPositionTrack::vfunc_08 (0x00185730, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SpeedCondition::vfunc_08 (0x000DD280), which was matched first;
// its addresses and names were swapped for this function's.
// NISObjectPositionTrack::vfunc_08 (0x00185730, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0048C060;

class NISObjectPositionTrack
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

int NISObjectPositionTrack::vfunc_08(int a1)
{
    return *(int*)(DAT_0048C060 + (a1 * 4));
}

// ============================================================================
// [VERIFIED] NISObjectPositionTrack::vfunc_20 (0x00185740, 46 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CameraShakeTrack::vfunc_20 (0x000E8120), which was matched first;
// its addresses and names were swapped for this function's.
// NISObjectPositionTrack::vfunc_20 (0x00185740, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_0017EBF0(int, int);
};

extern "C" int DAT_0041A400;
extern "C" int __cdecl sub_000275B0(int, int);

class NISObjectPositionTrack
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

int NISObjectPositionTrack::vfunc_20(int a1)
{
    int t2;

    t2 = sub_000275B0(12, DAT_0041A400);
    if (t2) {
        return ((Object*)t2)->sub_0017EBF0((int)this, a1);
    }
    return 0;
}

// ============================================================================
// [VERIFIED] NISObjectPositionTrack::vfunc_03 (0x00186310, 46 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as LocomotionAnimDataTrack::vfunc_03 (0x000E9890), which was matched first;
// its addresses and names were swapped for this function's.
// NISObjectPositionTrack::vfunc_03 (0x00186310, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field14
{
    void sub_002A9290();
};

extern "C" char DAT_003B782C[];
extern "C" void __cdecl sub_0023F7A0(int);

class NISObjectPositionTrack
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual NISObjectPositionTrack* vfunc_03(int a1);
    void sub_00022970();
    char m_pad04[0x10];
    Field14 m_Field14; // +0x14
};

NISObjectPositionTrack* NISObjectPositionTrack::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_003B782C;
    m_Field14.sub_002A9290();
    sub_00022970();
    if (a1 & 1) {
        sub_0023F7A0((int)this);
    }
    return this;
}

