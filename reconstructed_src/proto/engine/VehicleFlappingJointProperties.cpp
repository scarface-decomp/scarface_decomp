// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/VehicleFlappingJointProperties.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 5 functions matched (80.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] VehicleFlappingJointProperties::vfunc_00 (0x001D21B0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// VehicleFlappingJointProperties::vfunc_00 (0x001D21B0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00421168[];

class VehicleFlappingJointProperties
{
public:
    virtual void* vfunc_00();
};

void* VehicleFlappingJointProperties::vfunc_00()
{
    return DAT_00421168;
}

// ============================================================================
// [VERIFIED] VehicleFlappingJointProperties::vfunc_01 (0x001D26C0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// VehicleFlappingJointProperties::vfunc_01 (0x001D26C0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A781C[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_00029C00(void);

class VehicleFlappingJointProperties
{
public:
    virtual void vfunc_00();
    virtual VehicleFlappingJointProperties* vfunc_01(int a1);
};

VehicleFlappingJointProperties* VehicleFlappingJointProperties::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003A781C;
    sub_00029C00();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] VehicleFlappingJointProperties::vfunc_27 (0x001D27B0, 62 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// VehicleFlappingJointProperties::vfunc_27 (Proto 0x001D27B0, 62 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field20
{
    void sub_0009BF60(int);
};

struct Field34
{
    void sub_0008D4C0(int);
};

extern "C" int __cdecl sub_00028120(int);

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
    virtual void vfunc_27(int a1);
    char m_pad04[0x1C];
    Field20 m_Field20; // +0x20
    char m_pad21[0x13];
    Field34 m_Field34; // +0x34
};

void VehicleFlappingJointProperties::vfunc_27(int a1)
{
    m_Field34.sub_0008D4C0(a1);
    if (sub_00028120(*(int*)((char*)this + 0x34))) {
        m_Field20.sub_0009BF60(sub_00028120(*(int*)((char*)this + 0x34)) + 52);
    }
}

// ============================================================================
// [VERIFIED] VehicleFlappingJointProperties::vfunc_28 (0x001D27F0, 25 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// VehicleFlappingJointProperties::vfunc_28 (Proto 0x001D27F0, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field20
{
    void sub_0009BF60(int);
};

struct Field34
{
    void sub_0008D4C0(int);
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
    char m_pad04[0x1C];
    Field20 m_Field20; // +0x20
    char m_pad21[0x13];
    Field34 m_Field34; // +0x34
};

void VehicleFlappingJointProperties::vfunc_28()
{
    m_Field20.sub_0009BF60(0);
    m_Field34.sub_0008D4C0(0);
}

