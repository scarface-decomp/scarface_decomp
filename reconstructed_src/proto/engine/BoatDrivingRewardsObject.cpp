// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/BoatDrivingRewardsObject.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 4 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] BoatDrivingRewardsObject::vfunc_05 (0x001E0180, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundEntityLoader::vfunc_04 (0x00064FA0), which was matched first;
// its addresses and names were swapped for this function's.
// BoatDrivingRewardsObject::vfunc_05 (0x001E0180, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001E0120(void);

class BoatDrivingRewardsObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_05();
};

void BoatDrivingRewardsObject::vfunc_05()
{
    sub_001E0120();
}

// ============================================================================
// [VERIFIED] BoatDrivingRewardsObject::vfunc_00 (0x001E0540, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// BoatDrivingRewardsObject::vfunc_00 (0x001E0540, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00426E64[];

class BoatDrivingRewardsObject
{
public:
    virtual void* vfunc_00();
};

void* BoatDrivingRewardsObject::vfunc_00()
{
    return DAT_00426E64;
}

// ============================================================================
// [VERIFIED] BoatDrivingRewardsObject::vfunc_01 (0x001E0760, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Collidable::vfunc_03 (0x00011F20), which was matched first;
// its addresses and names were swapped for this function's.
// BoatDrivingRewardsObject::vfunc_01 (0x001E0760, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001E0550(void);
extern "C" void __cdecl sub_00025160(int);

class BoatDrivingRewardsObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual BoatDrivingRewardsObject* vfunc_01(int a1);
};

BoatDrivingRewardsObject* BoatDrivingRewardsObject::vfunc_01(int a1)
{
    sub_001E0550();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] BoatDrivingRewardsObject::vfunc_27 (0x001E07E0, 68 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// BoatDrivingRewardsObject::vfunc_27 (Proto 0x001E07E0, 68 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field184
{
    void sub_000B69D0(int);
};

struct Field30
{
    int sub_00026D50();
    int sub_000D53A0();
};

struct Object
{
    void sub_000B5F80(int, int);
};

extern "C" void __cdecl sub_001E06A0(int);

class BoatDrivingRewardsObject
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
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27(int a1);
    char m_pad04[0x2C];
    Field30 m_Field30; // +0x30
    char m_pad31[0x153];
    Field184 m_Field184; // +0x184
};

void BoatDrivingRewardsObject::vfunc_27(int a1)
{
    int t2;

    if (m_Field30.sub_00026D50()) {
        t2 = m_Field30.sub_000D53A0();
        sub_001E06A0(t2);
        ((Object*)t2)->sub_000B5F80(a1, (int)this);
    }
    m_Field184.sub_000B69D0(a1);
}

