// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/WorldAmbienceSpawnObject.cpp (5 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 5 of 13 functions matched (38.46%). NOT COMPLETE YET.
// The 8 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] WorldAmbienceSpawnObject::vfunc_00 (0x001EAFD0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// WorldAmbienceSpawnObject::vfunc_00 (0x001EAFD0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0043D914[];

class WorldAmbienceSpawnObject
{
public:
    virtual void* vfunc_00();
};

void* WorldAmbienceSpawnObject::vfunc_00()
{
    return DAT_0043D914;
}

// ============================================================================
// [VERIFIED] WorldAmbienceSpawnObject::vfunc_47 (0x001EAFF0, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// WorldAmbienceSpawnObject::vfunc_47 (0x001EAFF0, 12 bytes)
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
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual int vfunc_47();
    char m_pad04[0xAF];
    unsigned char m_FieldB3; // +0xB3
};

int WorldAmbienceSpawnObject::vfunc_47()
{
    return (m_FieldB3 >> 5) - 1;
}

// ============================================================================
// [VERIFIED] WorldAmbienceSpawnObject::vfunc_04 (0x001EB000, 53 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// WorldAmbienceSpawnObject::vfunc_04 (0x001EB000, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_001E8630(int, int);
};

extern "C" int DAT_0048F740;
extern "C" void __stdcall sub_001EA030(int);

class WorldAmbienceSpawnObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int a1);
    char m_pad04[0x80];
    int m_Field84; // +0x84
    char m_pad88[0xC];
    int m_Field94; // +0x94
    int m_Field98; // +0x98
};

void WorldAmbienceSpawnObject::vfunc_04(int a1)
{
    int r_eax;

    r_eax = a1;
    sub_001EA030(a1);
    r_eax = m_Field98;
    if (!r_eax) {
        r_eax = ((Object*)DAT_0048F740)->sub_001E8630(m_Field84, 0);
        m_Field94 = r_eax;
    }
}

// ============================================================================
// [VERIFIED] WorldAmbienceSpawnObject::vfunc_42 (0x001EB050, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// WorldAmbienceSpawnObject::vfunc_42 (0x001EB050, 30 bytes)
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
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual int vfunc_42();
    char m_pad04[0x90];
    int m_Field94; // +0x94
    char m_pad98[0x1B];
    bool m_FieldB3; // +0xB3
};

int WorldAmbienceSpawnObject::vfunc_42()
{
    int r_eax;

    r_eax = 1;
    if (1 & m_FieldB3) {
        if (*(int*)(m_Field94 + 22) & 127) goto L_1D;
    }
    r_eax = 0;
L_1D:
    return r_eax;
}

// ============================================================================
// [VERIFIED] WorldAmbienceSpawnObject::vfunc_40 (0x001EB1A0, 44 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// WorldAmbienceSpawnObject::vfunc_40 (0x001EB1A0, 44 bytes)
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
    virtual int vfunc_40(int a1, int a2);
    char m_pad04[0x73];
    unsigned char m_Field77; // +0x77
    char m_pad78[0x3B];
    unsigned char m_FieldB3; // +0xB3
    int m_FieldB4; // +0xB4
};

int WorldAmbienceSpawnObject::vfunc_40(int a1, int a2)
{
    int r_eax;

    m_FieldB3 &= 253;
    r_eax = a2;
    if (!a2) {
        r_eax = a1;
        if (*(int*)(r_eax + 617) & 1) goto L_25;
    }
    if (!(m_FieldB4 & 8)) goto L_29;
L_25:
    m_Field77 |= 16;
L_29:
    return r_eax;
}

