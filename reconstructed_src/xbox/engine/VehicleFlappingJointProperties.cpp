// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/VehicleFlappingJointProperties.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 5 functions matched (80.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] VehicleFlappingJointProperties::vfunc_00 (0x0020D420, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns VehicleFlappingJointProperties's static class record (ConcreteClassRep<VehicleFlappingJointProperties>), the object's run-time type.
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// VehicleFlappingJointProperties::vfunc_00 (0x0020D420, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004477C8[];

class VehicleFlappingJointProperties
{
public:
    virtual void* vfunc_00();
};

void* VehicleFlappingJointProperties::vfunc_00()
{
    return DAT_004477C8;
}

// ============================================================================
// [VERIFIED] VehicleFlappingJointProperties::vfunc_01 (0x0020D970, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: VehicleFlappingJointProperties's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// VehicleFlappingJointProperties::vfunc_01 (0x0020D970, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003CDA0C[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_0002C720(void);

class VehicleFlappingJointProperties
{
public:
    virtual void vfunc_00();
    virtual VehicleFlappingJointProperties* vfunc_01(int a1);
};

VehicleFlappingJointProperties* VehicleFlappingJointProperties::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003CDA0C;
    sub_0002C720();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] VehicleFlappingJointProperties::vfunc_29 (0x0020DA60, 62 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as VehicleFlappingJointProperties::vfunc_27 (Proto 0x001D27B0), which was matched first;
// its addresses and names were swapped for this function's.
// VehicleFlappingJointProperties::vfunc_29 (Proto 0x0020DA60, 62 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field20
{
    void sub_000A7E30(int);
};

struct Field34
{
    void sub_00098B90(int);
};

extern "C" int __cdecl sub_0002AC90(int);

class VehicleFlappingJointProperties
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
    Field20 m_Field20; // +0x20
    char m_pad21[0x13];
    Field34 m_Field34; // +0x34
};

void VehicleFlappingJointProperties::vfunc_29(int a1)
{
    m_Field34.sub_00098B90(a1);
    if (sub_0002AC90(*(int*)((char*)this + 0x34))) {
        m_Field20.sub_000A7E30(sub_0002AC90(*(int*)((char*)this + 0x34)) + 52);
    }
}

// ============================================================================
// [VERIFIED] VehicleFlappingJointProperties::vfunc_30 (0x0020DAA0, 25 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as VehicleFlappingJointProperties::vfunc_28 (Proto 0x001D27F0), which was matched first;
// its addresses and names were swapped for this function's.
// VehicleFlappingJointProperties::vfunc_30 (Proto 0x0020DAA0, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field20
{
    void sub_000A7E30(int);
};

struct Field34
{
    void sub_00098B90(int);
};

class VehicleFlappingJointProperties
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
    char m_pad04[0x1C];
    Field20 m_Field20; // +0x20
    char m_pad21[0x13];
    Field34 m_Field34; // +0x34
};

void VehicleFlappingJointProperties::vfunc_30()
{
    m_Field20.sub_000A7E30(0);
    m_Field34.sub_00098B90(0);
}

