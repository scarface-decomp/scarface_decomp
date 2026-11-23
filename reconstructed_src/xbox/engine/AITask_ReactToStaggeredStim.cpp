// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/AITask_ReactToStaggeredStim.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 5 functions matched (60.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AITask_ReactToStaggeredStim::vfunc_37 (0x00109900, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundEntityLoader::vfunc_04 (0x00064FA0), which was matched first;
// its addresses and names were swapped for this function's.
// AITask_ReactToStaggeredStim::vfunc_37 (0x00109900, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00106610(void);

class AITask_ReactToStaggeredStim
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_37();
};

void AITask_ReactToStaggeredStim::vfunc_37()
{
    sub_00106610();
}

// ============================================================================
// [VERIFIED] AITask_ReactToStaggeredStim::vfunc_39 (0x00109910, 73 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AITask_ReactToStaggeredStim::vfunc_36 (Proto 0x000F2BD0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: proto
// va: 0x00109910
// what: 
// tool: the portal's starter code (no AI)

// AITask_ReactToStaggeredStim::vfunc_39 (Proto 0x00109910, 73 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00168B80();
    void sub_002A9290();
    void sub_00242DF0(int);
};

extern "C" char DAT_003ABE48[];
extern "C" int DAT_0042F578;
extern "C" void __cdecl sub_00106610(void);

class AITask_ReactToStaggeredStim
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
    int sub_00104FC0(int, int, int);
    char m_pad04[0x48];
    bool m_Field4C; // +0x4C
};

void AITask_ReactToStaggeredStim::vfunc_39()
{
    int local_4;

    sub_00106610();
    if (m_Field4C) {
        ((Object*)(int)(&local_4))->sub_00242DF0((int)DAT_003ABE48);
        ((Object*)sub_00104FC0((int)(&local_4), DAT_0042F578, 0))->sub_00168B80();
        ((Object*)(int)(&local_4))->sub_002A9290();
        m_Field4C = false;
    }
}

// ============================================================================
// [VERIFIED] AITask_ReactToStaggeredStim::vfunc_00 (0x00109CA0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns AITask_ReactToStaggeredStim's static class record (ConcreteClassRep<AITask_ReactToStaggeredStim>), the object's run-time type.
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// AITask_ReactToStaggeredStim::vfunc_00 (0x00109CA0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00429210[];

class AITask_ReactToStaggeredStim
{
public:
    virtual void* vfunc_00();
};

void* AITask_ReactToStaggeredStim::vfunc_00()
{
    return DAT_00429210;
}

