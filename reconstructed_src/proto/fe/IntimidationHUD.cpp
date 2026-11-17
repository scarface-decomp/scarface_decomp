// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, fe/IntimidationHUD.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 7 functions matched (42.86%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] IntimidationHUD::vfunc_00 (0x00178D50, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// IntimidationHUD::vfunc_00 (0x00178D50, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0041112C[];

class IntimidationHUD
{
public:
    virtual void* vfunc_00();
};

void* IntimidationHUD::vfunc_00()
{
    return DAT_0041112C;
}

// ============================================================================
// [VERIFIED] IntimidationHUD::vfunc_39 (0x00178E10, 135 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// IntimidationHUD::vfunc_39 (Proto 0x00178E10, 135 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
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
    virtual void vfunc_30(int);
    bool sub_00133860();
    void sub_00135770(int);
};

extern "C" char DAT_00399E18[];
extern "C" void __cdecl sub_00065ED0(int, int, int, int, int);
extern "C" int __cdecl sub_00133750(void);
extern "C" bool __stdcall sub_0016E890(int);

class IntimidationHUD
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
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual bool vfunc_39(int a1);
};

bool IntimidationHUD::vfunc_39(int a1)
{
    int r_esi, t2;

    r_esi = (int)this;
    if (sub_0016E890(a1)) {
        return true;
    }
    *(unsigned char*)(r_esi + 60) &= 254;
    t2 = *(int*)(r_esi + 36);
    *(int*)(r_esi + 132) = 6;
    *(int*)(r_esi + 128) = -1;
    ((Object*)t2)->vfunc_30(0);
    *(int*)(r_esi + 940) = 0;
    *(int*)(r_esi + 1088) = 0;
    r_esi = sub_00133750();
    if (r_esi) {
        if (!((Object*)r_esi)->sub_00133860()) goto L_6C;
        ((Object*)r_esi)->sub_00135770(0);
    }
L_6C:
    sub_00065ED0((int)DAT_00399E18, 0, 0, 0, -1);
    return false;
}

// ============================================================================
// [VERIFIED] IntimidationHUD::vfunc_01 (0x00179760, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// IntimidationHUD::vfunc_01 (0x00179760, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00399D0C[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_0016E130(void);

class IntimidationHUD
{
public:
    virtual void vfunc_00();
    virtual IntimidationHUD* vfunc_01(int a1);
};

IntimidationHUD* IntimidationHUD::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_00399D0C;
    sub_0016E130();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

