// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/GangSpawnObject.cpp (5 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 5 of 9 functions matched (55.56%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] GangSpawnObject::vfunc_00 (0x001E0120, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// GangSpawnObject::vfunc_00 (0x001E0120, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0043DB50[];

class GangSpawnObject
{
public:
    virtual void* vfunc_00();
};

void* GangSpawnObject::vfunc_00()
{
    return DAT_0043DB50;
}

// ============================================================================
// [VERIFIED] GangSpawnObject::vfunc_37 (0x001E0130, 79 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: xb
// va: 0x001E0130
// what: 
// tool: the portal's starter code (no AI)

// GangSpawnObject::vfunc_37 (0x001E0130, 79 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field8C
{
    void sub_001DE370(int);
};

struct Object
{
    void sub_001DE370(int);
};

class GangSpawnObject
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
    char m_pad04[0x74];
    int m_Field78; // +0x78
    char m_pad7C[0x10];
    Field8C* m_Field8C; // +0x8C
    bool m_Field90; // +0x90
};

void GangSpawnObject::vfunc_37()
{
    int r_ebp, r_edi, r_esi;

    r_esi = (int)(((char*)this + 0x81));
    r_edi = (int)(&m_Field78);
    r_ebp = 2;
    do {
        if (*(unsigned char*)r_esi) {
            ((Object*)*(int*)r_edi)->sub_001DE370(16);
            *(bool*)r_esi = false;
        }
        r_edi += 4;
        r_esi += 1;
        r_ebp -= 1;
    } while (r_ebp);
    if (m_Field90) {
        m_Field8C->sub_001DE370(16);
        m_Field90 = false;
    }
}

// ============================================================================
// [VERIFIED] GangSpawnObject::vfunc_41 (0x001E01D0, 82 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: xb
// va: 0x001E01D0
// what: 
// tool: the portal's starter code (no AI)

// GangSpawnObject::vfunc_41 (0x001E01D0, 82 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0002A160(int);
};

class GangSpawnObject
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
    virtual void vfunc_41(int a1, int a2);
    char m_pad04[0x98];
    int m_Field9C; // +0x9C
    int m_FieldA0; // +0xA0
    char m_padA4[0x4];
    bool m_FieldA8; // +0xA8
    char m_padA9[0x3];
    int m_FieldAC; // +0xAC
};

void GangSpawnObject::vfunc_41(int a1, int a2)
{
    int r_eax;

    r_eax = a2;
    if (!a2) {
        m_Field9C -= 1;
    } else {
        if (r_eax != 1) goto L_29;
        m_FieldA0 -= 1;
    }
    ((Object*)a1)->sub_0002A160(0);
L_29:
    r_eax = m_Field9C;
    if (!r_eax) {
        r_eax = m_FieldA8;
        if (!((unsigned char)r_eax)) goto L_4E;
        m_FieldA8 = false;
        m_FieldAC = 3;
    }
L_4E:
    ;
}

// ============================================================================
// [VERIFIED] GangSpawnObject::vfunc_01 (0x001E0630, 43 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as GameGroup::vfunc_01 (0x000290E0), which was matched first;
// its addresses and names were swapped for this function's.
// GangSpawnObject::vfunc_01 (0x001E0630, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003C7C74[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_001E0130(void);

class GangSpawnObject
{
public:
    virtual void vfunc_00();
    virtual GangSpawnObject* vfunc_01(int a1);
    void sub_001EA010();
};

GangSpawnObject* GangSpawnObject::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003C7C74;
    sub_001E0130();
    sub_001EA010();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] GangSpawnObject::vfunc_45 (0x0026D450, 6 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as GangSpawnObject::vfunc_43 (Proto 0x00213E60), which was matched first;
// its addresses and names were swapped for this function's.
// GangSpawnObject::vfunc_45 (Proto 0x0026D450, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class GangSpawnObject
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
    virtual int vfunc_45();
};

int GangSpawnObject::vfunc_45()
{
    return 16;
}

