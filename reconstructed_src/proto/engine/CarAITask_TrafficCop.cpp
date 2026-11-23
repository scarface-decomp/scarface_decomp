// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/CarAITask_TrafficCop.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 5 functions matched (80.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] CarAITask_TrafficCop::vfunc_00 (0x0012AC10, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// CarAITask_TrafficCop::vfunc_00 (0x0012AC10, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004093BC[];

class CarAITask_TrafficCop
{
public:
    virtual void* vfunc_00();
};

void* CarAITask_TrafficCop::vfunc_00()
{
    return DAT_004093BC;
}

// ============================================================================
// [VERIFIED] CarAITask_TrafficCop::vfunc_28 (0x0012AC20, 25 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 /arch:SSE
// ============================================================================
// bin: proto
// va: 0x0012AC20
// what: 
// tool: the portal's starter code (no AI)

// CarAITask_TrafficCop::vfunc_28 (Proto 0x0012AC20, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class CarAITask_TrafficCop
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
    char m_pad04[0x34];
    int m_Field38; // +0x38
    char m_pad3C[0x4];
    bool m_Field40; // +0x40
    char m_pad41[0x3];
    float m_Field44; // +0x44
};

void CarAITask_TrafficCop::vfunc_28()
{
    if (m_Field38 != 6) {
        m_Field38 = 0;
    }
    m_Field40 = false;
    m_Field44 = 0.0f;
}

// ============================================================================
// [VERIFIED] CarAITask_TrafficCop::vfunc_29 (0x0012AC40, 36 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// CarAITask_TrafficCop::vfunc_29 (Proto 0x0012AC40, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field28
{
    void sub_00121EB0(int);
};

class CarAITask_TrafficCop
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
    char m_pad04[0x24];
    Field28* m_Field28; // +0x28
    char m_pad2C[0xC];
    int m_Field38; // +0x38
    char m_pad3C[0x4];
    bool m_Field40; // +0x40
};

void CarAITask_TrafficCop::vfunc_29()
{
    Field28* t1;

    t1 = m_Field28;
    m_Field38 = 6;
    *(int*)((int)t1 + 36) = 0;
    m_Field28->sub_00121EB0(1);
    m_Field40 = false;
}

// ============================================================================
// [VERIFIED] CarAITask_TrafficCop::vfunc_30 (0x0012AD90, 110 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x0012AD90
// what: 
// tool: the portal's starter code (no AI)

// CarAITask_TrafficCop::vfunc_30 (Proto 0x0012AD90, 110 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    bool sub_001DB730(int);
    int sub_001DB8F0();
};

extern "C" int DAT_00408E8C;
extern "C" int __cdecl sub_00018D30(int, int);
extern "C" int __cdecl sub_00028120(int);

class CarAITask_TrafficCop
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
    char m_pad04[0x1C];
    int m_Field20; // +0x20
    char m_pad24[0x4];
    int m_Field28; // +0x28
    int m_Field2C; // +0x2C
    char m_pad30[0xC];
    int m_Field3C; // +0x3C
};

void CarAITask_TrafficCop::vfunc_30()
{
    int t1, t4;

    t1 = m_Field28;
    m_Field20 = 0;
    if (m_Field28) {
        if (!*(int*)(t1 + 172)) goto L_6C;
        t4 = ((Object*)sub_00028120(m_Field2C))->sub_001DB8F0();
        if (!t4) goto L_6C;
        if (!((Object*)t4)->sub_001DB730(0)) goto L_6C;
        m_Field20 = DAT_00408E8C;
        if (sub_00018D30(m_Field3C, 0)) {
            *(int*)(m_Field28 + 36) = m_Field3C;
            return;
        }
        m_Field3C = 0;
    }
L_6C:
    ;
}

