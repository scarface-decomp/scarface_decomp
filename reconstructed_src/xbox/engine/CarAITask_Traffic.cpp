// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/CarAITask_Traffic.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 5 functions matched (60.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] CarAITask_Traffic::vfunc_00 (0x00146DF0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// CarAITask_Traffic::vfunc_00 (0x00146DF0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0042E0D8[];

class CarAITask_Traffic
{
public:
    virtual void* vfunc_00();
};

void* CarAITask_Traffic::vfunc_00()
{
    return DAT_0042E0D8;
}

// ============================================================================
// [VERIFIED] CarAITask_Traffic::vfunc_01 (0x00146E10, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// CarAITask_Traffic::vfunc_01 (0x00146E10, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B2594[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_001460B0(void);

class CarAITask_Traffic
{
public:
    virtual void vfunc_00();
    virtual CarAITask_Traffic* vfunc_01(int a1);
};

CarAITask_Traffic* CarAITask_Traffic::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003B2594;
    sub_001460B0();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] CarAITask_Traffic::vfunc_30 (0x00146F20, 62 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// CarAITask_Traffic::vfunc_30 (0x00146F20, 62 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0013CFE0(int);
    void sub_0013D130(int);
};

extern "C" int __cdecl sub_0002AC90(int);

class CarAITask_Traffic
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
    char m_pad04[0x24];
    int m_Field28; // +0x28
};

void CarAITask_Traffic::vfunc_30()
{
    int t2;

    t2 = sub_0002AC90(m_Field28);
    ((Object*)t2)->sub_0013D130(2);
    *(unsigned char*)(t2 + 369) |= 8;
    *(int*)(t2 + 184) = -1;
    *(int*)(t2 + 188) = 64;
    ((Object*)t2)->sub_0013CFE0(0);
}

