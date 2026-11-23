// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, ai/AIActionCustomLogicalEffect.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 5 functions matched (60.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AIActionCustomLogicalEffect::vfunc_04 (0x00120920, 22 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AIActionCustomLogicalEffect::vfunc_04 (0x00120920, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_0011E190(void);

class AIActionCustomLogicalEffect
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
};

void AIActionCustomLogicalEffect::vfunc_04()
{
    if (sub_0011E190()) {
        vfunc_07();
        return;
    }
}

// ============================================================================
// [VERIFIED] AIActionCustomLogicalEffect::vfunc_06 (0x00120970, 20 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AIActionCustomLogicalEffect::vfunc_07 (Proto 0x001053E0), which was matched first;
// its addresses and names were swapped for this function's.
// AIActionCustomLogicalEffect::vfunc_06 (Proto 0x00120970, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    virtual void vfunc_00(int);
};

class AIActionCustomLogicalEffect
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual int vfunc_06();
    char m_pad04[0x4];
    char m_Field08; // +0x08
    char m_pad09[0x3];
    Field0C* m_Field0C; // +0x0C
};

int AIActionCustomLogicalEffect::vfunc_06()
{
    m_Field0C->vfunc_00(m_Field08);
    return 1;
}

// ============================================================================
// [VERIFIED] AIActionCustomLogicalEffect::vfunc_00 (0x001215F0, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: AIActionCustomLogicalEffect's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// Same machine code as SoundSequenceLoader::vfunc_03 (0x00065190), which was matched first;
// its addresses and names were swapped for this function's.
// AIActionCustomLogicalEffect::vfunc_00 (0x001215F0, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003AAAC8[];
extern "C" void __cdecl sub_00027600(int);

class AIActionCustomLogicalEffect
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual AIActionCustomLogicalEffect* vfunc_00(int a1);
};

AIActionCustomLogicalEffect* AIActionCustomLogicalEffect::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003AAAC8;
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

