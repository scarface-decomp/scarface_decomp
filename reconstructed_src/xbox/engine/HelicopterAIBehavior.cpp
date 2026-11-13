// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/HelicopterAIBehavior.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 5 functions matched (60.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] HelicopterAIBehavior::vfunc_36 (0x001477D0, 41 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// HelicopterAIBehavior::vfunc_36 (0x001477D0, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class HelicopterAIBehavior
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
    virtual int vfunc_36();
    char m_pad04[0x34];
    int m_Field38; // +0x38
};

int HelicopterAIBehavior::vfunc_36()
{
    int r_eax, t1;

    r_eax = 2;
    t1 = m_Field38;
    if (m_Field38) {
        r_eax = 4;
        if (*(int*)(t1 + 1400) == 4) goto L_28;
        r_eax = 0;
        r_eax = !*(bool*)(t1 + 1466);
    }
L_28:
    return r_eax;
}

// ============================================================================
// [VERIFIED] HelicopterAIBehavior::vfunc_00 (0x00147880, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// HelicopterAIBehavior::vfunc_00 (0x00147880, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0042E1C4[];

class HelicopterAIBehavior
{
public:
    virtual void* vfunc_00();
};

void* HelicopterAIBehavior::vfunc_00()
{
    return DAT_0042E1C4;
}

// ============================================================================
// [VERIFIED] HelicopterAIBehavior::vfunc_01 (0x00147890, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Collidable::vfunc_03 (0x00011F20), which was matched first;
// its addresses and names were swapped for this function's.
// HelicopterAIBehavior::vfunc_01 (0x00147890, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0014A260(void);
extern "C" void __cdecl sub_00027600(int);

class HelicopterAIBehavior
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual HelicopterAIBehavior* vfunc_01(int a1);
};

HelicopterAIBehavior* HelicopterAIBehavior::vfunc_01(int a1)
{
    sub_0014A260();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

