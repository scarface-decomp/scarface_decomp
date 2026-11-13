// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/AITask_WatchDangerSource.cpp (5 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 5 of 10 functions matched (50.00%). NOT COMPLETE YET.
// The 5 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AITask_WatchDangerSource::vfunc_46 (0x00127760, 37 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AITask_WatchDangerSource::vfunc_46 (0x00127760, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field64
{
    int sub_00061970();
    bool sub_00103C80();
};

class AITask_WatchDangerSource
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
    virtual int vfunc_46();
    char m_pad04[0x60];
    Field64 m_Field64; // +0x64
};

int AITask_WatchDangerSource::vfunc_46()
{
    if (m_Field64.sub_00061970()) {
        if (m_Field64.sub_00103C80()) goto L_1E;
        return 0;
    }
L_1E:
    return 1;
}

// ============================================================================
// [VERIFIED] AITask_WatchDangerSource::vfunc_47 (0x00127790, 56 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AITask_BasicInVehicle::vfunc_40 (0x0010CDB0), which was matched first;
// its addresses and names were swapped for this function's.
// AITask_WatchDangerSource::vfunc_47 (0x00127790, 56 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B01D8[];
extern "C" int DAT_00489EB0;
extern "C" bool DAT_00489EB4;
extern "C" int __cdecl sub_000700C0(int, int);

class AITask_WatchDangerSource
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

int AITask_WatchDangerSource::vfunc_47()
{
    int t1;

    if (!(1 & DAT_00489EB4)) {
        *(int*)&DAT_00489EB4 = *(int*)&DAT_00489EB4 | 1;
        t1 = sub_000700C0((int)DAT_003B01D8, 0);
        DAT_00489EB0 = t1;
        return t1;
    }
    return DAT_00489EB0;
}

// ============================================================================
// [VERIFIED] AITask_WatchDangerSource::vfunc_50 (0x00127820, 39 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AITask_WatchDangerSource::vfunc_50 (0x00127820, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004879E8;
extern "C" void __cdecl sub_00109480(int);

class AITask_WatchDangerSource
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
    virtual int vfunc_50();
    char m_pad04[0x50];
    int m_Field54; // +0x54
    char m_pad58[0x74];
    int m_FieldCC; // +0xCC
};

int AITask_WatchDangerSource::vfunc_50()
{
    int r_eax;

    if (this) {
        r_eax = (int)(&m_Field54);
    } else {
        r_eax = 0;
    }
    sub_00109480(r_eax);
    r_eax = DAT_004879E8;
    m_FieldCC = *(int*)(r_eax + 44);
    return r_eax;
}

// ============================================================================
// [VERIFIED] AITask_WatchDangerSource::vfunc_02 (0x00127FA0, 48 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AITask_WatchDangerSource::vfunc_02 (0x00127FA0, 48 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class AITask_WatchDangerSource
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02(int a1);
    char m_pad04[0x78];
    int m_Field7C; // +0x7C
    int m_Field80; // +0x80
    int m_Field84; // +0x84
    int m_Field88; // +0x88
    int m_Field8C; // +0x8C
};

int AITask_WatchDangerSource::vfunc_02(int a1)
{
    *(int*)a1 = m_Field7C;
    *(int*)(a1 + 4) = m_Field80;
    *(int*)(a1 + 8) = m_Field84;
    *(int*)(a1 + 12) = m_Field88;
    *(int*)(a1 + 16) = m_Field8C;
    return a1;
}

// ============================================================================
// [VERIFIED] AITask_WatchDangerSource::vfunc_00 (0x00128360, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// AITask_WatchDangerSource::vfunc_00 (0x00128360, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00429370[];

class AITask_WatchDangerSource
{
public:
    virtual void* vfunc_00();
};

void* AITask_WatchDangerSource::vfunc_00()
{
    return DAT_00429370;
}

