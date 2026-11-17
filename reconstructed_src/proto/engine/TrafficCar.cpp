// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/TrafficCar.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 4 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] TrafficCar::vfunc_00 (0x001DFDE0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// TrafficCar::vfunc_00 (0x001DFDE0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00426574[];

class TrafficCar
{
public:
    virtual void* vfunc_00();
};

void* TrafficCar::vfunc_00()
{
    return DAT_00426574;
}

// ============================================================================
// [VERIFIED] TrafficCar::vfunc_46 (0x001DFDF0, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundEntityLoader::vfunc_04 (0x00064FA0), which was matched first;
// its addresses and names were swapped for this function's.
// TrafficCar::vfunc_46 (0x001DFDF0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001D9150(void);

class TrafficCar
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_46();
};

void TrafficCar::vfunc_46()
{
    sub_001D9150();
}

// ============================================================================
// [VERIFIED] TrafficCar::vfunc_01 (0x001DFEC0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// TrafficCar::vfunc_01 (0x001DFEC0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A9D5C[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_001D8780(void);

class TrafficCar
{
public:
    virtual void vfunc_00();
    virtual TrafficCar* vfunc_01(int a1);
};

TrafficCar* TrafficCar::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003A9D5C;
    sub_001D8780();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] TrafficCar::vfunc_47 (0x001DFEF0, 86 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// TrafficCar::vfunc_47 (Proto 0x001DFEF0, 86 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00029460();
    int sub_001DC620();
};

extern "C" char DAT_003F47F4[];
extern "C" char DAT_003F4D28[];
extern "C" int DAT_00462DD4;
extern "C" void __cdecl sub_001D8A80(void);
extern "C" int __cdecl sub_002C92F8(int, int, int, int, int);

class TrafficCar
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
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void vfunc_47();
    int sub_001DB8F0();
    int sub_001DB8F0(int);
};

void TrafficCar::vfunc_47()
{
    int r_eax;

    sub_001D8A80();
    r_eax = sub_001DB8F0();
    if (r_eax) {
        r_eax = sub_001DB8F0(0);
        r_eax = ((Object*)r_eax)->sub_001DC620();
    } else {
        r_eax = 0;
    }
    r_eax = sub_002C92F8(r_eax, 0, (int)DAT_003F4D28, (int)DAT_003F47F4, 0);
    if (r_eax) {
        if (*(int*)(r_eax + 16) == DAT_00462DD4) goto L_55;
        ((Object*)r_eax)->sub_00029460();
        return;
    }
L_55:
    ;
}

