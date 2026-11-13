// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/MissionTriggerObject.cpp (6 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 6 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] MissionTriggerObject::vfunc_00 (0x00212C10, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// MissionTriggerObject::vfunc_00 (0x00212C10, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0044C0C0[];

class MissionTriggerObject
{
public:
    virtual void* vfunc_00();
};

void* MissionTriggerObject::vfunc_00()
{
    return DAT_0044C0C0;
}

// ============================================================================
// [VERIFIED] MissionTriggerObject::vfunc_04 (0x00212C20, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundEntityLoader::vfunc_04 (0x00064FA0), which was matched first;
// its addresses and names were swapped for this function's.
// MissionTriggerObject::vfunc_04 (0x00212C20, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00212FB0(void);

class MissionTriggerObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
};

void MissionTriggerObject::vfunc_04()
{
    sub_00212FB0();
}

// ============================================================================
// [VERIFIED] MissionTriggerObject::vfunc_01 (0x00212C30, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// MissionTriggerObject::vfunc_01 (0x00212C30, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003CF514[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_00212E40(void);

class MissionTriggerObject
{
public:
    virtual void vfunc_00();
    virtual MissionTriggerObject* vfunc_01(int a1);
};

MissionTriggerObject* MissionTriggerObject::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003CF514;
    sub_00212E40();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] MissionTriggerObject::vfunc_30 (0x00212E80, 32 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// MissionTriggerObject::vfunc_30 (0x00212E80, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field74
{
    void sub_00098040(int);
};

extern "C" void __stdcall sub_00029610(int);

class MissionTriggerObject
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
    virtual void vfunc_30(int a1);
    char m_pad04[0x70];
    Field74* m_Field74; // +0x74
};

void MissionTriggerObject::vfunc_30(int a1)
{
    sub_00029610(a1);
    if (m_Field74) {
        m_Field74->sub_00098040(a1);
    }
}

// ============================================================================
// [VERIFIED] MissionTriggerObject::vfunc_32 (0x00212EA0, 32 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as MissionTriggerObject::vfunc_30 (0x00212E80), which was matched first;
// its addresses and names were swapped for this function's.
// MissionTriggerObject::vfunc_32 (0x00212EA0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field74
{
    void sub_00098170(int);
};

extern "C" void __stdcall sub_00029540(int);

class MissionTriggerObject
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
    virtual void vfunc_32(int a1);
    char m_pad04[0x70];
    Field74* m_Field74; // +0x74
};

void MissionTriggerObject::vfunc_32(int a1)
{
    sub_00029540(a1);
    if (m_Field74) {
        m_Field74->sub_00098170(a1);
    }
}

// ============================================================================
// [VERIFIED] MissionTriggerObject::vfunc_29 (0x00212F80, 40 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// MissionTriggerObject::vfunc_29 (0x00212F80, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00098010(int);
};

class MissionTriggerObject
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
    char m_pad04[0x60];
    int m_Field64; // +0x64
    int m_Field68; // +0x68
    int m_Field6C; // +0x6C
    char m_pad70[0x4];
    int m_Field74; // +0x74
};

void MissionTriggerObject::vfunc_29(int a1)
{
    int t1, t2;

    m_Field64 = *(int*)a1;
    m_Field68 = *(int*)(a1 + 4);
    m_Field6C = *(int*)(a1 + 8);
    t1 = m_Field74;
    if (m_Field74) {
        a1 = a1;
        t2 = ((Object*)t1)->sub_00098010(a1);
        return;
    }
}

