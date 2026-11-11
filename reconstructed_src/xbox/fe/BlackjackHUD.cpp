// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, fe/BlackjackHUD.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 7 functions matched (42.86%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] BlackjackHUD::vfunc_00 (0x001898B0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// BlackjackHUD::vfunc_00 (0x001898B0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00435E84[];

class BlackjackHUD
{
public:
    virtual void* vfunc_00();
};

void* BlackjackHUD::vfunc_00()
{
    return DAT_00435E84;
}

// ============================================================================
// [VERIFIED] BlackjackHUD::vfunc_01 (0x00189AF0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Collidable::vfunc_03 (0x00011F20), which was matched first;
// its addresses and names were swapped for this function's.
// BlackjackHUD::vfunc_01 (0x00189AF0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001898C0(void);
extern "C" void __cdecl sub_00027600(int);

class BlackjackHUD
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual BlackjackHUD* vfunc_01(int a1);
};

BlackjackHUD* BlackjackHUD::vfunc_01(int a1)
{
    sub_001898C0();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] BlackjackHUD::vfunc_04 (0x001BFEB0, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundEntityLoader::vfunc_04 (0x00064FA0), which was matched first;
// its addresses and names were swapped for this function's.
// BlackjackHUD::vfunc_04 (0x001BFEB0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0002AA90(void);

class BlackjackHUD
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
};

void BlackjackHUD::vfunc_04()
{
    sub_0002AA90();
}

