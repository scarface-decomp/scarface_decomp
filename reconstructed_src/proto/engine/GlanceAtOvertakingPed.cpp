// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/GlanceAtOvertakingPed.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 9 functions matched (44.44%). NOT COMPLETE YET.
// The 5 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] GlanceAtOvertakingPed::vfunc_08 (0x000DC5A0, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as GlanceAtOvertakingPed::vfunc_08 (0x000EFD20), which was matched first;
// its addresses and names were swapped for this function's.
// GlanceAtOvertakingPed::vfunc_08 (0x000DC5A0, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0038086C;

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
    return DAT_0038086C;
}

// ============================================================================
// [VERIFIED] GlanceAtOvertakingPed::vfunc_07 (0x000DC5E0, 14 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Says whether sub_000CA1C0 on the member at +0x14 answers no.
// ============================================================================
// Same machine code as GlanceAtOvertakingPed::vfunc_07 (0x000EFCF0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x000DC5E0
// what: Says whether sub_000BAE80 on the member at +0x14 answers no.
// tool: Claude Opus 5.5 (generated from the shape 'not of a member's answer', checked on decomp.me preset 266 by example)
class Member_000DC5E0
{
public:
    bool sub_000BAE80();
};

class Class_000DC5E0
{
public:
    int sub_000DC5E0();
    char m_pad00[0x14];
    Member_000DC5E0 m_Field14; // +0x14
};

int Class_000DC5E0::sub_000DC5E0()
{
    return !m_Field14.sub_000BAE80();
}

// ============================================================================
// [VERIFIED] GlanceAtOvertakingPed::vfunc_00 (0x000DCE50, 41 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// GlanceAtOvertakingPed::vfunc_00 (Proto 0x000DCE50, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00028120(int);

class GlanceAtOvertakingPed
{
public:
    virtual int vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual bool vfunc_07();
    char m_pad04[0xC];
    int m_Field10; // +0x10
};

int GlanceAtOvertakingPed::vfunc_00()
{
    if (sub_00028120(m_Field10)) {
        if (!vfunc_07()) goto L_25;
        return 1;
    }
L_25:
    return 0;
}

// ============================================================================
// [VERIFIED] GlanceAtOvertakingPed::vfunc_10 (0x0026CAA0, 6 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: GlanceAtOvertakingPed: Always returns 13.
// ============================================================================
// GlanceAtOvertakingPed::vfunc_10 (Proto 0x0026CAA0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

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
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual int vfunc_10();
};

int GlanceAtOvertakingPed::vfunc_10()
{
    return 13;
}

