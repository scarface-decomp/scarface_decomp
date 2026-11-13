// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/MortarTemplate.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 5 functions matched (60.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
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

