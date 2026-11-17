// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/MountedWeaponTemplate.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] MountedWeaponTemplate::vfunc_00 (0x001C4950, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// MountedWeaponTemplate::vfunc_00 (0x001C4950, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0041AA00[];

class MountedWeaponTemplate
{
public:
    virtual void* vfunc_00();
};

void* MountedWeaponTemplate::vfunc_00()
{
    return DAT_0041AA00;
}

// ============================================================================
// [VERIFIED] MountedWeaponTemplate::vfunc_27 (0x001C49A0, 78 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// MountedWeaponTemplate::vfunc_27 (Proto 0x001C49A0, 78 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00024AB0(int);
    void sub_00024AD0();
    int sub_001B9710(int, int);
};

extern "C" char DAT_0037CD30[];
extern "C" int __cdecl sub_00025140(int, int);

class MountedWeaponTemplate
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
    virtual int vfunc_27();
    void sub_001C4370(int);
};

int MountedWeaponTemplate::vfunc_27()
{
    int local_4, r_esi, t2;

    ((Object*)(int)(&local_4))->sub_00024AB0(9);
    t2 = sub_00025140(352, 9);
    if (t2) {
        r_esi = ((Object*)t2)->sub_001B9710((int)DAT_0037CD30, 9);
    } else {
        r_esi = 0;
    }
    sub_001C4370(r_esi);
    ((Object*)(int)(&local_4))->sub_00024AD0();
    return r_esi;
}

