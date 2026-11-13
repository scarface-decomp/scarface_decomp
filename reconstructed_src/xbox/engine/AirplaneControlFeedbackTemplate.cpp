// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/AirplaneControlFeedbackTemplate.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 6 functions matched (66.67%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AirplaneControlFeedbackTemplate::vfunc_00 (0x0020D350, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// AirplaneControlFeedbackTemplate::vfunc_00 (0x0020D350, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00447744[];

class AirplaneControlFeedbackTemplate
{
public:
    virtual void* vfunc_00();
};

void* AirplaneControlFeedbackTemplate::vfunc_00()
{
    return DAT_00447744;
}

// ============================================================================
// [VERIFIED] AirplaneControlFeedbackTemplate::vfunc_04 (0x0020D360, 25 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as RandomWaterObjectTemplate::vfunc_04 (0x00200C00), which was matched first;
// its addresses and names were swapped for this function's.
// AirplaneControlFeedbackTemplate::vfunc_04 (0x0020D360, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field24
{
    void sub_0009AD50();
};

extern "C" void __stdcall sub_0002B700(int);

class AirplaneControlFeedbackTemplate
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int a1);
    char m_pad04[0x20];
    Field24 m_Field24; // +0x24
};

void AirplaneControlFeedbackTemplate::vfunc_04(int a1)
{
    sub_0002B700(a1);
    m_Field24.sub_0009AD50();
}

// ============================================================================
// [VERIFIED] AirplaneControlFeedbackTemplate::vfunc_30 (0x0020D3A0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AirplaneControlFeedbackTemplate::vfunc_30 (0x0020D3A0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0009AC30();
};

class AirplaneControlFeedbackTemplate
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
};

void AirplaneControlFeedbackTemplate::vfunc_30()
{
    ((Object*)(int)this + 36)->sub_0009AC30();
}

// ============================================================================
// [VERIFIED] AirplaneControlFeedbackTemplate::vfunc_01 (0x0020D7D0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// AirplaneControlFeedbackTemplate::vfunc_01 (0x0020D7D0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003CD894[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_0020C490(void);

class AirplaneControlFeedbackTemplate
{
public:
    virtual void vfunc_00();
    virtual AirplaneControlFeedbackTemplate* vfunc_01(int a1);
};

AirplaneControlFeedbackTemplate* AirplaneControlFeedbackTemplate::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003CD894;
    sub_0020C490();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

