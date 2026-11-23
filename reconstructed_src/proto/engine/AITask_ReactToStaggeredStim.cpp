// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/AITask_ReactToStaggeredStim.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 5 functions matched (60.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AITask_ReactToStaggeredStim::vfunc_34 (0x000F2BC0, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundEntityLoader::vfunc_04 (0x00064FA0), which was matched first;
// its addresses and names were swapped for this function's.
// AITask_ReactToStaggeredStim::vfunc_34 (0x000F2BC0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_000EFBB0(void);

class AITask_ReactToStaggeredStim
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_34();
};

void AITask_ReactToStaggeredStim::vfunc_34()
{
    sub_000EFBB0();
}

// ============================================================================
// [VERIFIED] AITask_ReactToStaggeredStim::vfunc_36 (0x000F2BD0, 73 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x000F2BD0
// what: 
// tool: the portal's starter code (no AI)

// AITask_ReactToStaggeredStim::vfunc_36 (Proto 0x000F2BD0, 73 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0014C030();
    void sub_001B7A10();
    void sub_00200310(int);
};

extern "C" char DAT_0038A2B8[];
extern "C" int DAT_0040AA24;
extern "C" void __cdecl sub_000EFBB0(void);

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
    int sub_000EEAA0(int, int, int);
    char m_pad04[0x48];
    bool m_Field4C; // +0x4C
};

void AITask_ReactToStaggeredStim::vfunc_36()
{
    int local_4;

    sub_000EFBB0();
    if (m_Field4C) {
        ((Object*)(int)(&local_4))->sub_00200310((int)DAT_0038A2B8);
        ((Object*)sub_000EEAA0((int)(&local_4), DAT_0040AA24, 0))->sub_0014C030();
        ((Object*)(int)(&local_4))->sub_001B7A10();
        m_Field4C = false;
    }
}

// ============================================================================
// [VERIFIED] AITask_ReactToStaggeredStim::vfunc_00 (0x000F2EC0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// AITask_ReactToStaggeredStim::vfunc_00 (0x000F2EC0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00403E4C[];

class AITask_ReactToStaggeredStim
{
public:
    virtual void* vfunc_00();
};

void* AITask_ReactToStaggeredStim::vfunc_00()
{
    return DAT_00403E4C;
}

