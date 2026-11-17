// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, fe/PauseMenuPage.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 11 functions matched (36.36%). NOT COMPLETE YET.
// The 7 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] PauseMenuPage::vfunc_00 (0x00193E90, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// PauseMenuPage::vfunc_00 (0x00193E90, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00413408[];

class PauseMenuPage
{
public:
    virtual void* vfunc_00();
};

void* PauseMenuPage::vfunc_00()
{
    return DAT_00413408;
}

// ============================================================================
// [VERIFIED] PauseMenuPage::vfunc_05 (0x00193EB0, 50 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// PauseMenuPage::vfunc_05 (Proto 0x00193EB0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00193C40();
};

extern "C" void __stdcall sub_00028C40(int);
extern "C" int __stdcall sub_00193880(int);

class PauseMenuPage
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int a1);
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
    virtual void vfunc_31(int, int, int);
};

void PauseMenuPage::vfunc_05(int a1)
{
    sub_00028C40(a1);
    vfunc_27();
    ((Object*)sub_00193880((int)this))->sub_00193C40();
    vfunc_31(1, 0, 0);
}

// ============================================================================
// [VERIFIED] PauseMenuPage::vfunc_39 (0x00193FB0, 129 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// PauseMenuPage::vfunc_39 (Proto 0x00193FB0, 129 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00(int);
    void sub_001B7A10();
};

extern "C" char DAT_0039E538[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_00065830(int, int);
extern "C" bool __stdcall sub_0016E890(int);

class PauseMenuPage
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
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual bool vfunc_39(int a1);
    char m_pad04[0x40];
    int m_Field44; // +0x44
    int m_Field48; // +0x48
    int m_Field4C; // +0x4C
    char m_pad50[0x4];
    bool m_Field54; // +0x54
};

bool PauseMenuPage::vfunc_39(int a1)
{
    int t2, t4, t6;

    if (sub_0016E890(a1)) {
        return true;
    }
    t2 = m_Field44;
    if (m_Field44) {
        ((Object*)t2)->vfunc_00(1);
        m_Field44 = 0;
    }
    t4 = m_Field4C;
    if (m_Field4C) {
        ((Object*)t4)->vfunc_00(1);
        m_Field4C = 0;
    }
    t6 = m_Field48;
    if (m_Field48) {
        ((Object*)t6)->sub_001B7A10();
        sub_00025160(t6);
        m_Field48 = 0;
    }
    if (m_Field54) {
        sub_00065830((int)DAT_0039E538, vfunc_02());
    }
    return false;
}

// ============================================================================
// [VERIFIED] PauseMenuPage::vfunc_01 (0x00196870, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Collidable::vfunc_03 (0x00011F20), which was matched first;
// its addresses and names were swapped for this function's.
// PauseMenuPage::vfunc_01 (0x00196870, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00194180(void);
extern "C" void __cdecl sub_00025160(int);

class PauseMenuPage
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual PauseMenuPage* vfunc_01(int a1);
};

PauseMenuPage* PauseMenuPage::vfunc_01(int a1)
{
    sub_00194180();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

