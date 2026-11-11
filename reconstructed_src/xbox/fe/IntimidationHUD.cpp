// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, fe/IntimidationHUD.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 11 functions matched (27.27%). NOT COMPLETE YET.
// The 8 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] IntimidationHUD::vfunc_00 (0x001A37A0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// IntimidationHUD::vfunc_00 (0x001A37A0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004374EC[];

class IntimidationHUD
{
public:
    virtual void* vfunc_00();
};

void* IntimidationHUD::vfunc_00()
{
    return DAT_004374EC;
}

// ============================================================================
// [VERIFIED] IntimidationHUD::vfunc_47 (0x001A37E0, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundEntityLoader::vfunc_04 (0x00064FA0), which was matched first;
// its addresses and names were swapped for this function's.
// IntimidationHUD::vfunc_47 (0x001A37E0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00193500(void);

class IntimidationHUD
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_47();
};

void IntimidationHUD::vfunc_47()
{
    sub_00193500();
}

// ============================================================================
// [VERIFIED] IntimidationHUD::vfunc_01 (0x001A4190, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// IntimidationHUD::vfunc_01 (0x001A4190, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003BDCDC[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_00193F80(void);

class IntimidationHUD
{
public:
    virtual void vfunc_00();
    virtual IntimidationHUD* vfunc_01(int a1);
};

IntimidationHUD* IntimidationHUD::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003BDCDC;
    sub_00193F80();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

