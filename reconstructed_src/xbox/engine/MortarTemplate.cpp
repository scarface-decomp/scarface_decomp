// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/MortarTemplate.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 5 functions matched (80.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] MortarTemplate::vfunc_00 (0x001FBF60, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// MortarTemplate::vfunc_00 (0x001FBF60, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004400A0[];

class MortarTemplate
{
public:
    virtual void* vfunc_00();
};

void* MortarTemplate::vfunc_00()
{
    return DAT_004400A0;
}

// ============================================================================
// [VERIFIED] MortarTemplate::vfunc_01 (0x001FC090, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// MortarTemplate::vfunc_01 (0x001FC090, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003CAE44[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_002120C0(void);

class MortarTemplate
{
public:
    virtual void vfunc_00();
    virtual MortarTemplate* vfunc_01(int a1);
};

MortarTemplate* MortarTemplate::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003CAE44;
    sub_002120C0();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] MortarTemplate::vfunc_04 (0x00212090, 25 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as RandomWaterObjectTemplate::vfunc_04 (0x00200C00), which was matched first;
// its addresses and names were swapped for this function's.
// MortarTemplate::vfunc_04 (0x00212090, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field24
{
    void sub_000876E0();
};

extern "C" void __stdcall sub_0002B700(int);

class MortarTemplate
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

void MortarTemplate::vfunc_04(int a1)
{
    sub_0002B700(a1);
    m_Field24.sub_000876E0();
}

// ============================================================================
// [VERIFIED] MortarTemplate::vfunc_11 (0x002120F0, 131 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// MortarTemplate::vfunc_11 (0x002120F0, 131 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field24
{
    void sub_00087780();
};

struct Object
{
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
};

extern "C" int __cdecl sub_0002AC90(int);

class MortarTemplate
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
    char m_pad23[0x1];
    Field24 m_Field24; // +0x24
    char m_pad25[0xB];
    int m_Field30; // +0x30
    int m_Field34; // +0x34
    char m_pad38[0x20];
    int m_Field58; // +0x58
    char m_pad5C[0xD0];
    int m_Field12C; // +0x12C
    char m_pad130[0x8];
    int m_Field138; // +0x138
    int m_Field13C; // +0x13C
    char m_pad140[0x8];
    int m_Field148; // +0x148
    char m_pad14C[0x4];
    int m_Field150; // +0x150
    char m_pad154[0xC];
    int m_Field160; // +0x160
};

void MortarTemplate::vfunc_11()
{
    int r_ebp, r_esi;

    r_esi = (int)(&m_Field13C);
    r_ebp = 2;
L_13:
    if (sub_0002AC90(*(int*)r_esi)) {
        if (!*(bool*)(sub_0002AC90(*(int*)r_esi) + 34)) goto L_46;
        ((Object*)sub_0002AC90(*(int*)r_esi))->vfunc_11();
    }
L_46:
    r_esi += 4;
    r_ebp -= 1;
    if (r_ebp) goto L_13;
    m_Field24.sub_00087780();
    m_Field150 = 0;
    m_Field138 = 0;
    m_Field148 = 0;
    m_Field160 = 0;
    m_Field12C = 0;
    m_Field30 = 0;
    m_Field34 = 0;
    m_Field58 = 0;
    m_Field22 = false;
}

