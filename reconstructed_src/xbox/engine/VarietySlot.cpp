// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/VarietySlot.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 4 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] VarietySlot::vfunc_00 (0x00096510, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// VarietySlot::vfunc_00 (0x00096510, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00423628[];

class VarietySlot
{
public:
    virtual void* vfunc_00();
};

void* VarietySlot::vfunc_00()
{
    return DAT_00423628;
}

// ============================================================================
// [VERIFIED] VarietySlot::vfunc_29 (0x00096520, 65 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// VarietySlot::vfunc_29 (0x00096520, 65 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00095070(int);
    int sub_000956F0(int, int, int);
    int sub_000CE360();
};

extern "C" int DAT_00481B60;
extern "C" int DAT_00481B64;
extern "C" int __cdecl sub_0002A9D0(void);
extern "C" int __cdecl sub_00094C80(void);

class VarietySlot
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
    int sub_000CE360();
};

void VarietySlot::vfunc_29()
{
    int t1, t4, t5;

    t1 = sub_00094C80();
    t4 = ((Object*)t1)->sub_00095070(((Object*)sub_0002A9D0())->sub_000CE360());
    t5 = sub_000CE360();
    DAT_00481B64 = ((Object*)t1)->sub_000956F0(t4, DAT_00481B60, t5);
}

// ============================================================================
// [VERIFIED] VarietySlot::vfunc_30 (0x00096570, 88 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// VarietySlot::vfunc_30 (0x00096570, 88 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00095070(int);
    void sub_00095390(int, int, int);
    int sub_000CE360();
};

extern "C" char DAT_003A4758[];
extern "C" int DAT_00481B60;
extern "C" int DAT_00481B64;
extern "C" int __cdecl sub_0002A9D0(void);
extern "C" int __cdecl sub_00094C80(void);

class VarietySlot
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
    int sub_0002B540(int, int);
};

void VarietySlot::vfunc_30()
{
    int t1, t5;

    t1 = sub_00094C80();
    ((Object*)t1)->sub_00095070(((Object*)sub_0002A9D0())->sub_000CE360());
    t5 = sub_0002B540((int)DAT_003A4758, 0);
    if (t5) {
        if (!*(char*)t5) goto L_4B;
        ((Object*)t1)->sub_00095390(DAT_00481B60, DAT_00481B64, t5);
    }
L_4B:
    DAT_00481B64 = 0;
}

// ============================================================================
// [VERIFIED] VarietySlot::vfunc_01 (0x00096630, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// VarietySlot::vfunc_01 (0x00096630, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A46DC[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_0002AA80(void);

class VarietySlot
{
public:
    virtual void vfunc_00();
    virtual VarietySlot* vfunc_01(int a1);
};

VarietySlot* VarietySlot::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003A46DC;
    sub_0002AA80();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

