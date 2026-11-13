// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/CallForVehicleSpawnObject.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 8 functions matched (50.00%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] CallForVehicleSpawnObject::vfunc_00 (0x001D8FA0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// CallForVehicleSpawnObject::vfunc_00 (0x001D8FA0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0043DAF8[];

class CallForVehicleSpawnObject
{
public:
    virtual void* vfunc_00();
};

void* CallForVehicleSpawnObject::vfunc_00()
{
    return DAT_0043DAF8;
}

// ============================================================================
// [VERIFIED] CallForVehicleSpawnObject::vfunc_39 (0x001D8FB0, 9 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// CallForVehicleSpawnObject::vfunc_39 (0x001D8FB0, 9 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_003A50E4;

class CallForVehicleSpawnObject
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
    virtual float vfunc_39(int a1, int a2);
};

float CallForVehicleSpawnObject::vfunc_39(int a1, int a2)
{
    return DAT_003A50E4;
}

// ============================================================================
// [VERIFIED] CallForVehicleSpawnObject::vfunc_37 (0x001D8FC0, 41 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// CallForVehicleSpawnObject::vfunc_37 (0x001D8FC0, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct FieldB0
{
    int sub_001DE370(int);
};

class CallForVehicleSpawnObject
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
    char m_pad04[0xAC];
    FieldB0* m_FieldB0; // +0xB0
    FieldB0* m_FieldB4; // +0xB4
    char m_padB8[0x4];
    bool m_FieldBC; // +0xBC
};

void CallForVehicleSpawnObject::vfunc_37()
{
    int r_eax;

    r_eax = m_FieldBC;
    if ((unsigned char)r_eax) {
        m_FieldB0->sub_001DE370(64);
        r_eax = m_FieldB4->sub_001DE370(64);
    }
}

// ============================================================================
// [VERIFIED] CallForVehicleSpawnObject::vfunc_01 (0x001D9090, 74 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// CallForVehicleSpawnObject::vfunc_01 (0x001D9090, 74 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct FieldB0
{
    void sub_001DE370(int);
};

extern "C" char DAT_003C730C[];
extern "C" void __cdecl sub_00027600(int);

class CallForVehicleSpawnObject
{
public:
    virtual void vfunc_00();
    virtual CallForVehicleSpawnObject* vfunc_01(int a1);
    void sub_001EA010();
    char m_pad04[0xAC];
    FieldB0* m_FieldB0; // +0xB0
    FieldB0* m_FieldB4; // +0xB4
    char m_padB8[0x4];
    bool m_FieldBC; // +0xBC
};

CallForVehicleSpawnObject* CallForVehicleSpawnObject::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003C730C;
    if (m_FieldBC) {
        m_FieldB0->sub_001DE370(64);
        m_FieldB4->sub_001DE370(64);
    }
    sub_001EA010();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

