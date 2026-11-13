// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/GlanceAtOvertakingPed.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 9 functions matched (22.22%). NOT COMPLETE YET.
// The 7 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] GlanceAtOvertakingPed::vfunc_01 (0x000EFD00, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// GlanceAtOvertakingPed::vfunc_01 (0x000EFD00, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000CA300(int, int);
};

class GlanceAtOvertakingPed
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
};

void GlanceAtOvertakingPed::vfunc_01()
{
    ((Object*)(int)this + 20)->sub_000CA300(350, 600);
}

// ============================================================================
// [VERIFIED] GlanceAtOvertakingPed::vfunc_08 (0x000EFD20, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// GlanceAtOvertakingPed::vfunc_08 (0x000EFD20, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_003B2314;

class GlanceAtOvertakingPed
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
    virtual float vfunc_08();
};

float GlanceAtOvertakingPed::vfunc_08()
{
    return DAT_003B2314;
}

