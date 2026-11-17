// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/AirplaneObject.cpp (13 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 13 of 30 functions matched (43.33%). NOT COMPLETE YET.
// The 17 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AirplaneObject::vfunc_00 (0x001D8230, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// AirplaneObject::vfunc_00 (0x001D8230, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00425C00[];

class AirplaneObject
{
public:
    virtual void* vfunc_00();
};

void* AirplaneObject::vfunc_00()
{
    return DAT_00425C00;
}

// ============================================================================
// [VERIFIED] AirplaneObject::vfunc_01 (0x001D8350, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// AirplaneObject::vfunc_01 (0x001D8350, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A93CC[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_001DB870(void);

class AirplaneObject
{
public:
    virtual void vfunc_00();
    virtual AirplaneObject* vfunc_01(int a1);
};

AirplaneObject* AirplaneObject::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003A93CC;
    sub_001DB870();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] AirplaneObject::vfunc_55 (0x001D8380, 41 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AirplaneObject::vfunc_55 (Proto 0x001D8380, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_001D8240(int, int);
};

extern "C" int __cdecl sub_00025120(int);

class AirplaneObject
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
    virtual void vfunc_54();
    virtual int vfunc_55();
    char m_pad04[0xA0];
    int m_FieldA4; // +0xA4
};

int AirplaneObject::vfunc_55()
{
    int t1;

    t1 = sub_00025120(1760);
    if (t1) {
        return ((Object*)t1)->sub_001D8240((int)this, m_FieldA4);
    }
    return 0;
}

// ============================================================================
// [VERIFIED] AirplaneObject::vfunc_09 (0x001DB910, 11 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AirplaneObject::vfunc_09 (Proto 0x001DB910, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct FieldBC
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

class AirplaneObject
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
    char m_pad04[0xB8];
    FieldBC* m_FieldBC; // +0xBC
};

void AirplaneObject::vfunc_09()
{
    m_FieldBC->vfunc_01();
}

// ============================================================================
// [VERIFIED] AirplaneObject::vfunc_10 (0x001DB920, 11 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AirplaneObject::vfunc_10 (Proto 0x001DB920, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct FieldBC
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
};

class AirplaneObject
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
    char m_pad04[0xB8];
    FieldBC* m_FieldBC; // +0xBC
};

void AirplaneObject::vfunc_10()
{
    m_FieldBC->vfunc_02();
}

// ============================================================================
// [VERIFIED] AirplaneObject::vfunc_05 (0x001DB930, 23 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AirplaneObject::vfunc_05 (Proto 0x001DB930, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_00027B40(int);

class AirplaneObject
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
    virtual void vfunc_31(int);
};

void AirplaneObject::vfunc_05(int a1)
{
    sub_00027B40(0);
    vfunc_31(1);
}

// ============================================================================
// [VERIFIED] AirplaneObject::vfunc_15 (0x001DC9E0, 54 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AirplaneObject::vfunc_15 (Proto 0x001DC9E0, 54 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
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
    virtual void vfunc_38(int, int);
};

extern "C" int __cdecl sub_00027990(void);

class AirplaneObject
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
    virtual void vfunc_31(int);
    int sub_00027990();
    char m_pad04[0xB8];
    int m_FieldBC; // +0xBC
};

void AirplaneObject::vfunc_15()
{
    if (::sub_00027990()) {
        ((Object*)sub_00027990())->vfunc_38((int)this, *(int*)(m_FieldBC + 1564));
    }
    vfunc_31(0);
}

// ============================================================================
// [VERIFIED] AirplaneObject::vfunc_46 (0x001DCC10, 49 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AirplaneObject::vfunc_46 (Proto 0x001DCC10, 49 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
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
    virtual int vfunc_27(int);
    int sub_0008D4E0(int);
};

extern "C" Object DAT_00461DDC;
extern "C" int DAT_00461DE0;

class AirplaneObject
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
    virtual int vfunc_46();
    char m_pad04[0xA0];
    int m_FieldA4; // +0xA4
};

int AirplaneObject::vfunc_46()
{
    int r_eax;

    r_eax = m_FieldA4;
    if (r_eax) {
        if (!*(bool*)(r_eax + 192)) goto L_2F;
        r_eax = DAT_00461DE0;
        r_eax = DAT_00461DDC.sub_0008D4E0(r_eax);
        r_eax = ((Object*)r_eax)->vfunc_27((int)this);
    }
L_2F:
    return r_eax;
}

// ============================================================================
// [VERIFIED] AirplaneObject::vfunc_27 (0x001DCFE0, 66 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AirplaneObject::vfunc_27 (Proto 0x001DCFE0, 66 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_0009F320(int);
};

