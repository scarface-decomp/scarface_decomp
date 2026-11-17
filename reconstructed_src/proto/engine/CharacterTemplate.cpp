// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/CharacterTemplate.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 5 functions matched (60.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] CharacterTemplate::vfunc_00 (0x001BF9B0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// CharacterTemplate::vfunc_00 (0x001BF9B0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004191A0[];

class CharacterTemplate
{
public:
    virtual void* vfunc_00();
};

void* CharacterTemplate::vfunc_00()
{
    return DAT_004191A0;
}

// ============================================================================
// [VERIFIED] CharacterTemplate::vfunc_05 (0x001BF9C0, 43 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// CharacterTemplate::vfunc_05 (Proto 0x001BF9C0, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_00028C40(int);
extern "C" int __cdecl sub_00200280(int);

class CharacterTemplate
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual int vfunc_05(int a1);
    char m_pad04[0x48];
    int m_Field4C; // +0x4C
    int m_Field50; // +0x50
};

int CharacterTemplate::vfunc_05(int a1)
{
    int r_eax;

    r_eax = a1;
    sub_00028C40(a1);
    r_eax = m_Field4C;
    m_Field50 = 0;
    if (r_eax) {
        r_eax = sub_00200280(r_eax);
        m_Field50 = r_eax;
    }
    return r_eax;
}

// ============================================================================
// [VERIFIED] CharacterTemplate::vfunc_01 (0x001BFB50, 46 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// CharacterTemplate::vfunc_01 (Proto 0x001BFB50, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field34
{
    void sub_001B7A10();
};

extern "C" char DAT_003A45EC[];
extern "C" void __cdecl sub_00025160(int);

class CharacterTemplate
{
public:
    virtual void vfunc_00();
    virtual CharacterTemplate* vfunc_01(int a1);
    void sub_0002BBD0();
    char m_pad04[0x30];
    Field34 m_Field34; // +0x34
};

CharacterTemplate* CharacterTemplate::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003A45EC;
    m_Field34.sub_001B7A10();
    sub_0002BBD0();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

