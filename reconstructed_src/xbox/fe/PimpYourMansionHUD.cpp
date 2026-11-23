// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, fe/PimpYourMansionHUD.cpp (6 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 6 of 11 functions matched (54.55%). NOT COMPLETE YET.
// The 5 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] PimpYourMansionHUD::vfunc_00 (0x001B68C0, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Steps back to the object this one is part of and calls one of its functions with 0.
// ============================================================================
// bin: xb
// va: 0x001B68C0
// what: Steps back to the object this one is part of and calls one of its functions with 0.
// tool: Claude Fable 5.2 (look-alike of 0x001B2250, names and addresses swapped)
// PimpYourMansionHUD::vfunc_00 (0x001B68C0, 11 bytes)
struct Object
{
    void sub_001B6010(int);
};

class PimpYourMansionHUD
{
public:
    virtual void vfunc_00();
};

void PimpYourMansionHUD::vfunc_00()
{
    ((Object*)(int)this + -104)->sub_001B6010(0);
}

// ============================================================================
// [VERIFIED] PimpYourMansionHUD::vfunc_01 (0x001B68D0, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Steps back to the object this one is part of and calls one of its functions with 0.
// ============================================================================
// bin: xb
// va: 0x001B68D0
// what: Steps back to the object this one is part of and calls one of its functions with 0.
// tool: Claude Fable 5.2 (look-alike of 0x001B2250, names and addresses swapped)
// PimpYourMansionHUD::vfunc_01 (0x001B68D0, 11 bytes)
struct Object
{
    void sub_001B6090(int);
};

class PimpYourMansionHUD
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
};

void PimpYourMansionHUD::vfunc_01()
{
    ((Object*)(int)this + -104)->sub_001B6090(0);
}

// ============================================================================
// [VERIFIED] PimpYourMansionHUD::vfunc_54 (0x001BAD90, 91 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 /arch:SSE
// ============================================================================
// bin: xb
// va: 0x001BAD90
// what: 
// tool: the portal's starter code (no AI)

// PimpYourMansionHUD::vfunc_54 (0x001BAD90, 91 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01(int);
};

struct Object2
{
    virtual void vfunc_00();
    virtual void vfunc_01(int, int);
};

extern "C" float DAT_003BAC90;
extern "C" void __stdcall sub_00193280(int);

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
    virtual void vfunc_50();
    virtual void vfunc_51();
    virtual void vfunc_52();
    virtual void vfunc_53();
    virtual void vfunc_54(int a1);
    char m_pad04[0x5C];
    unsigned char m_Field60; // +0x60
    char m_pad61[0xB];
    int m_Field6C; // +0x6C
    char m_pad70[0x4];
    int m_Field74; // +0x74
    char m_pad78[0x10];
    float m_Field88; // +0x88
};

void PimpYourMansionHUD::vfunc_54(int a1)
{
    int r_edi, t2, t4;

    if (m_Field60 & 1) {
        r_edi = a1;
        sub_00193280(a1);
        t2 = m_Field6C;
        if (m_Field6C) {
            ((Object*)t2)->vfunc_01(a1);
        }
        t4 = m_Field74;
        if (m_Field74) {
            ((Object2*)t4)->vfunc_01(r_edi, 0);
        }
        if (DAT_003BAC90 >= m_Field88) {
            m_Field88 = *(float*)(r_edi + 8) + m_Field88;
        }
    }
}

// ============================================================================
// [VERIFIED] PimpYourMansionHUD::vfunc_00 (0x001BADF0, 37 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// PimpYourMansionHUD::vfunc_00 (0x001BADF0, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00193B40(int, int);
};

class PimpYourMansionHUD
{
public:
    virtual void vfunc_00(int a1, int a2);
};

void PimpYourMansionHUD::vfunc_00(int a1, int a2)
{
    if (a1 == 212) {
        a2 = 1;
        a1 = 1;
        ((Object*)(int)this + -100)->sub_00193B40(a1, a2);
        return;
    }
}

// ============================================================================
// [VERIFIED] PimpYourMansionHUD::vfunc_00 (0x001BAEA0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// PimpYourMansionHUD::vfunc_00 (0x001BAEA0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00437C44[];

class PimpYourMansionHUD
{
public:
    virtual void* vfunc_00();
};

void* PimpYourMansionHUD::vfunc_00()
{
    return DAT_00437C44;
}

// ============================================================================
// [VERIFIED] PimpYourMansionHUD::vfunc_01 (0x001BAF20, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Collidable::vfunc_03 (0x00011F20), which was matched first;
// its addresses and names were swapped for this function's.
// PimpYourMansionHUD::vfunc_01 (0x001BAF20, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001BAEB0(void);
extern "C" void __cdecl sub_00027600(int);

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
    sub_001BAEB0();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

