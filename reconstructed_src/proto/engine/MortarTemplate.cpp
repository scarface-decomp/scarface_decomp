// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/MortarTemplate.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 5 functions matched (80.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] MortarTemplate::vfunc_00 (0x001C0A70, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// MortarTemplate::vfunc_00 (0x001C0A70, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00419830[];

class MortarTemplate
{
public:
    virtual void* vfunc_00();
};

void* MortarTemplate::vfunc_00()
{
    return DAT_00419830;
}

// ============================================================================
// [VERIFIED] MortarTemplate::vfunc_01 (0x001C0B80, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// MortarTemplate::vfunc_01 (0x001C0B80, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A4A2C[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_001D6F50(void);

class MortarTemplate
{
public:
    virtual void vfunc_00();
    virtual MortarTemplate* vfunc_01(int a1);
};

MortarTemplate* MortarTemplate::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003A4A2C;
    sub_001D6F50();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] MortarTemplate::vfunc_05 (0x001D6F20, 25 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as RandomWaterObjectTemplate::vfunc_04 (0x00200C00), which was matched first;
// its addresses and names were swapped for this function's.
// MortarTemplate::vfunc_05 (0x001D6F20, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field24
{
    void sub_0007D240();
};

extern "C" void __stdcall sub_00028C40(int);

class MortarTemplate
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_05(int a1);
    char m_pad04[0x20];
    Field24 m_Field24; // +0x24
};

void MortarTemplate::vfunc_05(int a1)
{
    sub_00028C40(a1);
    m_Field24.sub_0007D240();
}

// ============================================================================
// [VERIFIED] MortarTemplate::vfunc_12 (0x001D6F80, 122 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// MortarTemplate::vfunc_12 (Proto 0x001D6F80, 122 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field24
{
    void sub_0007D2E0();
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
    virtual void vfunc_12();
};

extern "C" int __cdecl sub_00028120(int);

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
    virtual void vfunc_12();
    char m_pad04[0x1E];
    bool m_Field22; // +0x22
    char m_pad23[0x1];
    Field24 m_Field24; // +0x24
    char m_pad25[0x11B];
    int m_Field140; // +0x140
    char m_pad144[0x8];
    int m_Field14C; // +0x14C
    int m_Field150; // +0x150
    char m_pad154[0x8];
    int m_Field15C; // +0x15C
    char m_pad160[0x4];
    int m_Field164; // +0x164
    char m_pad168[0x8];
    int m_Field170; // +0x170
};

void MortarTemplate::vfunc_12()
{
    int r_ebp, r_esi;

    r_esi = (int)(&m_Field150);
    r_ebp = 2;
L_13:
    if (sub_00028120(*(int*)r_esi)) {
        if (!*(bool*)(sub_00028120(*(int*)r_esi) + 34)) goto L_46;
        ((Object*)sub_00028120(*(int*)r_esi))->vfunc_12();
    }
L_46:
    r_esi += 4;
    r_ebp -= 1;
    if (r_ebp) goto L_13;
    m_Field24.sub_0007D2E0();
    m_Field164 = 0;
    m_Field14C = 0;
    m_Field15C = 0;
    m_Field170 = 0;
    m_Field140 = 0;
    m_Field22 = false;
}

