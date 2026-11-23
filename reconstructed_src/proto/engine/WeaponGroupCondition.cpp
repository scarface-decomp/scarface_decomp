// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/WeaponGroupCondition.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 3 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] WeaponGroupCondition::vfunc_08 (0x000CB5E0, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SpeedCondition::vfunc_08 (0x000DD280), which was matched first;
// its addresses and names were swapped for this function's.
// WeaponGroupCondition::vfunc_08 (0x000CB5E0, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00459E64;

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
    return *(int*)(DAT_00459E64 + (a1 * 4));
}

// ============================================================================
// [VERIFIED] WeaponGroupCondition::vfunc_03 (0x000CBCD0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// WeaponGroupCondition::vfunc_03 (0x000CBCD0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003858CC[];
extern "C" void __cdecl sub_001FCF60(int);
extern "C" void __cdecl sub_0001F680(void);

class WeaponGroupCondition
{
public:
    virtual void vfunc_00();
    virtual WeaponGroupCondition* vfunc_03(int a1);
};

WeaponGroupCondition* WeaponGroupCondition::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_003858CC;
    sub_0001F680();
    if (a1 & 1) {
        sub_001FCF60((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] WeaponGroupCondition::vfunc_15 (0x000CBD00, 61 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x000CBD00
// what: 
// tool: the portal's starter code (no AI)

// WeaponGroupCondition::vfunc_15 (Proto 0x000CBD00, 61 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00148290();
};

extern "C" int DAT_003FF730[];
extern "C" int __cdecl sub_00028120(int);

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
        t2 = sub_00028120(*(int*)(a1 + 28));
        if (!t2) goto L_37;
        return m_Field10 == DAT_003FF730[((Object*)t2)->sub_00148290()];
    }
L_37:
    return false;
}

