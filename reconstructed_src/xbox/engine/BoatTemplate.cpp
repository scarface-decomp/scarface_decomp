// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/BoatTemplate.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 5 functions matched (60.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] BoatTemplate::vfunc_00 (0x002012F0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// BoatTemplate::vfunc_00 (0x002012F0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00443CE0[];

class BoatTemplate
{
public:
    virtual void* vfunc_00();
};

void* BoatTemplate::vfunc_00()
{
    return DAT_00443CE0;
}

// ============================================================================
// [VERIFIED] BoatTemplate::vfunc_11 (0x00201300, 29 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// BoatTemplate::vfunc_11 (0x00201300, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct FieldEC
{
    void sub_0009E7C0(int, int);
};

extern "C" void __cdecl sub_0020F260(void);

class BoatTemplate
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
    char m_pad04[0xE8];
    FieldEC* m_FieldEC; // +0xEC
};

void BoatTemplate::vfunc_11()
{
    sub_0020F260();
    if (m_FieldEC) {
        m_FieldEC->sub_0009E7C0(0, 0);
    }
}

// ============================================================================
// [VERIFIED] BoatTemplate::vfunc_01 (0x00201440, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// BoatTemplate::vfunc_01 (0x00201440, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003CBE0C[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_0020ED80(void);

class BoatTemplate
{
public:
    virtual void vfunc_00();
    virtual BoatTemplate* vfunc_01(int a1);
};

BoatTemplate* BoatTemplate::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003CBE0C;
    sub_0020ED80();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

