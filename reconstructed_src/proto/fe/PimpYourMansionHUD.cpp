// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, fe/PimpYourMansionHUD.cpp (7 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 7 of 11 functions matched (63.64%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] PimpYourMansionHUD::vfunc_39 (0x001869D0, 131 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// PimpYourMansionHUD::vfunc_39 (Proto 0x001869D0, 131 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00(int);
    void sub_001B7A10();
};

extern "C" char DAT_0039C4D4[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_00065ED0(int, int, int, int, int);
extern "C" bool __stdcall sub_0016E890(int);

class PimpYourMansionHUD
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
    char m_pad04[0x38];
    unsigned char m_Field3C; // +0x3C
    char m_pad3D[0xB];
    int m_Field48; // +0x48
    int m_Field4C; // +0x4C
    int m_Field50; // +0x50
};

bool PimpYourMansionHUD::vfunc_39(int a1)
{
    int t2, t4, t6;

    if (sub_0016E890(a1)) {
        return true;
    }
    t2 = m_Field48;
    if (m_Field48) {
        ((Object*)t2)->vfunc_00(1);
        m_Field48 = 0;
    }
    t4 = m_Field50;
    if (m_Field50) {
        ((Object*)t4)->vfunc_00(1);
        m_Field50 = 0;
    }
    t6 = m_Field4C;
    if (m_Field4C) {
        ((Object*)t6)->sub_001B7A10();
        sub_00025160(t6);
        m_Field4C = 0;
    }
    m_Field3C = (unsigned char)(m_Field3C & 254);
    sub_00065ED0((int)DAT_0039C4D4, 0, 0, 0, -1);
    return false;
}

// ============================================================================
// [VERIFIED] PimpYourMansionHUD::vfunc_00 (0x00187E90, 11 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// PimpYourMansionHUD::vfunc_00 (Proto 0x00187E90, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00187950(int);
};

class PimpYourMansionHUD
{
public:
    virtual void vfunc_00();
};

void PimpYourMansionHUD::vfunc_00()
{
    ((Object*)(int)this + -68)->sub_00187950(0);
}

// ============================================================================
// [VERIFIED] PimpYourMansionHUD::vfunc_01 (0x00187EA0, 11 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// PimpYourMansionHUD::vfunc_01 (Proto 0x00187EA0, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001879D0(int);
};

class PimpYourMansionHUD
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
};

void PimpYourMansionHUD::vfunc_01()
{
    ((Object*)(int)this + -68)->sub_001879D0(0);
}

// ============================================================================
// [VERIFIED] PimpYourMansionHUD::vfunc_40 (0x00187F60, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundEntityLoader::vfunc_04 (0x00064FA0), which was matched first;
// its addresses and names were swapped for this function's.
// PimpYourMansionHUD::vfunc_40 (0x00187F60, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0016E790(void);

class PimpYourMansionHUD
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_40();
};

void PimpYourMansionHUD::vfunc_40()
{
    sub_0016E790();
}

// ============================================================================
// [VERIFIED] PimpYourMansionHUD::vfunc_00 (0x00188070, 37 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// PimpYourMansionHUD::vfunc_00 (Proto 0x00188070, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0016E3C0(int, int);
};

class PimpYourMansionHUD
{
public:
    virtual void vfunc_00(int a1, int a2);
};

void PimpYourMansionHUD::vfunc_00(int a1, int a2)
{
    if (a1 == 138) {
        a2 = 1;
        a1 = 1;
        ((Object*)(int)this + -64)->sub_0016E3C0(a1, a2);
        return;
    }
}

// ============================================================================
// [VERIFIED] PimpYourMansionHUD::vfunc_00 (0x00188110, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// PimpYourMansionHUD::vfunc_00 (0x00188110, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0041196C[];

class PimpYourMansionHUD
{
public:
    virtual void* vfunc_00();
};

void* PimpYourMansionHUD::vfunc_00()
{
    return DAT_0041196C;
}

// ============================================================================
// [VERIFIED] PimpYourMansionHUD::vfunc_01 (0x00188190, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Collidable::vfunc_03 (0x00011F20), which was matched first;
// its addresses and names were swapped for this function's.
// PimpYourMansionHUD::vfunc_01 (0x00188190, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00188120(void);
extern "C" void __cdecl sub_00025160(int);

class PimpYourMansionHUD
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual PimpYourMansionHUD* vfunc_01(int a1);
};

PimpYourMansionHUD* PimpYourMansionHUD::vfunc_01(int a1)
{
    sub_00188120();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

