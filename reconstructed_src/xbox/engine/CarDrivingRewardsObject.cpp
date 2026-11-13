// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/CarDrivingRewardsObject.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 4 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] CarDrivingRewardsObject::vfunc_04 (0x0021C560, 39 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// CarDrivingRewardsObject::vfunc_04 (0x0021C560, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field170
{
    void sub_000C3040();
};

struct Field1A8
{
    void sub_000C2FF0();
};

extern "C" void __stdcall sub_0021C4F0(int);

class CarDrivingRewardsObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int a1);
    char m_pad04[0x16C];
    Field170 m_Field170; // +0x170
    char m_pad171[0x37];
    Field1A8 m_Field1A8; // +0x1A8
};

void CarDrivingRewardsObject::vfunc_04(int a1)
{
    sub_0021C4F0(a1);
    m_Field170.sub_000C3040();
    m_Field1A8.sub_000C2FF0();
}

// ============================================================================
// [VERIFIED] CarDrivingRewardsObject::vfunc_00 (0x0021C800, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// CarDrivingRewardsObject::vfunc_00 (0x0021C800, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0044D490[];

class CarDrivingRewardsObject
{
public:
    virtual void* vfunc_00();
};

void* CarDrivingRewardsObject::vfunc_00()
{
    return DAT_0044D490;
}

// ============================================================================
// [VERIFIED] CarDrivingRewardsObject::vfunc_01 (0x0021C8F0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Collidable::vfunc_03 (0x00011F20), which was matched first;
// its addresses and names were swapped for this function's.
// CarDrivingRewardsObject::vfunc_01 (0x0021C8F0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0021C810(void);
extern "C" void __cdecl sub_00027600(int);

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
    sub_0021C810();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] CarDrivingRewardsObject::vfunc_29 (0x0021CC00, 68 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// CarDrivingRewardsObject::vfunc_29 (0x0021CC00, 68 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field1CC
{
    void sub_000C42F0(int);
};

struct Field30
{
    int sub_000CE970();
    int sub_0017E700();
};

struct Object
{
    void sub_000C38A0(int, int);
};

extern "C" void __cdecl sub_0021CB10(int);

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
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29(int a1);
    char m_pad04[0x2C];
    Field30 m_Field30; // +0x30
    char m_pad31[0x19B];
    Field1CC m_Field1CC; // +0x1CC
};

void CarDrivingRewardsObject::vfunc_29(int a1)
{
    int t2;

    if (m_Field30.sub_000CE970()) {
        t2 = m_Field30.sub_0017E700();
        sub_0021CB10(t2);
        ((Object*)t2)->sub_000C38A0(a1, (int)this);
    }
    m_Field1CC.sub_000C42F0(a1);
}

