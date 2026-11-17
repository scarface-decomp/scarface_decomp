// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/AITask_AvoidIncomingCar.cpp (5 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 5 of 12 functions matched (41.67%). NOT COMPLETE YET.
// The 7 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AITask_AvoidIncomingCar::vfunc_00 (0x00107080, 64 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AITask_AvoidIncomingCar::vfunc_00 (Proto 0x00107080, 64 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct FieldM54
{
    bool sub_000EEA50();
    int sub_000EEAB0();
};

struct Object
{
    int sub_0026DAC0();
};

extern "C" int DAT_0045A0EC;

class AITask_AvoidIncomingCar
{
public:
    virtual void vfunc_00(int a1);
    char m_pad04[0x1C];
    bool m_Field20; // +0x20
    char m_pad21[0x3];
    int m_Field24; // +0x24
    char m_pad28[0xC];
    int m_Field34; // +0x34
};

void AITask_AvoidIncomingCar::vfunc_00(int a1)
{
    if (!((FieldM54*)(int)(((char*)this - 0x54)))->sub_000EEA50()) {
        *(bool*)(((FieldM54*)(int)(((char*)this - 0x54)))->sub_000EEAB0() + 1540) = true;
        m_Field20 = true;
        m_Field24 = *(int*)(DAT_0045A0EC + 44);
        m_Field34 = ((Object*)a1)->sub_0026DAC0();
    }
}

// ============================================================================
// [VERIFIED] AITask_AvoidIncomingCar::vfunc_44 (0x00107110, 56 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AITask_BasicInVehicle::vfunc_40 (0x0010CDB0), which was matched first;
// its addresses and names were swapped for this function's.
// AITask_AvoidIncomingCar::vfunc_44 (0x00107110, 56 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0038CE94[];
extern "C" int DAT_0045BF80;
extern "C" bool DAT_0045BF84;
extern "C" int __cdecl sub_00065CF0(int, int);

class AITask_AvoidIncomingCar
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
    virtual int vfunc_44();
};

int AITask_AvoidIncomingCar::vfunc_44()
{
    int t1;

    if (!(1 & DAT_0045BF84)) {
        *(int*)&DAT_0045BF84 = *(int*)&DAT_0045BF84 | 1;
        t1 = sub_00065CF0((int)DAT_0038CE94, 0);
        DAT_0045BF80 = t1;
        return t1;
    }
    return DAT_0045BF80;
}

// ============================================================================
// [VERIFIED] AITask_AvoidIncomingCar::vfunc_01 (0x00107150, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AITask_AvoidIncomingCar::vfunc_01 (Proto 0x00107150, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000EEAA0();
};

class AITask_AvoidIncomingCar
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
};

void AITask_AvoidIncomingCar::vfunc_01()
{
    ((Object*)(int)this + -96)->sub_000EEAA0();
}

// ============================================================================
// [VERIFIED] AITask_AvoidIncomingCar::vfunc_00 (0x00107CB0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// AITask_AvoidIncomingCar::vfunc_00 (0x00107CB0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00403BB8[];

class AITask_AvoidIncomingCar
{
public:
    virtual void* vfunc_00();
};

void* AITask_AvoidIncomingCar::vfunc_00()
{
    return DAT_00403BB8;
}

// ============================================================================
// [VERIFIED] AITask_AvoidIncomingCar::vfunc_01 (0x00107CC0, 40 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AITask_AvoidIncomingCar::vfunc_01 (Proto 0x00107CC0, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field64
{
    void sub_00102BA0();
};

extern "C" void __cdecl sub_00025160(int);

class AITask_AvoidIncomingCar
{
public:
    virtual void vfunc_00();
    virtual AITask_AvoidIncomingCar* vfunc_01(int a1);
    void sub_000DC430();
    char m_pad04[0x60];
    Field64 m_Field64; // +0x64
};

AITask_AvoidIncomingCar* AITask_AvoidIncomingCar::vfunc_01(int a1)
{
    m_Field64.sub_00102BA0();
    sub_000DC430();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

