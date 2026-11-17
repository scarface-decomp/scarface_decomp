// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/AITask_CopChallenge.cpp (8 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 8 of 12 functions matched (66.67%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AITask_CopChallenge::vfunc_41 (0x00107FD0, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AITask_CopChallenge::vfunc_41 (Proto 0x00107FD0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class AITask_CopChallenge
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
    char m_pad04[0xCA];
    bool m_FieldCE; // +0xCE
};

void AITask_CopChallenge::vfunc_41()
{
    m_FieldCE = false;
}

// ============================================================================
// [VERIFIED] AITask_CopChallenge::vfunc_47 (0x00107FE0, 39 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AITask_CopChallenge::vfunc_47 (Proto 0x00107FE0, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_000F2770(int);

class AITask_CopChallenge
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
    char m_pad04[0x54];
    int m_Field58; // +0x58
    char m_pad5C[0x70];
    bool m_FieldCC; // +0xCC
    bool m_FieldCD; // +0xCD
};

void AITask_CopChallenge::vfunc_47()
{
    int r_eax;

    if (this) {
        r_eax = (int)(&m_Field58);
    } else {
        r_eax = 0;
    }
    sub_000F2770(r_eax);
    m_FieldCC = false;
    m_FieldCD = false;
}

// ============================================================================
// [VERIFIED] AITask_CopChallenge::vfunc_00 (0x00108090, 4 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AITask_CopChallenge::vfunc_00 (Proto 0x00108090, 4 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class AITask_CopChallenge
{
public:
    virtual bool vfunc_00();
    char m_pad04[0x73];
    bool m_Field77; // +0x77
};

bool AITask_CopChallenge::vfunc_00()
{
    return m_Field77;
}

// ============================================================================
// [VERIFIED] AITask_CopChallenge::vfunc_01 (0x001080A0, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AITask_CopChallenge::vfunc_01 (Proto 0x001080A0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000EEAA0();
};

class AITask_CopChallenge
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
};

void AITask_CopChallenge::vfunc_01()
{
    ((Object*)(int)this + -88)->sub_000EEAA0();
}

// ============================================================================
// [VERIFIED] AITask_CopChallenge::vfunc_00 (0x001087F0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// AITask_CopChallenge::vfunc_00 (0x001087F0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0040405C[];

class AITask_CopChallenge
{
public:
    virtual void* vfunc_00();
};

void* AITask_CopChallenge::vfunc_00()
{
    return DAT_0040405C;
}

// ============================================================================
// [VERIFIED] AITask_CopChallenge::vfunc_03 (0x00108800, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AITask_PedFlee::vfunc_03 (0x001095B0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x00108800
// what: Returns a fixed number kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of 0x000EFD20, names and addresses swapped)
// AITask_CopChallenge::vfunc_03 (0x00108800, 7 bytes)
extern "C" float DAT_0037E6C0;

class AITask_CopChallenge
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual float vfunc_03();
};

float AITask_CopChallenge::vfunc_03()
{
    return DAT_0037E6C0;
}

// ============================================================================
// [VERIFIED] AITask_CopChallenge::vfunc_02 (0x0010A060, 46 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AITask_CopChallenge::vfunc_02 (Proto 0x0010A060, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_0008D4E0(int);
    void sub_000BAFA0();
};

extern "C" Object DAT_00462DD4;
extern "C" int DAT_00462DD8;

class AITask_CopChallenge
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02(int a1);
};

int AITask_CopChallenge::vfunc_02(int a1)
{
    *(int*)a1 = *(int*)(DAT_00462DD4.sub_0008D4E0(DAT_00462DD8) + 16);
    *(int*)(a1 + 16) = 0;
    ((Object*)a1)->sub_000BAFA0();
    return a1;
}

// ============================================================================
// [VERIFIED] AITask_CopChallenge::vfunc_01 (0x0010C990, 51 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AITask_CopChallenge::vfunc_01 (Proto 0x0010C990, 51 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field5C
{
    void sub_000DBE80();
};

struct FieldB8
{
    void sub_00102BA0();
};

extern "C" void __cdecl sub_00025160(int);

class AITask_CopChallenge
{
public:
    virtual void vfunc_00();
    virtual AITask_CopChallenge* vfunc_01(int a1);
    void sub_000DC430();
    char m_pad04[0x58];
    Field5C m_Field5C; // +0x5C
    char m_pad5D[0x5B];
    FieldB8 m_FieldB8; // +0xB8
};

AITask_CopChallenge* AITask_CopChallenge::vfunc_01(int a1)
{
    m_FieldB8.sub_00102BA0();
    m_Field5C.sub_000DBE80();
    sub_000DC430();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

