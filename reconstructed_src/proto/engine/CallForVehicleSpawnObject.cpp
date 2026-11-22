// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/CallForVehicleSpawnObject.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 7 functions matched (57.14%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] CallForVehicleSpawnObject::vfunc_00 (0x001A1890, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// CallForVehicleSpawnObject::vfunc_00 (0x001A1890, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004173C4[];

class CallForVehicleSpawnObject
{
public:
    virtual void* vfunc_00();
};

void* CallForVehicleSpawnObject::vfunc_00()
{
    return DAT_004173C4;
}

// ============================================================================
// [VERIFIED] CallForVehicleSpawnObject::vfunc_37 (0x001A18A0, 9 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CallForVehicleSpawnObject::vfunc_39 (0x001D8FB0), which was matched first;
// its addresses and names were swapped for this function's.
// CallForVehicleSpawnObject::vfunc_37 (0x001A18A0, 9 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_003831C0;

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
    virtual float vfunc_37(int a1, int a2);
};

float CallForVehicleSpawnObject::vfunc_37(int a1, int a2)
{
    return DAT_003831C0;
}

// ============================================================================
// [VERIFIED] CallForVehicleSpawnObject::vfunc_35 (0x001A18B0, 41 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: When a flag is set, sends the same message (64) to its two linked objects.
// ============================================================================
// bin: proto
// va: 0x001A18B0
// what: When a flag is set, sends the same message (64) to its two linked objects.
// tool: Claude Opus 5.5 (transplanted from xb:0x001D8FC0, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct FieldB0
{
    int sub_001A6530(int);
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
    char m_pad04[0xB0];
    FieldB0* m_FieldB4; // +0xB4
    FieldB0* m_FieldB8; // +0xB8
    bool m_FieldBC; // +0xBC
};

void CallForVehicleSpawnObject::vfunc_37()
{
    int r_eax;

    r_eax = m_FieldBC;
    if ((unsigned char)r_eax) {
        m_FieldB4->sub_001A6530(64);
        r_eax = m_FieldB8->sub_001A6530(64);
    }
}

// ============================================================================
// [VERIFIED] CallForVehicleSpawnObject::vfunc_01 (0x001A1980, 74 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// CallForVehicleSpawnObject::vfunc_01 (Proto 0x001A1980, 74 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct FieldB4
{
    void sub_001A6530(int);
};

extern "C" char DAT_003A13D4[];
extern "C" void __cdecl sub_00025160(int);

class CallForVehicleSpawnObject
{
public:
    virtual void vfunc_00();
    virtual CallForVehicleSpawnObject* vfunc_01(int a1);
    void sub_001B0CB0();
    char m_pad04[0xB0];
    FieldB4* m_FieldB4; // +0xB4
    FieldB4* m_FieldB8; // +0xB8
    bool m_FieldBC; // +0xBC
};

CallForVehicleSpawnObject* CallForVehicleSpawnObject::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003A13D4;
    if (m_FieldBC) {
        m_FieldB4->sub_001A6530(64);
        m_FieldB8->sub_001A6530(64);
    }
    sub_001B0CB0();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