class AirplaneObject
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
    virtual int vfunc_27(int a1);
    char m_pad04[0x5C];
    int m_Field60; // +0x60
    int m_Field64; // +0x64
    int m_Field68; // +0x68
    char m_pad6C[0x38];
    int m_FieldA4; // +0xA4
    char m_padA8[0x14];
    int m_FieldBC; // +0xBC
};

int AirplaneObject::vfunc_27(int a1)
{
    int r_eax;

    r_eax = a1;
    m_Field60 = *(int*)r_eax;
    m_Field64 = *(int*)(r_eax + 4);
    r_eax = *(int*)(r_eax + 8);
    m_Field68 = r_eax;
    r_eax = m_FieldA4;
    if (r_eax) {
        r_eax = m_FieldBC;
        if (!r_eax) goto L_3F;
        if (!*(bool*)(r_eax + 68)) goto L_3F;
        a1 = (int)this + 48;
        return ((Object*)r_eax + 72)->sub_0009F320(a1);
    }
L_3F:
    return r_eax;
}

// ============================================================================
// [VERIFIED] AirplaneObject::vfunc_28 (0x001DD030, 56 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AirplaneObject::vfunc_28 (Proto 0x001DD030, 56 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_0009F320(int);
};

extern "C" void __stdcall sub_00026F90(int);

class AirplaneObject
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
    virtual int vfunc_28(int a1);
    char m_pad04[0xA0];
    int m_FieldA4; // +0xA4
    char m_padA8[0x14];
    int m_FieldBC; // +0xBC
};

int AirplaneObject::vfunc_28(int a1)
{
    int r_eax;

    r_eax = a1;
    sub_00026F90(a1);
    r_eax = m_FieldA4;
    if (r_eax) {
        r_eax = m_FieldBC;
        if (!r_eax) goto L_34;
        if (!*(bool*)(r_eax + 68)) goto L_34;
        r_eax = ((Object*)r_eax + 72)->sub_0009F320((int)this + 48);
    }
L_34:
    return r_eax;
}

// ============================================================================
// [VERIFIED] AirplaneObject::vfunc_29 (0x001DD070, 56 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AirplaneObject::vfunc_29 (Proto 0x001DD070, 56 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_0009F320(int);
};

extern "C" void __stdcall sub_00026F00(int);

class AirplaneObject
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
    virtual int vfunc_29(int a1);
    char m_pad04[0xA0];
    int m_FieldA4; // +0xA4
    char m_padA8[0x14];
    int m_FieldBC; // +0xBC
};

int AirplaneObject::vfunc_29(int a1)
{
    int r_eax;

    r_eax = a1;
    sub_00026F00(a1);
    r_eax = m_FieldA4;
    if (r_eax) {
        r_eax = m_FieldBC;
        if (!r_eax) goto L_34;
        if (!*(bool*)(r_eax + 68)) goto L_34;
        r_eax = ((Object*)r_eax + 72)->sub_0009F320((int)this + 48);
    }
L_34:
    return r_eax;
}

// ============================================================================
// [VERIFIED] AirplaneObject::vfunc_30 (0x001DD0B0, 56 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AirplaneObject::vfunc_30 (Proto 0x001DD0B0, 56 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_0009F320(int);
};

extern "C" void __stdcall sub_00026F40(int);

class AirplaneObject
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
    virtual int vfunc_30(int a1);
    char m_pad04[0xA0];
    int m_FieldA4; // +0xA4
    char m_padA8[0x14];
    int m_FieldBC; // +0xBC
};

int AirplaneObject::vfunc_30(int a1)
{
    int r_eax;

    r_eax = a1;
    sub_00026F40(a1);
    r_eax = m_FieldA4;
    if (r_eax) {
        r_eax = m_FieldBC;
        if (!r_eax) goto L_34;
        if (!*(bool*)(r_eax + 68)) goto L_34;
        r_eax = ((Object*)r_eax + 72)->sub_0009F320((int)this + 48);
    }
L_34:
    return r_eax;
}

// ============================================================================
// [VERIFIED] AirplaneObject::vfunc_52 (0x001DEBB0, 23 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AirplaneObject::vfunc_52 (Proto 0x001DEBB0, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct FieldBC
{
    void sub_001DBDB0(int);
};

extern "C" void __cdecl sub_001DCF70(void);

class AirplaneObject
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
    char m_pad04[0xB8];
    FieldBC* m_FieldBC; // +0xBC
};

void AirplaneObject::vfunc_52()
{
    sub_001DCF70();
    m_FieldBC->sub_001DBDB0(0);
}

