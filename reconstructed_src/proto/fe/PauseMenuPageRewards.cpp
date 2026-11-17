// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, fe/PauseMenuPageRewards.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 9 functions matched (33.33%). NOT COMPLETE YET.
// The 6 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] PauseMenuPageRewards::vfunc_00 (0x001959E0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// PauseMenuPageRewards::vfunc_00 (0x001959E0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004134B8[];

class PauseMenuPageRewards
{
public:
    virtual void* vfunc_00();
};

void* PauseMenuPageRewards::vfunc_00()
{
    return DAT_004134B8;
}

// ============================================================================
// [VERIFIED] PauseMenuPageRewards::vfunc_50 (0x00195DA0, 26 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// PauseMenuPageRewards::vfunc_50 (Proto 0x00195DA0, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_001940E0(void);
extern "C" int __stdcall sub_00195C10(int);

class PauseMenuPageRewards
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
    virtual int vfunc_50();
    char m_pad04[0x58];
    int m_Field5C; // +0x5C
};

int PauseMenuPageRewards::vfunc_50()
{
    int r_eax;

    r_eax = m_Field5C;
    if (r_eax == 1) {
        return sub_001940E0();
    }
    if (r_eax == 2) {
        r_eax = sub_00195C10(1);
    }
    return r_eax;
}

// ============================================================================
// [VERIFIED] PauseMenuPageRewards::vfunc_01 (0x00196070, 65 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// PauseMenuPageRewards::vfunc_01 (Proto 0x00196070, 65 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00(int);
};

extern "C" char DAT_0039F310[];
extern "C" char DAT_0039F324[];
extern "C" void __cdecl sub_00025160(int);

class PauseMenuPageRewards
{
public:
    virtual void vfunc_00();
    virtual PauseMenuPageRewards* vfunc_01(int a1);
    void sub_00194180();
    char m_pad04[0x3C];
    int m_Field40; // +0x40
    char m_pad44[0x14];
    int m_Field58; // +0x58
};

PauseMenuPageRewards* PauseMenuPageRewards::vfunc_01(int a1)
{
    int t1;

    t1 = m_Field58;
    *(int*)this = (int)DAT_0039F324;
    m_Field40 = (int)DAT_0039F310;
    if (m_Field58) {
        ((Object*)t1)->vfunc_00(1);
        m_Field58 = 0;
    }
    sub_00194180();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

