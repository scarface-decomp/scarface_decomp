// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/AITask_PedFlee.cpp (6 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 6 of 10 functions matched (60.00%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AITask_PedFlee::vfunc_00 (0x00108D50, 23 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AITask_PedFlee::vfunc_00 (Proto 0x000F1EB0), which was matched first;
// its addresses and names were swapped for this function's.
// AITask_PedFlee::vfunc_00 (Proto 0x00108D50, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004879E8;

class AITask_PedFlee
{
public:
    virtual bool vfunc_00();
    char m_pad04[0x70];
    int m_Field74; // +0x74
};

bool AITask_PedFlee::vfunc_00()
{
    return (*(int*)(DAT_004879E8 + 44) - m_Field74) > 500;
}

// ============================================================================
// [VERIFIED] AITask_PedFlee::vfunc_01 (0x00108D70, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AITask_PedFlee::vfunc_01 (Proto 0x000F1ED0), which was matched first;
// its addresses and names were swapped for this function's.
// AITask_PedFlee::vfunc_01 (Proto 0x00108D70, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00104FC0();
};

class AITask_PedFlee
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
};

void AITask_PedFlee::vfunc_01()
{
    ((Object*)(int)this + -76)->sub_00104FC0();
}

// ============================================================================
// [VERIFIED] AITask_PedFlee::vfunc_00 (0x001095A0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// AITask_PedFlee::vfunc_00 (0x001095A0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004294FC[];

class AITask_PedFlee
{
public:
    virtual void* vfunc_00();
};

void* AITask_PedFlee::vfunc_00()
{
    return DAT_004294FC;
}

// ============================================================================
// [VERIFIED] AITask_PedFlee::vfunc_03 (0x001095B0, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns a fixed number kept in the game's data.
// ============================================================================
// bin: xb
// va: 0x001095B0
// what: Returns a fixed number kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of 0x000EFD20, names and addresses swapped)
// AITask_PedFlee::vfunc_03 (0x001095B0, 7 bytes)
extern "C" float DAT_003A01E8;

class AITask_PedFlee
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual float vfunc_03();
};

float AITask_PedFlee::vfunc_03()
{
    return DAT_003A01E8;
}

// ============================================================================
// [VERIFIED] AITask_PedFlee::vfunc_01 (0x001096E0, 51 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AITask_PedFlee::vfunc_01 (Proto 0x000F2940), which was matched first;
// its addresses and names were swapped for this function's.
// AITask_PedFlee::vfunc_01 (Proto 0x001096E0, 51 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field50
{
    void sub_0010AA70();
};

struct FieldAC
{
    void sub_0011DD70();
};

extern "C" void __cdecl sub_00027600(int);

class AITask_PedFlee
{
public:
    virtual void vfunc_00();
    virtual AITask_PedFlee* vfunc_01(int a1);
    void sub_00126EC0();
    char m_pad04[0x4C];
    Field50 m_Field50; // +0x50
    char m_pad51[0x5B];
    FieldAC m_FieldAC; // +0xAC
};

AITask_PedFlee* AITask_PedFlee::vfunc_01(int a1)
{
    m_FieldAC.sub_0011DD70();
    m_Field50.sub_0010AA70();
    sub_00126EC0();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] AITask_PedFlee::vfunc_41 (0x00109850, 172 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AITask_PedFlee::vfunc_41 (0x00109850, 172 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field50
{
    int sub_0011DF80(int);
};

struct Object
{
    void sub_000F8770();
    int sub_001161C0();
    int sub_001623E0(int);
    void sub_00162620();
};

class AITask_PedFlee
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
    int sub_00104FC0();
    int sub_00104FD0();
    void sub_00108FD0();
    void sub_00109630(int);
    void sub_00109720();
    char m_pad04[0x4C];
    Field50 m_Field50; // +0x50
    char m_pad51[0x57];
    int m_FieldA8; // +0xA8
    char m_padAC[0x18];
    int m_FieldC4; // +0xC4
};

void AITask_PedFlee::vfunc_41()
{
    int r_eax, r_edi;

    r_eax = m_Field50.sub_0011DF80(5000);
    if ((unsigned char)r_eax) {
        sub_00109720();
        m_FieldA8 = 1;
    }
    if (m_FieldC4 == 8) {
        r_eax = sub_00104FD0();
        r_eax = ((Object*)*(int*)(r_eax + 340))->sub_001161C0();
        if (!((unsigned char)r_eax)) goto L_4D;
        sub_00109630(9);
    }
L_4D:
    r_eax = sub_00104FD0();
    ((Object*)r_eax)->sub_000F8770();
    r_eax = sub_00104FC0();
    ((Object*)r_eax + 432)->sub_00162620();
    r_eax = m_FieldC4;
    if (r_eax == 9) {
        sub_00108FD0();
        return;
    }
    r_edi = 2;
    if (r_eax == 7) {
        r_edi = 1;
    }
    r_eax = sub_00104FC0();
    r_eax = ((Object*)r_eax + 432)->sub_001623E0(r_edi);
    sub_00104FD0();
}

