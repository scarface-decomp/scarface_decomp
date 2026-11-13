// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/RainObject.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 3 functions matched (66.67%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] RainObject::vfunc_00 (0x001D22A0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// RainObject::vfunc_00 (0x001D22A0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0043A960[];

class RainObject
{
public:
    virtual void* vfunc_00();
};

void* RainObject::vfunc_00()
{
    return DAT_0043A960;
}

// ============================================================================
// [VERIFIED] RainObject::vfunc_01 (0x001D24B0, 62 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// RainObject::vfunc_01 (0x001D24B0, 62 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field114
{
    void sub_001D7CD0();
};

extern "C" char DAT_003C60EC[];
extern "C" char DAT_003C61EC[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_00080300(int);

class RainObject
{
public:
    virtual void vfunc_00();
    virtual RainObject* vfunc_01(int a1);
    void sub_0002A770();
    char m_pad04[0x110];
    Field114 m_Field114; // +0x114
};

RainObject* RainObject::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003C60EC;
    sub_00080300((int)DAT_003C61EC);
    m_Field114.sub_001D7CD0();
    sub_0002A770();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

