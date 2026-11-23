// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, fe/DrugWarsHUD.cpp (5 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 5 of 10 functions matched (50.00%). NOT COMPLETE YET.
// The 5 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] DrugWarsHUD::vfunc_00 (0x00192DA0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// DrugWarsHUD::vfunc_00 (0x00192DA0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004365D4[];

class DrugWarsHUD
{
public:
    virtual void* vfunc_00();
};

void* DrugWarsHUD::vfunc_00()
{
    return DAT_004365D4;
}

// ============================================================================
// [VERIFIED] DrugWarsHUD::vfunc_54 (0x00192E70, 128 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: xb
// va: 0x00192E70
// what: 
// tool: the portal's starter code (no AI)

// DrugWarsHUD::vfunc_54 (0x00192E70, 128 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field5C
{
    bool sub_00025760();
    void sub_00026010(int);
};

struct Field98
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06(int);
};

struct Field9C
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06(int);
};

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

extern "C" void __stdcall sub_00193280(int);

class DrugWarsHUD
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
    char m_pad04[0x58];
    Field5C* m_Field5C; // +0x5C
    unsigned char m_Field60; // +0x60
    char m_pad61[0xF];
    int m_Field70; // +0x70
    int m_Field74; // +0x74
    int m_Field78; // +0x78
    char m_pad7C[0x1C];
    Field98* m_Field98; // +0x98
    Field9C* m_Field9C; // +0x9C
    char m_padA0[0x1C];
    bool m_FieldBC; // +0xBC
};

void DrugWarsHUD::vfunc_54(int a1)
{
    int t2, t4;

    sub_00193280(a1);
    if (m_Field60 & 1) {
        t2 = m_Field74;
        if (m_Field74) {
            ((Object*)t2)->vfunc_01(a1);
        }
        t4 = m_Field78;
        if (m_Field78) {
            ((Object2*)t4)->vfunc_01(a1, 0);
        }
        if (m_Field74 == m_Field70) {
            m_Field98->vfunc_06(a1);
            m_Field9C->vfunc_06(a1);
        }
        if (!m_FieldBC) goto L_7B;
        if (m_Field5C) {
            if (!m_Field5C->sub_00025760()) goto L_7B;
            m_Field5C->sub_00026010(0);
        }
        m_FieldBC = false;
    }
L_7B:
    ;
}

// ============================================================================
// [VERIFIED] DrugWarsHUD::vfunc_01 (0x00193040, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Collidable::vfunc_03 (0x00011F20), which was matched first;
// its addresses and names were swapped for this function's.
// DrugWarsHUD::vfunc_01 (0x00193040, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00192D40(void);
extern "C" void __cdecl sub_00027600(int);

class DrugWarsHUD
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual DrugWarsHUD* vfunc_01(int a1);
};

DrugWarsHUD* DrugWarsHUD::vfunc_01(int a1)
{
    sub_00192D40();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] DrugWarsHUD::vfunc_00 (0x001B2610, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// DrugWarsHUD::vfunc_00 (0x001B2610, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001B1BC0();
};

class DrugWarsHUD
{
public:
    virtual void vfunc_00();
};

void DrugWarsHUD::vfunc_00()
{
    ((Object*)(int)this + -104)->sub_001B1BC0();
}

// ============================================================================
// [VERIFIED] DrugWarsHUD::vfunc_01 (0x001B2620, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as DrugWarsHUD::vfunc_00 (0x001B2610), which was matched first;
// its addresses and names were swapped for this function's.
// DrugWarsHUD::vfunc_01 (0x001B2620, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001B1C30();
};

class DrugWarsHUD
{
public:
    virtual void vfunc_01();
};

void DrugWarsHUD::vfunc_01()
{
    ((Object*)(int)this + -104)->sub_001B1C30();
}

