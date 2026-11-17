// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, fe/PauseMenuPageMain.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 7 functions matched (42.86%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] PauseMenuPageMain::vfunc_00 (0x001950C0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// PauseMenuPageMain::vfunc_00 (0x001950C0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00413460[];

class PauseMenuPageMain
{
public:
    virtual void* vfunc_00();
};

void* PauseMenuPageMain::vfunc_00()
{
    return DAT_00413460;
}

// ============================================================================
// [VERIFIED] PauseMenuPageMain::vfunc_39 (0x00195430, 69 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// PauseMenuPageMain::vfunc_39 (Proto 0x00195430, 69 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00(int);
};

extern "C" bool __stdcall sub_00193FB0(int);

class PauseMenuPageMain
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
    virtual bool vfunc_39(int a1);
    char m_pad04[0x70];
    int m_Field74; // +0x74
    int m_Field78; // +0x78
};

bool PauseMenuPageMain::vfunc_39(int a1)
{
    int t2, t4;

    if (sub_00193FB0(a1)) {
        return true;
    }
    t2 = m_Field74;
    if (m_Field74) {
        ((Object*)t2)->vfunc_00(1);
        m_Field74 = 0;
    }
    t4 = m_Field78;
    if (m_Field78) {
        ((Object*)t4)->vfunc_00(1);
        m_Field78 = 0;
    }
    return false;
}

// ============================================================================
// [VERIFIED] PauseMenuPageMain::vfunc_01 (0x00195530, 92 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// PauseMenuPageMain::vfunc_01 (Proto 0x00195530, 92 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00(int);
};

extern "C" char DAT_0039EEC8[];
extern "C" char DAT_0039EED0[];
extern "C" char DAT_0039EEE4[];
extern "C" void __cdecl sub_00025160(int);

class PauseMenuPageMain
{
public:
    virtual void vfunc_00();
    virtual PauseMenuPageMain* vfunc_01(int a1);
    void sub_00194180();
    char m_pad04[0x3C];
    int m_Field40; // +0x40
    char m_pad44[0x14];
    int m_Field58; // +0x58
    char m_pad5C[0x18];
    int m_Field74; // +0x74
    int m_Field78; // +0x78
};

PauseMenuPageMain* PauseMenuPageMain::vfunc_01(int a1)
{
    int t1, t3;

    t1 = m_Field74;
    *(int*)this = (int)DAT_0039EEE4;
    m_Field40 = (int)DAT_0039EED0;
    m_Field58 = (int)DAT_0039EEC8;
    if (m_Field74) {
        ((Object*)t1)->vfunc_00(1);
        m_Field74 = 0;
    }
    t3 = m_Field78;
    if (m_Field78) {
        ((Object*)t3)->vfunc_00(1);
        m_Field78 = 0;
    }
    sub_00194180();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

