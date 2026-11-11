// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, fe/BusinessDetailHUD.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 9 functions matched (33.33%). NOT COMPLETE YET.
// The 6 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] BusinessDetailHUD::vfunc_00 (0x0016C110, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// BusinessDetailHUD::vfunc_00 (0x0016C110, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00410214[];

class BusinessDetailHUD
{
public:
    virtual void* vfunc_00();
};

void* BusinessDetailHUD::vfunc_00()
{
    return DAT_00410214;
}

// ============================================================================
// [VERIFIED] BusinessDetailHUD::vfunc_01 (0x0016C2B0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Collidable::vfunc_03 (0x00011F20), which was matched first;
// its addresses and names were swapped for this function's.
// BusinessDetailHUD::vfunc_01 (0x0016C2B0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0016E130(void);
extern "C" void __cdecl sub_00025160(int);

class BusinessDetailHUD
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual BusinessDetailHUD* vfunc_01(int a1);
};

BusinessDetailHUD* BusinessDetailHUD::vfunc_01(int a1)
{
    sub_0016E130();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] BusinessDetailHUD::vfunc_27 (0x00193EA0, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundEntityLoader::vfunc_04 (0x00064FA0), which was matched first;
// its addresses and names were swapped for this function's.
// BusinessDetailHUD::vfunc_27 (0x00193EA0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0016E150(void);

class BusinessDetailHUD
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_27();
};

void BusinessDetailHUD::vfunc_27()
{
    sub_0016E150();
}

