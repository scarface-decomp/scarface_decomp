// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/VehicleZoneProperties.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 5 functions matched (80.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] VehicleZoneProperties::vfunc_00 (0x0020D670, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// VehicleZoneProperties::vfunc_00 (0x0020D670, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00447928[];

class VehicleZoneProperties
{
public:
    virtual void* vfunc_00();
};

void* VehicleZoneProperties::vfunc_00()
{
    return DAT_00447928;
}

// ============================================================================
// [VERIFIED] VehicleZoneProperties::vfunc_01 (0x0020E070, 46 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundPlayTrack::vfunc_03 (0x000E9E90), which was matched first;
// its addresses and names were swapped for this function's.
// VehicleZoneProperties::vfunc_01 (0x0020E070, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field20
{
    void sub_000A6E80();
};

extern "C" char DAT_003CDE14[];
extern "C" void __cdecl sub_00027600(int);

class VehicleZoneProperties
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual VehicleZoneProperties* vfunc_01(int a1);
    void sub_0002C720();
    char m_pad04[0x1C];
    Field20 m_Field20; // +0x20
};

VehicleZoneProperties* VehicleZoneProperties::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003CDE14;
    m_Field20.sub_000A6E80();
    sub_0002C720();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] VehicleZoneProperties::vfunc_29 (0x0020E960, 69 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// VehicleZoneProperties::vfunc_29 (0x0020E960, 69 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field44
{
    void sub_000A7D30(int);
};

struct Field5C
{
    void sub_00098B90(int);
};

extern "C" int __cdecl sub_0002AC90(int);

class VehicleZoneProperties
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
    void sub_0020E0A0();
    char m_pad04[0x40];
    Field44 m_Field44; // +0x44
    char m_pad45[0x17];
    Field5C m_Field5C; // +0x5C
};

void VehicleZoneProperties::vfunc_29(int a1)
{
    m_Field5C.sub_00098B90(a1);
    if (sub_0002AC90(*(int*)((char*)this + 0x5C))) {
        m_Field44.sub_000A7D30(sub_0002AC90(*(int*)((char*)this + 0x5C)) + 52);
        sub_0020E0A0();
    }
}

// ============================================================================
// [VERIFIED] VehicleZoneProperties::vfunc_30 (0x0020E9B0, 58 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// VehicleZoneProperties::vfunc_30 (0x0020E9B0, 58 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field24
{
    void sub_00087680();
};

struct Field5C
{
    void sub_00098B90(int);
};

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
};

extern "C" int __cdecl sub_0002AC90(int);

class VehicleZoneProperties
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
    char m_pad25[0x33];
    int m_Field58; // +0x58
    Field5C m_Field5C; // +0x5C
};

void VehicleZoneProperties::vfunc_30()
{
    if (sub_0002AC90(m_Field58)) {
        ((Object*)sub_0002AC90(m_Field58))->vfunc_30();
    }
    m_Field24.sub_00087680();
    m_Field5C.sub_00098B90(0);
}

