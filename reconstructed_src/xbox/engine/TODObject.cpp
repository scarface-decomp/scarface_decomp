// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/TODObject.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 3 functions matched (66.67%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] TODObject::vfunc_00 (0x001D38A0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// TODObject::vfunc_00 (0x001D38A0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0043ACA8[];

class TODObject
{
public:
    virtual void* vfunc_00();
};

void* TODObject::vfunc_00()
{
    return DAT_0043ACA8;
}

// ============================================================================
// [VERIFIED] TODObject::vfunc_01 (0x001D3AD0, 46 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as PromptHUD::vfunc_01 (0x001AC410), which was matched first;
// its addresses and names were swapped for this function's.
// TODObject::vfunc_01 (0x001D3AD0, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003C642C[];
extern "C" int DAT_0048F0B0;
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_00029F90(void);

class TODObject
{
public:
    virtual void vfunc_00();
    virtual TODObject* vfunc_01(int a1);
};

TODObject* TODObject::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003C642C;
    DAT_0048F0B0 = 0;
    sub_00029F90();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

