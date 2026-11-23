// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/CharacterFightTreeTemplate.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 4 functions matched (75.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] CharacterFightTreeTemplate::vfunc_00 (0x001FB1E0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns CharacterFightTreeTemplate's static class record (ConcreteClassRep<CharacterFightTreeTemplate>), the object's run-time type.
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// CharacterFightTreeTemplate::vfunc_00 (0x001FB1E0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0043FA80[];

class CharacterFightTreeTemplate
{
public:
    virtual void* vfunc_00();
};

void* CharacterFightTreeTemplate::vfunc_00()
{
    return DAT_0043FA80;
}

// ============================================================================
// [VERIFIED] CharacterFightTreeTemplate::vfunc_11 (0x001FB1F0, 14 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// CharacterFightTreeTemplate::vfunc_11 (0x001FB1F0, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_000221B0(void);

class CharacterFightTreeTemplate
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
    char m_pad04[0x1E];
    bool m_Field22; // +0x22
};

void CharacterFightTreeTemplate::vfunc_11()
{
    sub_000221B0();
    m_Field22 = false;
}

// ============================================================================
// [VERIFIED] CharacterFightTreeTemplate::vfunc_01 (0x001FB500, 50 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: CharacterFightTreeTemplate's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// Same machine code as CharacterFightTreeTemplate::vfunc_01 (Proto 0x001C0020), which was matched first;
// its addresses and names were swapped for this function's.
// CharacterFightTreeTemplate::vfunc_01 (Proto 0x001FB500, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039FE34[];
extern "C" char DAT_003CAB64[];
extern "C" int DAT_004902C4;
extern "C" void __cdecl sub_00027600(int);

class CharacterFightTreeTemplate
{
public:
    virtual void vfunc_00();
    virtual CharacterFightTreeTemplate* vfunc_01(int a1);
    void sub_0002C720();
};

CharacterFightTreeTemplate* CharacterFightTreeTemplate::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003CAB64;
    DAT_004902C4 -= 1;
    *(int*)this = (int)DAT_0039FE34;
    sub_0002C720();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

