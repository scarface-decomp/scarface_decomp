// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/VehiclePropellerTemplate.cpp (5 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 5 of 6 functions matched (83.33%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] VehiclePropellerTemplate::vfunc_00 (0x0020D2C0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// VehiclePropellerTemplate::vfunc_00 (0x0020D2C0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00447718[];

class VehiclePropellerTemplate
{
public:
    virtual void* vfunc_00();
};

void* VehiclePropellerTemplate::vfunc_00()
{
    return DAT_00447718;
}

// ============================================================================
// [VERIFIED] VehiclePropellerTemplate::vfunc_01 (0x0020D6A0, 46 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as DismemberTrack::vfunc_03 (0x000E8620), which was matched first;
// its addresses and names were swapped for this function's.
// VehiclePropellerTemplate::vfunc_01 (0x0020D6A0, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field24
{
    void sub_000879E0();
};

extern "C" char DAT_003CD80C[];
extern "C" void __cdecl sub_00027600(int);

class VehiclePropellerTemplate
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual VehiclePropellerTemplate* vfunc_01(int a1);
    void sub_0020C490();
    char m_pad04[0x20];
    Field24 m_Field24; // +0x24
};

VehiclePropellerTemplate* VehiclePropellerTemplate::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003CD80C;
    m_Field24.sub_000879E0();
    sub_0020C490();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] VehiclePropellerTemplate::vfunc_04 (0x0020D6D0, 63 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// VehiclePropellerTemplate::vfunc_04 (0x0020D6D0, 63 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field24
{
    void sub_000A7E60(int);
};

extern "C" int __cdecl sub_0002AC90(int);
extern "C" void __stdcall sub_0002B700(int);

class VehiclePropellerTemplate
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int a1);
    char m_pad04[0x20];
    Field24 m_Field24; // +0x24
    char m_pad25[0x7F];
    int m_FieldA4; // +0xA4
};

void VehiclePropellerTemplate::vfunc_04(int a1)
{
    sub_0002B700(a1);
    if (sub_0002AC90(m_FieldA4)) {
        m_Field24.sub_000A7E60(sub_0002AC90(m_FieldA4) + 52);
    }
}

// ============================================================================
// [VERIFIED] VehiclePropellerTemplate::vfunc_29 (0x0020D710, 70 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// VehiclePropellerTemplate::vfunc_29 (0x0020D710, 70 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field24
{
    void sub_000A7EA0(int, int);
};

struct FieldA4
{
    void sub_00098B90(int);
};

extern "C" int __cdecl sub_0002AC90(int);

class VehiclePropellerTemplate
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
    virtual void vfunc_29(int a1);
    char m_pad04[0x1C];
    short m_Field20; // +0x20
    char m_pad22[0x2];
    Field24 m_Field24; // +0x24
    char m_pad25[0x7F];
    FieldA4 m_FieldA4; // +0xA4
};

void VehiclePropellerTemplate::vfunc_29(int a1)
{
    m_FieldA4.sub_00098B90(a1);
    if (sub_0002AC90(*(int*)((char*)this + 0xA4))) {
        m_Field24.sub_000A7EA0(m_Field20, sub_0002AC90(*(int*)((char*)this + 0xA4)) + 52);
    }
}

// ============================================================================
// [VERIFIED] VehiclePropellerTemplate::vfunc_30 (0x0020D760, 26 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// VehiclePropellerTemplate::vfunc_30 (0x0020D760, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field24
{
    void sub_000A6EF0();
};

struct FieldA4
{
    void sub_00098B90(int);
};

class VehiclePropellerTemplate
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
    char m_pad04[0x20];
    Field24 m_Field24; // +0x24
    char m_pad25[0x7F];
    FieldA4 m_FieldA4; // +0xA4
};

void VehiclePropellerTemplate::vfunc_30()
{
    m_Field24.sub_000A6EF0();
    m_FieldA4.sub_00098B90(0);
}

