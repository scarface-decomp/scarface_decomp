// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/WorldAmbienceSpawnObject.cpp (8 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 8 of 10 functions matched (80.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] WorldAmbienceSpawnObject::vfunc_00 (0x001B1520, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// WorldAmbienceSpawnObject::vfunc_00 (0x001B1520, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0041715C[];

class WorldAmbienceSpawnObject
{
public:
    virtual void* vfunc_00();
};

void* WorldAmbienceSpawnObject::vfunc_00()
{
    return DAT_0041715C;
}

// ============================================================================
// [VERIFIED] WorldAmbienceSpawnObject::vfunc_05 (0x001B1530, 53 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x001B1530
// what: 
// tool: the portal's starter code (no AI)

// WorldAmbienceSpawnObject::vfunc_05 (Proto 0x001B1530, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_001AF720(int, int);
};

extern "C" int DAT_00460C24;
extern "C" void __stdcall sub_001B0CD0(int);

class WorldAmbienceSpawnObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int a1);
    char m_pad04[0x84];
    int m_Field88; // +0x88
    char m_pad8C[0xC];
    int m_Field98; // +0x98
    int m_Field9C; // +0x9C
};

void WorldAmbienceSpawnObject::vfunc_05(int a1)
{
    sub_001B0CD0(a1);
    if (!m_Field9C) {
        m_Field98 = ((Object*)DAT_00460C24)->sub_001AF720(m_Field88, 0);
    }
}

// ============================================================================
// [VERIFIED] WorldAmbienceSpawnObject::vfunc_38 (0x001B1570, 10 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// WorldAmbienceSpawnObject::vfunc_38 (Proto 0x001B1570, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class WorldAmbienceSpawnObject
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
    virtual void vfunc_38(int a1, int a2);
    char m_pad04[0xAF];
    unsigned char m_FieldB3; // +0xB3
};

void WorldAmbienceSpawnObject::vfunc_38(int a1, int a2)
{
    m_FieldB3 &= 253;
}

// ============================================================================
// [VERIFIED] WorldAmbienceSpawnObject::vfunc_39 (0x001B1580, 14 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// WorldAmbienceSpawnObject::vfunc_39 (Proto 0x001B1580, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0023E120(int);
};

class WorldAmbienceSpawnObject
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
    virtual void vfunc_39(int a1, int a2);
};

void WorldAmbienceSpawnObject::vfunc_39(int a1, int a2)
{
    ((Object*)a1)->sub_0023E120(0);
}

// ============================================================================
// [VERIFIED] WorldAmbienceSpawnObject::vfunc_40 (0x001B1590, 31 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// WorldAmbienceSpawnObject::vfunc_40 (Proto 0x001B1590, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class WorldAmbienceSpawnObject
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
    virtual int vfunc_40();
    char m_pad04[0x94];
    int m_Field98; // +0x98
    char m_pad9C[0x17];
    bool m_FieldB3; // +0xB3
};

int WorldAmbienceSpawnObject::vfunc_40()
{
    int r_eax;

    r_eax = 1;
    if (1 & m_FieldB3) {
        if (*(bool*)(m_Field98 + 20)) goto L_1E;
    }
    r_eax = 0;
L_1E:
    return r_eax;
}

// ============================================================================
// [VERIFIED] WorldAmbienceSpawnObject::vfunc_14 (0x001B15B0, 110 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x001B15B0
// what: 
// tool: the portal's starter code (no AI)

// WorldAmbienceSpawnObject::vfunc_14 (Proto 0x001B15B0, 110 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003F45D8[];
extern "C" char DAT_00415728[];
extern "C" char DAT_0041574C[];
extern "C" int __cdecl sub_00028F60(int);
extern "C" int __cdecl sub_002C92F8(int, int, int, int, int);

class WorldAmbienceSpawnObject
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
    char m_pad1F[0x7D];
    int m_Field9C; // +0x9C
    int m_FieldA0; // +0xA0
};

void WorldAmbienceSpawnObject::vfunc_14()
{
    int t1, t4;

    t1 = m_Field9C;
    m_Field1E = (unsigned char)(m_Field1E | 2);
    if (m_Field9C) {
        m_Field9C = sub_002C92F8(sub_00028F60(t1), 0, (int)DAT_003F45D8, (int)DAT_00415728, 0);
    }
    t4 = m_FieldA0;
    if (m_FieldA0) {
        m_FieldA0 = sub_002C92F8(sub_00028F60(t4), 0, (int)DAT_003F45D8, (int)DAT_0041574C, 0);
    }
}

// ============================================================================
// [VERIFIED] WorldAmbienceSpawnObject::vfunc_35 (0x001B19F0, 54 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x001B19F0
// what: 
// tool: the portal's starter code (no AI)

// WorldAmbienceSpawnObject::vfunc_35 (Proto 0x001B19F0, 54 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field98
{
    int sub_001A6530(int);
};

class WorldAmbienceSpawnObject
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
    virtual int vfunc_35();
    char m_pad04[0x94];
    Field98* m_Field98; // +0x98
    int m_Field9C; // +0x9C
    char m_padA0[0x13];
    unsigned char m_FieldB3; // +0xB3
};

int WorldAmbienceSpawnObject::vfunc_35()
{
    int r_eax;

    r_eax = *(int*)this;
    r_eax = ((int (__cdecl*)(void))*(int*)(r_eax + 172))();
    if (m_Field9C) {
        r_eax |= 1;
    }
    if (m_FieldB3 & 1) {
        r_eax = m_Field98->sub_001A6530(r_eax);
        m_FieldB3 &= 254;
    }
    return r_eax;
}

// ============================================================================
// [VERIFIED] WorldAmbienceSpawnObject::vfunc_01 (0x001B1C60, 85 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x001B1C60
// what: 
// tool: the portal's starter code (no AI)

// WorldAmbienceSpawnObject::vfunc_01 (Proto 0x001B1C60, 85 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field98
{
    void sub_001A6530(int);
};

extern "C" char DAT_003A2ECC[];
extern "C" int DAT_003A2F78;
extern "C" void __cdecl sub_00025160(int);

class WorldAmbienceSpawnObject
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1);
    void sub_001B0CB0();
    char m_pad04[0x94];
    Field98* m_Field98; // +0x98
    int m_Field9C; // +0x9C
    char m_padA0[0x13];
    unsigned char m_FieldB3; // +0xB3
};

int WorldAmbienceSpawnObject::vfunc_01(int a1)
{
    int r_eax;

    *(int*)this = (int)DAT_003A2ECC;
    r_eax = ((int (__cdecl*)(void))DAT_003A2F78)();
    if (m_Field9C) {
        r_eax |= 1;
    }
    if (m_FieldB3 & 1) {
        m_Field98->sub_001A6530(r_eax);
        m_FieldB3 &= 254;
    }
    sub_001B0CB0();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    r_eax = (int)this;
    return r_eax;
}

