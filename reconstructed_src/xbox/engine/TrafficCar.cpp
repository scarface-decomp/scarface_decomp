// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/TrafficCar.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 4 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] TrafficCar::vfunc_00 (0x0021C1B0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns TrafficCar's static class record (ConcreteClassRep<TrafficCar>), the object's run-time type.
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// TrafficCar::vfunc_00 (0x0021C1B0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0044CC08[];

class TrafficCar
{
public:
    virtual void* vfunc_00();
};

void* TrafficCar::vfunc_00()
{
    return DAT_0044CC08;
}

// ============================================================================
// [VERIFIED] TrafficCar::vfunc_64 (0x0021C1C0, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundEntityLoader::vfunc_04 (0x00064FA0), which was matched first;
// its addresses and names were swapped for this function's.
// TrafficCar::vfunc_64 (0x0021C1C0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_002144B0(void);

class TrafficCar
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_64();
};

void TrafficCar::vfunc_64()
{
    sub_002144B0();
}

// ============================================================================
// [VERIFIED] TrafficCar::vfunc_01 (0x0021C270, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: TrafficCar's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// TrafficCar::vfunc_01 (0x0021C270, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003D03DC[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_00213AB0(void);

class TrafficCar
{
public:
    virtual void vfunc_00();
    virtual TrafficCar* vfunc_01(int a1);
};

TrafficCar* TrafficCar::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003D03DC;
    sub_00213AB0();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] TrafficCar::vfunc_65 (0x0021C2A0, 89 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// TrafficCar::vfunc_65 (0x0021C2A0, 89 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0002BFA0();
    int sub_00218050();
};

extern "C" char DAT_00419818[];
extern "C" char DAT_00419D60[];
extern "C" int DAT_0048A9D8;
extern "C" void __cdecl sub_00213DE0(void);
extern "C" int __cdecl sub_002FC034(int, int, int, int, int);

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
    virtual void vfunc_48();
    virtual void vfunc_49();
    virtual void vfunc_50();
    virtual void vfunc_51();
    virtual void vfunc_52();
    virtual void vfunc_53();
    virtual void vfunc_54();
    virtual void vfunc_55();
    virtual void vfunc_56();
    virtual void vfunc_57();
    virtual void vfunc_58();
    virtual void vfunc_59();
    virtual void vfunc_60();
    virtual void vfunc_61();
    virtual void vfunc_62();
    virtual void vfunc_63();
    virtual void vfunc_64();
    virtual void vfunc_65();
    int sub_00217380();
    int sub_00217380(int);
};

void TrafficCar::vfunc_65()
{
    int r_eax, t6;

    sub_00213DE0();
    r_eax = sub_00217380();
    if (r_eax) {
        r_eax = sub_00217380(0);
        r_eax = ((Object*)r_eax)->sub_00218050();
    } else {
        r_eax = 0;
    }
    r_eax = sub_002FC034(r_eax, 0, (int)DAT_00419D60, (int)DAT_00419818, 0);
    if (r_eax) {
        t6 = DAT_0048A9D8;
        if (DAT_0048A9D8) {
            if (r_eax == t6) goto L_58;
        }
        ((Object*)r_eax)->sub_0002BFA0();
        return;
    }
L_58:
    ;
}

