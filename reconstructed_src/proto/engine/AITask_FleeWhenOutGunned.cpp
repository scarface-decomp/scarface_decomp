// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/AITask_FleeWhenOutGunned.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 5 functions matched (80.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AITask_FleeWhenOutGunned::vfunc_36 (0x000F0430, 19 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AITask_FleeWhenOutGunned::vfunc_36 (Proto 0x000F0430, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_000EFC40(int);

class AITask_FleeWhenOutGunned
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
    char m_pad04[0x13D];
    bool m_Field141; // +0x141
};

void AITask_FleeWhenOutGunned::vfunc_36()
{
    sub_000EFC40(0);
    m_Field141 = false;
}

// ============================================================================
// [VERIFIED] AITask_FleeWhenOutGunned::vfunc_34 (0x000F0AF0, 70 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AITask_FleeWhenOutGunned::vfunc_34 (Proto 0x000F0AF0, 70 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    bool sub_00028CB0(int);
};

extern "C" char DAT_00381FB4[];
extern "C" int __cdecl sub_00028120(int);
extern "C" void __cdecl sub_00066030(int, int, int);
extern "C" void __stdcall sub_000EFC40(int);

class AITask_FleeWhenOutGunned
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
    char m_pad04[0x1C];
    int m_Field20; // +0x20
    char m_pad24[0x11D];
    bool m_Field141; // +0x141
};

void AITask_FleeWhenOutGunned::vfunc_34()
{
    int t3;

    sub_000EFC40(1);
    t3 = sub_00028120(m_Field20);
    if (!m_Field141) {
        if (!((Object*)t3)->sub_00028CB0(34)) goto L_3D;
        sub_00066030((int)this, 1, (int)DAT_00381FB4);
    }
L_3D:
    m_Field141 = true;
}

// ============================================================================
// [VERIFIED] AITask_FleeWhenOutGunned::vfunc_00 (0x000F0CD0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// AITask_FleeWhenOutGunned::vfunc_00 (0x000F0CD0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0040431C[];

class AITask_FleeWhenOutGunned
{
public:
    virtual void* vfunc_00();
};

void* AITask_FleeWhenOutGunned::vfunc_00()
{
    return DAT_0040431C;
}

// ============================================================================
// [VERIFIED] AITask_FleeWhenOutGunned::vfunc_01 (0x000F0E20, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Collidable::vfunc_03 (0x00011F20), which was matched first;
// its addresses and names were swapped for this function's.
// AITask_FleeWhenOutGunned::vfunc_01 (0x000F0E20, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_000F0E40(void);
extern "C" void __cdecl sub_00025160(int);

class AITask_FleeWhenOutGunned
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual AITask_FleeWhenOutGunned* vfunc_01(int a1);
};

AITask_FleeWhenOutGunned* AITask_FleeWhenOutGunned::vfunc_01(int a1)
{
    sub_000F0E40();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

