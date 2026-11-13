// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/NISCharacterDamageTrack.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 3 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] NISCharacterDamageTrack::vfunc_08 (0x00184F40, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SpeedCondition::vfunc_08 (0x000DD280), which was matched first;
// its addresses and names were swapped for this function's.
// NISCharacterDamageTrack::vfunc_08 (0x00184F40, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0048BFF0;

class NISCharacterDamageTrack
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

int NISCharacterDamageTrack::vfunc_08(int a1)
{
    return *(int*)(DAT_0048BFF0 + (a1 * 4));
}

// ============================================================================
// [VERIFIED] NISCharacterDamageTrack::vfunc_20 (0x00184F90, 46 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CameraShakeTrack::vfunc_20 (0x000E8120), which was matched first;
// its addresses and names were swapped for this function's.
// NISCharacterDamageTrack::vfunc_20 (0x00184F90, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_0017E770(int, int);
};

extern "C" int DAT_0041A400;
extern "C" int __cdecl sub_000275B0(int, int);

class NISCharacterDamageTrack
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

int NISCharacterDamageTrack::vfunc_20(int a1)
{
    int t2;

    t2 = sub_000275B0(12, DAT_0041A400);
    if (t2) {
        return ((Object*)t2)->sub_0017E770((int)this, a1);
    }
    return 0;
}

// ============================================================================
// [VERIFIED] NISCharacterDamageTrack::vfunc_03 (0x00185EE0, 54 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// NISCharacterDamageTrack::vfunc_03 (0x00185EE0, 54 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field18
{
    void sub_002A9290();
};

extern "C" char DAT_003B70BC[];
extern "C" void __cdecl sub_0023F7A0(int);

class NISCharacterDamageTrack
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual NISCharacterDamageTrack* vfunc_03(int a1);
    void sub_00022970();
    char m_pad04[0x10];
    Field18 m_Field14; // +0x14
    char m_pad15[0x3];
    Field18 m_Field18; // +0x18
};

NISCharacterDamageTrack* NISCharacterDamageTrack::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_003B70BC;
    m_Field18.sub_002A9290();
    m_Field14.sub_002A9290();
    sub_00022970();
    if (a1 & 1) {
        sub_0023F7A0((int)this);
    }
    return this;
}

