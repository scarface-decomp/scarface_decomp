// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/CharacterTypeCondition.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 3 functions matched (66.67%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] CharacterTypeCondition::vfunc_08 (0x000CB6B0, 25 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as UpperBodyAnimStateCondition::vfunc_08 (0x000DD100), which was matched first;
// its addresses and names were swapped for this function's.
// CharacterTypeCondition::vfunc_08 (0x000CB6B0, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_003FFCA0[];

class CharacterTypeCondition
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
    virtual int vfunc_08(int a1);
};

int CharacterTypeCondition::vfunc_08(int a1)
{
    int r_eax;

    r_eax = 0;
    if (a1 >= 0) {
        if ((unsigned int)a1 >= (unsigned int)1) goto L_16;
        r_eax = DAT_003FFCA0[a1];
    }
L_16:
    return r_eax;
}

// ============================================================================
// [VERIFIED] CharacterTypeCondition::vfunc_03 (0x000CBD70, 46 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as UpperBodyAnimStateCondition::vfunc_03 (0x000DD650), which was matched first;
// its addresses and names were swapped for this function's.
// CharacterTypeCondition::vfunc_03 (0x000CBD70, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field10
{
    void sub_001B7A10();
};

extern "C" char DAT_0038595C[];
extern "C" void __cdecl sub_001FCF60(int);

class CharacterTypeCondition
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual CharacterTypeCondition* vfunc_03(int a1);
    void sub_0001F680();
    char m_pad04[0xC];
    Field10 m_Field10; // +0x10
};

CharacterTypeCondition* CharacterTypeCondition::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_0038595C;
    m_Field10.sub_001B7A10();
    sub_0001F680();
    if (a1 & 1) {
        sub_001FCF60((int)this);
    }
    return this;
}

