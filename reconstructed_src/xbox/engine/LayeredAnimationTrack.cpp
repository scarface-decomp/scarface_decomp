// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/LayeredAnimationTrack.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 4 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] LayeredAnimationTrack::vfunc_33 (0x000E9570, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as GlobalVehicleSound::vfunc_12 (0x00065430), which was matched first;
// its addresses and names were swapped for this function's.
// LayeredAnimationTrack::vfunc_33 (0x000E9570, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004878C8;

class LayeredAnimationTrack
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
    virtual int vfunc_33();
};

int LayeredAnimationTrack::vfunc_33()
{
    return DAT_004878C8;
}

// ============================================================================
// [VERIFIED] LayeredAnimationTrack::vfunc_08 (0x000E95A0, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SpeedCondition::vfunc_08 (0x000DD280), which was matched first;
// its addresses and names were swapped for this function's.
// LayeredAnimationTrack::vfunc_08 (0x000E95A0, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004878CC;

class LayeredAnimationTrack
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

int LayeredAnimationTrack::vfunc_08(int a1)
{
    return *(int*)(DAT_004878CC + (a1 * 4));
}

// ============================================================================
// [VERIFIED] LayeredAnimationTrack::vfunc_20 (0x000E95B0, 42 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as LayeredAnimationTrack::vfunc_20 (Proto 0x000D6F20), which was matched first;
// its addresses and names were swapped for this function's.
// LayeredAnimationTrack::vfunc_20 (Proto 0x000E95B0, 42 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_000E5300(int, int);
};

extern "C" int __cdecl sub_000275B0(int, int);

class LayeredAnimationTrack
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

int LayeredAnimationTrack::vfunc_20(int a1)
{
    int t1;

    t1 = sub_000275B0(20, 10);
    if (t1) {
        return ((Object*)t1)->sub_000E5300((int)this, a1);
    }
    return 0;
}

// ============================================================================
// [VERIFIED] LayeredAnimationTrack::vfunc_03 (0x000E9640, 46 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: LayeredAnimationTrack's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// Same machine code as Animation360Track::vfunc_03 (0x000E7400), which was matched first;
// its addresses and names were swapped for this function's.
// LayeredAnimationTrack::vfunc_03 (0x000E9640, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field1C
{
    void sub_002A9290();
};

extern "C" char DAT_003A8B0C[];
extern "C" void __cdecl sub_0023F7A0(int);

class LayeredAnimationTrack
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual LayeredAnimationTrack* vfunc_03(int a1);
    void sub_00022970();
    char m_pad04[0x18];
    Field1C m_Field1C; // +0x1C
};

LayeredAnimationTrack* LayeredAnimationTrack::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_003A8B0C;
    m_Field1C.sub_002A9290();
    sub_00022970();
    if (a1 & 1) {
        sub_0023F7A0((int)this);
    }
    return this;
}

