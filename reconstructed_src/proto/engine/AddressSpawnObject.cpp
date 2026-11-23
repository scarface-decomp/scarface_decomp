// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/AddressSpawnObject.cpp (6 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 6 of 17 functions matched (35.29%). NOT COMPLETE YET.
// The 11 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AddressSpawnObject::vfunc_00 (0x001A08E0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// AddressSpawnObject::vfunc_00 (0x001A08E0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0041720C[];

class AddressSpawnObject
{
public:
    virtual void* vfunc_00();
};

void* AddressSpawnObject::vfunc_00()
{
    return DAT_0041720C;
}

// ============================================================================
// [VERIFIED] AddressSpawnObject::vfunc_01 (0x001A09A0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// AddressSpawnObject::vfunc_01 (0x001A09A0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A116C[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_001A9F10(void);

class AddressSpawnObject
{
public:
    virtual void vfunc_00();
    virtual AddressSpawnObject* vfunc_01(int a1);
};

AddressSpawnObject* AddressSpawnObject::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003A116C;
    sub_001A9F10();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] AddressSpawnObject::vfunc_46 (0x001A0BB0, 33 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 /arch:SSE
// ============================================================================
// bin: proto
// va: 0x001A0BB0
// what: 
// tool: the portal's starter code (no AI)

// AddressSpawnObject::vfunc_46 (Proto 0x001A0BB0, 33 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class AddressSpawnObject
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
    char m_pad04[0xD0];
    float m_FieldD4; // +0xD4
    char m_padD8[0x134];
    float m_Field20C; // +0x20C
};

int AddressSpawnObject::vfunc_46()
{
    float t1;

    t1 = m_FieldD4;
    if ((t1 * t1) > m_Field20C) {
        return 1;
    }
    return 0;
}

// ============================================================================
// [VERIFIED] AddressSpawnObject::vfunc_43 (0x001A80B0, 72 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AddressSpawnObject::vfunc_43 (Proto 0x001A80B0, 72 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field100
{
    int sub_002A56A0();
};

class AddressSpawnObject
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
    virtual int vfunc_43();
    char m_pad04[0xFC];
    Field100* m_Field100; // +0x100
    char m_pad104[0xE0];
    bool m_Field1E4; // +0x1E4
    bool m_Field1E5; // +0x1E5
    bool m_Field1E6; // +0x1E6
};

int AddressSpawnObject::vfunc_43()
{
    int r_eax;

    if (m_Field100) {
        r_eax = m_Field100->sub_002A56A0();
    } else {
        r_eax = 64;
    }
    if (m_Field1E4) {
        r_eax = 4;
    }
    if (m_Field1E5) {
        r_eax = 16;
    }
    if (m_Field1E6) {
        r_eax = 32;
    }
    return r_eax;
}

// ============================================================================
// [VERIFIED] AddressSpawnObject::vfunc_14 (0x001A85B0, 110 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x001A85B0
// what: 
// tool: the portal's starter code (no AI)

// AddressSpawnObject::vfunc_14 (Proto 0x001A85B0, 110 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003F45D8[];
extern "C" char DAT_00415728[];
extern "C" char DAT_0041574C[];
extern "C" int __cdecl sub_00028F60(int);
extern "C" int __cdecl sub_002C92F8(int, int, int, int, int);

class AddressSpawnObject
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
    char m_pad04[0x1A];
    unsigned char m_Field1E; // +0x1E
    char m_pad1F[0xA5];
    int m_FieldC4; // +0xC4
    char m_padC8[0x4];
    int m_FieldCC; // +0xCC
};

void AddressSpawnObject::vfunc_14()
{
    int t1, t4;

    t1 = m_FieldC4;
    m_Field1E = (unsigned char)(m_Field1E | 2);
    if (m_FieldC4) {
        m_FieldC4 = sub_002C92F8(sub_00028F60(t1), 0, (int)DAT_003F45D8, (int)DAT_00415728, 0);
    }
    t4 = m_FieldCC;
    if (m_FieldCC) {
        m_FieldCC = sub_002C92F8(sub_00028F60(t4), 0, (int)DAT_003F45D8, (int)DAT_0041574C, 0);
    }
}

// ============================================================================
// [VERIFIED] AddressSpawnObject::vfunc_42 (0x001B0CF0, 29 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x001B0CF0
// what: 
// tool: the portal's starter code (no AI)

// AddressSpawnObject::vfunc_42 (Proto 0x001B0CF0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_001E2EE0(void);

class AddressSpawnObject
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
    virtual int vfunc_42();
    char m_pad04[0x77];
    bool m_Field7B; // +0x7B
};

int AddressSpawnObject::vfunc_42()
{
    bool t1;

    t1 = m_Field7B;
    if (m_Field7B & 1) {
        if (t1 & 2) {
            if (sub_001E2EE0() <= 0) goto L_1A;
        }
        return 1;
    }
L_1A:
    return 0;
}

