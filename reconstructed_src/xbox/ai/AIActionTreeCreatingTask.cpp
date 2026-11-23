// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, ai/AIActionTreeCreatingTask.cpp (10 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 10 of 15 functions matched (66.67%). NOT COMPLETE YET.
// The 5 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AIActionTreeCreatingTask::vfunc_00 (0x000EF270, 17 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Says whether sub_000CA1C0 on the member at +0x108 answers no.
// ============================================================================
// bin: xb
// va: 0x000EF270
// what: Says whether sub_000CA1C0 on the member at +0x108 answers no.
// tool: Claude Opus 5.5 (generated from the shape 'not of a member's answer', checked on decomp.me preset 266 by example)
class Member_000EF270
{
public:
    bool sub_000CA1C0();
};

class Class_000EF270
{
public:
    int sub_000EF270();
    char m_pad00[0x108];
    Member_000EF270 m_Field108; // +0x108
};

int Class_000EF270::sub_000EF270()
{
    return !m_Field108.sub_000CA1C0();
}

// ============================================================================
// [VERIFIED] AIActionTreeCreatingTask::vfunc_40 (0x000EF380, 83 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AIActionTreeCreatingTask::vfunc_40 (0x000EF380, 83 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field5C
{
    int sub_00120670();
};

extern "C" int DAT_004879E8;
extern "C" bool __cdecl sub_00128A00(int, int);
extern "C" int __cdecl sub_00128BE0(void);

class AIActionTreeCreatingTask
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
    virtual int vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual int vfunc_44();
    char m_pad04[0x54];
    int m_Field58; // +0x58
    Field5C m_Field5C; // +0x5C
    char m_pad5D[0x3];
    int m_Field60; // +0x60
};

int AIActionTreeCreatingTask::vfunc_40()
{
    int r_edi, t5;

    r_edi = vfunc_44();
    if (r_edi > 0) {
        if (!m_Field58) goto L_4E;
        if (!sub_00128A00((int)(&m_Field60), 2000)) {
            t5 = *(int*)(DAT_004879E8 + 44);
            if (m_Field5C.sub_00120670() <= t5) goto L_4E;
        }
        return sub_00128BE0() + 1;
    }
L_4E:
    return r_edi;
}

// ============================================================================
// [VERIFIED] AIActionTreeCreatingTask::vfunc_00 (0x000EFC10, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// AIActionTreeCreatingTask::vfunc_00 (0x000EFC10, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004290DC[];

class AIActionTreeCreatingTask
{
public:
    virtual void* vfunc_00();
};

void* AIActionTreeCreatingTask::vfunc_00()
{
    return DAT_004290DC;
}

// ============================================================================
// [VERIFIED] AIActionTreeCreatingTask::vfunc_01 (0x000EFC20, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Collidable::vfunc_03 (0x00011F20), which was matched first;
// its addresses and names were swapped for this function's.
// AIActionTreeCreatingTask::vfunc_01 (0x000EFC20, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_000EFC40(void);
extern "C" void __cdecl sub_00027600(int);

class AIActionTreeCreatingTask
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual AIActionTreeCreatingTask* vfunc_01(int a1);
};

AIActionTreeCreatingTask* AIActionTreeCreatingTask::vfunc_01(int a1)
{
    sub_000EFC40();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] AIActionTreeCreatingTask::vfunc_31 (0x001065C0, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AIActionTreeCreatingTask::vfunc_31 (0x001065C0, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class AIActionTreeCreatingTask
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
    char m_pad04[0x44];
    bool m_Field48; // +0x48
};

void AIActionTreeCreatingTask::vfunc_31()
{
    m_Field48 = false;
    vfunc_39();
}

// ============================================================================
// [VERIFIED] AIActionTreeCreatingTask::vfunc_29 (0x001067B0, 67 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: xb
// va: 0x001067B0
// what: 
// tool: the portal's starter code (no AI)

// AIActionTreeCreatingTask::vfunc_29 (0x001067B0, 67 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
};

class AIActionTreeCreatingTask
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
    virtual bool vfunc_29();
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
    virtual bool vfunc_43();
    char m_pad04[0x34];
    int m_Field38; // +0x38
    int m_Field3C; // +0x3C
    char m_pad40[0x9];
    unsigned char m_Field49; // +0x49
};

bool AIActionTreeCreatingTask::vfunc_29()
{
    int r_ebx, r_esi;
    bool t4;

    r_ebx = m_Field3C;
    r_esi = m_Field38;
    if (r_esi != r_ebx) {
        do {
            ((Object*)*(int*)r_esi)->vfunc_02();
            r_esi += 4;
        } while (r_esi != r_ebx);
    }
    vfunc_38();
    vfunc_42();
    t4 = vfunc_43();
    m_Field49 = t4;
    return t4;
}

// ============================================================================
// [VERIFIED] AIActionTreeCreatingTask::vfunc_35 (0x00106800, 51 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AIActionTreeCreatingTask::vfunc_32 (Proto 0x000EFDC0), which was matched first;
// its addresses and names were swapped for this function's.
// AIActionTreeCreatingTask::vfunc_35 (Proto 0x00106800, 51 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01(int);
};

extern "C" int __cdecl sub_0002AC90(int);

class AIActionTreeCreatingTask
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
};

void AIActionTreeCreatingTask::vfunc_35()
{
    int r_ebx, r_edi, r_esi, t2;

    r_esi = (int)this;
    t2 = sub_0002AC90(*(int*)(r_esi + 32));
    r_edi = *(int*)(r_esi + 60);
    r_esi = *(int*)(r_esi + 56);
    r_ebx = t2;
    if (r_esi != r_edi) {
        do {
            ((Object*)*(int*)r_esi)->vfunc_01(r_ebx);
            r_esi += 4;
        } while (r_esi != r_edi);
    }
}

// ============================================================================
// [VERIFIED] AIActionTreeCreatingTask::vfunc_02 (0x00123920, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AIActionTreeCreatingTask::vfunc_02 (0x00123920, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000CA450();
};

extern "C" int DAT_0048A9D8;

class AIActionTreeCreatingTask
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02(int a1);
};

int AIActionTreeCreatingTask::vfunc_02(int a1)
{
    *(int*)a1 = *(int*)(DAT_0048A9D8 + 16);
    *(int*)(a1 + 16) = 0;
    ((Object*)a1)->sub_000CA450();
    return a1;
}

// ============================================================================
// [VERIFIED] AIActionTreeCreatingTask::vfunc_01 (0x00127470, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AITask_RunToAssistCorpse::vfunc_01 (Proto 0x0010B960), which was matched first;
// its addresses and names were swapped for this function's.
// AIActionTreeCreatingTask::vfunc_01 (Proto 0x00127470, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00104FC0();
};

class AIActionTreeCreatingTask
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
};

void AIActionTreeCreatingTask::vfunc_01()
{
    ((Object*)(int)this + -84)->sub_00104FC0();
}

// ============================================================================
// [VERIFIED] AIActionTreeCreatingTask::vfunc_03 (0x001276B0, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AITask_PedFlee::vfunc_03 (0x001095B0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x001276B0
// what: Returns a fixed number kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of 0x000EFD20, names and addresses swapped)
// AIActionTreeCreatingTask::vfunc_03 (0x001276B0, 7 bytes)
extern "C" float DAT_003A4974;

class AIActionTreeCreatingTask
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual float vfunc_03();
};

float AIActionTreeCreatingTask::vfunc_03()
{
    return DAT_003A4974;
}

