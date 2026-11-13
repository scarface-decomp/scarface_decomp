// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/Targeting.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 4 functions matched (75.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] Targeting::vfunc_00 (0x001F6240, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// Targeting::vfunc_00 (0x001F6240, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0043EFAC[];

class Targeting
{
public:
    virtual void* vfunc_00();
};

void* Targeting::vfunc_00()
{
    return DAT_0043EFAC;
}

// ============================================================================
// [VERIFIED] Targeting::vfunc_09 (0x001F6250, 46 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Targeting::vfunc_09 (0x001F6250, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001FAB40();
};

extern "C" int DAT_0048A9D8;
extern "C" int __cdecl sub_001F8B60(void);

class Targeting
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
    virtual void vfunc_09(int a1);
    char m_pad04[0x141];
    bool m_Field145; // +0x145
    bool m_Field146; // +0x146
};

void Targeting::vfunc_09(int a1)
{
    int r_eax;

    r_eax = DAT_0048A9D8;
    if (r_eax) {
        r_eax = sub_001F8B60();
        if (r_eax) {
            ((Object*)r_eax)->sub_001FAB40();
        }
        r_eax = 1;
        m_Field145 = true;
        m_Field146 = true;
    }
}

// ============================================================================
// [VERIFIED] Targeting::vfunc_01 (0x001F62F0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// Targeting::vfunc_01 (0x001F62F0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003CA75C[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_00029F90(void);

class Targeting
{
public:
    virtual void vfunc_00();
    virtual Targeting* vfunc_01(int a1);
};

Targeting* Targeting::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003CA75C;
    sub_00029F90();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

