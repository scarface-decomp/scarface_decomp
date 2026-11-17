// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/CarDrivingRewardsObject.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 4 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] CarDrivingRewardsObject::vfunc_05 (0x001E0190, 39 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// CarDrivingRewardsObject::vfunc_05 (Proto 0x001E0190, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field168
{
    void sub_000B5720();
};

struct Field1A0
{
    void sub_000B56E0();
};

extern "C" void __stdcall sub_001E0120(int);

class CarDrivingRewardsObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int a1);
    char m_pad04[0x164];
    Field168 m_Field168; // +0x168
    char m_pad169[0x37];
    Field1A0 m_Field1A0; // +0x1A0
};

void CarDrivingRewardsObject::vfunc_05(int a1)
{
    sub_001E0120(a1);
    m_Field168.sub_000B5720();
    m_Field1A0.sub_000B56E0();
}

// ============================================================================
// [VERIFIED] CarDrivingRewardsObject::vfunc_00 (0x001E0630, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// CarDrivingRewardsObject::vfunc_00 (0x001E0630, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00426E90[];

class CarDrivingRewardsObject
{
public:
    virtual void* vfunc_00();
};

void* CarDrivingRewardsObject::vfunc_00()
{
    return DAT_00426E90;
}

// ============================================================================
// [VERIFIED] CarDrivingRewardsObject::vfunc_01 (0x001E0780, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Collidable::vfunc_03 (0x00011F20), which was matched first;
// its addresses and names were swapped for this function's.
// CarDrivingRewardsObject::vfunc_01 (0x001E0780, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001E0640(void);
extern "C" void __cdecl sub_00025160(int);

class CarDrivingRewardsObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual CarDrivingRewardsObject* vfunc_01(int a1);
};

CarDrivingRewardsObject* CarDrivingRewardsObject::vfunc_01(int a1)
{
    sub_001E0640();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] CarDrivingRewardsObject::vfunc_27 (0x001E0830, 68 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// CarDrivingRewardsObject::vfunc_27 (Proto 0x001E0830, 68 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field1C4
{
    void sub_000B6A40(int);
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

class CarDrivingRewardsObject
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
    char m_pad31[0x193];
    Field1C4 m_Field1C4; // +0x1C4
};

void CarDrivingRewardsObject::vfunc_27(int a1)
{
    int t2;

    if (m_Field30.sub_00026D50()) {
        t2 = m_Field30.sub_000D53A0();
        sub_001E06A0(t2);
        ((Object*)t2)->sub_000B5F80(a1, (int)this);
    }
    m_Field1C4.sub_000B6A40(a1);
}

