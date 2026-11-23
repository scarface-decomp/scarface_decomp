// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/VarietySlot.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 4 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] VarietySlot::vfunc_00 (0x0008ACF0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// VarietySlot::vfunc_00 (0x0008ACF0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003FE348[];

class VarietySlot
{
public:
    virtual void* vfunc_00();
};

void* VarietySlot::vfunc_00()
{
    return DAT_003FE348;
}

// ============================================================================
// [VERIFIED] VarietySlot::vfunc_27 (0x0008AD00, 66 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// VarietySlot::vfunc_27 (Proto 0x0008AD00, 66 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02();
    int sub_000897D0(int);
    int sub_0008A0E0(int, int, int);
};

extern "C" int DAT_0045418C;
extern "C" int DAT_00454190;
extern "C" int __cdecl sub_00027F60(void);
extern "C" int __cdecl sub_000893F0(void);

class VarietySlot
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02();
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
};

void VarietySlot::vfunc_27()
{
    int t1, t4;

    t1 = sub_000893F0();
    t4 = ((Object*)t1)->sub_000897D0(((Object*)sub_00027F60())->vfunc_02());
    DAT_00454190 = ((Object*)t1)->sub_0008A0E0(t4, DAT_0045418C, vfunc_02());
}

// ============================================================================
// [VERIFIED] VarietySlot::vfunc_28 (0x0008AD50, 88 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x0008AD50
// what: 
// tool: the portal's starter code (no AI)

// VarietySlot::vfunc_28 (Proto 0x0008AD50, 88 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02();
    void sub_000897D0(int);
    void sub_00089BB0(int, int, int);
};

extern "C" char DAT_00383C98[];
extern "C" int DAT_0045418C;
extern "C" int DAT_00454190;
extern "C" int __cdecl sub_00027F60(void);
extern "C" int __cdecl sub_000893F0(void);

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
    int sub_00028A80(int, int);
};

void VarietySlot::vfunc_28()
{
    int t1, t5;

    t1 = sub_000893F0();
    ((Object*)t1)->sub_000897D0(((Object*)sub_00027F60())->vfunc_02());
    t5 = sub_00028A80((int)DAT_00383C98, 0);
    if (t5) {
        if (!*(unsigned char*)t5) goto L_4B;
        ((Object*)t1)->sub_00089BB0(DAT_0045418C, DAT_00454190, t5);
    }
L_4B:
    DAT_00454190 = 0;
}

// ============================================================================
// [VERIFIED] VarietySlot::vfunc_01 (0x0008AE10, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// VarietySlot::vfunc_01 (0x0008AE10, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00383C24[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_00028010(void);

class VarietySlot
{
public:
    virtual void vfunc_00();
    virtual VarietySlot* vfunc_01(int a1);
};

VarietySlot* VarietySlot::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_00383C24;
    sub_00028010();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

