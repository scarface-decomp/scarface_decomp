// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/VehiclePropellerTemplate.cpp (5 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 5 of 6 functions matched (83.33%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] VehiclePropellerTemplate::vfunc_00 (0x001D2050, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// VehiclePropellerTemplate::vfunc_00 (0x001D2050, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004210B8[];

class VehiclePropellerTemplate
{
public:
    virtual void* vfunc_00();
};

void* VehiclePropellerTemplate::vfunc_00()
{
    return DAT_004210B8;
}

// ============================================================================
// [VERIFIED] VehiclePropellerTemplate::vfunc_01 (0x001D23F0, 46 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// VehiclePropellerTemplate::vfunc_01 (Proto 0x001D23F0, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field2C
{
    void sub_0007D540();
};

extern "C" char DAT_003A763C[];
extern "C" void __cdecl sub_00025160(int);

class VehiclePropellerTemplate
{
public:
    virtual void vfunc_00();
    virtual VehiclePropellerTemplate* vfunc_01(int a1);
    void sub_001D1AC0();
    char m_pad04[0x28];
    Field2C m_Field2C; // +0x2C
};

VehiclePropellerTemplate* VehiclePropellerTemplate::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003A763C;
    m_Field2C.sub_0007D540();
    sub_001D1AC0();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] VehiclePropellerTemplate::vfunc_05 (0x001D2420, 63 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// VehiclePropellerTemplate::vfunc_05 (Proto 0x001D2420, 63 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field2C
{
    void sub_0009BFA0(int);
};

extern "C" int __cdecl sub_00028120(int);
extern "C" void __stdcall sub_001D16C0(int);

class VehiclePropellerTemplate
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int a1);
    char m_pad04[0x28];
    Field2C m_Field2C; // +0x2C
    char m_pad2D[0x83];
    int m_FieldB0; // +0xB0
};

void VehiclePropellerTemplate::vfunc_05(int a1)
{
    sub_001D16C0(a1);
    if (sub_00028120(m_FieldB0)) {
        m_Field2C.sub_0009BFA0(sub_00028120(m_FieldB0) + 52);
    }
}

// ============================================================================
// [VERIFIED] VehiclePropellerTemplate::vfunc_27 (0x001D2460, 70 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// VehiclePropellerTemplate::vfunc_27 (Proto 0x001D2460, 70 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field2C
{
    void sub_0009BFE0(int, int);
};

struct FieldB0
{
    void sub_0008D4C0(int);
};

extern "C" int __cdecl sub_00028120(int);

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
    virtual void vfunc_27(int a1);
    char m_pad04[0x1C];
    short m_Field20; // +0x20
    char m_pad22[0xA];
    Field2C m_Field2C; // +0x2C
    char m_pad2D[0x83];
    FieldB0 m_FieldB0; // +0xB0
};

void VehiclePropellerTemplate::vfunc_27(int a1)
{
    m_FieldB0.sub_0008D4C0(a1);
    if (sub_00028120(*(int*)((char*)this + 0xB0))) {
        m_Field2C.sub_0009BFE0(m_Field20, sub_00028120(*(int*)((char*)this + 0xB0)) + 52);
    }
}

// ============================================================================
// [VERIFIED] VehiclePropellerTemplate::vfunc_28 (0x001D24B0, 26 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// VehiclePropellerTemplate::vfunc_28 (Proto 0x001D24B0, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field2C
{
    void sub_0009B020();
};

struct FieldB0
{
    void sub_0008D4C0(int);
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
    char m_pad04[0x28];
    Field2C m_Field2C; // +0x2C
    char m_pad2D[0x83];
    FieldB0 m_FieldB0; // +0xB0
};

void VehiclePropellerTemplate::vfunc_28()
{
    m_Field2C.sub_0009B020();
    m_FieldB0.sub_0008D4C0(0);
}

