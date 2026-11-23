// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/WeaponGroupCondition.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 3 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] WeaponGroupCondition::vfunc_08 (0x000DD340, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SpeedCondition::vfunc_08 (0x000DD280), which was matched first;
// its addresses and names were swapped for this function's.
// WeaponGroupCondition::vfunc_08 (0x000DD340, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00487764;

class WeaponGroupCondition
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

int WeaponGroupCondition::vfunc_08(int a1)
{
    return *(int*)(DAT_00487764 + (a1 * 4));
}

// ============================================================================
// [VERIFIED] WeaponGroupCondition::vfunc_03 (0x000DDA00, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: WeaponGroupCondition's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// WeaponGroupCondition::vfunc_03 (0x000DDA00, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A692C[];
extern "C" void __cdecl sub_0023F7A0(int);
extern "C" void __cdecl sub_00021870(void);

class WeaponGroupCondition
{
public:
    virtual void vfunc_00();
    virtual WeaponGroupCondition* vfunc_03(int a1);
};

WeaponGroupCondition* WeaponGroupCondition::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_003A692C;
    sub_00021870();
    if (a1 & 1) {
        sub_0023F7A0((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] WeaponGroupCondition::vfunc_15 (0x000DDA30, 61 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as WeaponGroupCondition::vfunc_15 (Proto 0x000CBD00), which was matched first;
// its addresses and names were swapped for this function's.
// bin: proto
// va: 0x000DDA30
// what: 
// tool: the portal's starter code (no AI)

// WeaponGroupCondition::vfunc_15 (Proto 0x000DDA30, 61 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00164720();
};

extern "C" int DAT_00424A80[];
extern "C" int __cdecl sub_0002AC90(int);

class WeaponGroupCondition
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
    virtual bool vfunc_15(int a1, int a2);
    char m_pad04[0xC];
    int m_Field10; // +0x10
};

bool WeaponGroupCondition::vfunc_15(int a1, int a2)
{
    int t2;

    if (a1) {
        t2 = sub_0002AC90(*(int*)(a1 + 28));
        if (!t2) goto L_37;
        return m_Field10 == DAT_00424A80[((Object*)t2)->sub_00164720()];
    }
L_37:
    return false;
}

