// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/CharacterTemplate.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 5 functions matched (80.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] CharacterTemplate::vfunc_00 (0x001FAE70, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// CharacterTemplate::vfunc_00 (0x001FAE70, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0043FA28[];

class CharacterTemplate
{
public:
    virtual void* vfunc_00();
};

void* CharacterTemplate::vfunc_00()
{
    return DAT_0043FA28;
}

// ============================================================================
// [VERIFIED] CharacterTemplate::vfunc_04 (0x001FAE80, 43 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// CharacterTemplate::vfunc_04 (0x001FAE80, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_0002B700(int);
extern "C" int __cdecl sub_0028E510(int);

class CharacterTemplate
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual int vfunc_04(int a1);
    char m_pad04[0x54];
    int m_Field58; // +0x58
    int m_Field5C; // +0x5C
};

int CharacterTemplate::vfunc_04(int a1)
{
    int r_eax;

    r_eax = a1;
    sub_0002B700(a1);
    r_eax = m_Field58;
    m_Field5C = 0;
    if (r_eax) {
        r_eax = sub_0028E510(r_eax);
        m_Field5C = r_eax;
    }
    return r_eax;
}

// ============================================================================
// [VERIFIED] CharacterTemplate::vfunc_11 (0x001FAEB0, 18 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// CharacterTemplate::vfunc_11 (0x001FAEB0, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00014BE0(int);

class CharacterTemplate
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
    char m_pad04[0x7C];
    int m_Field80; // +0x80
};

void CharacterTemplate::vfunc_11()
{
    int r_eax;

    r_eax = m_Field80;
    if (r_eax) {
        r_eax = sub_00014BE0(r_eax);
    }
}

// ============================================================================
// [VERIFIED] CharacterTemplate::vfunc_01 (0x001FB170, 46 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// CharacterTemplate::vfunc_01 (0x001FB170, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field40
{
    void sub_002A9290();
};

extern "C" char DAT_003CA9B4[];
extern "C" void __cdecl sub_00027600(int);

class CharacterTemplate
{
public:
    virtual void vfunc_00();
    virtual CharacterTemplate* vfunc_01(int a1);
    void sub_0002E660();
    char m_pad04[0x3C];
    Field40 m_Field40; // +0x40
};

CharacterTemplate* CharacterTemplate::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003CA9B4;
    m_Field40.sub_002A9290();
    sub_0002E660();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

