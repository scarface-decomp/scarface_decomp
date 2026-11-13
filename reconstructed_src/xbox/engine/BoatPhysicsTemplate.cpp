// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/BoatPhysicsTemplate.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 3 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] BoatPhysicsTemplate::vfunc_00 (0x00200E00, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// BoatPhysicsTemplate::vfunc_00 (0x00200E00, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00442554[];

class BoatPhysicsTemplate
{
public:
    virtual void* vfunc_00();
};

void* BoatPhysicsTemplate::vfunc_00()
{
    return DAT_00442554;
}

// ============================================================================
// [VERIFIED] BoatPhysicsTemplate::vfunc_01 (0x00200E70, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// BoatPhysicsTemplate::vfunc_01 (0x00200E70, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003CBCBC[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_0020C490(void);

class BoatPhysicsTemplate
{
public:
    virtual void vfunc_00();
    virtual BoatPhysicsTemplate* vfunc_01(int a1);
};

BoatPhysicsTemplate* BoatPhysicsTemplate::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003CBCBC;
    sub_0020C490();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] BoatPhysicsTemplate::vfunc_04 (0x002012D0, 24 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as BoatAITask_Enemy::vfunc_33 (0x0013CE40), which was matched first;
// its addresses and names were swapped for this function's.
// BoatPhysicsTemplate::vfunc_04 (0x002012D0, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_0020D120(int);

class BoatPhysicsTemplate
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
    virtual void vfunc_04(int a1);
    void sub_00201020();
};

void BoatPhysicsTemplate::vfunc_04(int a1)
{
    sub_0020D120(a1);
    sub_00201020();
}

