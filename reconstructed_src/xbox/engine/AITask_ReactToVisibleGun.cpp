// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/AITask_ReactToVisibleGun.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 9 functions matched (44.44%). NOT COMPLETE YET.
// The 5 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AITask_ReactToVisibleGun::vfunc_49 (0x001276E0, 56 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AITask_ReactToVisibleGun::vfunc_49 (0x001276E0, 56 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct FieldC4
{
    void sub_000CA300(int, int);
};

extern "C" char sub_00015F90[];
extern "C" void __cdecl sub_00109460(int);

class AITask_ReactToVisibleGun
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
    virtual void vfunc_47();
    virtual void vfunc_48();
    virtual void vfunc_49();
    char m_pad04[0x50];
    int m_Field54; // +0x54
    char m_pad58[0x58];
    int m_FieldB0; // +0xB0
    char m_padB4[0x10];
    FieldC4 m_FieldC4; // +0xC4
};

void AITask_ReactToVisibleGun::vfunc_49()
{
    int r_eax;

    if (this) {
        r_eax = (int)(&m_Field54);
    } else {
        r_eax = 0;
    }
    sub_00109460(r_eax);
    m_FieldC4.sub_000CA300(30000, (int)sub_00015F90);
    m_FieldB0 = 2;
}

// ============================================================================
// [VERIFIED] AITask_ReactToVisibleGun::vfunc_47 (0x00127B70, 56 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AITask_BasicInVehicle::vfunc_40 (0x0010CDB0), which was matched first;
// its addresses and names were swapped for this function's.
// AITask_ReactToVisibleGun::vfunc_47 (0x00127B70, 56 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B01B0[];
extern "C" int DAT_00489EA8;
extern "C" bool DAT_00489EAC;
extern "C" int __cdecl sub_000700C0(int, int);

class AITask_ReactToVisibleGun
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
    virtual int vfunc_47();
};

int AITask_ReactToVisibleGun::vfunc_47()
{
    int t1;

    if (!(1 & DAT_00489EAC)) {
        *(int*)&DAT_00489EAC = *(int*)&DAT_00489EAC | 1;
        t1 = sub_000700C0((int)DAT_003B01B0, 0);
        DAT_00489EA8 = t1;
        return t1;
    }
    return DAT_00489EA8;
}

// ============================================================================
// [VERIFIED] AITask_ReactToVisibleGun::vfunc_00 (0x00128510, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// AITask_ReactToVisibleGun::vfunc_00 (0x00128510, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00429344[];

class AITask_ReactToVisibleGun
{
public:
    virtual void* vfunc_00();
};

void* AITask_ReactToVisibleGun::vfunc_00()
{
    return DAT_00429344;
}

// ============================================================================
// [VERIFIED] AITask_ReactToVisibleGun::vfunc_03 (0x00128520, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AITask_PedFlee::vfunc_03 (0x001095B0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x00128520
// what: Returns a fixed number kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of 0x000EFD20, names and addresses swapped)
// AITask_ReactToVisibleGun::vfunc_03 (0x00128520, 7 bytes)
extern "C" float DAT_003B0654;

class AITask_ReactToVisibleGun
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual float vfunc_03();
};

float AITask_ReactToVisibleGun::vfunc_03()
{
    return DAT_003B0654;
}

