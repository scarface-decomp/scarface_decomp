// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/VehicleMountedWeaponTemplate.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 4 functions matched (75.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] VehicleMountedWeaponTemplate::vfunc_00 (0x0020D560, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// VehicleMountedWeaponTemplate::vfunc_00 (0x0020D560, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0044784C[];

class VehicleMountedWeaponTemplate
{
public:
    virtual void* vfunc_00();
};

void* VehicleMountedWeaponTemplate::vfunc_00()
{
    return DAT_0044784C;
}

// ============================================================================
// [VERIFIED] VehicleMountedWeaponTemplate::vfunc_32 (0x0020D570, 29 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// VehicleMountedWeaponTemplate::vfunc_32 (0x0020D570, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_001F4A40(int, int);
};

extern "C" int __cdecl sub_00027590(int);

class VehicleMountedWeaponTemplate
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
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual int vfunc_32(int a1, int a2);
};

int VehicleMountedWeaponTemplate::vfunc_32(int a1, int a2)
{
    int t1;

    t1 = sub_00027590(392);
    if (t1) {
        return ((Object*)t1)->sub_001F4A40(a1, a2);
    }
    return 0;
}

// ============================================================================
// [VERIFIED] VehicleMountedWeaponTemplate::vfunc_01 (0x0020DBF0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// VehicleMountedWeaponTemplate::vfunc_01 (0x0020DBF0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003CDB9C[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_0020C490(void);

class VehicleMountedWeaponTemplate
{
public:
    virtual void vfunc_00();
    virtual VehicleMountedWeaponTemplate* vfunc_01(int a1);
};

VehicleMountedWeaponTemplate* VehicleMountedWeaponTemplate::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003CDB9C;
    sub_0020C490();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

