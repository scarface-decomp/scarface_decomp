// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/CarAITask_TrafficCop.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 5 functions matched (60.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] CarAITask_TrafficCop::vfunc_00 (0x00146FA0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// CarAITask_TrafficCop::vfunc_00 (0x00146FA0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0042E104[];

class CarAITask_TrafficCop
{
public:
    virtual void* vfunc_00();
};

void* CarAITask_TrafficCop::vfunc_00()
{
    return DAT_0042E104;
}

// ============================================================================
// [VERIFIED] CarAITask_TrafficCop::vfunc_32 (0x00146FB0, 121 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: xb
// va: 0x00146FB0
// what: 
// tool: the portal's starter code (no AI)

// CarAITask_TrafficCop::vfunc_32 (0x00146FB0, 121 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    bool sub_00217210(int);
    int sub_00217380();
};

extern "C" int DAT_0042DC98;
extern "C" int __cdecl sub_00018F60(int, int);
extern "C" int __cdecl sub_0002AC90(int);

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
    virtual void vfunc_31();
    virtual void vfunc_32();
    char m_pad04[0x1C];
    int m_Field20; // +0x20
    char m_pad24[0x4];
    int m_Field28; // +0x28
    int m_Field2C; // +0x2C
    char m_pad30[0x10];
    int m_Field40; // +0x40
};

void CarAITask_TrafficCop::vfunc_32()
{
    int t2, t5;

    m_Field20 = 0;
    t2 = sub_0002AC90(m_Field28);
    if (t2) {
        if (!*(int*)(t2 + 152)) goto L_76;
        t5 = ((Object*)sub_0002AC90(m_Field2C))->sub_00217380();
        if (!t5) goto L_76;
        if (!((Object*)t5)->sub_00217210(0)) goto L_76;
        m_Field20 = DAT_0042DC98;
        if (sub_00018F60(m_Field40, 0)) {
            *(int*)(t2 + 36) = m_Field40;
            return;
        }
        m_Field40 = 0;
    }
L_76:
    ;
}

// ============================================================================
// [VERIFIED] CarAITask_TrafficCop::vfunc_31 (0x001470A0, 48 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// CarAITask_TrafficCop::vfunc_31 (0x001470A0, 48 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0013D130(int);
};

extern "C" int __cdecl sub_0002AC90(int);

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
    virtual void vfunc_31();
    char m_pad04[0x24];
    int m_Field28; // +0x28
    char m_pad2C[0xC];
    int m_Field38; // +0x38
    char m_pad3C[0x8];
    bool m_Field44; // +0x44
};

void CarAITask_TrafficCop::vfunc_31()
{
    int t2;

    m_Field38 = 6;
    t2 = sub_0002AC90(m_Field28);
    if (t2) {
        *(int*)(t2 + 36) = 0;
        ((Object*)t2)->sub_0013D130(1);
    }
    m_Field44 = false;
}

