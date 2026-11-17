// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, fe/HUDSubtitle.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 6 functions matched (66.67%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] HUDSubtitle::vfunc_00 (0x0016C6B0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// HUDSubtitle::vfunc_00 (0x0016C6B0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00410350[];

class HUDSubtitle
{
public:
    virtual void* vfunc_00();
};

void* HUDSubtitle::vfunc_00()
{
    return DAT_00410350;
}

// ============================================================================
// [VERIFIED] HUDSubtitle::vfunc_01 (0x0016D700, 59 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// HUDSubtitle::vfunc_01 (Proto 0x0016D700, 59 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field40
{
    void sub_0016D250(int);
};

extern "C" char DAT_00397914[];
extern "C" void __cdecl sub_00025160(int);

class HUDSubtitle
{
public:
    virtual void vfunc_00();
    virtual HUDSubtitle* vfunc_01(int a1);
    void sub_0016E130();
    char m_pad04[0x3C];
    Field40* m_Field40; // +0x40
};

HUDSubtitle* HUDSubtitle::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_00397914;
    if (m_Field40) {
        m_Field40->sub_0016D250(3);
        m_Field40 = 0;
    }
    sub_0016E130();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] HUDSubtitle::vfunc_39 (0x0016E890, 81 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// HUDSubtitle::vfunc_39 (Proto 0x0016E890, 81 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0016F8D0(int, int);
};

extern "C" int DAT_0045E07C;

class HUDSubtitle
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
    virtual void vfunc_33(int, int);
    virtual bool vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual bool vfunc_39(int a1);
    char m_pad04[0x1C];
    int m_Field20; // +0x20
    char m_pad24[0x4];
    int m_Field28; // +0x28
    char m_pad2C[0x10];
    unsigned char m_Field3C; // +0x3C
};

bool HUDSubtitle::vfunc_39(int a1)
{
    unsigned char t1;

    t1 = m_Field3C;
    if (m_Field3C & 2) {
        if (!(t1 & 4)) goto L_4B;
        m_Field3C = (unsigned char)(t1 & 251);
        vfunc_33(0, 0);
        if (vfunc_34()) {
            ((Object*)DAT_0045E07C)->sub_0016F8D0(m_Field28, 1);
        }
        m_Field20 = 0;
        return false;
    }
L_4B:
    return true;
}

// ============================================================================
// [VERIFIED] HUDSubtitle::vfunc_05 (0x0017C820, 24 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// HUDSubtitle::vfunc_05 (Proto 0x0017C820, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_0016E190(int);

class HUDSubtitle
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
};

void HUDSubtitle::vfunc_05(int a1)
{
    sub_0016E190(a1);
    vfunc_27();
}

