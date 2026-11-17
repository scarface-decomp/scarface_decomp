// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, fe/ExoticsHUD2.cpp (7 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 7 of 18 functions matched (38.89%). NOT COMPLETE YET.
// The 11 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ExoticsHUD2::vfunc_00 (0x00168610, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// ExoticsHUD2::vfunc_00 (0x00168610, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0040FFA8[];

class ExoticsHUD2
{
public:
    virtual void* vfunc_00();
};

void* ExoticsHUD2::vfunc_00()
{
    return DAT_0040FFA8;
}

// ============================================================================
// [VERIFIED] ExoticsHUD2::vfunc_05 (0x001686E0, 43 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ExoticsHUD2::vfunc_05 (Proto 0x001686E0, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001F0990(int, int);
};

extern "C" int DAT_0045E030;
extern "C" int DAT_004635E0;
extern "C" void __stdcall sub_00028C40(int);

class ExoticsHUD2
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

void ExoticsHUD2::vfunc_05(int a1)
{
    sub_00028C40(a1);
    vfunc_27();
    ((Object*)DAT_004635E0)->sub_001F0990(4, DAT_0045E030);
}

// ============================================================================
// [VERIFIED] ExoticsHUD2::vfunc_39 (0x00168F10, 193 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ExoticsHUD2::vfunc_39 (Proto 0x00168F10, 193 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00(int);
    void sub_00024320();
    void sub_001B7A10();
    void sub_001ECB40(int);
};

extern "C" char DAT_00396CE4[];
extern "C" int DAT_00462F98;
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_00065ED0(int, int, int, int, int);
extern "C" bool __stdcall sub_0016E890(int);

class ExoticsHUD2
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
    char m_pad04[0x40];
    int m_Field44; // +0x44
    int m_Field48; // +0x48
    int m_Field4C; // +0x4C
    char m_pad50[0x2C];
    int m_Field7C; // +0x7C
    int m_Field80; // +0x80
    int m_Field84; // +0x84
};

bool ExoticsHUD2::vfunc_39(int a1)
{
    int r_ebx, t2, t5, t7, t9, t12, t14;

    if (sub_0016E890(a1)) {
        return true;
    }
    r_ebx = 0;
    t2 = m_Field84;
    if (m_Field84) {
        ((Object*)t2)->sub_00024320();
        sub_00025160(t2);
        m_Field84 = 0;
    }
    t5 = m_Field44;
    if (m_Field44 != r_ebx) {
        ((Object*)t5)->vfunc_00(1);
        m_Field44 = r_ebx;
    }
    t7 = m_Field4C;
    if (m_Field4C != r_ebx) {
        ((Object*)t7)->vfunc_00(1);
        m_Field4C = r_ebx;
    }
    t9 = m_Field48;
    if (m_Field48 != r_ebx) {
        ((Object*)t9)->sub_001B7A10();
        sub_00025160(t9);
        m_Field48 = r_ebx;
    }
    t12 = m_Field7C;
    if (m_Field7C != r_ebx) {
        ((Object*)t12)->vfunc_00(1);
        m_Field7C = r_ebx;
    }
    t14 = m_Field80;
    if (m_Field80 != r_ebx) {
        ((Object*)t14)->vfunc_00(1);
        m_Field80 = r_ebx;
    }
    ((Object*)DAT_00462F98)->sub_001ECB40(r_ebx);
    sub_00065ED0((int)DAT_00396CE4, r_ebx, r_ebx, r_ebx, -1);
    return false;
}

// ============================================================================
// [VERIFIED] ExoticsHUD2::vfunc_01 (0x00169380, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Collidable::vfunc_03 (0x00011F20), which was matched first;
// its addresses and names were swapped for this function's.
// ExoticsHUD2::vfunc_01 (0x00169380, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00168D40(void);
extern "C" void __cdecl sub_00025160(int);

class ExoticsHUD2
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual ExoticsHUD2* vfunc_01(int a1);
};

ExoticsHUD2* ExoticsHUD2::vfunc_01(int a1)
{
    sub_00168D40();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] ExoticsHUD2::vfunc_00 (0x00169710, 11 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ExoticsHUD2::vfunc_00 (Proto 0x00169710, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00168FE0(int);
};

class ExoticsHUD2
{
public:
    virtual void vfunc_00();
};

void ExoticsHUD2::vfunc_00()
{
    ((Object*)(int)this + -64)->sub_00168FE0(0);
}

// ============================================================================
// [VERIFIED] ExoticsHUD2::vfunc_01 (0x00169720, 11 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ExoticsHUD2::vfunc_01 (Proto 0x00169720, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00169110(int);
};

class ExoticsHUD2
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
};

void ExoticsHUD2::vfunc_01()
{
    ((Object*)(int)this + -64)->sub_00169110(0);
}

// ============================================================================
// [VERIFIED] ExoticsHUD2::vfunc_43 (0x0016E520, 22 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ExoticsHUD2::vfunc_43 (Proto 0x0016E520, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class ExoticsHUD2
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
    virtual void vfunc_39(int);
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    char m_pad04[0x1C];
    int m_Field20; // +0x20
};

void ExoticsHUD2::vfunc_43()
{
    vfunc_39(1);
    m_Field20 = 4;
}

