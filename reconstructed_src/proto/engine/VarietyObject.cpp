// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/VarietyObject.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 4 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] VarietyObject::vfunc_00 (0x0008AC90, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// VarietyObject::vfunc_00 (0x0008AC90, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003FE31C[];

class VarietyObject
{
public:
    virtual void* vfunc_00();
};

void* VarietyObject::vfunc_00()
{
    return DAT_003FE31C;
}

// ============================================================================
// [VERIFIED] VarietyObject::vfunc_30 (0x0008ACA0, 59 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// VarietyObject::vfunc_30 (Proto 0x0008ACA0, 59 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02();
    int sub_000897D0(int);
    int sub_0008A8E0(int, int);
};

extern "C" int DAT_0045418C;
extern "C" int __cdecl sub_00027F60(void);
extern "C" int __cdecl sub_000893F0(void);

class VarietyObject
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
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
};

void VarietyObject::vfunc_30()
{
    int t1, t4;

    t1 = sub_000893F0();
    t4 = ((Object*)t1)->sub_000897D0(((Object*)sub_00027F60())->vfunc_02());
    DAT_0045418C = ((Object*)t1)->sub_0008A8E0(t4, vfunc_02());
}

// ============================================================================
// [VERIFIED] VarietyObject::vfunc_31 (0x0008ACE0, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Sets a global value to 0.
// ============================================================================
// bin: proto
// va: 0x0008ACE0
// what: Sets a global value to 0.
// tool: Claude Fable 5.2 (look-alike of xb 0x00096500, names and addresses swapped)
// VarietyObject::vfunc_31 (0x0008ACE0, 11 bytes)
extern "C" int DAT_0045418C;

class VarietyObject
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
};

void VarietyObject::vfunc_31()
{
    DAT_0045418C = 0;
}

// ============================================================================
// [VERIFIED] VarietyObject::vfunc_01 (0x0008ADE0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// VarietyObject::vfunc_01 (0x0008ADE0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00383B9C[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_00027FC0(void);

class VarietyObject
{
public:
    virtual void vfunc_00();
    virtual VarietyObject* vfunc_01(int a1);
};

VarietyObject* VarietyObject::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_00383B9C;
    sub_00027FC0();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

