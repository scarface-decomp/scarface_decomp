// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/AirplaneControlFeedbackTemplate.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 6 functions matched (66.67%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AirplaneControlFeedbackTemplate::vfunc_00 (0x001D20E0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// AirplaneControlFeedbackTemplate::vfunc_00 (0x001D20E0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004210E4[];

class AirplaneControlFeedbackTemplate
{
public:
    virtual void* vfunc_00();
};

void* AirplaneControlFeedbackTemplate::vfunc_00()
{
    return DAT_004210E4;
}

// ============================================================================
// [VERIFIED] AirplaneControlFeedbackTemplate::vfunc_05 (0x001D20F0, 25 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AirplaneControlFeedbackTemplate::vfunc_05 (Proto 0x001D20F0, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field2C
{
    void sub_0008F580();
};

extern "C" void __stdcall sub_001D16C0(int);

class AirplaneControlFeedbackTemplate
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int a1);
    char m_pad04[0x28];
    Field2C m_Field2C; // +0x2C
};

void AirplaneControlFeedbackTemplate::vfunc_05(int a1)
{
    sub_001D16C0(a1);
    m_Field2C.sub_0008F580();
}

// ============================================================================
// [VERIFIED] AirplaneControlFeedbackTemplate::vfunc_28 (0x001D2130, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AirplaneControlFeedbackTemplate::vfunc_28 (Proto 0x001D2130, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0008F460();
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
};

void AirplaneControlFeedbackTemplate::vfunc_28()
{
    ((Object*)(int)this + 44)->sub_0008F460();
}

// ============================================================================
// [VERIFIED] AirplaneControlFeedbackTemplate::vfunc_01 (0x001D2520, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// AirplaneControlFeedbackTemplate::vfunc_01 (0x001D2520, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A76BC[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_001D1AC0(void);

class AirplaneControlFeedbackTemplate
{
public:
    virtual void vfunc_00();
    virtual AirplaneControlFeedbackTemplate* vfunc_01(int a1);
};

AirplaneControlFeedbackTemplate* AirplaneControlFeedbackTemplate::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003A76BC;
    sub_001D1AC0();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

